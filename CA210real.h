#ifndef CA210REAL_H
#define CA210REAL_H


#include "xMsrPoint/CA210.h"
#include "xMsrPoint/ca200srvr.h"
#include "xMsrPoint/Bullet.h"

//單獨控制CA-210模組是不是要進入 DEBUG模式
//#define _CA210DEBUG _DEBUG

class Ca210real : public Ca210
{
    ICa200          *m_pICa200;
    ICa             *m_pICa;
    IProbe          *m_pIProbe;
    IMemory         *m_pIMemory;
//    IProbes         m_IProbes;
    IProbeInfo      *m_pIProbeInfo;
//    ICas            m_ICas;
//    IOutputProbes   m_IOutputProbes;
//    _ICaEvents      m__ICaEvents;

    Bullet m_blt;

    CaState m_caState;
	CaState m_caStateTemp;
    CString str;

    CString ImpsbStr;
protected:
    void MsgFrmt(CException* e, CString, CString);
    void MsgFrmt(CString);

public:
	Ca210real();
    virtual ~Ca210real();

public:
	CaState CalZero();
    CaState Measure();

    void LinkMemory();

    MsrAiState MsrAI(float MsrDeviation = 0.0001);//0.0001

    void SetOnline(BOOL b = TRUE);
    BOOL isOnline() const { return m_caState == CA_Offline ? FALSE : TRUE; };
    CString GetLcmSize();
    CString GetChData();
    Bullet  GetMsrData();
    CString OutData();

//for setup Dialog Value
	float   GetRangeColor1();
	float   GetRangeColor2();
	float   GetRangeFAM();

	void    SetChId(LPCTSTR &Id) { m_pIMemory->SetChannelID(Id); };
	CString GetChId()            {                               return m_pIMemory->GetChannelID(); };
	CString GetChId(long &No)    { m_pIMemory->SetChannelNO(No); return m_pIMemory->GetChannelID(); };

 	void    SetChNo(long &No)    { m_pIMemory->SetChannelNO(No); };
    CString GetChStrNo()         { str.Format("%ld", m_pIMemory->GetChannelNO()); return str; };
	long    GetChNo()            { return m_pIMemory->GetChannelNO(); };

	CString GetProb()       { return m_pIProbe->GetSerialNO(); };
    CString GetDeviceType() { return m_pICa->GetCAType();      };
	CString GetCaVersion()  { return m_pICa->GetCAVersion();   };

	CString GetRefProbe();
	CString GetCalProbe();
	CString GetCalMode();
	
	CString GetRefLv();
	CString GetRefSx();
	CString GetRefSy();

//for setup dialog combo box ItemString
	CString GetSynMode(SynMode);
	CString GetDisplayMode(DisPlay);
	CString GetDisplayDigits(DisDigits);
	CString GetAvgingMode(AvgMode);
	CString GetBrigUnit(BrigUnit);
	CString GetCalStandard(CalStand);

//Get and Set of CA-SDK 
	void    SetSynMode(SynMode);			float   GetSynMode();
	void    SetDisplayMode(DisPlay);		long    GetDisplayMode();
	void    SetDisplayDigits(DisDigits);	long    GetDisplayDigits();
	void    SetAvgingMode(AvgMode);			long    GetAvgingMode();
	void    SetBrigUnit(BrigUnit);			long    GetBrigUnit();
	void    SetCalStandard(CalStand);		long    GetCalStandard();

#ifdef _CA210DEBUG
    CString GetSetupValue() const;
    void DBugModeBox(CString) const;
#endif

private:  //for setup CA-SDK parameter
	float   ChooseSynMode(SynMode);
	int     ChooseDisplayMode(DisPlay);
	int     ChooseDisplayDigits(DisDigits);
	int     ChooseAvgingMode(AvgMode);
	int     ChooseBrigUnit(BrigUnit);
	int     ChooseCalStandard(CalStand);

private:  //for real CA-210 USB connect initial
	BOOL initCreatCa200();
	BOOL initConnectCa210();
	BOOL initAttachCa();
	BOOL initAttchProbe();
};

#endif