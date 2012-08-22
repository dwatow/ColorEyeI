// SelXls.h : main header file for the SELXLS application
//

#if !defined(AFX_SELXLS_H__998B706D_D507_49EF_BA4E_6AA2914970D8__INCLUDED_)
#define AFX_SELXLS_H__998B706D_D507_49EF_BA4E_6AA2914970D8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSelXlsApp:
// See SelXls.cpp for the implementation of this class
//

class CSelXlsApp : public CWinApp
{
public:
	CSelXlsApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSelXlsApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSelXlsApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SELXLS_H__998B706D_D507_49EF_BA4E_6AA2914970D8__INCLUDED_)
