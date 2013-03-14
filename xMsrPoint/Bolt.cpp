#include "stdafx.h"
#include <cmath>
#include "Bolt.h"
#include "../MainFrm.h"

/***************************************************
 *    GetFE9Point(UINT few, float FromEdge)  const *
 *    GetFE5Point(UINT few, float FromEdge)  const *
 *    Get5nits9Point(UINT few)               const *
 *    GetD13Point(UINT few)                  const *
 *    GetD21Point(UINT few, float hDecile, float vDecile, float FromEdge) const
 *    GetD25Point(UINT few, UINT side)       const *
 *    GetW49Point(UINT few)                  const *
 *    GetCrossTalk(UINT few, float FromEdge) const *
 ***************************************************/

CPoint Bolt::GetFE9Point(UINT few) const
{
//運算第幾個（以九點為計）

    //ScrmV 螢幕垂直pixel數
    //ScrmH 螢幕水平pixel數
    int LeftEdge   = (m_f9FE) ? static_cast<int>(m_nScrmH / m_f9FE) : CmtoPixel(2.3);
    int TopEdge    = (m_f9FE) ? static_cast<int>(m_nScrmV / m_f9FE) : CmtoPixel(2.3);
    int RightEdge  = m_nScrmH - LeftEdge;
    int BottomEdge = m_nScrmV - TopEdge;
    int hCenter    = m_nScrmH/2;
    int vCenter    = m_nScrmV/2;
/*
+------------------------------+
|                              |
|    00        01        02    |
|                              |
|                              |
|    03        04        05    |
|                              |
|                              |
|    06        07        08    |
|                              |
+------------------------------+
*/
    CPoint 
        Point0(LeftEdge ,TopEdge),
        Point1(hCenter  ,TopEdge),
        Point2(RightEdge,TopEdge),
        Point3(LeftEdge ,vCenter),
        Point4(hCenter  ,vCenter),
        Point5(RightEdge,vCenter),
        Point6(LeftEdge ,BottomEdge),
        Point7(hCenter  ,BottomEdge),
        Point8(RightEdge,BottomEdge),
        PointD(hCenter  ,vCenter);

//回傳一個點
    switch(few)
    {
        case 0: return Point0; break;
        case 1: return Point1; break;
        case 2: return Point2; break;

        case 3: return Point3; break;
        case 4: return Point4; break;
        case 5: return Point5; break;

        case 6: return Point6; break;
        case 7: return Point7; break;
        case 8: return Point8; break;

        default: return PointD;
    }
}

CPoint Bolt::GetFE5Point(UINT few) const
{
//運算第幾個（以九點為計）

    //ScrmV 螢幕垂直pixel數
    //ScrmH 螢幕水平pixel數
    int LeftEdge   = (m_f5FE) ? static_cast<int>(m_nScrmH / m_f5FE) : CmtoPixel(2.3);
    int TopEdge    = (m_f5FE) ? static_cast<int>(m_nScrmV / m_f5FE) : CmtoPixel(2.3);
    int RightEdge  = m_nScrmH - LeftEdge;
    int BottomEdge = m_nScrmV - TopEdge;
    int hCenter    = m_nScrmH/2;
    int vCenter    = m_nScrmV/2;
/*
+------------------------------+
|                              |
|    00                  01    |
|                              |
|                              |
|              02              |
|                              |
|                              |
|    03                  04    |
|                              |
+------------------------------+
*/
    CPoint 
        Point0(LeftEdge ,TopEdge),
        Point1(RightEdge,TopEdge),
        Point2(hCenter  ,vCenter),
        Point3(LeftEdge ,BottomEdge),
        Point4(RightEdge,BottomEdge),
        PointD(hCenter  ,vCenter);

//回傳一個點
    switch(few)
    {
        case 0: return Point0; break;
        case 1: return Point1; break;
        case 2: return Point2; break;//中心
        case 3: return Point3; break;
        case 4: return Point4; break;

        default: return PointD;
    }
}

CPoint Bolt::Get5nits9Point(UINT few) const
{
//運算第幾個（以九點為計）

    //ScrmV 螢幕垂直pixel數
    //ScrmH 螢幕水平pixel數
    int LeftEdge   = CmtoPixel(10);
    int TopEdge    = static_cast<int>(m_nScrmV / 6);//六分之一上邊緣
    int RightEdge  = m_nScrmH - LeftEdge;
    int BottomEdge = m_nScrmV - TopEdge;
    int hCenter    = m_nScrmH/2;
    int vCenter    = m_nScrmV/2;
/*5nits
+------------------------------+
|                              |
|    00        01        02    |
|                              |
|                              |
|    03        04        05    |
|                              |
|                              |
|    06        07        08    |
|                              |
+-----------------------------+
*/
    CPoint 
        Point0(LeftEdge ,TopEdge),
        Point1(hCenter  ,TopEdge),
        Point2(RightEdge,TopEdge),
        Point3(LeftEdge ,vCenter),
        Point4(hCenter  ,vCenter),  //中心點不量
        Point5(RightEdge,vCenter),
        Point6(LeftEdge ,BottomEdge),
        Point7(hCenter  ,BottomEdge),
        Point8(RightEdge,BottomEdge),

        PointD(hCenter  ,vCenter);

//回傳一個點
    switch(few)
    {
        case 0: return Point0; break;
        case 1: return Point1; break;
        case 2: return Point2; break;

        case 3: return Point3; break;
        case 4: return Point4; break;//中心
        case 5: return Point5; break;

        case 6: return Point6; break;
        case 7: return Point7; break;
        case 8: return Point8; break;

        default: return PointD;
    }
}

CPoint Bolt::GetD13Point(UINT few) const
{
//運算第幾個（以九點為計）

    //ScrmV 螢幕垂直pixel數
    //ScrmH 螢幕水平pixel數
	int LeftEdge  ((m_f13FE) ? static_cast<int>(m_nScrmH / m_f13FE) : CmtoPixel(2.3));//左邊緣
    int TopEdge   ((m_f13FE) ? static_cast<int>(m_nScrmV / m_f13FE) : CmtoPixel(2.3));//上邊緣
    int RightEdge (m_nScrmH - LeftEdge);
    int BottomEdge(m_nScrmV - TopEdge);

    int hCenter(m_nScrmH/2);
    int vCenter(m_nScrmV/2);

	int hPitch((RightEdge-LeftEdge)/4);
	int vPitch((BottomEdge-TopEdge)/4);

    int L1(hCenter - hPitch);
    int T1(vCenter - vPitch);

    int R1(hCenter + hPitch);
    int B1(vCenter + vPitch);
/*
 LE     L1     HC     R1     RE
+------------------------------+
|00            01            02|TE
|                              |  
|       09            10       |T1
|                              |
|03            04            05|VC
|                              |
|       11            12       |B1  
|                              |  
|06            07            08|BE
+------------------------------+
*/
    CPoint 
        Point00(LeftEdge ,TopEdge),        Point01(hCenter  ,TopEdge),        Point02(RightEdge,TopEdge),

		                       Point09(L1, T1),                     Point10(R1, T1),
		
        Point03(LeftEdge ,vCenter),        Point04(hCenter  ,vCenter),        Point05(RightEdge,vCenter),

                               Point11(L1, B1),                     Point12(R1 ,B1),

        Point06(LeftEdge ,BottomEdge),     Point07(hCenter  ,BottomEdge),     Point08(RightEdge,BottomEdge),


        PointD(hCenter  ,vCenter);

//回傳一個點
    switch(few)
    {
        case 0: return Point00; break;
        case 1: return Point01; break;
        case 2: return Point02; break;

        case 3: return Point03; break;
        case 4: return Point04; break;//中心
        case 5: return Point05; break;

        case 6: return Point06; break;
        case 7: return Point07; break;
        case 8: return Point08; break;

        case 9:  return Point09; break;
        case 10: return Point10; break;
        case 11: return Point11; break;
        case 12: return Point12; break;

        default: return PointD;
    }
}

CPoint Bolt::GetD21Point(UINT few) const
{
//運算第幾個（以九點為計）

    //ScrmV 螢幕垂直pixel數
    //ScrmH 螢幕水平pixel數
    int LE((m_f21FE) ? static_cast<int>(m_nScrmH / m_f21FE) : CmtoPixel(2.3));
    int TE((m_f21FE) ? static_cast<int>(m_nScrmV / m_f21FE) : CmtoPixel(2.3));
    int RE(m_nScrmH - LE);
    int BE(m_nScrmV - TE);

    int hC(m_nScrmH/2);
    int vC(m_nScrmV/2);


	int hPitch( m_nScrmH / 6 );
	int vPitch( m_nScrmV / 4 );

	if (m_f21FE)
	{
		hPitch = ((float)m_nScrmH - ((m_nScrmH/m_f21FE)*2.0)) / 7.0;
		vPitch = ((float)m_nScrmV - ((m_nScrmV/m_f21FE)*2.0)) / 5.0;
	}

    int L2(hC - hPitch), L1(L2 - hPitch), R2(hC + hPitch), R1(R2 + hPitch);

    int T1(vC - vPitch);
    int B1(vC + vPitch);

/*21點
     L1  L2      R2  R1
+--------------------------+
|04  05  06  07  08  09  10| 
|                          |
|03                      11| T1
|                          |
|02          20          12|
|                          |
|01                      13| B1
|                          |
|00  19  18  17  16  15  14| 
+--------------------------+
*/
    CPoint 
        Point04(LE, TE), Point05(L1, TE), Point06(L2, TE), Point07(hC, TE), Point08(R2, TE), Point09(R1, TE), Point10(RE, TE),
        Point03(LE, T1),                                                                                      Point11(RE, T1),
        Point02(LE, vC),                                   Point20(hC, vC),                                   Point12(RE, vC),
        Point01(LE, B1),                                                                                      Point13(RE, B1),
        Point00(LE, BE), Point19(L1, BE), Point18(L2, BE), Point17(hC, BE), Point16(R2, BE), Point15(R1, BE), Point14(RE, BE),
        
        PointD(hC,vC);

//	CString str;
// 	str.Format("few:%d/ %d", m_MsrFlowNo, m_MsrFlowNum);
// 	AfxMessageBox(str);

//回傳一個點
    switch(few)
    {
        case  0: return Point00; break;
        case  1: return Point01; break;
        case  2: return Point02; break;
        case  3: return Point03; break;
        case  4: return Point04; break;
        case  5: return Point05; break;
        case  6: return Point06; break;
        case  7: return Point07; break;
        case  8: return Point08; break;
        case  9: return Point09; break;
        case 10: return Point10; break;
        case 11: return Point11; break;
        case 12: return Point12; break;
        case 13: return Point13; break;
        case 14: return Point14; break;
        case 15: return Point15; break;
        case 16: return Point16; break;
        case 17: return Point17; break;
        case 18: return Point18; break;
        case 19: return Point19; break;
        case 20: return Point20; break;//中心

        default: return PointD;
    }
}

CPoint Bolt::GetD25Point(UINT few) const
{
    //ScrmV 螢幕垂直pixel數
    //ScrmH 螢幕水平pixel數
    int LeftEdge   = (m_f25FE) ? static_cast<int>(m_nScrmH / m_f25FE) : CmtoPixel(2.3);
    int TopEdge    = (m_f25FE) ? static_cast<int>(m_nScrmV / m_f25FE) : CmtoPixel(2.3);

 //   int LeftEdge   = CmtoPixel(2.3);
    int Left_10    = LeftEdge + CmtoPixel(m_n25RectSide/2);
    int Left_20    = Left_10  + CmtoPixel(m_n25RectSide/2);

    int RightEdge  = m_nScrmH - LeftEdge;
    int Right_10   = RightEdge - CmtoPixel(m_n25RectSide/2);
    int Right_20   = Right_10  - CmtoPixel(m_n25RectSide/2);
    
    int hCenter    = m_nScrmH/2;
    int vCenter    = m_nScrmV/2;

//    int TopEdge    = CmtoPixel(2.3);//上邊緣
    int Top_10     = TopEdge + CmtoPixel(m_n25RectSide/2);
    int Top_20     = Top_10  + CmtoPixel(m_n25RectSide/2);

    int BottomEdge = m_nScrmV - TopEdge;
    int Bottom_10  = BottomEdge - CmtoPixel(m_n25RectSide/2);
    int Bottom_20  = Bottom_10  - CmtoPixel(m_n25RectSide/2);

/* L1L2                  R2R1
+------------------------------+
|00  01        05        07  06|
|  04                      10  |T1
|02  03                  09  08|T2
|                              |
|11            12            13|
|                              |
|16  17                  23  25|B2
|  18                      24  |B1
|14  15        19        21  20|
+------------------------------+
*/
    CPoint 
        Point00(LeftEdge, TopEdge),        Point01(Left_20, TopEdge),

                    Point04(Left_10, Top_10),

        Point02(LeftEdge, Top_20),        Point03(Left_20, Top_20),
                        
                            
        Point05(hCenter, TopEdge),


        Point07(Right_20, TopEdge),        Point06(RightEdge, TopEdge),
        
                    Point10(Right_10 ,Top_10),

        Point09(Right_20, Top_20),        Point08(RightEdge,Top_20),
        //--------------------
        Point11(LeftEdge, vCenter),

        Point12(hCenter, vCenter),

        Point13(RightEdge, vCenter),
        //--------------------
        Point16(LeftEdge ,Bottom_20),    Point17(Left_20    ,Bottom_20),

                    Point18(Left_10, Bottom_10),

        Point14(LeftEdge,BottomEdge),    Point15(Left_20    ,BottomEdge),
        
        Point19(hCenter ,BottomEdge),

        Point23(Right_20, Bottom_20),    Point22(RightEdge  ,Bottom_20),

                    Point24(Right_10, Bottom_10),

        Point21(Right_20 ,BottomEdge),    Point20(RightEdge  ,BottomEdge),
        //--------------------        
        PointD(hCenter  ,vCenter);

//回傳一個點
    switch(few)
    {
        case 0: return Point00; break;
        case 1: return Point01; break;
        case 2: return Point02; break;
        case 3: return Point03; break;
        case 4: return Point04; break;

        case 5: return Point05; break;

        case 6: return Point06; break;
        case 7: return Point07; break;
        case 8: return Point08; break;
        case 9: return Point09; break;
        case 10: return Point10; break;
//----------
        case 11: return Point11; break;

        case 12: return Point12; break;//中心

        case 13: return Point13; break;
//----------
        case 14: return Point14; break;
        case 15: return Point15; break;
        case 16: return Point16; break;
        case 17: return Point17; break;
        case 18: return Point18; break;

        case 19: return Point19; break;
        
        case 20: return Point20; break;
        case 21: return Point21; break;
        case 22: return Point22; break;
        case 23: return Point23; break;
        case 24: return Point24; break;

        default: return PointD;
    }
}

CPoint Bolt::GetW49Point(UINT few) const
{
//運算第幾個（以49點為計）

    //ScrmV 螢幕垂直pixel數
    //ScrmH 螢幕水平pixel數
    int LeftEdge  = m_nScrmH  / 12;   //左數1直排
    int DLeftEdge = LeftEdge  *  2;   //左數2直排
    int FLeftEdge = DLeftEdge *  2;   //左數3直排

    int TopEdge   = m_nScrmV / 12;    //上數1橫排
    int DTopEdge  = TopEdge  * 2;    //上數2橫排
    int FTopEdge  = DTopEdge * 2;    //上數2橫排

    int RightEdge  = m_nScrmH -  LeftEdge;   //右數1直排
    int DRightEdge = m_nScrmH - DLeftEdge;   //右數2直排
    int FRightEdge = m_nScrmH - FLeftEdge;   //右數3直排

    int BottomEdge = m_nScrmV -  TopEdge;    //下數1橫排
    int DBottomEdge= m_nScrmV - DTopEdge;    //下數2橫排
    int FBottomEdge= m_nScrmV - FTopEdge;    //下數3橫排

    int hCenter = m_nScrmH/2;  //水平中心
    int vCenter = m_nScrmV/2;  //垂直中心
/* L1L2                  R2R1
+------------------------------+
|                              |
| 00 01  02    03    04  05 06 |T1
| 10 11  12    13    14  15 16 |T2
| 20 21  22    23    24  25 26 |
| 30 31  32    33    34  35 36 |
| 40 41  42    43    44  45 46 |
| 50 51  52    53    54  55 56 |B2
| 60 61  62    63    64  65 66 |B1
|                              |
+------------------------------+
*/
    CPoint 
        Point00(LeftEdge  ,TopEdge),
        Point01(DLeftEdge ,TopEdge),
        Point02(FLeftEdge ,TopEdge),
        Point03(hCenter   ,TopEdge),
        Point04(FRightEdge,TopEdge),
        Point05(DRightEdge,TopEdge),
        Point06(RightEdge ,TopEdge),

        Point10(LeftEdge  ,DTopEdge),
        Point11(DLeftEdge ,DTopEdge),
        Point12(FLeftEdge ,DTopEdge),
        Point13(hCenter   ,DTopEdge),
        Point14(FRightEdge,DTopEdge),
        Point15(DRightEdge,DTopEdge),
        Point16(RightEdge ,DTopEdge),

        Point20(LeftEdge  ,FTopEdge),
        Point21(DLeftEdge ,FTopEdge),
        Point22(FLeftEdge ,FTopEdge),
        Point23(hCenter   ,FTopEdge),
        Point24(FRightEdge,FTopEdge),
        Point25(DRightEdge,FTopEdge),
        Point26(RightEdge ,FTopEdge),

        Point30(LeftEdge  ,vCenter),
        Point31(DLeftEdge ,vCenter),
        Point32(FLeftEdge ,vCenter),
        Point33(hCenter   ,vCenter),//中心點
        Point34(FRightEdge,vCenter),
        Point35(DRightEdge,vCenter),
        Point36(RightEdge ,vCenter),

        Point40(LeftEdge  ,FBottomEdge),
        Point41(DLeftEdge ,FBottomEdge),
        Point42(FLeftEdge ,FBottomEdge),
        Point43(hCenter   ,FBottomEdge),
        Point44(FRightEdge,FBottomEdge),
        Point45(DRightEdge,FBottomEdge),
        Point46(RightEdge ,FBottomEdge),

        Point50(LeftEdge  ,DBottomEdge),
        Point51(DLeftEdge ,DBottomEdge),
        Point52(FLeftEdge ,DBottomEdge),
        Point53(hCenter   ,DBottomEdge),
        Point54(FRightEdge,DBottomEdge),
        Point55(DRightEdge,DBottomEdge),
        Point56(RightEdge ,DBottomEdge),

        Point60(LeftEdge  ,BottomEdge),
        Point61(DLeftEdge ,BottomEdge),
        Point62(FLeftEdge ,BottomEdge),
        Point63(hCenter   ,BottomEdge),
        Point64(FRightEdge,BottomEdge),
        Point65(DRightEdge,BottomEdge),
        Point66(RightEdge ,BottomEdge),

        PointD(hCenter  ,vCenter);

//回傳一個點
    switch(few)
    {
        case  0:  return Point00;  break;
        case  1:  return Point01;  break;
        case  2:  return Point02;  break;
        case  3:  return Point03;  break;
        case  4:  return Point04;  break;
        case  5:  return Point05;  break;
        case  6:  return Point06;  break;

        case  7:  return Point10;  break;
        case  8:  return Point11;  break;
        case  9:  return Point12;  break;
        case 10:  return Point13;  break;
        case 11:  return Point14;  break;
        case 12:  return Point15;  break;
        case 13:  return Point16;  break;

        case 14:  return Point20;  break;
        case 15:  return Point21;  break;
        case 16:  return Point22;  break;
        case 17:  return Point23;  break;
        case 18:  return Point24;  break;
        case 19:  return Point25;  break;
        case 20:  return Point26;  break;

        case 21:  return Point30;  break;
        case 22:  return Point31;  break;
        case 23:  return Point32;  break;
        case 24:  return Point33;  break;//中心點
        case 25:  return Point34;  break;
        case 26:  return Point35;  break;
        case 27:  return Point36;  break;

        case 28:  return Point40;  break;
        case 29:  return Point41;  break;
        case 30:  return Point42;  break;
        case 31:  return Point43;  break;
        case 32:  return Point44;  break;
        case 33:  return Point45;  break;
        case 34:  return Point46;  break;

        case 35:  return Point50;  break;
        case 36:  return Point51;  break;
        case 37:  return Point52;  break;
        case 38:  return Point53;  break;
        case 39:  return Point54;  break;
        case 40:  return Point55;  break;
        case 41:  return Point56;  break;

        case 42:  return Point60;  break;
        case 43:  return Point61;  break;
        case 44:  return Point62;  break;
        case 45:  return Point63;  break;
        case 46:  return Point64;  break;
        case 47:  return Point65;  break;
        case 48:  return Point66;  break;

        default: return PointD;
    }
}


CPoint Bolt::GetCrossTalk(UINT few) const
{
//運算第幾個（以九點為計）
	//不可以貼邊

    //ScrmV 螢幕垂直pixel數
    //ScrmH 螢幕水平pixel數
	float FromEdge = m_fCrsTlkRectFE * (float)2.0 ;

    int LeftEdge   = static_cast<int>(m_nScrmH / FromEdge);    //上
    int TopEdge    = static_cast<int>(m_nScrmV / FromEdge);    //下
    int RightEdge  = m_nScrmH - LeftEdge;  //左
    int BottomEdge = m_nScrmV - TopEdge;   //右
    int hCenter    = m_nScrmH/2;
    int vCenter    = m_nScrmV/2;
/*
+------------------------------+
|                              |
|              00              |  
|                              |  
|                              |
|  01                      02  |
|                              |
|                              |  
|              03              |  
|                              |
+------------------------------+
*/
    CPoint 
        PtTop    (hCenter  , TopEdge),
        PtLefp   (LeftEdge , vCenter),
        PtRight  (RightEdge, vCenter),
        PtButtom (hCenter  , BottomEdge),
        PointD   (hCenter  , vCenter);

//回傳一個點
    switch(few)
    {
        case 0: return PtTop;    break;
        case 1: return PtLefp;   break;
        case 2: return PtRight;  break;
        case 3: return PtButtom; break;

        default: return PointD;
    }
}

CPoint Bolt::GetGammaPoint() const
{
//運算第幾個
    //ScrmV 螢幕垂直pixel數
    //ScrmH 螢幕水平pixel數

    int hCenter    = m_nScrmH/2;
    int vCenter    = m_nScrmV/2;
/*
+------------------------------+
|                              |
|                              |  
|                              |  
|                              |
|              00              |
|                              |
|                              |  
|                              |  
|                              |
+------------------------------+
*/
    CPoint PointD (hCenter, vCenter);

//回傳一個點
	return PointD;
}

UINT Bolt::CmtoPixel(const double cm) const
{    
	CMainFrame* pMainFrm = dynamic_cast<CMainFrame*>(AfxGetMainWnd());
	ASSERT_VALID(pMainFrm);
//	ASSERT(pMainFrm->m_pCa210);
	//開啟舊檔時, pMainFrm->m_pCa210 為空指標
	//有量測（與CA-210連線）時, pMainFrm->m_pCa210 有指向儀器
	float LCMsize;

	if(pMainFrm->m_pCa210 == 0)
		LCMsize = 0.0;
	else
		LCMsize = atof(pMainFrm->m_pCa210->GetLcmSize());

    return (UINT)(m_nScrmV*cm / (LCMsize * sin( atan((double)m_nScrmV/(double)m_nScrmH) ) * 2.54));
}


/*******************************************************
 *******************************************************
 *******************************************************
 *******************************************************
 *******************************************************
 *******************************************************/


Bolt::Bolt():m_nScrmH(GetSystemMetrics(SM_CXSCREEN)), \
m_nScrmV(GetSystemMetrics(SM_CYSCREEN)), m_Radius(0), \
m_5nitsBkColor(RGB(127, 127, 127)),
m_f5FE(0.0),
m_f9FE(6.0),
m_f13FE(0.0),
m_f21FE(0.0),
m_f25FE(0.0){}


BOOL Bolt::Magazine(std::vector<Cartridge>::iterator& EndItor)
{
/*
    要得到以下訊息    本次量測的環境如何
    LcmSize
    圈半徑
*/
    m_itEnd = EndItor;
    m_Radius = CmtoPixel(2.25);

    return TRUE;
}

TrigStatus Bolt::Trigger(std::vector<Cartridge>::iterator& it)
{
    /*
    0 沒有資料
    1 正常
    2 5nits
	*/
    if (it != m_itEnd)
    {
        m_BkColor    = it->GetBackColor();
        m_MsrFlowNum = it->GetMsrFlowNum();
        m_MsrFlowNo  = it->GetMsrFlowNo();

		if (m_BkColor == JND)
			return TS_JND;
		else if (m_BkColor == JNDX)
			return TS_JNDX;
        else if (m_BkColor == Nits && it->GetArea() == 1)
            return TS_Find_Nits;
        else
            return TS_Normal;
    }
    else 
        return TS_FinalPoint;
}

COLORREF Bolt::GetBkColor() const
{
	if (m_MsrFlowNum == PnGamma)
		switch(m_BkColor)
		{
			case Red:      return RGB( m_MsrFlowNo,           0,           0);
			case Green:    return RGB(           0, m_MsrFlowNo,           0);
			case Blue:     return RGB(           0,           0, m_MsrFlowNo);
			case White:    
			case Dark:     
			default:       return RGB( m_MsrFlowNo, m_MsrFlowNo, m_MsrFlowNo);
		}
	else
		switch(m_BkColor)
		{
			case White:    return RGB( 255, 255, 255);
			case Dark:     return RGB(   0,   0,   0);
			case Red:      return RGB( 255,   0,   0);
			case Green:    return RGB(   0, 255,   0);
			case Blue:     return RGB(   0,   0, 255);
			case Nits:     return m_5nitsBkColor;
			case JNDX:
			case JND:      return m_JNDBkColor;
			case CrsTlk: 
			case CrsTlkW:
			case CrsTlkD:  return RGB( 128, 128, 128);
			default:       return RGB( 192, 212,  49); 
		}
}

void Bolt::CenterRect(CDC* pDC, COLORREF CntrClr)
{
    CRect* pCenterArea = new CRect( (long)( m_nScrmH / m_fCrsTlkRectFE ), 
		(long)( m_nScrmV / m_fCrsTlkRectFE ), 
		(long)( m_nScrmH - m_nScrmH / m_fCrsTlkRectFE), 
		(long)( m_nScrmV - m_nScrmV / m_fCrsTlkRectFE) );
	
    CBrush* pBrush = new CBrush(CntrClr);
    pDC->FillRect(pCenterArea, pBrush);
    delete pBrush;
    delete pCenterArea;
}

void Bolt::CenterCross(CDC* pDC, COLORREF CrosColor)
{
	CPoint hStart(0, m_nScrmV/2), hEnd(m_nScrmH, m_nScrmV/2);
	CPoint vStart(m_nScrmH/2, 0), vEnd(m_nScrmH/2, m_nScrmV);
	
 	CPen pen;
 	pen.CreatePen(PS_SOLID, 1, CrosColor); 
 	CPen* oldPen = pDC->SelectObject(&pen); 

	//H line
	pDC->MoveTo(hStart);
	pDC->LineTo(hEnd);
	//V line
	pDC->MoveTo(vStart);
	pDC->LineTo(vEnd);

 	pDC-> SelectObject(oldPen);
	pen.DeleteObject();
}

void Bolt::SetJNDBkColor(COLORREF color)
{
    m_JNDBkColor = color;
}

COLORREF Bolt::GetJDNBkColor() const
{
	return m_JNDBkColor;
}
BOOL Bolt::Set5NitsBkColor(COLORREF color)
{
    m_5nitsBkColor = color;	
    return TRUE;
}

COLORREF Bolt::Get5NitsBkColor() const
{
    return m_5nitsBkColor;
}

CPoint Bolt::GetPointPosition() const
{
// 	CString str;
// 	str.Format("%d, %d", m_MsrFlowNo, m_MsrFlowNum);
// 	AfxMessageBox(str);

    switch(m_MsrFlowNum)
    {
        case Pn1:
            //中心點定義不分
            return GetFE9Point(4);
        case Pn4:
            return GetCrossTalk(m_MsrFlowNo);
        case Pn5:
            return GetFE5Point(m_MsrFlowNo);
        case Pn9:
            //九點週邊定義各有不同
            //分白、黑、5Nits
            if(m_BkColor == Nits)  return Get5nits9Point(m_MsrFlowNo);
			else                   return GetFE9Point(m_MsrFlowNo);
        case Pn13:
            return GetD13Point(m_MsrFlowNo);
        case Pn21:
			return GetD21Point(m_MsrFlowNo);
        case Pn25:
            return GetD25Point(m_MsrFlowNo);
        case Pn49:
            return GetW49Point(m_MsrFlowNo);
		case PnGamma:
			return GetGammaPoint();
        default:
            return GetFE9Point(0);
    }
}

int Bolt::GetRadius() const
{
    return m_Radius;
}

CString Bolt::GetMsrFlowName() const
{
    CString clr("NotReady");
    CString ptnum("NotReady");

    switch(m_BkColor)
    {
		case White:     clr.Format("白色");        break;
		case Dark:      clr.Format("黑色");        break;
		case Red:       clr.Format("紅色");        break;
		case Blue:      clr.Format("藍色");        break;
		case Green:     clr.Format("綠色");        break;
		case Nits:      clr.Format("5Nits");       break;
		case CrsTlk:    clr.Format("CrossTalk");   break;
		case CrsTlkW:   clr.Format("CrossTalkW");  break;
		case CrsTlkD:   clr.Format("CrossTalkD");  break;
    }

    switch(m_MsrFlowNum)
    {
        case Pn1:     ptnum.Format("中心點");  break;
        case Pn4:     ptnum.Format("4點");    break;
        case Pn5:     ptnum.Format("5點");    break;
        case Pn9:     ptnum.Format("9點");    break;
        case Pn49:    ptnum.Format("49點");   break;
        case Pn13:    ptnum.Format("13點");   break;
		case Pn21:    ptnum.Format("21點");   break;
        case Pn25:    ptnum.Format("25點");   break;
		case PnGamma: ptnum.Format("Gamma");  break;
    }
 
    CString temp;
    temp.Format("%s%s", clr, ptnum);
    return temp;
}

AreaKind Bolt::PointToArea(CPoint p) const
{
//         Set Area Code
//         +--+--+--+
//         |02|03|07|
//         +--a--+--+
//         |04|01|08|
//         +--+--d--+
//         |05|06|09|
//         +--+--+--+
	
	CPoint centerPoint(m_nScrmH/2, m_nScrmV/2);
	const int shift = 0;
	CPoint aP(centerPoint.x - shift, centerPoint.y - shift), 
		   dP(centerPoint.x + shift, centerPoint.y + shift);
	
// 	CString str;
// 	//str.Format("point: %d, %d\naPoint: %d, %d\ndPoint: %d, %d", p.x, p.y, aP.x, aP.y, dP.x, dP.y);
// 	str.Format("X:%d, Y:%d", m_nScrmH/2, m_nScrmV/2);
// 	AfxMessageBox(str);

	    if (p.y < aP.y)
		{
			if ( (p.x >= 0) && (p.x < aP.x)) return AA_02; 
			else if ( (p.x >= aP.x) && (p.x <= dP.x) ) return AA_03;
			else                                                     return AA_07;
		}
		else if ((p.y >= aP.y) && (p.y <= dP.y))
		{
			if ( (p.x >= 0) && (p.x < aP.x)) return AA_04; 
			else if ( (p.x >= aP.x) && (p.x <= dP.x) ) return AA_01;
			else                                                     return AA_08;
		}
		else
		{
			if ( (p.x >= 0) && (p.x < aP.x)) return AA_05; 
			else if ( (p.x >= aP.x) && (p.x <= dP.x) ) return AA_06;
			else                                                     return AA_09;
		}
}

void Bolt::Grow(xChain& vCar, Cartridge& MsrCell)
{
	m_BkColor    = MsrCell.GetBackColor();        //背景色標籤
    m_MsrFlowNum = MsrCell.GetMsrFlowNum();       //點數標籤

    UINT areaCode = 0;
	UINT origCode = 0;

    for (m_MsrFlowNo = 0; m_MsrFlowNo < (UINT)m_MsrFlowNum; ++m_MsrFlowNo)
    {
        MsrCell.SetMsrFlowNo(m_MsrFlowNo);
		CPoint hitPoint(GetPointPosition());

// 		CString str;
// 		str.Format("%d, %d", hitPoint.x, hitPoint.y);
// 		AfxMessageBox(str);

		switch( PointToArea (hitPoint) )
		{
		case AA_01: 
			areaCode = 1;
			origCode = ( MsrCell.GetMsrFlowNum() == PnGamma )? ( vCar.size() + 1 ) : 1 ; 
			break;

		case AA_02: areaCode = 2; origCode = vCar.size() + 1; break;
		case AA_03: areaCode = 3; origCode = vCar.size() + 1; break;
		case AA_04: areaCode = 4; origCode = vCar.size() + 1; break;
		case AA_05: areaCode = 5; origCode = vCar.size() + 1; break;
		case AA_06: areaCode = 6; origCode = vCar.size() + 1; break;
		case AA_07: areaCode = 7; origCode = vCar.size() + 1; break;
		case AA_08: areaCode = 8; origCode = vCar.size() + 1; break;
		case AA_09: areaCode = 9; origCode = vCar.size() + 1; break;
		default:    areaCode = 0; origCode = vCar.size() + 1;
		}
        MsrCell.SetArea(areaCode);
		MsrCell.SetOrigSeqc(origCode);

        vCar.push_back(MsrCell);
    }
}

NitsKind Bolt::GetNitsKind(){ return m_nNitsKind;}
//////////////////////////////////////////////////////////////////////////
//Msr Parameter
Bolt* Bolt::SetP5FE(float P5FE)               {m_f5FE          = P5FE;                         return this;}
Bolt* Bolt::SetP9FE(float P9FE)               {m_f9FE          = P9FE;                         return this;}
Bolt* Bolt::SetP13FE(float P13FE)             {m_f13FE         = P13FE;                        return this;}
Bolt* Bolt::SetP21FE(float P21FE)             {m_f21FE         = P21FE;                        return this;}
Bolt* Bolt::SetP21Avg(float Havg, float Vavg) {m_f21Havg       = Havg;    m_f21Vavg = Vavg;    return this;}
Bolt* Bolt::SetP25FE(float P25FE)             {m_f25FE         = P25FE;                        return this;}
Bolt* Bolt::SetP25RectSide(UINT SideLong)     {m_n25RectSide   = SideLong;                     return this;}
Bolt* Bolt::SetGammaRange(UINT GM1, UINT GM2) {m_nGM1          = GM1;     m_nGM2    = GM2;     return this;}
Bolt* Bolt::GammaStep(float GmStep)           {m_fGammaSetp    = GmStep;                       return this;}
Bolt* Bolt::SetNitsNum(float NitsNum)         {m_fNits         = NitsNum;                      return this;}
Bolt* Bolt::SetNitsKind(NitsKind nk)          {m_nNitsKind     = nk;				           return this;}

Bolt* Bolt::SetCrsTlkRectFE(float RectSideFE) {m_fCrsTlkRectFE = RectSideFE;                   return this;}

//////////////////////////////////////////////////////////////////////////
//debug function

#ifdef _DEBUG

CString  Bolt::GetSetupValue() const
{
    CString str;
    
    str.Format("解析度(%d×%d), 半徑 = %d, 顏色項目點: %s/%d/%d, 5Nits背景色(%d,%d,%d), 背景色(%d,%d,%d)", \
        m_nScrmH, m_nScrmV, m_Radius, GetMsrFlowName(), m_MsrFlowNo, m_MsrFlowNum, \
        GetRValue(m_5nitsBkColor), GetGValue(m_5nitsBkColor), GetBValue(m_5nitsBkColor), \
        GetRValue(GetBkColor()), GetGValue(GetBkColor()), GetBValue(GetBkColor())
        );
    
    return str;
}

#endif
