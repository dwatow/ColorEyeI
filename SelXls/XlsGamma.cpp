// XlsGamma.cpp: implementation of the CXlsGamma class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SelXls.h"
#include "XlsGamma.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

void CXlsGamma::InitForm()
{

}

CXlsFile2* CXlsGamma::iData(std::vector<Cartridge>& , std::vector<Cartridge>::size_type)
{
	return this;
}

// std::vector<Cartridge> CXlsGamma::oData()
// {
// 	std::vector<Cartridge> a;
// 	Cartridge x;
// 	a.push_back(x);
// 	return a;
// }