// DlgProxy.cpp : implementation file
//

#include "stdafx.h"
#include "MsrItems.h"
#include "DlgProxy.h"
#include "MsrItemsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMsrItemsDlgAutoProxy

IMPLEMENT_DYNCREATE(CMsrItemsDlgAutoProxy, CCmdTarget)

CMsrItemsDlgAutoProxy::CMsrItemsDlgAutoProxy()
{
	EnableAutomation();
	
	// To keep the application running as long as an automation 
	//	object is active, the constructor calls AfxOleLockApp.
	AfxOleLockApp();

	// Get access to the dialog through the application's
	//  main window pointer.  Set the proxy's internal pointer
	//  to point to the dialog, and set the dialog's back pointer to
	//  this proxy.
	ASSERT (AfxGetApp()->m_pMainWnd != NULL);
	ASSERT_VALID (AfxGetApp()->m_pMainWnd);
	ASSERT_KINDOF(CMsrItemsDlg, AfxGetApp()->m_pMainWnd);
	m_pDialog = (CMsrItemsDlg*) AfxGetApp()->m_pMainWnd;
	m_pDialog->m_pAutoProxy = this;
}

CMsrItemsDlgAutoProxy::~CMsrItemsDlgAutoProxy()
{
	// To terminate the application when all objects created with
	// 	with automation, the destructor calls AfxOleUnlockApp.
	//  Among other things, this will destroy the main dialog
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CMsrItemsDlgAutoProxy::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CMsrItemsDlgAutoProxy, CCmdTarget)
	//{{AFX_MSG_MAP(CMsrItemsDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CMsrItemsDlgAutoProxy, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CMsrItemsDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IMsrItems to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {01AEEDB5-825A-4132-8DC6-BE80965170FD}
static const IID IID_IMsrItems =
{ 0x1aeedb5, 0x825a, 0x4132, { 0x8d, 0xc6, 0xbe, 0x80, 0x96, 0x51, 0x70, 0xfd } };

BEGIN_INTERFACE_MAP(CMsrItemsDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CMsrItemsDlgAutoProxy, IID_IMsrItems, Dispatch)
END_INTERFACE_MAP()

// The IMPLEMENT_OLECREATE2 macro is defined in StdAfx.h of this project
// {52E3D8AC-CFD7-468D-A510-A52BCC410D81}
IMPLEMENT_OLECREATE2(CMsrItemsDlgAutoProxy, "MsrItems.Application", 0x52e3d8ac, 0xcfd7, 0x468d, 0xa5, 0x10, 0xa5, 0x2b, 0xcc, 0x41, 0xd, 0x81)

/////////////////////////////////////////////////////////////////////////////
// CMsrItemsDlgAutoProxy message handlers
