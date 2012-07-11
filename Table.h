<<<<<<< HEAD
// Table.h: interface for the CTable class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TABLE_H__A9B82117_1597_4B66_8A15_2D3924158934__INCLUDED_)
#define AFX_TABLE_H__A9B82117_1597_4B66_8A15_2D3924158934__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <vector>
#include "ColorEyeI.h"

class CTable  
{
    //字型
    CFont m_defFont;
    CFont m_curFont;
    CFont* p_OldFont;
    LOGFONT m_lft;

    //文字顏色
    COLORREF m_oldclr;
    COLORREF m_clrText;
    COLORREF m_clrBackGround;

    //畫格線
    UINT m_fBoard;
    UINT m_gBoard;
    CPen m_GridPen;
    CPen m_FramPen;
    CPen* p_OldPen;
    COLORREF m_fbColor;
    COLORREF m_gbColor;

    //背景色
    CBrush m_BkArea;
    CBrush* p_OldBrush;

	//定位點
    CPoint m_ptOrig;
    CPoint m_ptCur;
    CPoint m_ptNextXY;
    CPoint m_ptEnd;

    CDC* p_DC;

    std::vector<UINT> m_SpanTable;  //建一個table，以0開始定址，記錄跳格子的表
    std::vector<CPoint> m_PointTable;

    std::vector<UINT>::size_type m_xCnt;
    std::vector<UINT>::size_type m_yCnt;
    std::vector<UINT>::size_type m_xCnt_Max;
    std::vector<UINT>::size_type m_yCnt_Max;

    CSize m_CellSpace; //內容與格線間距
public:
    CTable(CDC*, CPoint&);
    virtual ~CTable();

//protected:
    CTable& SetFont(CFont&);
	CTable& SetBackColor(COLORREF BkClr = RGB(255, 255, 255));
    //粗體
    CTable& b();
    CTable& b_();
    //斜體
    CTable& i();
    CTable& i_();
    //底線
    CTable& u();
    CTable& u_();
    //刪除線
    CTable& s();
    CTable& s_();

    CTable& tr();//, CFont& ft
    CTable& tr_();

    CTable& td(UINT Hspan = 1, UINT Vspan = 1);
    CTable& td(CFont ft, UINT Hspan = 1, UINT Vspan = 1);
    CTable& td(COLORREF bkclr, UINT Hspan, UINT Vspan);//是否要設定成灰色格子
    CTable& td(COLORREF bkclr);//是否要設定成灰色格子
    CTable& td_();


    CTable& text(CString, UINT nFlags = TA_LEFT);
    CTable& text(CString, CFont&, UINT nFlags = TA_LEFT);
    CTable& text(CString, CFont&, COLORREF, UINT nFlags = TA_LEFT);

    CTable& Width(std::vector<UINT>::size_type n, UINT w); //SetWidth(第幾個Cell, 多寬）
    CTable& Hight(std::vector<UINT>::size_type n, UINT h); //SetHight(第幾個Cell, 多高）
    CPoint  GetCellNum();
    CTable& SetCellNum(UINT, UINT);
    CTable& SetTableBoard(UINT tableboard, COLORREF tbclr = RGB(0,0,0));
    CTable& SetGridBoard (UINT gridboard , COLORREF gbclr = RGB(0,0,0));
    CTable& SetCellSpace(UINT sp = 2);

    CPoint  table_();
    CPoint  table_(std::vector<CPoint>& tbPt);

private:
    void DrawRect(COLORREF bkclr);

    UINT nextX(UINT);
    UINT nextY(UINT);

    void DrawGridBoard();
    void DrawFrameBoard();

    //debug
    void ViewSpanTableValue(const CString title = "");
    void ViewTableTableValue(const CString title = "");
};

    /*
    Spen Table Readme

       0        1       2         3       4個
    +--------+--------+--------+--------+
o    |        | h邊長1 | h邊長2 | h邊長3 |
    +--------+========+========+========+
1    | v邊長1 | 跳格子 |        |        |
    +--------+========+========+========+
2    | v邊長2 | 跳格子 |        |        |
    +--------+========+========+========+
3    | v邊長3 |        | 跳格子 |        |
    +--------+========+========+========+
4個
  
    m_vCellWidth.at(m_xCnt) = Wk(k=0~n)
    

      記錄左上角的定位點

               0       1         2       3個
             +========+========+========+
         0     |pt(0,0) |pt(0,0) |pt(0,0) |
             +========+========+========+
         1     |pt(0,0) |pt(0,0) |pt(0,0) |
             +========+========+========+
         2   |pt(0,0) |pt(0,0) |pt(0,0) |
             +========+========+========+
         3個
         
    m_PointTable.at(m_xCnt) = Wk(k=0~n)
    */
#endif // !defined(AFX_TABLE_H__A9B82117_1597_4B66_8A15_2D3924158934__INCLUDED_)
=======
// Table.h: interface for the CTable class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TABLE_H__A9B82117_1597_4B66_8A15_2D3924158934__INCLUDED_)
#define AFX_TABLE_H__A9B82117_1597_4B66_8A15_2D3924158934__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <vector>
#include "ColorEyeI.h"

class CTable  
{
    //字型
    CFont m_defFont;
    CFont m_curFont;
    CFont* p_OldFont;
    LOGFONT m_lft;

    //文字顏色
    COLORREF m_oldclr;
    COLORREF m_clrText;
    COLORREF m_clrBackGround;

    //畫格線
    UINT m_fBoard;
    UINT m_gBoard;
    CPen m_GridPen;
    CPen m_FramPen;
    CPen* p_OldPen;
    COLORREF m_fbColor;
    COLORREF m_gbColor;

    //背景色
    CBrush m_BkArea;
    CBrush* p_OldBrush;

	//定位點
    CPoint m_ptOrig;
    CPoint m_ptCur;
    CPoint m_ptNextXY;
    CPoint m_ptEnd;

    CDC* p_DC;

    std::vector<UINT> m_SpanTable;  //建一個table，以0開始定址，記錄跳格子的表
    std::vector<CPoint> m_PointTable;

    std::vector<UINT>::size_type m_xCnt;
    std::vector<UINT>::size_type m_yCnt;
    std::vector<UINT>::size_type m_xCnt_Max;
    std::vector<UINT>::size_type m_yCnt_Max;

    CSize m_CellSpace; //內容與格線間距
public:
    CTable(CDC*, CPoint&);
    virtual ~CTable();

//protected:
    CTable& SetFont(CFont&);
	CTable& SetBackColor(COLORREF BkClr = RGB(255, 255, 255));
    //粗體
    CTable& b();
    CTable& b_();
    //斜體
    CTable& i();
    CTable& i_();
    //底線
    CTable& u();
    CTable& u_();
    //刪除線
    CTable& s();
    CTable& s_();

    CTable& tr();//, CFont& ft
    CTable& tr_();

    CTable& td(UINT Hspan = 1, UINT Vspan = 1);
    CTable& td(CFont ft, UINT Hspan = 1, UINT Vspan = 1);
    CTable& td(COLORREF bkclr, UINT Hspan, UINT Vspan);//是否要設定成灰色格子
    CTable& td(COLORREF bkclr);//是否要設定成灰色格子
    CTable& td_();


    CTable& text(CString, UINT nFlags = TA_LEFT);
    CTable& text(CString, CFont&, UINT nFlags = TA_LEFT);
    CTable& text(CString, CFont&, COLORREF, UINT nFlags = TA_LEFT);

    CTable& Width(std::vector<UINT>::size_type n, UINT w); //SetWidth(第幾個Cell, 多寬）
    CTable& Hight(std::vector<UINT>::size_type n, UINT h); //SetHight(第幾個Cell, 多高）
    CPoint  GetCellNum();
    CTable& SetCellNum(UINT, UINT);
    CTable& SetTableBoard(UINT tableboard, COLORREF tbclr = RGB(0,0,0));
    CTable& SetGridBoard (UINT gridboard , COLORREF gbclr = RGB(0,0,0));
    CTable& SetCellSpace(UINT sp = 2);

    CPoint  table_();
    CPoint  table_(std::vector<CPoint>& tbPt);

private:
    void DrawRect(COLORREF bkclr);

    UINT nextX(UINT);
    UINT nextY(UINT);

    void DrawGridBoard();
    void DrawFrameBoard();

    //debug
    void ViewSpanTableValue(const CString title = "");
    void ViewTableTableValue(const CString title = "");
};

    /*
    Spen Table Readme

       0        1       2         3       4個
    +--------+--------+--------+--------+
o    |        | h邊長1 | h邊長2 | h邊長3 |
    +--------+========+========+========+
1    | v邊長1 | 跳格子 |        |        |
    +--------+========+========+========+
2    | v邊長2 | 跳格子 |        |        |
    +--------+========+========+========+
3    | v邊長3 |        | 跳格子 |        |
    +--------+========+========+========+
4個
  
    m_vCellWidth.at(m_xCnt) = Wk(k=0~n)
    

      記錄左上角的定位點

               0       1         2       3個
             +========+========+========+
         0     |pt(0,0) |pt(0,0) |pt(0,0) |
             +========+========+========+
         1     |pt(0,0) |pt(0,0) |pt(0,0) |
             +========+========+========+
         2   |pt(0,0) |pt(0,0) |pt(0,0) |
             +========+========+========+
         3個
         
    m_PointTable.at(m_xCnt) = Wk(k=0~n)
    */
#endif // !defined(AFX_TABLE_H__A9B82117_1597_4B66_8A15_2D3924158934__INCLUDED_)
>>>>>>> b5425c75ef070be7770a30afe5b503213bd2584b
