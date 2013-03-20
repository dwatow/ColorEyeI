#ifndef BKNORMAL_H
#define BKNORMAL_H

#include "BkMaker.h"

class BkNormal : public BkMaker
{
public:
	BkNormal();
	BkNormal(const BkNormal& bkN);
    void SetRect(const CRect& _rect, const ColorRef& clr){};
    void Draw(CPaintDC& dc){};
	void setRect(const CRect& _rect){};
	void setRect(const ColorRef& clr){};
	CRect getRect() const{ return m_centerRect;};
	ColorRef getRectColor() const{ return m_rectColor; };

	ColorRef nits2color(){ return GetBkColor(); };
	void setWnd(CWnd* cWnd){};
	void setCa(Ca210* pCa){};

};

inline BkNormal::BkNormal()
{
	ColorRef clr(0, 0, 0);
	SetBkColor(clr);
}

inline BkNormal::BkNormal(const BkNormal& bkN)
{
	SetBkColor(bkN.GetBkColor());
}

#endif
