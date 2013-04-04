// XlsOQC1.h: interface for the CXlsOQC2 class.
//
//////////////////////////////////////////////////////////////////////

#ifndef XLSFILE2_H
#define XLSFILE2_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "XlsFile2.h"

class CXlsOQC2 : public CXlsFile2
{
	int m_ModuleNO;
	void idW9();
	void idW1();
	void idR1();
	void idG1();
	void idB1();
	void idD1();
	void idNits();
	void idD21();
	void idD25();
	void idW5();
	void idCrsTlk();
	void iColorTemperature();
	void iColorGamu();

public:
    void InitForm(){  }; //畫出表格的title
	
    CXlsFile2* iCellNO(std::vector<Cartridge2>::size_type);

    CXlsFile2* iPanelID(CString    , std::vector<Cartridge2>::size_type);
    CXlsFile2* iProb   (CString    , std::vector<Cartridge2>::size_type){ return this; };
    CXlsFile2* iChannel(CString    , std::vector<Cartridge2>::size_type);
    CXlsFile2* iData   (RNA&, std::vector<Cartridge2>::size_type);
//     CXlsFile2* iData   (CDataChain&, std::vector<Cartridge2>::size_type);
	CXlsFile2* iNitsLv (CString    , std::vector<Cartridge2>::size_type);

    CXlsFile2* iPanelID(CString     );
    CXlsFile2* iProb   (CString     ){ return this; };
    CXlsFile2* iChannel(CString     );
    CXlsFile2* iData   (RNA& );
//     CXlsFile2* iData   (CDataChain& );
	CXlsFile2* iNitsLv (CString     );

    CXlsFile2* operator->() { return this; };
};

#endif 
