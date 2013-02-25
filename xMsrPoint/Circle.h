#ifndef CIRCLE_H
#define CIRCLE_H
#include <afxmt.h>
#include "Bullet.h"
#include "../CColorRef.h"

enum CirclePercent {CP_NULL, CP_X, CP_FULL};

class Circle
{
	CDC *m_pDC;
    CPen m_Pen;
    int  m_nPenWidth;

protected:
    CCriticalSection m_cs; //單一執行緒的鎖
    CRect    m_DrawRect;
    int      m_nRadius;
    int      m_Percent;
    CPoint   m_nCenter;
    ColorRef m_Color;

	CString m_valuesLabel;
    virtual void Draw(){};

private:
	void reSetRect(int expnd = 0);
public:
    Circle(int r = 1);

    void SetColor(const ColorRef clr);
    ColorRef GetColor() const;

    void SetRadius(int r);
    int GetRadius() const;

    void SetCenter(CPoint p);
    void SetCenter(int x, int y);
    CPoint GetCenter() const;

    CirclePercent SetPercent(int pct);
    int GetPercent() const;

    virtual void DrawCircle(CPaintDC&);
//    virtual CRect VbrFun(int, int);

// private:
// 	struct myThreadInfo
//     {
//         Circle* pCircle;
//     }Info1;
// public:
// 	static void elasticAnimation(LPVOID LParam);

#ifdef _DEBUG
    CString showMe() const;
#endif

};
#endif