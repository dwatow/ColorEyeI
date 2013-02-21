// DataChain.cpp: implementation of the RNA class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
//#include "ColorEyeI.h"
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

// bool RNA::AreaPriority(const Cartridge2 &sp1, const Cartridge2 &sp2)
// {
//     return (sp1.getSqncArea() < sp2.getSqncArea()) ? 1 : 0;
// }
// 
// bool RNA::OrigPriority(const Cartridge2 &sp1, const Cartridge2 &sp2)
// {
//     return (sp1.getSqncFrm() < sp2.getSqncFrm()) ? 1 : 0;
// }


// void RNA::SortQuackMsr(std::vector<Cartridge2>& vCar) const
// {
//     std::stable_sort(vCar.begin(), vCar.end(), AreaPriority);
// }
// 
// void RNA::SortOrigMsr(std::vector<Cartridge2>& vCar) const
// {
//     std::stable_sort(vCar.begin(), vCar.end(), OrigPriority);
// }
// 
// void RNA::SortQuackMsr()
// {
//     std::stable_sort(Begin(), End(), AreaPriority);
// }
// 
// void RNA::SortOrigMsr()
// {
//     std::stable_sort(Begin(), End(), OrigPriority);
// }

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

const Cartridge2& RNA::At(Cartridge2 _C2) const
{
    for (std::vector<Cartridge2>::const_iterator citor = m_CarChain2.begin(); citor != m_CarChain2.end(); ++citor)
        if (_C2 == *citor)
            return m_CarChain2.at(abs(citor - m_CarChain2.begin()));

        return m_CarChain2.at(0);
}

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

void RNA::CutEqualCell(RNA compData)
{
    if (!compData.IsEmpty())//裡面這些不要修改，影響再次量測的資料擺放
    {
        CString str;
        debugCode(
            m_dTxt.clear();
        )
        //在這時
        //m_CarChain2是舊
        //compData是新的
        std::vector<Cartridge2>::iterator rnaitor = 0;
        std::vector<Cartridge2>::iterator compItor, removeItor;
        debugCode(
            str.Format("Begin: %X, End: %X\n", Begin(), End());
            m_dTxt.push_back(str);
            m_dTxt.push_back("\nRNA原本的位址\n");

            for (rnaitor  = m_CarChain2.begin();
                 rnaitor != m_CarChain2.end(); ++rnaitor)
            {
                str.Format("%X, c(%d, %d, %d), P(%d, %d)\n",\
                    rnaitor,\
                    GetRValue(rnaitor->GetBkColor()), GetGValue(rnaitor->GetBkColor()), GetBValue(rnaitor->GetBkColor()),\
                    rnaitor->GetPointPosi().x, rnaitor->GetPointPosi().y); 
                m_dTxt.push_back(str);
            }

            m_dTxt.push_back("\ncompData的位址\n");
            for (compItor = compData.Begin(); compItor != compData.End(); ++compItor)
            {
                str.Format("%X, c(%d, %d, %d), P(%d, %d)\n",\
                    compItor,\
                    GetRValue(compItor->GetBkColor()), GetGValue(compItor->GetBkColor()), GetBValue(compItor->GetBkColor()),\
                    compItor->GetPointPosi().x, compItor->GetPointPosi().y); 
                m_dTxt.push_back(str);
            }
        )
        //remove & cut 在新的裡面，比對舊的，代表重覆，重覆量測去除掉
        removeItor = End();
        debugCode(
            str.Format("\nremoveItor:\n");
            m_dTxt.push_back(str);
        )
        for (compItor = compData.Begin(); compItor != compData.End(); ++compItor)
        {
            //移動一個元素到最後，就刪掉
            debugCode(
                str.Format("B. %X\n", removeItor);
                m_dTxt.push_back(str);
            )
            //removeItor = std::remove(Begin(), removeItor, *compItor);//確認compData的資料是沒錯的
            removeItor = std::remove(Begin(), removeItor, *compItor);

            debugCode(
                str.Format("A. %x\n", removeItor);
                m_dTxt.push_back(str);
                )
        //m_CarChain2.erase(removeItor, End());
        }
        
        m_CarChain2.erase(removeItor, End());
        
        debugCode(
            m_dTxt.push_back("\nRNA後來的位址\n");
            
            for (rnaitor  = m_CarChain2.begin();
            rnaitor != m_CarChain2.end(); ++rnaitor)
            {
                str.Format("%X, c(%d, %d, %d), P(%d, %d)\n",\
                    rnaitor,\
                    GetRValue(rnaitor->GetBkColor()), GetGValue(rnaitor->GetBkColor()), GetBValue(rnaitor->GetBkColor()),\
                    rnaitor->GetPointPosi().x, rnaitor->GetPointPosi().y); 
                m_dTxt.push_back(str);
            }
        )
    }
    debugCode(
        CTxtFile fTxt;
        CFileException fx;
        fTxt.Save("C://Users//1004066//Desktop//RNA_address.log", fx);
        fTxt.iTxtData(m_dTxt);
        fTxt.Close();
    )

}

// void RNA::freeEmptyCell()
// {
//     //適用於InitStd之後收集資料完，再free掉沒有資料的Cell
//     //void COmdFile1::iForm()
//     std::vector<Cartridge2> x;
//     for (std::vector<Cartridge2>::iterator itor = Begin(); itor != End(); ++itor)
//         if (itor->GetBullet().isEmpty())
//             x.push_back(*itor);           //要剪掉的
// 
//     CutEqualCell(x);
// }

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
