#include "stdafx.h"
#include "Circle.h"
#include <cmath>

Circle::Circle(CWnd* cWnd, int r):
m_Percent(r), m_nPenWidth(5), m_pdlgcWnd(cWnd), m_isShowPercentNum(FALSE), m_isShowLabel(FALSE)
{
    m_Info1.pCircle = this;
}

void Circle::SetCenter(CPoint p)
{
    SetCenter(p.x, p.y);
	//��b�o�A�N�O�u�I�b���A���ҴN�b���v
	m_Label.comCircle(m_nRadius, m_nCenter);
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

void Circle::SetArcColor(const ColorRef clr)
{
	m_arcColor = clr;
	m_Pen.DeleteObject();
	m_Pen.CreatePen(PS_SOLID, m_nPenWidth, m_arcColor.oRGB());//�ܦ�
	tracePen = &m_Pen;
}

void Circle::SetStrColor(const ColorRef clr)
{
	m_strColor = clr;
}

void Circle::Draw(CPaintDC &dc)
{
	drawCircle(dc);
	if (m_isShowPercentNum)
		drawPercentNum(dc);
	if (m_isShowLabel)
		m_Label.Draw(dc);
}

void Circle::drawCircle(CPaintDC &dc)
{
    //�]�w�e��
    CPen* OldPen;

    CPoint StartPoint(m_nCenter.x, m_nCenter.y - m_nRadius);
    CPoint   EndPoint(m_nCenter.x, m_nCenter.y - m_nRadius);
    
    if(m_Percent > 0 && m_Percent < 100)  
        drawPercent();

    //expandRect(m_nRadius);
    OldPen = dc.SelectObject(&m_Pen);
    dc.Arc(m_DrawCircleRect, StartPoint, EndPoint);

	CPen* tempPen;
    tempPen = dc.SelectObject(OldPen);
	ASSERT(tracePen == tempPen);
}

void Circle::ShowLabel(BOOL _B)
{
	m_isShowLabel = _B;
}

void Circle::drawPercentNum(CPaintDC &dc)
{
 	dc.SetTextColor(m_strColor.oRGB());
	CString percent;
	percent.Format("%3d%% \0", GetPercent());
	TextOut(dc, GetCenter().x - 15, GetCenter().y - (GetRadius()+20) , (LPCSTR)percent, percent.GetLength());  //�W
	TextOut(dc, GetCenter().x - 15, GetCenter().y + (GetRadius()+2 ) , (LPCSTR)percent, percent.GetLength());  //�U
	TextOut(dc, GetCenter().x - (GetRadius()+40),  GetCenter().y -7 , (LPCSTR)percent, percent.GetLength());  //��
	TextOut(dc, GetCenter().x + (GetRadius()+2) ,  GetCenter().y -7 , (LPCSTR)percent, percent.GetLength());  //�k
}

CirclePercent Circle::SetPercent(int percent)
{
    //�~�� ����100%
    //���� �W�L100%
    if (percent < 0)
    {
        m_Percent = 0;
        return CP_NULL;//�ŪM��
    }
    else if (percent >= 0 && percent <100)
    {
        m_Percent = percent;
        return CP_X;//�i�椤
    }
    else if (percent >= 100)
    {
        m_Percent = 100;
        return CP_FULL;//���X�Ӱ�
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

ColorRef Circle::GetArcColor() const
{
    return m_arcColor;
}

ColorRef Circle::GetStrColor() const
{
	return m_strColor;
}

void Circle::drawPercent()
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
	{
		
		BOOL t_isShowLabel(m_isShowLabel);
		m_isShowLabel = FALSE;
		m_isShowPercentNum = FALSE;
		
		CSingleLock csl(&m_cs);
		csl.Lock();
// 		int r = GetRadius();
		elasticAnimation((LPVOID)&m_Info1);
// 		SetRadius(r);
		csl.Unlock();
		
		m_isShowPercentNum = TRUE;
		m_isShowLabel = t_isShowLabel;
	}
	else
		ASSERT(0);
};

void Circle::readRadius(int& dyR)
{
	if (m_MaxRadius < dyR)
		m_MaxRadius = dyR;
	m_reDeawRect = r2rect(m_MaxRadius);

	m_nRadius = dyR;
	m_DrawCircleRect = r2rect(m_nRadius);
}

void Circle::elasticAnimation(LPVOID LParam)
{
    myThreadInfo *pInfo1 = (myThreadInfo *)LParam;
    Circle *_pCircle = (Circle*)(pInfo1->pCircle);

    ASSERT(_pCircle);
    ASSERT(_pCircle->GetRadius() > 0);

    const int r = _pCircle->GetRadius();
    _pCircle->gethWnd()->Invalidate();
    _pCircle->gethWnd()->UpdateWindow();

	int dynamicR;
    for (int i = 1; i < 17; ++i)
    {
		dynamicR = _pCircle->DampingVibration(i, r);
		_pCircle->readRadius(dynamicR);
		_pCircle->reDrawWindow();
        Sleep(16); //�ո`�ʵe���e�ɬO�_�ݱo��
    }
}
 
void Circle::reDrawWindow()
{
	gethWnd()->RedrawWindow(&m_reDeawRect);
}

int Circle::DampingVibration(int k, int x0) 
{
	//�_�ʪ�����ơA���D�ק�_�ʪ����p�]�����j�p�Ϊ̬O�_���ɶ��^
	//�_�h���ܡA���έק�
    //max = 375
    //min = 0
    //375-15/15
    ASSERT(k>=0);
    ASSERT(x0>=0);
	const int trmpR = (long)((x0*-exp(-0.01*(24*k+15))*sin(0.0209439*(24*k+15)+1.570795)) + x0);
	return trmpR;
}

CRect Circle::r2rect(int expnd)
{
	CRect _rect((long)(m_nCenter.x - expnd), (long)(m_nCenter.y - expnd),
		(long)(m_nCenter.x + expnd), (long)(m_nCenter.y + expnd));

	return _rect;
}

void Circle::SetupLabel(Bullet& blt)
{
	m_Label.SetData(blt);
	//��b�o�A�N�O�u�I���b���A���ҴN�b���v
	m_Label.comCircle(m_nRadius, m_nCenter);
}

#ifdef _DEBUG

CString Circle::showMe() const
{
    CString str;
    
    str.Format("�����I(%d, %d), �C��(%d, %d, %d), �b�| = %d, �ʤ��� = %d%% �ϧνd�� = %d, %d", \
        m_nCenter.x, m_nCenter.y, m_arcColor.R(), m_arcColor.G(), m_arcColor.B(), m_nRadius, m_Percent, m_DrawCircleRect.right - m_DrawCircleRect.left, m_DrawCircleRect.bottom - m_DrawCircleRect.top);

    return str;
}

#endif