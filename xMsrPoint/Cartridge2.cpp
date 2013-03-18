#include "stdafx.h"
#include "Cartridge2.h"

Cartridge2::Cartridge2():
m_sequenceArea(AA_00), m_sequenceFrom(0),
m_PointPosition(0, 0), m_pBackGorund(0),
m_Description(""), m_bkStatus(BGS_Normal)
{}

Cartridge2::Cartridge2(const Cartridge2& _C):
m_sequenceArea(_C.m_sequenceArea), m_sequenceFrom(_C.m_sequenceFrom),
m_PointPosition(_C.m_PointPosition), m_pBackGorund(_C.m_pBackGorund), 
m_bkStatus(_C.m_bkStatus),
m_Description(_C.m_Description), m_Data(_C.m_Data)
{
}

Cartridge2::Cartridge2(const ColorRef& cy, const CPoint& pn):
m_sequenceArea(AA_00), m_sequenceFrom(0),
m_PointPosition(pn), m_bkStatus(BGS_Normal), 
m_Description("")
{
	m_pBackGorund = new BkNormal();
	const int r = cy.R();
	const int g = cy.G();
	const int b = cy.B();
	m_pBackGorund->GetBkColor().iRGB(r, g, b);
// 	ASSERT(m_pBackGorund->GetBkColor().oRGB() == cy.oRGB());
}

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
	m_pBackGorund   = vCar.m_pBackGorund;
	m_bkStatus      = vCar.m_bkStatus;
    m_Data          = vCar.m_Data;
	m_Description   = vCar.m_Description;
}

CString Cartridge2::showMe() const
{
    CString str;
    str.Format("Sequence: %d, AreaCode: %d, Point(%d, %d), BkColor(%d, %d, %d), BeHaveData(%d), %s\n", \
        m_sequenceFrom, 
        m_sequenceArea, 
        m_PointPosition.x, m_PointPosition.y, 
        m_pBackGorund->GetBkColor().R(), m_pBackGorund->GetBkColor().G(), m_pBackGorund->GetBkColor().B(),
        !m_Data.isEmpty(), 
        m_Data.GetLastTime());
    return str;
}

/*******************************************
 *    Define PointSet Class member function  *
 *******************************************/

void Cartridge2::setSqncFrm(UINT _F)
{
	m_sequenceFrom = _F;
}

UINT Cartridge2::getSqncFrm() const
{
	return m_sequenceFrom;
}

void Cartridge2::setSqncArea(AreaKind _A)
{
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
{ m_pBackGorund->SetBkColor(_C); }
ColorRef Cartridge2::GetBkColor() const
{ ASSERT(m_pBackGorund);
	return m_pBackGorund->GetBkColor(); }

void Cartridge2::SetBkStatus(BackGroundStatus _BGS)
{
	m_bkStatus = _BGS;
	if (m_pBackGorund != 0)
		delete m_pBackGorund;
	switch(_BGS)
	{
	case BGS_CrossTalkWrite:
		m_pBackGorund = new BkCrossTalk();
		break;
	case BGS_Normal:
		m_pBackGorund = new BkNormal();
		break;
	}
}

BackGroundStatus Cartridge2::GetBkStatus() const
{ return m_bkStatus; }

void Cartridge2::SetDescrip(CString str)
{
	m_Description = str;
}

CString Cartridge2::GetDescrip() const
{
	return m_Description;
}