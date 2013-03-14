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
//資料
private:    Bullet    m_Data;
public://    Bullet&   GetBullet();
            Bullet    GetBullet() const;
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
 private:   ColorRef m_bColor;
			//CBrush* m_pCtrRctBrush;
            CRect   m_centerRect;
public:// virtual void  DrawBackGround(CPaintDC&){};
		    void setCrsTlkRect(CRect&, ColorRef&);
		    void DrawCrsTlkRect(CPaintDC& dc);

};

#endif