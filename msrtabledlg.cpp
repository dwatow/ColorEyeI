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
	: CDialog(CMsrTableDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMsrTableDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CMsrTableDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMsrTableDlg)
	DDX_Control(pDX, IDC_STATIC_TABLE_VIEW, m_tableView);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMsrTableDlg, CDialog)
	//{{AFX_MSG_MAP(CMsrTableDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMsrTableDlg message handlers

BOOL CMsrTableDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CBitmap bmp;
	bmp.LoadBitmap(IDB_BMP_RA_FROM);
// 	HBITMAP bmp = 
// 	(HBITMAP)LoadImage(NULL,_T(".\\\DataFile\\Picture\\mail.bmp"),IMAGE_BITMAP,512,256,LR_LOADFROMFILE);
	
	
 	m_tableView.g


	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
