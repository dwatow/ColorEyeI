#if !defined(AFX_STATICTEXT_H__5371577E_8E50_4DCA_93C5_9E3DD65AF6BB__INCLUDED_)
#define AFX_STATICTEXT_H__5371577E_8E50_4DCA_93C5_9E3DD65AF6BB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StaticText.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStaticText window

class CStaticText : public CStatic
{
    LPFONT lpFont;
// Construction
public:
    CStaticText();

// Attributes
public:

// Operations
public:

// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CStaticText)
    //}}AFX_VIRTUAL

// Implementation
public:
    //OnCtlColor of Dlg
    const CStaticText& SetTextColor(const CWnd* pWnd, CDC* pDC, const COLORREF& clr);
    const CStaticText& SetBkColor  (const CWnd* pWnd, CDC* pDC, const COLORREF& clr);
    const    COLORREF  GetTextColor(const CDC* pDC) const;
    const    COLORREF  GetBkColor  (const CDC* pDC) const;

    const CStaticText& SetFontFace(const LPCTSTR& FontFace);
    const CStaticText& SetFont(const CFont* pFont);
    const       CFont* GetFont() const;

    virtual ~CStaticText();

    // Generated message map functions
protected:
    //{{AFX_MSG(CStaticText)
        // NOTE - the ClassWizard will add and remove member functions here.
    //}}AFX_MSG

    DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STATICTEXT_H__5371577E_8E50_4DCA_93C5_9E3DD65AF6BB__INCLUDED_)
