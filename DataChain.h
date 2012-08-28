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
#include "../xMsrPoint/Bolt.h"


class CDataChain// :public std::vector<Cartridge>
{
 	std::vector<Cartridge> m_CarChain1;
	Bolt* m_pVectorMaker;

 public:
 	CDataChain();
 	virtual ~CDataChain();
 	void AddCell(const Cartridge&);
 	void AddChain(std::vector<Cartridge>::iterator _P, std::vector<Cartridge>::const_iterator _F, std::vector<Cartridge>::const_iterator _L);
	void DelCell(const std::vector<Cartridge>::size_type index);

	void operator+(const Cartridge&);
	void operator+(CDataChain&);

	//+
	
	std::vector<Cartridge>::size_type StdInit();
	void RemoveEqualCell(CDataChain& );
	void Partition(ColorType ct, PointNum pn);
	void SortQuackMsr();
	void ReleaseBuffer();

//Simulator Vector member function
	void Empty(); 
	std::vector<Cartridge>::iterator Begin();
	std::vector<Cartridge>::iterator End();
	std::vector<Cartridge>::const_iterator cBegin();
	std::vector<Cartridge>::const_iterator cEnd();
 	Cartridge& At(ColorType, PointNum, UINT );
	Cartridge& At(std::vector<Cartridge>::size_type );

 	std::vector<Cartridge>& operator=(const std::vector<Cartridge>&);
	BOOL IsEmpty();

//	Cartridge& operator[](ColorType, PointNum, UINT);

 private:
	 static bool AreaPriority(const Cartridge &sp1, const Cartridge &sp2);
	 static bool OrigPriority(const Cartridge &sp1, const Cartridge &sp2);
	 void SortQuackMsr(std::vector<Cartridge>& vCar) const;
	 void SortOrigMsr(std::vector<Cartridge>& vCar) const;
};

#endif // !defined(AFX_DATACHAIN_H__0108A325_5755_4826_B203_49A50707E9EF__INCLUDED_)
