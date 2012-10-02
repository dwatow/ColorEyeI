#include "StdAfx.h"
#include "CA210.h"
#include <cstdlib>
#include <ctime>


Ca210::Ca210(BOOL tr):
ImpsbStr("1. 按「Prt Scm鍵」抓下目前的螢幕，並開小畫家貼上，另存成圖檔\n2. Mail給此程式設計者，詳細描述使用過程並將圖檔存成附件\n這是尚未預測到出現的問題。（應該不會發生的那種。）"),
m_isSuccess(TRUE)
{
    /*
    初始化ca-210
    設定是否為模擬機
    */
//    m_CA210DEBUGFlag = TRUE;
//    m_CA210DEBUGFlag = FALSE;
    m_isTrue = tr;  //TRUE接實體儀器, FALSE模擬儀器
    if (m_isTrue)
    {
#ifdef _CA210DEBUG
        DBugModeBox("TRUE of Ca210(BOOL tr)");
#endif
		int flag = 1;
		     if (!CreatCa200())   AfxMessageBox("CreatCa200() ERROR!!");
		else if (!ConnectCa210()) AfxMessageBox("ConnectCa210() ERROR!!");
		else if (!AttachCa())     AfxMessageBox("AttachCa() ERROR!!");
		else if (!AttchProbe())   AfxMessageBox("AttchProbe() ERROR!!");            
		else
			m_isZeroCal = FALSE;
    }
    else
    {
        //模擬機
#ifdef _CA210DEBUG
        DBugModeBox("FALSE of Ca210(BOOL tr)");
#endif
        m_isZeroCal = FALSE;
//        SetOnline(FALSE);
    }
}

Ca210::~Ca210()
{
    if (m_isTrue)
    {
#ifdef _CA210DEBUG
        DBugModeBox("TRUE of ~Ca210()");
#endif
        if (GetOnline())
            SetOnline(FALSE);
        m_pIMemory->DetachDispatch();		delete m_pIMemory;
		m_pIProbeInfo->DetachDispatch();	delete m_pIProbeInfo;
        m_pIProbe->DetachDispatch();		delete m_pIProbe;
        m_pICa->DetachDispatch();			delete m_pICa;
        m_pICa200->ReleaseDispatch();		delete m_pICa200;
    }
}

BOOL Ca210::CreatCa200()
{
	BOOL m_isSuccess(TRUE);
	try
	{
		m_pICa200 = new ICa200();
		m_pICa200->CreateDispatch("CA200Srvr.Ca200.1");
		m_pICa200->m_bAutoRelease = TRUE;		
	}
	catch (CException* e)
	{
		MsgFrmt(e, "CreatCa200();出問題", "1. 檢查USB線和量筒\n2. 按確定");
		m_pICa200->ReleaseDispatch();		
		m_isSuccess = FALSE;
	}
	return m_isSuccess;
}

BOOL Ca210::ConnectCa210()
{
	BOOL m_isSuccess(TRUE);
	try
	{
		m_pICa200->AutoConnect();
	}            
	catch (CException* e)
	{
		MsgFrmt(e, "LPDISPATCH pICa = m_pICa200->ConnectCa210();出問題", ImpsbStr);
		m_pICa200->ReleaseDispatch();
		m_isSuccess = FALSE;
	}
	
	return m_isSuccess;
}

BOOL  Ca210::AttachCa()
{
	LPDISPATCH pICa;
	BOOL m_isSuccess(TRUE);
	try
	{
		m_pICa = new ICa();
		pICa = m_pICa200->GetSingleCa();
		m_pICa->AttachDispatch(pICa);
	}            
	catch (CException* e)
	{
		MsgFrmt(e, "LPDISPATCH pICa = m_pICa200->GetSingleCa();出問題", ImpsbStr);
		pICa = 0;
		m_pICa200->ReleaseDispatch();
		m_isSuccess = FALSE;
	}

	return m_isSuccess;
}

BOOL Ca210::AttchProbe()
{
	LPDISPATCH pIProbe;
	BOOL m_isSuccess;
	try
	{
		m_pIProbe = new IProbe();
		m_pIProbeInfo = new IProbeInfo();
		pIProbe = m_pICa->GetSingleProbe();
		m_pIProbe->AttachDispatch(pIProbe);
		m_pIProbeInfo->AttachDispatch(pIProbe);
	}            
	catch (CException* e)
	{
		MsgFrmt(e, "LPDISPATCH pIProbe = m_pICa->GetSingleProbe();出問題", ImpsbStr);
		pIProbe = 0;
		m_pICa->DetachDispatch();
		m_pICa200->ReleaseDispatch();
		m_isSuccess = FALSE;
	}
	
	return m_isSuccess;
}

BOOL Ca210::CalZero(int flag)
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
    if(m_Online && m_isTrue)
    {
#ifdef _CA210DEBUG
        DBugModeBox("TRUE of CalZero()");
#endif
         do 
         {
            try
            {
                m_pICa->CalZero();
                m_isZeroCal = TRUE;
                flag = 0;
            }
            catch (CException* e)
            {
                if (flag < 1)
                    MsgFrmt(e,"將套筒還沒轉至0-Cal就執行Zero Cal", "1. 將量測筒轉至0-Cal檔。\n2. 按「確定」");
                else
                    MsgFrmt("1. 將量測筒轉至0-Cal檔。\n2. 按「確定」");
				SetOnline(TRUE);
				flag++;
            }
         } while (flag);
        return TRUE;
    }
    else if(m_Online && !m_isTrue)
    {
        //模擬的
#ifdef _CA210DEBUG
        DBugModeBox("FALSE of CalZero()");
#endif

        m_isZeroCal = TRUE;
        Sleep(1000);
        return TRUE;
    }
    else
    {
#ifdef _CA210DEBUG
        DBugModeBox("TRUE of CalZero()");
#endif
        return FALSE;
    }
}

void Ca210::LinkMemory()
{
    if (m_isTrue && m_Online)
    {
#ifdef _CA210DEBUG
        DBugModeBox("TRUE of LinkMemory()");
#endif
        try
        {
			LPDISPATCH pMemory;

			m_pIMemory = new IMemory();
			pMemory = m_pICa->GetMemory();
			m_pIMemory->AttachDispatch(pMemory);
        }
        catch (CException* e)
        {
            MsgFrmt(e, "LinkMemory(pMemory);出問題", ImpsbStr);
        }
    } 
#ifdef _CA210DEBUG
    else
    {
        DBugModeBox("FALSE of LinkMemory()");
    }
#endif
}

UINT Ca210::Measure()
{
    /*
    0 沒連線
    1 連線
    2 尚未Zero Cal
    3 檔位不在MEAS
    4 量測正常
    */
    UINT Mode = m_Online;
    if(m_Online && m_isTrue)
    {
#ifdef _CA210DEBUG
        DBugModeBox("TRUE of Measure()");
#endif
        int flag = 0;
    
            do 
            {
                try
                {
                    m_pICa->Measure(0);
                    if (m_pIProbe->GetLv() < 0.01)
                        Mode = 3;
                    else
                        Mode = 4;
                    flag = 0;
                }
                catch (CException* e)
                {
					SetOnline(TRUE);
					if (!m_isZeroCal)
					{
						Mode = 2;
						break;
					}
					else
					{
                    TCHAR buf[255];
                    e->GetErrorMessage(buf, 255);

//                     MsgFrmt(e, "量測出問題", "剛剛是不是不正常使用量筒（像是搖它或對著強光源...之類的）\n否則，不要移動量筒按確定重量剛剛的點");
//                     flag++;
                    continue;
					}
                }
            } while (flag);
    }
    return Mode;
}

BOOL Ca210::SetOnline(BOOL isOnline)
{
    if (m_isTrue)
    {
#ifdef _CA210DEBUG
        DBugModeBox("TRUE of SetOnline(BOOL isOnline)");
#endif
        try
        {
            m_pICa->SetRemoteMode(isOnline);
        }
        catch (CException* e)
        {
            MsgFrmt(e, "連線/離線出問題", ImpsbStr);
        }
    }
    m_Online = isOnline;
    return isOnline;
}

BOOL Ca210::GetOnline() const
{
    return m_Online;
}

CString Ca210::GetLcmSize()
{
    CString str;
    if (m_Online)
    {
         if (m_isTrue)
         {
#ifdef _CA210DEBUG
             DBugModeBox("TRUE of GetLcmSize()");
#endif
             try
             {
                 str.Format("%s", m_pIMemory->GetChannelID().Left(2));
             }
             catch (CException* e)
             {
                 MsgFrmt(e, "模組尺寸大小設定出問題", ImpsbStr);
                 return "-1";
             }
             return str;
         }
         else
         {
#ifdef _CA210DEBUG
             DBugModeBox("TRUE of GetLcmSize()");
#endif
             str.Format("24");
         }
    }
    else 
        str.Format("-1");
        return str;
}

CString Ca210::GetChData()
{
    CString temp;
    if (m_Online)
    {
        try
        {
            CString str;
            str.Format("%s of GetChData()", m_Online ? "TRUE" : "FALSE");
#ifdef _CA210DEBUG
            DBugModeBox(str);
#endif
            temp.Format(m_isTrue ? "%ld - %s", m_pIMemory->GetChannelNO(), m_pIMemory->GetChannelID() : "XX - 模擬頻道");
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

Bullet Ca210::GetMsrData()
{

    if (m_Online)
    {
        if (m_isTrue)
        {
#ifdef _CA210DEBUG
            DBugModeBox("TRUE of GetMsrData()");
#endif

            try
            {
                m_blt.SetLv(m_pIProbe->GetLv());
                m_blt.SetSx(m_pIProbe->GetSx());
                m_blt.SetSy(m_pIProbe->GetSy());
                
                m_blt.SetT(m_pIProbe->GetT());
                m_blt.SetDuv(m_pIProbe->GetDuv());
                
                m_blt.SetDu(m_pIProbe->GetUd());
                m_blt.SetDv(m_pIProbe->GetVd());
                
                m_blt.SetX(m_pIProbe->GetX());
                m_blt.SetY(m_pIProbe->GetY());
                m_blt.SetZ(m_pIProbe->GetZ());
            }
            catch (CException* e)
            {
                MsgFrmt(e, "從CA-210讀取量測值出問題", ImpsbStr);
            }

        }
        else
        {
#ifdef _CA210DEBUG
            DBugModeBox("FALSE of GetMsrData()");
#endif
            srand(time(NULL));
            m_blt.SetLv((float)(rand()%100000)/100);    //%3.2f
            m_blt.SetSx((float)(rand()%10000 +1)/(float)10000);  //%1.4f
            m_blt.SetSy((float)(rand()%10000 +1)/(float)10000);  //%1.4f
            
            m_blt.SetT(rand()%1000);//%3d
            m_blt.SetDuv((float)(rand()%100000)/10000);  //%1.4f
            
            m_blt.SetDu((float)(rand()%100000)/10000);  //%1.4f
            m_blt.SetDv((float)(rand()%100000)/10000);  //%1.4f
            
            m_blt.SetX((float)(rand()%100000)/100);  //%3.2f
            m_blt.SetY((float)(rand()%100000)/100);  //%3.2f
            m_blt.SetZ((float)(rand()%100000)/100);  //%3.2f
        }
    }
    return m_blt;
}

CString Ca210::OutData()
{
    CString Lv, SX, SY;
    CString T, Duv;
    CString Du, Dv;
    CString X, Y, Z;

    if (m_Online)
    {
#ifdef _CA210DEBUG
        DBugModeBox("TRUE of OutData()");
#endif
        try
        {
            Lv.Format("%3.2f", m_blt.GetLv());//Lv
            SX.Format("%1.4f", m_blt.GetSx());//Small x
            SY.Format("%1.4f", m_blt.GetSy());//Small y
            
            T.Format("%3d°", m_blt.GetT());//T
            Duv.Format("%1.4f", m_blt.GetDuv());//duv
            
            Du.Format("%1.4f", m_blt.GetDu());//du
            Dv.Format("%1.4f", m_blt.GetDv());//dv
            
            X.Format("%3.2f", m_blt.GetX());//X
            Y.Format("%3.2f", m_blt.GetY());//Y
            Z.Format("%3.2f", m_blt.GetZ());//Z
        }
        catch (CException* e)
        {
            MsgFrmt(e, "從CA-210讀取量測值出問題", ImpsbStr);
        }
    }    
    else
    {
        Lv.Format("離線了");//Lv
        SX.Format("離線了");//Small x
        SY.Format("離線了");//Small y
        
        T.Format("離線了");//T
        Duv.Format("離線了");//duv
        
        Du.Format("離線了");//du
        Dv.Format("離線了");//dv
        
        X.Format("離線了");//X
        Y.Format("離線了");//Y
        Z.Format("離線了");//Z

    } 
    return " Lv =" + Lv + "     \n" 
         + "  x =" + SX + "     \n" 
         + "  y =" + SY + "     \n" 
         + "  T =" +  T + "     \n" 
         + "Δuv=" + Duv + "     \n" 
         + " u' =" + Du + "     \n"
         + " v' =" + Dv + "     \n"
         + "  X =" +  X + "     \n"
         + "  Y =" +  Y + "     \n"
         + "  Z =" +  Z;
}

float Ca210::GetRangeColor1()
{
	float clr1, clr2;
	m_pICa->GetAnalogRange(&clr1, &clr2);
	return clr1;
}

float Ca210::GetRangeColor2()
{
	float clr1, clr2;
	m_pICa->GetAnalogRange(&clr1, &clr2);
	return clr2;
}

float Ca210::GetRangeFAM()
{
	float FMA;
	m_pICa->GetFMAAnalogRange(&FMA);
	return FMA;
}

CString Ca210::GetRefSx()
{
	float Lv, Sx, Sy;
	m_pIMemory->GetReferenceColor(m_pIProbe->GetId(), &Sx, &Sy, &Lv);
	CString strSx;
	strSx.Format("%f", Sx);
	return strSx;
}

CString Ca210::GetRefSy()
{
	float Lv, Sx, Sy;
	m_pIMemory->GetReferenceColor(m_pIProbe->GetId(), &Sx, &Sy, &Lv);
	CString strSy;
	strSy.Format("%f", Sy);
	return strSy;
}

CString Ca210::GetRefLv()
{
	float Lv, Sx, Sy;
	m_pIMemory->GetReferenceColor(m_pIProbe->GetId(), &Sx, &Sy, &Lv);
	CString strLv;
	strLv.Format("%f", Lv);
	return strLv;
}

CString Ca210::GetRefProbe()
{
	long CalProbe, RefProbe, CalMode;
	m_pIMemory->GetMemoryStatus(m_pIProbe->GetNumber(), &CalProbe, &RefProbe, &CalMode);
	CString str;
	str.Format("%ld", RefProbe);
	return str;
}

CString Ca210::GetCalProbe()
{
	long CalProbe, RefProbe, CalMode;
	m_pIMemory->GetMemoryStatus(m_pIProbe->GetNumber(), &CalProbe, &RefProbe, &CalMode);
	CString str;
	str.Format("%ld", CalProbe);
	return str;
}

CString Ca210::GetCalMode()
{
	long CalProbe, RefProbe, CalMode;
	m_pIMemory->GetMemoryStatus(m_pIProbe->GetNumber(), &CalProbe, &RefProbe, &CalMode);
	CString str;
	str.Format("%ld", CalMode);
	return str;
}
//////////////////////////////////////////////////////////////////////////

void Ca210::SetSynMode(SynMode SmType)
{
	m_pICa->SetSyncMode(ChooseSynMode(SmType));
}

float Ca210::ChooseSynMode(SynMode SmType)
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

CString Ca210::GetSynMode(SynMode SmType)
{
	switch(SmType)
	{
	case SM_NTSC:	return "NTSC";
	case SM_PAL:	return "PAL";
	case SM_EXT:	return "EXT";
	case SM_UNIV:	return "UNIV";
	case SM_INT:	return "INT";
	default:        return "No this Mode";
	}
}

float Ca210::GetSynMode()
{
    return m_pICa->GetSyncMode();
}
//////////////////////////////////////////////////////////////////////////
void Ca210::SetDisplayMode(DisPlay DpType)
{
	m_pICa->SetDisplayMode(ChooseDisplayMode(DpType));
}

int Ca210::ChooseDisplayMode(DisPlay DpType)
{
	return (int)DpType;
}

CString Ca210::GetDisplayMode(DisPlay DpType)
{
	switch(DpType)
	{
	case DP_Lvxy:	            return "xyLv";
	case DP_duvT:	            return "duvTLv";	//return "duvT";
	case DP_Analyzer_NoDisplay:	return "RGB";		//return "Analyzer mode";
	case DP_Analyzer_Gstand:	return "RGB(G)";	//return "Analyzer mode(G)";
	case DP_Analyzer_Rstand:    return "RGB(R)";	//return "Analyzer mode(R)";
	case DP_dudv:               return "u'v'Lv'";	//return "u'v'";
	case DP_FMA:                return "FMA";
	case DP_XYZ:                return "XYZ";
	case DP_JEITA:              return "JEITA";
	default:                    return "No this Mode";
	}
}

long Ca210::GetDisplayMode()
{
	return m_pICa->GetDisplayMode();
}
//////////////////////////////////////////////////////////////////////////

void Ca210::SetDisplayDigits(DisDigits DdType)
{
	m_pICa->SetDisplayDigits(ChooseDisplayDigits(DdType));
}

int Ca210::ChooseDisplayDigits(DisDigits DdType)
{
	switch(DdType)
	{
	case DD_3DisDigits: return 0;
	case DD_4DisDigits: return 1;
	default: return -1;
	}	
}

CString Ca210::GetDisplayDigits(DisDigits DdType)
{
	switch(DdType)
	{
	case DD_3DisDigits: return "3";
	case DD_4DisDigits: return "4";
	default: return "Out of SPEC";
	}
}

long Ca210::GetDisplayDigits()
{
	return m_pICa->GetDisplayDigits();
}
//////////////////////////////////////////////////////////////////////////
void Ca210::SetAvgingMode(AvgMode AmType)
{
	m_pICa->SetAveragingMode(ChooseAvgingMode(AmType));
}

int Ca210::ChooseAvgingMode(AvgMode AmType)
{
	switch(AmType)
	{
	case AM_SLOW: return 0;
	case AM_FAST: return 1;
	case AM_AUTO: return 2;
	default:      return -1;
	}	
}

CString Ca210::GetAvgingMode(AvgMode AmType)
{
	switch(AmType)
	{
	case AM_SLOW: return "Slow";
	case AM_FAST: return "Fast";
	case AM_AUTO: return "Auto";
	default:      return "No this Mode";
	}
}

long Ca210::GetAvgingMode()
{
	return m_pICa->GetAveragingMode();
}
//////////////////////////////////////////////////////////////////////////
void Ca210::SetBrigUnit(BrigUnit BuType)
{
	m_pICa->SetBrightnessUnit(ChooseBrigUnit(BuType));
}

int Ca210::ChooseBrigUnit(BrigUnit BuType)
{
	switch(BuType)
	{
	case BU_fL:   return 0;
	case BU_cdm2: return 1;
	default:      return -1;
	}	
}

CString Ca210::GetBrigUnit(BrigUnit BuType)
{
	switch(BuType)
	{
	case BU_fL:   return "fL";
	case BU_cdm2: return "cd/m2";
	default:      return "No this Unit";
	}
}

long Ca210::GetBrigUnit()
{
	return m_pICa->GetBrightnessUnit();
}

//////////////////////////////////////////////////////////////////////////
void Ca210::SetCalStandard(CalStand CsType)
{
	m_pICa->SetCalStandard(ChooseCalStandard(CsType));
}

int Ca210::ChooseCalStandard(CalStand CsType)
{
	switch(CsType)
	{
	case CS_6500K: return 1;
	case CS_9300K: return 2;
	default:       return -1;
	}
}

CString Ca210::GetCalStandard(CalStand CsType)
{
	switch(CsType)
	{
	case CS_6500K: return "6500K";
	case CS_9300K: return "9300K";
	default:       return "Out of SPEC";
	}
}

long Ca210::GetCalStandard()
{
	return m_pICa->GetCalStandard();
}
//////////////////////////////////////////////////////////////////////////

UINT Ca210::MsrAI(float MsrDeviation)
{
/*
  return 
  0  亮度0，目前0-Cal
  1  標準門檻值內：繼續量測+百分比
  2  標準門檻值外：繼續量測-百分比
  3  未連線
 */
    if (m_Online)
    {
        float XFristValue = 0.0, deltaX = 0.0,
              YFristValue = 0.0, deltaY = 0.0,
              ZFristValue = 0.0, deltaZ = 0.0, deltaAll;

        if (m_isTrue)
        {
#ifdef _CA210DEBUG
            DBugModeBox("TRUE of MsrAI(float MsrDeviation)");
#endif        //第一筆資料暫存空間  //宣告誤差值計算空間

            Measure();

            if((double)m_pIProbe->GetLv() == 0.0)
                return 0;//0 cal 檔位

            //抓參考值
                XFristValue = m_pIProbe->GetX();
                YFristValue = m_pIProbe->GetY();
                ZFristValue = m_pIProbe->GetZ();

            Measure();

            //誤差取絕對值
                deltaX = ((XFristValue-m_pIProbe->GetX())>=0) ? XFristValue - m_pIProbe->GetX() : m_pIProbe->GetX() - XFristValue;
                deltaY = ((YFristValue-m_pIProbe->GetY())>=0) ? YFristValue - m_pIProbe->GetY() : m_pIProbe->GetY() - YFristValue;
                deltaZ = ((ZFristValue-m_pIProbe->GetZ())>=0) ? ZFristValue - m_pIProbe->GetZ() : m_pIProbe->GetZ() - ZFristValue;
        }
        else
        {
#ifdef _CA210DEBUG
            DBugModeBox("FALSE of MsrAI(float MsrDeviation)");
#endif
            srand(time(NULL));

             //誤差取絕對值
                deltaX = (float)(rand()%100000)/100 - (float)(rand()%100000)/100;
                deltaY = (float)(rand()%100000)/100 - (float)(rand()%100000)/100;
                deltaZ = (float)(rand()%100000)/100 - (float)(rand()%100000)/100;
        }

        deltaAll = deltaX * deltaY * deltaZ;

        if (deltaAll < MsrDeviation )    return 1;//門檻值內
        else                             return 2;//門檻值外
    }
    else
        return 3; //未連線
}

//設定警告標示的標準格式
void Ca210::MsgFrmt(CException* e, CString mean, CString steps)
{
    CString str;
    TCHAR buf[255];
    e->GetErrorMessage(buf, 255);
    
    str.Format("糟糕!!!出現ERROR!!!\n\n原廠錯誤訊息:\n%s\n\n看不懂沒關係，意思就是:\n「%s」\n\n你只要做:\n%s", buf, mean, steps);
    AfxMessageBox(str);
}

void Ca210::MsgFrmt(CString steps)
{
    CString str;
    str.Format("你發呆嗎？\n%s", steps);
    AfxMessageBox(str);
}


//////////////////////////////////////////////////////////////////////////
//debug function

#ifdef _CA210DEBUG

CString Ca210::GetSetupValue() const
{
    CString str;
    str.Format("連線:%d, 實機:%d, ZeroCal了沒:%d", m_Online, m_isTrue, m_isZeroCal);
    return str;
}

void Ca210::DBugModeBox(CString str) const
{
    CString strTemp;
    strTemp.Format("%s\n%s模式, %s", str, m_isTrue?"真實":"模擬", m_Online?"連線":"離線");
    AfxMessageBox(strTemp);
}

#endif
