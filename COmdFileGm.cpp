// OmdFile1.cpp: implementation of the COmdFileGm class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "COmdFileGm.h"
#include "Nucleotide.h"
#include "debugFile.h"

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

void COmdFileGm::omd2txt()
{
	CString& PanelId    = m_omdFileHead.oPnlID();
	CString& MsrDevice  = m_omdFileHead.oMsrDvc();
	CString& ProbeIndex = m_omdFileHead.oPrb();
	CString& ChannelId  = m_omdFileHead.oCHID();
	CString& LcmInch    = m_omdFileHead.oInch();
	CString gammaIndex;
	CString levelIndex;

    m_dTxt.push_back("Panel ID\t"           + PanelId    + "\tGamma curve\tL\t\t\t\tx\t\t\t\ty\t\t\t\tT\tduv\n");
	m_dTxt.push_back("Measurement device\t" + MsrDevice  + "\tLevel\tWhite\tRed\tGreen\tBlue\tWhite\tRed\tGreen\tBlue\tWhite\tRed\tGreen\tBlue\tWhite\tWhite\n");
	m_dTxt.push_back("Probe\t"              + ProbeIndex + "\t0\t" + m_omdRNA.Find("白", "gamma", "1", "0 255 255").GetBullet().oStr(VluK_Lv) + "\t" + m_omdRNA.Find("紅", "gamma", "1", "0 255 255").GetBullet().oStr(VluK_Lv) + "\t" + m_omdRNA.Find("藍", "gamma", "1", "0 255 255").GetBullet().oStr(VluK_Lv) + "\t" + m_omdRNA.Find("綠", "gamma", "1", "0 255 255").GetBullet().oStr(VluK_Lv) + "\t" + m_omdRNA.Find("白", "gamma", "1", "0 255 255").GetBullet().oStr(VluK_Sx) + "\t" + m_omdRNA.Find("紅", "gamma", "1", "0 255 255").GetBullet().oStr(VluK_Sx) + "\t" + m_omdRNA.Find("藍", "gamma", "1", "0 255 255").GetBullet().oStr(VluK_Sx) + "\t" + m_omdRNA.Find("綠", "gamma", "1", "0 255 255").GetBullet().oStr(VluK_Sx) + "\t" + m_omdRNA.Find("白", "gamma", "1", "0 255 255").GetBullet().oStr(VluK_Sy) + "\t" + m_omdRNA.Find("紅", "gamma", "1", "0 255 255").GetBullet().oStr(VluK_Sy) + "\t" + m_omdRNA.Find("藍", "gamma", "1", "0 255 255").GetBullet().oStr(VluK_Sy) + "\t" + m_omdRNA.Find("綠", "gamma", "1", "0 255 255").GetBullet().oStr(VluK_Sy) + "\t" + m_omdRNA.Find("白", "gamma", "1", "0 255 255").GetBullet().oStr(VluK_T) + "\t" + m_omdRNA.Find("白", "gamma", "1", "0 255 255").GetBullet().oStr(VluK_Duv) + "\n");
	m_dTxt.push_back("CH\t"                 + ChannelId  + "\t1\t" + m_omdRNA.Find("白", "gamma", "2", "0 255 255").GetBullet().oStr(VluK_Lv) + "\t" + m_omdRNA.Find("紅", "gamma", "2", "0 255 255").GetBullet().oStr(VluK_Lv) + "\t" + m_omdRNA.Find("藍", "gamma", "2", "0 255 255").GetBullet().oStr(VluK_Lv) + "\t" + m_omdRNA.Find("綠", "gamma", "2", "0 255 255").GetBullet().oStr(VluK_Lv) + "\t" + m_omdRNA.Find("白", "gamma", "2", "0 255 255").GetBullet().oStr(VluK_Sx) + "\t" + m_omdRNA.Find("紅", "gamma", "2", "0 255 255").GetBullet().oStr(VluK_Sx) + "\t" + m_omdRNA.Find("藍", "gamma", "2", "0 255 255").GetBullet().oStr(VluK_Sx) + "\t" + m_omdRNA.Find("綠", "gamma", "2", "0 255 255").GetBullet().oStr(VluK_Sx) + "\t" + m_omdRNA.Find("白", "gamma", "2", "0 255 255").GetBullet().oStr(VluK_Sy) + "\t" + m_omdRNA.Find("紅", "gamma", "2", "0 255 255").GetBullet().oStr(VluK_Sy) + "\t" + m_omdRNA.Find("藍", "gamma", "2", "0 255 255").GetBullet().oStr(VluK_Sy) + "\t" + m_omdRNA.Find("綠", "gamma", "2", "0 255 255").GetBullet().oStr(VluK_Sy) + "\t" + m_omdRNA.Find("白", "gamma", "2", "0 255 255").GetBullet().oStr(VluK_T) + "\t" + m_omdRNA.Find("白", "gamma", "2", "0 255 255").GetBullet().oStr(VluK_Duv) + "\n");
	m_dTxt.push_back("Inch\t"               + LcmInch    + "\t2\t" + m_omdRNA.Find("白", "gamma", "3", "0 255 255").GetBullet().oStr(VluK_Lv) + "\t" + m_omdRNA.Find("紅", "gamma", "3", "0 255 255").GetBullet().oStr(VluK_Lv) + "\t" + m_omdRNA.Find("藍", "gamma", "3", "0 255 255").GetBullet().oStr(VluK_Lv) + "\t" + m_omdRNA.Find("綠", "gamma", "3", "0 255 255").GetBullet().oStr(VluK_Lv) + "\t" + m_omdRNA.Find("白", "gamma", "3", "0 255 255").GetBullet().oStr(VluK_Sx) + "\t" + m_omdRNA.Find("紅", "gamma", "3", "0 255 255").GetBullet().oStr(VluK_Sx) + "\t" + m_omdRNA.Find("藍", "gamma", "3", "0 255 255").GetBullet().oStr(VluK_Sx) + "\t" + m_omdRNA.Find("綠", "gamma", "3", "0 255 255").GetBullet().oStr(VluK_Sx) + "\t" + m_omdRNA.Find("白", "gamma", "3", "0 255 255").GetBullet().oStr(VluK_Sy) + "\t" + m_omdRNA.Find("紅", "gamma", "3", "0 255 255").GetBullet().oStr(VluK_Sy) + "\t" + m_omdRNA.Find("藍", "gamma", "3", "0 255 255").GetBullet().oStr(VluK_Sy) + "\t" + m_omdRNA.Find("綠", "gamma", "3", "0 255 255").GetBullet().oStr(VluK_Sy) + "\t" + m_omdRNA.Find("白", "gamma", "3", "0 255 255").GetBullet().oStr(VluK_T) + "\t" + m_omdRNA.Find("白", "gamma", "3", "0 255 255").GetBullet().oStr(VluK_Duv) + "\n");

	for (int n = 3; n < PnGamma; ++n)
	{
		levelIndex.Format("%d", n);
		gammaIndex.Format("%d", n+1);
		m_dTxt.push_back("\t\t" + levelIndex + "\t" + m_omdRNA.Find("白", "gamma", gammaIndex, "0 255 255").GetBullet().oStr(VluK_Lv) + "\t" + m_omdRNA.Find("紅", "gamma", gammaIndex, "0 255 255").GetBullet().oStr(VluK_Lv) + "\t" + m_omdRNA.Find("藍", "gamma", gammaIndex, "0 255 255").GetBullet().oStr(VluK_Lv) + "\t" + m_omdRNA.Find("綠", "gamma", gammaIndex, "0 255 255").GetBullet().oStr(VluK_Lv) + "\t" + m_omdRNA.Find("白", "gamma", gammaIndex, "0 255 255").GetBullet().oStr(VluK_Sx) + "\t" + m_omdRNA.Find("紅", "gamma", gammaIndex, "0 255 255").GetBullet().oStr(VluK_Sx) + "\t" + m_omdRNA.Find("藍", "gamma", gammaIndex, "0 255 255").GetBullet().oStr(VluK_Sx) + "\t" + m_omdRNA.Find("綠", "gamma", gammaIndex, "0 255 255").GetBullet().oStr(VluK_Sx) + "\t" + m_omdRNA.Find("白", "gamma", gammaIndex, "0 255 255").GetBullet().oStr(VluK_Sy) + "\t" + m_omdRNA.Find("紅", "gamma", gammaIndex, "0 255 255").GetBullet().oStr(VluK_Sy) + "\t" + m_omdRNA.Find("藍", "gamma", gammaIndex, "0 255 255").GetBullet().oStr(VluK_Sy) + "\t" + m_omdRNA.Find("綠", "gamma", gammaIndex, "0 255 255").GetBullet().oStr(VluK_Sy) + "\t" + m_omdRNA.Find("白", "gamma", "n", "0 255 255").GetBullet().oStr(VluK_T) + "\t" + m_omdRNA.Find("白", "gamma", "n", "0 255 255").GetBullet().oStr(VluK_Duv) + "\n");
	}

    m_fTxt.iTxtData(m_dTxt);

}

void COmdFileGm::txt2omd()
{
//	m_omdRNA.GammaInit();
	m_fTxt.oTxtData(m_dTxt);
//檔頭
	t2oHead();
//初始化裝資料的這些容器
	t2oDNAnRNA();
//檔案資料      
    //Gamma
	t2oGamma();

	debugFile logfile;
// 	for (std::vector<Cartridge2>::iterator itor = m_omdRNA.Begin(); itor != m_omdRNA.End(); ++itor)
// 		logfile.Add(itor->ShowMe());
	
	for (std::vector<Nucleotide>::iterator itor = m_omdDNA.Begin(); itor != m_omdDNA.End(); ++itor)
		logfile.Add(itor->ShowMe());

	logfile.Out2File("c:\\gammaData.log");

 	m_omdRNA.DeleteEmptyCell();
	t2oDelDNAinEmptyRNA();
	m_omdFileHead.iDNA(m_omdDNA);

	m_dTxt.clear();
}

void COmdFileGm::CreatDNA(DnaConfig& dnaConfig)
{
	dnaConfig.Add_Omd_Gamma();
}

void COmdFileGm::t2oHead()
{
    m_omdFileHead.iPnlID ( GetCell('B', 1) );
    m_omdFileHead.iMsrDvc( GetCell('B', 2) );
    m_omdFileHead.iPrb   ( GetCell('B', 3) );
    m_omdFileHead.iCHID  ( GetCell('B', 4) );
	m_omdFileHead.iInch  ( GetCell('B', 5) );
}

void COmdFileGm::t2oGamma()
{
	CString gammaIndex;

	for (int level = 0; level < PnGamma; ++level)
	{
		gammaIndex.Format("%d", level+1);
		m_omdRNA.Find("白", "gamma", gammaIndex, "0 255 255").GetBullet().i(VluK_Lv, GetCell('D', 3 + level) );
		m_omdRNA.Find("紅", "gamma", gammaIndex, "0 255 255").GetBullet().i(VluK_Lv, GetCell('E', 3 + level) );
		m_omdRNA.Find("綠", "gamma", gammaIndex, "0 255 255").GetBullet().i(VluK_Lv, GetCell('F', 3 + level) );
		m_omdRNA.Find("藍", "gamma", gammaIndex, "0 255 255").GetBullet().i(VluK_Lv, GetCell('G', 3 + level) );
		
		m_omdRNA.Find("白", "gamma", gammaIndex, "0 255 255").GetBullet().i(VluK_Sx, GetCell('H', 3 + level) );
		m_omdRNA.Find("紅", "gamma", gammaIndex, "0 255 255").GetBullet().i(VluK_Sx, GetCell('I', 3 + level) );
		m_omdRNA.Find("綠", "gamma", gammaIndex, "0 255 255").GetBullet().i(VluK_Sx, GetCell('J', 3 + level) );
		m_omdRNA.Find("藍", "gamma", gammaIndex, "0 255 255").GetBullet().i(VluK_Sx, GetCell('K', 3 + level) );
		
		m_omdRNA.Find("白", "gamma", gammaIndex, "0 255 255").GetBullet().i(VluK_Sy, GetCell('L', 3 + level) );
		m_omdRNA.Find("紅", "gamma", gammaIndex, "0 255 255").GetBullet().i(VluK_Sy, GetCell('M', 3 + level) );
		m_omdRNA.Find("綠", "gamma", gammaIndex, "0 255 255").GetBullet().i(VluK_Sy, GetCell('N', 3 + level) );
		m_omdRNA.Find("藍", "gamma", gammaIndex, "0 255 255").GetBullet().i(VluK_Sy, GetCell('O', 3 + level) );
		
		m_omdRNA.Find("白", "gamma", gammaIndex, "0 255 255").GetBullet().i(VluK_T  , GetCell('P', 3 + level) );
		m_omdRNA.Find("白", "gamma", gammaIndex, "0 255 255").GetBullet().i(VluK_Duv, GetCell('Q', 3 + level) );
	}
}
