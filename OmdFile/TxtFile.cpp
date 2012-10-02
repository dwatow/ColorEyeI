// TxtFile.cpp: implementation of the CTxtFile class.
//
//////////////////////////////////////////////////////////////////////

#include "stdAfx.h"
#include "TxtFile.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTxtFile::CTxtFile(){}
CTxtFile::~CTxtFile(){}

BOOL CTxtFile::Open(CString path, CFileException& fx)
{
    if (f_Std.Open(path, CFile::modeRead | CFile::typeText, &fx))
        return TRUE;  //成功入侵取得資料
    else
    { 
        ErrorMsg(fx);
        f_Std.Close();
        return FALSE;  //失敗
    }
}

void CTxtFile::FileToMem()
{
    D_Txt.clear();
    CString strTemp;
    while (f_Std.ReadString(strTemp))
    {
        strTemp.Format(_T("%s\n"), strTemp);
        D_Txt.push_back(strTemp);
    }
}

BOOL CTxtFile::Save(CString path, CFileException& fx)
{
    if (f_Std.Open(path, CFile::modeCreate | CFile::modeWrite | CFile::typeText, &fx))
        return TRUE;
    else
    {
        ErrorMsg(fx);
		f_Std.Close();
        return FALSE;
    }
}

void CTxtFile::MemToFile()
{
    if (!D_Txt.empty())
    {
        for (TxtStrData::iterator it = D_Txt.begin(); it != D_Txt.end(); ++it)
			//AfxMessageBox(*it);
				f_Std.WriteString(*it);
    }
}

void CTxtFile::ErrorMsg(CFileException& fx)
{
    //例外處理
    TCHAR buf[255];
    fx.GetErrorMessage(buf, 255);
    CString strPrompt;
    strPrompt.Format("CTxtFile\n%s", buf);
    AfxMessageBox(strPrompt);
}


