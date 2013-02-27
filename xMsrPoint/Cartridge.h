#ifndef  CARTRIDGE_H
#define  CARTRIDGE_H

#include "../StdAfx.h"
#include "Bullet.h"
#include "../Enum.h"
//Belt �u��
//Bolt �j��
//Bullet �u�Y
//Cartridge �l�u

/***************************************
 *    Define Belt Class member function*
 ***************************************/
class Cartridge// : public Bullet
{
    ColorType m_BkColor;
    PointNum  m_MsrFlowNum;  //�Ӷ��ئ@�X�I
    UINT      m_MsrFlowNo;   //�o�O�Ӷ��ت��ĴX�I  ���ζ���
    UINT      m_AreaCode;    //�ֳt�q������    �̶q���Ϫ�e��
    UINT      m_OrigSeqc;
	Bullet    m_Data;

public:
    Cartridge();
    Cartridge(ColorType, PointNum);
    virtual  ~Cartridge();

    UINT GetOrigSeqc() const;
    void SetOrigSeqc(UINT);

    UINT GetMsrFlowNo() const;
    void SetMsrFlowNo(UINT);
    
    PointNum GetMsrFlowNum() const;
	CString  GetStrPointNum() const;
    void     SetMsrFlowNum(PointNum);
    
    UINT GetArea() const;
    void SetArea(UINT);

    ColorType GetBackColor() const;
	CString   GetStrColorType() const;
    void      SetBackColor(ColorType clr);

    float GetLv()  const;   CString GetStrLv()  const;    void SetLv(float);   void SetLv(CString);
    float GetSx()  const;   CString GetStrSx()  const;    void SetSx(float);   void SetSx(CString);
    float GetSy()  const;   CString GetStrSy()  const;    void SetSy(float);   void SetSy(CString);
    
    long  GetT()   const;   CString GetStrT()   const;    void SetT(float);     void SetT(CString);
    float GetDuv() const;   CString GetStrDuv() const;    void SetDuv(float);  void SetDuv(CString);
    
    float GetDu()  const;   CString GetStrDu()  const;    void SetDu(float);   void SetDu(CString);
    float GetDv()  const;   CString GetStrDv()  const;    void SetDv(float);   void SetDv(CString);
    
    float GetX()   const;   CString GetStrX()   const;    void SetX(float);    void SetX(CString);
    float GetY()   const;   CString GetStrY()   const;    void SetY(float);    void SetY(CString);
    float GetZ()   const;   CString GetStrZ()   const;    void SetZ(float);    void SetZ(CString);

	Bullet  GetBullet() const;
    void   SetBullet(const Bullet& Pd);

    BOOL operator==(const Cartridge& vCar);
	void operator= (const Cartridge& vCar);


//////////////////////////////////////////////////////////////////////////
//debug function

#ifdef _DEBUG
    CString MsgBoxStr() const;
    CString GetSetupValue() const;
#endif    
//////////////////////////////////////////////////////////////////////////
  
};


inline BOOL Cartridge::operator==(const Cartridge& vCar)
{
	return ((GetMsrFlowNo()  == vCar.GetMsrFlowNo() ) && 
		(GetMsrFlowNum() == vCar.GetMsrFlowNum()) && 
		(GetBackColor()  == vCar.GetBackColor() )) ? TRUE : FALSE;
};

inline void Cartridge::operator= (const Cartridge& vCar)
{
	SetMsrFlowNo(vCar.GetMsrFlowNo());
	SetMsrFlowNum(vCar.GetMsrFlowNum());
	SetBackColor(vCar.GetBackColor());
	SetArea(vCar.GetArea());
	SetOrigSeqc(vCar.GetOrigSeqc());
	
	SetBullet(vCar.GetBullet());
}

#endif