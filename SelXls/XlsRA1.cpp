// XlsRA1->cpp: implementation of the CXlsRA1 class->
//
//////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "SelXls.h"
#include "XlsRA1.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
void CXlsRA1::InitForm()
{
    int cell_count = 0;
    
    SelectCell("A1","E3")->SetMergeCells()->SetCellBorder(1, 3);
    SelectCell("F1","AM1")->SetMergeCells()->SetCellColor(35)->SetCellBorder(1, 3)->SetFontSize(24)->SetCell("RA");
    SelectCell("F2","AM2")->SetMergeCells()->SetCellColor(39)->SetCellBorder(1, 3)->SetFontSize(14)->SetCell("WHITE-9點");
    
    SelectCell((char)('A'+cell_count++), 4)->SetCellBorder(1, 3)->SetCell("Cell NO");
    SelectCell((char)('A'+cell_count++), 4)->SetCellBorder(1, 3)->SetCell("Panel ID");
    SelectCell((char)('A'+cell_count++), 4)->SetCellBorder(1, 3)->SetCell("量測日期");
    SelectCell((char)('A'+cell_count++), 4)->SetCellBorder(1, 3)->SetCell("樣品名稱");
    SelectCell((char)('A'+cell_count++), 4)->SetCellBorder(1, 3)->SetCell("測試項目進度");
    
    SelectCell("F3","H3")->SetMergeCells()->SetCellColor(6)->SetCellBorder(1, 3)->SetCell(1);
    SelectCell((char)('A'+cell_count++), 4)->SetCellBorder(1, 3)->SetCell("x");
    SelectCell((char)('A'+cell_count++), 4)->SetCellBorder(1, 3)->SetCell("y");
    SelectCell((char)('A'+cell_count++), 4)->SetCellBorder(1, 3)->SetCellColor(41)->SetCell("L");
    SelectCell("I3","K3")->SetMergeCells()->SetCellColor(6)->SetCellBorder(1, 3)->SetCell(2);
    SelectCell((char)('A'+cell_count++), 4)->SetCellBorder(1, 3)->SetCell("x");
    SelectCell((char)('A'+cell_count++), 4)->SetCellBorder(1, 3)->SetCell("y");
    SelectCell((char)('A'+cell_count++), 4)->SetCellBorder(1, 3)->SetCellColor(41)->SetCell("L");
    SelectCell("L3","N3")->SetMergeCells()->SetCellColor(6)->SetCellBorder(1, 3)->SetCell(3);
    SelectCell((char)('A'+cell_count++), 4)->SetCellBorder(1, 3)->SetCell("x");
    SelectCell((char)('A'+cell_count++), 4)->SetCellBorder(1, 3)->SetCell("y");
    SelectCell((char)('A'+cell_count++), 4)->SetCellBorder(1, 3)->SetCellColor(41)->SetCell("L");
    SelectCell("O3","Q3")->SetMergeCells()->SetCellColor(6)->SetCellBorder(1, 3)->SetCell(4);
    SelectCell((char)('A'+cell_count++), 4)->SetCellBorder(1, 3)->SetCell("x");
    SelectCell((char)('A'+cell_count++), 4)->SetCellBorder(1, 3)->SetCell("y");
    SelectCell((char)('A'+cell_count++), 4)->SetCellBorder(1, 3)->SetCellColor(41)->SetCell("L");
    SelectCell("R3","T3")->SetMergeCells()->SetCellColor(6)->SetCellBorder(1, 3)->SetCell(5);
    SelectCell((char)('A'+cell_count++), 4)->SetCellBorder(1, 3)->SetCell("x");
    SelectCell((char)('A'+cell_count++), 4)->SetCellBorder(1, 3)->SetCell("y");
    SelectCell((char)('A'+cell_count++), 4)->SetCellBorder(1, 3)->SetCellColor(41)->SetCell("L");
    SelectCell("U3","W3")->SetMergeCells()->SetCellColor(6)->SetCellBorder(1, 3)->SetCell(6);
    SelectCell((char)('A'+cell_count++), 4)->SetCellBorder(1, 3)->SetCell("x");
    SelectCell((char)('A'+cell_count++), 4)->SetCellBorder(1, 3)->SetCell("y");
    SelectCell((char)('A'+cell_count++), 4)->SetCellBorder(1, 3)->SetCellColor(41)->SetCell("L");
    SelectCell("X3","Z3")->SetMergeCells()->SetCellColor(6)->SetCellBorder(1, 3)->SetCell(7);
    SelectCell((char)('A'+cell_count++), 4)->SetCellBorder(1, 3)->SetCell("x");
    SelectCell((char)('A'+cell_count++), 4)->SetCellBorder(1, 3)->SetCell("y");
    SelectCell((char)('A'+cell_count++), 4)->SetCellBorder(1, 3)->SetCellColor(41)->SetCell("L");
    //----------------------------------------------------------
    cell_count = 0;
    SelectCell("AA3","AC3")->SetMergeCells()->SetCellColor(6)->SetCellBorder(1, 3)->SetCell(8);
    SelectCell('A', (char)('A'+cell_count++), 4)->SetCellBorder(1, 3)->SetCell("x");
    SelectCell('A', (char)('A'+cell_count++), 4)->SetCellBorder(1, 3)->SetCell("y");
    SelectCell('A', (char)('A'+cell_count++), 4)->SetCellBorder(1, 3)->SetCellColor(41)->SetCell("L");
    
    SelectCell("AD3","AF3")->SetMergeCells()->SetCellColor(6)->SetCellBorder(1, 3)->SetCell(9);
    SelectCell('A', (char)('A'+cell_count++), 4)->SetCellBorder(1, 3)->SetCell("x");
    SelectCell('A', (char)('A'+cell_count++), 4)->SetCellBorder(1, 3)->SetCell("y");
    SelectCell('A', (char)('A'+cell_count++), 4)->SetCellBorder(1, 3)->SetCellColor(41)->SetCell("L");
    
    SelectCell('A', (char)('A'+cell_count), 3, 'A', (char)('A'+cell_count), 4)->SetMergeCells()->SetCellColor(40)->SetCellBorder(1, 3)->SetCell("CA210-CH");cell_count++;
    SelectCell('A', (char)('A'+cell_count), 3, 'A', (char)('A'+cell_count), 4)->SetMergeCells()->SetCellColor(40)->SetCellBorder(1, 3)->SetCell("CA210-Probe");cell_count++;
    SelectCell('A', (char)('A'+cell_count), 3, 'A', (char)('A'+cell_count), 4)->SetMergeCells()->SetCellColor(40)->SetCellBorder(1, 3)->SetCell("Avg");cell_count++;
    SelectCell('A', (char)('A'+cell_count), 3, 'A', (char)('A'+cell_count), 4)->SetMergeCells()->SetCellColor(40)->SetCellBorder(1, 3)->SetCell("Median");cell_count++;
    SelectCell('A', (char)('A'+cell_count), 3, 'A', (char)('A'+cell_count), 4)->SetMergeCells()->SetCellColor(40)->SetCellBorder(1, 3)->SetCell("Max");cell_count++;
    SelectCell('A', (char)('A'+cell_count), 3, 'A', (char)('A'+cell_count), 4)->SetMergeCells()->SetCellColor(40)->SetCellBorder(1, 3)->SetCell("Min");cell_count++;
    SelectCell('A', (char)('A'+cell_count), 3, 'A', (char)('A'+cell_count), 4)->SetMergeCells()->SetCellColor(40)->SetCellBorder(1, 3)->SetCell("Spec");cell_count++;
}

CXlsFile2* CXlsRA1::iCellNO(std::vector<Cartridge2>::size_type box_count)
{    
    m_CellNO = box_count;    
    SelectCell('A', 5+m_CellNO)->SetCellBorder(1, 3)->SetCell(m_CellNO+1);    
    return this;
}

//////////////////////////////////////////////////////////////////////////
CXlsFile2* CXlsRA1::iPanelID(CString strPanelID , std::vector<Cartridge2>::size_type box_count){    iCellNO(box_count)->iPanelID(strPanelID);  return this;}
CXlsFile2* CXlsRA1::iChannel(CString strCHID    , std::vector<Cartridge2>::size_type box_count){    iCellNO(box_count)->iChannel(strCHID);     return this;}
CXlsFile2* CXlsRA1::iProb   (CString strProb    , std::vector<Cartridge2>::size_type box_count){    iCellNO(box_count)->iProb(strProb);        return this;}
CXlsFile2* CXlsRA1::iData   (RNA& vCar   , std::vector<Cartridge2>::size_type box_count){    iCellNO(box_count)->iData(vCar);           return this;}

//////////////////////////////////////////////////////////////////////////
CXlsFile2* CXlsRA1::iPanelID(CString strPanelID) { SelectCell('B' , 5+m_CellNO)->SetCellBorder(1, 3)->SetCell(strPanelID);   return this;}
CXlsFile2* CXlsRA1::iChannel(CString strCHID)    { SelectCell("AG", 5+m_CellNO)->SetCellBorder(1, 3)->SetCell(strCHID);      return this;}
CXlsFile2* CXlsRA1::iProb(CString striProb)      { SelectCell("AH", 5+m_CellNO)->SetCellBorder(1, 3)->SetCell(striProb);     return this;}

CXlsFile2* CXlsRA1::iData(RNA& vCar)
{
    m_vCar = vCar;
    
    idW9();
    idAvg();
    idMedian();
    idMax();
    idMin();

	SelectSheet(1);
    SelectCell("A", 5, "AM", 5+m_CellNO)->SetCellBorder(1, 3)->SetHorztlAlgmet(HA_CENTER);    //設定對齊方式
    SelectCell("A1","AM1")->AutoFitWidth();    //最適欄寬
	SetVisible(true);

//    SelectCell("A", 5, "AM", 5+m_CellNO)->Sort("B5",1,"C5",1);    //排序
//    SelectCell("A1","E3")->InsertImage(CurrentPath, 141, 40);    //貼Logo
    return this;
}

// std::vector<Cartridge2> CXlsRA1::oData()
// {
//     std::vector<Cartridge2> a;
//     Cartridge x;
//     a->push_back(x);
//     return a;
// }

void CXlsRA1::idW9()
{
//     SelectSheet(1);
// 
//     SelectCell('F'+0,  5+m_CellNO)->SetCellBorder(1, 3)->SetCell(m_vCar.At(White, Pn9, 0).GetSx());
//     SelectCell('F'+1,  5+m_CellNO)->SetCellBorder(1, 3)->SetCell(m_vCar.At(White, Pn9, 0).GetSy());
//     SelectCell('F'+2,  5+m_CellNO)->SetCellBorder(1, 3)->SetCell(m_vCar.At(White, Pn9, 0).GetLv());
//     
//     SelectCell('F'+3,  5+m_CellNO)->SetCellBorder(1, 3)->SetCell(m_vCar.At(White, Pn9, 1).GetSx());
//     SelectCell('F'+4,  5+m_CellNO)->SetCellBorder(1, 3)->SetCell(m_vCar.At(White, Pn9, 1).GetSy());
//     SelectCell('F'+5,  5+m_CellNO)->SetCellBorder(1, 3)->SetCell(m_vCar.At(White, Pn9, 1).GetLv());
//     
//     SelectCell('F'+6,  5+m_CellNO)->SetCellBorder(1, 3)->SetCell(m_vCar.At(White, Pn9, 2).GetSx());
//     SelectCell('F'+7,  5+m_CellNO)->SetCellBorder(1, 3)->SetCell(m_vCar.At(White, Pn9, 2).GetSy());
//     SelectCell('F'+8,  5+m_CellNO)->SetCellBorder(1, 3)->SetCell(m_vCar.At(White, Pn9, 2).GetLv());
//     
//     SelectCell('F'+9,  5+m_CellNO)->SetCellBorder(1, 3)->SetCell(m_vCar.At(White, Pn9, 3).GetSx());
//     SelectCell('F'+10, 5+m_CellNO)->SetCellBorder(1, 3)->SetCell(m_vCar.At(White, Pn9, 3).GetSy());
//     SelectCell('F'+11, 5+m_CellNO)->SetCellBorder(1, 3)->SetCell(m_vCar.At(White, Pn9, 3).GetLv());
//     
//     SelectCell('F'+12, 5+m_CellNO)->SetCellBorder(1, 3)->SetCell(m_vCar.At(White, Pn9, 4).GetSx());
//     SelectCell('F'+13, 5+m_CellNO)->SetCellBorder(1, 3)->SetCell(m_vCar.At(White, Pn9, 4).GetSy());
//     SelectCell('F'+14, 5+m_CellNO)->SetCellBorder(1, 3)->SetCell(m_vCar.At(White, Pn9, 4).GetLv());
//     
//     SelectCell('F'+15, 5+m_CellNO)->SetCellBorder(1, 3)->SetCell(m_vCar.At(White, Pn9, 5).GetSx());
//     SelectCell('F'+16, 5+m_CellNO)->SetCellBorder(1, 3)->SetCell(m_vCar.At(White, Pn9, 5).GetSy());
//     SelectCell('F'+17, 5+m_CellNO)->SetCellBorder(1, 3)->SetCell(m_vCar.At(White, Pn9, 5).GetLv());
//     
//     SelectCell('F'+18, 5+m_CellNO)->SetCellBorder(1, 3)->SetCell(m_vCar.At(White, Pn9, 6).GetSx());
//     SelectCell('F'+19, 5+m_CellNO)->SetCellBorder(1, 3)->SetCell(m_vCar.At(White, Pn9, 6).GetSy());
//     SelectCell('F'+20, 5+m_CellNO)->SetCellBorder(1, 3)->SetCell(m_vCar.At(White, Pn9, 6).GetLv());
//     
//     // A-Z, AA的中間界線-----------------------------------------------------
//     SelectCell('A', 'A'+0, 5+m_CellNO)->SetCellBorder(1, 3)->SetCell(m_vCar.At(White, Pn9, 7).GetSx());
//     SelectCell('A', 'A'+1, 5+m_CellNO)->SetCellBorder(1, 3)->SetCell(m_vCar.At(White, Pn9, 7).GetSy());
//     SelectCell('A', 'A'+2, 5+m_CellNO)->SetCellBorder(1, 3)->SetCell(m_vCar.At(White, Pn9, 7).GetLv());
//     
//     SelectCell('A', 'A'+3, 5+m_CellNO)->SetCellBorder(1, 3)->SetCell(m_vCar.At(White, Pn9, 8).GetSx());
//     SelectCell('A', 'A'+4, 5+m_CellNO)->SetCellBorder(1, 3)->SetCell(m_vCar.At(White, Pn9, 8).GetSy());
//     SelectCell('A', 'A'+5, 5+m_CellNO)->SetCellBorder(1, 3)->SetCell(m_vCar.At(White, Pn9, 8).GetLv());
}

void CXlsRA1::idAvg()
{
    SelectSheet(1);
    CString strTemp;
    strTemp.Format("=SUM(AF%d,AC%d,Z%d,W%d,T%d,Q%d,N%d,K%d,H%d)/9",\
        5+m_CellNO, 5+m_CellNO, 5+m_CellNO, 5+m_CellNO, 5+m_CellNO, 5+m_CellNO, 5+m_CellNO, 5+m_CellNO, 5+m_CellNO);
    SelectCell("AI", 5+m_CellNO)->SetCellBorder(1, 3)->SetCell(strTemp);  //Avg
}

void CXlsRA1::idMedian()
{
    SelectSheet(1);
    CString strTemp;
    strTemp.Format("=T%d", 5+m_CellNO);
    SelectCell("AJ", 5+m_CellNO)->SetCellBorder(1, 3)->SetCell(strTemp); //Median
}

void CXlsRA1::idMax()
{
    SelectSheet(1);
    CString strTemp;
    strTemp.Format("=MAX(AF%d,AC%d,Z%d,W%d,T%d,Q%d,N%d,K%d,H%d)",\
        5+m_CellNO, 5+m_CellNO, 5+m_CellNO, 5+m_CellNO, 5+m_CellNO, 5+m_CellNO, 5+m_CellNO, 5+m_CellNO, 5+m_CellNO);
    SelectCell("AK", 5+m_CellNO)->SetCellBorder(1, 3)->SetCell(strTemp); //Max
}

void CXlsRA1::idMin()
{
    SelectSheet(1);
    CString strTemp;
    strTemp.Format("=MIN(AF%d,AC%d,Z%d,W%d,T%d,Q%d,N%d,K%d,H%d)",\
        5+m_CellNO, 5+m_CellNO, 5+m_CellNO, 5+m_CellNO, 5+m_CellNO, 5+m_CellNO, 5+m_CellNO, 5+m_CellNO, 5+m_CellNO);
    SelectCell("AL", 5+m_CellNO)->SetCellBorder(1, 3)->SetCell(strTemp); //Min
}

