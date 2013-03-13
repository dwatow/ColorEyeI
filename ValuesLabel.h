#ifndef VALUESLABEL_H
#define VALUESLABEL_H

#include "Bullet.h"
#include "CColorRef.h"

class ValuesLabel
{
	Bullet m_bltData;

	const int m_cWidth;
	const int m_cHight;
	const ColorRef m_clrNG;
	const CSize m_DisplayArea;

	CPoint  m_pointMsring;
	CPoint  m_pointShow;

	Bullet m_specMax;
	Bullet m_specMin;
	void printx(CPaintDC& , int);
public:
	ValuesLabel();
	void comCircle(const int, const CPoint );
	void SetData(Bullet& );
	void Draw(CPaintDC& );
};

inline ValuesLabel::ValuesLabel(): m_cWidth(88), m_cHight(158),
m_DisplayArea(m_cWidth, m_cHight), m_clrNG(192, 0, 0)
{}

inline void ValuesLabel::comCircle(const int _r, const CPoint _p)
{
	//Msred
    CPoint pointShow(-10 - _r, -20 - _r);
	m_pointShow = _p + pointShow;

	//Msring
	//原則上是右手操作，顯示在左邊，無法的時候就顯示在右邊
	CPoint pointMsring(0, -20 - _r);
    pointMsring.x = ( _p.x < (LONG)(_p.x + 125 + m_cWidth) ) ? 40-_r : -125-_r;
	m_pointMsring = _p + pointMsring;
}

inline void ValuesLabel::SetData(Bullet& _B)
{
	m_bltData = _B;
}

inline void ValuesLabel::Draw(CPaintDC& dc)
{
	//需要點定位，需要顏色，需要資料
    //正在量的數據

//     pCD->DrawText(m_pCA210->OutData(), rect2, DT_LEFT | DT_VCENTER);
	for(int lineNum = 0; lineNum < 10; ++lineNum)
		printx(dc, lineNum);
}

inline void ValuesLabel::printx(CPaintDC& dc, int lineNum)
{
	CPoint pointOrig(m_pointMsring);
	const int wordHight(16);
	CString str;
	str.Format("%s", m_bltData.oStr((ValueKind)lineNum));

// 	if (m_bltData.oFlt( (ValueKind)lineNum ) > m_specMax.oFlt( (ValueKind)lineNum ) || 
// 		m_bltData.oFlt( (ValueKind)lineNum ) < m_specMin.oFlt( (ValueKind)lineNum ))
// 	{
// 		ColorRef tempClr;
// 		tempClr = dc.GetTextColor();
// 		
// 		dc.SetTextColor(m_clrNG.oRGB());
// 		TextOut(dc, pointOrig.x, pointOrig.y + wordHight*lineNum, str, str.GetLength());
// 
// 		dc.SetTextColor(tempClr.oRGB());
// 	}
// 	else
		TextOut(dc, pointOrig.x, pointOrig.y + wordHight*lineNum, str, str.GetLength());
}

#endif