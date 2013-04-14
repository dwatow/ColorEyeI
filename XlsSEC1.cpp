// XlsSEC1.cpp: implementation of the CXlsSEC1 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "XlsSEC1.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

void CXlsSEC1::InitForm()
{
    int i,j;

    for(i=1;i<47;i++)
    {
        if( (i>= 5)&&(i < 8) || 
            (i>= 9)&&(i <13) || 
            (i>=15)&&(i <18) || 
            (i==19)||(i==21) ||
            (i>=23)&&(i <25) || 
            (i>=26)&&(i <28) ||
            (i>=30)&&(i <38) ||
            (i>=39)&&(i <46) )
            SelectCell('A', i)->SetCellHeight((float)13.50);
        else if(i==14)
            SelectCell('A', i)->SetCellHeight((float)12.75);
        else if(i==18)
            SelectCell('A', i)->SetCellHeight((float)16.50);
        else
            SelectCell('A', i)->SetCellHeight((float)14.25);
    }

    for(j=0;j<10;j++)
    {
        if(j==1)//B
            SelectCell((char)('A'+j), 1)->SetCellWidth((float)24.63);
        else 
            SelectCell((char)('A'+j), 1)->SetCellWidth((float)8.38);
    }    
    
    for(i=2;i<47;i++)
    {

        switch(i)
        {
            case  2: SelectCell('B', i)->SetCellWidth((float)24.63)->SetCellBorder()->SetCell("Module Serial Number"); break;
            case  3: SelectCell('B', i)->SetCellWidth((float)24.63)->SetCellBorder()->SetCell("LED-LGP Gap "); break;
            case  4: SelectCell('B', i)->SetCellWidth((float)24.63)->SetCellBorder()->SetCell("LED Spec. "); break;
            case  5: SelectCell('B', i)->SetCellWidth((float)24.63)->SetCellBorder()->SetCell("Sheet Spec. "); break;
            case  9: SelectCell('B', i)->SetCellWidth((float)24.63)->SetCellBorder()->SetCell("Center Point "); break;
            case 14: SelectCell('B', i)->SetCellWidth((float)24.63)->SetCellBorder()->SetCell("49 Point Brightness "); break;
            case 21: SelectCell('B', i)->SetCellWidth((float)24.63)->SetCellBorder()->SetCell("49 Point Avg, "); break;
            case 22: SelectCell('B', i)->SetCellWidth((float)24.63)->SetCellBorder()->SetCell("9 Point Avg, "); break;
            case 23: SelectCell('B', i)->SetCellWidth((float)24.63)->SetCellBorder()->SetCell("Low Frequency Uniformity\n(5 nits) "); break;
            case 26: SelectCell('B', i)->SetCellWidth((float)24.63)->SetCellBorder()->SetCell("Dark Corner 9 Point "); break;
            case 29: SelectCell('B', i)->SetCellWidth((float)24.63)->SetCellBorder()->SetCell("Color coordinate uni."); break;
   
            case 30: SelectCell('B', i)->SetCellWidth((float)24.63)->SetCellBorder()->SetCell("上左"); break;
            case 31: SelectCell('B', i)->SetCellWidth((float)24.63)->SetCellBorder()->SetCell("上中"); break;
            case 32: SelectCell('B', i)->SetCellWidth((float)24.63)->SetCellBorder()->SetCell("上右"); break;
            case 33: SelectCell('B', i)->SetCellWidth((float)24.63)->SetCellBorder()->SetCell("中左"); break;
            case 34: SelectCell('B', i)->SetCellWidth((float)24.63)->SetCellBorder()->SetCell("中中"); break;
            case 35: SelectCell('B', i)->SetCellWidth((float)24.63)->SetCellBorder()->SetCell("中右"); break;
            case 36: SelectCell('B', i)->SetCellWidth((float)24.63)->SetCellBorder()->SetCell("下左"); break;
            case 37: SelectCell('B', i)->SetCellWidth((float)24.63)->SetCellBorder()->SetCell("下中"); break;
            case 38: SelectCell('B', i)->SetCellWidth((float)24.63)->SetCellBorder()->SetCell("下右"); break;
   
            case 39: SelectCell('B', i)->SetCellWidth((float)24.63)->SetCellBorder()->SetCell("Cosmetic Picture(F/W)"); break;
            default: SelectCell('B', i)->SetCellWidth((float)24.63)->SetCellBorder()->SetCell(""); break;
        }
    }
    for(i=2;i<47;i++)
    {
        switch(i)
        {
        case  5:  SelectCell('B', i, 'B', i+3)->SetMergeCells();   break;
        case  9:  SelectCell('B', i, 'B', i+4)->SetMergeCells();   break;
        case 14:  SelectCell('B', i, 'B', i+6)->SetMergeCells();   break;
        case 23:  
        case 26:  SelectCell('B', i, 'B', i+2)->SetMergeCells();   break;
        case 39:  SelectCell('B', i, 'B', i+7)->SetMergeCells();   break;
        }
    }

    //設定上排
    SelectCell("C2", "I2")->SetMergeCells()->SetCellBorder(1,3,1);    
    SelectCell("B2", "I2")->SetCellBorder(1, 3, 1);
    //3列
    SelectCell("C3", "E3")->SetMergeCells()->SetCellBorder()->SetCell("上 :  /  /");
    SelectCell("F3", "G3")->SetMergeCells()->SetCellBorder()->SetCell("LGP Version");
    SelectCell("H3", "I3")->SetMergeCells()->SetCellBorder();
    SelectCell("B3", "I3")->SetCellBorder(1,3,1);
    
    //4列
    SelectCell("C4", "E4")->SetMergeCells()->SetCellBorder()->SetCell("00 EA /SLED");
    SelectCell("F4", "G4")->SetMergeCells()->SetCellBorder()->SetCell("Current");
    SelectCell("H4", "I4")->SetMergeCells()->SetCellBorder()->SetCell("mA");
    SelectCell("B4", "I4")->SetCellBorder(1,3,1);

    //Sheet Spec.列
    SelectCell("C5", "I5")->SetMergeCells()->SetCellBorder();
    SelectCell("C6", "I6")->SetMergeCells()->SetCellBorder();
    SelectCell("C8", "I8")->SetMergeCells()->SetCellBorder();

    SelectCell("B5", "I8")->SetCellBorder(1,3,1);

    //Center Point列
    for(i=0;i<4;i++){
    for(j=0;j<5;j++){
        if(j == 0)
        {
            switch(i)
            {
                //case 0:  strcpy(buf,"");  break;
            case 1:  SelectCell((char)('C'+i), 9+j)->SetCellBorder()->SetCell("L"); break;
            case 2:  SelectCell((char)('C'+i), 9+j)->SetCellBorder()->SetCell("x"); break;
            case 3:  SelectCell((char)('C'+i), 9+j)->SetCellBorder()->SetCell("y"); break;
            }
        }
        if(i==0)
        {
            switch(j)
            {
                //case 0:  SelectCell('C'+i, 9+i)->SetCell("");      break;
            case 1:  SelectCell((char)('C'+i), 9+j)->SetCellBorder()->SetCell("White"); break;
            case 2:  SelectCell((char)('C'+i), 9+j)->SetCellBorder()->SetCell("Red");   break;
            case 3:  SelectCell((char)('C'+i), 9+j)->SetCellBorder()->SetCell("Green"); break;
            case 4:  SelectCell((char)('C'+i), 9+j)->SetCellBorder()->SetCell("Blue");  break;
            }
        }
        SelectCell((char)('C'+i), 9+j)->SetCellBorder();
    }}
    SelectCell("G9", "I13")->SetMergeCells()->SetCellBorder(1,3,1);
    SelectCell("B9", "I13")->SetCellBorder(1, 3, 1);

    //49 Point Brightness
    for(i=0;i<7;i++){
    for(j=0;j<7;j++){
        SelectCell((char)('C'+i), 14+j)->SetCellBorder();
        if((i%2==1)&&(j%2==1))
            SelectCell((char)('C'+i), 14+j)->SetCellColor(6);
    }}
    SelectCell("B14", "I20")->SetCellBorder(1, 3, 1);

    //49 Point Avg,
    SelectCell("C21", "E21")->SetMergeCells()->SetCellBorder()->SetCell("=AVERAGE(C14:I20)");
    //9 Point Avg,
    SelectCell("C22", "E22")->SetMergeCells()->SetCellBorder()->SetCell("=AVERAGE(D15,F15,H15,D17,F17,H17,D19,F19,H19)");

    SelectCell("F21", "G22")->SetMergeCells()->SetCellBorder()->SetCell("Uniformity");
    SelectCell("H21", "I22")->SetMergeCells()->SetCellBorder()->SetCell("=MIN(D15,F15,H15,D17,F17,H17,D19,F19,H19)/MAX(D15,F15,H15,D17,F17,H17,D19,F19,H19)");
    SelectCell("B21", "I22")->SetCellBorder(1,3,1);

    //Low Frequency Uniformity (5 nits)
    for(i=0;i<7;i++){
    for(j=0;j<16;j++){
        SelectCell((char)('C'+i), 23+j)->SetCellBorder();
    }}

    SelectCell("F23")->SetCell("=ABS(C23-D23)/D23");
    SelectCell("F24")->SetCell("=ABS(C24-D24)/D23");
    SelectCell("F25")->SetCell("=ABS(C25-D25)/D23");
    SelectCell("G23", "G25")->SetMergeCells();

    SelectCell("H23")->SetCell("=ABS(E23-D23)/D23");
    SelectCell("H24")->SetCell("=ABS(E24-D24)/D24");
    SelectCell("H25")->SetCell("=ABS(E25-D25)/D25");
    SelectCell("F26", "I28")->SetMergeCells()->SetCellColor(16);

    SelectCell("B23", "I25")->SetCellBorder(1, 3, 1);

    //"黑" Corner 9 Point 
    SelectCell("B26", "I28")->SetCellBorder(1, 3, 1);

    //Color coordinate unit.
    SelectCell("C29")->SetCell("L");
    SelectCell("D29")->SetCell("x");
    SelectCell("E29")->SetCell("y");
    SelectCell("F29")->SetCell("ΔT");
    SelectCell("G29")->SetCell("Δuv");
    SelectCell("H29", "I38")->SetMergeCells()->SetCellColor(16)->SetCellBorder(1, 3, 1);

    //Cosmetic Picture(F/W)
    SelectCell("B21", "I22")->SetCellBorder()->SetCellBorder(1, 3, 1);
    SelectCell("C23", "E28")->SetCellBorder();
    SelectCell("C39", "I46")->SetMergeCells();//->SetCellBorder(1, 3, 1);
    SelectCell("B39", "I46")->SetCellBorder(1, 3, 1);

    SelectCell("B29", "G29")->SetCellBorder(1, 3, 1);
    SelectCell("B2", "B46")->SetCellBorder(1, 3, 1);

	//Sheet2
	SelectSheet(2)->SetSheetName(2, "CrossTalk");

	//左邊表格填文字
	SelectCell("B1")->SetCell("Lv");
	SelectCell("A3")->SetCell("Ya");
	SelectCell("A6")->SetCell("Yb");
	SelectCell("A10")->SetCell("Yb");

	//灰方塊
	SelectCell("B2", "D4")->SetCellColor(SelectColor(8, 4))->SetCellBorder();
	SelectCell("B6", "D8")->SetCellColor(SelectColor(8, 4))->SetCellBorder();
	SelectCell("B10", "D12")->SetCellColor(SelectColor(8, 4))->SetCellBorder();

	//中心顏色
	SelectCell("C7")->SetCellColor(SelectColor(8, 5));
	SelectCell("C11")->SetCellColor(SelectColor(1, 1));

	//右邊表格
	SelectCell("H2")->SetCellColor(SelectColor(2, 4))->SetCellBorder()->SetCell("Gray 0");
	SelectCell("I2")->SetCellBorder()->SetCell("YB");
	SelectCell("J2")->SetCellBorder()->SetCell("YA");
	SelectCell("K2")->SetCellBorder()->SetCell("CT");

	SelectCell("H3")->SetCellBorder()->SetCell("YU");//
	SelectCell("I3")->SetCellBorder()->SetCell("=C10");
	SelectCell("J3")->SetCellBorder()->SetCell("=C2");
	SelectCell("K3")->SetCellBorder()->SetCell("=(I3-J3)/J3");

	SelectCell("H4")->SetCellBorder()->SetCell("YD");//
	SelectCell("I4")->SetCellBorder()->SetCell("=C12");
	SelectCell("J4")->SetCellBorder()->SetCell("=C4");
	SelectCell("K4")->SetCellBorder()->SetCell("=(I4-J4)/J4");

	SelectCell("H5")->SetCellBorder()->SetCell("YL");//
	SelectCell("I5")->SetCellBorder()->SetCell("=B11");
	SelectCell("J5")->SetCellBorder()->SetCell("=B3");
	SelectCell("K5")->SetCellBorder()->SetCell("=(I5-J5)/J5");

	SelectCell("H6")->SetCellBorder()->SetCell("YR");//
	SelectCell("I6")->SetCellBorder()->SetCell("=D11");
	SelectCell("J6")->SetCellBorder()->SetCell("=D3");
	SelectCell("K6")->SetCellBorder()->SetCell("=(I6-J6)/J6");

	SelectCell("H2", "K6")->SetCellBorder(1, 4, 1);

	
	SelectCell("H8")->SetCellColor(SelectColor(2, 4))->SetCellBorder()->SetCell("Gray 255");
	SelectCell("I8")->SetCellBorder()->SetCell("YB");
	SelectCell("J8")->SetCellBorder()->SetCell("YA");
	SelectCell("K8")->SetCellBorder()->SetCell("CT");

	SelectCell("H9")->SetCellBorder()->SetCell("YB");//
	SelectCell("I9")->SetCellBorder()->SetCell("=C6");
	SelectCell("J9")->SetCellBorder()->SetCell("=C2");
	SelectCell("K9")->SetCellBorder()->SetCell("=(I9-J9)/J9");

	SelectCell("H10")->SetCellBorder()->SetCell("YD");//
	SelectCell("I10")->SetCellBorder()->SetCell("=C8");
	SelectCell("J10")->SetCellBorder()->SetCell("=C4");
	SelectCell("K10")->SetCellBorder()->SetCell("=(I10-J10)/J10");

	SelectCell("H11")->SetCellBorder()->SetCell("YL");
	SelectCell("I11")->SetCellBorder()->SetCell("=B7");
	SelectCell("J11")->SetCellBorder()->SetCell("=B3");
	SelectCell("K11")->SetCellBorder()->SetCell("=(I11-J11)/J11");

	SelectCell("H12")->SetCellBorder()->SetCell("YR");
	SelectCell("I12")->SetCellBorder()->SetCell("=D7");
	SelectCell("J12")->SetCellBorder()->SetCell("=D3");
	SelectCell("K12")->SetCellBorder()->SetCell("=(I12-J12)/J12");

	SelectCell("H8", "K12")->SetCellBorder(1, 4, 1);

}

CXlsFile2* CXlsSEC1::iData (RNA& vCar   , std::vector<Cartridge2>::size_type box_count)
{
	box_count = 1;
    iCellNO(box_count)->iData(vCar);
    return this;
}

CXlsFile2* CXlsSEC1::iPanelID   (CString strProb    , std::vector<Cartridge2>::size_type box_count)
{    
	iCellNO(box_count)->iPanelID(strProb);
	return this;
}

CXlsFile2* CXlsSEC1::iPanelID(CString strPanelID)
{
	SelectSheet(1);
	SelectCell("C2", "I2")->SetCell(strPanelID);
	return this;
}

CXlsFile2* CXlsSEC1::iData(RNA& vCar)
{

//Step 4.開始設定內容
//-----------------------------------------------------------------------------------------------
//           表格字填完！下面是填入資料！請準備陣列！
//-----------------------------------------------------------------------------------------------
    m_vCar = vCar;

	//不重疊
// 	if (nMsred(Red  , Pn1 )) idR1();
// 	if (nMsred(Green, Pn1 )) idG1();
//     if (nMsred(Blue , Pn1 )) idB1();
// 	if (nMsred(Nits , "9" )) idNits();

	//重疊
//     if (nMsred("白", "49")) idW49();
// 	if (nMsred("白", "9"))  idW9();
// 	if (nMsred("白", Pn1 )) idW1();
// 
//     if (nMsred("黑" , "9"))  idD9();
// 	if (nMsred("黑" , Pn1))  idD1();
// 
//     if ((nMsred("cross" , "4")) ||
// 		(nMsred("crossW", "4")) ||
// 		(nMsred("crossD", "4")) )  idCrosTalk();
// 
// 	if (nMsred(Red  , Pn1 )) idR1();
// 	if (nMsred(Green, Pn1 )) idG1();
//     if (nMsred(Blue , Pn1 )) idB1();
// 	if (nMsred(Nits , "9" )) idNits();
	
	//不重疊
	idR1();
	idG1();
	idB1();
	idNits();
	//重疊
    idW49();
	idW9();
	idW1();
	
	idD9();
	idD1();

	idCrosTalk();

	SetVisible(true);

    return this;
}

// std::vector<Cartridge2> CXlsSEC1::oData()
// {
//     std::vector<Cartridge2> a;
//     //...
//     return a;
// }

void CXlsSEC1::idW1()
{
	SelectSheet(1);
    SelectCell("D10")->SetCell("%3.2f", m_vCar.fFind("白", "1", "1", " ", VluK_Lv) );
    SelectCell("E10")->SetCell("%1.4f", m_vCar.fFind("白", "1", "1", " ", VluK_Sx) );
    SelectCell("F10")->SetCell("%1.4f", m_vCar.fFind("白", "1", "1", " ", VluK_Sy) );

	//等效W49
	SelectSheet(1)->SelectCell("F17")->SetCell("=D10");

	//等校W9
	SelectCell("C34")->SetCell("=D10");
	SelectCell("D34")->SetCell("=E10");
	SelectCell("E34")->SetCell("=F10");
	SelectCell("F34")->SetCell("%1.4f"   , m_vCar.fFind("白", "1", "1", " ", VluK_T)   );
	SelectCell("G34")->SetCell("%1.4f"   , m_vCar.fFind("白", "1", "1", " ", VluK_Duv) );
}

void CXlsSEC1::idR1()
{
	SelectSheet(1);
    SelectCell("D11")->SetCell("%3.2f", m_vCar.fFind("紅", "1", "1", " ", VluK_Lv) );
    SelectCell("E11")->SetCell("%1.4f", m_vCar.fFind("紅", "1", "1", " ", VluK_Sx) );
    SelectCell("F11")->SetCell("%1.4f", m_vCar.fFind("紅", "1", "1", " ", VluK_Sy) );
}

void CXlsSEC1::idG1()
{
	SelectSheet(1);
    SelectCell("D12")->SetCell("%3.2f", m_vCar.fFind("綠", "1", "1", " ", VluK_Lv) );
    SelectCell("E12")->SetCell("%1.4f", m_vCar.fFind("綠", "1", "1", " ", VluK_Sx) );
    SelectCell("F12")->SetCell("%1.4f", m_vCar.fFind("綠", "1", "1", " ", VluK_Sy) );
}

void CXlsSEC1::idB1()
{
	SelectSheet(1);
    SelectCell("D13")->SetCell("%3.2f", m_vCar.fFind("藍", "1", "1", " ", VluK_Lv) );
    SelectCell("E13")->SetCell("%1.4f", m_vCar.fFind("藍", "1", "1", " ", VluK_Sx) );
    SelectCell("F13")->SetCell("%1.4f", m_vCar.fFind("藍", "1", "1", " ", VluK_Sy) );
}

void CXlsSEC1::idW49()
{
	SelectSheet(1);
	int i, j;
	CString msrItemIndex;
    for(i=0;i<7;i++){//橫的
	for(j=0;j<7;j++){//直的
		msrItemIndex.Format("%d", (i+j*7)+1);
		SelectCell((char)('C'+i), 14+j)->SetCell("%3.2f", m_vCar.fFind("白", "49", msrItemIndex, " ", VluK_Lv) );
    }}

	//等效W9
	//Lv
	SelectCell("C30")->SetCell("=D15");
	SelectCell("C31")->SetCell("=F15");
	SelectCell("C32")->SetCell("=H15");
	SelectCell("C33")->SetCell("=D17");
	SelectCell("C34")->SetCell("=F17");
	SelectCell("C35")->SetCell("=H17");
	SelectCell("C36")->SetCell("=D19");
	SelectCell("C37")->SetCell("=F19");
	SelectCell("C38")->SetCell("=H19");

	//Sx
	SelectCell("D30")->SetCell("%1.4f", m_vCar.fFind("白", "49",  "9", " ", VluK_Sx) );
	SelectCell("D31")->SetCell("%1.4f", m_vCar.fFind("白", "49", "11", " ", VluK_Sx) );
	SelectCell("D32")->SetCell("%1.4f", m_vCar.fFind("白", "49", "13", " ", VluK_Sx) );
	SelectCell("D33")->SetCell("%1.4f", m_vCar.fFind("白", "49", "23", " ", VluK_Sx) );
	SelectCell("D34")->SetCell("%1.4f", m_vCar.fFind("白", "49", "25", " ", VluK_Sx) );
	SelectCell("D35")->SetCell("%1.4f", m_vCar.fFind("白", "49", "27", " ", VluK_Sx) );
	SelectCell("D36")->SetCell("%1.4f", m_vCar.fFind("白", "49", "37", " ", VluK_Sx) );
	SelectCell("D37")->SetCell("%1.4f", m_vCar.fFind("白", "49", "39", " ", VluK_Sx) );
	SelectCell("D38")->SetCell("%1.4f", m_vCar.fFind("白", "49", "41", " ", VluK_Sx) );

	//Sy
	SelectCell("E30")->SetCell("%1.4f", m_vCar.fFind("白", "49", " 8", " ", VluK_Sy) );
	SelectCell("E31")->SetCell("%1.4f", m_vCar.fFind("白", "49", "10", " ", VluK_Sy) );
	SelectCell("E32")->SetCell("%1.4f", m_vCar.fFind("白", "49", "12", " ", VluK_Sy) );
	SelectCell("E33")->SetCell("%1.4f", m_vCar.fFind("白", "49", "22", " ", VluK_Sy) );
	SelectCell("E34")->SetCell("%1.4f", m_vCar.fFind("白", "49", "24", " ", VluK_Sy) );
	SelectCell("E35")->SetCell("%1.4f", m_vCar.fFind("白", "49", "26", " ", VluK_Sy) );
	SelectCell("E36")->SetCell("%1.4f", m_vCar.fFind("白", "49", "36", " ", VluK_Sy) );
	SelectCell("E37")->SetCell("%1.4f", m_vCar.fFind("白", "49", "38", " ", VluK_Sy) );
	SelectCell("E38")->SetCell("%1.4f", m_vCar.fFind("白", "49", "40", " ", VluK_Sy) );

	//T
	SelectCell("F30")->SetCell("%3d", m_vCar.fFind("白", "49", " 8", " ", VluK_T) );
	SelectCell("F31")->SetCell("%3d", m_vCar.fFind("白", "49", "10", " ", VluK_T) );
	SelectCell("F32")->SetCell("%3d", m_vCar.fFind("白", "49", "12", " ", VluK_T) );
	SelectCell("F33")->SetCell("%3d", m_vCar.fFind("白", "49", "22", " ", VluK_T) );
	SelectCell("F34")->SetCell("%3d", m_vCar.fFind("白", "49", "24", " ", VluK_T) );
	SelectCell("F35")->SetCell("%3d", m_vCar.fFind("白", "49", "26", " ", VluK_T) );
	SelectCell("F36")->SetCell("%3d", m_vCar.fFind("白", "49", "36", " ", VluK_T) );
	SelectCell("F37")->SetCell("%3d", m_vCar.fFind("白", "49", "38", " ", VluK_T) );
	SelectCell("F38")->SetCell("%3d", m_vCar.fFind("白", "49", "40", " ", VluK_T) );
	
	//Duv
	SelectCell("G30")->SetCell("%1.4f", m_vCar.fFind("白", "49", " 8", " ", VluK_Duv) );
	SelectCell("G31")->SetCell("%1.4f", m_vCar.fFind("白", "49", "10", " ", VluK_Duv) );
	SelectCell("G32")->SetCell("%1.4f", m_vCar.fFind("白", "49", "12", " ", VluK_Duv) );
	SelectCell("G33")->SetCell("%1.4f", m_vCar.fFind("白", "49", "22", " ", VluK_Duv) );
	SelectCell("G34")->SetCell("%1.4f", m_vCar.fFind("白", "49", "24", " ", VluK_Duv) );
	SelectCell("G35")->SetCell("%1.4f", m_vCar.fFind("白", "49", "26", " ", VluK_Duv) );
	SelectCell("G36")->SetCell("%1.4f", m_vCar.fFind("白", "49", "36", " ", VluK_Duv) );
	SelectCell("G37")->SetCell("%1.4f", m_vCar.fFind("白", "49", "38", " ", VluK_Duv) );
	SelectCell("G38")->SetCell("%1.4f", m_vCar.fFind("白", "49", "40", " ", VluK_Duv) );
	
	//等效W1
	SelectCell("D10")->SetCell("=C34");
	SelectCell("F10")->SetCell("=D34");
	SelectCell("H10")->SetCell("=E34");

}

void CXlsSEC1::idW9()
{
	SelectSheet(1);
	int i, j;
	CString msrItemIndex;
	for(i=0;i<5;i++){
	for(j=0;j<9;j++){
		msrItemIndex.Format("%d", j+1);
			 if(i == 0)     SelectCell((char)('C'+i), 30+j)->SetCell("%3.2f", m_vCar.fFind("白", "9", msrItemIndex, "1/6", VluK_Lv)  ); //[W][1-9][L]
		else if(i == 1)     SelectCell((char)('C'+i), 30+j)->SetCell("%1.4f", m_vCar.fFind("白", "9", msrItemIndex, "1/6", VluK_Sx)  ); //[W][1-9][T]
		else if(i == 2)     SelectCell((char)('C'+i), 30+j)->SetCell("%1.4f", m_vCar.fFind("白", "9", msrItemIndex, "1/6", VluK_Sy)  ); //[W][1-9][T]
		else if(i == 3)     SelectCell((char)('C'+i), 30+j)->SetCell("%4.0f", m_vCar.fFind("白", "9", msrItemIndex, "1/6", VluK_T )  ); //[W][1-9][T]
		else if(i == 4)     SelectCell((char)('C'+i), 30+j)->SetCell("%1.4f", m_vCar.fFind("白", "9", msrItemIndex, "1/6", VluK_Duv) ); //[W][1-9][T]
    }}

	//等效W1
	SelectCell("D10")->SetCell("=C34");
	SelectCell("F10")->SetCell("=D34");
	SelectCell("H10")->SetCell("=E34");

	//等效W49
	SelectCell("D15")->SetCell("=C30");
	SelectCell("F15")->SetCell("=C31");
	SelectCell("H15")->SetCell("=C32");
	SelectCell("D17")->SetCell("=C33");
	SelectCell("F17")->SetCell("=C34");
	SelectCell("H17")->SetCell("=C35");
	SelectCell("D19")->SetCell("=C36");
	SelectCell("F19")->SetCell("=C37");
	SelectCell("H19")->SetCell("=C38");

}
void CXlsSEC1::idD9()
{
	SelectSheet(1);
	int i, j;
	CString msrItemIndex;
    for(i=0;i<3;i++){
	for(j=0;j<3;j++){
		msrItemIndex.Format("%d", j+1);
        SelectCell((char)('C'+j), 26+i)->SetCell("%3.2f", m_vCar.fFind("黑" , "9", msrItemIndex, " ", VluK_Lv) );
    }}
}

void CXlsSEC1::idNits()
{
	SelectSheet(1);
	int i, j;
	CString msrItemIndex;
    for(i=0;i<3;i++){
	for(j=0;j<3;j++){
		msrItemIndex.Format("%d", j+1);
        SelectCell((char)('C'+j), 23+i)->SetCell("%3.2f", m_vCar.fFind("Nits", "9", msrItemIndex, "5-", VluK_Lv) );
    }}
}

void CXlsSEC1::idCrosTalk()
{
	SelectSheet(2);
	
	//灰色方塊
	SelectCell("C2")->SetCell(m_vCar.fFind("cross", "4", "1", "1/4", VluK_Lv) );
	SelectCell("B3")->SetCell(m_vCar.fFind("cross", "4", "2", "1/4", VluK_Lv) );
	SelectCell("D3")->SetCell(m_vCar.fFind("cross", "4", "3", "1/4", VluK_Lv) );
	SelectCell("C4")->SetCell(m_vCar.fFind("cross", "4", "4", "1/4", VluK_Lv) );
	
	SelectCell("C6")->SetCell(m_vCar.fFind("crossW", "4", "1", "1/4", VluK_Lv) );
	SelectCell("B7")->SetCell(m_vCar.fFind("crossW", "4", "2", "1/4", VluK_Lv) );
	SelectCell("D7")->SetCell(m_vCar.fFind("crossW", "4", "3", "1/4", VluK_Lv) );
	SelectCell("C8")->SetCell(m_vCar.fFind("crossW", "4", "4", "1/4", VluK_Lv) );
	
	SelectCell("C10")->SetCell(m_vCar.fFind("crossD", "4", "1", "1/4", VluK_Lv) );
	SelectCell("B11")->SetCell(m_vCar.fFind("crossD", "4", "2", "1/4", VluK_Lv) );
	SelectCell("D11")->SetCell(m_vCar.fFind("crossD", "4", "3", "1/4", VluK_Lv) );
	SelectCell("C12")->SetCell(m_vCar.fFind("crossD", "4", "4", "1/4", VluK_Lv) );
}

void CXlsSEC1::idD1()
{
	SelectSheet(1);
	SelectCell("D27")->SetCell("%3.2f", m_vCar.fFind("黑", "1", "1", " ", VluK_Lv) );
}
 
