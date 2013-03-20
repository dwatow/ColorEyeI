#ifndef BKCROSSTALK_H
#define BKCROSSTALK_H

#include "BkMaker.h"

class BkCrossTalk : public BkMaker
{
public:	
	BkCrossTalk(ColorRef);
	BkCrossTalk(const BkCrossTalk& bkN);

	void SetRect(const CRect& _rect, const ColorRef& clr);
	void Draw(CPaintDC& dc);

	void setRect(const CRect& _rect);
	void setRect(const ColorRef& clr);
	CRect getRect() const;
	ColorRef getRectColor() const;

	ColorRef nits2color(){ return GetBkColor(); };
	void setWnd(CWnd* cWnd){};
	void setCa(Ca210* pCa){};
};

inline BkCrossTalk::BkCrossTalk(ColorRef clr)
{
	BkMaker::BkMaker();
	setRect(clr);
	clr.iGray(128);
	SetBkColor(clr);
}

inline BkCrossTalk::BkCrossTalk(const BkCrossTalk& bkN)
{
	BkMaker::BkMaker();
	setRect(bkN.getRect());
	setRect(bkN.getRectColor());
	SetBkColor(bkN.GetBkColor());
}

inline void BkCrossTalk::SetRect(const CRect& _rect, const ColorRef& clr)
{
	//�bDNA��RNA�ɨϥ�
	setRect(_rect);
	setRect(clr);
}

inline void BkCrossTalk::Draw(CPaintDC& dc)
{
	//�bCPatternDlg�ϥ�
	//Cross Talk ���I����
	CBrush _brush(getRectColor().oRGB());
    dc.FillRect(getRect(), &_brush);
}

inline CRect BkCrossTalk::getRect() const
{ return m_centerRect; }
inline ColorRef BkCrossTalk::getRectColor() const
{ return m_rectColor; }

inline void BkCrossTalk::setRect(const CRect& _rect)
{ m_centerRect = _rect; }
inline void BkCrossTalk::setRect(const ColorRef& clr)
{ m_rectColor = clr; }

#endif
