// a210sim.h: interface for the Ca210sim class.
//
//////////////////////////////////////////////////////////////////////

#ifndef CA210SIM_H
#define CA210SIM_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "xMsrPoint/CA210.h"

class Ca210sim : public Ca210
{    
    Bullet* m_pIProbe;

//simulation setup dialog item
    SynMode m_syncMode;
    DisPlay m_displayMode;
    DisDigits m_displayDigits;
    AvgMode m_averageMide;
    BrigUnit m_brightnessUnit;
    CalStand m_calStandard;

    CaState m_caState;
    CaState m_caStateTemp;
    CString str;
    
    CString ImpsbStr;
//////////////////////////////////////////////////////////////////////////
    void MsgFrmt(CException* , const CString&, const CString&){};
    void MsgFrmt(const CString&){};
public:
    Ca210sim();
    virtual ~Ca210sim();
    
public:
    const CaState CalZero();
    const CaState Measure();
    
             void LinkMemory();
    
    const MsrAiState MsrAI(const float& MsrDeviation = 0.0001);//0.0001
    
             void SetOnline(const BOOL& b = TRUE);
    const    BOOL isOnline() const { return m_caState == CA_Offline ? FALSE : TRUE; };
    const CString GetLcmSize();
    const CString GetChData();
    const  Bullet GetMsrData();
    
//for setup Dialog Value
    const float GetRangeColor1() const;
    const float GetRangeColor2() const;
    const float GetRangeFAM()    const;
    
             void SetChId(const LPCTSTR &)    {  };
    const CString GetChId()             const {  return "SimCh"; };
    const CString GetChId(const long &) const {  return "SimCh"; };
    
             void SetChNo(const long &) {  };
    const CString GetChStrNo()          { return "0"; };
    const    long GetChNo() const       { return  0;  };
    
    const CString GetProb()       const { return "8115678";   };
    const CString GetDeviceType() const { return "SimCA-210"; };
    const CString GetCaVersion()  const { return "Simulator"; };
    
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
    
#ifdef _CA210DEBUG
    const CString GetSetupValue() const;
    void DBugModeBox(const CString&) const;
#endif
    
private:  //for setup CA-SDK parameter
    const float ChooseSynMode      (const   SynMode&) const;
    const int   ChooseDisplayMode  (const   DisPlay&) const;
    const int   ChooseDisplayDigits(const DisDigits&) const;
    const int   ChooseAvgingMode   (const   AvgMode&) const;
    const int   ChooseBrigUnit     (const  BrigUnit&) const;
    const int   ChooseCalStandard  (const  CalStand&) const;
};



#endif // !defined(AFX_A210SIM_H__BEC68607_FF0F_4C06_97AF_665A09334DFE__INCLUDED_)
