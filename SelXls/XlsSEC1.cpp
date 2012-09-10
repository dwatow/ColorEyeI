// XlsSEC1.cpp: implementation of the CXlsSEC1 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SelXls.h"
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
		if(	(i>= 5)&&(i < 8) || 
			(i>= 9)&&(i <13) || 
			(i>=15)&&(i <18) || 
			(i==19)||(i==21) ||
			(i>=23)&&(i <25) || 
			(i>=26)&&(i <28) ||
			(i>=30)&&(i <38) ||
			(i>=39)&&(i <46) )
			SelectCell('A', i).SetCellHeight((float)13.50);
		else if(i==14)
			SelectCell('A', i).SetCellHeight((float)12.75);
		else if(i==18)
			SelectCell('A', i).SetCellHeight((float)16.50);
		else
			SelectCell('A', i).SetCellHeight((float)14.25);
	}

    for(j=0;j<10;j++)
    {
        if(j==1)//B
			SelectCell('A'+j, 1).SetCellWidth((float)24.63);
        else 
			SelectCell('A'+j, 1).SetCellWidth((float)8.38);
    }
	
	
	for(i=2;i<47;i++)
	{

		switch(i)
		{
			case  2: SelectCell('B', i).SetCellWidth((float)24.63).SetCellBorder().SetCell("Module Serial Number"); break;
			case  3: SelectCell('B', i).SetCellWidth((float)24.63).SetCellBorder().SetCell("LED-LGP Gap "); break;
			case  4: SelectCell('B', i).SetCellWidth((float)24.63).SetCellBorder().SetCell("LED Spec. "); break;
			case  5: SelectCell('B', i).SetCellWidth((float)24.63).SetCellBorder().SetCell("Sheet Spec. "); break;
			case  9: SelectCell('B', i).SetCellWidth((float)24.63).SetCellBorder().SetCell("Center Point "); break;
			case 14: SelectCell('B', i).SetCellWidth((float)24.63).SetCellBorder().SetCell("49 Point Brightness "); break;
			case 21: SelectCell('B', i).SetCellWidth((float)24.63).SetCellBorder().SetCell("49 Point Avg, "); break;
			case 22: SelectCell('B', i).SetCellWidth((float)24.63).SetCellBorder().SetCell("9 Point Avg, "); break;
			case 23: SelectCell('B', i).SetCellWidth((float)24.63).SetCellBorder().SetCell("Low Frequency Uniformity\n(5 nits) "); break;
			case 26: SelectCell('B', i).SetCellWidth((float)24.63).SetCellBorder().SetCell("Dark Corner 9 Point "); break;
			case 29: SelectCell('B', i).SetCellWidth((float)24.63).SetCellBorder().SetCell("Color coordinate uni."); break;
   
			case 30: SelectCell('B', i).SetCellWidth((float)24.63).SetCellBorder().SetCell("�W��"); break;
			case 31: SelectCell('B', i).SetCellWidth((float)24.63).SetCellBorder().SetCell("�W��"); break;
			case 32: SelectCell('B', i).SetCellWidth((float)24.63).SetCellBorder().SetCell("�W�k"); break;
			case 33: SelectCell('B', i).SetCellWidth((float)24.63).SetCellBorder().SetCell("����"); break;
			case 34: SelectCell('B', i).SetCellWidth((float)24.63).SetCellBorder().SetCell("����"); break;
			case 35: SelectCell('B', i).SetCellWidth((float)24.63).SetCellBorder().SetCell("���k"); break;
			case 36: SelectCell('B', i).SetCellWidth((float)24.63).SetCellBorder().SetCell("�U��"); break;
			case 37: SelectCell('B', i).SetCellWidth((float)24.63).SetCellBorder().SetCell("�U��"); break;
			case 38: SelectCell('B', i).SetCellWidth((float)24.63).SetCellBorder().SetCell("�U�k"); break;
   
			case 39: SelectCell('B', i).SetCellWidth((float)24.63).SetCellBorder().SetCell("Cosmetic Picture(F/W)"); break;
			default: SelectCell('B', i).SetCellWidth((float)24.63).SetCellBorder().SetCell(""); break;
		}
	}
	for(i=2;i<47;i++)
	{
		switch(i)
		{
		case  5:  SelectCell('B', i, 'B', i+3).SetMergeCells();   break;
		case  9:  SelectCell('B', i, 'B', i+4).SetMergeCells();   break;
		case 14:  SelectCell('B', i, 'B', i+6).SetMergeCells();   break;
		case 23:  
		case 26:  SelectCell('B', i, 'B', i+2).SetMergeCells();   break;
		case 39:  SelectCell('B', i, 'B', i+7).SetMergeCells();   break;
		}
    }

	//�]�w�W��
	SelectCell("C2", "I2").SetMergeCells().SetCellBorder(1,3,1);	
	SelectCell("B2", "I2").SetCellBorder(1, 3, 1);
    //3�C
	SelectCell("C3", "E3").SetMergeCells().SetCellBorder().SetCell("�W :  /  /");
	SelectCell("F3", "G3").SetMergeCells().SetCellBorder().SetCell("LGP Version");
	SelectCell("H3", "I3").SetMergeCells().SetCellBorder();
	SelectCell("B3", "I3").SetCellBorder(1,3,1);
    
	//4�C
	SelectCell("C4", "E4").SetMergeCells().SetCellBorder().SetCell("00 EA /SLED");
	SelectCell("F4", "G4").SetMergeCells().SetCellBorder().SetCell("Current");
	SelectCell("H4", "I4").SetMergeCells().SetCellBorder().SetCell("mA");
	SelectCell("B4", "I4").SetCellBorder(1,3,1);

    //Sheet Spec.�C
	SelectCell("C5", "I5").SetMergeCells().SetCellBorder();
	SelectCell("C6", "I6").SetMergeCells().SetCellBorder();
	SelectCell("C8", "I8").SetMergeCells().SetCellBorder();

	SelectCell("B5", "I8").SetCellBorder(1,3,1);

	//Center Point�C
    for(i=0;i<4;i++){
	for(j=0;j<5;j++){
		if(j == 0)
		{
			switch(i)
			{
				//case 0:  strcpy(buf,"");  break;
			case 1:  SelectCell('C'+i, 9+j).SetCellBorder().SetCell("L"); break;
			case 2:  SelectCell('C'+i, 9+j).SetCellBorder().SetCell("x"); break;
			case 3:  SelectCell('C'+i, 9+j).SetCellBorder().SetCell("y"); break;
			}
		}
		if(i==0)
		{
			switch(j)
			{
				//case 0:  SelectCell('C'+i, 9+i).SetCell("");      break;
			case 1:  SelectCell('C'+i, 9+j).SetCellBorder().SetCell("White"); break;
			case 2:  SelectCell('C'+i, 9+j).SetCellBorder().SetCell("Red");   break;
			case 3:  SelectCell('C'+i, 9+j).SetCellBorder().SetCell("Green"); break;
			case 4:  SelectCell('C'+i, 9+j).SetCellBorder().SetCell("Blue");  break;
			}
		}
		SelectCell('C'+i, 9+j).SetCellBorder();
    }}
	SelectCell("G9", "I13").SetMergeCells().SetCellBorder(1,3,1);
	SelectCell("B9", "I13").SetCellBorder(1, 3, 1);

	//49 Point Brightness
	for(i=0;i<7;i++){
    for(j=0;j<7;j++){
		SelectCell('C'+i, 14+j).SetCellBorder();
        if((i%2==1)&&(j%2==1))
			SelectCell('C'+i, 14+j).SetCellColor(6);
    }}
	SelectCell("B14", "I20").SetCellBorder(1, 3, 1);

	//49 Point Avg,
	SelectCell("C21", "E21").SetMergeCells().SetCellBorder().SetCell("=AVERAGE(C14:I20)");
	//9 Point Avg,
	SelectCell("C22", "E22").SetMergeCells().SetCellBorder().SetCell("=AVERAGE(D15,F15,H15,D17,F17,H17,D19,F19,H19)");

	SelectCell("F21", "G22").SetMergeCells().SetCellBorder().SetCell("Uniformity");
	SelectCell("H21", "I22").SetMergeCells().SetCellBorder().SetCell("=MIN(D15,F15,H15,D17,F17,H17,D19,F19,H19)/MAX(D15,F15,H15,D17,F17,H17,D19,F19,H19)");
	SelectCell("B21", "I22").SetCellBorder(1,3,1);

	//Low Frequency Uniformity (5 nits)
	for(i=0;i<7;i++){
    for(j=0;j<16;j++){
		SelectCell('C'+i, 23+j).SetCellBorder();
	}}

	SelectCell("F23").SetCell("=ABS(C23-D23)/D23");
	SelectCell("F24").SetCell("=ABS(C24-D24)/D23");
	SelectCell("F25").SetCell("=ABS(C25-D25)/D23");
	SelectCell("G23", "G25").SetMergeCells();

	SelectCell("H23").SetCell("=ABS(E23-D23)/D23");
	SelectCell("H24").SetCell("=ABS(E24-D24)/D24");
	SelectCell("H25").SetCell("=ABS(E25-D25)/D25");
	SelectCell("F26", "I28").SetMergeCells().SetCellColor(16);

	SelectCell("B23", "I25").SetCellBorder(1, 3, 1);

	//Dark Corner 9 Point 
	SelectCell("B26", "I28").SetCellBorder(1, 3, 1);

	//Color coordinate unit.
	SelectCell("C29").SetCell("L");
	SelectCell("D29").SetCell("x");
	SelectCell("E29").SetCell("y");
	SelectCell("F29").SetCell("�GT");
	SelectCell("G29").SetCell("�Guv");
	SelectCell("H29", "I38").SetMergeCells().SetCellColor(16).SetCellBorder(1, 3, 1);

	//Cosmetic Picture(F/W)
	SelectCell("B21", "I22").SetCellBorder().SetCellBorder(1, 3, 1);
	SelectCell("C23", "E28").SetCellBorder();
	SelectCell("C39", "I46").SetMergeCells();//.SetCellBorder(1, 3, 1);
	SelectCell("B39", "I46").SetCellBorder(1, 3, 1);

	SelectCell("B29", "G29").SetCellBorder(1, 3, 1);
	SelectCell("B2", "B46").SetCellBorder(1, 3, 1);
}

CXlsSEC1& CXlsSEC1::iData(CDataChain& vCar)
{

//Step 4.�}�l�]�w���e
//-----------------------------------------------------------------------------------------------
//           ���r�񧹡I�U���O��J��ơI�зǳư}�C�I
//-----------------------------------------------------------------------------------------------
    m_vCar = vCar;
	SelectSheet(1);
	int i, j;

	CString str;
	str.Format("%3.2f, %1.4f, %1.4f", m_vCar.At(White, Pn1, 0).GetLv(), m_vCar.At(White, Pn1, 0).GetSx(), m_vCar.At(White, Pn1, 0).GetSy());
	AfxMessageBox(str);

	str.Format("%3.2f, %1.4f, %1.4f", vCar.At(White, Pn1, 0).GetLv(), vCar.At(White, Pn1, 0).GetSx(), vCar.At(White, Pn1, 0).GetSy());
	AfxMessageBox(str);

    SelectCell("D10").SetCell("%3.2f", m_vCar.At(White, Pn1, 0).GetLv());
    SelectCell("E10").SetCell("%1.4f", m_vCar.At(White, Pn1, 0).GetSx());
	SelectCell("F10").SetCell("%1.4f", m_vCar.At(White, Pn1, 0).GetSy());
	
    SelectCell("D11").SetCell("%3.2f", m_vCar.At(Red  , Pn1, 0).GetLv());
    SelectCell("E11").SetCell("%1.4f", m_vCar.At(Red  , Pn1, 0).GetSx());
	SelectCell("F11").SetCell("%1.4f", m_vCar.At(Red  , Pn1, 0).GetSy());
	
    SelectCell("D12").SetCell("%3.2f", m_vCar.At(Green, Pn1, 0).GetLv());
    SelectCell("E12").SetCell("%1.4f", m_vCar.At(Green, Pn1, 0).GetSx());
	SelectCell("F12").SetCell("%1.4f", m_vCar.At(Green, Pn1, 0).GetSy());
	
	SelectCell("D13").SetCell("%3.2f", m_vCar.At(Blue , Pn1, 0).GetLv());
    SelectCell("E13").SetCell("%1.4f", m_vCar.At(Blue , Pn1, 0).GetSx());
	SelectCell("F13").SetCell("%1.4f", m_vCar.At(Blue , Pn1, 0).GetSy());
	
	
	//w,49�I�G�׭�
	for(i=0;i<7;i++){//�
	for(j=0;j<7;j++){//����
		SelectCell('C'+i, 14+j).SetCell("%3.2f",m_vCar.At(White, Pn49, i+j*7).GetLv());
    }}
	//�զ� 9�I������
	for(i=0;i<5;i++){
	for(j=0;j<9;j++){
			 if(i == 0)	    SelectCell('C'+i, 30+j).SetCell("%3.2f", m_vCar.At(White, Pn9, j).GetLv()); //[W][1-9][L]
		else if(i == 1)     SelectCell('C'+i, 30+j).SetCell("%1.4f", m_vCar.At(White, Pn9, j).GetSx()); //[W][1-9][T]
		else if(i == 2)     SelectCell('C'+i, 30+j).SetCell("%1.4f", m_vCar.At(White, Pn9, j).GetSy()); //[W][1-9][T]
		else if(i == 3)     SelectCell('C'+i, 30+j).SetCell("%4.0f", m_vCar.At(White, Pn9, j).GetT()); //[W][1-9][T]
		else if(i == 4)     SelectCell('C'+i, 30+j).SetCell("%1.4f", m_vCar.At(White, Pn9, j).GetDuv()); //[W][1-9][T]
	}}
	//�¦� 9�I�����ȡ]�|���|���^
	for(i=0;i<3;i++){
	for(j=0;j<3;j++){
			SelectCell('C'+j,26+i).SetCell("%3.2f",m_vCar.At(Dark , Pn9, i*3+j).GetLv());
	}}
	
	//5nits 
	for(i=0;i<3;i++){
	for(j=0;j<3;j++){
			SelectCell('C'+j,23+i).SetCell("%3.2f", m_vCar.At(Nits, Pn9, i*3+j).GetLv());
    }}

//	SetVisible(TRUE);
	
	return *this;
}

std::vector<Cartridge> CXlsSEC1::oData()
{
	std::vector<Cartridge> a;
	/*...*/
	return a;
}
