#ifndef  CARTRIDGE2_H
#define  CARTRIDGE2_H

#include "../StdAfx.h"
#include "Bullet.h"
#include "../Enum.h"
#include "Bolt.h"
#include "../CColorRef.h"
//Belt �u��
//Bolt �j��
//Bullet �u�Y
//Cartridge2 �l�u

/***************************************
 *    Define Belt Class member function*
 ***************************************/
class Cartridge2
{
//�ظѺc�l
public:
    Cartridge2();
	Cartridge2(const Cartridge2&);
    Cartridge2(const ColorRef& , const CPoint& );
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
//�I����
private:    ColorRef  m_BkColor;
public:     ColorRef  GetBkColor() const;
		    void      SetBkColor(ColorRef);
//���
private:    Bullet    m_Data;
public://    Bullet&   GetBullet();
            Bullet    GetBullet() const;
			void      SetBullet(const Bullet& Pd);
//��r�y�z
private:    CString m_Description;
public:     void SetDescrip(CString);
			CString GetDescrip() const;
//�B��l�M�䥦
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