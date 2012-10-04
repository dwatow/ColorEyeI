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
	AfxMessageBox("ca-210�����{��");
}
// 
// BOOL Ca210sim::CalZero(int flag)
// {
// 	/*
// 	case 10   Delay1sec ����ZeroCal���ɶ�
// 	*/
// 	if(m_Online)
//     {
//         //������
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
// 	//�s�u �^��4(Msr��)
// 	//     �^��3(0-Cal��)
// 	//���u �^�����u���A
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
// 			str.Format("14");  //���q
// //			str.Format("24");  //���
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
// 			Ca210::MsgFrmt(e, "�qCA-210��Channel����ƥX�ӥX���D", ImpsbStr);
//         }
//     }
//     else
//         temp.Format("�w���u - �L�W�D");
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
//   0  �G��0�A�ثe0-Cal
//   1  �зǪ��e�Ȥ��G�~��q��+�ʤ���
//   2  �зǪ��e�ȥ~�G�~��q��-�ʤ���
//   3  ���s�u
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
//          //�~�t�������
//             deltaX = (float)(rand()%100000)/100 - (float)(rand()%100000)/100;
//             deltaY = (float)(rand()%100000)/100 - (float)(rand()%100000)/100;
//             deltaZ = (float)(rand()%100000)/100 - (float)(rand()%100000)/100;
// 
//         deltaAll = deltaX * deltaY * deltaZ;
// 
//         if (deltaAll < MsrDeviation )    return 1;//���e�Ȥ�
//         else                             return 2;//���e�ȥ~
//     }
//     else
//         return 3; //���s�u
// }
// 
