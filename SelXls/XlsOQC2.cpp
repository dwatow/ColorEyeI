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
CXlsFile2* CXlsOQC2::iNitsLv(CString strNitsLv   ) { SelectSheet(1)->SelectCell("BE", 5+m_ModuleNO)->SetCell(strNitsLv); /*AfxMessageBox(strNitsLv);*/    return this;}
CXlsFile2* CXlsOQC2::iPanelID(CString strPanelID)
{
    SelectSheet(1)->SelectCell('B' , 5+m_ModuleNO)->SetCell(strPanelID);

//     CString BarCode;
//     BarCode.Format("=\'%s\'!B%d", GetSheetName(1), 5+m_ModuleNO);

//     SelectSheet(2)->SelectCell('B', 5+m_ModuleNO)->SetCell(BarCode);  //堵︹25翴
//     SelectSheet(3)->SelectCell('B', 5+m_ModuleNO)->SetCell(BarCode);  //堵︹21翴
//     SelectSheet(4)->SelectCell('B', 5+m_ModuleNO)->SetCell(BarCode);  //フ︹ 9翴
//     SelectSheet(5)->SelectCell('B', 9+m_ModuleNO)->SetCell(BarCode);  //Cross Talk
//     SelectSheet(6)->SelectCell('B', 5+m_ModuleNO)->SetCell(BarCode);  //Color Temperature

    return this;
}
CXlsFile2* CXlsOQC2::iChannel(CString striChannel) { SelectSheet(1)->SelectCell("BL", 5+m_ModuleNO)->SetCell(striChannel);    return this;}
CXlsFile2* CXlsOQC2::iData(CDataChain& vCar)
{
    m_vCar = vCar;

    //礚舼
    if (nMsred(Red   , Pn1))  idR1();
    if (nMsred(Green , Pn1))  idG1();
    if (nMsred(Blue  , Pn1))  idB1();
    if (nMsred(Nits  , Pn9))  idNits();
    if (nMsred(CrsTlk, Pn4))  idCrsTlk();

    //舼
    if (nMsred(Dark , Pn25)) idD25();
    if (nMsred(Dark , Pn21)) idD21();
    if (nMsred(Dark , Pn1))  idD1();

    if (nMsred(White, Pn9))  idW9();
    if (nMsred(White, Pn5))  idW5();
    if (nMsred(White, Pn1))  idW1();

    //ㄤウ
    if (nMsred(Red   , Pn1) && nMsred(Green , Pn1) && nMsred(Blue  , Pn1))
        iColorGamu();
    if (nMsred(White, Pn1))
        iColorTemperature();

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
    str.Format("=O%d", 5+m_ModuleNO);    SelectSheet(1)->SelectCell("AD", 5+m_ModuleNO)->SetCell(str);
    str.Format("=P%d", 5+m_ModuleNO);    SelectSheet(1)->SelectCell("AE", 5+m_ModuleNO)->SetCell(str);

    //单禟娩フ︹翴
    str.Format("=\'%s\'!O%d", GetSheetName(1), 5+m_ModuleNO);    SelectSheet(4)->SelectCell('O', 5+m_ModuleNO)->SetCell(str);
    str.Format("=\'%s\'!P%d", GetSheetName(1), 5+m_ModuleNO);    SelectSheet(4)->SelectCell('P', 5+m_ModuleNO)->SetCell(str);
    str.Format("=\'%s\'!Q%d", GetSheetName(1), 5+m_ModuleNO);    SelectSheet(4)->SelectCell('Q', 5+m_ModuleNO)->SetCell(str);
}

void CXlsOQC2::idW1()
{
    SelectSheet(1);
    SelectCell('O', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn1, 0).GetSx());
    SelectCell('P', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn1, 0).GetSy());
    SelectCell('Q', 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(White, Pn1, 0).GetLv());

    //Color Temperature
    SelectSheet(6);
    SelectCell('C', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn1, 0).GetSx());
    SelectCell('D', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn1, 0).GetSy());

    //单フ︹いみ
    SelectCell("AD", 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn1, 0).GetSx());
    SelectCell("AE", 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn1, 0).GetSy());

    //单禟娩フ︹翴
    SelectSheet(4)->SelectCell('O', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn1, 0).GetSx());
    SelectSheet(4)->SelectCell('P', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn1, 0).GetSy());
    SelectSheet(4)->SelectCell('Q', 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(White, Pn1, 0).GetLv());
}

void CXlsOQC2::idR1()
{
    SelectSheet(1);
    SelectCell("AF", 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(Red, Pn1, 0).GetLv());
    SelectCell("AG", 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(Red, Pn1, 0).GetSx());
    SelectCell("AH", 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(Red, Pn1, 0).GetSy());

    SelectSheet(7);
    switch (m_ModuleNO)
    {
    case 0:     SelectCell("F3")->SetCell("%1.4f", m_vCar.At(Red, Pn1, 0).GetSx());
                SelectCell("G3")->SetCell("%1.4f", m_vCar.At(Red, Pn1, 0).GetSy());        break;
    case 1:     SelectCell("J3")->SetCell("%1.4f", m_vCar.At(Red, Pn1, 0).GetSx());
                SelectCell("K3")->SetCell("%1.4f", m_vCar.At(Red, Pn1, 0).GetSy());        break;
    case 2:     SelectCell("N3")->SetCell("%1.4f", m_vCar.At(Red, Pn1, 0).GetSx());
                SelectCell("O3")->SetCell("%1.4f", m_vCar.At(Red, Pn1, 0).GetSy());        break;

    case 3:     SelectCell("F11")->SetCell("%1.4f", m_vCar.At(Red, Pn1, 0).GetSx());
                SelectCell("G11")->SetCell("%1.4f", m_vCar.At(Red, Pn1, 0).GetSy());    break;
    case 4:     SelectCell("J11")->SetCell("%1.4f", m_vCar.At(Red, Pn1, 0).GetSx());
                SelectCell("K11")->SetCell("%1.4f", m_vCar.At(Red, Pn1, 0).GetSy());    break;
    case 5:     SelectCell("N11")->SetCell("%1.4f", m_vCar.At(Red, Pn1, 0).GetSx());
                SelectCell("O11")->SetCell("%1.4f", m_vCar.At(Red, Pn1, 0).GetSy());    break;
        
    case 6:     SelectCell("F19")->SetCell("%1.4f", m_vCar.At(Red, Pn1, 0).GetSx());
                SelectCell("G19")->SetCell("%1.4f", m_vCar.At(Red, Pn1, 0).GetSy());    break;
    case 7:     SelectCell("J19")->SetCell("%1.4f", m_vCar.At(Red, Pn1, 0).GetSx());
                SelectCell("K19")->SetCell("%1.4f", m_vCar.At(Red, Pn1, 0).GetSy());    break;
    case 8:     SelectCell("N19")->SetCell("%1.4f", m_vCar.At(Red, Pn1, 0).GetSx());
                SelectCell("O19")->SetCell("%1.4f", m_vCar.At(Red, Pn1, 0).GetSy());    break;
        
    case 9:     SelectCell("F27")->SetCell("%1.4f", m_vCar.At(Red, Pn1, 0).GetSx());
                SelectCell("G27")->SetCell("%1.4f", m_vCar.At(Red, Pn1, 0).GetSy());    break;
    }
}

void CXlsOQC2::idG1()
{
    SelectSheet(1);
    SelectCell("AI", 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(Green, Pn1, 0).GetLv());
    SelectCell("AJ", 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(Green, Pn1, 0).GetSx());
    SelectCell("AK", 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(Green, Pn1, 0).GetSy());
 
	SelectSheet(7);
    switch (m_ModuleNO)
    {
    case 0:     SelectCell("F4")->SetCell("%1.4f", m_vCar.At(Green, Pn1, 0).GetSx());
                SelectCell("G4")->SetCell("%1.4f", m_vCar.At(Green, Pn1, 0).GetSy());    break;
    case 1:        SelectCell("J4")->SetCell("%1.4f", m_vCar.At(Green, Pn1, 0).GetSx());
                SelectCell("K4")->SetCell("%1.4f", m_vCar.At(Green, Pn1, 0).GetSy());    break;
    case 2:     SelectCell("N4")->SetCell("%1.4f", m_vCar.At(Green, Pn1, 0).GetSx());
                SelectCell("O4")->SetCell("%1.4f", m_vCar.At(Green, Pn1, 0).GetSy());    break;
        
    case 3:     SelectCell("F12")->SetCell("%1.4f", m_vCar.At(Green, Pn1, 0).GetSx());
                SelectCell("G12")->SetCell("%1.4f", m_vCar.At(Green, Pn1, 0).GetSy());    break;
    case 4:        SelectCell("J12")->SetCell("%1.4f", m_vCar.At(Green, Pn1, 0).GetSx());
                SelectCell("K12")->SetCell("%1.4f", m_vCar.At(Green, Pn1, 0).GetSy());    break;
    case 5:        SelectCell("N12")->SetCell("%1.4f", m_vCar.At(Green, Pn1, 0).GetSx());
                SelectCell("O12")->SetCell("%1.4f", m_vCar.At(Green, Pn1, 0).GetSy());    break;
        
    case 6:     SelectCell("F20")->SetCell("%1.4f", m_vCar.At(Green, Pn1, 0).GetSx());
                SelectCell("G20")->SetCell("%1.4f", m_vCar.At(Green, Pn1, 0).GetSy());    break;
    case 7:     SelectCell("J20")->SetCell("%1.4f", m_vCar.At(Green, Pn1, 0).GetSx());
                SelectCell("K20")->SetCell("%1.4f", m_vCar.At(Green, Pn1, 0).GetSy());    break;
    case 8:     SelectCell("N20")->SetCell("%1.4f", m_vCar.At(Green, Pn1, 0).GetSx());
                SelectCell("O20")->SetCell("%1.4f", m_vCar.At(Green, Pn1, 0).GetSy());    break;
        
    case 9:     SelectCell("F28")->SetCell("%1.4f", m_vCar.At(Green, Pn1, 0).GetSx());
                SelectCell("G28")->SetCell("%1.4f", m_vCar.At(Green, Pn1, 0).GetSy());    break;
    }
}

void CXlsOQC2::idB1()
{
    SelectSheet(1);
    SelectCell("AL", 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(Blue, Pn1, 0).GetLv());
    SelectCell("AM", 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(Blue, Pn1, 0).GetSx());
    SelectCell("AN", 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(Blue, Pn1, 0).GetSy());

    SelectSheet(7);
    switch (m_ModuleNO)
    {
    case 0:     SelectCell("F5")->SetCell("%1.4f", m_vCar.At(Blue, Pn1, 0).GetSx());
                SelectCell("G5")->SetCell("%1.4f", m_vCar.At(Blue, Pn1, 0).GetSy());    break;
    case 1:        SelectCell("J5")->SetCell("%1.4f", m_vCar.At(Blue, Pn1, 0).GetSx());
                SelectCell("K5")->SetCell("%1.4f", m_vCar.At(Blue, Pn1, 0).GetSy());    break;
    case 2:     SelectCell("N5")->SetCell("%1.4f", m_vCar.At(Blue, Pn1, 0).GetSx());
                SelectCell("O5")->SetCell("%1.4f", m_vCar.At(Blue, Pn1, 0).GetSy());    break;
        
    case 3:     SelectCell("F13")->SetCell("%1.4f", m_vCar.At(Blue, Pn1, 0).GetSx());
                SelectCell("G13")->SetCell("%1.4f", m_vCar.At(Blue, Pn1, 0).GetSy());    break;
    case 4:        SelectCell("J13")->SetCell("%1.4f", m_vCar.At(Blue, Pn1, 0).GetSx());
                SelectCell("K13")->SetCell("%1.4f", m_vCar.At(Blue, Pn1, 0).GetSy());    break;
    case 5:        SelectCell("N13")->SetCell("%1.4f", m_vCar.At(Blue, Pn1, 0).GetSx());
                SelectCell("O13")->SetCell("%1.4f", m_vCar.At(Blue, Pn1, 0).GetSy());    break;
        
    case 6:     SelectCell("F21")->SetCell("%1.4f", m_vCar.At(Blue, Pn1, 0).GetSx());
                SelectCell("G21")->SetCell("%1.4f", m_vCar.At(Blue, Pn1, 0).GetSy());    break;
    case 7:     SelectCell("J21")->SetCell("%1.4f", m_vCar.At(Blue, Pn1, 0).GetSx());
                SelectCell("K21")->SetCell("%1.4f", m_vCar.At(Blue, Pn1, 0).GetSy());    break;
    case 8:     SelectCell("N21")->SetCell("%1.4f", m_vCar.At(Blue, Pn1, 0).GetSx());
                SelectCell("O21")->SetCell("%1.4f", m_vCar.At(Blue, Pn1, 0).GetSy());    break;
        
    case 9:     SelectCell("F29")->SetCell("%1.4f", m_vCar.At(Blue, Pn1, 0).GetSx());
                SelectCell("G29")->SetCell("%1.4f", m_vCar.At(Blue, Pn1, 0).GetSy());    break;
    }
}

void CXlsOQC2::idD1()
{
    SelectSheet(1);
    SelectCell("AO", 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(Dark, Pn1, 0).GetLv());
    SelectCell("AP", 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(Dark, Pn1, 0).GetSx());
    SelectCell("AQ", 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(Dark, Pn1, 0).GetSy());
    
    //单D25
    CString str;
    str.Format("=\'%s\'!AO%d", GetSheetName(1), 5+m_ModuleNO);    SelectSheet(2)->SelectCell('R', 5+m_ModuleNO)->SetCell(str);
                                                                SelectSheet(2)->SelectCell('C', 5+m_ModuleNO)->SetCell(str);
    str.Format("=\'%s\'!AP%d", GetSheetName(1), 5+m_ModuleNO);    SelectSheet(2)->SelectCell('D', 5+m_ModuleNO)->SetCell(str);
    str.Format("=\'%s\'!AQ%d", GetSheetName(1), 5+m_ModuleNO);    SelectSheet(2)->SelectCell('E', 5+m_ModuleNO)->SetCell(str);
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

    //いみ翴
    SelectCell('C', 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(Dark, Pn25, 12).GetLv());
    SelectCell('D', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(Dark, Pn25, 12).GetSx());
    SelectCell('E', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(Dark, Pn25, 12).GetSy());

    //单D1
    CString str;
    str.Format("=\'%s\'!C%d", GetSheetName(2), 5+m_ModuleNO);    SelectSheet(1)->SelectCell("AO", 5+m_ModuleNO)->SetCell(str);
    str.Format("=\'%s\'!D%d", GetSheetName(2), 5+m_ModuleNO);    SelectSheet(1)->SelectCell("AP", 5+m_ModuleNO)->SetCell(str);
    str.Format("=\'%s\'!E%d", GetSheetName(2), 5+m_ModuleNO);    SelectSheet(1)->SelectCell("AQ", 5+m_ModuleNO)->SetCell(str);
}

void CXlsOQC2::idW5()
{
    SelectSheet(4);  //禟"禟娩フ︹翴"ぶノ┮⊿Τcover兜ヘ
    //W5(Lv,x,y)
    SelectCell('C',  5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(White, Pn5, 0).GetLv());
    SelectCell('D',  5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn5, 0).GetSx());
    SelectCell('E',  5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn5, 0).GetSy());
    //W5(Lv)
    SelectCell('I',  5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(White, Pn5, 1).GetLv());
    SelectCell('J',  5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn5, 1).GetSx());
    SelectCell('K',  5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn5, 1).GetSy());
    
    SelectCell('O',  5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(White, Pn5, 2).GetLv());  //いみ翴
    SelectCell('P',  5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn5, 2).GetSx());  //いみ翴
    SelectCell('Q',  5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn5, 2).GetSy());  //いみ翴
    
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
    SelectSheet(1);
    SelectCell("AO", 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(Dark, Pn21, 20).GetLv());
    SelectCell("AP", 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(Dark, Pn21, 20).GetSx());
    SelectCell("AQ", 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(Dark, Pn21, 20).GetSy());

//     //单D25
//     SelectSheet(2);
//     //いみ翴
//     SelectCell('C', 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(Dark, Pn21, 20).GetLv());
//     SelectCell('D', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(Dark, Pn21, 20).GetSx());
//     SelectCell('E', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(Dark, Pn21, 20).GetSy());
//     //à
//     SelectCell('T', 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(Dark, Pn21,  0).GetLv());
//     SelectCell('F', 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(Dark, Pn21,  5).GetLv());
//     SelectCell('L', 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(Dark, Pn21, 10).GetLv());
//     SelectCell('Z', 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(Dark, Pn21, 14).GetLv());
}

void CXlsOQC2::idCrsTlk()
{
    SelectSheet(5);
    SelectCell('M', 9+m_ModuleNO)->SetCell("%f", m_vCar.At(CrsTlkW, Pn4, 0).GetLv());
    SelectCell('N', 9+m_ModuleNO)->SetCell("%f", m_vCar.At(CrsTlkW, Pn4, 1).GetLv());
    SelectCell('O', 9+m_ModuleNO)->SetCell("%f", m_vCar.At(CrsTlkW, Pn4, 2).GetLv());
    SelectCell('P', 9+m_ModuleNO)->SetCell("%f", m_vCar.At(CrsTlkW, Pn4, 3).GetLv());

    SelectCell('R', 9+m_ModuleNO)->SetCell("%f", m_vCar.At(CrsTlkD, Pn4, 0).GetLv());
    SelectCell('S', 9+m_ModuleNO)->SetCell("%f", m_vCar.At(CrsTlkD, Pn4, 1).GetLv());
    SelectCell('T', 9+m_ModuleNO)->SetCell("%f", m_vCar.At(CrsTlkD, Pn4, 2).GetLv());
    SelectCell('U', 9+m_ModuleNO)->SetCell("%f", m_vCar.At(CrsTlkD, Pn4, 3).GetLv());

    SelectCell('W', 9+m_ModuleNO)->SetCell("%f", m_vCar.At(CrsTlk , Pn4, 0).GetLv());
    SelectCell('X', 9+m_ModuleNO)->SetCell("%f", m_vCar.At(CrsTlk , Pn4, 1).GetLv());
    SelectCell('Y', 9+m_ModuleNO)->SetCell("%f", m_vCar.At(CrsTlk , Pn4, 2).GetLv());
    SelectCell('Z', 9+m_ModuleNO)->SetCell("%f", m_vCar.At(CrsTlk , Pn4, 3).GetLv());

    SelectCell('E', 9+m_ModuleNO)->SetCell("%f", (SelectCell('R', 9+m_ModuleNO)->GetCell2Double() - SelectCell('W', 9+m_ModuleNO)->GetCell2Double()) / SelectCell('W', 9+m_ModuleNO)->GetCell2Double());
    SelectCell('F', 9+m_ModuleNO)->SetCell("%f", (SelectCell('S', 9+m_ModuleNO)->GetCell2Double() - SelectCell('X', 9+m_ModuleNO)->GetCell2Double()) / SelectCell('X', 9+m_ModuleNO)->GetCell2Double());
    SelectCell('G', 9+m_ModuleNO)->SetCell("%f", (SelectCell('T', 9+m_ModuleNO)->GetCell2Double() - SelectCell('Y', 9+m_ModuleNO)->GetCell2Double()) / SelectCell('Y', 9+m_ModuleNO)->GetCell2Double());
    SelectCell('H', 9+m_ModuleNO)->SetCell("%f", (SelectCell('U', 9+m_ModuleNO)->GetCell2Double() - SelectCell('Z', 9+m_ModuleNO)->GetCell2Double()) / SelectCell('Z', 9+m_ModuleNO)->GetCell2Double());

    SelectCell('I', 9+m_ModuleNO)->SetCell("%f", (SelectCell('M', 9+m_ModuleNO)->GetCell2Double() - SelectCell('W', 9+m_ModuleNO)->GetCell2Double()) / SelectCell('W', 9+m_ModuleNO)->GetCell2Double());
    SelectCell('J', 9+m_ModuleNO)->SetCell("%f", (SelectCell('N', 9+m_ModuleNO)->GetCell2Double() - SelectCell('X', 9+m_ModuleNO)->GetCell2Double()) / SelectCell('X', 9+m_ModuleNO)->GetCell2Double());
    SelectCell('K', 9+m_ModuleNO)->SetCell("%f", (SelectCell('O', 9+m_ModuleNO)->GetCell2Double() - SelectCell('Y', 9+m_ModuleNO)->GetCell2Double()) / SelectCell('Y', 9+m_ModuleNO)->GetCell2Double());
    SelectCell('L', 9+m_ModuleNO)->SetCell("%f", (SelectCell('P', 9+m_ModuleNO)->GetCell2Double() - SelectCell('Z', 9+m_ModuleNO)->GetCell2Double()) / SelectCell('Z', 9+m_ModuleNO)->GetCell2Double());

    SelectCell('M', 9+m_ModuleNO)->ClearCell();
    SelectCell('N', 9+m_ModuleNO)->ClearCell();
    SelectCell('O', 9+m_ModuleNO)->ClearCell();
    SelectCell('P', 9+m_ModuleNO)->ClearCell();
    
    SelectCell('R', 9+m_ModuleNO)->ClearCell();
    SelectCell('S', 9+m_ModuleNO)->ClearCell();
    SelectCell('T', 9+m_ModuleNO)->ClearCell();
    SelectCell('U', 9+m_ModuleNO)->ClearCell();
    
    SelectCell('W', 9+m_ModuleNO)->ClearCell();
    SelectCell('X', 9+m_ModuleNO)->ClearCell();
    SelectCell('Y', 9+m_ModuleNO)->ClearCell();
    SelectCell('Z', 9+m_ModuleNO)->ClearCell();
}

void CXlsOQC2::iColorTemperature()
{
    //眖フ︹いみ翴笲衡ㄓ︹放禟
    SelectSheet(5)->SelectCell('C', 9+m_ModuleNO)->SetCell("%f", SelectSheet(6)->SelectCell('F', 5+m_ModuleNO)->GetCell2Double());
}

void CXlsOQC2::iColorGamu()
{
    SelectSheet(7);
	double CGvalue = 0.0;
    switch (m_ModuleNO)
    {
    case 0:  CGvalue = SelectCell("F7")->GetCell2Double();  break;
    case 1:  CGvalue = SelectCell("J7")->GetCell2Double();  break;
    case 2:  CGvalue = SelectCell("N7")->GetCell2Double();  break;

    case 3:  CGvalue = SelectCell("F15")->GetCell2Double();  break;
    case 4:  CGvalue = SelectCell("J15")->GetCell2Double();  break;
    case 5:  CGvalue = SelectCell("N15")->GetCell2Double();  break;
        
    case 6:  CGvalue = SelectCell("F23")->GetCell2Double();  break;
    case 7:  CGvalue = SelectCell("J23")->GetCell2Double();  break;
    case 8:  CGvalue = SelectCell("N23")->GetCell2Double();  break;
        
    case 9:  CGvalue = SelectCell("F31")->GetCell2Double();  break;
    }

    SelectSheet(5)->SelectCell('D', 9+m_ModuleNO)->SetCell("%f", CGvalue);
}
