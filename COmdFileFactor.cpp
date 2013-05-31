// OmdFile1.cpp: implementation of the COmdFile0 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "COmdFile0.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////////
//��X��J���榡
//oForm()  output form
//iForm()  input  form
//////////////////////////////////////////////////////////////////////////

COmdFileFactor::COmdFileFactor(){};

COmdFileFactor::~COmdFileFactor()
{
    m_dOmd.Empty(); 
    m_dTxt.clear();
};

BOOL COmdFileFactor::Open(LPCTSTR path, CFileException& fx)
{
    if (m_fTxt.Open(path, fx))
        return TRUE;
    else
    {
        ErrorMsg(fx);
        return FALSE;
    }
}

BOOL COmdFileFactor::Save(LPCTSTR path, CFileException& fx)
{
    if (m_fTxt.Save(path, fx))
    {
        return TRUE;
    }
    else
    {
        ErrorMsg(fx);
        m_fTxt.Close();
        return FALSE;
    }
}

const CString COmdFileFactor::GetLine(const int& lineIndex) const//OK
{
    if (lineIndex <= 0)
        return "�X�{���~: �Ѽ� < 1";
    else if (lineIndex > m_dTxt.size())
        return "�W�X�d��";
    else
        return m_dTxt.at((std::vector<CString>::size_type)lineIndex - 1);
}

const CString COmdFileFactor::GetCell(const int& Word, const int& line) const
{
    CString strBuf1;
    CString strBuf2;
    
    strBuf1 = GetLine(line) + '\t';   
    
    if (!strBuf1.IsEmpty())
    {
        int wBegin = 0, wLength = 0;
        
        for (int i = 0; i < Word; ++i)
        {
            wLength = strBuf1.Right(strBuf1.GetLength() - wBegin).Find('\t');
            strBuf2.Format("%s", strBuf1.Mid(wBegin, wLength));
            wBegin += wLength + 1;
        }
    }
    if (strBuf2.IsEmpty())
        strBuf2.Format("");//(���e�ť�)
    return strBuf2;
}

const CString COmdFileFactor::GetCell(const TCHAR& c, const int& n) const
{
    int x;
    x = c - 'A'+1;
    return GetCell(x, n);
}

const CString COmdFileFactor::GetCell(const PTCHAR& c, const int& n) const
{
    CString str;
    str.Format("%s", c);
    
    TCHAR c1;
    TCHAR c2;
    c1 = *(str.Left(1).GetBuffer(str.Left(1).GetLength()));
    c2 = *(str.Right(1).GetBuffer(str.Left(1).GetLength()));
    
    int x;
    x = (c1 - 'A'+1) + (c2 - 'A'+1) + 'Z'+1;//+25�O�]���o�ӳ����O�qAA�}�l��A�ҥH�n���LA~Z
        
    return GetCell(x, n);
}

void COmdFileFactor::ErrorMsg(CFileException& fx) const
{
    //�ҥ~�B�z
    TCHAR buf[255];
    fx.GetErrorMessage(buf, 255);
    CString strPrompt;
    strPrompt.Format("COmdFileFactor::LoadData()\n%s", buf);
    AfxMessageBox(strPrompt);
}
