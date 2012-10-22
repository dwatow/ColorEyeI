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
#include "../DataChain.h"
#include <vector>
#include <iterator>
#include "../xMsrPoint/Bolt.h"

//typedef std::vector<Cartridge> OmdCarData;
typedef CDataChain OmdCarData;

class COmdFilePtr
{
//Diff of Txt file
protected:
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
protected:
//	virtual BOOL isOldForm(TxtStrData&) = 0;
	CString GetLine(UINT );	
	CString GetCell(UINT , UINT );
	CString GetCell(TCHAR , UINT );   // 0< c<=24
	CString GetCell(PTCHAR , UINT );  //25<=c¡A±qAA¶}©lºâ

protected:
	TxtStrData m_dTxt;
//the same of Txt file;
	CTxtFile   m_fTxt;
	OmdCarData m_dOmd;
public:
    COmdFilePtr();
	virtual ~COmdFilePtr();
    BOOL Open(CString, CFileException&);
    BOOL Save(CString, CFileException&);

	void Close(){ m_fTxt.Close(); };

	OmdCarData oOmdData(){ TxtToOmd(); return m_dOmd; };
	void oOmdData(OmdCarData& data){ TxtToOmd(); data = m_dOmd; };
	void iOmdData(OmdCarData& data){ m_dOmd = data; OmdToTxt(); };

private:
 	virtual void TxtToOmd() = 0;
 	virtual void OmdToTxt() = 0;
 	void ErrorMsg(CFileException& );
};

#endif // OMDFILE0_H
