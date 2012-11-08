// OmdFile1.cpp: implementation of the COmdFileGm class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "COmdFileGm.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////////
//輸出輸入文件格式
//oForm()  output form
//iForm()  input  form
//////////////////////////////////////////////////////////////////////////

void COmdFileGm::OmdToTxt()
{
//	int n(0);
	CString nlv;

    m_dTxt.push_back("Panel ID\t"           + m_PnlID  + "\tGamma curve\tL\t\t\t\tx\t\t\t\ty\t\t\t\tT\tduv\n");
	m_dTxt.push_back("Measurement device\t" + m_MsrDvc + "\tLevel\tWhite\tRed\tGreen\tBlue\tWhite\tRed\tGreen\tBlue\tWhite\tRed\tGreen\tBlue\tWhite\tWhite\n");
	m_dTxt.push_back("Probe\t"              + m_Prb    + "\t0\t" + m_dOmd.At(White, PnGamma, 0).GetStrLv() + "\t" + m_dOmd.At(Red  , PnGamma, 0).GetStrLv() + "\t" + m_dOmd.At(Blue , PnGamma, 0).GetStrLv() + "\t" + m_dOmd.At(Green, PnGamma, 0).GetStrLv() + "\t" + m_dOmd.At(White, PnGamma, 0).GetStrSx() + "\t" + m_dOmd.At(Red  , PnGamma, 0).GetStrSx() + "\t" + m_dOmd.At(Blue , PnGamma, 0).GetStrSx() + "\t" + m_dOmd.At(Green, PnGamma, 0).GetStrSx() + "\t" + m_dOmd.At(White, PnGamma, 0).GetStrSy() + "\t" + m_dOmd.At(Red  , PnGamma, 0).GetStrSy() + "\t" + m_dOmd.At(Blue , PnGamma, 0).GetStrSy() + "\t" + m_dOmd.At(Green, PnGamma, 0).GetStrSy() + "\t" + m_dOmd.At(White, PnGamma, 0).GetStrT() + "\t" + m_dOmd.At(White, PnGamma, 0).GetStrDuv() + "\n");
	m_dTxt.push_back("CH\t"                 + m_CHID   + "\t1\t" + m_dOmd.At(White, PnGamma, 1).GetStrLv() + "\t" + m_dOmd.At(Red  , PnGamma, 1).GetStrLv() + "\t" + m_dOmd.At(Blue , PnGamma, 1).GetStrLv() + "\t" + m_dOmd.At(Green, PnGamma, 1).GetStrLv() + "\t" + m_dOmd.At(White, PnGamma, 1).GetStrSx() + "\t" + m_dOmd.At(Red  , PnGamma, 1).GetStrSx() + "\t" + m_dOmd.At(Blue , PnGamma, 1).GetStrSx() + "\t" + m_dOmd.At(Green, PnGamma, 1).GetStrSx() + "\t" + m_dOmd.At(White, PnGamma, 1).GetStrSy() + "\t" + m_dOmd.At(Red  , PnGamma, 1).GetStrSy() + "\t" + m_dOmd.At(Blue , PnGamma, 1).GetStrSy() + "\t" + m_dOmd.At(Green, PnGamma, 1).GetStrSy() + "\t" + m_dOmd.At(White, PnGamma, 1).GetStrT() + "\t" + m_dOmd.At(White, PnGamma, 1).GetStrDuv() + "\n");
	for (int n = 2; n < PnGamma; ++n)
	{
		nlv.Format("%d", n);
		m_dTxt.push_back("\t\t"                        + nlv + "\t" + m_dOmd.At(White, PnGamma, n).GetStrLv() + "\t" + m_dOmd.At(Red  , PnGamma, n).GetStrLv() + "\t" + m_dOmd.At(Blue , PnGamma, n).GetStrLv() + "\t" + m_dOmd.At(Green, PnGamma, n).GetStrLv() + "\t" + m_dOmd.At(White, PnGamma, n).GetStrSx() + "\t" + m_dOmd.At(Red  , PnGamma, n).GetStrSx() + "\t" + m_dOmd.At(Blue , PnGamma, n).GetStrSx() + "\t" + m_dOmd.At(Green, PnGamma, n).GetStrSx() + "\t" + m_dOmd.At(White, PnGamma, n).GetStrSy() + "\t" + m_dOmd.At(Red  , PnGamma, n).GetStrSy() + "\t" + m_dOmd.At(Blue , PnGamma, n).GetStrSy() + "\t" + m_dOmd.At(Green, PnGamma, n).GetStrSy() + "\t" + m_dOmd.At(White, PnGamma, n).GetStrT() + "\t" + m_dOmd.At(White, PnGamma, n).GetStrDuv() + "\n");
	}

    m_fTxt.iTxtData(m_dTxt);

}

void COmdFileGm::TxtToOmd()
{
	m_dOmd.GammaInit();
	m_fTxt.oTxtData(m_dTxt);

//檔頭
     m_PnlID .Format("%s", GetCell('B', 1));  m_PnlID.TrimRight();
     m_MsrDvc.Format("%s", GetCell('B', 2));  m_MsrDvc.TrimRight();
     m_Prb   .Format("%s", GetCell('B', 3));  m_Prb.TrimRight();
     m_CHID  .Format("%s", GetCell('B', 4));  m_CHID.TrimRight();

//檔案資料      
    //Gamma
	for (int level = 0; level < PnGamma; ++level)
	{
		m_dOmd.At(White, PnGamma, level).SetLv( GetCell('D', 3 + level) );
		m_dOmd.At(Red  , PnGamma, level).SetLv( GetCell('E', 3 + level) );
		m_dOmd.At(Green, PnGamma, level).SetLv( GetCell('F', 3 + level) );
		m_dOmd.At(Blue , PnGamma, level).SetLv( GetCell('G', 3 + level) );

		m_dOmd.At(White, PnGamma, level).SetSx( GetCell('H', 3 + level) );
		m_dOmd.At(Red  , PnGamma, level).SetSx( GetCell('I', 3 + level) );
		m_dOmd.At(Green, PnGamma, level).SetSx( GetCell('J', 3 + level) );
		m_dOmd.At(Blue , PnGamma, level).SetSx( GetCell('K', 3 + level) );

		m_dOmd.At(White, PnGamma, level).SetSy( GetCell('L', 3 + level) );
		m_dOmd.At(Red  , PnGamma, level).SetSy( GetCell('M', 3 + level) );
		m_dOmd.At(Green, PnGamma, level).SetSy( GetCell('N', 3 + level) );
		m_dOmd.At(Blue , PnGamma, level).SetSy( GetCell('O', 3 + level) );

		m_dOmd.At(White, PnGamma, level).SetT ( GetCell('P', 3 + level) );
		m_dOmd.At(White, PnGamma, level).SetDuv(GetCell('Q', 3 + level) );
	}
	m_dOmd.freeEmptyCell();
	m_dTxt.clear();
}
	
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


