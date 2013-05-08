#if !defined(AFX_CMsrTableDlg_H__183594A8_2114_4DF9_B849_ADFD19EBABE8__INCLUDED_)
#define AFX_CMsrTableDlg_H__183594A8_2114_4DF9_B849_ADFD19EBABE8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MsrTableDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMsrTableDlg dialog

class CMsrTableDlg : public CDialog
{
// Construction
public:
	CMsrTableDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMsrTableDlg)
	enum { IDD = IDD_MSR_TABLE };
	CStatic	m_tableView;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMsrTableDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMsrTableDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CMSRTABLEDLG_H__183594A8_2114_4DF9_B849_ADFD19EBABE8__INCLUDED_)
