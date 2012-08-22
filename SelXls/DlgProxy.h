// DlgProxy.h : header file
//

#if !defined(AFX_DLGPROXY_H__8119263F_8845_4567_B8C0_D77B811DF185__INCLUDED_)
#define AFX_DLGPROXY_H__8119263F_8845_4567_B8C0_D77B811DF185__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CSelXlsDlg;

/////////////////////////////////////////////////////////////////////////////
// CSelXlsDlgAutoProxy command target

class CSelXlsDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CSelXlsDlgAutoProxy)

	CSelXlsDlgAutoProxy();           // protected constructor used by dynamic creation

// Attributes
public:
	CSelXlsDlg* m_pDialog;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSelXlsDlgAutoProxy)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CSelXlsDlgAutoProxy();

	// Generated message map functions
	//{{AFX_MSG(CSelXlsDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CSelXlsDlgAutoProxy)

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CSelXlsDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPROXY_H__8119263F_8845_4567_B8C0_D77B811DF185__INCLUDED_)
