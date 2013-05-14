#include "StdAfx.h"
#include "DNAfactory.h"
#include "TranScripter.h"

DnaFactory::DnaFactory():
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
msrQuick(0),

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
m_BGammaBegin(0), m_BGamma_End(0), m_BGamma_Avg(0)
{}

void DnaFactory::CreatDNA(DNA& _D, RNA& _R)
{
	DNA sortableDNA;
	
	selMsrItem2DNA_sortable(sortableDNA);
	
	TranScripter Ts;
	if (sortableDNA.Size()) Ts.Trans(sortableDNA, _R);
	_D + sortableDNA;
	//    sortableDNA.Empty();
	
	//排序
	if (msrQuick)  _R.SortQuackMsr();
	else           _R.SortOrigMsr();
	
	DNA UnsortableDNA;
	
	selMsrItem2DNA_Unsortable(UnsortableDNA);
	
	if (UnsortableDNA.Size()) Ts.Trans(UnsortableDNA, _R);
        _D + UnsortableDNA;
}

void DnaFactory::Add_WRGBD_center()
{
	Add_W_center();
	Add_R_center();
	Add_G_center();
	Add_B_center();
	Add_D_center();	
}
void DnaFactory::Add_W_center(){m_chkWP1 = TRUE;}
void DnaFactory::Add_R_center(){m_chkRP1 = TRUE;}
void DnaFactory::Add_G_center(){m_chkGP1 = TRUE;}
void DnaFactory::Add_B_center(){m_chkBP1 = TRUE;}
void DnaFactory::Add_D_center(){m_chkDP1 = TRUE;}

//W
void DnaFactory::Add_W_5(const int& fromEdgeNum, const int& fromEdgeType)
{
	m_W5FE = fromEdgeNum;
	m_chkWP5 = TRUE;
}

void DnaFactory::Add_W_9(const int& fromEdgeNum, const int& fromEdgeType)
{
	m_W9FE = fromEdgeNum;
	m_W9EdgeType = fromEdgeType;
	m_chkWP9 = TRUE;
}

void DnaFactory::Add_W_49(){m_chkWP49 = TRUE;}

//Dark
void DnaFactory::Add_D_9(const int& fromEdgeNum, const int& fromEdgeType)
{
	m_D9FE = fromEdgeNum;
	m_chkDP9 = TRUE;
}

void DnaFactory::Add_D_13(const int& fromEdgeNum, const int& fromEdgeType)
{
	m_D13FE = fromEdgeNum;
	m_chkDP13 = TRUE;
}

void DnaFactory::Add_D_21(const int& fromEdgeNum, const int& fromEdgeType)
{
	m_D21FE = fromEdgeNum;
	m_chkDP21 = TRUE;
}

void DnaFactory::Add_D_25(const int& fromEdgeNum, const int& rectSide)
{
	m_D25FE = fromEdgeNum;
	m_D25RectSide = rectSide;
	m_chkDP25 = TRUE;
}

//Other
void DnaFactory::Add_CrossTalk(const int& fromEdgeNum)
{
	m_CTFE = fromEdgeNum;
	m_chkCrossTalk = TRUE;
}

void DnaFactory::Add_Nits(const int& Lv, const int& direct)
{
	m_NitsLv = Lv;
	m_NitsDirect = direct;
	m_chkNits = TRUE;
}

//WRGB
void DnaFactory::Add_W_Gamma(const int& lvBegin,  const int& lvEnd, const int& lfAvgStep)
{
	m_WGammaBegin = lvBegin;
	m_WGamma_End = lvEnd;
	m_WGamma_Avg = lfAvgStep;
	m_chkWGamma = TRUE;
}

void DnaFactory::Add_R_Gamma(const int& lvBegin,  const int& lvEnd, const int& lfAvgStep)
{
	m_RGammaBegin = lvBegin;
	m_RGamma_End = lvEnd;
	m_RGamma_Avg = lfAvgStep;
	m_chkRGamma = TRUE;
}

void DnaFactory::Add_G_Gamma(const int& lvBegin,  const int& lvEnd, const int& lfAvgStep)
{
	m_GGammaBegin = lvBegin;
	m_GGamma_End = lvEnd;
	m_GGamma_Avg = lfAvgStep;
	m_chkGGamma = TRUE;
}

void DnaFactory::Add_B_Gamma(const int& lvBegin,  const int& lvEnd, const int& lfAvgStep)
{
	m_BGammaBegin = lvBegin;
	m_BGamma_End = lvEnd;
	m_BGamma_Avg = lfAvgStep;
	m_chkBGamma = TRUE;
}

void DnaFactory::selMsrItem2DNA_sortable(DNA& sortableDNA)
{
    //修改的話，要同步修改
    //中心點
    if (m_chkWP1)  sortableDNA.AddCell(White, Pn1);
    if (m_chkRP1)  sortableDNA.AddCell(Red  , Pn1);
    if (m_chkGP1)  sortableDNA.AddCell(Green, Pn1);
    if (m_chkBP1)  sortableDNA.AddCell(Blue , Pn1);
    if (m_chkDP1)  sortableDNA.AddCell(Dark , Pn1);
    
    //Nits
    if (m_chkNits)  sortableDNA.AddCell(Nits, Pn9, m_NitsLv, m_NitsDirect);
    
    //5點
    if (m_chkWP5)    sortableDNA.AddCell(White, Pn5, m_W5FE);
//     if (m_chkRP5)    sortableDNA.AddCell(Red  , Pn5, W5FE);
//     if (m_chkGP5)    sortableDNA.AddCell(Green, Pn5, W5FE);
//     if (m_chkBP5)    sortableDNA.AddCell(Blue , Pn5, W5FE);
//     if (m_chkDP5)    sortableDNA.AddCell(Dark , Pn5, W5FE);
    
    //9點
    if (m_chkWP9)    sortableDNA.AddCell(White, Pn9, m_W9FE, m_W9EdgeType);
//     if (m_chkRP9)    sortableDNA.AddCell(Red  , Pn9, W9FE, PA_FEover);
//     if (m_chkGP9)    sortableDNA.AddCell(Green, Pn9, W9FE, PA_FEover);
//     if (m_chkBP9)    sortableDNA.AddCell(Blue , Pn9, W9FE, PA_FEover);
    if (m_chkDP9)    sortableDNA.AddCell(Dark , Pn9, m_D9FE, m_D9EdgeType);
    
    //21點
//     if (m_chkWP21)    sortableDNA.AddCell(White, Pn21, D21FE);
//     if (m_chkRP21)    sortableDNA.AddCell(Red  , Pn21, D21FE);
//     if (m_chkGP21)    sortableDNA.AddCell(Green, Pn21, D21FE);
//     if (m_chkBP21)    sortableDNA.AddCell(Blue , Pn21, D21FE);
    if (m_chkDP21)    sortableDNA.AddCell(Dark , Pn21, m_D21FE);
    
    //13點
//     if (m_chkWP13)    sortableDNA.AddCell(White, Pn13, D13FE);
//     if (m_chkRP13)    sortableDNA.AddCell(Red  , Pn13, D13FE);
//     if (m_chkGP13)    sortableDNA.AddCell(Green, Pn13, D13FE);
//     if (m_chkBP13)    sortableDNA.AddCell(Blue , Pn13, D13FE);
    if (m_chkDP13)    sortableDNA.AddCell(Dark , Pn13, m_D13FE);
    
    //25點
//     if (m_chkWP25)    sortableDNA.AddCell(White, Pn25, D25FE, D25RectSide);
//     if (m_chkRP25)    sortableDNA.AddCell(Red  , Pn25, D25FE, D25RectSide);
//     if (m_chkGP25)    sortableDNA.AddCell(Green, Pn25, D25FE, D25RectSide);
//     if (m_chkBP25)    sortableDNA.AddCell(Blue , Pn25, D25FE, D25RectSide);
    if (m_chkDP25)    sortableDNA.AddCell(Dark , Pn25, m_D25FE, m_D25RectSide);
    
    //49點
    if (m_chkWP49)    sortableDNA.AddCell(White, Pn49);
//     if (m_chkRP49)    sortableDNA.AddCell(Red  , Pn49);
//     if (m_chkGP49)    sortableDNA.AddCell(Green, Pn49);
//     if (m_chkBP49)    sortableDNA.AddCell(Blue , Pn49);
//     if (m_chkDP49)    sortableDNA.AddCell(Dark , Pn49);
}
void DnaFactory::selMsrItem2DNA_Unsortable(DNA& unsortableDNA)
{
    //Cross Talk
    if (m_chkCrossTalk)
    {
        unsortableDNA.AddCell(CrsTlk , Pn4, m_CTFE);
        unsortableDNA.AddCell(CrsTlkD, Pn4, m_CTFE);
        unsortableDNA.AddCell(CrsTlkW, Pn4, m_CTFE);
    }
	//Gamma
    if (m_chkWGamma || m_chkDGamma)        
                        unsortableDNA.AddCell(White, PnGamma, m_WGammaBegin, m_WGamma_End, m_WGamma_Avg );  
    if (m_chkRGamma)    unsortableDNA.AddCell(Red  , PnGamma, m_RGammaBegin, m_RGamma_End, m_RGamma_Avg );
    if (m_chkGGamma)    unsortableDNA.AddCell(Green, PnGamma, m_GGammaBegin, m_GGamma_End, m_GGamma_Avg );
    if (m_chkBGamma)    unsortableDNA.AddCell(Blue , PnGamma, m_BGammaBegin, m_BGamma_End, m_BGamma_Avg );
}

void DnaFactory::Add_OmdFileDNA()
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

void DnaFactory::Add_Table_OQC_MASS_TPV()
{
	Add_WRGBD_center();
	Add_W_9();
	Add_W_9(3, PA_FElength);
	Add_D_25();
}

void DnaFactory::Add_Table_OQC_MASS_SEC()
{}

void DnaFactory::Add_Table_RA()
{
	Add_W_9();
}

void DnaFactory::Add_Table_SEC()
{
	Add_WRGBD_center();
//	Add_W_9();
	Add_W_49();
	Add_D_9();
	Add_Nits();
}
