<<<<<<< HEAD
#ifndef CIRCLE_H
#define CIRCLE_H
#include <afxmt.h>

class Circle
{
	CPen m_Pen;
	int m_nPenWidth;
	COLORREF m_BkColor;
public:
	Circle();
 	void reSetRect(int range = 0);
// 	CRect GetRect() const;

	BOOL SetColor(COLORREF clr);
	COLORREF GetColor() const;

	BOOL SetBkColor(COLORREF clr);
	COLORREF GetBkColor() const;

	BOOL SetRadius(UINT r);
	UINT GetRadius() const;

	BOOL SetCenter(CPoint p);
	BOOL SetCenter(int x, int y);
	CPoint GetCenter() const;

	UINT SetPercent(UINT pct);
	UINT GetPercent() const;

	void DrawCircle(CPaintDC&);
	virtual CRect VbrFun(UINT, UINT);

	CString GetSetupValue() const;

protected:
	CCriticalSection m_cs; //單一執行緒的鎖
	CRect    m_DrawRect;
	UINT     m_nRadius;
	UINT     m_Percent;
	CPoint   m_nCenter;
	COLORREF m_Color;
	virtual void DrawArc(CPoint& ){};
	virtual void DrawClr(COLORREF& ){};
};
=======
#ifndef CIRCLE_H
#define CIRCLE_H
#include <afxmt.h>

class Circle
{
	CPen m_Pen;
	int m_nPenWidth;
	COLORREF m_BkColor;
public:
	Circle();
 	void reSetRect(int range = 0);
// 	CRect GetRect() const;

	BOOL SetColor(COLORREF clr);
	COLORREF GetColor() const;

	BOOL SetBkColor(COLORREF clr);
	COLORREF GetBkColor() const;

	BOOL SetRadius(UINT r);
	UINT GetRadius() const;

	BOOL SetCenter(CPoint p);
	BOOL SetCenter(int x, int y);
	CPoint GetCenter() const;

	UINT SetPercent(UINT pct);
	UINT GetPercent() const;

	void DrawCircle(CPaintDC&);
	virtual CRect VbrFun(UINT, UINT);

	CString GetSetupValue() const;

protected:
	CCriticalSection m_cs; //單一執行緒的鎖
	CRect    m_DrawRect;
	UINT     m_nRadius;
	UINT     m_Percent;
	CPoint   m_nCenter;
	COLORREF m_Color;
	virtual void DrawArc(CPoint& ){};
	virtual void DrawClr(COLORREF& ){};
};
>>>>>>> b5425c75ef070be7770a30afe5b503213bd2584b
#endif