// xMsrPoint.h : main header file for the XMSRPOINT application
//

#if !defined(AFX_XMSRPOINT_H__DFE8E74C_E836_4F0A_80AD_46E49238E82C__INCLUDED_)
#define AFX_XMSRPOINT_H__DFE8E74C_E836_4F0A_80AD_46E49238E82C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

// #include <vector>
// #include <cmath>
// #include <vector>
#include "resource.h"		// main symbols
// #include "DlgProxy.h"
// #include "CA210.h"
// #include "Circle.h"	// Added by ClassView
// #include "comdef.h"
// #include "xMsrPointDlg.h"


/////////////////////////////////////////////////////////////////////////////
// CXMsrPointApp:
// See xMsrPoint.cpp for the implementation of this class
//

class CXMsrPointApp : public CWinApp
{
public:
	CXMsrPointApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CXMsrPointApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CXMsrPointApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XMSRPOINT_H__DFE8E74C_E836_4F0A_80AD_46E49238E82C__INCLUDED_)
