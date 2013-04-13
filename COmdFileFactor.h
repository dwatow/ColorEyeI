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

class COmdFileFactor
{
//Diff of Txt file
protected:
	OmdHead m_omdFileHead;

// 	CString m_PnlID;
//     CString m_MsrDvc;
//     CString m_Prb;
//     CString m_CHID;
//  	CString m_nitsLv;

public:
	OmdHead& GetFileHead(){ return m_omdFileHead; };
	const OmdHead GetFileHead() const{ return m_omdFileHead; };
	void SetFileHead(const OmdHead& _H){ m_omdFileHead = _H; };

//     const CString GetPnlID () const { return m_PnlID;  };
//     const CString GetMsrDvc() const { return m_MsrDvc; };
//     const CString GetPrb   () const { return m_Prb;    };
//     const CString GetCHID  () const { return m_CHID;   };
//  	const CString GetNitsLv() const { return m_nitsLv; };
	
// 	void SetPnlID  (const CString& _S) { m_PnlID  =  _S; };
// 	void SetMsrDvc (const CString& _S) { m_MsrDvc =  _S; };
//     void SetPrb    (const CString& _S) { m_Prb    =  _S; };
//     void SetCHID   (const CString& _S) { m_CHID   =  _S; };
// 
//  	void SetNitsLv (const CString& _S) { m_nitsLv =  _S; };

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

	RNA  oOmdData()         { txt2omd(); return m_dOmd; };
	void oOmdData(RNA& data){ txt2omd(); data = m_dOmd; };
	void iOmdData(const RNA& data){ m_dOmd = data; omd2txt(); };
// 	OmdCarData oOmdData(){ txt2omd(); return m_dOmd; };
// 	void oOmdData(OmdCarData& data){ txt2omd(); data = m_dOmd; };
// 	void iOmdData(OmdCarData& data){ m_dOmd = data; omd2txt(); };

private:
 	virtual void txt2omd() = 0;
 	virtual void omd2txt() = 0;
 	void ErrorMsg(CFileException& );
};

#endif // OMDFILE0_H
