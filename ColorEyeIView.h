// ColorEyeIView.h : interface of the CColorEyeIView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_COLOREYEIVIEW_H__7DEB958F_E82C_4D8B_B114_9704103E3C06__INCLUDED_)
#define AFX_COLOREYEIVIEW_H__7DEB958F_E82C_4D8B_B114_9704103E3C06__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Table.h"

class ViewTable
{
    isMsrItem  m_MsrItem;
    isMsrValue m_MsrValue;
public:
    const isMsrItem  GetMsrItem()  const               { return m_MsrItem;  }
    const isMsrValue GetMsrValue() const               { return m_MsrValue; }
                void SetMsrItem (const isMsrItem&  MI) { m_MsrItem  = MI;   }
                void SetMsrValue(const isMsrValue& MV) { m_MsrValue = MV;   }
};


class CColorEyeIView : public CScrollView
{
protected: // create from serialization only
    CColorEyeIView();
    DECLARE_DYNCREATE(CColorEyeIView)

// Attributes
public:
    CColorEyeIDoc* GetDocument();

// Operations
public:

// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CColorEyeIView)
	public:
    virtual void OnDraw(CDC* pDC);  // overridden to draw this view
    virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
    virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
    virtual ~CColorEyeIView();
#ifdef _DEBUG
    virtual void AssertValid() const;
    virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
    //{{AFX_MSG(CColorEyeIView)
    afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
    afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
//    afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
    DECLARE_MESSAGE_MAP()
private:
    void KeepSc();

//////////////////////////////////////////////////////////////////////////
//debug function
#ifdef _DEBUG
private:
    void ViewTableBkColor(isMsrItem);
    CString strTemp;
    CString temp;

    void DebugView(CDC*, CColorEyeIDoc*, UINT);
#endif

};


#ifndef _DEBUG  // debug version in ColorEyeIView.cpp
inline CColorEyeIDoc* CColorEyeIView::GetDocument()
   { return (CColorEyeIDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLOREYEIVIEW_H__7DEB958F_E82C_4D8B_B114_9704103E3C06__INCLUDED_)
