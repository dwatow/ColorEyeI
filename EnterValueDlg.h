#if !defined(AFX_ENTERVALUEDLG_H__2090C39B_4C09_4C1F_A25F_8C5D643F411C__INCLUDED_)
#define AFX_ENTERVALUEDLG_H__2090C39B_4C09_4C1F_A25F_8C5D643F411C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EnterValueDlg.h : header file
//
/////////////////////////////////////////////////////////////////////////////
// CEnterValueDlg dialog

class CEnterValueDlg : public CDialog
{
// Construction
public:
	CEnterValueDlg(const CString& dlgTitle, const CString& str, CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEnterValueDlg)
	enum { IDD = IDD_EDIT_DIALOG };
	CString	m_strName;
	CString	m_strValue;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEnterValueDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEnterValueDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CString m_dlgTitle;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENTERVALUEDLG_H__2090C39B_4C09_4C1F_A25F_8C5D643F411C__INCLUDED_)
