// xChain.h: interface for the CDataChain class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_xChain_H__0108A325_5755_4826_B203_49A50707E9EF__INCLUDED_)
#define AFX_xChain_H__0108A325_5755_4826_B203_49A50707E9EF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <vector>
#include <iterator>
#include "xMsrPoint/Bolt.h"

//typedef std::vector<Cartridge> xChain;

class CDataChain
{
	//public:
	xChain m_CarChain1;
	
public:
	CDataChain();
	virtual ~CDataChain();
	
	//完全不像vector的操作
public:
    xChain::size_type StdInit();
	xChain::size_type GammaInit();
    void DelCell(xChain::size_type index){ m_CarChain1.erase(&m_CarChain1.at(index)); };
   	void CutEqualCell(CDataChain );
    void CutEqualCell(xChain );
    void Grow(ColorType ct, PointNum pn);
    void SortQuackMsr();
    void freeEmptyCell();
	//像vector的函數，卻不是直接回傳
public:
	Cartridge& At (ColorType, PointNum, UINT );
    const Cartridge& At (ColorType, PointNum, UINT )const ;
	
    void Empty(); 
    BOOL IsEmpty() const{ return (m_CarChain1.size() <= 1) ? TRUE : FALSE; };
	
	//不管名字像不像直接由vector 回傳
public:
	Cartridge& At(xChain::size_type _P)       { return m_CarChain1.at(_P);   };
    const Cartridge& At(xChain::size_type _P) const { return m_CarChain1.at(_P);   };
	
	xChain::iterator            Begin()       { return (m_CarChain1.end() - m_CarChain1.begin() == 1) ? m_CarChain1.end() : m_CarChain1.begin() +1 ; }
	xChain::const_iterator      Begin() const { return (m_CarChain1.end() - m_CarChain1.begin() == 1) ? m_CarChain1.end() : m_CarChain1.begin() +1 ; }
	
	xChain::iterator            End  ()       { return m_CarChain1.end();     };
	xChain::const_iterator      End  () const { return m_CarChain1.end();     };
	
	xChain::size_type           Size () const { return m_CarChain1.size()-1; };
	
    xChain& operator=(const xChain&);
    void AddCell(xChain::iterator _P, 
		xChain::const_iterator _F, 
		xChain::const_iterator _L)
	{ m_CarChain1.insert(_P, _F, _L); };
    void AddCell(const Cartridge& _X)   { m_CarChain1.push_back(_X);      };
	//sorting
private:
	static bool AreaPriority(const Cartridge &sp1, const Cartridge &sp2);
	static bool OrigPriority(const Cartridge &sp1, const Cartridge &sp2);
	void SortQuackMsr(xChain& vCar) const;
	void SortOrigMsr (xChain& vCar) const;
	//operator
public:
	void operator+(const Cartridge&  _X) { AddCell(_X); };
	void operator+(      CDataChain& _X) { AddCell(m_CarChain1.end(), _X.Begin(), _X.End()); };
	////
	//debug
public:
	std::vector<CString> InsideData();
};

#endif // !defined(AFX_xChain_H__0108A325_5755_4826_B203_49A50707E9EF__INCLUDED_)
