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

//#include "MsrItems/MsrItemDlg.h"

/////////////////////////////////////////////////////////////////////////////
// CColorEyeIApp:
// See ColorEyeI.cpp for the implementation of this class
//

class CPatternDlg;
class CCaSetupDlg;

class CColorEyeIApp : public CWinApp
{
	CString m_strPathName;
    CPatternDlg *m_pdlgPattern;
	CCaSetupDlg *m_pdlgCaSetup;
public:
	void DelMsrItemDlgSetupFile();
	CString GetPath();
	CString GetPathName();
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
	afx_msg void OnFileOmdtoxls();
	afx_msg void OnMsrForItem();
	afx_msg void OnSetupCa210();
	//}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLOREYEI_H__3F3C8B55_98DA_4864_80E6_452AE80C822F__INCLUDED_)
