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
public:
    void InitForm(){ SetVisible(true); }; //畫出表格的title
	
    CXlsFile2* iCellNO(std::vector<Cartridge>::size_type);

    CXlsFile2* iPanelID(CString    , std::vector<Cartridge>::size_type);
    CXlsFile2* iProb   (CString    , std::vector<Cartridge>::size_type){ return this; };
    CXlsFile2* iChannel(CString    , std::vector<Cartridge>::size_type);
    CXlsFile2* iData   (CDataChain&, std::vector<Cartridge>::size_type);

    CXlsFile2* iPanelID(CString     );
    CXlsFile2* iProb   (CString     ){ return this; };
    CXlsFile2* iChannel(CString     );
    CXlsFile2* iData   (CDataChain& );

    CXlsFile2* operator->() { return this; };
};

#endif 
