#include "stdafx.h"
#include "ValuesLabel.h"

ValuesLabel::ValuesLabel(): m_cWidth(88), m_cHight(158),
m_DisplayArea(m_cWidth, m_cHight), m_clrNG(192, 0, 0)
{}

void ValuesLabel::BindCircle(const int _r, const CPoint _p)
{
    //Msred
    CPoint pointShow(-10 - _r, -20 - _r);
    m_pointShow = _p + pointShow;
    
    //Msring
    //��h�W�O�k��ާ@�A��ܦb����A�L�k���ɭԴN��ܦb�k��
    CPoint pointMsring(0, -20 - _r);
    pointMsring.x = ( _p.x < (LONG)(_p.x + 125 + m_cWidth) ) ? 40-_r : -125-_r;
    m_pointMsring = _p + pointMsring;
}

void ValuesLabel::SetData(const Bullet& _B)
{
    m_bltData = _B;
}

void ValuesLabel::Draw(CPaintDC& dc)
{
    //�ݭn�I�w��A�ݭn�C��A�ݭn���
    //���b�q���ƾ�
    
    //     pCD->DrawText(m_pCA210->OutData(), rect2, DT_LEFT | DT_VCENTER);
    for(int lineIndex = 0; lineIndex < 10; ++lineIndex)
        printx(dc, lineIndex);
}

void ValuesLabel::printx(CPaintDC& dc, int lineIndex)
{
    CPoint pointOrig(m_pointMsring);
    const int wordHight(16);
    CString str;

    switch (lineIndex)
    {
    case 0:    str.Format("Lv: %s", m_bltData.oStr((ValueKind)lineIndex)); break;
    case 1:    str.Format(" x: %s", m_bltData.oStr((ValueKind)lineIndex)); break;
    case 2:    str.Format(" y: %s", m_bltData.oStr((ValueKind)lineIndex)); break;
    case 3:    str.Format(" T: %s", m_bltData.oStr((ValueKind)lineIndex)); break;
    case 4:    str.Format("uv: %s", m_bltData.oStr((ValueKind)lineIndex)); break;
    case 5:    str.Format("u': %s", m_bltData.oStr((ValueKind)lineIndex)); break;
    case 6:    str.Format("v': %s", m_bltData.oStr((ValueKind)lineIndex)); break;
    case 7:    str.Format(" X: %s", m_bltData.oStr((ValueKind)lineIndex)); break;
    case 8:    str.Format(" Y: %s", m_bltData.oStr((ValueKind)lineIndex)); break;
    case 9:    str.Format(" Z: %s", m_bltData.oStr((ValueKind)lineIndex)); break;
    }

    
    //     if (m_bltData.oFlt( (ValueKind)lineIndex ) > m_specMax.oFlt( (ValueKind)lineIndex ) || 
    //         m_bltData.oFlt( (ValueKind)lineIndex ) < m_specMin.oFlt( (ValueKind)lineIndex ))
    //     {
    //         ColorRef tempClr;
    //         tempClr = dc.GetTextColor();
    //         
    //         dc.SetTextColor(m_clrNG.oRGB());
    //         TextOut(dc, pointOrig.x, pointOrig.y + wordHight*lineIndex, str, str.GetLength());
    // 
    //         dc.SetTextColor(tempClr.oRGB());
    //     }
    //     else
    TextOut(dc, pointOrig.x, pointOrig.y + wordHight*lineIndex, str, str.GetLength());
}