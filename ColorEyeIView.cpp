// ColorEyeIView.cpp : implementation of the CColorEyeIView class
//

#include "stdafx.h"
#include "ColorEyeI.h"

#include "ColorEyeIDoc.h"
#include "ColorEyeIView.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CColorEyeIView

IMPLEMENT_DYNCREATE(CColorEyeIView, CScrollView)

BEGIN_MESSAGE_MAP(CColorEyeIView, CScrollView)
    //{{AFX_MSG_MAP(CColorEyeIView)
    ON_WM_VSCROLL()
    ON_WM_MOUSEWHEEL()
    ON_WM_LBUTTONUP()
    ON_WM_MOUSEMOVE()
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CColorEyeIView construction/destruction

CColorEyeIView::CColorEyeIView()
{
    // TODO: add construction code here
}

CColorEyeIView::~CColorEyeIView()
{
}

BOOL CColorEyeIView::PreCreateWindow(CREATESTRUCT& cs)
{
    // TODO: Modify the Window class or styles here by modifying
    //  the CREATESTRUCT cs

    return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CColorEyeIView drawing

void CColorEyeIView::OnDraw(CDC* pDC)
{
    CColorEyeIDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    // TODO: add draw code for native data here
    int nDC = pDC->SaveDC();

    CSize szAroundSpace(2, 2);  //視窗的留白
    CPoint ptOrig(0, 0);        //視窗的原點（左上角）
    CPoint ptFix(0, 0);

    ptOrig = ptOrig + szAroundSpace;
    ptFix.x = ptFix.x + szAroundSpace.cx;
    ptFix.y = ptFix.y + szAroundSpace.cy;

    //自訂字型
    CFont afont;
    UINT TextHight(16);
    afont.CreateFont(TextHight, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, FF_MODERN, "Verdana");

    m_isMsr.clear();

    //定義導覽表格是否有量測值
    for(int i = 0; i < 10; ++i)
    {
//         CString strTemp2;
//         switch(i)
//         {
//             case 0: strTemp2.Format("Lv"); break;
//             case 1: strTemp2.Format("x"); break;
//             case 2: strTemp2.Format("y"); break;
//             case 3: strTemp2.Format("du"); break;
//             case 4: strTemp2.Format("dv"); break;
//             case 5: strTemp2.Format("T"); break;
//             case 6: strTemp2.Format("duv"); break;
//             case 7: strTemp2.Format("X"); break;
//             case 8: strTemp2.Format("Y"); break;
//             case 9: strTemp2.Format("Z"); break;
//         }
// 
//         strTemp.Format("從Doc抓%s值出來，是不是有量測\nWRGBD = %d, %d, %d, %d, %d\nD25 = %d\nW49 = %d\nW9 = %d\nW5 = %d\nNits = %d\n",\
//             strTemp2, \
//             pDoc->GetOmdFile().IsMsr(White, Pn1, (isMsrValue)i), \
//             pDoc->GetOmdFile().IsMsr(Red  , Pn1, (isMsrValue)i), \
//             pDoc->GetOmdFile().IsMsr(Green, Pn1, (isMsrValue)i), \
//             pDoc->GetOmdFile().IsMsr(Blue , Pn1, (isMsrValue)i), \
//             pDoc->GetOmdFile().IsMsr(Dark , Pn1, (isMsrValue)i), \
//             
//             pDoc->GetOmdFile().IsMsr(Dark , Pn25, (isMsrValue)i), \
//             pDoc->GetOmdFile().IsMsr(White, Pn49, (isMsrValue)i), \
//             pDoc->GetOmdFile().IsMsr(White, Pn9, (isMsrValue)i), \
//             pDoc->GetOmdFile().IsMsr(White, Pn5, (isMsrValue)i), \
//             pDoc->GetOmdFile().IsMsr(Nits , Pn9 , (isMsrValue)i)
//             );
//         MessageBox(strTemp); 

        TbBkClr_WRGBD[i] = ((pDoc->GetOmdFile().IsMsr(White, Pn1, (isMsrValue)i)) ||
            (pDoc->GetOmdFile().IsMsr(Red  , Pn1, (isMsrValue)i)) ||
            (pDoc->GetOmdFile().IsMsr(Green, Pn1, (isMsrValue)i)) ||
            (pDoc->GetOmdFile().IsMsr(Blue , Pn1, (isMsrValue)i)) ||
            (pDoc->GetOmdFile().IsMsr(Dark , Pn1, (isMsrValue)i)))? TRUE : FALSE ;
        
        TbBkClr_D25[i]  = (pDoc->GetOmdFile().IsMsr(Dark , Pn25, (isMsrValue)i))? TRUE : FALSE ;
        TbBkClr_W49[i]  = (pDoc->GetOmdFile().IsMsr(White, Pn49, (isMsrValue)i))? TRUE : FALSE ;
        TbBkClr_W9[i]   = (pDoc->GetOmdFile().IsMsr(White, Pn9 , (isMsrValue)i))? TRUE : FALSE ;
        TbBkClr_W5[i]   = (pDoc->GetOmdFile().IsMsr(White, Pn5 , (isMsrValue)i))? TRUE : FALSE ;
        TbBkClr_Nits[i] = (pDoc->GetOmdFile().IsMsr(Nits , Pn9 , (isMsrValue)i))? TRUE : FALSE ;
    }
    
    m_isMsr.push_back(TbBkClr_WRGBD);
    m_isMsr.push_back(TbBkClr_Nits);
    m_isMsr.push_back(TbBkClr_W49);
    m_isMsr.push_back(TbBkClr_W9);
    m_isMsr.push_back(TbBkClr_D25);
    m_isMsr.push_back(TbBkClr_W5);
    
//看看5Nits的T是不是如預期的出現灰背景
//     strTemp.Format("RGB = (%d, %d, %d)", GetRValue(TbBkClr_Nits[5]), GetGValue(TbBkClr_Nits[5]), GetBValue(TbBkClr_Nits[5]));
//     MessageBox(strTemp);

//////////////////////////////////////////////////////////////////////////
    //表格的部份
    //設計一個table class用類似HTML的語法來管理表格

    //視窗左半邊，導覽區
    ptFix = GetDeviceScrollPosition();
    CPoint ptTemp = ptFix;

    CTable tbInfo(pDC, ptTemp);
    ptTemp = tbInfo.SetCellNum(2, 4).SetTableBoard(0).SetGridBoard(0).SetFont(afont).SetCellSpace(1)
     .Width(0, TextHight*10).Width(1, TextHight*12).Hight(0, 16).Hight(1, 16).Hight(2, 16)//.Hight(3, 16)
             .tr().td().b().text("Panel ID").b_().td_()          .td().text(pDoc->GetOmdFile().GetPnlID()).td_().tr_()
             .tr().td().b().text("Measurement device").b_().td_().td().text(pDoc->GetOmdFile().GetMsrDvc()).td_().tr_()
             .tr().td().b().text("Probe").b_().td_()             .td().text(pDoc->GetOmdFile().GetPrb()).td_().tr_()
             .tr().td().b().text("Chanel").b_().td_()            .td().text(pDoc->GetOmdFile().GetCHID()).td_().tr_()
        .table_();

    

    //enum MV_TABLE    {WRGBD = 0, W49, W9, D25, W5};
    //enum isMsrValue    {Lv = 0, Sx, Sy, du, dv, T, duv, X, Y, Z};
    //11×7的hittest表格
    CTable tbOmdMap(pDC, ptTemp);
    //ptTemp = ;
    ptTemp = tbOmdMap.SetCellNum(11, 7).SetGridBoard(1).SetTableBoard(1, RGB(255, 255, 255)).SetCellSpace(7)
        .Width(0, 42).Width( 1, 14).Width( 2, 14).Width( 3, 14).Width( 4, 14).Width( 5, 14).Width( 6, 14).Width( 7, 14).Width( 8, 14).Width( 9, 14).Width(10, 14)//.Width(11, 14)
        .tr().td().text("").td_()      .td().text("L").td_().td().text("x").td_().td().text("y").td_().td().text("u\'").td_().td().text("v\'").td_().td().text("T").td_().td().text("uv\'").td_().td().text("X").td_().td().text("Y").td_().td().text("Z").td_().tr_()
        .tr().td().text("中心點").td_().td(isMsrToBkColor(m_isMsr[WRGBD][Lv]), 5, 1).td_()                                                                                                                                                          .td(isMsrToBkColor(m_isMsr[WRGBD][T])).td_()        .td(isMsrToBkColor(m_isMsr[WRGBD][duv])).td_()           .td(isMsrToBkColor(m_isMsr[WRGBD][X])).td_()        .td(isMsrToBkColor(m_isMsr[WRGBD][Y])).td_()        .td(isMsrToBkColor(m_isMsr[WRGBD][Z])).td_().tr_()
        .tr().td().text("5Nits").td_() .td(isMsrToBkColor(m_isMsr[Nts][Lv])).td_()          .td(isMsrToBkColor(m_isMsr[Nts][Sx])).td_()          .td(isMsrToBkColor(m_isMsr[Nts][Sy])).td_()          .td(isMsrToBkColor(m_isMsr[Nts][du])).td_()            .td(isMsrToBkColor(m_isMsr[Nts][dv])).td_()            .td(isMsrToBkColor(m_isMsr[Nts][T])).td_()          .td(isMsrToBkColor(m_isMsr[Nts][duv])).td_()             .td(isMsrToBkColor(m_isMsr[Nts][X])).td_()          .td(isMsrToBkColor(m_isMsr[Nts][Y])).td_()          .td(isMsrToBkColor(m_isMsr[Nts][Z])).td_().tr_()
        .tr().td().text("白49").td_()  .td(isMsrToBkColor(m_isMsr[W49][Lv])).td_()          .td(isMsrToBkColor(m_isMsr[W49][Sx])).td_()          .td(isMsrToBkColor(m_isMsr[W49][Sy])).td_()          .td(isMsrToBkColor(m_isMsr[W49][du])).td_()            .td(isMsrToBkColor(m_isMsr[W49][dv])).td_()            .td(isMsrToBkColor(m_isMsr[W49][T])).td_()          .td(isMsrToBkColor(m_isMsr[W49][duv])).td_()             .td(isMsrToBkColor(m_isMsr[W49][X])).td_()          .td(isMsrToBkColor(m_isMsr[W49][Y])).td_()          .td(isMsrToBkColor(m_isMsr[W49][Z])).td_().tr_()
        .tr().td().text("白9").td_()   .td(isMsrToBkColor(m_isMsr[W9][Lv])).td_()           .td(isMsrToBkColor(m_isMsr[W9][Sx])).td_()           .td(isMsrToBkColor(m_isMsr[W9][Sy])).td_()           .td(isMsrToBkColor(m_isMsr[W9][du])).td_()             .td(isMsrToBkColor(m_isMsr[W9][dv])).td_()             .td(isMsrToBkColor(m_isMsr[W9][T])).td_()           .td(isMsrToBkColor(m_isMsr[W9][duv])).td_()              .td(isMsrToBkColor(m_isMsr[W9][X])).td_()           .td(isMsrToBkColor(m_isMsr[W9][Y])).td_()           .td(isMsrToBkColor(m_isMsr[W9][Z])).td_().tr_()
        .tr().td().text("黑25").td_()  .td(isMsrToBkColor(m_isMsr[D25][Lv])).td_()          .td(isMsrToBkColor(m_isMsr[D25][Sx])).td_()          .td(isMsrToBkColor(m_isMsr[D25][Sy])).td_()          .td(isMsrToBkColor(m_isMsr[D25][du])).td_()            .td(isMsrToBkColor(m_isMsr[D25][dv])).td_()            .td(isMsrToBkColor(m_isMsr[D25][T])).td_()          .td(isMsrToBkColor(m_isMsr[D25][duv])).td_()             .td(isMsrToBkColor(m_isMsr[D25][X])).td_()          .td(isMsrToBkColor(m_isMsr[D25][Y])).td_()          .td(isMsrToBkColor(m_isMsr[D25][Z])).td_().tr_()
        .tr().td().text("白5").td_()   .td(isMsrToBkColor(m_isMsr[W5][Lv])).td_()           .td(isMsrToBkColor(m_isMsr[W5][Sx])).td_()           .td(isMsrToBkColor(m_isMsr[W5][Sy])).td_()           .td(isMsrToBkColor(m_isMsr[W5][du])).td_()             .td(isMsrToBkColor(m_isMsr[W5][dv])).td_()             .td(isMsrToBkColor(m_isMsr[W5][T])).td_()           .td(isMsrToBkColor(m_isMsr[W5][duv])).td_()              .td(isMsrToBkColor(m_isMsr[W5][X])).td_()           .td(isMsrToBkColor(m_isMsr[W5][Y])).td_()           .td(isMsrToBkColor(m_isMsr[W5][Z])).td_().tr_()
    .table_(m_NvgtHit);


//    KeepSc();
//     CRect flashrect(ptOrig, ptTemp);
// 
//     flashrect.right = 360;
//     pDC->Rectangle(&flashrect);
//     InvalidateRect(&flashrect);
//    ViewTableBkColor(WRGBD);

    //    pDC->TextOut(ptFix.x, ptFix.y, "測試文字");
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //背景色的debug
//    std::vector<Cartridge>::iterator vit;
//     strTemp.Format("Lv    x    y    Du    Dv    T    Duv    X    Y    Z\n");
//     pDC->TextOut(ptTemp.x, ptTemp.y, strTemp.GetBuffer(0), strTemp.GetLength());
//     for (vit = vNits.begin(); vit != vNits.end(); ++vit)
//     {
//         ptTemp.y += TextHight + 2;
//         strTemp.Format("%s,    %s,    %s,    %s,    %s,    %s,    %s,    %s,    %s,    %s", \
//             vit->GetStrLv(), vit->GetStrSx(), vit->GetStrSy(), vit->GetStrDu(), vit->GetStrDv(), vit->GetStrT(), vit->GetStrDuv(), vit->GetStrX(), vit->GetStrY(), vit->GetStrZ());
//         pDC->TextOut(ptTemp.x, ptTemp.y, strTemp.GetBuffer(0), strTemp.GetLength());
//     }
    

    //視窗右半邊（主要資料檢視區）
    ptTemp.x = 365;
    ptTemp.y = ptOrig.y;
    
    //表格寬956
//    int CellWidth = 64;
    
    for (std::vector<ViewTable>::iterator it = m_vViewTable.begin(); it != m_vViewTable.end(); ++it)
    {
        ptTemp = DrawTable(it->GetMsrItem(), it->GetMsrValue(),pDC, pDoc, ptTemp);
        ptTemp.y += 16;
    }

//     for (std::vector<CPoint>::iterator ptIt = m_NvgtHit.begin(); ptIt != m_NvgtHit.end(); ++ptIt)
//         pDC->SetPixel(*ptIt, RGB(61, 234, 36));

//     strTemp.Format("%d, %d", ptTemp.x, ptTemp.y);
//     AfxMessageBox(strTemp);

//    pDC->SetPixel(ptTemp, RGB(0, 128, 128));
    DebugView(pDC);
    pDC->RestoreDC( nDC );

    //設定高度
    CSize sizeTotal;
    // TODO: calculate the total size of this view
    sizeTotal.cx = 956;
    sizeTotal.cy = (ptTemp.y > 291) ? ptTemp.y : 291; //291是左邊的
    SetScrollSizes(MM_TEXT, sizeTotal);
    
}

CPoint CColorEyeIView::DrawTable(isMsrItem Item, isMsrValue Value, CDC* pDC, CColorEyeIDoc* pDoc, CPoint ptTemp)
{
    //switch-case的資料來自
    //OmdFile1.h
    //enum isMsrItem    {WRGBD = 0, Nts, W49, W9, D25, W5};
    //enum isMsrValue    {Lv = 0, Sx, Sy, du, dv, T, duv, X, Y, Z};
    switch(Item)
    {
        case WRGBD:
            switch(Value)
            {
                default:
                case Lv:     return DrawWRGBDTable_Lv(pDC, pDoc, ptTemp);
//                 case Sx:     return DrawWRGBDTable_Sx(pDC, pDoc, ptTemp);
//                 case Sy:     return DrawWRGBDTable_Sy(pDC, pDoc, ptTemp);
//                 case du:     return DrawWRGBDTable_T(pDC, pDoc, ptTemp);
//                 case dv:     return DrawWRGBDTable_Du(pDC, pDoc, ptTemp);
//                 case T:      return DrawWRGBDTable_Dv(pDC, pDoc, ptTemp);
//                 case duv:    return DrawWRGBDTable_Duv(pDC, pDoc, ptTemp);
//                 case X:      return DrawWRGBDTable_X(pDC, pDoc, ptTemp);
//                 case Y:      return DrawWRGBDTable_Y(pDC, pDoc, ptTemp);
//                 case Z:      return DrawWRGBDTable_Z(pDC, pDoc, ptTemp);
            }
        case Nts:
            switch(Value)
            {
                default:
                case Lv:   return DrawNitsTable_Lv(pDC, pDoc, ptTemp);
                case Sx:   return DrawNitsTable_Sx(pDC, pDoc, ptTemp);
                case Sy:   return DrawNitsTable_Sy(pDC, pDoc, ptTemp);
                case du:   return DrawNitsTable_Du(pDC, pDoc, ptTemp);
                case dv:   return DrawNitsTable_Dv(pDC, pDoc, ptTemp);
                case T:    return DrawNitsTable_T(pDC, pDoc, ptTemp);
                case duv:  return DrawNitsTable_Duv(pDC, pDoc, ptTemp);
                case X:    return DrawNitsTable_X(pDC, pDoc, ptTemp);
                case Y:    return DrawNitsTable_Y(pDC, pDoc, ptTemp);
                case Z:    return DrawNitsTable_Z(pDC, pDoc, ptTemp);
            }
        case W49:
            switch(Value)
            {
                default:
                case Lv:   return DrawW49Table_Lv(pDC, pDoc, ptTemp);
                case Sx:   return DrawW49Table_Sx(pDC, pDoc, ptTemp);
                case Sy:   return DrawW49Table_Sy(pDC, pDoc, ptTemp);
                case du:   return DrawW49Table_Du(pDC, pDoc, ptTemp);
                case dv:   return DrawW49Table_Dv(pDC, pDoc, ptTemp);
                case T:    return DrawW49Table_T(pDC, pDoc, ptTemp);
                case duv:  return DrawW49Table_Duv(pDC, pDoc, ptTemp);
                case X:    return DrawW49Table_X(pDC, pDoc, ptTemp);
                case Y:    return DrawW49Table_Y(pDC, pDoc, ptTemp);
                case Z:    return DrawW49Table_Z(pDC, pDoc, ptTemp);
            }
        case W9:
            switch(Value)
            {
                default:
                case Lv:   return DrawW09Table_Lv(pDC, pDoc, ptTemp);
                case Sx:   return DrawW09Table_Sx(pDC, pDoc, ptTemp);
                case Sy:   return DrawW09Table_Sy(pDC, pDoc, ptTemp);
                case du:   return DrawW09Table_Du(pDC, pDoc, ptTemp);
                case dv:   return DrawW09Table_Dv(pDC, pDoc, ptTemp);
                case T:    return DrawW09Table_T(pDC, pDoc, ptTemp);
                case duv:  return DrawW09Table_Duv(pDC, pDoc, ptTemp);
                case X:    return DrawW09Table_X(pDC, pDoc, ptTemp);
                case Y:    return DrawW09Table_Y(pDC, pDoc, ptTemp);
                case Z:    return DrawW09Table_Z(pDC, pDoc, ptTemp);
            }
        case W5:
            switch(Value)
            {
                default:
                case Lv:   return DrawW05Table_Lv(pDC, pDoc, ptTemp);
                case Sx:   return DrawW05Table_Sx(pDC, pDoc, ptTemp);
                case Sy:   return DrawW05Table_Sy(pDC, pDoc, ptTemp);
                case du:   return DrawW05Table_Du(pDC, pDoc, ptTemp);
                case dv:   return DrawW05Table_Dv(pDC, pDoc, ptTemp);
                case T:    return DrawW05Table_T(pDC, pDoc, ptTemp);
                case duv:  return DrawW05Table_Duv(pDC, pDoc, ptTemp);
                case X:    return DrawW05Table_X(pDC, pDoc, ptTemp);
                case Y:    return DrawW05Table_Y(pDC, pDoc, ptTemp);
                case Z:    return DrawW05Table_Z(pDC, pDoc, ptTemp);
            }
        case D25:
            switch(Value)
            {
                default:
                case Lv:   return DrawD25Table_Lv(pDC, pDoc, ptTemp);
                case Sx:   return DrawD25Table_Sx(pDC, pDoc, ptTemp);
                case Sy:   return DrawD25Table_Sy(pDC, pDoc, ptTemp);
                case du:   return DrawD25Table_Du(pDC, pDoc, ptTemp);
                case dv:   return DrawD25Table_Dv(pDC, pDoc, ptTemp);
                case T:    return DrawD25Table_T(pDC, pDoc, ptTemp);
                case duv:  return DrawD25Table_Duv(pDC, pDoc, ptTemp);
                case X:    return DrawD25Table_X(pDC, pDoc, ptTemp);
                case Y:    return DrawD25Table_Y(pDC, pDoc, ptTemp);
                case Z:    return DrawD25Table_Z(pDC, pDoc, ptTemp);
            }
        default:    return ptTemp;
    }
}

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
CPoint CColorEyeIView::DrawTableTitle(CDC* pDC, CPoint ptTemp, const CString strTitle)
{
    CTable TitleTable(pDC, ptTemp);
    
    TitleTable.SetCellNum(1, 1).SetCellSpace().SetGridBoard(0).SetTableBoard(0)
    .Width(1, strTitle.GetLength())
        .tr()
            .td().text(strTitle).td_()
        .tr_()
    .table_();

    return ptTemp;
}

CPoint CColorEyeIView::DrawD25Table_Lv(CDC* pDC, CColorEyeIDoc* pDoc, CPoint ptTemp)
{
    CTable tbD25  (pDC, ptTemp);
    std::vector<Cartridge> vD25 = pDoc->GetOmdFile().AddMsrData(Dark , Pn25);

    int CellWidth = 64;
    ptTemp = tbD25.SetCellNum(7, 9).SetGridBoard(0).SetTableBoard(1).SetCellSpace(10)
        .Width(0, CellWidth).Width(1, CellWidth).Width(2, CellWidth).Width(3, CellWidth).Width(4, CellWidth).Width(5, CellWidth).Width(6, CellWidth)
        .tr().td().text(vD25[ 0].GetStrLv(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[ 1].GetStrLv(), TA_CENTER).td_()    .td().text(vD25[ 5].GetStrLv(), TA_CENTER).td_()    .td().text(vD25[ 7].GetStrLv(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[ 6].GetStrLv(), TA_CENTER).td_().tr_()
        .tr().td()                                     .td_().td().text(vD25[ 4].GetStrLv(), TA_CENTER).td_().td()                                     .td_()    .td()                                     .td_()    .td()                                     .td_().td().text(vD25[10].GetStrLv(), TA_CENTER).td_().td()                                     .td_().tr_()
        .tr().td().text(vD25[ 2].GetStrLv(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[ 3].GetStrLv(), TA_CENTER).td_()    .td()                                     .td_()    .td().text(vD25[ 9].GetStrLv(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[ 8].GetStrLv(), TA_CENTER).td_().tr_()
        .tr().td()                                     .td_().td()                                     .td_().td()                                     .td_()    .td()                                     .td_()    .td()                                     .td_().td()                                     .td_().td()                                     .td_().tr_()
        .tr().td().text(vD25[11].GetStrLv(), TA_CENTER).td_().td()                                     .td_().td()                                     .td_()    .td().text(vD25[12].GetStrLv(), TA_CENTER).td_()    .td()                                     .td_().td()                                     .td_().td().text(vD25[13].GetStrLv(), TA_CENTER).td_().tr_()
        .tr().td()                                     .td_().td()                                     .td_().td()                                     .td_()    .td()                                     .td_()    .td()                                     .td_().td()                                     .td_().td()                                     .td_().tr_()
        .tr().td().text(vD25[16].GetStrLv(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[17].GetStrLv(), TA_CENTER).td_()    .td()                                     .td_()    .td().text(vD25[23].GetStrLv(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[22].GetStrLv(), TA_CENTER).td_().tr_()
        .tr().td()                                     .td_().td().text(vD25[18].GetStrLv(), TA_CENTER).td_().td()                                     .td_()    .td()                                     .td_()    .td()                                     .td_().td().text(vD25[24].GetStrLv(), TA_CENTER).td_().td()                                     .td_().tr_()
        .tr().td().text(vD25[14].GetStrLv(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[15].GetStrLv(), TA_CENTER).td_()    .td().text(vD25[19].GetStrLv(), TA_CENTER).td_()    .td().text(vD25[21].GetStrLv(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[20].GetStrLv(), TA_CENTER).td_().tr_()
        .table_();
    
    return ptTemp;
}

CPoint CColorEyeIView::DrawD25Table_Sx(CDC* pDC, CColorEyeIDoc* pDoc, CPoint ptTemp)
{
    CTable tbD25  (pDC, ptTemp);
    std::vector<Cartridge> vD25 = pDoc->GetOmdFile().AddMsrData(Dark , Pn25);
    
    int CellWidth = 64;
    ptTemp = tbD25.SetCellNum(7, 9).SetGridBoard(0).SetTableBoard(1).SetCellSpace(10)
        .Width(0, CellWidth).Width(1, CellWidth).Width(2, CellWidth).Width(3, CellWidth).Width(4, CellWidth).Width(5, CellWidth).Width(6, CellWidth)
        .tr().td().text(vD25[ 0].GetStrSx(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[ 1].GetStrSx(), TA_CENTER).td_()    .td().text(vD25[ 5].GetStrSx(), TA_CENTER).td_()    .td().text(vD25[ 7].GetStrSx(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[ 6].GetStrSx(), TA_CENTER).td_().tr_()
        .tr().td()                                     .td_().td().text(vD25[ 4].GetStrSx(), TA_CENTER).td_().td()                                     .td_()    .td()                                     .td_()    .td()                                     .td_().td().text(vD25[10].GetStrSx(), TA_CENTER).td_().td()                                     .td_().tr_()
        .tr().td().text(vD25[ 2].GetStrSx(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[ 3].GetStrSx(), TA_CENTER).td_()    .td()                                     .td_()    .td().text(vD25[ 9].GetStrSx(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[ 8].GetStrSx(), TA_CENTER).td_().tr_()
        .tr().td()                                     .td_().td()                                     .td_().td()                                     .td_()    .td()                                     .td_()    .td()                                     .td_().td()                                     .td_().td()                                     .td_().tr_()
        .tr().td().text(vD25[11].GetStrSx(), TA_CENTER).td_().td()                                     .td_().td()                                     .td_()    .td().text(vD25[12].GetStrSx(), TA_CENTER).td_()    .td()                                     .td_().td()                                     .td_().td().text(vD25[13].GetStrSx(), TA_CENTER).td_().tr_()
        .tr().td()                                     .td_().td()                                     .td_().td()                                     .td_()    .td()                                     .td_()    .td()                                     .td_().td()                                     .td_().td()                                     .td_().tr_()
        .tr().td().text(vD25[16].GetStrSx(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[17].GetStrSx(), TA_CENTER).td_()    .td()                                     .td_()    .td().text(vD25[23].GetStrSx(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[22].GetStrSx(), TA_CENTER).td_().tr_()
        .tr().td()                                     .td_().td().text(vD25[18].GetStrSx(), TA_CENTER).td_().td()                                     .td_()    .td()                                     .td_()    .td()                                     .td_().td().text(vD25[24].GetStrSx(), TA_CENTER).td_().td()                                     .td_().tr_()
        .tr().td().text(vD25[14].GetStrSx(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[15].GetStrSx(), TA_CENTER).td_()    .td().text(vD25[19].GetStrSx(), TA_CENTER).td_()    .td().text(vD25[21].GetStrSx(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[20].GetStrSx(), TA_CENTER).td_().tr_()
        .table_();
    
    return ptTemp;
}

CPoint CColorEyeIView::DrawD25Table_Sy(CDC* pDC, CColorEyeIDoc* pDoc, CPoint ptTemp)
{
    CTable tbD25  (pDC, ptTemp);
    std::vector<Cartridge> vD25 = pDoc->GetOmdFile().AddMsrData(Dark , Pn25);
    
    int CellWidth = 64;
    ptTemp = tbD25.SetCellNum(7, 9).SetGridBoard(0).SetTableBoard(1).SetCellSpace(10)
        .Width(0, CellWidth).Width(1, CellWidth).Width(2, CellWidth).Width(3, CellWidth).Width(4, CellWidth).Width(5, CellWidth).Width(6, CellWidth)
        .tr().td().text(vD25[ 0].GetStrSy(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[ 1].GetStrSy(), TA_CENTER).td_()    .td().text(vD25[ 5].GetStrSy(), TA_CENTER).td_()    .td().text(vD25[ 7].GetStrSy(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[ 6].GetStrSy(), TA_CENTER).td_().tr_()
        .tr().td()                                     .td_().td().text(vD25[ 4].GetStrSy(), TA_CENTER).td_().td()                                     .td_()    .td()                                     .td_()    .td()                                     .td_().td().text(vD25[10].GetStrSy(), TA_CENTER).td_().td()                                     .td_().tr_()
        .tr().td().text(vD25[ 2].GetStrSy(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[ 3].GetStrSy(), TA_CENTER).td_()    .td()                                     .td_()    .td().text(vD25[ 9].GetStrSy(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[ 8].GetStrSy(), TA_CENTER).td_().tr_()
        .tr().td()                                     .td_().td()                                     .td_().td()                                     .td_()    .td()                                     .td_()    .td()                                     .td_().td()                                     .td_().td()                                     .td_().tr_()
        .tr().td().text(vD25[11].GetStrSy(), TA_CENTER).td_().td()                                     .td_().td()                                     .td_()    .td().text(vD25[12].GetStrSy(), TA_CENTER).td_()    .td()                                     .td_().td()                                     .td_().td().text(vD25[13].GetStrSy(), TA_CENTER).td_().tr_()
        .tr().td()                                     .td_().td()                                     .td_().td()                                     .td_()    .td()                                     .td_()    .td()                                     .td_().td()                                     .td_().td()                                     .td_().tr_()
        .tr().td().text(vD25[16].GetStrSy(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[17].GetStrSy(), TA_CENTER).td_()    .td()                                     .td_()    .td().text(vD25[23].GetStrSy(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[22].GetStrSy(), TA_CENTER).td_().tr_()
        .tr().td()                                     .td_().td().text(vD25[18].GetStrSy(), TA_CENTER).td_().td()                                     .td_()    .td()                                     .td_()    .td()                                     .td_().td().text(vD25[24].GetStrSy(), TA_CENTER).td_().td()                                     .td_().tr_()
        .tr().td().text(vD25[14].GetStrSy(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[15].GetStrSy(), TA_CENTER).td_()    .td().text(vD25[19].GetStrSy(), TA_CENTER).td_()    .td().text(vD25[21].GetStrSy(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[20].GetStrSy(), TA_CENTER).td_().tr_()
        .table_();
    
    return ptTemp;
}

CPoint CColorEyeIView::DrawD25Table_Du(CDC* pDC, CColorEyeIDoc* pDoc, CPoint ptTemp)
{
    CTable tbD25  (pDC, ptTemp);
    std::vector<Cartridge> vD25 = pDoc->GetOmdFile().AddMsrData(Dark , Pn25);
    
    int CellWidth = 64;
    ptTemp = tbD25.SetCellNum(7, 9).SetGridBoard(0).SetTableBoard(1).SetCellSpace(10)
        .Width(0, CellWidth).Width(1, CellWidth).Width(2, CellWidth).Width(3, CellWidth).Width(4, CellWidth).Width(5, CellWidth).Width(6, CellWidth)
        .tr().td().text(vD25[ 0].GetStrDu(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[ 1].GetStrDu(), TA_CENTER).td_()    .td().text(vD25[ 5].GetStrDu(), TA_CENTER).td_()    .td().text(vD25[ 7].GetStrDu(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[ 6].GetStrDu(), TA_CENTER).td_().tr_()
        .tr().td()                                     .td_().td().text(vD25[ 4].GetStrDu(), TA_CENTER).td_().td()                                     .td_()    .td()                                     .td_()    .td()                                     .td_().td().text(vD25[10].GetStrDu(), TA_CENTER).td_().td()                                     .td_().tr_()
        .tr().td().text(vD25[ 2].GetStrDu(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[ 3].GetStrDu(), TA_CENTER).td_()    .td()                                     .td_()    .td().text(vD25[ 9].GetStrDu(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[ 8].GetStrDu(), TA_CENTER).td_().tr_()
        .tr().td()                                     .td_().td()                                     .td_().td()                                     .td_()    .td()                                     .td_()    .td()                                     .td_().td()                                     .td_().td()                                     .td_().tr_()
        .tr().td().text(vD25[11].GetStrDu(), TA_CENTER).td_().td()                                     .td_().td()                                     .td_()    .td().text(vD25[12].GetStrDu(), TA_CENTER).td_()    .td()                                     .td_().td()                                     .td_().td().text(vD25[13].GetStrDu(), TA_CENTER).td_().tr_()
        .tr().td()                                     .td_().td()                                     .td_().td()                                     .td_()    .td()                                     .td_()    .td()                                     .td_().td()                                     .td_().td()                                     .td_().tr_()
        .tr().td().text(vD25[16].GetStrDu(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[17].GetStrDu(), TA_CENTER).td_()    .td()                                     .td_()    .td().text(vD25[23].GetStrDu(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[22].GetStrDu(), TA_CENTER).td_().tr_()
        .tr().td()                                     .td_().td().text(vD25[18].GetStrDu(), TA_CENTER).td_().td()                                     .td_()    .td()                                     .td_()    .td()                                     .td_().td().text(vD25[24].GetStrDu(), TA_CENTER).td_().td()                                     .td_().tr_()
        .tr().td().text(vD25[14].GetStrDu(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[15].GetStrDu(), TA_CENTER).td_()    .td().text(vD25[19].GetStrDu(), TA_CENTER).td_()    .td().text(vD25[21].GetStrDu(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[20].GetStrDu(), TA_CENTER).td_().tr_()
        .table_();
    
    return ptTemp;
}

CPoint CColorEyeIView::DrawD25Table_Dv(CDC* pDC, CColorEyeIDoc* pDoc, CPoint ptTemp)
{
    CTable tbD25  (pDC, ptTemp);
    std::vector<Cartridge> vD25 = pDoc->GetOmdFile().AddMsrData(Dark , Pn25);
    
    int CellWidth = 64;
    ptTemp = tbD25.SetCellNum(7, 9).SetGridBoard(0).SetTableBoard(1).SetCellSpace(10)
        .Width(0, CellWidth).Width(1, CellWidth).Width(2, CellWidth).Width(3, CellWidth).Width(4, CellWidth).Width(5, CellWidth).Width(6, CellWidth)
        .tr().td().text(vD25[ 0].GetStrDv(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[ 1].GetStrDv(), TA_CENTER).td_()    .td().text(vD25[ 5].GetStrDv(), TA_CENTER).td_()    .td().text(vD25[ 7].GetStrDv(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[ 6].GetStrDv(), TA_CENTER).td_().tr_()
        .tr().td()                                     .td_().td().text(vD25[ 4].GetStrDv(), TA_CENTER).td_().td()                                     .td_()    .td()                                     .td_()    .td()                                     .td_().td().text(vD25[10].GetStrDv(), TA_CENTER).td_().td()                                     .td_().tr_()
        .tr().td().text(vD25[ 2].GetStrDv(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[ 3].GetStrDv(), TA_CENTER).td_()    .td()                                     .td_()    .td().text(vD25[ 9].GetStrDv(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[ 8].GetStrDv(), TA_CENTER).td_().tr_()
        .tr().td()                                     .td_().td()                                     .td_().td()                                     .td_()    .td()                                     .td_()    .td()                                     .td_().td()                                     .td_().td()                                     .td_().tr_()
        .tr().td().text(vD25[11].GetStrDv(), TA_CENTER).td_().td()                                     .td_().td()                                     .td_()    .td().text(vD25[12].GetStrDv(), TA_CENTER).td_()    .td()                                     .td_().td()                                     .td_().td().text(vD25[13].GetStrDv(), TA_CENTER).td_().tr_()
        .tr().td()                                     .td_().td()                                     .td_().td()                                     .td_()    .td()                                     .td_()    .td()                                     .td_().td()                                     .td_().td()                                     .td_().tr_()
        .tr().td().text(vD25[16].GetStrDv(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[17].GetStrDv(), TA_CENTER).td_()    .td()                                     .td_()    .td().text(vD25[23].GetStrDv(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[22].GetStrDv(), TA_CENTER).td_().tr_()
        .tr().td()                                     .td_().td().text(vD25[18].GetStrDv(), TA_CENTER).td_().td()                                     .td_()    .td()                                     .td_()    .td()                                     .td_().td().text(vD25[24].GetStrDv(), TA_CENTER).td_().td()                                     .td_().tr_()
        .tr().td().text(vD25[14].GetStrDv(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[15].GetStrDv(), TA_CENTER).td_()    .td().text(vD25[19].GetStrDv(), TA_CENTER).td_()    .td().text(vD25[21].GetStrDv(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[20].GetStrDv(), TA_CENTER).td_().tr_()
        .table_();
    
    return ptTemp;
}

CPoint CColorEyeIView::DrawD25Table_T(CDC* pDC, CColorEyeIDoc* pDoc, CPoint ptTemp)
{
    CTable tbD25  (pDC, ptTemp);
    std::vector<Cartridge> vD25 = pDoc->GetOmdFile().AddMsrData(Dark , Pn25);
    
    int CellWidth = 64;
    ptTemp = tbD25.SetCellNum(7, 9).SetGridBoard(0).SetTableBoard(1).SetCellSpace(10)
        .Width(0, CellWidth).Width(1, CellWidth).Width(2, CellWidth).Width(3, CellWidth).Width(4, CellWidth).Width(5, CellWidth).Width(6, CellWidth)
        .tr().td().text(vD25[ 0].GetStrT(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[ 1].GetStrT(), TA_CENTER).td_()    .td().text(vD25[ 5].GetStrT(), TA_CENTER).td_()    .td().text(vD25[ 7].GetStrT(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[ 6].GetStrT(), TA_CENTER).td_().tr_()
        .tr().td()                                     .td_().td().text(vD25[ 4].GetStrT(), TA_CENTER).td_().td()                                     .td_()    .td()                                     .td_()    .td()                                     .td_().td().text(vD25[10].GetStrT(), TA_CENTER).td_().td()                                     .td_().tr_()
        .tr().td().text(vD25[ 2].GetStrT(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[ 3].GetStrT(), TA_CENTER).td_()    .td()                                     .td_()    .td().text(vD25[ 9].GetStrT(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[ 8].GetStrT(), TA_CENTER).td_().tr_()
        .tr().td()                                     .td_().td()                                     .td_().td()                                     .td_()    .td()                                     .td_()    .td()                                     .td_().td()                                     .td_().td()                                     .td_().tr_()
        .tr().td().text(vD25[11].GetStrT(), TA_CENTER).td_().td()                                     .td_().td()                                     .td_()    .td().text(vD25[12].GetStrT(), TA_CENTER).td_()    .td()                                     .td_().td()                                     .td_().td().text(vD25[13].GetStrT(), TA_CENTER).td_().tr_()
        .tr().td()                                     .td_().td()                                     .td_().td()                                     .td_()    .td()                                     .td_()    .td()                                     .td_().td()                                     .td_().td()                                     .td_().tr_()
        .tr().td().text(vD25[16].GetStrT(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[17].GetStrT(), TA_CENTER).td_()    .td()                                     .td_()    .td().text(vD25[23].GetStrT(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[22].GetStrT(), TA_CENTER).td_().tr_()
        .tr().td()                                     .td_().td().text(vD25[18].GetStrT(), TA_CENTER).td_().td()                                     .td_()    .td()                                     .td_()    .td()                                     .td_().td().text(vD25[24].GetStrT(), TA_CENTER).td_().td()                                     .td_().tr_()
        .tr().td().text(vD25[14].GetStrT(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[15].GetStrT(), TA_CENTER).td_()    .td().text(vD25[19].GetStrT(), TA_CENTER).td_()    .td().text(vD25[21].GetStrT(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[20].GetStrT(), TA_CENTER).td_().tr_()
        .table_();
    
    return ptTemp;
}

CPoint CColorEyeIView::DrawD25Table_Duv(CDC* pDC, CColorEyeIDoc* pDoc, CPoint ptTemp)
{
    CTable tbD25  (pDC, ptTemp);
    std::vector<Cartridge> vD25 = pDoc->GetOmdFile().AddMsrData(Dark , Pn25);
    
    int CellWidth = 64;
    ptTemp = tbD25.SetCellNum(7, 9).SetGridBoard(0).SetTableBoard(1).SetCellSpace(10)
        .Width(0, CellWidth).Width(1, CellWidth).Width(2, CellWidth).Width(3, CellWidth).Width(4, CellWidth).Width(5, CellWidth).Width(6, CellWidth)
        .tr().td().text(vD25[ 0].GetStrDuv(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[ 1].GetStrDuv(), TA_CENTER).td_()    .td().text(vD25[ 5].GetStrDuv(), TA_CENTER).td_()    .td().text(vD25[ 7].GetStrDuv(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[ 6].GetStrDuv(), TA_CENTER).td_().tr_()
        .tr().td()                                     .td_().td().text(vD25[ 4].GetStrDuv(), TA_CENTER).td_().td()                                     .td_()    .td()                                     .td_()    .td()                                     .td_().td().text(vD25[10].GetStrDuv(), TA_CENTER).td_().td()                                     .td_().tr_()
        .tr().td().text(vD25[ 2].GetStrDuv(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[ 3].GetStrDuv(), TA_CENTER).td_()    .td()                                     .td_()    .td().text(vD25[ 9].GetStrDuv(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[ 8].GetStrDuv(), TA_CENTER).td_().tr_()
        .tr().td()                                     .td_().td()                                     .td_().td()                                     .td_()    .td()                                     .td_()    .td()                                     .td_().td()                                     .td_().td()                                     .td_().tr_()
        .tr().td().text(vD25[11].GetStrDuv(), TA_CENTER).td_().td()                                     .td_().td()                                     .td_()    .td().text(vD25[12].GetStrDuv(), TA_CENTER).td_()    .td()                                     .td_().td()                                     .td_().td().text(vD25[13].GetStrDuv(), TA_CENTER).td_().tr_()
        .tr().td()                                     .td_().td()                                     .td_().td()                                     .td_()    .td()                                     .td_()    .td()                                     .td_().td()                                     .td_().td()                                     .td_().tr_()
        .tr().td().text(vD25[16].GetStrDuv(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[17].GetStrDuv(), TA_CENTER).td_()    .td()                                     .td_()    .td().text(vD25[23].GetStrDuv(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[22].GetStrDuv(), TA_CENTER).td_().tr_()
        .tr().td()                                     .td_().td().text(vD25[18].GetStrDuv(), TA_CENTER).td_().td()                                     .td_()    .td()                                     .td_()    .td()                                     .td_().td().text(vD25[24].GetStrDuv(), TA_CENTER).td_().td()                                     .td_().tr_()
        .tr().td().text(vD25[14].GetStrDuv(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[15].GetStrDuv(), TA_CENTER).td_()    .td().text(vD25[19].GetStrDuv(), TA_CENTER).td_()    .td().text(vD25[21].GetStrDuv(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[20].GetStrDuv(), TA_CENTER).td_().tr_()
        .table_();
    
    return ptTemp;
}

CPoint CColorEyeIView::DrawD25Table_X(CDC* pDC, CColorEyeIDoc* pDoc, CPoint ptTemp)
{
    CTable tbD25  (pDC, ptTemp);
    std::vector<Cartridge> vD25 = pDoc->GetOmdFile().AddMsrData(Dark , Pn25);
    
    int CellWidth = 64;
    ptTemp = tbD25.SetCellNum(7, 9).SetGridBoard(0).SetTableBoard(1).SetCellSpace(10)
        .Width(0, CellWidth).Width(1, CellWidth).Width(2, CellWidth).Width(3, CellWidth).Width(4, CellWidth).Width(5, CellWidth).Width(6, CellWidth)
        .tr().td().text(vD25[ 0].GetStrX(), TA_CENTER).td_().td()                                    .td_().td().text(vD25[ 1].GetStrX(), TA_CENTER).td_()    .td().text(vD25[ 5].GetStrX(), TA_CENTER).td_()    .td().text(vD25[ 7].GetStrX(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[ 6].GetStrX(), TA_CENTER).td_().tr_()
        .tr().td()                                    .td_().td().text(vD25[ 4].GetStrX(), TA_CENTER).td_().td()                                     .td_()    .td()                                     .td_()    .td()                                     .td_().td().text(vD25[10].GetStrX(), TA_CENTER).td_().td()                                     .td_().tr_()
        .tr().td().text(vD25[ 2].GetStrX(), TA_CENTER).td_().td()                                    .td_().td().text(vD25[ 3].GetStrX(), TA_CENTER).td_()    .td()                                     .td_()    .td().text(vD25[ 9].GetStrX(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[ 8].GetStrX(), TA_CENTER).td_().tr_()
        .tr().td()                                    .td_().td()                                    .td_().td()                                     .td_()    .td()                                     .td_()    .td()                                     .td_().td()                                     .td_().td()                                     .td_().tr_()
        .tr().td().text(vD25[11].GetStrX(), TA_CENTER).td_().td()                                    .td_().td()                                     .td_()    .td().text(vD25[12].GetStrX(), TA_CENTER).td_()    .td()                                     .td_().td()                                     .td_().td().text(vD25[13].GetStrX(), TA_CENTER).td_().tr_()
        .tr().td()                                    .td_().td()                                    .td_().td()                                     .td_()    .td()                                     .td_()    .td()                                     .td_().td()                                     .td_().td()                                     .td_().tr_()
        .tr().td().text(vD25[16].GetStrX(), TA_CENTER).td_().td()                                    .td_().td().text(vD25[17].GetStrX(), TA_CENTER).td_()    .td()                                     .td_()    .td().text(vD25[23].GetStrX(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[22].GetStrX(), TA_CENTER).td_().tr_()
        .tr().td()                                    .td_().td().text(vD25[18].GetStrX(), TA_CENTER).td_().td()                                     .td_()    .td()                                     .td_()    .td()                                     .td_().td().text(vD25[24].GetStrX(), TA_CENTER).td_().td()                                     .td_().tr_()
        .tr().td().text(vD25[14].GetStrX(), TA_CENTER).td_().td()                                    .td_().td().text(vD25[15].GetStrX(), TA_CENTER).td_()    .td().text(vD25[19].GetStrX(), TA_CENTER).td_()    .td().text(vD25[21].GetStrX(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[20].GetStrX(), TA_CENTER).td_().tr_()
        .table_();
    
    return ptTemp;
}

CPoint CColorEyeIView::DrawD25Table_Y(CDC* pDC, CColorEyeIDoc* pDoc, CPoint ptTemp)
{
    CTable tbD25  (pDC, ptTemp);
    std::vector<Cartridge> vD25 = pDoc->GetOmdFile().AddMsrData(Dark , Pn25);
    
    int CellWidth = 64;
    ptTemp = tbD25.SetCellNum(7, 9).SetGridBoard(0).SetTableBoard(1).SetCellSpace(10)
        .Width(0, CellWidth).Width(1, CellWidth).Width(2, CellWidth).Width(3, CellWidth).Width(4, CellWidth).Width(5, CellWidth).Width(6, CellWidth)
        .tr().td().text(vD25[ 0].GetStrY(), TA_CENTER).td_().td()                                    .td_().td().text(vD25[ 1].GetStrY(), TA_CENTER).td_()    .td().text(vD25[ 5].GetStrY(), TA_CENTER).td_()    .td().text(vD25[ 7].GetStrY(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[ 6].GetStrY(), TA_CENTER).td_().tr_()
        .tr().td()                                    .td_().td().text(vD25[ 4].GetStrY(), TA_CENTER).td_().td()                                     .td_()    .td()                                     .td_()    .td()                                     .td_().td().text(vD25[10].GetStrY(), TA_CENTER).td_().td()                                     .td_().tr_()
        .tr().td().text(vD25[ 2].GetStrY(), TA_CENTER).td_().td()                                    .td_().td().text(vD25[ 3].GetStrY(), TA_CENTER).td_()    .td()                                     .td_()    .td().text(vD25[ 9].GetStrY(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[ 8].GetStrY(), TA_CENTER).td_().tr_()
        .tr().td()                                    .td_().td()                                    .td_().td()                                     .td_()    .td()                                     .td_()    .td()                                     .td_().td()                                     .td_().td()                                     .td_().tr_()
        .tr().td().text(vD25[11].GetStrY(), TA_CENTER).td_().td()                                    .td_().td()                                     .td_()    .td().text(vD25[12].GetStrY(), TA_CENTER).td_()    .td()                                     .td_().td()                                     .td_().td().text(vD25[13].GetStrY(), TA_CENTER).td_().tr_()
        .tr().td()                                    .td_().td()                                    .td_().td()                                     .td_()    .td()                                     .td_()    .td()                                     .td_().td()                                     .td_().td()                                     .td_().tr_()
        .tr().td().text(vD25[16].GetStrY(), TA_CENTER).td_().td()                                    .td_().td().text(vD25[17].GetStrY(), TA_CENTER).td_()    .td()                                     .td_()    .td().text(vD25[23].GetStrY(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[22].GetStrY(), TA_CENTER).td_().tr_()
        .tr().td()                                    .td_().td().text(vD25[18].GetStrY(), TA_CENTER).td_().td()                                     .td_()    .td()                                     .td_()    .td()                                     .td_().td().text(vD25[24].GetStrY(), TA_CENTER).td_().td()                                     .td_().tr_()
        .tr().td().text(vD25[14].GetStrY(), TA_CENTER).td_().td()                                    .td_().td().text(vD25[15].GetStrY(), TA_CENTER).td_()    .td().text(vD25[19].GetStrY(), TA_CENTER).td_()    .td().text(vD25[21].GetStrY(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[20].GetStrY(), TA_CENTER).td_().tr_()
        .table_();
    
    return ptTemp;
}

CPoint CColorEyeIView::DrawD25Table_Z(CDC* pDC, CColorEyeIDoc* pDoc, CPoint ptTemp)
{
    CTable tbD25  (pDC, ptTemp);
    std::vector<Cartridge> vD25 = pDoc->GetOmdFile().AddMsrData(Dark , Pn25);
    
    int CellWidth = 64;
    ptTemp = tbD25.SetCellNum(7, 9).SetGridBoard(0).SetTableBoard(1).SetCellSpace(10)
        .Width(0, CellWidth).Width(1, CellWidth).Width(2, CellWidth).Width(3, CellWidth).Width(4, CellWidth).Width(5, CellWidth).Width(6, CellWidth)
        .tr().td().text(vD25[ 0].GetStrZ(), TA_CENTER).td_().td()                                    .td_().td().text(vD25[ 1].GetStrZ(), TA_CENTER).td_()    .td().text(vD25[ 5].GetStrZ(), TA_CENTER).td_()    .td().text(vD25[ 7].GetStrZ(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[ 6].GetStrZ(), TA_CENTER).td_().tr_()
        .tr().td()                                    .td_().td().text(vD25[ 4].GetStrZ(), TA_CENTER).td_().td()                                     .td_()    .td()                                     .td_()    .td()                                     .td_().td().text(vD25[10].GetStrZ(), TA_CENTER).td_().td()                                     .td_().tr_()
        .tr().td().text(vD25[ 2].GetStrZ(), TA_CENTER).td_().td()                                    .td_().td().text(vD25[ 3].GetStrZ(), TA_CENTER).td_()    .td()                                     .td_()    .td().text(vD25[ 9].GetStrZ(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[ 8].GetStrZ(), TA_CENTER).td_().tr_()
        .tr().td()                                    .td_().td()                                    .td_().td()                                     .td_()    .td()                                     .td_()    .td()                                     .td_().td()                                     .td_().td()                                     .td_().tr_()
        .tr().td().text(vD25[11].GetStrZ(), TA_CENTER).td_().td()                                    .td_().td()                                     .td_()    .td().text(vD25[12].GetStrZ(), TA_CENTER).td_()    .td()                                     .td_().td()                                     .td_().td().text(vD25[13].GetStrZ(), TA_CENTER).td_().tr_()
        .tr().td()                                    .td_().td()                                    .td_().td()                                     .td_()    .td()                                     .td_()    .td()                                     .td_().td()                                     .td_().td()                                     .td_().tr_()
        .tr().td().text(vD25[16].GetStrZ(), TA_CENTER).td_().td()                                    .td_().td().text(vD25[17].GetStrZ(), TA_CENTER).td_()    .td()                                     .td_()    .td().text(vD25[23].GetStrZ(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[22].GetStrZ(), TA_CENTER).td_().tr_()
        .tr().td()                                    .td_().td().text(vD25[18].GetStrZ(), TA_CENTER).td_().td()                                     .td_()    .td()                                     .td_()    .td()                                     .td_().td().text(vD25[24].GetStrZ(), TA_CENTER).td_().td()                                     .td_().tr_()
        .tr().td().text(vD25[14].GetStrZ(), TA_CENTER).td_().td()                                    .td_().td().text(vD25[15].GetStrZ(), TA_CENTER).td_()    .td().text(vD25[19].GetStrZ(), TA_CENTER).td_()    .td().text(vD25[21].GetStrZ(), TA_CENTER).td_().td()                                     .td_().td().text(vD25[20].GetStrZ(), TA_CENTER).td_().tr_()
        .table_();
    
    return ptTemp;
}

CPoint CColorEyeIView::DrawW05Table_Lv(CDC* pDC, CColorEyeIDoc* pDoc, CPoint ptTemp)
{
    //資料寫出
    //資料鍊一條變多條（各量測項目）
    //無關順序
    std::vector<Cartridge> vW5 = pDoc->GetOmdFile().AddMsrData(White, Pn5);
    CTable tbW5 (pDC, ptTemp);
    
    int CellWidth = 176;
    ptTemp = tbW5.SetCellNum(3, 7).SetGridBoard(0).SetTableBoard(1).SetCellSpace(10)
        .Width(0, CellWidth).Width(1, CellWidth).Width(2, CellWidth)//.Width(3, CellWidth).Width(4, CellWidth).Width(5, CellWidth).Width(6, CellWidth)
        .tr().td().text(vW5[0].GetStrLv(), TA_CENTER).td_().td()                                   .td_().td().text(vW5[1].GetStrLv(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td()                                   .td_().td().text(vW5[2].GetStrLv(), TA_CENTER).td_().td()                                   .td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vW5[3].GetStrLv(), TA_CENTER).td_().td()                                   .td_().td().text(vW5[4].GetStrLv(), TA_CENTER).td_().td().tr_()
        .table_();
    
    return ptTemp;
}

CPoint CColorEyeIView::DrawW05Table_Sx(CDC* pDC, CColorEyeIDoc* pDoc, CPoint ptTemp)
{
    //資料寫出
    //資料鍊一條變多條（各量測項目）
    //無關順序
    std::vector<Cartridge> vW5 = pDoc->GetOmdFile().AddMsrData(White, Pn5);
    CTable tbW5 (pDC, ptTemp);
    
    int CellWidth = 176;
    ptTemp = tbW5.SetCellNum(3, 7).SetGridBoard(0).SetTableBoard(1).SetCellSpace(10)
        .Width(0, CellWidth).Width(1, CellWidth).Width(2, CellWidth)//.Width(3, CellWidth).Width(4, CellWidth).Width(5, CellWidth).Width(6, CellWidth)
        .tr().td().text(vW5[0].GetStrSx(), TA_CENTER).td_().td()                                   .td_().td().text(vW5[1].GetStrSx(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td()                                   .td_().td().text(vW5[2].GetStrSx(), TA_CENTER).td_().td()                                   .td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vW5[3].GetStrSx(), TA_CENTER).td_().td()                                   .td_().td().text(vW5[4].GetStrSx(), TA_CENTER).td_().td().tr_()
        .table_();
    
    return ptTemp;
}

CPoint CColorEyeIView::DrawW05Table_Sy(CDC* pDC, CColorEyeIDoc* pDoc, CPoint ptTemp)
{
    //資料寫出
    //資料鍊一條變多條（各量測項目）
    //無關順序
    std::vector<Cartridge> vW5 = pDoc->GetOmdFile().AddMsrData(White, Pn5);
    CTable tbW5 (pDC, ptTemp);
    
    int CellWidth = 176;
    ptTemp = tbW5.SetCellNum(3, 7).SetGridBoard(0).SetTableBoard(1).SetCellSpace(10)
        .Width(0, CellWidth).Width(1, CellWidth).Width(2, CellWidth)//.Width(3, CellWidth).Width(4, CellWidth).Width(5, CellWidth).Width(6, CellWidth)
        .tr().td().text(vW5[0].GetStrSy(), TA_CENTER).td_().td()                                   .td_().td().text(vW5[1].GetStrSy(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td()                                   .td_().td().text(vW5[2].GetStrSy(), TA_CENTER).td_().td()                                   .td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vW5[3].GetStrSy(), TA_CENTER).td_().td()                                   .td_().td().text(vW5[4].GetStrSy(), TA_CENTER).td_().td().tr_()
        .table_();
    
    return ptTemp;
}

CPoint CColorEyeIView::DrawW05Table_Du(CDC* pDC, CColorEyeIDoc* pDoc, CPoint ptTemp)
{
    //資料寫出
    //資料鍊一條變多條（各量測項目）
    //無關順序
    std::vector<Cartridge> vW5 = pDoc->GetOmdFile().AddMsrData(White, Pn5);
    CTable tbW5 (pDC, ptTemp);
    
    int CellWidth = 176;
    ptTemp = tbW5.SetCellNum(3, 7).SetGridBoard(0).SetTableBoard(1).SetCellSpace(10)
        .Width(0, CellWidth).Width(1, CellWidth).Width(2, CellWidth)//.Width(3, CellWidth).Width(4, CellWidth).Width(5, CellWidth).Width(6, CellWidth)
        .tr().td().text(vW5[0].GetStrDu(), TA_CENTER).td_().td()                                   .td_().td().text(vW5[1].GetStrDu(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td()                                   .td_().td().text(vW5[2].GetStrDu(), TA_CENTER).td_().td()                                   .td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vW5[3].GetStrDu(), TA_CENTER).td_().td()                                   .td_().td().text(vW5[4].GetStrDu(), TA_CENTER).td_().td().tr_()
        .table_();
    
    return ptTemp;
}

CPoint CColorEyeIView::DrawW05Table_Dv(CDC* pDC, CColorEyeIDoc* pDoc, CPoint ptTemp)
{
    //資料寫出
    //資料鍊一條變多條（各量測項目）
    //無關順序
    std::vector<Cartridge> vW5 = pDoc->GetOmdFile().AddMsrData(White, Pn5);
    CTable tbW5 (pDC, ptTemp);
    
    int CellWidth = 176;
    ptTemp = tbW5.SetCellNum(3, 7).SetGridBoard(0).SetTableBoard(1).SetCellSpace(10)
        .Width(0, CellWidth).Width(1, CellWidth).Width(2, CellWidth)//.Width(3, CellWidth).Width(4, CellWidth).Width(5, CellWidth).Width(6, CellWidth)
        .tr().td().text(vW5[0].GetStrDv(), TA_CENTER).td_().td()                                   .td_().td().text(vW5[1].GetStrDv(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td()                                   .td_().td().text(vW5[2].GetStrDv(), TA_CENTER).td_().td()                                   .td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vW5[3].GetStrDv(), TA_CENTER).td_().td()                                   .td_().td().text(vW5[4].GetStrDv(), TA_CENTER).td_().td().tr_()
        .table_();
    
    return ptTemp;
}

CPoint CColorEyeIView::DrawW05Table_Duv(CDC* pDC, CColorEyeIDoc* pDoc, CPoint ptTemp)
{
    //資料寫出
    //資料鍊一條變多條（各量測項目）
    //無關順序
    std::vector<Cartridge> vW5 = pDoc->GetOmdFile().AddMsrData(White, Pn5);
    CTable tbW5 (pDC, ptTemp);
    
    int CellWidth = 176;
    ptTemp = tbW5.SetCellNum(3, 7).SetGridBoard(0).SetTableBoard(1).SetCellSpace(10)
        .Width(0, CellWidth).Width(1, CellWidth).Width(2, CellWidth)//.Width(3, CellWidth).Width(4, CellWidth).Width(5, CellWidth).Width(6, CellWidth)
        .tr().td().text(vW5[0].GetStrDuv(), TA_CENTER).td_().td()                                   .td_().td().text(vW5[1].GetStrDuv(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td()                                   .td_().td().text(vW5[2].GetStrDuv(), TA_CENTER).td_().td()                                   .td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vW5[3].GetStrDuv(), TA_CENTER).td_().td()                                   .td_().td().text(vW5[4].GetStrDuv(), TA_CENTER).td_().td().tr_()
        .table_();
    
    return ptTemp;
}

CPoint CColorEyeIView::DrawW05Table_T(CDC* pDC, CColorEyeIDoc* pDoc, CPoint ptTemp)
{
    //資料寫出
    //資料鍊一條變多條（各量測項目）
    //無關順序
    std::vector<Cartridge> vW5 = pDoc->GetOmdFile().AddMsrData(White, Pn5);
    CTable tbW5 (pDC, ptTemp);
    
    int CellWidth = 176;
    ptTemp = tbW5.SetCellNum(3, 7).SetGridBoard(0).SetTableBoard(1).SetCellSpace(10)
        .Width(0, CellWidth).Width(1, CellWidth).Width(2, CellWidth)//.Width(3, CellWidth).Width(4, CellWidth).Width(5, CellWidth).Width(6, CellWidth)
        .tr().td().text(vW5[0].GetStrT(), TA_CENTER).td_().td()                                   .td_().td().text(vW5[1].GetStrT(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td()                                   .td_().td().text(vW5[2].GetStrT(), TA_CENTER).td_().td()                                   .td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vW5[3].GetStrT(), TA_CENTER).td_().td()                                   .td_().td().text(vW5[4].GetStrT(), TA_CENTER).td_().td().tr_()
        .table_();
    
    return ptTemp;
}

CPoint CColorEyeIView::DrawW05Table_X(CDC* pDC, CColorEyeIDoc* pDoc, CPoint ptTemp)
{
    //資料寫出
    //資料鍊一條變多條（各量測項目）
    //無關順序
    std::vector<Cartridge> vW5 = pDoc->GetOmdFile().AddMsrData(White, Pn5);
    CTable tbW5 (pDC, ptTemp);
    
    int CellWidth = 176;
    ptTemp = tbW5.SetCellNum(3, 7).SetGridBoard(0).SetTableBoard(1).SetCellSpace(10)
        .Width(0, CellWidth).Width(1, CellWidth).Width(2, CellWidth)//.Width(3, CellWidth).Width(4, CellWidth).Width(5, CellWidth).Width(6, CellWidth)
        .tr().td().text(vW5[0].GetStrX(), TA_CENTER).td_().td()                                   .td_().td().text(vW5[1].GetStrX(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td()                                   .td_().td().text(vW5[2].GetStrX(), TA_CENTER).td_().td()                                   .td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vW5[3].GetStrX(), TA_CENTER).td_().td()                                   .td_().td().text(vW5[4].GetStrX(), TA_CENTER).td_().td().tr_()
        .table_();
    
    return ptTemp;
}

CPoint CColorEyeIView::DrawW05Table_Y(CDC* pDC, CColorEyeIDoc* pDoc, CPoint ptTemp)
{
    //資料寫出
    //資料鍊一條變多條（各量測項目）
    //無關順序
    std::vector<Cartridge> vW5 = pDoc->GetOmdFile().AddMsrData(White, Pn5);
    CTable tbW5 (pDC, ptTemp);
    
    int CellWidth = 176;
    ptTemp = tbW5.SetCellNum(3, 7).SetGridBoard(0).SetTableBoard(1).SetCellSpace(10)
        .Width(0, CellWidth).Width(1, CellWidth).Width(2, CellWidth)//.Width(3, CellWidth).Width(4, CellWidth).Width(5, CellWidth).Width(6, CellWidth)
        .tr().td().text(vW5[0].GetStrY(), TA_CENTER).td_().td()                                   .td_().td().text(vW5[1].GetStrY(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td()                                   .td_().td().text(vW5[2].GetStrY(), TA_CENTER).td_().td()                                   .td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vW5[3].GetStrY(), TA_CENTER).td_().td()                                   .td_().td().text(vW5[4].GetStrY(), TA_CENTER).td_().td().tr_()
        .table_();
    
    return ptTemp;
}

CPoint CColorEyeIView::DrawW05Table_Z(CDC* pDC, CColorEyeIDoc* pDoc, CPoint ptTemp)
{
    //資料寫出
    //資料鍊一條變多條（各量測項目）
    //無關順序
    std::vector<Cartridge> vW5 = pDoc->GetOmdFile().AddMsrData(White, Pn5);
    CTable tbW5 (pDC, ptTemp);
    
    int CellWidth = 176;
    ptTemp = tbW5.SetCellNum(3, 7).SetGridBoard(0).SetTableBoard(1).SetCellSpace(10)
        .Width(0, CellWidth).Width(1, CellWidth).Width(2, CellWidth)//.Width(3, CellWidth).Width(4, CellWidth).Width(5, CellWidth).Width(6, CellWidth)
        .tr().td().text(vW5[0].GetStrZ(), TA_CENTER).td_().td()                                   .td_().td().text(vW5[1].GetStrZ(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td()                                   .td_().td().text(vW5[2].GetStrZ(), TA_CENTER).td_().td()                                   .td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vW5[3].GetStrZ(), TA_CENTER).td_().td()                                   .td_().td().text(vW5[4].GetStrZ(), TA_CENTER).td_().td().tr_()
        .table_();
    
    return ptTemp;
}

CPoint CColorEyeIView::DrawW09Table_Lv(CDC* pDC, CColorEyeIDoc* pDoc, CPoint ptTemp)
{
    //資料寫出
    //資料鍊一條變多條（各量測項目）
    //無關順序
    std::vector<Cartridge> vW9  = pDoc->GetOmdFile().AddMsrData(White, Pn9);
    //輸出表格W9
    CTable tbW9 (pDC, ptTemp);
    
    int CellWidth = 176;
    ptTemp = tbW9.SetCellNum(3, 7).SetGridBoard(0).SetTableBoard(1).SetCellSpace(10)
        .Width(0, CellWidth).Width(1, CellWidth).Width(2, CellWidth)//.Width(3, CellWidth).Width(4, CellWidth).Width(5, CellWidth).Width(6, CellWidth)
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vW9[0].GetStrLv(), TA_CENTER).td_().td().text(vW9[1].GetStrLv(), TA_CENTER).td_().td().text(vW9[2].GetStrLv(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vW9[3].GetStrLv(), TA_CENTER).td_().td().text(vW9[4].GetStrLv(), TA_CENTER).td_().td().text(vW9[5].GetStrLv(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vW9[6].GetStrLv(), TA_CENTER).td_().td().text(vW9[7].GetStrLv(), TA_CENTER).td_().td().text(vW9[8].GetStrLv(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .table_();
    
    return ptTemp;
}

CPoint CColorEyeIView::DrawW09Table_Sx(CDC* pDC, CColorEyeIDoc* pDoc, CPoint ptTemp)
{
    //資料寫出
    //資料鍊一條變多條（各量測項目）
    //無關順序
    std::vector<Cartridge> vW9  = pDoc->GetOmdFile().AddMsrData(White, Pn9);
    //輸出表格W9
    CTable tbW9 (pDC, ptTemp);
    
    int CellWidth = 176;
    ptTemp = tbW9.SetCellNum(3, 7).SetGridBoard(0).SetTableBoard(1).SetCellSpace(10)
        .Width(0, CellWidth).Width(1, CellWidth).Width(2, CellWidth)//.Width(3, CellWidth).Width(4, CellWidth).Width(5, CellWidth).Width(6, CellWidth)
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vW9[0].GetStrSx(), TA_CENTER).td_().td().text(vW9[1].GetStrSx(), TA_CENTER).td_().td().text(vW9[2].GetStrSx(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vW9[3].GetStrSx(), TA_CENTER).td_().td().text(vW9[4].GetStrSx(), TA_CENTER).td_().td().text(vW9[5].GetStrSx(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vW9[6].GetStrSx(), TA_CENTER).td_().td().text(vW9[7].GetStrSx(), TA_CENTER).td_().td().text(vW9[8].GetStrSx(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .table_();
    
    return ptTemp;
}

CPoint CColorEyeIView::DrawW09Table_Sy(CDC* pDC, CColorEyeIDoc* pDoc, CPoint ptTemp)
{
    //資料寫出
    //資料鍊一條變多條（各量測項目）
    //無關順序
    std::vector<Cartridge> vW9  = pDoc->GetOmdFile().AddMsrData(White, Pn9);
    //輸出表格W9
    CTable tbW9 (pDC, ptTemp);
    
    int CellWidth = 176;
    ptTemp = tbW9.SetCellNum(3, 7).SetGridBoard(0).SetTableBoard(1).SetCellSpace(10)
        .Width(0, CellWidth).Width(1, CellWidth).Width(2, CellWidth)//.Width(3, CellWidth).Width(4, CellWidth).Width(5, CellWidth).Width(6, CellWidth)
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vW9[0].GetStrSy(), TA_CENTER).td_().td().text(vW9[1].GetStrSy(), TA_CENTER).td_().td().text(vW9[2].GetStrSy(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vW9[3].GetStrSy(), TA_CENTER).td_().td().text(vW9[4].GetStrSy(), TA_CENTER).td_().td().text(vW9[5].GetStrSy(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vW9[6].GetStrSy(), TA_CENTER).td_().td().text(vW9[7].GetStrSy(), TA_CENTER).td_().td().text(vW9[8].GetStrSy(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .table_();
    
    return ptTemp;
}

CPoint CColorEyeIView::DrawW09Table_Du(CDC* pDC, CColorEyeIDoc* pDoc, CPoint ptTemp)
{
    //資料寫出
    //資料鍊一條變多條（各量測項目）
    //無關順序
    std::vector<Cartridge> vW9  = pDoc->GetOmdFile().AddMsrData(White, Pn9);
    //輸出表格W9
    CTable tbW9 (pDC, ptTemp);
    
    int CellWidth = 176;
    ptTemp = tbW9.SetCellNum(3, 7).SetGridBoard(0).SetTableBoard(1).SetCellSpace(10)
        .Width(0, CellWidth).Width(1, CellWidth).Width(2, CellWidth)//.Width(3, CellWidth).Width(4, CellWidth).Width(5, CellWidth).Width(6, CellWidth)
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vW9[0].GetStrDu(), TA_CENTER).td_().td().text(vW9[1].GetStrDu(), TA_CENTER).td_().td().text(vW9[2].GetStrDu(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vW9[3].GetStrDu(), TA_CENTER).td_().td().text(vW9[4].GetStrDu(), TA_CENTER).td_().td().text(vW9[5].GetStrDu(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vW9[6].GetStrDu(), TA_CENTER).td_().td().text(vW9[7].GetStrDu(), TA_CENTER).td_().td().text(vW9[8].GetStrDu(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .table_();
    
    return ptTemp;
}

CPoint CColorEyeIView::DrawW09Table_Dv(CDC* pDC, CColorEyeIDoc* pDoc, CPoint ptTemp)
{
    //資料寫出
    //資料鍊一條變多條（各量測項目）
    //無關順序
    std::vector<Cartridge> vW9  = pDoc->GetOmdFile().AddMsrData(White, Pn9);
    //輸出表格W9
    CTable tbW9 (pDC, ptTemp);
    
    int CellWidth = 176;
    ptTemp = tbW9.SetCellNum(3, 7).SetGridBoard(0).SetTableBoard(1).SetCellSpace(10)
        .Width(0, CellWidth).Width(1, CellWidth).Width(2, CellWidth)//.Width(3, CellWidth).Width(4, CellWidth).Width(5, CellWidth).Width(6, CellWidth)
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vW9[0].GetStrDv(), TA_CENTER).td_().td().text(vW9[1].GetStrDv(), TA_CENTER).td_().td().text(vW9[2].GetStrDv(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vW9[3].GetStrDv(), TA_CENTER).td_().td().text(vW9[4].GetStrDv(), TA_CENTER).td_().td().text(vW9[5].GetStrDv(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vW9[6].GetStrDv(), TA_CENTER).td_().td().text(vW9[7].GetStrDv(), TA_CENTER).td_().td().text(vW9[8].GetStrDv(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .table_();
    
    return ptTemp;
}

CPoint CColorEyeIView::DrawW09Table_T(CDC* pDC, CColorEyeIDoc* pDoc, CPoint ptTemp)
{
    //資料寫出
    //資料鍊一條變多條（各量測項目）
    //無關順序
    std::vector<Cartridge> vW9  = pDoc->GetOmdFile().AddMsrData(White, Pn9);
    //輸出表格W9
    CTable tbW9 (pDC, ptTemp);
    
    int CellWidth = 176;
    ptTemp = tbW9.SetCellNum(3, 7).SetGridBoard(0).SetTableBoard(1).SetCellSpace(10)
        .Width(0, CellWidth).Width(1, CellWidth).Width(2, CellWidth)//.Width(3, CellWidth).Width(4, CellWidth).Width(5, CellWidth).Width(6, CellWidth)
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vW9[0].GetStrT(), TA_CENTER).td_().td().text(vW9[1].GetStrT(), TA_CENTER).td_().td().text(vW9[2].GetStrT(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vW9[3].GetStrT(), TA_CENTER).td_().td().text(vW9[4].GetStrT(), TA_CENTER).td_().td().text(vW9[5].GetStrT(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vW9[6].GetStrT(), TA_CENTER).td_().td().text(vW9[7].GetStrT(), TA_CENTER).td_().td().text(vW9[8].GetStrT(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .table_();
    
    return ptTemp;
}

CPoint CColorEyeIView::DrawW09Table_Duv(CDC* pDC, CColorEyeIDoc* pDoc, CPoint ptTemp)
{
    //資料寫出
    //資料鍊一條變多條（各量測項目）
    //無關順序
    std::vector<Cartridge> vW9  = pDoc->GetOmdFile().AddMsrData(White, Pn9);
    //輸出表格W9
    CTable tbW9 (pDC, ptTemp);
    
    int CellWidth = 176;
    ptTemp = tbW9.SetCellNum(3, 7).SetGridBoard(0).SetTableBoard(1).SetCellSpace(10)
        .Width(0, CellWidth).Width(1, CellWidth).Width(2, CellWidth)//.Width(3, CellWidth).Width(4, CellWidth).Width(5, CellWidth).Width(6, CellWidth)
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vW9[0].GetStrDuv(), TA_CENTER).td_().td().text(vW9[1].GetStrDuv(), TA_CENTER).td_().td().text(vW9[2].GetStrDuv(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vW9[3].GetStrDuv(), TA_CENTER).td_().td().text(vW9[4].GetStrDuv(), TA_CENTER).td_().td().text(vW9[5].GetStrDuv(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vW9[6].GetStrDuv(), TA_CENTER).td_().td().text(vW9[7].GetStrDuv(), TA_CENTER).td_().td().text(vW9[8].GetStrDuv(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .table_();
    
    return ptTemp;
}

CPoint CColorEyeIView::DrawW09Table_X(CDC* pDC, CColorEyeIDoc* pDoc, CPoint ptTemp)
{
    //資料寫出
    //資料鍊一條變多條（各量測項目）
    //無關順序
    std::vector<Cartridge> vW9  = pDoc->GetOmdFile().AddMsrData(White, Pn9);
    //輸出表格W9
    CTable tbW9 (pDC, ptTemp);
    
    int CellWidth = 176;
    ptTemp = tbW9.SetCellNum(3, 7).SetGridBoard(0).SetTableBoard(1).SetCellSpace(10)
        .Width(0, CellWidth).Width(1, CellWidth).Width(2, CellWidth)//.Width(3, CellWidth).Width(4, CellWidth).Width(5, CellWidth).Width(6, CellWidth)
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vW9[0].GetStrX(), TA_CENTER).td_().td().text(vW9[1].GetStrX(), TA_CENTER).td_().td().text(vW9[2].GetStrX(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vW9[3].GetStrX(), TA_CENTER).td_().td().text(vW9[4].GetStrX(), TA_CENTER).td_().td().text(vW9[5].GetStrX(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vW9[6].GetStrX(), TA_CENTER).td_().td().text(vW9[7].GetStrX(), TA_CENTER).td_().td().text(vW9[8].GetStrX(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .table_();
    
    return ptTemp;
}

CPoint CColorEyeIView::DrawW09Table_Y(CDC* pDC, CColorEyeIDoc* pDoc, CPoint ptTemp)
{
    //資料寫出
    //資料鍊一條變多條（各量測項目）
    //無關順序
    std::vector<Cartridge> vW9  = pDoc->GetOmdFile().AddMsrData(White, Pn9);
    //輸出表格W9
    CTable tbW9 (pDC, ptTemp);
    
    int CellWidth = 176;
    ptTemp = tbW9.SetCellNum(3, 7).SetGridBoard(0).SetTableBoard(1).SetCellSpace(10)
        .Width(0, CellWidth).Width(1, CellWidth).Width(2, CellWidth)//.Width(3, CellWidth).Width(4, CellWidth).Width(5, CellWidth).Width(6, CellWidth)
        .tr().td()                                  .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vW9[0].GetStrY(), TA_CENTER).td_().td().text(vW9[1].GetStrY(), TA_CENTER).td_().td().text(vW9[2].GetStrY(), TA_CENTER).td_().td().tr_()
        .tr().td()                                  .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vW9[3].GetStrY(), TA_CENTER).td_().td().text(vW9[4].GetStrY(), TA_CENTER).td_().td().text(vW9[5].GetStrY(), TA_CENTER).td_().td().tr_()
        .tr().td()                                  .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vW9[6].GetStrY(), TA_CENTER).td_().td().text(vW9[7].GetStrY(), TA_CENTER).td_().td().text(vW9[8].GetStrY(), TA_CENTER).td_().td().tr_()
        .tr().td()                                  .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .table_();   
    
    return ptTemp;
}

CPoint CColorEyeIView::DrawW09Table_Z(CDC* pDC, CColorEyeIDoc* pDoc, CPoint ptTemp)
{
    //資料寫出
    //資料鍊一條變多條（各量測項目）
    //無關順序
    std::vector<Cartridge> vW9  = pDoc->GetOmdFile().AddMsrData(White, Pn9);
    //輸出表格W9
    CTable tbW9 (pDC, ptTemp);
    
    int CellWidth = 176;
    ptTemp = tbW9.SetCellNum(3, 7).SetGridBoard(0).SetTableBoard(1).SetCellSpace(10)
        .Width(0, CellWidth).Width(1, CellWidth).Width(2, CellWidth)//.Width(3, CellWidth).Width(4, CellWidth).Width(5, CellWidth).Width(6, CellWidth)
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vW9[0].GetStrZ(), TA_CENTER).td_().td().text(vW9[1].GetStrZ(), TA_CENTER).td_().td().text(vW9[2].GetStrZ(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vW9[3].GetStrZ(), TA_CENTER).td_().td().text(vW9[4].GetStrZ(), TA_CENTER).td_().td().text(vW9[5].GetStrZ(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vW9[6].GetStrZ(), TA_CENTER).td_().td().text(vW9[7].GetStrZ(), TA_CENTER).td_().td().text(vW9[8].GetStrZ(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .table_();
    
    return ptTemp;
}

CPoint CColorEyeIView::DrawW49Table_Lv(CDC* pDC, CColorEyeIDoc* pDoc, CPoint ptTemp)
{
    //資料寫出
    //資料鍊一條變多條（各量測項目）
    //無關順序
    std::vector<Cartridge> vW49 = pDoc->GetOmdFile().AddMsrData(White, Pn49);
    //輸出表格W49
    CTable tbW49  (pDC, ptTemp);
    int CellWidth = 64;
    ptTemp = tbW49.SetCellNum(7, 7).SetGridBoard(0).SetTableBoard(1).SetCellSpace(10)
        .Width(0, CellWidth).Width(1, CellWidth).Width(2, CellWidth).Width(3, CellWidth).Width(4, CellWidth).Width(5, CellWidth).Width(6, CellWidth)
        .tr().td().text(vW49[ 0].GetStrLv(), TA_CENTER).td_().td()    .text(vW49[ 1].GetStrLv(), TA_CENTER)     .td_().td().text(vW49[ 2].GetStrLv(), TA_CENTER).td_().td()    .text(vW49[ 3].GetStrLv(), TA_CENTER)     .td_().td().text(vW49[ 4].GetStrLv(), TA_CENTER).td_().td()    .text(vW49[ 5].GetStrLv(), TA_CENTER)     .td_().td().text(vW49[ 6].GetStrLv(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[ 7].GetStrLv(), TA_CENTER).td_().td().b().text(vW49[ 8].GetStrLv(), TA_CENTER).b_().td_().td().text(vW49[ 9].GetStrLv(), TA_CENTER).td_().td().b().text(vW49[10].GetStrLv(), TA_CENTER).b_().td_().td().text(vW49[11].GetStrLv(), TA_CENTER).td_().td().b().text(vW49[12].GetStrLv(), TA_CENTER).b_().td_().td().text(vW49[13].GetStrLv(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[14].GetStrLv(), TA_CENTER).td_().td()    .text(vW49[15].GetStrLv(), TA_CENTER)     .td_().td().text(vW49[16].GetStrLv(), TA_CENTER).td_().td()    .text(vW49[17].GetStrLv(), TA_CENTER)     .td_().td().text(vW49[18].GetStrLv(), TA_CENTER).td_().td()    .text(vW49[15].GetStrLv(), TA_CENTER)     .td_().td().text(vW49[16].GetStrLv(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[21].GetStrLv(), TA_CENTER).td_().td().b().text(vW49[22].GetStrLv(), TA_CENTER).b_().td_().td().text(vW49[23].GetStrLv(), TA_CENTER).td_().td().b().text(vW49[24].GetStrLv(), TA_CENTER).b_().td_().td().text(vW49[25].GetStrLv(), TA_CENTER).td_().td().b().text(vW49[26].GetStrLv(), TA_CENTER).b_().td_().td().text(vW49[27].GetStrLv(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[28].GetStrLv(), TA_CENTER).td_().td()    .text(vW49[29].GetStrLv(), TA_CENTER)     .td_().td().text(vW49[30].GetStrLv(), TA_CENTER).td_().td()    .text(vW49[31].GetStrLv(), TA_CENTER)     .td_().td().text(vW49[32].GetStrLv(), TA_CENTER).td_().td()    .text(vW49[33].GetStrLv(), TA_CENTER)     .td_().td().text(vW49[34].GetStrLv(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[35].GetStrLv(), TA_CENTER).td_().td().b().text(vW49[36].GetStrLv(), TA_CENTER).b_().td_().td().text(vW49[37].GetStrLv(), TA_CENTER).td_().td().b().text(vW49[38].GetStrLv(), TA_CENTER).b_().td_().td().text(vW49[39].GetStrLv(), TA_CENTER).td_().td().b().text(vW49[40].GetStrLv(), TA_CENTER).b_().td_().td().text(vW49[42].GetStrLv(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[42].GetStrLv(), TA_CENTER).td_().td()    .text(vW49[43].GetStrLv(), TA_CENTER)     .td_().td().text(vW49[44].GetStrLv(), TA_CENTER).td_().td()    .text(vW49[45].GetStrLv(), TA_CENTER)     .td_().td().text(vW49[46].GetStrLv(), TA_CENTER).td_().td()    .text(vW49[47].GetStrLv(), TA_CENTER)     .td_().td().text(vW49[48].GetStrLv(), TA_CENTER).td_().tr_()
        .table_();
    
    return ptTemp;
}

CPoint CColorEyeIView::DrawW49Table_Sx(CDC* pDC, CColorEyeIDoc* pDoc, CPoint ptTemp)
{
    //資料寫出
    //資料鍊一條變多條（各量測項目）
    //無關順序
    std::vector<Cartridge> vW49 = pDoc->GetOmdFile().AddMsrData(White, Pn49);
    //輸出表格W49
    CTable tbW49  (pDC, ptTemp);
    int CellWidth = 64;
    ptTemp = tbW49.SetCellNum(7, 7).SetGridBoard(0).SetTableBoard(1).SetCellSpace(10)
        .Width(0, CellWidth).Width(1, CellWidth).Width(2, CellWidth).Width(3, CellWidth).Width(4, CellWidth).Width(5, CellWidth).Width(6, CellWidth)
        .tr().td().text(vW49[ 0].GetStrSx(), TA_CENTER).td_().td()    .text(vW49[ 1].GetStrSx(), TA_CENTER)     .td_().td().text(vW49[ 2].GetStrSx(), TA_CENTER).td_().td()    .text(vW49[ 3].GetStrSx(), TA_CENTER)     .td_().td().text(vW49[ 4].GetStrSx(), TA_CENTER).td_().td()    .text(vW49[ 5].GetStrSx(), TA_CENTER)     .td_().td().text(vW49[ 6].GetStrSx(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[ 7].GetStrSx(), TA_CENTER).td_().td().b().text(vW49[ 8].GetStrSx(), TA_CENTER).b_().td_().td().text(vW49[ 9].GetStrSx(), TA_CENTER).td_().td().b().text(vW49[10].GetStrSx(), TA_CENTER).b_().td_().td().text(vW49[11].GetStrSx(), TA_CENTER).td_().td().b().text(vW49[12].GetStrSx(), TA_CENTER).b_().td_().td().text(vW49[13].GetStrSx(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[14].GetStrSx(), TA_CENTER).td_().td()    .text(vW49[15].GetStrSx(), TA_CENTER)     .td_().td().text(vW49[16].GetStrSx(), TA_CENTER).td_().td()    .text(vW49[17].GetStrSx(), TA_CENTER)     .td_().td().text(vW49[18].GetStrSx(), TA_CENTER).td_().td()    .text(vW49[15].GetStrSx(), TA_CENTER)     .td_().td().text(vW49[16].GetStrSx(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[21].GetStrSx(), TA_CENTER).td_().td().b().text(vW49[22].GetStrSx(), TA_CENTER).b_().td_().td().text(vW49[23].GetStrSx(), TA_CENTER).td_().td().b().text(vW49[24].GetStrSx(), TA_CENTER).b_().td_().td().text(vW49[25].GetStrSx(), TA_CENTER).td_().td().b().text(vW49[26].GetStrSx(), TA_CENTER).b_().td_().td().text(vW49[27].GetStrSx(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[28].GetStrSx(), TA_CENTER).td_().td()    .text(vW49[29].GetStrSx(), TA_CENTER)     .td_().td().text(vW49[30].GetStrSx(), TA_CENTER).td_().td()    .text(vW49[31].GetStrSx(), TA_CENTER)     .td_().td().text(vW49[32].GetStrSx(), TA_CENTER).td_().td()    .text(vW49[33].GetStrSx(), TA_CENTER)     .td_().td().text(vW49[34].GetStrSx(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[35].GetStrSx(), TA_CENTER).td_().td().b().text(vW49[36].GetStrSx(), TA_CENTER).b_().td_().td().text(vW49[37].GetStrSx(), TA_CENTER).td_().td().b().text(vW49[38].GetStrSx(), TA_CENTER).b_().td_().td().text(vW49[39].GetStrSx(), TA_CENTER).td_().td().b().text(vW49[40].GetStrSx(), TA_CENTER).b_().td_().td().text(vW49[42].GetStrSx(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[42].GetStrSx(), TA_CENTER).td_().td()    .text(vW49[43].GetStrSx(), TA_CENTER)     .td_().td().text(vW49[44].GetStrSx(), TA_CENTER).td_().td()    .text(vW49[45].GetStrSx(), TA_CENTER)     .td_().td().text(vW49[46].GetStrSx(), TA_CENTER).td_().td()    .text(vW49[47].GetStrSx(), TA_CENTER)     .td_().td().text(vW49[48].GetStrSx(), TA_CENTER).td_().tr_()
        .table_();

    return ptTemp;
}

CPoint CColorEyeIView::DrawW49Table_Sy(CDC* pDC, CColorEyeIDoc* pDoc, CPoint ptTemp)
{
    //資料寫出
    //資料鍊一條變多條（各量測項目）
    //無關順序
    std::vector<Cartridge> vW49 = pDoc->GetOmdFile().AddMsrData(White, Pn49);
    //輸出表格W49
    CTable tbW49  (pDC, ptTemp);
    int CellWidth = 64;
    ptTemp = tbW49.SetCellNum(7, 7).SetGridBoard(0).SetTableBoard(1).SetCellSpace(10)
        .Width(0, CellWidth).Width(1, CellWidth).Width(2, CellWidth).Width(3, CellWidth).Width(4, CellWidth).Width(5, CellWidth).Width(6, CellWidth)
        .tr().td().text(vW49[ 0].GetStrSy(), TA_CENTER).td_().td()    .text(vW49[ 1].GetStrSy(), TA_CENTER)     .td_().td().text(vW49[ 2].GetStrSy(), TA_CENTER).td_().td()    .text(vW49[ 3].GetStrSy(), TA_CENTER)     .td_().td().text(vW49[ 4].GetStrSy(), TA_CENTER).td_().td()    .text(vW49[ 5].GetStrSy(), TA_CENTER)     .td_().td().text(vW49[ 6].GetStrSy(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[ 7].GetStrSy(), TA_CENTER).td_().td().b().text(vW49[ 8].GetStrSy(), TA_CENTER).b_().td_().td().text(vW49[ 9].GetStrSy(), TA_CENTER).td_().td().b().text(vW49[10].GetStrSy(), TA_CENTER).b_().td_().td().text(vW49[11].GetStrSy(), TA_CENTER).td_().td().b().text(vW49[12].GetStrSy(), TA_CENTER).b_().td_().td().text(vW49[13].GetStrSy(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[14].GetStrSy(), TA_CENTER).td_().td()    .text(vW49[15].GetStrSy(), TA_CENTER)     .td_().td().text(vW49[16].GetStrSy(), TA_CENTER).td_().td()    .text(vW49[17].GetStrSy(), TA_CENTER)     .td_().td().text(vW49[18].GetStrSy(), TA_CENTER).td_().td()    .text(vW49[15].GetStrSy(), TA_CENTER)     .td_().td().text(vW49[16].GetStrSy(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[21].GetStrSy(), TA_CENTER).td_().td().b().text(vW49[22].GetStrSy(), TA_CENTER).b_().td_().td().text(vW49[23].GetStrSy(), TA_CENTER).td_().td().b().text(vW49[24].GetStrSy(), TA_CENTER).b_().td_().td().text(vW49[25].GetStrSy(), TA_CENTER).td_().td().b().text(vW49[26].GetStrSy(), TA_CENTER).b_().td_().td().text(vW49[27].GetStrSy(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[28].GetStrSy(), TA_CENTER).td_().td()    .text(vW49[29].GetStrSy(), TA_CENTER)     .td_().td().text(vW49[30].GetStrSy(), TA_CENTER).td_().td()    .text(vW49[31].GetStrSy(), TA_CENTER)     .td_().td().text(vW49[32].GetStrSy(), TA_CENTER).td_().td()    .text(vW49[33].GetStrSy(), TA_CENTER)     .td_().td().text(vW49[34].GetStrSy(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[35].GetStrSy(), TA_CENTER).td_().td().b().text(vW49[36].GetStrSy(), TA_CENTER).b_().td_().td().text(vW49[37].GetStrSy(), TA_CENTER).td_().td().b().text(vW49[38].GetStrSy(), TA_CENTER).b_().td_().td().text(vW49[39].GetStrSy(), TA_CENTER).td_().td().b().text(vW49[40].GetStrSy(), TA_CENTER).b_().td_().td().text(vW49[42].GetStrSy(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[42].GetStrSy(), TA_CENTER).td_().td()    .text(vW49[43].GetStrSy(), TA_CENTER)     .td_().td().text(vW49[44].GetStrSy(), TA_CENTER).td_().td()    .text(vW49[45].GetStrSy(), TA_CENTER)     .td_().td().text(vW49[46].GetStrSy(), TA_CENTER).td_().td()    .text(vW49[47].GetStrSy(), TA_CENTER)     .td_().td().text(vW49[48].GetStrSy(), TA_CENTER).td_().tr_()
        .table_();

    return ptTemp;
}

CPoint CColorEyeIView::DrawW49Table_Du(CDC* pDC, CColorEyeIDoc* pDoc, CPoint ptTemp)
{
    //資料寫出
    //資料鍊一條變多條（各量測項目）
    //無關順序
    std::vector<Cartridge> vW49 = pDoc->GetOmdFile().AddMsrData(White, Pn49);
    //輸出表格W49
    CTable tbW49  (pDC, ptTemp);
    int CellWidth = 64;
    ptTemp = tbW49.SetCellNum(7, 7).SetGridBoard(0).SetTableBoard(1).SetCellSpace(10)
        .Width(0, CellWidth).Width(1, CellWidth).Width(2, CellWidth).Width(3, CellWidth).Width(4, CellWidth).Width(5, CellWidth).Width(6, CellWidth)
        .tr().td().text(vW49[ 0].GetStrDu(), TA_CENTER).td_().td()    .text(vW49[ 1].GetStrDu(), TA_CENTER)     .td_().td().text(vW49[ 2].GetStrDu(), TA_CENTER).td_().td()    .text(vW49[ 3].GetStrDu(), TA_CENTER)     .td_().td().text(vW49[ 4].GetStrDu(), TA_CENTER).td_().td()    .text(vW49[ 5].GetStrDu(), TA_CENTER)     .td_().td().text(vW49[ 6].GetStrDu(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[ 7].GetStrDu(), TA_CENTER).td_().td().b().text(vW49[ 8].GetStrDu(), TA_CENTER).b_().td_().td().text(vW49[ 9].GetStrDu(), TA_CENTER).td_().td().b().text(vW49[10].GetStrDu(), TA_CENTER).b_().td_().td().text(vW49[11].GetStrDu(), TA_CENTER).td_().td().b().text(vW49[12].GetStrDu(), TA_CENTER).b_().td_().td().text(vW49[13].GetStrDu(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[14].GetStrDu(), TA_CENTER).td_().td()    .text(vW49[15].GetStrDu(), TA_CENTER)     .td_().td().text(vW49[16].GetStrDu(), TA_CENTER).td_().td()    .text(vW49[17].GetStrDu(), TA_CENTER)     .td_().td().text(vW49[18].GetStrDu(), TA_CENTER).td_().td()    .text(vW49[15].GetStrDu(), TA_CENTER)     .td_().td().text(vW49[16].GetStrDu(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[21].GetStrDu(), TA_CENTER).td_().td().b().text(vW49[22].GetStrDu(), TA_CENTER).b_().td_().td().text(vW49[23].GetStrDu(), TA_CENTER).td_().td().b().text(vW49[24].GetStrDu(), TA_CENTER).b_().td_().td().text(vW49[25].GetStrDu(), TA_CENTER).td_().td().b().text(vW49[26].GetStrDu(), TA_CENTER).b_().td_().td().text(vW49[27].GetStrDu(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[28].GetStrDu(), TA_CENTER).td_().td()    .text(vW49[29].GetStrDu(), TA_CENTER)     .td_().td().text(vW49[30].GetStrDu(), TA_CENTER).td_().td()    .text(vW49[31].GetStrDu(), TA_CENTER)     .td_().td().text(vW49[32].GetStrDu(), TA_CENTER).td_().td()    .text(vW49[33].GetStrDu(), TA_CENTER)     .td_().td().text(vW49[34].GetStrDu(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[35].GetStrDu(), TA_CENTER).td_().td().b().text(vW49[36].GetStrDu(), TA_CENTER).b_().td_().td().text(vW49[37].GetStrDu(), TA_CENTER).td_().td().b().text(vW49[38].GetStrDu(), TA_CENTER).b_().td_().td().text(vW49[39].GetStrDu(), TA_CENTER).td_().td().b().text(vW49[40].GetStrDu(), TA_CENTER).b_().td_().td().text(vW49[42].GetStrDu(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[42].GetStrDu(), TA_CENTER).td_().td()    .text(vW49[43].GetStrDu(), TA_CENTER)     .td_().td().text(vW49[44].GetStrDu(), TA_CENTER).td_().td()    .text(vW49[45].GetStrDu(), TA_CENTER)     .td_().td().text(vW49[46].GetStrDu(), TA_CENTER).td_().td()    .text(vW49[47].GetStrDu(), TA_CENTER)     .td_().td().text(vW49[48].GetStrDu(), TA_CENTER).td_().tr_()
        .table_();
    
    return ptTemp;
}

CPoint CColorEyeIView::DrawW49Table_Dv(CDC* pDC, CColorEyeIDoc* pDoc, CPoint ptTemp)
{
    //資料寫出
    //資料鍊一條變多條（各量測項目）
    //無關順序
    std::vector<Cartridge> vW49 = pDoc->GetOmdFile().AddMsrData(White, Pn49);
    //輸出表格W49
    CTable tbW49  (pDC, ptTemp);
    int CellWidth = 64;
    ptTemp = tbW49.SetCellNum(7, 7).SetGridBoard(0).SetTableBoard(1).SetCellSpace(10)
        .Width(0, CellWidth).Width(1, CellWidth).Width(2, CellWidth).Width(3, CellWidth).Width(4, CellWidth).Width(5, CellWidth).Width(6, CellWidth)
        .tr().td().text(vW49[ 0].GetStrDv(), TA_CENTER).td_().td()    .text(vW49[ 1].GetStrDv(), TA_CENTER)     .td_().td().text(vW49[ 2].GetStrDv(), TA_CENTER).td_().td()    .text(vW49[ 3].GetStrDv(), TA_CENTER)     .td_().td().text(vW49[ 4].GetStrDv(), TA_CENTER).td_().td()    .text(vW49[ 5].GetStrDv(), TA_CENTER)     .td_().td().text(vW49[ 6].GetStrDv(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[ 7].GetStrDv(), TA_CENTER).td_().td().b().text(vW49[ 8].GetStrDv(), TA_CENTER).b_().td_().td().text(vW49[ 9].GetStrDv(), TA_CENTER).td_().td().b().text(vW49[10].GetStrDv(), TA_CENTER).b_().td_().td().text(vW49[11].GetStrDv(), TA_CENTER).td_().td().b().text(vW49[12].GetStrDv(), TA_CENTER).b_().td_().td().text(vW49[13].GetStrDv(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[14].GetStrDv(), TA_CENTER).td_().td()    .text(vW49[15].GetStrDv(), TA_CENTER)     .td_().td().text(vW49[16].GetStrDv(), TA_CENTER).td_().td()    .text(vW49[17].GetStrDv(), TA_CENTER)     .td_().td().text(vW49[18].GetStrDv(), TA_CENTER).td_().td()    .text(vW49[15].GetStrDv(), TA_CENTER)     .td_().td().text(vW49[16].GetStrDv(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[21].GetStrDv(), TA_CENTER).td_().td().b().text(vW49[22].GetStrDv(), TA_CENTER).b_().td_().td().text(vW49[23].GetStrDv(), TA_CENTER).td_().td().b().text(vW49[24].GetStrDv(), TA_CENTER).b_().td_().td().text(vW49[25].GetStrDv(), TA_CENTER).td_().td().b().text(vW49[26].GetStrDv(), TA_CENTER).b_().td_().td().text(vW49[27].GetStrDv(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[28].GetStrDv(), TA_CENTER).td_().td()    .text(vW49[29].GetStrDv(), TA_CENTER)     .td_().td().text(vW49[30].GetStrDv(), TA_CENTER).td_().td()    .text(vW49[31].GetStrDv(), TA_CENTER)     .td_().td().text(vW49[32].GetStrDv(), TA_CENTER).td_().td()    .text(vW49[33].GetStrDv(), TA_CENTER)     .td_().td().text(vW49[34].GetStrDv(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[35].GetStrDv(), TA_CENTER).td_().td().b().text(vW49[36].GetStrDv(), TA_CENTER).b_().td_().td().text(vW49[37].GetStrDv(), TA_CENTER).td_().td().b().text(vW49[38].GetStrDv(), TA_CENTER).b_().td_().td().text(vW49[39].GetStrDv(), TA_CENTER).td_().td().b().text(vW49[40].GetStrDv(), TA_CENTER).b_().td_().td().text(vW49[42].GetStrDv(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[42].GetStrDv(), TA_CENTER).td_().td()    .text(vW49[43].GetStrDv(), TA_CENTER)     .td_().td().text(vW49[44].GetStrDv(), TA_CENTER).td_().td()    .text(vW49[45].GetStrDv(), TA_CENTER)     .td_().td().text(vW49[46].GetStrDv(), TA_CENTER).td_().td()    .text(vW49[47].GetStrDv(), TA_CENTER)     .td_().td().text(vW49[48].GetStrDv(), TA_CENTER).td_().tr_()
        .table_();
    
    return ptTemp;
}

CPoint CColorEyeIView::DrawW49Table_T(CDC* pDC, CColorEyeIDoc* pDoc, CPoint ptTemp)
{
    //資料寫出
    //資料鍊一條變多條（各量測項目）
    //無關順序
    std::vector<Cartridge> vW49 = pDoc->GetOmdFile().AddMsrData(White, Pn49);
    //輸出表格W49
    CTable tbW49  (pDC, ptTemp);
    int CellWidth = 64;
    ptTemp = tbW49.SetCellNum(7, 7).SetGridBoard(0).SetTableBoard(1).SetCellSpace(10)
        .Width(0, CellWidth).Width(1, CellWidth).Width(2, CellWidth).Width(3, CellWidth).Width(4, CellWidth).Width(5, CellWidth).Width(6, CellWidth)
        .tr().td().text(vW49[ 0].GetStrT(), TA_CENTER).td_().td()    .text(vW49[ 1].GetStrT(), TA_CENTER)     .td_().td().text(vW49[ 2].GetStrT(), TA_CENTER).td_().td()    .text(vW49[ 3].GetStrT(), TA_CENTER)     .td_().td().text(vW49[ 4].GetStrT(), TA_CENTER).td_().td()    .text(vW49[ 5].GetStrT(), TA_CENTER)     .td_().td().text(vW49[ 6].GetStrT(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[ 7].GetStrT(), TA_CENTER).td_().td().b().text(vW49[ 8].GetStrT(), TA_CENTER).b_().td_().td().text(vW49[ 9].GetStrT(), TA_CENTER).td_().td().b().text(vW49[10].GetStrT(), TA_CENTER).b_().td_().td().text(vW49[11].GetStrT(), TA_CENTER).td_().td().b().text(vW49[12].GetStrT(), TA_CENTER).b_().td_().td().text(vW49[13].GetStrT(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[14].GetStrT(), TA_CENTER).td_().td()    .text(vW49[15].GetStrT(), TA_CENTER)     .td_().td().text(vW49[16].GetStrT(), TA_CENTER).td_().td()    .text(vW49[17].GetStrT(), TA_CENTER)     .td_().td().text(vW49[18].GetStrT(), TA_CENTER).td_().td()    .text(vW49[15].GetStrT(), TA_CENTER)     .td_().td().text(vW49[16].GetStrT(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[21].GetStrT(), TA_CENTER).td_().td().b().text(vW49[22].GetStrT(), TA_CENTER).b_().td_().td().text(vW49[23].GetStrT(), TA_CENTER).td_().td().b().text(vW49[24].GetStrT(), TA_CENTER).b_().td_().td().text(vW49[25].GetStrT(), TA_CENTER).td_().td().b().text(vW49[26].GetStrT(), TA_CENTER).b_().td_().td().text(vW49[27].GetStrT(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[28].GetStrT(), TA_CENTER).td_().td()    .text(vW49[29].GetStrT(), TA_CENTER)     .td_().td().text(vW49[30].GetStrT(), TA_CENTER).td_().td()    .text(vW49[31].GetStrT(), TA_CENTER)     .td_().td().text(vW49[32].GetStrT(), TA_CENTER).td_().td()    .text(vW49[33].GetStrT(), TA_CENTER)     .td_().td().text(vW49[34].GetStrT(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[35].GetStrT(), TA_CENTER).td_().td().b().text(vW49[36].GetStrT(), TA_CENTER).b_().td_().td().text(vW49[37].GetStrT(), TA_CENTER).td_().td().b().text(vW49[38].GetStrT(), TA_CENTER).b_().td_().td().text(vW49[39].GetStrT(), TA_CENTER).td_().td().b().text(vW49[40].GetStrT(), TA_CENTER).b_().td_().td().text(vW49[42].GetStrT(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[42].GetStrT(), TA_CENTER).td_().td()    .text(vW49[43].GetStrT(), TA_CENTER)     .td_().td().text(vW49[44].GetStrT(), TA_CENTER).td_().td()    .text(vW49[45].GetStrT(), TA_CENTER)     .td_().td().text(vW49[46].GetStrT(), TA_CENTER).td_().td()    .text(vW49[47].GetStrT(), TA_CENTER)     .td_().td().text(vW49[48].GetStrT(), TA_CENTER).td_().tr_()
        .table_();
    
    return ptTemp;
}

CPoint CColorEyeIView::DrawW49Table_Duv(CDC* pDC, CColorEyeIDoc* pDoc, CPoint ptTemp)
{
    //資料寫出
    //資料鍊一條變多條（各量測項目）
    //無關順序
    std::vector<Cartridge> vW49 = pDoc->GetOmdFile().AddMsrData(White, Pn49);
    //輸出表格W49
    CTable tbW49  (pDC, ptTemp);
    int CellWidth = 64;
    ptTemp = tbW49.SetCellNum(7, 7).SetGridBoard(0).SetTableBoard(1).SetCellSpace(10)
        .Width(0, CellWidth).Width(1, CellWidth).Width(2, CellWidth).Width(3, CellWidth).Width(4, CellWidth).Width(5, CellWidth).Width(6, CellWidth)
        .tr().td().text(vW49[ 0].GetStrDuv(), TA_CENTER).td_().td()    .text(vW49[ 1].GetStrDuv(), TA_CENTER)     .td_().td().text(vW49[ 2].GetStrDuv(), TA_CENTER).td_().td()    .text(vW49[ 3].GetStrDuv(), TA_CENTER)     .td_().td().text(vW49[ 4].GetStrDuv(), TA_CENTER).td_().td()    .text(vW49[ 5].GetStrDuv(), TA_CENTER)     .td_().td().text(vW49[ 6].GetStrDuv(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[ 7].GetStrDuv(), TA_CENTER).td_().td().b().text(vW49[ 8].GetStrDuv(), TA_CENTER).b_().td_().td().text(vW49[ 9].GetStrDuv(), TA_CENTER).td_().td().b().text(vW49[10].GetStrDuv(), TA_CENTER).b_().td_().td().text(vW49[11].GetStrDuv(), TA_CENTER).td_().td().b().text(vW49[12].GetStrDuv(), TA_CENTER).b_().td_().td().text(vW49[13].GetStrDuv(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[14].GetStrDuv(), TA_CENTER).td_().td()    .text(vW49[15].GetStrDuv(), TA_CENTER)     .td_().td().text(vW49[16].GetStrDuv(), TA_CENTER).td_().td()    .text(vW49[17].GetStrDuv(), TA_CENTER)     .td_().td().text(vW49[18].GetStrDuv(), TA_CENTER).td_().td()    .text(vW49[15].GetStrDuv(), TA_CENTER)     .td_().td().text(vW49[16].GetStrDuv(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[21].GetStrDuv(), TA_CENTER).td_().td().b().text(vW49[22].GetStrDuv(), TA_CENTER).b_().td_().td().text(vW49[23].GetStrDuv(), TA_CENTER).td_().td().b().text(vW49[24].GetStrDuv(), TA_CENTER).b_().td_().td().text(vW49[25].GetStrDuv(), TA_CENTER).td_().td().b().text(vW49[26].GetStrDuv(), TA_CENTER).b_().td_().td().text(vW49[27].GetStrDuv(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[28].GetStrDuv(), TA_CENTER).td_().td()    .text(vW49[29].GetStrDuv(), TA_CENTER)     .td_().td().text(vW49[30].GetStrDuv(), TA_CENTER).td_().td()    .text(vW49[31].GetStrDuv(), TA_CENTER)     .td_().td().text(vW49[32].GetStrDuv(), TA_CENTER).td_().td()    .text(vW49[33].GetStrDuv(), TA_CENTER)     .td_().td().text(vW49[34].GetStrDuv(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[35].GetStrDuv(), TA_CENTER).td_().td().b().text(vW49[36].GetStrDuv(), TA_CENTER).b_().td_().td().text(vW49[37].GetStrDuv(), TA_CENTER).td_().td().b().text(vW49[38].GetStrDuv(), TA_CENTER).b_().td_().td().text(vW49[39].GetStrDuv(), TA_CENTER).td_().td().b().text(vW49[40].GetStrDuv(), TA_CENTER).b_().td_().td().text(vW49[42].GetStrDuv(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[42].GetStrDuv(), TA_CENTER).td_().td()    .text(vW49[43].GetStrDuv(), TA_CENTER)     .td_().td().text(vW49[44].GetStrDuv(), TA_CENTER).td_().td()    .text(vW49[45].GetStrDuv(), TA_CENTER)     .td_().td().text(vW49[46].GetStrDuv(), TA_CENTER).td_().td()    .text(vW49[47].GetStrDuv(), TA_CENTER)     .td_().td().text(vW49[48].GetStrDuv(), TA_CENTER).td_().tr_()
        .table_();
    
    return ptTemp;
}

CPoint CColorEyeIView::DrawW49Table_X(CDC* pDC, CColorEyeIDoc* pDoc, CPoint ptTemp)
{
    //資料寫出
    //資料鍊一條變多條（各量測項目）
    //無關順序
    std::vector<Cartridge> vW49 = pDoc->GetOmdFile().AddMsrData(White, Pn49);
    //輸出表格W49
    CTable tbW49  (pDC, ptTemp);
    int CellWidth = 64;
    ptTemp = tbW49.SetCellNum(7, 7).SetGridBoard(0).SetTableBoard(1).SetCellSpace(10)
        .Width(0, CellWidth).Width(1, CellWidth).Width(2, CellWidth).Width(3, CellWidth).Width(4, CellWidth).Width(5, CellWidth).Width(6, CellWidth)
        .tr().td().text(vW49[ 0].GetStrX(), TA_CENTER).td_().td()    .text(vW49[ 1].GetStrX(), TA_CENTER)     .td_().td().text(vW49[ 2].GetStrX(), TA_CENTER).td_().td()    .text(vW49[ 3].GetStrX(), TA_CENTER)     .td_().td().text(vW49[ 4].GetStrX(), TA_CENTER).td_().td()    .text(vW49[ 5].GetStrX(), TA_CENTER)     .td_().td().text(vW49[ 6].GetStrX(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[ 7].GetStrX(), TA_CENTER).td_().td().b().text(vW49[ 8].GetStrX(), TA_CENTER).b_().td_().td().text(vW49[ 9].GetStrX(), TA_CENTER).td_().td().b().text(vW49[10].GetStrX(), TA_CENTER).b_().td_().td().text(vW49[11].GetStrX(), TA_CENTER).td_().td().b().text(vW49[12].GetStrX(), TA_CENTER).b_().td_().td().text(vW49[13].GetStrX(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[14].GetStrX(), TA_CENTER).td_().td()    .text(vW49[15].GetStrX(), TA_CENTER)     .td_().td().text(vW49[16].GetStrX(), TA_CENTER).td_().td()    .text(vW49[17].GetStrX(), TA_CENTER)     .td_().td().text(vW49[18].GetStrX(), TA_CENTER).td_().td()    .text(vW49[15].GetStrX(), TA_CENTER)     .td_().td().text(vW49[16].GetStrX(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[21].GetStrX(), TA_CENTER).td_().td().b().text(vW49[22].GetStrX(), TA_CENTER).b_().td_().td().text(vW49[23].GetStrX(), TA_CENTER).td_().td().b().text(vW49[24].GetStrX(), TA_CENTER).b_().td_().td().text(vW49[25].GetStrX(), TA_CENTER).td_().td().b().text(vW49[26].GetStrX(), TA_CENTER).b_().td_().td().text(vW49[27].GetStrX(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[28].GetStrX(), TA_CENTER).td_().td()    .text(vW49[29].GetStrX(), TA_CENTER)     .td_().td().text(vW49[30].GetStrX(), TA_CENTER).td_().td()    .text(vW49[31].GetStrX(), TA_CENTER)     .td_().td().text(vW49[32].GetStrX(), TA_CENTER).td_().td()    .text(vW49[33].GetStrX(), TA_CENTER)     .td_().td().text(vW49[34].GetStrX(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[35].GetStrX(), TA_CENTER).td_().td().b().text(vW49[36].GetStrX(), TA_CENTER).b_().td_().td().text(vW49[37].GetStrX(), TA_CENTER).td_().td().b().text(vW49[38].GetStrX(), TA_CENTER).b_().td_().td().text(vW49[39].GetStrX(), TA_CENTER).td_().td().b().text(vW49[40].GetStrX(), TA_CENTER).b_().td_().td().text(vW49[42].GetStrX(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[42].GetStrX(), TA_CENTER).td_().td()    .text(vW49[43].GetStrX(), TA_CENTER)     .td_().td().text(vW49[44].GetStrX(), TA_CENTER).td_().td()    .text(vW49[45].GetStrX(), TA_CENTER)     .td_().td().text(vW49[46].GetStrX(), TA_CENTER).td_().td()    .text(vW49[47].GetStrX(), TA_CENTER)     .td_().td().text(vW49[48].GetStrX(), TA_CENTER).td_().tr_()
        .table_();

    return ptTemp;
}

CPoint CColorEyeIView::DrawW49Table_Y(CDC* pDC, CColorEyeIDoc* pDoc, CPoint ptTemp)
{
    //資料寫出
    //資料鍊一條變多條（各量測項目）
    //無關順序
    std::vector<Cartridge> vW49 = pDoc->GetOmdFile().AddMsrData(White, Pn49);
    //輸出表格W49
    CTable tbW49  (pDC, ptTemp);
    int CellWidth = 64;
    ptTemp = tbW49.SetCellNum(7, 7).SetGridBoard(0).SetTableBoard(1).SetCellSpace(10)
        .Width(0, CellWidth).Width(1, CellWidth).Width(2, CellWidth).Width(3, CellWidth).Width(4, CellWidth).Width(5, CellWidth).Width(6, CellWidth)
        .tr().td().text(vW49[ 0].GetStrY(), TA_CENTER).td_().td()    .text(vW49[ 1].GetStrY(), TA_CENTER)     .td_().td().text(vW49[ 2].GetStrY(), TA_CENTER).td_().td()    .text(vW49[ 3].GetStrY(), TA_CENTER)     .td_().td().text(vW49[ 4].GetStrY(), TA_CENTER).td_().td()    .text(vW49[ 5].GetStrY(), TA_CENTER)     .td_().td().text(vW49[ 6].GetStrY(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[ 7].GetStrY(), TA_CENTER).td_().td().b().text(vW49[ 8].GetStrY(), TA_CENTER).b_().td_().td().text(vW49[ 9].GetStrY(), TA_CENTER).td_().td().b().text(vW49[10].GetStrY(), TA_CENTER).b_().td_().td().text(vW49[11].GetStrY(), TA_CENTER).td_().td().b().text(vW49[12].GetStrY(), TA_CENTER).b_().td_().td().text(vW49[13].GetStrY(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[14].GetStrY(), TA_CENTER).td_().td()    .text(vW49[15].GetStrY(), TA_CENTER)     .td_().td().text(vW49[16].GetStrY(), TA_CENTER).td_().td()    .text(vW49[17].GetStrY(), TA_CENTER)     .td_().td().text(vW49[18].GetStrY(), TA_CENTER).td_().td()    .text(vW49[15].GetStrY(), TA_CENTER)     .td_().td().text(vW49[16].GetStrY(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[21].GetStrY(), TA_CENTER).td_().td().b().text(vW49[22].GetStrY(), TA_CENTER).b_().td_().td().text(vW49[23].GetStrY(), TA_CENTER).td_().td().b().text(vW49[24].GetStrY(), TA_CENTER).b_().td_().td().text(vW49[25].GetStrY(), TA_CENTER).td_().td().b().text(vW49[26].GetStrY(), TA_CENTER).b_().td_().td().text(vW49[27].GetStrY(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[28].GetStrY(), TA_CENTER).td_().td()    .text(vW49[29].GetStrY(), TA_CENTER)     .td_().td().text(vW49[30].GetStrY(), TA_CENTER).td_().td()    .text(vW49[31].GetStrY(), TA_CENTER)     .td_().td().text(vW49[32].GetStrY(), TA_CENTER).td_().td()    .text(vW49[33].GetStrY(), TA_CENTER)     .td_().td().text(vW49[34].GetStrY(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[35].GetStrY(), TA_CENTER).td_().td().b().text(vW49[36].GetStrY(), TA_CENTER).b_().td_().td().text(vW49[37].GetStrY(), TA_CENTER).td_().td().b().text(vW49[38].GetStrY(), TA_CENTER).b_().td_().td().text(vW49[39].GetStrY(), TA_CENTER).td_().td().b().text(vW49[40].GetStrY(), TA_CENTER).b_().td_().td().text(vW49[42].GetStrY(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[42].GetStrY(), TA_CENTER).td_().td()    .text(vW49[43].GetStrY(), TA_CENTER)     .td_().td().text(vW49[44].GetStrY(), TA_CENTER).td_().td()    .text(vW49[45].GetStrY(), TA_CENTER)     .td_().td().text(vW49[46].GetStrY(), TA_CENTER).td_().td()    .text(vW49[47].GetStrY(), TA_CENTER)     .td_().td().text(vW49[48].GetStrY(), TA_CENTER).td_().tr_()
        .table_();

    return ptTemp;
}

CPoint CColorEyeIView::DrawW49Table_Z(CDC* pDC, CColorEyeIDoc* pDoc, CPoint ptTemp)
{
    //資料寫出
    //資料鍊一條變多條（各量測項目）
    //無關順序
    std::vector<Cartridge> vW49 = pDoc->GetOmdFile().AddMsrData(White, Pn49);
    //輸出表格W49
    CTable tbW49  (pDC, ptTemp);
    int CellWidth = 64;
    ptTemp = tbW49.SetCellNum(7, 7).SetGridBoard(0).SetTableBoard(1).SetCellSpace(10)
        .Width(0, CellWidth).Width(1, CellWidth).Width(2, CellWidth).Width(3, CellWidth).Width(4, CellWidth).Width(5, CellWidth).Width(6, CellWidth)
        .tr().td().text(vW49[ 0].GetStrZ(), TA_CENTER).td_().td()    .text(vW49[ 1].GetStrZ(), TA_CENTER)     .td_().td().text(vW49[ 2].GetStrZ(), TA_CENTER).td_().td()    .text(vW49[ 3].GetStrZ(), TA_CENTER)     .td_().td().text(vW49[ 4].GetStrZ(), TA_CENTER).td_().td()    .text(vW49[ 5].GetStrZ(), TA_CENTER)     .td_().td().text(vW49[ 6].GetStrZ(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[ 7].GetStrZ(), TA_CENTER).td_().td().b().text(vW49[ 8].GetStrZ(), TA_CENTER).b_().td_().td().text(vW49[ 9].GetStrZ(), TA_CENTER).td_().td().b().text(vW49[10].GetStrZ(), TA_CENTER).b_().td_().td().text(vW49[11].GetStrZ(), TA_CENTER).td_().td().b().text(vW49[12].GetStrZ(), TA_CENTER).b_().td_().td().text(vW49[13].GetStrZ(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[14].GetStrZ(), TA_CENTER).td_().td()    .text(vW49[15].GetStrZ(), TA_CENTER)     .td_().td().text(vW49[16].GetStrZ(), TA_CENTER).td_().td()    .text(vW49[17].GetStrZ(), TA_CENTER)     .td_().td().text(vW49[18].GetStrZ(), TA_CENTER).td_().td()    .text(vW49[15].GetStrZ(), TA_CENTER)     .td_().td().text(vW49[16].GetStrZ(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[21].GetStrZ(), TA_CENTER).td_().td().b().text(vW49[22].GetStrZ(), TA_CENTER).b_().td_().td().text(vW49[23].GetStrZ(), TA_CENTER).td_().td().b().text(vW49[24].GetStrZ(), TA_CENTER).b_().td_().td().text(vW49[25].GetStrZ(), TA_CENTER).td_().td().b().text(vW49[26].GetStrZ(), TA_CENTER).b_().td_().td().text(vW49[27].GetStrZ(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[28].GetStrZ(), TA_CENTER).td_().td()    .text(vW49[29].GetStrZ(), TA_CENTER)     .td_().td().text(vW49[30].GetStrZ(), TA_CENTER).td_().td()    .text(vW49[31].GetStrZ(), TA_CENTER)     .td_().td().text(vW49[32].GetStrZ(), TA_CENTER).td_().td()    .text(vW49[33].GetStrZ(), TA_CENTER)     .td_().td().text(vW49[34].GetStrZ(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[35].GetStrZ(), TA_CENTER).td_().td().b().text(vW49[36].GetStrZ(), TA_CENTER).b_().td_().td().text(vW49[37].GetStrZ(), TA_CENTER).td_().td().b().text(vW49[38].GetStrZ(), TA_CENTER).b_().td_().td().text(vW49[39].GetStrZ(), TA_CENTER).td_().td().b().text(vW49[40].GetStrZ(), TA_CENTER).b_().td_().td().text(vW49[42].GetStrZ(), TA_CENTER).td_().tr_()
        .tr().td().text(vW49[42].GetStrZ(), TA_CENTER).td_().td()    .text(vW49[43].GetStrZ(), TA_CENTER)     .td_().td().text(vW49[44].GetStrZ(), TA_CENTER).td_().td()    .text(vW49[45].GetStrZ(), TA_CENTER)     .td_().td().text(vW49[46].GetStrZ(), TA_CENTER).td_().td()    .text(vW49[47].GetStrZ(), TA_CENTER)     .td_().td().text(vW49[48].GetStrZ(), TA_CENTER).td_().tr_()
        .table_();
    
    return ptTemp;
}

CPoint CColorEyeIView::DrawWRGBDTable_Lv(CDC* pDC, CColorEyeIDoc* pDoc, CPoint ptTemp)
{
    //資料寫出
    //資料鍊一條變多條（各量測項目）
    //無關順序
    std::vector<Cartridge> vWRGBD;//這個WRGBD要依順序
    pDoc->GetOmdFile().AddMsrData(White, Pn1, vWRGBD);
    pDoc->GetOmdFile().AddMsrData(Red  , Pn1, vWRGBD);
    pDoc->GetOmdFile().AddMsrData(Green, Pn1, vWRGBD);
    pDoc->GetOmdFile().AddMsrData(Blue , Pn1, vWRGBD);
    pDoc->GetOmdFile().AddMsrData(Dark , Pn1, vWRGBD);    
    CTable tbWRGBD(pDC, ptTemp);

    return ptTemp;    
}

CPoint CColorEyeIView::DrawNitsTable_Lv(CDC* pDC, CColorEyeIDoc* pDoc, CPoint ptTemp)
{
    //資料寫出
    //資料鍊一條變多條（各量測項目）
    //無關順序
    std::vector<Cartridge> vNits = pDoc->GetOmdFile().AddMsrData(Nits , Pn9);
    CTable tbNits(pDC, ptTemp);
    
    int CellWidth = 176;
    ptTemp = tbNits.SetCellNum(3, 7).SetGridBoard(0).SetTableBoard(1).SetCellSpace(10)
        .Width(0, CellWidth).Width(1, CellWidth).Width(2, CellWidth)//.Width(3, CellWidth).Width(4, CellWidth).Width(5, CellWidth).Width(6, CellWidth)
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vNits[0].GetStrLv(), TA_CENTER).td_().td().text(vNits[1].GetStrLv(), TA_CENTER).td_().td().text(vNits[2].GetStrLv(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vNits[3].GetStrLv(), TA_CENTER).td_().td().text(vNits[4].GetStrLv(), TA_CENTER).td_().td().text(vNits[5].GetStrLv(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vNits[6].GetStrLv(), TA_CENTER).td_().td().text(vNits[7].GetStrLv(), TA_CENTER).td_().td().text(vNits[8].GetStrLv(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .table_();
    
    
    return ptTemp;
}

CPoint CColorEyeIView::DrawNitsTable_Sx(CDC* pDC, CColorEyeIDoc* pDoc, CPoint ptTemp)
{
    //資料寫出
    //資料鍊一條變多條（各量測項目）
    //無關順序
    std::vector<Cartridge> vNits = pDoc->GetOmdFile().AddMsrData(Nits , Pn9);
    CTable tbNits(pDC, ptTemp);
    
    int CellWidth = 176;
    ptTemp = tbNits.SetCellNum(3, 7).SetGridBoard(0).SetTableBoard(1).SetCellSpace(10)
        .Width(0, CellWidth).Width(1, CellWidth).Width(2, CellWidth)//.Width(3, CellWidth).Width(4, CellWidth).Width(5, CellWidth).Width(6, CellWidth)
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vNits[0].GetStrSx(), TA_CENTER).td_().td().text(vNits[1].GetStrSx(), TA_CENTER).td_().td().text(vNits[2].GetStrSx(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vNits[3].GetStrSx(), TA_CENTER).td_().td().text(vNits[4].GetStrSx(), TA_CENTER).td_().td().text(vNits[5].GetStrSx(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vNits[6].GetStrSx(), TA_CENTER).td_().td().text(vNits[7].GetStrSx(), TA_CENTER).td_().td().text(vNits[8].GetStrSx(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .table_();
    
    return ptTemp;
}

CPoint CColorEyeIView::DrawNitsTable_Sy(CDC* pDC, CColorEyeIDoc* pDoc, CPoint ptTemp)
{
    //資料寫出
    //資料鍊一條變多條（各量測項目）
    //無關順序
    std::vector<Cartridge> vNits = pDoc->GetOmdFile().AddMsrData(Nits , Pn9);
    CTable tbNits(pDC, ptTemp);
    
    int CellWidth = 176;
    ptTemp = tbNits.SetCellNum(3, 7).SetGridBoard(0).SetTableBoard(1).SetCellSpace(10)
        .Width(0, CellWidth).Width(1, CellWidth).Width(2, CellWidth)//.Width(3, CellWidth).Width(4, CellWidth).Width(5, CellWidth).Width(6, CellWidth)
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vNits[0].GetStrSy(), TA_CENTER).td_().td().text(vNits[1].GetStrSy(), TA_CENTER).td_().td().text(vNits[2].GetStrSy(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vNits[3].GetStrSy(), TA_CENTER).td_().td().text(vNits[4].GetStrSy(), TA_CENTER).td_().td().text(vNits[5].GetStrSy(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vNits[6].GetStrSy(), TA_CENTER).td_().td().text(vNits[7].GetStrSy(), TA_CENTER).td_().td().text(vNits[8].GetStrSy(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .table_();
    
    return ptTemp;
}

CPoint CColorEyeIView::DrawNitsTable_Du(CDC* pDC, CColorEyeIDoc* pDoc, CPoint ptTemp)
{
    //資料寫出
    //資料鍊一條變多條（各量測項目）
    //無關順序
    std::vector<Cartridge> vNits = pDoc->GetOmdFile().AddMsrData(Nits , Pn9);
    CTable tbNits(pDC, ptTemp);
    
    int CellWidth = 176;
    ptTemp = tbNits.SetCellNum(3, 7).SetGridBoard(0).SetTableBoard(1).SetCellSpace(10)
        .Width(0, CellWidth).Width(1, CellWidth).Width(2, CellWidth)//.Width(3, CellWidth).Width(4, CellWidth).Width(5, CellWidth).Width(6, CellWidth)
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vNits[0].GetStrDu(), TA_CENTER).td_().td().text(vNits[1].GetStrDu(), TA_CENTER).td_().td().text(vNits[2].GetStrDu(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vNits[3].GetStrDu(), TA_CENTER).td_().td().text(vNits[4].GetStrDu(), TA_CENTER).td_().td().text(vNits[5].GetStrDu(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vNits[6].GetStrDu(), TA_CENTER).td_().td().text(vNits[7].GetStrDu(), TA_CENTER).td_().td().text(vNits[8].GetStrDu(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .table_();
        
    return ptTemp;
}

CPoint CColorEyeIView::DrawNitsTable_Dv(CDC* pDC, CColorEyeIDoc* pDoc, CPoint ptTemp)
{
    //資料寫出
    //資料鍊一條變多條（各量測項目）
    //無關順序
    std::vector<Cartridge> vNits = pDoc->GetOmdFile().AddMsrData(Nits , Pn9);
    CTable tbNits(pDC, ptTemp);
    
    int CellWidth = 176;
    ptTemp = tbNits.SetCellNum(3, 7).SetGridBoard(0).SetTableBoard(1).SetCellSpace(10)
        .Width(0, CellWidth).Width(1, CellWidth).Width(2, CellWidth)//.Width(3, CellWidth).Width(4, CellWidth).Width(5, CellWidth).Width(6, CellWidth)
        .tr().td()                                     .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vNits[0].GetStrDv(), TA_CENTER).td_().td().text(vNits[1].GetStrDv(), TA_CENTER).td_().td().text(vNits[2].GetStrDv(), TA_CENTER).td_().td().tr_()
        .tr().td()                                     .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vNits[3].GetStrDv(), TA_CENTER).td_().td().text(vNits[4].GetStrDv(), TA_CENTER).td_().td().text(vNits[5].GetStrDv(), TA_CENTER).td_().td().tr_()
        .tr().td()                                     .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vNits[6].GetStrDv(), TA_CENTER).td_().td().text(vNits[7].GetStrDv(), TA_CENTER).td_().td().text(vNits[8].GetStrDv(), TA_CENTER).td_().td().tr_()
        .tr().td()                                     .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .table_();
        
    return ptTemp;
}

CPoint CColorEyeIView::DrawNitsTable_T(CDC* pDC, CColorEyeIDoc* pDoc, CPoint ptTemp)
{
    //資料寫出
    //資料鍊一條變多條（各量測項目）
    //無關順序
    std::vector<Cartridge> vNits = pDoc->GetOmdFile().AddMsrData(Nits , Pn9);
    CTable tbNits(pDC, ptTemp);
    
    int CellWidth = 176;
    ptTemp = tbNits.SetCellNum(3, 7).SetGridBoard(0).SetTableBoard(1).SetCellSpace(10)
        .Width(0, CellWidth).Width(1, CellWidth).Width(2, CellWidth)//.Width(3, CellWidth).Width(4, CellWidth).Width(5, CellWidth).Width(6, CellWidth)
        .tr().td()                                    .td_().td()                                    .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vNits[0].GetStrT(), TA_CENTER).td_().td().text(vNits[1].GetStrT(), TA_CENTER).td_().td().text(vNits[2].GetStrT(), TA_CENTER).td_().td().tr_()
        .tr().td()                                    .td_().td()                                    .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vNits[3].GetStrT(), TA_CENTER).td_().td().text(vNits[4].GetStrT(), TA_CENTER).td_().td().text(vNits[5].GetStrT(), TA_CENTER).td_().td().tr_()
        .tr().td()                                    .td_().td()                                    .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vNits[6].GetStrT(), TA_CENTER).td_().td().text(vNits[7].GetStrT(), TA_CENTER).td_().td().text(vNits[8].GetStrT(), TA_CENTER).td_().td().tr_()
        .tr().td()                                    .td_().td()                                    .td_().td()                                   .td_().td().tr_()
        .table_();
        
    return ptTemp;
}

CPoint CColorEyeIView::DrawNitsTable_Duv(CDC* pDC, CColorEyeIDoc* pDoc, CPoint ptTemp)
{
    //資料寫出
    //資料鍊一條變多條（各量測項目）
    //無關順序
    std::vector<Cartridge> vNits = pDoc->GetOmdFile().AddMsrData(Nits , Pn9);
    CTable tbNits(pDC, ptTemp);
    
    int CellWidth = 176;
    ptTemp = tbNits.SetCellNum(3, 7).SetGridBoard(0).SetTableBoard(1).SetCellSpace(10)
        .Width(0, CellWidth).Width(1, CellWidth).Width(2, CellWidth)//.Width(3, CellWidth).Width(4, CellWidth).Width(5, CellWidth).Width(6, CellWidth)
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vNits[0].GetStrDuv(), TA_CENTER).td_().td().text(vNits[1].GetStrDuv(), TA_CENTER).td_().td().text(vNits[2].GetStrDuv(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vNits[3].GetStrDuv(), TA_CENTER).td_().td().text(vNits[4].GetStrDuv(), TA_CENTER).td_().td().text(vNits[5].GetStrDuv(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vNits[6].GetStrDuv(), TA_CENTER).td_().td().text(vNits[7].GetStrDuv(), TA_CENTER).td_().td().text(vNits[8].GetStrDuv(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .table_();
        
    return ptTemp;
}

CPoint CColorEyeIView::DrawNitsTable_X(CDC* pDC, CColorEyeIDoc* pDoc, CPoint ptTemp)
{
    //資料寫出
    //資料鍊一條變多條（各量測項目）
    //無關順序
    std::vector<Cartridge> vNits = pDoc->GetOmdFile().AddMsrData(Nits , Pn9);
    CTable tbNits(pDC, ptTemp);
    
    int CellWidth = 176;
    ptTemp = tbNits.SetCellNum(3, 7).SetGridBoard(0).SetTableBoard(1).SetCellSpace(10)
        .Width(0, CellWidth).Width(1, CellWidth).Width(2, CellWidth)//.Width(3, CellWidth).Width(4, CellWidth).Width(5, CellWidth).Width(6, CellWidth)
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vNits[0].GetStrX(), TA_CENTER).td_().td().text(vNits[1].GetStrX(), TA_CENTER).td_().td().text(vNits[2].GetStrX(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vNits[3].GetStrX(), TA_CENTER).td_().td().text(vNits[4].GetStrX(), TA_CENTER).td_().td().text(vNits[5].GetStrX(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vNits[6].GetStrX(), TA_CENTER).td_().td().text(vNits[7].GetStrX(), TA_CENTER).td_().td().text(vNits[8].GetStrX(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .table_();   
    
    return ptTemp;
}

CPoint CColorEyeIView::DrawNitsTable_Y(CDC* pDC, CColorEyeIDoc* pDoc, CPoint ptTemp)
{
    //資料寫出
    //資料鍊一條變多條（各量測項目）
    //無關順序
    std::vector<Cartridge> vNits = pDoc->GetOmdFile().AddMsrData(Nits , Pn9);
    CTable tbNits(pDC, ptTemp);
    
    int CellWidth = 176;
    ptTemp = tbNits.SetCellNum(3, 7).SetGridBoard(0).SetTableBoard(1).SetCellSpace(10)
        .Width(0, CellWidth).Width(1, CellWidth).Width(2, CellWidth)//.Width(3, CellWidth).Width(4, CellWidth).Width(5, CellWidth).Width(6, CellWidth)
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vNits[0].GetStrY(), TA_CENTER).td_().td().text(vNits[1].GetStrY(), TA_CENTER).td_().td().text(vNits[2].GetStrY(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vNits[3].GetStrY(), TA_CENTER).td_().td().text(vNits[4].GetStrY(), TA_CENTER).td_().td().text(vNits[5].GetStrY(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vNits[6].GetStrY(), TA_CENTER).td_().td().text(vNits[7].GetStrY(), TA_CENTER).td_().td().text(vNits[8].GetStrY(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .table_();   
    
    return ptTemp;
}

CPoint CColorEyeIView::DrawNitsTable_Z(CDC* pDC, CColorEyeIDoc* pDoc, CPoint ptTemp)
{
    //資料寫出
    //資料鍊一條變多條（各量測項目）
    //無關順序
    std::vector<Cartridge> vNits = pDoc->GetOmdFile().AddMsrData(Nits , Pn9);
    CTable tbNits(pDC, ptTemp);
    
    int CellWidth = 176;
    ptTemp = tbNits.SetCellNum(3, 7).SetGridBoard(0).SetTableBoard(1).SetCellSpace(10)
        .Width(0, CellWidth).Width(1, CellWidth).Width(2, CellWidth)//.Width(3, CellWidth).Width(4, CellWidth).Width(5, CellWidth).Width(6, CellWidth)
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vNits[0].GetStrZ(), TA_CENTER).td_().td().text(vNits[1].GetStrZ(), TA_CENTER).td_().td().text(vNits[2].GetStrZ(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vNits[3].GetStrZ(), TA_CENTER).td_().td().text(vNits[4].GetStrZ(), TA_CENTER).td_().td().text(vNits[5].GetStrZ(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .tr().td().text(vNits[6].GetStrZ(), TA_CENTER).td_().td().text(vNits[7].GetStrZ(), TA_CENTER).td_().td().text(vNits[8].GetStrZ(), TA_CENTER).td_().td().tr_()
        .tr().td()                                   .td_().td()                                   .td_().td()                                   .td_().td().tr_()
        .table_();
        
    return ptTemp;
}
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////



// CPoint CColorEyeIView::DrawW49Table(CDC* pDC, CPoint& ptTemp, std::vector<Cartridge> W49)
// {    
//     return ptTemp;
// }

void CColorEyeIView::OnInitialUpdate()
{
    CScrollView::OnInitialUpdate();
    CSize sizeTotal;
    // TODO: calculate the total size of this view
    sizeTotal.cx = GetDeviceScrollPosition().x;
    sizeTotal.cy = GetDeviceScrollPosition().y;
    SetScrollSizes(MM_TEXT, sizeTotal);
}


/////////////////////////////////////////////////////////////////////////////
// CColorEyeIView diagnostics

#ifdef _DEBUG
void CColorEyeIView::AssertValid() const
{
    CScrollView::AssertValid();
}

void CColorEyeIView::Dump(CDumpContext& dc) const
{
    CScrollView::Dump(dc);
}

CColorEyeIDoc* CColorEyeIView::GetDocument() // non-debug version is inline
{
    ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CColorEyeIDoc)));
    return (CColorEyeIDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CColorEyeIView message handlers

void CColorEyeIView::KeepSc()
{
    CRect* pRcClient = new CRect;
//    GetClientRect(&rcClient);
    pRcClient->top    = 2;
    pRcClient->left   = 2;
    pRcClient->right  = 340;
    pRcClient->bottom = 285;
    InvalidateRect(pRcClient);
    delete pRcClient;
}

void CColorEyeIView::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
    // TODO: Add your message handler code here and/or call default
    KeepSc();
    CScrollView::OnVScroll(nSBCode, nPos, pScrollBar);
}

BOOL CColorEyeIView::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) 
{
    // TODO: Add your message handler code here and/or call default
    KeepSc();
    return CScrollView::OnMouseWheel(nFlags, zDelta, pt);
}

void CColorEyeIView::ViewTableBkColor(isMsrItem Item)
{
    strTemp.Format("Lv = (%d, %d, %d)\nSx = (%d, %d, %d)\nSy = (%d, %d, %d)\ndu = (%d, %d, %d)\ndv = (%d, %d, %d)\nT  = (%d, %d, %d)\nduv = (%d, %d, %d)\nX  = (%d, %d, %d)\nY  = (%d, %d, %d)\nZ  = (%d, %d, %d)",\
        GetRValue(m_isMsr[Item][Lv]), GetGValue(m_isMsr[Item][Lv]), GetBValue(m_isMsr[Item][Lv]), \
        GetRValue(m_isMsr[Item][Sx]), GetGValue(m_isMsr[Item][Sx]), GetBValue(m_isMsr[Item][Sx]), \
        GetRValue(m_isMsr[Item][Sy]), GetGValue(m_isMsr[Item][Sy]), GetBValue(m_isMsr[Item][Sy]), \
        GetRValue(m_isMsr[Item][du]), GetGValue(m_isMsr[Item][du]), GetBValue(m_isMsr[Item][du]), \
        GetRValue(m_isMsr[Item][dv]), GetGValue(m_isMsr[Item][dv]), GetBValue(m_isMsr[Item][dv]), \
        GetRValue(m_isMsr[Item][T]), GetGValue(m_isMsr[Item][T]), GetBValue(m_isMsr[Item][T]), \
        GetRValue(m_isMsr[Item][duv]), GetGValue(m_isMsr[Item][duv]), GetBValue(m_isMsr[Item][duv]), \
        GetRValue(m_isMsr[Item][X]), GetGValue(m_isMsr[Item][X]), GetBValue(m_isMsr[Item][X]), \
        GetRValue(m_isMsr[Item][Y]), GetGValue(m_isMsr[Item][Y]), GetBValue(m_isMsr[Item][Y]), \
        GetRValue(m_isMsr[Item][Z]), GetGValue(m_isMsr[Item][Z]), GetBValue(m_isMsr[Item][Z]));
    MessageBox(strTemp);
};

void CColorEyeIView::OnMouseMove(UINT nFlags, CPoint point) 
{
    // TODO: Add your message handler code here and/or call default

    m_MousePoint = point;


    CScrollView::OnMouseMove(nFlags, point);
}

void CColorEyeIView::DebugView(CDC* p_DC)
{
    CRect* pRect = new CRect;
    GetClientRect(pRect);
    CPoint pt(pRect->right, pRect->top);
    UINT hText = 16;
    UINT nlines = 1;

    while(nlines > 0)
    {
        switch(nlines)
        {
            case 0:        strTemp.Format("%d, %d", m_MousePoint.x, m_MousePoint.y); break;
            default: 
                ;
        }
        p_DC->SetTextAlign(TA_RIGHT);
        p_DC->TextOut(pt.x, pt.y + hText*nlines, strTemp.GetBuffer(0), strTemp.GetLength());

        nlines--;
    }
}

void CColorEyeIView::OnLButtonUp(UINT nFlags, CPoint point) 
{
    // TODO: Add your message handler code here and/or call default
    /*
    若有值（表格白色）
    若有顯示→取出它的順序值，將它在鍊中去掉
    

    //準備滑鼠命中的座標
    CPoint ptLeftTop = m_NvgtHit[13];          //表格左上角參考點
    CPoint ptHit     = point - m_NvgtHit[13];  //命中的座標（相對於參考點）;

    const UINT xCnt_Max = 10; //有十個值
    UINT yCnt_Max = 0;        //不知道有幾個量測項目
    //計數量測項目
    for (std::vector<CPoint>::iterator it = m_NvgtHit.begin(); it != m_NvgtHit.end(); ++it)
        yCnt_Max++;
    yCnt_Max /= (xCnt_Max + 1);
    yCnt_Max--;

    //準備被命中的座標
    CPoint ptRightButtom;
    UINT hHitTable;
    UINT vHitTable;
    if (m_NvgtHit.empty())//是空白時
    {
        hHitTable = 99;
        vHitTable = 99;
        AfxMessageBox("m_NvgtHit is empty()");
    }
    else
    {
        ptRightButtom = *m_NvgtHit.rbegin();
        hHitTable = ptRightButtom.x - ptLeftTop.x;
        vHitTable = ptRightButtom.y - ptLeftTop.y;

        //一個儲存格的尺寸
        const UINT hCell = hHitTable/xCnt_Max;  //高度
        const UINT vCell = vHitTable/yCnt_Max;  //寬度


        //命中的座標轉表格
        BOOL bView = m_isMsr[ptHit.y/vCell][ptHit.x/hCell];
        BOOL addOne = TRUE;//增加

        strTemp.Format("範圍:\nTop %d\nButton %d\nLeft %d\n Right %d\nptHit.y/vCell = %d / %d\n ptHit.x / hCell = %d / %d\nHit = %d, %d"\
            ,m_NvgtHit[13].y, m_NvgtHit.rbegin()->y, m_NvgtHit[13].x, m_NvgtHit.rbegin()->x, ptHit.y, vCell, ptHit.x, hCell, ptHit.y/vCell, ptHit.x/hCell);
        AfxMessageBox(strTemp);

        //若在可點選的範圍裡
        if ((point.x > m_NvgtHit[13].x && point.x < m_NvgtHit.rbegin()->x) && \
            (point.y > m_NvgtHit[13].y && point.y < m_NvgtHit.rbegin()->y) && \
            (bView))//如果有值
        {

            ViewTable vt;
            vt.SetMsrItem(UIntToMrItm(ptHit.y/vCell));
            vt.SetMsrValue(UIntToMrVle(ptHit.x/hCell));

            //否則就找找看鍊中有沒有這個東西
            for (std::vector<ViewTable>::iterator it = m_vViewTable.begin(); it != m_vViewTable.end(); ++it)
            {
               if ((vt.GetMsrItem()  == it->GetMsrItem()) && \
                   (vt.GetMsrValue() == it->GetMsrValue()))
               {
                   m_vViewTable.erase(it);
                   addOne = FALSE;
               }
            }
            if (addOne) 
                m_vViewTable.push_back(vt);

            //更新頁面
            CColorEyeIDoc* pDoc = GetDocument();
            ASSERT_VALID(pDoc);
            pDoc->UpdateAllViews(NULL);
        }//如果在範圍裡
    }
*/
    CScrollView::OnLButtonUp(nFlags, point);
}

// enum isMsrItem    {WRGBD = 0, Nts, W49, W9, D25, W5};
isMsrItem  CColorEyeIView::UIntToMrItm(UINT i)
{
    switch(i)
    {
        default:
        case 0: return WRGBD;
        case 1: return Nts;
        case 2: return W49;
        case 3: return W9;
        case 4: return D25;
        case 5: return W5;
    }
}

// enum isMsrValue    {Lv = 0, Sx, Sy, du, dv, T, duv, X, Y, Z};
isMsrValue CColorEyeIView::UIntToMrVle(UINT i)
{
    switch(i)
    {
        default:
        case  0: return Lv;
        case  1: return Sx;
        case  2: return Sy;
        case  3: return du;
        case  4: return dv;
        case  5: return T;
        case  6: return duv;
        case  7: return X;
        case  8: return Y;
        case  9: return Z;
    }
}


