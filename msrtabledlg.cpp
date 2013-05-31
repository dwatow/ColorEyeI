// MsrTableDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ColorEyeI.h"
#include "MsrTableDlg.h"
#include "TranScripter.h"
#include "MainFrm.h"
#include "ColorEyeIDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMsrTableDlg dialog

CMsrTableDlg::CMsrTableDlg(CWnd* pParent /*=NULL*/)
    : CDialog(CMsrTableDlg::IDD, pParent), m_TableIndex(TI_OQC_MASS_TPV), 
    descripTableRA          ("白色9點"), 
    descripTableSECfrom     ("WRGBD中心點 | 白色9點(1/6) | 白色49點 | 黑色9點 | 5Nits9點"), 
    descripTableQOCmassSEC  ("WRGBD中心點 | 白色9點(1/6) | 白色5點(貼邊) | 黑色25點 | 5Nits9點(5-) | 灰階Gamma"), 
    descripTableQOCmassTPV  ("WRGBD中心點 | 白色9點(1/6) | 白色9點(3cm) | 黑色21點 | 灰階Gamma"), 
    descripTableQOCmassNibo ("WRGBD中心點 | 白色9點(1/6) | 黑色25點 | Cross Talk"), 
    descripTableQOCtest     ("RGBWD中心點 | 白色9點(1/6) | 白色9點(貼邊) | 黑色25點 | 黑色21點 | 5Nits | CrossTalk")
{
    //{{AFX_DATA_INIT(CMsrTableDlg)
    //}}AFX_DATA_INIT
}

void CMsrTableDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CMsrTableDlg)
	DDX_Control(pDX, IDC_BTN_OQC_NIBO, m_tableOQCNibo);
    DDX_Control(pDX, IDC_BTN_SECF, m_tableSECF);
    DDX_Control(pDX, IDC_BTN_RA, m_tableRA);
    DDX_Control(pDX, IDC_BTN_OQC_TPV, m_tableOQCTPV);
    DDX_Control(pDX, IDC_BTN_OQC_TEST, m_tableOQCtest);
    DDX_Control(pDX, IDC_BTN_OQC_SEC, m_tableOQCSEC);
    DDX_Control(pDX, IDC_TABLE_DESCRIP, m_tableDescrip);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMsrTableDlg, CDialog)
    //{{AFX_MSG_MAP(CMsrTableDlg)
    ON_WM_PAINT()
//     ON_BN_CLICKED(IDC_BUTTON3, OnButtonOQCMASS)
    ON_BN_CLICKED(IDC_BTN_OQC_NIBO, OnBtnOqcNibo)
    ON_BN_CLICKED(IDC_BTN_OQC_SEC, OnBtnOqcSec)
    ON_BN_CLICKED(IDC_BTN_RA, OnBtnRa)
    ON_BN_CLICKED(IDC_BTN_SECF, OnBtnSecfrom)
    ON_BN_CLICKED(IDC_BTN_OQC_TEST, OnBtnOqcTest)
    ON_BN_CLICKED(IDC_BTN_OQC_TPV, OnBtnOqcTpv)
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMsrTableDlg message handlers

BOOL CMsrTableDlg::OnInitDialog() 
{
    CDialog::OnInitDialog();
    
    // TODO: Add extra initialization here

    return TRUE;  // return TRUE unless you set the focus to a control
                  // EXCEPTION: OCX Property Pages should return FALSE
}

void CMsrTableDlg::OnPaint() 
{
    CPaintDC dc(this); // device context for painting
    // TODO: Add your message handler code here
    showTableImage(&dc);
    showMsrItem(&dc);
    // Do not call CDialog::OnPaint() for painting messages
}

void CMsrTableDlg::showTableImage(CPaintDC* pDc)
{
    CBitmap m_tableImage;
    m_tableImage.LoadBitmap(tableID());//
    
    CDC memDC;
    memDC.CreateCompatibleDC(pDc);
    CBitmap* oldBitMap = memDC.SelectObject(&m_tableImage);
    
    pDc->BitBlt(20, 33, 542, 334, &memDC, 0, 0, SRCCOPY);
    pDc->SelectObject(oldBitMap);
}

void CMsrTableDlg::showMsrItem(CPaintDC* pDc)
{
    m_tableDescrip.SetWindowText(tableDescrip());//
}

const UINT CMsrTableDlg::tableID() const
{
    switch(m_TableIndex)
    {
    case TI_SEC_From:      return IDB_BMP_SEC_FROM;
    case TI_OQC_MASS_SEC:  return IDB_BMP_OQC_MASS;
    case TI_OQC_MASS_TPV:  return IDB_BMP_OQC_MASS;
    case TI_QOC_MASS_NIBO: return IDB_BMP_OQC_MASS;
    case TI_OQC_TEST:      return IDB_BMP_OQC_TEST;
    case TI_RA:            return IDB_BMP_RA_FROM;
    default:
        AfxMessageBox("預覽表格的圖片時出錯了！");
        return IDB_BMP_SEC_FROM;
    }
}

const CString CMsrTableDlg::tableDescrip() const
{
    switch(m_TableIndex)
    {
	case TI_SEC_From:      return descripTableSECfrom;
    case TI_OQC_MASS_SEC:  return descripTableQOCmassSEC;
    case TI_OQC_MASS_TPV:  return descripTableQOCmassTPV;
    case TI_QOC_MASS_NIBO: return descripTableQOCmassNibo;
    case TI_OQC_TEST:      return descripTableQOCtest;
    case TI_RA:            return descripTableRA;
    default:
        AfxMessageBox("預覽表格的圖片時出錯了！");
        return "";
    }
}

void CMsrTableDlg::SetTableImage(const tableIndex& index)
{
    if (m_TableIndex != index)
    {
         m_TableIndex = index;
        Invalidate();
    }
}

void CMsrTableDlg::Exit()
{
    m_DnaInit.CreatDNA(m_DNA, m_RNA);

    CMainFrame* pMainFrm = dynamic_cast<CMainFrame*>(AfxGetMainWnd());
    ASSERT_VALID(pMainFrm);
    
    CColorEyeIDoc* pDoc = dynamic_cast<CColorEyeIDoc*>(pMainFrm->GetActiveDocument());
    ASSERT_VALID(pDoc);
    
    pDoc->UpdateDocDNA(m_DNA);
    pDoc->UpdateMsrRNA(m_RNA);  

    CDialog::OnOK();
}

void CMsrTableDlg::OnBtnOqcNibo() 
{
    m_DnaInit.Add_Table_OQC_MASS_NIBO();
    Exit();
}

void CMsrTableDlg::OnBtnOqcSec() 
{
    m_DnaInit.Add_Table_OQC_MASS_SEC();
    Exit();
}

void CMsrTableDlg::OnBtnRa() 
{
    m_DnaInit.Add_Table_RA();
    Exit();
}

void CMsrTableDlg::OnBtnSecfrom() 
{
    m_DnaInit.Add_Table_SEC();    
    Exit();
}

void CMsrTableDlg::OnBtnOqcTest() 
{
    m_DnaInit.Add_Table_OQC_TEST();    
    Exit();
}

void CMsrTableDlg::OnBtnOqcTpv() 
{
    m_DnaInit.Add_Table_OQC_MASS_TPV();
    Exit();
}
