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
    COmdFile1 *f_Omd;
//    CString m_OmdFilePath;
    CString m_strFilter;
public:
    CDataChain vChain1;
    CDataChain vChain2;

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
    COmdFile1& GetOmdFile();
    CDataChain& GetVector();//新的一條鍊 vChain2
    void RestructureVector();

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
    void NewOmdData();
    void DebugByTxt();
	void DebugByTxt(CString path);
//    static bool isMsred(const Cartridge &sp1, const Cartridge &sp2);

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLOREYEIDOC_H__62D30A8B_5BB7_46BF_B1C6_CC0CF695D9C8__INCLUDED_)
