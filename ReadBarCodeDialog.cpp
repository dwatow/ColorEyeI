// ReadBarCodeDialog.cpp : implementation file
//

#include "stdafx.h"
#include "ColorEyeI.h"
#include "ReadBarCodeDialog.h"
#include "OmdFile/TxtFile.h"
#include "MainFrm.h"
#include "ColorEyeIDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CReadBarCodeDialog dialog


CReadBarCodeDialog::CReadBarCodeDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CReadBarCodeDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CReadBarCodeDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

}


void CReadBarCodeDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CReadBarCodeDialog)
	DDX_Control(pDX, IDC_STATIC_BARCODE, m_stcBarCode);
	DDX_Control(pDX, IDC_COMBO_SELNO, m_cbxNo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CReadBarCodeDialog, CDialog)
	//{{AFX_MSG_MAP(CReadBarCodeDialog)
	ON_CBN_SELCHANGE(IDC_COMBO_SELNO, OnSelchangeComboSelno)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReadBarCodeDialog message handlers

void CReadBarCodeDialog::InitBarCodeList()
{
	CColorEyeIApp* pApp = dynamic_cast<CColorEyeIApp*>(AfxGetApp());
	ASSERT_VALID(pApp);
	
	m_PathName.Format("%s\\BarCode.txt", pApp->GetPath());
	CTxtFile fTxt;
	CFileException fx;	
	if (fTxt.Open(m_PathName, fx))
	{
		fTxt.oTxtData(m_Barcodelsit);
		fTxt.Close();
	}
	else
		CDialog::OnCancel();


	CString str;
	for (int i = 0; i < m_Barcodelsit.size(); ++i)
	{
		str.Format("%d", i);
		m_cbxNo.AddString(str);
	}

	m_Barcodelsit.push_back("");
	m_cbxNo.AddString("null");
}

void CReadBarCodeDialog::OnSelchangeComboSelno() 
{
	// TODO: Add your control notification handler code here
	m_stcBarCode.SetWindowText(m_Barcodelsit.at(m_cbxNo.GetCurSel()));
}

BOOL CReadBarCodeDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	InitBarCodeList();
	m_cbxNo.SetCurSel(m_cbxNo.GetCount()-1);
	OnSelchangeComboSelno();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CReadBarCodeDialog::OnOK() 
{
	// TODO: Add extra validation here
	CMainFrame* pMainFrm = dynamic_cast<CMainFrame*>(AfxGetMainWnd());
	ASSERT_VALID(pMainFrm);

	CColorEyeIDoc* pDoc = dynamic_cast<CColorEyeIDoc*>(pMainFrm->GetActiveDocument());
	ASSERT_VALID(pDoc);
	
	CString pnlId;
	m_stcBarCode.GetWindowText(pnlId);
	pDoc->SetPnlID(pnlId);

	CDialog::OnOK();
}
