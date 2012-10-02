// OmdFile1.h: interface for the COmdFile class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OMDFILE1_H__5E9E8D8E_4BB9_40C8_BEE3_2756DA9A7E76__INCLUDED_)
#define AFX_OMDFILE1_H__5E9E8D8E_4BB9_40C8_BEE3_2756DA9A7E76__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TxtFile.h"
//#include "../xMsrPoint/Cartridge.h"
#include "../DataChain.h"
#include <vector>
#include <iterator>
#include "../xMsrPoint/Bolt.h"

//typedef std::vector<Cartridge> OmdCarData;
typedef CDataChain OmdCarData;

class COmdFile1// : public CTxtFile
{
//Diff of Txt file
	CString m_PnlID;
    CString m_MsrDvc;
    CString m_Prb;
    CString m_CHID;
	
public:
    CString GetPnlID () const { return m_PnlID;  };
    CString GetMsrDvc() const { return m_MsrDvc; };
    CString GetPrb   () const { return m_Prb;    };
    CString GetCHID  () const { return m_CHID;   };
	
	void SetPnlID  (CString& _S) { m_PnlID  =  _S; };
	void SetMsrDvc (CString& _S) { m_MsrDvc =  _S; };
    void SetPrb    (CString& _S) { m_Prb    =  _S; };
    void SetCHID   (CString& _S) { m_CHID   =  _S; };
private:
	BOOL isOldForm(TxtStrData&);
	
	CString GetLine(UINT LineNum);	
	CString GetCell(UINT Word, UINT Line);
	CString GetCell(TCHAR c, UINT n);   // 0< c<=24
	CString GetCell(PTCHAR c, UINT n);  //25<=c¡A±qAA¶}©lºâ

//the same of Txt file;
private:
	CTxtFile f_Txt;
	OmdCarData D_Omd;

	TxtStrData D_Txt;
public:
    COmdFile1();
	virtual ~COmdFile1(){  D_Omd.Empty(); D_Txt.clear(); D_Txt.clear(); };
    BOOL Open(CString, CFileException&);
    BOOL Save(CString, CFileException&);
    
	void Close(){ f_Txt.Close(); };

	void iOmdData(OmdCarData& data){ D_Omd = data; OmdToTxt(); };
	void oOmdData(OmdCarData& data){ TxtToOmd(); data = D_Omd; };
	OmdCarData oOmdData(){ TxtToOmd(); return D_Omd; };
private:
	void TxtToOmd();
	void OmdToTxt();
	void ErrorMsg(CFileException& fx);
};

#endif // !defined(AFX_OMDFILE1_H__5E9E8D8E_4BB9_40C8_BEE3_2756DA9A7E76__INCLUDED_)
