// OmdFile1.cpp: implementation of the COmdFile1 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "OmdFile1.h"

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
	int n(0);

    D_Txt.push_back("Panel ID\t" + m_PnlID + "\tMeasurement device\t" + m_MsrDvc + "\tProbe\t" + m_Prb + "\tCH\t" + m_CHID + "\n");

    D_Txt.push_back("中心點\tL\tx\ty\tu'\tv'\t5nits 9點均齊度\tL\t\t\t\t\t5nits 9點均齊度\tx\t\t\t\t\t5nits 9點均齊度\ty\t\t\t\t\t5nits 9點均齊度\tT\t\t\t\t\t5nits 9點均齊度\tduv\n");
    D_Txt.push_back("White\t" + D_Omd.At(White, Pn1, 0).GetStrLv() + "\t" + D_Omd.At(White, Pn1, 0).GetStrSx() + "\t" + D_Omd.At(White, Pn1, 0).GetStrSy() + "\t" + D_Omd.At(White, Pn1, 0).GetStrDu() + "\t" + D_Omd.At(White, Pn1, 0).GetStrDv() + "\t灰階:XX\t" + D_Omd.At(Nits, Pn9, 0).GetStrLv() + "\t" + D_Omd.At(Nits, Pn9, 1).GetStrLv() + "\t" + D_Omd.At(Nits, Pn9, 2).GetStrLv() + "\t\t\t\t" + D_Omd.At(Nits, Pn9, 0).GetStrSx() + "\t" + D_Omd.At(Nits, Pn9, 1).GetStrSx() + "\t" + D_Omd.At(Nits, Pn9, 2).GetStrSx() + "\t\t\t\t" + D_Omd.At(Nits, Pn9, 0).GetStrSy() + "\t" + D_Omd.At(Nits, Pn9, 1).GetStrSy() + "\t" + D_Omd.At(Nits, Pn9, 2).GetStrSy() + "\t\t\t\t" + D_Omd.At(Nits, Pn9, 0).GetStrT() + "\t" + D_Omd.At(Nits, Pn9, 1).GetStrT() + "\t" + D_Omd.At(Nits, Pn9, 2).GetStrT() + "\t\t\t\t" + D_Omd.At(Nits, Pn9, 0).GetStrDuv() + "\t" + D_Omd.At(Nits, Pn9, 1).GetStrDuv() + "\t" + D_Omd.At(Nits, Pn9, 2).GetStrDuv() + "\n");
    D_Txt.push_back("Red  \t" + D_Omd.At(Red  , Pn1, 0).GetStrLv() + "\t" + D_Omd.At(Red  , Pn1, 0).GetStrSx() + "\t" + D_Omd.At(Red  , Pn1, 0).GetStrSy() + "\t" + D_Omd.At(Red  , Pn1, 0).GetStrDu() + "\t" + D_Omd.At(Red  , Pn1, 0).GetStrDv() + "\t\t"        + D_Omd.At(Nits, Pn9, 3).GetStrLv() + "\t" + D_Omd.At(Nits, Pn9, 4).GetStrLv() + "\t" + D_Omd.At(Nits, Pn9, 5).GetStrLv() + "\t\t\t\t" + D_Omd.At(Nits, Pn9, 3).GetStrSx() + "\t" + D_Omd.At(Nits, Pn9, 4).GetStrSx() + "\t" + D_Omd.At(Nits, Pn9, 5).GetStrSx() + "\t\t\t\t" + D_Omd.At(Nits, Pn9, 3).GetStrSy() + "\t" + D_Omd.At(Nits, Pn9, 4).GetStrSy() + "\t" + D_Omd.At(Nits, Pn9, 5).GetStrSy() + "\t\t\t\t" + D_Omd.At(Nits, Pn9, 3).GetStrT() + "\t" + D_Omd.At(Nits, Pn9, 4).GetStrT() + "\t" + D_Omd.At(Nits, Pn9, 5).GetStrT() + "\t\t\t\t" + D_Omd.At(Nits, Pn9, 3).GetStrDuv() + "\t" + D_Omd.At(Nits, Pn9, 4).GetStrDuv() + "\t" + D_Omd.At(Nits, Pn9, 5).GetStrDuv() + "\n");
    D_Txt.push_back("Green\t" + D_Omd.At(Green, Pn1, 0).GetStrLv() + "\t" + D_Omd.At(Green, Pn1, 0).GetStrSx() + "\t" + D_Omd.At(Green, Pn1, 0).GetStrSy() + "\t" + D_Omd.At(Green, Pn1, 0).GetStrDu() + "\t" + D_Omd.At(Green, Pn1, 0).GetStrDv() + "\t\t"        + D_Omd.At(Nits, Pn9, 6).GetStrLv() + "\t" + D_Omd.At(Nits, Pn9, 7).GetStrLv() + "\t" + D_Omd.At(Nits, Pn9, 8).GetStrLv() + "\t\t\t\t" + D_Omd.At(Nits, Pn9, 6).GetStrSx() + "\t" + D_Omd.At(Nits, Pn9, 7).GetStrSx() + "\t" + D_Omd.At(Nits, Pn9, 8).GetStrSx() + "\t\t\t\t" + D_Omd.At(Nits, Pn9, 6).GetStrSy() + "\t" + D_Omd.At(Nits, Pn9, 7).GetStrSy() + "\t" + D_Omd.At(Nits, Pn9, 8).GetStrSy() + "\t\t\t\t" + D_Omd.At(Nits, Pn9, 6).GetStrT() + "\t" + D_Omd.At(Nits, Pn9, 7).GetStrT() + "\t" + D_Omd.At(Nits, Pn9, 8).GetStrT() + "\t\t\t\t" + D_Omd.At(Nits, Pn9, 6).GetStrDuv() + "\t" + D_Omd.At(Nits, Pn9, 7).GetStrDuv() + "\t" + D_Omd.At(Nits, Pn9, 8).GetStrDuv() + "\n");
    D_Txt.push_back("Blue \t" + D_Omd.At(Blue , Pn1, 0).GetStrLv() + "\t" + D_Omd.At(Blue , Pn1, 0).GetStrSx() + "\t" + D_Omd.At(Blue , Pn1, 0).GetStrSy() + "\t" + D_Omd.At(Blue , Pn1, 0).GetStrDu() + "\t" + D_Omd.At(Blue , Pn1, 0).GetStrDv() + "\n");

    D_Txt.push_back("\t\t\t\t\t\t9點均齊度\tL\t\t\t\t\t9點均齊度\tx\t\t\t\t\t9點均齊度\ty\t\t\t\t\t9點均齊度\tT\t\t\t\t\t9點均齊度\tduv\n");
    D_Txt.push_back("\t\t\t\t\t\t離邊6分之1\t" + D_Omd.At(White, Pn9, 0).GetStrLv() + "\t" + D_Omd.At(White, Pn9, 1).GetStrLv() + "\t" + D_Omd.At(White, Pn9, 2).GetStrLv() + "\t\t\t\t" + D_Omd.At(White, Pn9, 0).GetStrSx() + "\t" + D_Omd.At(White, Pn9, 1).GetStrSx() + "\t" + D_Omd.At(White, Pn9, 2).GetStrSx() + "\t\t\t\t" + D_Omd.At(White, Pn9, 0).GetStrSy() + "\t" + D_Omd.At(White, Pn9, 1).GetStrSy() + "\t" + D_Omd.At(White, Pn9, 2).GetStrSy() + "\t\t\t\t" + D_Omd.At(White, Pn9, 0).GetStrT() + "\t" + D_Omd.At(White, Pn9, 1).GetStrT() + "\t" + D_Omd.At(White, Pn9, 2).GetStrT() + "\t\t\t\t" + D_Omd.At(White, Pn9, 0).GetStrDuv() + "\t" + D_Omd.At(White, Pn9, 1).GetStrDuv() + "\t" + D_Omd.At(White, Pn9, 2).GetStrDuv() + "\n");
    D_Txt.push_back("\t\t\t\t\t\t\t"           + D_Omd.At(White, Pn9, 3).GetStrLv() + "\t" + D_Omd.At(White, Pn9, 4).GetStrLv() + "\t" + D_Omd.At(White, Pn9, 5).GetStrLv() + "\t\t\t\t" + D_Omd.At(White, Pn9, 3).GetStrSx() + "\t" + D_Omd.At(White, Pn9, 4).GetStrSx() + "\t" + D_Omd.At(White, Pn9, 5).GetStrSx() + "\t\t\t\t" + D_Omd.At(White, Pn9, 3).GetStrSy() + "\t" + D_Omd.At(White, Pn9, 4).GetStrSy() + "\t" + D_Omd.At(White, Pn9, 5).GetStrSy() + "\t\t\t\t" + D_Omd.At(White, Pn9, 3).GetStrT() + "\t" + D_Omd.At(White, Pn9, 4).GetStrT() + "\t" + D_Omd.At(White, Pn9, 5).GetStrT() + "\t\t\t\t" + D_Omd.At(White, Pn9, 3).GetStrDuv() + "\t" + D_Omd.At(White, Pn9, 4).GetStrDuv() + "\t" + D_Omd.At(White, Pn9, 5).GetStrDuv() + "\n");
    D_Txt.push_back("\t\t\t\t\t\t\t"           + D_Omd.At(White, Pn9, 6).GetStrLv() + "\t" + D_Omd.At(White, Pn9, 7).GetStrLv() + "\t" + D_Omd.At(White, Pn9, 8).GetStrLv() + "\t\t\t\t" + D_Omd.At(White, Pn9, 6).GetStrSx() + "\t" + D_Omd.At(White, Pn9, 7).GetStrSx() + "\t" + D_Omd.At(White, Pn9, 8).GetStrSx() + "\t\t\t\t" + D_Omd.At(White, Pn9, 6).GetStrSy() + "\t" + D_Omd.At(White, Pn9, 7).GetStrSy() + "\t" + D_Omd.At(White, Pn9, 8).GetStrSy() + "\t\t\t\t" + D_Omd.At(White, Pn9, 6).GetStrT() + "\t" + D_Omd.At(White, Pn9, 7).GetStrT() + "\t" + D_Omd.At(White, Pn9, 8).GetStrT() + "\t\t\t\t" + D_Omd.At(White, Pn9, 6).GetStrDuv() + "\t" + D_Omd.At(White, Pn9, 7).GetStrDuv() + "\t" + D_Omd.At(White, Pn9, 8).GetStrDuv() + "\n");
    D_Txt.push_back("\n");
    

    D_Txt.push_back("\t\t\t\t\t\t黑色9點均齊度\tL\t\t\t\t\t黑色9點均齊度\tx\t\t\t\t\t黑色9點均齊度\ty\t\t\t\t\t黑色9點均齊度\tT\t\t\t\t\t黑色9點均齊度\tduv\n");
    D_Txt.push_back("\t\t\t\t\t\t\t" + D_Omd.At(Dark , Pn9, 0).GetStrLv() + "\t" + D_Omd.At(Dark , Pn9, 1).GetStrLv() + "\t" + D_Omd.At(Dark , Pn9, 2).GetStrLv() + "\t\t\t\t" + D_Omd.At(Dark , Pn9, 0).GetStrSx() + "\t" + D_Omd.At(Dark , Pn9, 1).GetStrSx() + "\t" + D_Omd.At(Dark , Pn9, 2).GetStrSx() + "\t\t\t\t" + D_Omd.At(Dark , Pn9, 0).GetStrSy() + "\t" + D_Omd.At(Dark , Pn9, 1).GetStrSy() + "\t" + D_Omd.At(Dark , Pn9, 2).GetStrSy() + "\t\t\t\t" + D_Omd.At(Dark , Pn9, 0).GetStrT() + "\t" + D_Omd.At(Dark , Pn9, 1).GetStrT() + "\t" + D_Omd.At(Dark , Pn9, 2).GetStrT() + "\t\t\t\t" + D_Omd.At(Dark , Pn9, 0).GetStrDuv() + "\t" + D_Omd.At(Dark , Pn9, 1).GetStrDuv() + "\t" + D_Omd.At(Dark , Pn9, 2).GetStrDuv() + "\n");
    D_Txt.push_back("\t\t\t\t\t\t\t" + D_Omd.At(Dark , Pn9, 3).GetStrLv() + "\t" + D_Omd.At(Dark , Pn9, 4).GetStrLv() + "\t" + D_Omd.At(Dark , Pn9, 5).GetStrLv() + "\t\t\t\t" + D_Omd.At(Dark , Pn9, 3).GetStrSx() + "\t" + D_Omd.At(Dark , Pn9, 4).GetStrSx() + "\t" + D_Omd.At(Dark , Pn9, 5).GetStrSx() + "\t\t\t\t" + D_Omd.At(Dark , Pn9, 3).GetStrSy() + "\t" + D_Omd.At(Dark , Pn9, 4).GetStrSy() + "\t" + D_Omd.At(Dark , Pn9, 5).GetStrSy() + "\t\t\t\t" + D_Omd.At(Dark , Pn9, 3).GetStrT() + "\t" + D_Omd.At(Dark , Pn9, 4).GetStrT() + "\t" + D_Omd.At(Dark , Pn9, 5).GetStrT() + "\t\t\t\t" + D_Omd.At(Dark , Pn9, 3).GetStrDuv() + "\t" + D_Omd.At(Dark , Pn9, 4).GetStrDuv() + "\t" + D_Omd.At(Dark , Pn9, 5).GetStrDuv() + "\n");
    D_Txt.push_back("\t\t\t\t\t\t\t" + D_Omd.At(Dark , Pn9, 6).GetStrLv() + "\t" + D_Omd.At(Dark , Pn9, 7).GetStrLv() + "\t" + D_Omd.At(Dark , Pn9, 8).GetStrLv() + "\t\t\t\t" + D_Omd.At(Dark , Pn9, 6).GetStrSx() + "\t" + D_Omd.At(Dark , Pn9, 7).GetStrSx() + "\t" + D_Omd.At(Dark , Pn9, 8).GetStrSx() + "\t\t\t\t" + D_Omd.At(Dark , Pn9, 6).GetStrSy() + "\t" + D_Omd.At(Dark , Pn9, 7).GetStrSy() + "\t" + D_Omd.At(Dark , Pn9, 8).GetStrSy() + "\t\t\t\t" + D_Omd.At(Dark , Pn9, 6).GetStrT() + "\t" + D_Omd.At(Dark , Pn9, 7).GetStrT() + "\t" + D_Omd.At(Dark , Pn9, 8).GetStrT() + "\t\t\t\t" + D_Omd.At(Dark , Pn9, 6).GetStrDuv() + "\t" + D_Omd.At(Dark , Pn9, 7).GetStrDuv() + "\t" + D_Omd.At(Dark , Pn9, 8).GetStrDuv() + "\n");
    D_Txt.push_back("\n");
    
    D_Txt.push_back("\t\t\t\t\t\t15點均齊度\tL\t\t\t\t\t15點均齊度\tx\t\t\t\t\t15點均齊度\ty\t\t\t\t\t15點均齊度\tT\t\t\t\t\t15點均齊度\tduv\n");

    for (n = 0; n < 4 ; ++n)
        D_Txt.push_back(" \n");

    //D_Txt.push_back("\n\n\n\n");
    D_Txt.push_back("\t\t\t\t\t\t2010 SEC 15點均齊度-W\tL\t\t\t\t\t2010 SEC 15點均齊度-W\tx\t\t\t\t\t2010 SEC 15點均齊度-W\ty\t\t\t\t\t2010 SEC 15點均齊度-W\tT\t\t\t\t\t2010 SEC 15點均齊度-W\tduv\n");
    
    for (n = 0; n < 4 ; ++n)
        D_Txt.push_back(" \n");

    D_Txt.push_back("\t\t\t\t\t\t2010 SEC 15點均齊度-D\tL\t\t\t\t\t2010 SEC 15點均齊度-D\tx\t\t\t\t\t2010 SEC 15點均齊度-D\ty\t\t\t\t\t2010 SEC 15點均齊度-D\tT\t\t\t\t\t2010 SEC 15點均齊度-D\tduv\n");
    
    for (n = 0; n < 6 ; ++n)
        D_Txt.push_back(" \n");

    D_Txt.push_back("\t\t\t\t\t\t49點均齊度\tL\t\t\t\t\t\t\t49點均齊度\tx\t\t\t\t\t\t\t49點均齊度\ty\t\t\t\t\t\t\t49點均齊度\tT\t\t\t\t\t\t\t49點均齊度\tduv\n");
    
    D_Txt.push_back("\t\t\t\t\t\t\t" + 
           D_Omd.At(White, Pn49, 0).GetStrLv()  + "\t" + D_Omd.At(White, Pn49, 1).GetStrLv() + "\t" + D_Omd.At(White, Pn49, 2).GetStrLv() + "\t" + D_Omd.At(White, Pn49, 3).GetStrLv() + "\t" + D_Omd.At(White, Pn49, 4).GetStrLv() + "\t" + D_Omd.At(White, Pn49, 5).GetStrLv() + "\t" + D_Omd.At(White, Pn49, 6).GetStrLv() + "\t\t" +
           D_Omd.At(White, Pn49, 0).GetStrSx()  + "\t" + D_Omd.At(White, Pn49, 1).GetStrSx() + "\t" + D_Omd.At(White, Pn49, 2).GetStrSx() + "\t" + D_Omd.At(White, Pn49, 3).GetStrSx() + "\t" + D_Omd.At(White, Pn49, 4).GetStrSx() + "\t" + D_Omd.At(White, Pn49, 5).GetStrSx() + "\t" + D_Omd.At(White, Pn49, 6).GetStrSx() + "\t\t" +
           D_Omd.At(White, Pn49, 0).GetStrSy()  + "\t" + D_Omd.At(White, Pn49, 1).GetStrSy() + "\t" + D_Omd.At(White, Pn49, 2).GetStrSy() + "\t" + D_Omd.At(White, Pn49, 3).GetStrSy() + "\t" + D_Omd.At(White, Pn49, 4).GetStrSy() + "\t" + D_Omd.At(White, Pn49, 5).GetStrSy() + "\t" + D_Omd.At(White, Pn49, 6).GetStrSy() + "\t\t" +
           D_Omd.At(White, Pn49, 0).GetStrT()   + "\t" + D_Omd.At(White, Pn49, 1).GetStrT()  + "\t" + D_Omd.At(White, Pn49, 2).GetStrT()  + "\t" + D_Omd.At(White, Pn49, 3).GetStrT()  + "\t" + D_Omd.At(White, Pn49, 4).GetStrT()  + "\t" + D_Omd.At(White, Pn49, 5).GetStrT()  + "\t" + D_Omd.At(White, Pn49, 6).GetStrT()  + "\t\t" +
           D_Omd.At(White, Pn49, 0).GetStrDuv() + "\t" + D_Omd.At(White, Pn49, 1).GetStrDuv() + "\t" + D_Omd.At(White, Pn49, 2).GetStrDuv() + "\t" + D_Omd.At(White, Pn49, 3).GetStrDuv() + "\t" + D_Omd.At(White, Pn49, 4).GetStrDuv() + "\t" + D_Omd.At(White, Pn49, 5).GetStrDuv() + "\t" + D_Omd.At(White, Pn49, 6).GetStrDuv() + "\n");
    
    D_Txt.push_back("\t\t\t\t\t\t\t" +
           D_Omd.At(White, Pn49,  7).GetStrLv() + "\t" + D_Omd.At(White, Pn49,  8).GetStrLv() + "\t" + D_Omd.At(White, Pn49,  9).GetStrLv() + "\t" + D_Omd.At(White, Pn49, 10).GetStrLv() + "\t" + D_Omd.At(White, Pn49, 11).GetStrLv() + "\t" + D_Omd.At(White, Pn49, 12).GetStrLv() + "\t" + D_Omd.At(White, Pn49, 13).GetStrLv() + "\t\t" +
           D_Omd.At(White, Pn49,  7).GetStrSx() + "\t" + D_Omd.At(White, Pn49,  8).GetStrSx() + "\t" + D_Omd.At(White, Pn49,  9).GetStrSx() + "\t" + D_Omd.At(White, Pn49, 10).GetStrSx() + "\t" + D_Omd.At(White, Pn49, 11).GetStrSx() + "\t" + D_Omd.At(White, Pn49, 12).GetStrSx() + "\t" + D_Omd.At(White, Pn49, 13).GetStrSx() + "\t\t" +
           D_Omd.At(White, Pn49,  7).GetStrSy() + "\t" + D_Omd.At(White, Pn49,  8).GetStrSy() + "\t" + D_Omd.At(White, Pn49,  9).GetStrSy() + "\t" + D_Omd.At(White, Pn49, 10).GetStrSy() + "\t" + D_Omd.At(White, Pn49, 11).GetStrSy() + "\t" + D_Omd.At(White, Pn49, 12).GetStrSy() + "\t" + D_Omd.At(White, Pn49, 13).GetStrSy() + "\t\t" +
           D_Omd.At(White, Pn49,  7).GetStrT()  + "\t" + D_Omd.At(White, Pn49,  8).GetStrT()  + "\t" + D_Omd.At(White, Pn49,  9).GetStrT()  + "\t" + D_Omd.At(White, Pn49, 10).GetStrT()  + "\t" + D_Omd.At(White, Pn49, 11).GetStrT()  + "\t" + D_Omd.At(White, Pn49, 12).GetStrT()  + "\t" + D_Omd.At(White, Pn49, 13).GetStrT()  + "\t\t" +
           D_Omd.At(White, Pn49,  7).GetStrDuv() + "\t" + D_Omd.At(White, Pn49,  8).GetStrDuv() + "\t" + D_Omd.At(White, Pn49,  9).GetStrDuv() + "\t" + D_Omd.At(White, Pn49, 10).GetStrDuv() + "\t" + D_Omd.At(White, Pn49, 11).GetStrDuv() + "\t" + D_Omd.At(White, Pn49, 12).GetStrDuv() + "\t" + D_Omd.At(White, Pn49, 13).GetStrDuv() + "\n");
    
    D_Txt.push_back("\t\t\t\t\t\t\t" +
           D_Omd.At(White, Pn49, 14).GetStrLv() + "\t" + D_Omd.At(White, Pn49, 15).GetStrLv() + "\t" + D_Omd.At(White, Pn49, 16).GetStrLv() + "\t" + D_Omd.At(White, Pn49, 17).GetStrLv() + "\t" + D_Omd.At(White, Pn49, 18).GetStrLv() + "\t" + D_Omd.At(White, Pn49, 19).GetStrLv() + "\t" + D_Omd.At(White, Pn49, 20).GetStrLv() + "\t\t" +
           D_Omd.At(White, Pn49, 14).GetStrSx() + "\t" + D_Omd.At(White, Pn49, 15).GetStrSx() + "\t" + D_Omd.At(White, Pn49, 16).GetStrSx() + "\t" + D_Omd.At(White, Pn49, 17).GetStrSx() + "\t" + D_Omd.At(White, Pn49, 18).GetStrSx() + "\t" + D_Omd.At(White, Pn49, 19).GetStrSx() + "\t" + D_Omd.At(White, Pn49, 20).GetStrSx() + "\t\t" +
           D_Omd.At(White, Pn49, 14).GetStrSy() + "\t" + D_Omd.At(White, Pn49, 15).GetStrSy() + "\t" + D_Omd.At(White, Pn49, 16).GetStrSy() + "\t" + D_Omd.At(White, Pn49, 17).GetStrSy() + "\t" + D_Omd.At(White, Pn49, 18).GetStrSy() + "\t" + D_Omd.At(White, Pn49, 19).GetStrSy() + "\t" + D_Omd.At(White, Pn49, 20).GetStrSy() + "\t\t" +
           D_Omd.At(White, Pn49, 14).GetStrT()  + "\t" + D_Omd.At(White, Pn49, 15).GetStrT()  + "\t" + D_Omd.At(White, Pn49, 16).GetStrT()  + "\t" + D_Omd.At(White, Pn49, 17).GetStrT()  + "\t" + D_Omd.At(White, Pn49, 18).GetStrT()  + "\t" + D_Omd.At(White, Pn49, 19).GetStrT()  + "\t" + D_Omd.At(White, Pn49, 20).GetStrT()  + "\t\t" +
           D_Omd.At(White, Pn49, 14).GetStrDuv() + "\t" + D_Omd.At(White, Pn49, 15).GetStrDuv() + "\t" + D_Omd.At(White, Pn49, 16).GetStrDuv() + "\t" + D_Omd.At(White, Pn49, 17).GetStrDuv() + "\t" + D_Omd.At(White, Pn49, 18).GetStrDuv() + "\t" + D_Omd.At(White, Pn49, 19).GetStrDuv() + "\t" + D_Omd.At(White, Pn49, 20).GetStrDuv() + "\n");
    
    D_Txt.push_back("\t\t\t\t\t\t\t" +
           D_Omd.At(White, Pn49, 21).GetStrLv() + "\t" + D_Omd.At(White, Pn49, 22).GetStrLv() + "\t" + D_Omd.At(White, Pn49, 23).GetStrLv() + "\t" + D_Omd.At(White, Pn49, 24).GetStrLv() + "\t" + D_Omd.At(White, Pn49, 25).GetStrLv() + "\t" + D_Omd.At(White, Pn49, 26).GetStrLv() + "\t" + D_Omd.At(White, Pn49, 27).GetStrLv() + "\t\t" +
           D_Omd.At(White, Pn49, 21).GetStrSx() + "\t" + D_Omd.At(White, Pn49, 22).GetStrSx() + "\t" + D_Omd.At(White, Pn49, 23).GetStrSx() + "\t" + D_Omd.At(White, Pn49, 24).GetStrSx() + "\t" + D_Omd.At(White, Pn49, 25).GetStrSx() + "\t" + D_Omd.At(White, Pn49, 26).GetStrSx() + "\t" + D_Omd.At(White, Pn49, 27).GetStrSx() + "\t\t" +
           D_Omd.At(White, Pn49, 21).GetStrSy() + "\t" + D_Omd.At(White, Pn49, 22).GetStrSy() + "\t" + D_Omd.At(White, Pn49, 23).GetStrSy() + "\t" + D_Omd.At(White, Pn49, 24).GetStrSy() + "\t" + D_Omd.At(White, Pn49, 25).GetStrSy() + "\t" + D_Omd.At(White, Pn49, 26).GetStrSy() + "\t" + D_Omd.At(White, Pn49, 27).GetStrSy() + "\t\t" + 
           D_Omd.At(White, Pn49, 21).GetStrT()  + "\t" + D_Omd.At(White, Pn49, 22).GetStrT()  + "\t" + D_Omd.At(White, Pn49, 23).GetStrT()  + "\t" + D_Omd.At(White, Pn49, 24).GetStrT()  + "\t" + D_Omd.At(White, Pn49, 25).GetStrT()  + "\t" + D_Omd.At(White, Pn49, 26).GetStrT()  + "\t" + D_Omd.At(White, Pn49, 27).GetStrT()  + "\t\t" +
           D_Omd.At(White, Pn49, 21).GetStrDuv() + "\t" + D_Omd.At(White, Pn49, 22).GetStrDuv() + "\t" + D_Omd.At(White, Pn49, 23).GetStrDuv() + "\t" + D_Omd.At(White, Pn49, 24).GetStrDuv() + "\t" + D_Omd.At(White, Pn49, 25).GetStrDuv() + "\t" + D_Omd.At(White, Pn49, 26).GetStrDuv() + "\t" + D_Omd.At(White, Pn49, 27).GetStrDuv() + "\n");
    
    D_Txt.push_back("\t\t\t\t\t\t\t" +
           D_Omd.At(White, Pn49, 28).GetStrLv() + "\t" + D_Omd.At(White, Pn49, 29).GetStrLv() + "\t" + D_Omd.At(White, Pn49, 30).GetStrLv() + "\t" + D_Omd.At(White, Pn49, 31).GetStrLv() + "\t" + D_Omd.At(White, Pn49, 32).GetStrLv() + "\t" + D_Omd.At(White, Pn49, 33).GetStrLv() + "\t" + D_Omd.At(White, Pn49, 34).GetStrLv() + "\t\t" +
           D_Omd.At(White, Pn49, 28).GetStrSx() + "\t" + D_Omd.At(White, Pn49, 29).GetStrSx() + "\t" + D_Omd.At(White, Pn49, 30).GetStrSx() + "\t" + D_Omd.At(White, Pn49, 31).GetStrSx() + "\t" + D_Omd.At(White, Pn49, 32).GetStrSx() + "\t" + D_Omd.At(White, Pn49, 33).GetStrSx() + "\t" + D_Omd.At(White, Pn49, 34).GetStrSx() + "\t\t" +
           D_Omd.At(White, Pn49, 28).GetStrSy() + "\t" + D_Omd.At(White, Pn49, 29).GetStrSy() + "\t" + D_Omd.At(White, Pn49, 30).GetStrSy() + "\t" + D_Omd.At(White, Pn49, 31).GetStrSy() + "\t" + D_Omd.At(White, Pn49, 32).GetStrSy() + "\t" + D_Omd.At(White, Pn49, 33).GetStrSy() + "\t" + D_Omd.At(White, Pn49, 34).GetStrSy() + "\t\t" +
           D_Omd.At(White, Pn49, 28).GetStrT()  + "\t" + D_Omd.At(White, Pn49, 29).GetStrT()  + "\t" + D_Omd.At(White, Pn49, 30).GetStrT()  + "\t" + D_Omd.At(White, Pn49, 31).GetStrT()  + "\t" + D_Omd.At(White, Pn49, 32).GetStrT()  + "\t" + D_Omd.At(White, Pn49, 33).GetStrT()  + "\t" + D_Omd.At(White, Pn49, 34).GetStrT()  + "\t\t" +
           D_Omd.At(White, Pn49, 28).GetStrDuv() + "\t" + D_Omd.At(White, Pn49, 29).GetStrDuv() + "\t" + D_Omd.At(White, Pn49, 30).GetStrDuv() + "\t" + D_Omd.At(White, Pn49, 31).GetStrDuv() + "\t" + D_Omd.At(White, Pn49, 32).GetStrDuv() + "\t" + D_Omd.At(White, Pn49, 33).GetStrDuv() + "\t" + D_Omd.At(White, Pn49, 34).GetStrDuv() + "\n");
    
    D_Txt.push_back("\t\t\t\t\t\t\t" +
           D_Omd.At(White, Pn49, 35).GetStrLv() + "\t" + D_Omd.At(White, Pn49, 36).GetStrLv() + "\t" + D_Omd.At(White, Pn49, 37).GetStrLv() + "\t" + D_Omd.At(White, Pn49, 38).GetStrLv() + "\t" + D_Omd.At(White, Pn49, 39).GetStrLv() + "\t" + D_Omd.At(White, Pn49, 40).GetStrLv() + "\t" + D_Omd.At(White, Pn49, 41).GetStrLv() + "\t\t" +
           D_Omd.At(White, Pn49, 35).GetStrSx() + "\t" + D_Omd.At(White, Pn49, 36).GetStrSx() + "\t" + D_Omd.At(White, Pn49, 37).GetStrSx() + "\t" + D_Omd.At(White, Pn49, 38).GetStrSx() + "\t" + D_Omd.At(White, Pn49, 39).GetStrSx() + "\t" + D_Omd.At(White, Pn49, 40).GetStrSx() + "\t" + D_Omd.At(White, Pn49, 41).GetStrSx() + "\t\t" +
           D_Omd.At(White, Pn49, 35).GetStrSy() + "\t" + D_Omd.At(White, Pn49, 36).GetStrSy() + "\t" + D_Omd.At(White, Pn49, 37).GetStrSy() + "\t" + D_Omd.At(White, Pn49, 38).GetStrSy() + "\t" + D_Omd.At(White, Pn49, 39).GetStrSy() + "\t" + D_Omd.At(White, Pn49, 40).GetStrSy() + "\t" + D_Omd.At(White, Pn49, 41).GetStrSy() + "\t\t" +
           D_Omd.At(White, Pn49, 35).GetStrT()  + "\t" + D_Omd.At(White, Pn49, 36).GetStrT()  + "\t" + D_Omd.At(White, Pn49, 37).GetStrT()  + "\t" + D_Omd.At(White, Pn49, 38).GetStrT()  + "\t" + D_Omd.At(White, Pn49, 39).GetStrT()  + "\t" + D_Omd.At(White, Pn49, 40).GetStrT()  + "\t" + D_Omd.At(White, Pn49, 41).GetStrT()  + "\t\t" +
           D_Omd.At(White, Pn49, 35).GetStrDuv() + "\t" + D_Omd.At(White, Pn49, 36).GetStrDuv() + "\t" + D_Omd.At(White, Pn49, 37).GetStrDuv() + "\t" + D_Omd.At(White, Pn49, 38).GetStrDuv() + "\t" + D_Omd.At(White, Pn49, 39).GetStrDuv() + "\t" + D_Omd.At(White, Pn49, 40).GetStrDuv() + "\t" + D_Omd.At(White, Pn49, 41).GetStrDuv() + "\n");
    
    D_Txt.push_back("\t\t\t\t\t\t\t" +
           D_Omd.At(White, Pn49, 42).GetStrLv() + "\t" + D_Omd.At(White, Pn49, 43).GetStrLv() + "\t" + D_Omd.At(White, Pn49, 44).GetStrLv() + "\t" + D_Omd.At(White, Pn49, 45).GetStrLv() + "\t" + D_Omd.At(White, Pn49, 46).GetStrLv() + "\t" + D_Omd.At(White, Pn49, 47).GetStrLv() + "\t" +  D_Omd.At(White, Pn49, 48).GetStrLv() + "\t\t" +
           D_Omd.At(White, Pn49, 42).GetStrSx() + "\t" + D_Omd.At(White, Pn49, 43).GetStrSx() + "\t" + D_Omd.At(White, Pn49, 44).GetStrSx() + "\t" + D_Omd.At(White, Pn49, 45).GetStrSx() + "\t" +  D_Omd.At(White, Pn49, 46).GetStrSx() + "\t" + D_Omd.At(White, Pn49, 47).GetStrSx() + "\t" + D_Omd.At(White, Pn49, 48).GetStrSx() + "\t\t" +
           D_Omd.At(White, Pn49, 42).GetStrSy() + "\t" + D_Omd.At(White, Pn49, 43).GetStrSy() + "\t" + D_Omd.At(White, Pn49, 44).GetStrSy() + "\t" + D_Omd.At(White, Pn49, 45).GetStrSy() + "\t" + D_Omd.At(White, Pn49, 46).GetStrSy() + "\t" + D_Omd.At(White, Pn49, 47).GetStrSy() + "\t" + D_Omd.At(White, Pn49, 48).GetStrSy() + "\t\t" +
           D_Omd.At(White, Pn49, 42).GetStrT()  + "\t" + D_Omd.At(White, Pn49, 43).GetStrT()  + "\t" + D_Omd.At(White, Pn49, 44).GetStrT()  + "\t" + D_Omd.At(White, Pn49, 45).GetStrT()  + "\t" + D_Omd.At(White, Pn49, 46).GetStrT()  + "\t" + D_Omd.At(White, Pn49, 47).GetStrT()  + "\t" + D_Omd.At(White, Pn49, 48).GetStrT()  + "\t\t" +
           D_Omd.At(White, Pn49, 42).GetStrDuv() + "\t" + D_Omd.At(White, Pn49, 43).GetStrDuv() + "\t" + D_Omd.At(White, Pn49, 44).GetStrDuv() + "\t" + D_Omd.At(White, Pn49, 45).GetStrDuv() + "\t" + D_Omd.At(White, Pn49, 46).GetStrDuv() + "\t" + D_Omd.At(White, Pn49, 47).GetStrDuv() + "\t" + D_Omd.At(White, Pn49, 48).GetStrDuv() + "\n");

    D_Txt.push_back(" \n");

    D_Txt.push_back("\t\t\t\t\t\t黑色13點均齊度\tL\t\t\t\t\t黑色13點均齊度\tx\t\t\t\t\t黑色13點均齊度\ty\n");
    
    for (n = 0; n<22; ++n)
        D_Txt.push_back(" \n");

    D_Txt.push_back("\t\t\t\t\t\tGamma curve\tL\t\t\t\tx\t\t\t\ty\t\t\t\tT\tduv\n");
    D_Txt.push_back("\t\t\t\t\t\tLevel\tWhite\tRed\tGreen\tBlue\tWhite\tRed\tGreen\tBlue\tWhite\tRed\tGreen\tBlue\tWhite\tWhite\n");


    f_Txt.iTxtData(D_Txt);

//	D_Txt.clear();
}

BOOL COmdFile1::isOldForm(TxtStrData& dTxt)//判斷是不是Labview輸出的檔
{
	return (dTxt.at(0).Find(':') != -1) ? TRUE : FALSE;
};  

void COmdFile1::TxtToOmd()
{
	D_Omd.StdInit();
	f_Txt.oTxtData(D_Txt);

//檔頭
    if (isOldForm(D_Txt))
    {
         m_PnlID .Format("%s", GetCell('B', 1));           m_PnlID.TrimRight();
         m_MsrDvc.Format("%s", GetCell('F', 1).Left(6));   m_MsrDvc.TrimRight();
         m_Prb   .Format("%s", GetCell('F', 1).Right(8));  m_Prb.TrimRight();
         m_CHID  .Format("%s", GetCell('G', 1).Right(2));  m_CHID.TrimRight();
    }
    else
    {
         m_PnlID .Format("%s", GetCell('B', 1));  m_PnlID.TrimRight();
         m_MsrDvc.Format("%s", GetCell('D', 1));  m_MsrDvc.TrimRight();
         m_Prb   .Format("%s", GetCell('F', 1));  m_Prb.TrimRight();
         m_CHID  .Format("%s", GetCell('H', 1));  m_CHID.TrimRight();
    }

//檔案資料      
    //中心點    
    D_Omd.At(White, Pn1, 0).SetLv( GetCell('B', 3) );
    D_Omd.At(White, Pn1, 0).SetSx( GetCell('C', 3) );
    D_Omd.At(White, Pn1, 0).SetSy( GetCell('D', 3) );
    D_Omd.At(White, Pn1, 0).SetDu( GetCell('E', 3) );
    D_Omd.At(White, Pn1, 0).SetDv( GetCell('F', 3) );

    D_Omd.At(Red, Pn1, 0).SetLv( GetCell('B', 4) );
    D_Omd.At(Red, Pn1, 0).SetSx( GetCell('C', 4) );
    D_Omd.At(Red, Pn1, 0).SetSy( GetCell('D', 4) );
    D_Omd.At(Red, Pn1, 0).SetDu( GetCell('E', 4) );
    D_Omd.At(Red, Pn1, 0).SetDv( GetCell('F', 4) );
    
    D_Omd.At(Green, Pn1, 0).SetLv( GetCell('B', 5) );
    D_Omd.At(Green, Pn1, 0).SetSx( GetCell('C', 5) );
    D_Omd.At(Green, Pn1, 0).SetSy( GetCell('D', 5) );
    D_Omd.At(Green, Pn1, 0).SetDu( GetCell('E', 5) );
    D_Omd.At(Green, Pn1, 0).SetDv( GetCell('F', 5) );
    
    D_Omd.At(Blue, Pn1, 0).SetLv( GetCell('B', 6) );
    D_Omd.At(Blue, Pn1, 0).SetSx( GetCell('C', 6) );
    D_Omd.At(Blue, Pn1, 0).SetSy( GetCell('D', 6) );
    D_Omd.At(Blue, Pn1, 0).SetDu( GetCell('E', 6) );
    D_Omd.At(Blue, Pn1, 0).SetDv( GetCell('F', 6) );

    //5nits
	D_Omd.At(Nits, Pn9, 0).SetLv( GetCell('H', 3) );
    D_Omd.At(Nits, Pn9, 1).SetLv( GetCell('I', 3) );
    D_Omd.At(Nits, Pn9, 2).SetLv( GetCell('J', 3) );
    D_Omd.At(Nits, Pn9, 3).SetLv( GetCell('H', 4) );
    D_Omd.At(Nits, Pn9, 4).SetLv( GetCell('I', 4) );
    D_Omd.At(Nits, Pn9, 5).SetLv( GetCell('J', 4) );
    D_Omd.At(Nits, Pn9, 6).SetLv( GetCell('H', 5) );
    D_Omd.At(Nits, Pn9, 7).SetLv( GetCell('I', 5) );
    D_Omd.At(Nits, Pn9, 8).SetLv( GetCell('J', 5) );

    D_Omd.At(Nits, Pn9, 0).SetSx( GetCell('N', 3) );
    D_Omd.At(Nits, Pn9, 1).SetSx( GetCell('O', 3) );
    D_Omd.At(Nits, Pn9, 2).SetSx( GetCell('P', 3) );
    D_Omd.At(Nits, Pn9, 3).SetSx( GetCell('N', 4) );
    D_Omd.At(Nits, Pn9, 4).SetSx( GetCell('O', 4) );
    D_Omd.At(Nits, Pn9, 5).SetSx( GetCell('P', 4) );
    D_Omd.At(Nits, Pn9, 6).SetSx( GetCell('N', 5) );
    D_Omd.At(Nits, Pn9, 7).SetSx( GetCell('O', 5) );
    D_Omd.At(Nits, Pn9, 8).SetSx( GetCell('P', 5) );

    D_Omd.At(Nits, Pn9, 0).SetSy( GetCell('T', 3) );
    D_Omd.At(Nits, Pn9, 1).SetSy( GetCell('U', 3) );
    D_Omd.At(Nits, Pn9, 2).SetSy( GetCell('V', 3) );
    D_Omd.At(Nits, Pn9, 3).SetSy( GetCell('T', 4) );
    D_Omd.At(Nits, Pn9, 4).SetSy( GetCell('U', 4) );
    D_Omd.At(Nits, Pn9, 5).SetSy( GetCell('V', 4) );
    D_Omd.At(Nits, Pn9, 6).SetSy( GetCell('T', 5) );
    D_Omd.At(Nits, Pn9, 7).SetSy( GetCell('U', 5) );
    D_Omd.At(Nits, Pn9, 8).SetSy( GetCell('V', 5) );

    D_Omd.At(Nits, Pn9, 0).SetT( GetCell('Z' , 3) );
    D_Omd.At(Nits, Pn9, 1).SetT( GetCell("AA", 3) );
    D_Omd.At(Nits, Pn9, 2).SetT( GetCell("AB", 3) );
    D_Omd.At(Nits, Pn9, 3).SetT( GetCell('Z' , 4) );
    D_Omd.At(Nits, Pn9, 4).SetT( GetCell("AA", 4) );
    D_Omd.At(Nits, Pn9, 5).SetT( GetCell("AB", 4) );
    D_Omd.At(Nits, Pn9, 6).SetT( GetCell('Z' , 5) );
    D_Omd.At(Nits, Pn9, 7).SetT( GetCell("AA", 5) );
    D_Omd.At(Nits, Pn9, 8).SetT( GetCell("AB", 5) );

    D_Omd.At(Nits, Pn9, 0).SetDuv( GetCell("AF", 3) );
    D_Omd.At(Nits, Pn9, 1).SetDuv( GetCell("AG", 3) );
    D_Omd.At(Nits, Pn9, 2).SetDuv( GetCell("AH", 3) );
    D_Omd.At(Nits, Pn9, 3).SetDuv( GetCell("AF", 4) );
    D_Omd.At(Nits, Pn9, 4).SetDuv( GetCell("AG", 4) );
    D_Omd.At(Nits, Pn9, 5).SetDuv( GetCell("AH", 4) );
    D_Omd.At(Nits, Pn9, 6).SetDuv( GetCell("AF", 5) );
    D_Omd.At(Nits, Pn9, 7).SetDuv( GetCell("AG", 5) );
    D_Omd.At(Nits, Pn9, 8).SetDuv( GetCell("AH", 5) );

    //白色九點均齊
    D_Omd.At(White, Pn9, 0).SetLv( GetCell('H', 8) );
    D_Omd.At(White, Pn9, 1).SetLv( GetCell('I', 8) );
    D_Omd.At(White, Pn9, 2).SetLv( GetCell('J', 8) );
    D_Omd.At(White, Pn9, 3).SetLv( GetCell('H', 9) );
    D_Omd.At(White, Pn9, 4).SetLv( GetCell('I', 9) );
    D_Omd.At(White, Pn9, 5).SetLv( GetCell('J', 9) );
    D_Omd.At(White, Pn9, 6).SetLv( GetCell('H', 10) );
    D_Omd.At(White, Pn9, 7).SetLv( GetCell('I', 10) );
    D_Omd.At(White, Pn9, 8).SetLv( GetCell('J', 10) );

	//D_Omd.At(Red  , Pn9, 0).SetSx( 0.666);

    D_Omd.At(White, Pn9, 0).SetSx( GetCell('N', 8) );
    D_Omd.At(White, Pn9, 1).SetSx( GetCell('O', 8) );
    D_Omd.At(White, Pn9, 2).SetSx( GetCell('P', 8) );
    D_Omd.At(White, Pn9, 3).SetSx( GetCell('N', 9) );
    D_Omd.At(White, Pn9, 4).SetSx( GetCell('O', 9) );
    D_Omd.At(White, Pn9, 5).SetSx( GetCell('P', 9) );
    D_Omd.At(White, Pn9, 6).SetSx( GetCell('N', 10) );
    D_Omd.At(White, Pn9, 7).SetSx( GetCell('O', 10) );
    D_Omd.At(White, Pn9, 8).SetSx( GetCell('P', 10) );
    
    D_Omd.At(White, Pn9, 0).SetSy( GetCell('T', 8) );
    D_Omd.At(White, Pn9, 1).SetSy( GetCell('U', 8) );
    D_Omd.At(White, Pn9, 2).SetSy( GetCell('V', 8) );
    D_Omd.At(White, Pn9, 3).SetSy( GetCell('T', 9) );
    D_Omd.At(White, Pn9, 4).SetSy( GetCell('U', 9) );
    D_Omd.At(White, Pn9, 5).SetSy( GetCell('V', 9) );
    D_Omd.At(White, Pn9, 6).SetSy( GetCell('T', 10) );
    D_Omd.At(White, Pn9, 7).SetSy( GetCell('U', 10) );
    D_Omd.At(White, Pn9, 8).SetSy( GetCell('V', 10) );
    
    D_Omd.At(White, Pn9, 0).SetT( GetCell('Z' , 8) );
    D_Omd.At(White, Pn9, 1).SetT( GetCell("AA", 8) );
    D_Omd.At(White, Pn9, 2).SetT( GetCell("AB", 8) );
    D_Omd.At(White, Pn9, 3).SetT( GetCell('Z' , 9) );
    D_Omd.At(White, Pn9, 4).SetT( GetCell("AA", 9) );
    D_Omd.At(White, Pn9, 5).SetT( GetCell("AB", 9) );
    D_Omd.At(White, Pn9, 6).SetT( GetCell('Z' , 10) );
    D_Omd.At(White, Pn9, 7).SetT( GetCell("AA", 10) );
    D_Omd.At(White, Pn9, 8).SetT( GetCell("AB", 10) );

    D_Omd.At(White, Pn9, 0).SetDuv( GetCell("AF", 8) );
    D_Omd.At(White, Pn9, 1).SetDuv( GetCell("AG", 8) );
    D_Omd.At(White, Pn9, 2).SetDuv( GetCell("AH", 8) );
    D_Omd.At(White, Pn9, 3).SetDuv( GetCell("AF", 9) );
    D_Omd.At(White, Pn9, 4).SetDuv( GetCell("AG", 9) );
    D_Omd.At(White, Pn9, 5).SetDuv( GetCell("AH", 9) );
    D_Omd.At(White, Pn9, 6).SetDuv( GetCell("AF", 10) );
    D_Omd.At(White, Pn9, 7).SetDuv( GetCell("AG", 10) );
    D_Omd.At(White, Pn9, 8).SetDuv( GetCell("AH", 10) );
    
    //黑色9點
    D_Omd.At(Dark, Pn9, 0).SetLv( GetCell('H', 13) );
    D_Omd.At(Dark, Pn9, 1).SetLv( GetCell('I', 13) );
    D_Omd.At(Dark, Pn9, 2).SetLv( GetCell('J', 13) );
    D_Omd.At(Dark, Pn9, 3).SetLv( GetCell('H', 14) );
    D_Omd.At(Dark, Pn9, 4).SetLv( GetCell('I', 14) );
    D_Omd.At(Dark, Pn9, 5).SetLv( GetCell('J', 14) );
    D_Omd.At(Dark, Pn9, 6).SetLv( GetCell('H', 15) );
    D_Omd.At(Dark, Pn9, 7).SetLv( GetCell('I', 15) );
    D_Omd.At(Dark, Pn9, 8).SetLv( GetCell('J', 15) );

    D_Omd.At(Dark, Pn9, 0).SetSx( GetCell('N', 13) );
    D_Omd.At(Dark, Pn9, 1).SetSx( GetCell('O', 13) );
    D_Omd.At(Dark, Pn9, 2).SetSx( GetCell('P', 13) );
    D_Omd.At(Dark, Pn9, 3).SetSx( GetCell('N', 14) );
    D_Omd.At(Dark, Pn9, 4).SetSx( GetCell('O', 14) );
    D_Omd.At(Dark, Pn9, 5).SetSx( GetCell('P', 14) );
    D_Omd.At(Dark, Pn9, 6).SetSx( GetCell('N', 15) );
    D_Omd.At(Dark, Pn9, 7).SetSx( GetCell('O', 15) );
    D_Omd.At(Dark, Pn9, 8).SetSx( GetCell('P', 15) );

    D_Omd.At(Dark, Pn9, 0).SetSy( GetCell('T', 13) );
    D_Omd.At(Dark, Pn9, 1).SetSy( GetCell('U', 13) );
    D_Omd.At(Dark, Pn9, 2).SetSy( GetCell('V', 13) );
    D_Omd.At(Dark, Pn9, 3).SetSy( GetCell('T', 14) );
    D_Omd.At(Dark, Pn9, 4).SetSy( GetCell('U', 14) );
    D_Omd.At(Dark, Pn9, 5).SetSy( GetCell('V', 14) );
    D_Omd.At(Dark, Pn9, 6).SetSy( GetCell('T', 15) );
    D_Omd.At(Dark, Pn9, 7).SetSy( GetCell('U', 15) );
    D_Omd.At(Dark, Pn9, 8).SetSy( GetCell('V', 15) );
    
    D_Omd.At(Dark, Pn9, 0).SetT( GetCell('Z' , 13) );
    D_Omd.At(Dark, Pn9, 1).SetT( GetCell("AA", 13) );
    D_Omd.At(Dark, Pn9, 2).SetT( GetCell("AB", 13) );
    D_Omd.At(Dark, Pn9, 3).SetT( GetCell('Z' , 14) );
    D_Omd.At(Dark, Pn9, 4).SetT( GetCell("AA", 14) );
    D_Omd.At(Dark, Pn9, 5).SetT( GetCell("AB" , 14) );
    D_Omd.At(Dark, Pn9, 6).SetT( GetCell('Z' , 15) );
    D_Omd.At(Dark, Pn9, 7).SetT( GetCell("AA", 15) );
    D_Omd.At(Dark, Pn9, 8).SetT( GetCell("AB", 15) );
    
    D_Omd.At(Dark, Pn9, 0).SetDuv( GetCell("AF", 13) );
    D_Omd.At(Dark, Pn9, 1).SetDuv( GetCell("AG", 13) );
    D_Omd.At(Dark, Pn9, 2).SetDuv( GetCell("AH", 13) );
    D_Omd.At(Dark, Pn9, 3).SetDuv( GetCell("AF", 14) );
    D_Omd.At(Dark, Pn9, 4).SetDuv( GetCell("AG", 14) );
    D_Omd.At(Dark, Pn9, 5).SetDuv( GetCell("AH", 14) );
    D_Omd.At(Dark, Pn9, 6).SetDuv( GetCell("AF", 15) );
    D_Omd.At(Dark, Pn9, 7).SetDuv( GetCell("AG", 15) );
    D_Omd.At(Dark, Pn9, 8).SetDuv( GetCell("AH", 15) );

    //49點
    D_Omd.At(White, Pn49,  0).SetLv( GetCell('H', 35) );
    D_Omd.At(White, Pn49,  1).SetLv( GetCell('I', 35) );
    D_Omd.At(White, Pn49,  2).SetLv( GetCell('J', 35) );
    D_Omd.At(White, Pn49,  3).SetLv( GetCell('K', 35) );
    D_Omd.At(White, Pn49,  4).SetLv( GetCell('L', 35) );
    D_Omd.At(White, Pn49,  5).SetLv( GetCell('M', 35) );
    D_Omd.At(White, Pn49,  6).SetLv( GetCell('N', 35) );
    D_Omd.At(White, Pn49,  7).SetLv( GetCell('H', 36) );
    D_Omd.At(White, Pn49,  8).SetLv( GetCell('I', 36) );
    D_Omd.At(White, Pn49,  9).SetLv( GetCell('J', 36) );
    D_Omd.At(White, Pn49, 10).SetLv( GetCell('K', 36) );
    D_Omd.At(White, Pn49, 11).SetLv( GetCell('L', 36) );
    D_Omd.At(White, Pn49, 12).SetLv( GetCell('M', 36) );
    D_Omd.At(White, Pn49, 13).SetLv( GetCell('N', 36) );
    D_Omd.At(White, Pn49, 14).SetLv( GetCell('H', 37) );
    D_Omd.At(White, Pn49, 15).SetLv( GetCell('I', 37) );
    D_Omd.At(White, Pn49, 16).SetLv( GetCell('J', 37) );
    D_Omd.At(White, Pn49, 17).SetLv( GetCell('K', 37) );
    D_Omd.At(White, Pn49, 18).SetLv( GetCell('L', 37) );
    D_Omd.At(White, Pn49, 19).SetLv( GetCell('M', 37) );
    D_Omd.At(White, Pn49, 20).SetLv( GetCell('N', 37) );
    D_Omd.At(White, Pn49, 21).SetLv( GetCell('H', 38) );
    D_Omd.At(White, Pn49, 22).SetLv( GetCell('I', 38) );
    D_Omd.At(White, Pn49, 23).SetLv( GetCell('J', 38) );
    D_Omd.At(White, Pn49, 24).SetLv( GetCell('K', 38) );
    D_Omd.At(White, Pn49, 25).SetLv( GetCell('L', 38) );
    D_Omd.At(White, Pn49, 26).SetLv( GetCell('M', 38) );
    D_Omd.At(White, Pn49, 27).SetLv( GetCell('N', 38) );
    D_Omd.At(White, Pn49, 28).SetLv( GetCell('H', 39) );
    D_Omd.At(White, Pn49, 29).SetLv( GetCell('I', 39) );
    D_Omd.At(White, Pn49, 30).SetLv( GetCell('J', 39) );
    D_Omd.At(White, Pn49, 31).SetLv( GetCell('K', 39) );
    D_Omd.At(White, Pn49, 32).SetLv( GetCell('L', 39) );
    D_Omd.At(White, Pn49, 33).SetLv( GetCell('M', 39) );
    D_Omd.At(White, Pn49, 34).SetLv( GetCell('N', 39) );
    D_Omd.At(White, Pn49, 35).SetLv( GetCell('H', 40) );
    D_Omd.At(White, Pn49, 36).SetLv( GetCell('I', 40) );
    D_Omd.At(White, Pn49, 37).SetLv( GetCell('J', 40) );
    D_Omd.At(White, Pn49, 38).SetLv( GetCell('K', 40) );
    D_Omd.At(White, Pn49, 39).SetLv( GetCell('L', 40) );
    D_Omd.At(White, Pn49, 40).SetLv( GetCell('M', 40) );
    D_Omd.At(White, Pn49, 41).SetLv( GetCell('N', 40) );
    D_Omd.At(White, Pn49, 42).SetLv( GetCell('H', 41) );
    D_Omd.At(White, Pn49, 43).SetLv( GetCell('I', 41) );
    D_Omd.At(White, Pn49, 44).SetLv( GetCell('J', 41) );
    D_Omd.At(White, Pn49, 45).SetLv( GetCell('K', 41) );
    D_Omd.At(White, Pn49, 46).SetLv( GetCell('L', 41) );
    D_Omd.At(White, Pn49, 47).SetLv( GetCell('M', 41) );
    D_Omd.At(White, Pn49, 48).SetLv( GetCell('N', 41) );

    D_Omd.At(White, Pn49,  0).SetSx( GetCell('P', 35) );
    D_Omd.At(White, Pn49,  1).SetSx( GetCell('Q', 35) );
    D_Omd.At(White, Pn49,  2).SetSx( GetCell('R', 35) );
    D_Omd.At(White, Pn49,  3).SetSx( GetCell('S', 35) );
    D_Omd.At(White, Pn49,  4).SetSx( GetCell('T', 35) );
    D_Omd.At(White, Pn49,  5).SetSx( GetCell('U', 35) );
    D_Omd.At(White, Pn49,  6).SetSx( GetCell('V', 35) );
    D_Omd.At(White, Pn49,  7).SetSx( GetCell('P', 36) );
    D_Omd.At(White, Pn49,  8).SetSx( GetCell('Q', 36) );
    D_Omd.At(White, Pn49,  9).SetSx( GetCell('R', 36) );
    D_Omd.At(White, Pn49, 10).SetSx( GetCell('S', 36) );
    D_Omd.At(White, Pn49, 11).SetSx( GetCell('T', 36) );
    D_Omd.At(White, Pn49, 12).SetSx( GetCell('U', 36) );
    D_Omd.At(White, Pn49, 13).SetSx( GetCell('V', 36) );
    D_Omd.At(White, Pn49, 14).SetSx( GetCell('P', 37) );
    D_Omd.At(White, Pn49, 15).SetSx( GetCell('Q', 37) );
    D_Omd.At(White, Pn49, 16).SetSx( GetCell('R', 37) );
    D_Omd.At(White, Pn49, 17).SetSx( GetCell('S', 37) );
    D_Omd.At(White, Pn49, 18).SetSx( GetCell('T', 37) );
    D_Omd.At(White, Pn49, 19).SetSx( GetCell('U', 37) );
    D_Omd.At(White, Pn49, 20).SetSx( GetCell('V', 37) );
    D_Omd.At(White, Pn49, 21).SetSx( GetCell('P', 38) );
    D_Omd.At(White, Pn49, 22).SetSx( GetCell('Q', 38) );
    D_Omd.At(White, Pn49, 23).SetSx( GetCell('R', 38) );
    D_Omd.At(White, Pn49, 24).SetSx( GetCell('S', 38) );
    D_Omd.At(White, Pn49, 25).SetSx( GetCell('T', 38) );
    D_Omd.At(White, Pn49, 26).SetSx( GetCell('U', 38) );
    D_Omd.At(White, Pn49, 27).SetSx( GetCell('V', 38) );
    D_Omd.At(White, Pn49, 28).SetSx( GetCell('P', 39) );
    D_Omd.At(White, Pn49, 29).SetSx( GetCell('Q', 39) );
    D_Omd.At(White, Pn49, 30).SetSx( GetCell('R', 39) );
    D_Omd.At(White, Pn49, 31).SetSx( GetCell('S', 39) );
    D_Omd.At(White, Pn49, 32).SetSx( GetCell('T', 39) );
    D_Omd.At(White, Pn49, 33).SetSx( GetCell('U', 39) );
    D_Omd.At(White, Pn49, 34).SetSx( GetCell('V', 39) );
    D_Omd.At(White, Pn49, 35).SetSx( GetCell('P', 40) );
    D_Omd.At(White, Pn49, 36).SetSx( GetCell('Q', 40) );
    D_Omd.At(White, Pn49, 37).SetSx( GetCell('R', 40) );
    D_Omd.At(White, Pn49, 38).SetSx( GetCell('S', 40) );
    D_Omd.At(White, Pn49, 39).SetSx( GetCell('T', 40) );
    D_Omd.At(White, Pn49, 40).SetSx( GetCell('U', 40) );
    D_Omd.At(White, Pn49, 41).SetSx( GetCell('V', 40) );
    D_Omd.At(White, Pn49, 42).SetSx( GetCell('P', 41) );
    D_Omd.At(White, Pn49, 43).SetSx( GetCell('Q', 41) );
    D_Omd.At(White, Pn49, 44).SetSx( GetCell('R', 41) );
    D_Omd.At(White, Pn49, 45).SetSx( GetCell('S', 41) );
    D_Omd.At(White, Pn49, 46).SetSx( GetCell('T', 41) );
    D_Omd.At(White, Pn49, 47).SetSx( GetCell('U', 41) );
    D_Omd.At(White, Pn49, 48).SetSx( GetCell('V', 41) );

    D_Omd.At(White, Pn49,  0).SetSy( GetCell('X' , 35) );
    D_Omd.At(White, Pn49,  1).SetSy( GetCell('Y' , 35) );
    D_Omd.At(White, Pn49,  2).SetSy( GetCell('Z' , 35) );
    D_Omd.At(White, Pn49,  3).SetSy( GetCell("AA", 35) );
    D_Omd.At(White, Pn49,  4).SetSy( GetCell("AB", 35) );
    D_Omd.At(White, Pn49,  5).SetSy( GetCell("AC", 35) );
    D_Omd.At(White, Pn49,  6).SetSy( GetCell("AD", 35) );
    D_Omd.At(White, Pn49,  7).SetSy( GetCell('X' , 36) );
    D_Omd.At(White, Pn49,  8).SetSy( GetCell('Y' , 36) );
    D_Omd.At(White, Pn49,  9).SetSy( GetCell('Z' , 36) );
    D_Omd.At(White, Pn49, 10).SetSy( GetCell("AA", 36) );
    D_Omd.At(White, Pn49, 11).SetSy( GetCell("AB", 36) );
    D_Omd.At(White, Pn49, 12).SetSy( GetCell("AC", 36) );
    D_Omd.At(White, Pn49, 13).SetSy( GetCell("AD", 36) );
    D_Omd.At(White, Pn49, 14).SetSy( GetCell('X' , 37) );
    D_Omd.At(White, Pn49, 15).SetSy( GetCell('Y' , 37) );
    D_Omd.At(White, Pn49, 16).SetSy( GetCell('Z' , 37) );
    D_Omd.At(White, Pn49, 17).SetSy( GetCell("AA", 37) );
    D_Omd.At(White, Pn49, 18).SetSy( GetCell("AB", 37) );
    D_Omd.At(White, Pn49, 19).SetSy( GetCell("AC", 37) );
    D_Omd.At(White, Pn49, 20).SetSy( GetCell("AD", 37) );
    D_Omd.At(White, Pn49, 21).SetSy( GetCell('X' , 38) );
    D_Omd.At(White, Pn49, 22).SetSy( GetCell('Y' , 38) );
    D_Omd.At(White, Pn49, 23).SetSy( GetCell('Z' , 38) );
    D_Omd.At(White, Pn49, 24).SetSy( GetCell("AA", 38) );
    D_Omd.At(White, Pn49, 25).SetSy( GetCell("AB", 38) );
    D_Omd.At(White, Pn49, 26).SetSy( GetCell("AC", 38) );
    D_Omd.At(White, Pn49, 27).SetSy( GetCell("AD", 38) );
    D_Omd.At(White, Pn49, 28).SetSy( GetCell('X' , 39) );
    D_Omd.At(White, Pn49, 29).SetSy( GetCell('Y' , 39) );
    D_Omd.At(White, Pn49, 30).SetSy( GetCell('Z' , 39) );
    D_Omd.At(White, Pn49, 31).SetSy( GetCell("AA", 39) );
    D_Omd.At(White, Pn49, 32).SetSy( GetCell("AB", 39) );
    D_Omd.At(White, Pn49, 33).SetSy( GetCell("AC", 39) );
    D_Omd.At(White, Pn49, 34).SetSy( GetCell("AD", 39) );
    D_Omd.At(White, Pn49, 35).SetSy( GetCell('X' , 40) );
    D_Omd.At(White, Pn49, 36).SetSy( GetCell('Y' , 40) );
    D_Omd.At(White, Pn49, 37).SetSy( GetCell('Z' , 40) );
    D_Omd.At(White, Pn49, 38).SetSy( GetCell("AA", 40) );
    D_Omd.At(White, Pn49, 39).SetSy( GetCell("AB", 40) );
    D_Omd.At(White, Pn49, 40).SetSy( GetCell("AC", 40) );
    D_Omd.At(White, Pn49, 41).SetSy( GetCell("AD", 40) );
    D_Omd.At(White, Pn49, 42).SetSy( GetCell('X' , 41) );
    D_Omd.At(White, Pn49, 43).SetSy( GetCell('Y' , 41) );
    D_Omd.At(White, Pn49, 44).SetSy( GetCell('Z' , 41) );
    D_Omd.At(White, Pn49, 45).SetSy( GetCell("AA", 41) );
    D_Omd.At(White, Pn49, 46).SetSy( GetCell("AB", 41) );
    D_Omd.At(White, Pn49, 47).SetSy( GetCell("AC", 41) );
    D_Omd.At(White, Pn49, 48).SetSy( GetCell("AD", 41) );

    D_Omd.At(White, Pn49,  0).SetT( GetCell("AF", 35) );
    D_Omd.At(White, Pn49,  1).SetT( GetCell("AG", 35) );
    D_Omd.At(White, Pn49,  2).SetT( GetCell("AH", 35) );
    D_Omd.At(White, Pn49,  3).SetT( GetCell("AI", 35) );
    D_Omd.At(White, Pn49,  4).SetT( GetCell("AJ", 35) );
    D_Omd.At(White, Pn49,  5).SetT( GetCell("AK", 35) );
    D_Omd.At(White, Pn49,  6).SetT( GetCell("AL", 35) );
    D_Omd.At(White, Pn49,  7).SetT( GetCell("AF", 36) );
    D_Omd.At(White, Pn49,  8).SetT( GetCell("AG", 36) );
    D_Omd.At(White, Pn49,  9).SetT( GetCell("AH", 36) );
    D_Omd.At(White, Pn49, 10).SetT( GetCell("AI", 36) );
    D_Omd.At(White, Pn49, 11).SetT( GetCell("AJ", 36) );
    D_Omd.At(White, Pn49, 12).SetT( GetCell("AK", 36) );
    D_Omd.At(White, Pn49, 13).SetT( GetCell("AL", 36) );
    D_Omd.At(White, Pn49, 14).SetT( GetCell("AF", 37) );
    D_Omd.At(White, Pn49, 15).SetT( GetCell("AG", 37) );
    D_Omd.At(White, Pn49, 16).SetT( GetCell("AH", 37) );
    D_Omd.At(White, Pn49, 17).SetT( GetCell("AI", 37) );
    D_Omd.At(White, Pn49, 18).SetT( GetCell("AJ", 37) );
    D_Omd.At(White, Pn49, 19).SetT( GetCell("AK", 37) );
    D_Omd.At(White, Pn49, 20).SetT( GetCell("AL", 37) );
    D_Omd.At(White, Pn49, 21).SetT( GetCell("AF", 38) );
    D_Omd.At(White, Pn49, 22).SetT( GetCell("AG", 38) );
    D_Omd.At(White, Pn49, 23).SetT( GetCell("AH", 38) );
    D_Omd.At(White, Pn49, 24).SetT( GetCell("AI", 38) );
    D_Omd.At(White, Pn49, 25).SetT( GetCell("AJ", 38) );
    D_Omd.At(White, Pn49, 26).SetT( GetCell("AK", 38) );
    D_Omd.At(White, Pn49, 27).SetT( GetCell("AL", 38) );
    D_Omd.At(White, Pn49, 28).SetT( GetCell("AF", 39) );
    D_Omd.At(White, Pn49, 29).SetT( GetCell("AG", 39) );
    D_Omd.At(White, Pn49, 30).SetT( GetCell("AH", 39) );
    D_Omd.At(White, Pn49, 31).SetT( GetCell("AI", 39) );
    D_Omd.At(White, Pn49, 32).SetT( GetCell("AJ", 39) );
    D_Omd.At(White, Pn49, 33).SetT( GetCell("AK", 39) );
    D_Omd.At(White, Pn49, 34).SetT( GetCell("AL", 39) );
    D_Omd.At(White, Pn49, 35).SetT( GetCell("AF", 40) );
    D_Omd.At(White, Pn49, 36).SetT( GetCell("AG", 40) );
    D_Omd.At(White, Pn49, 37).SetT( GetCell("AH", 40) );
    D_Omd.At(White, Pn49, 38).SetT( GetCell("AI", 40) );
    D_Omd.At(White, Pn49, 39).SetT( GetCell("AJ", 40) );
    D_Omd.At(White, Pn49, 40).SetT( GetCell("AK", 40) );
    D_Omd.At(White, Pn49, 41).SetT( GetCell("AL", 40) );
    D_Omd.At(White, Pn49, 42).SetT( GetCell("AF", 41) );
    D_Omd.At(White, Pn49, 43).SetT( GetCell("AG", 41) );
    D_Omd.At(White, Pn49, 44).SetT( GetCell("AH", 41) );
    D_Omd.At(White, Pn49, 45).SetT( GetCell("AI", 41) );
    D_Omd.At(White, Pn49, 46).SetT( GetCell("AJ", 41) );
    D_Omd.At(White, Pn49, 47).SetT( GetCell("AK", 41) );
    D_Omd.At(White, Pn49, 48).SetT( GetCell("AL", 41) );

    D_Omd.At(White, Pn49,  0).SetDuv( GetCell("AN", 35) );
    D_Omd.At(White, Pn49,  1).SetDuv( GetCell("AO", 35) );
    D_Omd.At(White, Pn49,  2).SetDuv( GetCell("AP", 35) );
    D_Omd.At(White, Pn49,  3).SetDuv( GetCell("AQ", 35) );
    D_Omd.At(White, Pn49,  4).SetDuv( GetCell("AR", 35) );
    D_Omd.At(White, Pn49,  5).SetDuv( GetCell("AS", 35) );
    D_Omd.At(White, Pn49,  6).SetDuv( GetCell("AT", 35) );
    D_Omd.At(White, Pn49,  7).SetDuv( GetCell("AN", 36) );
    D_Omd.At(White, Pn49,  8).SetDuv( GetCell("AO", 36) );
    D_Omd.At(White, Pn49,  9).SetDuv( GetCell("AP", 36) );
    D_Omd.At(White, Pn49, 10).SetDuv( GetCell("AQ", 36) );
    D_Omd.At(White, Pn49, 11).SetDuv( GetCell("AR", 36) );
    D_Omd.At(White, Pn49, 12).SetDuv( GetCell("AS", 36) );
    D_Omd.At(White, Pn49, 13).SetDuv( GetCell("AT", 36) );
    D_Omd.At(White, Pn49, 14).SetDuv( GetCell("AN", 37) );
    D_Omd.At(White, Pn49, 15).SetDuv( GetCell("AO", 37) );
    D_Omd.At(White, Pn49, 16).SetDuv( GetCell("AP", 37) );
    D_Omd.At(White, Pn49, 17).SetDuv( GetCell("AQ", 37) );
    D_Omd.At(White, Pn49, 18).SetDuv( GetCell("AR", 37) );
    D_Omd.At(White, Pn49, 19).SetDuv( GetCell("AS", 37) );
    D_Omd.At(White, Pn49, 20).SetDuv( GetCell("AT", 37) );
    D_Omd.At(White, Pn49, 21).SetDuv( GetCell("AN", 38) );
    D_Omd.At(White, Pn49, 22).SetDuv( GetCell("AO", 38) );
    D_Omd.At(White, Pn49, 23).SetDuv( GetCell("AP", 38) );
    D_Omd.At(White, Pn49, 24).SetDuv( GetCell("AQ", 38) );
    D_Omd.At(White, Pn49, 25).SetDuv( GetCell("AR", 38) );
    D_Omd.At(White, Pn49, 26).SetDuv( GetCell("AS", 38) );
    D_Omd.At(White, Pn49, 27).SetDuv( GetCell("AT", 38) );
    D_Omd.At(White, Pn49, 28).SetDuv( GetCell("AN", 39) );
    D_Omd.At(White, Pn49, 29).SetDuv( GetCell("AO", 39) );
    D_Omd.At(White, Pn49, 30).SetDuv( GetCell("AP", 39) );
    D_Omd.At(White, Pn49, 31).SetDuv( GetCell("AQ", 39) );
    D_Omd.At(White, Pn49, 32).SetDuv( GetCell("AR", 39) );
    D_Omd.At(White, Pn49, 33).SetDuv( GetCell("AS", 39) );
    D_Omd.At(White, Pn49, 34).SetDuv( GetCell("AT", 39) );
    D_Omd.At(White, Pn49, 35).SetDuv( GetCell("AN", 40) );
    D_Omd.At(White, Pn49, 36).SetDuv( GetCell("AO", 40) );
    D_Omd.At(White, Pn49, 37).SetDuv( GetCell("AP", 40) );
    D_Omd.At(White, Pn49, 38).SetDuv( GetCell("AQ", 40) );
    D_Omd.At(White, Pn49, 39).SetDuv( GetCell("AR", 40) );
    D_Omd.At(White, Pn49, 40).SetDuv( GetCell("AS", 40) );
    D_Omd.At(White, Pn49, 41).SetDuv( GetCell("AT", 40) );
    D_Omd.At(White, Pn49, 42).SetDuv( GetCell("AN", 41) );
    D_Omd.At(White, Pn49, 43).SetDuv( GetCell("AO", 41) );
    D_Omd.At(White, Pn49, 44).SetDuv( GetCell("AP", 41) );
    D_Omd.At(White, Pn49, 45).SetDuv( GetCell("AQ", 41) );
    D_Omd.At(White, Pn49, 46).SetDuv( GetCell("AR", 41) );
    D_Omd.At(White, Pn49, 47).SetDuv( GetCell("AS", 41) );
    D_Omd.At(White, Pn49, 48).SetDuv( GetCell("AT", 41) );
 
	D_Omd.freeEmptyCell();
	D_Txt.clear();
}
	
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

COmdFile1::COmdFile1():
m_PnlID(""), m_MsrDvc(""), m_Prb(""), m_CHID("")
//m_5nitsBkColor(127)
{}

BOOL COmdFile1::Open(CString path, CFileException& fx)
{
	if (f_Txt.Open(path, fx))
		return TRUE;
	else
	{
		ErrorMsg(fx);
		f_Txt.Close();
		return FALSE;
	}
}

BOOL COmdFile1::Save(CString path, CFileException& fx)
{
	if (f_Txt.Save(path, fx))
	{
		return TRUE;
	}
	else
	{
		ErrorMsg(fx);
		f_Txt.Close();
		return FALSE;
	}
}

CString COmdFile1::GetLine(UINT LineNum)
{
    if (LineNum <= 0)
        return "出現錯誤: 參數 < 1";
    else if (LineNum > D_Txt.size())
        return "超出範圍";
    else
        return D_Txt.at((std::vector<CString>::size_type)LineNum - 1);
}

CString COmdFile1::GetCell(UINT Word, UINT Line)
{
    CString strBuf1;
    CString strBuf2;
    
    strBuf1 = GetLine(Line) + '\t';   
    
    if (!strBuf1.IsEmpty())
    {
        UINT wBegin = 0, wLength = 0;
		
        for (UINT i = 0; i < Word; ++i)
        {
            wLength = strBuf1.Right(strBuf1.GetLength() - wBegin).Find('\t');
            strBuf2.Format("%s", strBuf1.Mid(wBegin, wLength));
            wBegin += wLength + 1;
        }
    }
    if (strBuf2.IsEmpty())
        strBuf2.Format("");//(內容空白)
    return strBuf2;
}

CString COmdFile1::GetCell(TCHAR c, UINT n)
{
    UINT x;
    x = c - 'A' + 1;
    return GetCell(x, n);
}

CString COmdFile1::GetCell(PTCHAR c, UINT n)
{
    CString str;
    str.Format("%s", c);
	
    TCHAR c1;
    TCHAR c2;
    c1 = *(str.Left(1).GetBuffer(str.Left(1).GetLength()));
    c2 = *(str.Right(1).GetBuffer(str.Left(1).GetLength()));
	
    UINT x;
    x = (c1 - 'A' + 1) + (c2 - 'A' + 1) + 25;//+25是因為這個部份是從AA開始算，所以要跳過A~Z
    	
    return GetCell(x, n);
}

void COmdFile1::ErrorMsg(CFileException& fx)
{
	//例外處理
	TCHAR buf[255];
	fx.GetErrorMessage(buf, 255);
	CString strPrompt;
	strPrompt.Format("COmdFile1::LoadData()\n%s", buf);
	AfxMessageBox(strPrompt);
}
