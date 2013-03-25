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

void Bullet::i(const ValueKind& _VK, const float& _F)
{
//    ASSERT( _F>=0 && _F<=0.8 ); 
//不是只會輸入色度，所以不需要檢查定義域
    m_vfValues[_VK] = _F;
    m_LastModifyTime = CTime::GetCurrentTime(); 
}

void Bullet::i(const ValueKind& _VK, const CString& _S)
{
    ASSERT( str2flt(_S)>=0 && str2flt(_S)<=0.8 ); 
    m_vfValues[_VK] = str2flt(_S);
    m_LastModifyTime = CTime::GetCurrentTime(); 
}

const float Bullet::oFlt(const ValueKind& _VK) const
{
    return m_vfValues[_VK];
}

const CString Bullet::oStr(const ValueKind& _VK) const
{
    return flt2str(m_vfValues[_VK]);
}
//////////////////////////////////////////////////////////////////////////
const float Bullet::str2flt(CString _Str) const
{
    return atof(_Str.GetBuffer(0));
}

const CString Bullet::flt2str(const float& _F) const
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

const BOOL Bullet::isEmpty() const
{
	for (std::vector<float>::const_iterator vitor = m_vfValues.begin(); vitor != m_vfValues.end(); ++vitor)
		if ( *vitor == 0.0 ) 
			return TRUE;

    return FALSE ;
}

const CString Bullet::GetLastTime() const
{
    CString str;
    str.Format("%d/%d/%d, %d:%d:%d", 
        m_LastModifyTime.GetYear(), m_LastModifyTime.GetMonth(), m_LastModifyTime.GetDay(), 
        m_LastModifyTime.GetHour(), m_LastModifyTime.GetMinute(), m_LastModifyTime.GetSecond());

    return str;
}

const CString Bullet::show() const
{
    return " Lv =" + flt2str(m_vfValues[VluK_Lv]) + "\n" 
		+ "  x =" + flt2str(m_vfValues[VluK_Sx]) + "\n" 
		+ "  y =" + flt2str(m_vfValues[VluK_Sy]) + "\n" 
		+ "  T =" + flt2str(m_vfValues[VluK_T])  + "\n" 
		+ "Δuv=" + flt2str(m_vfValues[VluK_Duv]) + "\n" 
		+ " u' =" + flt2str(m_vfValues[VluK_Du]) + "\n"
		+ " v' =" + flt2str(m_vfValues[VluK_Dv]) + "\n"
		+ "  X =" + flt2str(m_vfValues[VluK_X]) + "\n"
		+ "  Y =" + flt2str(m_vfValues[VluK_Y]) + "\n"
		+ "  Z =" + flt2str(m_vfValues[VluK_Z]);
}