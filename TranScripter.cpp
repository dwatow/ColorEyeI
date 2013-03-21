#include "TranScripter.h"
#include "MainFrm.h"
#include <cmath>

#ifdef _DEBUG
#define DebugCode( code_fragment ) { code_fragment }
#else
#define DebugCode( code_fragment )
#endif

/***************************************************
 *    getFE9Point(UINT few, float FromEdge)  const *
 *    getFE5Point(UINT few, float FromEdge)  const *
 *    get5nits9Point(UINT few)               const *
 *    getD13Point(UINT few)                  const *
 *    getD21Point(UINT few, float hDeciLeftEdge, float vDeciLeftEdge, float FromEdge) const
 *    getD25Point(UINT few, UINT side)       const *
 *    getW49Point(UINT few)                  const *
 *    getCrossTalk(UINT few, float FromEdge) const *
 ***************************************************/
void TranScripter::checkPointValue(const int _hCI, const int _vCI) const
{
    ASSERT(_hCI > 0);
    ASSERT(_hCI < m_nScrmH);

    ASSERT(_vCI > 0);
    ASSERT(_vCI < m_nScrmV);
}

void TranScripter::checkPointValue(const double dFE, const int _cm2pixel) const
{
    ASSERT(dFE >= 0); //dFE
    ASSERT(_cm2pixel > 0);  //Cm2pixel(2.3)
}

CPoint TranScripter::getCenterPoint() const
{
//運算第幾個（以九點為計）
    //ScrmV 螢幕垂直pixel數
    //ScrmH 螢幕水平pixel數
    const int hCenter(m_nScrmH/2);
    const int vCenter(m_nScrmV/2);

    checkPointValue(hCenter, vCenter);
    
/*
+------------------------------+
|                              |
|                              |
|                              |
|                              |
|              04              |
|                              |
|                              |
|                              |
|                              |
+------------------------------+
*/
    const CPoint PointD(hCenter  ,vCenter);

//回傳一個點
    return PointD;

}

CPoint TranScripter::getFE9Point(UINT few) const
{
//運算第幾個（以九點為計）
    const double dFE = (double)m_tranPointer->GetPara(PA_FEover);
    //ScrmV 螢幕垂直pixel數
    //ScrmH 螢幕水平pixel數
    const int LeftEdge((dFE) ? static_cast<int>(m_nScrmH / dFE) : Cm2pixel(2.3));
    const int TopEdge((dFE) ? static_cast<int>(m_nScrmV / dFE) : Cm2pixel(2.3));
    const int RightEdge(m_nScrmH - LeftEdge);
    const int BottomEdge(m_nScrmV - TopEdge);
    const int hCenter(m_nScrmH/2);
    const int vCenter(m_nScrmV/2);

    checkPointValue(dFE, Cm2pixel(2.3));
    checkPointValue(LeftEdge, TopEdge);
    checkPointValue(RightEdge, BottomEdge);
    checkPointValue(hCenter, vCenter);
    
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
    const double dFE = (double)m_tranPointer->GetPara(PA_FEover);
    const int LeftEdge   = (dFE) ? static_cast<int>(m_nScrmH / dFE) : Cm2pixel(2.3);
    const int TopEdge    = (dFE) ? static_cast<int>(m_nScrmV / dFE) : Cm2pixel(2.3);
    const int RightEdge  = m_nScrmH - LeftEdge;
    const int BottomEdge = m_nScrmV - TopEdge;
    const int hCenter    = m_nScrmH/2;
    const int vCenter    = m_nScrmV/2;

    checkPointValue(dFE, Cm2pixel(2.3));
    checkPointValue(LeftEdge, TopEdge);
    checkPointValue(RightEdge, BottomEdge);
    checkPointValue(hCenter, vCenter);
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
    const int LeftEdge   = Cm2pixel(10);
    const int TopEdge    = static_cast<int>(m_nScrmV / 6);//六分之一上邊緣
    const int RightEdge  = m_nScrmH - LeftEdge;
    const int BottomEdge = m_nScrmV - TopEdge;
    const int hCenter    = m_nScrmH/2;
    const int vCenter    = m_nScrmV/2;
    checkPointValue(Cm2pixel(2.3));
    checkPointValue(LeftEdge, TopEdge);
    checkPointValue(RightEdge, BottomEdge);
    checkPointValue(hCenter, vCenter);
    
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
    const double dFE = (double)m_tranPointer->GetPara(PA_FEover);

    const int LeftEdge  ((dFE) ? static_cast<int>(m_nScrmH / dFE) : Cm2pixel(2.3));//左邊緣
    const int TopEdge   ((dFE) ? static_cast<int>(m_nScrmV / dFE) : Cm2pixel(2.3));//上邊緣
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
    checkPointValue(dFE, Cm2pixel(2.3));
    checkPointValue(LeftEdge, TopEdge);
    checkPointValue(RightEdge, BottomEdge);
    checkPointValue(hCenter, vCenter);

    checkPointValue(hPitch, vPitch);
    checkPointValue(L1, T1);
    checkPointValue(R1, B1);
    
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
    const double dFE = (double)m_tranPointer->GetPara(PA_FEover);
    const int LeftEdge((dFE) ? static_cast<int>(m_nScrmH / dFE) : Cm2pixel(2.3));
    const int TopEdge((dFE) ? static_cast<int>(m_nScrmV / dFE) : Cm2pixel(2.3));
    const int RightEdge(m_nScrmH - LeftEdge);
    const int BottomEdge(m_nScrmV - TopEdge);

    const int hCenter(m_nScrmH/2);
    const int vCenter(m_nScrmV/2);


    int hPitch( m_nScrmH / 6 );
    int vPitch( m_nScrmV / 4 );

    if (dFE)
    {
        hPitch = (m_nScrmH - ((m_nScrmH/dFE)*2.0)) / 7.0;
        vPitch = (m_nScrmV - ((m_nScrmV/dFE)*2.0)) / 5.0;
    }

    const int L2(hCenter - hPitch), L1(L2 - hPitch), R2(hCenter + hPitch), R1(R2 + hPitch);

    const int T1(vCenter - vPitch);
    const int B1(vCenter + vPitch);

    checkPointValue(dFE, Cm2pixel(2.3));
    checkPointValue(LeftEdge, TopEdge);
    checkPointValue(RightEdge, BottomEdge);
    checkPointValue(hCenter, vCenter);
    
    checkPointValue(hPitch, vPitch);
    checkPointValue(L1, T1);
    checkPointValue(L2, T1);
    checkPointValue(R1, B1);    
    checkPointValue(R2, B1);

    
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
        Point04(LeftEdge, TopEdge), Point05(L1, TopEdge), Point06(L2, TopEdge), Point07(hCenter, TopEdge), Point08(R2, TopEdge), Point09(R1, TopEdge), Point10(RightEdge, TopEdge),
        Point03(LeftEdge, T1),                                                                                      Point11(RightEdge, T1),
        Point02(LeftEdge, vCenter),                                   Point20(hCenter, vCenter),                                   Point12(RightEdge, vCenter),
        Point01(LeftEdge, B1),                                                                                      Point13(RightEdge, B1),
        Point00(LeftEdge, BottomEdge), Point19(L1, BottomEdge), Point18(L2, BottomEdge), Point17(hCenter, BottomEdge), Point16(R2, BottomEdge), Point15(R1, BottomEdge), Point14(RightEdge, BottomEdge),
        
        PointD(hCenter,vCenter);

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
    const double dFE = (double)m_tranPointer->GetPara(PA_FEover);
    const int fRectSide = m_tranPointer->GetPara(PA_D25RectSide);

    const int LeftEdge   = (dFE) ? static_cast<int>(m_nScrmH / dFE) : Cm2pixel(2.3);
    const int TopEdge    = (dFE) ? static_cast<int>(m_nScrmV / dFE) : Cm2pixel(2.3);

 //   const int LeftEdge   = Cm2pixel(2.3);
    const int L1    = LeftEdge + Cm2pixel(fRectSide/2);
    const int L2    = L1       + Cm2pixel(fRectSide/2);

    const int RightEdge  = m_nScrmH - LeftEdge;
    const int R1   = RightEdge - Cm2pixel(fRectSide/2);
    const int R2   = R1        - Cm2pixel(fRectSide/2);
    
    const int hCenter    = m_nScrmH/2;
    const int vCenter    = m_nScrmV/2;

//    const int TopEdge    = Cm2pixel(2.3);//上邊緣
    const int T1     = TopEdge + Cm2pixel(fRectSide/2);
    const int T2     = T1  + Cm2pixel(fRectSide/2);

    const int BottomEdge = m_nScrmV - TopEdge;
    const int B1  = BottomEdge - Cm2pixel(fRectSide/2);
    const int B2  = B1  - Cm2pixel(fRectSide/2);

    checkPointValue(dFE, Cm2pixel(2.3));
    checkPointValue(LeftEdge, TopEdge);
    checkPointValue(RightEdge, BottomEdge);
    checkPointValue(hCenter, vCenter);
    
    checkPointValue(L1, T1);
    checkPointValue(R1, B1);    
    checkPointValue(L2, T2);
    checkPointValue(R2, B2);


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
        Point00(LeftEdge, TopEdge),        Point01(L2, TopEdge),

                    Point04(L1, T1),

        Point02(LeftEdge, T2),        Point03(L2, T2),
                        
                            
        Point05(hCenter, TopEdge),


        Point07(R2, TopEdge),        Point06(RightEdge, TopEdge),
        
                    Point10(R1 ,T1),

        Point09(R2, T2),        Point08(RightEdge,T2),
        //--------------------
        Point11(LeftEdge, vCenter),

        Point12(hCenter, vCenter),

        Point13(RightEdge, vCenter),
        //--------------------
        Point16(LeftEdge ,B2),    Point17(L2    ,B2),

                    Point18(L1, B1),

        Point14(LeftEdge,BottomEdge),    Point15(L2    ,BottomEdge),
        
        Point19(hCenter ,BottomEdge),

        Point23(R2, B2),    Point22(RightEdge  ,B2),

                    Point24(R1, B1),

        Point21(R2 ,BottomEdge),    Point20(RightEdge  ,BottomEdge),
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
    const int LeftEdge = m_nScrmH  / 12;   //左數1直排
    const int L1 = LeftEdge  *  2;   //左數2直排
    const int L2 = L1 *  2;   //左數3直排

    const int TopEdge = m_nScrmV / 12;    //上數1橫排
    const int T1  = TopEdge  * 2;    //上數2橫排
    const int T2  = T1 * 2;    //上數2橫排

    const int RightEdge  = m_nScrmH -  LeftEdge;   //右數1直排
    const int R1 = m_nScrmH - L1;   //右數2直排
    const int R2 = m_nScrmH - L2;   //右數3直排

    const int BottomEdge = m_nScrmV -  TopEdge;    //下數1橫排
    const int B1= m_nScrmV - T1;    //下數2橫排
    const int B2= m_nScrmV - T2;    //下數3橫排

    const int hCenter = m_nScrmH/2;  //水平中心
    const int vCenter = m_nScrmV/2;  //垂直中心

    checkPointValue(LeftEdge, TopEdge);
    checkPointValue(RightEdge, BottomEdge);
    checkPointValue(hCenter, vCenter);
    
    checkPointValue(L1, T1);
    checkPointValue(R1, B1);    
    checkPointValue(L2, T2);
    checkPointValue(R2, B2);

/*   L1  L2          R2  R1
+------------------------------+
|                              |
| 00 01  02    03    04  05 06 |
| 10 11  12    13    14  15 16 |T1
| 20 21  22    23    24  25 26 |T2
| 30 31  32    33    34  35 36 |
| 40 41  42    43    44  45 46 |B2
| 50 51  52    53    54  55 56 |B1
| 60 61  62    63    64  65 66 |
|                              |
+------------------------------+
*/
    const CPoint 
        Point00(LeftEdge  ,TopEdge),
        Point01(L1 ,TopEdge),
        Point02(L2 ,TopEdge),
        Point03(hCenter   ,TopEdge),
        Point04(R2,TopEdge),
        Point05(R1,TopEdge),
        Point06(RightEdge ,TopEdge),

        Point10(LeftEdge  ,T1),
        Point11(L1 ,T1),
        Point12(L2 ,T1),
        Point13(hCenter   ,T1),
        Point14(R2,T1),
        Point15(R1,T1),
        Point16(RightEdge ,T1),

        Point20(LeftEdge  ,T2),
        Point21(L1 ,T2),
        Point22(L2 ,T2),
        Point23(hCenter   ,T2),
        Point24(R2,T2),
        Point25(R1,T2),
        Point26(RightEdge ,T2),

        Point30(LeftEdge  ,vCenter),
        Point31(L1 ,vCenter),
        Point32(L2 ,vCenter),
        Point33(hCenter   ,vCenter),//中心點
        Point34(R2,vCenter),
        Point35(R1,vCenter),
        Point36(RightEdge ,vCenter),

        Point40(LeftEdge  ,B2),
        Point41(L1 ,B2),
        Point42(L2 ,B2),
        Point43(hCenter   ,B2),
        Point44(R2,B2),
        Point45(R1,B2),
        Point46(RightEdge ,B2),

        Point50(LeftEdge  ,B1),
        Point51(L1 ,B1),
        Point52(L2 ,B1),
        Point53(hCenter   ,B1),
        Point54(R2,B1),
        Point55(R1,B1),
        Point56(RightEdge ,B1),

        Point60(LeftEdge  ,BottomEdge),
        Point61(L1 ,BottomEdge),
        Point62(L2 ,BottomEdge),
        Point63(hCenter   ,BottomEdge),
        Point64(R2,BottomEdge),
        Point65(R1,BottomEdge),
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
    const double dFE = (double)m_tranPointer->GetPara(PA_FEover)* 2;

    const int LeftEdge   = static_cast<int>(m_nScrmH / dFE);    //上
    const int TopEdge    = static_cast<int>(m_nScrmV / dFE);    //下
    const int RightEdge  = m_nScrmH - LeftEdge;  //左
    const int BottomEdge = m_nScrmV - TopEdge;   //右
    const int hCenter    = m_nScrmH/2;
    const int vCenter    = m_nScrmV/2;

    checkPointValue(LeftEdge, TopEdge);
    checkPointValue(RightEdge, BottomEdge);
    checkPointValue(hCenter, vCenter);
    checkPointValue(dFE);
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

int TranScripter::Cm2pixel(const double cm) const
{    
    CMainFrame* pMainFrm = dynamic_cast<CMainFrame*>(AfxGetMainWnd());
    ASSERT_VALID(pMainFrm);
    ASSERT(pMainFrm->m_pCa210);
    //開啟舊檔時, pMainFrm->m_pCa210 為空指標
    //有量測（與CA-210連線）時, pMainFrm->m_pCa210 有指向儀器
    float LCMsize;

    if(pMainFrm->m_pCa210 == 0)
        LCMsize = 0.0;
    else
        LCMsize = atof(pMainFrm->m_pCa210->GetLcmSize());

    return (int)(m_nScrmV*cm / (LCMsize * sin( atan((double)m_nScrmV/(double)m_nScrmH) ) * 2.54));
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
{
	DebugCode(
		CColorEyeIApp* pApp = dynamic_cast<CColorEyeIApp*>(AfxGetApp());
		ASSERT_VALID(pApp);
		m_desktopPath.Format("%s", pApp->GetDesktopPath());
    )
}

void TranScripter::Trans(DNA& _vD, RNA& _vR)
{
    ASSERT(_vD.Size());

	std::vector<Cartridge2> tempNits;
	BkMaker* NitsClr = 0;

    m_tranPointer = _vD.Begin();
    for (m_tranPointer = _vD.Begin(); m_tranPointer != _vD.End(); ++m_tranPointer)
    {
        const UINT msrFrowNoMax = m_tranPointer->GetMsrFlowNum();
        for (unsigned int msrFlowNo = 0; msrFlowNo < msrFrowNoMax; ++msrFlowNo)
        {
            Cartridge2 tempCar;
			tempCar.SetBkStatus(tranBkStatus(msrFlowNo));
            tempCar.SetBkColor(tranColor(msrFlowNo));
            tempCar.SetPointPosi(tranPoint(msrFlowNo));
            
            setSquence(tempCar, _vR.Size(), msrFlowNo);
            
            tempCar.SetDescrip(tranDescrip(msrFlowNo));

			forCrsTlk(tempCar);
//vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv//中間不要動！5nits靠它了！
			if (m_tranPointer->GetBackColor() == Nits)
			{
				//if (msrFlowNo == m_tranPointer->GetMsrFlowNum()/2)
				if (tempCar.getSqncFrm() == 1)
				{
					NitsClr = tempCar.m_pBackGorund;
					NitsClr->_SetBkColor(RGB(123, 123, 123));
 					_vR.AddCell(tempCar);
				}
				else
					tempNits.push_back(tempCar);
			}
 			else
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
				_vR.AddCell(tempCar);
        }
//vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv//中間不要動！5nits靠它了！
		if (m_tranPointer->GetBackColor() == Nits)
		{
			for (std::vector<Cartridge2>::iterator nitsitor = tempNits.begin(); nitsitor != tempNits.end(); ++nitsitor)
			{
				delete nitsitor->m_pBackGorund;
				nitsitor->m_pBackGorund = NitsClr;
			}
			_vR.AddCell(tempNits.begin(), tempNits.end());
		}
    }
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
	DebugCode(
        CTxtFile fTxt;
		CFileException fx;
		fTxt.Save(m_desktopPath+"//TranS.log", fx);
		fTxt.iTxtData(m_dTxt);
		fTxt.Close();
    )
}

BackGroundStatus TranScripter::tranBkStatus(UINT msrFlowNo) const
{
	BackGroundStatus status;
	ColorType ct = m_tranPointer->GetBackColor();
	if ( (ct == Nits) && (msrFlowNo == m_tranPointer->GetMsrFlowNum()/2) )
	{
		if (m_tranPointer->GetPara(PA_NitsDir) == 1) //Neg
			status = BGS_NitsNeg;
		else if (m_tranPointer->GetPara(PA_NitsDir) == 0) //Pos
			status = BGS_NitsPos;
	}
	else if (ct == CrsTlkD)
		status = BGS_CrossTalkDark;
	else if (ct == CrsTlkW)
		status = BGS_CrossTalkWrite;
	else
		status = BGS_Normal;
	return status;
}

void TranScripter::forCrsTlk(Cartridge2& crtg)
{
    ColorType ct = m_tranPointer->GetBackColor();
	if (ct == CrsTlkD || ct == CrsTlkW)
	{
		ColorRef _clr;
		if (ct == CrsTlkD)
			_clr.iRGB(0, 0, 0);
		else if (ct == CrsTlkW)
			_clr.iRGB(255, 255, 255);
		
		int m_fCrsTlkRectFE = m_tranPointer->GetPara(PA_FEover);
		ASSERT(m_fCrsTlkRectFE > 0);
		
		CRect _rect = 
			new CRect( (long)( m_nScrmH / m_fCrsTlkRectFE ), 
			(long)( m_nScrmV / m_fCrsTlkRectFE ), 
			(long)( m_nScrmH - m_nScrmH / m_fCrsTlkRectFE), 
			(long)( m_nScrmV - m_nScrmV / m_fCrsTlkRectFE) );
		
		crtg.m_pBackGorund->CT_SetRect(_rect, _clr);
	}
}

ColorRef TranScripter::tranColor(UINT flowNo) const
{
	ColorRef clr;
    if (m_tranPointer->GetMsrFlowNum() == PnGamma)
        switch(m_tranPointer->GetBackColor())
        {
            case Red:      clr.iRGB( flowNo,      0,      0); break;
            case Green:    clr.iRGB(      0, flowNo,      0); break;
            case Blue:     clr.iRGB(      0,      0, flowNo); break;
            case White:    
            case Dark:     
            default:       clr.iRGB(flowNo, flowNo, flowNo);
        }
    else
        switch(m_tranPointer->GetBackColor())
        {
            case White:    clr.iRGB( 255, 255, 255); break;
            case Dark:     clr.iRGB(   0,   0,   0); break;
            case Red:      clr.iRGB( 255,   0,   0); break;
            case Green:    clr.iRGB(   0, 255,   0); break;
            case Blue:     clr.iRGB(   0,   0, 255); break;
            case Nits:     clr.iRGB( 192, 212,  49);
				return m_tranPointer->GetPara(PA_NitsNum);
            case JNDX:
            case JND:      
				return m_tranPointer->GetPara(PA_JndGrayLv);
            case CrsTlk: 
            case CrsTlkW:
            case CrsTlkD:  clr.iRGB( 128, 128, 128); break;
            default:       clr.iRGB( 192, 212,  49);
        }
	return clr;
}

CPoint TranScripter::tranPoint(UINT flowNo) const
{
    switch(m_tranPointer->GetMsrFlowNum())
    {
    case Pn1:        return getCenterPoint();        //中心點定義不分
    case Pn4:        return getCrossTalk(flowNo);
    case Pn5:        return getFE5Point(flowNo);
    case Pn9:    if (m_tranPointer->GetBackColor() == Nits)          //九點週邊定義各有不同
                     return get5nits9Point(flowNo);        //分白、黑、5Nits
                 else
                     return getFE9Point(flowNo);
    case Pn13:       return getD13Point(flowNo);
    case Pn21:       return getD21Point(flowNo);
    case Pn25:       return getD25Point(flowNo);
    case Pn49:       return getW49Point(flowNo);
    case PnGamma:    return getCenterPoint();
    default:         return getFE9Point(0);
    }    
}

CString TranScripter::tranDescrip(UINT flowNo) const
{
    CString color, poNum, poNo, para;

    color = m_tranPointer->GetStrColorType();
    poNum = m_tranPointer->GetStrPointNum();
    para  = m_tranPointer->GetStrPara();
    
    poNo.Format(", 第%d點", flowNo+1 );
    
    return color + poNum + poNo + para;
}

void TranScripter::setSquence(Cartridge2& _Car, std::vector<Nucleotide>::size_type size, int msrFlowNo) const
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
    if (msrFlowNo <  m_tranPointer->GetMsrFlowNum()/2) _Car.setSqncFrm(size + 2); 
    if (msrFlowNo == m_tranPointer->GetMsrFlowNum()/2) _Car.setSqncFrm(1);
    if (msrFlowNo >  m_tranPointer->GetMsrFlowNum()/2) _Car.setSqncFrm(size + 1);
}
