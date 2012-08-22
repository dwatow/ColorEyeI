// MsrItemsDlg.h : header file
//

#if !defined(AFX_MSRITEMSDLG_H__164BFD00_E85D_47D8_9621_AEB101AC0245__INCLUDED_)
#define AFX_MSRITEMSDLG_H__164BFD00_E85D_47D8_9621_AEB101AC0245__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMsrItemsDlgAutoProxy;

/////////////////////////////////////////////////////////////////////////////
// CMsrItemsDlg dialog

class CMsrItemsDlg : public CDialog
{
    DECLARE_DYNAMIC(CMsrItemsDlg);
    friend class CMsrItemsDlgAutoProxy;

// Construction
public:
    CMsrItemsDlg(CWnd* pParent = NULL);    // standard constructor
    virtual ~CMsrItemsDlg();

// Dialog Data
    //{{AFX_DATA(CMsrItemsDlg)
    enum { IDD = IDD_MSRITEMS_DIALOG };
    CButton    m_btn9;
    CButton    m_btn8;
    CButton    m_btn7;
    CButton    m_btn6;
    CButton    m_btn5;
    CButton    m_btn4;
    CButton    m_btn3;
    CButton    m_btn11;
    CButton    m_btn2;
    CButton    m_btn10;
    CButton    m_btn1;
    //}}AFX_DATA

    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CMsrItemsDlg)
    public:
    //virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
    protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    //}}AFX_VIRTUAL

// Implementation
protected:
    CMsrItemsDlgAutoProxy* m_pAutoProxy;
    HICON m_hIcon;

    BOOL CanExit();

    // Generated message map functions
    //{{AFX_MSG(CMsrItemsDlg)
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

#endif // !defined(AFX_MSRITEMSDLG_H__164BFD00_E85D_47D8_9621_AEB101AC0245__INCLUDED_)
