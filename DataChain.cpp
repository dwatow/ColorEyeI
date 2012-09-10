// DataChain.cpp: implementation of the CDataChain class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
//#include "ColorEyeI.h"
#include "DataChain.h"
#include <algorithm>

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


void CDataChain::SortQuackMsr(ChainData& vCar) const
{
    std::sort(vCar.begin(), vCar.end(), AreaPriority);
}

void CDataChain::SortOrigMsr(ChainData& vCar) const
{
    std::sort(vCar.begin(), vCar.end(), OrigPriority);
}

void CDataChain::SortQuackMsr()
{
    std::sort(Begin(), End(), AreaPriority);
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
    m_CarChain1.clear();
}

ChainData::size_type CDataChain::StdInit()
{
    m_CarChain1.clear();
    
    Grow(White, Pn1);
    Grow(Red  , Pn1);
    Grow(Green, Pn1);
    Grow(Blue , Pn1);
    Grow(Dark , Pn1);
    
    Grow(White, Pn5);    
    Grow(Red  , Pn5);    
    Grow(Green, Pn5);    
    Grow(Blue , Pn5);    
    Grow(Dark , Pn5);    
    
    Grow(White, Pn9);    
    Grow(Red  , Pn9);    
    Grow(Green, Pn9);    
    Grow(Blue , Pn9);    
    Grow(Dark , Pn9);    
    
    Grow(White, Pn25);    
    Grow(Red  , Pn25);    
    Grow(Green, Pn25);    
    Grow(Blue , Pn25);    
    Grow(Dark , Pn25);    
    
    Grow(White, Pn49);    
    Grow(Red  , Pn49);    
    Grow(Green, Pn49);    
    Grow(Blue , Pn49);    
    Grow(Dark , Pn49);    
    
    Grow(Nits, Pn9);
    
    Grow(CrsTlk , Pn4);
    Grow(CrsTlkW, Pn4);
    Grow(CrsTlkD, Pn4);
    
    //freeBuffer();
    return m_CarChain1.size();
}

void CDataChain::Grow(ColorType ct, PointNum pn)
{
    Bolt* PetriDish;
    PetriDish = new Bolt;
    if (ct == CrsTlk)
    {
        ChainData vCrossTalk;
		
        Cartridge CrsTlk1(CrsTlk, pn);
        Cartridge CrsTlk2(CrsTlkW, pn);
        Cartridge CrsTlk3(CrsTlkD, pn);
		
        PetriDish->Grow(vCrossTalk, CrsTlk1);
        PetriDish->Grow(vCrossTalk, CrsTlk2);
        PetriDish->Grow(vCrossTalk, CrsTlk3);
		
        SortQuackMsr(vCrossTalk);
        m_CarChain1.insert(m_CarChain1.end(), vCrossTalk.begin(), vCrossTalk.end());
    }
    else
    {
        Cartridge MsrItem(ct, pn);
        PetriDish->Grow(m_CarChain1, MsrItem);
    }
 
    delete PetriDish;
}

Cartridge& CDataChain::At(ColorType clr, PointNum Large, UINT Little) 
{
	if(Little > Large)
	{
		AfxMessageBox("CDataChain::At() ERROR!!!");
	    return m_CarChain1.at(0);
	}
	else
		for (ChainData::const_iterator itor = m_CarChain1.begin(); itor != m_CarChain1.end(); ++itor)
			if (itor->GetBackColor()  == clr   && 
				itor->GetMsrFlowNum() == Large && 
				itor->GetMsrFlowNo()  == Little)
				return m_CarChain1.at(abs(itor - m_CarChain1.begin()));
		
	return m_CarChain1.at(0);
}

const Cartridge& CDataChain::At(ColorType clr, PointNum Large, UINT Little) const
{
	if(Little > Large)
	{
		AfxMessageBox("CDataChain::At() ERROR!!!");
		return m_CarChain1.at(0);
	}
	else
		for (ChainData::const_iterator itor = m_CarChain1.begin(); itor != m_CarChain1.end(); ++itor)
			if (itor->GetBackColor()  == clr   && 
				itor->GetMsrFlowNum() == Large && 
				itor->GetMsrFlowNo()  == Little)
				return m_CarChain1.at(abs(itor - m_CarChain1.begin()));
			
			return m_CarChain1.at(0);
}

void CDataChain::Empty()
{
    m_CarChain1.clear();
	Cartridge x;
	m_CarChain1.push_back(x);
}

void CDataChain::RemoveEqualCell(ChainData& compData)
{
    if (!compData.empty())
    {
        ChainData::iterator compItor, removeBeginItor;
		
        for (compItor = compData.begin(); compItor != compData.end(); ++compItor)
        {
            removeBeginItor = std::remove(Begin(), End(), *compItor);
            m_CarChain1.erase(removeBeginItor, End());
        }
    }
}

void CDataChain::RemoveEqualCell(CDataChain& compData)
{
    if (!compData.IsEmpty())//�̭��o�Ǥ��n�ק�A�v�T�A���q��������\��
    {
        //�b�o��m_CarChain1�O�ª�compData�O�s��
        ChainData::iterator compItor, removeBeginItor;

        //remove & cut
        //�b�s���̭��A����ª��A�N�����СA���жq���h����
        for (compItor = compData.Begin(); compItor != compData.End(); ++compItor)
        {
            removeBeginItor = std::remove(Begin(), End(), *compItor);
            m_CarChain1.erase(removeBeginItor, End());
        }

        //�N�ª����b�s���᭱�]���Ū���b�Ĥ@�ӡ^
        //����ܦ��ª����@��
        //��^Omd��
//        vCar.AddChain(vCar.End(), Begin(), itX);
//        Empty();
//          AddChain(End(), vCar.Begin(), vCar.End());
    }
//    ReleaseBuffer();
}
/*

//////////////////////////////////////////////////////////////////////////

ChainData& CDataChain::operator=(const ChainData& vCar)
{
    m_CarChain1 = vCar;
    return m_CarChain1;
}

void CDataChain::freeBuffer()
{
    //�A�Ω��z���nfee���򥻰ѻP�q�����I�C
    //void CColorEyeIDoc::RestructureVector()
    //CDataChain::StdInit()    
    for (ChainData::iterator itor = Begin(); itor != End(); ++itor)
        if (itor->GetArea() == 99 && itor->GetMsrFlowNo() == 99 && itor->GetMsrFlowNum() == NoPn)
            m_CarChain1.erase(itor);
}

void CDataChain::freeZeroCell()
{
    //�A�Ω�InitStd���᦬����Ƨ��A�Afree���S����ƪ�Cell
    //void COmdFile1::iForm()
    ChainData x;
    for (ChainData::iterator itor = Begin(); itor != End(); ++itor)
        if (itor->GetBullet().isAllValueZero())
            x.push_back(*itor);

    RemoveEqualCell(x);
}

void CDataChain::DelCell(const ChainData::size_type index)
{
    ChainData::iterator it = &m_CarChain1.at(index);
    m_CarChain1.erase(it);
}
*/
std::vector<CString> CDataChain::InsideData()
{
    std::vector<CString> vStr;
    CString str1;

    vStr.clear();
    str1.Format("�O�����}    ��l����    �ϰ�X    �I����X    �ĴX�I    �q���I��    Lv    x    y    du    dv    T    Duv    X    Y    Z  Doc:%d\n", m_CarChain1.size());
    vStr.push_back(str1);

    for (ChainData::const_iterator iter = m_CarChain1.begin(); iter != m_CarChain1.end(); ++iter)
    {                  
        CString str;
//         str.Format("%x    %d    %d    %s    %d    %s    %f    %f    %f    %f    %f    %d    %f    %f    %f    %f\n",\
//             iter,                      //�O�����}
//             iter->GetOrigSeqc(),       //��l���� 99 
//             iter->GetArea(),           //�ϰ�X
//             iter->GetStrColorType(),   //�I����X
//             iter->GetMsrFlowNo(),      //�ĴX�I
//             iter->GetStrPointNum(),    //�q���I��
// 
//             iter->GetLv(), 
//             iter->GetSx(), 
//             iter->GetSy(),
//             iter->GetDu(), 
//             iter->GetDv(), 
//             iter->GetT(), 
//             iter->GetDuv(), 
//             iter->GetX(), 
//             iter->GetY(), 
//             iter->GetZ()
//             );

        str.Format("%x    %d    %d    %s    %d    %s    %s    %s    %s    %s    %s    %s    %s    %s    %s    %s\n",\
            iter,                      //�O�����}
            iter->GetOrigSeqc(),       //��l���� 99 
            iter->GetArea(),           //�ϰ�X
            iter->GetStrColorType(),   //�I����X
            iter->GetMsrFlowNo(),      //�ĴX�I
            iter->GetStrPointNum(),    //�q���I��
            
            iter->GetStrLv(), 
            iter->GetStrSx(), 
            iter->GetStrSy(),
            iter->GetStrDu(), 
            iter->GetStrDv(), 
            iter->GetStrT(), 
            iter->GetStrDuv(), 
            iter->GetStrX(), 
            iter->GetStrY(), 
            iter->GetStrZ()
            );

        //AfxMessageBox(iter->GetBullet().MsgBoxStr());

        vStr.push_back(str);
    }
    return vStr;
}