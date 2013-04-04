// OmdFile1.cpp: implementation of the COmdFileGm class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "COmdFileGm.h"
#include "../xMsrPoint\Nucleotide.h"

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
	m_dTxt.push_back("Probe\t"              + m_Prb    + "\t0\t" + m_dOmd.Find("白","gamma", "0","0 255 255").GetBullet().oStr(VluK_Lv) + "\t" + m_dOmd.Find("紅","gamma", "0","0 255 255").GetBullet().oStr(VluK_Lv) + "\t" + m_dOmd.Find("藍","gamma", "0","0 255 255").GetBullet().oStr(VluK_Lv) + "\t" + m_dOmd.Find("綠","gamma", "0","0 255 255").GetBullet().oStr(VluK_Lv) + "\t" + m_dOmd.Find("白","gamma", "0","0 255 255").GetBullet().oStr(VluK_Sx) + "\t" + m_dOmd.Find("紅","gamma", "0","0 255 255").GetBullet().oStr(VluK_Sx) + "\t" + m_dOmd.Find("藍","gamma", "0","0 255 255").GetBullet().oStr(VluK_Sx) + "\t" + m_dOmd.Find("綠","gamma", "0","0 255 255").GetBullet().oStr(VluK_Sx) + "\t" + m_dOmd.Find("白","gamma", "0","0 255 255").GetBullet().oStr(VluK_Sy) + "\t" + m_dOmd.Find("紅","gamma", "0","0 255 255").GetBullet().oStr(VluK_Sy) + "\t" + m_dOmd.Find("藍","gamma", "0","0 255 255").GetBullet().oStr(VluK_Sy) + "\t" + m_dOmd.Find("綠","gamma", "0","0 255 255").GetBullet().oStr(VluK_Sy) + "\t" + m_dOmd.Find("白","gamma", "0","0 255 255").GetBullet().oStr(VluK_T) + "\t" + m_dOmd.Find("白","gamma", "0","0 255 255").GetBullet().oStr(VluK_Duv) + "\n");
	m_dTxt.push_back("CH\t"                 + m_CHID   + "\t1\t" + m_dOmd.Find("白","gamma", "1","0 255 255").GetBullet().oStr(VluK_Lv) + "\t" + m_dOmd.Find("紅","gamma", "1","0 255 255").GetBullet().oStr(VluK_Lv) + "\t" + m_dOmd.Find("藍","gamma", "1","0 255 255").GetBullet().oStr(VluK_Lv) + "\t" + m_dOmd.Find("綠","gamma", "1","0 255 255").GetBullet().oStr(VluK_Lv) + "\t" + m_dOmd.Find("白","gamma", "1","0 255 255").GetBullet().oStr(VluK_Sx) + "\t" + m_dOmd.Find("紅","gamma", "1","0 255 255").GetBullet().oStr(VluK_Sx) + "\t" + m_dOmd.Find("藍","gamma", "1","0 255 255").GetBullet().oStr(VluK_Sx) + "\t" + m_dOmd.Find("綠","gamma", "1","0 255 255").GetBullet().oStr(VluK_Sx) + "\t" + m_dOmd.Find("白","gamma", "1","0 255 255").GetBullet().oStr(VluK_Sy) + "\t" + m_dOmd.Find("紅","gamma", "1","0 255 255").GetBullet().oStr(VluK_Sy) + "\t" + m_dOmd.Find("藍","gamma", "1","0 255 255").GetBullet().oStr(VluK_Sy) + "\t" + m_dOmd.Find("綠","gamma", "1","0 255 255").GetBullet().oStr(VluK_Sy) + "\t" + m_dOmd.Find("白","gamma", "1","0 255 255").GetBullet().oStr(VluK_T) + "\t" + m_dOmd.Find("白","gamma", "1","0 255 255").GetBullet().oStr(VluK_Duv) + "\n");

	for (int n = 2; n < PnGamma; ++n)
	{
		nlv.Format("%d", n);
		m_dTxt.push_back("\t\t" + nlv + "\t" + m_dOmd.Find("白","gamma", nlv,"0 255 255").GetBullet().oStr(VluK_Lv) + "\t" + m_dOmd.Find("紅","gamma", nlv,"0 255 255").GetBullet().oStr(VluK_Lv) + "\t" + m_dOmd.Find("藍","gamma", nlv,"0 255 255").GetBullet().oStr(VluK_Lv) + "\t" + m_dOmd.Find("綠","gamma", nlv,"0 255 255").GetBullet().oStr(VluK_Lv) + "\t" + m_dOmd.Find("白","gamma", nlv,"0 255 255").GetBullet().oStr(VluK_Sx) + "\t" + m_dOmd.Find("紅","gamma", nlv,"0 255 255").GetBullet().oStr(VluK_Sx) + "\t" + m_dOmd.Find("藍","gamma", nlv,"0 255 255").GetBullet().oStr(VluK_Sx) + "\t" + m_dOmd.Find("綠","gamma", nlv,"0 255 255").GetBullet().oStr(VluK_Sx) + "\t" + m_dOmd.Find("白","gamma", nlv,"0 255 255").GetBullet().oStr(VluK_Sy) + "\t" + m_dOmd.Find("紅","gamma", nlv,"0 255 255").GetBullet().oStr(VluK_Sy) + "\t" + m_dOmd.Find("藍","gamma", nlv,"0 255 255").GetBullet().oStr(VluK_Sy) + "\t" + m_dOmd.Find("綠","gamma", nlv,"0 255 255").GetBullet().oStr(VluK_Sy) + "\t" + m_dOmd.Find("白","gamma", "n","0 255 255").GetBullet().oStr(VluK_T) + "\t" + m_dOmd.Find("白","gamma", "n","0 255 255").GetBullet().oStr(VluK_Duv) + "\n");
	}

    m_fTxt.iTxtData(m_dTxt);

}

void COmdFileGm::TxtToOmd()
{
//	m_dOmd.GammaInit();
	m_fTxt.oTxtData(m_dTxt);

//檔頭
     m_PnlID .Format("%s", GetCell('B', 1));  m_PnlID.TrimRight();
     m_MsrDvc.Format("%s", GetCell('B', 2));  m_MsrDvc.TrimRight();
     m_Prb   .Format("%s", GetCell('B', 3));  m_Prb.TrimRight();
     m_CHID  .Format("%s", GetCell('B', 4));  m_CHID.TrimRight();

//檔案資料      
    //Gamma
	CString gammaIndex;
	for (int level = 0; level < PnGamma; ++level)
	{
		gammaIndex.Format("%d",gammaIndex);
		m_dOmd.Find("白","gamma",gammaIndex,"0 255 255").GetBullet().i(VluK_Lv, GetCell('D', 3 + level) );
		m_dOmd.Find("紅","gamma",gammaIndex,"0 255 255").GetBullet().i(VluK_Lv, GetCell('E', 3 + level) );
		m_dOmd.Find("綠","gamma",gammaIndex,"0 255 255").GetBullet().i(VluK_Lv, GetCell('F', 3 + level) );
		m_dOmd.Find("藍","gamma",gammaIndex,"0 255 255").GetBullet().i(VluK_Lv, GetCell('G', 3 + level) );

		m_dOmd.Find("白","gamma",gammaIndex,"0 255 255").GetBullet().i(VluK_Sx, GetCell('H', 3 + level) );
		m_dOmd.Find("紅","gamma",gammaIndex,"0 255 255").GetBullet().i(VluK_Sx, GetCell('I', 3 + level) );
		m_dOmd.Find("綠","gamma",gammaIndex,"0 255 255").GetBullet().i(VluK_Sx, GetCell('J', 3 + level) );
		m_dOmd.Find("藍","gamma",gammaIndex,"0 255 255").GetBullet().i(VluK_Sx, GetCell('K', 3 + level) );

		m_dOmd.Find("白","gamma",gammaIndex,"0 255 255").GetBullet().i(VluK_Sy, GetCell('L', 3 + level) );
		m_dOmd.Find("紅","gamma",gammaIndex,"0 255 255").GetBullet().i(VluK_Sy, GetCell('M', 3 + level) );
		m_dOmd.Find("綠","gamma",gammaIndex,"0 255 255").GetBullet().i(VluK_Sy, GetCell('N', 3 + level) );
		m_dOmd.Find("藍","gamma",gammaIndex,"0 255 255").GetBullet().i(VluK_Sy, GetCell('O', 3 + level) );

		m_dOmd.Find("白","gamma",gammaIndex,"0 255 255").GetBullet().i(VluK_T, GetCell('P', 3 + level) );
		m_dOmd.Find("白","gamma",gammaIndex,"0 255 255").GetBullet().i(VluK_Duv, GetCell('Q', 3 + level) );
	}
// 	m_dOmd.freeEmptyCell();
	m_dTxt.clear();
}
	
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


