#ifndef VALUESLABEL_H
#define VALUESLABEL_H

#include "Bullet.h"
#include "CColorRef.h"

class ValuesLabel
{
	Bullet m_bltData;

	const int m_cWidth;
	const int m_cHight;
	const ColorRef m_clrNG;
	const CSize m_DisplayArea;

	CPoint  m_pointMsring;
	CPoint  m_pointShow;

	Bullet m_specMax;
	Bullet m_specMin;
	void printx(CPaintDC& , int);
public:
	ValuesLabel();
	void BindCircle(const int, const CPoint );
	void SetData(const Bullet& );
	void Draw(CPaintDC& );
};



#endif