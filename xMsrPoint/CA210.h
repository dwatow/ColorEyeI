#ifndef CA210_H
#define CA210_H

#include "ca200srvr.h"
#include "Bullet.h"

//虫縒北CA-210家舱琌ぃ琌璶秈 DEBUG家Α
//#define _CA210DEBUG _DEBUG

enum SynMode   { SM_NTSC = 0, SM_PAL, SM_EXT, SM_UNIV, SM_INT};
enum DisPlay   { DP_Lvxy = 0, DP_duvT, DP_Analyzer_NoDisplay, DP_Analyzer_Gstand, DP_Analyzer_Rstand, DP_dudv, DP_FMA, DP_XYZ, DP_JEITA};
enum DisDigits { DD_3DisDigits = 0, DD_4DisDigits};
enum AvgMode   { AM_SLOW = 0, AM_FAST, AM_AUTO};
enum BrigUnit  { BU_fL =0, BU_cdm2 };
enum CalStand  { CS_6500K = 1, CS_9300K };

enum CaState    { CA_Offline, CA_BeforeZeroCal, CA_ZeroCalMode, CA_MsrMode};
enum MsrAiState { MA_nonMsr, MA_InDeviation, MA_OutDeviation };

class Ca210
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
//    BOOL m_isZeroCal;
    CString str;

protected:
    void MsgFrmt(CException* e, CString, CString);
    void MsgFrmt(CString);

public:
    CString ImpsbStr;

    //﹍てㄧ计
	Ca210();
    virtual ~Ca210();
//	virtual BOOL isReady() const { return m_isSuccess; };
		BOOL initCreatCa200();
		BOOL initConnectCa210();
		BOOL initAttachCa();
		BOOL initAttchProbe();

	virtual CaState CalZero();
    virtual CaState Measure();

    virtual void LinkMemory();

    virtual MsrAiState MsrAI(float MsrDeviation = 0.0001);//0.0001

    void SetOnline(BOOL b = TRUE);
    virtual BOOL isOnline() const { return m_caState == CA_Offline ? FALSE : TRUE; };
    virtual CString GetLcmSize();
    virtual CString GetChData();
    virtual Bullet  GetMsrData();
    CString OutData();

	//for setup
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

	void    SetSynMode(SynMode);
	CString GetSynMode(SynMode);
	float   GetSynMode();

	void    SetDisplayMode(DisPlay);
	CString GetDisplayMode(DisPlay);
	long    GetDisplayMode();

	void    SetDisplayDigits(DisDigits);
	CString GetDisplayDigits(DisDigits);
	long    GetDisplayDigits();

	void    SetAvgingMode(AvgMode);
	CString GetAvgingMode(AvgMode);
	long    GetAvgingMode();

	void    SetBrigUnit(BrigUnit);
	CString GetBrigUnit(BrigUnit);
	long    GetBrigUnit();

	void    SetCalStandard(CalStand);
	CString GetCalStandard(CalStand);
	long    GetCalStandard();


#ifdef _CA210DEBUG
    virtual CString GetSetupValue() const;
    virtual void DBugModeBox(CString) const;
#endif

protected:
	float   ChooseSynMode(SynMode);
	int     ChooseDisplayMode(DisPlay);
	int     ChooseDisplayDigits(DisDigits);
	int     ChooseAvgingMode(AvgMode);
	int     ChooseBrigUnit(BrigUnit);
	int     ChooseCalStandard(CalStand);
};

#endif