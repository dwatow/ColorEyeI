// DlgProxy.h : header file
//

#if !defined(AFX_DLGPROXY_H__D4990FEE_E4E0_4846_903C_90D1452B18B5__INCLUDED_)
#define AFX_DLGPROXY_H__D4990FEE_E4E0_4846_903C_90D1452B18B5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMsrItemsDlg;

/////////////////////////////////////////////////////////////////////////////
// CMsrItemsDlgAutoProxy command target

class CMsrItemsDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CMsrItemsDlgAutoProxy)

	CMsrItemsDlgAutoProxy();           // protected constructor used by dynamic creation

// Attributes
public:
	CMsrItemsDlg* m_pDialog;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMsrItemsDlgAutoProxy)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CMsrItemsDlgAutoProxy();

	// Generated message map functions
	//{{AFX_MSG(CMsrItemsDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CMsrItemsDlgAutoProxy)

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CMsrItemsDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPROXY_H__D4990FEE_E4E0_4846_903C_90D1452B18B5__INCLUDED_)
