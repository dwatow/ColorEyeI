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
  void idW9();
  void idAvg();
  void idMedian();
  void idMax();
  void idMin();

public:
  void InitForm();
  //    std::vector<Cartridge> oData();

  CXlsFile2* iCellNO(std::vector<Cartridge>::size_type);

  CXlsFile2* iChannel(CString    , std::vector<Cartridge>::size_type );
  CXlsFile2* iPanelID(CString    , std::vector<Cartridge>::size_type );
  CXlsFile2* iProb   (CString    , std::vector<Cartridge>::size_type );
  CXlsFile2* iData   (CDataChain&, std::vector<Cartridge>::size_type );
  CXlsFile2* iNitsLv (CString    , std::vector<Cartridge>::size_type ){ return this;};

  CXlsFile2* iChannel(CString     );
  CXlsFile2* iPanelID(CString     );
  CXlsFile2* iProb   (CString     );
  CXlsFile2* iData   (CDataChain& );
  CXlsFile2* iNitsLv (CString     ){ return this;};

  CXlsFile2* operator->() { return this; };
};

#endif // !defined(AFX_XLSRA1_H__31300755_DBA3_46D7_8D23_B37B8813FCE7__INCLUDED_)

