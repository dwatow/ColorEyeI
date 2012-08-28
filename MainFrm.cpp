// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "ColorEyeI.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
    //{{AFX_MSG_MAP(CMainFrame)
    ON_WM_CREATE()
    ON_COMMAND(ID_MSR_CONNECTCA210, OnMsrConnectca210)
    ON_UPDATE_COMMAND_UI(ID_MSR_ITEM, OnUpdateMsrItem)
    ON_WM_DESTROY()
    ON_UPDATE_COMMAND_UI(ID_MSR_CONNECTCA210, OnUpdateMsrConnectca210)
    ON_UPDATE_COMMAND_UI(ID_INDICATOR_USB, OnCntUSBUI)
    ON_UPDATE_COMMAND_UI(ID_INDICATOR_RES, OnResolutionUI)
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
    ID_SEPARATOR,           // status line indicator
//     ID_INDICATOR_CAPS,
//     ID_INDICATOR_NUM,
//     ID_INDICATOR_SCRL,
    ID_INDICATOR_USB,
    ID_INDICATOR_RES,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
    // TODO: add member initialization code here
    m_pCa210 = 0;
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
        return -1;
    
    if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
        | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
        !m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
    {
        TRACE0("Failed to create toolbar\n");
        return -1;      // fail to create
    }

    if (!m_wndStatusBar.Create(this) ||
        !m_wndStatusBar.SetIndicators(indicators,
          sizeof(indicators)/sizeof(UINT)))
    {
        TRACE0("Failed to create status bar\n");
        return -1;      // fail to create
    }

    // TODO: Delete these three lines if you don't want the toolbar to
    //  be dockable
    m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
    EnableDocking(CBRS_ALIGN_ANY);
    DockControlBar(&m_wndToolBar);

    return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
    if( !CFrameWnd::PreCreateWindow(cs) )
        return FALSE;
    // TODO: Modify the Window class or styles here by modifying
    //  the CREATESTRUCT cs
    m_iConnectCa210 = m_iOnlineCa210 = FALSE;

    return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
    CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
    CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers

void CMainFrame::OnMsrConnectca210() 
{
    // TODO: Add your command handler code here
    if (!m_iConnectCa210)
    {
//        m_pCa210 = new Ca210(TRUE);
        m_pCa210 = new Ca210(FALSE);
        m_iConnectCa210 = TRUE;
        m_iOnlineCa210 = FALSE;
    }

    m_pCa210->SetOnline(m_iOnlineCa210);
}

void CMainFrame::OnCntUSBUI(CCmdUI  *pCmdUI)
{
    pCmdUI->SetText(m_iConnectCa210 ? "USB設定完成" : "USB尚未設定");
}

void CMainFrame::OnResolutionUI(CCmdUI  *pCmdUI)
{
    CString str;
    str.Format("%d×%d",GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));
    pCmdUI->SetText(str);
}

void CMainFrame::OnUpdateMsrConnectca210(CCmdUI* pCmdUI) 
{
    // TODO: Add your command update UI handler code here
    pCmdUI->SetCheck( (!m_iConnectCa210) ? FALSE : m_iConnectCa210);
}

void CMainFrame::OnUpdateMsrItem(CCmdUI* pCmdUI) 
{
    // TODO: Add your command update UI handler code here
    pCmdUI->Enable(m_iConnectCa210);
}
void CMainFrame::OnDestroy() 
{
    CFrameWnd::OnDestroy();
    // TODO: Add your message handler code here
    delete    m_pCa210;
}


