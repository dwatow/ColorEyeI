#include"stdafx.h"
#include <cmath>
#include "Bolt.h"

/********************************************
 *    GetFE9Point (UINT few, float FromEdge) *
 *    GetD9Point (UINT few, float FromEdge)	*
 *    GetW49Point(UINT few)					*
 *    GetD13Point(UINT few)					*
 *    GetD25Point(UINT few)					*
 *    GetD29Point(UINT few)					*
 ********************************************/

CPoint Bolt::GetFE9Point(UINT few, float FromEdge) const
{
//運算第幾個（以九點為計）

    //ScrmV 螢幕垂直pixel數
    //ScrmH 螢幕水平pixel數
    UINT LeftEdge   = (FromEdge) ? static_cast<UINT>(m_nScrmH / FromEdge) : CmtoPixel(2.3);
    UINT TopEdge    = (FromEdge) ? static_cast<UINT>(m_nScrmV / FromEdge) : CmtoPixel(2.3);
    UINT RightEdge  = m_nScrmH - LeftEdge;
    UINT BottomEdge = m_nScrmV - TopEdge;
    UINT CenterH    = m_nScrmH/2;
    UINT CenterV    = m_nScrmV/2;
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
        Point1(CenterH  ,TopEdge),
        Point2(RightEdge,TopEdge),
        Point3(LeftEdge ,CenterV),
        Point4(CenterH  ,CenterV),
        Point5(RightEdge,CenterV),
        Point6(LeftEdge ,BottomEdge),
        Point7(CenterH  ,BottomEdge),
        Point8(RightEdge,BottomEdge),
        PointD(CenterH  ,CenterV);

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

        default: PointD; return PointD; break;
    }
}

CPoint Bolt::GetFE5Point(UINT few, float FromEdge) const
{
//運算第幾個（以九點為計）

    //ScrmV 螢幕垂直pixel數
    //ScrmH 螢幕水平pixel數
    UINT LeftEdge   = (FromEdge) ? static_cast<UINT>(m_nScrmH / FromEdge) : CmtoPixel(2.3);
    UINT TopEdge    = (FromEdge) ? static_cast<UINT>(m_nScrmV / FromEdge) : CmtoPixel(2.3);
    UINT RightEdge  = m_nScrmH - LeftEdge;
    UINT BottomEdge = m_nScrmV - TopEdge;
    UINT CenterH    = m_nScrmH/2;
    UINT CenterV    = m_nScrmV/2;
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
        Point2(CenterH  ,CenterV),
        Point3(LeftEdge ,BottomEdge),
        Point4(RightEdge,BottomEdge),
        PointD(CenterH  ,CenterV);

//回傳一個點
    switch(few)
    {
        case 0: return Point0; break;
        case 1: return Point1; break;
        case 2: return Point2; break;//中心
        case 3: return Point3; break;
        case 4: return Point4; break;

        default: PointD; return PointD; break;
    }
}

CPoint Bolt::Get5nits9Point(UINT few) const
{
//運算第幾個（以九點為計）

    //ScrmV 螢幕垂直pixel數
    //ScrmH 螢幕水平pixel數
    UINT LeftEdge   = CmtoPixel(10);
    UINT TopEdge    = static_cast<UINT>(m_nScrmV / 6);//六分之一上邊緣
    UINT RightEdge  = m_nScrmH - LeftEdge;
    UINT BottomEdge = m_nScrmV - TopEdge;
    UINT CenterH    = m_nScrmH/2;
    UINT CenterV    = m_nScrmV/2;
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
        Point1(CenterH  ,TopEdge),
        Point2(RightEdge,TopEdge),
        Point3(LeftEdge ,CenterV),
        Point4(CenterH  ,CenterV),  //中心點不量
        Point5(RightEdge,CenterV),
        Point6(LeftEdge ,BottomEdge),
        Point7(CenterH  ,BottomEdge),
        Point8(RightEdge,BottomEdge),

        PointD(CenterH  ,CenterV);

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

        default: PointD; return PointD; break;
    }
}


// CPoint Bolt::GetD9Point(UINT few) const
// {
// //運算第幾個（以九點為計）
// 
//     //ScrmV 螢幕垂直pixel數
//     //ScrmH 螢幕水平pixel數
//     UINT LeftEdge   = CmtoPixel(2.3);//左邊緣
//     UINT TopEdge    = CmtoPixel(2.3);//上邊緣
//     UINT RightEdge  = m_nScrmH - LeftEdge;
//     UINT BottomEdge = m_nScrmV - TopEdge;
//     UINT CenterH    = m_nScrmH/2;
//     UINT CenterV    = m_nScrmV/2;
// /*
// +------------------------------+
// |00            01            02|
// |                              |  
// |                              |  
// |                              |
// |03            04            05|
// |                              |
// |                              |  
// |                              |  
// |06            07            08|
// +------------------------------+
// */
// 
//     CPoint 
//         Point0(LeftEdge ,TopEdge),
//         Point1(CenterH  ,TopEdge),
//         Point2(RightEdge,TopEdge),
//         Point3(LeftEdge ,CenterV),
//         Point4(CenterH  ,CenterV),
//         Point5(RightEdge,CenterV),
//         Point6(LeftEdge ,BottomEdge),
//         Point7(CenterH  ,BottomEdge),
//         Point8(RightEdge,BottomEdge),
//         PointD(CenterH  ,CenterV);
// //回傳一個點
//     switch(few)
//     {
//         case 0: return Point0; break;
//         case 1: return Point1; break;
//         case 2: return Point2; break;
// 
//         case 3: return Point3; break;
//         case 4: return Point4; break;//中心
//         case 5: return Point5; break;
// 
//         case 6: return Point6; break;
//         case 7: return Point7; break;
//         case 8: return Point8; break;
// 
//         default: PointD; return PointD; break;
//     }
// }


CPoint Bolt::GetD13Point(UINT few) const
{
//運算第幾個（以九點為計）

    //ScrmV 螢幕垂直pixel數
    //ScrmH 螢幕水平pixel數
    UINT LeftEdge  = CmtoPixel(2.3);//左邊緣
    UINT TopEdge   = CmtoPixel(2.3);//上邊緣

    UINT RightEdge  = m_nScrmH - LeftEdge;
    UINT BottomEdge = m_nScrmV - TopEdge;

    UINT CenterH = m_nScrmH/2;
    UINT CenterV = m_nScrmV/2;

    UINT LeftQuarterH = m_nScrmH/4;
    UINT TopQuarterV  = m_nScrmV/4;

    UINT RightQuarterH   = m_nScrmH - m_nScrmH/4;
    UINT BottomQuarterV  = m_nScrmV - m_nScrmV/4;
/*
+------------------------------+
|00            01            02|
|                              |  
|       09            10       |  
|                              |
|03            04            05|
|                              |
|       11            12       |  
|                              |  
|06            07            08|
+------------------------------+
*/
    CPoint 
        Point00(LeftEdge ,TopEdge),
        Point01(CenterH  ,TopEdge),
        Point02(RightEdge,TopEdge),

        Point03(LeftEdge ,CenterV),
        Point04(CenterH  ,CenterV),
        Point05(RightEdge,CenterV),

        Point06(LeftEdge ,BottomEdge),
        Point07(CenterH  ,BottomEdge),
        Point08(RightEdge,BottomEdge),

            Point09(LeftQuarterH ,TopQuarterV),
            Point10(RightQuarterH  ,TopQuarterV),

            Point11(LeftQuarterH,BottomQuarterV),
            Point12(RightQuarterH ,BottomQuarterV),

        PointD(CenterH  ,CenterV);

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

        default: PointD; return PointD; break;
    }
}


CPoint Bolt::GetD25Point(UINT few) const
{
    //ScrmV 螢幕垂直pixel數
    //ScrmH 螢幕水平pixel數

    UINT LeftEdge   = CmtoPixel(2.3);
    UINT Left_10    = LeftEdge + CmtoPixel(5);
    UINT Left_20    = Left_10  + CmtoPixel(5);

    UINT RightEdge  = m_nScrmH - LeftEdge;
    UINT Right_10   = RightEdge - CmtoPixel(5);
    UINT Right_20   = Right_10  - CmtoPixel(5);
    
    UINT CenterH    = m_nScrmH/2;
    UINT CenterV    = m_nScrmV/2;

    UINT TopEdge    = CmtoPixel(2.3);//上邊緣
    UINT Top_10     = TopEdge + CmtoPixel(5);
    UINT Top_20     = Top_10  + CmtoPixel(5);

    UINT BottomEdge = m_nScrmV - TopEdge;
    UINT Bottom_10  = BottomEdge - CmtoPixel(5);
    UINT Bottom_20  = Bottom_10  - CmtoPixel(5);

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
                        
                            
        Point05(CenterH, TopEdge),


        Point07(Right_20, TopEdge),        Point06(RightEdge, TopEdge),
        
                    Point10(Right_10 ,Top_10),

        Point09(Right_20, Top_20),        Point08(RightEdge,Top_20),
        //--------------------
        Point11(LeftEdge, CenterV),

        Point12(CenterH, CenterV),

        Point13(RightEdge, CenterV),
        //--------------------
        Point16(LeftEdge ,Bottom_20),    Point17(Left_20    ,Bottom_20),

                    Point18(Left_10, Bottom_10),

        Point14(LeftEdge,BottomEdge),    Point15(Left_20    ,BottomEdge),
        
        Point19(CenterH ,BottomEdge),

        Point23(Right_20, Bottom_20),    Point22(RightEdge  ,Bottom_20),

                    Point24(Right_10, Bottom_10),

        Point21(Right_20 ,BottomEdge),    Point20(RightEdge  ,BottomEdge),
        //--------------------        
        PointD(CenterH  ,CenterV);

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

        default: PointD; return PointD; break;
    }
}

//25+13的組合
CPoint Bolt::GetD29Point(UINT few) const
{
//運算第幾個（以九點為計）

    //ScrmV 螢幕垂直pixel數
    //ScrmH 螢幕水平pixel數

    UINT LeftEdge   = CmtoPixel(2.3);
    UINT Left_10    = LeftEdge + CmtoPixel(5);
    UINT Left_20    = Left_10  + CmtoPixel(5);

    UINT RightEdge  = m_nScrmH - LeftEdge;
    UINT Right_10   = RightEdge - CmtoPixel(5);
    UINT Right_20   = Right_10  - CmtoPixel(5);
    
    UINT CenterH    = m_nScrmH/2;
    UINT CenterV    = m_nScrmV/2;

    UINT TopEdge    = CmtoPixel(2.3);//上邊緣
    UINT Top_10     = TopEdge + CmtoPixel(5);
    UINT Top_20     = Top_10  + CmtoPixel(5);

    UINT BottomEdge = m_nScrmV - TopEdge;
    UINT Bottom_10  = BottomEdge - CmtoPixel(5);
    UINT Bottom_20  = Bottom_10  - CmtoPixel(5);

    UINT LeftQuarterH = m_nScrmH/4;
    UINT TopQuarterV  = m_nScrmV/4;

    UINT RightQuarterH   = m_nScrmH - m_nScrmH/4;
    UINT BottomQuarterV  = m_nScrmV - m_nScrmV/4;
/* L1L2                  R2R1
+------------------------------+
|00  01        05        07  06|
|  04                      10  |T1
|02  03  25          26  09  08|T2
|                              |
|11            12            13|
|                              |
|16  17  27          28  23  25|B2
|  18                      24  |B1
|14  15        19        21  20|
+------------------------------+
*/
    CPoint 
        Point00(LeftEdge, TopEdge),        Point01(Left_20, TopEdge),

                    Point04(Left_10, Top_10),

        Point02(LeftEdge, Top_20),        Point03(Left_20, Top_20),
                        
                            
        Point05(CenterH, TopEdge),


        Point07(Right_20, TopEdge),        Point06(RightEdge, TopEdge),
        
                    Point10(Right_10 ,Top_10),

        Point09(Right_20, Top_20),        Point08(RightEdge,Top_20),
        //--------------------
        Point11(LeftEdge, CenterV),

        Point12(CenterH, CenterV),

        Point13(RightEdge, CenterV),
        //--------------------
        Point16(LeftEdge ,Bottom_20),    Point17(Left_20    ,Bottom_20),

                    Point18(Left_10, Bottom_10),

        Point14(LeftEdge,BottomEdge),    Point15(Left_20    ,BottomEdge),
        
        Point19(CenterH ,BottomEdge),

        Point23(Right_20, Bottom_20),    Point22(RightEdge  ,Bottom_20),

                    Point24(Right_10, Bottom_10),

        Point21(Right_20 ,BottomEdge),    Point20(RightEdge  ,BottomEdge),
        //--------------------        
        Point25(LeftQuarterH ,TopQuarterV),        Point26(RightQuarterH  ,TopQuarterV),

        Point27(LeftQuarterH,BottomQuarterV),        Point28(RightQuarterH ,BottomQuarterV),        
        //--------------------  
		PointD(CenterH  ,CenterV);

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
//----------
		case 25: return Point25; break;
        case 26: return Point26; break;
		case 27: return Point27; break;
        case 28: return Point28; break;

        default: PointD; return PointD; break;
    }
}

CPoint Bolt::GetW49Point(UINT few) const
{
//運算第幾個（以49點為計）

    //ScrmV 螢幕垂直pixel數
    //ScrmH 螢幕水平pixel數
    UINT LeftEdge  = m_nScrmH  / 12;   //左數1直排
    UINT DLeftEdge = LeftEdge  *  2;   //左數2直排
    UINT FLeftEdge = DLeftEdge *  2;   //左數3直排

    UINT TopEdge   = m_nScrmV / 12;    //上數1橫排
    UINT DTopEdge  = TopEdge  * 2;    //上數2橫排
    UINT FTopEdge  = DTopEdge * 2;    //上數2橫排

    UINT RightEdge  = m_nScrmH -  LeftEdge;   //右數1直排
    UINT DRightEdge = m_nScrmH - DLeftEdge;   //右數2直排
    UINT FRightEdge = m_nScrmH - FLeftEdge;   //右數3直排

    UINT BottomEdge = m_nScrmV -  TopEdge;    //下數1橫排
    UINT DBottomEdge= m_nScrmV - DTopEdge;    //下數2橫排
    UINT FBottomEdge= m_nScrmV - FTopEdge;    //下數3橫排

    UINT CenterH = m_nScrmH/2;  //水平中心
    UINT CenterV = m_nScrmV/2;  //垂直中心
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
        Point03(CenterH   ,TopEdge),
        Point04(FRightEdge,TopEdge),
        Point05(DRightEdge,TopEdge),
        Point06(RightEdge ,TopEdge),

        Point10(LeftEdge  ,DTopEdge),
        Point11(DLeftEdge ,DTopEdge),
        Point12(FLeftEdge ,DTopEdge),
        Point13(CenterH   ,DTopEdge),
        Point14(FRightEdge,DTopEdge),
        Point15(DRightEdge,DTopEdge),
        Point16(RightEdge ,DTopEdge),

        Point20(LeftEdge  ,FTopEdge),
        Point21(DLeftEdge ,FTopEdge),
        Point22(FLeftEdge ,FTopEdge),
        Point23(CenterH   ,FTopEdge),
        Point24(FRightEdge,FTopEdge),
        Point25(DRightEdge,FTopEdge),
        Point26(RightEdge ,FTopEdge),

        Point30(LeftEdge  ,CenterV),
        Point31(DLeftEdge ,CenterV),
        Point32(FLeftEdge ,CenterV),
        Point33(CenterH   ,CenterV),//中心點
        Point34(FRightEdge,CenterV),
        Point35(DRightEdge,CenterV),
        Point36(RightEdge ,CenterV),

        Point40(LeftEdge  ,FBottomEdge),
        Point41(DLeftEdge ,FBottomEdge),
        Point42(FLeftEdge ,FBottomEdge),
        Point43(CenterH   ,FBottomEdge),
        Point44(FRightEdge,FBottomEdge),
        Point45(DRightEdge,FBottomEdge),
        Point46(RightEdge ,FBottomEdge),

        Point50(LeftEdge  ,DBottomEdge),
        Point51(DLeftEdge ,DBottomEdge),
        Point52(FLeftEdge ,DBottomEdge),
        Point53(CenterH   ,DBottomEdge),
        Point54(FRightEdge,DBottomEdge),
        Point55(DRightEdge,DBottomEdge),
        Point56(RightEdge ,DBottomEdge),

        Point60(LeftEdge  ,BottomEdge),
        Point61(DLeftEdge ,BottomEdge),
        Point62(FLeftEdge ,BottomEdge),
        Point63(CenterH   ,BottomEdge),
        Point64(FRightEdge,BottomEdge),
        Point65(DRightEdge,BottomEdge),
        Point66(RightEdge ,BottomEdge),

        PointD(CenterH  ,CenterV);

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

        default: PointD; return PointD; break;
    }
}

CPoint Bolt::GetCrossTalk(UINT few, float FromEdge) const
{
//運算第幾個（以九點為計）

    //ScrmV 螢幕垂直pixel數
    //ScrmH 螢幕水平pixel數
    UINT LeftEdge   = (FromEdge) ? static_cast<UINT>(m_nScrmH / FromEdge) : CmtoPixel(2.3);    //上
    UINT TopEdge    = (FromEdge) ? static_cast<UINT>(m_nScrmV / FromEdge) : CmtoPixel(2.3);    //下
    UINT RightEdge  = m_nScrmH - LeftEdge;  //左
    UINT BottomEdge = m_nScrmV - TopEdge;   //右
    UINT CenterH    = m_nScrmH/2;
    UINT CenterV    = m_nScrmV/2;
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
        Point0(CenterH  , TopEdge),
        Point1(LeftEdge , CenterV),
        Point2(RightEdge, CenterV),
        Point3(CenterH  , BottomEdge),
        PointD(CenterH  , CenterV);
//回傳一個點
    switch(few)
    {
        case 0: return Point0; break;
        case 1: return Point1; break;
        case 2: return Point2; break;
        case 3: return Point3; break;

        default: PointD; return PointD; break;
    }
}

UINT Bolt::CmtoPixel(const double cm) const
{	
	return (UINT)(m_nScrmV*cm / ((double)m_LcmSize * sin( atan((double)m_nScrmV/(double)m_nScrmH) ) * 2.54));
}


/*******************************************************
 *******************************************************
 *******************************************************
 *******************************************************
 *******************************************************
 *******************************************************/


Bolt::Bolt():m_nScrmH(0), m_nScrmV(0), m_Radius(0),	
m_LcmSize(0), m_isReady(0), m_5nitsBkColor(RGB(127, 127, 127)){}

Bolt::~Bolt(){}

BOOL Bolt::Magazine(CString LcmSize, std::vector<Cartridge>& vCar)
{
/*
	要得到以下訊息
	LcmSize
	解析度
	背景色
	該項目共幾點
	目前量的點是該項第幾點
*/
	m_itEnd = vCar.end();
	m_LcmSize = (UINT)atoi(LcmSize);
	m_nScrmH  = GetSystemMetrics(SM_CXSCREEN);
	m_nScrmV  = GetSystemMetrics(SM_CYSCREEN);

	m_BkColor    = vCar.begin()->GetBackColor();
	m_MsrFlowNum = vCar.begin()->GetPostition();
	m_MsrFlowNo  = vCar.begin()->GetMsrFlowNo();

	m_Radius = CmtoPixel(2.25);

	m_isReady = TRUE;

	return m_isReady;
}

UINT Bolt::Trigger(std::vector<Cartridge>::iterator& it)
{
	/*
	0 沒有資料
	1 正常
	2 5nits
	*/
	if (it != m_itEnd && m_isReady)
	{
		m_BkColor    = it->GetBackColor();
		m_MsrFlowNum = it->GetPostition();
		m_MsrFlowNo  = it->GetMsrFlowNo();
		if (m_BkColor == Nits && it->GetArea() == 1)
			return 2;
		else
			return 1;
	}
	else 
		return 0;
}

COLORREF Bolt::GetBkColor() const
{
	if (m_isReady)
	{
		switch(m_BkColor)
		{
			case White:	 return RGB( 255, 255, 255);
			case Dark:	 return RGB(   0,   0,   0);
			case Red:	 return RGB( 255,   0,   0);
			case Green:	 return RGB(   0, 255,   0);
			case Blue:	 return RGB(   0,   0, 255);
			case Nits:	 return m_5nitsBkColor;
			case CrsTlk: 
			case CrsTlkW:
			case CrsTlkD:
						 return RGB( 128, 128, 128);
			default:     return RGB( 192, 212,  49); 
		}
	}
	else
		return RGB( 176,  133,  77);
}

void Bolt::CenterRect(CDC* pDC, float FromEdge, COLORREF CntrClr)
{
	CRect* pCenterArea = new CRect(m_nScrmH/FromEdge, m_nScrmV/FromEdge, m_nScrmH - m_nScrmH/FromEdge, m_nScrmV - m_nScrmV/FromEdge);
	CBrush* pBrush = new CBrush(CntrClr);
	pDC->FillRect(pCenterArea, pBrush);
	delete pBrush;
	delete pCenterArea;
}

BOOL Bolt::Set5NitsBkColor(COLORREF color)
{
	if (m_isReady)
	{
		m_5nitsBkColor = color;
		return TRUE;
	}
	else
	{
		m_5nitsBkColor = RGB(127, 127, 127);
		return FALSE;
	}
}

COLORREF Bolt::Get5NitsBkColor() const
{
	return m_5nitsBkColor;
}

CPoint Bolt::GetPointPosition() const
{
	if (m_isReady)
	{
		switch(m_MsrFlowNum)
		{
			case Pn1:
				//中心點定義不分
				return GetFE9Point(4, 2);
			case Pn4:
				return GetCrossTalk(m_MsrFlowNo);
			case Pn5:
				return GetFE5Point(m_MsrFlowNo, 0);
			case Pn9:
				//九點週邊定義各有不同
				//分白、黑、5Nits
				if(m_BkColor == White) return GetFE9Point(m_MsrFlowNo);
				if(m_BkColor == Dark ) return GetFE9Point(m_MsrFlowNo, 0);
				if(m_BkColor == Nits)  return Get5nits9Point(m_MsrFlowNo);
			case Pn49:
				return GetW49Point(m_MsrFlowNo);
			case Pn13:
				return GetD13Point(m_MsrFlowNo);
			case Pn25:
				return GetD25Point(m_MsrFlowNo);
			case Pn29:
				return GetD29Point(m_MsrFlowNo);
			default:
				return GetFE9Point(0, 0);
		}
	}
	else
		return GetFE9Point(0, 0);
}

UINT Bolt::GetRadius() const
{
	return m_isReady ? m_Radius : 0;
}

BOOL Bolt::isReady() const
{
	return m_isReady;
}

CString Bolt::GetMsrFlowName() const
{
	CString clr("NotReady");
	CString ptnum("NotReady");

	if (m_isReady)
	{
		switch(m_MsrFlowNum)
		{
		case Pn1:  ptnum.Format("中心點"); break;
		case Pn9:  ptnum.Format("9點");    break;
		case Pn49: ptnum.Format("49點");   break;
		case Pn13: ptnum.Format("13點");   break;
		case Pn25: ptnum.Format("25點");   break;
		case Pn29: ptnum.Format("29點");   break;
		}
		switch(m_BkColor)
		{
		case White:     clr.Format("白色");      break;
		case Dark:      clr.Format("黑色");      break;
		case Red:       clr.Format("紅色");      break;
		case Blue:      clr.Format("藍色");      break;
		case Green:     clr.Format("綠色");      break;
		case Nits:      clr.Format("5Nits");     break;
		case CrsTlk:    clr.Format("CrossTalk"); break;
		}
	}

	CString temp;
	temp.Format("%s%s", clr, ptnum);
	return temp;
}

void Bolt::Partition(std::vector<Cartridge>& vCar, Cartridge& MsrFlow)
{
	m_LcmSize = 24;
	m_nScrmH  = GetSystemMetrics(SM_CXSCREEN);
	m_nScrmV  = GetSystemMetrics(SM_CYSCREEN);

	m_BkColor    = MsrFlow.GetBackColor();
	m_MsrFlowNum = MsrFlow.GetPostition();

	UINT areaCode = 0;

	UINT centerX = m_nScrmH/2;
	UINT centerY = m_nScrmV/2;
	m_isReady = TRUE;
	for (m_MsrFlowNo = 0; m_MsrFlowNo < (UINT)m_MsrFlowNum; ++m_MsrFlowNo)
	{
		MsrFlow.SetMsrFlowNo(m_MsrFlowNo);
// 		+----------+
// 		|02  03  07|
// 		|04  01  08|
// 		|05  06  09|
// 		+----------+
		if((((UINT)m_MsrFlowNum - 1)/2) == MsrFlow.GetMsrFlowNo())
			areaCode = 1;
		else
		{
			UINT Xp = GetPointPosition().x;
			UINT Yp = GetPointPosition().y;

			 	 if	(Xp <  centerX && Yp <  centerY)	areaCode = 2;
			else if (Xp == centerX && Yp <  centerY)	areaCode = 3;
			else if (Xp <  centerX && Yp == centerY)	areaCode = 4;
			else if (Xp <  centerX && Yp >  centerY)	areaCode = 5;
			else if (Xp == centerX && Yp >  centerY)	areaCode = 6;
			else if (Xp >  centerX && Yp <  centerY)	areaCode = 7;
			else if (Xp >  centerX && Yp == centerY)	areaCode = 8;
			else if (Xp >  centerX && Yp >  centerY)	areaCode = 9;
			else                                        areaCode = 0;
		}

		MsrFlow.SetArea(areaCode);
		vCar.push_back(MsrFlow);
	}
	m_isReady = FALSE;
}

CString  Bolt::GetSetupValue() const
{
	CString str;

	str.Format("Ready = %d, 解析度(%d×%d), 半徑 = %d, LCM尺寸 = %d 寸, 顏色項目點: %s/%d/%d, 5Nits背景色(%d,%d,%d)", \
			m_isReady, m_nScrmH, m_nScrmV, m_Radius, m_LcmSize, GetMsrFlowName(), m_MsrFlowNo, m_MsrFlowNum, \
			GetRValue(m_5nitsBkColor), GetGValue(m_5nitsBkColor), GetBValue(m_5nitsBkColor));
	
	return str;
}