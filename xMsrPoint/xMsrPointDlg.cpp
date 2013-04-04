// xMsrPointDlg.cpp : implementation file
//

#include "stdafx.h"
#include "xMsrPoint.h"
#include "xMsrPointDlg.h"
#include "DlgProxy.h"
#include "comdef.h"
#include <vector>

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
	public:
// 	virtual BOOL PreTranslateMessage(MSG* pMsg);
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
// CXMsrPointDlg dialog

IMPLEMENT_DYNAMIC(CXMsrPointDlg, CDialog);

CXMsrPointDlg::CXMsrPointDlg(CWnd* pParent /*=NULL*/)
	:CDialog(CXMsrPointDlg::IDD, pParent)//,,m_W49(chain1, White , Pn49)	
	//	m_CA210(TRUE)
	//	m_CA210(FALSE)
{
	//{{AFX_DATA_INIT(CXMsrPointDlg)
	m_strDu = _T("");
	m_strDuv = _T("");
	m_strDv = _T("");
	m_strLv = _T("");
	m_strSx = _T("");
	m_strSy = _T("");
	m_strT = _T("");
	m_strX = _T("");
	m_strY = _T("");
	m_strZ = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pAutoProxy = NULL;
}

CXMsrPointDlg::~CXMsrPointDlg()
{
	// If there is an automation proxy for this dialog, set
	//  its back pointer to this dialog to NULL, so it knows
	//  the dialog has been deleted.

	if (m_pAutoProxy != NULL)
		m_pAutoProxy->m_pDialog = NULL;
}

void CXMsrPointDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CXMsrPointDlg)
	DDX_Control(pDX, IDC_SLIDER1, m_sldViewControl);
	DDX_Text(pDX, IDC_STATIC_DU , m_strDu);
	DDX_Text(pDX, IDC_STATIC_DUV, m_strDuv);
	DDX_Text(pDX, IDC_STATIC_DV , m_strDv);
	DDX_Text(pDX, IDC_STATIC_L  , m_strLv);
	DDX_Text(pDX, IDC_STATIC_SX , m_strSx);
	DDX_Text(pDX, IDC_STATIC_SY , m_strSy);
	DDX_Text(pDX, IDC_STATIC_T  , m_strT);
	DDX_Text(pDX, IDC_STATIC_X  , m_strX);
	DDX_Text(pDX, IDC_STATIC_Y  , m_strY);
	DDX_Text(pDX, IDC_STATIC_Z  , m_strZ);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CXMsrPointDlg, CDialog)
	//{{AFX_MSG_MAP(CXMsrPointDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_MSR, OnButtonMsr)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER1, OnReleasedcaptureSlider1)
	ON_WM_CLOSE()
	ON_WM_KEYDOWN()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CXMsrPointDlg message handlers

BOOL CXMsrPointDlg::OnInitDialog()
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
	m_sldViewControl.EnableWindow(FALSE);
// 	m_pCA210 = 0;

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CXMsrPointDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CXMsrPointDlg::OnPaint() 
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
HCURSOR CXMsrPointDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

// Automation servers should not exit when a user closes the UI
//  if a controller still holds on to one of its objects.  These
//  message handlers make sure that if the proxy is still in use,
//  then the UI is hidden but the dialog remains around if it
//  is dismissed.


BOOL CXMsrPointDlg::CanExit()
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

void CXMsrPointDlg::OnButtonMsr() 
{
	// TODO: Add your control notification handler code here
// 	if (m_pCA210 == 0)
// 	{
// 		p_PtnDlg = new CPatternDlg;
// 		//m_pCA210 = new Ca210(TRUE);
// 		m_pCA210 = new Ca210(FALSE);
// 		
// 		if (!p_PtnDlg->ConnectCa210(m_pCA210))
// 			MessageBox("OnButtonMsr的CA-210連線錯誤");
// 		p_PtnDlg->Create(IDD_PATTERN_DIALOG);
// 
// 		vChain1.clear();
// 		Cartridge x;
// 		vChain1.push_back(x);
// 		
// 		//  Cartridge R1(Red, Pn1);
// 		// 	Cartridge G1(Green, Pn1);
// 		// 	Cartridge B1(Blue, Pn1);
// 		// 	Cartridge W9(White, Pn9);
// 		// 	Cartridge D25(Dark, Pn25);
// 		// 	Cartridge W49(White, Pn49);
// 		Cartridge nits(Nits, Pn9);
// 		
// 		
// 		//  p_PtnDlg->Partition(vChain1, R1);
// 		// 	p_PtnDlg->Partition(vChain1, G1);
// 		// 	p_PtnDlg->Partition(vChain1, B1);
// 		// 
// 		// 	p_PtnDlg->Partition(vChain1, W9);
// 		// 	p_PtnDlg->Partition(vChain1, D25);
// 		// 	p_PtnDlg->Partition(vChain1, W49);
// 		p_PtnDlg->Partition(vChain1, nits);
// 		//	p_PtnDlg->Partition(vChain1, W5);
// 		
// 		//ReadyFire
// 		m_sldViewControl.SetRangeMin(0);
// 		m_sldViewControl.SetRangeMax(vChain1.size()-1);
// 		m_sldViewControl.EnableWindow(TRUE);
// 		
// 		QuackMsrSort(vChain1);
// 	}
// 	else
// 	{
// 		m_pCA210->SetOnline(TRUE);
// 	}
// 
// 	if(!p_PtnDlg->Magazine(vChain1))	MessageBox("OnButtonMsr的彈匣出錯");
// 
// 	p_PtnDlg->ShowWindow(SW_MAXIMIZE);
}

void CXMsrPointDlg::OnReleasedcaptureSlider1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
// 	std::vector<Cartridge>::size_type i = (std::vector<Cartridge>::size_type)(m_sldViewControl.GetPos());
// 
// 	m_strLv.Format("Lv:%3.2f", vChain1.at(i).GetLv());
// 	m_strSx.Format("x:%1.4f", vChain1.at(i).GetSx());
// 	m_strSy.Format("y:%1.4f", vChain1.at(i).GetSy());
// 	
// 	m_strT.Format("T:%4d", vChain1.at(i).GetT());
// 	m_strDuv.Format("Δuv:%1.4f", vChain1.at(i).GetDuv());
// 	
// 	m_strDu.Format("Δu:%1.4f", vChain1.at(i).GetDu());
// 	m_strDv.Format("Δv:%1.4f", vChain1.at(i).GetDv());
// 	
// 	m_strX.Format("X:%3.2f", vChain1.at(i).GetX());
// 	m_strY.Format("Y:%3.2f", vChain1.at(i).GetY());
// 	m_strZ.Format("Z:%3.2f", vChain1.at(i).GetZ());
// 
// 	UpdateData(FALSE);
	*pResult = 0;
}

void CXMsrPointDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
/*	delete m_pCA210;*/	
}

/////////////////////////////////////////////////////////////////////////////
//sort function

// bool CXMsrPointDlg::AreaPriority(const Cartridge &sp1, const Cartridge &sp2)
// {
//     return (sp1.GetArea() < sp2.GetArea()) ? 1 : 0;
// }
// 
// bool CXMsrPointDlg::OrigPriority(const Cartridge &sp1, const Cartridge &sp2)
// {
//     return (sp1.GetOrigSeqc() < sp2.GetOrigSeqc()) ? 1 : 0;
// }
// 
// 
// void CXMsrPointDlg::QuackMsrSort(std::vector<Cartridge>& vCar) const
// {
// 	std::sort(vCar.begin(), vCar.end(), AreaPriority);
// }
// 
// void CXMsrPointDlg::OrigMsrSort(std::vector<Cartridge>& vCar) const
// {
// 	std::sort(vCar.begin(), vCar.end(), OrigPriority);
// }
