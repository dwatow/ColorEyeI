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
#include "../xMsrPoint/Cartridge.h"
#include "Enum.h"
#include "../xMsrPoint/Bolt.h"


class CDataChain// :public std::vector<Cartridge>
{
 	std::vector<Cartridge> m_CarChain1;
 	std::vector<Cartridge>::iterator m_vitCar;
	Bolt* m_pVectorMaker;

 public:
 	CDataChain();
 	virtual ~CDataChain();
 	void AddCell(const Cartridge&);
 	void AddChain(std::vector<Cartridge>::iterator _P, std::vector<Cartridge>::const_iterator _F, std::vector<Cartridge>::const_iterator _L);
	std::vector<Cartridge>::size_type StdInit();
	void RemoveEqualCell(CDataChain& );
	void Partition(ColorType ct, PointNum pn);
	void QuackMsrSort();
	CString str;
	void ReleaseBuffer();

//Simulator Vector member function
	void Empty(); 
	std::vector<Cartridge>::iterator Begin();
	std::vector<Cartridge>::iterator End();
	std::vector<Cartridge>::const_iterator cBegin();
	std::vector<Cartridge>::const_iterator cEnd();
 	Cartridge At(ColorType, PointNum, UINT ) const;
 	void operator=(const std::vector<Cartridge>&);
	BOOL IsEmpty();
 private:
	 static bool AreaPriority(const Cartridge &sp1, const Cartridge &sp2);
	 static bool OrigPriority(const Cartridge &sp1, const Cartridge &sp2);
	 void QuackMsrSort(std::vector<Cartridge>& vCar) const;
	 void OrigMsrSort(std::vector<Cartridge>& vCar) const;
};

#endif // !defined(AFX_DATACHAIN_H__0108A325_5755_4826_B203_49A50707E9EF__INCLUDED_)
