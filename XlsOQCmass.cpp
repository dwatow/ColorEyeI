// XlsOQC1.cpp: implementation of the CXlsOQCmass class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "XlsOQCmass.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CXlsFile2* CXlsOQCmass::iCellNO(std::vector<Cartridge2>::size_type ModuleNO)
{
    m_ModuleNO = ModuleNO;
//    SelectCell('A', 5+m_ModuleNO)->SetCell(m_ModuleNO+1);
    return this;
}

//////////////////////////////////////////////////////////////////////////
CXlsFile2* CXlsOQCmass::iPanelID(CString strPanelID , std::vector<Cartridge2>::size_type ModuleNO){ iCellNO(ModuleNO)->iPanelID(strPanelID);     return this;}
CXlsFile2* CXlsOQCmass::iChannel(CString striChannel, std::vector<Cartridge2>::size_type ModuleNO){ iCellNO(ModuleNO)->iChannel(striChannel);    return this;}
CXlsFile2* CXlsOQCmass::iNitsLv(CString strNitsLv   , std::vector<Cartridge2>::size_type ModuleNO){ iCellNO(ModuleNO)->iNitsLv(strNitsLv);       return this;}
CXlsFile2* CXlsOQCmass::iData(RNA&           , std::vector<Cartridge2>::size_type ModuleNO){ iCellNO(ModuleNO)->iData(m_vCar);            return this;}

//////////////////////////////////////////////////////////////////////////
CXlsFile2* CXlsOQCmass::iNitsLv(CString strNitsLv   ) { SelectSheet("光學")->SelectCell("AM", 5+m_ModuleNO)->SetCell(strNitsLv); /*AfxMessageBox(strNitsLv);*/    return this;}
CXlsFile2* CXlsOQCmass::iPanelID(CString strPanelID)
{
    SelectSheet("光學")->SelectCell('B' , 5+m_ModuleNO)->SetCell(strPanelID);
    return this;
}

CXlsFile2* CXlsOQCmass::iChannel(CString striChannel) { SelectSheet("光學")->SelectCell("AP", 5+m_ModuleNO)->SetCell(striChannel);    return this;}
CXlsFile2* CXlsOQCmass::iData(RNA& vCar)
{
    m_vCar = vCar;

    //無重疊
    if (vCar.HaveSeveral("紅","1"))           idR1();
    if (vCar.HaveSeveral("綠","1"))           idG1();
    if (vCar.HaveSeveral("藍","1"))           idB1();
    if (vCar.HaveSeveral("Nits","","","5-"))  idNits();
    if (vCar.HaveSeveral("cross")  ||
		vCar.HaveSeveral("crossW") ||
		vCar.HaveSeveral("crossD")  )         idCrsTlk();
    
    //重疊
    if (vCar.HaveSeveral("黑","25"))          idD25();
    if (vCar.HaveSeveral("黑","21"))          idD21();
    if (vCar.HaveSeveral("黑","1"))           idD1();
    
    if (vCar.HaveSeveral("白","9","","1/6"))  idW9_1over6();
    if (vCar.HaveSeveral("白","5","","0"))    idW5_corner();
    if (vCar.HaveSeveral("白","1"))           idW1();
    
    //其它
    if (vCar.HaveSeveral("紅","1") && 
		vCar.HaveSeveral("綠","1") && 
		vCar.HaveSeveral("藍","1"))           iColorGamu();
    if (vCar.HaveSeveral("白","1"))           iColorTemperature();

    SetVisible(true);
    return this;
}

void CXlsOQCmass::idW9_1over6()
{
    SelectSheet("光學");
    CString msrItemIndex;
    for(int i = 0; i < 9; ++i)
    {
        msrItemIndex.Format("%d", i+1);
        SelectCell((char)('C'+i), 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.fFind("白", "9", msrItemIndex, "1/6", VluK_Lv) );
    }

    CString WcenterLv, WcenterSx, WcenterSy;
    WcenterLv.Format("%3.2f", m_vCar.fFind("白", "9", "6", "1/6", VluK_Lv) );
    WcenterSx.Format("%1.4f", m_vCar.fFind("白", "9", "6", "1/6", VluK_Sx) );
    WcenterSy.Format("%1.4f", m_vCar.fFind("白", "9", "6", "1/6", VluK_Sy) );

    //等效白色中心
    SelectSheet("光學");
    SelectCell('L', 5+m_ModuleNO)->SetCell(WcenterSx);
    SelectCell('M', 5+m_ModuleNO)->SetCell(WcenterSy);
    
    //等效貼邊白色5點 的中心點
    SelectSheet("白色5點");
    SelectCell('I', 5+m_ModuleNO)->SetCell(WcenterSx);
    SelectCell('J', 5+m_ModuleNO)->SetCell(WcenterSy);
    SelectCell('K', 5+m_ModuleNO)->SetCell(WcenterLv);

    //Color Temperature
    SelectSheet("Color Temperature");
    SelectCell('C', 5+m_ModuleNO)->SetCell(WcenterSx);
    SelectCell('D', 5+m_ModuleNO)->SetCell(WcenterSy);
}

void CXlsOQCmass::idW5_corner()
{
    //W5(Lv,x,y)
    SelectSheet("白色5點");
    SelectCell('C', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.fFind("白", "5", "1", "0", VluK_Sx) );
    SelectCell('D', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.fFind("白", "5", "1", "0", VluK_Sy) );
    SelectCell('E', 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.fFind("白", "5", "1", "0", VluK_Lv) );
    
    SelectCell('F', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.fFind("白", "5", "2", "0", VluK_Sx) );
    SelectCell('G', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.fFind("白", "5", "2", "0", VluK_Sy) );
    SelectCell('H', 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.fFind("白", "5", "2", "0", VluK_Lv) );
    
    SelectCell('I', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.fFind("白", "5", "3", "0", VluK_Sx) );
    SelectCell('J', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.fFind("白", "5", "3", "0", VluK_Sy) );
    SelectCell('K', 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.fFind("白", "5", "3", "0", VluK_Lv) );
    
    SelectCell('L', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.fFind("白", "5", "4", "0", VluK_Sx) );
    SelectCell('M', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.fFind("白", "5", "4", "0", VluK_Sy) );
    SelectCell('N', 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.fFind("白", "5", "4", "0", VluK_Lv) );
    
    SelectCell('O', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.fFind("白", "5", "5", "0", VluK_Sx) );
    SelectCell('P', 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.fFind("白", "5", "5", "0", VluK_Sy) );
    SelectCell('Q', 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.fFind("白", "5", "5", "0", VluK_Lv) );

    CString WcenterLv, WcenterSx, WcenterSy;
    WcenterLv.Format("%3.2f", m_vCar.fFind("白", "5", "3", "0", VluK_Lv) );
    WcenterSx.Format("%1.4f", m_vCar.fFind("白", "5", "3", "0", VluK_Sx) );
    WcenterSy.Format("%1.4f", m_vCar.fFind("白", "5", "3", "0", VluK_Sy) );
    
    //等效白色中心
    SelectSheet("光學");
    SelectCell('L', 5+m_ModuleNO)->SetCell(WcenterSx);
    SelectCell('M', 5+m_ModuleNO)->SetCell(WcenterSy);

    //等效白色9點1/6
    SelectSheet("光學");
    SelectCell('G', 5+m_ModuleNO)->SetCell(WcenterLv);
    
    //Color Temperature
    SelectSheet("Color Temperature");
    SelectCell('C', 5+m_ModuleNO)->SetCell(WcenterSx);
    SelectCell('D', 5+m_ModuleNO)->SetCell(WcenterSy);
}

void CXlsOQCmass::idW1()
{
    CString WcenterLv, WcenterSx, WcenterSy;
    WcenterSx.Format("%1.4f", m_vCar.fFind("白", "1", "1", " ", VluK_Sx) );
    WcenterSy.Format("%1.4f", m_vCar.fFind("白", "1", "1", " ", VluK_Sy) );
    WcenterLv.Format("%3.2f", m_vCar.fFind("白", "1", "1", " ", VluK_Lv) );

    SelectSheet("光學");
    SelectCell('L', 5+m_ModuleNO)->SetCell(WcenterSx);
    SelectCell('M', 5+m_ModuleNO)->SetCell(WcenterSy);
    SelectCell('G', 5+m_ModuleNO)->SetCell(WcenterLv);

    //等效貼邊白色5點
    SelectSheet("白色5點");
    SelectCell('I', 5+m_ModuleNO)->SetCell(WcenterSx);
    SelectCell('J', 5+m_ModuleNO)->SetCell(WcenterSy);
    SelectCell('K', 5+m_ModuleNO)->SetCell(WcenterLv);

    //等效離邊白色9點
    SelectSheet("光學");
    SelectCell('G', 5+m_ModuleNO)->SetCell(WcenterLv);

    //Color Temperature
    SelectSheet("Color Temperature");
    SelectCell('C', 5+m_ModuleNO)->SetCell(WcenterSx);
    SelectCell('D', 5+m_ModuleNO)->SetCell(WcenterSy);
}

void CXlsOQCmass::idR1()
{
    CString RcenterLv, RcenterSx, RcenterSy;
    RcenterLv.Format("%3.2f", m_vCar.fFind("紅", "1", "1", " ", VluK_Lv) );
    RcenterSx.Format("%1.4f", m_vCar.fFind("紅", "1", "1", " ", VluK_Sx) );
    RcenterSy.Format("%1.4f", m_vCar.fFind("紅", "1", "1", " ", VluK_Sy) );

    SelectSheet("光學");
    SelectCell('N', 5+m_ModuleNO)->SetCell(RcenterLv);
    SelectCell('O', 5+m_ModuleNO)->SetCell(RcenterSx);
    SelectCell('P', 5+m_ModuleNO)->SetCell(RcenterSy);

    //等效Color Gamut
    SelectSheet("Color Gamut");
    switch (m_ModuleNO)
    {
    case 0: SelectCell("F3")->SetCell(RcenterSx);
            SelectCell("G3")->SetCell(RcenterSy);  break;
    case 1: SelectCell("J3")->SetCell(RcenterSx);
            SelectCell("K3")->SetCell(RcenterSy);  break;
    case 2: SelectCell("N3")->SetCell(RcenterSx);
            SelectCell("O3")->SetCell(RcenterSy);  break;
        
    case 3: SelectCell("F11")->SetCell(RcenterSx);
            SelectCell("G11")->SetCell(RcenterSy);  break;
    case 4: SelectCell("J11")->SetCell(RcenterSx);
            SelectCell("K11")->SetCell(RcenterSy);  break;
    case 5: SelectCell("N11")->SetCell(RcenterSx);
            SelectCell("O11")->SetCell(RcenterSy);  break;
        
    case 6: SelectCell("F19")->SetCell(RcenterSx);
            SelectCell("G19")->SetCell(RcenterSy);  break;
    case 7: SelectCell("J19")->SetCell(RcenterSx);
            SelectCell("K19")->SetCell(RcenterSy);  break;
    case 8: SelectCell("N19")->SetCell(RcenterSx);
            SelectCell("O19")->SetCell(RcenterSy);  break;
        
    case 9: SelectCell("F27")->SetCell(RcenterSx);
            SelectCell("G27")->SetCell(RcenterSy);  break;
    }
}

void CXlsOQCmass::idG1()
{
    CString GcenterLv, GcenterSx, GcenterSy;
    GcenterLv.Format("%3.2f", m_vCar.fFind("綠", "1", "1", " ", VluK_Lv) );
    GcenterSx.Format("%1.4f", m_vCar.fFind("綠", "1", "1", " ", VluK_Sx) );
    GcenterSy.Format("%1.4f", m_vCar.fFind("綠", "1", "1", " ", VluK_Sy) );

    SelectSheet("光學");
    SelectCell('Q', 5+m_ModuleNO)->SetCell(GcenterLv);
    SelectCell('R', 5+m_ModuleNO)->SetCell(GcenterSx);
    SelectCell('S', 5+m_ModuleNO)->SetCell(GcenterSy);

    //等效Color Gamut
    SelectSheet("Color Gamut");
    switch (m_ModuleNO)
    {
    case 0:     SelectCell("F4")->SetCell(GcenterSx);
                SelectCell("G4")->SetCell(GcenterSy);  break;
    case 1:     SelectCell("J4")->SetCell(GcenterSx);
                SelectCell("K4")->SetCell(GcenterSy);  break;
    case 2:     SelectCell("N4")->SetCell(GcenterSx);
                SelectCell("O4")->SetCell(GcenterSy);  break;
        
    case 3:     SelectCell("F12")->SetCell(GcenterSx);
                SelectCell("G12")->SetCell(GcenterSy);  break;
    case 4:     SelectCell("J12")->SetCell(GcenterSx);
                SelectCell("K12")->SetCell(GcenterSy);  break;
    case 5:     SelectCell("N12")->SetCell(GcenterSx);
                SelectCell("O12")->SetCell(GcenterSy);  break;
        
    case 6:     SelectCell("F20")->SetCell(GcenterSx);
                SelectCell("G20")->SetCell(GcenterSy);  break;
    case 7:     SelectCell("J20")->SetCell(GcenterSx);
                SelectCell("K20")->SetCell(GcenterSy);  break;
    case 8:     SelectCell("N20")->SetCell(GcenterSx);
                SelectCell("O20")->SetCell(GcenterSy);  break;
        
    case 9:     SelectCell("F28")->SetCell(GcenterSx);
                SelectCell("G28")->SetCell(GcenterSy);    break;
    }
}

void CXlsOQCmass::idB1()
{
    CString BcenterLv, BcenterSx, BcenterSy;
    BcenterLv.Format("%3.2f", m_vCar.fFind("藍", "1", "1", " ", VluK_Lv) );
    BcenterSx.Format("%1.4f", m_vCar.fFind("藍", "1", "1", " ", VluK_Sx) );
    BcenterSy.Format("%1.4f", m_vCar.fFind("藍", "1", "1", " ", VluK_Sy) );
    
	//B1
    SelectSheet("光學");
    SelectCell('T', 5+m_ModuleNO)->SetCell(BcenterLv);
    SelectCell('U', 5+m_ModuleNO)->SetCell(BcenterSx);
    SelectCell('V', 5+m_ModuleNO)->SetCell(BcenterSy);

    //等效Color Gamut
    SelectSheet("Color Gamut");
    switch (m_ModuleNO)
    {
    case 0:     SelectCell("F5")->SetCell(BcenterSx);
                SelectCell("G5")->SetCell(BcenterSy);    break;
    case 1:     SelectCell("J5")->SetCell(BcenterSx);
                SelectCell("K5")->SetCell(BcenterSy);    break;
    case 2:     SelectCell("N5")->SetCell(BcenterSx);
                SelectCell("O5")->SetCell(BcenterSy);    break;
        
    case 3:     SelectCell("F13")->SetCell(BcenterSx);
                SelectCell("G13")->SetCell(BcenterSy);    break;
    case 4:     SelectCell("J13")->SetCell(BcenterSx);
                SelectCell("K13")->SetCell(BcenterSy);    break;
    case 5:     SelectCell("N13")->SetCell(BcenterSx);
                SelectCell("O13")->SetCell(BcenterSy);    break;
        
    case 6:     SelectCell("F21")->SetCell(BcenterSx);
                SelectCell("G21")->SetCell(BcenterSy);    break;
    case 7:     SelectCell("J21")->SetCell(BcenterSx);
                SelectCell("K21")->SetCell(BcenterSy);    break;
    case 8:     SelectCell("N21")->SetCell(BcenterSx);
                SelectCell("O21")->SetCell(BcenterSy);    break;
        
    case 9:     SelectCell("F29")->SetCell(BcenterSx);
                SelectCell("G29")->SetCell(BcenterSy);    break;
    }
}

void CXlsOQCmass::idD1()
{
    CString DcenterLv, DcenterSx, DcenterSy;
    DcenterLv.Format("%3.2f", m_vCar.fFind("黑", "1", "1", " ", VluK_Lv) );
    DcenterSx.Format("%1.4f", m_vCar.fFind("黑", "1", "1", " ", VluK_Sx) );
    DcenterSy.Format("%1.4f", m_vCar.fFind("黑", "1", "1", " ", VluK_Sy) );

	//D1
    SelectSheet("光學");
    SelectCell('W', 5+m_ModuleNO)->SetCell(DcenterLv);
    SelectCell('X', 5+m_ModuleNO)->SetCell(DcenterSx);
    SelectCell('Y', 5+m_ModuleNO)->SetCell(DcenterSy);

    //等效D21
    SelectSheet("黑色21點");
    SelectCell('Z', 5+m_ModuleNO)->SetCell(DcenterLv);
    SelectCell('C', 5+m_ModuleNO)->SetCell(DcenterLv);
    SelectCell('D', 5+m_ModuleNO)->SetCell(DcenterSx);
    SelectCell('E', 5+m_ModuleNO)->SetCell(DcenterSy);

    //等效D25
    SelectSheet("黑色25點");
    SelectCell('R', 5+m_ModuleNO)->SetCell(DcenterLv);
    SelectCell('C', 5+m_ModuleNO)->SetCell(DcenterLv);
    SelectCell('D', 5+m_ModuleNO)->SetCell(DcenterSx);
    SelectCell('E', 5+m_ModuleNO)->SetCell(DcenterSy);
}

void CXlsOQCmass::idNits()
{
    SelectSheet("光學");
    SelectCell('Z', 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.fFind("Nits", "9", "1", "5-", VluK_Lv) );
    
    CString msrItemIndex;
    for(int i=1;i<9;++i)
    {
        msrItemIndex.Format("%d", i+1);
        SelectCell('A',(char)('A'+i), 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.fFind("Nits", "9", msrItemIndex, "5-", VluK_Lv) );
    }
    SelectCell("AJ", 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.fFind("Nits", "9", 4, "5-", VluK_Sx) );
    SelectCell("AK", 5+m_ModuleNO)->SetCell("%1.4f", m_vCar.fFind("Nits", "9", 4, "5-", VluK_Sy) );
}

void CXlsOQCmass::idD21()
{
    SelectSheet("黑色21點");
    int i;
    CString msrItemIndex;
    for(i=0;i<21;++i)
    {
        msrItemIndex.Format("%d", i+1);
        SelectCell((char)('F'+i), 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.fFind("黑", "21", msrItemIndex, "0", VluK_Lv) );
    }

    CString DcenterLv, DcenterSx, DcenterSy;
    DcenterLv.Format("%3.2f", m_vCar.fFind("黑", "21", "21", "0", VluK_Lv) );
    DcenterSx.Format("%1.4f", m_vCar.fFind("黑", "21", "21", "0", VluK_Sx) );
    DcenterSy.Format("%1.4f", m_vCar.fFind("黑", "21", "21", "0", VluK_Sy) );
    
	//Set D21 center
    SelectCell('C', 5+m_ModuleNO)->SetCell(DcenterLv);
    SelectCell('D', 5+m_ModuleNO)->SetCell(DcenterSx);
    SelectCell('E', 5+m_ModuleNO)->SetCell(DcenterSy);

    //等效D1
    SelectSheet("光學");
    SelectCell("W", 5+m_ModuleNO)->SetCell(DcenterLv);
    SelectCell("X", 5+m_ModuleNO)->SetCell(DcenterSx);
    SelectCell("Y", 5+m_ModuleNO)->SetCell(DcenterSy);
    
    //等效D25
    SelectSheet("黑色25點");
    SelectCell('R', 5+m_ModuleNO)->SetCell(DcenterLv);
    SelectCell('C', 5+m_ModuleNO)->SetCell(DcenterLv);
    SelectCell('D', 5+m_ModuleNO)->SetCell(DcenterSx);
    SelectCell('E', 5+m_ModuleNO)->SetCell(DcenterSy);
	//四角
	SelectCell('T', 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.fFind("黑", "21",  "1", "0", VluK_Lv) );
    SelectCell('F', 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.fFind("黑", "21",  "5", "0", VluK_Lv) );
    SelectCell('L', 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.fFind("黑", "21", "11", "0", VluK_Lv) );
    SelectCell('Z', 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.fFind("黑", "21", "15", "0", VluK_Lv) );
}
void CXlsOQCmass::idD25()
{
    //D25(Lv)
    SelectSheet("黑色25點");
    CString msrItemIndex;
    for(int i = 0; i < 21; ++i)
    {
        msrItemIndex.Format("%d", i+1);
        SelectCell((char)('F'+i), 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.fFind("黑", "25", msrItemIndex, "0", VluK_Lv) );
    }

    for(i=0;i<4;++i)
    {
        msrItemIndex.Format("%d", (i+21)+1);
        SelectCell('A',(char)('A'+i), 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.fFind("黑", "25", msrItemIndex, "0", VluK_Lv) );
    }

    CString DcenterLv, DcenterSx, DcenterSy;
    DcenterLv.Format("%3.2f", m_vCar.fFind("黑", "25", "13", "0", VluK_Lv) );
    DcenterSx.Format("%1.4f", m_vCar.fFind("黑", "25", "13", "0", VluK_Sx) );
    DcenterSy.Format("%1.4f", m_vCar.fFind("黑", "25", "13", "0", VluK_Sy) );

	//D25 center
    SelectCell('C', 5+m_ModuleNO)->SetCell(DcenterLv);
    SelectCell('D', 5+m_ModuleNO)->SetCell(DcenterSx);
    SelectCell('E', 5+m_ModuleNO)->SetCell(DcenterSy);

    //等效D1
    SelectSheet("光學");
    SelectCell("W", 5+m_ModuleNO)->SetCell(DcenterLv);
    SelectCell("X", 5+m_ModuleNO)->SetCell(DcenterSx);
    SelectCell("Y", 5+m_ModuleNO)->SetCell(DcenterSy);

    //等效D21
    SelectSheet("黑色21點");
    SelectCell('Z', 5+m_ModuleNO)->SetCell(DcenterLv);
    SelectCell('C', 5+m_ModuleNO)->SetCell(DcenterLv);
    SelectCell('D', 5+m_ModuleNO)->SetCell(DcenterSx);
    SelectCell('E', 5+m_ModuleNO)->SetCell(DcenterSy);
	//四角
	SelectCell('J', 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.fFind("黑", "25",  "1", "0", VluK_Lv) );
    SelectCell('P', 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.fFind("黑", "25",  "7", "0", VluK_Lv) );
    SelectCell('F', 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.fFind("黑", "25", "15", "0", VluK_Lv) );
    SelectCell('T', 5+m_ModuleNO)->SetCell("%3.2f", m_vCar.fFind("黑", "25", "21", "0", VluK_Lv) );
}

void CXlsOQCmass::idCrsTlk()
{
    SelectSheet("CrossTalk");

	const CString Up    = "1";
	const CString Left  = "2";
	const CString Right = "3";
	const CString Down  = "4";

    SelectCell('E', 9+m_ModuleNO)->SetCell("%f", m_vCar.fFind("cross" , "4", Up   , "1/4", VluK_Lv) );
    SelectCell('F', 9+m_ModuleNO)->SetCell("%f", m_vCar.fFind("cross" , "4", Down , "1/4", VluK_Lv) );
    SelectCell('G', 9+m_ModuleNO)->SetCell("%f", m_vCar.fFind("cross" , "4", Left , "1/4", VluK_Lv) );
    SelectCell('H', 9+m_ModuleNO)->SetCell("%f", m_vCar.fFind("cross" , "4", Right, "1/4", VluK_Lv) );
    
    SelectCell('I', 9+m_ModuleNO)->SetCell("%f", m_vCar.fFind("crossD", "4", Up   , "1/4", VluK_Lv) );
    SelectCell('J', 9+m_ModuleNO)->SetCell("%f", m_vCar.fFind("crossD", "4", Down , "1/4", VluK_Lv) );
    SelectCell('K', 9+m_ModuleNO)->SetCell("%f", m_vCar.fFind("crossD", "4", Left , "1/4", VluK_Lv) );
    SelectCell('L', 9+m_ModuleNO)->SetCell("%f", m_vCar.fFind("crossD", "4", Right, "1/4", VluK_Lv) );
    
    SelectCell('M', 9+m_ModuleNO)->SetCell("%f", m_vCar.fFind("crossW", "4", Up   , "1/4", VluK_Lv) );
    SelectCell('N', 9+m_ModuleNO)->SetCell("%f", m_vCar.fFind("crossW", "4", Down , "1/4", VluK_Lv) );
    SelectCell('O', 9+m_ModuleNO)->SetCell("%f", m_vCar.fFind("crossW", "4", Left , "1/4", VluK_Lv) );
    SelectCell('P', 9+m_ModuleNO)->SetCell("%f", m_vCar.fFind("crossW", "4", Right, "1/4", VluK_Lv) );
    
    SelectCell('Q', 9+m_ModuleNO)->SetCell("%f", (SelectCell('I', 9+m_ModuleNO)->GetCell2Double() - SelectCell('E', 9+m_ModuleNO)->GetCell2Double()) / SelectCell('E', 9+m_ModuleNO)->GetCell2Double() );
    SelectCell('R', 9+m_ModuleNO)->SetCell("%f", (SelectCell('J', 9+m_ModuleNO)->GetCell2Double() - SelectCell('F', 9+m_ModuleNO)->GetCell2Double()) / SelectCell('F', 9+m_ModuleNO)->GetCell2Double() );
    SelectCell('S', 9+m_ModuleNO)->SetCell("%f", (SelectCell('K', 9+m_ModuleNO)->GetCell2Double() - SelectCell('G', 9+m_ModuleNO)->GetCell2Double()) / SelectCell('G', 9+m_ModuleNO)->GetCell2Double() );
    SelectCell('T', 9+m_ModuleNO)->SetCell("%f", (SelectCell('L', 9+m_ModuleNO)->GetCell2Double() - SelectCell('H', 9+m_ModuleNO)->GetCell2Double()) / SelectCell('H', 9+m_ModuleNO)->GetCell2Double() );
    
    SelectCell('U', 9+m_ModuleNO)->SetCell("%f", (SelectCell('M', 9+m_ModuleNO)->GetCell2Double() - SelectCell('E', 9+m_ModuleNO)->GetCell2Double()) / SelectCell('E', 9+m_ModuleNO)->GetCell2Double() );
    SelectCell('V', 9+m_ModuleNO)->SetCell("%f", (SelectCell('N', 9+m_ModuleNO)->GetCell2Double() - SelectCell('F', 9+m_ModuleNO)->GetCell2Double()) / SelectCell('F', 9+m_ModuleNO)->GetCell2Double() );
    SelectCell('W', 9+m_ModuleNO)->SetCell("%f", (SelectCell('O', 9+m_ModuleNO)->GetCell2Double() - SelectCell('G', 9+m_ModuleNO)->GetCell2Double()) / SelectCell('G', 9+m_ModuleNO)->GetCell2Double() );
    SelectCell('X', 9+m_ModuleNO)->SetCell("%f", (SelectCell('P', 9+m_ModuleNO)->GetCell2Double() - SelectCell('H', 9+m_ModuleNO)->GetCell2Double()) / SelectCell('H', 9+m_ModuleNO)->GetCell2Double() );
}

void CXlsOQCmass::iColorTemperature()
{
    //從白色中心點運算出來的色溫貼到
    SelectSheet("CrossTalk")
		->SelectCell('C', 9+m_ModuleNO)
		->SetCell("%f", SelectSheet("Color Temperature")->SelectCell('F', 5+m_ModuleNO)->GetCell2Double());
}

void CXlsOQCmass::iColorGamu()
{
    SelectSheet("Color Gamut");
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
    
    SelectSheet("CrossTalk")->SelectCell('D', 9+m_ModuleNO)->SetCell("%f", CGvalue);
}