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
	COmdFilePtr *m_Omd;
	COmdFilePtr *m_GmOmd;
	TxtStrData m_dTxt;

public:
	CString GetPnlID () const { return m_Omd->GetPnlID (); };
    CString GetMsrDvc() const { return m_Omd->GetMsrDvc(); };
    CString GetPrb   () const { return m_Omd->GetPrb   (); };
    CString GetCHID  () const { return m_Omd->GetCHID  (); };
	
	void SetPnlID  (CString& _S) { if (m_GmOmd != 0) m_GmOmd->SetPnlID(_S);  m_Omd->SetPnlID  (_S); };
	void SetMsrDvc (CString& _S) { if (m_GmOmd != 0) m_GmOmd->SetMsrDvc(_S); m_Omd->SetMsrDvc (_S); };
    void SetPrb    (CString& _S) { if (m_GmOmd != 0) m_GmOmd->SetPrb(_S);    m_Omd->SetPrb    (_S); };
    void SetCHID   (CString& _S) { if (m_GmOmd != 0) m_GmOmd->SetCHID(_S);   m_Omd->SetCHID   (_S); };
public:
	COmdFile0():m_Omd(0), m_GmOmd(0){};
	virtual ~COmdFile0() { delete m_Omd; };
    BOOL Open(CString _S, CFileException& _Fx);
    BOOL Save(CString _S, CFileException& _Fx, OmdCarData _D);
    
	void Close(){ if (m_GmOmd != 0) m_GmOmd->Close();   m_Omd->Close(); };

	void iOmdData(OmdCarData& data){ if (m_GmOmd != 0) m_GmOmd->iOmdData(data);   m_Omd->iOmdData(data); };
	void oOmdData(OmdCarData& data){ m_Omd->oOmdData(data); };
//	OmdCarData oOmdData(){ return m_Omd->oOmdData(); };

private:
	void openWhichKindOmefile();
	void saveWhichKindOmefile(OmdCarData);
	void GetOpenSample(CString , CFileException& );
};

#endif // OMDFILE0_H
