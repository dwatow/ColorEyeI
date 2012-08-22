// MsrItemDlg.cpp : implementation file
//

#include "stdafx.h"
#include "resource.h"
#include "MsrItemDlg.h"
#include "../xMsrPoint/PatternDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMsrItemDlg dialog


CMsrItemDlg::CMsrItemDlg(CWnd* pParent /*=NULL*/)
    : CDialog(CMsrItemDlg::IDD, pParent)
{
    EnableAutomation();

    Pusher = 0;
    //m_pDlgPattern = 0;
//    m_pCA210 = 0;
    //{{AFX_DATA_INIT(CMsrItemDlg)
    m_nGM1 = 0;
    m_nGM2 = 255;
    m_f21FE = 0.0f;
    m_f21Havg = 7.0f;
    m_f21Vavg = 5.0f;
    m_f25FE = 0.0f;
    m_f5FE = 0.0f;
    m_f9FE = 6.0f;
    m_fGammaSetp = 255.0f;
    m_n25RectSide = 0;
    m_fCrsTlkRectFE = 4.0f;
    m_fNits = 5.0f;
    //}}AFX_DATA_INIT
}


// void CMsrItemDlg::OnFinalRelease()
// {
//     // When the last reference for an automation object is released
//     // OnFinalRelease is called.  The base class will automatically
//     // deletes the object.  Add additional cleanup required for your
//     // object before calling the base class.
// 
//     CDialog::OnFinalRelease();
// }

void CMsrItemDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CMsrItemDlg)
    DDX_Control(pDX, IDC_CHECK_CBP21, m_chkCBP21);
    DDX_Control(pDX, IDC_CHECK_CDP21, m_chkCDP21);
    DDX_Control(pDX, IDC_CHECK_CGP21, m_chkCGP21);
    DDX_Control(pDX, IDC_CHECK_CWP21, m_chkCWP21);
    DDX_Control(pDX, IDC_CHECK_CRP21, m_chkCRP21);
    DDX_Control(pDX, IDC_CHECK_QUICKMSR, m_chkQuickMsr);
    DDX_Control(pDX, IDC_CHECK_CROSSTALK, m_chkCrossTalk);
    DDX_Control(pDX, IDC_CHECK_NITS, m_chkNits);
    DDX_Control(pDX, IDC_CHECK_CWP9, m_chkCWP9);
    DDX_Control(pDX, IDC_CHECK_CWP5, m_chkCWP5);
    DDX_Control(pDX, IDC_CHECK_CWP49, m_chkCWP49);
    DDX_Control(pDX, IDC_CHECK_CWP25, m_chkCWP25);
    DDX_Control(pDX, IDC_CHECK_CWP13, m_chkCWP13);
    DDX_Control(pDX, IDC_CHECK_CWGM, m_chkCWGM);
    DDX_Control(pDX, IDC_CHECK_CRP9, m_chkCRP9);
    DDX_Control(pDX, IDC_CHECK_CRP5, m_chkCRP5);
    DDX_Control(pDX, IDC_CHECK_CRP49, m_chkCRP49);
    DDX_Control(pDX, IDC_CHECK_CRP25, m_chkCRP25);
    DDX_Control(pDX, IDC_CHECK_CRP13, m_chkCRP13);
    DDX_Control(pDX, IDC_CHECK_CRGM, m_chkCRGM);
    DDX_Control(pDX, IDC_CHECK_CGP9, m_chkCGP9);
    DDX_Control(pDX, IDC_CHECK_CGP5, m_chkCGP5);
    DDX_Control(pDX, IDC_CHECK_CGP49, m_chkCGP49);
    DDX_Control(pDX, IDC_CHECK_CGP25, m_chkCGP25);
    DDX_Control(pDX, IDC_CHECK_CGP13, m_chkCGP13);
    DDX_Control(pDX, IDC_CHECK_CGGM, m_chkCGGM);
    DDX_Control(pDX, IDC_CHECK_CDP9, m_chkCDP9);
    DDX_Control(pDX, IDC_CHECK_CDP5, m_chkCDP5);
    DDX_Control(pDX, IDC_CHECK_CDP49, m_chkCDP49);
    DDX_Control(pDX, IDC_CHECK_CDP25, m_chkCDP25);
    DDX_Control(pDX, IDC_CHECK_CDP13, m_chkCDP13);
    DDX_Control(pDX, IDC_CHECK_CDGM, m_chkCDGM);
    DDX_Control(pDX, IDC_CHECK_CBP9, m_chkCBP9);
    DDX_Control(pDX, IDC_CHECK_CBP5, m_chkCBP5);
    DDX_Control(pDX, IDC_CHECK_CBP49, m_chkCBP49);
    DDX_Control(pDX, IDC_CHECK_CBP25, m_chkCBP25);
    DDX_Control(pDX, IDC_CHECK_CBP13, m_chkCBP13);
    DDX_Control(pDX, IDC_CHECK_CBGM, m_chkCBGM);
    DDX_Control(pDX, IDC_CHECK_CWP1, m_chkCWP1);
    DDX_Control(pDX, IDC_CHECK_CRP1, m_chkCRP1);
    DDX_Control(pDX, IDC_CHECK_CGP1, m_chkCGP1);
    DDX_Control(pDX, IDC_CHECK_CDP1, m_chkCDP1);
    DDX_Control(pDX, IDC_STATIC_W, m_stcWhite);
    DDX_Control(pDX, IDC_STATIC_B, m_stcBlue);
    DDX_Control(pDX, IDC_STATIC_D, m_stcDark);
    DDX_Control(pDX, IDC_STATIC_G, m_stcGreen);
    DDX_Control(pDX, IDC_STATIC_R, m_stcRed);
    DDX_Control(pDX, IDC_CHECK_CBP1, m_chkCBP1);
    DDX_Text(pDX, IDC_EDIT_GM1, m_nGM1);
    DDV_MinMaxUInt(pDX, m_nGM1, 0, 255);
    DDX_Text(pDX, IDC_EDIT_GM2, m_nGM2);
    DDV_MinMaxUInt(pDX, m_nGM2, 0, 255);
    DDX_Text(pDX, IDC_EDIT_P21FE, m_f21FE);
    DDV_MinMaxFloat(pDX, m_f21FE, 0.f, 100.f);
    DDX_Text(pDX, IDC_EDIT_P21HAVG, m_f21Havg);
    DDV_MinMaxFloat(pDX, m_f21Havg, 1.f, 100.f);
    DDX_Text(pDX, IDC_EDIT_P21VAVG, m_f21Vavg);
    DDV_MinMaxFloat(pDX, m_f21Vavg, 1.f, 100.f);
    DDX_Text(pDX, IDC_EDIT_P25FE, m_f25FE);
    DDV_MinMaxFloat(pDX, m_f25FE, 0.f, 100.f);
    DDX_Text(pDX, IDC_EDIT_P5FE, m_f5FE);
    DDV_MinMaxFloat(pDX, m_f5FE, 0.f, 100.f);
    DDX_Text(pDX, IDC_EDIT_P9FE, m_f9FE);
    DDV_MinMaxFloat(pDX, m_f9FE, 0.f, 100.f);
    DDX_Text(pDX, IDC_EDIT_GM3, m_fGammaSetp);
    DDV_MinMaxFloat(pDX, m_fGammaSetp, 1.f, 255.f);
    DDX_Text(pDX, IDC_EDIT_P25RECTSIDE, m_n25RectSide);
    DDV_MinMaxUInt(pDX, m_n25RectSide, 0, 100);
    DDX_Text(pDX, IDC_EDIT_CROSSTALK1, m_fCrsTlkRectFE);
    DDV_MinMaxFloat(pDX, m_fCrsTlkRectFE, 0.f, 100.f);
    DDX_Text(pDX, IDC_EDIT_NITS, m_fNits);
    DDV_MinMaxFloat(pDX, m_fNits, 1.f, 600.f);
    //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMsrItemDlg, CDialog)
    //{{AFX_MSG_MAP(CMsrItemDlg)
    ON_WM_CTLCOLOR()
    ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CMsrItemDlg, CDialog)
    //{{AFX_DISPATCH_MAP(CMsrItemDlg)
        // NOTE - the ClassWizard will add and remove mapping macros here.
    //}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IMsrItemDlg to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {7CD56503-6F6C-449E-8A5E-781F3EA45898}
static const IID IID_IMsrItemDlg =
{ 0x7cd56503, 0x6f6c, 0x449e, { 0x8a, 0x5e, 0x78, 0x1f, 0x3e, 0xa4, 0x58, 0x98 } };

BEGIN_INTERFACE_MAP(CMsrItemDlg, CDialog)
    INTERFACE_PART(CMsrItemDlg, IID_IMsrItemDlg, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMsrItemDlg message handlers

HBRUSH CMsrItemDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
    HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
    // TODO: Change any attributes of the DC here
    const COLORREF DarkClr  = RGB(  0,   0,   0);
    const COLORREF RedClr   = RGB(255,   0,   0);
    const COLORREF GreenClr = RGB(  0, 255,   0);
    const COLORREF BlueClr  = RGB(  0,   0, 255);
    const COLORREF WhiteClr = RGB(255, 255, 255);

    m_stcWhite.SetTextColor(pWnd, pDC, WhiteClr);
    m_stcRed.  SetTextColor(pWnd, pDC, RedClr);
    m_stcGreen.SetTextColor(pWnd, pDC, GreenClr);
    m_stcBlue. SetTextColor(pWnd, pDC, BlueClr);
    m_stcDark. SetTextColor(pWnd, pDC, DarkClr);

    // TODO: Return a different brush if the default is not desired
    return hbr;
}

void CMsrItemDlg::OnPaint() 
{
    CPaintDC dc(this); // device context for painting
    
    // TODO: Add your message handler code here
    m_stcWhite.SetFontFace("新細明體");
    m_stcRed.  SetFontFace("新細明體");
    m_stcGreen.SetFontFace("新細明體");
    m_stcBlue. SetFontFace("新細明體");
    m_stcDark. SetFontFace("新細明體");

    // Do not call CDialog::OnPaint() for painting messages
}


 /////////////////////////////////////////////////////////////////////////////
 //sort function
 
 bool CMsrItemDlg::AreaPriority(const Cartridge &sp1, const Cartridge &sp2)
 {
     return (sp1.GetArea() < sp2.GetArea()) ? 1 : 0;
 }
 
 bool CMsrItemDlg::OrigPriority(const Cartridge &sp1, const Cartridge &sp2)
 {
     return (sp1.GetOrigSeqc() < sp2.GetOrigSeqc()) ? 1 : 0;
 }
 
 
 void CMsrItemDlg::QuackMsrSort(std::vector<Cartridge>& vCar) const
 {
     std::sort(vCar.begin(), vCar.end(), AreaPriority);
 }
 
 void CMsrItemDlg::OrigMsrSort(std::vector<Cartridge>& vCar) const
 {
     std::sort(vCar.begin(), vCar.end(), OrigPriority);
 }

// BOOL CMsrItemDlg::DestroyWindow() 
// {
//     // TODO: Add your specialized code here and/or call the base class
//     //delete m_pDlgPattern;
// //    vCrossTalk.clear();
//     
//     return CDialog::DestroyWindow();
// }

// void CMsrItemDlg::Ready(/*std::vector<Cartridge>& vChain1*/)
// {
// //    m_chkCWP9.GetState();    
// }

// BOOL CMsrItemDlg::OnInitDialog() 
// {
//     CDialog::OnInitDialog();
//     
//     // TODO: Add extra initialization here
// 
// 
//     return TRUE;  // return TRUE unless you set the focus to a control
//                   // EXCEPTION: OCX Property Pages should return FALSE
// }

void CMsrItemDlg::SetBolt(Bolt* pusher)
{
    Pusher = pusher;
}


void CMsrItemDlg::OnOK() 
{
    // TODO: Add extra validation here
    if (Pusher != 0)
    {
        CMainFrame* pMainFrm = dynamic_cast<CMainFrame*>(AfxGetMainWnd());
        ASSERT_VALID(pMainFrm);

        CColorEyeIDoc* pDoc = dynamic_cast<CColorEyeIDoc*>(pMainFrm->GetActiveDocument());
        ASSERT_VALID(pDoc);

		pDoc->SetModifiedFlag(TRUE);

        pDoc->GetVector().clear();
        Cartridge x;
        pDoc->GetVector().push_back(x);

        UpdateData(TRUE);

        //執行連到了這
        //1. CA-210已連線
        //2. CA-210已宣告
        //////////////////////////////////////////////////////////////////////////
        Cartridge w1(White, Pn1);
        Cartridge r1(Red  , Pn1);
        Cartridge g1(Green, Pn1);
        Cartridge b1(Blue , Pn1);
        Cartridge d1(Dark , Pn1);

        Cartridge w5(White, Pn5);    
        Cartridge r5(Red  , Pn5);    
        Cartridge g5(Green, Pn5);    
        Cartridge b5(Blue , Pn5);    
        Cartridge d5(Dark , Pn5);    
    
        Cartridge w9(White, Pn9);    
        Cartridge r9(Red  , Pn9);    
        Cartridge g9(Green, Pn9);    
        Cartridge b9(Blue , Pn9);    
        Cartridge d9(Dark , Pn9);    

        Cartridge w25(White, Pn25);    
        Cartridge r25(Red  , Pn25);    
        Cartridge g25(Green, Pn25);    
        Cartridge b25(Blue , Pn25);    
        Cartridge d25(Dark , Pn25);    
    
        Cartridge w49(White, Pn49);    
        Cartridge r49(Red  , Pn49);    
        Cartridge g49(Green, Pn49);    
        Cartridge b49(Blue , Pn49);    
        Cartridge d49(Dark , Pn49);    
    
        Cartridge nits(Nits, Pn9);

        Cartridge crstlk1(CrsTlk , Pn4);
        Cartridge crstlk2(CrsTlkW, Pn4);
        Cartridge crstlk3(CrsTlkD, Pn4);

        if (m_chkCWP1.GetState())    Pusher->Partition(pDoc->GetVector(), w1);
        if (m_chkCRP1.GetState())    Pusher->Partition(pDoc->GetVector(), r1);
        if (m_chkCGP1.GetState())    Pusher->Partition(pDoc->GetVector(), g1);
        if (m_chkCBP1.GetState())    Pusher->Partition(pDoc->GetVector(), b1);
        if (m_chkCDP1.GetState())    Pusher->Partition(pDoc->GetVector(), d1);

        if (m_chkCWP5.GetState())    Pusher->Partition(pDoc->GetVector(), w5);
        if (m_chkCRP5.GetState())    Pusher->Partition(pDoc->GetVector(), r5);
        if (m_chkCGP5.GetState())    Pusher->Partition(pDoc->GetVector(), g5);
        if (m_chkCBP5.GetState())    Pusher->Partition(pDoc->GetVector(), b5);
        if (m_chkCDP5.GetState())    Pusher->Partition(pDoc->GetVector(), d5);
        
        if (m_chkCWP5.GetState() || m_chkCRP5.GetState() || m_chkCGP5.GetState() || m_chkCBP5.GetState() || m_chkCDP5.GetState())
            Pusher->SetP5FE(m_f5FE);

        if (m_chkCWP9.GetState())    Pusher->Partition(pDoc->GetVector(), w9);
        if (m_chkCRP9.GetState())    Pusher->Partition(pDoc->GetVector(), r9);
        if (m_chkCGP9.GetState())    Pusher->Partition(pDoc->GetVector(), g9);
        if (m_chkCBP9.GetState())    Pusher->Partition(pDoc->GetVector(), b9);
        if (m_chkCDP9.GetState())    Pusher->Partition(pDoc->GetVector(), d9);

        if (m_chkCWP9.GetState() || m_chkCRP9.GetState() || m_chkCGP9.GetState() || m_chkCBP9.GetState() || m_chkCDP9.GetState())
            Pusher->SetP9FE(m_f9FE);

        if (m_chkCWP21.GetState() || m_chkCRP21.GetState() || m_chkCGP21.GetState() || m_chkCBP21.GetState() || m_chkCDP21.GetState())
            Pusher->SetP21Avg(m_f21Havg, m_f21Vavg)->SetP21FE(m_f21FE);

        if (m_chkCWP25.GetState())    Pusher->Partition(pDoc->GetVector(), w25);
        if (m_chkCRP25.GetState())    Pusher->Partition(pDoc->GetVector(), r25);
        if (m_chkCGP25.GetState())    Pusher->Partition(pDoc->GetVector(), g25);
        if (m_chkCBP25.GetState())    Pusher->Partition(pDoc->GetVector(), b25);
        if (m_chkCDP25.GetState())    Pusher->Partition(pDoc->GetVector(), d25);

        if (m_chkCWP25.GetState() || m_chkCRP25.GetState() || m_chkCGP25.GetState() || m_chkCBP25.GetState() || m_chkCDP25.GetState())        
            Pusher->SetP25RectSide(m_n25RectSide)->SetP25FE(m_f25FE);
        
        if (m_chkCWP49.GetState())    Pusher->Partition(pDoc->GetVector(), w49);
        if (m_chkCRP49.GetState())    Pusher->Partition(pDoc->GetVector(), r49);
        if (m_chkCGP49.GetState())    Pusher->Partition(pDoc->GetVector(), g49);
        if (m_chkCBP49.GetState())    Pusher->Partition(pDoc->GetVector(), b49);
        if (m_chkCDP49.GetState())    Pusher->Partition(pDoc->GetVector(), d49);
    
        if (m_chkNits.GetState())     Pusher->Partition(pDoc->GetVector(), nits);

        if (m_chkNits.GetState())
            Pusher->SetNitsNum(m_fNits);

        if (m_chkCWGM.GetState() || m_chkCRGM.GetState() || m_chkCGGM.GetState() || m_chkCBGM.GetState() || m_chkCDGM.GetState())        
            Pusher->SetGammaRange(m_nGM1, m_nGM2)->GammaStep(m_fGammaSetp);

        if (m_chkQuickMsr.GetState())    QuackMsrSort(pDoc->GetVector());

        if (m_chkCrossTalk.GetState())
        {
            vCrossTalk.clear();
            Pusher->Partition(vCrossTalk, crstlk1);
            Pusher->Partition(vCrossTalk, crstlk2);
            Pusher->Partition(vCrossTalk, crstlk3);

            QuackMsrSort(vCrossTalk);

            pDoc->GetVector().insert(pDoc->GetVector().end(), vCrossTalk.begin(), vCrossTalk.end());
//             for (std::vector<Cartridge>::iterator itor = vCrossTalk.begin(); itor != vCrossTalk.end(); ++itor)
//                 pDoc->GetVector().push_back(*itor);

            Pusher->SetCrsTlkRectFE(m_fCrsTlkRectFE);
        }
    }
	
    CDialog::OnOK();
}
