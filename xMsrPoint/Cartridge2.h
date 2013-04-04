#ifndef  CARTRIDGE2_H
#define  CARTRIDGE2_H

#include "../StdAfx.h"
#include "Bullet.h"
#include "../CColorRef.h"
#include "../BkCrossTalk.h"
#include "../BkNits.h"

//Belt �u��
//Bolt �j��
//Bullet �u�Y
//Cartridge2 �l�u
enum BackGroundStatus { BGS_Normal = 0, BGS_NitsPos, BGS_NitsNeg, BGS_CrossTalkWrite, BGS_CrossTalkDark };
enum AreaKind { AA_00, AA_01, AA_02, AA_03, AA_04, AA_05, AA_06, AA_07, AA_08, AA_09};

/***************************************
 *    Define Belt Class member function*
 ***************************************/
class Cartridge2
{
//�ظѺc�l
public:
    Cartridge2();
    Cartridge2(const Cartridge2&);
    ~Cartridge2();
//��涶��
private:              UINT m_sequenceFrom;
public:               void SetSqncFrm(const UINT&);
                const UINT GetSqncFrm() const;
//�ϰ춶��
private:          AreaKind m_sequenceArea;
public:               void SetSqncArea(const AreaKind&);
            const AreaKind GetSqncArea() const;
//�I��m
private:            CPoint m_PointPosition;
public:       const CPoint GetPointPosi() const;
                      void SetPointPosi(const CPoint&);
//�I��
private:
public:           BkMaker* m_pBackGorund;
                  ColorRef GetBkColor() const;  //operator==() can't return const
                      void SetBkColor(const ColorRef&);
//�I�����A�]�y�z�š^
private:  BackGroundStatus m_bkStatus;
public:               void SetBkStatus( const BackGroundStatus& _BGS, const BOOL& creatBGS = TRUE);
          BackGroundStatus GetBkStatus() const;
		     const CString GetStrBkStatus() const;
//���
private:            Bullet m_Data;
public:       const Bullet GetBullet() const;
			        Bullet GetBullet();
                      void SetBullet(const Bullet& Pd);
//��r�y�z
private:           CString m_Description;
public:               void SetDescrip(const CString&);
             const CString GetDescrip() const;
//�B��l�M�䥦
public:         const BOOL operator==(const Cartridge2& vCar) const;
                      void operator= (const Cartridge2& vCar);
//////////////////////////////////////////////////////////////////////////
             const CString showMe() const;
};

#endif