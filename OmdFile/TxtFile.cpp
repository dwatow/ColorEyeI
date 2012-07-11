<<<<<<< HEAD
// TxtFile.cpp: implementation of the CTxtFile class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TxtFile.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTxtFile::CTxtFile()
{
	vStr.clear();
	m_LineNum = 0;
}

CTxtFile::~CTxtFile()
{

}

CString CTxtFile::GetLine(UINT LineNum)
{
	if (LineNum <= 0)
		return "出現錯誤: 參數 < 1";
	else if (LineNum > m_LineNum)
		return "超出範圍";
	else
		return vStr.at((std::vector<CString>::size_type)LineNum - 1);
}

std::vector<CString>::size_type CTxtFile::SetLine(CString& LineStr)
{
	LineStr = LineStr + '\n'; 
	vStr.push_back(LineStr);
	m_LineNum = vStr.size();
	LineStr.Format("");
	return vStr.size();
}

void CTxtFile::Clear()
{
	vStr.clear();
}

UINT CTxtFile::GetLineNum()
{
	return m_LineNum;
}

CString CTxtFile::GetCell(UINT Word, UINT Line)
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

CString CTxtFile::GetCell(TCHAR c, UINT n)
{
	UINT x;
	x = c - 'A' + 1;
	return GetCell(x, n);
}

CString CTxtFile::GetCell(PTCHAR c, UINT n)
{
	CString str;
	str.Format("%s", c);

	TCHAR c1;
	TCHAR c2;
	c1 = *(str.Left(1).GetBuffer(str.Left(1).GetLength()));
	c2 = *(str.Right(1).GetBuffer(str.Left(1).GetLength()));

	UINT x;
	x = (c1 - 'A' + 1) + (c2 - 'A' + 1) + 25;//+25是因為這個部份是從AA開始算，所以要跳過A~Z
	
// 	CString temp;
// 	temp.Format("str = %s\nc1 = %c, c2 = %c", str, c1, c2);
// 	AfxMessageBox(temp);

//  	temp.Format("str = %s\nc1 = %c\tc2 = %c\nx1+x2 = %d", str, c1, c2, x1+x2+25);
//  	AfxMessageBox(temp);

	return GetCell(x, n);
}

BOOL CTxtFile::Open(CString path)
{
	CStdioFile file;
	CFileException fx;
	
	if (!file.Open(path, CFile::modeRead | CFile::typeText, &fx))
	{
		//例外處理
		TCHAR buf[255];
		fx.GetErrorMessage(buf, 255);
		CString strPrompt(buf);
		AfxMessageBox(strPrompt);
		file.Close();
		return FALSE;
	}
	else
	{
		LoadData(file);
		file.Close();
		return TRUE;
	}
}

BOOL CTxtFile::Save(CString path)
{
	CStdioFile file;
	CFileException fx;
	
	if (!file.Open(path, CFile::modeCreate | CFile::modeWrite | CFile::typeText, &fx))
	{
		TCHAR buf[255];
		fx.GetErrorMessage(buf, 255);
		CString strPrompt(buf);
		AfxMessageBox(strPrompt);
		file.Close();
		return FALSE;
	}
	else
	{
		SaveData(file);
		file.Close();
		return TRUE;
	}
}

//LoadData 將一篇文，存成vector<CString)
//SaveData 將vector<CString)，存成一篇文

BOOL CTxtFile::LoadData(CStdioFile &infile)
{
	vStr.clear();//reset vStr
	CString strTemp;
	while (infile.ReadString(strTemp))
		vStr.push_back(strTemp);		
	
	m_LineNum = vStr.size();
	return (vStr.empty()) ? FALSE : TRUE;
}

BOOL CTxtFile::SaveData(CStdioFile &infile)
{
	if (!vStr.empty())
		for (std::vector<CString>::iterator it = vStr.begin(); it != vStr.end(); ++it)
			infile.WriteString(it->GetBuffer(0));
		
		m_LineNum = vStr.size();
		
		return (vStr.begin() == vStr.end()) ? FALSE : TRUE;
=======
// TxtFile.cpp: implementation of the CTxtFile class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TxtFile.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTxtFile::CTxtFile()
{
	vStr.clear();
	m_LineNum = 0;
}

CTxtFile::~CTxtFile()
{

}

CString CTxtFile::GetLine(UINT LineNum)
{
	if (LineNum <= 0)
		return "出現錯誤: 參數 < 1";
	else if (LineNum > m_LineNum)
		return "超出範圍";
	else
		return vStr.at((std::vector<CString>::size_type)LineNum - 1);
}

std::vector<CString>::size_type CTxtFile::SetLine(CString& LineStr)
{
	LineStr = LineStr + '\n'; 
	vStr.push_back(LineStr);
	m_LineNum = vStr.size();
	LineStr.Format("");
	return vStr.size();
}

void CTxtFile::Clear()
{
	vStr.clear();
}

UINT CTxtFile::GetLineNum()
{
	return m_LineNum;
}

CString CTxtFile::GetCell(UINT Word, UINT Line)
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

CString CTxtFile::GetCell(TCHAR c, UINT n)
{
	UINT x;
	x = c - 'A' + 1;
	return GetCell(x, n);
}

CString CTxtFile::GetCell(PTCHAR c, UINT n)
{
	CString str;
	str.Format("%s", c);

	TCHAR c1;
	TCHAR c2;
	c1 = *(str.Left(1).GetBuffer(str.Left(1).GetLength()));
	c2 = *(str.Right(1).GetBuffer(str.Left(1).GetLength()));

	UINT x;
	x = (c1 - 'A' + 1) + (c2 - 'A' + 1) + 25;//+25是因為這個部份是從AA開始算，所以要跳過A~Z
	
// 	CString temp;
// 	temp.Format("str = %s\nc1 = %c, c2 = %c", str, c1, c2);
// 	AfxMessageBox(temp);

//  	temp.Format("str = %s\nc1 = %c\tc2 = %c\nx1+x2 = %d", str, c1, c2, x1+x2+25);
//  	AfxMessageBox(temp);

	return GetCell(x, n);
}

BOOL CTxtFile::Open(CString path)
{
	CStdioFile file;
	CFileException fx;
	
	if (!file.Open(path, CFile::modeRead | CFile::typeText, &fx))
	{
		//例外處理
		TCHAR buf[255];
		fx.GetErrorMessage(buf, 255);
		CString strPrompt(buf);
		AfxMessageBox(strPrompt);
		file.Close();
		return FALSE;
	}
	else
	{
		LoadData(file);
		file.Close();
		return TRUE;
	}
}

BOOL CTxtFile::Save(CString path)
{
	CStdioFile file;
	CFileException fx;
	
	if (!file.Open(path, CFile::modeCreate | CFile::modeWrite | CFile::typeText, &fx))
	{
		TCHAR buf[255];
		fx.GetErrorMessage(buf, 255);
		CString strPrompt(buf);
		AfxMessageBox(strPrompt);
		file.Close();
		return FALSE;
	}
	else
	{
		SaveData(file);
		file.Close();
		return TRUE;
	}
}

//LoadData 將一篇文，存成vector<CString)
//SaveData 將vector<CString)，存成一篇文

BOOL CTxtFile::LoadData(CStdioFile &infile)
{
	vStr.clear();//reset vStr
	CString strTemp;
	while (infile.ReadString(strTemp))
		vStr.push_back(strTemp);		
	
	m_LineNum = vStr.size();
	return (vStr.empty()) ? FALSE : TRUE;
}

BOOL CTxtFile::SaveData(CStdioFile &infile)
{
	if (!vStr.empty())
		for (std::vector<CString>::iterator it = vStr.begin(); it != vStr.end(); ++it)
			infile.WriteString(it->GetBuffer(0));
		
		m_LineNum = vStr.size();
		
		return (vStr.begin() == vStr.end()) ? FALSE : TRUE;
>>>>>>> b5425c75ef070be7770a30afe5b503213bd2584b
}