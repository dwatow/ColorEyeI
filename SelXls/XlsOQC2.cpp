// XlsOQC1.cpp: implementation of the CXlsOQC2 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SelXls.h"
#include "XlsOQC2.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CXlsFile2* CXlsOQC2::iCellNO(std::vector<Cartridge>::size_type ModuleNO)
{
    m_ModuleNO = ModuleNO;
    SelectCell('A', 5+m_ModuleNO)->SetCell(m_ModuleNO+1);
    return this;
}

//////////////////////////////////////////////////////////////////////////
CXlsFile2* CXlsOQC2::iPanelID(CString strPanelID , std::vector<Cartridge>::size_type ModuleNO){ iCellNO(ModuleNO)->iPanelID(strPanelID);     return this;}
CXlsFile2* CXlsOQC2::iChannel(CString striChannel, std::vector<Cartridge>::size_type ModuleNO){ iCellNO(ModuleNO)->iChannel(striChannel);    return this;}
CXlsFile2* CXlsOQC2::iData(CDataChain&           , std::vector<Cartridge>::size_type ModuleNO){ iCellNO(ModuleNO)->iData(m_vCar);            return this;}

//////////////////////////////////////////////////////////////////////////
CXlsFile2* CXlsOQC2::iPanelID(CString strPanelID)  { SelectSheet(1)->SelectCell('B' , 5+m_ModuleNO)->SetCell(strPanelID);     return this;}
CXlsFile2* CXlsOQC2::iChannel(CString striChannel) { SelectSheet(1)->SelectCell("BL", 5+m_ModuleNO)->SetCell(striChannel);    return this;}
CXlsFile2* CXlsOQC2::iData(CDataChain& vCar)
{
//Step 4.開始設定內容
//-----------------------------------------------------------------------------------------------
//       表格字填完！下面是填入資料！請準備陣列！
//-----------------------------------------------------------------------------------------------
//填入資料
	m_vCar = vCar;
    int i = 0;
	CString str;
    //W9(Lv)(1~8)
	SelectSheet(1);
    for(i = 0; i < 8; ++i)
	{
		SelectCell((char)('C'+i*3+0), 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn9, i).GetSx());
		SelectCell((char)('C'+i*3+1), 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn9, i).GetSy());
        SelectCell((char)('C'+i*3+2), 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(White, Pn9, i).GetLv());
	}
	//W9(Lv)(1~8)
	SelectCell("AA", 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn9, 8).GetSx());
	SelectCell("AB", 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn9, 8).GetSx());
	SelectCell("AC", 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(White, Pn9, 8).GetLv());

    //W1(x,y)
//     SelectCell('L', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn1, 0).GetSx());
//     SelectCell('M', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn1, 0).GetSy());
	//R1(Lv,x,y)
    SelectCell("AF", 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(Red, Pn1, 0).GetLv());
    SelectCell("AG", 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(Red, Pn1, 0).GetSx());
    SelectCell("AH", 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(Red, Pn1, 0).GetSy());
    //G1(Lv,x,y)
    SelectCell("AI", 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(Green, Pn1, 0).GetLv());
    SelectCell("AJ", 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(Green, Pn1, 0).GetSx());
    SelectCell("AK", 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(Green, Pn1, 0).GetSy());
    //B1(Lv,x,y)
    SelectCell("AL", 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(Blue, Pn1, 0).GetLv());
    SelectCell("AM", 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(Blue, Pn1, 0).GetSx());
    SelectCell("AN", 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(Blue, Pn1, 0).GetSy());
    //D1(Lv,x,y)
    SelectCell("AO", 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(Dark, Pn1, 0).GetLv());
    SelectCell("AP", 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(Dark, Pn1, 0).GetSx());
    SelectCell("AQ", 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(Dark, Pn1, 0).GetSy());
    //5nits(Lv)
//     SelectCell('Z', 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(Nits, Pn9, 0).GetLv());
    for(i=0;i<9;++i)
        SelectCell('A',(char)('R'+i), 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(Nits, Pn9, i).GetLv());

    //5nits(x,y)
    SelectCell("BB", 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(Nits, Pn9, 4).GetSx());
    SelectCell("BC", 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(Nits, Pn9, 4).GetSy());
    
	//Bar Code 的公式
    CString BarCode;
    BarCode.Format("=\'%s\'!B%d", GetSheetName(1), 5+m_ModuleNO);
	//////////////////////////////////////////////////////////////////////////
    SelectSheet(2)->SelectCell('B', 5+m_ModuleNO)->SetCell(BarCode);
    //D1(Lv,x,y)
 //   SelectCell('C', 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(Dark, Pn1, 0).GetLv());
    SelectCell('D', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(Dark, Pn1, 0).GetSx());
    SelectCell('E', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(Dark, Pn1, 0).GetSy());
    //D25(Lv)
    for(i=0;i<21;++i)
        SelectCell((char)('F'+i), 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(Dark, Pn25, i).GetLv());

    for(i=0;i<4;++i)
        SelectCell('A',(char)('A'+i), 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(Dark, Pn25, i+21).GetLv());

	//////////////////////////////////////////////////////////////////////////
    //Step 4.設定Sheet3
//     SelectSheet(3)->SelectCell('B', 5+m_ModuleNO)->SetCell(BarCode);
//     //W5(Lv,x,y)
//     SelectCell('C', 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(White, Pn5, 0).GetLv());
//     SelectCell('D', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn5, 0).GetSx());
//     SelectCell('E', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn5, 0).GetSy());
//     //W5(Lv)
//     SelectCell('F', 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(White, Pn5, 1).GetLv());
//     SelectCell('G', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn5, 1).GetSx());
//     SelectCell('H', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn5, 1).GetSy());
//     
//     SelectCell('I', 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(White, Pn5, 2).GetLv());
//     SelectCell('J', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn5, 2).GetSx());
//     SelectCell('K', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn5, 2).GetSy());
//     
//     SelectCell('L', 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(White, Pn5, 3).GetLv());
//     SelectCell('M', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn5, 3).GetSx());
//     SelectCell('N', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn5, 3).GetSy());
// 
//     SelectCell('O', 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(White, Pn5, 4).GetLv());
//     SelectCell('P', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn5, 4).GetSx());
//     SelectCell('Q', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn5, 4).GetSy());

    return this;
}


