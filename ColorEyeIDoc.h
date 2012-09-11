// ColorEyeIDoc.h : interface of the CColorEyeIDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_COLOREYEIDOC_H__62D30A8B_5BB7_46BF_B1C6_CC0CF695D9C8__INCLUDED_)
#define AFX_COLOREYEIDOC_H__62D30A8B_5BB7_46BF_B1C6_CC0CF695D9C8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Omdfile/OmdFile1.h"
#include <vector>
#include <algorithm>

class CColorEyeIDoc : public CDocument
{
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

//OMD File
private:
    OmdValueData m_OmdData;
public:
    void OpenOmdFile(LPCTSTR);
    void SaveOmdFile(LPCTSTR);
    OmdValueData GetOmdData(){return m_OmdData; };

//TXT File
private:
    TxtStrData m_TextData;
public:
    void OpenTxtFile(LPCTSTR );
    void SaveTxtFile(LPCTSTR );
    TxtStrData GetTextData(){return m_TextData; };
    //TxtStrData& GetTextData(){return m_TextData; }; //也可以

//MsrDataChain
private:
	CDataChain m_msrData;
public:
	CDataChain& GetMsrDataChain(){ return m_msrData; };//新的一條鍊 vChain2
    void RestructureVector();


protected: // create from serialization only
    CColorEyeIDoc();
    DECLARE_DYNCREATE(CColorEyeIDoc)
public:
// Attributes

// Operations
public:

// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CColorEyeIDoc)
    public:
    virtual BOOL OnNewDocument();
    virtual void Serialize(CArchive& ar);
    virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
    //}}AFX_VIRTUAL

// Implementation
public:
    virtual ~CColorEyeIDoc();
#ifdef _DEBUG
    virtual void AssertValid() const;
    virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
    //{{AFX_MSG(CColorEyeIDoc)
    afx_msg void OnFileOpen();
    afx_msg void OnFileNew();
    afx_msg void OnFileSaveAs();
    afx_msg void OnFileSave();
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()

    // Generated OLE dispatch map functions
    //{{AFX_DISPATCH(CColorEyeIDoc)
        // NOTE - the ClassWizard will add and remove member functions here.
        //    DO NOT EDIT what you see in these blocks of generated code !
    //}}AFX_DISPATCH
    DECLARE_DISPATCH_MAP()
    DECLARE_INTERFACE_MAP()
private:
    void DebugByTxt();
    void DebugByTxt(CString path);
//    static bool isMsred(const Cartridge &sp1, const Cartridge &sp2);

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLOREYEIDOC_H__62D30A8B_5BB7_46BF_B1C6_CC0CF695D9C8__INCLUDED_)
