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
#include "xMsrPoint/Bolt.h"
#include "MainFrm.h"

class CColorEyeIDoc : public CDocument
{
/*
Ca210        m_CA210;
CPatternDlg* p_PtnDlg;
std::vector<Cartridge> vChain1;
*/

	COmdFile1 *f_Omd;
	Bolt m_SimPtnDlg;
	std::vector<Cartridge> vChain1;

	CString m_OmdFilePath;
	CString m_strFilter;

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
	COmdFile1 GetOmdFile();
//	std::vector<Cartridge> GetMsrData();
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
	afx_msg void OnUpdateFileSave(CCmdUI* pCmdUI);
	afx_msg void OnMsrItem();
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
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLOREYEIDOC_H__62D30A8B_5BB7_46BF_B1C6_CC0CF695D9C8__INCLUDED_)
