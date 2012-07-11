// OmdFile.h : main header file for the OMDFILE application
//

#if !defined(AFX_OMDFILE_H__B0A6E5D0_1C28_4988_8746_B6B26971A569__INCLUDED_)
#define AFX_OMDFILE_H__B0A6E5D0_1C28_4988_8746_B6B26971A569__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// COmdFileApp:
// See OmdFile.cpp for the implementation of this class
//

class COmdFileApp : public CWinApp
{
public:
	COmdFileApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COmdFileApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(COmdFileApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OMDFILE_H__B0A6E5D0_1C28_4988_8746_B6B26971A569__INCLUDED_)
