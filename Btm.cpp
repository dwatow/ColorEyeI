// Btm.cpp : implementation file
//

#include "stdafx.h"
#include "ColorEyeI.h"
#include "Btm.h"
#include "MsrTableDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBtm

CBtm::CBtm()
{
// 	CRect rect;
// 	GetWindowRect(&rect);
	
// 	CString str;
// 	str.Format("Buttom:%d, %d, %d, %d", rect.left, rect.top, rect.right, rect.bottom);
// 	AfxMessageBox(str);
}

CBtm::~CBtm()
{
}


BEGIN_MESSAGE_MAP(CBtm, CButton)
	//{{AFX_MSG_MAP(CBtm)
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBtm message handlers


void CBtm::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CMsrTableDlg* pDlg = dynamic_cast<CMsrTableDlg*>(GetOwner());
	CString str;
	// 	str.Format("%d, %d, %d, %d", rect.left, rect.top, rect.right, rect.bottom);
	// 	//str.Format("%d, %d", pt.x, pt.y);
	GetWindowText(str);
	if (str.Find("SEC") != -1)
		pDlg->SetTableImage(TI_SEC);
	else if (str.Find("RA") != -1)
		pDlg->SetTableImage(TI_RA);
	else if (str.Find("mass") != -1)
		pDlg->SetTableImage(TI_OQCMASS);
// 	else
// 		AfxMessageBox("°ÝÃD");

// 	str.Format("0x%p", GetOwner());
//  	AfxMessageBox(str);

	CButton::OnMouseMove(nFlags, point);
}
