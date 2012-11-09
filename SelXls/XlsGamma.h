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
	int m_ModuleNO;

	void idGamma();
public:
	void InitForm(){ SetVisible(true); }; //�e�X��檺title
	CXlsFile2* iData(std::vector<Cartridge>&, std::vector<Cartridge>::size_type = 0){ return this; };
    CXlsFile2* iCellNO(std::vector<Cartridge>::size_type);
	
    CXlsFile2* iPanelID(CString    , std::vector<Cartridge>::size_type);
    CXlsFile2* iProb   (CString    , std::vector<Cartridge>::size_type){ return this; };
    CXlsFile2* iChannel(CString    , std::vector<Cartridge>::size_type){ return this; };
    CXlsFile2* iData   (CDataChain&, std::vector<Cartridge>::size_type);
	
    CXlsFile2* iPanelID(CString     );
    CXlsFile2* iProb   (CString     ){ return this; };
    CXlsFile2* iChannel(CString     ){ return this; };
    CXlsFile2* iData   (CDataChain& );

    CXlsFile2* operator->() { return this; };
};

#endif // !defined(AFX_XLSGAMMA_H__48CD5DA9_A210_4129_84AA_182FAFBAA016__INCLUDED_)

