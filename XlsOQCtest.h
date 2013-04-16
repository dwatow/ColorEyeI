// XlsOQCtest.h: interface for the XlsOQCtest class.
//
//////////////////////////////////////////////////////////////////////

#ifndef XLSFILETEST_H
#define XLSFILETEST_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "XlsFile2.h"

class CXlsOQCtest : public CXlsFile2
{
	int m_ModuleNO;
	void idW9_1over6();
	void idW9_corner();
	void idW5_corner();
	void idW1();
	void idR1();
	void idG1();
	void idB1();
	void idD1();
	void idNits();
	void idD21();
	void idD25();
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
	CXlsFile2* iNitsLv (CString    , std::vector<Cartridge2>::size_type);

    CXlsFile2* iPanelID(CString     );
    CXlsFile2* iProb   (CString     ){ return this; };
    CXlsFile2* iChannel(CString     );
    CXlsFile2* iData   (RNA& );
	CXlsFile2* iNitsLv (CString     );

    CXlsFile2* operator->() { return this; };
};

#endif 
