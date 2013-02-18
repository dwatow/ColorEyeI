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

    float GetLv()  const;   CString GetStrLv()  const;    BOOL SetLv(float);   BOOL SetLv(CString);
    float GetSx()  const;   CString GetStrSx()  const;    BOOL SetSx(float);   BOOL SetSx(CString);
    float GetSy()  const;   CString GetStrSy()  const;    BOOL SetSy(float);   BOOL SetSy(CString);
    
    long  GetT()   const;   CString GetStrT()   const;    BOOL SetT(long);     BOOL SetT(CString);
    float GetDuv() const;   CString GetStrDuv() const;    BOOL SetDuv(float);  BOOL SetDuv(CString);
    
    float GetDu()  const;   CString GetStrDu()  const;    BOOL SetDu(float);   BOOL SetDu(CString);
    float GetDv()  const;   CString GetStrDv()  const;    BOOL SetDv(float);   BOOL SetDv(CString);
    
    float GetX()   const;   CString GetStrX()   const;    BOOL SetX(float);    BOOL SetX(CString);
    float GetY()   const;   CString GetStrY()   const;    BOOL SetY(float);    BOOL SetY(CString);
    float GetZ()   const;   CString GetStrZ()   const;    BOOL SetZ(float);    BOOL SetZ(CString);

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