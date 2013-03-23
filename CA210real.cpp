#include "StdAfx.h"
#include "Ca210real.h"
#include <cstdlib>
#include <ctime>

#ifdef _CA210DEBUG
#define DebugCode( code_fragment ) { code_fragment }
#else
#define DebugCode( code_fragment )
#endif
//������ƪ���l�ơA�٬O�n��l�����O���СA�ҥH�s�u��ƥ��������A���i�H��b�@�P�������I
//���M�N�O���@�Ӧ@�P����¦���O�C
Ca210real::Ca210real():
ImpsbStr("1. ���uPrt Scm��v��U�ثe���ù��A�ö}�p�e�a�K�W�A�t�s������\n2. Mail�����{���]�p�̡A�ԲӴy�z�ϥιL�{�ñN���ɦs������\n�o�O�|���w����X�{�����D�C�]���Ӥ��|�o�ͪ����ءC�^"),
m_pICa200(0), m_pICa(0), m_pIProbe(0), m_pIProbeInfo(0), m_pIMemory(0)
{
    DebugCode( DBugModeBox("TRUE of Ca210real()"); )

    if (initCreatCa200())
    if (initConnectCa210())
    if (initAttachCa())
    if (initAttchProbe())
        m_caState = CA_not_yet_ZeroCal;
}

Ca210real::~Ca210real()
{
    DebugCode( DBugModeBox("TRUE of ~Ca210real()"); )
    if (isOnline())
        SetOnline(FALSE);
    m_pIMemory->DetachDispatch();        delete m_pIMemory;
    m_pIProbeInfo->DetachDispatch();    delete m_pIProbeInfo;
    m_pIProbe->DetachDispatch();        delete m_pIProbe;
    m_pICa->DetachDispatch();            delete m_pICa;
    m_pICa200->ReleaseDispatch();        delete m_pICa200;
}

BOOL Ca210real::initCreatCa200()
{
    try
    {
        if (m_pICa200 == 0)            
            m_pICa200 = new ICa200();
        m_pICa200->CreateDispatch("CA200Srvr.Ca200.1");
        return TRUE;
    }
    catch (CException* e)
    {
        MsgFrmt(e, "CreatCa200();�X���D", "1. �ˬdUSB�u�M�q��\n2. ���T�w");        
        m_pICa200->ReleaseDispatch();
        return FALSE;
    }
}

BOOL Ca210real::initConnectCa210()
{
    try
    {
        m_pICa200->m_bAutoRelease = TRUE;        
        m_pICa200->AutoConnect();
        return TRUE;
    }            
    catch (CException* e)
    {
        MsgFrmt(e, "LPDISPATCH pICa = m_pICa200->ConnectCa210();�X���D", ImpsbStr);
        m_pICa200->ReleaseDispatch();
        return FALSE;
    }
}

BOOL  Ca210real::initAttachCa()
{
    try
    {
        if (m_pICa == 0)
            m_pICa = new ICa();
        LPDISPATCH pICa(0);
        pICa = m_pICa200->GetSingleCa();
        m_pICa->AttachDispatch(pICa);
        return TRUE;
    }            
    catch (CException* e)
    {
        MsgFrmt(e, "LPDISPATCH pICa = m_pICa200->GetSingleCa();�X���D", ImpsbStr);
        m_pICa200->ReleaseDispatch();
        return FALSE;
    }
}

BOOL Ca210real::initAttchProbe()
{
    try
    {
        if (m_pIProbe     == 0) m_pIProbe     = new IProbe();
        if (m_pIProbeInfo == 0) m_pIProbeInfo = new IProbeInfo();

        LPDISPATCH pIProbe(0);
        pIProbe = m_pICa->GetSingleProbe();

        m_pIProbe->AttachDispatch(pIProbe);
        m_pIProbeInfo->AttachDispatch(pIProbe);
        return TRUE;
   }            
    catch (CException* e)
    {
        MsgFrmt(e, "LPDISPATCH pIProbe = m_pICa->GetSingleProbe();�X���D", ImpsbStr);
        m_pICa->DetachDispatch();
        m_pICa200->ReleaseDispatch();
        return FALSE;
    }
}

CaState Ca210real::CalZero()
{
    /*
    �s�u ���
    caes 11   ����ZeroCal
                �ҥ~�B�z:
                  ��MessageBox
                  �A����ZeroCal
    default   �^��FALSE  �L�k����
    */
    if (isOnline())
    {
        DebugCode( DBugModeBox("TRUE of CalZero()"); )
        int flag(0);
        do 
        {
            try
            {
                m_pICa->CalZero();
                flag = 0;
            }
            catch (CException* e)
            {
                if (flag < 1)
                    MsgFrmt(e,"�N�M���٨S���0-Cal�N����Zero Cal", "1. �N�q�������0-Cal�ɡC\n2. ���u�T�w�v");
                else
                    MsgFrmt("1. �N�q�������0-Cal�ɡC\n2. ���u�T�w�v");
                SetOnline();
                flag++;
            }
        } while (flag);
        return m_caState = CA_ZeroCalMode;
    }
    else
    {
        DebugCode( DBugModeBox("CalZero() Offline."); )
        return m_caState = CA_Offline;
    }
}

void Ca210real::LinkMemory()
{
    if (isOnline())
    {
        DebugCode( DBugModeBox("TRUE of LinkMemory()"); )
        try
        {
            if (m_pIMemory == 0)
                m_pIMemory = new IMemory();
            LPDISPATCH pMemory(0);
            pMemory = m_pICa->GetMemory();
            m_pIMemory->AttachDispatch(pMemory);
        }
        catch (CException* e)
        {
            MsgFrmt(e, "LinkMemory(pMemory);�X���D", ImpsbStr);
        }
    } 
    DebugCode( else{ DBugModeBox("FALSE of LinkMemory()"); } )
}

CaState Ca210real::Measure()
{
    CaState Mode = m_caState;
    if(isOnline())
    {
        DebugCode(  DBugModeBox("TRUE of Measure()"); )
        int flag = 0;

        do 
        {
            try
            {
                m_pICa->Measure(0);

				//�w�gZeroCal�A�ˬd�ɦ�O�_���T
                if (m_pIProbe->GetLv() < 0.01)
                    Mode = CA_ZeroCalMode;     //is0-Cal��
                else
                    Mode = CA_MsrMode;        //�wZeroCal, �ɦ쥿�T
                flag = 0;
            }
            catch (CException* e)
            {
				//MsrError
                SetOnline();
                if (m_caState == CA_not_yet_ZeroCal)  //�٨SZeroCal
                {
                    if (CalZero() == CA_Offline)
                        Mode = CA_Offline;
                    ++flag;
                }
                else
                {
                    TCHAR buf[255];
                    e->GetErrorMessage(buf, 255);
					++flag;
					if (flag > 10)
						//���ФӦh���A�ɭP����������p�C
						break;
					else
						//�b�o��������ʧ@�A���а���j�餺���F��C						
						continue;
                }
            }
        } while (flag);
    }
    return Mode;
}

MsrAiState Ca210real::MsrAI(float MsrDeviation)
{
    DebugCode( DBugModeBox("TRUE of MsrAI(float MsrDeviation)"); )
        //�Ĥ@����ƼȦs�Ŷ�  //�ŧi�~�t�ȭp��Ŷ�
    
    float XFristValue = 0.0, deltaX = 0.0,
          YFristValue = 0.0, deltaY = 0.0,
          ZFristValue = 0.0, deltaZ = 0.0, deltaAll;
    
    if ( Measure() == CA_MsrMode )
    {
        //��Ѧҭ�
        XFristValue = m_pIProbe->GetX();
        YFristValue = m_pIProbe->GetY();
        ZFristValue = m_pIProbe->GetZ();
        
        if ( Measure() == CA_MsrMode )
		{
			//�~�t�������
			deltaX = ((XFristValue-m_pIProbe->GetX()) >= 0) ? XFristValue - m_pIProbe->GetX() : m_pIProbe->GetX() - XFristValue;
			deltaY = ((YFristValue-m_pIProbe->GetY()) >= 0) ? YFristValue - m_pIProbe->GetY() : m_pIProbe->GetY() - YFristValue;
			deltaZ = ((ZFristValue-m_pIProbe->GetZ()) >= 0) ? ZFristValue - m_pIProbe->GetZ() : m_pIProbe->GetZ() - ZFristValue;
        
			deltaAll = deltaX * deltaY * deltaZ;

			if (deltaAll < MsrDeviation )    return MA_InDeviation;//���e�Ȥ�
			else                             return MA_OutDeviation;//���e�ȥ~
		}
		else
			return MA_nonMsr;
    }
    else
        return MA_nonMsr;
    //�L�Ķq���A�i��O�S�s�u������
}

void Ca210real::SetOnline(BOOL isOnline)
{
    DebugCode( DBugModeBox("TRUE of SetOnline(BOOL isOnline)"); )
    try
    {
        m_pICa->SetRemoteMode(isOnline);
    }
    catch (CException* e)
    {
        MsgFrmt(e, "�s�u/���u�X���D", ImpsbStr);
    }

    if (isOnline == FALSE) 
    {
        m_caStateTemp = m_caState;
        m_caState = CA_Offline;
    }
    else
        m_caState = m_caStateTemp;  //�u���S���D�ܡH
}

CString Ca210real::GetLcmSize()
{
    if(isOnline())
    {
        DebugCode( DBugModeBox("TRUE of GetLcmSize()"); )           
        try
        {
            if (m_LCMsize.IsEmpty())
                m_LCMsize.Format("%s", m_pIMemory->GetChannelID().Left(2));
        }
        catch (CException* e)
        {
            MsgFrmt(e, "�Ҳդؤo�j�p�]�w�X���D", ImpsbStr);
            m_LCMsize.Format("-1");
        }
    }
    else 
        m_LCMsize.Format("-1");

    return m_LCMsize;
}

CString Ca210real::GetChData()
{
    CString temp;
    if(isOnline())
    {
        try
        {
            DebugCode(
                CString str;
                str.Format("%s of GetChData()", m_Online ? "TRUE" : "FALSE");
                DBugModeBox(str);
            )
            temp.Format("%ld - %s", m_pIMemory->GetChannelNO(), m_pIMemory->GetChannelID());
        }
        catch (CException* e)
        {
            MsgFrmt(e, "�qCA-210��Channel����ƥX�ӥX���D", ImpsbStr);
        }
    }
    else
        temp.Format("�w���u - �L�W�D");
    return temp;
}

Bullet Ca210real::GetMsrData()
{
    if (isOnline())
    {
        DebugCode( DBugModeBox("TRUE of GetMsrData()"); )
        try
        {
            m_blt.i(VluK_Lv, m_pIProbe->GetLv());
            m_blt.i(VluK_Sx, m_pIProbe->GetSx());
            m_blt.i(VluK_Sy, m_pIProbe->GetSy());
            
            m_blt.i(VluK_T, m_pIProbe->GetT());
            m_blt.i(VluK_Duv, m_pIProbe->GetDuv());
            
            m_blt.i(VluK_Du, m_pIProbe->GetUd());
            m_blt.i(VluK_Dv, m_pIProbe->GetVd());
            
            m_blt.i(VluK_X, m_pIProbe->GetX());
            m_blt.i(VluK_Y, m_pIProbe->GetY());
            m_blt.i(VluK_Z, m_pIProbe->GetZ());
        }
        catch (CException* e)
        {
            MsgFrmt(e, "�qCA-210Ū���q���ȥX���D", ImpsbStr);
        }

    }
    return m_blt;
}


//////////////////////////////////////////////////////////////////////////
float Ca210real::GetRangeColor1()
{
    float clr1, clr2;
    m_pICa->GetAnalogRange(&clr1, &clr2);
    return clr1;
}

float Ca210real::GetRangeColor2()
{
    float clr1, clr2;
    m_pICa->GetAnalogRange(&clr1, &clr2);
    return clr2;
}

float Ca210real::GetRangeFAM()
{
    float FMA;
    m_pICa->GetFMAAnalogRange(&FMA);
    return FMA;
}

CString Ca210real::GetRefSx()
{
    float Lv, Sx, Sy;
    m_pIMemory->GetReferenceColor(m_pIProbe->GetId(), &Sx, &Sy, &Lv);
    CString strSx;
    strSx.Format("%1.4f", Sx);
    return strSx;
}

CString Ca210real::GetRefSy()
{
    float Lv, Sx, Sy;
    m_pIMemory->GetReferenceColor(m_pIProbe->GetId(), &Sx, &Sy, &Lv);
    CString strSy;
    strSy.Format("%1.4f", Sy);
    return strSy;
}

CString Ca210real::GetRefLv()
{
    float Lv, Sx, Sy;
    m_pIMemory->GetReferenceColor(m_pIProbe->GetId(), &Sx, &Sy, &Lv);
    CString strLv;
    strLv.Format("%f", Lv);
    return strLv;
}

CString Ca210real::GetRefProbe()
{
    long CalProbe, RefProbe, CalMode;
    m_pIMemory->GetMemoryStatus(m_pIProbe->GetNumber(), &CalProbe, &RefProbe, &CalMode);
    CString str;
    str.Format("%ld", RefProbe);
    return str;
}

CString Ca210real::GetCalProbe()
{
    long CalProbe, RefProbe, CalMode;
    m_pIMemory->GetMemoryStatus(m_pIProbe->GetNumber(), &CalProbe, &RefProbe, &CalMode);
    CString str;
    str.Format("%ld", CalProbe);
    return str;
}

CString Ca210real::GetCalMode()
{
    long CalProbe, RefProbe, CalMode;
    m_pIMemory->GetMemoryStatus(m_pIProbe->GetNumber(), &CalProbe, &RefProbe, &CalMode);
    CString str;
    str.Format("%ld", CalMode);
    return str;
}
//////////////////////////////////////////////////////////////////////////

void Ca210real::SetSynMode(SynMode SmType)
{
    m_pICa->SetSyncMode(ChooseSynMode(SmType));
}

float Ca210real::ChooseSynMode(SynMode SmType)
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

CString Ca210real::GetSynMode(SynMode SmType)
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

float Ca210real::GetSynMode()
{
    return m_pICa->GetSyncMode();
}
//////////////////////////////////////////////////////////////////////////
void Ca210real::SetDisplayMode(DisPlay DpType)
{
    m_pICa->SetDisplayMode(ChooseDisplayMode(DpType));
}

int Ca210real::ChooseDisplayMode(DisPlay DpType)
{
    return (int)DpType;
}

CString Ca210real::GetDisplayMode(DisPlay DpType)
{
    switch(DpType)
    {
    case DP_Lvxy:                return "xyLv";
    case DP_duvT:                return "duvTLv";    //return "duvT";
    case DP_Analyzer_NoDisplay:    return "RGB";        //return "Analyzer mode";
    case DP_Analyzer_Gstand:    return "RGB(G)";    //return "Analyzer mode(G)";
    case DP_Analyzer_Rstand:    return "RGB(R)";    //return "Analyzer mode(R)";
    case DP_dudv:               return "u'v'Lv'";    //return "u'v'";
    case DP_FMA:                return "FMA";
    case DP_XYZ:                return "XYZ";
    case DP_JEITA:              return "JEITA";
    default:                    return "No this Mode";
    }
}

long Ca210real::GetDisplayMode()
{
    return m_pICa->GetDisplayMode();
}
//////////////////////////////////////////////////////////////////////////

void Ca210real::SetDisplayDigits(DisDigits DdType)
{
    m_pICa->SetDisplayDigits(ChooseDisplayDigits(DdType));
}

int Ca210real::ChooseDisplayDigits(DisDigits DdType)
{
    switch(DdType)
    {
    case DD_3DisDigits: return 0;
    case DD_4DisDigits: return 1;
    default: return -1;
    }    
}

CString Ca210real::GetDisplayDigits(DisDigits DdType)
{
    switch(DdType)
    {
    case DD_3DisDigits: return "3";
    case DD_4DisDigits: return "4";
    default: return "Out of SPEC";
    }
}

long Ca210real::GetDisplayDigits()
{
    return m_pICa->GetDisplayDigits();
}
//////////////////////////////////////////////////////////////////////////
void Ca210real::SetAvgingMode(AvgMode AmType)
{
    m_pICa->SetAveragingMode(ChooseAvgingMode(AmType));
}

int Ca210real::ChooseAvgingMode(AvgMode AmType)
{
    switch(AmType)
    {
    case AM_SLOW: return 0;
    case AM_FAST: return 1;
    case AM_AUTO: return 2;
    default:      return -1;
    }    
}

CString Ca210real::GetAvgingMode(AvgMode AmType)
{
    switch(AmType)
    {
    case AM_SLOW: return "Slow";
    case AM_FAST: return "Fast";
    case AM_AUTO: return "Auto";
    default:      return "No this Mode";
    }
}

long Ca210real::GetAvgingMode()
{
    return m_pICa->GetAveragingMode();
}
//////////////////////////////////////////////////////////////////////////
void Ca210real::SetBrigUnit(BrigUnit BuType)
{
    m_pICa->SetBrightnessUnit(ChooseBrigUnit(BuType));
}

int Ca210real::ChooseBrigUnit(BrigUnit BuType)
{
    switch(BuType)
    {
    case BU_fL:   return 0;
    case BU_cdm2: return 1;
    default:      return -1;
    }    
}

CString Ca210real::GetBrigUnit(BrigUnit BuType)
{
    switch(BuType)
    {
    case BU_fL:   return "fL";
    case BU_cdm2: return "cd/m2";
    default:      return "No this Unit";
    }
}

long Ca210real::GetBrigUnit()
{
    return m_pICa->GetBrightnessUnit();
}

//////////////////////////////////////////////////////////////////////////
void Ca210real::SetCalStandard(CalStand CsType)
{
    m_pICa->SetCalStandard(ChooseCalStandard(CsType));
}

int Ca210real::ChooseCalStandard(CalStand CsType)
{
    switch(CsType)
    {
    case CS_6500K: return 1;
    case CS_9300K: return 2;
    default:       return -1;
    }
}

CString Ca210real::GetCalStandard(CalStand CsType)
{
    switch(CsType)
    {
    case CS_6500K: return "6500K";
    case CS_9300K: return "9300K";
    default:       return "Out of SPEC";
    }
}

long Ca210real::GetCalStandard()
{
    return m_pICa->GetCalStandard();
}
//////////////////////////////////////////////////////////////////////////

//�]�wĵ�i�Хܪ��зǮ榡
void Ca210real::MsgFrmt(CException* e, CString mean, CString steps)
{
    CString str;
    TCHAR buf[255];
    e->GetErrorMessage(buf, 255);
    
    str.Format("�V�|!!!�X�{ERROR!!!\n\n��t���~�T��:\n%s\n\n�ݤ����S���Y�A�N��N�O:\n�u%s�v\n\n�A�u�n��:\n%s", buf, mean, steps);
    AfxMessageBox(str);
}

void Ca210real::MsgFrmt(CString steps)
{
    CString str;
    str.Format("�A�o�b�ܡH\n%s", steps);
    AfxMessageBox(str);
}


//////////////////////////////////////////////////////////////////////////
//debug function

#ifdef _CA210DEBUG

CString Ca210real::GetSetupValue() const
{
    CString str;
    str.Format("�s�u:%d, ���:%d, ZeroCal�F�S:%d", m_Online, m_isTrue, m_isZeroCal);
    return str;
}

void Ca210real::DBugModeBox(CString str) const
{
    CString strTemp;
    strTemp.Format("%s\n%s�Ҧ�, %s", str, m_isTrue?"�u��":"����", m_Online?"�s�u":"���u");
    AfxMessageBox(strTemp);
}

#endif
