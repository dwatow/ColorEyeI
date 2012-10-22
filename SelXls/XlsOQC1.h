// XlsOQC1.h: interface for the CXlsOQC1 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_XLSOQC1_H__D5913DE1_A748_4AC1_885C_6385B3C1CB17__INCLUDED_)
#define AFX_XLSOQC1_H__D5913DE1_A748_4AC1_885C_6385B3C1CB17__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "XlsFile2.h"

class CXlsOQC1 : public CXlsFile2
{
    int m_ModuleNO;
public:
    void InitForm(){ SetVisible(true); }; //畫出表格的title
//    std::vector<Cartridge> oData();
	
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

#endif // !defined(AFX_XLSOQC1_H__D5913DE1_A748_4AC1_885C_6385B3C1CB17__INCLUDED_)
