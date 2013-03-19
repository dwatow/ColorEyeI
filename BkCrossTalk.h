#ifndef BKCROSSTALK_H
#define BKCROSSTALK_H

#include "BkMaker.h"

class BkCrossTalk : public BkMaker
{
	/*private:*/
public:	
	BkCrossTalk(ColorRef);
	BkCrossTalk(const BkCrossTalk& bkN);

	ColorRef GetBkColor() const;
    void SetBkColor(ColorRef);

	void setRect(CRect& _rect, ColorRef& clr);
	void setRect(CRect& _rect);
	void setRect(ColorRef& clr);
	void Draw(CPaintDC& dc);
};

inline BkCrossTalk::BkCrossTalk(ColorRef clr)
{
	m_BkColor.iRGB(128, 128, 128);
	m_rectColor = clr;
}

inline BkCrossTalk::BkCrossTalk(const BkCrossTalk& bkN)
{
	m_rectColor  = bkN.m_rectColor;
	m_centerRect = bkN.m_centerRect;
	m_BkColor    = bkN.m_BkColor;
}

inline ColorRef BkCrossTalk::GetBkColor() const
{
	return m_BkColor;
}

inline void BkCrossTalk::SetBkColor(ColorRef _CLR)
{
	m_BkColor = _CLR;
}

inline void BkCrossTalk::setRect(CRect& _rect, ColorRef& clr)
{
	//�bDNA��RNA�ɨϥ�
	setRect(_rect);
	setRect(clr);
}

inline void BkCrossTalk::setRect(CRect& _rect)
{
	//�bDNA��RNA�ɨϥ�
	m_centerRect = _rect;
}

inline void BkCrossTalk::setRect(ColorRef& clr)
{
	//�bDNA��RNA�ɨϥ�
	m_rectColor = clr;
}

inline void BkCrossTalk::Draw(CPaintDC& dc)
{
	//�bCPatternDlg�ϥ�
	// Cross Talk ���I����
	CBrush _brush(m_rectColor.oRGB());
    dc.FillRect(m_centerRect, &_brush);
}
#endif
