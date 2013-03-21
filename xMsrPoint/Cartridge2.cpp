#include "stdafx.h"
#include "Cartridge2.h"

Cartridge2::Cartridge2():
m_sequenceArea(AA_00), m_sequenceFrom(0),
m_PointPosition(0, 0), m_pBackGorund(0),
m_Description(""), m_bkStatus(BGS_Normal)
{
	SetBkStatus(m_bkStatus);
}

Cartridge2::Cartridge2(const Cartridge2& _C):
m_sequenceArea(_C.m_sequenceArea), m_sequenceFrom(_C.m_sequenceFrom),
m_PointPosition(_C.m_PointPosition), m_pBackGorund(_C.m_pBackGorund), //m_pBackGorund(0), 
m_bkStatus(_C.m_bkStatus), 
m_Description(_C.m_Description), m_Data(_C.m_Data)
{
// 	SetBkStatus(_C.GetBkStatus());
// 	*(m_pBackGorund) = *(_C.m_pBackGorund);
}

Cartridge2::~Cartridge2()
{ 
	if (m_pBackGorund->cnt == 0)
		delete m_pBackGorund;
}

BOOL Cartridge2::operator==(const Cartridge2& vCar2)
{
    return ( (GetPointPosi() == vCar2.GetPointPosi()) && 
		   (  GetBkColor()   == vCar2.GetBkColor()  ) &&
		   (  GetBkStatus()  == vCar2.GetBkStatus() )
		   ) ? TRUE : FALSE;
};

void Cartridge2::operator= (const Cartridge2& vCar)
{
// 	SetBkStatus(vCar.m_bkStatus);
// 	*(m_pBackGorund) = *(vCar.m_pBackGorund);
	m_pBackGorund   = vCar.m_pBackGorund;
    m_sequenceFrom  = vCar.m_sequenceFrom;
    m_sequenceArea  = vCar.m_sequenceArea;
    m_PointPosition = vCar.m_PointPosition;
	m_bkStatus      = vCar.m_bkStatus;
    m_Data          = vCar.m_Data;
	m_Description   = vCar.m_Description;
}

CString Cartridge2::showMe() const
{
    CString str;
    str.Format("Sequence: %d, AreaCode: %d, Point(%d, %d), BkColor(%d, %d, %d), BkAdd: 0x%X, BkCnt: %d, BkStatus: %s, BeHaveData(%d), %s\n", \
        m_sequenceFrom, 
        m_sequenceArea, 
        m_PointPosition.x, m_PointPosition.y, 

        m_pBackGorund->_GetBkColor().R(), 
		m_pBackGorund->_GetBkColor().G(), 
		m_pBackGorund->_GetBkColor().B(),

		m_pBackGorund,
		*(m_pBackGorund->cnt),

		GetStrBkStatus(), 
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
{
	ASSERT(m_pBackGorund);
	m_pBackGorund->_SetBkColor(_C); 
}

ColorRef Cartridge2::GetBkColor() const
{ 
	ASSERT(m_pBackGorund);
	return m_pBackGorund->_GetBkColor(); 
}

void Cartridge2::SetBkStatus(BackGroundStatus _BGS)
{
	m_bkStatus = _BGS;
	if (m_pBackGorund != 0)
		delete m_pBackGorund;
	switch(_BGS)
	{
	case BGS_NitsPos:
		m_pBackGorund = new BkNits(ND_Pos);
		break;
	case BGS_NitsNeg:
		m_pBackGorund = new BkNits(ND_Neg);
		break;
	case BGS_CrossTalkDark:
		m_pBackGorund = new BkCrossTalk(RGB(0, 0, 0));
		break;
	case BGS_CrossTalkWrite:
		m_pBackGorund = new BkCrossTalk(RGB(255, 255, 255));
		break;
	case BGS_Normal:
	default:
		m_pBackGorund = new BkMaker();
	}
}

BackGroundStatus Cartridge2::GetBkStatus() const
{ return m_bkStatus; }

CString Cartridge2::GetStrBkStatus() const
{
	//{BGS_Normal = 0, BGS_NitsPos, BGS_NitsNeg, BGS_CrossTalkWrite, BGS_CrossTalkDark };
	CString str;
	switch(m_bkStatus)
	{
	case BGS_Normal:
		str.Format("單色背景");
		break;
	case BGS_NitsPos:
		str.Format("追縱Nits略高背景");
		break;
	case BGS_NitsNeg:
		str.Format("追縱Nits略低背景");
		break;
	case BGS_CrossTalkWrite:
		str.Format("Cross Talk+白矩形背景");
		break;
	case BGS_CrossTalkDark:
		str.Format("Cross Talk+黑矩形背景");
		break;
	default:
		str.Format("不該出現的無定義背景");
	}
	return str; 
}

void Cartridge2::SetDescrip(CString str)
{
	m_Description = str;
}

CString Cartridge2::GetDescrip() const
{
	return m_Description;
}