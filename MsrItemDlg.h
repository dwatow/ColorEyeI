#if !defined(AFX_MSRITEMDLG_H__DEC35ECB_1464_43F7_9CCB_1997DF3C7F5D__INCLUDED_)
#define AFX_MSRITEMDLG_H__DEC35ECB_1464_43F7_9CCB_1997DF3C7F5D__INCLUDED_

#include <vector>
#include <algorithm>
#include "StaticText.h"
#include "debugFile.h"

#include "Nucleotide.h"
#include "DNA.h"
#include "RNA.h"
#include "TxtFile.h"

#include "DnaConfig.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MsrItemDlg.h : header file
//
/////////////////////////////////////////////////////////////////////////////
// CMsrItemDlg dialog

class CMsrItemDlg : public CDialog
{
// Construction
public:
	CMsrItemDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMsrItemDlg)
	enum { IDD = IDD_MSR_ITEM };
	CSpinButtonCtrl	m_spinP9Para;
	CStatic	m_p9_Ncm;
	CStatic	m_p9_1overN;
	CComboBox	m_cbxSelNitsKind;
	CButton	m_btnOK;
	CButton	m_btnDelItems;
	CButton	m_btnAddItems;
	CListBox	m_lstMsrItems;
    CButton    m_chkCBP21;
    CButton    m_chkCDP21;
    CButton    m_chkCGP21;
    CButton    m_chkCWP21;
    CButton    m_chkCRP21;
    CButton    m_chkQuickMsr;
    CButton    m_chkCrossTalk;
    CButton    m_chkNits;
    CButton    m_chkCWP9;
    CButton    m_chkCWP5;
    CButton    m_chkCWP49;
    CButton    m_chkCWP25;
    CButton    m_chkCWP13;
    CButton    m_chkCWGM;
    CButton    m_chkCRP9;
    CButton    m_chkCRP5;
    CButton    m_chkCRP49;
    CButton    m_chkCRP25;
    CButton    m_chkCRP13;
    CButton    m_chkCRGM;
    CButton    m_chkCGP9;
    CButton    m_chkCGP5;
    CButton    m_chkCGP49;
    CButton    m_chkCGP25;
    CButton    m_chkCGP13;
    CButton    m_chkCGGM;
    CButton    m_chkCDP9;
    CButton    m_chkCDP5;
    CButton    m_chkCDP49;
    CButton    m_chkCDP25;
    CButton    m_chkCDP13;
    CButton    m_chkCDGM;
    CButton    m_chkCBP9;
    CButton    m_chkCBP5;
    CButton    m_chkCBP49;
    CButton    m_chkCBP25;
    CButton    m_chkCBP13;
    CButton    m_chkCBGM;
    CButton    m_chkCWP1;
    CButton    m_chkCRP1;
    CButton    m_chkCGP1;
    CButton    m_chkCDP1;
    CButton    m_chkCBP1;
    CStaticText    m_stcWhite;
    CStaticText    m_stcBlue;
    CStaticText    m_stcDark;
    CStaticText    m_stcGreen;
    CStaticText    m_stcRed;
    UINT    m_nGM1;
    UINT    m_nGM2;
    float    m_f21FE;
    float    m_f25FE;
    float    m_f5FE;
    float    m_f9FE;
	float    m_f13FE;
    float    m_fGammaSetp;
    UINT     m_n25RectSide;
    float    m_fCrsTlkRectFE;
    float    m_fNits;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMsrItemDlg)
	public:
	virtual void Serialize(CArchive& ar);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMsrItemDlg)
    afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonDel();
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnButtonSelall();
	afx_msg void OnButtonSelno();
	virtual void OnCancel();
	afx_msg void OnDeltaposSwP9fe(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	FEtype m_W9FEtype;
	debugFile m_debugLog;
	CString m_desktopPath;
	
	CString m_RememberChkPathName;
// 	DnaConfig m_DnaInit;
	DNA m_DNA;
	RNA m_RNA;
private:
	void listBoxUpdate();
//     void selMsrItem2DNA_sortable(DNA&);
//     void selMsrItem2DNA_Unsortable(DNA&);
	void SetupDnaConfig(DnaConfig&);
	void rememberSelMsrItems();
	BOOL checkMsrParaOK();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MSRITEMDLG_H__DEC35ECB_1464_43F7_9CCB_1997DF3C7F5D__INCLUDED_)
