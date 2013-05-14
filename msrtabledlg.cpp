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
	: CDialog(CMsrTableDlg::IDD, pParent), m_TableIndex(TI_OQCMASS), 
	descripTableRA("白色9點"), 
	descripTableSEC("RGBW中心點 | 白色9點 | 白色49點 | 黑色9點 | 5Nits"), 
	descripTableQOCmass("RGBW中心點 | 白色9點 | 白色49點 | 黑色9點 | 5Nits | CrossTalk | ...之類的mass"), 
	descripTableQOCtest("RGBW中心點 | 白色9點 | 白色49點 | 黑色9點 | 5Nits | CrossTalk | ...之類的test")
{
	//{{AFX_DATA_INIT(CMsrTableDlg)
	//}}AFX_DATA_INIT
}


void CMsrTableDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMsrTableDlg)
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
	ON_BN_CLICKED(IDC_BUTTON4, OnButtonRA)
	ON_BN_CLICKED(IDC_BUTTON2, OnButtonSEC)
	ON_BN_CLICKED(IDC_BUTTON3, OnButtonOQCMASS)
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
	m_tableImage.LoadBitmap(tableID());
	
	CDC memDC;
	memDC.CreateCompatibleDC(pDc);
	CBitmap* oldBitMap = memDC.SelectObject(&m_tableImage);
	
	pDc->BitBlt(20, 33, 542, 334, &memDC, 0, 0, SRCCOPY);
	pDc->SelectObject(oldBitMap);
}

void CMsrTableDlg::showMsrItem(CPaintDC* pDc)
{
// 	CRect textRect(240, 275, 98+240, 107+275);
// 	pDc->FillSolidRect(&textRect, GetSysColor(COLOR_BTNFACE));
// 	pDc->DrawText(tableDescrip(), &textRect, DT_RIGHT );
	m_tableDescrip.SetWindowText(tableDescrip());
}

const UINT CMsrTableDlg::tableID() const
{
	switch(m_TableIndex)
	{
	case TI_SEC:     return IDB_BMP_SEC_FROM;
	case TI_RA:      return IDB_BMP_RA_FROM;
	case TI_OQCMASS: return IDB_BMP_OQC_MASS;
	case TI_OQCTEST: return IDB_BMP_OQC_TEST;
	default:
		AfxMessageBox("預覽表格的圖片時出錯了！");
		return IDB_BMP_SEC_FROM;
	}
}

const CString CMsrTableDlg::tableDescrip() const
{
	switch(m_TableIndex)
	{
	case TI_SEC:     return descripTableSEC;
	case TI_RA:      return descripTableRA;
	case TI_OQCMASS: return descripTableQOCmass;
	case TI_OQCTEST: return descripTableQOCtest;
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

void CMsrTableDlg::OnButtonRA() 
{
	m_DnaInit.Add_Table_RA();

	Exit();
}

void CMsrTableDlg::OnButtonSEC() 
{
	// TODO: Add your control notification handler code here
	m_DnaInit.Add_Table_SEC();

	Exit();
}

void CMsrTableDlg::OnButtonOQCMASS() 
{
	// TODO: Add your control notification handler code here
	m_DnaInit.Add_Table_OQC_MASS_TPV();
	Exit();
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
