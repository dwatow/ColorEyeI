// OmdFile1.cpp: implementation of the COmdFile1 class.
//
//////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "COmdFile1.h"
#include "../TranScripter.h"
#include "../MainFrm.h"

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

void COmdFile1::OmdToTxt()
{
	CString& PanelId    = m_omdFileHead.oPnlID();
	CString& MsrDevice  = m_omdFileHead.oMsrDvc();
	CString& ProbeIndex = m_omdFileHead.oPrb();
	CString& ChannelId  = m_omdFileHead.oCHID();
	CString& LcmInch    = m_omdFileHead.oInch();
    
	m_dTxt.push_back("Panel ID\t" + PanelId + "\tMeasurement device\t" + MsrDevice + "\tProbe\t" + ProbeIndex + "\tCH\t" + ChannelId + "\tInch\t" + LcmInch + "\n");

	o2tWRGB1nNits();
	o2tW9nD1();
	o2tD9();    
	o2tCT();
	o2tD25();
	o2tW49_01to28();
	o2tW49_29to49();
	o2tD21();
	o2tD13();
	o2tW5();

    m_fTxt.iTxtData(m_dTxt);
}

void COmdFile1::o2tWRGB1nNits()
{
	CString& NitsGray   = m_omdFileHead.oNitsLv();
    m_dTxt.push_back("中心點\tL\tx\ty\tu'\tv'\t5nits 9點均齊度\tL\t\t\t\t\t5nits 9點均齊度\tx\t\t\t\t\t5nits 9點均齊度\ty\t\t\t\t\t5nits 9點均齊度\tT\t\t\t\t\t5nits 9點均齊度\tduv\n");
    m_dTxt.push_back("白色\t" + m_dOmd.sFind("白","1","1"," ",VluK_Lv) + "\t" + m_dOmd.sFind("白","1","1"," ",VluK_Sx) + "\t" + m_dOmd.sFind("白","1","1"," ",VluK_Sy) + "\t" + m_dOmd.sFind("白","1","1"," ",VluK_Du) + "\t" + m_dOmd.sFind("白","1","1"," ",VluK_Dv) + "\t灰階:" + NitsGray + "\t" + m_dOmd.sFind("Nits","9","1","5-",VluK_Lv) + "\t" + m_dOmd.sFind("Nits","9","2","5-",VluK_Lv) + "\t" + m_dOmd.sFind("Nits","9","3","5-",VluK_Lv) + "\t\t\t\t" + m_dOmd.sFind("Nits","9","1","5-",VluK_Sx) + "\t" + m_dOmd.sFind("Nits","9","2","5-",VluK_Sx) + "\t" + m_dOmd.sFind("Nits","9","3","5-",VluK_Sx) + "\t\t\t\t" + m_dOmd.sFind("Nits","9","1","5-",VluK_Sy) + "\t" + m_dOmd.sFind("Nits","9","2","5-",VluK_Sy) + "\t" + m_dOmd.sFind("Nits","9","3","5-",VluK_Sy) + "\t\t\t\t" + m_dOmd.sFind("Nits","9","1","5-",VluK_T) + "\t" + m_dOmd.sFind("Nits","9","2","5-",VluK_T) + "\t" + m_dOmd.sFind("Nits","9","3","5-",VluK_T) + "\t\t\t\t" + m_dOmd.sFind("Nits","9","1","5-",VluK_Duv) + "\t" + m_dOmd.sFind("Nits","9","2","5-",VluK_Duv) + "\t" + m_dOmd.sFind("Nits","9","3","5-",VluK_Duv) + "\n");
    m_dTxt.push_back("紅色\t" + m_dOmd.sFind("紅","1","1"," ",VluK_Lv) + "\t" + m_dOmd.sFind("紅","1","1"," ",VluK_Sx) + "\t" + m_dOmd.sFind("紅","1","1"," ",VluK_Sy) + "\t" + m_dOmd.sFind("紅","1","1"," ",VluK_Du) + "\t" + m_dOmd.sFind("紅","1","1"," ",VluK_Dv) + "\t\t"                     + m_dOmd.sFind("Nits","9","4","5-",VluK_Lv) + "\t" + m_dOmd.sFind("Nits","9","5","5-",VluK_Lv) + "\t" + m_dOmd.sFind("Nits","9","6","5-",VluK_Lv) + "\t\t\t\t" + m_dOmd.sFind("Nits","9","4","5-",VluK_Sx) + "\t" + m_dOmd.sFind("Nits","9","5","5-",VluK_Sx) + "\t" + m_dOmd.sFind("Nits","9","6","5-",VluK_Sx) + "\t\t\t\t" + m_dOmd.sFind("Nits","9","4","5-",VluK_Sy) + "\t" + m_dOmd.sFind("Nits","9","5","5-",VluK_Sy) + "\t" + m_dOmd.sFind("Nits","9","6","5-",VluK_Sy) + "\t\t\t\t" + m_dOmd.sFind("Nits","9","4","5-",VluK_T) + "\t" + m_dOmd.sFind("Nits","9","5","5-",VluK_T) + "\t" + m_dOmd.sFind("Nits","9","6","5-",VluK_T) + "\t\t\t\t" + m_dOmd.sFind("Nits","9","4","5-",VluK_Duv) + "\t" + m_dOmd.sFind("Nits","9","5","5-",VluK_Duv) + "\t" + m_dOmd.sFind("Nits","9","6","5-",VluK_Duv) + "\n");
    m_dTxt.push_back("綠色\t" + m_dOmd.sFind("綠","1","1"," ",VluK_Lv) + "\t" + m_dOmd.sFind("綠","1","1"," ",VluK_Sx) + "\t" + m_dOmd.sFind("綠","1","1"," ",VluK_Sy) + "\t" + m_dOmd.sFind("綠","1","1"," ",VluK_Du) + "\t" + m_dOmd.sFind("綠","1","1"," ",VluK_Dv) + "\t\t"                     + m_dOmd.sFind("Nits","9","7","5-",VluK_Lv) + "\t" + m_dOmd.sFind("Nits","9","8","5-",VluK_Lv) + "\t" + m_dOmd.sFind("Nits","9","9","5-",VluK_Lv) + "\t\t\t\t" + m_dOmd.sFind("Nits","9","7","5-",VluK_Sx) + "\t" + m_dOmd.sFind("Nits","9","8","5-",VluK_Sx) + "\t" + m_dOmd.sFind("Nits","9","9","5-",VluK_Sx) + "\t\t\t\t" + m_dOmd.sFind("Nits","9","7","5-",VluK_Sy) + "\t" + m_dOmd.sFind("Nits","9","8","5-",VluK_Sy) + "\t" + m_dOmd.sFind("Nits","9","9","5-",VluK_Sy) + "\t\t\t\t" + m_dOmd.sFind("Nits","9","7","5-",VluK_T) + "\t" + m_dOmd.sFind("Nits","9","8","5-",VluK_T) + "\t" + m_dOmd.sFind("Nits","9","9","5-",VluK_T) + "\t\t\t\t" + m_dOmd.sFind("Nits","9","7","5-",VluK_Duv) + "\t" + m_dOmd.sFind("Nits","9","8","5-",VluK_Duv) + "\t" + m_dOmd.sFind("Nits","9","9","5-",VluK_Duv) + "\n");
    m_dTxt.push_back("藍色\t" + m_dOmd.sFind("藍","1","1"," ",VluK_Lv) + "\t" + m_dOmd.sFind("藍","1","1"," ",VluK_Sx) + "\t" + m_dOmd.sFind("藍","1","1"," ",VluK_Sy) + "\t" + m_dOmd.sFind("藍","1","1"," ",VluK_Du) + "\t" + m_dOmd.sFind("藍","1","1"," ",VluK_Dv) + "\n");
}
void COmdFile1::o2tW9nD1()
{
    m_dTxt.push_back("Dark \t" + m_dOmd.sFind("黑","1","1"," ",VluK_Lv) + "\t" + m_dOmd.sFind("黑","1","1"," ",VluK_Sx) + "\t" + m_dOmd.sFind("黑","1","1"," ",VluK_Sy) + "\t" + m_dOmd.sFind("黑","1","1"," ",VluK_Du) + "\t" + m_dOmd.sFind("黑","1","1"," ",VluK_Dv) + "\t" + "9點均齊度\tL\t\t\t\t\t9點均齊度\tx\t\t\t\t\t9點均齊度\ty\t\t\t\t\t9點均齊度\tT\t\t\t\t\t9點均齊度\tduv\n");
    m_dTxt.push_back("\t\t\t\t\t\t離邊6分之1\t" + m_dOmd.sFind("白","9","1","1/6",VluK_Lv) + "\t" + m_dOmd.sFind("白","9","2","1/6",VluK_Lv) + "\t" + m_dOmd.sFind("白","9","3","1/6",VluK_Lv) + "\t\t\t\t" + m_dOmd.sFind("白","9","1","1/6",VluK_Sx) + "\t" + m_dOmd.sFind("白","9","2","1/6",VluK_Sx) + "\t" + m_dOmd.sFind("白","9","3","1/6",VluK_Sx) + "\t\t\t\t" + m_dOmd.sFind("白","9","1","1/6",VluK_Sy) + "\t" + m_dOmd.sFind("白","9","2","1/6",VluK_Sy) + "\t" + m_dOmd.sFind("白","9","3","1/6",VluK_Sy) + "\t\t\t\t" + m_dOmd.sFind("白","9","1","1/6",VluK_T) + "\t" + m_dOmd.sFind("白","9","2","1/6",VluK_T) + "\t" + m_dOmd.sFind("白","9","3","1/6",VluK_T) + "\t\t\t\t" + m_dOmd.sFind("白","9","1","1/6",VluK_Duv) + "\t" + m_dOmd.sFind("白","9","2","1/6",VluK_Duv) + "\t" + m_dOmd.sFind("白","9","3","1/6",VluK_Duv) + "\n");
    m_dTxt.push_back("\t\t\t\t\t\t\t"          + m_dOmd.sFind("白","9","4","1/6",VluK_Lv) + "\t" + m_dOmd.sFind("白","9","5","1/6",VluK_Lv) + "\t" + m_dOmd.sFind("白","9","6","1/6",VluK_Lv) + "\t\t\t\t" + m_dOmd.sFind("白","9","4","1/6",VluK_Sx) + "\t" + m_dOmd.sFind("白","9","5","1/6",VluK_Sx) + "\t" + m_dOmd.sFind("白","9","6","1/6",VluK_Sx) + "\t\t\t\t" + m_dOmd.sFind("白","9","4","1/6",VluK_Sy) + "\t" + m_dOmd.sFind("白","9","5","1/6",VluK_Sy) + "\t" + m_dOmd.sFind("白","9","6","1/6",VluK_Sy) + "\t\t\t\t" + m_dOmd.sFind("白","9","4","1/6",VluK_T) + "\t" + m_dOmd.sFind("白","9","5","1/6",VluK_T) + "\t" + m_dOmd.sFind("白","9","6","1/6",VluK_T) + "\t\t\t\t" + m_dOmd.sFind("白","9","4","1/6",VluK_Duv) + "\t" + m_dOmd.sFind("白","9","5","1/6",VluK_Duv) + "\t" + m_dOmd.sFind("白","9","6","1/6",VluK_Duv) + "\n");
    m_dTxt.push_back("\t\t\t\t\t\t\t"          + m_dOmd.sFind("白","9","7","1/6",VluK_Lv) + "\t" + m_dOmd.sFind("白","9","8","1/6",VluK_Lv) + "\t" + m_dOmd.sFind("白","9","9","1/6",VluK_Lv) + "\t\t\t\t" + m_dOmd.sFind("白","9","7","1/6",VluK_Sx) + "\t" + m_dOmd.sFind("白","9","8","1/6",VluK_Sx) + "\t" + m_dOmd.sFind("白","9","9","1/6",VluK_Sx) + "\t\t\t\t" + m_dOmd.sFind("白","9","7","1/6",VluK_Sy) + "\t" + m_dOmd.sFind("白","9","8","1/6",VluK_Sy) + "\t" + m_dOmd.sFind("白","9","9","1/6",VluK_Sy) + "\t\t\t\t" + m_dOmd.sFind("白","9","7","1/6",VluK_T) + "\t" + m_dOmd.sFind("白","9","8","1/6",VluK_T) + "\t" + m_dOmd.sFind("白","9","9","1/6",VluK_T) + "\t\t\t\t" + m_dOmd.sFind("白","9","7","1/6",VluK_Duv) + "\t" + m_dOmd.sFind("白","9","8","1/6",VluK_Duv) + "\t" + m_dOmd.sFind("白","9","9","1/6",VluK_Duv) + "\n");
    m_dTxt.push_back("\n");
}
void COmdFile1::o2tD9()
{
    m_dTxt.push_back("\t\t\t\t\t\t黑色9點均齊度\tL\t\t\t\t\t黑色9點均齊度\tx\t\t\t\t\t黑色9點均齊度\ty\t\t\t\t\t黑色9點均齊度\tT\t\t\t\t\t黑色9點均齊度\tduv\n");
    m_dTxt.push_back("\t\t\t\t\t\t\t" + m_dOmd.sFind("黑","9","1","0",VluK_Lv) + "\t" + m_dOmd.sFind("黑","9","2","0",VluK_Lv) + "\t" + m_dOmd.sFind("黑","9","3","0",VluK_Lv) + "\t\t\t\t" + m_dOmd.sFind("黑","9","1","0",VluK_Sx) + "\t" + m_dOmd.sFind("黑","9","2","0",VluK_Sx) + "\t" + m_dOmd.sFind("黑","9","3","0",VluK_Sx) + "\t\t\t\t" + m_dOmd.sFind("黑","9","1","0",VluK_Sy) + "\t" + m_dOmd.sFind("黑","9","2","0",VluK_Sy) + "\t" + m_dOmd.sFind("黑","9","3","0",VluK_Sy) + "\t\t\t\t" + m_dOmd.sFind("黑","9","1","0",VluK_T) + "\t" + m_dOmd.sFind("黑","9","2","0",VluK_T) + "\t" + m_dOmd.sFind("黑","9","3","0",VluK_T) + "\t\t\t\t" + m_dOmd.sFind("黑","9","1","0",VluK_Duv) + "\t" + m_dOmd.sFind("黑","9","2","0",VluK_Duv) + "\t" + m_dOmd.sFind("黑","9","3","0",VluK_Duv) + "\n");
    m_dTxt.push_back("\t\t\t\t\t\t\t" + m_dOmd.sFind("黑","9","4","0",VluK_Lv) + "\t" + m_dOmd.sFind("黑","9","5","0",VluK_Lv) + "\t" + m_dOmd.sFind("黑","9","6","0",VluK_Lv) + "\t\t\t\t" + m_dOmd.sFind("黑","9","4","0",VluK_Sx) + "\t" + m_dOmd.sFind("黑","9","5","0",VluK_Sx) + "\t" + m_dOmd.sFind("黑","9","6","0",VluK_Sx) + "\t\t\t\t" + m_dOmd.sFind("黑","9","4","0",VluK_Sy) + "\t" + m_dOmd.sFind("黑","9","5","0",VluK_Sy) + "\t" + m_dOmd.sFind("黑","9","6","0",VluK_Sy) + "\t\t\t\t" + m_dOmd.sFind("黑","9","4","0",VluK_T) + "\t" + m_dOmd.sFind("黑","9","5","0",VluK_T) + "\t" + m_dOmd.sFind("黑","9","6","0",VluK_T) + "\t\t\t\t" + m_dOmd.sFind("黑","9","4","0",VluK_Duv) + "\t" + m_dOmd.sFind("黑","9","5","0",VluK_Duv) + "\t" + m_dOmd.sFind("黑","9","6","0",VluK_Duv) + "\n");
    m_dTxt.push_back("\t\t\t\t\t\t\t" + m_dOmd.sFind("黑","9","7","0",VluK_Lv) + "\t" + m_dOmd.sFind("黑","9","8","0",VluK_Lv) + "\t" + m_dOmd.sFind("黑","9","9","0",VluK_Lv) + "\t\t\t\t" + m_dOmd.sFind("黑","9","7","0",VluK_Sx) + "\t" + m_dOmd.sFind("黑","9","8","0",VluK_Sx) + "\t" + m_dOmd.sFind("黑","9","9","0",VluK_Sx) + "\t\t\t\t" + m_dOmd.sFind("黑","9","7","0",VluK_Sy) + "\t" + m_dOmd.sFind("黑","9","8","0",VluK_Sy) + "\t" + m_dOmd.sFind("黑","9","9","0",VluK_Sy) + "\t\t\t\t" + m_dOmd.sFind("黑","9","7","0",VluK_T) + "\t" + m_dOmd.sFind("黑","9","8","0",VluK_T) + "\t" + m_dOmd.sFind("黑","9","9","0",VluK_T) + "\t\t\t\t" + m_dOmd.sFind("黑","9","7","0",VluK_Duv) + "\t" + m_dOmd.sFind("黑","9","8","0",VluK_Duv) + "\t" + m_dOmd.sFind("黑","9","9","0",VluK_Duv) + "\n");
    m_dTxt.push_back("\n");
}

void COmdFile1::o2tCT()
{
    m_dTxt.push_back("\t\t\t\t\t\tCross Talk\tYa\t\t\t\t\tCross Talk\tYb\t\t\t\t\tCross Talk\tYb\n");
    m_dTxt.push_back("\t\t\t\t\t\t\t\t"                                               + m_dOmd.sFind("cross","4","1","1/4",VluK_Lv) +                                                 "\t\t\t\t\t\t"                                                 + m_dOmd.sFind("crossW","4","1","1/4",VluK_Lv) +                                                 "\t\t\t\t\t\t"                                               + m_dOmd.sFind("crossD","4","1","1/4",VluK_Lv) + "\n");
    m_dTxt.push_back("\t\t\t\t\t\t\t" + m_dOmd.sFind("cross","4","2","1/4",VluK_Lv) +                    "\t灰\t"                   + m_dOmd.sFind("cross","4","3","1/4",VluK_Lv) +   "\t\t\t\t"   + m_dOmd.sFind("crossW","4","2","1/4",VluK_Lv) +                      "\t白\t"                  + m_dOmd.sFind("crossW","4","3","1/4",VluK_Lv) + "\t\t\t\t" + m_dOmd.sFind("crossD","4","2","1/4",VluK_Lv) +                     "\t黑\t"                   + m_dOmd.sFind("crossD","4","3","1/4",VluK_Lv) + "\n");
    m_dTxt.push_back("\t\t\t\t\t\t\t\t"                                               + m_dOmd.sFind("cross","4","4","1/4",VluK_Lv) +                                                 "\t\t\t\t\t\t"                                                  + m_dOmd.sFind("crossW","4","4","1/4",VluK_Lv) +                                                 "\t\t\t\t\t\t"                                              + m_dOmd.sFind("crossD","4","4","1/4",VluK_Lv) + "\n");
    m_dTxt.push_back("\n\n\n\n");
}

void COmdFile1::o2tD25()
{
    m_dTxt.push_back("\t\t\t\t\t\t25點暗態\tL\t\t\t\t\t\t\t25點暗態\tx\t\t\t\t\t\t\t25點暗態\ty\t\t\t\t\t\t\t25點暗態\tT\t\t\t\t\t\t\t25點暗態\tduv\n");
    
    m_dTxt.push_back("\t\t\t\t\t\t\t" + 
        m_dOmd.sFind("黑","25","1","0",VluK_Lv)  + "\t\t" + m_dOmd.sFind("黑","25","2","0",VluK_Lv)  + "\t" + m_dOmd.sFind("黑","25","6","0",VluK_Lv)  + "\t" + m_dOmd.sFind("黑","25","8","0",VluK_Lv)  + "\t\t" + m_dOmd.sFind("黑","25","7","0",VluK_Lv)  + "\t\t" +
        m_dOmd.sFind("黑","25","1","0",VluK_Sx)  + "\t\t" + m_dOmd.sFind("黑","25","2","0",VluK_Sx)  + "\t" + m_dOmd.sFind("黑","25","6","0",VluK_Sx)  + "\t" + m_dOmd.sFind("黑","25","8","0",VluK_Sx)  + "\t\t" + m_dOmd.sFind("黑","25","7","0",VluK_Sx)  + "\t\t" +
        m_dOmd.sFind("黑","25","1","0",VluK_Sy)  + "\t\t" + m_dOmd.sFind("黑","25","2","0",VluK_Sy)  + "\t" + m_dOmd.sFind("黑","25","6","0",VluK_Sy)  + "\t" + m_dOmd.sFind("黑","25","8","0",VluK_Sy)  + "\t\t" + m_dOmd.sFind("黑","25","7","0",VluK_Sy)  + "\t\t" +
        m_dOmd.sFind("黑","25","1","0",VluK_T)   + "\t\t" + m_dOmd.sFind("黑","25","2","0",VluK_T)   + "\t" + m_dOmd.sFind("黑","25","6","0",VluK_T)   + "\t" + m_dOmd.sFind("黑","25","8","0",VluK_T)   + "\t\t" + m_dOmd.sFind("黑","25","7","0",VluK_T)   + "\t\t" +
        m_dOmd.sFind("黑","25","1","0",VluK_Duv) + "\t\t" + m_dOmd.sFind("黑","25","2","0",VluK_Duv) + "\t" + m_dOmd.sFind("黑","25","6","0",VluK_Duv) + "\t" + m_dOmd.sFind("黑","25","8","0",VluK_Duv) + "\t\t" + m_dOmd.sFind("黑","25","7","0",VluK_Duv) + "\n");
    
    m_dTxt.push_back("\t\t\t\t\t\t\t\t" +
        m_dOmd.sFind("黑","25","5","0",VluK_Lv)  + "\t\t\t\t" + m_dOmd.sFind("黑","25","11","0",VluK_Lv)  + "\t\t\t\t" +
        m_dOmd.sFind("黑","25","5","0",VluK_Sx)  + "\t\t\t\t" + m_dOmd.sFind("黑","25","11","0",VluK_Sx)  + "\t\t\t\t" +
        m_dOmd.sFind("黑","25","5","0",VluK_Sy)  + "\t\t\t\t" + m_dOmd.sFind("黑","25","11","0",VluK_Sy)  + "\t\t\t\t" +
        m_dOmd.sFind("黑","25","5","0",VluK_T)   + "\t\t\t\t" + m_dOmd.sFind("黑","25","11","0",VluK_T)   + "\t\t\t\t" +
        m_dOmd.sFind("黑","25","5","0",VluK_Duv) + "\t\t\t\t" + m_dOmd.sFind("黑","25","11","0",VluK_Duv) + "\n");
    
    m_dTxt.push_back("\t\t\t\t\t\t\t" + 
        m_dOmd.sFind("黑","25","3","0",VluK_Lv)  + "\t\t" + m_dOmd.sFind("黑","25","4","0",VluK_Lv)  + "\t\t" + m_dOmd.sFind("黑","25","10","0",VluK_Lv)  + "\t\t" + m_dOmd.sFind("黑","25","9","0",VluK_Lv)  + "\t\t" +
        m_dOmd.sFind("黑","25","3","0",VluK_Sx)  + "\t\t" + m_dOmd.sFind("黑","25","4","0",VluK_Sx)  + "\t\t" + m_dOmd.sFind("黑","25","10","0",VluK_Sx)  + "\t\t" + m_dOmd.sFind("黑","25","9","0",VluK_Sx)  + "\t\t" +
        m_dOmd.sFind("黑","25","3","0",VluK_Sy)  + "\t\t" + m_dOmd.sFind("黑","25","4","0",VluK_Sy)  + "\t\t" + m_dOmd.sFind("黑","25","10","0",VluK_Sy)  + "\t\t" + m_dOmd.sFind("黑","25","9","0",VluK_Sy)  + "\t\t" +
        m_dOmd.sFind("黑","25","3","0",VluK_T)   + "\t\t" + m_dOmd.sFind("黑","25","4","0",VluK_T)   + "\t\t" + m_dOmd.sFind("黑","25","10","0",VluK_T)   + "\t\t" + m_dOmd.sFind("黑","25","9","0",VluK_T)   + "\t\t" +
        m_dOmd.sFind("黑","25","3","0",VluK_Duv) + "\t\t" + m_dOmd.sFind("黑","25","4","0",VluK_Duv) + "\t\t" + m_dOmd.sFind("黑","25","10","0",VluK_Duv) + "\t\t" + m_dOmd.sFind("黑","25","9","0",VluK_Duv) + "\n");
    
    m_dTxt.push_back("\t\t\t\t\t\t\t" + 
        m_dOmd.sFind("黑","25","12","0",VluK_Lv)  + "\t\t\t" + m_dOmd.sFind("黑","25","13","0",VluK_Lv)  + "\t\t\t" + m_dOmd.sFind("黑","25","14","0",VluK_Lv)  + "\t\t" +
        m_dOmd.sFind("黑","25","12","0",VluK_Sx)  + "\t\t\t" + m_dOmd.sFind("黑","25","13","0",VluK_Sx)  + "\t\t\t" + m_dOmd.sFind("黑","25","14","0",VluK_Sx)  + "\t\t" +
        m_dOmd.sFind("黑","25","12","0",VluK_Sy)  + "\t\t\t" + m_dOmd.sFind("黑","25","13","0",VluK_Sy)  + "\t\t\t" + m_dOmd.sFind("黑","25","14","0",VluK_Sy)  + "\t\t" +
        m_dOmd.sFind("黑","25","12","0",VluK_T)   + "\t\t\t" + m_dOmd.sFind("黑","25","13","0",VluK_T)   + "\t\t\t" + m_dOmd.sFind("黑","25","14","0",VluK_T)   + "\t\t" +
        m_dOmd.sFind("黑","25","12","0",VluK_Duv) + "\t\t\t" + m_dOmd.sFind("黑","25","13","0",VluK_Duv) + "\t\t\t" + m_dOmd.sFind("黑","25","14","0",VluK_Duv) + "\n");
    
    m_dTxt.push_back("\t\t\t\t\t\t\t" + 
        m_dOmd.sFind("黑","25","17","0",VluK_Lv)  + "\t\t" + m_dOmd.sFind("黑","25","18","0",VluK_Lv)  + "\t\t" + m_dOmd.sFind("黑","25","24","0",VluK_Lv)  + "\t\t" + m_dOmd.sFind("黑","25","23","0",VluK_Lv)  + "\t\t" +
        m_dOmd.sFind("黑","25","17","0",VluK_Sx)  + "\t\t" + m_dOmd.sFind("黑","25","18","0",VluK_Sx)  + "\t\t" + m_dOmd.sFind("黑","25","24","0",VluK_Sx)  + "\t\t" + m_dOmd.sFind("黑","25","23","0",VluK_Sx)  + "\t\t" +
        m_dOmd.sFind("黑","25","17","0",VluK_Sy)  + "\t\t" + m_dOmd.sFind("黑","25","18","0",VluK_Sy)  + "\t\t" + m_dOmd.sFind("黑","25","24","0",VluK_Sy)  + "\t\t" + m_dOmd.sFind("黑","25","23","0",VluK_Sy)  + "\t\t" +
        m_dOmd.sFind("黑","25","17","0",VluK_T)   + "\t\t" + m_dOmd.sFind("黑","25","18","0",VluK_T)   + "\t\t" + m_dOmd.sFind("黑","25","24","0",VluK_T)   + "\t\t" + m_dOmd.sFind("黑","25","23","0",VluK_T)   + "\t\t" +
        m_dOmd.sFind("黑","25","17","0",VluK_Duv) + "\t\t" + m_dOmd.sFind("黑","25","18","0",VluK_Duv) + "\t\t" + m_dOmd.sFind("黑","25","24","0",VluK_Duv) + "\t\t" + m_dOmd.sFind("黑","25","23","0",VluK_Duv) + "\n");
    
    m_dTxt.push_back("\t\t\t\t\t\t\t\t" +
        m_dOmd.sFind("黑","25","19","0",VluK_Lv)  + "\t\t\t\t" + m_dOmd.sFind("黑","25","25","0",VluK_Lv)  + "\t\t\t\t" +
        m_dOmd.sFind("黑","25","19","0",VluK_Sx)  + "\t\t\t\t" + m_dOmd.sFind("黑","25","25","0",VluK_Sx)  + "\t\t\t\t" +
        m_dOmd.sFind("黑","25","19","0",VluK_Sy)  + "\t\t\t\t" + m_dOmd.sFind("黑","25","25","0",VluK_Sy)  + "\t\t\t\t" +
        m_dOmd.sFind("黑","25","19","0",VluK_T)   + "\t\t\t\t" + m_dOmd.sFind("黑","25","25","0",VluK_T)   + "\t\t\t\t" +
        m_dOmd.sFind("黑","25","19","0",VluK_Duv) + "\t\t\t\t" + m_dOmd.sFind("黑","25","25","0",VluK_Duv) + "\n");

    m_dTxt.push_back("\t\t\t\t\t\t\t" + 
        m_dOmd.sFind("黑","25","15","0",VluK_Lv)  + "\t\t" + m_dOmd.sFind("黑","25","16","0",VluK_Lv)  + "\t" + m_dOmd.sFind("黑","25","20","0",VluK_Lv)  + "\t" + m_dOmd.sFind("黑","25","22","0",VluK_Lv)  + "\t\t" + m_dOmd.sFind("黑","25","21","0",VluK_Lv)  + "\t\t" +
        m_dOmd.sFind("黑","25","15","0",VluK_Sx)  + "\t\t" + m_dOmd.sFind("黑","25","16","0",VluK_Sx)  + "\t" + m_dOmd.sFind("黑","25","20","0",VluK_Sx)  + "\t" + m_dOmd.sFind("黑","25","22","0",VluK_Sx)  + "\t\t" + m_dOmd.sFind("黑","25","21","0",VluK_Sx)  + "\t\t" +
        m_dOmd.sFind("黑","25","15","0",VluK_Sy)  + "\t\t" + m_dOmd.sFind("黑","25","16","0",VluK_Sy)  + "\t" + m_dOmd.sFind("黑","25","20","0",VluK_Sy)  + "\t" + m_dOmd.sFind("黑","25","22","0",VluK_Sy)  + "\t\t" + m_dOmd.sFind("黑","25","21","0",VluK_Sy)  + "\t\t" +
        m_dOmd.sFind("黑","25","15","0",VluK_T)   + "\t\t" + m_dOmd.sFind("黑","25","16","0",VluK_T)   + "\t" + m_dOmd.sFind("黑","25","20","0",VluK_T)   + "\t" + m_dOmd.sFind("黑","25","22","0",VluK_T)   + "\t\t" + m_dOmd.sFind("黑","25","21","0",VluK_T)   + "\t\t" +
        m_dOmd.sFind("黑","25","15","0",VluK_Duv) + "\t\t" + m_dOmd.sFind("黑","25","16","0",VluK_Duv) + "\t" + m_dOmd.sFind("黑","25","20","0",VluK_Duv) + "\t" + m_dOmd.sFind("黑","25","22","0",VluK_Duv) + "\t\t" + m_dOmd.sFind("黑","25","21","0",VluK_Duv) + "\n");

    m_dTxt.push_back("\n");
}

void COmdFile1::o2tD21()
{
    m_dTxt.push_back("\t\t\t\t\t\t黑色21點均齊度\tL\t\t\t\t\t\t\t黑色21點均齊度\tx\t\t\t\t\t\t\t黑色21點均齊度\ty\n");

    m_dTxt.push_back("\t\t\t\t\t\t\t" + 
        m_dOmd.sFind("黑","21","5","0",VluK_Lv)  + "\t" + m_dOmd.sFind("黑","21","6","0",VluK_Lv) + "\t" + m_dOmd.sFind("黑","21","7","0",VluK_Lv) + "\t" + m_dOmd.sFind("黑","21","8","0",VluK_Lv) + "\t" + m_dOmd.sFind("黑","21","9","0",VluK_Lv) + "\t" + m_dOmd.sFind("黑","21","10","0",VluK_Lv) + "\t" + m_dOmd.sFind("黑","21","11","0",VluK_Lv) + "\t\t" +
        m_dOmd.sFind("黑","21","5","0",VluK_Sx)  + "\t" + m_dOmd.sFind("黑","21","6","0",VluK_Sx) + "\t" + m_dOmd.sFind("黑","21","7","0",VluK_Sx) + "\t" + m_dOmd.sFind("黑","21","8","0",VluK_Sx) + "\t" + m_dOmd.sFind("黑","21","9","0",VluK_Sx) + "\t" + m_dOmd.sFind("黑","21","10","0",VluK_Sx) + "\t" + m_dOmd.sFind("黑","21","11","0",VluK_Sx) + "\t\t" +
        m_dOmd.sFind("黑","21","5","0",VluK_Sy)  + "\t" + m_dOmd.sFind("黑","21","6","0",VluK_Sy) + "\t" + m_dOmd.sFind("黑","21","7","0",VluK_Sy) + "\t" + m_dOmd.sFind("黑","21","8","0",VluK_Sy) + "\t" + m_dOmd.sFind("黑","21","9","0",VluK_Sy) + "\t" + m_dOmd.sFind("黑","21","10","0",VluK_Sy) + "\t" + m_dOmd.sFind("黑","21","11","0",VluK_Sy) + "\n" );

    m_dTxt.push_back("\t\t\t\t\t\t\t" + 
        m_dOmd.sFind("黑","21","4","0",VluK_Lv)  + "\t\t\t\t\t\t" + m_dOmd.sFind("黑","21","12","0",VluK_Lv) + "\t\t" +
        m_dOmd.sFind("黑","21","4","0",VluK_Sx)  + "\t\t\t\t\t\t" + m_dOmd.sFind("黑","21","12","0",VluK_Sx) + "\t\t" +
        m_dOmd.sFind("黑","21","4","0",VluK_Sy)  + "\t\t\t\t\t\t" + m_dOmd.sFind("黑","21","12","0",VluK_Sy) + "\n" );

    m_dTxt.push_back("\t\t\t\t\t\t\t" + 
        m_dOmd.sFind("黑","21","3","0",VluK_Lv)  + "\t\t\t" + m_dOmd.sFind("黑","21","21","0",VluK_Lv) + "\t\t\t" + m_dOmd.sFind("黑","21","13","0",VluK_Lv) + "\t\t" +
        m_dOmd.sFind("黑","21","3","0",VluK_Sx)  + "\t\t\t" + m_dOmd.sFind("黑","21","21","0",VluK_Sx) + "\t\t\t" + m_dOmd.sFind("黑","21","13","0",VluK_Sx) + "\t\t" +
        m_dOmd.sFind("黑","21","3","0",VluK_Sy)  + "\t\t\t" + m_dOmd.sFind("黑","21","21","0",VluK_Sy) + "\t\t\t" + m_dOmd.sFind("黑","21","13","0",VluK_Sy) + "\n" );
    
    m_dTxt.push_back("\t\t\t\t\t\t\t" + 
        m_dOmd.sFind("黑","21","2","0",VluK_Lv)  + "\t\t\t\t\t\t" + m_dOmd.sFind("黑","21","14","0",VluK_Lv) + "\t\t" +
        m_dOmd.sFind("黑","21","2","0",VluK_Sx)  + "\t\t\t\t\t\t" + m_dOmd.sFind("黑","21","14","0",VluK_Sx) + "\t\t" +
        m_dOmd.sFind("黑","21","2","0",VluK_Sy)  + "\t\t\t\t\t\t" + m_dOmd.sFind("黑","21","14","0",VluK_Sy) + "\n" );
    
    m_dTxt.push_back("\t\t\t\t\t\t\t" + 
        m_dOmd.sFind("黑","21","1","0",VluK_Lv)  + "\t" + m_dOmd.sFind("黑","21","20","0",VluK_Lv) + "\t" + m_dOmd.sFind("黑","21","19","0",VluK_Lv) + "\t" + m_dOmd.sFind("黑","21","18","0",VluK_Lv) + "\t" + m_dOmd.sFind("黑","21","17","0",VluK_Lv) + "\t" + m_dOmd.sFind("黑","21","16","0",VluK_Lv) + "\t" + m_dOmd.sFind("黑","21","15","0",VluK_Lv) + "\t\t" +
        m_dOmd.sFind("黑","21","1","0",VluK_Sx)  + "\t" + m_dOmd.sFind("黑","21","20","0",VluK_Sx) + "\t" + m_dOmd.sFind("黑","21","19","0",VluK_Sx) + "\t" + m_dOmd.sFind("黑","21","18","0",VluK_Sx) + "\t" + m_dOmd.sFind("黑","21","17","0",VluK_Sx) + "\t" + m_dOmd.sFind("黑","21","16","0",VluK_Sx) + "\t" + m_dOmd.sFind("黑","21","15","0",VluK_Sx) + "\t\t" +
        m_dOmd.sFind("黑","21","1","0",VluK_Sy)  + "\t" + m_dOmd.sFind("黑","21","20","0",VluK_Sy) + "\t" + m_dOmd.sFind("黑","21","19","0",VluK_Sy) + "\t" + m_dOmd.sFind("黑","21","18","0",VluK_Sy) + "\t" + m_dOmd.sFind("黑","21","17","0",VluK_Sy) + "\t" + m_dOmd.sFind("黑","21","16","0",VluK_Sy) + "\t" + m_dOmd.sFind("黑","21","15","0",VluK_Sy) + "\n" );
    
    m_dTxt.push_back(" \n");
}

void COmdFile1::o2tW49_01to28()
{
    m_dTxt.push_back("\t\t\t\t\t\t49點均齊度\tL\t\t\t\t\t\t\t49點均齊度\tx\t\t\t\t\t\t\t49點均齊度\ty\t\t\t\t\t\t\t49點均齊度\tT\t\t\t\t\t\t\t49點均齊度\tduv\n");
    
    m_dTxt.push_back("\t\t\t\t\t\t\t" + 
        m_dOmd.sFind("白","49","1"," ",VluK_Lv)  + "\t" + m_dOmd.sFind("白","49","2"," ",VluK_Lv)  + "\t" + m_dOmd.sFind("白","49","3"," ",VluK_Lv)  + "\t" + m_dOmd.sFind("白","49","4"," ",VluK_Lv)  + "\t" + m_dOmd.sFind("白","49","5"," ",VluK_Lv) +  "\t" + m_dOmd.sFind("白","49","6"," ",VluK_Lv)  + "\t" + m_dOmd.sFind("白","49","7"," ",VluK_Lv)  + "\t\t" +
        m_dOmd.sFind("白","49","1"," ",VluK_Sx)  + "\t" + m_dOmd.sFind("白","49","2"," ",VluK_Sx)  + "\t" + m_dOmd.sFind("白","49","3"," ",VluK_Sx)  + "\t" + m_dOmd.sFind("白","49","4"," ",VluK_Sx)  + "\t" + m_dOmd.sFind("白","49","5"," ",VluK_Sx) +  "\t" + m_dOmd.sFind("白","49","6"," ",VluK_Sx)  + "\t" + m_dOmd.sFind("白","49","7"," ",VluK_Sx)  + "\t\t" +
        m_dOmd.sFind("白","49","1"," ",VluK_Sy)  + "\t" + m_dOmd.sFind("白","49","2"," ",VluK_Sy)  + "\t" + m_dOmd.sFind("白","49","3"," ",VluK_Sy)  + "\t" + m_dOmd.sFind("白","49","4"," ",VluK_Sy)  + "\t" + m_dOmd.sFind("白","49","5"," ",VluK_Sy) +  "\t" + m_dOmd.sFind("白","49","6"," ",VluK_Sy)  + "\t" + m_dOmd.sFind("白","49","7"," ",VluK_Sy)  + "\t\t" +
        m_dOmd.sFind("白","49","1"," ",VluK_T)   + "\t" + m_dOmd.sFind("白","49","2"," ",VluK_T)   + "\t" + m_dOmd.sFind("白","49","3"," ",VluK_T)   + "\t" + m_dOmd.sFind("白","49","4"," ",VluK_T)   + "\t" + m_dOmd.sFind("白","49","5"," ",VluK_T)  +  "\t" + m_dOmd.sFind("白","49","6"," ",VluK_T)   + "\t" + m_dOmd.sFind("白","49","7"," ",VluK_T)   + "\t\t" +
        m_dOmd.sFind("白","49","1"," ",VluK_Duv) + "\t" + m_dOmd.sFind("白","49","2"," ",VluK_Duv) + "\t" + m_dOmd.sFind("白","49","3"," ",VluK_Duv) + "\t" + m_dOmd.sFind("白","49","4"," ",VluK_Duv) + "\t" + m_dOmd.sFind("白","49","5"," ",VluK_Duv) + "\t" + m_dOmd.sFind("白","49","6"," ",VluK_Duv) + "\t" + m_dOmd.sFind("白","49","7"," ",VluK_Duv) + "\n");
    
    m_dTxt.push_back("\t\t\t\t\t\t\t" +
        m_dOmd.sFind("白","49","8"," ",VluK_Lv)  + "\t" + m_dOmd.sFind("白","49","9"," ",VluK_Lv)  + "\t" + m_dOmd.sFind("白","49","10"," ",VluK_Lv)  + "\t" + m_dOmd.sFind("白","49","11"," ",VluK_Lv)  + "\t" + m_dOmd.sFind("白","49","12"," ",VluK_Lv)  + "\t" + m_dOmd.sFind("白","49","13"," ",VluK_Lv)  + "\t" + m_dOmd.sFind("白","49","14"," ",VluK_Lv)  + "\t\t" +
        m_dOmd.sFind("白","49","8"," ",VluK_Sx)  + "\t" + m_dOmd.sFind("白","49","9"," ",VluK_Sx)  + "\t" + m_dOmd.sFind("白","49","10"," ",VluK_Sx)  + "\t" + m_dOmd.sFind("白","49","11"," ",VluK_Sx)  + "\t" + m_dOmd.sFind("白","49","12"," ",VluK_Sx)  + "\t" + m_dOmd.sFind("白","49","13"," ",VluK_Sx)  + "\t" + m_dOmd.sFind("白","49","14"," ",VluK_Sx)  + "\t\t" +
        m_dOmd.sFind("白","49","8"," ",VluK_Sy)  + "\t" + m_dOmd.sFind("白","49","9"," ",VluK_Sy)  + "\t" + m_dOmd.sFind("白","49","10"," ",VluK_Sy)  + "\t" + m_dOmd.sFind("白","49","11"," ",VluK_Sy)  + "\t" + m_dOmd.sFind("白","49","12"," ",VluK_Sy)  + "\t" + m_dOmd.sFind("白","49","13"," ",VluK_Sy)  + "\t" + m_dOmd.sFind("白","49","14"," ",VluK_Sy)  + "\t\t" +
        m_dOmd.sFind("白","49","8"," ",VluK_T)   + "\t" + m_dOmd.sFind("白","49","9"," ",VluK_T)   + "\t" + m_dOmd.sFind("白","49","10"," ",VluK_T)   + "\t" + m_dOmd.sFind("白","49","11"," ",VluK_T)   + "\t" + m_dOmd.sFind("白","49","12"," ",VluK_T)   + "\t" + m_dOmd.sFind("白","49","13"," ",VluK_T)   + "\t" + m_dOmd.sFind("白","49","14"," ",VluK_T)   + "\t\t" +
        m_dOmd.sFind("白","49","8"," ",VluK_Duv) + "\t" + m_dOmd.sFind("白","49","9"," ",VluK_Duv) + "\t" + m_dOmd.sFind("白","49","10"," ",VluK_Duv) + "\t" + m_dOmd.sFind("白","49","11"," ",VluK_Duv) + "\t" + m_dOmd.sFind("白","49","12"," ",VluK_Duv) + "\t" + m_dOmd.sFind("白","49","13"," ",VluK_Duv) + "\t" + m_dOmd.sFind("白","49","14"," ",VluK_Duv) + "\n");
    
    m_dTxt.push_back("\t\t\t\t\t\t\t" +
        m_dOmd.sFind("白","49","15"," ",VluK_Lv)  + "\t" + m_dOmd.sFind("白","49","16"," ",VluK_Lv)  + "\t" + m_dOmd.sFind("白","49","17"," ",VluK_Lv)  + "\t" + m_dOmd.sFind("白","49","18"," ",VluK_Lv)  + "\t" + m_dOmd.sFind("白","49","19"," ",VluK_Lv)  + "\t" + m_dOmd.sFind("白","49","20"," ",VluK_Lv)  + "\t" + m_dOmd.sFind("白","49","21"," ",VluK_Lv)  + "\t\t" +
        m_dOmd.sFind("白","49","15"," ",VluK_Sx)  + "\t" + m_dOmd.sFind("白","49","16"," ",VluK_Sx)  + "\t" + m_dOmd.sFind("白","49","17"," ",VluK_Sx)  + "\t" + m_dOmd.sFind("白","49","18"," ",VluK_Sx)  + "\t" + m_dOmd.sFind("白","49","19"," ",VluK_Sx)  + "\t" + m_dOmd.sFind("白","49","20"," ",VluK_Sx)  + "\t" + m_dOmd.sFind("白","49","21"," ",VluK_Sx)  + "\t\t" +
        m_dOmd.sFind("白","49","15"," ",VluK_Sy)  + "\t" + m_dOmd.sFind("白","49","16"," ",VluK_Sy)  + "\t" + m_dOmd.sFind("白","49","17"," ",VluK_Sy)  + "\t" + m_dOmd.sFind("白","49","18"," ",VluK_Sy)  + "\t" + m_dOmd.sFind("白","49","19"," ",VluK_Sy)  + "\t" + m_dOmd.sFind("白","49","20"," ",VluK_Sy)  + "\t" + m_dOmd.sFind("白","49","21"," ",VluK_Sy)  + "\t\t" +
        m_dOmd.sFind("白","49","15"," ",VluK_T)   + "\t" + m_dOmd.sFind("白","49","16"," ",VluK_T)   + "\t" + m_dOmd.sFind("白","49","17"," ",VluK_T)   + "\t" + m_dOmd.sFind("白","49","18"," ",VluK_T)   + "\t" + m_dOmd.sFind("白","49","19"," ",VluK_T)   + "\t" + m_dOmd.sFind("白","49","20"," ",VluK_T)   + "\t" + m_dOmd.sFind("白","49","21"," ",VluK_T)   + "\t\t" +
        m_dOmd.sFind("白","49","15"," ",VluK_Duv) + "\t" + m_dOmd.sFind("白","49","16"," ",VluK_Duv) + "\t" + m_dOmd.sFind("白","49","17"," ",VluK_Duv) + "\t" + m_dOmd.sFind("白","49","18"," ",VluK_Duv) + "\t" + m_dOmd.sFind("白","49","19"," ",VluK_Duv) + "\t" + m_dOmd.sFind("白","49","20"," ",VluK_Duv) + "\t" + m_dOmd.sFind("白","49","21"," ",VluK_Duv) + "\n");
    
    m_dTxt.push_back("\t\t\t\t\t\t\t" +
        m_dOmd.sFind("白","49","22"," ",VluK_Lv)  + "\t" + m_dOmd.sFind("白","49","23"," ",VluK_Lv)  + "\t" + m_dOmd.sFind("白","49","24"," ",VluK_Lv)  + "\t" + m_dOmd.sFind("白","49","25"," ",VluK_Lv)  + "\t" + m_dOmd.sFind("白","49","26"," ",VluK_Lv)  + "\t" + m_dOmd.sFind("白","49","27"," ",VluK_Lv)  + "\t" + m_dOmd.sFind("白","49","28"," ",VluK_Lv)  + "\t\t" +
        m_dOmd.sFind("白","49","22"," ",VluK_Sx)  + "\t" + m_dOmd.sFind("白","49","23"," ",VluK_Sx)  + "\t" + m_dOmd.sFind("白","49","24"," ",VluK_Sx)  + "\t" + m_dOmd.sFind("白","49","25"," ",VluK_Sx)  + "\t" + m_dOmd.sFind("白","49","26"," ",VluK_Sx)  + "\t" + m_dOmd.sFind("白","49","27"," ",VluK_Sx)  + "\t" + m_dOmd.sFind("白","49","28"," ",VluK_Sx)  + "\t\t" +
        m_dOmd.sFind("白","49","22"," ",VluK_Sy)  + "\t" + m_dOmd.sFind("白","49","23"," ",VluK_Sy)  + "\t" + m_dOmd.sFind("白","49","24"," ",VluK_Sy)  + "\t" + m_dOmd.sFind("白","49","25"," ",VluK_Sy)  + "\t" + m_dOmd.sFind("白","49","26"," ",VluK_Sy)  + "\t" + m_dOmd.sFind("白","49","27"," ",VluK_Sy)  + "\t" + m_dOmd.sFind("白","49","28"," ",VluK_Sy)  + "\t\t" + 
        m_dOmd.sFind("白","49","22"," ",VluK_T)   + "\t" + m_dOmd.sFind("白","49","23"," ",VluK_T)   + "\t" + m_dOmd.sFind("白","49","24"," ",VluK_T)   + "\t" + m_dOmd.sFind("白","49","25"," ",VluK_T)   + "\t" + m_dOmd.sFind("白","49","26"," ",VluK_T)   + "\t" + m_dOmd.sFind("白","49","27"," ",VluK_T)   + "\t" + m_dOmd.sFind("白","49","28"," ",VluK_T)   + "\t\t" +
        m_dOmd.sFind("白","49","22"," ",VluK_Duv) + "\t" + m_dOmd.sFind("白","49","23"," ",VluK_Duv) + "\t" + m_dOmd.sFind("白","49","24"," ",VluK_Duv) + "\t" + m_dOmd.sFind("白","49","25"," ",VluK_Duv) + "\t" + m_dOmd.sFind("白","49","26"," ",VluK_Duv) + "\t" + m_dOmd.sFind("白","49","27"," ",VluK_Duv) + "\t" + m_dOmd.sFind("白","49","28"," ",VluK_Duv) + "\n");
}

void COmdFile1::o2tW49_29to49()
{
    m_dTxt.push_back("\t\t\t\t\t\t\t" +
        m_dOmd.sFind("白","49","29"," ",VluK_Lv)  + "\t" + m_dOmd.sFind("白","49","30"," ",VluK_Lv)  + "\t" + m_dOmd.sFind("白","49","31"," ",VluK_Lv)  + "\t" + m_dOmd.sFind("白","49","32"," ",VluK_Lv)  + "\t" + m_dOmd.sFind("白","49","33"," ",VluK_Lv)  + "\t" + m_dOmd.sFind("白","49","34"," ",VluK_Lv)  + "\t" + m_dOmd.sFind("白","49","35"," ",VluK_Lv)  + "\t\t" +
        m_dOmd.sFind("白","49","29"," ",VluK_Sx)  + "\t" + m_dOmd.sFind("白","49","30"," ",VluK_Sx)  + "\t" + m_dOmd.sFind("白","49","31"," ",VluK_Sx)  + "\t" + m_dOmd.sFind("白","49","32"," ",VluK_Sx)  + "\t" + m_dOmd.sFind("白","49","33"," ",VluK_Sx)  + "\t" + m_dOmd.sFind("白","49","34"," ",VluK_Sx)  + "\t" + m_dOmd.sFind("白","49","35"," ",VluK_Sx)  + "\t\t" +
        m_dOmd.sFind("白","49","29"," ",VluK_Sy)  + "\t" + m_dOmd.sFind("白","49","30"," ",VluK_Sy)  + "\t" + m_dOmd.sFind("白","49","31"," ",VluK_Sy)  + "\t" + m_dOmd.sFind("白","49","32"," ",VluK_Sy)  + "\t" + m_dOmd.sFind("白","49","33"," ",VluK_Sy)  + "\t" + m_dOmd.sFind("白","49","34"," ",VluK_Sy)  + "\t" + m_dOmd.sFind("白","49","35"," ",VluK_Sy)  + "\t\t" +
        m_dOmd.sFind("白","49","29"," ",VluK_T)   + "\t" + m_dOmd.sFind("白","49","30"," ",VluK_T)   + "\t" + m_dOmd.sFind("白","49","31"," ",VluK_T)   + "\t" + m_dOmd.sFind("白","49","32"," ",VluK_T)   + "\t" + m_dOmd.sFind("白","49","33"," ",VluK_T)   + "\t" + m_dOmd.sFind("白","49","34"," ",VluK_T)   + "\t" + m_dOmd.sFind("白","49","35"," ",VluK_T)   + "\t\t" +
        m_dOmd.sFind("白","49","29"," ",VluK_Duv) + "\t" + m_dOmd.sFind("白","49","30"," ",VluK_Duv) + "\t" + m_dOmd.sFind("白","49","31"," ",VluK_Duv) + "\t" + m_dOmd.sFind("白","49","32"," ",VluK_Duv) + "\t" + m_dOmd.sFind("白","49","33"," ",VluK_Duv) + "\t" + m_dOmd.sFind("白","49","34"," ",VluK_Duv) + "\t" + m_dOmd.sFind("白","49","35"," ",VluK_Duv) + "\n");
    
    m_dTxt.push_back("\t\t\t\t\t\t\t" +
        m_dOmd.sFind("白","49","36"," ",VluK_Lv)  + "\t" + m_dOmd.sFind("白","49","37"," ",VluK_Lv)  + "\t" + m_dOmd.sFind("白","49","38"," ",VluK_Lv)  + "\t" + m_dOmd.sFind("白","49","39"," ",VluK_Lv)  + "\t" + m_dOmd.sFind("白","49","40"," ",VluK_Lv)  + "\t" + m_dOmd.sFind("白","49","41"," ",VluK_Lv)  + "\t" + m_dOmd.sFind("白","49","42"," ",VluK_Lv)  + "\t\t" +
        m_dOmd.sFind("白","49","36"," ",VluK_Sx)  + "\t" + m_dOmd.sFind("白","49","37"," ",VluK_Sx)  + "\t" + m_dOmd.sFind("白","49","38"," ",VluK_Sx)  + "\t" + m_dOmd.sFind("白","49","39"," ",VluK_Sx)  + "\t" + m_dOmd.sFind("白","49","40"," ",VluK_Sx)  + "\t" + m_dOmd.sFind("白","49","41"," ",VluK_Sx)  + "\t" + m_dOmd.sFind("白","49","42"," ",VluK_Sx)  + "\t\t" +
        m_dOmd.sFind("白","49","36"," ",VluK_Sy)  + "\t" + m_dOmd.sFind("白","49","37"," ",VluK_Sy)  + "\t" + m_dOmd.sFind("白","49","38"," ",VluK_Sy)  + "\t" + m_dOmd.sFind("白","49","39"," ",VluK_Sy)  + "\t" + m_dOmd.sFind("白","49","40"," ",VluK_Sy)  + "\t" + m_dOmd.sFind("白","49","41"," ",VluK_Sy)  + "\t" + m_dOmd.sFind("白","49","42"," ",VluK_Sy)  + "\t\t" +
        m_dOmd.sFind("白","49","36"," ",VluK_T)   + "\t" + m_dOmd.sFind("白","49","37"," ",VluK_T)   + "\t" + m_dOmd.sFind("白","49","38"," ",VluK_T)   + "\t" + m_dOmd.sFind("白","49","39"," ",VluK_T)   + "\t" + m_dOmd.sFind("白","49","40"," ",VluK_T)   + "\t" + m_dOmd.sFind("白","49","41"," ",VluK_T)   + "\t" + m_dOmd.sFind("白","49","42"," ",VluK_T)   + "\t\t" +
        m_dOmd.sFind("白","49","36"," ",VluK_Duv) + "\t" + m_dOmd.sFind("白","49","37"," ",VluK_Duv) + "\t" + m_dOmd.sFind("白","49","38"," ",VluK_Duv) + "\t" + m_dOmd.sFind("白","49","39"," ",VluK_Duv) + "\t" + m_dOmd.sFind("白","49","40"," ",VluK_Duv) + "\t" + m_dOmd.sFind("白","49","41"," ",VluK_Duv) + "\t" + m_dOmd.sFind("白","49","42"," ",VluK_Duv) + "\n");
    
    m_dTxt.push_back("\t\t\t\t\t\t\t" +
        m_dOmd.sFind("白","49","43"," ",VluK_Lv)  + "\t" + m_dOmd.sFind("白","49","44"," ",VluK_Lv)  + "\t" + m_dOmd.sFind("白","49","45"," ",VluK_Lv)  + "\t" + m_dOmd.sFind("白","49","46"," ",VluK_Lv)  + "\t" + m_dOmd.sFind("白","49","47"," ",VluK_Lv)  + "\t" + m_dOmd.sFind("白","49","48"," ",VluK_Lv)  + "\t" + m_dOmd.sFind("白","49","49"," ",VluK_Lv)  + "\t\t" +
        m_dOmd.sFind("白","49","43"," ",VluK_Sx)  + "\t" + m_dOmd.sFind("白","49","44"," ",VluK_Sx)  + "\t" + m_dOmd.sFind("白","49","45"," ",VluK_Sx)  + "\t" + m_dOmd.sFind("白","49","46"," ",VluK_Sx)  + "\t" + m_dOmd.sFind("白","49","47"," ",VluK_Sx)  + "\t" + m_dOmd.sFind("白","49","48"," ",VluK_Sx)  + "\t" + m_dOmd.sFind("白","49","49"," ",VluK_Sx)  + "\t\t" +
        m_dOmd.sFind("白","49","43"," ",VluK_Sy)  + "\t" + m_dOmd.sFind("白","49","44"," ",VluK_Sy)  + "\t" + m_dOmd.sFind("白","49","45"," ",VluK_Sy)  + "\t" + m_dOmd.sFind("白","49","46"," ",VluK_Sy)  + "\t" + m_dOmd.sFind("白","49","47"," ",VluK_Sy)  + "\t" + m_dOmd.sFind("白","49","48"," ",VluK_Sy)  + "\t" + m_dOmd.sFind("白","49","49"," ",VluK_Sy)  + "\t\t" +
        m_dOmd.sFind("白","49","43"," ",VluK_T)   + "\t" + m_dOmd.sFind("白","49","44"," ",VluK_T)   + "\t" + m_dOmd.sFind("白","49","45"," ",VluK_T)   + "\t" + m_dOmd.sFind("白","49","46"," ",VluK_T)   + "\t" + m_dOmd.sFind("白","49","47"," ",VluK_T)   + "\t" + m_dOmd.sFind("白","49","48"," ",VluK_T)   + "\t" + m_dOmd.sFind("白","49","49"," ",VluK_T)   + "\t\t" +
        m_dOmd.sFind("白","49","43"," ",VluK_Duv) + "\t" + m_dOmd.sFind("白","49","44"," ",VluK_Duv) + "\t" + m_dOmd.sFind("白","49","45"," ",VluK_Duv) + "\t" + m_dOmd.sFind("白","49","46"," ",VluK_Duv) + "\t" + m_dOmd.sFind("白","49","47"," ",VluK_Duv) + "\t" + m_dOmd.sFind("白","49","48"," ",VluK_Duv) + "\t" + m_dOmd.sFind("白","49","49"," ",VluK_Duv) + "\n");
    
    m_dTxt.push_back(" \n");
}

void COmdFile1::o2tD13()
{
    m_dTxt.push_back("\t\t\t\t\t\t黑色13點均齊度\tL\t\t\t\t\t黑色13點均齊度\tx\t\t\t\t\t黑色13點均齊度\ty\n");
    m_dTxt.push_back("\t\t\t\t\t\t\t" + 
        m_dOmd.sFind("黑","13","1","0",VluK_Lv)  + "\t\t" + m_dOmd.sFind("黑","13","2","0",VluK_Lv) + "\t\t" + m_dOmd.sFind("黑","13","3","0",VluK_Lv) + "\t\t" +
        m_dOmd.sFind("黑","13","1","0",VluK_Sx)  + "\t\t" + m_dOmd.sFind("黑","13","2","0",VluK_Sx) + "\t\t" + m_dOmd.sFind("黑","13","3","0",VluK_Sx) + "\t\t" +
        m_dOmd.sFind("黑","13","1","0",VluK_Sy)  + "\t\t" + m_dOmd.sFind("黑","13","2","0",VluK_Sy) + "\t\t" + m_dOmd.sFind("黑","13","3","0",VluK_Sy) + "\n" );
    
    m_dTxt.push_back("\t\t\t\t\t\t\t\t" + 
        m_dOmd.sFind("黑","13","4","0",VluK_Lv)  + "\t\t" + m_dOmd.sFind("黑","13","5","0",VluK_Lv) + "\t\t\t\t" +
        m_dOmd.sFind("黑","13","4","0",VluK_Sx)  + "\t\t" + m_dOmd.sFind("黑","13","5","0",VluK_Sx) + "\t\t\t\t" +
        m_dOmd.sFind("黑","13","4","0",VluK_Sy)  + "\t\t" + m_dOmd.sFind("黑","13","5","0",VluK_Sy) + "\n" );
    
    m_dTxt.push_back("\t\t\t\t\t\t\t" + 
        m_dOmd.sFind("黑","13","6","0",VluK_Lv)  + "\t\t" + m_dOmd.sFind("黑","13","7","0",VluK_Lv) + "\t\t" + m_dOmd.sFind("黑","13","8","0",VluK_Lv) + "\t\t" +
        m_dOmd.sFind("黑","13","6","0",VluK_Sx)  + "\t\t" + m_dOmd.sFind("黑","13","7","0",VluK_Sx) + "\t\t" + m_dOmd.sFind("黑","13","8","0",VluK_Sx) + "\t\t" +
        m_dOmd.sFind("黑","13","6","0",VluK_Sy)  + "\t\t" + m_dOmd.sFind("黑","13","7","0",VluK_Sy) + "\t\t" + m_dOmd.sFind("黑","13","8","0",VluK_Sy) + "\n" );
    
    m_dTxt.push_back("\t\t\t\t\t\t\t\t" + 
        m_dOmd.sFind("黑","13","9","0",VluK_Lv)  + "\t\t" + m_dOmd.sFind("黑","13","10","0",VluK_Lv) + "\t\t\t\t" +
        m_dOmd.sFind("黑","13","9","0",VluK_Sx)  + "\t\t" + m_dOmd.sFind("黑","13","10","0",VluK_Sx) + "\t\t\t\t" +
        m_dOmd.sFind("黑","13","9","0",VluK_Sy)  + "\t\t" + m_dOmd.sFind("黑","13","10","0",VluK_Sy) + "\n" );

    m_dTxt.push_back("\t\t\t\t\t\t\t" + 
        m_dOmd.sFind("黑","13","11","0",VluK_Lv)  + "\t\t" + m_dOmd.sFind("黑","13","12","0",VluK_Lv) + "\t\t" + m_dOmd.sFind("黑","13","13","0",VluK_Lv) + "\t\t" +
        m_dOmd.sFind("黑","13","11","0",VluK_Sx)  + "\t\t" + m_dOmd.sFind("黑","13","12","0",VluK_Sx) + "\t\t" + m_dOmd.sFind("黑","13","13","0",VluK_Sx) + "\t\t" +
        m_dOmd.sFind("黑","13","11","0",VluK_Sy)  + "\t\t" + m_dOmd.sFind("黑","13","12","0",VluK_Sy) + "\t\t" + m_dOmd.sFind("黑","13","13","0",VluK_Sy) + "\n" );

        m_dTxt.push_back("\n");
}

void COmdFile1::o2tW5()
{
    m_dTxt.push_back("\t\t\t\t\t\t5點四角\tL\t\t\t\t\t5點四角\tx\t\t\t\t\t5點四角\ty\t\t\t\t\t5點四角\tT\t\t\t\t\t5點四角\tduv\n");
    m_dTxt.push_back("\t\t\t\t\t\t\t" + m_dOmd.sFind("白","5","1","0",VluK_Lv) + "\t\t"                              + m_dOmd.sFind("白","5","2","0",VluK_Lv) + "\t\t\t\t" + m_dOmd.sFind("白","5","1","0",VluK_Sx) + "\t\t"                              + m_dOmd.sFind("白","5","2","0",VluK_Sx) + "\t\t\t\t" + m_dOmd.sFind("白","5","1","0",VluK_Sy) + "\t\t"                              + m_dOmd.sFind("白","5","2","0",VluK_Sy) + "\t\t\t\t" + m_dOmd.sFind("白","5","1","0",VluK_T) + "\t\t"                                    + m_dOmd.sFind("白","5","2","0",VluK_T) + "\t\t\t\t" + m_dOmd.sFind("白","5","1","0",VluK_Duv) + "\t\t"                               + m_dOmd.sFind("白","5","2","0",VluK_Duv) + "\n");
    m_dTxt.push_back("\t\t\t\t\t\t\t\t"                                     + m_dOmd.sFind("白","5","3","0",VluK_Lv)                                       + "\t\t\t\t\t\t"                                   + m_dOmd.sFind("白","5","3","0",VluK_Sx)                                       + "\t\t\t\t\t\t"                                   + m_dOmd.sFind("白","5","3","0",VluK_Sy)                                       + "\t\t\t\t\t" +                                    "\t" + m_dOmd.sFind("白","5","3","0",VluK_T)                                      + "\t\t\t\t\t\t" +                                    m_dOmd.sFind("白","5","3","0",VluK_Duv) +                                        "\n");
    m_dTxt.push_back("\t\t\t\t\t\t\t" + m_dOmd.sFind("白","5","4","0",VluK_Lv) + "\t\t"                              + m_dOmd.sFind("白","5","5","0",VluK_Lv) + "\t\t\t\t" + m_dOmd.sFind("白","5","4","0",VluK_Sx) + "\t\t"                              + m_dOmd.sFind("白","5","5","0",VluK_Sx) + "\t\t\t\t" + m_dOmd.sFind("白","5","4","0",VluK_Sy) + "\t\t"                              + m_dOmd.sFind("白","5","5","0",VluK_Sy) + "\t\t\t\t" + m_dOmd.sFind("白","5","4","0",VluK_T) + "\t\t"                                    + m_dOmd.sFind("白","5","5","0",VluK_T) + "\t\t\t\t" + m_dOmd.sFind("白","5","4","0",VluK_Duv) + "\t\t"                               + m_dOmd.sFind("白","5","5","0",VluK_Duv) + "\n");
	
    m_dTxt.push_back("\n");
}
//m_debugLog
void COmdFile1::t2oInit()
{
	Ca210* pOldCa210;
	CMainFrame* pMainFrm = dynamic_cast<CMainFrame*>(AfxGetMainWnd());
    ASSERT_VALID(pMainFrm);
    
	pOldCa210 = pMainFrm->m_pCa210;

    pMainFrm->m_pCa210 = new Ca210sim();
	Ca210* pCa210 = pMainFrm->m_pCa210;
	pCa210->SetOnline(1);
	pCa210->SetLcmSize("14");
	
	TranScripter ts;

	DNA sortableDNA;
    DNA_sortable(sortableDNA);
    ts.Trans(sortableDNA, m_dOmd);
	
    DNA UnsortableDNA;
    DNA_Unsortable(UnsortableDNA);	
    ts.Trans(UnsortableDNA, m_dOmd);

	CPoint pointEmpty(0, 0);
	for (std::vector<Cartridge2>::iterator itor = m_dOmd.Begin(); itor != m_dOmd.End(); ++itor)
		itor->SetPointPosi(pointEmpty);

	delete pCa210;
	pMainFrm->m_pCa210 = pOldCa210;
}

void COmdFile1::TxtToOmd()
{
	m_fTxt.oTxtData(m_dTxt);
//檔頭
	t2oInfo();
//初始化裝資料的這些容器
	t2oInit();

//檔案資料      
	t2oWRGBD();
	t2oNits();
	t2oW9();
	t2oD9();
	t2oCT();
	t2oD25();
	t2oW49();
	t2oD21();
	t2oD13();
	t2oW5();

  	m_dOmd.freeEmptyCell();
	m_dTxt.clear();
}

void COmdFile1::t2oInfo()
{
	if (!m_isOld)
    {
		m_omdFileHead.iPnlID ( GetCell('B', 1)          );
		m_omdFileHead.iMsrDvc( GetCell('F', 1).Left(6)  );
		m_omdFileHead.iPrb   ( GetCell('F', 1).Right(8) );
		m_omdFileHead.iCHID  ( GetCell('G', 1).Right(2) );
		m_omdFileHead.iNitsLv( GetCell('G', 3).Mid(GetCell('G', 3).Find(':')+1));
    }
    else
    {
		m_omdFileHead.iPnlID ( GetCell('B', 1) );
		m_omdFileHead.iMsrDvc( GetCell('D', 1) );
		m_omdFileHead.iPrb   ( GetCell('F', 1) );
		m_omdFileHead.iCHID  ( GetCell('H', 1) );
		m_omdFileHead.iNitsLv( GetCell('G', 3).Mid(GetCell('G', 3).Find(':')+1));
		m_omdFileHead.iInch  ( GetCell('J', 1) );
	}
}

void COmdFile1::t2oWRGBD()
{
 	m_dOmd.Find("白","1","1"," ").GetBullet().i(VluK_Lv, GetCell('B', 3) );
    m_dOmd.Find("白","1","1"," ").GetBullet().i(VluK_Sx, GetCell('C', 3) );
    m_dOmd.Find("白","1","1"," ").GetBullet().i(VluK_Sy, GetCell('D', 3) );
    m_dOmd.Find("白","1","1"," ").GetBullet().i(VluK_Du, GetCell('E', 3) );
    m_dOmd.Find("白","1","1"," ").GetBullet().i(VluK_Dv, GetCell('F', 3) );
	
    m_dOmd.Find("紅","1","1"," ").GetBullet().i(VluK_Lv, GetCell('B', 4) );
    m_dOmd.Find("紅","1","1"," ").GetBullet().i(VluK_Sx, GetCell('C', 4) );
    m_dOmd.Find("紅","1","1"," ").GetBullet().i(VluK_Sy, GetCell('D', 4) );
    m_dOmd.Find("紅","1","1"," ").GetBullet().i(VluK_Du, GetCell('E', 4) );
    m_dOmd.Find("紅","1","1"," ").GetBullet().i(VluK_Dv, GetCell('F', 4) );
    
    m_dOmd.Find("綠","1","1"," ").GetBullet().i(VluK_Lv, GetCell('B', 5) );
    m_dOmd.Find("綠","1","1"," ").GetBullet().i(VluK_Sx, GetCell('C', 5) );
    m_dOmd.Find("綠","1","1"," ").GetBullet().i(VluK_Sy, GetCell('D', 5) );
    m_dOmd.Find("綠","1","1"," ").GetBullet().i(VluK_Du, GetCell('E', 5) );
    m_dOmd.Find("綠","1","1"," ").GetBullet().i(VluK_Dv, GetCell('F', 5) );
    
    m_dOmd.Find("藍","1","1"," ").GetBullet().i(VluK_Lv, GetCell('B', 6) );
    m_dOmd.Find("藍","1","1"," ").GetBullet().i(VluK_Sx, GetCell('C', 6) );
    m_dOmd.Find("藍","1","1"," ").GetBullet().i(VluK_Sy, GetCell('D', 6) );
    m_dOmd.Find("藍","1","1"," ").GetBullet().i(VluK_Du, GetCell('E', 6) );
    m_dOmd.Find("藍","1","1"," ").GetBullet().i(VluK_Dv, GetCell('F', 6) );
	
    m_dOmd.Find("黑","1","1"," ").GetBullet().i(VluK_Lv, GetCell('B', 7) );
    m_dOmd.Find("黑","1","1"," ").GetBullet().i(VluK_Sx, GetCell('C', 7) );
    m_dOmd.Find("黑","1","1"," ").GetBullet().i(VluK_Sy, GetCell('D', 7) );
    m_dOmd.Find("黑","1","1"," ").GetBullet().i(VluK_Du, GetCell('E', 7) );
    m_dOmd.Find("黑","1","1"," ").GetBullet().i(VluK_Dv, GetCell('F', 7) );
}

void COmdFile1::t2oNits()
{
    m_dOmd.Find("Nits","9","1","5-").GetBullet().i(VluK_Lv, GetCell('H', 3) );
    m_dOmd.Find("Nits","9","2","5-").GetBullet().i(VluK_Lv, GetCell('I', 3) );
    m_dOmd.Find("Nits","9","3","5-").GetBullet().i(VluK_Lv, GetCell('J', 3) );
    m_dOmd.Find("Nits","9","4","5-").GetBullet().i(VluK_Lv, GetCell('H', 4) );
    m_dOmd.Find("Nits","9","5","5-").GetBullet().i(VluK_Lv, GetCell('I', 4) );
    m_dOmd.Find("Nits","9","6","5-").GetBullet().i(VluK_Lv, GetCell('J', 4) );
    m_dOmd.Find("Nits","9","7","5-").GetBullet().i(VluK_Lv, GetCell('H', 5) );
    m_dOmd.Find("Nits","9","8","5-").GetBullet().i(VluK_Lv, GetCell('I', 5) );
    m_dOmd.Find("Nits","9","9","5-").GetBullet().i(VluK_Lv, GetCell('J', 5) );
    
    m_dOmd.Find("Nits","9","1","5-").GetBullet().i(VluK_Sx, GetCell('N', 3) );
    m_dOmd.Find("Nits","9","2","5-").GetBullet().i(VluK_Sx, GetCell('O', 3) );
    m_dOmd.Find("Nits","9","3","5-").GetBullet().i(VluK_Sx, GetCell('P', 3) );
    m_dOmd.Find("Nits","9","4","5-").GetBullet().i(VluK_Sx, GetCell('N', 4) );
    m_dOmd.Find("Nits","9","5","5-").GetBullet().i(VluK_Sx, GetCell('O', 4) );
    m_dOmd.Find("Nits","9","6","5-").GetBullet().i(VluK_Sx, GetCell('P', 4) );
    m_dOmd.Find("Nits","9","7","5-").GetBullet().i(VluK_Sx, GetCell('N', 5) );
    m_dOmd.Find("Nits","9","8","5-").GetBullet().i(VluK_Sx, GetCell('O', 5) );
    m_dOmd.Find("Nits","9","9","5-").GetBullet().i(VluK_Sx, GetCell('P', 5) );
    
    m_dOmd.Find("Nits","9","1","5-").GetBullet().i(VluK_Sy, GetCell('T', 3) );
    m_dOmd.Find("Nits","9","2","5-").GetBullet().i(VluK_Sy, GetCell('U', 3) );
    m_dOmd.Find("Nits","9","3","5-").GetBullet().i(VluK_Sy, GetCell('V', 3) );
    m_dOmd.Find("Nits","9","4","5-").GetBullet().i(VluK_Sy, GetCell('T', 4) );
    m_dOmd.Find("Nits","9","5","5-").GetBullet().i(VluK_Sy, GetCell('U', 4) );
    m_dOmd.Find("Nits","9","6","5-").GetBullet().i(VluK_Sy, GetCell('V', 4) );
    m_dOmd.Find("Nits","9","7","5-").GetBullet().i(VluK_Sy, GetCell('T', 5) );
    m_dOmd.Find("Nits","9","8","5-").GetBullet().i(VluK_Sy, GetCell('U', 5) );
    m_dOmd.Find("Nits","9","9","5-").GetBullet().i(VluK_Sy, GetCell('V', 5) );
    
    m_dOmd.Find("Nits","9","1","5-").GetBullet().i(VluK_T,  GetCell('Z' , 3) );
    m_dOmd.Find("Nits","9","2","5-").GetBullet().i(VluK_T,  GetCell("AA", 3) );
    m_dOmd.Find("Nits","9","3","5-").GetBullet().i(VluK_T,  GetCell("AB", 3) );
    m_dOmd.Find("Nits","9","4","5-").GetBullet().i(VluK_T,  GetCell('Z' , 4) );
    m_dOmd.Find("Nits","9","5","5-").GetBullet().i(VluK_T,  GetCell("AA", 4) );
    m_dOmd.Find("Nits","9","6","5-").GetBullet().i(VluK_T,  GetCell("AB", 4) );
    m_dOmd.Find("Nits","9","7","5-").GetBullet().i(VluK_T,  GetCell('Z' , 5) );
    m_dOmd.Find("Nits","9","8","5-").GetBullet().i(VluK_T,  GetCell("AA", 5) );
    m_dOmd.Find("Nits","9","9","5-").GetBullet().i(VluK_T,  GetCell("AB", 5) );
    
    m_dOmd.Find("Nits","9","1","5-").GetBullet().i(VluK_Duv,  GetCell("AF", 3) );
    m_dOmd.Find("Nits","9","2","5-").GetBullet().i(VluK_Duv,  GetCell("AG", 3) );
    m_dOmd.Find("Nits","9","3","5-").GetBullet().i(VluK_Duv,  GetCell("AH", 3) );
    m_dOmd.Find("Nits","9","4","5-").GetBullet().i(VluK_Duv,  GetCell("AF", 4) );
    m_dOmd.Find("Nits","9","5","5-").GetBullet().i(VluK_Duv,  GetCell("AG", 4) );
    m_dOmd.Find("Nits","9","6","5-").GetBullet().i(VluK_Duv,  GetCell("AH", 4) );
    m_dOmd.Find("Nits","9","7","5-").GetBullet().i(VluK_Duv,  GetCell("AF", 5) );
    m_dOmd.Find("Nits","9","8","5-").GetBullet().i(VluK_Duv,  GetCell("AG", 5) );
    m_dOmd.Find("Nits","9","9","5-").GetBullet().i(VluK_Duv,  GetCell("AH", 5) );
}

void COmdFile1::t2oW9()
{
	m_dOmd.Find("白","9","1","1/6").GetBullet().i(VluK_Lv, GetCell('H', 8) );
    m_dOmd.Find("白","9","2","1/6").GetBullet().i(VluK_Lv, GetCell('I', 8) );
    m_dOmd.Find("白","9","3","1/6").GetBullet().i(VluK_Lv, GetCell('J', 8) );
    m_dOmd.Find("白","9","4","1/6").GetBullet().i(VluK_Lv, GetCell('H', 9) );
    m_dOmd.Find("白","9","5","1/6").GetBullet().i(VluK_Lv, GetCell('I', 9) );
    m_dOmd.Find("白","9","6","1/6").GetBullet().i(VluK_Lv, GetCell('J', 9) );
    m_dOmd.Find("白","9","7","1/6").GetBullet().i(VluK_Lv, GetCell('H', 10) );
    m_dOmd.Find("白","9","8","1/6").GetBullet().i(VluK_Lv, GetCell('I', 10) );
    m_dOmd.Find("白","9","9","1/6").GetBullet().i(VluK_Lv, GetCell('J', 10) );
	
    m_dOmd.Find("白","9","1","1/6").GetBullet().i(VluK_Sx, GetCell('N', 8) );
    m_dOmd.Find("白","9","2","1/6").GetBullet().i(VluK_Sx, GetCell('O', 8) );
    m_dOmd.Find("白","9","3","1/6").GetBullet().i(VluK_Sx, GetCell('P', 8) );
    m_dOmd.Find("白","9","4","1/6").GetBullet().i(VluK_Sx, GetCell('N', 9) );
    m_dOmd.Find("白","9","5","1/6").GetBullet().i(VluK_Sx, GetCell('O', 9) );
    m_dOmd.Find("白","9","6","1/6").GetBullet().i(VluK_Sx, GetCell('P', 9) );
    m_dOmd.Find("白","9","7","1/6").GetBullet().i(VluK_Sx, GetCell('N', 10) );
    m_dOmd.Find("白","9","8","1/6").GetBullet().i(VluK_Sx, GetCell('O', 10) );
    m_dOmd.Find("白","9","9","1/6").GetBullet().i(VluK_Sx, GetCell('P', 10) );
    
    m_dOmd.Find("白","9","1","1/6").GetBullet().i(VluK_Sy, GetCell('T', 8) );
    m_dOmd.Find("白","9","2","1/6").GetBullet().i(VluK_Sy, GetCell('U', 8) );
    m_dOmd.Find("白","9","3","1/6").GetBullet().i(VluK_Sy, GetCell('V', 8) );
    m_dOmd.Find("白","9","4","1/6").GetBullet().i(VluK_Sy, GetCell('T', 9) );
    m_dOmd.Find("白","9","5","1/6").GetBullet().i(VluK_Sy, GetCell('U', 9) );
    m_dOmd.Find("白","9","6","1/6").GetBullet().i(VluK_Sy, GetCell('V', 9) );
    m_dOmd.Find("白","9","7","1/6").GetBullet().i(VluK_Sy, GetCell('T', 10) );
    m_dOmd.Find("白","9","8","1/6").GetBullet().i(VluK_Sy, GetCell('U', 10) );
    m_dOmd.Find("白","9","9","1/6").GetBullet().i(VluK_Sy, GetCell('V', 10) );
    
    m_dOmd.Find("白","9","1","1/6").GetBullet().i(VluK_T,  GetCell('Z' , 8) );
    m_dOmd.Find("白","9","2","1/6").GetBullet().i(VluK_T,  GetCell("AA", 8) );
    m_dOmd.Find("白","9","3","1/6").GetBullet().i(VluK_T,  GetCell("AB", 8) );
    m_dOmd.Find("白","9","4","1/6").GetBullet().i(VluK_T,  GetCell('Z' , 9) );
    m_dOmd.Find("白","9","5","1/6").GetBullet().i(VluK_T,  GetCell("AA", 9) );
    m_dOmd.Find("白","9","6","1/6").GetBullet().i(VluK_T,  GetCell("AB", 9) );
    m_dOmd.Find("白","9","7","1/6").GetBullet().i(VluK_T,  GetCell('Z' , 10) );
    m_dOmd.Find("白","9","8","1/6").GetBullet().i(VluK_T,  GetCell("AA", 10) );
    m_dOmd.Find("白","9","9","1/6").GetBullet().i(VluK_T,  GetCell("AB", 10) );
	
    m_dOmd.Find("白","9","1","1/6").GetBullet().i(VluK_Duv,  GetCell("AF", 8) );
    m_dOmd.Find("白","9","2","1/6").GetBullet().i(VluK_Duv,  GetCell("AG", 8) );
    m_dOmd.Find("白","9","3","1/6").GetBullet().i(VluK_Duv,  GetCell("AH", 8) );
    m_dOmd.Find("白","9","4","1/6").GetBullet().i(VluK_Duv,  GetCell("AF", 9) );
    m_dOmd.Find("白","9","5","1/6").GetBullet().i(VluK_Duv,  GetCell("AG", 9) );
    m_dOmd.Find("白","9","6","1/6").GetBullet().i(VluK_Duv,  GetCell("AH", 9) );
    m_dOmd.Find("白","9","7","1/6").GetBullet().i(VluK_Duv,  GetCell("AF", 10) );
    m_dOmd.Find("白","9","8","1/6").GetBullet().i(VluK_Duv,  GetCell("AG", 10) );
    m_dOmd.Find("白","9","9","1/6").GetBullet().i(VluK_Duv,  GetCell("AH", 10) );
}

void COmdFile1::t2oD9()
{
    m_dOmd.Find("黑","9","1","0").GetBullet().i(VluK_Lv, GetCell('H', 13) );
    m_dOmd.Find("黑","9","2","0").GetBullet().i(VluK_Lv, GetCell('I', 13) );
    m_dOmd.Find("黑","9","3","0").GetBullet().i(VluK_Lv, GetCell('J', 13) );
    m_dOmd.Find("黑","9","4","0").GetBullet().i(VluK_Lv, GetCell('H', 14) );
    m_dOmd.Find("黑","9","5","0").GetBullet().i(VluK_Lv, GetCell('I', 14) );
    m_dOmd.Find("黑","9","6","0").GetBullet().i(VluK_Lv, GetCell('J', 14) );
    m_dOmd.Find("黑","9","7","0").GetBullet().i(VluK_Lv, GetCell('H', 15) );
    m_dOmd.Find("黑","9","8","0").GetBullet().i(VluK_Lv, GetCell('I', 15) );
    m_dOmd.Find("黑","9","9","0").GetBullet().i(VluK_Lv, GetCell('J', 15) );
    
    m_dOmd.Find("黑","9","1","0").GetBullet().i(VluK_Sx, GetCell('N', 13) );
    m_dOmd.Find("黑","9","2","0").GetBullet().i(VluK_Sx, GetCell('O', 13) );
    m_dOmd.Find("黑","9","3","0").GetBullet().i(VluK_Sx, GetCell('P', 13) );
    m_dOmd.Find("黑","9","4","0").GetBullet().i(VluK_Sx, GetCell('N', 14) );
    m_dOmd.Find("黑","9","5","0").GetBullet().i(VluK_Sx, GetCell('O', 14) );
    m_dOmd.Find("黑","9","6","0").GetBullet().i(VluK_Sx, GetCell('P', 14) );
    m_dOmd.Find("黑","9","7","0").GetBullet().i(VluK_Sx, GetCell('N', 15) );
    m_dOmd.Find("黑","9","8","0").GetBullet().i(VluK_Sx, GetCell('O', 15) );
    m_dOmd.Find("黑","9","9","0").GetBullet().i(VluK_Sx, GetCell('P', 15) );
    
    m_dOmd.Find("黑","9","1","0").GetBullet().i(VluK_Sy, GetCell('T', 13) );
    m_dOmd.Find("黑","9","2","0").GetBullet().i(VluK_Sy, GetCell('U', 13) );
    m_dOmd.Find("黑","9","3","0").GetBullet().i(VluK_Sy, GetCell('V', 13) );
    m_dOmd.Find("黑","9","4","0").GetBullet().i(VluK_Sy, GetCell('T', 14) );
    m_dOmd.Find("黑","9","5","0").GetBullet().i(VluK_Sy, GetCell('U', 14) );
    m_dOmd.Find("黑","9","6","0").GetBullet().i(VluK_Sy, GetCell('V', 14) );
    m_dOmd.Find("黑","9","7","0").GetBullet().i(VluK_Sy, GetCell('T', 15) );
    m_dOmd.Find("黑","9","8","0").GetBullet().i(VluK_Sy, GetCell('U', 15) );
    m_dOmd.Find("黑","9","9","0").GetBullet().i(VluK_Sy, GetCell('V', 15) );
    
    m_dOmd.Find("黑","9","1","0").GetBullet().i(VluK_T,  GetCell('Z' , 13) );
    m_dOmd.Find("黑","9","2","0").GetBullet().i(VluK_T,  GetCell("AA", 13) );
    m_dOmd.Find("黑","9","3","0").GetBullet().i(VluK_T,  GetCell("AB", 13) );
    m_dOmd.Find("黑","9","4","0").GetBullet().i(VluK_T,  GetCell('Z' , 14) );
    m_dOmd.Find("黑","9","5","0").GetBullet().i(VluK_T,  GetCell("AA", 14) );
    m_dOmd.Find("黑","9","6","0").GetBullet().i(VluK_T,  GetCell("AB", 14) );
    m_dOmd.Find("黑","9","7","0").GetBullet().i(VluK_T,  GetCell('Z' , 15) );
    m_dOmd.Find("黑","9","8","0").GetBullet().i(VluK_T,  GetCell("AA", 15) );
    m_dOmd.Find("黑","9","9","0").GetBullet().i(VluK_T,  GetCell("AB", 15) );
    
    m_dOmd.Find("黑","9","1","0").GetBullet().i(VluK_Duv,  GetCell("AF", 13) );
    m_dOmd.Find("黑","9","2","0").GetBullet().i(VluK_Duv,  GetCell("AG", 13) );
    m_dOmd.Find("黑","9","3","0").GetBullet().i(VluK_Duv,  GetCell("AH", 13) );
    m_dOmd.Find("黑","9","4","0").GetBullet().i(VluK_Duv,  GetCell("AF", 14) );
    m_dOmd.Find("黑","9","5","0").GetBullet().i(VluK_Duv,  GetCell("AG", 14) );
    m_dOmd.Find("黑","9","6","0").GetBullet().i(VluK_Duv,  GetCell("AH", 14) );
    m_dOmd.Find("黑","9","7","0").GetBullet().i(VluK_Duv,  GetCell("AF", 15) );
    m_dOmd.Find("黑","9","8","0").GetBullet().i(VluK_Duv,  GetCell("AG", 15) );
    m_dOmd.Find("黑","9","9","0").GetBullet().i(VluK_Duv,  GetCell("AH", 15) );
}

void COmdFile1::t2oCT()
{
    m_dOmd.Find("cross","4","1","1/4").GetBullet().i(VluK_Lv, GetCell('I', 18) );
    m_dOmd.Find("cross","4","2","1/4").GetBullet().i(VluK_Lv, GetCell('H', 19) );
    m_dOmd.Find("cross","4","3","1/4").GetBullet().i(VluK_Lv, GetCell('J', 19) );
    m_dOmd.Find("cross","4","4","1/4").GetBullet().i(VluK_Lv, GetCell('I', 20) );
	
    m_dOmd.Find("crossW","4","1","1/4").GetBullet().i(VluK_Lv, GetCell('O', 18) );
    m_dOmd.Find("crossW","4","2","1/4").GetBullet().i(VluK_Lv, GetCell('N', 19) );
    m_dOmd.Find("crossW","4","3","1/4").GetBullet().i(VluK_Lv, GetCell('P', 19) );
    m_dOmd.Find("crossW","4","4","1/4").GetBullet().i(VluK_Lv, GetCell('O', 20) );
	
    m_dOmd.Find("crossD","4","1","1/4").GetBullet().i(VluK_Lv, GetCell('U', 18) );
    m_dOmd.Find("crossD","4","2","1/4").GetBullet().i(VluK_Lv, GetCell('T', 19) );
    m_dOmd.Find("crossD","4","3","1/4").GetBullet().i(VluK_Lv, GetCell('V', 19) );
    m_dOmd.Find("crossD","4","4","1/4").GetBullet().i(VluK_Lv, GetCell('U', 20) );
}

void COmdFile1::t2oD25()
{
    m_dOmd.Find("黑","25","1","0").GetBullet().i(VluK_Lv, GetCell('H', 26) );
    m_dOmd.Find("黑","25","2","0").GetBullet().i(VluK_Lv, GetCell('J', 26) );
    m_dOmd.Find("黑","25","3","0").GetBullet().i(VluK_Lv, GetCell('H', 28) );
    m_dOmd.Find("黑","25","4","0").GetBullet().i(VluK_Lv, GetCell('J', 28) );
    m_dOmd.Find("黑","25","5","0").GetBullet().i(VluK_Lv, GetCell('I', 27) );
    m_dOmd.Find("黑","25","6","0").GetBullet().i(VluK_Lv, GetCell('K', 26) );
    m_dOmd.Find("黑","25","7","0").GetBullet().i(VluK_Lv, GetCell('N', 26) );
    m_dOmd.Find("黑","25","8","0").GetBullet().i(VluK_Lv, GetCell('L', 26) );
    m_dOmd.Find("黑","25","9","0").GetBullet().i(VluK_Lv, GetCell('N', 28) );
    m_dOmd.Find("黑","25","10","0").GetBullet().i(VluK_Lv, GetCell('L', 28) );
    m_dOmd.Find("黑","25","11","0").GetBullet().i(VluK_Lv, GetCell('M', 27) );
    m_dOmd.Find("黑","25","12","0").GetBullet().i(VluK_Lv, GetCell('H', 29) );
    m_dOmd.Find("黑","25","13","0").GetBullet().i(VluK_Lv, GetCell('K', 29) );
    m_dOmd.Find("黑","25","14","0").GetBullet().i(VluK_Lv, GetCell('N', 29) );
    m_dOmd.Find("黑","25","15","0").GetBullet().i(VluK_Lv, GetCell('H', 32) );
    m_dOmd.Find("黑","25","16","0").GetBullet().i(VluK_Lv, GetCell('J', 32) );
    m_dOmd.Find("黑","25","17","0").GetBullet().i(VluK_Lv, GetCell('H', 30) );
    m_dOmd.Find("黑","25","18","0").GetBullet().i(VluK_Lv, GetCell('J', 30) );
    m_dOmd.Find("黑","25","19","0").GetBullet().i(VluK_Lv, GetCell('I', 31) );
    m_dOmd.Find("黑","25","20","0").GetBullet().i(VluK_Lv, GetCell('K', 32) );
    m_dOmd.Find("黑","25","21","0").GetBullet().i(VluK_Lv, GetCell('N', 32) );
    m_dOmd.Find("黑","25","22","0").GetBullet().i(VluK_Lv, GetCell('L', 32) );
    m_dOmd.Find("黑","25","23","0").GetBullet().i(VluK_Lv, GetCell('N', 30) );
    m_dOmd.Find("黑","25","24","0").GetBullet().i(VluK_Lv, GetCell('L', 30) );
    m_dOmd.Find("黑","25","25","0").GetBullet().i(VluK_Lv, GetCell('M', 31) );

    m_dOmd.Find("黑","25","1","0").GetBullet().i(VluK_Sx, GetCell('P', 26) );
    m_dOmd.Find("黑","25","2","0").GetBullet().i(VluK_Sx, GetCell('R', 26) );
    m_dOmd.Find("黑","25","3","0").GetBullet().i(VluK_Sx, GetCell('P', 28) );
    m_dOmd.Find("黑","25","4","0").GetBullet().i(VluK_Sx, GetCell('R', 28) );
    m_dOmd.Find("黑","25","5","0").GetBullet().i(VluK_Sx, GetCell('Q', 27) );
    m_dOmd.Find("黑","25","6","0").GetBullet().i(VluK_Sx, GetCell('S', 26) );
    m_dOmd.Find("黑","25","7","0").GetBullet().i(VluK_Sx, GetCell('V', 26) );
    m_dOmd.Find("黑","25","8","0").GetBullet().i(VluK_Sx, GetCell('T', 26) );
    m_dOmd.Find("黑","25","9","0").GetBullet().i(VluK_Sx, GetCell('V', 28) );
    m_dOmd.Find("黑","25","10","0").GetBullet().i(VluK_Sx, GetCell('T', 28) );
    m_dOmd.Find("黑","25","11","0").GetBullet().i(VluK_Sx, GetCell('U', 27) );
    m_dOmd.Find("黑","25","12","0").GetBullet().i(VluK_Sx, GetCell('P', 29) );
    m_dOmd.Find("黑","25","13","0").GetBullet().i(VluK_Sx, GetCell('S', 29) );
    m_dOmd.Find("黑","25","14","0").GetBullet().i(VluK_Sx, GetCell('V', 29) );
    m_dOmd.Find("黑","25","15","0").GetBullet().i(VluK_Sx, GetCell('P', 32) );
    m_dOmd.Find("黑","25","16","0").GetBullet().i(VluK_Sx, GetCell('R', 32) );
    m_dOmd.Find("黑","25","17","0").GetBullet().i(VluK_Sx, GetCell('P', 30) );
    m_dOmd.Find("黑","25","18","0").GetBullet().i(VluK_Sx, GetCell('R', 30) );
    m_dOmd.Find("黑","25","19","0").GetBullet().i(VluK_Sx, GetCell('Q', 31) );
    m_dOmd.Find("黑","25","20","0").GetBullet().i(VluK_Sx, GetCell('S', 32) );
    m_dOmd.Find("黑","25","21","0").GetBullet().i(VluK_Sx, GetCell('V', 32) );
    m_dOmd.Find("黑","25","22","0").GetBullet().i(VluK_Sx, GetCell('T', 32) );
    m_dOmd.Find("黑","25","23","0").GetBullet().i(VluK_Sx, GetCell('V', 30) );
    m_dOmd.Find("黑","25","24","0").GetBullet().i(VluK_Sx, GetCell('T', 30) );
    m_dOmd.Find("黑","25","25","0").GetBullet().i(VluK_Sx, GetCell('U', 31) );

    m_dOmd.Find("黑","25","1","0").GetBullet().i(VluK_Sy, GetCell('X' , 26) );
    m_dOmd.Find("黑","25","2","0").GetBullet().i(VluK_Sy, GetCell('Z' , 26) );
    m_dOmd.Find("黑","25","3","0").GetBullet().i(VluK_Sy, GetCell('X' , 28) );
    m_dOmd.Find("黑","25","4","0").GetBullet().i(VluK_Sy, GetCell('Z' , 28) );
    m_dOmd.Find("黑","25","5","0").GetBullet().i(VluK_Sy, GetCell('Y' , 27) );
    m_dOmd.Find("黑","25","6","0").GetBullet().i(VluK_Sy, GetCell("AA", 26) );
    m_dOmd.Find("黑","25","7","0").GetBullet().i(VluK_Sy, GetCell("AD", 26) );
    m_dOmd.Find("黑","25","8","0").GetBullet().i(VluK_Sy, GetCell("AB", 26) );
    m_dOmd.Find("黑","25","9","0").GetBullet().i(VluK_Sy, GetCell("AD", 28) );
    m_dOmd.Find("黑","25","10","0").GetBullet().i(VluK_Sy, GetCell("AB", 28) );
    m_dOmd.Find("黑","25","11","0").GetBullet().i(VluK_Sy, GetCell("AC", 27) );
    m_dOmd.Find("黑","25","12","0").GetBullet().i(VluK_Sy, GetCell('X' , 29) );
    m_dOmd.Find("黑","25","13","0").GetBullet().i(VluK_Sy, GetCell("AA", 29) );
    m_dOmd.Find("黑","25","14","0").GetBullet().i(VluK_Sy, GetCell("AD", 29) );
    m_dOmd.Find("黑","25","15","0").GetBullet().i(VluK_Sy, GetCell('X' , 32) );
    m_dOmd.Find("黑","25","16","0").GetBullet().i(VluK_Sy, GetCell('Z' , 32) );
    m_dOmd.Find("黑","25","17","0").GetBullet().i(VluK_Sy, GetCell('X' , 30) );
    m_dOmd.Find("黑","25","18","0").GetBullet().i(VluK_Sy, GetCell('Z' , 30) );
    m_dOmd.Find("黑","25","19","0").GetBullet().i(VluK_Sy, GetCell('Y' , 31) );
    m_dOmd.Find("黑","25","20","0").GetBullet().i(VluK_Sy, GetCell("AA", 32) );
    m_dOmd.Find("黑","25","21","0").GetBullet().i(VluK_Sy, GetCell("AD", 32) );
    m_dOmd.Find("黑","25","22","0").GetBullet().i(VluK_Sy, GetCell("AB", 32) );
    m_dOmd.Find("黑","25","23","0").GetBullet().i(VluK_Sy, GetCell("AD", 30) );
    m_dOmd.Find("黑","25","24","0").GetBullet().i(VluK_Sy, GetCell("AB", 30) );
    m_dOmd.Find("黑","25","25","0").GetBullet().i(VluK_Sy, GetCell("AC", 31) );
    
	m_dOmd.Find("黑","25","1","0").GetBullet().i(VluK_T,  GetCell("AF", 26) );
    m_dOmd.Find("黑","25","2","0").GetBullet().i(VluK_T,  GetCell("AH", 26) );
    m_dOmd.Find("黑","25","3","0").GetBullet().i(VluK_T,  GetCell("AF", 28) );
    m_dOmd.Find("黑","25","4","0").GetBullet().i(VluK_T,  GetCell("AH", 28) );
    m_dOmd.Find("黑","25","5","0").GetBullet().i(VluK_T,  GetCell("AG", 27) );
    m_dOmd.Find("黑","25","6","0").GetBullet().i(VluK_T,  GetCell("AI", 26) );
    m_dOmd.Find("黑","25","7","0").GetBullet().i(VluK_T,  GetCell("AL", 26) );
    m_dOmd.Find("黑","25","8","0").GetBullet().i(VluK_T,  GetCell("AJ", 26) );
    m_dOmd.Find("黑","25","9","0").GetBullet().i(VluK_T,  GetCell("AL", 28) );
    m_dOmd.Find("黑","25","10","0").GetBullet().i(VluK_T,  GetCell("AJ", 28) );
    m_dOmd.Find("黑","25","11","0").GetBullet().i(VluK_T,  GetCell("AK", 27) );
    m_dOmd.Find("黑","25","12","0").GetBullet().i(VluK_T,  GetCell("AF", 29) );
    m_dOmd.Find("黑","25","13","0").GetBullet().i(VluK_T,  GetCell("AI", 29) );
    m_dOmd.Find("黑","25","14","0").GetBullet().i(VluK_T,  GetCell("AL", 29) );
    m_dOmd.Find("黑","25","15","0").GetBullet().i(VluK_T,  GetCell("AF", 32) );
    m_dOmd.Find("黑","25","16","0").GetBullet().i(VluK_T,  GetCell("AH", 32) );
    m_dOmd.Find("黑","25","17","0").GetBullet().i(VluK_T,  GetCell("AF", 30) );
    m_dOmd.Find("黑","25","18","0").GetBullet().i(VluK_T,  GetCell("AH", 30) );
    m_dOmd.Find("黑","25","19","0").GetBullet().i(VluK_T,  GetCell("AG", 31) );
    m_dOmd.Find("黑","25","20","0").GetBullet().i(VluK_T,  GetCell("AI", 32) );
    m_dOmd.Find("黑","25","21","0").GetBullet().i(VluK_T,  GetCell("AL", 32) );
    m_dOmd.Find("黑","25","22","0").GetBullet().i(VluK_T,  GetCell("AJ", 32) );
    m_dOmd.Find("黑","25","23","0").GetBullet().i(VluK_T,  GetCell("AL", 30) );
    m_dOmd.Find("黑","25","24","0").GetBullet().i(VluK_T,  GetCell("AJ", 30) );
    m_dOmd.Find("黑","25","25","0").GetBullet().i(VluK_T,  GetCell("AK", 31) );

    m_dOmd.Find("黑","25","1","0").GetBullet().i(VluK_Duv,  GetCell("AN", 26) );
    m_dOmd.Find("黑","25","2","0").GetBullet().i(VluK_Duv,  GetCell("AP", 26) );
    m_dOmd.Find("黑","25","3","0").GetBullet().i(VluK_Duv,  GetCell("AN", 28) );
    m_dOmd.Find("黑","25","4","0").GetBullet().i(VluK_Duv,  GetCell("AP", 28) );
    m_dOmd.Find("黑","25","5","0").GetBullet().i(VluK_Duv,  GetCell("AO", 27) );
    m_dOmd.Find("黑","25","6","0").GetBullet().i(VluK_Duv,  GetCell("AQ", 26) );
    m_dOmd.Find("黑","25","7","0").GetBullet().i(VluK_Duv,  GetCell("AT", 26) );
    m_dOmd.Find("黑","25","8","0").GetBullet().i(VluK_Duv,  GetCell("AR", 26) );
    m_dOmd.Find("黑","25","9","0").GetBullet().i(VluK_Duv,  GetCell("AT", 28) );
    m_dOmd.Find("黑","25","10","0").GetBullet().i(VluK_Duv,  GetCell("AR", 28) );
    m_dOmd.Find("黑","25","11","0").GetBullet().i(VluK_Duv,  GetCell("AS", 27) );
    m_dOmd.Find("黑","25","12","0").GetBullet().i(VluK_Duv,  GetCell("AN", 29) );
    m_dOmd.Find("黑","25","13","0").GetBullet().i(VluK_Duv,  GetCell("AQ", 29) );
    m_dOmd.Find("黑","25","14","0").GetBullet().i(VluK_Duv,  GetCell("AT", 29) );
    m_dOmd.Find("黑","25","15","0").GetBullet().i(VluK_Duv,  GetCell("AN", 32) );
    m_dOmd.Find("黑","25","16","0").GetBullet().i(VluK_Duv,  GetCell("AP", 32) );
    m_dOmd.Find("黑","25","17","0").GetBullet().i(VluK_Duv,  GetCell("AN", 30) );
    m_dOmd.Find("黑","25","18","0").GetBullet().i(VluK_Duv,  GetCell("AP", 30) );
    m_dOmd.Find("黑","25","19","0").GetBullet().i(VluK_Duv,  GetCell("AO", 31) );
    m_dOmd.Find("黑","25","20","0").GetBullet().i(VluK_Duv,  GetCell("AQ", 32) );
    m_dOmd.Find("黑","25","21","0").GetBullet().i(VluK_Duv,  GetCell("AT", 32) );
    m_dOmd.Find("黑","25","22","0").GetBullet().i(VluK_Duv,  GetCell("AR", 32) );
    m_dOmd.Find("黑","25","23","0").GetBullet().i(VluK_Duv,  GetCell("AT", 30) );
    m_dOmd.Find("黑","25","24","0").GetBullet().i(VluK_Duv,  GetCell("AR", 30) );
    m_dOmd.Find("黑","25","25","0").GetBullet().i(VluK_Duv,  GetCell("AS", 31) );
}

void COmdFile1::t2oW49()
{
    m_dOmd.Find("白","49","1"," ").GetBullet().i(VluK_Lv, GetCell('H', 35) );
    m_dOmd.Find("白","49","2"," ").GetBullet().i(VluK_Lv, GetCell('I', 35) );
    m_dOmd.Find("白","49","3"," ").GetBullet().i(VluK_Lv, GetCell('J', 35) );
    m_dOmd.Find("白","49","4"," ").GetBullet().i(VluK_Lv, GetCell('K', 35) );
    m_dOmd.Find("白","49","5"," ").GetBullet().i(VluK_Lv, GetCell('L', 35) );
    m_dOmd.Find("白","49","6"," ").GetBullet().i(VluK_Lv, GetCell('M', 35) );
    m_dOmd.Find("白","49","7"," ").GetBullet().i(VluK_Lv, GetCell('N', 35) );
    m_dOmd.Find("白","49","8"," ").GetBullet().i(VluK_Lv, GetCell('H', 36) );
    m_dOmd.Find("白","49","9"," ").GetBullet().i(VluK_Lv, GetCell('I', 36) );
    m_dOmd.Find("白","49","10"," ").GetBullet().i(VluK_Lv, GetCell('J', 36) );
    m_dOmd.Find("白","49","11"," ").GetBullet().i(VluK_Lv, GetCell('K', 36) );
    m_dOmd.Find("白","49","12"," ").GetBullet().i(VluK_Lv, GetCell('L', 36) );
    m_dOmd.Find("白","49","13"," ").GetBullet().i(VluK_Lv, GetCell('M', 36) );
    m_dOmd.Find("白","49","14"," ").GetBullet().i(VluK_Lv, GetCell('N', 36) );
    m_dOmd.Find("白","49","15"," ").GetBullet().i(VluK_Lv, GetCell('H', 37) );
    m_dOmd.Find("白","49","16"," ").GetBullet().i(VluK_Lv, GetCell('I', 37) );
    m_dOmd.Find("白","49","17"," ").GetBullet().i(VluK_Lv, GetCell('J', 37) );
    m_dOmd.Find("白","49","18"," ").GetBullet().i(VluK_Lv, GetCell('K', 37) );
    m_dOmd.Find("白","49","19"," ").GetBullet().i(VluK_Lv, GetCell('L', 37) );
    m_dOmd.Find("白","49","20"," ").GetBullet().i(VluK_Lv, GetCell('M', 37) );
    m_dOmd.Find("白","49","21"," ").GetBullet().i(VluK_Lv, GetCell('N', 37) );
    m_dOmd.Find("白","49","22"," ").GetBullet().i(VluK_Lv, GetCell('H', 38) );
    m_dOmd.Find("白","49","23"," ").GetBullet().i(VluK_Lv, GetCell('I', 38) );
    m_dOmd.Find("白","49","24"," ").GetBullet().i(VluK_Lv, GetCell('J', 38) );
    m_dOmd.Find("白","49","25"," ").GetBullet().i(VluK_Lv, GetCell('K', 38) );
    m_dOmd.Find("白","49","26"," ").GetBullet().i(VluK_Lv, GetCell('L', 38) );
    m_dOmd.Find("白","49","27"," ").GetBullet().i(VluK_Lv, GetCell('M', 38) );
    m_dOmd.Find("白","49","28"," ").GetBullet().i(VluK_Lv, GetCell('N', 38) );
    m_dOmd.Find("白","49","29"," ").GetBullet().i(VluK_Lv, GetCell('H', 39) );
    m_dOmd.Find("白","49","30"," ").GetBullet().i(VluK_Lv, GetCell('I', 39) );
    m_dOmd.Find("白","49","31"," ").GetBullet().i(VluK_Lv, GetCell('J', 39) );
    m_dOmd.Find("白","49","32"," ").GetBullet().i(VluK_Lv, GetCell('K', 39) );
    m_dOmd.Find("白","49","33"," ").GetBullet().i(VluK_Lv, GetCell('L', 39) );
    m_dOmd.Find("白","49","34"," ").GetBullet().i(VluK_Lv, GetCell('M', 39) );
    m_dOmd.Find("白","49","35"," ").GetBullet().i(VluK_Lv, GetCell('N', 39) );
    m_dOmd.Find("白","49","36"," ").GetBullet().i(VluK_Lv, GetCell('H', 40) );
    m_dOmd.Find("白","49","37"," ").GetBullet().i(VluK_Lv, GetCell('I', 40) );
    m_dOmd.Find("白","49","38"," ").GetBullet().i(VluK_Lv, GetCell('J', 40) );
    m_dOmd.Find("白","49","39"," ").GetBullet().i(VluK_Lv, GetCell('K', 40) );
    m_dOmd.Find("白","49","40"," ").GetBullet().i(VluK_Lv, GetCell('L', 40) );
    m_dOmd.Find("白","49","41"," ").GetBullet().i(VluK_Lv, GetCell('M', 40) );
    m_dOmd.Find("白","49","42"," ").GetBullet().i(VluK_Lv, GetCell('N', 40) );
    m_dOmd.Find("白","49","43"," ").GetBullet().i(VluK_Lv, GetCell('H', 41) );
    m_dOmd.Find("白","49","44"," ").GetBullet().i(VluK_Lv, GetCell('I', 41) );
    m_dOmd.Find("白","49","45"," ").GetBullet().i(VluK_Lv, GetCell('J', 41) );
    m_dOmd.Find("白","49","46"," ").GetBullet().i(VluK_Lv, GetCell('K', 41) );
    m_dOmd.Find("白","49","47"," ").GetBullet().i(VluK_Lv, GetCell('L', 41) );
    m_dOmd.Find("白","49","48"," ").GetBullet().i(VluK_Lv, GetCell('M', 41) );
    m_dOmd.Find("白","49","49"," ").GetBullet().i(VluK_Lv, GetCell('N', 41) );

    m_dOmd.Find("白","49","1"," ").GetBullet().i(VluK_Sx, GetCell('P', 35) );
    m_dOmd.Find("白","49","2"," ").GetBullet().i(VluK_Sx, GetCell('Q', 35) );
    m_dOmd.Find("白","49","3"," ").GetBullet().i(VluK_Sx, GetCell('R', 35) );
    m_dOmd.Find("白","49","4"," ").GetBullet().i(VluK_Sx, GetCell('S', 35) );
    m_dOmd.Find("白","49","5"," ").GetBullet().i(VluK_Sx, GetCell('T', 35) );
    m_dOmd.Find("白","49","6"," ").GetBullet().i(VluK_Sx, GetCell('U', 35) );
    m_dOmd.Find("白","49","7"," ").GetBullet().i(VluK_Sx, GetCell('V', 35) );
    m_dOmd.Find("白","49","8"," ").GetBullet().i(VluK_Sx, GetCell('P', 36) );
    m_dOmd.Find("白","49","9"," ").GetBullet().i(VluK_Sx, GetCell('Q', 36) );
    m_dOmd.Find("白","49","10"," ").GetBullet().i(VluK_Sx, GetCell('R', 36) );
    m_dOmd.Find("白","49","11"," ").GetBullet().i(VluK_Sx, GetCell('S', 36) );
    m_dOmd.Find("白","49","12"," ").GetBullet().i(VluK_Sx, GetCell('T', 36) );
    m_dOmd.Find("白","49","13"," ").GetBullet().i(VluK_Sx, GetCell('U', 36) );
    m_dOmd.Find("白","49","14"," ").GetBullet().i(VluK_Sx, GetCell('V', 36) );
    m_dOmd.Find("白","49","15"," ").GetBullet().i(VluK_Sx, GetCell('P', 37) );
    m_dOmd.Find("白","49","16"," ").GetBullet().i(VluK_Sx, GetCell('Q', 37) );
    m_dOmd.Find("白","49","17"," ").GetBullet().i(VluK_Sx, GetCell('R', 37) );
    m_dOmd.Find("白","49","18"," ").GetBullet().i(VluK_Sx, GetCell('S', 37) );
    m_dOmd.Find("白","49","19"," ").GetBullet().i(VluK_Sx, GetCell('T', 37) );
    m_dOmd.Find("白","49","20"," ").GetBullet().i(VluK_Sx, GetCell('U', 37) );
    m_dOmd.Find("白","49","21"," ").GetBullet().i(VluK_Sx, GetCell('V', 37) );
    m_dOmd.Find("白","49","22"," ").GetBullet().i(VluK_Sx, GetCell('P', 38) );
    m_dOmd.Find("白","49","23"," ").GetBullet().i(VluK_Sx, GetCell('Q', 38) );
    m_dOmd.Find("白","49","24"," ").GetBullet().i(VluK_Sx, GetCell('R', 38) );
    m_dOmd.Find("白","49","25"," ").GetBullet().i(VluK_Sx, GetCell('S', 38) );
    m_dOmd.Find("白","49","26"," ").GetBullet().i(VluK_Sx, GetCell('T', 38) );
    m_dOmd.Find("白","49","27"," ").GetBullet().i(VluK_Sx, GetCell('U', 38) );
    m_dOmd.Find("白","49","28"," ").GetBullet().i(VluK_Sx, GetCell('V', 38) );
    m_dOmd.Find("白","49","29"," ").GetBullet().i(VluK_Sx, GetCell('P', 39) );
    m_dOmd.Find("白","49","30"," ").GetBullet().i(VluK_Sx, GetCell('Q', 39) );
    m_dOmd.Find("白","49","31"," ").GetBullet().i(VluK_Sx, GetCell('R', 39) );
    m_dOmd.Find("白","49","32"," ").GetBullet().i(VluK_Sx, GetCell('S', 39) );
    m_dOmd.Find("白","49","33"," ").GetBullet().i(VluK_Sx, GetCell('T', 39) );
    m_dOmd.Find("白","49","34"," ").GetBullet().i(VluK_Sx, GetCell('U', 39) );
    m_dOmd.Find("白","49","35"," ").GetBullet().i(VluK_Sx, GetCell('V', 39) );
    m_dOmd.Find("白","49","36"," ").GetBullet().i(VluK_Sx, GetCell('P', 40) );
    m_dOmd.Find("白","49","37"," ").GetBullet().i(VluK_Sx, GetCell('Q', 40) );
    m_dOmd.Find("白","49","38"," ").GetBullet().i(VluK_Sx, GetCell('R', 40) );
    m_dOmd.Find("白","49","39"," ").GetBullet().i(VluK_Sx, GetCell('S', 40) );
    m_dOmd.Find("白","49","40"," ").GetBullet().i(VluK_Sx, GetCell('T', 40) );
    m_dOmd.Find("白","49","41"," ").GetBullet().i(VluK_Sx, GetCell('U', 40) );
    m_dOmd.Find("白","49","42"," ").GetBullet().i(VluK_Sx, GetCell('V', 40) );
    m_dOmd.Find("白","49","43"," ").GetBullet().i(VluK_Sx, GetCell('P', 41) );
    m_dOmd.Find("白","49","44"," ").GetBullet().i(VluK_Sx, GetCell('Q', 41) );
    m_dOmd.Find("白","49","45"," ").GetBullet().i(VluK_Sx, GetCell('R', 41) );
    m_dOmd.Find("白","49","46"," ").GetBullet().i(VluK_Sx, GetCell('S', 41) );
    m_dOmd.Find("白","49","47"," ").GetBullet().i(VluK_Sx, GetCell('T', 41) );
    m_dOmd.Find("白","49","48"," ").GetBullet().i(VluK_Sx, GetCell('U', 41) );
    m_dOmd.Find("白","49","49"," ").GetBullet().i(VluK_Sx, GetCell('V', 41) );

    m_dOmd.Find("白","49","1"," ").GetBullet().i(VluK_Sy, GetCell('X' , 35) );
    m_dOmd.Find("白","49","2"," ").GetBullet().i(VluK_Sy, GetCell('Y' , 35) );
    m_dOmd.Find("白","49","3"," ").GetBullet().i(VluK_Sy, GetCell('Z' , 35) );
    m_dOmd.Find("白","49","4"," ").GetBullet().i(VluK_Sy, GetCell("AA", 35) );
    m_dOmd.Find("白","49","5"," ").GetBullet().i(VluK_Sy, GetCell("AB", 35) );
    m_dOmd.Find("白","49","6"," ").GetBullet().i(VluK_Sy, GetCell("AC", 35) );
    m_dOmd.Find("白","49","7"," ").GetBullet().i(VluK_Sy, GetCell("AD", 35) );
    m_dOmd.Find("白","49","8"," ").GetBullet().i(VluK_Sy, GetCell('X' , 36) );
    m_dOmd.Find("白","49","9"," ").GetBullet().i(VluK_Sy, GetCell('Y' , 36) );
    m_dOmd.Find("白","49","10"," ").GetBullet().i(VluK_Sy, GetCell('Z' , 36) );
    m_dOmd.Find("白","49","11"," ").GetBullet().i(VluK_Sy, GetCell("AA", 36) );
    m_dOmd.Find("白","49","12"," ").GetBullet().i(VluK_Sy, GetCell("AB", 36) );
    m_dOmd.Find("白","49","13"," ").GetBullet().i(VluK_Sy, GetCell("AC", 36) );
    m_dOmd.Find("白","49","14"," ").GetBullet().i(VluK_Sy, GetCell("AD", 36) );
    m_dOmd.Find("白","49","15"," ").GetBullet().i(VluK_Sy, GetCell('X' , 37) );
    m_dOmd.Find("白","49","16"," ").GetBullet().i(VluK_Sy, GetCell('Y' , 37) );
    m_dOmd.Find("白","49","17"," ").GetBullet().i(VluK_Sy, GetCell('Z' , 37) );
    m_dOmd.Find("白","49","18"," ").GetBullet().i(VluK_Sy, GetCell("AA", 37) );
    m_dOmd.Find("白","49","19"," ").GetBullet().i(VluK_Sy, GetCell("AB", 37) );
    m_dOmd.Find("白","49","20"," ").GetBullet().i(VluK_Sy, GetCell("AC", 37) );
    m_dOmd.Find("白","49","21"," ").GetBullet().i(VluK_Sy, GetCell("AD", 37) );
    m_dOmd.Find("白","49","22"," ").GetBullet().i(VluK_Sy, GetCell('X' , 38) );
    m_dOmd.Find("白","49","23"," ").GetBullet().i(VluK_Sy, GetCell('Y' , 38) );
    m_dOmd.Find("白","49","24"," ").GetBullet().i(VluK_Sy, GetCell('Z' , 38) );
    m_dOmd.Find("白","49","25"," ").GetBullet().i(VluK_Sy, GetCell("AA", 38) );
    m_dOmd.Find("白","49","26"," ").GetBullet().i(VluK_Sy, GetCell("AB", 38) );
    m_dOmd.Find("白","49","27"," ").GetBullet().i(VluK_Sy, GetCell("AC", 38) );
    m_dOmd.Find("白","49","28"," ").GetBullet().i(VluK_Sy, GetCell("AD", 38) );
    m_dOmd.Find("白","49","29"," ").GetBullet().i(VluK_Sy, GetCell('X' , 39) );
    m_dOmd.Find("白","49","30"," ").GetBullet().i(VluK_Sy, GetCell('Y' , 39) );
    m_dOmd.Find("白","49","31"," ").GetBullet().i(VluK_Sy, GetCell('Z' , 39) );
    m_dOmd.Find("白","49","32"," ").GetBullet().i(VluK_Sy, GetCell("AA", 39) );
    m_dOmd.Find("白","49","33"," ").GetBullet().i(VluK_Sy, GetCell("AB", 39) );
    m_dOmd.Find("白","49","34"," ").GetBullet().i(VluK_Sy, GetCell("AC", 39) );
    m_dOmd.Find("白","49","35"," ").GetBullet().i(VluK_Sy, GetCell("AD", 39) );
    m_dOmd.Find("白","49","36"," ").GetBullet().i(VluK_Sy, GetCell('X' , 40) );
    m_dOmd.Find("白","49","37"," ").GetBullet().i(VluK_Sy, GetCell('Y' , 40) );
    m_dOmd.Find("白","49","38"," ").GetBullet().i(VluK_Sy, GetCell('Z' , 40) );
    m_dOmd.Find("白","49","39"," ").GetBullet().i(VluK_Sy, GetCell("AA", 40) );
    m_dOmd.Find("白","49","40"," ").GetBullet().i(VluK_Sy, GetCell("AB", 40) );
    m_dOmd.Find("白","49","41"," ").GetBullet().i(VluK_Sy, GetCell("AC", 40) );
    m_dOmd.Find("白","49","42"," ").GetBullet().i(VluK_Sy, GetCell("AD", 40) );
    m_dOmd.Find("白","49","43"," ").GetBullet().i(VluK_Sy, GetCell('X' , 41) );
    m_dOmd.Find("白","49","44"," ").GetBullet().i(VluK_Sy, GetCell('Y' , 41) );
    m_dOmd.Find("白","49","45"," ").GetBullet().i(VluK_Sy, GetCell('Z' , 41) );
    m_dOmd.Find("白","49","46"," ").GetBullet().i(VluK_Sy, GetCell("AA", 41) );
    m_dOmd.Find("白","49","47"," ").GetBullet().i(VluK_Sy, GetCell("AB", 41) );
    m_dOmd.Find("白","49","48"," ").GetBullet().i(VluK_Sy, GetCell("AC", 41) );
    m_dOmd.Find("白","49","49"," ").GetBullet().i(VluK_Sy, GetCell("AD", 41) );

    m_dOmd.Find("白","49","1"," ").GetBullet().i(VluK_T,  GetCell("AF", 35) );
    m_dOmd.Find("白","49","2"," ").GetBullet().i(VluK_T,  GetCell("AG", 35) );
    m_dOmd.Find("白","49","3"," ").GetBullet().i(VluK_T,  GetCell("AH", 35) );
    m_dOmd.Find("白","49","4"," ").GetBullet().i(VluK_T,  GetCell("AI", 35) );
    m_dOmd.Find("白","49","5"," ").GetBullet().i(VluK_T,  GetCell("AJ", 35) );
    m_dOmd.Find("白","49","6"," ").GetBullet().i(VluK_T,  GetCell("AK", 35) );
    m_dOmd.Find("白","49","7"," ").GetBullet().i(VluK_T,  GetCell("AL", 35) );
    m_dOmd.Find("白","49","8"," ").GetBullet().i(VluK_T,  GetCell("AF", 36) );
    m_dOmd.Find("白","49","9"," ").GetBullet().i(VluK_T,  GetCell("AG", 36) );
    m_dOmd.Find("白","49","10"," ").GetBullet().i(VluK_T,  GetCell("AH", 36) );
    m_dOmd.Find("白","49","10"," ").GetBullet().i(VluK_T,  GetCell("AI", 36) );
    m_dOmd.Find("白","49","11"," ").GetBullet().i(VluK_T,  GetCell("AJ", 36) );
    m_dOmd.Find("白","49","12"," ").GetBullet().i(VluK_T,  GetCell("AK", 36) );
    m_dOmd.Find("白","49","13"," ").GetBullet().i(VluK_T,  GetCell("AL", 36) );
    m_dOmd.Find("白","49","14"," ").GetBullet().i(VluK_T,  GetCell("AF", 37) );
    m_dOmd.Find("白","49","15"," ").GetBullet().i(VluK_T,  GetCell("AG", 37) );
    m_dOmd.Find("白","49","16"," ").GetBullet().i(VluK_T,  GetCell("AH", 37) );
    m_dOmd.Find("白","49","17"," ").GetBullet().i(VluK_T,  GetCell("AI", 37) );
    m_dOmd.Find("白","49","18"," ").GetBullet().i(VluK_T,  GetCell("AJ", 37) );
    m_dOmd.Find("白","49","19"," ").GetBullet().i(VluK_T,  GetCell("AK", 37) );
    m_dOmd.Find("白","49","20"," ").GetBullet().i(VluK_T,  GetCell("AL", 37) );
    m_dOmd.Find("白","49","21"," ").GetBullet().i(VluK_T,  GetCell("AF", 38) );
    m_dOmd.Find("白","49","22"," ").GetBullet().i(VluK_T,  GetCell("AG", 38) );
    m_dOmd.Find("白","49","23"," ").GetBullet().i(VluK_T,  GetCell("AH", 38) );
    m_dOmd.Find("白","49","24"," ").GetBullet().i(VluK_T,  GetCell("AI", 38) );
    m_dOmd.Find("白","49","25"," ").GetBullet().i(VluK_T,  GetCell("AJ", 38) );
    m_dOmd.Find("白","49","27"," ").GetBullet().i(VluK_T,  GetCell("AK", 38) );
    m_dOmd.Find("白","49","28"," ").GetBullet().i(VluK_T,  GetCell("AL", 38) );
    m_dOmd.Find("白","49","29"," ").GetBullet().i(VluK_T,  GetCell("AF", 39) );
    m_dOmd.Find("白","49","30"," ").GetBullet().i(VluK_T,  GetCell("AG", 39) );
    m_dOmd.Find("白","49","31"," ").GetBullet().i(VluK_T,  GetCell("AH", 39) );
    m_dOmd.Find("白","49","32"," ").GetBullet().i(VluK_T,  GetCell("AI", 39) );
    m_dOmd.Find("白","49","33"," ").GetBullet().i(VluK_T,  GetCell("AJ", 39) );
    m_dOmd.Find("白","49","34"," ").GetBullet().i(VluK_T,  GetCell("AK", 39) );
    m_dOmd.Find("白","49","35"," ").GetBullet().i(VluK_T,  GetCell("AL", 39) );
    m_dOmd.Find("白","49","36"," ").GetBullet().i(VluK_T,  GetCell("AF", 40) );
    m_dOmd.Find("白","49","37"," ").GetBullet().i(VluK_T,  GetCell("AG", 40) );
    m_dOmd.Find("白","49","38"," ").GetBullet().i(VluK_T,  GetCell("AH", 40) );
    m_dOmd.Find("白","49","39"," ").GetBullet().i(VluK_T,  GetCell("AI", 40) );
    m_dOmd.Find("白","49","40"," ").GetBullet().i(VluK_T,  GetCell("AJ", 40) );
    m_dOmd.Find("白","49","41"," ").GetBullet().i(VluK_T,  GetCell("AK", 40) );
    m_dOmd.Find("白","49","42"," ").GetBullet().i(VluK_T,  GetCell("AL", 40) );
    m_dOmd.Find("白","49","43"," ").GetBullet().i(VluK_T,  GetCell("AF", 41) );
    m_dOmd.Find("白","49","44"," ").GetBullet().i(VluK_T,  GetCell("AG", 41) );
    m_dOmd.Find("白","49","45"," ").GetBullet().i(VluK_T,  GetCell("AH", 41) );
    m_dOmd.Find("白","49","46"," ").GetBullet().i(VluK_T,  GetCell("AI", 41) );
    m_dOmd.Find("白","49","47"," ").GetBullet().i(VluK_T,  GetCell("AJ", 41) );
    m_dOmd.Find("白","49","48"," ").GetBullet().i(VluK_T,  GetCell("AK", 41) );
    m_dOmd.Find("白","49","49"," ").GetBullet().i(VluK_T,  GetCell("AL", 41) );
	
    m_dOmd.Find("白","49","1"," ").GetBullet().i(VluK_Duv,  GetCell("AN", 35) );
    m_dOmd.Find("白","49","2"," ").GetBullet().i(VluK_Duv,  GetCell("AO", 35) );
    m_dOmd.Find("白","49","3"," ").GetBullet().i(VluK_Duv,  GetCell("AP", 35) );
    m_dOmd.Find("白","49","4"," ").GetBullet().i(VluK_Duv,  GetCell("AQ", 35) );
    m_dOmd.Find("白","49","5"," ").GetBullet().i(VluK_Duv,  GetCell("AR", 35) );
    m_dOmd.Find("白","49","6"," ").GetBullet().i(VluK_Duv,  GetCell("AS", 35) );
    m_dOmd.Find("白","49","7"," ").GetBullet().i(VluK_Duv,  GetCell("AT", 35) );
    m_dOmd.Find("白","49","8"," ").GetBullet().i(VluK_Duv,  GetCell("AN", 36) );
    m_dOmd.Find("白","49","9"," ").GetBullet().i(VluK_Duv,  GetCell("AO", 36) );
    m_dOmd.Find("白","49","10"," ").GetBullet().i(VluK_Duv,  GetCell("AP", 36) );
    m_dOmd.Find("白","49","10"," ").GetBullet().i(VluK_Duv,  GetCell("AQ", 36) );
    m_dOmd.Find("白","49","11"," ").GetBullet().i(VluK_Duv,  GetCell("AR", 36) );
    m_dOmd.Find("白","49","12"," ").GetBullet().i(VluK_Duv,  GetCell("AS", 36) );
    m_dOmd.Find("白","49","13"," ").GetBullet().i(VluK_Duv,  GetCell("AT", 36) );
    m_dOmd.Find("白","49","14"," ").GetBullet().i(VluK_Duv,  GetCell("AN", 37) );
    m_dOmd.Find("白","49","15"," ").GetBullet().i(VluK_Duv,  GetCell("AO", 37) );
    m_dOmd.Find("白","49","16"," ").GetBullet().i(VluK_Duv,  GetCell("AP", 37) );
    m_dOmd.Find("白","49","17"," ").GetBullet().i(VluK_Duv,  GetCell("AQ", 37) );
    m_dOmd.Find("白","49","18"," ").GetBullet().i(VluK_Duv,  GetCell("AR", 37) );
    m_dOmd.Find("白","49","19"," ").GetBullet().i(VluK_Duv,  GetCell("AS", 37) );
    m_dOmd.Find("白","49","20"," ").GetBullet().i(VluK_Duv,  GetCell("AT", 37) );
    m_dOmd.Find("白","49","21"," ").GetBullet().i(VluK_Duv,  GetCell("AN", 38) );
    m_dOmd.Find("白","49","22"," ").GetBullet().i(VluK_Duv,  GetCell("AO", 38) );
    m_dOmd.Find("白","49","23"," ").GetBullet().i(VluK_Duv,  GetCell("AP", 38) );
    m_dOmd.Find("白","49","24"," ").GetBullet().i(VluK_Duv,  GetCell("AQ", 38) );
    m_dOmd.Find("白","49","25"," ").GetBullet().i(VluK_Duv,  GetCell("AR", 38) );
    m_dOmd.Find("白","49","27"," ").GetBullet().i(VluK_Duv,  GetCell("AS", 38) );
    m_dOmd.Find("白","49","28"," ").GetBullet().i(VluK_Duv,  GetCell("AT", 38) );
    m_dOmd.Find("白","49","29"," ").GetBullet().i(VluK_Duv,  GetCell("AN", 39) );
    m_dOmd.Find("白","49","30"," ").GetBullet().i(VluK_Duv,  GetCell("AO", 39) );
    m_dOmd.Find("白","49","31"," ").GetBullet().i(VluK_Duv,  GetCell("AP", 39) );
    m_dOmd.Find("白","49","32"," ").GetBullet().i(VluK_Duv,  GetCell("AQ", 39) );
    m_dOmd.Find("白","49","33"," ").GetBullet().i(VluK_Duv,  GetCell("AR", 39) );
    m_dOmd.Find("白","49","34"," ").GetBullet().i(VluK_Duv,  GetCell("AS", 39) );
    m_dOmd.Find("白","49","35"," ").GetBullet().i(VluK_Duv,  GetCell("AT", 39) );
    m_dOmd.Find("白","49","36"," ").GetBullet().i(VluK_Duv,  GetCell("AN", 40) );
    m_dOmd.Find("白","49","37"," ").GetBullet().i(VluK_Duv,  GetCell("AO", 40) );
    m_dOmd.Find("白","49","38"," ").GetBullet().i(VluK_Duv,  GetCell("AP", 40) );
    m_dOmd.Find("白","49","39"," ").GetBullet().i(VluK_Duv,  GetCell("AQ", 40) );
    m_dOmd.Find("白","49","40"," ").GetBullet().i(VluK_Duv,  GetCell("AR", 40) );
    m_dOmd.Find("白","49","41"," ").GetBullet().i(VluK_Duv,  GetCell("AS", 40) );
    m_dOmd.Find("白","49","42"," ").GetBullet().i(VluK_Duv,  GetCell("AT", 40) );
    m_dOmd.Find("白","49","43"," ").GetBullet().i(VluK_Duv,  GetCell("AN", 41) );
    m_dOmd.Find("白","49","44"," ").GetBullet().i(VluK_Duv,  GetCell("AO", 41) );
    m_dOmd.Find("白","49","45"," ").GetBullet().i(VluK_Duv,  GetCell("AP", 41) );
    m_dOmd.Find("白","49","46"," ").GetBullet().i(VluK_Duv,  GetCell("AQ", 41) );
    m_dOmd.Find("白","49","47"," ").GetBullet().i(VluK_Duv,  GetCell("AR", 41) );
    m_dOmd.Find("白","49","48"," ").GetBullet().i(VluK_Duv,  GetCell("AS", 41) );
    m_dOmd.Find("白","49","49"," ").GetBullet().i(VluK_Duv,  GetCell("AT", 41) );
}

void COmdFile1::t2oD21()
{
	m_dOmd.Find("黑","21","1","0").GetBullet().i(VluK_Lv, GetCell('H', 48) );
	m_dOmd.Find("黑","21","2","0").GetBullet().i(VluK_Lv, GetCell('H', 47) );
	m_dOmd.Find("黑","21","3","0").GetBullet().i(VluK_Lv, GetCell('H', 46) );
	m_dOmd.Find("黑","21","4","0").GetBullet().i(VluK_Lv, GetCell('H', 45) );
	m_dOmd.Find("黑","21","5","0").GetBullet().i(VluK_Lv, GetCell('H', 44) );
	m_dOmd.Find("黑","21","6","0").GetBullet().i(VluK_Lv, GetCell('I', 44) );
	m_dOmd.Find("黑","21","7","0").GetBullet().i(VluK_Lv, GetCell('J', 44) );
	m_dOmd.Find("黑","21","8","0").GetBullet().i(VluK_Lv, GetCell('K', 44) );
	m_dOmd.Find("黑","21","9","0").GetBullet().i(VluK_Lv, GetCell('L', 44) );
	m_dOmd.Find("黑","21","10","0").GetBullet().i(VluK_Lv, GetCell('M', 44) );
	m_dOmd.Find("黑","21","11","0").GetBullet().i(VluK_Lv, GetCell('N', 44) );
	m_dOmd.Find("黑","21","12","0").GetBullet().i(VluK_Lv, GetCell('N', 45) );
	m_dOmd.Find("黑","21","13","0").GetBullet().i(VluK_Lv, GetCell('N', 46) );
	m_dOmd.Find("黑","21","14","0").GetBullet().i(VluK_Lv, GetCell('N', 47) );
	m_dOmd.Find("黑","21","15","0").GetBullet().i(VluK_Lv, GetCell('N', 48) );
	m_dOmd.Find("黑","21","16","0").GetBullet().i(VluK_Lv, GetCell('M', 48) );
	m_dOmd.Find("黑","21","17","0").GetBullet().i(VluK_Lv, GetCell('L', 48) );
	m_dOmd.Find("黑","21","18","0").GetBullet().i(VluK_Lv, GetCell('K', 48) );
	m_dOmd.Find("黑","21","19","0").GetBullet().i(VluK_Lv, GetCell('J', 48) );
	m_dOmd.Find("黑","21","20","0").GetBullet().i(VluK_Lv, GetCell('I', 48) );
	m_dOmd.Find("黑","21","21","0").GetBullet().i(VluK_Lv, GetCell('K', 46) );
	
	m_dOmd.Find("黑","21","1","0").GetBullet().i(VluK_Sx, GetCell('P', 48) );
	m_dOmd.Find("黑","21","2","0").GetBullet().i(VluK_Sx, GetCell('P', 47) );
	m_dOmd.Find("黑","21","3","0").GetBullet().i(VluK_Sx, GetCell('P', 46) );
	m_dOmd.Find("黑","21","4","0").GetBullet().i(VluK_Sx, GetCell('P', 45) );
	m_dOmd.Find("黑","21","5","0").GetBullet().i(VluK_Sx, GetCell('P', 44) );
	m_dOmd.Find("黑","21","6","0").GetBullet().i(VluK_Sx, GetCell('Q', 44) );
	m_dOmd.Find("黑","21","7","0").GetBullet().i(VluK_Sx, GetCell('R', 44) );
	m_dOmd.Find("黑","21","8","0").GetBullet().i(VluK_Sx, GetCell('S', 44) );
	m_dOmd.Find("黑","21","9","0").GetBullet().i(VluK_Sx, GetCell('T', 44) );
	m_dOmd.Find("黑","21","10","0").GetBullet().i(VluK_Sx, GetCell('U', 44) );
	m_dOmd.Find("黑","21","11","0").GetBullet().i(VluK_Sx, GetCell('V', 44) );
	m_dOmd.Find("黑","21","12","0").GetBullet().i(VluK_Sx, GetCell('V', 45) );
	m_dOmd.Find("黑","21","13","0").GetBullet().i(VluK_Sx, GetCell('V', 46) );
	m_dOmd.Find("黑","21","14","0").GetBullet().i(VluK_Sx, GetCell('V', 47) );
	m_dOmd.Find("黑","21","15","0").GetBullet().i(VluK_Sx, GetCell('V', 48) );
	m_dOmd.Find("黑","21","16","0").GetBullet().i(VluK_Sx, GetCell('U', 48) );
	m_dOmd.Find("黑","21","17","0").GetBullet().i(VluK_Sx, GetCell('T', 48) );
	m_dOmd.Find("黑","21","18","0").GetBullet().i(VluK_Sx, GetCell('S', 48) );
	m_dOmd.Find("黑","21","19","0").GetBullet().i(VluK_Sx, GetCell('R', 48) );
	m_dOmd.Find("黑","21","20","0").GetBullet().i(VluK_Sx, GetCell('Q', 48) );
	m_dOmd.Find("黑","21","21","0").GetBullet().i(VluK_Sx, GetCell('S', 46) );
	
	m_dOmd.Find("黑","21","1","0").GetBullet().i(VluK_Sy, GetCell('X' , 48) );
	m_dOmd.Find("黑","21","2","0").GetBullet().i(VluK_Sy, GetCell('X' , 47) );
	m_dOmd.Find("黑","21","3","0").GetBullet().i(VluK_Sy, GetCell('X' , 46) );
	m_dOmd.Find("黑","21","4","0").GetBullet().i(VluK_Sy, GetCell('X' , 45) );
	m_dOmd.Find("黑","21","5","0").GetBullet().i(VluK_Sy, GetCell('X' , 44) );
	m_dOmd.Find("黑","21","6","0").GetBullet().i(VluK_Sy, GetCell('Y' , 44) );
	m_dOmd.Find("黑","21","7","0").GetBullet().i(VluK_Sy, GetCell('Z' , 44) );
	m_dOmd.Find("黑","21","8","0").GetBullet().i(VluK_Sy, GetCell("AA", 44) );
	m_dOmd.Find("黑","21","9","0").GetBullet().i(VluK_Sy, GetCell("AB", 44) );
	m_dOmd.Find("黑","21","10","0").GetBullet().i(VluK_Sy, GetCell("AC", 44) );
	m_dOmd.Find("黑","21","11","0").GetBullet().i(VluK_Sy, GetCell("AD", 44) );
	m_dOmd.Find("黑","21","12","0").GetBullet().i(VluK_Sy, GetCell("AD", 45) );
	m_dOmd.Find("黑","21","13","0").GetBullet().i(VluK_Sy, GetCell("AD", 46) );
	m_dOmd.Find("黑","21","14","0").GetBullet().i(VluK_Sy, GetCell("AD", 47) );
	m_dOmd.Find("黑","21","15","0").GetBullet().i(VluK_Sy, GetCell("AD", 48) );
	m_dOmd.Find("黑","21","16","0").GetBullet().i(VluK_Sy, GetCell("AC", 48) );
	m_dOmd.Find("黑","21","17","0").GetBullet().i(VluK_Sy, GetCell("AB", 48) );
	m_dOmd.Find("黑","21","18","0").GetBullet().i(VluK_Sy, GetCell("AA", 48) );
	m_dOmd.Find("黑","21","19","0").GetBullet().i(VluK_Sy, GetCell('Z' , 48) );
	m_dOmd.Find("黑","21","20","0").GetBullet().i(VluK_Sy, GetCell('Y' , 48) );
	m_dOmd.Find("黑","21","21","0").GetBullet().i(VluK_Sy, GetCell("AA", 46) );
}

void COmdFile1::t2oD13()
{
	m_dOmd.Find("黑","13","1","0").GetBullet().i(VluK_Lv, GetCell('H', 51) );
	m_dOmd.Find("黑","13","2","0").GetBullet().i(VluK_Lv, GetCell('J', 51) );
	m_dOmd.Find("黑","13","3","0").GetBullet().i(VluK_Lv, GetCell('L', 51) );
	m_dOmd.Find("黑","13","4","0").GetBullet().i(VluK_Lv, GetCell('H', 53) );
	m_dOmd.Find("黑","13","5","0").GetBullet().i(VluK_Lv, GetCell('J', 53) );
	m_dOmd.Find("黑","13","6","0").GetBullet().i(VluK_Lv, GetCell('L', 53) );
	m_dOmd.Find("黑","13","7","0").GetBullet().i(VluK_Lv, GetCell('H', 55) );
	m_dOmd.Find("黑","13","8","0").GetBullet().i(VluK_Lv, GetCell('J', 55) );
	m_dOmd.Find("黑","13","9","0").GetBullet().i(VluK_Lv, GetCell('L', 55) );
	m_dOmd.Find("黑","13","10","0").GetBullet().i(VluK_Lv, GetCell('I', 52) );
	m_dOmd.Find("黑","13","11","0").GetBullet().i(VluK_Lv, GetCell('K', 52) );
	m_dOmd.Find("黑","13","12","0").GetBullet().i(VluK_Lv, GetCell('I', 54) );
	m_dOmd.Find("黑","13","13","0").GetBullet().i(VluK_Lv, GetCell('K', 54) );
	
	m_dOmd.Find("黑","13","1","0").GetBullet().i(VluK_Sx, GetCell('N', 51) );
	m_dOmd.Find("黑","13","2","0").GetBullet().i(VluK_Sx, GetCell('P', 51) );
	m_dOmd.Find("黑","13","3","0").GetBullet().i(VluK_Sx, GetCell('R', 51) );
	m_dOmd.Find("黑","13","4","0").GetBullet().i(VluK_Sx, GetCell('N', 53) );
	m_dOmd.Find("黑","13","5","0").GetBullet().i(VluK_Sx, GetCell('P', 53) );
	m_dOmd.Find("黑","13","6","0").GetBullet().i(VluK_Sx, GetCell('R', 53) );
	m_dOmd.Find("黑","13","7","0").GetBullet().i(VluK_Sx, GetCell('N', 55) );
	m_dOmd.Find("黑","13","8","0").GetBullet().i(VluK_Sx, GetCell('P', 55) );
	m_dOmd.Find("黑","13","9","0").GetBullet().i(VluK_Sx, GetCell('R', 55) );
	m_dOmd.Find("黑","13","10","0").GetBullet().i(VluK_Sx, GetCell('O', 52) );
	m_dOmd.Find("黑","13","11","0").GetBullet().i(VluK_Sx, GetCell('Q', 52) );
	m_dOmd.Find("黑","13","12","0").GetBullet().i(VluK_Sx, GetCell('O', 54) );
	m_dOmd.Find("黑","13","13","0").GetBullet().i(VluK_Sx, GetCell('Q', 54) );
	
	m_dOmd.Find("黑","13","1","0").GetBullet().i(VluK_Sy, GetCell('T', 51) );
	m_dOmd.Find("黑","13","2","0").GetBullet().i(VluK_Sy, GetCell('V', 51) );
	m_dOmd.Find("黑","13","3","0").GetBullet().i(VluK_Sy, GetCell('X', 51) );
	m_dOmd.Find("黑","13","4","0").GetBullet().i(VluK_Sy, GetCell('T', 53) );
	m_dOmd.Find("黑","13","5","0").GetBullet().i(VluK_Sy, GetCell('V', 53) );
	m_dOmd.Find("黑","13","6","0").GetBullet().i(VluK_Sy, GetCell('X', 53) );
	m_dOmd.Find("黑","13","7","0").GetBullet().i(VluK_Sy, GetCell('T', 55) );
	m_dOmd.Find("黑","13","8","0").GetBullet().i(VluK_Sy, GetCell('V', 55) );
	m_dOmd.Find("黑","13","9","0").GetBullet().i(VluK_Sy, GetCell('X', 55) );
	m_dOmd.Find("黑","13","10","0").GetBullet().i(VluK_Sy, GetCell('U', 52) );
	m_dOmd.Find("黑","13","11","0").GetBullet().i(VluK_Sy, GetCell('W', 52) );
	m_dOmd.Find("黑","13","12","0").GetBullet().i(VluK_Sy, GetCell('U', 54) );
	m_dOmd.Find("黑","13","13","0").GetBullet().i(VluK_Sy, GetCell('W', 54) );
}

void COmdFile1::t2oW5()
{
	m_dOmd.Find("白","5","1","0").GetBullet().i(VluK_Lv, GetCell('H', 58) );
	m_dOmd.Find("白","5","2","0").GetBullet().i(VluK_Lv, GetCell('J', 58) );
	m_dOmd.Find("白","5","3","0").GetBullet().i(VluK_Lv, GetCell('I', 59) );
	m_dOmd.Find("白","5","4","0").GetBullet().i(VluK_Lv, GetCell('H', 60) );
	m_dOmd.Find("白","5","5","0").GetBullet().i(VluK_Lv, GetCell('J', 60) );
	
	m_dOmd.Find("白","5","1","0").GetBullet().i(VluK_Sx, GetCell('N', 58) );
	m_dOmd.Find("白","5","2","0").GetBullet().i(VluK_Sx, GetCell('P', 58) );
	m_dOmd.Find("白","5","3","0").GetBullet().i(VluK_Sx, GetCell('O', 59) );
	m_dOmd.Find("白","5","4","0").GetBullet().i(VluK_Sx, GetCell('N', 60) );
	m_dOmd.Find("白","5","5","0").GetBullet().i(VluK_Sx, GetCell('P', 60) );
	
	m_dOmd.Find("白","5","1","0").GetBullet().i(VluK_Sy, GetCell('T', 58) );
	m_dOmd.Find("白","5","2","0").GetBullet().i(VluK_Sy, GetCell('V', 58) );
	m_dOmd.Find("白","5","3","0").GetBullet().i(VluK_Sy, GetCell('U', 59) );
	m_dOmd.Find("白","5","4","0").GetBullet().i(VluK_Sy, GetCell('T', 60) );
	m_dOmd.Find("白","5","5","0").GetBullet().i(VluK_Sy, GetCell('V', 60) );
	
	m_dOmd.Find("白","5","1","0").GetBullet().i(VluK_T,  GetCell('Z' , 58) );
	m_dOmd.Find("白","5","2","0").GetBullet().i(VluK_T,  GetCell("AB", 58) );
	m_dOmd.Find("白","5","3","0").GetBullet().i(VluK_T,  GetCell("AA", 59) );
	m_dOmd.Find("白","5","4","0").GetBullet().i(VluK_T,  GetCell('Z' , 60) );
	m_dOmd.Find("白","5","5","0").GetBullet().i(VluK_T,  GetCell("AB", 60) );
	
	m_dOmd.Find("白","5","1","0").GetBullet().i(VluK_Duv,  GetCell("AF", 58) );
	m_dOmd.Find("白","5","2","0").GetBullet().i(VluK_Duv,  GetCell("AH", 58) );
	m_dOmd.Find("白","5","3","0").GetBullet().i(VluK_Duv,  GetCell("AG", 59) );
	m_dOmd.Find("白","5","4","0").GetBullet().i(VluK_Duv,  GetCell("AF", 60) );
	m_dOmd.Find("白","5","5","0").GetBullet().i(VluK_Duv,  GetCell("AH", 60) );
}

void COmdFile1::DNA_sortable(DNA& sortableDNA)
{
    //準備DNA
    //填入參數
    //JND
//     sortableDNA.AddCell(JNDX , Pn1, m_JndGray);
//     sortableDNA.AddCell(JND , Pn1, m_JndGray);
    
    //中心點
    sortableDNA.AddCell(White, Pn1);
    sortableDNA.AddCell(Red  , Pn1);
    sortableDNA.AddCell(Green, Pn1);
    sortableDNA.AddCell(Blue , Pn1);
    sortableDNA.AddCell(Dark , Pn1);
    
    //Nits
    sortableDNA.AddCell(Nits, Pn9, 5, 1);
    
    //5點
    sortableDNA.AddCell(White, Pn5, 0);
//     sortableDNA.AddCell(Red  , Pn5, 0);
//     sortableDNA.AddCell(Green, Pn5, 0);
//     sortableDNA.AddCell(Blue , Pn5, 0);
//     sortableDNA.AddCell(Dark , Pn5, 0);
    
    //9點
    sortableDNA.AddCell(White, Pn9, 6);
//     sortableDNA.AddCell(Red  , Pn9, 6);
//     sortableDNA.AddCell(Green, Pn9, 6);
//     sortableDNA.AddCell(Blue , Pn9, 6);
    sortableDNA.AddCell(Dark , Pn9, 6);
    
    //21點
//     sortableDNA.AddCell(White, Pn21, 0);
//     sortableDNA.AddCell(Red  , Pn21, 0);
//     sortableDNA.AddCell(Green, Pn21, 0);
//     sortableDNA.AddCell(Blue , Pn21, 0);
    sortableDNA.AddCell(Dark , Pn21, 0);
    
    //13點
//    sortableDNA.AddCell(White, Pn13, 0);
//     sortableDNA.AddCell(Red  , Pn13, 0);
//     sortableDNA.AddCell(Green, Pn13, 0);
//     sortableDNA.AddCell(Blue , Pn13, 0);
    sortableDNA.AddCell(Dark , Pn13, 0);
    
    //25點
//     sortableDNA.AddCell(White, Pn25, 0, 10);
//     sortableDNA.AddCell(Red  , Pn25, 0, 10);
//     sortableDNA.AddCell(Green, Pn25, 0, 10);
//     sortableDNA.AddCell(Blue , Pn25, 0, 10);
    sortableDNA.AddCell(Dark , Pn25, 0, 10);
    
    //49點
    sortableDNA.AddCell(White, Pn49);
//     sortableDNA.AddCell(Red  , Pn49);
//     sortableDNA.AddCell(Green, Pn49);
//     sortableDNA.AddCell(Blue , Pn49);
//     sortableDNA.AddCell(Dark , Pn49);
}

void COmdFile1::DNA_Unsortable(DNA& unsortableDNA)
{
    //Cross Talk srot by AreaCode
    unsortableDNA.AddCell(CrsTlk , Pn4, 4);  
    unsortableDNA.AddCell(CrsTlkD, Pn4, 4);  
    unsortableDNA.AddCell(CrsTlkW, Pn4, 4);  
    
	//Gamma
//     unsortableDNA.AddCell(White, PnGamma, 0, 255, 255);  
//     unsortableDNA.AddCell(Red  , PnGamma, 0, 255, 255);
//     unsortableDNA.AddCell(Green, PnGamma, 0, 255, 255);
//     unsortableDNA.AddCell(Blue , PnGamma, 0, 255, 255);
}
