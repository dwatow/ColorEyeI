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

enum CaState    { CA_Offline, CA_not_yet_ZeroCal, CA_ZeroCalMode, CA_MsrMode};
enum MsrAiState { MA_nonMsr, MA_InDeviation, MA_OutDeviation };

class Ca210
{
    CString ImpsbStr;
    CaState m_caState;
    CaState m_caStateTemp;
protected:
    CString m_LCMsize;
    Bullet m_blt;
//////////////////////////////////////////////////////////////////////////
    virtual void MsgFrmt(CException* e, const CString&, const CString&) = 0;
    virtual void MsgFrmt(const CString&) = 0;

public:
    Ca210(): m_LCMsize(""){};
    virtual ~Ca210(){};

public:
    virtual const CaState CalZero() = 0;
    virtual const CaState Measure() = 0;
 
    virtual          void LinkMemory() = 0;
 
    virtual const MsrAiState MsrAI(const float&) = 0;
 
    virtual          void SetOnline(const BOOL&) = 0;
    virtual    const BOOL isOnline() const = 0;
                     void SetLcmSize(const CString& _S){ m_LCMsize = _S; };
    virtual const CString GetLcmSize() = 0;
    virtual const CString GetChData() = 0;
    virtual const Bullet  GetMsrData() = 0;
            const CString OutData();

 //for setup Dialog Value
    virtual const float GetRangeColor1() const = 0;
    virtual const float GetRangeColor2() const = 0;
    virtual const float GetRangeFAM()    const = 0;
 
    virtual          void SetChId(const LPCTSTR& )   = 0;
    virtual const CString GetChId()            const = 0;
    virtual const CString GetChId(const long&) const = 0;
 
    virtual          void SetChNo(const long&) = 0;
    virtual const    long GetChNo() const      = 0;
    virtual const CString GetChStrNo()         = 0;

    virtual const CString GetProb()       const = 0;
    virtual const CString GetDeviceType() const = 0;
    virtual const CString GetCaVersion()  const = 0;

    virtual const CString GetRefProbe() const = 0;
    virtual const CString GetCalProbe() const = 0;
    virtual const CString GetCalMode()  const = 0;
    
    virtual const CString GetRefLv() const = 0;
    virtual const CString GetRefSx() const = 0;
    virtual const CString GetRefSy() const = 0;

//for setup dialog combo box ItemString
    virtual const CString GetSynMode      (const   SynMode&) const = 0;
    virtual const CString GetDisplayMode  (const   DisPlay&) const = 0;
    virtual const CString GetDisplayDigits(const DisDigits&) const = 0;
    virtual const CString GetAvgingMode   (const   AvgMode&) const = 0;
    virtual const CString GetBrigUnit     (const  BrigUnit&) const = 0;
    virtual const CString GetCalStandard  (const  CalStand&) const = 0;

//Get and Set of CA-SDK 
    virtual void SetSynMode      (const   SynMode&) = 0; virtual const float GetSynMode()       const = 0;
    virtual void SetDisplayMode  (const   DisPlay&) = 0; virtual const long  GetDisplayMode()   const = 0;
    virtual void SetDisplayDigits(const DisDigits&) = 0; virtual const long  GetDisplayDigits() const = 0;
    virtual void SetAvgingMode   (const   AvgMode&) = 0; virtual const long  GetAvgingMode()    const = 0;
    virtual void SetBrigUnit     (const  BrigUnit&) = 0; virtual const long  GetBrigUnit()      const = 0;
    virtual void SetCalStandard  (const  CalStand&) = 0; virtual const long  GetCalStandard()   const = 0;
};

#endif