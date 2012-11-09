// XlsGamma.cpp: implementation of the CXlsGamma class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SelXls.h"
#include "XlsGamma.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CXlsFile2* CXlsGamma::iCellNO(std::vector<Cartridge>::size_type ModuleNO)
{
    m_ModuleNO = ModuleNO;
    return this;
}

//////////////////////////////////////////////////////////////////////////
CXlsFile2* CXlsGamma::iPanelID(CString strPanelID , std::vector<Cartridge>::size_type ModuleNO)
{
	iCellNO(ModuleNO)->iPanelID(strPanelID);
	return this;
}

CXlsFile2* CXlsGamma::iData(CDataChain&, std::vector<Cartridge>::size_type ModuleNO)
{
	iCellNO(ModuleNO)->iData(m_vCar);
	return this;
}

//////////////////////////////////////////////////////////////////////////
CXlsFile2* CXlsGamma::iPanelID(CString strPanelID)
{
	SelectSheet(1)->SelectCell('E'+13*m_ModuleNO, '2', 'F'+13*m_ModuleNO, '2')->SetCell(strPanelID);
	return this;
}

CXlsFile2* CXlsGamma::iData(CDataChain& vCar)
{
	m_vCar = vCar;
    idGamma();	
    return this;
}

void CXlsGamma::idGamma()
{
	SelectSheet(1);
	int i(0);
    for(i = 0; i < PnGamma; ++i)
	{
		SelectCell((char)('E'+13*m_ModuleNO), 53+i)->SetCell("%3.2f", m_vCar.At(White, PnGamma, i).GetLv());
		SelectCell((char)('F'+13*m_ModuleNO), 53+i)->SetCell("%1.4f", m_vCar.At(White, PnGamma, i).GetSx());
        SelectCell((char)('G'+13*m_ModuleNO), 53+i)->SetCell("%1.4f", m_vCar.At(White, PnGamma, i).GetSy());
	}
}