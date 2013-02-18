#include "TranScripter.h"
#include "MainFrm.h"
#include <cmath>

/***************************************************
 *    getFE9Point(UINT few, float FromEdge)  const *
 *    getFE5Point(UINT few, float FromEdge)  const *
 *    get5nits9Point(UINT few)               const *
 *    getD13Point(UINT few)                  const *
 *    getD21Point(UINT few, float hDecile, float vDecile, float FromEdge) const
 *    getD25Point(UINT few, UINT side)       const *
 *    getW49Point(UINT few)                  const *
 *    getCrossTalk(UINT few, float FromEdge) const *
 ***************************************************/

CPoint TranScripter::getFE9Point(UINT few) const
{
//運算第幾個（以九點為計）
	const int nFE = m_tranPointer->GetPara(PA_FEover);
    //ScrmV 螢幕垂直pixel數
    //ScrmH 螢幕水平pixel數
    const int LeftEdge   = (nFE) ? static_cast<int>(m_nScrmH / nFE) : cm2pixel(2.3);
    const int TopEdge    = (nFE) ? static_cast<int>(m_nScrmV / nFE) : cm2pixel(2.3);
    const int RightEdge  = m_nScrmH - LeftEdge;
    const int BottomEdge = m_nScrmV - TopEdge;
    const int hCenter    = m_nScrmH/2;
    const int vCenter    = m_nScrmV/2;
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
    const CPoint 
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

CPoint TranScripter::getFE5Point(UINT few) const
{
//運算第幾個（以九點為計）

    //ScrmV 螢幕垂直pixel數
    //ScrmH 螢幕水平pixel數
	const int nFE = m_tranPointer->GetPara(PA_FEover);
    const int LeftEdge   = (nFE) ? static_cast<int>(m_nScrmH / nFE) : cm2pixel(2.3);
    const int TopEdge    = (nFE) ? static_cast<int>(m_nScrmV / nFE) : cm2pixel(2.3);
    const int RightEdge  = m_nScrmH - LeftEdge;
    const int BottomEdge = m_nScrmV - TopEdge;
    const int hCenter    = m_nScrmH/2;
    const int vCenter    = m_nScrmV/2;
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
    const CPoint 
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

CPoint TranScripter::get5nits9Point(UINT few) const
{
//運算第幾個（以九點為計）

    //ScrmV 螢幕垂直pixel數
    //ScrmH 螢幕水平pixel數
    const int LeftEdge   = cm2pixel(10);
    const int TopEdge    = static_cast<int>(m_nScrmV / 6);//六分之一上邊緣
    const int RightEdge  = m_nScrmH - LeftEdge;
    const int BottomEdge = m_nScrmV - TopEdge;
    const int hCenter    = m_nScrmH/2;
    const int vCenter    = m_nScrmV/2;
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
    const CPoint 
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

CPoint TranScripter::getD13Point(UINT few) const
{
//運算第幾個（以九點為計）

    //ScrmV 螢幕垂直pixel數
    //ScrmH 螢幕水平pixel數
	const int nFE = m_tranPointer->GetPara(PA_FEover);

	const int LeftEdge  ((nFE) ? static_cast<int>(m_nScrmH / nFE) : cm2pixel(2.3));//左邊緣
    const int TopEdge   ((nFE) ? static_cast<int>(m_nScrmV / nFE) : cm2pixel(2.3));//上邊緣
    const int RightEdge (m_nScrmH - LeftEdge);
    const int BottomEdge(m_nScrmV - TopEdge);

    const int hCenter(m_nScrmH/2);
    const int vCenter(m_nScrmV/2);

	const int hPitch((RightEdge-LeftEdge)/4);
	const int vPitch((BottomEdge-TopEdge)/4);

    const int L1(hCenter - hPitch);
    const int T1(vCenter - vPitch);

    const int R1(hCenter + hPitch);
    const int B1(vCenter + vPitch);
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
    const CPoint 
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

CPoint TranScripter::getD21Point(UINT few) const
{
//運算第幾個（以九點為計）

    //ScrmV 螢幕垂直pixel數
    //ScrmH 螢幕水平pixel數
	const int nFE = m_tranPointer->GetPara(PA_FEover);
    const int LE((nFE) ? static_cast<int>(m_nScrmH / nFE) : cm2pixel(2.3));
    const int TE((nFE) ? static_cast<int>(m_nScrmV / nFE) : cm2pixel(2.3));
    const int RE(m_nScrmH - LE);
    const int BE(m_nScrmV - TE);

    const int hC(m_nScrmH/2);
    const int vC(m_nScrmV/2);


	int hPitch( m_nScrmH / 6 );
	int vPitch( m_nScrmV / 4 );

	if (nFE)
	{
		hPitch = ((float)m_nScrmH - ((m_nScrmH/nFE)*2.0)) / 7.0;
		vPitch = ((float)m_nScrmV - ((m_nScrmV/nFE)*2.0)) / 5.0;
	}

    const int L2(hC - hPitch), L1(L2 - hPitch), R2(hC + hPitch), R1(R2 + hPitch);

    const int T1(vC - vPitch);
    const int B1(vC + vPitch);

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
    const CPoint 
        Point04(LE, TE), Point05(L1, TE), Point06(L2, TE), Point07(hC, TE), Point08(R2, TE), Point09(R1, TE), Point10(RE, TE),
        Point03(LE, T1),                                                                                      Point11(RE, T1),
        Point02(LE, vC),                                   Point20(hC, vC),                                   Point12(RE, vC),
        Point01(LE, B1),                                                                                      Point13(RE, B1),
        Point00(LE, BE), Point19(L1, BE), Point18(L2, BE), Point17(hC, BE), Point16(R2, BE), Point15(R1, BE), Point14(RE, BE),
        
        PointD(hC,vC);

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

CPoint TranScripter::getD25Point(UINT few) const
{
    //ScrmV 螢幕垂直pixel數
    //ScrmH 螢幕水平pixel數
	const int nFE = m_tranPointer->GetPara(PA_FEover);
	const int fRectSide = m_tranPointer->GetPara(PA_D25RectSide);

    const int LeftEdge   = (nFE) ? static_cast<int>(m_nScrmH / nFE) : cm2pixel(2.3);
    const int TopEdge    = (nFE) ? static_cast<int>(m_nScrmV / nFE) : cm2pixel(2.3);

 //   const int LeftEdge   = cm2pixel(2.3);
    const int Left_10    = LeftEdge + cm2pixel(fRectSide/2);
    const int Left_20    = Left_10  + cm2pixel(fRectSide/2);

    const int RightEdge  = m_nScrmH - LeftEdge;
    const int Right_10   = RightEdge - cm2pixel(fRectSide/2);
    const int Right_20   = Right_10  - cm2pixel(fRectSide/2);
    
    const int hCenter    = m_nScrmH/2;
    const int vCenter    = m_nScrmV/2;

//    const int TopEdge    = cm2pixel(2.3);//上邊緣
    const int Top_10     = TopEdge + cm2pixel(fRectSide/2);
    const int Top_20     = Top_10  + cm2pixel(fRectSide/2);

    const int BottomEdge = m_nScrmV - TopEdge;
    const int Bottom_10  = BottomEdge - cm2pixel(fRectSide/2);
    const int Bottom_20  = Bottom_10  - cm2pixel(fRectSide/2);

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
    const CPoint 
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

CPoint TranScripter::getW49Point(UINT few) const
{
//運算第幾個（以49點為計）

    //ScrmV 螢幕垂直pixel數
    //ScrmH 螢幕水平pixel數
    const int LeftEdge  = m_nScrmH  / 12;   //左數1直排
    const int DLeftEdge = LeftEdge  *  2;   //左數2直排
    const int FLeftEdge = DLeftEdge *  2;   //左數3直排

    const int TopEdge   = m_nScrmV / 12;    //上數1橫排
    const int DTopEdge  = TopEdge  * 2;    //上數2橫排
    const int FTopEdge  = DTopEdge * 2;    //上數2橫排

    const int RightEdge  = m_nScrmH -  LeftEdge;   //右數1直排
    const int DRightEdge = m_nScrmH - DLeftEdge;   //右數2直排
    const int FRightEdge = m_nScrmH - FLeftEdge;   //右數3直排

    const int BottomEdge = m_nScrmV -  TopEdge;    //下數1橫排
    const int DBottomEdge= m_nScrmV - DTopEdge;    //下數2橫排
    const int FBottomEdge= m_nScrmV - FTopEdge;    //下數3橫排

    const int hCenter = m_nScrmH/2;  //水平中心
    const int vCenter = m_nScrmV/2;  //垂直中心
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
    const CPoint 
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


CPoint TranScripter::getCrossTalk(UINT few) const
{
//運算第幾個（以九點為計）
	//不可以貼邊

    //ScrmV 螢幕垂直pixel數
    //ScrmH 螢幕水平pixel數
	const int nFE = m_tranPointer->GetPara(PA_FEover)* 2;

    const int LeftEdge   = static_cast<int>(m_nScrmH / nFE);    //上
    const int TopEdge    = static_cast<int>(m_nScrmV / nFE);    //下
    const int RightEdge  = m_nScrmH - LeftEdge;  //左
    const int BottomEdge = m_nScrmV - TopEdge;   //右
    const int hCenter    = m_nScrmH/2;
    const int vCenter    = m_nScrmV/2;
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
    const CPoint 
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

CPoint TranScripter::getGammaPoint() const
{
//運算第幾個
    //ScrmV 螢幕垂直pixel數
    //ScrmH 螢幕水平pixel數

    const int hCenter    = m_nScrmH/2;
    const int vCenter    = m_nScrmV/2;
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
    const CPoint PointD (hCenter, vCenter);

//回傳一個點
	return PointD;
}

UINT TranScripter::cm2pixel(const double cm) const
{    
	CMainFrame* pMainFrm = dynamic_cast<CMainFrame*>(AfxGetMainWnd());
	ASSERT(pMainFrm);
	ASSERT(pMainFrm->m_pCa210);
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

TranScripter::TranScripter():
m_nScrmH(GetSystemMetrics(SM_CXSCREEN)), 
m_nScrmV(GetSystemMetrics(SM_CYSCREEN))
{}

void TranScripter::Trans(DNA& _vN, RNA& _vR)
{
	CPoint ScrmCenter(m_nScrmH/2, m_nScrmV/2);

	m_tranPointer = _vN.Begin();
	for (m_tranPointer = _vN.Begin(); m_tranPointer != _vN.End(); ++m_tranPointer)
	{
		UINT msrFrowNoMax = m_tranPointer->GetMsrFlowNum();
		for (unsigned int msrFlowNo = 0; msrFlowNo < msrFrowNoMax; ++msrFlowNo)
		{
			Cartridge2 abc;
			
			abc.SetBkColor(tranColor(msrFlowNo));
			abc.SetPointPosi(tranPoint(msrFlowNo));
			
			setSquence(abc, _vR.Size());
			abc.SetDescrip(tranDescrip(msrFlowNo));
			
			
			_vR.AddCell(abc);
		}
	}

}

COLORREF TranScripter::tranColor(UINT flowNo) const
{
	if (m_tranPointer->GetMsrFlowNum() == PnGamma)
		switch(m_tranPointer->GetBackColor())
	{
		case Red:      return RGB( flowNo,      0,      0);
		case Green:    return RGB(      0, flowNo,      0);
		case Blue:     return RGB(      0,      0, flowNo);
		case White:    
		case Dark:     
		default:       return RGB( flowNo, flowNo, flowNo);
	}
	else
		switch(m_tranPointer->GetBackColor())
	{
		case White:    return RGB( 255, 255, 255);
		case Dark:     return RGB(   0,   0,   0);
		case Red:      return RGB( 255,   0,   0);
		case Green:    return RGB(   0, 255,   0);
		case Blue:     return RGB(   0,   0, 255);
		case Nits:     return m_tranPointer->GetPara(PA_NitsNum);
		case JNDX:
		case JND:      return m_tranPointer->GetPara(PA_JndGrayLv);
		case CrsTlk: 
		case CrsTlkW:
		case CrsTlkD:  return RGB( 128, 128, 128);
		default:       return RGB( 192, 212,  49);
	}
}

CPoint TranScripter::tranPoint(unsigned int flowNo) const
{
	switch(m_tranPointer->GetMsrFlowNum())
	{
    case Pn1:
        //中心點定義不分
        return getFE9Point(4);
    case Pn4:
        return getCrossTalk(flowNo);
    case Pn5:
        return getFE5Point(flowNo);
    case Pn9:
        //九點週邊定義各有不同
        //分白、黑、5Nits
        if(m_tranPointer->GetBackColor() == Nits)  
			return get5nits9Point(flowNo);
		else
			return getFE9Point(flowNo);
    case Pn13:
        return getD13Point(flowNo);
    case Pn21:
		return getD21Point(flowNo);
    case Pn25:
        return getD25Point(flowNo);
    case Pn49:
        return getW49Point(flowNo);
	case PnGamma:
		return getGammaPoint();
    default:
        return getFE9Point(0);
	}	
}

CString TranScripter::tranDescrip(UINT flowNo) const
{
	CString color, poNum, poNo, para;
	switch(m_tranPointer->GetBackColor())
	{
	case White: color = "白色"; break;
	case Red:   color = "紅色"; break;
	case Blue:  color = "藍色"; break;
	case Green: color = "綠色"; break;
	case Dark:  color = "黑色"; break;
	case Nits:  color = "Nits"; break;
	case CrsTlk:
	case CrsTlkD:
	case CrsTlkW: color = "Cross Talk"; break;
	case JND:
	case JNDX:  color = "JND"; break;
	default:
		color = "無定義的顏色"; break;
	}

	poNum.Format("%d點", m_tranPointer->GetMsrFlowNum());
	poNo.Format("第%d點", flowNo);
	
	     if (m_tranPointer->GetPara(PA_FEover) == 0 || m_tranPointer->GetPara(PA_FEnum) == 0) para.Format("貼邊");
	else if (m_tranPointer->GetPara(PA_FEover) > 0) para.Format("離邊%d分之一", m_tranPointer->GetPara(PA_FEover));
	else if (m_tranPointer->GetPara(PA_FEnum) > 0)  para.Format("離邊%d公分", m_tranPointer->GetPara(PA_FEnum));
	else para.Empty();
	
	return color + poNum + poNo + para;
}

void TranScripter::setSquence(Cartridge2& _Car, std::vector<Nucleotide>::size_type size) const
{
	const CPoint center(m_nScrmH/2, m_nScrmV/2);
	const CPoint carPoint(_Car.GetPointPosi());
	const int shift = 5;
	const CPoint aP(center.x - shift, center.y - shift), 
	             dP(center.x + shift, center.y + shift);
	
	//從point判斷area code
	if (carPoint.y < aP.y)
	{
		if ( (carPoint.x >= 0) && (carPoint.x < aP.x)) _Car.setSqncArea(AA_02); 
		else if ( (carPoint.x >= aP.x) && (carPoint.x <= dP.x) ) _Car.setSqncArea(AA_03);
		else                                                     _Car.setSqncArea(AA_07);
	}
	else if ((carPoint.y >= aP.y) && (carPoint.y <= dP.y))
	{
		if ( (carPoint.x >= 0) && (carPoint.x < aP.x)) _Car.setSqncArea(AA_04); 
		else if ( (carPoint.x >= aP.x) && (carPoint.x <= dP.x) ) _Car.setSqncArea(AA_01);
		else                                                     _Car.setSqncArea(AA_08);
	}
	else
	{
		if ( (carPoint.x >= 0) && (carPoint.x < aP.x)) _Car.setSqncArea(AA_05); 
		else if ( (carPoint.x >= aP.x) && (carPoint.x <= dP.x) ) _Car.setSqncArea(AA_06);
		else                                                     _Car.setSqncArea(AA_09);
	}

	//依area code判斷順序的選擇
	if (_Car.getSqncArea() == AA_01)
	{
		if ( m_tranPointer->GetMsrFlowNum() == PnGamma )
		_Car.setSqncFrm( size + 1 );
		else
		_Car.setSqncFrm(1);
	}
	else
		_Car.setSqncFrm( size + 1);

}
