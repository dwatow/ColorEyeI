// OmdFile1.h: interface for the COmdFile class.
//
//////////////////////////////////////////////////////////////////////

#ifndef OMDFILE0_H
#define OMDFILE0_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "COmdFile1.h"
#include "COmdFileGm.h"

enum KindOfOmd { OMD_OLD = 0, OMD_AtYPE, OMD_GAMMA  };

class COmdFile0
{
//Diff of Txt file
	COmdFileFactor *m_Omd;
	COmdFileFactor *m_GmOmd;
	TxtStrData m_dTxt;
public:
	OmdHead& GetFileHead(){ return m_Omd->GetFileHead(); };
	const OmdHead GetFileHead() const{ return m_Omd->GetFileHead(); };
	void SetFileHead(const OmdHead& _H){ m_Omd->SetFileHead(_H); };

	//這些介面剩下 void CSelExcelDlg::otherOmd2xls(CXlsFile2* pHDfXls) 在使用
	CString GetPnlID () const { return m_Omd->GetFileHead().oPnlID (); };
//    CString GetPnlID  () const 
// 	{
// 		CString str;
// 		str.Format("%s", m_Omd->GetFileHead().oPnlID ());
// 		AfxMessageBox(str);
// 		return str; 
// 	};
    CString GetMsrDvc() const { return m_Omd->GetFileHead().oMsrDvc(); };
    CString GetPrb   () const { return m_Omd->GetFileHead().oPrb   (); };
    CString GetCHID  () const { return m_Omd->GetFileHead().oCHID  (); };
	CString GetInch  () const { return m_Omd->GetFileHead().oInch  (); };
	CString GetNitsLv() const { return m_Omd->GetFileHead().oNitsLv(); };
	
	void SetPnlID  (const CString& _S) { if (m_GmOmd != 0) m_GmOmd->GetFileHead().iPnlID(_S);  m_Omd->GetFileHead().iPnlID  (_S); };
	void SetMsrDvc (const CString& _S) { if (m_GmOmd != 0) m_GmOmd->GetFileHead().iMsrDvc(_S); m_Omd->GetFileHead().iMsrDvc (_S); };
    void SetPrb    (const CString& _S) { if (m_GmOmd != 0) m_GmOmd->GetFileHead().iPrb(_S);    m_Omd->GetFileHead().iPrb    (_S); };
    void SetCHID   (const CString& _S) { if (m_GmOmd != 0) m_GmOmd->GetFileHead().iCHID(_S);   m_Omd->GetFileHead().iCHID   (_S); };
	void SetInch   (const CString& _S) { if (m_GmOmd != 0) m_GmOmd->GetFileHead().iInch(_S);   m_Omd->GetFileHead().iInch   (_S); };
	void SetNitsLv (const CString& _S) {                                                       m_Omd->GetFileHead().iNitsLv (_S); };
public:
	COmdFile0():m_Omd(0), m_GmOmd(0){};
	virtual ~COmdFile0() { delete m_Omd; };
    BOOL Open(LPCTSTR _S);
    BOOL Open(LPCTSTR _S, CFileException& _Fx);
    BOOL Save(LPCTSTR _S, CFileException& _Fx, RNA& _D);
    
	void Close(){ if (m_GmOmd != 0) m_GmOmd->Close();   m_Omd->Close(); };

	void iOmdData(RNA& data){ if (m_GmOmd != 0) m_GmOmd->iOmdData(data);   m_Omd->iOmdData(data); };
	void oOmdData(RNA& data){ m_Omd->oOmdData(data); };
	RNA  oOmdData()         { return m_Omd->oOmdData(); };

private:
	void openWhichKindOmefile();
	void saveWhichKindOmefile(RNA&);
	void getOpenSample(LPCTSTR , CFileException& );
};

#endif // OMDFILE0_H
