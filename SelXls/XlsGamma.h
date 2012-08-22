// XlsGamma.h: interface for the CXlsGamma class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_XLSGAMMA_H__48CD5DA9_A210_4129_84AA_182FAFBAA016__INCLUDED_)
#define AFX_XLSGAMMA_H__48CD5DA9_A210_4129_84AA_182FAFBAA016__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "XlsFile2.h"

class CXlsGamma : public CXlsFile2
{
public:
	void InitForm(); //畫出表格的title
	xlsFile& iData(std::vector<Cartridge>&, std::vector<Cartridge>::size_type = 0);
	std::vector<Cartridge> oData();
};

#endif // !defined(AFX_XLSGAMMA_H__48CD5DA9_A210_4129_84AA_182FAFBAA016__INCLUDED_)

