// OmdFile1.h: interface for the COmdFile class.
//
//////////////////////////////////////////////////////////////////////

#ifndef OMDFILEPTR_H
#define OMDFILEPTR_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TxtFile.h"
#include "RNA.h"
#include <vector>
#include <iterator>
#include "OmdHead.h"
#include "DNAconfig.h"
#include "MainFrm.h"

class COmdFileFactor
{
//Diff of Txt file
protected:
    OmdHead m_omdFileHead;

public:
    OmdHead& GetFileHead(){ return m_omdFileHead; };
    const OmdHead& GetFileHead() const{ return m_omdFileHead; };
    void SetFileHead(const OmdHead& _H){ m_omdFileHead = _H; };

protected:
//    virtual BOOL isOldForm(TxtStrData&) = 0;
    const CString GetLine(const int& ) const;    
    const CString GetCell(const int&    , const int& ) const;
    const CString GetCell(const TCHAR&  , const int& ) const;  // 0< c<=24
    const CString GetCell(const PTCHAR& , const int& ) const;  //25<=c，從AA開始算

protected:
    TxtStrData m_dTxt;
//the same of Txt file;
    CTxtFile m_fTxt;
	DNA m_omdDNA;
    RNA m_omdRNA;

public:
    COmdFileFactor();
    virtual ~COmdFileFactor();
    BOOL Open(LPCTSTR, CFileException&);
    BOOL Save(LPCTSTR, CFileException&);

    void Close(){ m_fTxt.Close(); };

    RNA  oOmdData()         { txt2omd(); return m_omdRNA; };
    void oOmdData(RNA& data){ txt2omd(); data = m_omdRNA; };
    void iOmdData(const RNA& data){ m_omdRNA = data; omd2txt(); };

private:
    virtual void txt2omd() = 0;
    virtual void omd2txt() = 0;
    void ErrorMsg(CFileException& ) const;
protected:
	void t2oDNAnRNA();
	const CString getInch() const;
	virtual void CreatDNA(DnaConfig&) = 0;
	void t2oDelDNAinEmptyRNA();
};

inline void COmdFileFactor::t2oDNAnRNA()
{
	//Init LCM size
	Ca210* pOldCa210;
	CMainFrame* pMainFrm = dynamic_cast<CMainFrame*>(AfxGetMainWnd());
	ASSERT_VALID(pMainFrm);
	
	pOldCa210 = pMainFrm->m_pCa210;
	
	pMainFrm->m_pCa210 = new Ca210sim();
	Ca210* pCa210 = pMainFrm->m_pCa210;
	pCa210->SetOnline(1);
	pCa210->SetLcmSize(getInch());
	
	DnaConfig dnaConfig;
	CreatDNA(dnaConfig);
	dnaConfig.CreatRNA(m_omdDNA, m_omdRNA);
	
	int dnaSize, rnaSize;
	dnaSize = m_omdDNA.Size();
	rnaSize = m_omdRNA.Size();

	//setup Point
	CPoint pointEmpty(0, 0);
	for (std::vector<Cartridge2>::iterator itor = m_omdRNA.Begin(); itor != m_omdRNA.End(); ++itor)
		itor->SetPointPosi(pointEmpty);
	
	delete pCa210;
	pMainFrm->m_pCa210 = pOldCa210;
}

inline const CString COmdFileFactor::getInch() const
{
	if ( atoi(m_omdFileHead.oInch()) > 1 )
		return m_omdFileHead.oInch();
	else
		return "24";
}

inline void COmdFileFactor::t2oDelDNAinEmptyRNA()
{
	debugFile df;
	df.Add("一開始\n");
	std::vector<Nucleotide>::iterator logItor;
	for (logItor = m_omdDNA.Begin(); logItor != m_omdDNA.End(); ++logItor)
		df.Add(logItor->ShowMe());
	
	DNA inverEmptyDNA = m_omdDNA;
	DNA emptyDNA;
    for (std::vector<Cartridge2>::iterator itor = m_omdRNA.Begin(); itor != m_omdRNA.End(); ++itor)
	{
		BOOL colorMatch;
		BOOL ptTotalMatch;
		BOOL paraMatch;
		const CString sample(itor->GetDescrip());
		for (std::vector<Nucleotide>::const_iterator itorDNA = m_omdDNA.Begin(); itorDNA != m_omdDNA.End(); ++itorDNA)
		{
			// 			colorMatch = ptTotalMatch = paraMatch = 1;
			
			colorMatch   = ( sample.Find( itorDNA->GetStrBackColor()     ) != -1)? TRUE: FALSE;
			ptTotalMatch = ( sample.Find( itorDNA->GetStrMsrPointTotal() ) != -1)? TRUE: FALSE;
			paraMatch    = ( sample.Find( itorDNA->GetStrPara()          ) != -1)? TRUE: FALSE;
			
			if (colorMatch && ptTotalMatch && paraMatch)
				emptyDNA.AddCell(*itorDNA);
		}
	}
	
	inverEmptyDNA.DelCell(emptyDNA);
	m_omdDNA.DelCell(inverEmptyDNA);
	
	df.Add("\n最後\n");
	for (logItor = m_omdDNA.Begin(); logItor != m_omdDNA.End(); ++logItor)
		df.Add(logItor->ShowMe());
	
	df.Out2File("c:\\t2oDelDNAinEmptyRNA.log");
}

#endif // OMDFILE0_H
