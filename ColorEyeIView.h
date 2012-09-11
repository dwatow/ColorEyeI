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
    isMsrItem  GetMsrItem()  const            {    return m_MsrItem;    }
    isMsrValue GetMsrValue() const            {    return m_MsrValue;    }
    void SetMsrItem (const isMsrItem&  MI)    {    m_MsrItem = MI;        }
    void SetMsrValue(const isMsrValue& MV)    {    m_MsrValue = MV;    }
};


class CColorEyeIView : public CScrollView
{
    CPoint m_MousePoint;

    //Debug var
    std::vector<BOOL*>  m_isMsr;
    BOOL TbBkClr_WRGBD[10];
    BOOL TbBkClr_D25[10];
    BOOL TbBkClr_W49[10];
    BOOL TbBkClr_W9[10];
    BOOL TbBkClr_W5[10];
    BOOL TbBkClr_Nits[10];

    std::vector<ViewTable> m_vViewTable;
    std::vector<CPoint> m_NvgtHit;//導覽命中座標點

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
    afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
    DECLARE_MESSAGE_MAP()
private:
	void DrawAsTxtFile(CDC* pDC, TxtStrData Data, CPoint& pt);
	void DrawAsOmdFile(CDC* pDC, OmdValueData Data, CPoint& pt);

    COLORREF isMsrToBkColor(BOOL b)
    { return b ? RGB(255, 255, 255) : RGB(192, 192, 192); };
//    void ViewMsrItemView(std::vector<Cartridge>&, CDC, CPoint);
	/*
    CPoint DrawW05Table_Lv (CDC*, CColorEyeIDoc*, CPoint);
    CPoint DrawW05Table_Sx (CDC*, CColorEyeIDoc*, CPoint);
    CPoint DrawW05Table_Sy (CDC*, CColorEyeIDoc*, CPoint);
    CPoint DrawW05Table_Du (CDC*, CColorEyeIDoc*, CPoint);
    CPoint DrawW05Table_Dv (CDC*, CColorEyeIDoc*, CPoint);
    CPoint DrawW05Table_T  (CDC*, CColorEyeIDoc*, CPoint);
    CPoint DrawW05Table_Duv(CDC*, CColorEyeIDoc*, CPoint);
    CPoint DrawW05Table_X  (CDC*, CColorEyeIDoc*, CPoint);
    CPoint DrawW05Table_Y  (CDC*, CColorEyeIDoc*, CPoint);
    CPoint DrawW05Table_Z  (CDC*, CColorEyeIDoc*, CPoint);

    CPoint DrawW09Table_Lv (CDC*, CColorEyeIDoc*, CPoint);
    CPoint DrawW09Table_Sx (CDC*, CColorEyeIDoc*, CPoint);
    CPoint DrawW09Table_Sy (CDC*, CColorEyeIDoc*, CPoint);
    CPoint DrawW09Table_Du (CDC*, CColorEyeIDoc*, CPoint);
    CPoint DrawW09Table_Dv (CDC*, CColorEyeIDoc*, CPoint);
    CPoint DrawW09Table_T  (CDC*, CColorEyeIDoc*, CPoint);
    CPoint DrawW09Table_Duv(CDC*, CColorEyeIDoc*, CPoint);
    CPoint DrawW09Table_X  (CDC*, CColorEyeIDoc*, CPoint);
    CPoint DrawW09Table_Y  (CDC*, CColorEyeIDoc*, CPoint);
    CPoint DrawW09Table_Z  (CDC*, CColorEyeIDoc*, CPoint);

    CPoint DrawW49Table_Lv (CDC*, CColorEyeIDoc*, CPoint);
    CPoint DrawW49Table_Sx (CDC*, CColorEyeIDoc*, CPoint);
    CPoint DrawW49Table_Sy (CDC*, CColorEyeIDoc*, CPoint);
    CPoint DrawW49Table_Du (CDC*, CColorEyeIDoc*, CPoint);
    CPoint DrawW49Table_Dv (CDC*, CColorEyeIDoc*, CPoint);
    CPoint DrawW49Table_T  (CDC*, CColorEyeIDoc*, CPoint);
    CPoint DrawW49Table_Duv(CDC*, CColorEyeIDoc*, CPoint);
    CPoint DrawW49Table_X  (CDC*, CColorEyeIDoc*, CPoint);
    CPoint DrawW49Table_Y  (CDC*, CColorEyeIDoc*, CPoint);
    CPoint DrawW49Table_Z  (CDC*, CColorEyeIDoc*, CPoint);

    CPoint DrawD25Table_Lv (CDC*, CColorEyeIDoc*, CPoint);
    CPoint DrawD25Table_Sx (CDC*, CColorEyeIDoc*, CPoint);
    CPoint DrawD25Table_Sy (CDC*, CColorEyeIDoc*, CPoint);
    CPoint DrawD25Table_Du (CDC*, CColorEyeIDoc*, CPoint);
    CPoint DrawD25Table_Dv (CDC*, CColorEyeIDoc*, CPoint);
    CPoint DrawD25Table_T  (CDC*, CColorEyeIDoc*, CPoint);
    CPoint DrawD25Table_Duv(CDC*, CColorEyeIDoc*, CPoint);
    CPoint DrawD25Table_X  (CDC*, CColorEyeIDoc*, CPoint);
    CPoint DrawD25Table_Y  (CDC*, CColorEyeIDoc*, CPoint);
    CPoint DrawD25Table_Z  (CDC*, CColorEyeIDoc*, CPoint);

     CPoint DrawWRGBDTable_Lv (CDC*, CColorEyeIDoc*, CPoint);
//     CPoint DrawWRGBDTable_Sx (CDC*, CColorEyeIDoc*, CPoint);
//     CPoint DrawWRGBDTable_Sy (CDC*, CColorEyeIDoc*, CPoint);
//     CPoint DrawWRGBDTable_Du (CDC*, CColorEyeIDoc*, CPoint);
//     CPoint DrawWRGBDTable_Dv (CDC*, CColorEyeIDoc*, CPoint);
//     CPoint DrawWRGBDTable_T  (CDC*, CColorEyeIDoc*, CPoint);
//     CPoint DrawWRGBDTable_Duv(CDC*, CColorEyeIDoc*, CPoint);
//     CPoint DrawWRGBDTable_X  (CDC*, CColorEyeIDoc*, CPoint);
//     CPoint DrawWRGBDTable_Y  (CDC*, CColorEyeIDoc*, CPoint);
//     CPoint DrawWRGBDTable_Z  (CDC*, CColorEyeIDoc*, CPoint);

    CPoint DrawNitsTable_Lv (CDC*, CColorEyeIDoc*, CPoint);
    CPoint DrawNitsTable_Sx (CDC*, CColorEyeIDoc*, CPoint);
    CPoint DrawNitsTable_Sy (CDC*, CColorEyeIDoc*, CPoint);
    CPoint DrawNitsTable_Du (CDC*, CColorEyeIDoc*, CPoint);
    CPoint DrawNitsTable_Dv (CDC*, CColorEyeIDoc*, CPoint);
    CPoint DrawNitsTable_T  (CDC*, CColorEyeIDoc*, CPoint);
    CPoint DrawNitsTable_Duv(CDC*, CColorEyeIDoc*, CPoint);
    CPoint DrawNitsTable_X  (CDC*, CColorEyeIDoc*, CPoint);
    CPoint DrawNitsTable_Y  (CDC*, CColorEyeIDoc*, CPoint);
    CPoint DrawNitsTable_Z  (CDC*, CColorEyeIDoc*, CPoint);

  CPoint DrawTable(isMsrItem, isMsrValue, CDC*, CColorEyeIDoc*, CPoint);
*/        //   DrawTableTitle(CDC* pDC, CPoint ptTemp, const CString strTitle)
    CPoint DrawTableTitle  (CDC*, CPoint, const CString);

    void KeepSc();

    isMsrItem  UIntToMrItm(UINT);
    isMsrValue UIntToMrVle(UINT);

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
