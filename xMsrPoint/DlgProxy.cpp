// DlgProxy.cpp : implementation file
//

#include "stdafx.h"
#include "xMsrPoint.h"
#include "DlgProxy.h"
#include "xMsrPointDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CXMsrPointDlgAutoProxy

IMPLEMENT_DYNCREATE(CXMsrPointDlgAutoProxy, CCmdTarget)

CXMsrPointDlgAutoProxy::CXMsrPointDlgAutoProxy()
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
	ASSERT_KINDOF(CXMsrPointDlg, AfxGetApp()->m_pMainWnd);
	m_pDialog = (CXMsrPointDlg*) AfxGetApp()->m_pMainWnd;
	m_pDialog->m_pAutoProxy = this;
}

CXMsrPointDlgAutoProxy::~CXMsrPointDlgAutoProxy()
{
	// To terminate the application when all objects created with
	// 	with automation, the destructor calls AfxOleUnlockApp.
	//  Among other things, this will destroy the main dialog
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CXMsrPointDlgAutoProxy::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CXMsrPointDlgAutoProxy, CCmdTarget)
	//{{AFX_MSG_MAP(CXMsrPointDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CXMsrPointDlgAutoProxy, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CXMsrPointDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IXMsrPoint to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {9D8EAAE8-421A-43B3-AAE9-E75B39EE4CA9}
static const IID IID_IXMsrPoint =
{ 0x9d8eaae8, 0x421a, 0x43b3, { 0xaa, 0xe9, 0xe7, 0x5b, 0x39, 0xee, 0x4c, 0xa9 } };

BEGIN_INTERFACE_MAP(CXMsrPointDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CXMsrPointDlgAutoProxy, IID_IXMsrPoint, Dispatch)
END_INTERFACE_MAP()

// The IMPLEMENT_OLECREATE2 macro is defined in StdAfx.h of this project
// {3F6C8654-68A8-4054-88B2-08A70568065B}
IMPLEMENT_OLECREATE2(CXMsrPointDlgAutoProxy, "XMsrPoint.Application", 0x3f6c8654, 0x68a8, 0x4054, 0x88, 0xb2, 0x8, 0xa7, 0x5, 0x68, 0x6, 0x5b)

/////////////////////////////////////////////////////////////////////////////
// CXMsrPointDlgAutoProxy message handlers
