// MsrItemsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MsrItems.h"
#include "MsrItemsDlg.h"
#include "DlgProxy.h"
#include "MsrItemDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

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

/////////////////////////////////////////////////////////////////////////////
// CMsrItemsDlg dialog

IMPLEMENT_DYNAMIC(CMsrItemsDlg, CDialog);

CMsrItemsDlg::CMsrItemsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMsrItemsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMsrItemsDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pAutoProxy = NULL;
}

CMsrItemsDlg::~CMsrItemsDlg()
{
	// If there is an automation proxy for this dialog, set
	//  its back pointer to this dialog to NULL, so it knows
	//  the dialog has been deleted.
	if (m_pAutoProxy != NULL)
		m_pAutoProxy->m_pDialog = NULL;
}

void CMsrItemsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMsrItemsDlg)
	DDX_Control(pDX, IDC_CHECK9, m_btn9);
	DDX_Control(pDX, IDC_CHECK8, m_btn8);
	DDX_Control(pDX, IDC_CHECK7, m_btn7);
	DDX_Control(pDX, IDC_CHECK6, m_btn6);
	DDX_Control(pDX, IDC_CHECK5, m_btn5);
	DDX_Control(pDX, IDC_CHECK4, m_btn4);
	DDX_Control(pDX, IDC_CHECK3, m_btn3);
	DDX_Control(pDX, IDC_CHECK11, m_btn11);
	DDX_Control(pDX, IDC_CHECK2, m_btn2);
	DDX_Control(pDX, IDC_CHECK10, m_btn10);
	DDX_Control(pDX, IDC_CHECK1, m_btn1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMsrItemsDlg, CDialog)
	//{{AFX_MSG_MAP(CMsrItemsDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMsrItemsDlg message handlers

BOOL CMsrItemsDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

 	m_btn1.SetButtonStyle(BS_PUSHBUTTON);


 	m_btn2.SetButtonStyle(BS_DEFPUSHBUTTON);
 	m_btn3.SetButtonStyle(BS_CHECKBOX);
 	m_btn4.SetButtonStyle(BS_AUTOCHECKBOX);
 	m_btn5.SetButtonStyle(BS_RADIOBUTTON);
 	m_btn6.SetButtonStyle(BS_3STATE);
 	m_btn7.SetButtonStyle(BS_AUTO3STATE);
 	m_btn8.SetButtonStyle(BS_GROUPBOX);
 	m_btn9.SetButtonStyle(BS_USERBUTTON);
 	m_btn10.SetButtonStyle(BS_AUTORADIOBUTTON);
 	m_btn11.SetButtonStyle(BS_LEFTTEXT);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMsrItemsDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMsrItemsDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMsrItemsDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

// Automation servers should not exit when a user closes the UI
//  if a controller still holds on to one of its objects.  These
//  message handlers make sure that if the proxy is still in use,
//  then the UI is hidden but the dialog remains around if it
//  is dismissed.

void CMsrItemsDlg::OnClose() 
{
	if (CanExit())
		CDialog::OnClose();
}

void CMsrItemsDlg::OnOK() 
{
	if (CanExit())
		CDialog::OnOK();
}

void CMsrItemsDlg::OnCancel() 
{
	if (CanExit())
		CDialog::OnCancel();
}

BOOL CMsrItemsDlg::CanExit()
{
	// If the proxy object is still around, then the automation
	//  controller is still holding on to this application.  Leave
	//  the dialog around, but hide its UI.
	if (m_pAutoProxy != NULL)
	{
		ShowWindow(SW_HIDE);
		return FALSE;
	}

	return TRUE;
}

void CMsrItemsDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	std::vector<Cartridge> vcar;


	CMsrItemDlg MIDlg;
	if (MIDlg.DoModal() == IDOK)
	{
		MIDlg.Ready(vcar);
	}
	
}

