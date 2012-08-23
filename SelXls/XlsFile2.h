// XlsFile2.h: interface for the CXlsFile2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_XLSFILE2_H__495733B9_0350_4EE1_8991_5F6C138728CA__INCLUDED_)
#define AFX_XLSFILE2_H__495733B9_0350_4EE1_8991_5F6C138728CA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "xlef.h"
#include "../DataChain.h"

class CXlsFile2 : public xlsFile
{
protected:
	CDataChain m_vCar;
public:
	virtual void InitForm() = 0; //畫出表格的title
};

#endif // !defined(AFX_XLSFILE2_H__495733B9_0350_4EE1_8991_5F6C138728CA__INCLUDED_)
