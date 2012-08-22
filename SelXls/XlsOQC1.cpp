// XlsOQC1.cpp: implementation of the CXlsOQC1 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SelXls.h"
#include "XlsOQC1.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

void CXlsOQC1::InitForm()
{
/* 叫外面的表格 */
}

CXlsOQC1& CXlsOQC1::iCellNO(std::vector<Cartridge>::size_type ModuleNO)
{
    m_ModuleNO = ModuleNO;
    SelectCell('A', 5+m_ModuleNO).SetCell(m_ModuleNO+1);
    return *this;
}

//////////////////////////////////////////////////////////////////////////
CXlsOQC1& CXlsOQC1::iBarCode(CString strPanelID       , std::vector<Cartridge>::size_type ModuleNO){    iCellNO(ModuleNO).iBarCode(strPanelID);     return *this;}
CXlsOQC1& CXlsOQC1::iChannel(CString striChannel      , std::vector<Cartridge>::size_type ModuleNO){    iCellNO(ModuleNO).iChannel(striChannel);    return *this;}
CXlsOQC1& CXlsOQC1::iData(std::vector<Cartridge>& vCar, std::vector<Cartridge>::size_type ModuleNO){    iCellNO(ModuleNO).iData(m_vCar);              return *this;}

//////////////////////////////////////////////////////////////////////////
CXlsOQC1& CXlsOQC1::iBarCode(CString strPanelID)       {    SelectSheet(1).SelectCell('B' , 5+m_ModuleNO).SetCell(strPanelID);     return *this;}
CXlsOQC1& CXlsOQC1::iChannel(CString striChannel)      {    SelectSheet(1).SelectCell("AP", 5+m_ModuleNO).SetCell(striChannel);    return *this;}
CXlsOQC1& CXlsOQC1::iData(std::vector<Cartridge>& vCar)
{
//Step 4.開始設定內容
//-----------------------------------------------------------------------------------------------
//       表格字填完！下面是填入資料！請準備陣列！
//-----------------------------------------------------------------------------------------------
//填入資料
	m_vCar = vCar;
    int i = 0;
	CString str;
    //W9(Lv)
	SelectSheet(1);
    for(i = 0; i < 9; ++i)
        SelectCell('C'+i, 5+m_ModuleNO).SetCell("%3.2f", m_vCar.at(SubNum(White, Pn9, i)).GetLv());
    //W1(x,y)
    SelectCell('L', 5+m_ModuleNO).SetCell("%1.4f", m_vCar.at(SubNum(White, Pn1, 0)).GetSx());
    SelectCell('M', 5+m_ModuleNO).SetCell("%1.4f", m_vCar.at(SubNum(White, Pn1, 0)).GetSy());
	//R1(Lv,x,y)
    SelectCell('N', 5+m_ModuleNO).SetCell("%3.2f", m_vCar.at(SubNum(Red, Pn1, 0)).GetLv());
    SelectCell('O', 5+m_ModuleNO).SetCell("%1.4f", m_vCar.at(SubNum(Red, Pn1, 0)).GetSx());
    SelectCell('P', 5+m_ModuleNO).SetCell("%1.4f", m_vCar.at(SubNum(Red, Pn1, 0)).GetSy());
    //G1(Lv,x,y)
    SelectCell('Q', 5+m_ModuleNO).SetCell("%3.2f", m_vCar.at(SubNum(Green, Pn1, 0)).GetLv());
    SelectCell('R', 5+m_ModuleNO).SetCell("%1.4f", m_vCar.at(SubNum(Green, Pn1, 0)).GetSx());
    SelectCell('S', 5+m_ModuleNO).SetCell("%1.4f", m_vCar.at(SubNum(Green, Pn1, 0)).GetSy());
    //B1(Lv,x,y)
    SelectCell('T', 5+m_ModuleNO).SetCell("%3.2f", m_vCar.at(SubNum(Blue, Pn1, 0)).GetLv());
    SelectCell('U', 5+m_ModuleNO).SetCell("%1.4f", m_vCar.at(SubNum(Blue, Pn1, 0)).GetSx());
    SelectCell('V', 5+m_ModuleNO).SetCell("%1.4f", m_vCar.at(SubNum(Blue, Pn1, 0)).GetSy());
    //D1(Lv,x,y)
    SelectCell('W', 5+m_ModuleNO).SetCell("%3.2f", m_vCar.at(SubNum(Dark, Pn1, 0)).GetLv());
    SelectCell('X', 5+m_ModuleNO).SetCell("%1.4f", m_vCar.at(SubNum(Dark, Pn1, 0)).GetSx());
    SelectCell('Y', 5+m_ModuleNO).SetCell("%1.4f", m_vCar.at(SubNum(Dark, Pn1, 0)).GetSy());
    //5nits(Lv)
    SelectCell('Z', 5+m_ModuleNO).SetCell("%3.2f", m_vCar.at(SubNum(Nits, Pn9, 0)).GetLv());

    for(i=0;i<8;++i)
        SelectCell('A','A'+i, 5+m_ModuleNO).SetCell("%3.2f", m_vCar.at(SubNum(Nits, Pn9, i+1)).GetLv());

    //5nits(x,y)
    SelectCell('A','J', 5+m_ModuleNO).SetCell("%1.4f", m_vCar.at(SubNum(Nits, Pn9, 4)).GetSx());
    SelectCell('A','K', 5+m_ModuleNO).SetCell("%1.4f", m_vCar.at(SubNum(Nits, Pn9, 4)).GetSy());
    
    //SPD Board編號
//    SelectCell('A','N', 5+m_ModuleNO).SetCell(m_vCar.at(SubNum(DriverDevice);
//    if(m_vCar.at(SubNum(Current) //電流
//        SelectCell('A','O', 5+m_ModuleNO).SetCell(m_vCar.at(SubNum(Current);
//    if(m_vCar.at(SubNum(ChannelNO) //CH
//    if(m_vCar.at(SubNum(WorkNum)
//        SelectCell('A','Q', 5+m_ModuleNO).SetCell(m_vCar.at(SubNum(WorkNum);

//Step 3.設定Sheet2
    //Bar Code
    CString BarCode;
    BarCode.Format("=\'%s\'!B%d", GetSheetName(1), 5+m_ModuleNO);

    SelectSheet(2).SelectCell('B', 5+m_ModuleNO).SetCell(BarCode);
    //D1(Lv,x,y)
    SelectCell('C', 5+m_ModuleNO).SetCell("%3.2f", m_vCar.at(SubNum(Dark, Pn1, 0)).GetLv());
    SelectCell('D', 5+m_ModuleNO).SetCell("%1.4f", m_vCar.at(SubNum(Dark, Pn1, 0)).GetSx());
    SelectCell('E', 5+m_ModuleNO).SetCell("%1.4f", m_vCar.at(SubNum(Dark, Pn1, 0)).GetSy());
    //D25(Lv)
    for(i=0;i<21;++i)
        SelectCell('F'+i, 5+m_ModuleNO).SetCell("%3.2f", m_vCar.at(SubNum(Dark, Pn25, i)).GetLv());

    for(i=0;i<4;++i)
    
    //    CString temp;
    //    temp.Format("OQC_Date[%d].d25[%d].GetLv() = %f\nOQC_Date[%d].d25[%d].GetLv() = %f", Tai, i+21,m_vCar.at(SubNum(d25[i+21].GetLv(), Tai, i+21,m_vCar.at(SubNum(d25[i].GetLv());
    //    MessageBox(temp);
        SelectCell('A','A'+i, 5+m_ModuleNO).SetCell("%3.2f", m_vCar.at(SubNum(Dark, Pn25, i+21)).GetLv());

    //Step 4.設定Sheet3
//	CopySheet(3);
    SelectSheet(3).SelectCell('B', 5+m_ModuleNO).SetCell(BarCode);
    //W5(Lv,x,y)
    SelectCell('C', 5+m_ModuleNO).SetCell("%3.2f", m_vCar.at(SubNum(White, Pn5, 0)).GetLv());
    SelectCell('D', 5+m_ModuleNO).SetCell("%1.4f", m_vCar.at(SubNum(White, Pn5, 0)).GetSx());
    SelectCell('E', 5+m_ModuleNO).SetCell("%1.4f", m_vCar.at(SubNum(White, Pn5, 0)).GetSy());
    //W5(Lv)
    SelectCell('F', 5+m_ModuleNO).SetCell("%3.2f", m_vCar.at(SubNum(White, Pn5, 1)).GetLv());
    SelectCell('G', 5+m_ModuleNO).SetCell("%1.4f", m_vCar.at(SubNum(White, Pn5, 1)).GetSx());
    SelectCell('H', 5+m_ModuleNO).SetCell("%1.4f", m_vCar.at(SubNum(White, Pn5, 1)).GetSy());
    
    SelectCell('I', 5+m_ModuleNO).SetCell("%3.2f", m_vCar.at(SubNum(White, Pn5, 2)).GetLv());
    SelectCell('J', 5+m_ModuleNO).SetCell("%1.4f", m_vCar.at(SubNum(White, Pn5, 2)).GetSx());
    SelectCell('K', 5+m_ModuleNO).SetCell("%1.4f", m_vCar.at(SubNum(White, Pn5, 2)).GetSy());
    
    SelectCell('L', 5+m_ModuleNO).SetCell("%3.2f", m_vCar.at(SubNum(White, Pn5, 3)).GetLv());
    SelectCell('M', 5+m_ModuleNO).SetCell("%1.4f", m_vCar.at(SubNum(White, Pn5, 3)).GetSx());
    SelectCell('N', 5+m_ModuleNO).SetCell("%1.4f", m_vCar.at(SubNum(White, Pn5, 3)).GetSy());

    SelectCell('O', 5+m_ModuleNO).SetCell("%3.2f", m_vCar.at(SubNum(White, Pn5, 4)).GetLv());
    SelectCell('P', 5+m_ModuleNO).SetCell("%1.4f", m_vCar.at(SubNum(White, Pn5, 4)).GetSx());
    SelectCell('Q', 5+m_ModuleNO).SetCell("%1.4f", m_vCar.at(SubNum(White, Pn5, 4)).GetSy());

//    SetVisible(TRUE);    

    return *this;
}

// std::vector<Cartridge> CXlsOQC1::oData()
// {
//     std::vector<Cartridge> a;
//     Cartridge x;
//     a.push_back(x);
//     return a;
// }
