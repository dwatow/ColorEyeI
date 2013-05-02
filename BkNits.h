#ifndef BKNITS_H
#define BKNITS_H

#include "BkMaker.h"

class BkNits : public BkMaker
{
	//m_pCA210
	//hWnd
	void n2cPos(ColorRef&);
	void n2cNeg(ColorRef&);
public:
 	BkNits(const NitsDirect&);
    BkNits(const BkNits& bkN);

	void NT_SetWnd(CWnd* cWnd){ m_pdlgcWnd = cWnd; };
	void NT_SetCa(Ca210* pCa){ m_pCa210 = pCa; };

	void NT_colorReviseByNits(ColorRef&);

	void NT_SetNitsLv(const int&);
	const int  NT_GetNitsLv()const;

};

inline BkNits::BkNits(const NitsDirect& nt)
{
	BkMaker::BkMaker();
	m_NitsDirect = nt;
};

inline BkNits::BkNits(const BkNits& bkN)
{
	BkMaker::BkMaker();
	m_NitsDirect = bkN.m_NitsDirect;
	_SetBkColor(bkN._GetBkColor());
};

inline void BkNits::NT_SetNitsLv(const int& _N)
{ m_NitsLv = _N*100; };
inline const int BkNits::NT_GetNitsLv() const
{ return m_NitsLv/100; };

inline void BkNits::NT_colorReviseByNits(ColorRef& Bkclr)
{
	switch(m_NitsDirect)
	{
	case ND_Pos: n2cPos(Bkclr); break;
	case ND_Neg:
	default:     n2cNeg(Bkclr);
	}
};

#endif