// DataChain.cpp: implementation of the CDataChain class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ColorEyeI.h"
#include "DataChain.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////////
//sort

bool CDataChain::AreaPriority(const Cartridge &sp1, const Cartridge &sp2)
{
	return (sp1.GetArea() < sp2.GetArea()) ? 1 : 0;
}

bool CDataChain::OrigPriority(const Cartridge &sp1, const Cartridge &sp2)
{
	return (sp1.GetOrigSeqc() < sp2.GetOrigSeqc()) ? 1 : 0;
}


void CDataChain::SortQuackMsr(std::vector<Cartridge>& vCar) const
{
	std::sort(vCar.begin(), vCar.end(), AreaPriority);
}

void CDataChain::SortOrigMsr(std::vector<Cartridge>& vCar) const
{
	std::sort(vCar.begin(), vCar.end(), OrigPriority);
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDataChain::CDataChain()
{
	Cartridge x;
	m_CarChain1.push_back(x);
}

CDataChain::~CDataChain()
{
	Empty();
}

void CDataChain::AddCell(const Cartridge& _X)
{
	m_CarChain1.push_back(_X);
}

std::vector<Cartridge>::iterator CDataChain::Begin()
{
	return m_CarChain1.begin()+1;
}

std::vector<Cartridge>::iterator CDataChain::End()
{
	return m_CarChain1.end();
}

std::vector<Cartridge>::const_iterator CDataChain::cBegin()
{
	return m_CarChain1.begin()+1;
}

std::vector<Cartridge>::const_iterator CDataChain::cEnd()
{
	return m_CarChain1.end();
}

BOOL CDataChain::IsEmpty()
{
	return (BOOL)m_CarChain1.empty();
}

void CDataChain::Empty()
{
	m_CarChain1.clear();
	Cartridge x;
	m_CarChain1.push_back(x);

}

void CDataChain::AddChain(
    std::vector<Cartridge>::iterator _P, 
    std::vector<Cartridge>::const_iterator _F, 
	std::vector<Cartridge>::const_iterator _L)
{
	m_CarChain1.insert(_P, _F, _L);
}

void CDataChain::operator+(const Cartridge& _X)
{
	m_CarChain1.push_back(_X);
}

void CDataChain::operator+(CDataChain& Data)
{	
	m_CarChain1.insert(m_CarChain1.end(), Data.Begin(), Data.End());
}


void CDataChain::RemoveEqualCell(CDataChain& vCar)
{
    if (!vCar.IsEmpty())//裡面這些不要修改，影響再次量測的資料擺放
    {
        //在這時
        //m_CarChain1是舊的
        //vCar是新的
        std::vector<Cartridge>::iterator it2, itX;

        //remove & cut
        //在新的裡面，比對舊的，代表重覆
        //重覆量測去除掉
        for (it2 = vCar.Begin(); it2 != vCar.End(); ++it2)
        {
            itX = std::remove(Begin(), End(), *it2);
            m_CarChain1.erase(itX, End());
        }

        //將舊的掛在新的後面（讓空的放在第一個）
        //整串變成舊的那一串
        //放回Omd檔
        vCar.AddChain(vCar.End(), Begin(), itX);
        Empty();
		AddChain(End(), vCar.Begin(), vCar.End());
    }
	ReleaseBuffer();
}

std::vector<Cartridge>::size_type CDataChain::StdInit()
{
	Empty();
	
	Partition(White, Pn1);
	Partition(Red  , Pn1);
	Partition(Green, Pn1);
	Partition(Blue , Pn1);
	Partition(Dark , Pn1);
	
	Partition(White, Pn5);    
	Partition(Red  , Pn5);    
	Partition(Green, Pn5);    
	Partition(Blue , Pn5);    
	Partition(Dark , Pn5);    
    
	Partition(White, Pn9);    
	Partition(Red  , Pn9);    
	Partition(Green, Pn9);    
	Partition(Blue , Pn9);    
	Partition(Dark , Pn9);    
	
	Partition(White, Pn25);    
	Partition(Red  , Pn25);    
	Partition(Green, Pn25);    
	Partition(Blue , Pn25);    
	Partition(Dark , Pn25);    
    
	Partition(White, Pn49);    
	Partition(Red  , Pn49);    
	Partition(Green, Pn49);    
	Partition(Blue , Pn49);    
	Partition(Dark , Pn49);    
    
	Partition(Nits, Pn9);
	
	Partition(CrsTlk , Pn4);
	Partition(CrsTlkW, Pn4);
    Partition(CrsTlkD, Pn4);
	
	ReleaseBuffer();
	return m_CarChain1.size();
}

void CDataChain::Partition(ColorType ct, PointNum pn)
{
	m_pVectorMaker = new Bolt;
	if (ct == CrsTlk)
	{
		std::vector<Cartridge> vCrossTalk;

		Cartridge CrsTlk1(CrsTlk, pn);
		Cartridge CrsTlk2(CrsTlkW, pn);
		Cartridge CrsTlk3(CrsTlkD, pn);

		m_pVectorMaker->Partition(vCrossTalk, CrsTlk1);
		m_pVectorMaker->Partition(vCrossTalk, CrsTlk2);
		m_pVectorMaker->Partition(vCrossTalk, CrsTlk3);

		SortQuackMsr(vCrossTalk);
		AddChain(End(), vCrossTalk.begin(), vCrossTalk.end());
	}
	else
	{
		Cartridge MsrItem(ct, pn);
	    m_pVectorMaker->Partition(m_CarChain1, MsrItem);
	}
	delete m_pVectorMaker;
}

void CDataChain::SortQuackMsr()
{
	SortQuackMsr(m_CarChain1);
}

Cartridge& CDataChain::At(ColorType clr, PointNum Large, UINT Little)
{
    std::vector<Cartridge>::size_type SubNum = -1;
    for (std::vector<Cartridge>::const_iterator itor = m_CarChain1.begin(); itor != m_CarChain1.end(); ++itor)
    {
        if(itor->GetMsrFlowNum() == Large && itor->GetMsrFlowNo() == Little && itor->GetBackColor() == clr)
            SubNum = itor - m_CarChain1.begin();
    }
    return (m_CarChain1.at((SubNum == -1) ? 0 : SubNum));
}

// Cartridge& CDataChain::operator[](ColorType clr, PointNum Large, UINT Little)
// {
//     return At(ColorType clr, PointNum Large, UINT Little);
// }

std::vector<Cartridge>& CDataChain::operator=(const std::vector<Cartridge>& vCar)
{
	m_CarChain1 = vCar;
	return m_CarChain1;
}

void CDataChain::ReleaseBuffer()
{
    for (std::vector<Cartridge>::iterator itor = Begin(); itor != End(); ++itor)
    {
        if (itor->GetArea()       == 99 && 
			itor->GetMsrFlowNo()  == 99 &&
			itor->GetMsrFlowNum() == NoPn)
            m_CarChain1.erase(itor);
    }
}
