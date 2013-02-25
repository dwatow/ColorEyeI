#ifndef  CARTRIDGE2_H
#define  CARTRIDGE2_H

#include "../StdAfx.h"
#include "Bullet.h"
#include "../Enum.h"
#include "Bolt.h"
#include "../CColorRef.h"
//Belt ºu¡Â
//Bolt ∫jæ˜
//Bullet ºu¿Y
//Cartridge2 §lºu

/***************************************
 *    Define Belt Class member function*
 ***************************************/
class Cartridge2
{
public:
    Cartridge2();
    Cartridge2(ColorRef , CPoint );
    virtual  ~Cartridge2();

private:
    UINT m_sequenceFrom;
public:
    void setSqncFrm(UINT);
    UINT getSqncFrm() const;

private:
    AreaKind  m_sequenceArea;
public:
    void     setSqncArea(AreaKind);
    AreaKind getSqncArea() const;

private:
    CPoint    m_PointPosition;
public:
    CPoint    GetPointPosi() const;
    void      SetPointPosi(CPoint);

private:
    ColorRef  m_BkColor;
public:
    ColorRef  GetBkColor() const;
    void      SetBkColor(ColorRef);

private:
    Bullet    m_Data;

public:
//    Bullet&   GetBullet();
    Bullet    GetBullet() const;
    void      SetBullet(const Bullet& Pd);

public:
    CString   GetTime() const;

private:
    CString m_Description;
public:
    void SetDescrip(CString);
    CString GetDescrip() const;

public:
    BOOL operator==(const Cartridge2& vCar);
    void operator= (const Cartridge2& vCar);

    CString showMe() const;
};

inline Cartridge2::Cartridge2():
m_PointPosition(0, 0), m_BkColor(0, 0, 0)
{}

inline Cartridge2::Cartridge2(ColorRef cy, CPoint pn):
m_PointPosition(pn), m_BkColor(cy)//, _Time(CTime::GetCurrentTime())
{}

inline Cartridge2::~Cartridge2()
{}

inline BOOL Cartridge2::operator==(const Cartridge2& vCar2)
{
    return ( (GetPointPosi() == vCar2.GetPointPosi()) && 
             (GetBkColor()   == vCar2.GetBkColor()  )
            ) ? TRUE : FALSE;
};

inline CString Cartridge2::GetTime() const
{
    return m_Data.GetLastTime();
}

inline void Cartridge2::operator= (const Cartridge2& vCar)
{
    SetDescrip(vCar.GetDescrip());
    setSqncArea(vCar.getSqncArea());
    setSqncFrm(vCar.getSqncFrm());

    SetPointPosi(vCar.GetPointPosi());
    SetBkColor(vCar.GetBkColor());
    
    SetBullet(vCar.GetBullet());
}

inline CString Cartridge2::showMe() const
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

#endif