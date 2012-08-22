// XlsFile2.h: interface for the CXlsFile2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_XLSFILE2_H__495733B9_0350_4EE1_8991_5F6C138728CA__INCLUDED_)
#define AFX_XLSFILE2_H__495733B9_0350_4EE1_8991_5F6C138728CA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "xlef.h"
#include "../Enum.h"

class CXlsFile2 : public xlsFile  
{
protected:
	std::vector<Cartridge> m_vCar;
public:
	std::vector<Cartridge>::size_type SubNum(ColorType clr, PointNum Large, UINT Little) const;
public:
	virtual void InitForm() = 0; //畫出表格的title
// 	virtual CXlsFile2& iData(std::vector<Cartridge>&, std::vector<Cartridge>::size_type) = 0;
// 	virtual std::vector<Cartridge> oData() = 0;
};

#endif // !defined(AFX_XLSFILE2_H__495733B9_0350_4EE1_8991_5F6C138728CA__INCLUDED_)
