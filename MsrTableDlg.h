#if !defined(AFX_CMsrTableDlg_H__183594A8_2114_4DF9_B849_ADFD19EBABE8__INCLUDED_)
#define AFX_CMsrTableDlg_H__183594A8_2114_4DF9_B849_ADFD19EBABE8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MsrTableDlg.h : header file
//
#include "Btm.h"
#include "DNA.h"
#include "RNA.h"
#include "DnaConfig.h"

/////////////////////////////////////////////////////////////////////////////
// CMsrTableDlg dialog

class CMsrTableDlg : public CDialog
{
	DnaConfig m_dnaConfig;
	DNA m_DNA;
	RNA m_RNA;
	tableIndex m_TableIndex;
	const CString descripTableRA;
	const CString descripTableSECfrom;
	const CString descripTableQOCmassSEC;
	const CString descripTableQOCmassTPV;
	const CString descripTableQOCmassNibo;
	const CString descripTableQOCtest;
	void showTableImage(CPaintDC* pDc);
	void showMsrItem(CPaintDC* pDc);
	const UINT tableID() const;
	const CString tableDescrip() const;

// Construction
public:
	void Exit();
	void SetTableImage(const tableIndex&);
	CMsrTableDlg(CWnd* pParent = NULL);   // standard constructor


// Dialog Data
	//{{AFX_DATA(CMsrTableDlg)
	enum { IDD = IDD_MSR_TABLE };
	CBtm	m_tableOQCNibo;
	CBtm	m_tableSECF;
	CBtm	m_tableRA;
	CBtm	m_tableOQCTPV;
	CBtm	m_tableOQCtest;
	CBtm	m_tableOQCSEC;
	CStatic	m_tableDescrip;
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
	afx_msg void OnPaint();
	afx_msg void OnBtnOqcNibo();
	afx_msg void OnBtnOqcSec();
	afx_msg void OnBtnRa();
	afx_msg void OnBtnSecfrom();
	afx_msg void OnBtnOqcTest();
	afx_msg void OnBtnOqcTpv();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CMSRTABLEDLG_H__183594A8_2114_4DF9_B849_ADFD19EBABE8__INCLUDED_)
