#include "StdAfx.h"
#include "ValuesLabel.h"

ValuesLabel::ValuesLabel(): m_cWidth(88), m_cHight(158),
m_DisplayArea(m_cWidth, m_cHight), m_clrNG(192, 0, 0)
{}

void ValuesLabel::comCircle(const int _r, const CPoint _p)
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

void ValuesLabel::SetData(Bullet& _B)
{
    m_bltData = _B;
}

void ValuesLabel::Draw(CPaintDC& dc)
{
    //需要點定位，需要顏色，需要資料
    //正在量的數據
    
    //     pCD->DrawText(m_pCA210->OutData(), rect2, DT_LEFT | DT_VCENTER);
    for(int lineNum = 0; lineNum < 10; ++lineNum)
        printx(dc, lineNum);
}

void ValuesLabel::printx(CPaintDC& dc, int lineNum)
{
    CPoint pointOrig(m_pointMsring);
    const int wordHight(16);
    CString str;

    switch (lineNum)
    {
    case 0:    str.Format("Lv: %s", m_bltData.oStr((ValueKind)lineNum)); break;
    case 1:    str.Format(" x: %s", m_bltData.oStr((ValueKind)lineNum)); break;
    case 2:    str.Format(" y: %s", m_bltData.oStr((ValueKind)lineNum)); break;
    case 3:    str.Format(" T: %s", m_bltData.oStr((ValueKind)lineNum)); break;
    case 4:    str.Format("uv: %s", m_bltData.oStr((ValueKind)lineNum)); break;
    case 5:    str.Format("u': %s", m_bltData.oStr((ValueKind)lineNum)); break;
    case 6:    str.Format("v': %s", m_bltData.oStr((ValueKind)lineNum)); break;
    case 7:    str.Format(" X: %s", m_bltData.oStr((ValueKind)lineNum)); break;
    case 8:    str.Format(" Y: %s", m_bltData.oStr((ValueKind)lineNum)); break;
    case 9:    str.Format(" Z: %s", m_bltData.oStr((ValueKind)lineNum)); break;
    }

    
    //     if (m_bltData.oFlt( (ValueKind)lineNum ) > m_specMax.oFlt( (ValueKind)lineNum ) || 
    //         m_bltData.oFlt( (ValueKind)lineNum ) < m_specMin.oFlt( (ValueKind)lineNum ))
    //     {
    //         ColorRef tempClr;
    //         tempClr = dc.GetTextColor();
    //         
    //         dc.SetTextColor(m_clrNG.oRGB());
    //         TextOut(dc, pointOrig.x, pointOrig.y + wordHight*lineNum, str, str.GetLength());
    // 
    //         dc.SetTextColor(tempClr.oRGB());
    //     }
    //     else
    TextOut(dc, pointOrig.x, pointOrig.y + wordHight*lineNum, str, str.GetLength());
}