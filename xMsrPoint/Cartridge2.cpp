#include "stdafx.h"
#include "Cartridge2.h"

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

Bullet& Cartridge2::GetBullet()
{    
    return m_Data;
}

Bullet Cartridge2::GetBullet() const
{    
    return m_Data;    
}

void Cartridge2::SetBullet(const Bullet& Pd)    
{
	_Time = CTime::GetCurrentTime();
    m_Data = Pd;
}

CPoint Cartridge2::GetPointPosi() const
{
    return m_PointPosition;
}

void Cartridge2::SetPointPosi(CPoint _P)
{
	m_PointPosition = _P;
}

COLORREF  Cartridge2::GetBkColor() const
{
    return m_BkColor;
}

void      Cartridge2::SetBkColor(COLORREF _C)
{
	m_BkColor = _C;
}

void Cartridge2::SetDescrip(CString str)
{
	m_Description = str;
}

CString Cartridge2::GetDescrip() const
{
	return m_Description;
}