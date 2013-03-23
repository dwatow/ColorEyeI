#include "stdafx.h"
#include "Circle.h"

Circle::Circle(CWnd* cWnd, int r):
m_Percent(r), m_nPenWidth(5), m_pdlgcWnd(cWnd), m_isShowPercentNum(FALSE), m_isShowLabel(FALSE), m_Visible(TRUE)
{
    m_Info1.pCircle = this;
}

BOOL Circle::isVisible() const
{ return m_Visible; }
void Circle::Visible(BOOL _V)
{ m_Visible = _V; }

void Circle::SetCenter(const CPoint& p)
{ SetCenter(p.x, p.y); }
CPoint Circle::GetCenter() const
{ return m_nCenter; }


void Circle::SetPercent(int percent)
{ m_Percent = percent; }
int Circle::GetPercent() const
{ return m_Percent; }
ColorRef Circle::GetArcColor() const
{  return m_arcColor; }
ColorRef Circle::GetStrColor() const
{ return m_strColor; }

void Circle::reDrawWindow()
{ gethWnd()->RedrawWindow(&m_reDeawRect); }

void Circle::SetCenter(const int& x, const int& y)
{
    ASSERT(x >= 0 && y >= 0);
    m_nCenter.x = x;
    m_nCenter.y = y;
	m_Label.BindCircle(GetRadius(), GetCenter());
}

void Circle::SetRadius(const int& r)
{
    ASSERT(r > 0);
    m_nRadius = r;
	m_Label.BindCircle(GetRadius(), GetCenter());
}

void Circle::SetArcColor(const ColorRef clr)
{
	m_arcColor = clr;
	m_Pen.DeleteObject();
	m_Pen.CreatePen(PS_SOLID, m_nPenWidth, m_arcColor.oRGB());//變色
	tracePen = &m_Pen;
}

void Circle::SetStrColor(const ColorRef clr)
{ m_strColor = clr; }

void Circle::Draw(CPaintDC &dc)
{
	if (m_Visible)
	{
		drawCircle(dc);
		if (m_isShowPercentNum)
			drawPercentNum(dc);
		if (m_isShowLabel)
			m_Label.Draw(dc);
	}
}

void Circle::drawCircle(CPaintDC &dc)
{
    //設定畫筆
	CPen* OldPen;
    OldPen = dc.SelectObject(&m_Pen);

	drawPercent(dc);

	CPen* tempPen;
    tempPen = dc.SelectObject(OldPen);

	ASSERT(tracePen == tempPen);
}

void Circle::ShowLabel(BOOL _B)
{ m_isShowLabel = _B; }

void Circle::drawPercent(CPaintDC& dc)
{
    int oX(0), oY(0);

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

    CPoint StartPoint(GetCenter().x, GetCenter().y - m_nRadius);
    CPoint   EndPoint(GetCenter().x, GetCenter().y - m_nRadius);

    EndPoint.x = oX + EndPoint.x;
    EndPoint.y = oY + EndPoint.y;

    dc.Arc(m_DrawCircleRect, StartPoint, EndPoint);
}

void Circle::drawPercentNum(CPaintDC &dc)
{
 	dc.SetTextColor(m_strColor.oRGB());
	CString percent;
	percent.Format("%3d%%", GetPercent());
	TextOut(dc, GetCenter().x - 15, GetCenter().y - (GetRadius()+20) , (LPCSTR)percent, percent.GetLength());  //上
	TextOut(dc, GetCenter().x - 15, GetCenter().y + (GetRadius()+2 ) , (LPCSTR)percent, percent.GetLength());  //下
	TextOut(dc, GetCenter().x - (GetRadius()+40),  GetCenter().y -7 , (LPCSTR)percent, percent.GetLength());  //左
	TextOut(dc, GetCenter().x + (GetRadius()+2) ,  GetCenter().y -7 , (LPCSTR)percent, percent.GetLength());  //右
}

void Circle::readRadius(const int& dyR)
{
	if (m_MaxRadius < dyR)
		m_MaxRadius = dyR;
	m_reDeawRect = r2rect(m_MaxRadius);

	m_nRadius = dyR;
	m_DrawCircleRect = r2rect(m_nRadius);
}

CRect Circle::r2rect(int expnd)
{
	CRect _rect((long)(m_nCenter.x - expnd), (long)(m_nCenter.y - expnd),
		        (long)(m_nCenter.x + expnd), (long)(m_nCenter.y + expnd));

	return _rect;
}

void Circle::SetData(const Bullet& blt)
{
	m_Label.SetData(blt);
}


#ifdef _DEBUG

CString Circle::showMe() const
{
    CString str;
    
    str.Format("中心點(%d, %d), 顏色(%d, %d, %d), 半徑 = %d, 百分比 = %d%% 圖形範圍 = %d, %d", \
        GetCenter().x, GetCenter().y, m_arcColor.R(), m_arcColor.G(), m_arcColor.B(), m_nRadius, m_Percent, m_DrawCircleRect.right - m_DrawCircleRect.left, m_DrawCircleRect.bottom - m_DrawCircleRect.top);

    return str;
}


#endif