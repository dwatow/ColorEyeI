#include"stdafx.h"
#include"Bullet.h"
/******************************************
 *    Define Bullet Class member function *
 ******************************************/

Bullet::Bullet():
m_vstrValues(VluK_Total), m_vfValues(VluK_Total, 0.0),
m_LastModifyTime(CTime::GetCurrentTime())
{}

Bullet::Bullet(const Bullet& xp):
m_vstrValues(xp.m_vstrValues), m_vfValues(xp.m_vfValues),
m_LastModifyTime(xp.m_LastModifyTime)
{}

Bullet::~Bullet()
{
    m_vfValues.clear();
    m_vstrValues.clear();
}

void Bullet::i(ValueKind _VK, float _F)
{
    ASSERT( _F>=0 && _F<=0.8 ); 
    m_vfValues[_VK] = _F;
    m_vstrValues[_VK] = flt2str(_F);
    m_LastModifyTime = CTime::GetCurrentTime(); 
}

void Bullet::i(ValueKind _VK, CString _S)
{
    ASSERT( str2flt(_S)>=0 && str2flt(_S)<=0.8 ); 
    m_vfValues[_VK] = str2flt(_S);
    m_vstrValues[_VK] = _S;
    m_LastModifyTime = CTime::GetCurrentTime(); 
}

float Bullet::oFlt(ValueKind _VK) const
{
    return m_vfValues[_VK];
}

CString Bullet::oStr(ValueKind _VK) const
{
    return m_vstrValues[_VK];
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
    m_vstrValues = xp.m_vstrValues;
    m_LastModifyTime = xp.m_LastModifyTime;
}

BOOL Bullet::isEmpty() const
{
    return (m_vfValues.empty() && m_vstrValues.empty()) ? TRUE : FALSE ;
}

CString Bullet::GetLastTime() const
{
    CString str;
    str.Format("%d/%d/%d, %d:%d:%d", 
        m_LastModifyTime.GetYear(), m_LastModifyTime.GetMonth(), m_LastModifyTime.GetDay(), 
        m_LastModifyTime.GetHour(), m_LastModifyTime.GetMinute(), m_LastModifyTime.GetSecond());

    return str;
}

//////////////////////////////////////////////////////////////////////////
//debug function

CString Bullet::showStr() const
{
    return " Lv =" + m_vstrValues[VluK_Lv] + "\n" 
         + "  x =" + m_vstrValues[VluK_Sx] + "\n" 
         + "  y =" + m_vstrValues[VluK_Sy] + "\n" 
         + "  T =" + m_vstrValues[VluK_T]  + "\n" 
         + "£Guv=" + m_vstrValues[VluK_Duv] + "\n" 
         + " u' =" + m_vstrValues[VluK_Du] + "\n"
         + " v' =" + m_vstrValues[VluK_Dv] + "\n"
         + "  X =" + m_vstrValues[VluK_X] + "\n"
         + "  Y =" + m_vstrValues[VluK_Y] + "\n"
         + "  Z =" + m_vstrValues[VluK_Z];
}

CString Bullet::showFlt() const
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

//     strBullet.Format("Lv:%f, %s\nx:%f, %s\ny:%f, %s\nT:%d, %s\nDuv:%f, %s\nDu:%f, %s\nDv:%f, %s\nX:%f, %s\nY:%f, %s\nZ:%f, %s"\
//         , m_fLv , m_strLv  \
//         , m_fSx , m_strSx  \
//         , m_fSy , m_strSy  \
//         , m_lT  , m_strT   \
//         , m_fDuv, m_strDuv \
//         , m_fDu , m_strDu  \
//         , m_fDv , m_strDv  \
//         , m_fX  , m_strX   \
//         , m_fY  , m_strY   \
//         , m_fZ  , m_strZ   \
//         );
// 

