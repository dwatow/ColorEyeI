<<<<<<< HEAD
// OmdFileDlg.cpp : implementation file
//

#include "stdafx.h"

#include "OmdFile.h"
#include "OmdFile1.h"
#include "OmdFileDlg.h"
#include <algorithm>

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
// COmdFileDlg dialog

COmdFileDlg::COmdFileDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COmdFileDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(COmdFileDlg)
	m_str = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COmdFileDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COmdFileDlg)
	DDX_Control(pDX, IDC_COMBO1, m_cmbCartridgeChoose);
	DDX_Text(pDX, IDC_STATIC_TERMINAL, m_str);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(COmdFileDlg, CDialog)
	//{{AFX_MSG_MAP(COmdFileDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COmdFileDlg message handlers

BOOL COmdFileDlg::OnInitDialog()
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
	m_cmbCartridgeChoose.EnableWindow(FALSE);

	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void COmdFileDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void COmdFileDlg::OnPaint() 
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
HCURSOR COmdFileDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void COmdFileDlg::SetOrigPriority(std::vector<Cartridge>& vCar)
{
	std::vector<Cartridge>::size_type OrigPrty;
	for (std::vector<Cartridge>::iterator itor = vCar.begin(); itor != vCar.end() ; ++itor)
	{
		OrigPrty = itor - vCar.begin();
		itor->SetOrigSeqc(OrigPrty);
	}
}

void COmdFileDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
/*
// txt版
	CString strFilter = "Data Files (*.omd)|*.omd|All Files (*.*)|*.*||";//檔案過濾條件
	CFileDialog aFileDialog (TRUE, "omd", "*.omd", OFN_SHAREAWARE | OFN_OVERWRITEPROMPT, strFilter);
	
	int nID = aFileDialog.DoModal();
	if (nID == IDOK)
	{
		f_txt = new CTxtFile;
		f_txt->Open(aFileDialog.GetPathName());

	CString temp;
	temp.Format("LineNum = %d\n%s", f_txt->GetLineNum(), f_txt->GetLine(3));
	MessageBox(temp);
	}
*/

// Omd版
	vChain1.clear();
	
	Cartridge W1(White , Pn1);
	Cartridge R1(Red   , Pn1);
	Cartridge G1(Green , Pn1);
	Cartridge B1(Blue  , Pn1);
	Cartridge W9(  White, Pn9);
	Cartridge W49( White, Pn49);
	Cartridge nits(Nits,  Pn9);
	Cartridge D9(  Dark,  Pn9);
	Cartridge D25( Dark,  Pn25);
	
	SimPtnDlg.Partition(vChain1, W1);
	SimPtnDlg.Partition(vChain1, R1);
	SimPtnDlg.Partition(vChain1, G1);
	SimPtnDlg.Partition(vChain1, B1);
	
	SimPtnDlg.Partition(vChain1, W9);
	SimPtnDlg.Partition(vChain1, nits);
	SimPtnDlg.Partition(vChain1, D9);
	SimPtnDlg.Partition(vChain1, D25);
	SimPtnDlg.Partition(vChain1, W49);

	//SetOrigPriority(vChain1); //記得現在的順序
	
	CString strFilter  = "OrigMsrData Files (*.omd)|*.omd|All Files (*.*)|*.*||";//檔案過濾條件
	CFileDialog aFileDialog (TRUE, "omd", "*.omd", OFN_SHAREAWARE | OFN_OVERWRITEPROMPT, strFilter);
	int nID = aFileDialog.DoModal();

	if (nID == IDOK)
	{
		//Load Omd Data
		f_Omd = new COmdFile1(vChain1);
		f_Omd->Open(aFileDialog.GetPathName());

		//Make Interface Index
		for (UINT i = 0; i < f_Omd->GetIdxNum(); ++i)
 			m_cmbCartridgeChoose.AddString(f_Omd->GetIndex(i));
		m_cmbCartridgeChoose.SetCurSel(0);
		m_cmbCartridgeChoose.EnableWindow(TRUE);

// 		CString temp;
// 		temp.Format("LineNum = %d\n%s", f_Omd->GetLineNum(), f_Omd->GetLine(1));
// 		MessageBox(temp);
	}
}

void COmdFileDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	CString strFilter  = "OrigMsrData Files (*.omd)|*.omd|All Files (*.*)|*.*||";//檔案過濾條件
	CFileDialog fSaveDlg (TRUE, "omd", "*.omd", OFN_SHAREAWARE, strFilter);
	int nID = fSaveDlg.DoModal();
	
	if (nID == IDOK)
	{
		//Save Omd Data
		f_Omd->Save(fSaveDlg.GetPathName());
		delete f_Omd;
		//Clear Interface Index
		m_cmbCartridgeChoose.Clear();
		m_cmbCartridgeChoose.SetCurSel(0);
		m_cmbCartridgeChoose.EnableWindow(FALSE);
		
		vChain1.clear();
	}
}

void COmdFileDlg::OnSelchangeCombo1() 
{
	// TODO: Add your control notification handler code here
	std::vector<Cartridge>::size_type i = (std::vector<Cartridge>::size_type)m_cmbCartridgeChoose.GetCurSel();
	
	m_str.Format("Channel ID = %s\nProb = %s\nPanel ID = %s\nMsrDevice = %s\n\nLv:%3.2f     x:%1.4f     y:%1.4f     T:%5d     Duv:%1.4f\nDu:%1.4f     Dv:%1.4f     X:%3.2f\tY:%3.2f\tZ:%3.2f",\
	f_Omd->GetCHID(), f_Omd->GetPrb(), f_Omd->GetPnlID(), f_Omd->GetMsrDvc(), \
	vChain1.at(i).GetLv(), vChain1.at(i).GetSx(), vChain1.at(i).GetSy(), \
	vChain1.at(i).GetT(), vChain1.at(i).GetDuv(), \
	vChain1.at(i).GetDu(), vChain1.at(i).GetDv(), \
	vChain1.at(i).GetX(), vChain1.at(i).GetY(), vChain1.at(i).GetZ());

	UpdateData(FALSE);		
}
=======
// OmdFileDlg.cpp : implementation file
//

#include "stdafx.h"

#include "OmdFile.h"
#include "OmdFile1.h"
#include "OmdFileDlg.h"
#include <algorithm>

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
// COmdFileDlg dialog

COmdFileDlg::COmdFileDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COmdFileDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(COmdFileDlg)
	m_str = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COmdFileDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COmdFileDlg)
	DDX_Control(pDX, IDC_COMBO1, m_cmbCartridgeChoose);
	DDX_Text(pDX, IDC_STATIC_TERMINAL, m_str);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(COmdFileDlg, CDialog)
	//{{AFX_MSG_MAP(COmdFileDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COmdFileDlg message handlers

BOOL COmdFileDlg::OnInitDialog()
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
	m_cmbCartridgeChoose.EnableWindow(FALSE);

	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void COmdFileDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void COmdFileDlg::OnPaint() 
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
HCURSOR COmdFileDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void COmdFileDlg::SetOrigPriority(std::vector<Cartridge>& vCar)
{
	std::vector<Cartridge>::size_type OrigPrty;
	for (std::vector<Cartridge>::iterator itor = vCar.begin(); itor != vCar.end() ; ++itor)
	{
		OrigPrty = itor - vCar.begin();
		itor->SetOrigSeqc(OrigPrty);
	}
}

void COmdFileDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
/*
// txt版
	CString strFilter = "Data Files (*.omd)|*.omd|All Files (*.*)|*.*||";//檔案過濾條件
	CFileDialog aFileDialog (TRUE, "omd", "*.omd", OFN_SHAREAWARE | OFN_OVERWRITEPROMPT, strFilter);
	
	int nID = aFileDialog.DoModal();
	if (nID == IDOK)
	{
		f_txt = new CTxtFile;
		f_txt->Open(aFileDialog.GetPathName());

	CString temp;
	temp.Format("LineNum = %d\n%s", f_txt->GetLineNum(), f_txt->GetLine(3));
	MessageBox(temp);
	}
*/

// Omd版
	vChain1.clear();
	
	Cartridge W1(White , Pn1);
	Cartridge R1(Red   , Pn1);
	Cartridge G1(Green , Pn1);
	Cartridge B1(Blue  , Pn1);
	Cartridge W9(  White, Pn9);
	Cartridge W49( White, Pn49);
	Cartridge nits(Nits,  Pn9);
	Cartridge D9(  Dark,  Pn9);
	Cartridge D25( Dark,  Pn25);
	
	SimPtnDlg.Partition(vChain1, W1);
	SimPtnDlg.Partition(vChain1, R1);
	SimPtnDlg.Partition(vChain1, G1);
	SimPtnDlg.Partition(vChain1, B1);
	
	SimPtnDlg.Partition(vChain1, W9);
	SimPtnDlg.Partition(vChain1, nits);
	SimPtnDlg.Partition(vChain1, D9);
	SimPtnDlg.Partition(vChain1, D25);
	SimPtnDlg.Partition(vChain1, W49);

	//SetOrigPriority(vChain1); //記得現在的順序
	
	CString strFilter  = "OrigMsrData Files (*.omd)|*.omd|All Files (*.*)|*.*||";//檔案過濾條件
	CFileDialog aFileDialog (TRUE, "omd", "*.omd", OFN_SHAREAWARE | OFN_OVERWRITEPROMPT, strFilter);
	int nID = aFileDialog.DoModal();

	if (nID == IDOK)
	{
		//Load Omd Data
		f_Omd = new COmdFile1(vChain1);
		f_Omd->Open(aFileDialog.GetPathName());

		//Make Interface Index
		for (UINT i = 0; i < f_Omd->GetIdxNum(); ++i)
 			m_cmbCartridgeChoose.AddString(f_Omd->GetIndex(i));
		m_cmbCartridgeChoose.SetCurSel(0);
		m_cmbCartridgeChoose.EnableWindow(TRUE);

// 		CString temp;
// 		temp.Format("LineNum = %d\n%s", f_Omd->GetLineNum(), f_Omd->GetLine(1));
// 		MessageBox(temp);
	}
}

void COmdFileDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	CString strFilter  = "OrigMsrData Files (*.omd)|*.omd|All Files (*.*)|*.*||";//檔案過濾條件
	CFileDialog fSaveDlg (TRUE, "omd", "*.omd", OFN_SHAREAWARE, strFilter);
	int nID = fSaveDlg.DoModal();
	
	if (nID == IDOK)
	{
		//Save Omd Data
		f_Omd->Save(fSaveDlg.GetPathName());
		delete f_Omd;
		//Clear Interface Index
		m_cmbCartridgeChoose.Clear();
		m_cmbCartridgeChoose.SetCurSel(0);
		m_cmbCartridgeChoose.EnableWindow(FALSE);
		
		vChain1.clear();
	}
}

void COmdFileDlg::OnSelchangeCombo1() 
{
	// TODO: Add your control notification handler code here
	std::vector<Cartridge>::size_type i = (std::vector<Cartridge>::size_type)m_cmbCartridgeChoose.GetCurSel();
	
	m_str.Format("Channel ID = %s\nProb = %s\nPanel ID = %s\nMsrDevice = %s\n\nLv:%3.2f     x:%1.4f     y:%1.4f     T:%5d     Duv:%1.4f\nDu:%1.4f     Dv:%1.4f     X:%3.2f\tY:%3.2f\tZ:%3.2f",\
	f_Omd->GetCHID(), f_Omd->GetPrb(), f_Omd->GetPnlID(), f_Omd->GetMsrDvc(), \
	vChain1.at(i).GetLv(), vChain1.at(i).GetSx(), vChain1.at(i).GetSy(), \
	vChain1.at(i).GetT(), vChain1.at(i).GetDuv(), \
	vChain1.at(i).GetDu(), vChain1.at(i).GetDv(), \
	vChain1.at(i).GetX(), vChain1.at(i).GetY(), vChain1.at(i).GetZ());

	UpdateData(FALSE);		
}
>>>>>>> b5425c75ef070be7770a30afe5b503213bd2584b
