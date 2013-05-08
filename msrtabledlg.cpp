// MsrTableDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ColorEyeI.h"
#include "MsrTableDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMsrTableDlg dialog


CMsrTableDlg::CMsrTableDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMsrTableDlg::IDD, pParent), m_TableIndex(TI_OQCMASS)
{
	//{{AFX_DATA_INIT(CMsrTableDlg)
	//}}AFX_DATA_INIT
}


void CMsrTableDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMsrTableDlg)
	DDX_Control(pDX, IDC_BUTTON3, m_msrRAtable);
	DDX_Control(pDX, IDC_BUTTON2, m_msrSECtable);
	DDX_Control(pDX, IDC_BUTTON4, m_msrOQCMASStable);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMsrTableDlg, CDialog)
	//{{AFX_MSG_MAP(CMsrTableDlg)
	ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
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
	CBitmap m_tableImage;
	m_tableImage.LoadBitmap(tableID());


	CDC memDC;
	memDC.CreateCompatibleDC(&dc);
	CBitmap* oldBitMap = memDC.SelectObject(&m_tableImage);

	dc.BitBlt(240, 33, 450, 332, &memDC, 0, 0, SRCCOPY);
	dc.SelectObject(oldBitMap);
	// Do not call CDialog::OnPaint() for painting messages
}

UINT CMsrTableDlg::tableID()
{
	switch(m_TableIndex)
	{
	case TI_SEC:     return IDB_BMP_SEC_FROM;
	case TI_RA:      return IDB_BMP_RA_FROM;
	//case TI_OQCTEST:
	case TI_OQCMASS: return IDB_BMP_OQC_MASS;
	default:
		AfxMessageBox("預覽表格的圖片時出錯了！");
// 		ASSERT(0);
		return IDB_BMP_SEC_FROM;
	}
}


void CMsrTableDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	CDialog::OnMouseMove(nFlags, point);
}

void CMsrTableDlg::SetTableImage(tableIndex index)
{
	m_TableIndex = index;
	Invalidate();
}
