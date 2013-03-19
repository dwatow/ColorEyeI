#ifndef BKNORMAL_H
#define BKNORMAL_H

#include "BkMaker.h"

class BkNormal : public BkMaker
{
public:
	BkNormal();
	BkNormal(const BkNormal& bkN);
	ColorRef  GetBkColor() const;
    void      SetBkColor(ColorRef);
    void setRect(CRect& _rect, ColorRef& clr){};
    void setRect(CRect& _rect){};
    void setRect(ColorRef& clr){};
    void Draw(CPaintDC& dc){};
};

inline BkNormal::BkNormal()
{}

inline BkNormal::BkNormal(const BkNormal& bkN)
{
	m_BkColor = bkN.m_BkColor;
}

inline ColorRef BkNormal::GetBkColor() const
{
	return m_BkColor;
}

inline void BkNormal::SetBkColor(ColorRef _CLR)
{
	m_BkColor = _CLR;
}
#endif
