// DlgProxy.cpp : implementation file
//

#include "stdafx.h"
#include "SelXls.h"
#include "DlgProxy.h"
#include "SelXlsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSelXlsDlgAutoProxy

IMPLEMENT_DYNCREATE(CSelXlsDlgAutoProxy, CCmdTarget)

CSelXlsDlgAutoProxy::CSelXlsDlgAutoProxy()
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
	ASSERT_KINDOF(CSelXlsDlg, AfxGetApp()->m_pMainWnd);
	m_pDialog = (CSelXlsDlg*) AfxGetApp()->m_pMainWnd;
	m_pDialog->m_pAutoProxy = this;
}

CSelXlsDlgAutoProxy::~CSelXlsDlgAutoProxy()
{
	// To terminate the application when all objects created with
	// 	with automation, the destructor calls AfxOleUnlockApp.
	//  Among other things, this will destroy the main dialog
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CSelXlsDlgAutoProxy::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CSelXlsDlgAutoProxy, CCmdTarget)
	//{{AFX_MSG_MAP(CSelXlsDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CSelXlsDlgAutoProxy, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CSelXlsDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_ISelXls to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {6486896F-A660-4656-AC76-FE69C0E55AB1}
static const IID IID_ISelXls =
{ 0x6486896f, 0xa660, 0x4656, { 0xac, 0x76, 0xfe, 0x69, 0xc0, 0xe5, 0x5a, 0xb1 } };

BEGIN_INTERFACE_MAP(CSelXlsDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CSelXlsDlgAutoProxy, IID_ISelXls, Dispatch)
END_INTERFACE_MAP()

// The IMPLEMENT_OLECREATE2 macro is defined in StdAfx.h of this project
// {050F3C79-3BAE-41CF-B8D6-73329511CE66}
IMPLEMENT_OLECREATE2(CSelXlsDlgAutoProxy, "SelXls.Application", 0x50f3c79, 0x3bae, 0x41cf, 0xb8, 0xd6, 0x73, 0x32, 0x95, 0x11, 0xce, 0x66)

/////////////////////////////////////////////////////////////////////////////
// CSelXlsDlgAutoProxy message handlers
