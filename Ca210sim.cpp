// a210sim.cpp: implementation of the Ca210sim class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ColorEyeI.h"
#include "Ca210sim.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Ca210sim::Ca210sim():m_isZeroCal(FALSE), m_isSuccess(TRUE)
{
	AfxMessageBox("ca-210模擬程式");
}
// 
// BOOL Ca210sim::CalZero(int flag)
// {
// 	/*
// 	case 10   Delay1sec 模擬ZeroCal的時間
// 	*/
// 	if(m_Online)
//     {
//         //模擬的
// #ifdef _CA210DEBUG
//         DBugModeBox("FALSE of CalZero()");
// #endif
//         m_isZeroCal = TRUE;
//         Sleep(1000);
//         return TRUE;
//     }
//     else
//     {
// #ifdef _CA210DEBUG
//         DBugModeBox("TRUE of CalZero()");
// #endif
//         return FALSE;
//     }
// }
// 
// void Ca210sim::LinkMemory()
// {
// #ifdef _CA210DEBUG
//     if (!m_Online)
//     {
//         DBugModeBox("FALSE of LinkMemory()");
//     }
// #endif
// }
// 
// UINT Ca210sim::Measure()
// {
// 	//連線 回傳4(Msr檔)
// 	//     回傳3(0-Cal檔)
// 	//離線 回傳離線狀態
//     if(m_Online)
// 		return 4;
// 	else
// 		return m_Online;
// }
// 
// CString Ca210sim::GetLcmSize()
// {
//     CString str;
//     if (m_Online)
//     {
// #ifdef _CA210DEBUG
// 			DBugModeBox("TRUE of GetLcmSize()");
// #endif
// 			str.Format("14");  //筆電
// //			str.Format("24");  //桌機
//     }
//     else 
//         str.Format("-1");
// 	return str;
// }
// 
// CString Ca210sim::GetChData()
// {
//     CString temp;
//     if (m_Online)
//     {
//         try
//         {
// #ifdef _CA210DEBUG
//             CString str;
//             str.Format("%s of GetChData()", m_Online ? "TRUE" : "FALSE");
//             DBugModeBox(str);
// #endif
//             temp.Format("99 - SIMCH");
//         }
//         catch (CException* e)
//         {
// 			Ca210::MsgFrmt(e, "從CA-210抓Channel的資料出來出問題", ImpsbStr);
//         }
//     }
//     else
//         temp.Format("已離線 - 無頻道");
//     return temp;
// }
// 
// Bullet Ca210sim::GetMsrData()
// {
// 	
//     if (m_Online)
//     {
// #ifdef _CA210DEBUG
//         DBugModeBox("FALSE of GetMsrData()");
// #endif
//         srand(time(NULL));
//         m_blt.SetLv((float)(rand()%100000)/100);    //%3.2f
//         m_blt.SetSx((float)(rand()%10000 +1)/(float)10000);  //%1.4f
//         m_blt.SetSy((float)(rand()%10000 +1)/(float)10000);  //%1.4f
//         
//         m_blt.SetT(rand()%1000);//%3d
//         m_blt.SetDuv((float)(rand()%100000)/10000);  //%1.4f
//         
//         m_blt.SetDu((float)(rand()%100000)/10000);  //%1.4f
//         m_blt.SetDv((float)(rand()%100000)/10000);  //%1.4f
//         
//         m_blt.SetX((float)(rand()%100000)/100);  //%3.2f
//         m_blt.SetY((float)(rand()%100000)/100);  //%3.2f
//         m_blt.SetZ((float)(rand()%100000)/100);  //%3.2f
//     }
//     return m_blt;
// }
// 
// UINT Ca210sim::MsrAI(float MsrDeviation)
// {
// /*
//   return 
//   0  亮度0，目前0-Cal
//   1  標準門檻值內：繼續量測+百分比
//   2  標準門檻值外：繼續量測-百分比
//   3  未連線
//  */
//     if (m_Online)
//     {
//         float XFristValue = 0.0, deltaX = 0.0,
//               YFristValue = 0.0, deltaY = 0.0,
//               ZFristValue = 0.0, deltaZ = 0.0, deltaAll;
// 
// #ifdef _CA210DEBUG
//         DBugModeBox("FALSE of MsrAI(float MsrDeviation)");
// #endif
//         srand(time(NULL));
// 
//          //誤差取絕對值
//             deltaX = (float)(rand()%100000)/100 - (float)(rand()%100000)/100;
//             deltaY = (float)(rand()%100000)/100 - (float)(rand()%100000)/100;
//             deltaZ = (float)(rand()%100000)/100 - (float)(rand()%100000)/100;
// 
//         deltaAll = deltaX * deltaY * deltaZ;
// 
//         if (deltaAll < MsrDeviation )    return 1;//門檻值內
//         else                             return 2;//門檻值外
//     }
//     else
//         return 3; //未連線
// }
// 
