// SelXlsDlg.h : header file
//

#if !defined(AFX_SELXLSDLG_H__4C330C24_2D58_47E6_979F_BF3A525D98CC__INCLUDED_)
#define AFX_SELXLSDLG_H__4C330C24_2D58_47E6_979F_BF3A525D98CC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CSelXlsDlgAutoProxy;

/////////////////////////////////////////////////////////////////////////////
// CSelXlsDlg dialog

class CSelXlsDlg : public CDialog
{
	DECLARE_DYNAMIC(CSelXlsDlg);
	friend class CSelXlsDlgAutoProxy;

// Construction
public:
	CSelXlsDlg(CWnd* pParent = NULL);	// standard constructor
	virtual ~CSelXlsDlg();

// Dialog Data
	//{{AFX_DATA(CSelXlsDlg)
	enum { IDD = IDD_SELXLS_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSelXlsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CSelXlsDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// Generated message map functions
	//{{AFX_MSG(CSelXlsDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SELXLSDLG_H__4C330C24_2D58_47E6_979F_BF3A525D98CC__INCLUDED_)
