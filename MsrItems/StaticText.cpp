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

CStaticText::CStaticText(){}
CStaticText::~CStaticText(){}

BEGIN_MESSAGE_MAP(CStaticText, CStatic)
    //{{AFX_MSG_MAP(CStaticText)
        // NOTE - the ClassWizard will add and remove mapping macros here.
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStaticText message handlers

const CStaticText& CStaticText::SetFontFace(const LPCTSTR& FontFace)
{
    CFont *pFont = new CFont;
    pFont->CreateFont(16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, FF_MODERN, FontFace);
    //SetFont(&aFont);
    CStatic::SetFont(pFont);
    pFont->DeleteObject();
    
    return *this;
}

const CStaticText& CStaticText::SetFont(const CFont* pFont)
{ SetFont(pFont); return *this; }
const CFont* CStaticText::GetFont() const
{ return CWnd::GetFont(); }

const CStaticText& CStaticText::SetTextColor(const CWnd* pWnd, CDC* pDC, const COLORREF& clr)
{
    if (pWnd->GetDlgCtrlID() == GetDlgCtrlID())
        pDC->SetTextColor(clr);
    
    return *this;
}

const CStaticText& CStaticText::SetBkColor(const CWnd* pWnd, CDC* pDC, const COLORREF& clr)
{
    if (pWnd->GetDlgCtrlID() == GetDlgCtrlID())
        pDC->SetBkColor(clr);

    return *this;
}

const COLORREF CStaticText::GetTextColor(const CDC* pDC) const { return pDC->GetTextColor(); }
const COLORREF CStaticText::GetBkColor  (const CDC* pDC) const { return pDC->GetBkColor();   }
