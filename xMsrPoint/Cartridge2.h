#ifndef  CARTRIDGE2_H
#define  CARTRIDGE2_H

#include "../StdAfx.h"
#include "Bullet.h"
#include "../CColorRef.h"
#include "../BkCrossTalk.h"
#include "../BkNits.h"

//Belt 彈鍊
//Bolt 槍機
//Bullet 彈頭
//Cartridge2 子彈
enum BackGroundStatus { BGS_Normal = 0, BGS_NitsPos, BGS_NitsNeg, BGS_CrossTalkWrite, BGS_CrossTalkDark };
enum AreaKind { AA_00, AA_01, AA_02, AA_03, AA_04, AA_05, AA_06, AA_07, AA_08, AA_09};

/***************************************
 *    Define Belt Class member function*
 ***************************************/
class Cartridge2
{
//建解構子
public:
    Cartridge2();
    Cartridge2(const Cartridge2&);
    ~Cartridge2();
//表格順序
private:              UINT m_sequenceFrom;
public:               void SetSqncFrm(const UINT&);
                const UINT GetSqncFrm() const;
//區域順序
private:          AreaKind m_sequenceArea;
public:               void SetSqncArea(const AreaKind&);
            const AreaKind GetSqncArea() const;
//點位置
private:            CPoint m_PointPosition;
public:       const CPoint GetPointPosi() const;
                      void SetPointPosi(const CPoint&);
//背景
private:
public:           BkMaker* m_pBackGorund;
                  ColorRef GetBkColor() const;  //operator==() can't return const
                      void SetBkColor(const ColorRef&);
//背景狀態（描述符）
private:  BackGroundStatus m_bkStatus;
public:               void SetBkStatus( const BackGroundStatus& _BGS, const BOOL& creatBGS = TRUE);
          BackGroundStatus GetBkStatus() const;
		     const CString GetStrBkStatus() const;
//資料
private:            Bullet m_Data;
public:       const Bullet GetBullet() const;
			        Bullet GetBullet();
                      void SetBullet(const Bullet& Pd);
//文字描述
private:           CString m_Description;
public:               void SetDescrip(const CString&);
             const CString GetDescrip() const;
//運算子和其它
public:         const BOOL operator==(const Cartridge2& vCar) const;
                      void operator= (const Cartridge2& vCar);
//////////////////////////////////////////////////////////////////////////
             const CString showMe() const;
};

#endif