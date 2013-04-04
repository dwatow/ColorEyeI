// XlsFile2.h: interface for the CXlsFile2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_XLSFILE2_H__495733B9_0350_4EE1_8991_5F6C138728CA__INCLUDED_)
#define AFX_XLSFILE2_H__495733B9_0350_4EE1_8991_5F6C138728CA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "xlef.h"
//#include "../DataChain.h"
#include "../RNA.h"

class CXlsFile2 : public xlsFile
{
protected:
// 	BOOL nMsred(const CString clr, CString pn)
// 	{
// 		BOOL _notmsr(TRUE);
// 		for (int i =0; i < pn; ++i)
// //			_notmsr = m_vCar.At(clr, pn, i).GetBullet().isEmpty(); //量過就是非空的
// 				_notmsr &= m_vCar.At(clr, pn, i).GetBullet().isEmpty();
// 		return !_notmsr;
// 	}
	//CDataChain m_vCar;
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
