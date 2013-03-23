#ifndef CIRCLE_H
#define CIRCLE_H
#include <afxmt.h>
#include "../CColorRef.h"
#include "../ValuesLabel.h"
#include <cmath>

enum CirclePercent {CP_NULL, CP_X, CP_FULL};

class Circle
{
	//�غc�l
public:
    Circle(CWnd* cWnd = NULL, int r = 1);

	//Basic
private:
	int m_Percent;
    virtual void drawPercent(CPaintDC&);
public:
	void SetPercent(int pct);
    int GetPercent() const;
	
private:
	int m_nRadius;
public:
    void SetRadius(const int& r);
    int GetRadius() const;
	
private:
    CPoint m_nCenter;
public:
    void SetCenter(const CPoint& p);
    void SetCenter(const int& x, const int& y);
    CPoint GetCenter() const;

//Animation Dynamic
private:
	int   m_MaxRadius;
	CRect m_reDeawRect;
	void readRadius(const int&);
	CRect r2rect(int);

public:
	void Animation();

//Thread
private:
    struct myThreadInfo{ Circle* pCircle; }m_Info1;
    CCriticalSection m_cs; //��@���������
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
	void SetData(const Bullet&);
	void SetStrColor(const ColorRef clr);  //�����I����
	ColorRef GetStrColor() const;
	void ShowLabel(BOOL);

private:
    ColorRef m_arcColor;
public:
	void SetArcColor(const ColorRef clr);  //����O�C��
    ColorRef GetArcColor() const;
private:
	BOOL m_Visible;
public:
	BOOL isVisible() const;
	void Visible(BOOL b);
	
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
		m_isShowPercentNum = FALSE;
		
		CSingleLock csl(&m_cs);
		csl.Lock();
		elasticAnimation((LPVOID)&m_Info1);
		csl.Unlock();
		
		m_isShowPercentNum = TRUE;
		m_isShowLabel = t_isShowLabel;
	}
	else
		ASSERT(0);
};

inline void Circle::elasticAnimation(LPVOID LParam)
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
        Sleep(16); //�ո`�ʵe���e�ɬO�_�ݱo��
    }
}
 
inline int Circle::GetRadius() const
{ return m_nRadius; }

inline int Circle::DampingVibration(int k, int x0) 
{
	//�_�ʪ�����ơA���D�ק�_�ʪ����p�]�����j�p�Ϊ̬O�_���ɶ��^
	//�_�h���ܡA���έק�
    //max = 375
    //min = 0
    //375-15/15
    ASSERT(k>=0);
    ASSERT(x0>=0);
	const int trmpR = (long)((x0*-exp(-0.01*(24*k+15))*sin(0.0209439*(24*k+15)+1.570795)) + x0);
	return trmpR;
}


#endif