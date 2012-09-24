#if !defined(AFX_MSRITEMDLG_H__AF6311F3_C6B9_4378_86DC_CC4BDF4C4184__INCLUDED_)
#define AFX_MSRITEMDLG_H__AF6311F3_C6B9_4378_86DC_CC4BDF4C4184__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MsrItemDlg.h : header file
//
#include <algorithm>
#include <vector>
#include "StaticText.h"
#include "../xMsrPoint/Bolt.h"   //生成chain用的function
//#include "../xMsrPoint/PatternDlg.h"
//可以調整成只要Bolt進來
#include "../MainFrm.h"
#include "../ColorEyeIDoc.h"

/////////////////////////////////////////////////////////////////////////////
// CMsrItemDlg dialog

class CMsrItemDlg : public CDialog
{
//    CPatternDlg* m_pDlgPattern;
	CString m_filePathName;
    Bolt *Pusher;

// Construction
public:
    CMsrItemDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
    //{{AFX_DATA(CMsrItemDlg)
	enum { IDD = IDD_MSR_ITEM };
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
    afx_msg void OnPaint();
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonDel();
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
    DECLARE_MESSAGE_MAP()
    // Generated OLE dispatch map functions
    //{{AFX_DISPATCH(CMsrItemDlg)
        // NOTE - the ClassWizard will add and remove member functions here.
    //}}AFX_DISPATCH
    DECLARE_DISPATCH_MAP()
    DECLARE_INTERFACE_MAP()
public:
    void SetBolt(Bolt* Pusher);  //在CPatternDlg::InitDataDlgType()有用到
	unsigned int ListBoxUpdate(const CDataChain& );
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MSRITEMDLG_H__AF6311F3_C6B9_4378_86DC_CC4BDF4C4184__INCLUDED_)
