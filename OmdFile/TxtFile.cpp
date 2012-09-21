// Txtfile.cpp: implementation of the CTxtFile class.
//
//////////////////////////////////////////////////////////////////////

#include "stdAfx.h"
#include "Txtfile.h"

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

BOOL CTxtFile::Open(CString path)
{
	m_filepath = path;
	return !m_filepath.IsEmpty();
}

BOOL CTxtFile::Save(CString path)
{
	m_filepath = path;
	return !m_filepath.IsEmpty();
}

//CFileException::m_lOsError

BOOL CTxtFile::LoadData(TxtStrData& txtData)
{
	CStdioFile file;
    CFileException fx;
    if (file.Open(m_filepath, CFile::modeRead | CFile::typeText, &fx))
	{
		FileToMem(file, txtData);
		file.Close();
        return TRUE;  //成功入侵取得資料
	}
	else
    { 
		ErrorMsg(fx);
        file.Close();
        return FALSE;  //失敗
    }
}

BOOL CTxtFile::SaveData(TxtStrData& txtData)
{
	CStdioFile file;
    CFileException fx;
    if (file.Open(m_filepath, CFile::modeCreate | CFile::modeWrite | CFile::typeText, &fx))
	{
		MemToFile(txtData, file);			
		file.Close();
        return TRUE;
	}
    else
    {
		ErrorMsg(fx);
		file.Close();
        return FALSE;
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

void CTxtFile::FileToMem(CStdioFile& file, TxtStrData& txtData)
{
	txtData.clear();
	CString strTemp;
	while (file.ReadString(strTemp))
	{
		strTemp.Format(_T("%s\n"), strTemp);
		txtData.push_back(strTemp);
	}
}

void CTxtFile::MemToFile(TxtStrData& txtData, CStdioFile& file)
{
	if (!txtData.empty())
	{
		CString strTemp;
		for (TxtStrData::iterator it = txtData.begin(); it != txtData.end(); ++it)
			file.WriteString(*it);
	}
}