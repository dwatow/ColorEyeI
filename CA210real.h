#ifndef CA210REAL_H
#define CA210REAL_H


#include "CA210.h"
#include "ca200srvr.h"
#include "Bullet.h"

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

    CaState m_caState;
    CaState m_caStateTemp;
    CString str;

    CString ImpsbStr;
    void MsgFrmt(CException* e, const CString&, const CString&);
    void MsgFrmt(const CString&);
//////////////////////////////////////////////////////////////////////////
public:
    Ca210real();
    virtual ~Ca210real();

public:
    const CaState CalZero();
    const CaState Measure();

    void LinkMemory();

    const MsrAiState MsrAI(const float& MsrDeviation = 0.0001);//0.0001

    void SetOnline(const BOOL& b = TRUE);
    const BOOL isOnline() const
    { return m_caState == CA_Offline ? FALSE : TRUE; };

    const CString GetLcmSize();
    const CString GetChData();// const;
    const Bullet  GetMsrData();

//for setup Dialog Value
    const   float GetRangeColor1() const;
    const   float GetRangeColor2() const;
    const   float GetRangeFAM()    const;

             void SetChId(const LPCTSTR& Id)    { m_pIMemory->SetChannelID(Id); };
    const CString GetChId()               const {                               return m_pIMemory->GetChannelID(); };
    const CString GetChId(const long& No) const { m_pIMemory->SetChannelNO(No); return m_pIMemory->GetChannelID(); };

             void SetChNo(const long &No)  { m_pIMemory->SetChannelNO(No); };
    const    long GetChNo()          const { return m_pIMemory->GetChannelNO(); };
    const CString GetChStrNo() /*const*/   { str.Format("%ld", m_pIMemory->GetChannelNO()); return str; };

    const CString GetProb()       const { return m_pIProbe->GetSerialNO(); };
    const CString GetDeviceType() const { return m_pICa->GetCAType();      };
    const CString GetCaVersion()  const { return m_pICa->GetCAVersion();   };

    const CString GetRefProbe() const;
    const CString GetCalProbe() const;
    const CString GetCalMode()  const;

    const CString GetRefLv() const;
    const CString GetRefSx() const;
    const CString GetRefSy() const;

//for setup dialog combo box ItemString
    const CString GetSynMode      (const   SynMode&) const;
    const CString GetDisplayMode  (const   DisPlay&) const;
    const CString GetDisplayDigits(const DisDigits&) const;
    const CString GetAvgingMode   (const   AvgMode&) const;
    const CString GetBrigUnit     (const  BrigUnit&) const;
    const CString GetCalStandard  (const  CalStand&) const;

//Get and Set of CA-SDK 
    void SetSynMode      (const   SynMode&); const float GetSynMode()       const;
    void SetDisplayMode  (const   DisPlay&); const long  GetDisplayMode()   const;
    void SetDisplayDigits(const DisDigits&); const long  GetDisplayDigits() const;
    void SetAvgingMode   (const   AvgMode&); const long  GetAvgingMode()    const;
    void SetBrigUnit     (const  BrigUnit&); const long  GetBrigUnit()      const;
    void SetCalStandard  (const  CalStand&); const long  GetCalStandard()   const;
    
private:  //for setup CA-SDK parameter
    const float chooseSynMode      (const   SynMode&) const;
    const int   chooseDisplayMode  (const   DisPlay&) const;
    const int   chooseDisplayDigits(const DisDigits&) const;
    const int   chooseAvgingMode   (const   AvgMode&) const;
    const int   chooseBrigUnit     (const  BrigUnit&) const;
    const int   chooseCalStandard  (const  CalStand&) const;

private:  //for real CA-210 USB connect initial
    const BOOL initCreatCa200();
    const BOOL initConnectCa210();
    const BOOL initAttachCa();
    const BOOL initAttchProbe();
    
#ifdef _CA210DEBUG
    const CString GetSetupValue()             const;
             void debugMessageBox(const CString&) const;
#endif
};

#endif