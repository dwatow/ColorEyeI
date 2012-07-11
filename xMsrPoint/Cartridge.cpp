<<<<<<< HEAD
#include "stdafx.h"
#include "Cartridge.h"
/*******************************************
 *	Define PointSet Class member function  *
 *******************************************/
//繼承掉的介面
// BOOL Cartridge::SetLv(float L){	return m_Data.SetLv(L);}
// BOOL Cartridge::SetSx(float x){	return m_Data.SetSx(x);}
// BOOL Cartridge::SetSy(float y){	return m_Data.SetSy(y);}
// 
// BOOL Cartridge::SetT(long T)		{	return m_Data.SetT(T);}
// BOOL Cartridge::SetDuv(float Duv)	{	return m_Data.SetDuv(Duv);}
// 
// BOOL Cartridge::SetDu(float Du){	return m_Data.SetDu(Du);}
// BOOL Cartridge::SetDv(float Dv){	return m_Data.SetDv(Dv);}
// 
// BOOL Cartridge::SetX(float X){	return m_Data.SetX(X);}
// BOOL Cartridge::SetY(float Y){	return m_Data.SetY(Y);}
// BOOL Cartridge::SetZ(float Z){	return m_Data.SetZ(Z);}
// 
// 
// BOOL Cartridge::SetLv(CString L){	return m_Data.SetLv(L);}
// BOOL Cartridge::SetSx(CString x){	return m_Data.SetSx(x);}
// BOOL Cartridge::SetSy(CString y){	return m_Data.SetSy(y);}
// 
// BOOL Cartridge::SetT(CString T)		{	return m_Data.SetT(T);}
// BOOL Cartridge::SetDuv(CString Duv)	{	return m_Data.SetDuv(Duv);}
// 
// BOOL Cartridge::SetDu(CString Du){	return m_Data.SetDu(Du);}
// BOOL Cartridge::SetDv(CString Dv){	return m_Data.SetDv(Dv);}
// 
// BOOL Cartridge::SetX(CString X){	return m_Data.SetX(X);}
// BOOL Cartridge::SetY(CString Y){	return m_Data.SetY(Y);}
// BOOL Cartridge::SetZ(CString Z){	return m_Data.SetZ(Z);}
// 
// 
// float Cartridge::GetLv() const { return m_Data.GetLv();}	CString Cartridge::GetStrLv()  const {	return m_Data.GetStrLv();}
// float Cartridge::GetSx() const { return m_Data.GetSx();}	CString Cartridge::GetStrSx()  const {	return m_Data.GetStrSx();}
// float Cartridge::GetSy() const { return m_Data.GetSy();}	CString Cartridge::GetStrSy()  const {	return m_Data.GetStrSy();}
// 
// long  Cartridge::GetT()  const  { return m_Data.GetT();}	CString Cartridge::GetStrT()	const {	return m_Data.GetStrT();}
// float Cartridge::GetDuv() const { return m_Data.GetDuv();}	CString Cartridge::GetStrDuv() const {	return m_Data.GetStrDuv();}
// 
// float Cartridge::GetDu() const { return m_Data.GetDu();}	CString Cartridge::GetStrDu()  const {	return m_Data.GetStrDu();}
// float Cartridge::GetDv() const { return m_Data.GetDv();}	CString Cartridge::GetStrDv()  const {	return m_Data.GetStrDv();}
// 
// float Cartridge::GetX() const { return m_Data.GetX();}	CString Cartridge::GetStrX()   const {	return m_Data.GetStrX();}
// float Cartridge::GetY() const { return m_Data.GetY();}	CString Cartridge::GetStrY()   const {	return m_Data.GetStrY();}
// float Cartridge::GetZ() const { return m_Data.GetZ();}	CString Cartridge::GetStrZ()   const {	return m_Data.GetStrZ();}

Bullet Cartridge::GetBullet() const	
{	
	Bullet Pd;
	Pd.SetLv(m_fLv);											Pd.SetX(m_fX);
	Pd.SetSx(m_fSx);	Pd.SetT(m_lT);		Pd.SetDu(m_fDu);	Pd.SetY(m_fY);
	Pd.SetSy(m_fSy);	Pd.SetDuv(m_fDuv);	Pd.SetDv(m_fDv);	Pd.SetZ(m_fZ);
	return Pd;	
}
void Cartridge::SetBullet(const Bullet& Pd)	
{
	SetLv(Pd.GetLv());												SetX(Pd.GetX());
	SetSx(Pd.GetSx());	SetT  (Pd.GetT());		SetDu(Pd.GetDu());	SetY(Pd.GetY());
	SetSy(Pd.GetSy());	SetDuv(Pd.GetDuv());	SetDv(Pd.GetDv());	SetZ(Pd.GetZ());
}

Cartridge::Cartridge():
m_MsrFlowNo(0), m_AreaCode(0), m_OrigSeqc(0)
{}

Cartridge::Cartridge(ColorType cy, PointNum pn):
m_BkColor(cy), m_MsrFlowNum(pn),
m_AreaCode(0), m_MsrFlowNo(0)
{}

Cartridge::~Cartridge()
{}

ColorType Cartridge::GetBackColor()	const       {	return m_BkColor;	}
void      Cartridge::SetBackColor(ColorType clr){	m_BkColor = clr;    }

PointNum Cartridge::GetPostition()	const	  {	return m_MsrFlowNum;	}
void     Cartridge::SetPostition(PointNum pps){	m_MsrFlowNum = pps;}

void Cartridge::SetArea(UINT ac)              {    m_AreaCode = ac;   }
void Cartridge::SetMsrFlowNum(PointNum mfNum) {    m_MsrFlowNum = mfNum;}
void Cartridge::SetMsrFlowNo(UINT mfNo)       {    m_MsrFlowNo = mfNo;}

UINT     Cartridge::GetArea() const {    return m_AreaCode; } 

PointNum Cartridge::GetMsrFlowNum() const {    return m_MsrFlowNum;}
UINT     Cartridge::GetMsrFlowNo()  const {    return m_MsrFlowNo;}

void Cartridge::SetOrigSeqc(UINT Seqc){ m_OrigSeqc = Seqc;}
UINT Cartridge::GetOrigSeqc() const   { return m_OrigSeqc;}

CString Cartridge::MsgBoxStr() const
{
	CString str;
	str.Format("AreaCode   = %d\nBackColor  = %d\nMsrFlowNo  = %d\nMsrFlowNum = %d\nLv:%f, %s\nx:%f, %s\ny:%f, %s\nT:%d, %s\nDuv:%f, %s\nDu:%f, %s\nDv:%f, %s\nX:%f, %s\nY:%f, %s\nZ:%f, %s"\
		, m_AreaCode, m_BkColor, m_MsrFlowNo, m_MsrFlowNum\
		, m_fLv, m_strLv, m_fSx, m_strSx, m_fSy, m_strSy\
		, m_lT, m_strT, m_fDuv, m_strDuv\
		, m_fDu, m_strDu, m_fDv, m_strDv\
		, m_fX, m_strX, m_fY, m_strY, m_fZ, m_strZ);

	return str;
}

CString Cartridge::GetSetupValue() const
{
	CString str;
	CString color;

	switch(m_BkColor)
	{
	case 1:	color.Format("White"); break;
	case 2: color.Format("Red");   break;
	case 3: color.Format("Green"); break;
	case 4: color.Format("Blue");  break;
	case 5: color.Format("Dark");  break;
	case 6: color.Format("Nits");  break;
	default: color.Format("UnDefine"); break;
	}

	str.Format("顏色項目=%s, 點位/項目/所有: %d/%d/%d, 區域碼=%d",\
		color, m_MsrFlowNo, m_MsrFlowNum, m_OrigSeqc, m_AreaCode);

	return str;
=======
#include "stdafx.h"
#include "Cartridge.h"
/*******************************************
 *	Define PointSet Class member function  *
 *******************************************/
//繼承掉的介面
// BOOL Cartridge::SetLv(float L){	return m_Data.SetLv(L);}
// BOOL Cartridge::SetSx(float x){	return m_Data.SetSx(x);}
// BOOL Cartridge::SetSy(float y){	return m_Data.SetSy(y);}
// 
// BOOL Cartridge::SetT(long T)		{	return m_Data.SetT(T);}
// BOOL Cartridge::SetDuv(float Duv)	{	return m_Data.SetDuv(Duv);}
// 
// BOOL Cartridge::SetDu(float Du){	return m_Data.SetDu(Du);}
// BOOL Cartridge::SetDv(float Dv){	return m_Data.SetDv(Dv);}
// 
// BOOL Cartridge::SetX(float X){	return m_Data.SetX(X);}
// BOOL Cartridge::SetY(float Y){	return m_Data.SetY(Y);}
// BOOL Cartridge::SetZ(float Z){	return m_Data.SetZ(Z);}
// 
// 
// BOOL Cartridge::SetLv(CString L){	return m_Data.SetLv(L);}
// BOOL Cartridge::SetSx(CString x){	return m_Data.SetSx(x);}
// BOOL Cartridge::SetSy(CString y){	return m_Data.SetSy(y);}
// 
// BOOL Cartridge::SetT(CString T)		{	return m_Data.SetT(T);}
// BOOL Cartridge::SetDuv(CString Duv)	{	return m_Data.SetDuv(Duv);}
// 
// BOOL Cartridge::SetDu(CString Du){	return m_Data.SetDu(Du);}
// BOOL Cartridge::SetDv(CString Dv){	return m_Data.SetDv(Dv);}
// 
// BOOL Cartridge::SetX(CString X){	return m_Data.SetX(X);}
// BOOL Cartridge::SetY(CString Y){	return m_Data.SetY(Y);}
// BOOL Cartridge::SetZ(CString Z){	return m_Data.SetZ(Z);}
// 
// 
// float Cartridge::GetLv() const { return m_Data.GetLv();}	CString Cartridge::GetStrLv()  const {	return m_Data.GetStrLv();}
// float Cartridge::GetSx() const { return m_Data.GetSx();}	CString Cartridge::GetStrSx()  const {	return m_Data.GetStrSx();}
// float Cartridge::GetSy() const { return m_Data.GetSy();}	CString Cartridge::GetStrSy()  const {	return m_Data.GetStrSy();}
// 
// long  Cartridge::GetT()  const  { return m_Data.GetT();}	CString Cartridge::GetStrT()	const {	return m_Data.GetStrT();}
// float Cartridge::GetDuv() const { return m_Data.GetDuv();}	CString Cartridge::GetStrDuv() const {	return m_Data.GetStrDuv();}
// 
// float Cartridge::GetDu() const { return m_Data.GetDu();}	CString Cartridge::GetStrDu()  const {	return m_Data.GetStrDu();}
// float Cartridge::GetDv() const { return m_Data.GetDv();}	CString Cartridge::GetStrDv()  const {	return m_Data.GetStrDv();}
// 
// float Cartridge::GetX() const { return m_Data.GetX();}	CString Cartridge::GetStrX()   const {	return m_Data.GetStrX();}
// float Cartridge::GetY() const { return m_Data.GetY();}	CString Cartridge::GetStrY()   const {	return m_Data.GetStrY();}
// float Cartridge::GetZ() const { return m_Data.GetZ();}	CString Cartridge::GetStrZ()   const {	return m_Data.GetStrZ();}

Bullet Cartridge::GetBullet() const	
{	
	Bullet Pd;
	Pd.SetLv(m_fLv);											Pd.SetX(m_fX);
	Pd.SetSx(m_fSx);	Pd.SetT(m_lT);		Pd.SetDu(m_fDu);	Pd.SetY(m_fY);
	Pd.SetSy(m_fSy);	Pd.SetDuv(m_fDuv);	Pd.SetDv(m_fDv);	Pd.SetZ(m_fZ);
	return Pd;	
}
void Cartridge::SetBullet(const Bullet& Pd)	
{
	SetLv(Pd.GetLv());												SetX(Pd.GetX());
	SetSx(Pd.GetSx());	SetT  (Pd.GetT());		SetDu(Pd.GetDu());	SetY(Pd.GetY());
	SetSy(Pd.GetSy());	SetDuv(Pd.GetDuv());	SetDv(Pd.GetDv());	SetZ(Pd.GetZ());
}

Cartridge::Cartridge():
m_MsrFlowNo(0), m_AreaCode(0), m_OrigSeqc(0)
{}

Cartridge::Cartridge(ColorType cy, PointNum pn):
m_BkColor(cy), m_MsrFlowNum(pn),
m_AreaCode(0), m_MsrFlowNo(0)
{}

Cartridge::~Cartridge()
{}

ColorType Cartridge::GetBackColor()	const       {	return m_BkColor;	}
void      Cartridge::SetBackColor(ColorType clr){	m_BkColor = clr;    }

PointNum Cartridge::GetPostition()	const	  {	return m_MsrFlowNum;	}
void     Cartridge::SetPostition(PointNum pps){	m_MsrFlowNum = pps;}

void Cartridge::SetArea(UINT ac)              {    m_AreaCode = ac;   }
void Cartridge::SetMsrFlowNum(PointNum mfNum) {    m_MsrFlowNum = mfNum;}
void Cartridge::SetMsrFlowNo(UINT mfNo)       {    m_MsrFlowNo = mfNo;}

UINT     Cartridge::GetArea() const {    return m_AreaCode; } 

PointNum Cartridge::GetMsrFlowNum() const {    return m_MsrFlowNum;}
UINT     Cartridge::GetMsrFlowNo()  const {    return m_MsrFlowNo;}

void Cartridge::SetOrigSeqc(UINT Seqc){ m_OrigSeqc = Seqc;}
UINT Cartridge::GetOrigSeqc() const   { return m_OrigSeqc;}

CString Cartridge::MsgBoxStr() const
{
	CString str;
	str.Format("AreaCode   = %d\nBackColor  = %d\nMsrFlowNo  = %d\nMsrFlowNum = %d\nLv:%f, %s\nx:%f, %s\ny:%f, %s\nT:%d, %s\nDuv:%f, %s\nDu:%f, %s\nDv:%f, %s\nX:%f, %s\nY:%f, %s\nZ:%f, %s"\
		, m_AreaCode, m_BkColor, m_MsrFlowNo, m_MsrFlowNum\
		, m_fLv, m_strLv, m_fSx, m_strSx, m_fSy, m_strSy\
		, m_lT, m_strT, m_fDuv, m_strDuv\
		, m_fDu, m_strDu, m_fDv, m_strDv\
		, m_fX, m_strX, m_fY, m_strY, m_fZ, m_strZ);

	return str;
}

CString Cartridge::GetSetupValue() const
{
	CString str;
	CString color;

	switch(m_BkColor)
	{
	case 1:	color.Format("White"); break;
	case 2: color.Format("Red");   break;
	case 3: color.Format("Green"); break;
	case 4: color.Format("Blue");  break;
	case 5: color.Format("Dark");  break;
	case 6: color.Format("Nits");  break;
	default: color.Format("UnDefine"); break;
	}

	str.Format("顏色項目=%s, 點位/項目/所有: %d/%d/%d, 區域碼=%d",\
		color, m_MsrFlowNo, m_MsrFlowNum, m_OrigSeqc, m_AreaCode);

	return str;
>>>>>>> b5425c75ef070be7770a30afe5b503213bd2584b
}