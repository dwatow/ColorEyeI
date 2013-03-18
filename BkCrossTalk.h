#ifndef BKCROSSTALK_H
#define BKCROSSTALK_H

#include "BkMaker.h"

class BkCrossTalk : public BkMaker
{
	/*private:*/
	CRect     m_centerRect;
	ColorRef  m_rectColor;
public:	
	BkCrossTalk();
	BkCrossTalk(const BkCrossTalk& bkN);

	ColorRef GetBkColor() const;
    void SetBkColor(ColorRef);

	void setRect(CRect& _rect, ColorRef& clr);
	void Draw(CPaintDC& dc);
};

inline BkCrossTalk::BkCrossTalk()
{}

inline BkCrossTalk::BkCrossTalk(const BkCrossTalk& bkN)
{
	m_BkColor = bkN.m_BkColor;
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
	m_centerRect = _rect;
	m_BkColor = clr;
}

inline void BkCrossTalk::Draw(CPaintDC& dc)
{
	//�bCPatternDlg�ϥ�
	// Cross Talk ���I����
	CBrush _brush(m_BkColor.oRGB());
    dc.FillRect(m_centerRect, &_brush);
}
#endif
