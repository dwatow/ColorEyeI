#ifndef CIRCLE_H
#define CIRCLE_H
#include <afxmt.h>
#include "Bullet.h"
#include "../CColorRef.h"

enum CirclePercent {CP_NULL, CP_X, CP_FULL};

class Circle
{
//private:
    struct myThreadInfo
    {
        Circle* pCircle;
    }m_Info1;
//public:
    static void elasticAnimation(LPVOID LParam);

//private:
    CPen m_Pen;
    int  m_nPenWidth;
    CWnd* m_pdlgcWnd;

//protected:
    CCriticalSection m_cs; //單一執行緒的鎖
    CRect    m_DrawRect;
    int      m_nRadius;
    int      m_Percent;
    CPoint   m_nCenter;
    ColorRef m_Color;

    CString m_valuesLabel;
    virtual void Draw();
    CWnd* gethWnd(){ return m_pdlgcWnd; };

private:
    CRect expandRect(int expnd = 1);
public:
    Circle(CWnd* cWnd = NULL, int r = 1);
//     Circle(CWnd* cWnd, int r = 1);
     void setWnd(CWnd* cWnd){ m_pdlgcWnd = cWnd; };

    void SetColor(const ColorRef clr);
    ColorRef GetColor() const;

    void SetRadius(int r);
    int GetRadius() const;

    void SetCenter(CPoint p);
    void SetCenter(int x, int y);
    CPoint GetCenter() const;

    CirclePercent SetPercent(int pct);
    int GetPercent() const;

    CRect DampingVibration(int, int);
    virtual void DrawCircle(CPaintDC&);
    void Animation();

#ifdef _DEBUG
    CString showMe() const;
#endif

};
#endif