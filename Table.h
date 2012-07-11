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
    //�r��
    CFont m_defFont;
    CFont m_curFont;
    CFont* p_OldFont;
    LOGFONT m_lft;

    //��r�C��
    COLORREF m_oldclr;
    COLORREF m_clrText;
    COLORREF m_clrBackGround;

    //�e��u
    UINT m_fBoard;
    UINT m_gBoard;
    CPen m_GridPen;
    CPen m_FramPen;
    CPen* p_OldPen;
    COLORREF m_fbColor;
    COLORREF m_gbColor;

    //�I����
    CBrush m_BkArea;
    CBrush* p_OldBrush;

	//�w���I
    CPoint m_ptOrig;
    CPoint m_ptCur;
    CPoint m_ptNextXY;
    CPoint m_ptEnd;

    CDC* p_DC;

    std::vector<UINT> m_SpanTable;  //�ؤ@��table�A�H0�}�l�w�}�A�O������l����
    std::vector<CPoint> m_PointTable;

    std::vector<UINT>::size_type m_xCnt;
    std::vector<UINT>::size_type m_yCnt;
    std::vector<UINT>::size_type m_xCnt_Max;
    std::vector<UINT>::size_type m_yCnt_Max;

    CSize m_CellSpace; //���e�P��u���Z
public:
    CTable(CDC*, CPoint&);
    virtual ~CTable();

//protected:
    CTable& SetFont(CFont&);
	CTable& SetBackColor(COLORREF BkClr = RGB(255, 255, 255));
    //����
    CTable& b();
    CTable& b_();
    //����
    CTable& i();
    CTable& i_();
    //���u
    CTable& u();
    CTable& u_();
    //�R���u
    CTable& s();
    CTable& s_();

    CTable& tr();//, CFont& ft
    CTable& tr_();

    CTable& td(UINT Hspan = 1, UINT Vspan = 1);
    CTable& td(CFont ft, UINT Hspan = 1, UINT Vspan = 1);
    CTable& td(COLORREF bkclr, UINT Hspan, UINT Vspan);//�O�_�n�]�w���Ǧ��l
    CTable& td(COLORREF bkclr);//�O�_�n�]�w���Ǧ��l
    CTable& td_();


    CTable& text(CString, UINT nFlags = TA_LEFT);
    CTable& text(CString, CFont&, UINT nFlags = TA_LEFT);
    CTable& text(CString, CFont&, COLORREF, UINT nFlags = TA_LEFT);

    CTable& Width(std::vector<UINT>::size_type n, UINT w); //SetWidth(�ĴX��Cell, �h�e�^
    CTable& Hight(std::vector<UINT>::size_type n, UINT h); //SetHight(�ĴX��Cell, �h���^
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

       0        1       2         3       4��
    +--------+--------+--------+--------+
o    |        | h���1 | h���2 | h���3 |
    +--------+========+========+========+
1    | v���1 | ����l |        |        |
    +--------+========+========+========+
2    | v���2 | ����l |        |        |
    +--------+========+========+========+
3    | v���3 |        | ����l |        |
    +--------+========+========+========+
4��
  
    m_vCellWidth.at(m_xCnt) = Wk(k=0~n)
    

      �O�����W�����w���I

               0       1         2       3��
             +========+========+========+
         0     |pt(0,0) |pt(0,0) |pt(0,0) |
             +========+========+========+
         1     |pt(0,0) |pt(0,0) |pt(0,0) |
             +========+========+========+
         2   |pt(0,0) |pt(0,0) |pt(0,0) |
             +========+========+========+
         3��
         
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
    //�r��
    CFont m_defFont;
    CFont m_curFont;
    CFont* p_OldFont;
    LOGFONT m_lft;

    //��r�C��
    COLORREF m_oldclr;
    COLORREF m_clrText;
    COLORREF m_clrBackGround;

    //�e��u
    UINT m_fBoard;
    UINT m_gBoard;
    CPen m_GridPen;
    CPen m_FramPen;
    CPen* p_OldPen;
    COLORREF m_fbColor;
    COLORREF m_gbColor;

    //�I����
    CBrush m_BkArea;
    CBrush* p_OldBrush;

	//�w���I
    CPoint m_ptOrig;
    CPoint m_ptCur;
    CPoint m_ptNextXY;
    CPoint m_ptEnd;

    CDC* p_DC;

    std::vector<UINT> m_SpanTable;  //�ؤ@��table�A�H0�}�l�w�}�A�O������l����
    std::vector<CPoint> m_PointTable;

    std::vector<UINT>::size_type m_xCnt;
    std::vector<UINT>::size_type m_yCnt;
    std::vector<UINT>::size_type m_xCnt_Max;
    std::vector<UINT>::size_type m_yCnt_Max;

    CSize m_CellSpace; //���e�P��u���Z
public:
    CTable(CDC*, CPoint&);
    virtual ~CTable();

//protected:
    CTable& SetFont(CFont&);
	CTable& SetBackColor(COLORREF BkClr = RGB(255, 255, 255));
    //����
    CTable& b();
    CTable& b_();
    //����
    CTable& i();
    CTable& i_();
    //���u
    CTable& u();
    CTable& u_();
    //�R���u
    CTable& s();
    CTable& s_();

    CTable& tr();//, CFont& ft
    CTable& tr_();

    CTable& td(UINT Hspan = 1, UINT Vspan = 1);
    CTable& td(CFont ft, UINT Hspan = 1, UINT Vspan = 1);
    CTable& td(COLORREF bkclr, UINT Hspan, UINT Vspan);//�O�_�n�]�w���Ǧ��l
    CTable& td(COLORREF bkclr);//�O�_�n�]�w���Ǧ��l
    CTable& td_();


    CTable& text(CString, UINT nFlags = TA_LEFT);
    CTable& text(CString, CFont&, UINT nFlags = TA_LEFT);
    CTable& text(CString, CFont&, COLORREF, UINT nFlags = TA_LEFT);

    CTable& Width(std::vector<UINT>::size_type n, UINT w); //SetWidth(�ĴX��Cell, �h�e�^
    CTable& Hight(std::vector<UINT>::size_type n, UINT h); //SetHight(�ĴX��Cell, �h���^
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

       0        1       2         3       4��
    +--------+--------+--------+--------+
o    |        | h���1 | h���2 | h���3 |
    +--------+========+========+========+
1    | v���1 | ����l |        |        |
    +--------+========+========+========+
2    | v���2 | ����l |        |        |
    +--------+========+========+========+
3    | v���3 |        | ����l |        |
    +--------+========+========+========+
4��
  
    m_vCellWidth.at(m_xCnt) = Wk(k=0~n)
    

      �O�����W�����w���I

               0       1         2       3��
             +========+========+========+
         0     |pt(0,0) |pt(0,0) |pt(0,0) |
             +========+========+========+
         1     |pt(0,0) |pt(0,0) |pt(0,0) |
             +========+========+========+
         2   |pt(0,0) |pt(0,0) |pt(0,0) |
             +========+========+========+
         3��
         
    m_PointTable.at(m_xCnt) = Wk(k=0~n)
    */
#endif // !defined(AFX_TABLE_H__A9B82117_1597_4B66_8A15_2D3924158934__INCLUDED_)
>>>>>>> b5425c75ef070be7770a30afe5b503213bd2584b
