// ColorEyeI.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "ColorEyeI.h"

#include "MainFrm.h"
#include "ColorEyeIDoc.h"
#include "ColorEyeIView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CColorEyeIApp

BEGIN_MESSAGE_MAP(CColorEyeIApp, CWinApp)
    //{{AFX_MSG_MAP(CColorEyeIApp)
    ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	ON_COMMAND(ID_FILE_OMDTOXLS, OnFileOmdtoxls)
	ON_COMMAND(ID_MSR_ITEM, OnMsrForItem)
	//}}AFX_MSG_MAP
    // Standard file based document commands
    ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
    ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CColorEyeIApp construction

CColorEyeIApp::CColorEyeIApp():m_pdlgPattern(0)
{
    // TODO: add construction code here,
    // Place all significant initialization in InitInstance
}

CColorEyeIApp::~CColorEyeIApp()
{
	DelMsrItemDlgSetupFile();
    delete m_pdlgPattern;
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CColorEyeIApp object

CColorEyeIApp theApp;

// This identifier was generated to be statistically unique for your app.
// You may change it if you prefer to choose a specific identifier.

// {A4787937-49BE-4EDE-980D-3D4414E82EC8}
static const CLSID clsid =
{ 0xa4787937, 0x49be, 0x4ede, { 0x98, 0xd, 0x3d, 0x44, 0x14, 0xe8, 0x2e, 0xc8 } };

/////////////////////////////////////////////////////////////////////////////
// CColorEyeIApp initialization

BOOL CColorEyeIApp::InitInstance()
{
    // Initialize OLE libraries
    if (!AfxOleInit())
    {
        AfxMessageBox(IDP_OLE_INIT_FAILED);
        return FALSE;
    }

    AfxEnableControlContainer();

    // Standard initialization
    // If you are not using these features and wish to reduce the size
    //  of your final executable, you should remove from the following
    //  the specific initialization routines you do not need.

#ifdef _AFXDLL
    Enable3dControls();            // Call this when using MFC in a shared DLL
#else
    Enable3dControlsStatic();    // Call this when linking to MFC statically
#endif

    // Change the registry key under which our settings are stored.
    // TODO: You should modify this string to be something appropriate
    // such as the name of your company or organization.
    SetRegistryKey(_T("Local AppWizard-Generated Applications"));

    LoadStdProfileSettings();  // Load standard INI file options (including MRU)

    // Register the application's document templates.  Document templates
    //  serve as the connection between documents, frame windows and views.

    CSingleDocTemplate* pDocTemplate;
    pDocTemplate = new CSingleDocTemplate(
        IDR_MAINFRAME,
        RUNTIME_CLASS(CColorEyeIDoc),
        RUNTIME_CLASS(CMainFrame),       // main SDI frame window
        RUNTIME_CLASS(CColorEyeIView));
    AddDocTemplate(pDocTemplate);

    // Connect the COleTemplateServer to the document template.
    //  The COleTemplateServer creates new documents on behalf
    //  of requesting OLE containers by using information
    //  specified in the document template.
    m_server.ConnectTemplate(clsid, pDocTemplate, TRUE);
        // Note: SDI applications register server objects only if /Embedding
        //   or /Automation is present on the command line.

    // Enable DDE Execute open
    EnableShellOpen();
    RegisterShellFileTypes(TRUE);

    // Parse command line for standard shell commands, DDE, file open
    CCommandLineInfo cmdInfo;
    ParseCommandLine(cmdInfo);

    // Check to see if launched as OLE server
    if (cmdInfo.m_bRunEmbedded || cmdInfo.m_bRunAutomated)
    {
        // Register all OLE server (factories) as running.  This enables the
        //  OLE libraries to create objects from other applications.
        COleTemplateServer::RegisterAll();

        // Application was run with /Embedding or /Automation.  Don't show the
        //  main window in this case.
        return TRUE;
    }

    // When a server application is launched stand-alone, it is a good idea
    //  to update the system registry in case it has been damaged.
    m_server.UpdateRegistry(OAT_DISPATCH_OBJECT);
    COleObjectFactory::UpdateRegistryAll();

    // Dispatch commands specified on the command line
    if (!ProcessShellCommand(cmdInfo))
        return FALSE;

    // The one and only window has been initialized, so show and update it.
    m_pMainWnd->ShowWindow(SW_SHOW);
    m_pMainWnd->UpdateWindow();

    // Enable drag/drop open
    m_pMainWnd->DragAcceptFiles();

	// Get App PathName
	GetModuleFileName(NULL, m_strPathName.GetBuffer(MAX_PATH+1), MAX_PATH);  //抓應用程式所在的目錄+檔名+副檔名
	m_strPathName.ReleaseBuffer();   //要加這一行，才可以處理該字串

	// Get Desktop Path
// 	CString szPath;
// 	SHGetSpecialFolderPath(NULL, szPath, CSIDL_DESKTOP, 0);//取得桌面路徑
//    BCFandODFPath.Format("%s",szPath);

    return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
    CAboutDlg();

// Dialog Data
    //{{AFX_DATA(CAboutDlg)
    enum { IDD = IDD_ABOUTBOX };
    //}}AFX_DATA

    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CAboutDlg)
    protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    //}}AFX_VIRTUAL

// Implementation
protected:
    //{{AFX_MSG(CAboutDlg)
        // No message handlers
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
    //{{AFX_DATA_INIT(CAboutDlg)
    //}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CAboutDlg)
    //}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
    //{{AFX_MSG_MAP(CAboutDlg)
        // No message handlers
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CColorEyeIApp::OnAppAbout()
{
    CAboutDlg aboutDlg;
    aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CColorEyeIApp message handlers

void CColorEyeIApp::OnFileOmdtoxls() 
{
	// TODO: Add your command handler code here
	CSelExcelDlg dlgSelExcel;
	dlgSelExcel.DoModal();
}

void CColorEyeIApp::OnMsrForItem() 
{
	// TODO: Add your command handler code here
    //為Pattern Dialog初始化，做準備
    if (m_pdlgPattern != 0)
        delete m_pdlgPattern;
	
    //若執行m_pMsrItemDlg.XXX的時候，傳輸控制項的東西，就會崩潰（程式執行失敗）
    //執行開啟PattenDialog的Code
    //把vChain放進去
	
    m_pdlgPattern = new CPatternDlg(MsrForItem);  //初始化Pattern Dialog，可以呼叫MsrForItem等對話框出來初始化vChain
    if (m_pdlgPattern->isReady())
    {
        if (!m_pdlgPattern->Create(IDD_PATTERN_DIALOG))   AfxMessageBox("CColorEyeIView::PatternDialog.Create() 出錯啦！\n剪下圖片，並通知程式設計師");
        if (!m_pdlgPattern->Magazine())                   AfxMessageBox("OnButtonMsr的彈匣出錯");
        m_pdlgPattern->ShowWindow(SW_MAXIMIZE);
    }
}

CString CColorEyeIApp::GetPathName()
{
	return m_strPathName;
}

CString CColorEyeIApp::GetPath()
{
	return m_strPathName.Left(m_strPathName.ReverseFind('\\'));
}

void CColorEyeIApp::DelMsrItemDlgSetupFile()
{
	CString delFileNamePath;
	delFileNamePath.Format("%s\\~MsrItemDlg.temp", GetPath());
	DeleteFile(delFileNamePath);
}
