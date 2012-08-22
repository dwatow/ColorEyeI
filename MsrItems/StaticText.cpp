// StaticText.cpp : implementation file
//

#include "stdafx.h"
#include "MsrItems.h"
#include "StaticText.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStaticText

CStaticText::CStaticText()
{
}

CStaticText::~CStaticText()
{
}


BEGIN_MESSAGE_MAP(CStaticText, CStatic)
    //{{AFX_MSG_MAP(CStaticText)
        // NOTE - the ClassWizard will add and remove mapping macros here.
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStaticText message handlers

CStaticText& CStaticText::SetFontFace(LPCTSTR FontFace)
{
    CFont *pFont = new CFont;
    pFont->CreateFont(16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, FF_MODERN, FontFace);
    //SetFont(&aFont);
    CStatic::SetFont(pFont);
    pFont->DeleteObject();
    
    return *this;
}

CStaticText& CStaticText::SetFont(CFont* pFont)
{
    SetFont(pFont);
    
    return *this;
}
CFont* CStaticText::GetFont()
{
    return CWnd::GetFont();
}


CStaticText& CStaticText::SetTextColor(CWnd* pWnd, CDC* pDC, COLORREF clr)
{
    if (pWnd->GetDlgCtrlID() == GetDlgCtrlID())
        pDC->SetTextColor(clr);
    
    return *this;
}

CStaticText& CStaticText::SetBkColor(CWnd* pWnd, CDC* pDC, COLORREF clr)
{
    if (pWnd->GetDlgCtrlID() == GetDlgCtrlID())
        pDC->SetBkColor(clr);

    return *this;
}

COLORREF CStaticText::GetTextColor(CDC* pDC){return pDC->GetTextColor();}
COLORREF CStaticText::GetBkColor(CDC* pDC)  {return pDC->GetBkColor();}
