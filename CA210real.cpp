#include "StdAfx.h"
#include "Ca210real.h"
#include <cstdlib>
#include <ctime>

#ifdef _CA210DEBUG
#define DebugCode( code_fragment ) { code_fragment }
#else
#define DebugCode( code_fragment )
#endif
//虛擬函數的初始化，還是要初始父類別指標，所以連線函數必須移走，不可以放在共同的部份！
//不然就是做一個共同的基礎類別。
Ca210real::Ca210real():
ImpsbStr("1. 按「Prt Scm鍵」抓下目前的螢幕，並開小畫家貼上，另存成圖檔\n2. Mail給此程式設計者，詳細描述使用過程並將圖檔存成附件\n這是尚未預測到出現的問題。（應該不會發生的那種。）"),
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

const BOOL Ca210real::initCreatCa200()
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
        MsgFrmt(e, "CreatCa200();出問題", "1. 檢查USB線和量筒\n2. 按確定");        
        m_pICa200->ReleaseDispatch();
        return FALSE;
    }
}

const BOOL Ca210real::initConnectCa210()
{
    try
    {
        m_pICa200->m_bAutoRelease = TRUE;        
        m_pICa200->AutoConnect();
        return TRUE;
    }            
    catch (CException* e)
    {
        MsgFrmt(e, "LPDISPATCH pICa = m_pICa200->ConnectCa210();出問題", ImpsbStr);
        m_pICa200->ReleaseDispatch();
        return FALSE;
    }
}

const BOOL  Ca210real::initAttachCa()
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
        MsgFrmt(e, "LPDISPATCH pICa = m_pICa200->GetSingleCa();出問題", ImpsbStr);
        m_pICa200->ReleaseDispatch();
        return FALSE;
    }
}

const BOOL Ca210real::initAttchProbe()
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
        MsgFrmt(e, "LPDISPATCH pIProbe = m_pICa->GetSingleProbe();出問題", ImpsbStr);
        m_pICa->DetachDispatch();
        m_pICa200->ReleaseDispatch();
        return FALSE;
    }
}

const CaState Ca210real::CalZero()
{
    /*
    連線 實機
    caes 11   執行ZeroCal
                例外處理:
                  給MessageBox
                  再執行ZeroCal
    default   回傳FALSE  無法執行
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
                    MsgFrmt(e,"將套筒還沒轉至0-Cal就執行Zero Cal", "1. 將量測筒轉至0-Cal檔。\n2. 按「確定」");
                else
                    MsgFrmt("1. 將量測筒轉至0-Cal檔。\n2. 按「確定」");
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
            MsgFrmt(e, "LinkMemory(pMemory);出問題", ImpsbStr);
        }
    } 
    DebugCode( else{ DBugModeBox("FALSE of LinkMemory()"); } )
}

const CaState Ca210real::Measure()
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

				//已經ZeroCal，檢查檔位是否正確
                if (m_pIProbe->GetLv() < 0.01)
                    Mode = CA_ZeroCalMode;     //is0-Cal檔
                else
                    Mode = CA_MsrMode;        //已ZeroCal, 檔位正確
                flag = 0;
            }
            catch (CException* e)
            {
				//MsrError
                SetOnline();
                if (m_caState == CA_not_yet_ZeroCal)  //還沒ZeroCal
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
						//重覆太多次，導致類當機的情況。
						break;
					else
						//在這不做任何動作，重覆執行迴圈內的東西。						
						continue;
                }
            }
        } while (flag);
    }
    return Mode;
}

const MsrAiState Ca210real::MsrAI(const float& MsrDeviation)
{
    DebugCode( DBugModeBox("TRUE of MsrAI(float MsrDeviation)"); )
        //第一筆資料暫存空間  //宣告誤差值計算空間
    
    float XFristValue = 0.0, deltaX = 0.0,
          YFristValue = 0.0, deltaY = 0.0,
          ZFristValue = 0.0, deltaZ = 0.0, deltaAll;
    
    if ( Measure() == CA_MsrMode )
    {
        //抓參考值
        XFristValue = m_pIProbe->GetX();
        YFristValue = m_pIProbe->GetY();
        ZFristValue = m_pIProbe->GetZ();
        
        if ( Measure() == CA_MsrMode )
		{
			//誤差取絕對值
			deltaX = ((XFristValue-m_pIProbe->GetX()) >= 0) ? XFristValue - m_pIProbe->GetX() : m_pIProbe->GetX() - XFristValue;
			deltaY = ((YFristValue-m_pIProbe->GetY()) >= 0) ? YFristValue - m_pIProbe->GetY() : m_pIProbe->GetY() - YFristValue;
			deltaZ = ((ZFristValue-m_pIProbe->GetZ()) >= 0) ? ZFristValue - m_pIProbe->GetZ() : m_pIProbe->GetZ() - ZFristValue;
        
			deltaAll = deltaX * deltaY * deltaZ;

			if (deltaAll < MsrDeviation )    return MA_InDeviation;//門檻值內
			else                             return MA_OutDeviation;//門檻值外
		}
		else
			return MA_nonMsr;
    }
    else
        return MA_nonMsr;
    //無效量測，可能是沒連線之類的
}

void Ca210real::SetOnline(const BOOL& isOnline)
{
    DebugCode( DBugModeBox("TRUE of SetOnline(BOOL isOnline)"); )
    try
    {
        m_pICa->SetRemoteMode(isOnline);
    }
    catch (CException* e)
    {
        MsgFrmt(e, "連線/離線出問題", ImpsbStr);
    }

    if (isOnline == FALSE) 
    {
        m_caStateTemp = m_caState;
        m_caState = CA_Offline;
    }
    else
        m_caState = m_caStateTemp;  //真的沒問題嗎？
}

const CString Ca210real::GetLcmSize()
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
            MsgFrmt(e, "模組尺寸大小設定出問題", ImpsbStr);
            m_LCMsize.Format("-1");
        }
    }
    else 
        m_LCMsize.Format("-1");

    return m_LCMsize;
}

const CString Ca210real::GetChData()// const
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
            MsgFrmt(e, "從CA-210抓Channel的資料出來出問題", ImpsbStr);
        }
    }
    else
        temp.Format("已離線 - 無頻道");
    return temp;
}

const Bullet Ca210real::GetMsrData()
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
            MsgFrmt(e, "從CA-210讀取量測值出問題", ImpsbStr);
        }

    }
    return m_blt;
}


//////////////////////////////////////////////////////////////////////////
const float Ca210real::GetRangeColor1() const
{
    float clr1, clr2;
    m_pICa->GetAnalogRange(&clr1, &clr2);
    return clr1;
}

const float Ca210real::GetRangeColor2() const
{
    float clr1, clr2;
    m_pICa->GetAnalogRange(&clr1, &clr2);
    return clr2;
}

const float Ca210real::GetRangeFAM() const
{
    float FMA;
    m_pICa->GetFMAAnalogRange(&FMA);
    return FMA;
}

const CString Ca210real::GetRefSx() const
{
    float Lv, Sx, Sy;
    m_pIMemory->GetReferenceColor(m_pIProbe->GetId(), &Sx, &Sy, &Lv);
    CString strSx;
    strSx.Format("%1.4f", Sx);
    return strSx;
}

const CString Ca210real::GetRefSy() const
{
    float Lv, Sx, Sy;
    m_pIMemory->GetReferenceColor(m_pIProbe->GetId(), &Sx, &Sy, &Lv);
    CString strSy;
    strSy.Format("%1.4f", Sy);
    return strSy;
}

const CString Ca210real::GetRefLv() const
{
    float Lv, Sx, Sy;
    m_pIMemory->GetReferenceColor(m_pIProbe->GetId(), &Sx, &Sy, &Lv);
    CString strLv;
    strLv.Format("%f", Lv);
    return strLv;
}

const CString Ca210real::GetRefProbe() const
{
    long CalProbe, RefProbe, CalMode;
    m_pIMemory->GetMemoryStatus(m_pIProbe->GetNumber(), &CalProbe, &RefProbe, &CalMode);
    CString str;
    str.Format("%ld", RefProbe);
    return str;
}

const CString Ca210real::GetCalProbe() const
{
    long CalProbe, RefProbe, CalMode;
    m_pIMemory->GetMemoryStatus(m_pIProbe->GetNumber(), &CalProbe, &RefProbe, &CalMode);
    CString str;
    str.Format("%ld", CalProbe);
    return str;
}

const CString Ca210real::GetCalMode() const
{
    long CalProbe, RefProbe, CalMode;
    m_pIMemory->GetMemoryStatus(m_pIProbe->GetNumber(), &CalProbe, &RefProbe, &CalMode);
    CString str;
    str.Format("%ld", CalMode);
    return str;
}
//////////////////////////////////////////////////////////////////////////

void Ca210real::SetSynMode(const SynMode& SmType)
{
    m_pICa->SetSyncMode(ChooseSynMode(SmType));
}

const float Ca210real::ChooseSynMode(const SynMode& SmType) const
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

const CString Ca210real::GetSynMode(const SynMode& SmType) const
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

const float Ca210real::GetSynMode() const
{
    return m_pICa->GetSyncMode();
}
//////////////////////////////////////////////////////////////////////////
void Ca210real::SetDisplayMode(const DisPlay& DpType)
{
    m_pICa->SetDisplayMode(ChooseDisplayMode(DpType));
}

const int Ca210real::ChooseDisplayMode(const DisPlay& DpType) const
{
    return (int)DpType;
}

const CString Ca210real::GetDisplayMode(const DisPlay& DpType) const
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

const long Ca210real::GetDisplayMode() const
{
    return m_pICa->GetDisplayMode();
}
//////////////////////////////////////////////////////////////////////////

void Ca210real::SetDisplayDigits(const DisDigits& DdType)
{
    m_pICa->SetDisplayDigits(ChooseDisplayDigits(DdType));
}

const int Ca210real::ChooseDisplayDigits(const DisDigits& DdType) const
{
    switch(DdType)
    {
    case DD_3DisDigits: return 0;
    case DD_4DisDigits: return 1;
    default: return -1;
    }    
}

const CString Ca210real::GetDisplayDigits(const DisDigits& DdType) const
{
    switch(DdType)
    {
    case DD_3DisDigits: return "3";
    case DD_4DisDigits: return "4";
    default: return "Out of SPEC";
    }
}

const long Ca210real::GetDisplayDigits() const
{
    return m_pICa->GetDisplayDigits();
}
//////////////////////////////////////////////////////////////////////////
void Ca210real::SetAvgingMode(const AvgMode& AmType)
{
    m_pICa->SetAveragingMode(ChooseAvgingMode(AmType));
}

const int Ca210real::ChooseAvgingMode(const AvgMode& AmType) const
{
    switch(AmType)
    {
    case AM_SLOW: return 0;
    case AM_FAST: return 1;
    case AM_AUTO: return 2;
    default:      return -1;
    }    
}

const CString Ca210real::GetAvgingMode(const AvgMode& AmType) const
{
    switch(AmType)
    {
    case AM_SLOW: return "Slow";
    case AM_FAST: return "Fast";
    case AM_AUTO: return "Auto";
    default:      return "No this Mode";
    }
}

const long Ca210real::GetAvgingMode() const
{
    return m_pICa->GetAveragingMode();
}
//////////////////////////////////////////////////////////////////////////
void Ca210real::SetBrigUnit(const BrigUnit& BuType)
{
    m_pICa->SetBrightnessUnit(ChooseBrigUnit(BuType));
}

const int Ca210real::ChooseBrigUnit(const BrigUnit& BuType) const
{
    switch(BuType)
    {
    case BU_fL:   return 0;
    case BU_cdm2: return 1;
    default:      return -1;
    }    
}

const CString Ca210real::GetBrigUnit(const BrigUnit& BuType) const
{
    switch(BuType)
    {
    case BU_fL:   return "fL";
    case BU_cdm2: return "cd/m2";
    default:      return "No this Unit";
    }
}

const long Ca210real::GetBrigUnit() const
{
    return m_pICa->GetBrightnessUnit();
}

//////////////////////////////////////////////////////////////////////////
void Ca210real::SetCalStandard(const CalStand& CsType)
{
    m_pICa->SetCalStandard(ChooseCalStandard(CsType));
}

const int Ca210real::ChooseCalStandard(const CalStand& CsType) const
{
    switch(CsType)
    {
    case CS_6500K: return  1;
    case CS_9300K: return  2;
    default:       return -1;
    }
}

const CString Ca210real::GetCalStandard(const CalStand& CsType) const
{
    switch(CsType)
    {
    case CS_6500K: return "6500K";
    case CS_9300K: return "9300K";
    default:       return "Out of SPEC";
    }
}

const long Ca210real::GetCalStandard() const
{
    return m_pICa->GetCalStandard();
}
//////////////////////////////////////////////////////////////////////////

//設定警告標示的標準格式
void Ca210real::MsgFrmt(CException* e, const CString& mean, const CString& steps)
{
    CString str;
    TCHAR buf[255];
    e->GetErrorMessage(buf, 255);
    
    str.Format("糟糕!!!出現ERROR!!!\n\n原廠錯誤訊息:\n%s\n\n看不懂沒關係，意思就是:\n「%s」\n\n你只要做:\n%s", buf, mean, steps);
    AfxMessageBox(str);
}

void Ca210real::MsgFrmt(const CString& steps)
{
    CString str;
    str.Format("你發呆嗎？\n%s", steps);
    AfxMessageBox(str);
}


//////////////////////////////////////////////////////////////////////////
//debug function

#ifdef _CA210DEBUG

CString Ca210real::GetSetupValue() const
{
    CString str;
    str.Format("連線:%d, 實機:%d, ZeroCal了沒:%d", m_Online, m_isTrue, m_isZeroCal);
    return str;
}

void Ca210real::DBugModeBox(const CString& str) const
{
    CString strTemp;
    strTemp.Format("%s\n%s模式, %s", str, m_isTrue?"真實":"模擬", m_Online?"連線":"離線");
    AfxMessageBox(strTemp);
}

#endif
