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
	void InitForm(); //畫出表格的title
 	CXlsOQC1& iCellNO(std::vector<Cartridge>::size_type);

 	CXlsOQC1& iChannel(CString);
 	CXlsOQC1& iChannel(CString, std::vector<Cartridge>::size_type);
 	CXlsOQC1& iBarCode(CString );
 	CXlsOQC1& iBarCode(CString, std::vector<Cartridge>::size_type);
// 	CXlsOQC1& iProb(CString );
// 	CXlsOQC1& iProb(CString, std::vector<Cartridge>::size_type);
	CXlsOQC1& iData(CDataChain& );
	CXlsOQC1& iData(CDataChain&, std::vector<Cartridge>::size_type);
//	std::vector<Cartridge> oData();

};

#endif // !defined(AFX_XLSOQC1_H__D5913DE1_A748_4AC1_885C_6385B3C1CB17__INCLUDED_)
