#ifndef CIRCLE_H
#define CIRCLE_H
#include <afxmt.h>

class Circle
{
    CPen m_Pen;
    int m_nPenWidth;
    COLORREF m_BkColor;
public:
    Circle();
     void reSetRect(int range = 0);
//     CRect GetRect() const;

    BOOL SetColor(COLORREF clr);
    COLORREF GetColor() const;

//     BOOL SetBkColor(COLORREF clr);
//     COLORREF GetBkColor() const;

    BOOL SetRadius(UINT r);
    UINT GetRadius() const;

    BOOL SetCenter(CPoint p);
    BOOL SetCenter(int x, int y);
    CPoint GetCenter() const;

    UINT SetPercent(UINT pct);
    UINT GetPercent() const;

    virtual void DrawCircle(CPaintDC&);
    virtual CRect VbrFun(UINT, UINT);

#ifdef _DEBUG
    CString GetSetupValue() const;
#endif

protected:
    CCriticalSection m_cs; //單一執行緒的鎖
    CRect    m_DrawRect;
    UINT     m_nRadius;
    UINT     m_Percent;
    CPoint   m_nCenter;
    COLORREF m_Color;
    virtual void DrawArc(CPoint& ){};
    virtual void DrawClr(COLORREF& ){};
};
#endif