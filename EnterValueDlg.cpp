// EnterValueDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ColorEyeI.h"
#include "EnterValueDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEnterValueDlg dialog


CEnterValueDlg::CEnterValueDlg(const CString& dlgTitle, const CString& label, CWnd* pParent /*=NULL*/)
	: CDialog(CEnterValueDlg::IDD, pParent), m_strName(label)
{
	m_dlgTitle.Format("%s", dlgTitle);
	//{{AFX_DATA_INIT(CEnterValueDlg)
	m_strName = _T("");
	m_strValue = _T("");
	//}}AFX_DATA_INIT
}


void CEnterValueDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEnterValueDlg)
	DDX_Text(pDX, IDC_STATIC_SOMETHING, m_strName);
	DDX_Text(pDX, IDC_EDIT_VALUE, m_strValue);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEnterValueDlg, CDialog)
	//{{AFX_MSG_MAP(CEnterValueDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEnterValueDlg message handlers


BOOL CEnterValueDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	SetWindowText(m_dlgTitle);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
