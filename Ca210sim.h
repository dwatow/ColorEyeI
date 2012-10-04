// a210sim.h: interface for the Ca210sim class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_A210SIM_H__BEC68607_FF0F_4C06_97AF_665A09334DFE__INCLUDED_)
#define AFX_A210SIM_H__BEC68607_FF0F_4C06_97AF_665A09334DFE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "XMSRPOINT\CA210.h"

class Ca210sim : public Ca210  
{
    Bullet m_blt;
	BOOL m_isZeroCal;
	BOOL m_isSuccess;
    BOOL m_Online;

public:
	Ca210sim();
	virtual ~Ca210sim(){};
// 	BOOL isReady() const { return m_isSuccess; };
// 	BOOL CalZero(int i = 0);
//     void LinkMemory();
//     UINT Measure();
// 
//     virtual BOOL GetOnline() const { return m_Online; };
// 	CString GetLcmSize();
//     CString GetChData();
// 	Bullet  GetMsrData();
// 
// 	UINT MsrAI(float );//0.0001
};



#endif // !defined(AFX_A210SIM_H__BEC68607_FF0F_4C06_97AF_665A09334DFE__INCLUDED_)
