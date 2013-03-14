#include "stdafx.h"
#include "Cartridge2.h"

Cartridge2::Cartridge2():
m_sequenceArea(AA_00), m_sequenceFrom(0),
m_PointPosition(0, 0), m_BkColor(0, 0, 0),
m_Description(""), m_bkStatus(BGS_Normal),
m_centerRect(0, 0, 0, 0), m_bColor(0, 0, 0)
{}

Cartridge2::Cartridge2(const Cartridge2& _C):
m_sequenceArea(_C.m_sequenceArea), m_sequenceFrom(_C.m_sequenceFrom),
m_PointPosition(_C.m_PointPosition), m_BkColor(_C.m_BkColor), m_bkStatus(_C.m_bkStatus),
m_Description(_C.m_Description), m_Data(_C.m_Data), 
m_centerRect(_C.m_centerRect), m_bColor(_C.m_bColor)
{}

Cartridge2::Cartridge2(const ColorRef& cy, const CPoint& pn):
m_sequenceArea(AA_00), m_sequenceFrom(0),
m_PointPosition(pn), m_BkColor(cy), 
m_Description(""), m_bkStatus(BGS_Normal), 
m_centerRect(0, 0, 0, 0), m_bColor(0, 0, 0)
{}

Cartridge2::~Cartridge2(){}

BOOL Cartridge2::operator==(const Cartridge2& vCar2)
{
    return ( (GetPointPosi() == vCar2.GetPointPosi()) && 
		   (  GetBkColor()   == vCar2.GetBkColor()  )
		   ) ? TRUE : FALSE;
};

void Cartridge2::operator= (const Cartridge2& vCar)
{
    m_sequenceFrom  = vCar.m_sequenceFrom;
    m_sequenceArea  = vCar.m_sequenceArea;
    m_PointPosition = vCar.m_PointPosition;
	m_BkColor       = vCar.m_BkColor;
	m_bkStatus      = vCar.m_bkStatus;
    m_Data          = vCar.m_Data;
	m_Description   = vCar.m_Description;
	m_bColor        = vCar.m_bColor;
	m_centerRect    = vCar.m_centerRect;
}

CString Cartridge2::showMe() const
{
    CString str;
    str.Format("Sequence: %d, AreaCode: %d, Point(%d, %d), BkColor(%d, %d, %d), BeHaveData(%d), %s\n", \
        m_sequenceFrom, 
        m_sequenceArea, 
        m_PointPosition.x, m_PointPosition.y, 
        m_BkColor.R(), m_BkColor.G(), m_BkColor.B(),
        !m_Data.isEmpty(), 
        m_Data.GetLastTime());
    return str;
}

void Cartridge2::setCrsTlkRect(CRect& _rect, ColorRef& clr)
{
	//在DNA轉RNA時使用
	// 	m_centerRect.top    = 10;
	// 	m_centerRect.bottom = 200;
	// 	m_centerRect.left   = 10;
	// 	m_centerRect.right  = 200;
	// 	m_centerRectBrush.CreateSolidBrush(RGB(0, 0, 255));
	m_centerRect = _rect;
	m_bColor = clr;
}

void Cartridge2::DrawCrsTlkRect(CPaintDC& dc)
{
	//在CPatternDlg使用
	// Cross Talk 的背景色
	CBrush _brush(m_bColor.oRGB());
    dc.FillRect(m_centerRect, &_brush);
}

/*******************************************
 *    Define PointSet Class member function  *
 *******************************************/

void Cartridge2::setSqncFrm(UINT _F)
{
//	ASSERT(_F > 0);
	m_sequenceFrom = _F;
}

UINT Cartridge2::getSqncFrm() const
{
	return m_sequenceFrom;
}

void Cartridge2::setSqncArea(AreaKind _A)
{
//	ASSERT(_A > 0);
	m_sequenceArea = _A;
}

AreaKind Cartridge2::getSqncArea() const
{
	return m_sequenceArea;
}

void Cartridge2::SetBullet(const Bullet& Pd)    
{
    m_Data = Pd;
}

Bullet Cartridge2::GetBullet() const
{
    return m_Data;    
}

void Cartridge2::SetPointPosi(CPoint _P)
{
	ASSERT(_P.x>=0);
	ASSERT(_P.y>=0);
	m_PointPosition = _P;
}

CPoint Cartridge2::GetPointPosi() const
{
    return m_PointPosition;
}

void Cartridge2::SetBkColor(ColorRef _C)
{
	m_BkColor = _C;
}

ColorRef Cartridge2::GetBkColor() const
{
    return m_BkColor;
}

void Cartridge2::SetDescrip(CString str)
{
//	ASSERT(str.Empty());
	m_Description = str;
}

CString Cartridge2::GetDescrip() const
{
	return m_Description;
}