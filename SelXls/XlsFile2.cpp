// XlsFile2.cpp: implementation of the CXlsFile2 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SelXls.h"
#include "XlsFile2.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

std::vector<Cartridge>::size_type CXlsFile2::SubNum(ColorType clr, PointNum Large, UINT Little) const
{
    std::vector<Cartridge>::size_type SubNum = -1;
    for (std::vector<Cartridge>::const_iterator itor = m_vCar.begin(); itor != m_vCar.end(); ++itor)
    {
        if(Large == itor->GetMsrFlowNum() && Little == itor->GetMsrFlowNo() && clr == itor->GetBackColor())
            SubNum = itor - m_vCar.begin();
    }
    return (SubNum == -1) ? 0 : SubNum;
}