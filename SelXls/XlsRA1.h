// XlsRA1.h: interface for the CXlsRA1 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_XLSRA1_H__31300755_DBA3_46D7_8D23_B37B8813FCE7__INCLUDED_)
#define AFX_XLSRA1_H__31300755_DBA3_46D7_8D23_B37B8813FCE7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "XlsFile2.h"

class CXlsRA1 : public CXlsFile2
{
	int m_CellNO;
public:
	void InitForm();
	CXlsRA1& iCellNO(std::vector<Cartridge>::size_type);
	CXlsRA1& iChannel(CString);
	CXlsRA1& iChannel(CString, std::vector<Cartridge>::size_type);
	CXlsRA1& iPanelID(CString );
	CXlsRA1& iPanelID(CString, std::vector<Cartridge>::size_type);
	CXlsRA1& iProb(CString );
	CXlsRA1& iProb(CString, std::vector<Cartridge>::size_type);
public:
	CXlsRA1& iData(CDataChain&);
	CXlsRA1& iData(CDataChain&, std::vector<Cartridge>::size_type);
//	CDataChain& oData();
};

#endif // !defined(AFX_XLSRA1_H__31300755_DBA3_46D7_8D23_B37B8813FCE7__INCLUDED_)

