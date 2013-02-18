// std::vector<Cartridge2>.h: interface for the RNA class.
//
//////////////////////////////////////////////////////////////////////

#ifndef RNA_H
#define RNA_H

#include <vector>
#include <iterator>
#include "xMsrPoint/Cartridge2.h"
#include "xMsrPoint/Bolt.h"

//typedef std::vector<Cartridge2> std::vector<Cartridge2>;

class RNA
{
	//public:
	std::vector<Cartridge2> m_CarChain2;
	Bolt *p_Pusher;

	
public:
	RNA();
	virtual ~RNA();
	
	//完全不像vector的操作
public:
//     std::vector<Cartridge2>::size_type StdInit();
// 	std::vector<Cartridge2>::size_type GammaInit();
//     void DelCell(std::vector<Cartridge2>::size_type index){ m_CarChain2.erase(&m_CarChain2.at(index)); };
//    	void CutEqualCell(RNA );
//     void CutEqualCell(std::vector<Cartridge2> );
//     void Grow(ColorType ct, PointNum pn);
//     void SortQuackMsr();
// 	void SortOrigMsr();
//     void freeEmptyCell();
// 	void SetBolt(Bolt *_P){ p_Pusher = _P; };
// 	Bolt* GetBolt(){ return p_Pusher; };
	//像vector的函數，卻不是直接回傳
public:
// 	Cartridge2& At (ColorType, PointNum, UINT );
//     const Cartridge2& At (ColorType, PointNum, UINT )const ;
// 	
     void Empty(); 
     BOOL IsEmpty() const{ return (m_CarChain2.size() <= 1) ? TRUE : FALSE; };
	
	//不管名字像不像直接由vector 回傳
public:
	Cartridge2& At(Cartridge2);
    const Cartridge2& At(Cartridge2) const;
// 	Cartridge2& At(std::vector<Cartridge2>::size_type _P)       { return m_CarChain2.at(_P);   };
//     const Cartridge2& At(std::vector<Cartridge2>::size_type _P) const { return m_CarChain2.at(_P);   };

	std::vector<Cartridge2>::iterator            Begin()       { return (m_CarChain2.end() - m_CarChain2.begin() == 1) ? m_CarChain2.end() : m_CarChain2.begin() +1 ; }
	std::vector<Cartridge2>::const_iterator      Begin() const { return (m_CarChain2.end() - m_CarChain2.begin() == 1) ? m_CarChain2.end() : m_CarChain2.begin() +1 ; }
	
	std::vector<Cartridge2>::iterator            End  ()       { return m_CarChain2.end();     };
	std::vector<Cartridge2>::const_iterator      End  () const { return m_CarChain2.end();     };

 	std::vector<Cartridge2>::size_type           Size () const { return m_CarChain2.size()-1; };
// 	
//     std::vector<Cartridge2>& operator=(const std::vector<Cartridge2>&);
     void AddCell(std::vector<Cartridge2>::iterator _P, 
 		std::vector<Cartridge2>::const_iterator _F, 
 		std::vector<Cartridge2>::const_iterator _L)
 	{ m_CarChain2.insert(_P, _F, _L); };
     void AddCell(const Cartridge2& _X)   { m_CarChain2.push_back(_X);      };
	//sorting
private:
// 	static bool AreaPriority(const Cartridge2 &sp1, const Cartridge2 &sp2);
// 	static bool OrigPriority(const Cartridge2 &sp1, const Cartridge2 &sp2);
// 	void SortQuackMsr(std::vector<Cartridge2>& vCar) const;
// 	void SortOrigMsr (std::vector<Cartridge2>& vCar) const;
	//operator
public:
 	void operator+(const Cartridge2&  _X) { AddCell(_X); };
// 	void operator+(      RNA& _X) { AddCell(m_CarChain2.end(), _X.Begin(), _X.End()); };
	////
	//debug
public:
//	std::vector<CString> InsideData();
};

#endif // !defined(AFX_std::vector<Cartridge2>_H__0108A325_5755_4826_B203_49A50707E9EF__INCLUDED_)
