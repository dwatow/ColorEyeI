// TxtFile.cpp: implementation of the CTxtFile class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TxtFile.h"
#include <shlwapi.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

BOOL CTxtFile::Open(LPCTSTR path, CFileException& fx)
{
	if (PathFileExists(path))
	{
		if (ftxt_Std.Open(path, CFile::modeRead | CFile::typeText, &fx))
			return TRUE;  //成功入侵取得資料
		else
		{ 
			errorMsg(fx);
			ftxt_Std.Close();
			return FALSE;  //失敗
		}
	}
	else
		return FALSE;
}

void CTxtFile::file2mem()
{
    dtxt_Txt.clear();
    CString strTemp;
    while (ftxt_Std.ReadString(strTemp))
    {
        strTemp.Format(_T("%s\n"), strTemp);
        dtxt_Txt.push_back(strTemp);
    }
}

BOOL CTxtFile::Save(LPCTSTR path, CFileException& fx)
{
    if (ftxt_Std.Open(path, CFile::modeCreate | CFile::modeWrite | CFile::typeText, &fx))
        return TRUE;
    else
    {
        errorMsg(fx);
		ftxt_Std.Close();
        return FALSE;
    }
}

void CTxtFile::mem2file()
{
    if (!dtxt_Txt.empty())
    {
        for (TxtStrData::iterator it = dtxt_Txt.begin(); it != dtxt_Txt.end(); ++it)
			//AfxMessageBox(*it);
				ftxt_Std.WriteString(*it);
    }
}

void CTxtFile::errorMsg(CFileException& fx)
{
    //例外處理
    TCHAR buf[255];
    fx.GetErrorMessage(buf, 255);
    CString strPrompt;
    strPrompt.Format("CTxtFile說：「%s」", buf);
    AfxMessageBox(strPrompt);
}


