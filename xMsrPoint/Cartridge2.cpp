#include "stdafx.h"
#include "Cartridge2.h"

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

void Cartridge2::SetBkColor(COLORREF _C)
{
	ASSERT(GetRValue(_C) >= 0);  ASSERT(GetRValue(_C) <= 255);
	ASSERT(GetGValue(_C) >= 0);  ASSERT(GetGValue(_C) <= 255);
	ASSERT(GetBValue(_C) >= 0);  ASSERT(GetBValue(_C) <= 255);

	m_BkColor = _C;
}

COLORREF Cartridge2::GetBkColor() const
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