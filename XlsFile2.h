// XlsFile2.h: interface for the CXlsFile2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_XLSFILE2_H__495733B9_0350_4EE1_8991_5F6C138728CA__INCLUDED_)
#define AFX_XLSFILE2_H__495733B9_0350_4EE1_8991_5F6C138728CA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "xlef.h"
#include "RNA.h"

class CXlsFile2 : public xlsFile
{
protected:
	RNA m_vCar;
public:
	virtual void       InitForm() = 0;
	virtual CXlsFile2* iCellNO (std::vector<Cartridge2>::size_type) = 0;

	virtual CXlsFile2* iPanelID(CString    , std::vector<Cartridge2>::size_type ) = 0;
	virtual CXlsFile2* iProb   (CString    , std::vector<Cartridge2>::size_type ) = 0;
	virtual CXlsFile2* iChannel(CString    , std::vector<Cartridge2>::size_type ) = 0;
	virtual CXlsFile2* iNitsLv (CString    , std::vector<Cartridge2>::size_type ) = 0;
	virtual CXlsFile2* iData   (RNA&       , std::vector<Cartridge2>::size_type ) = 0;

	virtual CXlsFile2* iPanelID(CString     ) = 0;
	virtual CXlsFile2* iProb   (CString     ) = 0;
	virtual CXlsFile2* iChannel(CString     ) = 0;
	virtual CXlsFile2* iNitsLv (CString     ) = 0;
	virtual CXlsFile2* iData   (RNA& ) = 0;
};

#endif // !defined(AFX_XLSFILE2_H__495733B9_0350_4EE1_8991_5F6C138728CA__INCLUDED_)
