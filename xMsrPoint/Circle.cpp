#include "stdafx.h"
#include "Circle.h"
#include <cmath>

Circle::Circle(int r):m_Percent(r), m_nPenWidth(5)
{
}

void Circle::SetCenter(CPoint p)
{
    SetCenter(p.x, p.y);
}

void Circle::SetCenter(int x, int y)
{
    ASSERT(x >= 0 && y >= 0);
    m_nCenter.x = x;
    m_nCenter.y = y;
}

void Circle::SetRadius(int r)
{
	ASSERT(r > 0);
    m_nRadius = r;
}

int Circle::GetRadius() const
{
    return m_nRadius;
}

CPoint Circle::GetCenter() const
{
    return m_nCenter;
}

void Circle::DrawCircle(CPaintDC &dc)
{
    //設定畫筆
    CPen* OldPen;

    CPoint StartPoint(m_nCenter.x, m_nCenter.y - m_nRadius);
    CPoint   EndPoint(m_nCenter.x, m_nCenter.y - m_nRadius);
    
    if(m_Percent > 0 && m_Percent < 100)  
        Draw();

    reSetRect();
    OldPen = dc.SelectObject(&m_Pen);
    dc.Arc(m_DrawRect, StartPoint, EndPoint);

    dc.SelectObject(OldPen);
}

CirclePercent Circle::SetPercent(int percent)
{
    //繼續 未滿100%
    //停止 超過100%
    if (percent < 0)
    {
        m_Percent = 0;
        return CP_NULL;//空杯啦
    }
    else if (percent >= 0 && percent <100)
    {
        m_Percent = percent;
        return CP_X;//進行中
    }
    else if (percent >= 100)
    {
        m_Percent = 100;
        return CP_FULL;//滿出來啦
    }
	else
	{
		ASSERT(0);
		return CP_FULL;
	}
}
int Circle::GetPercent() const
{
    return m_Percent;
}

void Circle::SetColor(const COLORREF clr)
{
    const int O = 0x000000FF & (clr >>24);
    const int B = GetBValue(clr);
    const int G = GetGValue(clr);
    const int R = GetRValue(clr);

    ASSERT(O == 0 && R >= 0 && R <256
                  && G >= 0 && G <256 
                  && B >= 0 && B <256 );

    m_Color = clr;
    m_Pen.DeleteObject();
    m_Pen.CreatePen(PS_SOLID, m_nPenWidth, m_Color);//變色
}

COLORREF Circle::GetColor() const
{
    return m_Color;
}


// void Circle::elasticAnimation(LPVOID LParam)
// {
//     CPatternDlg  *PtnDlg = (CPatternDlg*)(pInfo1->ptnDlg);
// 	Circle *pCircle = (Circle*)(PtnDlg->m_Goal);
// 
// 	ASSERT_VALID(PtnDlg);
// 	ASSERT(pInfo1);
// 	ASSERT(pCircle);
// 
// 	for (UINT i = 0; i < 16; ++i)
//     {
//         pCircle->VbrFun(i, pCircle->GetRadius());
//         Sleep(15); //調節動畫重畫時是否看得到
//     }
// }

// CRect Circle::VbrFun(int k, int x0)
// {
//     //max = 375
//     //min = 0
//     //375-15/15
// 	ASSERT(k>=0);
// 	ASSERT(x0>=0);
//     int T0 = 15;
//     CSingleLock csl(&m_cs);
//     csl.Lock();
//     double timeX = 24*k;
//     m_nRadius  = (long)(x0*-exp(-0.01*(timeX+T0))*sin(0.0209439*(timeX+T0)+1.570795)) + x0;
//     reSetRect(m_nPenWidth+4);
//     csl.Unlock();
//     return m_DrawRect;
// }

void Circle::reSetRect(int expnd)
{
    m_DrawRect.left   = (long)(m_nCenter.x - m_nRadius - expnd);
    m_DrawRect.top    = (long)(m_nCenter.y - m_nRadius - expnd);
    m_DrawRect.right  = (long)(m_nCenter.x + m_nRadius + expnd);
    m_DrawRect.bottom = (long)(m_nCenter.y + m_nRadius + expnd);
}

#ifdef _DEBUG

CString Circle::showMe() const
{
    CString str;
    
    str.Format("中心點(%d, %d), 顏色(%d, %d, %d), 半徑 = %d, 百分比 = %d%% 圖形範圍 = %d, %d", \
        m_nCenter.x, m_nCenter.y, GetRValue(m_Color), GetGValue(m_Color), GetBValue(m_Color), m_nRadius, m_Percent, m_DrawRect.right - m_DrawRect.left, m_DrawRect.bottom - m_DrawRect.top);

    return str;
}

#endif