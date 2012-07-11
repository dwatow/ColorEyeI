<<<<<<< HEAD
// ColorEyeI.h : main header file for the COLOREYEI application
//

#if !defined(AFX_COLOREYEI_H__3F3C8B55_98DA_4864_80E6_452AE80C822F__INCLUDED_)
#define AFX_COLOREYEI_H__3F3C8B55_98DA_4864_80E6_452AE80C822F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif
#include "resource.h"       // main symbols
#include "xMsrPoint/CA210.h"

/////////////////////////////////////////////////////////////////////////////
// CColorEyeIApp:
// See ColorEyeI.cpp for the implementation of this class
//

class CColorEyeIApp : public CWinApp
{
public:
	CColorEyeIApp();
	~CColorEyeIApp();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColorEyeIApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	COleTemplateServer m_server;
		// Server object for document creation
	//{{AFX_MSG(CColorEyeIApp)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLOREYEI_H__3F3C8B55_98DA_4864_80E6_452AE80C822F__INCLUDED_)
=======
// ColorEyeI.h : main header file for the COLOREYEI application
//

#if !defined(AFX_COLOREYEI_H__3F3C8B55_98DA_4864_80E6_452AE80C822F__INCLUDED_)
#define AFX_COLOREYEI_H__3F3C8B55_98DA_4864_80E6_452AE80C822F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif
#include "resource.h"       // main symbols
#include "xMsrPoint/CA210.h"

/////////////////////////////////////////////////////////////////////////////
// CColorEyeIApp:
// See ColorEyeI.cpp for the implementation of this class
//

class CColorEyeIApp : public CWinApp
{
public:
	CColorEyeIApp();
	~CColorEyeIApp();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColorEyeIApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	COleTemplateServer m_server;
		// Server object for document creation
	//{{AFX_MSG(CColorEyeIApp)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLOREYEI_H__3F3C8B55_98DA_4864_80E6_452AE80C822F__INCLUDED_)
>>>>>>> b5425c75ef070be7770a30afe5b503213bd2584b
