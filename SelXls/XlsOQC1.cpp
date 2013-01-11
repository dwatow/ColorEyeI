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

CXlsFile2* CXlsOQC1::iCellNO(std::vector<Cartridge>::size_type ModuleNO)
{
    m_ModuleNO = ModuleNO;
//    SelectCell('A', 5+m_ModuleNO)->SetCell(m_ModuleNO+1);
    return this;
}

//////////////////////////////////////////////////////////////////////////
CXlsFile2* CXlsOQC1::iPanelID(CString strPanelID , std::vector<Cartridge>::size_type ModuleNO){ iCellNO(ModuleNO)->iPanelID(strPanelID);     return this;}
CXlsFile2* CXlsOQC1::iChannel(CString striChannel, std::vector<Cartridge>::size_type ModuleNO){ iCellNO(ModuleNO)->iChannel(striChannel);    return this;}
CXlsFile2* CXlsOQC1::iNitsLv(CString strNitsLv   , std::vector<Cartridge>::size_type ModuleNO){ iCellNO(ModuleNO)->iNitsLv(strNitsLv);       return this;}
CXlsFile2* CXlsOQC1::iData(CDataChain&           , std::vector<Cartridge>::size_type ModuleNO){ iCellNO(ModuleNO)->iData(m_vCar);            return this;}

//////////////////////////////////////////////////////////////////////////
CXlsFile2* CXlsOQC1::iNitsLv(CString strNitsLv   ) { SelectSheet(1)->SelectCell("BE", 5+m_ModuleNO)->SetCell(strNitsLv); /*AfxMessageBox(strNitsLv);*/    return this;}
CXlsFile2* CXlsOQC1::iPanelID(CString strPanelID)
{
    SelectSheet(1)->SelectCell('B' , 5+m_ModuleNO)->SetCell(strPanelID);
    return this;
}

CXlsFile2* CXlsOQC1::iChannel(CString striChannel) { SelectSheet(1)->SelectCell("AP", 5+m_ModuleNO)->SetCell(striChannel);    return this;}
CXlsFile2* CXlsOQC1::iData(CDataChain& vCar)
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

void CXlsOQC1::idW9()
{
    SelectSheet(1);
    for(int i = 0; i < 9; ++i)
        SelectCell((char)('C'+i), 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(White, Pn9, i).GetLv());

	CString Lv, Sx, Sy;
	Lv.Format("%3.2f", m_vCar.At(White, Pn9, 5).GetLv());
	Sx.Format("%1.4f", m_vCar.At(White, Pn9, 5).GetSx());
	Sy.Format("%1.4f", m_vCar.At(White, Pn9, 5).GetSy());

	//单フ︹いみ
    SelectSheet(1);
    SelectCell("L", 5+m_ModuleNO)->SetCell(Sx);
    SelectCell("M", 5+m_ModuleNO)->SetCell(Sy);
    
    //单禟娩フ︹5翴 いみ翴
    SelectSheet(3);
    SelectCell('I', 5+m_ModuleNO)->SetCell(Sx);
    SelectCell('J', 5+m_ModuleNO)->SetCell(Sy);
    SelectCell('K', 5+m_ModuleNO)->SetCell(Lv);

    //Color Temperature
    SelectSheet(7);
    SelectCell('C', 5+m_ModuleNO)->SetCell(Sx);
    SelectCell('D', 5+m_ModuleNO)->SetCell(Sy);
}

void CXlsOQC1::idW5()
{
    //W5(Lv,x,y)
    SelectSheet(3);
    SelectCell('C', 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(White, Pn5, 0).GetLv());
    SelectCell('D', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn5, 0).GetSx());
    SelectCell('E', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(White, Pn5, 0).GetSy());
	
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
	
	CString Lv, Sx, Sy;
	Lv.Format("%3.2f", m_vCar.At(White, Pn5, 2).GetLv());
	Sx.Format("%1.4f", m_vCar.At(White, Pn5, 2).GetSx());
	Sy.Format("%1.4f", m_vCar.At(White, Pn5, 2).GetSy());
	
	//单フ︹いみ
    SelectSheet(1);
    SelectCell("L", 5+m_ModuleNO)->SetCell(Sx);
    SelectCell("M", 5+m_ModuleNO)->SetCell(Sy);

	//单瞒娩フ︹9翴
    SelectSheet(1);
    SelectCell('G', 5+m_ModuleNO)->SetCell(Lv);
	
    //Color Temperature
    SelectSheet(7);
    SelectCell('C', 5+m_ModuleNO)->SetCell(Sx);
    SelectCell('D', 5+m_ModuleNO)->SetCell(Sy);
}

void CXlsOQC1::idW1()
{
	CString Lv, Sx, Sy;
	Lv.Format("%3.2f", m_vCar.At(White, Pn1, 0).GetLv());
	Sx.Format("%1.4f", m_vCar.At(White, Pn1, 0).GetSx());
	Sy.Format("%1.4f", m_vCar.At(White, Pn1, 0).GetSy());

    SelectSheet(1);
    SelectCell('L', 5+m_ModuleNO)->SetCell(Sx);
    SelectCell('M', 5+m_ModuleNO)->SetCell(Sy);
    SelectCell('G', 5+m_ModuleNO)->SetCell(Lv);

    //单禟娩フ︹5翴
    SelectSheet(3);
    SelectCell('I', 5+m_ModuleNO)->SetCell(Sx);
    SelectCell('J', 5+m_ModuleNO)->SetCell(Sy);
    SelectCell('K', 5+m_ModuleNO)->SetCell(Lv);

	//单瞒娩フ︹9翴
    SelectSheet(1);
    SelectCell('G', 5+m_ModuleNO)->SetCell(Lv);

    //Color Temperature
    SelectSheet(7);
    SelectCell('C', 5+m_ModuleNO)->SetCell(Sx);
    SelectCell('D', 5+m_ModuleNO)->SetCell(Sy);
}

void CXlsOQC1::idR1()
{
	CString Lv, Sx, Sy;
	Lv.Format("%3.2f", m_vCar.At(Red, Pn1, 0).GetLv());
	Sx.Format("%1.4f", m_vCar.At(Red, Pn1, 0).GetSx());
	Sy.Format("%1.4f", m_vCar.At(Red, Pn1, 0).GetSy());

    SelectSheet(1);
    SelectCell('N', 5+m_ModuleNO)->SetCell(Lv);
    SelectCell('O', 5+m_ModuleNO)->SetCell(Sx);
    SelectCell('P', 5+m_ModuleNO)->SetCell(Sy);

    //单Color Gamu
    SelectSheet(8);
    switch (m_ModuleNO)
    {
    case 0: SelectCell("F3")->SetCell(Sx);
            SelectCell("G3")->SetCell(Sy);  break;
    case 1: SelectCell("J3")->SetCell(Sx);
            SelectCell("K3")->SetCell(Sy);  break;
    case 2: SelectCell("N3")->SetCell(Sx);
            SelectCell("O3")->SetCell(Sy);  break;
        
    case 3: SelectCell("F11")->SetCell(Sx);
            SelectCell("G11")->SetCell(Sy);  break;
    case 4: SelectCell("J11")->SetCell(Sx);
            SelectCell("K11")->SetCell(Sy);  break;
    case 5: SelectCell("N11")->SetCell(Sx);
            SelectCell("O11")->SetCell(Sy);  break;
        
    case 6: SelectCell("F19")->SetCell(Sx);
            SelectCell("G19")->SetCell(Sy);  break;
    case 7: SelectCell("J19")->SetCell(Sx);
            SelectCell("K19")->SetCell(Sy);  break;
    case 8: SelectCell("N19")->SetCell(Sx);
            SelectCell("O19")->SetCell(Sy);  break;
        
    case 9: SelectCell("F27")->SetCell(Sx);
            SelectCell("G27")->SetCell(Sy);  break;
    }
}

void CXlsOQC1::idG1()
{
	CString Lv, Sx, Sy;
	Lv.Format("%3.2f", m_vCar.At(Green, Pn1, 0).GetLv());
	Sx.Format("%1.4f", m_vCar.At(Green, Pn1, 0).GetSx());
	Sy.Format("%1.4f", m_vCar.At(Green, Pn1, 0).GetSy());

    SelectSheet(1);
    SelectCell('Q', 5+m_ModuleNO)->SetCell(Lv);
    SelectCell('R', 5+m_ModuleNO)->SetCell(Sx);
    SelectCell('S', 5+m_ModuleNO)->SetCell(Sy);

    //单Color Gamu
    SelectSheet(8);
    switch (m_ModuleNO)
    {
    case 0:     SelectCell("F4")->SetCell(Sx);
                SelectCell("G4")->SetCell(Sy);  break;
    case 1:     SelectCell("J4")->SetCell(Sx);
                SelectCell("K4")->SetCell(Sy);  break;
    case 2:     SelectCell("N4")->SetCell(Sx);
                SelectCell("O4")->SetCell(Sy);  break;
        
    case 3:     SelectCell("F12")->SetCell(Sx);
                SelectCell("G12")->SetCell(Sy);  break;
    case 4:     SelectCell("J12")->SetCell(Sx);
                SelectCell("K12")->SetCell(Sy);  break;
    case 5:     SelectCell("N12")->SetCell(Sx);
                SelectCell("O12")->SetCell(Sy);  break;
        
    case 6:     SelectCell("F20")->SetCell(Sx);
                SelectCell("G20")->SetCell(Sy);  break;
    case 7:     SelectCell("J20")->SetCell(Sx);
                SelectCell("K20")->SetCell(Sy);  break;
    case 8:     SelectCell("N20")->SetCell(Sx);
                SelectCell("O20")->SetCell(Sy);  break;
        
    case 9:     SelectCell("F28")->SetCell(Sx);
                SelectCell("G28")->SetCell(Sy);    break;
    }
}

void CXlsOQC1::idB1()
{
	CString Lv, Sx, Sy;
	Lv.Format("%3.2f", m_vCar.At(Blue, Pn1, 0).GetLv());
	Sx.Format("%1.4f", m_vCar.At(Blue, Pn1, 0).GetSx());
	Sy.Format("%1.4f", m_vCar.At(Blue, Pn1, 0).GetSy());
	
    SelectSheet(1);
    SelectCell('T', 5+m_ModuleNO)->SetCell(Lv);
    SelectCell('U', 5+m_ModuleNO)->SetCell(Sx);
    SelectCell('V', 5+m_ModuleNO)->SetCell(Sy);

	//单Color Gamu
    SelectSheet(8);
    switch (m_ModuleNO)
    {
    case 0:     SelectCell("F5")->SetCell(Sx);
                SelectCell("G5")->SetCell(Sy);    break;
    case 1:     SelectCell("J5")->SetCell(Sx);
                SelectCell("K5")->SetCell(Sy);    break;
    case 2:     SelectCell("N5")->SetCell(Sx);
                SelectCell("O5")->SetCell(Sy);    break;
        
    case 3:     SelectCell("F13")->SetCell(Sx);
                SelectCell("G13")->SetCell(Sy);    break;
    case 4:     SelectCell("J13")->SetCell(Sx);
                SelectCell("K13")->SetCell(Sy);    break;
    case 5:     SelectCell("N13")->SetCell(Sx);
                SelectCell("O13")->SetCell(Sy);    break;
        
    case 6:     SelectCell("F21")->SetCell(Sx);
                SelectCell("G21")->SetCell(Sy);    break;
    case 7:     SelectCell("J21")->SetCell(Sx);
                SelectCell("K21")->SetCell(Sy);    break;
    case 8:     SelectCell("N21")->SetCell(Sx);
                SelectCell("O21")->SetCell(Sy);    break;
        
    case 9:     SelectCell("F29")->SetCell(Sx);
                SelectCell("G29")->SetCell(Sy);    break;
    }
}

void CXlsOQC1::idD1()
{
	CString Lv, Sx, Sy;
	Lv.Format("%3.2f", m_vCar.At(Dark, Pn1, 0).GetLv());
	Sx.Format("%1.4f", m_vCar.At(Dark, Pn1, 0).GetSx());
	Sy.Format("%1.4f", m_vCar.At(Dark, Pn1, 0).GetSy());

    SelectSheet(1);
    SelectCell('W', 5+m_ModuleNO)->SetCell(Lv);
    SelectCell('X', 5+m_ModuleNO)->SetCell(Sx);
    SelectCell('Y', 5+m_ModuleNO)->SetCell(Sy);

    //单D21
    SelectSheet(5);
	SelectCell('Z', 5+m_ModuleNO)->SetCell(Lv);
	SelectCell('C', 5+m_ModuleNO)->SetCell(Lv);
    SelectCell('D', 5+m_ModuleNO)->SetCell(Sx);
    SelectCell('E', 5+m_ModuleNO)->SetCell(Sy);

    //单D25
    SelectSheet(2);
	SelectCell('R', 5+m_ModuleNO)->SetCell(Lv);
	SelectCell('C', 5+m_ModuleNO)->SetCell(Lv);
    SelectCell('D', 5+m_ModuleNO)->SetCell(Sx);
    SelectCell('E', 5+m_ModuleNO)->SetCell(Sy);
}

void CXlsOQC1::idNits()
{
    SelectSheet(1);
    SelectCell('Z', 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(Nits, Pn9, 0).GetLv());
    
    for(int i=0;i<8;++i)
        SelectCell('A',(char)('A'+i), 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(Nits, Pn9, i+1).GetLv());

    SelectCell("AJ", 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(Nits, Pn9, 4).GetSx());
    SelectCell("AK", 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(Nits, Pn9, 4).GetSy());
}

void CXlsOQC1::idD21()
{
    SelectSheet(5);
    int i;
    for(i=0;i<21;++i)
        SelectCell((char)('F'+i), 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(Dark, Pn21, i).GetLv());
    
//     for(i=0;i<4;++i)
//         SelectCell('A',(char)('A'+i), 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(Dark, Pn25, i+21).GetLv());
    
    SelectCell('C', 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(Dark, Pn21, 20).GetLv());
    SelectCell('D', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(Dark, Pn21, 20).GetSx());
    SelectCell('E', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.At(Dark, Pn21, 20).GetSy());

	CString Lv, Sx, Sy;
	Lv.Format("%3.2f", m_vCar.At(Dark, Pn21, 20).GetLv());
	Sx.Format("%1.4f", m_vCar.At(Dark, Pn21, 20).GetSx());
	Sy.Format("%1.4f", m_vCar.At(Dark, Pn21, 20).GetSy());

    //单D1
    SelectSheet(1);
    SelectCell("AO", 5+m_ModuleNO)->SetCell(Lv);
    SelectCell("AP", 5+m_ModuleNO)->SetCell(Sx);
    SelectCell("AQ", 5+m_ModuleNO)->SetCell(Sy);
    
    //单D25
    SelectSheet(2);
	SelectCell('R', 5+m_ModuleNO)->SetCell(Lv);
	SelectCell('C', 5+m_ModuleNO)->SetCell(Lv);
    SelectCell('D', 5+m_ModuleNO)->SetCell(Sx);
    SelectCell('E', 5+m_ModuleNO)->SetCell(Sy);
}
void CXlsOQC1::idD25()
{
	CString Lv, Sx, Sy;
	Lv.Format("%3.2f", m_vCar.At(Dark, Pn25, 12).GetLv());
	Sx.Format("%1.4f", m_vCar.At(Dark, Pn25, 12).GetSx());
	Sy.Format("%1.4f", m_vCar.At(Dark, Pn25, 12).GetSy());

    SelectSheet(2);
    SelectCell('C', 5+m_ModuleNO)->SetCell(Lv);
    SelectCell('D', 5+m_ModuleNO)->SetCell(Sx);
    SelectCell('E', 5+m_ModuleNO)->SetCell(Sy);

    //D25(Lv)
    for(int i = 0; i < 21; ++i)
        SelectCell((char)('F'+i), 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(Dark, Pn25, i).GetLv());
    
    for(i=0;i<4;++i)
        SelectCell('A',(char)('A'+i), 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.At(Dark, Pn25, i+21).GetLv());

    //单D1
    SelectSheet(1);
    SelectCell("AO", 5+m_ModuleNO)->SetCell(Lv);
    SelectCell("AP", 5+m_ModuleNO)->SetCell(Sx);
    SelectCell("AQ", 5+m_ModuleNO)->SetCell(Sy);

	//单D21
    SelectSheet(5);
	SelectCell('Z', 5+m_ModuleNO)->SetCell(Lv);
	SelectCell('C', 5+m_ModuleNO)->SetCell(Lv);
    SelectCell('D', 5+m_ModuleNO)->SetCell(Sx);
    SelectCell('E', 5+m_ModuleNO)->SetCell(Sy);
}

void CXlsOQC1::idCrsTlk()
{
    SelectSheet(6);
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

void CXlsOQC1::iColorTemperature()
{
    //眖フ︹いみ翴笲衡ㄓ︹放禟
    SelectSheet(6)->SelectCell('C', 9+m_ModuleNO)->SetCell("%f", SelectSheet(7)->SelectCell('F', 5+m_ModuleNO)->GetCell2Double());
}

void CXlsOQC1::iColorGamu()
{
    SelectSheet(8);
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
    
// 	CString str;
// 	str.Format("%f", CGvalue);
// 	AfxMessageBox(str);

    SelectSheet(6)->SelectCell('D', 9+m_ModuleNO)->SetCell("%f", CGvalue);
}