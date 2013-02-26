#include "stdafx.h"
#include "Circle.h"
#include <cmath>

Circle::Circle(CWnd* cWnd, int r):
m_Percent(r), m_nPenWidth(5), m_pdlgcWnd(cWnd)
{
    m_Info1.pCircle = this;
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

    //expandRect(m_nRadius);
    dc.Arc(m_DrawRect, StartPoint, EndPoint);
    OldPen = dc.SelectObject(&m_Pen);

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

void Circle::SetColor(const ColorRef clr)
{
    m_Color = clr;
    m_Pen.DeleteObject();
    m_Pen.CreatePen(PS_SOLID, m_nPenWidth, m_Color.oRGB());//變色
}

ColorRef Circle::GetColor() const
{
    return m_Color;
}

void Circle::Draw()
{
    int oX, oY;
    
    oX = (int)(m_nRadius / cos(0.0628318 * m_Percent));
    oY = (int)(m_nRadius / sin(0.0628318 * m_Percent));
    if (m_Percent > 0 && m_Percent <= 25)
    {
        oX = (int)(m_nRadius / cos(0.0628318 * (m_Percent+50)));
        oY = (int)(m_nRadius / sin(0.0628318 * (m_Percent+50)));
    } 
    else if (m_Percent > 25 && m_Percent <= 50)
    {
        oX = (int)(m_nRadius / cos(0.0628318 * m_Percent));
        oY = (int)(m_nRadius / sin(0.0628318 * m_Percent));
    } 
    else if (m_Percent > 50 && m_Percent <= 75)
    {
        oX = (int)(m_nRadius / cos(0.0628318 * (m_Percent-50)));
        oY = (int)(m_nRadius / sin(0.0628318 * (m_Percent-50)));
    } 
    else if (m_Percent > 75 && m_Percent < 100)
    {
        oX = (int)(m_nRadius / cos(0.0628318 * m_Percent));
        oY = (int)(m_nRadius / sin(0.0628318 * m_Percent));
    }
    m_nCenter.x = oX + m_nCenter.x;
    m_nCenter.y = oY + m_nCenter.y;
}

void Circle::Animation()
{
	if (m_pdlgcWnd != NULL)
		elasticAnimation((LPVOID)&m_Info1);
};

void Circle::elasticAnimation(LPVOID LParam)
{
    myThreadInfo *pInfo1 = (myThreadInfo *)LParam;
    Circle *_pCircle = (Circle*)(pInfo1->pCircle);

    ASSERT(_pCircle);
    ASSERT(_pCircle->GetRadius() > 0);

    const int r = _pCircle->GetRadius();
    _pCircle->gethWnd()->Invalidate();
    _pCircle->gethWnd()->UpdateWindow();

    CRect _rect;
    for (UINT i = 0; i < 16; ++i)
    {
        _rect = _pCircle->DampingVibration(i, r);
		_pCircle->gethWnd()->RedrawWindow(&_rect);
//         _pCircle->gethWnd()->InvalidateRect(&_rect, TRUE);
//         _pCircle->gethWnd()->UpdateWindow();
        Sleep(15); //調節動畫重畫時是否看得到
    }
}

CRect Circle::DampingVibration(int k, int x0)
{
    //max = 375
    //min = 0
    //375-15/15
    ASSERT(k>=0);
    ASSERT(x0>=0);
    int T0 = 15;
    CSingleLock csl(&m_cs);
    csl.Lock();
    double timeX = 24*k;
	int trmpR = (long)(x0*-exp(-0.01*(timeX+T0))*sin(0.0209439*(timeX+T0)+1.570795)) + x0;
    csl.Unlock();
    return expandRect(trmpR);//(m_nPenWidth+4);
}

CRect Circle::expandRect(int expnd)
{
    m_DrawRect.left   = (long)(m_nCenter.x - expnd);
    m_DrawRect.top    = (long)(m_nCenter.y - expnd);
    m_DrawRect.right  = (long)(m_nCenter.x + expnd);
    m_DrawRect.bottom = (long)(m_nCenter.y + expnd);

	return m_DrawRect;
}

#ifdef _DEBUG

CString Circle::showMe() const
{
    CString str;
    
    str.Format("中心點(%d, %d), 顏色(%d, %d, %d), 半徑 = %d, 百分比 = %d%% 圖形範圍 = %d, %d", \
        m_nCenter.x, m_nCenter.y, m_Color.R(), m_Color.G(), m_Color.B(), m_nRadius, m_Percent, m_DrawRect.right - m_DrawRect.left, m_DrawRect.bottom - m_DrawRect.top);

    return str;
}

#endif