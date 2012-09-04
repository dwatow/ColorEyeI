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


CEnterValueDlg::CEnterValueDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEnterValueDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEnterValueDlg)
	m_strValue = _T("");
	m_strName = _T("");
	//}}AFX_DATA_INIT
}


void CEnterValueDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEnterValueDlg)
	DDX_Text(pDX, IDC_EDIT_VALUE, m_strValue);
	DDX_Text(pDX, IDC_STATIC_SOMETHING, m_strName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEnterValueDlg, CDialog)
	//{{AFX_MSG_MAP(CEnterValueDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEnterValueDlg message handlers

