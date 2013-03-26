// ColorEyeIDoc.h : interface of the CColorEyeIDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_COLOREYEIDOC_H__62D30A8B_5BB7_46BF_B1C6_CC0CF695D9C8__INCLUDED_)
#define AFX_COLOREYEIDOC_H__62D30A8B_5BB7_46BF_B1C6_CC0CF695D9C8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <vector>
#include <algorithm>
#include "Omdfile/COmdFile0.h"
#include "RNA.h"
#include "xMsrPoint/DNA.h"

class CColorEyeIDoc : public CDocument
{
//basic information in Doc
    CString m_PnlID;
    CString m_MsrDvc;
    CString m_Prb;
    CString m_CHID;
	CString m_nitsBkClr;

public:    
    CString& GetPnlID () { return m_PnlID;  };
    CString& GetMsrDvc() { return m_MsrDvc; };
    CString& GetPrb   () { return m_Prb;    };
    CString& GetCHID  () { return m_CHID;   };
	CString& GetNitsLv() { return m_nitsBkClr; };

    void SetPnlID  (const CString& _S) { m_PnlID  =  _S; };
    void SetMsrDvc (const CString& _S) { m_MsrDvc =  _S; };
    void SetPrb    (const CString& _S) { m_Prb    =  _S; };
    void SetCHID   (const CString& _S) { m_CHID   =  _S; };
	void SetNitsLv (const int& _I)     { m_nitsBkClr.Format("%d", _I); };
//File Error
	CFileException m_ErrorFx;
//OMD File
private:
    OmdCarData m_dOmd;
public:
	void OpenOmdDlg(LPCTSTR);
	void SaveOmdDlg(LPCTSTR);
    void OpenOmdFile(LPCTSTR);
    void SaveOmdFile(LPCTSTR);
    OmdCarData& GetOmdData(){return m_dOmd; };

//TXT File
private:
    TxtStrData m_TextData;
public:
	void OpenTxtDlg(LPCTSTR);
	void SaveTxtDlg(LPCTSTR);
    void OpenTxtFile(LPCTSTR);
    void SaveTxtFile(LPCTSTR);
    TxtStrData& GetTextData(){return m_TextData; };
    //TxtStrData GetTextData(){return m_TextData; }; //也可以

public:
	void AutoSave(int); //0: Txt, 1: Omd
//MsrDataChain
//private:
//	CDataChain m_MsrData;
//public:
//	CDataChain& GetMsrDataChain(){ return m_MsrData; };//新的一條鍊 vChain2
//    void RestructureVector();

private:
    RNA m_docRNA;
public:
    void UpdateDocRNA(const RNA& _docRNA);//{ m_docRNA.Empty(); m_docRNA = _docRNA; };
    RNA GetDocRNA() const { return m_docRNA; };

private:
    DNA m_docDNA;
public:
    void UpdateDocDNA(const DNA& _docDNA);//{ m_docDNA.Empty(); m_docDNA = _docDNA; };
    const DNA GetDocDNA() const { return m_docDNA; };
    
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
//    void DebugByTxt();
    void DebugByTxt(CString pathName);
//    static bool isMsred(const Cartridge &sp1, const Cartridge &sp2);

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLOREYEIDOC_H__62D30A8B_5BB7_46BF_B1C6_CC0CF695D9C8__INCLUDED_)
