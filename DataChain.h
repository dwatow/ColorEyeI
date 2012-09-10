// DataChain.h: interface for the CDataChain class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DATACHAIN_H__0108A325_5755_4826_B203_49A50707E9EF__INCLUDED_)
#define AFX_DATACHAIN_H__0108A325_5755_4826_B203_49A50707E9EF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <vector>
#include <iterator>
#include "xMsrPoint/Bolt.h"

typedef std::vector<Cartridge> ChainData;

class CDataChain
{
public:
     ChainData m_CarChain1;

public:
     CDataChain();
     virtual ~CDataChain();

public:
//完全不像vector的操作
    ChainData::size_type StdInit();
//    void DelCell(const ChainData::size_type index);
    
    void RemoveEqualCell(CDataChain& );
    void RemoveEqualCell(ChainData& vCar);
    void Grow(ColorType ct, PointNum pn);
    void SortQuackMsr();
    void freeBuffer();
    void freeZeroCell();
public:
//像vector的函數，卻不是直接回傳
          Cartridge& At (ColorType, PointNum, UINT );
    const Cartridge& At (ColorType, PointNum, UINT )const ;

    void Empty(); 
    BOOL IsEmpty(){ return (m_CarChain1.size() <= 1) ? TRUE : FALSE;};

//不管名字像不像直接由vector 回傳
public:
          Cartridge& At(ChainData::size_type _P)       { return m_CarChain1.at(_P);   };
    const Cartridge& At(ChainData::size_type _P) const { return m_CarChain1.at(_P);   };
          ChainData::iterator       Begin()            { return m_CarChain1.begin()+1;};
          ChainData::iterator       End()              { return m_CarChain1.end;      };
          ChainData::const_iterator Begin()      const { return m_CarChain1.begin()+1;};
          ChainData::const_iterator End()        const { return m_CarChain1.end;      };
          ChainData::size_type      Size()       const { return m_CarChain1.size()-1; };

    ChainData& operator=(const ChainData&);
    void AddCell(ChainData::iterator _P, 
                 ChainData::const_iterator _F, 
                 ChainData::const_iterator _L)
                                        { m_CarChain1.insert(_P, _F, _L); };
    void AddCell(const Cartridge& _X)   { m_CarChain1.push_back(_X);      };
//sorting
 private:
     static bool AreaPriority(const Cartridge &sp1, const Cartridge &sp2);
     static bool OrigPriority(const Cartridge &sp1, const Cartridge &sp2);
     void SortQuackMsr(ChainData& vCar) const;
     void SortOrigMsr (ChainData& vCar) const;
//operator
 public:
     void operator+(const Cartridge&  _X) { AddCell(_X); };
     void operator+(      CDataChain& _X) { AddCell(m_CarChain1.end(), _X.Begin(), _X.End()); };
////
//debug
 public:
     std::vector<CString> InsideData();
};

#endif // !defined(AFX_DATACHAIN_H__0108A325_5755_4826_B203_49A50707E9EF__INCLUDED_)
