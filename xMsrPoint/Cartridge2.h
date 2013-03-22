#ifndef  CARTRIDGE2_H
#define  CARTRIDGE2_H

#include "../StdAfx.h"
#include "Bullet.h"
#include "../Enum.h"
#include "Bolt.h"
#include "../CColorRef.h"
#include "../BkCrossTalk.h"
#include "../BkNits.h"

//Belt �u��
//Bolt �j��
//Bullet �u�Y
//Cartridge2 �l�u
enum BackGroundStatus{BGS_Normal = 0, BGS_NitsPos, BGS_NitsNeg, BGS_CrossTalkWrite, BGS_CrossTalkDark };

/***************************************
 *    Define Belt Class member function*
 ***************************************/
class Cartridge2
{
//�ظѺc�l
public:
    Cartridge2();
	Cartridge2(const Cartridge2&);
    virtual  ~Cartridge2();
//��涶��
private:    UINT m_sequenceFrom;
public:     void setSqncFrm(UINT);
		    UINT getSqncFrm() const;
//�ϰ춶��
private:    AreaKind m_sequenceArea;
public:     void     setSqncArea(AreaKind);
			AreaKind getSqncArea() const;
//�I��m
private:    CPoint    m_PointPosition;
public:     CPoint    GetPointPosi() const;
		    void      SetPointPosi(CPoint);
//�I��
private:
public:     BkMaker*  m_pBackGorund;
            ColorRef  GetBkColor() const;
		    void      SetBkColor(ColorRef);
			void      GrabBKM(Cartridge2&);

private:    BackGroundStatus m_bkStatus;
			CString   GetStrBkStatus() const;
public:     void      SetBkStatus(BackGroundStatus);
			BackGroundStatus GetBkStatus() const;
//���
private:    Bullet    m_Data;
public:     Bullet    GetBullet() const;
			void      SetBullet(const Bullet& Pd);
//��r�y�z
private:    CString m_Description;
public:     void SetDescrip(CString);
			CString GetDescrip() const;
//�B��l�M�䥦
public:     BOOL operator==(const Cartridge2& vCar);
		    void operator= (const Cartridge2& vCar);
//////////////////////////////////////////////////////////////////////////
			CString showMe() const;
};

inline void Cartridge2::GrabBKM(Cartridge2& _C)
{
	m_pBackGorund = _C.m_pBackGorund;
	_C.m_pBackGorund = 0;
}

#endif