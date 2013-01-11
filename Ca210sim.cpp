// a210sim.cpp: implementation of the Ca210sim class.
//
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

#include <cstdlib>
#include <ctime>

#include "StdAfx.h"
//#include "ColorEyeI.h"
#include "Ca210sim.h"

// #ifdef _DEBUG
// #undef THIS_FILE
// static char THIS_FILE[]=__FILE__;
// #define new DEBUG_NEW
// #endif

//#define _CA210DEBUG

//初始化ca-210為模擬機
Ca210sim::Ca210sim():
ImpsbStr("1. 按「Prt Scm鍵」抓下目前的螢幕，並開小畫家貼上，另存成圖檔\n2. Mail給此程式設計者，詳細描述使用過程並將圖檔存成附件\n這是尚未預測到出現的問題。（應該不會發生的那種。）")
{
//    int flag = 1;
    m_pIProbe = new Bullet();
    //m_caState = CA_BeforeZeroCal;
	m_caState = CA_MsrMode;  //模擬不用Zero Cal
}

Ca210sim::~Ca210sim()
{
    if (isOnline())
        SetOnline(FALSE);
}

CaState Ca210sim::CalZero()
{
    /*
    連線 實機
    caes 11   執行ZeroCal
                例外處理:
                  給MessageBox
                  再執行ZeroCal
    case 10   Delay1sec 模擬ZeroCal的時間
    default   回傳FALSE  無法執行
    */  
    if (isOnline())
    {
        Sleep(1000); //simulaction Zero-Cal time
		return m_caState = CA_ZeroCalMode;
    }
    else
    {
        return m_caState = CA_Offline;
    }
}

void Ca210sim::LinkMemory()
{
//    if (isOnline())
//    {   } 
}

CaState Ca210sim::Measure()
{
    /*
    0 沒連線
    1 連線
    2 尚未Zero Cal
    3 檔位不在MEAS
    4 量測正常
    */
    CaState Mode = m_caState;
    if(isOnline())
    {
        // Make Data for m_pIProbe;
        srand(time(NULL));
        m_pIProbe->SetLv((float)(rand()%100000)/100);    //%3.2f
        m_pIProbe->SetSx((float)(rand()%10000 +1)/(float)10000);  //%1.4f
        m_pIProbe->SetSy((float)(rand()%10000 +1)/(float)10000);  //%1.4f
        
        m_pIProbe->SetT(rand()%1000);//%3d
        m_pIProbe->SetDuv((float)(rand()%100000)/10000);  //%1.4f
        
        m_pIProbe->SetDu((float)(rand()%100000)/10000);  //%1.4f
        m_pIProbe->SetDv((float)(rand()%100000)/10000);  //%1.4f
        
        m_pIProbe->SetX((float)(rand()%100000)/100);  //%3.2f
        m_pIProbe->SetY((float)(rand()%100000)/100);  //%3.2f
        m_pIProbe->SetZ((float)(rand()%100000)/100);  //%3.2f
    }
    return Mode;
}

MsrAiState Ca210sim::MsrAI(float MsrDeviation)
{
    //第一筆資料暫存空間  //宣告誤差值計算空間
	float XFristValue = 0.0, deltaX = 0.0,
		  YFristValue = 0.0, deltaY = 0.0,
		  ZFristValue = 0.0, deltaZ = 0.0, deltaAll;
	
	if (Measure() == CA_MsrMode)
	{
		//抓參考值
         XFristValue = m_pIProbe->GetX();
         YFristValue = m_pIProbe->GetY();
         ZFristValue = m_pIProbe->GetZ();
		
		Measure();
		
		//誤差取絕對值
         deltaX = ((XFristValue-m_pIProbe->GetX())>=0) ? XFristValue - m_pIProbe->GetX() : m_pIProbe->GetX() - XFristValue;
         deltaY = ((YFristValue-m_pIProbe->GetY())>=0) ? YFristValue - m_pIProbe->GetY() : m_pIProbe->GetY() - YFristValue;
         deltaZ = ((ZFristValue-m_pIProbe->GetZ())>=0) ? ZFristValue - m_pIProbe->GetZ() : m_pIProbe->GetZ() - ZFristValue;
		
		
		deltaAll = deltaX * deltaY * deltaZ;
		
		if (deltaAll < MsrDeviation )    return MA_InDeviation;
		else                             return MA_OutDeviation;
	}
	else
		return MA_nonMsr;
}

void Ca210sim::SetOnline(BOOL isOnline)
{
	if (isOnline == FALSE) 
	{
		m_caStateTemp = m_caState;
		m_caState = CA_Offline;
	}
	else
		m_caState = m_caStateTemp;
}

CString Ca210sim::GetLcmSize()
{

//     CString str;
//     if(isOnline())
//     {
//         str.Format("%d", 14);
//         return str;
//     }
//     else 
//         str.Format("-1");
//    return str;
//////////////////////////////////////////////////////////////////////////
	if (m_LCMsize.IsEmpty())
		return "";
	else
		return m_LCMsize;
}

CString Ca210sim::GetChData()
{
    CString temp;
    if(isOnline())
    {
        temp.Format("XX - SimCh");
    }
    else
        temp.Format("?wA÷?u - μLAW1D");
    return temp;
}

Bullet Ca210sim::GetMsrData()
{
    if (isOnline())
    {
        m_blt.SetLv(m_pIProbe->GetLv());
        m_blt.SetSx(m_pIProbe->GetSx());
        m_blt.SetSy(m_pIProbe->GetSy());

        m_blt.SetT(m_pIProbe->GetT());
        m_blt.SetDuv(m_pIProbe->GetDuv());

        m_blt.SetDu(m_pIProbe->GetDu());  //Bullet function
        m_blt.SetDv(m_pIProbe->GetDv());  //Bullet function

        m_blt.SetX(m_pIProbe->GetX());
        m_blt.SetY(m_pIProbe->GetY());
        m_blt.SetZ(m_pIProbe->GetZ());
    }
    return m_blt;
}

//////////////////////////////////////////////////////////////////////////
float Ca210sim::GetRangeColor1()
{
    return 2.5;
}

float Ca210sim::GetRangeColor2()
{
    return 2.5;
}

float Ca210sim::GetRangeFAM()
{
    return 2.5;	
}

CString Ca210sim::GetRefSx()
{
    return "0.3127";
}

CString Ca210sim::GetRefSy()
{
    return "0.3293";
}

CString Ca210sim::GetRefLv()
{
    return "160";
}

CString Ca210sim::GetRefProbe()
{
    return "8115678";
}

CString Ca210sim::GetCalProbe()
{
    return "8115678";
}

CString Ca210sim::GetCalMode()
{
    return "11";
}
//////////////////////////////////////////////////////////////////////////

void Ca210sim::SetSynMode(SynMode SmType)
{
    m_syncMode = SmType;
}

float Ca210sim::ChooseSynMode(SynMode SmType)
{
    switch(SmType)
    {
    case SM_NTSC:  return 0.0;
    case SM_PAL:   return 1.0;
    case SM_EXT:   return 2.0;
    case SM_UNIV:  return 3.0;
    case SM_INT:   return 4.0;
    default:       return -1.0;
    }
}

CString Ca210sim::GetSynMode(SynMode SmType)
{
    switch(SmType)
    {
    case SM_NTSC:   return "NTSC";
    case SM_PAL:    return "PAL";
    case SM_EXT:    return "EXT";
    case SM_UNIV:   return "UNIV";
    case SM_INT:    return "INT";
    default:        return "No this Mode";
    }
}

float Ca210sim::GetSynMode()
{
	return 3.0; //SM_UNIV
}
//////////////////////////////////////////////////////////////////////////
void Ca210sim::SetDisplayMode(DisPlay DpType)
{
    m_displayMode = DpType;
}

int Ca210sim::ChooseDisplayMode(DisPlay DpType)
{
    return (int)DpType;
}

CString Ca210sim::GetDisplayMode(DisPlay DpType)
{
    switch(DpType)
    {
    case DP_Lvxy:               return "xyLv";
    case DP_duvT:               return "duvTLv";    //return "duvT";
    case DP_Analyzer_NoDisplay: return "RGB";       //return "Analyzer mode";
    case DP_Analyzer_Gstand:    return "RGB(G)";    //return "Analyzer mode(G)";
    case DP_Analyzer_Rstand:    return "RGB(R)";    //return "Analyzer mode(R)";
    case DP_dudv:               return "u'v'Lv'";   //return "u'v'";
    case DP_FMA:                return "FMA";
    case DP_XYZ:                return "XYZ";
    case DP_JEITA:              return "JEITA";
    default:                    return "No this Mode";
    }
}

long Ca210sim::GetDisplayMode()
{
	return 0;  //xyLv
}
//////////////////////////////////////////////////////////////////////////

void Ca210sim::SetDisplayDigits(DisDigits DdType)
{
    m_displayDigits = DdType;
}

int Ca210sim::ChooseDisplayDigits(DisDigits DdType)
{
    switch(DdType)
    {
    case DD_3DisDigits: return 0;
    case DD_4DisDigits: return 1;
    default: return -1;
    }    
}

CString Ca210sim::GetDisplayDigits(DisDigits DdType)
{
    switch(DdType)
    {
    case DD_3DisDigits: return "3";
    case DD_4DisDigits: return "4";
    default: return "Out of SPEC";
    }
}

long Ca210sim::GetDisplayDigits()
{
	return 1; //DD_4DisDigits
}
//////////////////////////////////////////////////////////////////////////
void Ca210sim::SetAvgingMode(AvgMode AmType)
{
    m_averageMide = AmType;
}

int Ca210sim::ChooseAvgingMode(AvgMode AmType)
{
    switch(AmType)
    {
    case AM_SLOW: return 0;
    case AM_FAST: return 1;
    case AM_AUTO: return 2;
    default:      return -1;
    }    
}

CString Ca210sim::GetAvgingMode(AvgMode AmType)
{
    switch(AmType)
    {
    case AM_SLOW: return "Slow";
    case AM_FAST: return "Fast";
    case AM_AUTO: return "Auto";
    default:      return "No this Mode";
    }
}

long Ca210sim::GetAvgingMode()
{
	return 1; //AM_FAST
}
//////////////////////////////////////////////////////////////////////////
void Ca210sim::SetBrigUnit(BrigUnit BuType)
{
    m_brightnessUnit = BuType;
}

int Ca210sim::ChooseBrigUnit(BrigUnit BuType)
{
    switch(BuType)
    {
    case BU_fL:   return 0;
    case BU_cdm2: return 1;
    default:      return -1;
    }    
}

CString Ca210sim::GetBrigUnit(BrigUnit BuType)
{
    switch(BuType)
    {
    case BU_fL:   return "fL";
    case BU_cdm2: return "cd/m2";
    default:      return "No this Unit";
    }
}

long Ca210sim::GetBrigUnit()
{
	return 1; //BU_cdm2
}

//////////////////////////////////////////////////////////////////////////
void Ca210sim::SetCalStandard(CalStand CsType)
{
    m_calStandard = CsType;
}

int Ca210sim::ChooseCalStandard(CalStand CsType)
{
    switch(CsType)
    {
    case CS_6500K: return 1;
    case CS_9300K: return 2;
    default:       return -1;
    }
}

CString Ca210sim::GetCalStandard(CalStand CsType)
{
    switch(CsType)
    {
    case CS_6500K: return "6500K";
    case CS_9300K: return "9300K";
    default:       return "Out of SPEC";
    }
}

long Ca210sim::GetCalStandard()
{
	return 1; //CS_6500K
}
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//debug function

#ifdef _CA210DEBUG

CString Ca210sim::GetSetupValue() const
{
    CString str;
    str.Format("連線:%d, 實機:%d, ZeroCal了沒:%d", m_Online, m_isTrue, m_isZeroCal);
    return str;
}

void Ca210sim::DBugModeBox(CString str) const
{
    CString strTemp;
    strTemp.Format("%s\n%s模式, %s", str, m_isTrue?"真實":"模擬", m_Online?"連線":"離線");
    AfxMessageBox(strTemp);
}

#endif