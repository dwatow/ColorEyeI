<<<<<<< HEAD
#include "stdafx.h"
#include "Circle.h"
#include <cmath>

Circle::Circle():m_Percent(0), m_nPenWidth(5)
{
}

BOOL Circle::SetCenter(CPoint p)
{
	if (p.x >= 0 && p.y >= 0)
	{
		SetCenter(p.x, p.y);
		return TRUE;
	} 
	else
		return FALSE;
}

BOOL Circle::SetCenter(int x, int y)
{
	if (x >= 0 && y >= 0)
	{
		m_nCenter.x = x;
		m_nCenter.y = y;
		return TRUE;
	} 
	else
		return FALSE;
}

BOOL Circle::SetRadius(UINT r)
{
	if (r > 0)
	{
		m_nRadius = r;
		return TRUE;
	} 
	else
		return FALSE;
}

UINT Circle::GetRadius() const
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
	{
		DrawArc(EndPoint);
		DrawClr(m_Color);
	}
	reSetRect();
	OldPen = dc.SelectObject(&m_Pen);
	dc.Arc(m_DrawRect, StartPoint, EndPoint);
	dc.SelectObject(OldPen);
}

UINT Circle::SetPercent(UINT percent)
{
	//繼續 未滿100%
	//停止 超過100%
	if (percent < 0)
	{
		m_Percent = 0;
		return 0;//空杯啦
	}
	else if (percent >= 0 && percent <100)
	{
	    m_Percent = percent;
		return 1;//進行中
	}
	else if (percent >= 100)
	{
		m_Percent = 100;
		return 2;//滿出來啦
	}
	else
		return 3;
}
UINT Circle::GetPercent() const
{
	return m_Percent;
}

BOOL Circle::SetColor(COLORREF clr)
{
	int O = 0x000000FF & (clr >>24);
	int B = GetBValue(clr);
    int G = GetGValue(clr);
    int R = GetRValue(clr);

	if(O == 0 && R >= 0 && R <256
		      && G >= 0 && G <256 
			  && B >= 0 && B <256 )
	{
		m_Color = clr;
		m_Pen.DeleteObject();
		m_Pen.CreatePen(PS_SOLID, m_nPenWidth, m_Color);//變色
		return TRUE;
	}	
	else 
		return FALSE;
}

COLORREF Circle::GetColor() const
{
	return m_Color;
}

BOOL Circle::SetBkColor(COLORREF clr)
{
	int O = 0x000000FF & (clr >>24);
	int B = GetBValue(clr);
    int G = GetGValue(clr);
    int R = GetRValue(clr);
	
	if(O == 0 && R >= 0 && R <256
		      && G >= 0 && G <256 
			  && B >= 0 && B <256 )
	{
		m_BkColor = clr;
		return TRUE;
	}	
	else 
		return FALSE;
}

COLORREF Circle::GetBkColor() const
{
	return m_BkColor;
}

CRect Circle::VbrFun(UINT k, UINT x0)
{
	//max = 375
	//min = 0
	//375-15/15
	int T0 = 15;
	CSingleLock csl(&m_cs);
	csl.Lock();
	double timeX = 24*k;
	m_nRadius  = (long)(x0*-exp(-0.01*(timeX+T0))*sin(0.0209439*(timeX+T0)+1.570795)) + x0;
	reSetRect(m_nPenWidth+4);
	csl.Unlock();
	return m_DrawRect;
}

void Circle::reSetRect(int range)
{
	m_DrawRect.left   = (long)(m_nCenter.x - m_nRadius - range);
	m_DrawRect.top    = (long)(m_nCenter.y - m_nRadius - range);
	m_DrawRect.right  = (long)(m_nCenter.x + m_nRadius + range);
	m_DrawRect.bottom = (long)(m_nCenter.y + m_nRadius + range);
}

CString Circle::GetSetupValue() const
{
	CString str;
	
	str.Format("中心點(%d, %d), 顏色(%d, %d, %d), 半徑 = %d, 百分比 = %d%% 圖形範圍 = %d, %d", \
		m_nCenter.x, m_nCenter.y, GetRValue(m_Color), GetGValue(m_Color), GetBValue(m_Color), m_nRadius, m_Percent, m_DrawRect.right - m_DrawRect.left, m_DrawRect.bottom - m_DrawRect.top);

	return str;
=======
#include "stdafx.h"
#include "Circle.h"
#include <cmath>

Circle::Circle():m_Percent(0), m_nPenWidth(5)
{
}

BOOL Circle::SetCenter(CPoint p)
{
	if (p.x >= 0 && p.y >= 0)
	{
		SetCenter(p.x, p.y);
		return TRUE;
	} 
	else
		return FALSE;
}

BOOL Circle::SetCenter(int x, int y)
{
	if (x >= 0 && y >= 0)
	{
		m_nCenter.x = x;
		m_nCenter.y = y;
		return TRUE;
	} 
	else
		return FALSE;
}

BOOL Circle::SetRadius(UINT r)
{
	if (r > 0)
	{
		m_nRadius = r;
		return TRUE;
	} 
	else
		return FALSE;
}

UINT Circle::GetRadius() const
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
	{
		DrawArc(EndPoint);
		DrawClr(m_Color);
	}
	reSetRect();
	OldPen = dc.SelectObject(&m_Pen);
	dc.Arc(m_DrawRect, StartPoint, EndPoint);
	dc.SelectObject(OldPen);
}

UINT Circle::SetPercent(UINT percent)
{
	//繼續 未滿100%
	//停止 超過100%
	if (percent < 0)
	{
		m_Percent = 0;
		return 0;//空杯啦
	}
	else if (percent >= 0 && percent <100)
	{
	    m_Percent = percent;
		return 1;//進行中
	}
	else if (percent >= 100)
	{
		m_Percent = 100;
		return 2;//滿出來啦
	}
	else
		return 3;
}
UINT Circle::GetPercent() const
{
	return m_Percent;
}

BOOL Circle::SetColor(COLORREF clr)
{
	int O = 0x000000FF & (clr >>24);
	int B = GetBValue(clr);
    int G = GetGValue(clr);
    int R = GetRValue(clr);

	if(O == 0 && R >= 0 && R <256
		      && G >= 0 && G <256 
			  && B >= 0 && B <256 )
	{
		m_Color = clr;
		m_Pen.DeleteObject();
		m_Pen.CreatePen(PS_SOLID, m_nPenWidth, m_Color);//變色
		return TRUE;
	}	
	else 
		return FALSE;
}

COLORREF Circle::GetColor() const
{
	return m_Color;
}

BOOL Circle::SetBkColor(COLORREF clr)
{
	int O = 0x000000FF & (clr >>24);
	int B = GetBValue(clr);
    int G = GetGValue(clr);
    int R = GetRValue(clr);
	
	if(O == 0 && R >= 0 && R <256
		      && G >= 0 && G <256 
			  && B >= 0 && B <256 )
	{
		m_BkColor = clr;
		return TRUE;
	}	
	else 
		return FALSE;
}

COLORREF Circle::GetBkColor() const
{
	return m_BkColor;
}

CRect Circle::VbrFun(UINT k, UINT x0)
{
	//max = 375
	//min = 0
	//375-15/15
	int T0 = 15;
	CSingleLock csl(&m_cs);
	csl.Lock();
	double timeX = 24*k;
	m_nRadius  = (long)(x0*-exp(-0.01*(timeX+T0))*sin(0.0209439*(timeX+T0)+1.570795)) + x0;
	reSetRect(m_nPenWidth+4);
	csl.Unlock();
	return m_DrawRect;
}

void Circle::reSetRect(int range)
{
	m_DrawRect.left   = (long)(m_nCenter.x - m_nRadius - range);
	m_DrawRect.top    = (long)(m_nCenter.y - m_nRadius - range);
	m_DrawRect.right  = (long)(m_nCenter.x + m_nRadius + range);
	m_DrawRect.bottom = (long)(m_nCenter.y + m_nRadius + range);
}

CString Circle::GetSetupValue() const
{
	CString str;
	
	str.Format("中心點(%d, %d), 顏色(%d, %d, %d), 半徑 = %d, 百分比 = %d%% 圖形範圍 = %d, %d", \
		m_nCenter.x, m_nCenter.y, GetRValue(m_Color), GetGValue(m_Color), GetBValue(m_Color), m_nRadius, m_Percent, m_DrawRect.right - m_DrawRect.left, m_DrawRect.bottom - m_DrawRect.top);

	return str;
>>>>>>> b5425c75ef070be7770a30afe5b503213bd2584b
}