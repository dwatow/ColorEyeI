// StrList.cpp : implementation file
//

#include "stdafx.h"
#include "ColorEyeI.h"
#include "StrList.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStrList

CStrList::CStrList()
{
}

CStrList::~CStrList()
{
}


BEGIN_MESSAGE_MAP(CStrList, CListBox)
	//{{AFX_MSG_MAP(CStrList)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStrList message handlers

void CStrList::DelSelItems()
{
	int nCount = GetSelCount();
	int* buffer = new int[nCount];
	memset(buffer, -1, sizeof(int)*nCount);
	
	GetSelItems(nCount, buffer);
	
	for(int i=nCount-1; i>=0; i--)
	{
		DeleteString(buffer[i]);
	}
	delete[] buffer;
}