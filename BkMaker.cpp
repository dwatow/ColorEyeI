#include "stdafx.h"
#include "BkMaker.h"

BkMaker::BkMaker(): 
ptr_i(0), cnt(0), 
m_BkColor(0), 
m_centerRect(0, 0, 0, 0), m_rectColor(0), 
m_pdlgcWnd(0), m_pCa210(0), m_NitsLv(0), m_NitsDirect(ND_NoDefine)
{
	cnt = new int(0);
	(*cnt)++;
}

BkMaker::BkMaker(const BkMaker& bkN): 
ptr_i(bkN.ptr_i), cnt(bkN.cnt), 
m_BkColor(bkN.m_BkColor), 
m_centerRect(bkN.m_centerRect), m_rectColor(bkN.m_rectColor), 
m_pdlgcWnd(bkN.m_pdlgcWnd), m_pCa210(bkN.m_pCa210), m_NitsLv(bkN.m_NitsLv), m_NitsDirect(bkN.m_NitsDirect)
{
	(*cnt)++;
}

BkMaker::~BkMaker()
{
	if (--(*cnt) == 0)
	{
		delete cnt;
		cnt = 0;
		
		delete ptr_i;
		ptr_i = 0;
	}
}

BkMaker& BkMaker::operator=(const BkMaker& sp)
{
	if(&sp != this)
	{
		//we shouldn't forget to handle the ref_cnt our AutoPtr previously pointed to
		if (--(*cnt) == 0)
		{
			delete cnt;
			cnt = 0;

			delete ptr_i;
			ptr_i = 0;
		}
		//copy the ptr and ref_cnt and increment the ref_cnt
		ptr_i = sp.ptr_i;
		cnt = sp. cnt;
		(*cnt)++;

		m_BkColor = sp.m_BkColor;
		m_centerRect = sp.m_centerRect;
		m_rectColor = sp.m_rectColor;
		m_pdlgcWnd = sp.m_pdlgcWnd;
		m_pCa210 = sp.m_pCa210;
		m_NitsLv = sp.m_NitsLv;
		m_NitsDirect = sp.m_NitsDirect;
	}
	return *this;
}

const ColorRef BkMaker::_GetBkColor() const
{ return m_BkColor; }
void BkMaker::_SetBkColor(const ColorRef& clr)
{ m_BkColor = clr; }

void BkMaker::Draw(CPaintDC& dc){};

