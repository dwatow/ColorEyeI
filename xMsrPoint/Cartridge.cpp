#include "stdafx.h"
#include "Cartridge.h"

/*******************************************
 *    Define PointSet Class member function  *
 *******************************************/
//繼承掉的介面
void Cartridge::SetLv(float L){    m_Data.i(VluK_Lv, L); }
void Cartridge::SetSx(float x){    m_Data.i(VluK_Sx, x); }
void Cartridge::SetSy(float y){    m_Data.i(VluK_Sy, y); }

void Cartridge::SetT(float T)        {    m_Data.i(VluK_T, T);}
void Cartridge::SetDuv(float Duv)    {    m_Data.i(VluK_Duv, Duv);}

void Cartridge::SetDu(float Du){    m_Data.i(VluK_Du, Du);}
void Cartridge::SetDv(float Dv){    m_Data.i(VluK_Dv, Dv);}

void Cartridge::SetX(float X){    m_Data.i(VluK_X, X);}
void Cartridge::SetY(float Y){    m_Data.i(VluK_Y, Y);}
void Cartridge::SetZ(float Z){    m_Data.i(VluK_Z, Z);}


void Cartridge::SetLv(CString L){    m_Data.i(VluK_Lv, L);}
void Cartridge::SetSx(CString x){    m_Data.i(VluK_Sx, x);}
void Cartridge::SetSy(CString y){    m_Data.i(VluK_Sy, y);}

void Cartridge::SetT(CString T)        {    m_Data.i(VluK_T, T);}
void Cartridge::SetDuv(CString Duv)    {    m_Data.i(VluK_Duv, Duv);}

void Cartridge::SetDu(CString Du){    m_Data.i(VluK_Du, Du);}
void Cartridge::SetDv(CString Dv){    m_Data.i(VluK_Dv, Dv);}

void Cartridge::SetX(CString X){    m_Data.i(VluK_X, X);}
void Cartridge::SetY(CString Y){    m_Data.i(VluK_Y, Y);}
void Cartridge::SetZ(CString Z){    m_Data.i(VluK_Z, Z);}


float Cartridge::GetLv() const { return m_Data.oFlt(VluK_Lv);}    CString Cartridge::GetStrLv()  const {    return m_Data.oStr(VluK_Lv);}
float Cartridge::GetSx() const { return m_Data.oFlt(VluK_Sx);}    CString Cartridge::GetStrSx()  const {    return m_Data.oStr(VluK_Sx);}
float Cartridge::GetSy() const { return m_Data.oFlt(VluK_Sy);}    CString Cartridge::GetStrSy()  const {    return m_Data.oStr(VluK_Sy);}

long  Cartridge::GetT()  const  { return m_Data.oFlt(VluK_T);}    CString Cartridge::GetStrT()    const {    return m_Data.oStr(VluK_T);}
float Cartridge::GetDuv() const { return m_Data.oFlt(VluK_Duv);}    CString Cartridge::GetStrDuv() const {    return m_Data.oStr(VluK_Duv);}

float Cartridge::GetDu() const { return m_Data.oFlt(VluK_Du);}    CString Cartridge::GetStrDu()  const {    return m_Data.oStr(VluK_Du);}
float Cartridge::GetDv() const { return m_Data.oFlt(VluK_Dv);}    CString Cartridge::GetStrDv()  const {    return m_Data.oStr(VluK_Dv);}

float Cartridge::GetX() const { return m_Data.oFlt(VluK_X);}    CString Cartridge::GetStrX()   const {    return m_Data.oStr(VluK_X);}
float Cartridge::GetY() const { return m_Data.oFlt(VluK_Y);}    CString Cartridge::GetStrY()   const {    return m_Data.oStr(VluK_Y);}
float Cartridge::GetZ() const { return m_Data.oFlt(VluK_Z);}    CString Cartridge::GetStrZ()   const {    return m_Data.oStr(VluK_Z);}

// Bullet& Cartridge::GetBullet()
// {    
// 	
// 	//     Pd.SetLv(m_fLv);                                            Pd.SetX(m_fX);
// 	//     Pd.SetSx(m_fSx);    Pd.SetT(m_lT);        Pd.SetDu(m_fDu);    Pd.SetY(m_fY);
// 	//     Pd.SetSy(m_fSy);    Pd.SetDuv(m_fDuv);    Pd.SetDv(m_fDv);    Pd.SetZ(m_fZ);
//     m_Data;    
// }

Bullet Cartridge::GetBullet() const
{    
	//     Pd.SetLv(m_fLv);                                            Pd.SetX(m_fX);
	//     Pd.SetSx(m_fSx);    Pd.SetT(m_lT);        Pd.SetDu(m_fDu);    Pd.SetY(m_fY);
	//     Pd.SetSy(m_fSy);    Pd.SetDuv(m_fDuv);    Pd.SetDv(m_fDv);    Pd.SetZ(m_fZ);
    return m_Data;    
}

void Cartridge::SetBullet(const Bullet& Pd)    
{
    m_Data = Pd;
//     SetLv(Pd.GetLv());                                                SetX(Pd.GetX());
//     SetSx(Pd.GetSx());    SetT  (Pd.GetT());        SetDu(Pd.GetDu());    SetY(Pd.GetY());
//     SetSy(Pd.GetSy());    SetDuv(Pd.GetDuv());    SetDv(Pd.GetDv());    SetZ(Pd.GetZ());
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

UINT Cartridge::GetOrigSeqc() const              { return m_OrigSeqc;    }
void Cartridge::SetOrigSeqc(UINT Orig)           { m_OrigSeqc = Orig;    }


ColorType Cartridge::GetBackColor() const        { return m_BkColor;     }
void      Cartridge::SetBackColor(ColorType clr) { m_BkColor = clr;      }

void Cartridge::SetArea(UINT ac)                 { m_AreaCode = ac;      }
UINT Cartridge::GetArea() const                  { return m_AreaCode;    } 

PointNum Cartridge::GetMsrFlowNum() const        { return m_MsrFlowNum;  }
void Cartridge::SetMsrFlowNum(PointNum mfNum)    { m_MsrFlowNum = mfNum; }

UINT Cartridge::GetMsrFlowNo()  const            { return m_MsrFlowNo;   }
void Cartridge::SetMsrFlowNo(UINT mfNo)          { m_MsrFlowNo = mfNo;   }

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
	case PnGamma: Num.Format("Gamma");   break;
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
	case JNDX:
	case JND:    Color.Format("JND"); break;
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
    case White: color.Format("White"); break;
    case Red: color.Format("Red");   break;
    case Green: color.Format("Green"); break;
    case Blue: color.Format("Blue");  break;
    case Dark: color.Format("Dark");  break;
    case Nits: color.Format("Nits");  break;
    case CrsTlk: color.Format("CrsTlk"); break;
    case CrsTlkW: color.Format("CrsTlkW"); break;
    case CrsTlkD: color.Format("CrsTlkD"); break;
	case JND:     color.Format("JND"); break;
	case JNDX:     color.Format("JNDX"); break;
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
        , m_AreaCode, m_BkColor, m_MsrFlowNo, m_MsrFlowNum, m_Data.showStr());
    
    return str;
}

#endif

