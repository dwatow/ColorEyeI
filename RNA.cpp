// DataChain.cpp: implementation of the RNA class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "RNA.h"
#include <algorithm>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


#ifdef _DEBUG
#define debugCode( code_fragment ) { code_fragment }
#else
#define debugCode( code_fragment )
#endif

//////////////////////////////////////////////////////////////////////////
//sort

bool RNA::areaPriority(const Cartridge2 &sp1, const Cartridge2 &sp2)
{
    return (sp1.GetSqncArea() < sp2.GetSqncArea()) ? 1 : 0;
}

bool RNA::origPriority(const Cartridge2 &sp1, const Cartridge2 &sp2)
{
    return (sp1.GetSqncFrm() < sp2.GetSqncFrm()) ? 1 : 0;
}

// void RNA::SortQuackMsr(std::vector<Cartridge2>& vCar) const
// {
//     std::stable_sort(vCar.begin(), vCar.end(), areaPriority);
// }
// 
// void RNA::SortOrigMsr(std::vector<Cartridge2>& vCar) const
// {
//     std::stable_sort(vCar.begin(), vCar.end(), origPriority);
// }

void RNA::SortQuackMsr()
{
    std::stable_sort(Begin(), End(), areaPriority);
}

void RNA::SortOrigMsr()
{
    std::stable_sort(Begin(), End(), origPriority);
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

RNA::RNA()//: p_Pusher(0)
{
    Cartridge2 x;
    m_CarChain2.push_back(x);
}

RNA::~RNA()
{
    m_CarChain2.clear();
}

// std::vector<Cartridge2>::size_type RNA::StdInit()
// {
//    Empty();    
//      Grow(JND, Pn1);
//      Grow(White, Pn1);       Grow(Red  , Pn1);       Grow(Green, Pn1);       Grow(Blue , Pn1);       Grow(Dark , Pn1);
//      Grow(Nits, Pn9);
//      Grow(White, Pn5);       Grow(Red  , Pn5);       Grow(Green, Pn5);       Grow(Blue , Pn5);       Grow(Dark , Pn5);    
//      Grow(White, Pn9);       Grow(Red  , Pn9);       Grow(Green, Pn9);       Grow(Blue , Pn9);       Grow(Dark , Pn9);    
//      Grow(White, Pn13);      Grow(Red  , Pn13);      Grow(Green, Pn13);      Grow(Blue , Pn13);      Grow(Dark , Pn13);
//      Grow(White, Pn21);      Grow(Red  , Pn21);      Grow(Green, Pn21);      Grow(Blue , Pn21);      Grow(Dark , Pn21);
//      Grow(White, Pn25);      Grow(Red  , Pn25);      Grow(Green, Pn25);      Grow(Blue , Pn25);      Grow(Dark , Pn25);
//      Grow(White, Pn49);      Grow(Red  , Pn49);      Grow(Green, Pn49);      Grow(Blue , Pn49);      Grow(Dark , Pn49);
//      Grow(CrsTlk , Pn4);
    
    //freeBuffer();
//     return m_CarChain2.size();
// }

// void RNA::Grow(ColorType ct, PointNum pn)
// {
//     BOOL delBolt = FALSE;
//     if (p_Pusher == 0)
//     {
//         p_Pusher = new Bolt();
//         delBolt = TRUE;
//     }
// //////////////////////////////////////////////////////////////////////////
//     if (ct == CrsTlk)
//     {
//         std::vector<Cartridge2> vCrossTalk;
//         
//         Cartridge2 CrsTlk1(CrsTlk , pn);    p_Pusher->Grow(vCrossTalk, CrsTlk1);
//         Cartridge2 CrsTlk2(CrsTlkW, pn);    p_Pusher->Grow(vCrossTalk, CrsTlk2);
//         Cartridge2 CrsTlk3(CrsTlkD, pn);    p_Pusher->Grow(vCrossTalk, CrsTlk3);
//         
//         SortQuackMsr(vCrossTalk);
//         m_CarChain2.insert(m_CarChain2.end(), vCrossTalk.begin(), vCrossTalk.end());
//     }
//     else if (ct == JND)
//     {
//         std::vector<Cartridge2> vJND;
//         
//         Cartridge2 JndX(JNDX, pn);
//         Cartridge2 Jnd(JND, pn);
//         
//         p_Pusher->Grow(vJND, JndX);
//         p_Pusher->Grow(vJND, Jnd);
//         
//         SortQuackMsr(vJND);
//         m_CarChain2.insert(m_CarChain2.end(), vJND.begin(), vJND.end());
//     }
//     else
//     {
//         Cartridge2 MsrItem(ct, pn);
//         p_Pusher->Grow(m_CarChain2, MsrItem);
//     }
// //////////////////////////////////////////////////////////////////////////
//     if (delBolt == TRUE)
//     {
//         delete p_Pusher;
//         p_Pusher = 0;
//     }
// }

// std::vector<Cartridge2>::size_type RNA::GammaInit()
// {
//     Grow(White, PnGamma);   Grow(Red  , PnGamma);   Grow(Green, PnGamma);   Grow(Blue , PnGamma);   Grow(Dark , PnGamma);
//     return m_CarChain2.size();
// }

// Cartridge2& RNA::At(Cartridge2 _C2) 
// {
//     for (std::vector<Cartridge2>::iterator itor = m_CarChain2.begin(); itor != m_CarChain2.end(); ++itor)
//         if (_C2 == *itor)
//             return m_CarChain2.at(abs(itor - m_CarChain2.begin()));
//     
//     return m_CarChain2.at(0);
// }

const Cartridge2& RNA::At(const Cartridge2& _C2) const
{
    for (std::vector<Cartridge2>::const_iterator citor = m_CarChain2.begin(); citor != m_CarChain2.end(); ++citor)
        if (_C2 == *citor)
            return m_CarChain2.at(abs(citor - m_CarChain2.begin()));

        return m_CarChain2.at(0);
}

const Cartridge2& RNA::At(const std::vector<Cartridge2>::size_type& _P) const
{ return m_CarChain2.at(_P);   };

// Cartridge2& RNA::At(ColorType clr, PointNum Large, UINT Little) 
// {
//     if(Little > (UINT)Large)
//     {
//         AfxMessageBox("RNA::At() ERROR!!!");
//         return m_CarChain2.at(0);
//     }
//     else
//         for (std::vector<Cartridge2>::const_iterator itor = m_CarChain2.begin(); itor != m_CarChain2.end(); ++itor)
//             if (itor->GetBackColor()  == clr   && 
//                 itor->GetMsrFlowNum() == Large && 
//                 itor->GetMsrFlowNo()  == Little)
//                 return m_CarChain2.at(abs(itor - m_CarChain2.begin()));
//         
//     return m_CarChain2.at(0);
// }
// 
// const Cartridge2& RNA::At(ColorType clr, PointNum Large, UINT Little) const
// {
//     if(Little > (UINT)Large)
//     {
//         AfxMessageBox("RNA::At() ERROR!!!");
//         return m_CarChain2.at(0);
//     }
//     else
//         for (std::vector<Cartridge2>::const_iterator itor = m_CarChain2.begin(); itor != m_CarChain2.end(); ++itor)
//             if (itor->GetBackColor()  == clr   && 
//                 itor->GetMsrFlowNum() == Large && 
//                 itor->GetMsrFlowNo()  == Little)
//                 return m_CarChain2.at(abs(itor - m_CarChain2.begin()));
//             
//             return m_CarChain2.at(0);
// }
float RNA::fFind(const CString& _C, const CString& _P, const CString& _M, const CString& _F, const ValueKind& _V)
{
	return Find(_C, _P, _M, _F).GetBullet().oFlt(_V);
}


CString RNA::sFind(const CString& _C, const CString& _P, const CString& _M, const CString& _F, const ValueKind& _V)
{
	return Find(_C, _P, _M, _F).GetBullet().oStr(_V);
}

std::vector<int>::size_type RNA::HaveSeveral(const CString& color, const CString& ptTotal, const CString& mrIndex, const CString& fePara)
{
	CString clr(color);
	CString ptTtl(ptTotal);
	CString mrIdx(mrIndex);
	CString fePr(fePara);
	
	std::vector<int> vSub;

	if ( finder.ReconstrKeyWord(clr, ptTtl, mrIdx, fePr) )
	{
		for (std::vector<Cartridge2>::iterator itor = m_CarChain2.begin(); itor != m_CarChain2.end(); ++itor)
		{
			if ( (itor->GetDescrip().Find(color) >= 0) && (itor->GetDescrip().Find(ptTtl) >= 0) && 
				 (itor->GetDescrip().Find(mrIdx) >= 0) && (itor->GetDescrip().Find(fePr)  >= 0)  )
				vSub.push_back(itor - m_CarChain2.begin());
		}
	}

	return vSub.size();
}

Cartridge2& RNA::Find(const CString& color, const CString& ptTotal, const CString& mrIndex, const CString& fePara)
{
/*	
將關鍵字切成  1. x色, 2. x點, 3. 第x點, 4. 離邊參數   三個部份
然後重建成三個詞（三個函數）
再進行交集搜尋（試試可以可以使用遞迴）
*/
	CString clr(color);
	CString ptTtl(ptTotal);
	CString mrIdx(mrIndex);
	CString fePr(fePara);

	CString sample;
	std::vector<int> vSub;
	if (finder.Reconstr(clr, ptTtl, mrIdx, fePr))
	{
		sample.Format("%s%s%s%s", clr, ptTtl, mrIdx, fePr);
		for ( std::vector<Cartridge2>::const_iterator itor = m_CarChain2.begin(); itor != m_CarChain2.end(); ++itor)
		{	
			if ( itor->GetDescrip().Find(sample) >= 0 )
			{
				CString debugCharPtr = itor->GetDescrip();
				vSub.push_back(itor - m_CarChain2.begin());
			}
		}
	}

	if (vSub.size() == 1)
		return m_CarChain2.at(vSub.at(0));
	else
		return m_CarChain2.at(0);
}

Cartridge2& RNA::Find(const CString& sample)
{
/*	
將關鍵字切成  1. x色, 2. x點, 3. 第x點, 4. 離邊參數   三個部份
然後重建成三個詞（三個函數）
再進行交集搜尋（試試可以可以使用遞迴）
*/
	CString smple(sample);
	std::vector<int> vSub;
	if (finder.Reconstr(smple))
	{
		for (std::vector<Cartridge2>::const_iterator itor = m_CarChain2.begin(); itor != m_CarChain2.end(); ++itor)
		{	
			//if (sample == itor->GetDescrip())
			if ( itor->GetDescrip().Find(smple) >= 0 )
				vSub.push_back(itor - m_CarChain2.begin());
		}
	}

	if (vSub.size() == 1)
		return m_CarChain2.at(vSub.at(0));
	else
		return m_CarChain2.at(0);
}

const int RNA::reconstrColor(CString& strResult)
{
	int colorName(0);

	//Crosstalk+矩形
	colorName = strResult.Find("Cross");
	if (colorName >= 0)
	{
		strResult.Format("%s", strResult.Mid(colorName, 13));
		return colorName;
	}

	//Nits
	colorName = strResult.Find("Nits");
	if (colorName >= 0)
	{
		strResult.Format("%s", strResult.Mid(colorName, 4));
		return colorName;
	}
	
	//x色
	colorName = strResult.Find("色") - 2;

	if (colorName >= 0)
	{
		strResult.Format("%s", strResult.Mid(colorName, 2));
		return colorName;
	}

	return colorName;
}

const int RNA::reconstrPointNum(CString& strResult)
{ 
	int colorName(0);

	//Gamma
	colorName = strResult.Find("Gamma");
	if (colorName >= 0)
	{
		strResult.Format("%s", strResult.Mid(colorName, 5));
		return colorName;
	}	

	//中心點
	colorName = strResult.Find("中心點");
	if (colorName >= 0)
	{
		strResult.Format("中心點");
		return colorName;
	}
	
	colorName = strResult.Find("1點");
	if (colorName >= 0)
	{
		strResult.Format("中心點");
		return colorName;
	}	

	//數字 點
	const int shift = 2;
	colorName = strResult.Find("點") - (3+shift);
	if (colorName >= 0-(3+shift) && atoi(strResult))
	{
		strResult.Format("%s", strResult.Mid(colorName, 3));
		return colorName;
	}	

	colorName = strResult.Find("點") - (2+shift);
	if (colorName >= 0-(2+shift) && atoi(strResult))
	{
		strResult.Format("%s", strResult.Mid(colorName, 2));
		return colorName;
	}	

	colorName = strResult.Find("點") - (1+shift);
	if (colorName >= 0-(1+shift) && atoi(strResult))
	{
		strResult.Format("%s", strResult.Mid(colorName, 1));
		return colorName;
	}

// 	if (colorName >= 0)
// 		strResult.Format("%s", strResult.Mid(colorName, 2));
	
	return colorName;
}
const int RNA::reconstrMsrNo(CString& strResult)
{
	const int shift = 2;
	int colorName(0);

	colorName = strResult.Find("第") + shift;
	if (colorName >= 0+shift && atoi(strResult.Mid(colorName, 3)))
	{
		strResult.Format("第%s點", strResult.Mid(colorName, 3));
		return colorName;
	}

	colorName = strResult.Find("第") + shift;
	if (colorName >= 0+shift && atoi(strResult.Mid(colorName, 2)))
	{
		strResult.Format("%s", strResult.Mid(colorName, 2));
		return colorName;
	}

	colorName = strResult.Find("第") + shift;
	if (colorName >= 0+shift && atoi(strResult.Mid(colorName, 1)))
	{
		strResult.Format("%s", strResult.Mid(colorName, 1));
		return colorName;
	}

	return colorName;
}


void RNA::Empty()
{
    m_CarChain2.clear();
    Cartridge2 x;
    m_CarChain2.push_back(x);
}

// void RNA::CutEqualCell(std::vector<Cartridge2> compData)
// {
//     if (!compData.empty())
//     {
//         std::vector<Cartridge2>::iterator compItor, removeBeginItor;
//         
//         for (compItor = compData.begin(); compItor != compData.end(); ++compItor)
//         {
//             removeBeginItor = std::remove(Begin(), End(), *compItor);
//             m_CarChain2.erase(removeBeginItor, End());
//         }
//     }
// }

void RNA::CutEqualCell(const RNA& compData)
{
    if (!compData.IsEmpty())//裡面這些不要修改，影響再次量測的資料擺放
    {
        CString str;
        debugLogMaker.Clear();
        //在這時
        //m_CarChain2是舊
        //compData是新的
        std::vector<Cartridge2>::const_iterator rnaitor = 0, compItor;
        debugCode(
            str.Format("Begin: %X, End: %X\n", Begin(), End());
            debugLogMaker.Add(str);

            debugLogMaker.Add("\nRNA原本的位址\n");
				for (rnaitor  = m_CarChain2.begin();
					 rnaitor != m_CarChain2.end(); ++rnaitor)
				{
					str.Format("%X, c(%d, %d, %d), P(%d, %d), status: %s\n",\
						rnaitor,\
						rnaitor->GetBkColor().R(), rnaitor->GetBkColor().G(), rnaitor->GetBkColor().B(),\
						rnaitor->GetPointPosi().x, rnaitor->GetPointPosi().y,\
						rnaitor->GetStrBkStatus()); 
					debugLogMaker.Add(str);
				}

            debugLogMaker.Add("\ncompData的位址\n");
				for (compItor = compData.Begin(); compItor != compData.End(); ++compItor)
				{
					str.Format("%X, c(%d, %d, %d), P(%d, %d), status: %s\n",\
						compItor,\
						compItor->GetBkColor().R(), compItor->GetBkColor().G(), compItor->GetBkColor().B(),\
						compItor->GetPointPosi().x, compItor->GetPointPosi().y,\
						compItor->GetStrBkStatus()); 
					debugLogMaker.Add(str);
				}
        )
        //remove & cut 在新的裡面，比對舊的，代表重覆，重覆量測去除掉
//         removeItor = ;
        debugCode(
            str.Format("\nremoveItor:\n");
            debugLogMaker.Add("\nremoveItor:\n");
        )
        std::vector<Cartridge2>::iterator removeItor(End());
        for (compItor = compData.Begin(); compItor != compData.End(); ++compItor)
        {
            //移動一個元素到最後，就刪掉
            debugCode(
                str.Format("B. %X\n", removeItor);
                debugLogMaker.Add(str);
            )
            //removeItor = std::remove(Begin(), removeItor, *compItor);//確認compData的資料是沒錯的
            removeItor = std::remove(Begin(), removeItor, *compItor);

            debugCode(
                str.Format("A. %x\n", removeItor);
                debugLogMaker.Add(str);
            )
        }
        
        m_CarChain2.erase(removeItor, End());

        debugCode(
            debugLogMaker.Add("\nRNA後來的位址\n");
            for (rnaitor = m_CarChain2.begin();
                 rnaitor != m_CarChain2.end(); ++rnaitor)
            {
                str.Format("%X, c(%d, %d, %d), P(%d, %d), status: %s\n",\
                    rnaitor,\
                    rnaitor->GetBkColor().R(), rnaitor->GetBkColor().G(), rnaitor->GetBkColor().B(),\
                    rnaitor->GetPointPosi().x, rnaitor->GetPointPosi().y,\
					rnaitor->GetStrBkStatus());
                debugLogMaker.Add(str);
            }
        )
    }
	debugLogMaker.Out2File("C://Users//1004066//Desktop//RNA_address.log");
}

void RNA::DeleteEmptyCell()
{
    //適用於InitStd之後收集資料完，再free掉沒有資料的Cell
	RNA x;
    for (std::vector<Cartridge2>::iterator itor = Begin(); itor != End(); ++itor)
	{
        if (itor->GetBullet().IsEmpty() == TRUE)
			x.AddCell(*itor);           //要剪掉的
	}
    //x.push_back(*itor);
	debugFile freeEmpty;
	for (std::vector<Cartridge2>::iterator itorX = x.Begin(); itorX != x.End(); ++itorX)
	{
		freeEmpty.Add(itorX->GetDescrip() + "\n");
	}
	freeEmpty.Out2File("C://Users//1004066//Desktop//freeEmpty.log");

    CutEqualCell(x);
}

//////////////////////////////////////////////////////////////////////////

// std::vector<Cartridge2>& RNA::operator=(const std::vector<Cartridge2>& vCar)
// {
//     m_CarChain2 = vCar;
//     return m_CarChain2;
// }

// std::vector<CString> RNA::InsideData()
// {
//     std::vector<CString> vStr;
//     CString str1;
// 
//     vStr.clear();
//     str1.Format("記憶體位址    原始順序    區域碼    背景色碼    第幾點    量測點數    ||    Lv    x    y    du    dv    T    Duv    X    Y    Z  Doc:%d\n", m_CarChain2.size());
//     vStr.push_back(str1);
// 
//     for (std::vector<Cartridge2>::const_iterator iter = m_CarChain2.begin(); iter != m_CarChain2.end(); ++iter)
//     {                  
//         CString str;
// //         str.Format("%x    %d    %d    %s    %d    %s    %f    %f    %f    %f    %f    %d    %f    %f    %f    %f\n",\
// //             iter,                      //記憶體位址
// //             iter->GetOrigSeqc(),       //原始順序 99 
// //             iter->GetArea(),           //區域碼
// //             iter->GetStrColorType(),   //背景色碼
// //             iter->GetMsrFlowNo(),      //第幾點
// //             iter->GetStrPointNum(),    //量測點數
// // 
// //             iter->GetLv(), 
// //             iter->GetSx(), 
// //             iter->GetSy(),
// //             iter->GetDu(), 
// //             iter->GetDv(), 
// //             iter->GetT(), 
// //             iter->GetDuv(), 
// //             iter->GetX(), 
// //             iter->GetY(), 
// //             iter->GetZ()
// //             );
// 
//         str.Format("%x    %d    %d    %s    %d    %s   ||    %s    %s    %s    %s    %s    %s    %s    %s    %s    %s\n",\
//             iter,                      //記憶體位址
//             iter->GetOrigSeqc(),       //原始順序 99 
//             iter->GetArea(),           //區域碼
//             iter->GetStrColorType(),   //背景色碼
//             iter->GetMsrFlowNo(),      //第幾點
//             iter->GetStrPointNum(),    //量測點數
//             
//             iter->GetStrLv(), 
//             iter->GetStrSx(), 
//             iter->GetStrSy(),
//             iter->GetStrDu(), 
//             iter->GetStrDv(), 
//             iter->GetStrT(), 
//             iter->GetStrDuv(), 
//             iter->GetStrX(), 
//             iter->GetStrY(), 
//             iter->GetStrZ()
//             );
// 
//         //AfxMessageBox(iter->GetBullet().MsgBoxStr());
// 
//         vStr.push_back(str);
//     }
//     return vStr;
// }
