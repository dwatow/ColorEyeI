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
CXlsFile2* CXlsOQC2::iPanelID(CString strPanelID)
{
	SelectSheet(1)->SelectCell('B' , 5+m_ModuleNO)->SetCell(strPanelID);

	CString BarCode;
    BarCode.Format("=\'%s\'!B%d", GetSheetName(1), 5+m_ModuleNO);

	SelectSheet(2)->SelectCell('B', 5+m_ModuleNO)->SetCell(BarCode);
	SelectSheet(3)->SelectCell('B', 5+m_ModuleNO)->SetCell(BarCode);

	return this;
}
CXlsFile2* CXlsOQC2::iChannel(CString striChannel) { SelectSheet(1)->SelectCell("BL", 5+m_ModuleNO)->SetCell(striChannel);    return this;}
CXlsFile2* CXlsOQC2::iData(CDataChain& vCar)
{
	m_vCar = vCar;

	idW9();
//	idW1();
	idR1();
	idG1();
    idB1();
    idD1();
	idNits();
   	idD25();
//	idW5();
    return this;
}

void CXlsOQC2::idW9()
{
	SelectSheet(1);
    int i = 0;
    //W9(Lv)(1~8)
    for(i = 0; i < 8; ++i)
	{
		SelectCell((char)('C'+i*3+0), 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn9, i).GetSx());
		SelectCell((char)('C'+i*3+1), 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn9, i).GetSy());
        SelectCell((char)('C'+i*3+2), 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(White, Pn9, i).GetLv());
	}
	SelectCell("AA", 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn9, 8).GetSx());
	SelectCell("AB", 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn9, 8).GetSx());
	SelectCell("AC", 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(White, Pn9, 8).GetLv());
}

void CXlsOQC2::idW1()
{
	SelectSheet(1);
//     SelectCell('L', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn1, 0).GetSx());
//     SelectCell('M', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn1, 0).GetSy());
}

void CXlsOQC2::idR1()
{
	SelectSheet(1);
    SelectCell("AF", 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(Red, Pn1, 0).GetLv());
    SelectCell("AG", 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(Red, Pn1, 0).GetSx());
    SelectCell("AH", 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(Red, Pn1, 0).GetSy());
}

void CXlsOQC2::idG1()
{
	SelectSheet(1);
	SelectCell("AI", 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(Green, Pn1, 0).GetLv());
    SelectCell("AJ", 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(Green, Pn1, 0).GetSx());
    SelectCell("AK", 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(Green, Pn1, 0).GetSy());
}

void CXlsOQC2::idB1()
{
	SelectSheet(1);
    SelectCell("AL", 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(Blue, Pn1, 0).GetLv());
    SelectCell("AM", 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(Blue, Pn1, 0).GetSx());
    SelectCell("AN", 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(Blue, Pn1, 0).GetSy());
}

void CXlsOQC2::idD1()
{
	SelectSheet(1);
    SelectCell("AO", 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(Dark, Pn1, 0).GetLv());
    SelectCell("AP", 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(Dark, Pn1, 0).GetSx());
    SelectCell("AQ", 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(Dark, Pn1, 0).GetSy());
	
	SelectSheet(2);

    SelectCell('D', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(Dark, Pn1, 0).GetSx());
    SelectCell('E', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(Dark, Pn1, 0).GetSy());
}

void CXlsOQC2::idNits()
{
	SelectSheet(1);
	int i;
    for(i=0;i<9;++i)
        SelectCell('A',(char)('R'+i), 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(Nits, Pn9, i).GetLv());

	SelectCell("BB", 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(Nits, Pn9, 4).GetSx());
    SelectCell("BC", 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(Nits, Pn9, 4).GetSy());
}

void CXlsOQC2::idD25()
{
	SelectSheet(2);
	int i;
    for(i=0;i<21;++i)
        SelectCell((char)('F'+i), 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(Dark, Pn25, i).GetLv());
	
    for(i=0;i<4;++i)
        SelectCell('A',(char)('A'+i), 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(Dark, Pn25, i+21).GetLv());
}

void CXlsOQC2::idW5()
{
    SelectSheet(3);
    //W5(Lv,x,y)
    SelectCell('C', 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(White, Pn5, 0).GetLv());
    SelectCell('D', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn5, 0).GetSx());
    SelectCell('E', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn5, 0).GetSy());
    //W5(Lv)
    SelectCell('F', 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(White, Pn5, 1).GetLv());
    SelectCell('G', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn5, 1).GetSx());
    SelectCell('H', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn5, 1).GetSy());
    
    SelectCell('I', 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(White, Pn5, 2).GetLv());
    SelectCell('J', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn5, 2).GetSx());
    SelectCell('K', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn5, 2).GetSy());
    
    SelectCell('L', 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(White, Pn5, 3).GetLv());
    SelectCell('M', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn5, 3).GetSx());
    SelectCell('N', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn5, 3).GetSy());

    SelectCell('O', 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(White, Pn5, 4).GetLv());
    SelectCell('P', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn5, 4).GetSx());
    SelectCell('Q', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn5, 4).GetSy());
}