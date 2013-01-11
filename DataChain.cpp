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


void CDataChain::SortQuackMsr(xChain& vCar) const
{
    std::stable_sort(vCar.begin(), vCar.end(), AreaPriority);
}

void CDataChain::SortOrigMsr(xChain& vCar) const
{
    std::stable_sort(vCar.begin(), vCar.end(), OrigPriority);
}

void CDataChain::SortQuackMsr()
{
    std::stable_sort(Begin(), End(), AreaPriority);
}

void CDataChain::SortOrigMsr()
{
    std::stable_sort(Begin(), End(), OrigPriority);
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDataChain::CDataChain(): p_Pusher(0)
{
    Cartridge x;
    m_CarChain1.push_back(x);
}

CDataChain::~CDataChain()
{
    m_CarChain1.clear();
}

xChain::size_type CDataChain::StdInit()
{
//    Empty();    
	 Grow(JND, Pn1);
     Grow(White, Pn1);       Grow(Red  , Pn1);       Grow(Green, Pn1);       Grow(Blue , Pn1);       Grow(Dark , Pn1);
     Grow(Nits, Pn9);
     Grow(White, Pn5);       Grow(Red  , Pn5);       Grow(Green, Pn5);       Grow(Blue , Pn5);       Grow(Dark , Pn5);    
     Grow(White, Pn9);       Grow(Red  , Pn9);       Grow(Green, Pn9);       Grow(Blue , Pn9);       Grow(Dark , Pn9);    
     Grow(White, Pn13);      Grow(Red  , Pn13);      Grow(Green, Pn13);      Grow(Blue , Pn13);      Grow(Dark , Pn13);
     Grow(White, Pn21);      Grow(Red  , Pn21);      Grow(Green, Pn21);      Grow(Blue , Pn21);      Grow(Dark , Pn21);
     Grow(White, Pn25);      Grow(Red  , Pn25);      Grow(Green, Pn25);      Grow(Blue , Pn25);      Grow(Dark , Pn25);
     Grow(White, Pn49);      Grow(Red  , Pn49);      Grow(Green, Pn49);      Grow(Blue , Pn49);      Grow(Dark , Pn49);
     Grow(CrsTlk , Pn4);
    
    //freeBuffer();
    return m_CarChain1.size();
}

void CDataChain::Grow(ColorType ct, PointNum pn)
{
	BOOL delBolt = FALSE;
	if (p_Pusher == 0)
	{
		p_Pusher = new Bolt();
		delBolt = TRUE;
	}
//////////////////////////////////////////////////////////////////////////
    if (ct == CrsTlk)
    {
        xChain vCrossTalk;
        
        Cartridge CrsTlk1(CrsTlk , pn);    p_Pusher->Grow(vCrossTalk, CrsTlk1);
        Cartridge CrsTlk2(CrsTlkW, pn);    p_Pusher->Grow(vCrossTalk, CrsTlk2);
        Cartridge CrsTlk3(CrsTlkD, pn);    p_Pusher->Grow(vCrossTalk, CrsTlk3);
		
        SortQuackMsr(vCrossTalk);
        m_CarChain1.insert(m_CarChain1.end(), vCrossTalk.begin(), vCrossTalk.end());
    }
    else if (ct == JND)
	{
		xChain vJND;
        
        Cartridge JndX(JNDX, pn);
        Cartridge Jnd(JND, pn);
        
        p_Pusher->Grow(vJND, JndX);
        p_Pusher->Grow(vJND, Jnd);
        
        SortQuackMsr(vJND);
        m_CarChain1.insert(m_CarChain1.end(), vJND.begin(), vJND.end());
	}
	else
    {
        Cartridge MsrItem(ct, pn);
        p_Pusher->Grow(m_CarChain1, MsrItem);
    }
//////////////////////////////////////////////////////////////////////////
	if (delBolt == TRUE)
	{
		delete p_Pusher;
		p_Pusher = 0;
	}
}

xChain::size_type CDataChain::GammaInit()
{
    Grow(White, PnGamma);   Grow(Red  , PnGamma);   Grow(Green, PnGamma);   Grow(Blue , PnGamma);   Grow(Dark , PnGamma);
    return m_CarChain1.size();
}


Cartridge& CDataChain::At(ColorType clr, PointNum Large, UINT Little) 
{
    if(Little > (UINT)Large)
    {
        AfxMessageBox("CDataChain::At() ERROR!!!");
        return m_CarChain1.at(0);
    }
    else
        for (xChain::const_iterator itor = m_CarChain1.begin(); itor != m_CarChain1.end(); ++itor)
            if (itor->GetBackColor()  == clr   && 
                itor->GetMsrFlowNum() == Large && 
                itor->GetMsrFlowNo()  == Little)
                return m_CarChain1.at(abs(itor - m_CarChain1.begin()));
        
    return m_CarChain1.at(0);
}

const Cartridge& CDataChain::At(ColorType clr, PointNum Large, UINT Little) const
{
    if(Little > (UINT)Large)
    {
        AfxMessageBox("CDataChain::At() ERROR!!!");
        return m_CarChain1.at(0);
    }
    else
        for (xChain::const_iterator itor = m_CarChain1.begin(); itor != m_CarChain1.end(); ++itor)
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

void CDataChain::CutEqualCell(xChain compData)
{
    if (!compData.empty())
    {
        xChain::iterator compItor, removeBeginItor;
        
        for (compItor = compData.begin(); compItor != compData.end(); ++compItor)
        {
            removeBeginItor = std::remove(Begin(), End(), *compItor);
            m_CarChain1.erase(removeBeginItor, End());
        }
    }
}

void CDataChain::CutEqualCell(CDataChain compData)
{
    if (!compData.IsEmpty())//裡面這些不要修改，影響再次量測的資料擺放
    {
        //在這時m_CarChain1是舊的compData是新的
        xChain::iterator compItor, removeBeginItor;
        //remove & cut 在新的裡面，比對舊的，代表重覆，重覆量測去除掉
         for (compItor = compData.Begin(); compItor != compData.End(); ++compItor)
         {
             removeBeginItor = std::remove(Begin(), End(), *compItor);
             m_CarChain1.erase(removeBeginItor, End());
         }
    }
}

void CDataChain::freeEmptyCell()
{
    //適用於InitStd之後收集資料完，再free掉沒有資料的Cell
    //void COmdFile1::iForm()
    xChain x;
    for (xChain::iterator itor = Begin(); itor != End(); ++itor)
        if (itor->GetBullet().isEmpty())
            x.push_back(*itor);           //要剪掉的

    CutEqualCell(x);
}

//////////////////////////////////////////////////////////////////////////

xChain& CDataChain::operator=(const xChain& vCar)
{
    m_CarChain1 = vCar;
    return m_CarChain1;
}

std::vector<CString> CDataChain::InsideData()
{
    std::vector<CString> vStr;
    CString str1;

    vStr.clear();
    str1.Format("記憶體位址    原始順序    區域碼    背景色碼    第幾點    量測點數    ||    Lv    x    y    du    dv    T    Duv    X    Y    Z  Doc:%d\n", m_CarChain1.size());
    vStr.push_back(str1);

    for (xChain::const_iterator iter = m_CarChain1.begin(); iter != m_CarChain1.end(); ++iter)
    {                  
        CString str;
//         str.Format("%x    %d    %d    %s    %d    %s    %f    %f    %f    %f    %f    %d    %f    %f    %f    %f\n",\
//             iter,                      //記憶體位址
//             iter->GetOrigSeqc(),       //原始順序 99 
//             iter->GetArea(),           //區域碼
//             iter->GetStrColorType(),   //背景色碼
//             iter->GetMsrFlowNo(),      //第幾點
//             iter->GetStrPointNum(),    //量測點數
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

        str.Format("%x    %d    %d    %s    %d    %s   ||    %s    %s    %s    %s    %s    %s    %s    %s    %s    %s\n",\
            iter,                      //記憶體位址
            iter->GetOrigSeqc(),       //原始順序 99 
            iter->GetArea(),           //區域碼
            iter->GetStrColorType(),   //背景色碼
            iter->GetMsrFlowNo(),      //第幾點
            iter->GetStrPointNum(),    //量測點數
            
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
