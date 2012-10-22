// XlsSEC1.h: interface for the CXlsSEC1 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_XLSSEC1_H__59E1F677_D8CC_4CC8_AB57_30A2EFC5243D__INCLUDED_)
#define AFX_XLSSEC1_H__59E1F677_D8CC_4CC8_AB57_30A2EFC5243D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "XlsFile2.h"


class CXlsSEC1 : public CXlsFile2
{
public:
    void InitForm(); //畫出表格的title
//    std::vector<Cartridge> oData();

    CXlsFile2* iCellNO(std::vector<Cartridge>::size_type){ return this;};
    
    CXlsFile2* iChannel(CString    , std::vector<Cartridge>::size_type ){ return this;};
    CXlsFile2* iPanelID(CString    , std::vector<Cartridge>::size_type ){ return this;};
    CXlsFile2* iProb   (CString    , std::vector<Cartridge>::size_type ){ return this;};
	CXlsFile2* iData   (CDataChain&, std::vector<Cartridge>::size_type );
    
    CXlsFile2* iChannel(CString     ){ return this;};
    CXlsFile2* iPanelID(CString     ){ return this;};
    CXlsFile2* iProb   (CString     ){ return this;};
    CXlsFile2* iData   (CDataChain&);
    
    CXlsFile2* operator->() { return this;};

};

#endif // !defined(AFX_XLSSEC1_H__59E1F677_D8CC_4CC8_AB57_30A2EFC5243D__INCLUDED_)
