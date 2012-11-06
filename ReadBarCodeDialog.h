#if !defined(AFX_READBARCODEDIALOG_H__09E6B9F8_921C_48CC_95D2_89D5C689EAD5__INCLUDED_)
#define AFX_READBARCODEDIALOG_H__09E6B9F8_921C_48CC_95D2_89D5C689EAD5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ReadBarCodeDialog.h : header file
//
#include <vector>
#include "OmdFile/TxtFile.h"

/////////////////////////////////////////////////////////////////////////////
// CReadBarCodeDialog dialog

class CReadBarCodeDialog : public CDialog
{
// Construction
	CString m_PathName;
	TxtStrData m_Barcodelsit;
	void InitBarCodeList();
public:
	CReadBarCodeDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CReadBarCodeDialog)
	enum { IDD = IDD_DIALOG_BARCODE };
	CStatic	m_stcBarCode;
	CComboBox	m_cbxNo;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReadBarCodeDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CReadBarCodeDialog)
	afx_msg void OnSelchangeComboSelno();
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_READBARCODEDIALOG_H__09E6B9F8_921C_48CC_95D2_89D5C689EAD5__INCLUDED_)
