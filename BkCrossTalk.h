#ifndef BKCROSSTALK_H
#define BKCROSSTALK_H

#include "BkMaker.h"

class BkCrossTalk : public BkMaker
{
public:	
	BkCrossTalk(ColorRef);
	BkCrossTalk(const BkCrossTalk& bkN);

private:
	          void setRect(const CRect& _rect);
	          void setRect(const ColorRef& clr);
	const    CRect getRect()      const;
	const ColorRef getRectColor() const;
public:	
    	      void CT_SetRect(const CRect& _rect, const ColorRef& clr);
public:	
              void Draw(CPaintDC& dc);
};

inline BkCrossTalk::BkCrossTalk(ColorRef clrRrect)
{
	BkMaker::BkMaker();
	setRect(clrRrect);

// 	ColorRef clrBk;
// 	clrBk.iGray(128);
// 	_SetBkColor(clrBk);
}

inline BkCrossTalk::BkCrossTalk(const BkCrossTalk& bkN)
{
	BkMaker::BkMaker();
	setRect(bkN.getRect());
	setRect(bkN.getRectColor());
	_SetBkColor(bkN._GetBkColor());
}

inline void BkCrossTalk::setRect(const CRect& _rect)
{ m_centerRect = _rect; }
inline void BkCrossTalk::setRect(const ColorRef& clr)
{ m_rectColor = clr; }

inline const CRect BkCrossTalk::getRect() const
{ return m_centerRect; }
inline const ColorRef BkCrossTalk::getRectColor() const
{ return m_rectColor; }

inline void BkCrossTalk::CT_SetRect(const CRect& _rect, const ColorRef& clr)
{
	//在DNA轉RNA時使用
	setRect(_rect);
	setRect(clr);
}

inline void BkCrossTalk::Draw(CPaintDC& dc)
{
	//在CPatternDlg使用
	//Cross Talk 的背景色
	CBrush _brush(getRectColor().oRGB());
    dc.FillRect(getRect(), &_brush);
}

#endif
