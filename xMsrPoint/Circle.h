#ifndef CIRCLE_H
#define CIRCLE_H
#include <afxmt.h>
//#include "Bullet.h"
#include "../CColorRef.h"
#include "../ValuesLabel.h"

enum CirclePercent {CP_NULL, CP_X, CP_FULL};

class Circle
{
	//建構子
public:
    Circle(CWnd* cWnd = NULL, int r = 1);

	//Basic
private:
	int m_Percent;
    virtual void drawPercent();
public:
	CirclePercent SetPercent(int pct);
    int GetPercent() const;
	
private:
	int m_nRadius;
public:
    void SetRadius(int r);
    int GetRadius() const;
	
private:
    CPoint m_nCenter;
public:
    void SetCenter(CPoint p);
    void SetCenter(int x, int y);
    CPoint GetCenter() const;

//Animation Dynamic
private:
	int   m_MaxRadius;
	CRect m_reDeawRect;
	void readRadius(int&);
	CRect r2rect(int);

public:
	void Animation();

//Thread
private:
    struct myThreadInfo{ Circle* pCircle; }m_Info1;
    CCriticalSection m_cs; //單一執行緒的鎖
    static void elasticAnimation(LPVOID LParam);
    CWnd* m_pdlgcWnd;
    CWnd* gethWnd(){ return m_pdlgcWnd; };
	void reDrawWindow();
public:
	void setWnd(CWnd* cWnd){ m_pdlgcWnd = cWnd; };
	int DampingVibration(int, int); //for Thread

//Draw Static
private:
	CPen* tracePen; //debug trace
    CPen m_Pen;
    int  m_nPenWidth;
	CRect m_DrawCircleRect;
    void drawCircle(CPaintDC&);

private:
	ColorRef m_strColor;
	BOOL m_isShowPercentNum;
	BOOL m_isShowLabel;
	ValuesLabel m_Label;
	void drawPercentNum(CPaintDC &dc);
public:	
	void SetupLabel(Bullet&);
	void SetStrColor(const ColorRef clr);
	ColorRef GetStrColor() const;

private:
    ColorRef m_arcColor;
public:
	void SetArcColor(const ColorRef clr);
    ColorRef GetArcColor() const;
			
	virtual void Draw(CPaintDC&);


#ifdef _DEBUG
    CString showMe() const;
#endif

};
#endif