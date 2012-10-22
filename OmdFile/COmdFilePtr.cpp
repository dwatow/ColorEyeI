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

COmdFilePtr::COmdFilePtr():
m_PnlID(""), m_MsrDvc(""), m_Prb(""), m_CHID("")
{};

COmdFilePtr::~COmdFilePtr()
{
    m_dOmd.Empty(); 
	m_dTxt.clear();
};

BOOL COmdFilePtr::Open(CString path, CFileException& fx)
{
	if (m_fTxt.Open(path, fx))
		return TRUE;
	else
	{
		ErrorMsg(fx);
		return FALSE;
	}
}

BOOL COmdFilePtr::Save(CString path, CFileException& fx)
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

CString COmdFilePtr::GetLine(UINT LineNum)
{
    if (LineNum <= 0)
        return "�X�{���~: �Ѽ� < 1";
    else if (LineNum > m_dTxt.size())
        return "�W�X�d��";
    else
        return m_dTxt.at((std::vector<CString>::size_type)LineNum - 1);
}

CString COmdFilePtr::GetCell(UINT Word, UINT Line)
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
        strBuf2.Format("");//(���e�ť�)
    return strBuf2;
}

CString COmdFilePtr::GetCell(TCHAR c, UINT n)
{
    UINT x;
    x = c - 'A' + 1;
    return GetCell(x, n);
}

CString COmdFilePtr::GetCell(PTCHAR c, UINT n)
{
    CString str;
    str.Format("%s", c);
	
    TCHAR c1;
    TCHAR c2;
    c1 = *(str.Left(1).GetBuffer(str.Left(1).GetLength()));
    c2 = *(str.Right(1).GetBuffer(str.Left(1).GetLength()));
	
    UINT x;
    x = (c1 - 'A' + 1) + (c2 - 'A' + 1) + 25;//+25�O�]���o�ӳ����O�qAA�}�l��A�ҥH�n���LA~Z
    	
    return GetCell(x, n);
}

void COmdFilePtr::ErrorMsg(CFileException& fx)
{
	//�ҥ~�B�z
	TCHAR buf[255];
	fx.GetErrorMessage(buf, 255);
	CString strPrompt;
	strPrompt.Format("COmdFilePtr::LoadData()\n%s", buf);
	AfxMessageBox(strPrompt);
}
