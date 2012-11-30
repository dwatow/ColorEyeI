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
    //SelectCell('A', 5+m_ModuleNO)->SetCell(m_ModuleNO+1);
    return this;
}

//////////////////////////////////////////////////////////////////////////
CXlsFile2* CXlsOQC2::iPanelID(CString strPanelID , std::vector<Cartridge>::size_type ModuleNO){ iCellNO(ModuleNO)->iPanelID(strPanelID);     return this;}
CXlsFile2* CXlsOQC2::iChannel(CString striChannel, std::vector<Cartridge>::size_type ModuleNO){ iCellNO(ModuleNO)->iChannel(striChannel);    return this;}
CXlsFile2* CXlsOQC2::iNitsLv(CString strNitsLv   , std::vector<Cartridge>::size_type ModuleNO){ iCellNO(ModuleNO)->iNitsLv(strNitsLv);       return this;}
CXlsFile2* CXlsOQC2::iData(CDataChain&           , std::vector<Cartridge>::size_type ModuleNO){ iCellNO(ModuleNO)->iData(m_vCar);            return this;}

//////////////////////////////////////////////////////////////////////////
CXlsFile2* CXlsOQC2::iNitsLv(CString strNitsLv   ) { SelectSheet(1)->SelectCell("BE", 5+m_ModuleNO)->SetCell(strNitsLv); AfxMessageBox(strNitsLv);    return this;}
CXlsFile2* CXlsOQC2::iPanelID(CString strPanelID)
{
	SelectSheet(1)->SelectCell('B' , 5+m_ModuleNO)->SetCell(strPanelID);

	CString BarCode;
    BarCode.Format("=\'%s\'!B%d", GetSheetName(1), 5+m_ModuleNO);

	SelectSheet(2)->SelectCell('B', 5+m_ModuleNO)->SetCell(BarCode);
	SelectSheet(3)->SelectCell('B', 5+m_ModuleNO)->SetCell(BarCode);
	SelectSheet(4)->SelectCell('B', 5+m_ModuleNO)->SetCell(BarCode);

	return this;
}
CXlsFile2* CXlsOQC2::iChannel(CString striChannel) { SelectSheet(1)->SelectCell("BL", 5+m_ModuleNO)->SetCell(striChannel);    return this;}
CXlsFile2* CXlsOQC2::iData(CDataChain& vCar)
{
	m_vCar = vCar;

	//礚舼
	if (nMsred(Red  , Pn1))  idR1();
	if (nMsred(Green, Pn1))  idG1();
    if (nMsred(Blue , Pn1))  idB1();
	if (nMsred(Nits , Pn9))  idNits();

	//舼
   	if (nMsred(Dark , Pn25)) idD25();
	if (nMsred(Dark , Pn21)) idD21();
    if (nMsred(Dark , Pn1))  idD1();

	if (nMsred(White, Pn9))  idW9();
	if (nMsred(White, Pn5))  idW5();
	if (nMsred(White, Pn1))  idW1();

	SetVisible(true);
    return this;
}

void CXlsOQC2::idW9()
{
	SelectSheet(1);
    int i(0);
    //W9(Lv)(1~8)
    for(i = 0; i < 8; ++i)
	{
		SelectCell((char)('C'+i*3+0), 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn9, i).GetSx());
		SelectCell((char)('C'+i*3+1), 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn9, i).GetSy());
        SelectCell((char)('C'+i*3+2), 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(White, Pn9, i).GetLv());
	}
	SelectCell("AA", 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn9, 8).GetSx());
	SelectCell("AB", 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn9, 8).GetSy());
	SelectCell("AC", 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(White, Pn9, 8).GetLv());
	
	//单フ︹いみ
	CString str;
	str.Format("=O%d", 5+m_ModuleNO);	SelectSheet(1)->SelectCell("AD", 5+m_ModuleNO)->SetCell(str);
	str.Format("=P%d", 5+m_ModuleNO);	SelectSheet(1)->SelectCell("AE", 5+m_ModuleNO)->SetCell(str);

	//单禟娩フ︹翴
	str.Format("=\'%s\'!O%d", GetSheetName(1), 5+m_ModuleNO);	SelectSheet(3)->SelectCell('O', 5+m_ModuleNO)->SetCell(str);
	str.Format("=\'%s\'!P%d", GetSheetName(1), 5+m_ModuleNO);	SelectSheet(3)->SelectCell('P', 5+m_ModuleNO)->SetCell(str);
	str.Format("=\'%s\'!Q%d", GetSheetName(1), 5+m_ModuleNO);	SelectSheet(3)->SelectCell('Q', 5+m_ModuleNO)->SetCell(str);
}

void CXlsOQC2::idW1()
{
    SelectSheet(1);
	SelectCell('O', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn1, 0).GetSx());
	SelectCell('P', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn1, 0).GetSy());
	SelectCell('Q', 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(White, Pn1, 0).GetLv());

	//单フ︹いみ
	SelectCell("AD", 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn1, 0).GetSx());
	SelectCell("AE", 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn1, 0).GetSy());

	//单禟娩フ︹翴
	SelectSheet(3)->SelectCell('O', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn1, 0).GetSx());
	SelectSheet(3)->SelectCell('P', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn1, 0).GetSy());
	SelectSheet(3)->SelectCell('Q', 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(White, Pn1, 0).GetLv());
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
	
	//单D25
	CString str;
	str.Format("=\'%s\'!AO%d", GetSheetName(1), 5+m_ModuleNO);	SelectSheet(2)->SelectCell('R', 5+m_ModuleNO)->SetCell(str);
	                                                            SelectSheet(2)->SelectCell('C', 5+m_ModuleNO)->SetCell(str);
	str.Format("=\'%s\'!AP%d", GetSheetName(1), 5+m_ModuleNO);	SelectSheet(2)->SelectCell('D', 5+m_ModuleNO)->SetCell(str);
	str.Format("=\'%s\'!AQ%d", GetSheetName(1), 5+m_ModuleNO);	SelectSheet(2)->SelectCell('E', 5+m_ModuleNO)->SetCell(str);
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

	SelectCell('C', 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(Dark, Pn25, 12).GetLv());
	SelectCell('D', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(Dark, Pn25, 12).GetSx());
	SelectCell('E', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(Dark, Pn25, 12).GetSy());

	//单D1
	CString str;
	str.Format("=\'%s\'!C%d", GetSheetName(2), 5+m_ModuleNO);	SelectSheet(1)->SelectCell("AO", 5+m_ModuleNO)->SetCell(str);
	str.Format("=\'%s\'!D%d", GetSheetName(2), 5+m_ModuleNO);	SelectSheet(1)->SelectCell("AP", 5+m_ModuleNO)->SetCell(str);
	str.Format("=\'%s\'!E%d", GetSheetName(2), 5+m_ModuleNO);	SelectSheet(1)->SelectCell("AQ", 5+m_ModuleNO)->SetCell(str);
}

void CXlsOQC2::idW5()
{
    SelectSheet(3);
    //W5(Lv,x,y)
    SelectCell('C',  5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(White, Pn5, 0).GetLv());
    SelectCell('D',  5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn5, 0).GetSx());
    SelectCell('E',  5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn5, 0).GetSy());
    //W5(Lv)
    SelectCell('I',  5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(White, Pn5, 1).GetLv());
    SelectCell('J',  5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn5, 1).GetSx());
    SelectCell('K',  5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn5, 1).GetSy());
    
    SelectCell('O',  5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(White, Pn5, 2).GetLv());
    SelectCell('P',  5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn5, 2).GetSx());
    SelectCell('Q',  5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn5, 2).GetSy());
    
    SelectCell('U',  5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(White, Pn5, 3).GetLv());
    SelectCell('V',  5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn5, 3).GetSx());
    SelectCell('W',  5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn5, 3).GetSy());

    SelectCell("AA", 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(White, Pn5, 4).GetLv());
    SelectCell("AB", 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn5, 4).GetSx());
    SelectCell("AC", 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn5, 4).GetSy());
}

void CXlsOQC2::idD21()
{
	SelectSheet(3);
	int i;
    for(i=0;i<21;++i)
        SelectCell((char)('F'+i), 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(Dark, Pn21, i).GetLv());

//     for(i=0;i<4;++i)
//         SelectCell('A',(char)('A'+i), 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(Dark, Pn25, i+21).GetLv());

	SelectCell('C', 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(Dark, Pn21, 20).GetLv());
	SelectCell('D', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(Dark, Pn21, 20).GetSx());
	SelectCell('E', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(Dark, Pn21, 20).GetSy());

	//单D1
	CString str;
	str.Format("=\'%s\'!C%d", GetSheetName(2), 5+m_ModuleNO);	SelectSheet(1)->SelectCell("AO", 5+m_ModuleNO)->SetCell(str);
	str.Format("=\'%s\'!D%d", GetSheetName(2), 5+m_ModuleNO);	SelectSheet(1)->SelectCell("AP", 5+m_ModuleNO)->SetCell(str);
	str.Format("=\'%s\'!E%d", GetSheetName(2), 5+m_ModuleNO);	SelectSheet(1)->SelectCell("AQ", 5+m_ModuleNO)->SetCell(str);
}