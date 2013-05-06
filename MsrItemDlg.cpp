// MsrItemDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ColorEyeI.h"
#include "MsrItemDlg.h"

#include "PatternDlg.h"
#include "TranScripter.h"
#include "MainFrm.h"
#include "ColorEyeIDoc.h"
#include "CColorRef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#ifdef _DEBUG
#define DebugCode( code_fragment ) { code_fragment }
#else
#define DebugCode( code_fragment )
#endif


/////////////////////////////////////////////////////////////////////////////
// CMsrItemDlg dialog

CMsrItemDlg::CMsrItemDlg(CWnd* pParent /*=NULL*/)
: CDialog(CMsrItemDlg::IDD, pParent), m_W9FEtype(FT_1overN)
{
    CColorEyeIApp* pApp = dynamic_cast<CColorEyeIApp*>(AfxGetApp());
    ASSERT_VALID(pApp);

    m_RememberChkPathName.Format("%s\\~MsrItemDlg.temp", pApp->GetPath());
    DebugCode( m_desktopPath.Format("%s", pApp->GetDesktopPath()); )

    //{{AFX_DATA_INIT(CMsrItemDlg)
    m_nGM1 = 0;
    m_nGM2 = 255;
    m_f21FE = 0.0f;
    m_f25FE = 0.0f;
    m_f5FE = 0.0f;
    m_f9FE = 6.0f;
    m_f13FE = 0.0f;
    m_fGammaSetp = 255.0f;
    m_n25RectSide = 10;
    m_fCrsTlkRectFE = 4.0f;
    m_fNits = 5.0f;
    m_JndGray = 0;
    //}}AFX_DATA_INIT
}


void CMsrItemDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CMsrItemDlg)
    DDX_Control(pDX, IDC_SW_P9FE, m_spinP9Para);
    DDX_Control(pDX, IDC_STATIC_P9FECM, m_p9_Ncm);
    DDX_Control(pDX, IDC_STATIC_P9FE1OVER, m_p9_1overN);
    DDX_Control(pDX, IDC_COMBO_SEL_NITS_KIND, m_cbxSelNitsKind);
    DDX_Control(pDX, IDC_CHECK_JND, m_chkJND);
    DDX_Control(pDX, IDOK, m_btnOK);
    DDX_Control(pDX, IDC_BUTTON_DEL, m_btnDelItems);
    DDX_Control(pDX, IDC_BUTTON_ADD, m_btnAddItems);
    DDX_Control(pDX, IDC_LIST_MSRITEMS, m_lstMsrItems);
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
    DDX_Control(pDX, IDC_CHECK_CBP1, m_chkCBP1);
    DDX_Control(pDX, IDC_STATIC_W, m_stcWhite);
    DDX_Control(pDX, IDC_STATIC_B, m_stcBlue);
    DDX_Control(pDX, IDC_STATIC_D, m_stcDark);
    DDX_Control(pDX, IDC_STATIC_G, m_stcGreen);
    DDX_Control(pDX, IDC_STATIC_R, m_stcRed);
    DDX_Text(pDX, IDC_EDIT_GM1, m_nGM1);
    DDV_MinMaxUInt(pDX, m_nGM1, 0, 255);
    DDX_Text(pDX, IDC_EDIT_GM2, m_nGM2);
    DDV_MinMaxUInt(pDX, m_nGM2, 0, 255);
    DDX_Text(pDX, IDC_EDIT_P21FE, m_f21FE);
    DDV_MinMaxFloat(pDX, m_f21FE, 0.f, 100.f);
    DDX_Text(pDX, IDC_EDIT_P25FE, m_f25FE);
    DDV_MinMaxFloat(pDX, m_f25FE, 0.f, 100.f);
    DDX_Text(pDX, IDC_EDIT_P5FE, m_f5FE);
    DDV_MinMaxFloat(pDX, m_f5FE, 0.f, 100.f);
    DDX_Text(pDX, IDC_EDIT_P9FE, m_f9FE);
    DDV_MinMaxFloat(pDX, m_f9FE, 0.f, 100.f);
    DDX_Text(pDX, IDC_EDIT_P13FE, m_f13FE);
    DDV_MinMaxFloat(pDX, m_f13FE, 0.f, 100.f);
    DDX_Text(pDX, IDC_EDIT_GM3, m_fGammaSetp);
    DDV_MinMaxFloat(pDX, m_fGammaSetp, 1.f, 255.f);
    DDX_Text(pDX, IDC_EDIT_P25RECTSIDE, m_n25RectSide);
    DDV_MinMaxUInt(pDX, m_n25RectSide, 0, 100);
    DDX_Text(pDX, IDC_EDIT_CROSSTALK1, m_fCrsTlkRectFE);
    DDV_MinMaxFloat(pDX, m_fCrsTlkRectFE, 0.f, 100.f);
    DDX_Text(pDX, IDC_EDIT_NITS, m_fNits);
    DDV_MinMaxFloat(pDX, m_fNits, 1.f, 600.f);
    DDX_Text(pDX, IDC_EDIT_JND_GRAYVALUE, m_JndGray);
    DDV_MinMaxUInt(pDX, m_JndGray, 0, 255);
    //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMsrItemDlg, CDialog)
    //{{AFX_MSG_MAP(CMsrItemDlg)
    ON_WM_CTLCOLOR()
    ON_WM_PAINT()
    ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
    ON_BN_CLICKED(IDC_BUTTON_DEL, OnButtonDel)
    ON_BN_CLICKED(IDC_BUTTON_SELALL, OnButtonSelall)
    ON_BN_CLICKED(IDC_BUTTON_SELNO, OnButtonSelno)
    ON_NOTIFY(UDN_DELTAPOS, IDC_SW_P9FE, OnDeltaposSwP9fe)
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMsrItemDlg message handlers

HBRUSH CMsrItemDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
    HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
    // TODO: Change any attributes of the DC here
    const ColorRef DarkClr  = RGB(  0,   0,   0);
    const ColorRef RedClr   = RGB(255,   0,   0);
    const ColorRef GreenClr = RGB(  0, 255,   0);
    const ColorRef BlueClr  = RGB(  0,   0, 255);
    const ColorRef WhiteClr = RGB(255, 255, 255);

    m_stcWhite.SetTextColor(pWnd, pDC, WhiteClr.oRGB());
    m_stcRed.  SetTextColor(pWnd, pDC, RedClr.oRGB());
    m_stcGreen.SetTextColor(pWnd, pDC, GreenClr.oRGB());
    m_stcBlue. SetTextColor(pWnd, pDC, BlueClr.oRGB());
    m_stcDark. SetTextColor(pWnd, pDC, DarkClr.oRGB());

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

void CMsrItemDlg::listBoxUpdate()
{
    m_lstMsrItems.ResetContent();
    m_btnDelItems.EnableWindow(m_RNA.Size());
    m_btnOK.EnableWindow(m_RNA.Size());

    if (m_RNA.Size())
        for (std::vector<Cartridge2>::iterator itor = m_RNA.Begin(); itor != m_RNA.End(); ++itor)
        {
            m_lstMsrItems.AddString(itor->GetDescrip());
            m_debugLog.Add(itor->GetDescrip() + "\n");
        }

    m_debugLog.Out2File(m_desktopPath+"//DNA.log");
}

void CMsrItemDlg::selMsrItem2DNA_sortable(DNA& sortableDNA)
{
    //修改的話，要同步修改
    //void COmdFile1::DNA_sortable(DNA& sortableDNA)

    //準備DNA
    //填入參數
    //JND
    UpdateData(TRUE);
//     if (m_chkJND.GetState())
//     {
//         sortableDNA.AddCell(JNDX , Pn1, m_JndGray);
//         sortableDNA.AddCell(JND , Pn1, m_JndGray);
//     }
    
    //中心點
    if (m_chkCWP1.GetState())  sortableDNA.AddCell(White, Pn1);
    if (m_chkCRP1.GetState())  sortableDNA.AddCell(Red  , Pn1);
    if (m_chkCGP1.GetState())  sortableDNA.AddCell(Green, Pn1);
    if (m_chkCBP1.GetState())  sortableDNA.AddCell(Blue , Pn1);
    if (m_chkCDP1.GetState())  sortableDNA.AddCell(Dark , Pn1);
    
    //Nits
    if (m_chkNits.GetState())  sortableDNA.AddCell(Nits, Pn9, m_fNits, m_cbxSelNitsKind.GetCurSel());
    
    //5點
    if (m_chkCWP5.GetState())    sortableDNA.AddCell(White, Pn5, m_f5FE);
    if (m_chkCRP5.GetState())    sortableDNA.AddCell(Red  , Pn5, m_f5FE);
    if (m_chkCGP5.GetState())    sortableDNA.AddCell(Green, Pn5, m_f5FE);
    if (m_chkCBP5.GetState())    sortableDNA.AddCell(Blue , Pn5, m_f5FE);
    if (m_chkCDP5.GetState())    sortableDNA.AddCell(Dark , Pn5, m_f5FE);
    
    //9點
    if (m_chkCWP9.GetState())    sortableDNA.AddCell(White, Pn9, (int)m_f9FE, m_W9FEtype);
    if (m_chkCRP9.GetState())    sortableDNA.AddCell(Red  , Pn9, (int)m_f9FE, m_W9FEtype);
    if (m_chkCGP9.GetState())    sortableDNA.AddCell(Green, Pn9, (int)m_f9FE, m_W9FEtype);
    if (m_chkCBP9.GetState())    sortableDNA.AddCell(Blue , Pn9, (int)m_f9FE, m_W9FEtype);
    if (m_chkCDP9.GetState())    sortableDNA.AddCell(Dark , Pn9, (int)m_f9FE, m_W9FEtype);
    
    //21點
    if (m_chkCWP21.GetState())    sortableDNA.AddCell(White, Pn21, m_f21FE);
    if (m_chkCRP21.GetState())    sortableDNA.AddCell(Red  , Pn21, m_f21FE);
    if (m_chkCGP21.GetState())    sortableDNA.AddCell(Green, Pn21, m_f21FE);
    if (m_chkCBP21.GetState())    sortableDNA.AddCell(Blue , Pn21, m_f21FE);
    if (m_chkCDP21.GetState())    sortableDNA.AddCell(Dark , Pn21, m_f21FE);
    
    //13點
    if (m_chkCWP13.GetState())    sortableDNA.AddCell(White, Pn13, m_f13FE);
    if (m_chkCRP13.GetState())    sortableDNA.AddCell(Red  , Pn13, m_f13FE);
    if (m_chkCGP13.GetState())    sortableDNA.AddCell(Green, Pn13, m_f13FE);
    if (m_chkCBP13.GetState())    sortableDNA.AddCell(Blue , Pn13, m_f13FE);
    if (m_chkCDP13.GetState())    sortableDNA.AddCell(Dark , Pn13, m_f13FE);
    
    //25點
    if (m_chkCWP25.GetState())    sortableDNA.AddCell(White, Pn25, m_f25FE, m_n25RectSide);
    if (m_chkCRP25.GetState())    sortableDNA.AddCell(Red  , Pn25, m_f25FE, m_n25RectSide);
    if (m_chkCGP25.GetState())    sortableDNA.AddCell(Green, Pn25, m_f25FE, m_n25RectSide);
    if (m_chkCBP25.GetState())    sortableDNA.AddCell(Blue , Pn25, m_f25FE, m_n25RectSide);
    if (m_chkCDP25.GetState())    sortableDNA.AddCell(Dark , Pn25, m_f25FE, m_n25RectSide);
    
    //49點
    if (m_chkCWP49.GetState())    sortableDNA.AddCell(White, Pn49);
    if (m_chkCRP49.GetState())    sortableDNA.AddCell(Red  , Pn49);
    if (m_chkCGP49.GetState())    sortableDNA.AddCell(Green, Pn49);
    if (m_chkCBP49.GetState())    sortableDNA.AddCell(Blue , Pn49);
    if (m_chkCDP49.GetState())    sortableDNA.AddCell(Dark , Pn49);
    
    m_debugLog.Clear();
    for (std::vector<Nucleotide>::iterator Nit = sortableDNA.Begin(); Nit != sortableDNA.End(); ++Nit)
        m_debugLog.Add(Nit->ShowMe());
}

void CMsrItemDlg::selMsrItem2DNA_Unsortable(DNA& unsortableDNA)
{
    UpdateData(TRUE);
    //Cross Talk srot by AreaCode
    if (m_chkCrossTalk.GetState())
    {
        unsortableDNA.AddCell(CrsTlk, Pn4, m_fCrsTlkRectFE);  
        unsortableDNA.AddCell(CrsTlkD, Pn4, m_fCrsTlkRectFE);  
        unsortableDNA.AddCell(CrsTlkW, Pn4, m_fCrsTlkRectFE);  
    }
    
    if (m_chkCWGM.GetState() || m_chkCDGM.GetState())        
        unsortableDNA.AddCell(White, PnGamma, m_nGM1, m_nGM2, m_fGammaSetp);  
    if (m_chkCRGM.GetState())    unsortableDNA.AddCell(Red  , PnGamma, m_nGM1, m_nGM2, m_fGammaSetp);//pDoc->GetMsrDataChain().Grow(Red  , PnGamma);
    if (m_chkCGGM.GetState())    unsortableDNA.AddCell(Green, PnGamma, m_nGM1, m_nGM2, m_fGammaSetp);//pDoc->GetMsrDataChain().Grow(Green, PnGamma);
    if (m_chkCBGM.GetState())    unsortableDNA.AddCell(Blue , PnGamma, m_nGM1, m_nGM2, m_fGammaSetp);//pDoc->GetMsrDataChain().Grow(Blue , PnGamma);
    

    m_debugLog.Clear();
    for (std::vector<Nucleotide>::iterator Nit = unsortableDNA.Begin(); Nit != unsortableDNA.End(); ++Nit)
        m_debugLog.Add(Nit->ShowMe());
}

BOOL CMsrItemDlg::checkMsrParaOK()
{
    if ( (m_f21FE == 1) || (m_f25FE == 1) || (m_f5FE == 1) || (m_f9FE == 1) || (m_f13FE == 1) || (m_fCrsTlkRectFE == 1) )
        return FALSE;
    else
        return TRUE;
}
void CMsrItemDlg::OnButtonAdd()
{
    //執行連到了這
    //1. CA-210已連線
    //2. CA-210已宣告
    if (checkMsrParaOK())
    {
        DNA sortableDNA;
        
        selMsrItem2DNA_sortable(sortableDNA);
        
        TranScripter Ts;
        if (sortableDNA.Size()) Ts.Trans(sortableDNA, m_RNA);
        m_DNA.AddCell(sortableDNA);
        //    sortableDNA.Empty();

        //排序
        if (m_chkQuickMsr.GetCheck())        m_RNA.SortQuackMsr();
        else                                 m_RNA.SortOrigMsr();
        
        
        DNA UnsortableDNA;
        
        selMsrItem2DNA_Unsortable(UnsortableDNA);
        
        if (UnsortableDNA.Size()) Ts.Trans(UnsortableDNA, m_RNA);
        m_DNA.AddCell(UnsortableDNA);
        //    UnsortableDNA.Empty();
        
        listBoxUpdate();
    }
    else
        AfxMessageBox("參數不可以為 1, 貼邊參數為 0");
}

void CMsrItemDlg::OnButtonDel() 
{
    LPINT buffer = new int[m_lstMsrItems.GetSelCount()];  //弄一個buffer，準備存放選擇好的東西
    m_lstMsrItems.GetSelItems(m_lstMsrItems.GetSelCount(), buffer);  //將選擇的選項，放進buffer
    
    //將buffer弄成RNA
    RNA temp;
    m_debugLog.Clear();
    for (int it = 0; it < m_lstMsrItems.GetSelCount(); ++it)
        temp.AddCell(m_RNA.At(buffer[it]+1));

    m_RNA.CutEqualCell(temp);
    temp.Empty();
    delete [] buffer;

    //只是更新
    listBoxUpdate();
}

BOOL CMsrItemDlg::OnInitDialog() 
{
    CDialog::OnInitDialog();
    
    // TODO: Add extra initialization here
    m_cbxSelNitsKind.AddString("+");
    m_cbxSelNitsKind.AddString("--");
    m_cbxSelNitsKind.SetCurSel(0);

    m_spinP9Para.SetRange(0, 1);
    m_spinP9Para.SetPos(1);
    m_spinP9Para.SetBase(10);


    //記憶 選項 file >> Dialog
    CFile LoadSet;
    CFileException fx;
    if (LoadSet.Open(m_RememberChkPathName, CFile::modeRead, &fx))
    {
        CArchive arch(&LoadSet, CArchive::load);
        Serialize(arch);
        arch.Close();
        LoadSet.Close();
    }
    else
    {
        //例外處理
        TCHAR buf[255];
        fx.GetErrorMessage(buf, 255);
    }
    return TRUE;  // return TRUE unless you set the focus to a control
                  // EXCEPTION: OCX Property Pages should return FALSE
}

void CMsrItemDlg::OnOK() 
{
    // TODO: Add extra validation here
    CMainFrame* pMainFrm = dynamic_cast<CMainFrame*>(AfxGetMainWnd());
    ASSERT_VALID(pMainFrm);
    
    CColorEyeIDoc* pDoc = dynamic_cast<CColorEyeIDoc*>(pMainFrm->GetActiveDocument());
    ASSERT_VALID(pDoc);

    pDoc->UpdateDocDNA(m_DNA);
    pDoc->UpdateMsrRNA(m_RNA);  
    //此Dialog是在PatternDialog前呼叫，所以還是要將DNA&RNA丟回Dialog
    //這個，還是等到PatternDialog量完再新增上來吧！

    rememberSelMsrItems();
}

void CMsrItemDlg::OnCancel() 
{
    // TODO: Add extra cleanup here
    CMainFrame* pMainFrm = dynamic_cast<CMainFrame*>(AfxGetMainWnd());
    ASSERT_VALID(pMainFrm);
    
    CColorEyeIDoc* pDoc = dynamic_cast<CColorEyeIDoc*>(pMainFrm->GetActiveDocument());
    ASSERT_VALID(pDoc);

//     m_DNA.Empty();
    m_RNA.Empty();

//     pDoc->UpdateDocDNA(m_DNA);
    pDoc->UpdateMsrRNA(m_RNA);  
    //此Dialog是在PatternDialog前呼叫，所以還是要將DNA&RNA丟回Dialog
    //這個，還是等到PatternDialog量完再新增上來吧！
    
    rememberSelMsrItems();
    
    CDialog::OnCancel();
}

void CMsrItemDlg::rememberSelMsrItems()
{
    //記憶 選項 file >> Dialog
    CFile SaveSet;
    CFileException fx;
    if (SaveSet.Open(m_RememberChkPathName, CFile::modeCreate | CFile::modeWrite, &fx))
    {
        CArchive arch(&SaveSet, CArchive::store);
        Serialize(arch);
        arch.Close();
        SaveSet.Close();
    }
    else
    {
        //例外處理
        TCHAR buf[255];
        fx.GetErrorMessage(buf, 255);
        CString strPrompt;
        strPrompt.Format("CMsrItemDlg\n%s", buf);
        AfxMessageBox(strPrompt);
    }
    CDialog::OnOK();
}

void CMsrItemDlg::Serialize(CArchive& ar) 
{
    BOOL chkQuickMsr;

    BOOL chkCrossTalk;
    BOOL chkNits;
    BOOL chkJND;

    BOOL chkCWP1 , chkCRP1 , chkCGP1 , chkCBP1 , chkCDP1 ;
    BOOL chkCWP5 , chkCRP5 , chkCGP5 , chkCBP5 , chkCDP5 ;
    BOOL chkCWP9 , chkCRP9 , chkCGP9 , chkCBP9 , chkCDP9 ;
    BOOL chkCWP13, chkCRP13, chkCGP13, chkCBP13, chkCDP13;
    BOOL chkCWP21, chkCRP21, chkCGP21, chkCBP21, chkCDP21;
    BOOL chkCWP25, chkCRP25, chkCGP25, chkCBP25, chkCDP25;
    BOOL chkCWP49, chkCRP49, chkCGP49, chkCBP49, chkCDP49;
    BOOL chkCWGM , chkCRGM , chkCGGM , chkCBGM , chkCDGM ;

    if (ar.IsStoring())
    {    // storing code
        chkQuickMsr = m_chkQuickMsr.GetCheck();    ar << chkQuickMsr;

        chkCrossTalk = m_chkCrossTalk.GetCheck();  ar << chkCrossTalk;
        chkNits = m_chkNits.GetCheck();            ar << chkNits;
        chkJND  = m_chkJND.GetCheck();             ar << chkJND;
        
        chkCWP21 = m_chkCWP21.GetCheck();    ar << chkCWP21;
        chkCRP21 = m_chkCRP21.GetCheck();    ar << chkCRP21;
        chkCGP21 = m_chkCGP21.GetCheck();    ar << chkCGP21;
        chkCBP21 = m_chkCBP21.GetCheck();    ar << chkCBP21;
        chkCDP21 = m_chkCDP21.GetCheck();    ar << chkCDP21;
        
        chkCWP9 = m_chkCWP9.GetCheck();    ar << chkCWP9;
        chkCRP9 = m_chkCRP9.GetCheck();    ar << chkCRP9;
        chkCGP9 = m_chkCGP9.GetCheck();    ar << chkCGP9;
        chkCBP9 = m_chkCBP9.GetCheck();    ar << chkCBP9;
        chkCDP9 = m_chkCDP9.GetCheck();    ar << chkCDP9;
        
        chkCWP5 = m_chkCWP5.GetCheck();    ar << chkCWP5;
        chkCRP5 = m_chkCRP5.GetCheck();    ar << chkCRP5;
        chkCGP5 = m_chkCGP5.GetCheck();    ar << chkCGP5;
        chkCBP5 = m_chkCBP5.GetCheck();    ar << chkCBP5;
        chkCDP5 = m_chkCDP5.GetCheck();    ar << chkCDP5;

        chkCWP49 = m_chkCWP49.GetCheck();    ar << chkCWP49;
        chkCRP49 = m_chkCRP49.GetCheck();    ar << chkCRP49;
        chkCGP49 = m_chkCGP49.GetCheck();    ar << chkCGP49;
        chkCBP49 = m_chkCBP49.GetCheck();    ar << chkCBP49;
        chkCDP49 = m_chkCDP49.GetCheck();    ar << chkCDP49;
        
        chkCWP25 = m_chkCWP25.GetCheck();    ar << chkCWP25;
        chkCRP25 = m_chkCRP25.GetCheck();    ar << chkCRP25;
        chkCGP25 = m_chkCGP25.GetCheck();    ar << chkCGP25;
        chkCBP25 = m_chkCBP25.GetCheck();    ar << chkCBP25;
        chkCDP25 = m_chkCDP25.GetCheck();    ar << chkCDP25;
        
        chkCWP13 = m_chkCWP13.GetCheck();    ar << chkCWP13;
        chkCRP13 = m_chkCRP13.GetCheck();    ar << chkCRP13;
        chkCGP13 = m_chkCGP13.GetCheck();    ar << chkCGP13;
        chkCBP13 = m_chkCBP13.GetCheck();    ar << chkCBP13;
        chkCDP13 = m_chkCDP13.GetCheck();    ar << chkCDP13;
        
        chkCWGM = m_chkCWGM.GetCheck();    ar << chkCWGM;
        chkCRGM = m_chkCRGM.GetCheck();    ar << chkCRGM;
        chkCGGM = m_chkCGGM.GetCheck();    ar << chkCGGM;
        chkCBGM = m_chkCBGM.GetCheck();    ar << chkCBGM;
        chkCDGM = m_chkCDGM.GetCheck();    ar << chkCDGM;
        
        chkCWP1 = m_chkCWP1.GetCheck();    ar << chkCWP1;
        chkCRP1 = m_chkCRP1.GetCheck();    ar << chkCRP1;
        chkCGP1 = m_chkCGP1.GetCheck();    ar << chkCGP1;
        chkCBP1 = m_chkCBP1.GetCheck();    ar << chkCBP1;
        chkCDP1 = m_chkCDP1.GetCheck();    ar << chkCDP1;

                                           ar << m_nGM1;
                                           ar << m_nGM2;
                                           ar << m_f21FE;
                                           ar << m_f5FE;
                                           ar << m_f9FE;
                                           ar << m_fGammaSetp;
                                           ar << m_n25RectSide;
                                           ar << m_fCrsTlkRectFE;
                                           ar << m_fNits;
    }
    else
    {    // loading code
        ar >> chkQuickMsr;   m_chkQuickMsr.SetCheck(chkQuickMsr);
        
        ar >> chkCrossTalk;  m_chkCrossTalk.SetCheck(chkCrossTalk);
        ar >> chkNits;       m_chkNits.SetCheck(chkNits);
        ar >> chkJND;        m_chkJND.SetCheck(chkJND);
        
        ar >> chkCWP21;   m_chkCWP21.SetCheck(chkCWP21);
        ar >> chkCRP21;   m_chkCRP21.SetCheck(chkCRP21);
        ar >> chkCGP21;   m_chkCGP21.SetCheck(chkCGP21);
        ar >> chkCBP21;   m_chkCBP21.SetCheck(chkCBP21);
        ar >> chkCDP21;   m_chkCDP21.SetCheck(chkCDP21);
        
        ar >> chkCWP9;   m_chkCWP9.SetCheck(chkCWP9);
        ar >> chkCRP9;   m_chkCRP9.SetCheck(chkCRP9);
        ar >> chkCGP9;   m_chkCGP9.SetCheck(chkCGP9);
        ar >> chkCBP9;   m_chkCBP9.SetCheck(chkCBP9);
        ar >> chkCDP9;   m_chkCDP9.SetCheck(chkCDP9);
        
        ar >> chkCWP5;   m_chkCWP5.SetCheck(chkCWP5);
        ar >> chkCRP5;   m_chkCRP5.SetCheck(chkCRP5);
        ar >> chkCGP5;   m_chkCGP5.SetCheck(chkCGP5);
        ar >> chkCBP5;   m_chkCBP5.SetCheck(chkCBP5);
        ar >> chkCDP5;   m_chkCDP5.SetCheck(chkCDP5);
        
        ar >> chkCWP49;   m_chkCWP49.SetCheck(chkCWP49);
        ar >> chkCRP49;   m_chkCRP49.SetCheck(chkCRP49);
        ar >> chkCGP49;   m_chkCGP49.SetCheck(chkCGP49);
        ar >> chkCBP49;   m_chkCBP49.SetCheck(chkCBP49);
        ar >> chkCDP49;   m_chkCDP49.SetCheck(chkCDP49);
        
        ar >> chkCWP25;   m_chkCWP25.SetCheck(chkCWP25);
        ar >> chkCRP25;   m_chkCRP25.SetCheck(chkCRP25);
        ar >> chkCGP25;   m_chkCGP25.SetCheck(chkCGP25);
        ar >> chkCBP25;   m_chkCBP25.SetCheck(chkCBP25);
        ar >> chkCDP25;   m_chkCDP25.SetCheck(chkCDP25);
        
        ar >> chkCWP13;   m_chkCWP13.SetCheck(chkCWP13);
        ar >> chkCRP13;   m_chkCRP13.SetCheck(chkCRP13);
        ar >> chkCGP13;   m_chkCGP13.SetCheck(chkCGP13);
        ar >> chkCBP13;   m_chkCBP13.SetCheck(chkCBP13);
        ar >> chkCDP13;   m_chkCDP13.SetCheck(chkCDP13);
        
        ar >> chkCWGM;   m_chkCWGM.SetCheck(chkCWGM);
        ar >> chkCRGM;   m_chkCRGM.SetCheck(chkCRGM);
        ar >> chkCGGM;   m_chkCGGM.SetCheck(chkCGGM);
        ar >> chkCBGM;   m_chkCBGM.SetCheck(chkCBGM);
        ar >> chkCDGM;   m_chkCDGM.SetCheck(chkCDGM);
        
        ar >> chkCWP1;   m_chkCWP1.SetCheck(chkCWP1);
        ar >> chkCRP1;   m_chkCRP1.SetCheck(chkCRP1);
        ar >> chkCGP1;   m_chkCGP1.SetCheck(chkCGP1);
        ar >> chkCBP1;   m_chkCBP1.SetCheck(chkCBP1);
        ar >> chkCDP1;   m_chkCDP1.SetCheck(chkCDP1);

        ar >> m_nGM1;
        ar >> m_nGM2;
        ar >> m_f21FE;
        ar >> m_f5FE;
        ar >> m_f9FE;
        ar >> m_fGammaSetp;
        ar >> m_n25RectSide;
        ar >> m_fCrsTlkRectFE;
        ar >> m_fNits;
    }
}


void CMsrItemDlg::OnButtonSelall() 
{
    // TODO: Add your control notification handler code here
    if (m_chkCrossTalk.IsWindowEnabled())   m_chkCrossTalk.SetCheck(TRUE);
    if (m_chkNits.IsWindowEnabled())        m_chkNits.SetCheck(TRUE);
//     if (m_chkJND.IsWindowEnabled())         m_chkJND.SetCheck(TRUE);
    
    if (m_chkCWP21.IsWindowEnabled())        m_chkCWP21.SetCheck(TRUE);
    if (m_chkCRP21.IsWindowEnabled())        m_chkCRP21.SetCheck(TRUE);
    if (m_chkCGP21.IsWindowEnabled())        m_chkCGP21.SetCheck(TRUE);
    if (m_chkCBP21.IsWindowEnabled())        m_chkCBP21.SetCheck(TRUE);
    if (m_chkCDP21.IsWindowEnabled())        m_chkCDP21.SetCheck(TRUE);
    
    if (m_chkCWP9.IsWindowEnabled())        m_chkCWP9.SetCheck(TRUE);
    if (m_chkCRP9.IsWindowEnabled())        m_chkCRP9.SetCheck(TRUE);
    if (m_chkCGP9.IsWindowEnabled())        m_chkCGP9.SetCheck(TRUE);
    if (m_chkCBP9.IsWindowEnabled())        m_chkCBP9.SetCheck(TRUE);
    if (m_chkCDP9.IsWindowEnabled())        m_chkCDP9.SetCheck(TRUE);
    
    if (m_chkCWP5.IsWindowEnabled())        m_chkCWP5.SetCheck(TRUE);
    if (m_chkCRP5.IsWindowEnabled())        m_chkCRP5.SetCheck(TRUE);
    if (m_chkCGP5.IsWindowEnabled())        m_chkCGP5.SetCheck(TRUE);
    if (m_chkCBP5.IsWindowEnabled())        m_chkCBP5.SetCheck(TRUE);
    if (m_chkCDP5.IsWindowEnabled())        m_chkCDP5.SetCheck(TRUE);
    
    if (m_chkCWP49.IsWindowEnabled())        m_chkCWP49.SetCheck(TRUE);
    if (m_chkCRP49.IsWindowEnabled())        m_chkCRP49.SetCheck(TRUE);
    if (m_chkCGP49.IsWindowEnabled())        m_chkCGP49.SetCheck(TRUE);
    if (m_chkCBP49.IsWindowEnabled())        m_chkCBP49.SetCheck(TRUE);
    if (m_chkCDP49.IsWindowEnabled())        m_chkCDP49.SetCheck(TRUE);
    
    if (m_chkCWP25.IsWindowEnabled())        m_chkCWP25.SetCheck(TRUE);
    if (m_chkCRP25.IsWindowEnabled())        m_chkCRP25.SetCheck(TRUE);
    if (m_chkCGP25.IsWindowEnabled())        m_chkCGP25.SetCheck(TRUE);
    if (m_chkCBP25.IsWindowEnabled())        m_chkCBP25.SetCheck(TRUE);
    if (m_chkCDP25.IsWindowEnabled())        m_chkCDP25.SetCheck(TRUE);
    
    if (m_chkCWP13.IsWindowEnabled())        m_chkCWP13.SetCheck(TRUE);
    if (m_chkCRP13.IsWindowEnabled())        m_chkCRP13.SetCheck(TRUE);
    if (m_chkCGP13.IsWindowEnabled())        m_chkCGP13.SetCheck(TRUE);
    if (m_chkCBP13.IsWindowEnabled())        m_chkCBP13.SetCheck(TRUE);
    if (m_chkCDP13.IsWindowEnabled())        m_chkCDP13.SetCheck(TRUE);
    
    if (m_chkCWGM.IsWindowEnabled())        m_chkCWGM.SetCheck(TRUE);
    if (m_chkCRGM.IsWindowEnabled())        m_chkCRGM.SetCheck(TRUE);
    if (m_chkCGGM.IsWindowEnabled())        m_chkCGGM.SetCheck(TRUE);
    if (m_chkCBGM.IsWindowEnabled())        m_chkCBGM.SetCheck(TRUE);
    if (m_chkCDGM.IsWindowEnabled())        m_chkCDGM.SetCheck(TRUE);
    
    if (m_chkCWP1.IsWindowEnabled())        m_chkCWP1.SetCheck(TRUE);
    if (m_chkCRP1.IsWindowEnabled())        m_chkCRP1.SetCheck(TRUE);
    if (m_chkCGP1.IsWindowEnabled())        m_chkCGP1.SetCheck(TRUE);
    if (m_chkCBP1.IsWindowEnabled())        m_chkCBP1.SetCheck(TRUE);
    if (m_chkCDP1.IsWindowEnabled())        m_chkCDP1.SetCheck(TRUE);
}

void CMsrItemDlg::OnButtonSelno() 
{
    // TODO: Add your control notification handler code here
    if (m_chkCrossTalk.IsWindowEnabled())   m_chkCrossTalk.SetCheck(FALSE);
    if (m_chkNits.IsWindowEnabled())        m_chkNits.SetCheck(FALSE);
//     if (m_chkJND.IsWindowEnabled())         m_chkJND.SetCheck(FALSE);
    
    if (m_chkCWP21.IsWindowEnabled())        m_chkCWP21.SetCheck(FALSE);
    if (m_chkCRP21.IsWindowEnabled())        m_chkCRP21.SetCheck(FALSE);
    if (m_chkCGP21.IsWindowEnabled())        m_chkCGP21.SetCheck(FALSE);
    if (m_chkCBP21.IsWindowEnabled())        m_chkCBP21.SetCheck(FALSE);
    if (m_chkCDP21.IsWindowEnabled())        m_chkCDP21.SetCheck(FALSE);
    
    if (m_chkCWP9.IsWindowEnabled())        m_chkCWP9.SetCheck(FALSE);
    if (m_chkCRP9.IsWindowEnabled())        m_chkCRP9.SetCheck(FALSE);
    if (m_chkCGP9.IsWindowEnabled())        m_chkCGP9.SetCheck(FALSE);
    if (m_chkCBP9.IsWindowEnabled())        m_chkCBP9.SetCheck(FALSE);
    if (m_chkCDP9.IsWindowEnabled())        m_chkCDP9.SetCheck(FALSE);
    
    if (m_chkCWP5.IsWindowEnabled())        m_chkCWP5.SetCheck(FALSE);
    if (m_chkCRP5.IsWindowEnabled())        m_chkCRP5.SetCheck(FALSE);
    if (m_chkCGP5.IsWindowEnabled())        m_chkCGP5.SetCheck(FALSE);
    if (m_chkCBP5.IsWindowEnabled())        m_chkCBP5.SetCheck(FALSE);
    if (m_chkCDP5.IsWindowEnabled())        m_chkCDP5.SetCheck(FALSE);
    
    if (m_chkCWP49.IsWindowEnabled())        m_chkCWP49.SetCheck(FALSE);
    if (m_chkCRP49.IsWindowEnabled())        m_chkCRP49.SetCheck(FALSE);
    if (m_chkCGP49.IsWindowEnabled())        m_chkCGP49.SetCheck(FALSE);
    if (m_chkCBP49.IsWindowEnabled())        m_chkCBP49.SetCheck(FALSE);
    if (m_chkCDP49.IsWindowEnabled())        m_chkCDP49.SetCheck(FALSE);
    
    if (m_chkCWP25.IsWindowEnabled())        m_chkCWP25.SetCheck(FALSE);
    if (m_chkCRP25.IsWindowEnabled())        m_chkCRP25.SetCheck(FALSE);
    if (m_chkCGP25.IsWindowEnabled())        m_chkCGP25.SetCheck(FALSE);
    if (m_chkCBP25.IsWindowEnabled())        m_chkCBP25.SetCheck(FALSE);
    if (m_chkCDP25.IsWindowEnabled())        m_chkCDP25.SetCheck(FALSE);
    
    if (m_chkCWP13.IsWindowEnabled())        m_chkCWP13.SetCheck(FALSE);
    if (m_chkCRP13.IsWindowEnabled())        m_chkCRP13.SetCheck(FALSE);
    if (m_chkCGP13.IsWindowEnabled())        m_chkCGP13.SetCheck(FALSE);
    if (m_chkCBP13.IsWindowEnabled())        m_chkCBP13.SetCheck(FALSE);
    if (m_chkCDP13.IsWindowEnabled())        m_chkCDP13.SetCheck(FALSE);
    
    if (m_chkCWGM.IsWindowEnabled())        m_chkCWGM.SetCheck(FALSE);
    if (m_chkCRGM.IsWindowEnabled())        m_chkCRGM.SetCheck(FALSE);
    if (m_chkCGGM.IsWindowEnabled())        m_chkCGGM.SetCheck(FALSE);
    if (m_chkCBGM.IsWindowEnabled())        m_chkCBGM.SetCheck(FALSE);
    if (m_chkCDGM.IsWindowEnabled())        m_chkCDGM.SetCheck(FALSE);
    
    if (m_chkCWP1.IsWindowEnabled())        m_chkCWP1.SetCheck(FALSE);
    if (m_chkCRP1.IsWindowEnabled())        m_chkCRP1.SetCheck(FALSE);
    if (m_chkCGP1.IsWindowEnabled())        m_chkCGP1.SetCheck(FALSE);
    if (m_chkCBP1.IsWindowEnabled())        m_chkCBP1.SetCheck(FALSE);
    if (m_chkCDP1.IsWindowEnabled())        m_chkCDP1.SetCheck(FALSE);
}


void CMsrItemDlg::OnDeltaposSwP9fe(NMHDR* pNMHDR, LRESULT* pResult) 
{
    NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
    // TODO: Add your control notification handler code here
    switch ((FEtype)pNMUpDown->iPos)
    {
    case FT_1overN:
        m_p9_1overN.EnableWindow(TRUE);
        m_p9_Ncm.EnableWindow(FALSE);
        m_W9FEtype = FT_1overN;
        break;
    case FT_Ncm:
        m_p9_1overN.EnableWindow(FALSE);
        m_p9_Ncm.EnableWindow(TRUE);
        m_W9FEtype = FT_Ncm;
    }

    *pResult = 0;
}
