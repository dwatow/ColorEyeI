// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__2970A856_005B_4639_95B2_3A4ACB1939A4__INCLUDED_)
#define AFX_MAINFRM_H__2970A856_005B_4639_95B2_3A4ACB1939A4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//#include "xMsrPoint/CA210.h"
#include "CA210sim.h"
#include "CA210real.h"

class CMainFrame : public CFrameWnd
{
    BOOL m_iConnectCa210;
    BOOL m_iOnlineCa210;
public:
    Ca210* m_pCa210;

protected: // create from serialization only
    CMainFrame();
    DECLARE_DYNCREATE(CMainFrame)

// Attributes
public:

// Operations
public:

// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CMainFrame)
    virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
    //}}AFX_VIRTUAL

// Implementation
public:
    virtual ~CMainFrame();
#ifdef _DEBUG
    virtual void AssertValid() const;
    virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
    CStatusBar  m_wndStatusBar;
    CToolBar    m_wndToolBar;

// Generated message map functions
protected:
    //{{AFX_MSG(CMainFrame)
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnMsrConnectca210();
    afx_msg void OnUpdateMsrItem(CCmdUI* pCmdUI);
    afx_msg void OnDestroy();
    afx_msg void OnUpdateMsrConnectca210(CCmdUI* pCmdUI);
    afx_msg void OnAppExit();
	afx_msg void OnCntUSBUI(CCmdUI  *pCmdUI);
	afx_msg void OnResolutionUI(CCmdUI  *pCmdUI);
	afx_msg void OnUpdateSetupCa210(CCmdUI* pCmdUI);
	//}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__2970A856_005B_4639_95B2_3A4ACB1939A4__INCLUDED_)
