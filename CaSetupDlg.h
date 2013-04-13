#if !defined(AFX_CASETUPDLG_H__BE5D64EA_9467_4284_B2C8_B1FF90213FA7__INCLUDED_)
#define AFX_CASETUPDLG_H__BE5D64EA_9467_4284_B2C8_B1FF90213FA7__INCLUDED_

#include "resource.h"
#include "MainFrm.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CaSetupDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCaSetupDlg dialog


class CCaSetupDlg : public CDialog
{
// Construction
public:
	CCaSetupDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCaSetupDlg)
	enum { IDD = IDD_CASETUP_DIALOG };
	CComboBox	m_cbxBrigUnit;
	CComboBox	m_cbxSynMode;
	CComboBox	m_cbxDisMode;
	CComboBox	m_cbxDisDigMode;
	CComboBox	m_cbxDisCalStand;
	CComboBox	m_cbxChNo;
	CComboBox	m_cbxChId;
	CComboBox	m_cbxAvgMode;
	CString	m_strCaType;
	CString	m_strCaVersion;
	CString	m_strCalMode;
	CString	m_strCalProb;
	CString	m_strProbSerialNo;
	CString	m_strRefLv;
	CString	m_strRefProb;
	CString	m_strRefSx;
	CString	m_strRefSy;
	float	m_fltRangeColor1;
	float	m_fltRangeColor2;
	float	m_fltRangeFlk;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCaSetupDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCaSetupDlg)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeComboChannelId();
	afx_msg void OnSelchangeComboChannelNumber();
	afx_msg void OnSelchangeComboDisplayMode();
	afx_msg void OnSelchangeComboSyncMode();
	afx_msg void OnSelchangeComboAveragingMode();
	afx_msg void OnSelchangeComboBrigUnit();
	afx_msg void OnSelchangeComboDisplayDigitsMode();
	afx_msg void OnSelchangeComboDisplayDefaultStd();
	virtual void OnCancel();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	Ca210* m_pCA210;
private:
	void dlgExit();
	void itemsUpdate();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CASETUPDLG_H__BE5D64EA_9467_4284_B2C8_B1FF90213FA7__INCLUDED_)
