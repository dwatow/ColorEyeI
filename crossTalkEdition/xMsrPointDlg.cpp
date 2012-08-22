// xMsrPointDlg.cpp : implementation file
//

#include "stdafx.h"
#include "xMsrPoint.h"
#include "xMsrPointDlg.h"
#include "DlgProxy.h"
#include "comdef.h"
#include <vector>
#include "xlef.h"

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
//     virtual BOOL PreTranslateMessage(MSG* pMsg);
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
//         m_pCA210(TRUE)
//     //    m_pCA210(FALSE)
{
    //{{AFX_DATA_INIT(CXMsrPointDlg)
    m_strDu = _T("");
    m_strDv = _T("");
    m_strDuv = _T("");
    m_strLv = _T("");
    m_strSx = _T("");
    m_strSy = _T("");
    m_strT = _T("");
    m_strX = _T("");
    m_strY = _T("");
    m_strZ = _T("");
    m_strOrig = _T("");
    m_strAreaCode = _T("");
    m_strBkColor = _T("");
    m_strFlowNo = _T("");
    m_strFlowNum = _T("");
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
    DDX_Control(pDX, IDC_BUTTON2, m_btnOutExcel);
    DDX_Control(pDX, IDC_BUTTON1, m_btnClearAll);
    DDX_Control(pDX, IDC_SLIDER1, m_sldViewControl);
    DDX_Text(pDX, IDC_STATIC_DU , m_strDu);
    DDX_Text(pDX, IDC_STATIC_DV , m_strDv);
    DDX_Text(pDX, IDC_STATIC_DUV, m_strDuv);
    DDX_Text(pDX, IDC_STATIC_L  , m_strLv);
    DDX_Text(pDX, IDC_STATIC_SX , m_strSx);
    DDX_Text(pDX, IDC_STATIC_SY , m_strSy);
    DDX_Text(pDX, IDC_STATIC_T  , m_strT);
    DDX_Text(pDX, IDC_STATIC_X  , m_strX);
    DDX_Text(pDX, IDC_STATIC_Y  , m_strY);
    DDX_Text(pDX, IDC_STATIC_Z  , m_strZ);
    DDX_Text(pDX, IDC_STATIC_ORIG, m_strOrig);
    DDX_Text(pDX, IDC_STATIC_AREA, m_strAreaCode);
    DDX_Text(pDX, IDC_STATIC_BKCLR, m_strBkColor);
    DDX_Text(pDX, IDC_STATIC_FLOWNO, m_strFlowNo);
    DDX_Text(pDX, IDC_STATIC_FLOWNUM, m_strFlowNum);
    //}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CXMsrPointDlg, CDialog)
    //{{AFX_MSG_MAP(CXMsrPointDlg)
    ON_WM_SYSCOMMAND()
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_BUTTON_MSR, OnButtonMsr)
    ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER1, OnReleasedcaptureSlider1)
    ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
    ON_WM_CLOSE()
    ON_WM_KEYDOWN()
    ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
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
    SetIcon(m_hIcon, TRUE);            // Set big icon
    SetIcon(m_hIcon, FALSE);        // Set small icon
    
    // TODO: Add extra initialization here
    m_sldViewControl.EnableWindow(FALSE);
    m_btnOutExcel.EnableWindow(FALSE);
    m_btnClearAll.EnableWindow(FALSE);
    m_pCA210 = 0;

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
    if (m_pCA210 == 0)
    {
        m_pCA210 = new Ca210(TRUE);
        p_PtnDlg = new CPatternDlg;
        
        if (!p_PtnDlg->ConnectCa210(m_pCA210))
            AfxMessageBox("OnButtonMsrCA-210硈絬岿粇");
        p_PtnDlg->Create(IDD_PATTERN_DIALOG);

		vChain1.clear();
		Cartridge x;
		vChain1.push_back(x);
		
		Cartridge R1(Red, Pn1);
		Cartridge G1(Green, Pn1);
		Cartridge B1(Blue, Pn1);
		Cartridge W5(White, Pn5);
		Cartridge W9(White, Pn9);
		Cartridge D25(Dark, Pn25);
		Cartridge W49(White, Pn49);
		Cartridge nits(Nits, Pn9);
		Cartridge CrossTalk1(CrsTlk, Pn4);
		Cartridge CrossTalk2(CrsTlkW, Pn4);
		Cartridge CrossTalk3(CrsTlkD, Pn4);
		
		p_PtnDlg->Partition(vChain1, R1);
		p_PtnDlg->Partition(vChain1, G1);
		p_PtnDlg->Partition(vChain1, B1);
		
		p_PtnDlg->Partition(vChain1, W9);
		p_PtnDlg->Partition(vChain1, D25);
		p_PtnDlg->Partition(vChain1, W49);
		p_PtnDlg->Partition(vChain1, nits);
		p_PtnDlg->Partition(vChain1, W5);
		p_PtnDlg->Partition(vChain1, CrossTalk1);
		p_PtnDlg->Partition(vChain1, CrossTalk2);
		p_PtnDlg->Partition(vChain1, CrossTalk3);
		
		//ReadyFire
		//    p_PtnDlg->SetOrigPriority(vChain1); //癘眔瞷抖
		
		m_sldViewControl.SetRangeMin(0);
		m_sldViewControl.SetRangeMax(vChain1.size()-1);
		m_sldViewControl.EnableWindow(TRUE);
		
		
		QuackMsrSort(vChain1);
		//OrigMsrSort(vChain1);

#ifdef _DEBUG
		CString strTemp;
		strTemp.Format("%d", m_pCA210->GetOnline());
		AfxMessageBox(strTemp);
#endif
    }
    else
    {
        m_pCA210->SetOnline(TRUE);
    }
      
    if(!p_PtnDlg->Magazine(vChain1))
        MessageBox("OnButtonMsr紆岿");

    m_btnClearAll.EnableWindow(TRUE);
    m_btnOutExcel.EnableWindow(TRUE);

	p_PtnDlg->ShowWindow(SW_MAXIMIZE);
}

void CXMsrPointDlg::OnReleasedcaptureSlider1(NMHDR* pNMHDR, LRESULT* pResult) 
{
    // TODO: Add your control notification handler code here
    DebugByExcel();
    std::vector<Cartridge>::size_type i = (std::vector<Cartridge>::size_type)(m_sldViewControl.GetPos());

    m_strLv.Format("Lv:%3.2f", vChain1.at(i).GetLv());
    m_strSx.Format("x:%1.4f", vChain1.at(i).GetSx());
    m_strSy.Format("y:%1.4f", vChain1.at(i).GetSy());
    
    m_strT.Format("T:%4d", vChain1.at(i).GetT());
    m_strDuv.Format("uv:%1.4f", vChain1.at(i).GetDuv());
    
    m_strDu.Format("u:%1.4f", vChain1.at(i).GetDu());
    m_strDv.Format("v:%1.4f", vChain1.at(i).GetDv());
    
    m_strX.Format("X:%3.2f", vChain1.at(i).GetX());
    m_strY.Format("Y:%3.2f", vChain1.at(i).GetY());
    m_strZ.Format("Z:%3.2f", vChain1.at(i).GetZ());

//    m_strOrig.Format("OrigSeqc:%d", vChain1.at(i).GetOrigSeqc());
    m_strFlowNum.Format("FlowNum:%s", itToPointNum(vChain1.at(i)));
    m_strFlowNo.Format("FlowNo:%d", vChain1.at(i).GetMsrFlowNo());
    m_strAreaCode.Format("AreaCode:%d", vChain1.at(i).GetArea());
    m_strBkColor.Format("BackColor:%s", itToColorType(vChain1.at(i)));

    UpdateData(FALSE);

//     CString strTemp;
//     strTemp.Format("SubNum(CrsTlk, Pn4, 0) = %d\tSubNum(W, Pn4, 0) = %d\tSubNum(D, Pn4, 0) = %d", \
//         SubNum(CrsTlk, Pn4, 0), SubNum(CrsTlkW, Pn4, 0), SubNum(CrsTlkD, Pn4, 0));
    

    *pResult = 0;
}

void CXMsrPointDlg::OnButton2() 
{
    // TODO: Add your control notification handler code here
    delete p_PtnDlg;
	delete m_pCA210;
	m_pCA210 = 0;
    vChain1.clear();

    m_sldViewControl.SetPos(0);      //菲笆膘耴箂
    m_sldViewControl.SetRangeMin(0); //┵ㄨ
    m_sldViewControl.SetRangeMax(0); //┵ㄨ
    m_sldViewControl.EnableWindow(FALSE);
    m_btnOutExcel.EnableWindow(FALSE);
    m_btnClearAll.EnableWindow(FALSE);
}

std::vector<Cartridge>::size_type CXMsrPointDlg::SubNum(ColorType clr, PointNum Large, UINT Little) const
{
    std::vector<Cartridge>::size_type SubNum = -1;
    for (std::vector<Cartridge>::const_iterator itor = vChain1.begin(); itor != vChain1.end() ; ++itor)
    {
        if(Large == itor->GetMsrFlowNum() && Little == itor->GetMsrFlowNo() && clr == itor->GetBackColor())
            SubNum = itor - vChain1.begin();
    }
    return (SubNum == -1) ? 0 : SubNum;
}

void CXMsrPointDlg::OnButton1() 
{
    // TODO: Add your control notification handler code here
	OrigMsrSort(vChain1);
//    p_PtnDlg->OrigMsrSort(vChain1);
//     CString strTemp, temp;
//     strTemp.Format("");
//     temp.Format("%x", &vChain1.at(0));
//     
//     for (std::vector<Cartridge>::iterator it = vChain1.begin(); it != vChain1.end(); ++it)
//     {
//         temp.Format("0x%x\n", it);
//         strTemp += temp;
//     }
//     AfxMessageBox(strTemp);
//    p_PtnDlg->OrigSort(vChain1);
    DebugByExcel();


    xlsFile CrossTalkFrom;

    CrossTalkFrom.New();
    CrossTalkFrom.SetSheetName(1, "CrossTalk");

    //////////////////////////////////////////////////////////////////////////
    //恶
    CrossTalkFrom.SelectCell("B1").SetCell("Lv");
    CrossTalkFrom.SelectCell("F1").SetCell("x");
    CrossTalkFrom.SelectCell("J1").SetCell("y");

    CrossTalkFrom.SelectCell("C2").SetCell(vChain1.at(SubNum(CrsTlk, Pn4, 0)).GetStrLv());
    CrossTalkFrom.SelectCell("B3").SetCell(vChain1.at(SubNum(CrsTlk, Pn4, 1)).GetStrLv());
    CrossTalkFrom.SelectCell("D3").SetCell(vChain1.at(SubNum(CrsTlk, Pn4, 2)).GetStrLv());
    CrossTalkFrom.SelectCell("C4").SetCell(vChain1.at(SubNum(CrsTlk, Pn4, 3)).GetStrLv());

    CrossTalkFrom.SelectCell("G2").SetCell(vChain1.at(SubNum(CrsTlk, Pn4, 0)).GetStrSx());
    CrossTalkFrom.SelectCell("F3").SetCell(vChain1.at(SubNum(CrsTlk, Pn4, 1)).GetStrSx());
    CrossTalkFrom.SelectCell("H3").SetCell(vChain1.at(SubNum(CrsTlk, Pn4, 2)).GetStrSx());
    CrossTalkFrom.SelectCell("G4").SetCell(vChain1.at(SubNum(CrsTlk, Pn4, 3)).GetStrSx());

    CrossTalkFrom.SelectCell("K2").SetCell(vChain1.at(SubNum(CrsTlk, Pn4, 0)).GetStrSy());
    CrossTalkFrom.SelectCell("J3").SetCell(vChain1.at(SubNum(CrsTlk, Pn4, 1)).GetStrSy());
    CrossTalkFrom.SelectCell("L3").SetCell(vChain1.at(SubNum(CrsTlk, Pn4, 2)).GetStrSy());
    CrossTalkFrom.SelectCell("K4").SetCell(vChain1.at(SubNum(CrsTlk, Pn4, 3)).GetStrSy());



    CrossTalkFrom.SelectCell("C6").SetCell(vChain1.at(SubNum(CrsTlkW, Pn4, 0)).GetStrLv());
    CrossTalkFrom.SelectCell("B7").SetCell(vChain1.at(SubNum(CrsTlkW, Pn4, 1)).GetStrLv());
    CrossTalkFrom.SelectCell("D7").SetCell(vChain1.at(SubNum(CrsTlkW, Pn4, 2)).GetStrLv());
    CrossTalkFrom.SelectCell("C8").SetCell(vChain1.at(SubNum(CrsTlkW, Pn4, 3)).GetStrLv());

    CrossTalkFrom.SelectCell("G6").SetCell(vChain1.at(SubNum(CrsTlkW, Pn4, 0)).GetStrSx());
    CrossTalkFrom.SelectCell("F7").SetCell(vChain1.at(SubNum(CrsTlkW, Pn4, 1)).GetStrSx());
    CrossTalkFrom.SelectCell("H7").SetCell(vChain1.at(SubNum(CrsTlkW, Pn4, 2)).GetStrSx());
    CrossTalkFrom.SelectCell("G8").SetCell(vChain1.at(SubNum(CrsTlkW, Pn4, 3)).GetStrSx());
    
    CrossTalkFrom.SelectCell("K6").SetCell(vChain1.at(SubNum(CrsTlkW, Pn4, 0)).GetStrSy());
    CrossTalkFrom.SelectCell("J7").SetCell(vChain1.at(SubNum(CrsTlkW, Pn4, 1)).GetStrSy());
    CrossTalkFrom.SelectCell("L7").SetCell(vChain1.at(SubNum(CrsTlkW, Pn4, 2)).GetStrSy());
    CrossTalkFrom.SelectCell("K8").SetCell(vChain1.at(SubNum(CrsTlkW, Pn4, 3)).GetStrSy());
    


    CrossTalkFrom.SelectCell("C10").SetCell(vChain1.at(SubNum(CrsTlkD, Pn4, 0)).GetStrLv());
    CrossTalkFrom.SelectCell("B11").SetCell(vChain1.at(SubNum(CrsTlkD, Pn4, 1)).GetStrLv());
    CrossTalkFrom.SelectCell("D11").SetCell(vChain1.at(SubNum(CrsTlkD, Pn4, 2)).GetStrLv());
    CrossTalkFrom.SelectCell("C12").SetCell(vChain1.at(SubNum(CrsTlkD, Pn4, 3)).GetStrLv());
    
    CrossTalkFrom.SelectCell("G10").SetCell(vChain1.at(SubNum(CrsTlkD, Pn4, 0)).GetStrSx());
    CrossTalkFrom.SelectCell("F11").SetCell(vChain1.at(SubNum(CrsTlkD, Pn4, 1)).GetStrSx());
    CrossTalkFrom.SelectCell("H11").SetCell(vChain1.at(SubNum(CrsTlkD, Pn4, 2)).GetStrSx());
    CrossTalkFrom.SelectCell("G12").SetCell(vChain1.at(SubNum(CrsTlkD, Pn4, 3)).GetStrSx());
    
    CrossTalkFrom.SelectCell("K10").SetCell(vChain1.at(SubNum(CrsTlkD, Pn4, 0)).GetStrSy());
    CrossTalkFrom.SelectCell("J11").SetCell(vChain1.at(SubNum(CrsTlkD, Pn4, 1)).GetStrSy());
    CrossTalkFrom.SelectCell("L11").SetCell(vChain1.at(SubNum(CrsTlkD, Pn4, 2)).GetStrSy());
    CrossTalkFrom.SelectCell("K12").SetCell(vChain1.at(SubNum(CrsTlkD, Pn4, 3)).GetStrSy());    //CrossTalkFrom.;

    //////////////////////////////////////////////////////////////////////////
    //礶璉春㎝絬
    char cCell = 'B';
    int iCell = 2;
    CrossTalkFrom.SelectCell(cCell, iCell   , cCell + 2, iCell + 2).SetCellColor(15).SetCellBorder();
    CrossTalkFrom.SelectCell(cCell, iCell +4, cCell + 2, iCell + 6).SetCellColor(15).SetCellBorder();
    CrossTalkFrom.SelectCell(cCell + 1, iCell +5).SetCellColor(2);
    CrossTalkFrom.SelectCell(cCell, iCell +8, cCell + 2, iCell +10).SetCellColor(15).SetCellBorder();
    CrossTalkFrom.SelectCell(cCell + 1, iCell +9).SetCellColor(1);

    cCell = 'F';
    CrossTalkFrom.SelectCell(cCell, iCell   , cCell + 2, iCell + 2).SetCellColor(15).SetCellBorder();
    CrossTalkFrom.SelectCell(cCell, iCell +4, cCell + 2, iCell + 6).SetCellColor(15).SetCellBorder();
    CrossTalkFrom.SelectCell(cCell + 1, iCell +5).SetCellColor(2);
    CrossTalkFrom.SelectCell(cCell, iCell +8, cCell + 2, iCell +10).SetCellColor(15).SetCellBorder();
    CrossTalkFrom.SelectCell(cCell + 1, iCell +9).SetCellColor(1);

    cCell = 'J';
    CrossTalkFrom.SelectCell(cCell, iCell   , cCell + 2, iCell + 2).SetCellColor(15).SetCellBorder();
    CrossTalkFrom.SelectCell(cCell, iCell +4, cCell + 2, iCell + 6).SetCellColor(15).SetCellBorder();
    CrossTalkFrom.SelectCell(cCell + 1, iCell +5).SetCellColor(2);
    CrossTalkFrom.SelectCell(cCell, iCell +8, cCell + 2, iCell +10).SetCellColor(15).SetCellBorder();
    CrossTalkFrom.SelectCell(cCell + 1, iCell +9).SetCellColor(1);

    CrossTalkFrom.SetVisible(true);
}

void CXMsrPointDlg::DebugByExcel()
{
    xlsFile xls1;
    
     xls1.New();
     xls1.SetSheetName(1, "Debug");
    int iCell;

    xls1.SelectCell('A', 1).SetCell("Mem Addr");     //Address
    xls1.SelectCell('B', 1).SetCell("SubNum");      //SubNum
    xls1.SelectCell('C', 1).SetCell("ColorType");   //ColorType
    xls1.SelectCell('D', 1).SetCell("PointNum");    //PointNum
    xls1.SelectCell('E', 1).SetCell("PointNo");     //PointNo
    xls1.SelectCell('F', 1).SetCell("AreaCode");      //AreaCode
    xls1.SelectCell('G', 1).SetCell("OrigSeqc");  //OrigSeqc
    
    xls1.SelectCell('H', 1).SetCell("Lv");      //Lv
    xls1.SelectCell('I', 1).SetCell("Sx");      //x
    xls1.SelectCell('J', 1).SetCell("Sy");      //y
    xls1.SelectCell('K', 1).SetCell("T");       //T
    xls1.SelectCell('L', 1).SetCell("Duv");     //Duv
    xls1.SelectCell('M', 1).SetCell("Du");      //Du
    xls1.SelectCell('N', 1).SetCell("Dv");      //Dv
    xls1.SelectCell('O', 1).SetCell("X");       //X
    xls1.SelectCell('P', 1).SetCell("Y");       //Y
     xls1.SelectCell('Q', 1).SetCell("Z");       //Z

    iCell = 2;
    UINT si;
    for (std::vector<Cartridge>::iterator it = vChain1.begin(); it != vChain1.end(); ++it)
    {
        si = UINT(it - vChain1.begin());
        xls1.SelectCell('A', iCell + si).SetCell(itToAddress(it));     //Address
        xls1.SelectCell('B', iCell + si).SetCell(itToSubNum(it));      //SubNum
        xls1.SelectCell('C', iCell + si).SetCell(itToColorType(it));   //ColorType
        xls1.SelectCell('D', iCell + si).SetCell(itToPointNum(it));    //PointNum
        xls1.SelectCell('E', iCell + si).SetCell(itToPointNo(it));     //PointNo
        xls1.SelectCell('F', iCell + si).SetCell(UintToStr(it->GetArea()));      //AreaCode
//        xls1.SelectCell('G', iCell + si).SetCell(UintToStr(it->GetOrigSeqc()));  //OrigSeqc

        xls1.SelectCell('H', iCell + si).SetCell(it->GetStrLv());      //Lv
         xls1.SelectCell('I', iCell + si).SetCell(it->GetStrSx());      //x
         xls1.SelectCell('J', iCell + si).SetCell(it->GetStrSy());      //y
         xls1.SelectCell('K', iCell + si).SetCell(it->GetStrT());       //T
         xls1.SelectCell('L', iCell + si).SetCell(it->GetStrDuv());     //Duv
         xls1.SelectCell('M', iCell + si).SetCell(it->GetStrDu());      //Du
         xls1.SelectCell('N', iCell + si).SetCell(it->GetStrDv());      //Dv
         xls1.SelectCell('O', iCell + si).SetCell(it->GetStrX());       //X
         xls1.SelectCell('P', iCell + si).SetCell(it->GetStrY());       //Y
         xls1.SelectCell('Q', iCell + si).SetCell(it->GetStrZ());       //Z
    }
    xls1.SelectSheet(2);
    
    xls1.SelectCell('A', 1).SetCell("Mem Addr");     //Address
    xls1.SelectCell('B', 1).SetCell("SubNum");      //SubNum
    xls1.SelectCell('C', 1).SetCell("ColorType");   //ColorType
    xls1.SelectCell('D', 1).SetCell("PointNum");    //PointNum
    xls1.SelectCell('E', 1).SetCell("PointNo");     //PointNo
    xls1.SelectCell('F', 1).SetCell("AreaCode");      //AreaCode
    xls1.SelectCell('G', 1).SetCell("OrigSeqc");  //OrigSeqc
    
    xls1.SelectCell('H', 1).SetCell("Lv");      //Lv
    xls1.SelectCell('I', 1).SetCell("Sx");      //x
    xls1.SelectCell('J', 1).SetCell("Sy");      //y
    xls1.SelectCell('K', 1).SetCell("T");       //T
    xls1.SelectCell('L', 1).SetCell("Duv");     //Duv
    xls1.SelectCell('M', 1).SetCell("Du");      //Du
    xls1.SelectCell('N', 1).SetCell("Dv");      //Dv
    xls1.SelectCell('O', 1).SetCell("X");       //X
    xls1.SelectCell('P', 1).SetCell("Y");       //Y
     xls1.SelectCell('Q', 1).SetCell("Z");       //Z
    
    iCell = 2;
    for (si = 0; si < vChain1.size(); ++si)
    {
//        it = &vChain1.at(si);
        xls1.SelectCell('A', iCell + si).SetCell(itToAddress(vChain1.at((std::vector<Cartridge>::size_type)si)));     //Address
        xls1.SelectCell('B', iCell + si).SetCell(itToSubNum(vChain1.at((std::vector<Cartridge>::size_type)si)));      //SubNum
        xls1.SelectCell('C', iCell + si).SetCell(itToColorType(vChain1.at((std::vector<Cartridge>::size_type)si)));   //ColorType
        xls1.SelectCell('D', iCell + si).SetCell(itToPointNum(vChain1.at((std::vector<Cartridge>::size_type)si)));    //PointNum
        xls1.SelectCell('E', iCell + si).SetCell(itToPointNo(vChain1.at((std::vector<Cartridge>::size_type)si)));     //PointNo
        xls1.SelectCell('F', iCell + si).SetCell(UintToStr(vChain1.at((std::vector<Cartridge>::size_type)si).GetArea()));      //AreaCode
//        xls1.SelectCell('G', iCell + si).SetCell(UintToStr(vChain1.at((std::vector<Cartridge>::size_type)si).GetOrigSeqc()));  //OrigSeqc

        xls1.SelectCell('H', iCell + si).SetCell(vChain1.at((std::vector<Cartridge>::size_type)si).GetStrLv());      //Lv
        xls1.SelectCell('I', iCell + si).SetCell(vChain1.at((std::vector<Cartridge>::size_type)si).GetStrSx());      //x
        xls1.SelectCell('J', iCell + si).SetCell(vChain1.at((std::vector<Cartridge>::size_type)si).GetStrSy());      //y
        xls1.SelectCell('K', iCell + si).SetCell(vChain1.at((std::vector<Cartridge>::size_type)si).GetStrT());       //T
        xls1.SelectCell('L', iCell + si).SetCell(vChain1.at((std::vector<Cartridge>::size_type)si).GetStrDuv());     //Duv
        xls1.SelectCell('M', iCell + si).SetCell(vChain1.at((std::vector<Cartridge>::size_type)si).GetStrDu());      //Du
        xls1.SelectCell('N', iCell + si).SetCell(vChain1.at((std::vector<Cartridge>::size_type)si).GetStrDv());      //Dv
        xls1.SelectCell('O', iCell + si).SetCell(vChain1.at((std::vector<Cartridge>::size_type)si).GetStrX());       //X
        xls1.SelectCell('P', iCell + si).SetCell(vChain1.at((std::vector<Cartridge>::size_type)si).GetStrY());       //Y
        xls1.SelectCell('Q', iCell + si).SetCell(vChain1.at((std::vector<Cartridge>::size_type)si).GetStrZ());       //Z
    }
    xls1.SetVisible(true);
}

CString CXMsrPointDlg::itToSubNum(std::vector<Cartridge>::iterator it)
{
    CString strTemp;
    strTemp.Format("%d", (UINT)SubNum(it->GetBackColor(), it->GetMsrFlowNum(), it->GetMsrFlowNo()));
    return strTemp;
}

CString CXMsrPointDlg::itToSubNum(Cartridge& vCar)
{
    CString strTemp;
    strTemp.Format("%d", (UINT)SubNum(vCar.GetBackColor(), vCar.GetMsrFlowNum(), vCar.GetMsrFlowNo()));
    return strTemp;
}

CString CXMsrPointDlg::itToAddress(std::vector<Cartridge>::iterator it)
{
    CString strTemp;
    strTemp.Format("0x%x", it);
    return strTemp;
}

CString CXMsrPointDlg::itToAddress(Cartridge& vCar)
{
    CString strTemp;
    strTemp.Format("0x%x", &vCar);
    return strTemp;
}

CString CXMsrPointDlg::itToColorType(std::vector<Cartridge>::iterator it)
{
    CString strTemp;
    switch(it->GetBackColor())
    {
        case Red:       strTemp.Format("Red");      break;
        case Blue:       strTemp.Format("Blue");     break;
        case Green:       strTemp.Format("Green");    break;
        case Dark:       strTemp.Format("Dark");     break;
        case White:       strTemp.Format("White");    break;
        case CrsTlk:   strTemp.Format("CrsTlk");   break;
        case CrsTlkW:  strTemp.Format("CrsTlkW");  break;
        case CrsTlkD:  strTemp.Format("CrsTlkD");  break;
        default:       strTemp.Format("ぐ或常⊿Τ");
    }

    return strTemp;
}

CString CXMsrPointDlg::itToColorType(Cartridge& vCar)
{
    CString strTemp;
    switch(vCar.GetBackColor())
    {
    case Red:       strTemp.Format("Red");      break;
    case Blue:       strTemp.Format("Blue");     break;
    case Green:       strTemp.Format("Green");    break;
    case Dark:       strTemp.Format("Dark");     break;
    case White:       strTemp.Format("White");    break;
    case CrsTlk:   strTemp.Format("CrsTlk");   break;
    case CrsTlkW:  strTemp.Format("CrsTlkW");  break;
    case CrsTlkD:  strTemp.Format("CrsTlkD");  break;
    default:       strTemp.Format("ぐ或常⊿Τ");
    }
    
    return strTemp;    
}

CString CXMsrPointDlg::itToPointNum(std::vector<Cartridge>::iterator it)
{
    CString strTemp;
    switch(it->GetMsrFlowNum())
    {
        case Pn1:    strTemp.Format("Point 1");   break;
        case Pn4:    strTemp.Format("Point 4");   break;
        case Pn5:    strTemp.Format("Point 5");   break;
        case Pn9:    strTemp.Format("Point 9");   break;
        case Pn13:    strTemp.Format("Point 13");  break;
        case Pn25:  strTemp.Format("Point 25");  break;
        case Pn49:  strTemp.Format("Point 49");  break;

        default:       strTemp.Format("ぐ或常⊿Τ");
    }
    
    return strTemp;
}

CString CXMsrPointDlg::itToPointNum(Cartridge& vCar)
{
    CString strTemp;
    switch(vCar.GetMsrFlowNum())
    {
    case Pn1:    strTemp.Format("Point 1");   break;
    case Pn4:    strTemp.Format("Point 4");   break;
    case Pn5:    strTemp.Format("Point 5");   break;
    case Pn9:    strTemp.Format("Point 9");   break;
    case Pn13:    strTemp.Format("Point 13");  break;
    case Pn25:  strTemp.Format("Point 25");  break;
    case Pn49:  strTemp.Format("Point 49");  break;
        
    default:       strTemp.Format("ぐ或常⊿Τ");
    }
    
    return strTemp;
}

CString CXMsrPointDlg::itToPointNo(std::vector<Cartridge>::iterator it)
{
    CString strTemp;
    strTemp.Format("%d", it->GetMsrFlowNo());
    return strTemp;
}

CString CXMsrPointDlg::itToPointNo(Cartridge& vCar)
{
    CString strTemp;
    strTemp.Format("%d", vCar.GetMsrFlowNo());
    return strTemp;
}

CString CXMsrPointDlg::UintToStr(UINT u)
{
    CString strTemp;
    strTemp.Format("%d", u);
    return strTemp;
}

/////////////////////////////////////////////////////////////////////////////
//sort function

bool CXMsrPointDlg::AreaPriority(const Cartridge &sp1, const Cartridge &sp2)
{
    return (sp1.GetArea() < sp2.GetArea()) ? 1 : 0;
}

bool CXMsrPointDlg::OrigPriority(const Cartridge &sp1, const Cartridge &sp2)
{
    return (sp1.GetOrigSeqc() < sp2.GetOrigSeqc()) ? 1 : 0;
}


void CXMsrPointDlg::QuackMsrSort(std::vector<Cartridge>& vCar) const
{
	std::sort(vCar.begin(), vCar.end(), AreaPriority);
}

void CXMsrPointDlg::OrigMsrSort(std::vector<Cartridge>& vCar) const
{
	std::sort(vCar.begin(), vCar.end(), OrigPriority);
}
