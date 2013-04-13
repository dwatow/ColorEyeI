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
#include "COmdFile0.h"
#include "OmdHead.h"
#include "RNA.h"
#include "DNA.h"

class CColorEyeIDoc : public CDocument
{
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
	//basic information in Doc
private:
	OmdHead m_docFileHead;
public:
	OmdHead& GetFileHead();
	const OmdHead GetFileHead() const;
	void SetFileHead(const OmdHead& _H);
	
private:
    RNA m_docRNA;
public:
    void UpdateDocRNA(const RNA& _docRNA);
    RNA  GetDocRNA() const { return m_docRNA; };
	
private:
    RNA m_MsrRNA;
public:
    void UpdateMsrRNA(const RNA& m_MsrRNA);
    RNA  GetMsrRNA() const { return m_MsrRNA; };
	
private:
    DNA m_docDNA;
public:
    void UpdateDocDNA(const DNA& _docDNA);
    const DNA GetDocDNA() const { return m_docDNA; };
	
	//File Error
	CFileException m_ErrorFx;
	//OMD File
// public:
	void openOmdDlg(LPCTSTR);
	void saveOmdDlg(LPCTSTR);
    void openOmdFile(LPCTSTR);
    void saveOmdFile(LPCTSTR);
	//    RNA& GetOmdData(){return m_docRNA; };
	
	//TXT File
private:
    TxtStrData m_TextData;
	void openTxtDlg(LPCTSTR);
	void saveTxtDlg(LPCTSTR);
    void openTxtFile(LPCTSTR);
    void saveTxtFile(LPCTSTR);
	//     TxtStrData& GetTextData(){return m_TextData; };
	//     TxtStrData GetTextData() const{return m_TextData; }; //¤]¥i¥H
	
	//debug
    void debugByTxt(CString pathName);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLOREYEIDOC_H__62D30A8B_5BB7_46BF_B1C6_CC0CF695D9C8__INCLUDED_)
