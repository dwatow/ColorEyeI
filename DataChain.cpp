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
    
    //freeBuffer();
    return m_CarChain1.size();
}

void CDataChain::Partition(ColorType ct, PointNum pn)
{
    Bolt* pVectorMaker;
    pVectorMaker = new Bolt;
    if (ct == CrsTlk)
    {
        ChainData vCrossTalk;
		
        Cartridge CrsTlk1(CrsTlk, pn);
        Cartridge CrsTlk2(CrsTlkW, pn);
        Cartridge CrsTlk3(CrsTlkD, pn);
		
        pVectorMaker->Partition(vCrossTalk, CrsTlk1);
        pVectorMaker->Partition(vCrossTalk, CrsTlk2);
        pVectorMaker->Partition(vCrossTalk, CrsTlk3);
		
        SortQuackMsr(vCrossTalk);
        m_CarChain1.insert(m_CarChain1.end(), vCrossTalk.begin(), vCrossTalk.end());
    }
    else
    {
        Cartridge MsrItem(ct, pn);
        pVectorMaker->Partition(m_CarChain1, MsrItem);
    }
 
    delete pVectorMaker;
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


/*

void CDataChain::RemoveEqualCell(ChainData& vCar)
{
    if (!vCar.empty())
    {
        ChainData::iterator it2, itX;

        for (it2 = vCar.begin(); it2 != vCar.end(); ++it2)
        {
            itX = std::remove(Begin(), End(), *it2);
            m_CarChain1.erase(itX, End());
        }

    }
}
void CDataChain::RemoveEqualCell(CDataChain& vCar)
{
    if (!vCar.IsEmpty())//�̭��o�Ǥ��n�ק�A�v�T�A���q��������\��
    {
        //�b�o��
        //m_CarChain1�O�ª�
        //vCar�O�s��
        ChainData::iterator it2, itX;

        //remove & cut
        //�b�s���̭��A����ª��A�N����
        //���жq���h����
        for (it2 = vCar.Begin(); it2 != vCar.End(); ++it2)
        {
            itX = std::remove(Begin(), End(), *it2);
            m_CarChain1.erase(itX, End());
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



Cartridge CDataChain::At(ChainData::size_type index)
{
    
}

//////////////////////////////////////////////////////////////////////////

// Cartridge& CDataChain::operator[](ColorType clr, PointNum Large, UINT Little)
// {
//     return At(ColorType clr, PointNum Large, UINT Little);
// }

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
