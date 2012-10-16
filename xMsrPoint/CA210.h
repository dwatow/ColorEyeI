#ifndef CA210_H
#define CA210_H

#include "ca200srvr.h"
#include "Bullet.h"

//單獨控制CA-210模組是不是要進入 DEBUG模式
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
    CString ImpsbStr;
    CaState m_caState;
	CaState m_caStateTemp;
protected:
    virtual void MsgFrmt(CException* e, CString, CString) = 0;
    virtual void MsgFrmt(CString) = 0;

public:
	Ca210(){};
    virtual ~Ca210(){};
//////////////////////////////////////////////////////////////////////////

public:
 	virtual CaState CalZero() = 0;
    virtual CaState Measure() = 0;
 
    virtual void LinkMemory() = 0;
 
    virtual MsrAiState MsrAI(float) = 0;
 
    virtual void SetOnline(BOOL) = 0;
	virtual BOOL isOnline() const = 0;
    virtual CString GetLcmSize() = 0;
    virtual CString GetChData() = 0;
    virtual Bullet  GetMsrData() = 0;
    virtual CString OutData() = 0;

 //for setup Dialog Value
 	virtual float   GetRangeColor1() = 0;
 	virtual float   GetRangeColor2() = 0;
 	virtual float   GetRangeFAM() = 0;
 
 	virtual void    SetChId(LPCTSTR& ) = 0;
 	virtual CString GetChId() = 0;
 	virtual CString GetChId(long&) = 0;
 
  	virtual void    SetChNo(long&) = 0;
     virtual CString GetChStrNo() = 0;
 	virtual long    GetChNo() = 0;

	virtual CString GetProb() = 0;
    virtual CString GetDeviceType() = 0;
	virtual CString GetCaVersion() = 0;

	virtual CString GetRefProbe() = 0;
	virtual CString GetCalProbe() = 0;
	virtual CString GetCalMode() = 0;
	
	virtual CString GetRefLv() = 0;
	virtual CString GetRefSx() = 0;
	virtual CString GetRefSy() = 0;

//for setup dialog combo box ItemString
	virtual CString GetSynMode(SynMode) = 0;
	virtual CString GetDisplayMode(DisPlay) = 0;
	virtual CString GetDisplayDigits(DisDigits) = 0;
	virtual CString GetAvgingMode(AvgMode) = 0;
	virtual CString GetBrigUnit(BrigUnit) = 0;
	virtual CString GetCalStandard(CalStand) = 0;

//Get and Set of CA-SDK 
	virtual void    SetSynMode(SynMode) = 0;			virtual float   GetSynMode() = 0;
	virtual void    SetDisplayMode(DisPlay) = 0;		virtual long    GetDisplayMode() = 0;
	virtual void    SetDisplayDigits(DisDigits) = 0;	virtual long    GetDisplayDigits() = 0;
	virtual void    SetAvgingMode(AvgMode) = 0;			virtual long    GetAvgingMode() = 0;
	virtual void    SetBrigUnit(BrigUnit) = 0;			virtual long    GetBrigUnit() = 0;
	virtual void    SetCalStandard(CalStand) = 0;		virtual long    GetCalStandard() = 0;
};

#endif