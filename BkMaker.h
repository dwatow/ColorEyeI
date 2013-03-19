#ifndef BKMAKER_H
#define BKMAKER_H

#include "CColorRef.h"
enum BackGroundStatus{BGS_Normal = 0, BGS_NitsPos, BGS_NitsNeg, BGS_CrossTalkWrite, BGS_CrossTalkDark};

class BkMaker
{
protected:
	ColorRef m_BkColor;
	CRect     m_centerRect;  //��b���~Ū�o��H�����F�I
	ColorRef  m_rectColor;  //��b���~Ū�o��H�����F�I
public:    
	BkMaker();
	BkMaker(const BkMaker& bkN);
virtual ColorRef  GetBkColor() const = 0;
virtual void      SetBkColor(ColorRef) = 0;
virtual void setRect(CRect& _rect, ColorRef& clr) = 0;
virtual void setRect(CRect& _rect) = 0;
virtual void setRect(ColorRef& clr) = 0;
virtual void Draw(CPaintDC& dc) = 0;

};

inline BkMaker::BkMaker(): m_BkColor(0)
{}

inline BkMaker::BkMaker(const BkMaker& bkN)
{
	m_BkColor = bkN.m_BkColor;
}


#endif
