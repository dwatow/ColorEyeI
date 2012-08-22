// DlgProxy.h : header file
//

#if !defined(AFX_DLGPROXY_H__7B8E9CBE_86DF_4B8A_9FDC_D6FCC10AAFFD__INCLUDED_)
#define AFX_DLGPROXY_H__7B8E9CBE_86DF_4B8A_9FDC_D6FCC10AAFFD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CXMsrPointDlg;

/////////////////////////////////////////////////////////////////////////////
// CXMsrPointDlgAutoProxy command target

class CXMsrPointDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CXMsrPointDlgAutoProxy)

	CXMsrPointDlgAutoProxy();           // protected constructor used by dynamic creation

// Attributes
public:
	CXMsrPointDlg* m_pDialog;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CXMsrPointDlgAutoProxy)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CXMsrPointDlgAutoProxy();

	// Generated message map functions
	//{{AFX_MSG(CXMsrPointDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CXMsrPointDlgAutoProxy)

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CXMsrPointDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPROXY_H__7B8E9CBE_86DF_4B8A_9FDC_D6FCC10AAFFD__INCLUDED_)
