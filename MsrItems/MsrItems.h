// MsrItems.h : main header file for the MSRITEMS application
//

#if !defined(AFX_MSRITEMS_H__41873360_1F5E_4669_B8FE_DE1023C94FB1__INCLUDED_)
#define AFX_MSRITEMS_H__41873360_1F5E_4669_B8FE_DE1023C94FB1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
    #error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"        // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMsrItemsApp:
// See MsrItems.cpp for the implementation of this class
//

class CMsrItemsApp : public CWinApp
{
public:
    CMsrItemsApp();

// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CMsrItemsApp)
    public:
    virtual BOOL InitInstance();
    //}}AFX_VIRTUAL

// Implementation

    //{{AFX_MSG(CMsrItemsApp)
        // NOTE - the ClassWizard will add and remove member functions here.
        //    DO NOT EDIT what you see in these blocks of generated code !
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MSRITEMS_H__41873360_1F5E_4669_B8FE_DE1023C94FB1__INCLUDED_)
