#include "stdafx.h"
#include "Cartridge.h"
/*******************************************
 *    Define PointSet Class member function  *
 *******************************************/
//繼承掉的介面
// BOOL Cartridge::SetLv(float L){    return m_Data.SetLv(L);}
// BOOL Cartridge::SetSx(float x){    return m_Data.SetSx(x);}
// BOOL Cartridge::SetSy(float y){    return m_Data.SetSy(y);}
// 
// BOOL Cartridge::SetT(long T)        {    return m_Data.SetT(T);}
// BOOL Cartridge::SetDuv(float Duv)    {    return m_Data.SetDuv(Duv);}
// 
// BOOL Cartridge::SetDu(float Du){    return m_Data.SetDu(Du);}
// BOOL Cartridge::SetDv(float Dv){    return m_Data.SetDv(Dv);}
// 
// BOOL Cartridge::SetX(float X){    return m_Data.SetX(X);}
// BOOL Cartridge::SetY(float Y){    return m_Data.SetY(Y);}
// BOOL Cartridge::SetZ(float Z){    return m_Data.SetZ(Z);}
// 
// 
// BOOL Cartridge::SetLv(CString L){    return m_Data.SetLv(L);}
// BOOL Cartridge::SetSx(CString x){    return m_Data.SetSx(x);}
// BOOL Cartridge::SetSy(CString y){    return m_Data.SetSy(y);}
// 
// BOOL Cartridge::SetT(CString T)        {    return m_Data.SetT(T);}
// BOOL Cartridge::SetDuv(CString Duv)    {    return m_Data.SetDuv(Duv);}
// 
// BOOL Cartridge::SetDu(CString Du){    return m_Data.SetDu(Du);}
// BOOL Cartridge::SetDv(CString Dv){    return m_Data.SetDv(Dv);}
// 
// BOOL Cartridge::SetX(CString X){    return m_Data.SetX(X);}
// BOOL Cartridge::SetY(CString Y){    return m_Data.SetY(Y);}
// BOOL Cartridge::SetZ(CString Z){    return m_Data.SetZ(Z);}


// float Cartridge::GetLv() const { return m_Data.GetLv();}    CString Cartridge::GetStrLv()  const {    return m_Data.GetStrLv();}
// float Cartridge::GetSx() const { return m_Data.GetSx();}    CString Cartridge::GetStrSx()  const {    return m_Data.GetStrSx();}
// float Cartridge::GetSy() const { return m_Data.GetSy();}    CString Cartridge::GetStrSy()  const {    return m_Data.GetStrSy();}
// 
// long  Cartridge::GetT()  const  { return m_Data.GetT();}    CString Cartridge::GetStrT()    const {    return m_Data.GetStrT();}
// float Cartridge::GetDuv() const { return m_Data.GetDuv();}    CString Cartridge::GetStrDuv() const {    return m_Data.GetStrDuv();}
// 
// float Cartridge::GetDu() const { return m_Data.GetDu();}    CString Cartridge::GetStrDu()  const {    return m_Data.GetStrDu();}
// float Cartridge::GetDv() const { return m_Data.GetDv();}    CString Cartridge::GetStrDv()  const {    return m_Data.GetStrDv();}
// 
// float Cartridge::GetX() const { return m_Data.GetX();}    CString Cartridge::GetStrX()   const {    return m_Data.GetStrX();}
// float Cartridge::GetY() const { return m_Data.GetY();}    CString Cartridge::GetStrY()   const {    return m_Data.GetStrY();}
// float Cartridge::GetZ() const { return m_Data.GetZ();}    CString Cartridge::GetStrZ()   const {    return m_Data.GetStrZ();}

Bullet Cartridge::GetBullet() const    
{    
    Bullet Pd;
    Pd.SetLv(m_fLv);                                            Pd.SetX(m_fX);
    Pd.SetSx(m_fSx);    Pd.SetT(m_lT);        Pd.SetDu(m_fDu);    Pd.SetY(m_fY);
    Pd.SetSy(m_fSy);    Pd.SetDuv(m_fDuv);    Pd.SetDv(m_fDv);    Pd.SetZ(m_fZ);
    return Pd;    
}
void Cartridge::SetBullet(const Bullet& Pd)    
{
//    m_Data = Pd;
    SetLv(Pd.GetLv());                                                SetX(Pd.GetX());
    SetSx(Pd.GetSx());    SetT  (Pd.GetT());        SetDu(Pd.GetDu());    SetY(Pd.GetY());
    SetSy(Pd.GetSy());    SetDuv(Pd.GetDuv());    SetDv(Pd.GetDv());    SetZ(Pd.GetZ());
}

Cartridge::Cartridge():
m_MsrFlowNo(99), m_AreaCode(99), m_OrigSeqc(99), m_BkColor(NoColor), m_MsrFlowNum(NoPn)
{}

Cartridge::Cartridge(ColorType cy, PointNum pn):
m_BkColor(cy), m_MsrFlowNum(pn),
m_AreaCode(99), m_MsrFlowNo(99), m_OrigSeqc(99)
{}

Cartridge::~Cartridge()
{}

UINT Cartridge::GetOrigSeqc() const{    return m_OrigSeqc;    }
void Cartridge::SetOrigSeqc(UINT Orig)  {    m_OrigSeqc = Orig;    }


ColorType Cartridge::GetBackColor()    const       {    return m_BkColor;    }
void      Cartridge::SetBackColor(ColorType clr){    m_BkColor = clr;    }

void Cartridge::SetArea(UINT ac)              {    m_AreaCode = ac;   }
UINT Cartridge::GetArea() const               {    return m_AreaCode; } 

PointNum Cartridge::GetMsrFlowNum() const     {    return m_MsrFlowNum;}
void Cartridge::SetMsrFlowNum(PointNum mfNum) {    m_MsrFlowNum = mfNum;}

UINT Cartridge::GetMsrFlowNo()  const     {    return (UINT)m_MsrFlowNo;}
void Cartridge::SetMsrFlowNo(UINT mfNo)       {    m_MsrFlowNo = mfNo;}

CString Cartridge::GetStrPointNum() const
{
    CString Num;
	switch(m_MsrFlowNum)
	{
	case Pn1:  Num.Format("中心點"); break;
	case Pn4:  Num.Format("  4點");   break;
	case Pn5:  Num.Format("  5點");   break;
	case Pn9:  Num.Format("  9點");   break;
	case Pn13: Num.Format(" 13點");   break;
	case Pn21: Num.Format(" 21點");   break;
	case Pn25: Num.Format(" 25點");   break;
	case Pn49: Num.Format(" 49點");   break;
	case NoPn:
	default:   Num.Format("未定義點位");
    }
	return Num;
}

CString Cartridge::GetStrColorType() const
{
    CString Color;
	switch(m_BkColor)
	{
	case White:  Color.Format("白色");   break;
	case Red:    Color.Format("紅色");   break;
	case Green:  Color.Format("綠色");   break;
	case Blue:   Color.Format("藍色");   break;
	case Dark:   Color.Format("黑色");   break;
	case Nits:   Color.Format("Nits");  break;
	case CrsTlkW:
	case CrsTlkD:
	case CrsTlk: Color.Format("CrossTalk"); break;
	case NoColor:
	default:     Color.Format("未定義色彩");
    }
	return Color;
}
//////////////////////////////////////////////////////////////////////////
//debug function
#ifdef _DEBUG

CString Cartridge::GetSetupValue() const
{
    CString str;
    CString color;
//    enum ColorType    { White = 1, Red, Green, Blue, Dark, Nits, CrsTlk, CrsTlkW, CrsTlkD};

    switch(m_BkColor)
    {
    case 1: color.Format("White"); break;
    case 2: color.Format("Red");   break;
    case 3: color.Format("Green"); break;
    case 4: color.Format("Blue");  break;
    case 5: color.Format("Dark");  break;
    case 6: color.Format("Nits");  break;
    case 7: color.Format("CrsTlk"); break;
    case 8: color.Format("CrsTlkW"); break;
    case 9: color.Format("CrsTlkD"); break;
    default: color.Format("UnDefine"); break;
    }

    str.Format("顏色項目=%s, 點位/所有: %d/%d, 區域碼=%d",\
        color, m_MsrFlowNo, m_MsrFlowNum, m_AreaCode);

    return str;
}

CString Cartridge::MsgBoxStr() const
{
    CString str;
    str.Format("AreaCode   = %d\nBackColor  = %d\nMsrFlowNo  = %d\nMsrFlowNum = %d\n%s"\
        , m_AreaCode, m_BkColor, m_MsrFlowNo, m_MsrFlowNum, Bullet::MsgBoxStr());
    
    return str;
}

#endif

