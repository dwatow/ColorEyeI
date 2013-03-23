#include"stdafx.h"
#include"Bullet.h"
/******************************************
 *    Define Bullet Class member function *
 ******************************************/
#include <iterator>

Bullet::Bullet():
m_vfValues(VluK_Total, 0.0),
m_LastModifyTime(CTime::GetCurrentTime())
{}

Bullet::Bullet(const Bullet& xp):
m_vfValues(xp.m_vfValues),
m_LastModifyTime(xp.m_LastModifyTime)
{}

Bullet::~Bullet()
{
    m_vfValues.clear();
}

void Bullet::i(ValueKind _VK, float _F)
{
//    ASSERT( _F>=0 && _F<=0.8 ); 
    m_vfValues[_VK] = _F;
    m_LastModifyTime = CTime::GetCurrentTime(); 
}

void Bullet::i(ValueKind _VK, CString _S)
{
    ASSERT( str2flt(_S)>=0 && str2flt(_S)<=0.8 ); 
    m_vfValues[_VK] = str2flt(_S);
    m_LastModifyTime = CTime::GetCurrentTime(); 
}

float Bullet::oFlt(ValueKind _VK) const
{
    return m_vfValues[_VK];
}

CString Bullet::oStr(ValueKind _VK) const
{
    return flt2str(m_vfValues[_VK]);
}
//////////////////////////////////////////////////////////////////////////
float Bullet::str2flt(CString _Str) const
{
    return atof(_Str.GetBuffer(0));
}

CString Bullet::flt2str(float _F) const
{
    CString str;
    str.Format("%f", _F);
    return str;
}
//////////////////////////////////////////////////////////////////////////

void Bullet::operator= (const Bullet& xp)
{
    m_vfValues = xp.m_vfValues;
    m_LastModifyTime = xp.m_LastModifyTime;
}

BOOL Bullet::isEmpty() const
{
	for (std::vector<float>::const_iterator vitor = m_vfValues.begin(); vitor != m_vfValues.end(); ++vitor)
		if ( *vitor == 0.0 ) 
			return TRUE;

    return FALSE ;
}

CString Bullet::GetLastTime() const
{
    CString str;
    str.Format("%d/%d/%d, %d:%d:%d", 
        m_LastModifyTime.GetYear(), m_LastModifyTime.GetMonth(), m_LastModifyTime.GetDay(), 
        m_LastModifyTime.GetHour(), m_LastModifyTime.GetMinute(), m_LastModifyTime.GetSecond());

    return str;
}

CString Bullet::show() const
{
    return " Lv =" + flt2str(m_vfValues[VluK_Lv]) + "\n" 
		+ "  x =" + flt2str(m_vfValues[VluK_Sx]) + "\n" 
		+ "  y =" + flt2str(m_vfValues[VluK_Sy]) + "\n" 
		+ "  T =" + flt2str(m_vfValues[VluK_T])  + "\n" 
		+ "£Guv=" + flt2str(m_vfValues[VluK_Duv]) + "\n" 
		+ " u' =" + flt2str(m_vfValues[VluK_Du]) + "\n"
		+ " v' =" + flt2str(m_vfValues[VluK_Dv]) + "\n"
		+ "  X =" + flt2str(m_vfValues[VluK_X]) + "\n"
		+ "  Y =" + flt2str(m_vfValues[VluK_Y]) + "\n"
		+ "  Z =" + flt2str(m_vfValues[VluK_Z]);
}