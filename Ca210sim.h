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
    Bullet m_blt;
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
protected:
    void MsgFrmt(CException* , CString, CString){};
    void MsgFrmt(CString){};
	
public:
	Ca210sim();
    virtual ~Ca210sim();
	
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
	
	void    SetChId(LPCTSTR &) {  };
	CString GetChId()            {  return "SimCh"; };
	CString GetChId(long &)    {  return "SimCh"; };
	
	void    SetChNo(long &)    {  };
    CString GetChStrNo()         { return "0"; };
	long    GetChNo()            { return 0; };
	
	CString GetProb()       { return "8115678"; };
    CString GetDeviceType() { return "SimCA-210"; };
	CString GetCaVersion()  { return "Simulator";   };
	
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
};



#endif // !defined(AFX_A210SIM_H__BEC68607_FF0F_4C06_97AF_665A09334DFE__INCLUDED_)
