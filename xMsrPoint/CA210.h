#ifndef CA210_H
#define CA210_H

#include "ca200srvr.h"
#include "Bullet.h"

//虫縒北CA-210家舱琌ぃ琌璶秈 DEBUG家Α
//#define _CA210DEBUG _DEBUG

class Ca210
{
    ICa200          m_ICa200;
    ICa             m_ICa;
    IProbe          m_IProbe;
    IMemory         m_IMemory;
//    IProbes         m_IProbes;
//    IProbeInfo      m_IProbeInfo;
//    ICas            m_ICas;
//    IOutputProbes   m_IOutputProbes;
//    _ICaEvents      m__ICaEvents;

    Bullet m_blt;
//    CString m_strData;

//    BOOL m_DebugFlag;
    BOOL m_isTrue;  //礚CA-210璶家览祘Α秈︽家Α
    BOOL m_Online;
    BOOL m_isZeroCal;
    CString str;
    void MsgFrmt(CException* e, CString, CString);
    void MsgFrmt(CString);
public:
    CString ImpsbStr;
//    Ca210();
    Ca210(BOOL tr = TRUE);
    ~Ca210();

    UINT MsrAI(float );//0.0001
    UINT Measure();

    BOOL isTrue() const;
    BOOL CalZero();
    BOOL LinkMemory();
    BOOL SetOnline(BOOL);
    BOOL GetOnline() const;
    CString GetLcmSize();
    Bullet  GetMsrData();
    CString OutData();
    CString GetChData();

    //for Omd File Head
    CString GetChNO();
    CString GetProb();
    CString GetDeviceType();


#ifdef _CA210DEBUG
    CString GetSetupValue() const;
    void DBugModeBox(CString) const;
#endif
};

#endif