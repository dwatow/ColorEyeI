// a210sim.cpp: implementation of the Ca210sim class.
//
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Ca210sim.h"
#include <cstdlib>
#include <ctime>


//#define _CA210DEBUG

//��l��ca-210��������
Ca210sim::Ca210sim():
ImpsbStr("1. ���uPrt Scm��v��U�ثe���ù��A�ö}�p�e�a�K�W�A�t�s������\n2. Mail�����{���]�p�̡A�ԲӴy�z�ϥιL�{�ñN���ɦs������\n�o�O�|���w����X�{�����D�C�]���Ӥ��|�o�ͪ����ءC�^")
{
//    int flag = 1;
    m_pIProbe = new Bullet();
    //m_caState = CA_BeforeZeroCal;
	m_caState = CA_MsrMode;  //��������Zero Cal
}

Ca210sim::~Ca210sim()
{
    if (isOnline())
        SetOnline(FALSE);
}

const CaState Ca210sim::CalZero()
{
    /*
    �s�u ���
    caes 11   ����ZeroCal
                �ҥ~�B�z:
                  ��MessageBox
                  �A����ZeroCal
    case 10   Delay1sec ����ZeroCal���ɶ�
    default   �^��FALSE  �L�k����
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

const CaState Ca210sim::Measure()
{
    /*
    0 �S�s�u
    1 �s�u
    2 �|��Zero Cal
    3 �ɦ줣�bMEAS
    4 �q�����`
    */
    CaState Mode = m_caState;
    if(isOnline())
    {
        // Make Data for m_pIProbe;
        srand(time(NULL));
        m_pIProbe->i(VluK_Lv, (rand()%100000)/100.0);    //%3.2f
        m_pIProbe->i(VluK_Sx, (rand()%10000 +1)/10000.0);  //%1.4f
        m_pIProbe->i(VluK_Sy, (rand()%10000 +1)/10000.0);  //%1.4f
        
        m_pIProbe->i(VluK_T, rand()%1000);//%3d
        m_pIProbe->i(VluK_Duv, (rand()%100000)/10000);  //%1.4f
        
        m_pIProbe->i(VluK_Du, (rand()%100000)/10000.0);  //%1.4f
        m_pIProbe->i(VluK_Dv, (rand()%100000)/10000.0);  //%1.4f
        
        m_pIProbe->i(VluK_X, (rand()%100000)/100.0);  //%3.2f
        m_pIProbe->i(VluK_Y, (rand()%100000)/100.0);  //%3.2f
        m_pIProbe->i(VluK_Z, (rand()%100000)/100.0);  //%3.2f
    }
    return Mode;
}

const MsrAiState Ca210sim::MsrAI(const float& MsrDeviation)
{
    //�Ĥ@����ƼȦs�Ŷ�  //�ŧi�~�t�ȭp��Ŷ�
	float XFristValue = 0.0, deltaX = 0.0,
		  YFristValue = 0.0, deltaY = 0.0,
		  ZFristValue = 0.0, deltaZ = 0.0, deltaAll;
	
	if (Measure() == CA_MsrMode)
	{
		//��Ѧҭ�
         XFristValue = m_pIProbe->oFlt(VluK_X);
         YFristValue = m_pIProbe->oFlt(VluK_Y);
         ZFristValue = m_pIProbe->oFlt(VluK_Z);
		
		Measure();
		
		//�~�t�������
         deltaX = ((XFristValue-m_pIProbe->oFlt(VluK_X))>=0) ? XFristValue - m_pIProbe->oFlt(VluK_X) : m_pIProbe->oFlt(VluK_X) - XFristValue;
         deltaY = ((YFristValue-m_pIProbe->oFlt(VluK_Y))>=0) ? YFristValue - m_pIProbe->oFlt(VluK_Y) : m_pIProbe->oFlt(VluK_Y) - YFristValue;
         deltaZ = ((ZFristValue-m_pIProbe->oFlt(VluK_Z))>=0) ? ZFristValue - m_pIProbe->oFlt(VluK_Z) : m_pIProbe->oFlt(VluK_Z) - ZFristValue;
		
		
		deltaAll = deltaX * deltaY * deltaZ;
		
		if (deltaAll < MsrDeviation )    return MA_InDeviation;
		else                             return MA_OutDeviation;
	}
	else
		return MA_nonMsr;
}

void Ca210sim::SetOnline(const BOOL& isOnline)
{
	//�o�̩ǩǪ��I@@
	if (isOnline == FALSE) 
	{
		m_caStateTemp = m_caState;
		m_caState = CA_Offline;
	}
	else
		m_caState = m_caStateTemp;
}

const CString Ca210sim::GetLcmSize()
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

const CString Ca210sim::GetChData()
{
    CString temp;
    if(isOnline())
    {
        temp.Format("XX - SimCh");
    }
    else
        temp.Format("?wA��?u - �gLAW1D");
    return temp;
}

const Bullet Ca210sim::GetMsrData()
{
    if (isOnline())
    {
        m_blt.i(VluK_Lv, m_pIProbe->oFlt(VluK_Lv));
        m_blt.i(VluK_Sx, m_pIProbe->oFlt(VluK_Sx));
        m_blt.i(VluK_Sy, m_pIProbe->oFlt(VluK_Sy));

        m_blt.i(VluK_T, m_pIProbe->oFlt(VluK_T));
        m_blt.i(VluK_Duv, m_pIProbe->oFlt(VluK_Duv));

        m_blt.i(VluK_Du, m_pIProbe->oFlt(VluK_Du));  //Bullet function
        m_blt.i(VluK_Dv, m_pIProbe->oFlt(VluK_Dv));  //Bullet function

        m_blt.i(VluK_X, m_pIProbe->oFlt(VluK_X));
        m_blt.i(VluK_Y, m_pIProbe->oFlt(VluK_Y));
        m_blt.i(VluK_Z, m_pIProbe->oFlt(VluK_Z));
    }
    return m_blt;
}

//////////////////////////////////////////////////////////////////////////
const float Ca210sim::GetRangeColor1() const
{ return 2.5; }
const float Ca210sim::GetRangeColor2() const
{ return 2.5; }
const float Ca210sim::GetRangeFAM() const
{ return 2.5; }

const CString Ca210sim::GetRefSx() const
{return "0.3127"; }
const CString Ca210sim::GetRefSy() const
{ return "0.3293"; }
const CString Ca210sim::GetRefLv() const
{ return "160"; }

const CString Ca210sim::GetRefProbe() const
{ return "8115678"; }
const CString Ca210sim::GetCalProbe() const
{ return "8115678"; }
const CString Ca210sim::GetCalMode() const
{ return "11"; }
//////////////////////////////////////////////////////////////////////////
void Ca210sim::SetSynMode(const SynMode& SmType)
{ m_syncMode = SmType; }
const float Ca210sim::GetSynMode() const
{ return 3.0; }//SM_UNIV

const float Ca210sim::chooseSynMode(const SynMode& SmType) const
{
    switch(SmType)
    {
    case SM_NTSC:  return  0.0;
    case SM_PAL:   return  1.0;
    case SM_EXT:   return  2.0;
    case SM_UNIV:  return  3.0;
    case SM_INT:   return  4.0;
    default:       return -1.0;
    }
}

const CString Ca210sim::GetSynMode(const SynMode& SmType) const
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


//////////////////////////////////////////////////////////////////////////
void Ca210sim::SetDisplayMode(const DisPlay& DpType)
{ m_displayMode = DpType; }
const long Ca210sim::GetDisplayMode() const
{ return 0; }//xyLv
const int Ca210sim::chooseDisplayMode(const DisPlay& DpType) const
{ return (int)DpType; }

const CString Ca210sim::GetDisplayMode(const DisPlay& DpType) const
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
//////////////////////////////////////////////////////////////////////////
void Ca210sim::SetDisplayDigits(const DisDigits& DdType)
{ m_displayDigits = DdType; }
const long Ca210sim::GetDisplayDigits() const
{ return 1; }//DD_4DisDigits
const int Ca210sim::chooseDisplayDigits(const DisDigits& DdType) const
{
    switch(DdType)
    {
    case DD_3DisDigits: return 0;
    case DD_4DisDigits: return 1;
    default: return -1;
    }    
}

const CString Ca210sim::GetDisplayDigits(const DisDigits& DdType) const
{
    switch(DdType)
    {
    case DD_3DisDigits: return "3";
    case DD_4DisDigits: return "4";
    default: return "Out of SPEC";
    }
}
//////////////////////////////////////////////////////////////////////////
void Ca210sim::SetAvgingMode(const AvgMode& AmType)
{ m_averageMide = AmType; }
const long Ca210sim::GetAvgingMode() const
{ return 1; }//AM_FAST

const int Ca210sim::chooseAvgingMode(const AvgMode& AmType) const
{
    switch(AmType)
    {
    case AM_SLOW: return 0;
    case AM_FAST: return 1;
    case AM_AUTO: return 2;
    default:      return -1;
    }    
}

const CString Ca210sim::GetAvgingMode(const AvgMode& AmType) const
{
    switch(AmType)
    {
    case AM_SLOW: return "Slow";
    case AM_FAST: return "Fast";
    case AM_AUTO: return "Auto";
    default:      return "No this Mode";
    }
}
//////////////////////////////////////////////////////////////////////////
void Ca210sim::SetBrigUnit(const BrigUnit& BuType)
{ m_brightnessUnit = BuType; }
const long Ca210sim::GetBrigUnit() const
{ return 1; }//BU_cdm2

const int Ca210sim::chooseBrigUnit(const BrigUnit& BuType) const
{
    switch(BuType)
    {
    case BU_fL:   return 0;
    case BU_cdm2: return 1;
    default:      return -1;
    }    
}

const CString Ca210sim::GetBrigUnit(const BrigUnit& BuType) const
{
    switch(BuType)
    {
    case BU_fL:   return "fL";
    case BU_cdm2: return "cd/m2";
    default:      return "No this Unit";
    }
}
//////////////////////////////////////////////////////////////////////////
void Ca210sim::SetCalStandard(const CalStand& CsType)
{ m_calStandard = CsType; }
const long Ca210sim::GetCalStandard() const
{ return 1; }//CS_6500K

const int Ca210sim::chooseCalStandard(const CalStand& CsType) const
{
    switch(CsType)
    {
    case CS_6500K: return 1;
    case CS_9300K: return 2;
    default:       return -1;
    }
}

const CString Ca210sim::GetCalStandard(const CalStand& CsType) const
{
    switch(CsType)
    {
    case CS_6500K: return "6500K";
    case CS_9300K: return "9300K";
    default:       return "Out of SPEC";
    }
}
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//debug function

#ifdef _CA210DEBUG

const CString Ca210sim::getSetupValue() const
{
    CString str;
    str.Format("�s�u:%d, ���:%d, ZeroCal�F�S:%d", m_Online, m_isTrue, m_isZeroCal);
    return str;
}

void Ca210sim::debugMessageBox(const CString& str) const
{
    CString strTemp;
    strTemp.Format("%s\n%s�Ҧ�, %s", str, m_isTrue?"�u��":"����", m_Online?"�s�u":"���u");
    AfxMessageBox(strTemp);
}

#endif