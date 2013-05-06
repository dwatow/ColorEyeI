// std::vector<Cartridge2>.h: interface for the RNA class.
//
//////////////////////////////////////////////////////////////////////

#ifndef RNA_H
#define RNA_H

#include <vector>
#include <iterator>
#include "Cartridge2.h"
#include "CartridgeFinder.h"
#include "TxtFile.h"
#include "debugFile.h"

class RNA
{
    std::vector<Cartridge2> m_CarChain2;
//�ظѺc�l
public:
    RNA();
    virtual ~RNA();
    
    //��������vector���ާ@
public:
//    std::vector<Cartridge2>::size_type StdInit();
//    std::vector<Cartridge2>::size_type GammaInit();
//    void DelCell(std::vector<Cartridge2>::size_type index){ m_CarChain2.erase(&m_CarChain2.at(index)); };
    void CutEqualCell(const RNA& );
//    void CutEqualCell(std::vector<Cartridge2> );
//    void Grow(ColorType ct, PointNum pn);
   void DeleteEmptyCell();
//    void SetBolt(Bolt *_P){ p_Pusher = _P; };
//    Bolt* GetBolt(){ return p_Pusher; };
    //��vector����ơA�o���O�����^��
public:
//     Cartridge2& At (ColorType, PointNum, UINT );
//     const Cartridge2& At (ColorType, PointNum, UINT )const ;
	std::vector<int>::size_type HaveSeveral
		(const CString& color = "", const CString& ptTotal = "", const CString& mrIndex = "", const CString& fePara = "");
	float   fFind(const CString&, const CString&, const CString&, const CString&, const ValueKind&);
	CString sFind(const CString&, const CString&, const CString&, const CString&, const ValueKind&);
    Cartridge2& Find(const CString&, const CString&, const CString&, const CString&);
	Cartridge2& Find(const CString&);

public:
	void Empty(); 
    const BOOL IsEmpty() const;
    
    //���ަW�r������������vector �^��
public:
//    Cartridge2& At(Cartridge2);
    const Cartridge2& At(const Cartridge2&) const;
//     Cartridge2& At(std::vector<Cartridge2>::size_type _P)    { return m_CarChain2.at(_P);   };
    const Cartridge2& At(const std::vector<Cartridge2>::size_type& _P) const;

    std::vector<Cartridge2>::iterator       Begin();
    std::vector<Cartridge2>::const_iterator Begin() const;  //using by CutEqualCell(const RNA)
    
    std::vector<Cartridge2>::iterator       End();
    std::vector<Cartridge2>::const_iterator End() const;  //using by CutEqualCell(const RNA)

    const std::vector<Cartridge2>::size_type Size() const;
//     
//     std::vector<Cartridge2>& operator=(const std::vector<Cartridge2>&);
//     void AddCell( std::vector<Cartridge2>::const_iterator& _F, 
//                   std::vector<Cartridge2>::const_iterator& _L );
    void AddCell(const RNA&);
    void AddCell(const Cartridge2& _X);

//sorting
public:
     void SortQuackMsr();
     void SortOrigMsr();
private:
    static bool areaPriority(const Cartridge2 &sp1, const Cartridge2 &sp2);
    static bool origPriority(const Cartridge2 &sp1, const Cartridge2 &sp2);
//     void SortQuackMsr(std::vector<Cartridge2>& vCar) const;
//     void SortOrigMsr (std::vector<Cartridge2>& vCar) const;
    
//operator
public:
    void operator+(const Cartridge2&  _X);
    void operator+(const RNA& _R);
//     void operator+(      RNA& _X) { AddCell(m_CarChain2.end(), _X.Begin(), _X.End()); };
    ////
    //debug
// public:
//    std::vector<CString> InsideData();
private:
	CartridgeFinder finder;
private:
	const int reconstrColor(CString&);
	const int reconstrPointNum(CString&);
	const int reconstrMsrNo(CString&);
	
private:
	debugFile debugLogMaker;
};

inline const BOOL RNA::IsEmpty() const
{ return (m_CarChain2.size() <= 1) ? TRUE : FALSE; };

//inline void RNA::AddCell(std::vector<Cartridge2>::const_iterator& _F, 
//                         std::vector<Cartridge2>::const_iterator& _L)
//{ m_CarChain2.insert(End(), _F, _L); };
inline void RNA::AddCell(const RNA& _R)
{ m_CarChain2.insert(End(), _R.Begin(), _R.End()); }
inline void RNA::AddCell(const Cartridge2& _X)
{ m_CarChain2.push_back(_X);      };

inline std::vector<Cartridge2>::iterator RNA::Begin()
{ return (m_CarChain2.size() <= 1) ? m_CarChain2.end() : m_CarChain2.begin() +1; }
inline std::vector<Cartridge2>::iterator RNA::End()
{ return m_CarChain2.end();};

//Just for coonst RNA
inline std::vector<Cartridge2>::const_iterator RNA::Begin() const
{ return (m_CarChain2.size() <= 1) ? m_CarChain2.end() : m_CarChain2.begin() +1; }
inline std::vector<Cartridge2>::const_iterator RNA::End() const 
{ return m_CarChain2.end();};

inline const std::vector<Cartridge2>::size_type RNA::Size () const
{ return m_CarChain2.size()-1; };

// inline void RNA::operator+(const RNA& _R)
// { AddCell(_R); };
inline void RNA::operator+(const Cartridge2&  _X)
{ AddCell(_X); };


#endif // !defined(AFX_std::vector<Cartridge2>_H__0108A325_5755_4826_B203_49A50707E9EF__INCLUDED_)
