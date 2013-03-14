#ifndef  CARTRIDGE2_H
#define  CARTRIDGE2_H

#include "../StdAfx.h"
#include "Bullet.h"
#include "../Enum.h"
#include "Bolt.h"
#include "../CColorRef.h"
//Belt 彈鍊
//Bolt 槍機
//Bullet 彈頭
//Cartridge2 子彈

enum BackGroundStatus{BGS_Normal = 0, BGS_NitsPos, BGS_NitsNeg};
/***************************************
 *    Define Belt Class member function*
 ***************************************/
class Cartridge2
{
//建解構子
public:
    Cartridge2();
	Cartridge2(const Cartridge2&);
    Cartridge2(const ColorRef& , const CPoint& );
    virtual  ~Cartridge2();
//表格順序
private:    UINT m_sequenceFrom;
public:     void setSqncFrm(UINT);
		    UINT getSqncFrm() const;
//區域順序
private:    AreaKind m_sequenceArea;
public:     void     setSqncArea(AreaKind);
			AreaKind getSqncArea() const;
//點位置
private:    CPoint    m_PointPosition;
public:     CPoint    GetPointPosi() const;
		    void      SetPointPosi(CPoint);
//背景色
private:    ColorRef  m_BkColor;
public:     ColorRef  GetBkColor() const;
		    void      SetBkColor(ColorRef);
private:    BackGroundStatus m_bkStatus;
public:     void      SetBkStatus(BackGroundStatus);
			BackGroundStatus GetBkStatus() const;
//資料
private:    Bullet    m_Data;
public:     Bullet    GetBullet() const;
			void      SetBullet(const Bullet& Pd);
//文字描述
private:    CString m_Description;
public:     void SetDescrip(CString);
			CString GetDescrip() const;
//運算子和其它
public:     BOOL operator==(const Cartridge2& vCar);
		    void operator= (const Cartridge2& vCar);
		    CString showMe() const;
//crossTalk
private:    ColorRef m_bColor;
            CRect   m_centerRect;
public:     void setCrsTlkRect(CRect&, ColorRef&);
		    void DrawCrsTlkRect(CPaintDC& dc);
//nits
private:    int m_nitsNum;
public:     int GetNitsNum() const;
 			void SetNitsNum(int&);
};

inline void Cartridge2::SetBkStatus(BackGroundStatus bks)
{
	m_bkStatus = bks;
}

inline BackGroundStatus  Cartridge2::GetBkStatus() const
{
	return m_bkStatus;
}

inline void Cartridge2::SetNitsNum(int& num)
{
	m_nitsNum = num;
}

inline int Cartridge2::GetNitsNum() const
{
	return m_nitsNum;
}

// inline void Cartridge2::fineNits()
// {
// 	int Graylevel(60);
// 	
// // 	if (m_GunMchn.GetNitsKind() == NK_POS) Graylevel = 55;
// //     else if (m_GunMchn.GetNitsKind() == NK_NEG) Graylevel = 60;
// 	
//     for(i = 0; i < 2; ++i)
//     {
// 		if (m_GunMchn.GetNitsKind() == NK_POS) fineNitsPos(Graylevel);
// 		else if (m_GunMchn.GetNitsKind() == NK_NEG) fineNitsNeg(Graylevel);
//         else MessageBox("找Nits出問題。");
//     }
//     m_GunMchn.Set5NitsBkColor(m_BkColor.oRGB());
//     //c_bMsring = c_bFind5nits = !c_bMsring;  //5Nits特別流程結束
// 	c_bFind5nits = FALSE;
// }

#endif