#ifndef CIRCLE_H
#define CIRCLE_H

#include "CColorRef.h"
#include "ValuesLabel.h"
#include <cmath>
#include <afxmt.h>

enum CirclePercent {CP_NULL, CP_X, CP_FULL};

class Circle
{
//建構子
public:
    Circle(CWnd* cWnd = NULL, int r = 1);

//Basic
//百分比
private:
	int      m_Percent;
	ColorRef m_percentColor;
    virtual void drawPercent(CPaintDC&);
public:
	void SetPercent   (const int& pct);
	void SetPrcntColor(const ColorRef clr);  //類似背景色
    const      int GetPercent() const;
	const ColorRef GetPrcntColor() const;

//半徑
private:
	int m_nRadius;
public:
    void SetRadius(const int& r);
    const int GetRadius() const;

//中心點座標
private:
    CPoint m_nCenter;
public:
    void SetCenter(const CPoint& p);
    void SetCenter(const int& x, const int& y);
    const CPoint GetCenter() const;

//Animation Dynamic
private:
	int   m_MaxRadius;
	CRect m_reDeawRect;
	void readRadius(const int&);
	const CRect r2rect(const int&);

public:
	void Animation();

//Thread
private:
    struct myThreadInfo{ Circle* pCircle; }m_Info1;
    CCriticalSection m_cs; //單一執行緒的鎖
    static void elasticAnimation(const LPVOID& LParam);

    CWnd* m_pdlgcWnd;
    CWnd* gethWnd(){ return m_pdlgcWnd; };
	void  reDrawWindow();
public:
	void SetWnd(CWnd* cWnd){ m_pdlgcWnd = cWnd; };
	const int DampingVibration(const int&, const int&); //for Thread

//Draw Static
private:
	CPen* tracePen; //debug trace
    CPen  m_Pen;
    int   m_nPenWidth;
	CRect m_DrawCircleRect;
    void  drawCircle(CPaintDC&);

//Label
private:
	ValuesLabel m_Label;
	BOOL m_isShowPercentCount;
	BOOL m_isShowLabel;
	void drawPercentCount(CPaintDC &dc);
public:	
	void SetData(const Bullet&);
	void ShowLabel(const BOOL&);

private:
    ColorRef m_arcColor;
public:
	void SetArcColor(const ColorRef& clr);  //紅綠燈顏色
    const ColorRef GetArcColor() const;
private:
	BOOL m_Visible;
public:
	const BOOL isVisible() const;
	void Visible(const BOOL& b);
	
	virtual void Draw(CPaintDC&);

#ifdef _DEBUG
    CString showMe() const;
#endif

};

inline void Circle::Animation()
{
	if (m_pdlgcWnd != NULL)
	{
		
		BOOL t_isShowLabel(m_isShowLabel);
		m_isShowLabel = FALSE;
		m_isShowPercentCount = FALSE;
		
		CSingleLock csl(&m_cs);
		csl.Lock();
		elasticAnimation((LPVOID)&m_Info1);
		csl.Unlock();
		
		m_isShowPercentCount = TRUE;
		m_isShowLabel = t_isShowLabel;
	}
	else
		ASSERT(0);
};

inline void Circle::elasticAnimation(const LPVOID& LParam)
{
    myThreadInfo *pInfo1 = (myThreadInfo *)LParam;
    Circle *_pCircle = (Circle*)(pInfo1->pCircle);
	
    ASSERT(_pCircle);
    ASSERT(_pCircle->GetRadius() > 0);
	
    const int r = _pCircle->GetRadius();
    _pCircle->gethWnd()->Invalidate();
    _pCircle->gethWnd()->UpdateWindow();
	
	int dynamicR;
    for (int i = 1; i < 17; ++i)
    {
		dynamicR = _pCircle->DampingVibration(i, r);
		_pCircle->readRadius(dynamicR);
		_pCircle->reDrawWindow();
        Sleep(16); //調節動畫重畫時是否看得到
    }
}
 
inline const int Circle::GetRadius() const
{ return m_nRadius; }

inline void Circle::SetPercent(const int& percent)
{ m_Percent = percent; }
inline const int Circle::GetPercent() const
{ return m_Percent; }

inline const ColorRef Circle::GetArcColor() const
{  return m_arcColor; }
inline const ColorRef Circle::GetPrcntColor() const
{ return m_percentColor; }

inline const BOOL Circle::isVisible() const
{ return m_Visible; }
inline void Circle::Visible(const BOOL& _V)
{ m_Visible = _V; }

inline void Circle::SetCenter(const CPoint& p)
{ SetCenter(p.x, p.y); }
inline const CPoint Circle::GetCenter() const
{ return m_nCenter; }

inline void Circle::reDrawWindow()
{ gethWnd()->RedrawWindow(&m_reDeawRect); }



inline const int Circle::DampingVibration(const int& k, const int& x0) 
{
	//震動阻尼函數，除非修改震動的情況（阻尼大小或者是震盪時間）
	//否則的話，不用修改
    //max = 375
    //min = 0
    //375-15/15
    ASSERT(k>=0);
    ASSERT(x0>=0);
	const int trmpR = (long)((x0*-exp(-0.01*(24*k+15))*sin(0.0209439*(24*k+15)+1.570795)) + x0);
	return trmpR;
}


#endif