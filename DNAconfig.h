#ifndef DNACONFIG_H
#define DNACONFIG_H

#include "DNA.h"
#include "RNA.h"
#include "BkMaker.h"  //ND_Neg, ND_Pos
#include "TranScripter.h"
#include "debugFile.h"
#include "ColorEyeI.h"

//enum ParaOfPara  { PA_FEover = 0, PA_FElength, PA_D25RectSide, PA_NitsLv, PA_NitsDir, PA_JndGrayLv, PA_GmaBegin, PA_GmaEnd, PA_GmaAvg, PA_Max};
//NitsDirect

#define NitsLv 5

#define W5FE 0
#define W9FE 6
#define D9FE 0
#define D13FE 0
#define D21FE 0
#define D25FE 0
#define D25RectSide 10

#define CrossTalkCenterRectFE 4

#define GammaBeginLv 0
#define GammaEndLv 255
#define GammaAvg 255


class DnaConfig
{
//          W       R       G       B       D
	BOOL m_chkWP1, m_chkRP1, m_chkGP1, m_chkBP1, m_chkDP1;   //ㄴㅯ헕
	BOOL m_chkWP5                                ;   //5헕
	BOOL m_chkWP9,                         m_chkDP9;   //9헕
	BOOL m_chkWP49                                ;  //49헕
	BOOL                                 m_chkDP13;  //13헕
	BOOL                                 m_chkDP21;  //21헕
	BOOL                                 m_chkDP25;  //25헕
	BOOL m_chkWGamma, m_chkRGamma, m_chkGGamma, m_chkBGamma, m_chkDGamma;

	//OTHER
	BOOL m_chkCrossTalk;
	BOOL m_chkNits;

	//control
	BOOL m_msrQuick;

	//para
	int m_W5FE, m_W5EdgeType;
	int m_W9FE, m_W9EdgeType;
	int m_D9FE, m_D9EdgeType;
	int m_D13FE, m_W13EdgeType;
	int m_D21FE, m_W21EdgeType;
	int m_D25FE, m_W25EdgeType, m_D25RectSide;
	int m_CTFE, m_CTEdgeType;
	int m_NitsLv, m_NitsDirect;
	int m_WGammaBegin, m_WGamma_End, m_WGamma_Avg;
	int m_RGammaBegin, m_RGamma_End, m_RGamma_Avg;
	int m_GGammaBegin, m_GGamma_End, m_GGamma_Avg;
	int m_BGammaBegin, m_BGamma_End, m_BGamma_Avg;

	TranScripter *Ts;
public:
	DnaConfig();
	void SetQuickSort(const BOOL& _B);
	void Add_WRGBD_center();
	void Add_W_center();
	void Add_R_center();
	void Add_G_center();
	void Add_B_center();
	void Add_D_center();
//W
	void Add_W_5(const int& fromEdgeNum = W5FE, const int& fromEdgeType = PA_FEover);
	void Add_W_9(const int& fromEdgeNum = W9FE, const int& fromEdgeType = PA_FEover);
	void Add_W_49();
//Dark
	void Add_D_9(const int& fromEdgeNum = D9FE, const int& fromEdgeType = PA_FEover);
	void Add_D_13(const int& fromEdgeNum = D13FE, const int& fromEdgeType = PA_FEover);
	void Add_D_21(const int& fromEdgeNum = D21FE, const int& fromEdgeType = PA_FEover);
	void Add_D_25(const int& fromEdgeNum = D25FE, const int& rectSide = D25RectSide);
//Other
	void Add_CrossTalk(const int& fromEdgeNum = CrossTalkCenterRectFE);
	void Add_Nits(const int& Lv = NitsLv, const int& direct = ND_Neg);
//WRGB
	void Add_W_Gamma(const int& lvBegin = GammaBeginLv,  const int& lvEnd = GammaEndLv, const int& lfStep = GammaAvg);
	void Add_R_Gamma(const int& lvBegin = GammaBeginLv,  const int& lvEnd = GammaEndLv, const int& lfStep = GammaAvg);
	void Add_G_Gamma(const int& lvBegin = GammaBeginLv,  const int& lvEnd = GammaEndLv, const int& lfStep = GammaAvg);
	void Add_B_Gamma(const int& lvBegin = GammaBeginLv,  const int& lvEnd = GammaEndLv, const int& lfStep = GammaAvg);

//for Omd file
	void Add_Omd();
	void Add_Omd_Gamma();
	void Add_Table_OQC_MASS_TPV();
	void Add_Table_OQC_MASS_SEC();
	void Add_Table_RA();
	void Add_Table_SEC();
	void Add_Table_OQC_MASS_NIBO();
	void Add_Table_OQC_TEST();

	void CreatRNA(DNA&, RNA&);
private:
	RNA add_DNA_WRGBD(DNA&);
	RNA add_DNA_CrossTalk(DNA&);
	RNA add_DNA_Gamma(DNA&);
	void showRNA(RNA& ) ;
};

inline void DnaConfig::showRNA(RNA& _R) 
{
	debugFile df;
	for (std::vector<Cartridge2>::iterator itor = _R.Begin(); itor != _R.End(); ++itor)
		df.Add( itor->ShowMe() );

	CString pathDesktop;
	CColorEyeIApp *pApp = dynamic_cast<CColorEyeIApp*>(AfxGetApp());
	pathDesktop.Format("%s\\DNAconfig.log", pApp->GetDesktopPath());
	df.Out2File(pathDesktop);
}

inline 	void DnaConfig::SetQuickSort(const BOOL& _B)
{
	m_msrQuick = _B;
}

#endif