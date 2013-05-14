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
	
	CMsrTableDlg* pDlgMsrTable = dynamic_cast<CMsrTableDlg*>(GetOwner());

         if ( checkKeyBtnText("SEC From" ) )    pDlgMsrTable->SetTableImage(TI_SEC);
    else if ( checkKeyBtnText("RA"  ) )         pDlgMsrTable->SetTableImage(TI_RA);
    else if ( checkKeyBtnText("量產") )          pDlgMsrTable->SetTableImage(TI_OQCMASS);
	else if ( checkKeyBtnText("試產") )          pDlgMsrTable->SetTableImage(TI_OQCTEST);

    CButton::OnMouseMove(nFlags, point);
}

BOOL CBtm::checkKeyBtnText(const CString& keyText)
{
	CString btnText;
    GetWindowText(btnText);

    if (btnText.Find(keyText) != -1)
        return TRUE;
    else
        return FALSE;
}
