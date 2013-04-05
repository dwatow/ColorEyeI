// OmdFile1.h: interface for the COmdFile class.
//
//////////////////////////////////////////////////////////////////////

#ifndef OMDFILEPTR_H
#define OMDFILEPTR_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TxtFile.h"
//#include "../xMsrPoint/Cartridge.h"
//#include "../DataChain.h"
#include "../RNA.h"
#include <vector>
#include <iterator>
// #include "../xMsrPoint/Bolt.h"

//typedef std::vector<Cartridge> OmdCarData;
// typedef CDataChain OmdCarData;

class COmdFileFactor
{
//Diff of Txt file
protected:
	CString m_PnlID;
    CString m_MsrDvc;
    CString m_Prb;
    CString m_CHID;
 	CString m_nitsLv;

public:
    const CString GetPnlID () const { return m_PnlID;  };
    const CString GetMsrDvc() const { return m_MsrDvc; };
    const CString GetPrb   () const { return m_Prb;    };
    const CString GetCHID  () const { return m_CHID;   };
 	const CString GetNitsLv() const { return m_nitsLv; };
	
	void SetPnlID  (const CString& _S) { m_PnlID  =  _S; };
	void SetMsrDvc (const CString& _S) { m_MsrDvc =  _S; };
    void SetPrb    (const CString& _S) { m_Prb    =  _S; };
    void SetCHID   (const CString& _S) { m_CHID   =  _S; };

 	void SetNitsLv (const CString& _S) { m_nitsLv =  _S; };

protected:
//	virtual BOOL isOldForm(TxtStrData&) = 0;
	const CString GetLine(const int& );	
	const CString GetCell(const int&, const int& );
	const CString GetCell(const TCHAR& , const int& );   // 0< c<=24
	const CString GetCell(const PTCHAR& , const int& );  //25<=c¡A±qAA¶}©lºâ

protected:
	TxtStrData m_dTxt;
//the same of Txt file;
	CTxtFile   m_fTxt;
	RNA m_dOmd;
//	OmdCarData m_dOmd;
public:
    COmdFileFactor();
	virtual ~COmdFileFactor();
    BOOL Open(LPCTSTR, CFileException&);
    BOOL Save(LPCTSTR, CFileException&);

	void Close(){ m_fTxt.Close(); };

	RNA  oOmdData()         { TxtToOmd(); return m_dOmd; };
	void oOmdData(RNA& data){ TxtToOmd(); data = m_dOmd; };
	void iOmdData(const RNA& data){ m_dOmd = data; OmdToTxt(); };
// 	OmdCarData oOmdData(){ TxtToOmd(); return m_dOmd; };
// 	void oOmdData(OmdCarData& data){ TxtToOmd(); data = m_dOmd; };
// 	void iOmdData(OmdCarData& data){ m_dOmd = data; OmdToTxt(); };

private:
 	virtual void TxtToOmd() = 0;
 	virtual void OmdToTxt() = 0;
 	void ErrorMsg(CFileException& );
};

#endif // OMDFILE0_H
