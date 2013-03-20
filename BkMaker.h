#ifndef BKMAKER_H
#define BKMAKER_H

#include "CColorRef.h"
#include "CA210.h"

enum NitsType{NT_Pos, NT_Neg};

class BkMaker
{
public:
    BkMaker();
    BkMaker(const BkMaker& bkN);

//背景色
private:
	ColorRef  m_BkColor;
public:
    ColorRef  GetBkColor() const;
    virtual	void SetBkColor(const ColorRef&);

//Crosstalk的介面
protected:
	CRect     m_centerRect;
    ColorRef  m_rectColor;
public:
    virtual	void SetRect(const CRect& _rect, const ColorRef& clr) = 0;
	virtual	void setRect(const CRect& _rect) = 0;
	virtual	void setRect(const ColorRef& clr) = 0;
	virtual	CRect getRect() const = 0;
	virtual	ColorRef getRectColor() const = 0;

//Nits的介面
private:
	CWnd* m_pdlgcWnd;
	Ca210* m_pCa210;

	int m_Nits;
	NitsType m_Ntype;
	virtual	ColorRef nits2color() = 0;
public:
	virtual	void setWnd(CWnd* cWnd) = 0;
	virtual void setCa(Ca210* pCa) = 0;

	void SetNitsType(NitsType nt);
	NitsType GetNitsType() const;
//共用介面
public:
	virtual void Draw(CPaintDC& dc) = 0;

};

inline BkMaker::BkMaker(): m_BkColor(0){}

inline BkMaker::BkMaker(const BkMaker& bkN)
{ SetBkColor(bkN.m_BkColor); }

inline ColorRef BkMaker::GetBkColor() const
{ return m_BkColor; }
inline void BkMaker::SetBkColor(const ColorRef& clr)
{ m_BkColor = clr; }



#endif
