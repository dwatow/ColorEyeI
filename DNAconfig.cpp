#include "StdAfx.h"
#include "DnaConfig.h"

DnaConfig::DnaConfig():
//   W            R            G            B            D   
m_chkWP1(0), m_chkRP1(0), m_chkGP1(0), m_chkBP1(0), m_chkDP1(0),   //中心點
m_chkWP5(0),                                                       //5點
m_chkWP9(0),                                        m_chkDP9(0),   //9點
m_chkWP49(0),                                                      //49點
                                                    m_chkDP13(0),  //13點
                                                    m_chkDP21(0),  //21點
                                                    m_chkDP25(0),  //25點
m_chkWGamma(0), m_chkRGamma(0), m_chkGGamma(0), m_chkBGamma(0), m_chkDGamma(0),

//OTHER
m_chkCrossTalk(0),
m_chkNits(0),

//control
m_msrQuick(0),

//para
m_W5FE(0),
m_W9FE(0), m_W9EdgeType(0),
m_D9FE(0), m_D9EdgeType(0),
m_D13FE(0),
m_D21FE(0),
m_D25FE(0), m_D25RectSide(0),
m_CTFE(0),
m_NitsLv(0), m_NitsDirect(0),
m_WGammaBegin(0), m_WGamma_End(0), m_WGamma_Avg(0),
m_RGammaBegin(0), m_RGamma_End(0), m_RGamma_Avg(0),
m_GGammaBegin(0), m_GGamma_End(0), m_GGamma_Avg(0),
m_BGammaBegin(0), m_BGamma_End(0), m_BGamma_Avg(0),
Ts(0)
{}

void DnaConfig::CreatDNA(DNA& _D, RNA& _R)
{
	Ts = new TranScripter();
	_R += selMsrItem2DNA_sortable();		
	_R += selMsrItem2DNA_CrossTalk();
	_R += selMsrItem2DNA_Gamma();
	delete Ts;
}

void DnaConfig::Add_WRGBD_center()
{
	Add_W_center();
	Add_R_center();
	Add_G_center();
	Add_B_center();
	Add_D_center();	
}
void DnaConfig::Add_W_center(){m_chkWP1 = TRUE;}
void DnaConfig::Add_R_center(){m_chkRP1 = TRUE;}
void DnaConfig::Add_G_center(){m_chkGP1 = TRUE;}
void DnaConfig::Add_B_center(){m_chkBP1 = TRUE;}
void DnaConfig::Add_D_center(){m_chkDP1 = TRUE;}

//W
void DnaConfig::Add_W_5(const int& fromEdgeNum, const int& fromEdgeType)
{
	m_W5FE = fromEdgeNum;
	m_chkWP5 = TRUE;
}

void DnaConfig::Add_W_9(const int& fromEdgeNum, const int& fromEdgeType)
{
	m_W9FE = fromEdgeNum;
	m_W9EdgeType = fromEdgeType;
	m_chkWP9 = TRUE;
}

void DnaConfig::Add_W_49(){m_chkWP49 = TRUE;}

//Dark
void DnaConfig::Add_D_9(const int& fromEdgeNum, const int& fromEdgeType)
{
	m_D9FE = fromEdgeNum;
	m_chkDP9 = TRUE;
}

void DnaConfig::Add_D_13(const int& fromEdgeNum, const int& fromEdgeType)
{
	m_D13FE = fromEdgeNum;
	m_chkDP13 = TRUE;
}

void DnaConfig::Add_D_21(const int& fromEdgeNum, const int& fromEdgeType)
{
	m_D21FE = fromEdgeNum;
	m_chkDP21 = TRUE;
}

void DnaConfig::Add_D_25(const int& fromEdgeNum, const int& rectSide)
{
	m_D25FE = fromEdgeNum;
	m_D25RectSide = rectSide;
	m_chkDP25 = TRUE;
}

//Other
void DnaConfig::Add_CrossTalk(const int& fromEdgeNum)
{
	m_CTFE = fromEdgeNum;
	m_chkCrossTalk = TRUE;
}

void DnaConfig::Add_Nits(const int& Lv, const int& direct)
{
	m_NitsLv = Lv;
	m_NitsDirect = direct;
	m_chkNits = TRUE;
}

//WRGB
void DnaConfig::Add_W_Gamma(const int& lvBegin,  const int& lvEnd, const int& lfAvgStep)
{
	m_WGammaBegin = lvBegin;
	m_WGamma_End = lvEnd;
	m_WGamma_Avg = lfAvgStep;
	m_chkWGamma = TRUE;
}

void DnaConfig::Add_R_Gamma(const int& lvBegin,  const int& lvEnd, const int& lfAvgStep)
{
	m_RGammaBegin = lvBegin;
	m_RGamma_End = lvEnd;
	m_RGamma_Avg = lfAvgStep;
	m_chkRGamma = TRUE;
}

void DnaConfig::Add_G_Gamma(const int& lvBegin,  const int& lvEnd, const int& lfAvgStep)
{
	m_GGammaBegin = lvBegin;
	m_GGamma_End = lvEnd;
	m_GGamma_Avg = lfAvgStep;
	m_chkGGamma = TRUE;
}

void DnaConfig::Add_B_Gamma(const int& lvBegin,  const int& lvEnd, const int& lfAvgStep)
{
	m_BGammaBegin = lvBegin;
	m_BGamma_End = lvEnd;
	m_BGamma_Avg = lfAvgStep;
	m_chkBGamma = TRUE;
}

RNA DnaConfig::selMsrItem2DNA_sortable()
{
	DNA dnaSortStable;
	RNA rnaSortStable;

    //修改的話，要同步修改
    //中心點
    if (m_chkWP1)  dnaSortStable.AddCell(White, Pn1);
    if (m_chkRP1)  dnaSortStable.AddCell(Red  , Pn1);
    if (m_chkGP1)  dnaSortStable.AddCell(Green, Pn1);
    if (m_chkBP1)  dnaSortStable.AddCell(Blue , Pn1);
    if (m_chkDP1)  dnaSortStable.AddCell(Dark , Pn1);
    
    //Nits
    if (m_chkNits)  dnaSortStable.AddCell(Nits, Pn9, m_NitsLv, m_NitsDirect);
    
    //5點
    if (m_chkWP5)    dnaSortStable.AddCell(White, Pn5, m_W5FE);
//     if (m_chkRP5)    dnaSortStable.AddCell(Red  , Pn5, W5FE);
//     if (m_chkGP5)    dnaSortStable.AddCell(Green, Pn5, W5FE);
//     if (m_chkBP5)    dnaSortStable.AddCell(Blue , Pn5, W5FE);
//     if (m_chkDP5)    dnaSortStable.AddCell(Dark , Pn5, W5FE);
    
    //9點
    if (m_chkWP9)    dnaSortStable.AddCell(White, Pn9, m_W9FE, m_W9EdgeType);
//     if (m_chkRP9)    dnaSortStable.AddCell(Red  , Pn9, W9FE, PA_FEover);
//     if (m_chkGP9)    dnaSortStable.AddCell(Green, Pn9, W9FE, PA_FEover);
//     if (m_chkBP9)    dnaSortStable.AddCell(Blue , Pn9, W9FE, PA_FEover);
    if (m_chkDP9)    dnaSortStable.AddCell(Dark , Pn9, m_D9FE, m_D9EdgeType);
    
    //21點
//     if (m_chkWP21)    dnaSortStable.AddCell(White, Pn21, D21FE);
//     if (m_chkRP21)    dnaSortStable.AddCell(Red  , Pn21, D21FE);
//     if (m_chkGP21)    dnaSortStable.AddCell(Green, Pn21, D21FE);
//     if (m_chkBP21)    dnaSortStable.AddCell(Blue , Pn21, D21FE);
    if (m_chkDP21)    dnaSortStable.AddCell(Dark , Pn21, m_D21FE);
    
    //13點
//     if (m_chkWP13)    dnaSortStable.AddCell(White, Pn13, D13FE);
//     if (m_chkRP13)    dnaSortStable.AddCell(Red  , Pn13, D13FE);
//     if (m_chkGP13)    dnaSortStable.AddCell(Green, Pn13, D13FE);
//     if (m_chkBP13)    dnaSortStable.AddCell(Blue , Pn13, D13FE);
    if (m_chkDP13)    dnaSortStable.AddCell(Dark , Pn13, m_D13FE);
    
    //25點
//     if (m_chkWP25)    dnaSortStable.AddCell(White, Pn25, D25FE, D25RectSide);
//     if (m_chkRP25)    dnaSortStable.AddCell(Red  , Pn25, D25FE, D25RectSide);
//     if (m_chkGP25)    dnaSortStable.AddCell(Green, Pn25, D25FE, D25RectSide);
//     if (m_chkBP25)    dnaSortStable.AddCell(Blue , Pn25, D25FE, D25RectSide);
    if (m_chkDP25)    dnaSortStable.AddCell(Dark , Pn25, m_D25FE, m_D25RectSide);
    
    //49點
    if (m_chkWP49)    dnaSortStable.AddCell(White, Pn49);
//     if (m_chkRP49)    dnaSortStable.AddCell(Red  , Pn49);
//     if (m_chkGP49)    dnaSortStable.AddCell(Green, Pn49);
//     if (m_chkBP49)    dnaSortStable.AddCell(Blue , Pn49);
//     if (m_chkDP49)    dnaSortStable.AddCell(Dark , Pn49);

	if (dnaSortStable.Size())
	{
		Ts->Trans(dnaSortStable, rnaSortStable);

		//排序
		if (m_msrQuick)  rnaSortStable.SortQuackMsr();
		else             rnaSortStable.SortOrigMsr();
	}

	showRNA(rnaSortStable);

	return rnaSortStable;
}

RNA DnaConfig::selMsrItem2DNA_CrossTalk()
{
	DNA dnaCrossTalk;
	RNA rnaCrossTalk;

    //Cross Talk
    if (m_chkCrossTalk)
    {
        dnaCrossTalk.AddCell(CrsTlk , Pn4, m_CTFE);
        dnaCrossTalk.AddCell(CrsTlkD, Pn4, m_CTFE);
        dnaCrossTalk.AddCell(CrsTlkW, Pn4, m_CTFE);
    }

	if (dnaCrossTalk.Size()) 
	{
		Ts->Trans(dnaCrossTalk, rnaCrossTalk);
		rnaCrossTalk.SortQuackMsr();
	}

	showRNA(rnaCrossTalk);

	return rnaCrossTalk;
	
}

RNA DnaConfig::selMsrItem2DNA_Gamma()
{
	DNA dnaGamma;
	RNA rnaGamma;
	//Gamma
    if (m_chkWGamma || m_chkDGamma)        
                        dnaGamma.AddCell(White, PnGamma, m_WGammaBegin, m_WGamma_End, m_WGamma_Avg );  
    if (m_chkRGamma)    dnaGamma.AddCell(Red  , PnGamma, m_RGammaBegin, m_RGamma_End, m_RGamma_Avg );
    if (m_chkGGamma)    dnaGamma.AddCell(Green, PnGamma, m_GGammaBegin, m_GGamma_End, m_GGamma_Avg );
    if (m_chkBGamma)    dnaGamma.AddCell(Blue , PnGamma, m_BGammaBegin, m_BGamma_End, m_BGamma_Avg );

	if (dnaGamma.Size()) 
	{
		Ts->Trans(dnaGamma, rnaGamma);
		rnaGamma.SortOrigMsr();
	}

	return rnaGamma;
}

void DnaConfig::Add_OmdFileDNA()
{
	Add_WRGBD_center();
	Add_Nits();
	Add_W_5();
	Add_W_9();
	Add_D_9();
	Add_D_21();
	Add_D_13();
	Add_D_25();
	Add_W_49();
	Add_CrossTalk();
}

void DnaConfig::Add_Table_OQC_MASS_TPV()
{
	Add_WRGBD_center();
	Add_W_9();
	Add_W_9(3, PA_FElength);
	Add_D_21();
	Add_W_Gamma();
	//check with OQC
}

void DnaConfig::Add_Table_OQC_MASS_SEC()
{
	Add_WRGBD_center();
	Add_Nits();
	Add_W_9();
	Add_W_5();
	Add_D_25();
	Add_W_Gamma();
	//check with OQC
}

void DnaConfig::Add_Table_RA()
{
	Add_W_9();
}

void DnaConfig::Add_Table_SEC()
{
	Add_WRGBD_center();
//	Add_W_9();  49 cover
	Add_W_49();
	Add_D_9();
	Add_Nits();
}

void DnaConfig::Add_Table_OQC_MASS_NIBO()
{
	Add_WRGBD_center();
	Add_W_9();
	Add_D_25();
	Add_CrossTalk();
	//check with OQC
}

void DnaConfig::Add_Table_OQC_TEST()
{
	Add_WRGBD_center();
	Add_W_9();
	Add_W_9(0);
	Add_D_25();
	Add_D_21();
	Add_Nits();
	Add_CrossTalk();
}
