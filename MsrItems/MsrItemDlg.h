#if !defined(AFX_MSRITEMDLG_H__AF6311F3_C6B9_4378_86DC_CC4BDF4C4184__INCLUDED_)
#define AFX_MSRITEMDLG_H__AF6311F3_C6B9_4378_86DC_CC4BDF4C4184__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MsrItemDlg.h : header file
//
#include <vector>
#include <algorithm>
#include "StaticText.h"

#include "../xMsrPoint/Nucleotide.h"
#include "../xMsrPoint/DNA.h"
#include "../RNA.h"
#include "../OmdFile/TxtFile.h"
/////////////////////////////////////////////////////////////////////////////
// CMsrItemDlg dialog

class CMsrItemDlg : public CDialog
{
#ifdef _DEBUG
	std::vector<CString> m_dTxt;
	CString m_desktopPath;
#endif // _DEBUG

	CString m_RememberChkPathName;
	DNA m_DNA;
	RNA m_RNA;

// Construction
public:
    CMsrItemDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
    //{{AFX_DATA(CMsrItemDlg)
	enum { IDD = IDD_MSR_ITEM };
	CComboBox	m_cbxSelNitsKind;
	CButton	m_chkJND;
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
    float    m_f21Havg;
    float    m_f21Vavg;
    float    m_f25FE;
    float    m_f5FE;
    float    m_f9FE;
	float    m_f13FE;
    float    m_fGammaSetp;
    UINT     m_n25RectSide;
    float    m_fCrsTlkRectFE;
    float    m_fNits;
	UINT	m_JndGray;
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
    afx_msg void OnPaint();
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonDel();
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnButtonSelall();
	afx_msg void OnButtonSelno();
	virtual void OnCancel();
	//}}AFX_MSG
    DECLARE_MESSAGE_MAP()
    // Generated OLE dispatch map functions
    //{{AFX_DISPATCH(CMsrItemDlg)
        // NOTE - the ClassWizard will add and remove member functions here.
    //}}AFX_DISPATCH
    DECLARE_DISPATCH_MAP()
    DECLARE_INTERFACE_MAP()
private:
	void listBoxUpdate();
    void selMsrItem2DNA_sortable(DNA&);
    void selMsrItem2DNA_Unsortable(DNA&);
	void rememberSelMsrItems();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MSRITEMDLG_H__AF6311F3_C6B9_4378_86DC_CC4BDF4C4184__INCLUDED_)
