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
    descripTableRA          ("�զ�9�I"), 
    descripTableSECfrom     ("WRGBD�����I | �զ�9�I(1/6) | �զ�49�I | �¦�9�I | 5Nits9�I"), 
    descripTableQOCmassSEC  ("WRGBD�����I | �զ�9�I(1/6) | �զ�5�I(�K��) | �¦�25�I | 5Nits9�I(5-) | �Ƕ�Gamma"), 
    descripTableQOCmassTPV  ("WRGBD�����I | �զ�9�I(1/6) | �զ�9�I(3cm) | �¦�21�I | �Ƕ�Gamma"), 
    descripTableQOCmassNibo ("WRGBD�����I | �զ�9�I(1/6) | �¦�25�I | Cross Talk"), 
    descripTableQOCtest     ("RGBWD�����I | �զ�9�I(1/6) | �զ�9�I(�K��) | �¦�25�I | �¦�21�I | 5Nits | CrossTalk")
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
        AfxMessageBox("�w����檺�Ϥ��ɥX���F�I");
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
        AfxMessageBox("�w����檺�Ϥ��ɥX���F�I");
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
