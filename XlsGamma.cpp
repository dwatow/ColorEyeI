// XlsGamma.cpp: implementation of the CXlsGamma class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "XlsGamma.h"
#include "Nucleotide.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CXlsFile2* CXlsGamma::iCellNO(std::vector<Cartridge2>::size_type ModuleNO)
{
    m_ModuleNO = ModuleNO;
    return this;
}

//////////////////////////////////////////////////////////////////////////
CXlsFile2* CXlsGamma::iPanelID(CString strPanelID , std::vector<Cartridge2>::size_type ModuleNO)
{
	iCellNO(ModuleNO)->iPanelID(strPanelID);
	return this;
}

CXlsFile2* CXlsGamma::iData(RNA&, std::vector<Cartridge2>::size_type ModuleNO)
{
// 	iCellNO(ModuleNO)->iData(m_vCar);
	return this;
}

//////////////////////////////////////////////////////////////////////////
CXlsFile2* CXlsGamma::iPanelID(CString strPanelID)
{
	SelectSheet(1)->SelectCell('E'+13*m_ModuleNO, '2', 'F'+13*m_ModuleNO, '2')->SetCell(strPanelID);
	return this;
}

CXlsFile2* CXlsGamma::iData(RNA& vCar)
{
// 	m_vCar = vCar;
    if (vCar.HaveSeveral("フ","gamma"))  idWGamma();	
	SetVisible(true);
    return this;
}

void CXlsGamma::idWGamma()
{
	SelectSheet(1);
	int i(0);
	CString msrItemIndex;
    for(i = 0; i < PnGamma; ++i)
	{
		msrItemIndex.Format("%d", i+1);
		SelectCell((char)('E'+13*m_ModuleNO), 53+i)->SetCell("%3.2f", m_vCar.fFind("フ","Gamma", msrItemIndex," ",VluK_Lv));
		SelectCell((char)('F'+13*m_ModuleNO), 53+i)->SetCell("%1.4f", m_vCar.fFind("フ","Gamma", msrItemIndex," ",VluK_Sx));
        SelectCell((char)('G'+13*m_ModuleNO), 53+i)->SetCell("%1.4f", m_vCar.fFind("フ","Gamma", msrItemIndex," ",VluK_Sy));
	}
}