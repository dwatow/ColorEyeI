// Machine generated IDispatch wrapper class(es) created with ClassWizard

#include "stdafx.h"
#include "msoutl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



/////////////////////////////////////////////////////////////////////////////
// _OutlApplication properties

/////////////////////////////////////////////////////////////////////////////
// _OutlApplication operations

LPDISPATCH _OutlApplication::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0xf000, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long _OutlApplication::GetClass()
{
	long result;
	InvokeHelper(0xf00a, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH _OutlApplication::GetSession()
{
	LPDISPATCH result;
	InvokeHelper(0xf00b, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _OutlApplication::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0xf001, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _OutlApplication::GetAssistant()
{
	LPDISPATCH result;
	InvokeHelper(0x114, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

CString _OutlApplication::GetName()
{
	CString result;
	InvokeHelper(0x3001, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

CString _OutlApplication::GetVersion()
{
	CString result;
	InvokeHelper(0x116, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

LPDISPATCH _OutlApplication::ActiveExplorer()
{
	LPDISPATCH result;
	InvokeHelper(0x111, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _OutlApplication::ActiveInspector()
{
	LPDISPATCH result;
	InvokeHelper(0x112, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _OutlApplication::CreateItem(long ItemType)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x10a, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		ItemType);
	return result;
}

LPDISPATCH _OutlApplication::CreateItemFromTemplate(LPCTSTR TemplatePath, const VARIANT& InFolder)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_BSTR VTS_VARIANT;
	InvokeHelper(0x10b, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		TemplatePath, &InFolder);
	return result;
}

LPDISPATCH _OutlApplication::CreateObject(LPCTSTR ObjectName)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x115, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		ObjectName);
	return result;
}

LPDISPATCH _OutlApplication::GetNamespace(LPCTSTR Type)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x110, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Type);
	return result;
}

void _OutlApplication::Quit()
{
	InvokeHelper(0x113, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

LPDISPATCH _OutlApplication::GetCOMAddIns()
{
	LPDISPATCH result;
	InvokeHelper(0x118, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _OutlApplication::GetExplorers()
{
	LPDISPATCH result;
	InvokeHelper(0x119, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _OutlApplication::GetInspectors()
{
	LPDISPATCH result;
	InvokeHelper(0x11a, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _OutlApplication::GetLanguageSettings()
{
	LPDISPATCH result;
	InvokeHelper(0x11b, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

CString _OutlApplication::GetProductCode()
{
	CString result;
	InvokeHelper(0x11c, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

LPDISPATCH _OutlApplication::GetAnswerWizard()
{
	LPDISPATCH result;
	InvokeHelper(0x11d, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _OutlApplication::ActiveWindow()
{
	LPDISPATCH result;
	InvokeHelper(0x11f, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _OutlApplication::CopyFile(LPCTSTR FilePath, LPCTSTR DestFolderPath)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_BSTR VTS_BSTR;
	InvokeHelper(0xfa62, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		FilePath, DestFolderPath);
	return result;
}

LPDISPATCH _OutlApplication::AdvancedSearch(LPCTSTR Scope, const VARIANT& Filter, const VARIANT& SearchSubFolders, const VARIANT& Tag)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_BSTR VTS_VARIANT VTS_VARIANT VTS_VARIANT;
	InvokeHelper(0xfa65, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Scope, &Filter, &SearchSubFolders, &Tag);
	return result;
}

BOOL _OutlApplication::IsSearchSynchronous(LPCTSTR LookInFolders)
{
	BOOL result;
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0xfa6c, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		LookInFolders);
	return result;
}

LPDISPATCH _OutlApplication::GetReminders()
{
	LPDISPATCH result;
	InvokeHelper(0xfa99, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}


/////////////////////////////////////////////////////////////////////////////
// _NameSpace properties

/////////////////////////////////////////////////////////////////////////////
// _NameSpace operations

LPDISPATCH _NameSpace::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0xf000, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long _NameSpace::GetClass()
{
	long result;
	InvokeHelper(0xf00a, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH _NameSpace::GetSession()
{
	LPDISPATCH result;
	InvokeHelper(0xf00b, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _NameSpace::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0xf001, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _NameSpace::GetCurrentUser()
{
	LPDISPATCH result;
	InvokeHelper(0x2101, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _NameSpace::GetFolders()
{
	LPDISPATCH result;
	InvokeHelper(0x2103, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

CString _NameSpace::GetType()
{
	CString result;
	InvokeHelper(0x2104, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

LPDISPATCH _NameSpace::GetAddressLists()
{
	LPDISPATCH result;
	InvokeHelper(0x210d, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _NameSpace::CreateRecipient(LPCTSTR RecipientName)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x210a, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		RecipientName);
	return result;
}

LPDISPATCH _NameSpace::GetDefaultFolder(long FolderType)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x210b, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		FolderType);
	return result;
}

LPDISPATCH _NameSpace::GetFolderFromID(LPCTSTR EntryIDFolder, const VARIANT& EntryIDStore)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_BSTR VTS_VARIANT;
	InvokeHelper(0x2108, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		EntryIDFolder, &EntryIDStore);
	return result;
}

LPDISPATCH _NameSpace::GetItemFromID(LPCTSTR EntryIDItem, const VARIANT& EntryIDStore)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_BSTR VTS_VARIANT;
	InvokeHelper(0x2109, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		EntryIDItem, &EntryIDStore);
	return result;
}

LPDISPATCH _NameSpace::GetRecipientFromID(LPCTSTR EntryID)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x2107, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		EntryID);
	return result;
}

LPDISPATCH _NameSpace::GetSharedDefaultFolder(LPDISPATCH Recipient, long FolderType)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_DISPATCH VTS_I4;
	InvokeHelper(0x210c, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Recipient, FolderType);
	return result;
}

void _NameSpace::Logoff()
{
	InvokeHelper(0x2106, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _NameSpace::Logon(const VARIANT& Profile, const VARIANT& Password, const VARIANT& ShowDialog, const VARIANT& NewSession)
{
	static BYTE parms[] =
		VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT;
	InvokeHelper(0x2105, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 &Profile, &Password, &ShowDialog, &NewSession);
}

LPDISPATCH _NameSpace::PickFolder()
{
	LPDISPATCH result;
	InvokeHelper(0x210e, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _NameSpace::GetSyncObjects()
{
	LPDISPATCH result;
	InvokeHelper(0x2118, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void _NameSpace::AddStore(const VARIANT& Store)
{
	static BYTE parms[] =
		VTS_VARIANT;
	InvokeHelper(0x2119, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 &Store);
}

void _NameSpace::RemoveStore(LPDISPATCH Folder)
{
	static BYTE parms[] =
		VTS_DISPATCH;
	InvokeHelper(0x211a, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Folder);
}

BOOL _NameSpace::GetOffline()
{
	BOOL result;
	InvokeHelper(0xfa4c, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _NameSpace::Dial(const VARIANT& ContactItem)
{
	static BYTE parms[] =
		VTS_VARIANT;
	InvokeHelper(0xfa0d, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 &ContactItem);
}

long _NameSpace::GetExchangeConnectionMode()
{
	long result;
	InvokeHelper(0xfac1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _NameSpace::AddStoreEx(const VARIANT& Store, long Type)
{
	static BYTE parms[] =
		VTS_VARIANT VTS_I4;
	InvokeHelper(0xfac5, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 &Store, Type);
}


/////////////////////////////////////////////////////////////////////////////
// _AppointmentItem properties

/////////////////////////////////////////////////////////////////////////////
// _AppointmentItem operations

LPDISPATCH _AppointmentItem::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0xf000, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long _AppointmentItem::GetClass()
{
	long result;
	InvokeHelper(0xf00a, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH _AppointmentItem::GetSession()
{
	LPDISPATCH result;
	InvokeHelper(0xf00b, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _AppointmentItem::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0xf001, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _AppointmentItem::GetActions()
{
	LPDISPATCH result;
	InvokeHelper(0xf817, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _AppointmentItem::GetAttachments()
{
	LPDISPATCH result;
	InvokeHelper(0xf815, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

CString _AppointmentItem::GetBillingInformation()
{
	CString result;
	InvokeHelper(0x8535, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _AppointmentItem::SetBillingInformation(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x8535, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _AppointmentItem::GetBody()
{
	CString result;
	InvokeHelper(0x9100, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _AppointmentItem::SetBody(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x9100, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _AppointmentItem::GetCategories()
{
	CString result;
	InvokeHelper(0x9001, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _AppointmentItem::SetCategories(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x9001, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _AppointmentItem::GetCompanies()
{
	CString result;
	InvokeHelper(0x853b, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _AppointmentItem::SetCompanies(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x853b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _AppointmentItem::GetConversationIndex()
{
	CString result;
	InvokeHelper(0xfac0, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

CString _AppointmentItem::GetConversationTopic()
{
	CString result;
	InvokeHelper(0x70, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

DATE _AppointmentItem::GetCreationTime()
{
	DATE result;
	InvokeHelper(0x3007, DISPATCH_PROPERTYGET, VT_DATE, (void*)&result, NULL);
	return result;
}

CString _AppointmentItem::GetEntryID()
{
	CString result;
	InvokeHelper(0xf01e, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

LPDISPATCH _AppointmentItem::GetFormDescription()
{
	LPDISPATCH result;
	InvokeHelper(0xf095, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _AppointmentItem::GetGetInspector()
{
	LPDISPATCH result;
	InvokeHelper(0xf03e, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long _AppointmentItem::GetImportance()
{
	long result;
	InvokeHelper(0x17, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _AppointmentItem::SetImportance(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x17, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

DATE _AppointmentItem::GetLastModificationTime()
{
	DATE result;
	InvokeHelper(0x3008, DISPATCH_PROPERTYGET, VT_DATE, (void*)&result, NULL);
	return result;
}

CString _AppointmentItem::GetMessageClass()
{
	CString result;
	InvokeHelper(0x1a, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _AppointmentItem::SetMessageClass(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x1a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _AppointmentItem::GetMileage()
{
	CString result;
	InvokeHelper(0x8534, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _AppointmentItem::SetMileage(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x8534, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

BOOL _AppointmentItem::GetNoAging()
{
	BOOL result;
	InvokeHelper(0x850e, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _AppointmentItem::SetNoAging(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x850e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

long _AppointmentItem::GetOutlookInternalVersion()
{
	long result;
	InvokeHelper(0x8552, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

CString _AppointmentItem::GetOutlookVersion()
{
	CString result;
	InvokeHelper(0x8554, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

BOOL _AppointmentItem::GetSaved()
{
	BOOL result;
	InvokeHelper(0xf0a3, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

long _AppointmentItem::GetSensitivity()
{
	long result;
	InvokeHelper(0x36, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _AppointmentItem::SetSensitivity(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x36, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _AppointmentItem::GetSize()
{
	long result;
	InvokeHelper(0xe08, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

CString _AppointmentItem::GetSubject()
{
	CString result;
	InvokeHelper(0x37, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _AppointmentItem::SetSubject(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x37, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

BOOL _AppointmentItem::GetUnRead()
{
	BOOL result;
	InvokeHelper(0xf01c, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _AppointmentItem::SetUnRead(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0xf01c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

LPDISPATCH _AppointmentItem::GetUserProperties()
{
	LPDISPATCH result;
	InvokeHelper(0xf816, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void _AppointmentItem::Close(long SaveMode)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xf023, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 SaveMode);
}

LPDISPATCH _AppointmentItem::Copy()
{
	LPDISPATCH result;
	InvokeHelper(0xf032, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void _AppointmentItem::Delete()
{
	InvokeHelper(0xf04a, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _AppointmentItem::Display(const VARIANT& Modal)
{
	static BYTE parms[] =
		VTS_VARIANT;
	InvokeHelper(0xf0a6, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 &Modal);
}

LPDISPATCH _AppointmentItem::Move(LPDISPATCH DestFldr)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_DISPATCH;
	InvokeHelper(0xf034, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		DestFldr);
	return result;
}

void _AppointmentItem::PrintOut()
{
	InvokeHelper(0xf033, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _AppointmentItem::Save()
{
	InvokeHelper(0xf048, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _AppointmentItem::SaveAs(LPCTSTR Path, const VARIANT& Type)
{
	static BYTE parms[] =
		VTS_BSTR VTS_VARIANT;
	InvokeHelper(0xf051, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Path, &Type);
}

BOOL _AppointmentItem::GetAllDayEvent()
{
	BOOL result;
	InvokeHelper(0x8215, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _AppointmentItem::SetAllDayEvent(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x8215, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

long _AppointmentItem::GetBusyStatus()
{
	long result;
	InvokeHelper(0x8205, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _AppointmentItem::SetBusyStatus(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x8205, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _AppointmentItem::GetDuration()
{
	long result;
	InvokeHelper(0x8213, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _AppointmentItem::SetDuration(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x8213, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

DATE _AppointmentItem::GetEnd()
{
	DATE result;
	InvokeHelper(0x820e, DISPATCH_PROPERTYGET, VT_DATE, (void*)&result, NULL);
	return result;
}

void _AppointmentItem::SetEnd(DATE newValue)
{
	static BYTE parms[] =
		VTS_DATE;
	InvokeHelper(0x820e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

BOOL _AppointmentItem::GetIsOnlineMeeting()
{
	BOOL result;
	InvokeHelper(0x8240, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _AppointmentItem::SetIsOnlineMeeting(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x8240, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL _AppointmentItem::GetIsRecurring()
{
	BOOL result;
	InvokeHelper(0x8223, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

CString _AppointmentItem::GetLocation()
{
	CString result;
	InvokeHelper(0x8208, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _AppointmentItem::SetLocation(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x8208, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

long _AppointmentItem::GetMeetingStatus()
{
	long result;
	InvokeHelper(0x8217, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _AppointmentItem::SetMeetingStatus(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x8217, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL _AppointmentItem::GetNetMeetingAutoStart()
{
	BOOL result;
	InvokeHelper(0x8244, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _AppointmentItem::SetNetMeetingAutoStart(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x8244, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

CString _AppointmentItem::GetNetMeetingOrganizerAlias()
{
	CString result;
	InvokeHelper(0x8243, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _AppointmentItem::SetNetMeetingOrganizerAlias(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x8243, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _AppointmentItem::GetNetMeetingServer()
{
	CString result;
	InvokeHelper(0x8242, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _AppointmentItem::SetNetMeetingServer(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x8242, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

long _AppointmentItem::GetNetMeetingType()
{
	long result;
	InvokeHelper(0x8241, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _AppointmentItem::SetNetMeetingType(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x8241, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

CString _AppointmentItem::GetOptionalAttendees()
{
	CString result;
	InvokeHelper(0xe03, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _AppointmentItem::SetOptionalAttendees(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0xe03, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _AppointmentItem::GetOrganizer()
{
	CString result;
	InvokeHelper(0x42, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

LPDISPATCH _AppointmentItem::GetRecipients()
{
	LPDISPATCH result;
	InvokeHelper(0xf814, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long _AppointmentItem::GetRecurrenceState()
{
	long result;
	InvokeHelper(0xf545, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long _AppointmentItem::GetReminderMinutesBeforeStart()
{
	long result;
	InvokeHelper(0x8501, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _AppointmentItem::SetReminderMinutesBeforeStart(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x8501, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL _AppointmentItem::GetReminderOverrideDefault()
{
	BOOL result;
	InvokeHelper(0x851c, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _AppointmentItem::SetReminderOverrideDefault(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x851c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL _AppointmentItem::GetReminderPlaySound()
{
	BOOL result;
	InvokeHelper(0x851e, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _AppointmentItem::SetReminderPlaySound(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x851e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL _AppointmentItem::GetReminderSet()
{
	BOOL result;
	InvokeHelper(0x8503, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _AppointmentItem::SetReminderSet(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x8503, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

CString _AppointmentItem::GetReminderSoundFile()
{
	CString result;
	InvokeHelper(0x851f, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _AppointmentItem::SetReminderSoundFile(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x851f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

DATE _AppointmentItem::GetReplyTime()
{
	DATE result;
	InvokeHelper(0x8220, DISPATCH_PROPERTYGET, VT_DATE, (void*)&result, NULL);
	return result;
}

void _AppointmentItem::SetReplyTime(DATE newValue)
{
	static BYTE parms[] =
		VTS_DATE;
	InvokeHelper(0x8220, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

CString _AppointmentItem::GetRequiredAttendees()
{
	CString result;
	InvokeHelper(0xe04, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _AppointmentItem::SetRequiredAttendees(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0xe04, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _AppointmentItem::GetResources()
{
	CString result;
	InvokeHelper(0xe02, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _AppointmentItem::SetResources(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0xe02, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

BOOL _AppointmentItem::GetResponseRequested()
{
	BOOL result;
	InvokeHelper(0x63, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _AppointmentItem::SetResponseRequested(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x63, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

long _AppointmentItem::GetResponseStatus()
{
	long result;
	InvokeHelper(0x8218, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

DATE _AppointmentItem::GetStart()
{
	DATE result;
	InvokeHelper(0x820d, DISPATCH_PROPERTYGET, VT_DATE, (void*)&result, NULL);
	return result;
}

void _AppointmentItem::SetStart(DATE newValue)
{
	static BYTE parms[] =
		VTS_DATE;
	InvokeHelper(0x820d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

void _AppointmentItem::ClearRecurrencePattern()
{
	InvokeHelper(0xf0a5, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

LPDISPATCH _AppointmentItem::ForwardAsVcal()
{
	LPDISPATCH result;
	InvokeHelper(0xf547, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _AppointmentItem::GetRecurrencePattern()
{
	LPDISPATCH result;
	InvokeHelper(0xf0a4, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _AppointmentItem::Respond(long Response, const VARIANT& fNoUI, const VARIANT& fAdditionalTextDialog)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_I4 VTS_VARIANT VTS_VARIANT;
	InvokeHelper(0xf502, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Response, &fNoUI, &fAdditionalTextDialog);
	return result;
}

void _AppointmentItem::Send()
{
	InvokeHelper(0xf075, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

CString _AppointmentItem::GetNetMeetingDocPathName()
{
	CString result;
	InvokeHelper(0x8247, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _AppointmentItem::SetNetMeetingDocPathName(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x8247, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _AppointmentItem::GetNetShowURL()
{
	CString result;
	InvokeHelper(0x8248, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _AppointmentItem::SetNetShowURL(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x8248, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

LPDISPATCH _AppointmentItem::GetLinks()
{
	LPDISPATCH result;
	InvokeHelper(0xf405, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

BOOL _AppointmentItem::GetConferenceServerAllowExternal()
{
	BOOL result;
	InvokeHelper(0x8246, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _AppointmentItem::SetConferenceServerAllowExternal(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x8246, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

CString _AppointmentItem::GetConferenceServerPassword()
{
	CString result;
	InvokeHelper(0x8249, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _AppointmentItem::SetConferenceServerPassword(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x8249, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

LPDISPATCH _AppointmentItem::GetItemProperties()
{
	LPDISPATCH result;
	InvokeHelper(0xfa09, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long _AppointmentItem::GetDownloadState()
{
	long result;
	InvokeHelper(0xfa4d, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _AppointmentItem::ShowCategoriesDialog()
{
	InvokeHelper(0xfa0b, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

long _AppointmentItem::GetInternetCodepage()
{
	long result;
	InvokeHelper(0x3fde, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _AppointmentItem::SetInternetCodepage(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x3fde, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _AppointmentItem::GetMarkForDownload()
{
	long result;
	InvokeHelper(0x8571, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _AppointmentItem::SetMarkForDownload(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x8571, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL _AppointmentItem::GetIsConflict()
{
	BOOL result;
	InvokeHelper(0xfaa4, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

CString _AppointmentItem::GetMeetingWorkspaceURL()
{
	CString result;
	InvokeHelper(0x8209, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

BOOL _AppointmentItem::GetAutoResolvedWinner()
{
	BOOL result;
	InvokeHelper(0xfaba, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

LPDISPATCH _AppointmentItem::GetConflicts()
{
	LPDISPATCH result;
	InvokeHelper(0xfabb, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}


/////////////////////////////////////////////////////////////////////////////
// _MailItem properties

/////////////////////////////////////////////////////////////////////////////
// _MailItem operations

LPDISPATCH _MailItem::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0xf000, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long _MailItem::GetClass()
{
	long result;
	InvokeHelper(0xf00a, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH _MailItem::GetSession()
{
	LPDISPATCH result;
	InvokeHelper(0xf00b, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _MailItem::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0xf001, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _MailItem::GetActions()
{
	LPDISPATCH result;
	InvokeHelper(0xf817, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _MailItem::GetAttachments()
{
	LPDISPATCH result;
	InvokeHelper(0xf815, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

CString _MailItem::GetBillingInformation()
{
	CString result;
	InvokeHelper(0x8535, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _MailItem::SetBillingInformation(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x8535, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _MailItem::GetBody()
{
	CString result;
	InvokeHelper(0x9100, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _MailItem::SetBody(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x9100, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _MailItem::GetCategories()
{
	CString result;
	InvokeHelper(0x9001, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _MailItem::SetCategories(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x9001, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _MailItem::GetCompanies()
{
	CString result;
	InvokeHelper(0x853b, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _MailItem::SetCompanies(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x853b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _MailItem::GetConversationIndex()
{
	CString result;
	InvokeHelper(0xfac0, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

CString _MailItem::GetConversationTopic()
{
	CString result;
	InvokeHelper(0x70, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

DATE _MailItem::GetCreationTime()
{
	DATE result;
	InvokeHelper(0x3007, DISPATCH_PROPERTYGET, VT_DATE, (void*)&result, NULL);
	return result;
}

CString _MailItem::GetEntryID()
{
	CString result;
	InvokeHelper(0xf01e, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

LPDISPATCH _MailItem::GetFormDescription()
{
	LPDISPATCH result;
	InvokeHelper(0xf095, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _MailItem::GetGetInspector()
{
	LPDISPATCH result;
	InvokeHelper(0xf03e, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long _MailItem::GetImportance()
{
	long result;
	InvokeHelper(0x17, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _MailItem::SetImportance(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x17, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

DATE _MailItem::GetLastModificationTime()
{
	DATE result;
	InvokeHelper(0x3008, DISPATCH_PROPERTYGET, VT_DATE, (void*)&result, NULL);
	return result;
}

CString _MailItem::GetMessageClass()
{
	CString result;
	InvokeHelper(0x1a, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _MailItem::SetMessageClass(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x1a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _MailItem::GetMileage()
{
	CString result;
	InvokeHelper(0x8534, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _MailItem::SetMileage(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x8534, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

BOOL _MailItem::GetNoAging()
{
	BOOL result;
	InvokeHelper(0x850e, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _MailItem::SetNoAging(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x850e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

long _MailItem::GetOutlookInternalVersion()
{
	long result;
	InvokeHelper(0x8552, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

CString _MailItem::GetOutlookVersion()
{
	CString result;
	InvokeHelper(0x8554, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

BOOL _MailItem::GetSaved()
{
	BOOL result;
	InvokeHelper(0xf0a3, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

long _MailItem::GetSensitivity()
{
	long result;
	InvokeHelper(0x36, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _MailItem::SetSensitivity(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x36, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _MailItem::GetSize()
{
	long result;
	InvokeHelper(0xe08, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

CString _MailItem::GetSubject()
{
	CString result;
	InvokeHelper(0x37, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _MailItem::SetSubject(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x37, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

BOOL _MailItem::GetUnRead()
{
	BOOL result;
	InvokeHelper(0xf01c, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _MailItem::SetUnRead(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0xf01c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

LPDISPATCH _MailItem::GetUserProperties()
{
	LPDISPATCH result;
	InvokeHelper(0xf816, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void _MailItem::Close(long SaveMode)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xf023, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 SaveMode);
}

LPDISPATCH _MailItem::Copy()
{
	LPDISPATCH result;
	InvokeHelper(0xf032, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void _MailItem::Delete()
{
	InvokeHelper(0xf04a, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _MailItem::Display(const VARIANT& Modal)
{
	static BYTE parms[] =
		VTS_VARIANT;
	InvokeHelper(0xf0a6, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 &Modal);
}

LPDISPATCH _MailItem::Move(LPDISPATCH DestFldr)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_DISPATCH;
	InvokeHelper(0xf034, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		DestFldr);
	return result;
}

void _MailItem::PrintOut()
{
	InvokeHelper(0xf033, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _MailItem::Save()
{
	InvokeHelper(0xf048, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _MailItem::SaveAs(LPCTSTR Path, const VARIANT& Type)
{
	static BYTE parms[] =
		VTS_BSTR VTS_VARIANT;
	InvokeHelper(0xf051, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Path, &Type);
}

BOOL _MailItem::GetAlternateRecipientAllowed()
{
	BOOL result;
	InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _MailItem::SetAlternateRecipientAllowed(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL _MailItem::GetAutoForwarded()
{
	BOOL result;
	InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _MailItem::SetAutoForwarded(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

CString _MailItem::GetBcc()
{
	CString result;
	InvokeHelper(0xe02, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _MailItem::SetBcc(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0xe02, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _MailItem::GetCc()
{
	CString result;
	InvokeHelper(0xe03, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _MailItem::SetCc(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0xe03, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

DATE _MailItem::GetDeferredDeliveryTime()
{
	DATE result;
	InvokeHelper(0xf, DISPATCH_PROPERTYGET, VT_DATE, (void*)&result, NULL);
	return result;
}

void _MailItem::SetDeferredDeliveryTime(DATE newValue)
{
	static BYTE parms[] =
		VTS_DATE;
	InvokeHelper(0xf, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

BOOL _MailItem::GetDeleteAfterSubmit()
{
	BOOL result;
	InvokeHelper(0xe01, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _MailItem::SetDeleteAfterSubmit(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0xe01, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

DATE _MailItem::GetExpiryTime()
{
	DATE result;
	InvokeHelper(0x15, DISPATCH_PROPERTYGET, VT_DATE, (void*)&result, NULL);
	return result;
}

void _MailItem::SetExpiryTime(DATE newValue)
{
	static BYTE parms[] =
		VTS_DATE;
	InvokeHelper(0x15, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

DATE _MailItem::GetFlagDueBy()
{
	DATE result;
	InvokeHelper(0x30, DISPATCH_PROPERTYGET, VT_DATE, (void*)&result, NULL);
	return result;
}

void _MailItem::SetFlagDueBy(DATE newValue)
{
	static BYTE parms[] =
		VTS_DATE;
	InvokeHelper(0x30, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

CString _MailItem::GetFlagRequest()
{
	CString result;
	InvokeHelper(0x8530, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _MailItem::SetFlagRequest(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x8530, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

long _MailItem::GetFlagStatus()
{
	long result;
	InvokeHelper(0x1090, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _MailItem::SetFlagStatus(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x1090, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

CString _MailItem::GetHTMLBody()
{
	CString result;
	InvokeHelper(0xf404, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _MailItem::SetHTMLBody(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0xf404, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

BOOL _MailItem::GetOriginatorDeliveryReportRequested()
{
	BOOL result;
	InvokeHelper(0x23, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _MailItem::SetOriginatorDeliveryReportRequested(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x23, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL _MailItem::GetReadReceiptRequested()
{
	BOOL result;
	InvokeHelper(0x29, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _MailItem::SetReadReceiptRequested(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x29, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

CString _MailItem::GetReceivedByEntryID()
{
	CString result;
	InvokeHelper(0x3f, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

CString _MailItem::GetReceivedByName()
{
	CString result;
	InvokeHelper(0x40, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

CString _MailItem::GetReceivedOnBehalfOfEntryID()
{
	CString result;
	InvokeHelper(0x43, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

CString _MailItem::GetReceivedOnBehalfOfName()
{
	CString result;
	InvokeHelper(0x44, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

DATE _MailItem::GetReceivedTime()
{
	DATE result;
	InvokeHelper(0xe06, DISPATCH_PROPERTYGET, VT_DATE, (void*)&result, NULL);
	return result;
}

BOOL _MailItem::GetRecipientReassignmentProhibited()
{
	BOOL result;
	InvokeHelper(0x2b, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _MailItem::SetRecipientReassignmentProhibited(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x2b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

LPDISPATCH _MailItem::GetRecipients()
{
	LPDISPATCH result;
	InvokeHelper(0xf814, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

BOOL _MailItem::GetReminderOverrideDefault()
{
	BOOL result;
	InvokeHelper(0x851c, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _MailItem::SetReminderOverrideDefault(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x851c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL _MailItem::GetReminderPlaySound()
{
	BOOL result;
	InvokeHelper(0x851e, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _MailItem::SetReminderPlaySound(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x851e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL _MailItem::GetReminderSet()
{
	BOOL result;
	InvokeHelper(0x8503, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _MailItem::SetReminderSet(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x8503, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

CString _MailItem::GetReminderSoundFile()
{
	CString result;
	InvokeHelper(0x851f, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _MailItem::SetReminderSoundFile(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x851f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

DATE _MailItem::GetReminderTime()
{
	DATE result;
	InvokeHelper(0x8502, DISPATCH_PROPERTYGET, VT_DATE, (void*)&result, NULL);
	return result;
}

void _MailItem::SetReminderTime(DATE newValue)
{
	static BYTE parms[] =
		VTS_DATE;
	InvokeHelper(0x8502, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

long _MailItem::GetRemoteStatus()
{
	long result;
	InvokeHelper(0x8511, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _MailItem::SetRemoteStatus(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x8511, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

CString _MailItem::GetReplyRecipientNames()
{
	CString result;
	InvokeHelper(0x50, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

LPDISPATCH _MailItem::GetReplyRecipients()
{
	LPDISPATCH result;
	InvokeHelper(0xf013, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _MailItem::GetSaveSentMessageFolder()
{
	LPDISPATCH result;
	InvokeHelper(0xf401, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void _MailItem::SetRefSaveSentMessageFolder(LPDISPATCH newValue)
{
	static BYTE parms[] =
		VTS_DISPATCH;
	InvokeHelper(0xf401, DISPATCH_PROPERTYPUTREF, VT_EMPTY, NULL, parms,
		 newValue);
}

CString _MailItem::GetSenderName()
{
	CString result;
	InvokeHelper(0xc1a, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

BOOL _MailItem::GetSent()
{
	BOOL result;
	InvokeHelper(0xf402, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

DATE _MailItem::GetSentOn()
{
	DATE result;
	InvokeHelper(0x39, DISPATCH_PROPERTYGET, VT_DATE, (void*)&result, NULL);
	return result;
}

CString _MailItem::GetSentOnBehalfOfName()
{
	CString result;
	InvokeHelper(0x42, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _MailItem::SetSentOnBehalfOfName(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x42, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

BOOL _MailItem::GetSubmitted()
{
	BOOL result;
	InvokeHelper(0xf403, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

CString _MailItem::GetTo()
{
	CString result;
	InvokeHelper(0xe04, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _MailItem::SetTo(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0xe04, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _MailItem::GetVotingOptions()
{
	CString result;
	InvokeHelper(0xf01b, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _MailItem::SetVotingOptions(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0xf01b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _MailItem::GetVotingResponse()
{
	CString result;
	InvokeHelper(0x8524, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _MailItem::SetVotingResponse(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x8524, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

void _MailItem::ClearConversationIndex()
{
	InvokeHelper(0xf822, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

LPDISPATCH _MailItem::Forward()
{
	LPDISPATCH result;
	InvokeHelper(0xf813, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _MailItem::Reply()
{
	LPDISPATCH result;
	InvokeHelper(0xf810, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _MailItem::ReplyAll()
{
	LPDISPATCH result;
	InvokeHelper(0xf811, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void _MailItem::Send()
{
	InvokeHelper(0xf075, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

LPDISPATCH _MailItem::GetLinks()
{
	LPDISPATCH result;
	InvokeHelper(0xf405, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _MailItem::GetItemProperties()
{
	LPDISPATCH result;
	InvokeHelper(0xfa09, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long _MailItem::GetBodyFormat()
{
	long result;
	InvokeHelper(0xfa49, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _MailItem::SetBodyFormat(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xfa49, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _MailItem::GetDownloadState()
{
	long result;
	InvokeHelper(0xfa4d, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _MailItem::ShowCategoriesDialog()
{
	InvokeHelper(0xfa0b, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

long _MailItem::GetInternetCodepage()
{
	long result;
	InvokeHelper(0x3fde, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _MailItem::SetInternetCodepage(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x3fde, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _MailItem::GetMarkForDownload()
{
	long result;
	InvokeHelper(0x8571, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _MailItem::SetMarkForDownload(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x8571, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL _MailItem::GetIsConflict()
{
	BOOL result;
	InvokeHelper(0xfaa4, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

long _MailItem::GetFlagIcon()
{
	long result;
	InvokeHelper(0xfacc, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _MailItem::SetFlagIcon(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xfacc, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL _MailItem::GetAutoResolvedWinner()
{
	BOOL result;
	InvokeHelper(0xfaba, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

LPDISPATCH _MailItem::GetConflicts()
{
	LPDISPATCH result;
	InvokeHelper(0xfabb, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

CString _MailItem::GetSenderEmailAddress()
{
	CString result;
	InvokeHelper(0xc1f, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

CString _MailItem::GetSenderEmailType()
{
	CString result;
	InvokeHelper(0xc1e, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

long _MailItem::GetPermission()
{
	long result;
	InvokeHelper(0xfac6, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _MailItem::SetPermission(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xfac6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _MailItem::GetPermissionService()
{
	long result;
	InvokeHelper(0xfacb, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _MailItem::SetPermissionService(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xfacb, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}


/////////////////////////////////////////////////////////////////////////////
// _ContactItem properties

/////////////////////////////////////////////////////////////////////////////
// _ContactItem operations

LPDISPATCH _ContactItem::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0xf000, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long _ContactItem::GetClass()
{
	long result;
	InvokeHelper(0xf00a, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH _ContactItem::GetSession()
{
	LPDISPATCH result;
	InvokeHelper(0xf00b, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _ContactItem::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0xf001, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _ContactItem::GetActions()
{
	LPDISPATCH result;
	InvokeHelper(0xf817, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _ContactItem::GetAttachments()
{
	LPDISPATCH result;
	InvokeHelper(0xf815, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

CString _ContactItem::GetBillingInformation()
{
	CString result;
	InvokeHelper(0x8535, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetBillingInformation(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x8535, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetBody()
{
	CString result;
	InvokeHelper(0x9100, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetBody(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x9100, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetCategories()
{
	CString result;
	InvokeHelper(0x9001, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetCategories(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x9001, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetCompanies()
{
	CString result;
	InvokeHelper(0x853b, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetCompanies(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x853b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetConversationIndex()
{
	CString result;
	InvokeHelper(0xfac0, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

CString _ContactItem::GetConversationTopic()
{
	CString result;
	InvokeHelper(0x70, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

DATE _ContactItem::GetCreationTime()
{
	DATE result;
	InvokeHelper(0x3007, DISPATCH_PROPERTYGET, VT_DATE, (void*)&result, NULL);
	return result;
}

CString _ContactItem::GetEntryID()
{
	CString result;
	InvokeHelper(0xf01e, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

LPDISPATCH _ContactItem::GetFormDescription()
{
	LPDISPATCH result;
	InvokeHelper(0xf095, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _ContactItem::GetGetInspector()
{
	LPDISPATCH result;
	InvokeHelper(0xf03e, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long _ContactItem::GetImportance()
{
	long result;
	InvokeHelper(0x17, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetImportance(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x17, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

DATE _ContactItem::GetLastModificationTime()
{
	DATE result;
	InvokeHelper(0x3008, DISPATCH_PROPERTYGET, VT_DATE, (void*)&result, NULL);
	return result;
}

CString _ContactItem::GetMessageClass()
{
	CString result;
	InvokeHelper(0x1a, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetMessageClass(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x1a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetMileage()
{
	CString result;
	InvokeHelper(0x8534, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetMileage(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x8534, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

BOOL _ContactItem::GetNoAging()
{
	BOOL result;
	InvokeHelper(0x850e, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetNoAging(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x850e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

long _ContactItem::GetOutlookInternalVersion()
{
	long result;
	InvokeHelper(0x8552, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

CString _ContactItem::GetOutlookVersion()
{
	CString result;
	InvokeHelper(0x8554, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

BOOL _ContactItem::GetSaved()
{
	BOOL result;
	InvokeHelper(0xf0a3, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

long _ContactItem::GetSensitivity()
{
	long result;
	InvokeHelper(0x36, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetSensitivity(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x36, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _ContactItem::GetSize()
{
	long result;
	InvokeHelper(0xe08, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

CString _ContactItem::GetSubject()
{
	CString result;
	InvokeHelper(0x37, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetSubject(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x37, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

BOOL _ContactItem::GetUnRead()
{
	BOOL result;
	InvokeHelper(0xf01c, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetUnRead(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0xf01c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

LPDISPATCH _ContactItem::GetUserProperties()
{
	LPDISPATCH result;
	InvokeHelper(0xf816, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void _ContactItem::Close(long SaveMode)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xf023, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 SaveMode);
}

LPDISPATCH _ContactItem::Copy()
{
	LPDISPATCH result;
	InvokeHelper(0xf032, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void _ContactItem::Delete()
{
	InvokeHelper(0xf04a, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _ContactItem::Display(const VARIANT& Modal)
{
	static BYTE parms[] =
		VTS_VARIANT;
	InvokeHelper(0xf0a6, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 &Modal);
}

LPDISPATCH _ContactItem::Move(LPDISPATCH DestFldr)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_DISPATCH;
	InvokeHelper(0xf034, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		DestFldr);
	return result;
}

void _ContactItem::PrintOut()
{
	InvokeHelper(0xf033, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _ContactItem::Save()
{
	InvokeHelper(0xf048, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _ContactItem::SaveAs(LPCTSTR Path, const VARIANT& Type)
{
	static BYTE parms[] =
		VTS_BSTR VTS_VARIANT;
	InvokeHelper(0xf051, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Path, &Type);
}

CString _ContactItem::GetAccount()
{
	CString result;
	InvokeHelper(0x3a00, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetAccount(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a00, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

DATE _ContactItem::GetAnniversary()
{
	DATE result;
	InvokeHelper(0x3a41, DISPATCH_PROPERTYGET, VT_DATE, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetAnniversary(DATE newValue)
{
	static BYTE parms[] =
		VTS_DATE;
	InvokeHelper(0x3a41, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

CString _ContactItem::GetAssistantName()
{
	CString result;
	InvokeHelper(0x3a30, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetAssistantName(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a30, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetAssistantTelephoneNumber()
{
	CString result;
	InvokeHelper(0x3a2e, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetAssistantTelephoneNumber(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a2e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

DATE _ContactItem::GetBirthday()
{
	DATE result;
	InvokeHelper(0x3a42, DISPATCH_PROPERTYGET, VT_DATE, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetBirthday(DATE newValue)
{
	static BYTE parms[] =
		VTS_DATE;
	InvokeHelper(0x3a42, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

CString _ContactItem::GetBusiness2TelephoneNumber()
{
	CString result;
	InvokeHelper(0x3a1b, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetBusiness2TelephoneNumber(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a1b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetBusinessAddress()
{
	CString result;
	InvokeHelper(0x801b, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetBusinessAddress(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x801b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetBusinessAddressCity()
{
	CString result;
	InvokeHelper(0x8046, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetBusinessAddressCity(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x8046, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetBusinessAddressCountry()
{
	CString result;
	InvokeHelper(0x8049, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetBusinessAddressCountry(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x8049, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetBusinessAddressPostalCode()
{
	CString result;
	InvokeHelper(0x8048, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetBusinessAddressPostalCode(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x8048, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetBusinessAddressPostOfficeBox()
{
	CString result;
	InvokeHelper(0x804a, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetBusinessAddressPostOfficeBox(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x804a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetBusinessAddressState()
{
	CString result;
	InvokeHelper(0x8047, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetBusinessAddressState(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x8047, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetBusinessAddressStreet()
{
	CString result;
	InvokeHelper(0x8045, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetBusinessAddressStreet(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x8045, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetBusinessFaxNumber()
{
	CString result;
	InvokeHelper(0x3a24, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetBusinessFaxNumber(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a24, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetBusinessHomePage()
{
	CString result;
	InvokeHelper(0x3a51, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetBusinessHomePage(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a51, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetBusinessTelephoneNumber()
{
	CString result;
	InvokeHelper(0x3a08, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetBusinessTelephoneNumber(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a08, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetCallbackTelephoneNumber()
{
	CString result;
	InvokeHelper(0x3a02, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetCallbackTelephoneNumber(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a02, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetCarTelephoneNumber()
{
	CString result;
	InvokeHelper(0x3a1e, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetCarTelephoneNumber(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a1e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetChildren()
{
	CString result;
	InvokeHelper(0x800c, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetChildren(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x800c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetCompanyAndFullName()
{
	CString result;
	InvokeHelper(0x8018, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

CString _ContactItem::GetCompanyLastFirstNoSpace()
{
	CString result;
	InvokeHelper(0x8032, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

CString _ContactItem::GetCompanyLastFirstSpaceOnly()
{
	CString result;
	InvokeHelper(0x8033, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

CString _ContactItem::GetCompanyMainTelephoneNumber()
{
	CString result;
	InvokeHelper(0x3a57, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetCompanyMainTelephoneNumber(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a57, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetCompanyName()
{
	CString result;
	InvokeHelper(0x3a16, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetCompanyName(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a16, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetComputerNetworkName()
{
	CString result;
	InvokeHelper(0x3a49, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetComputerNetworkName(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a49, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetCustomerID()
{
	CString result;
	InvokeHelper(0x3a4a, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetCustomerID(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a4a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetDepartment()
{
	CString result;
	InvokeHelper(0x3a18, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetDepartment(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a18, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetEmail1Address()
{
	CString result;
	InvokeHelper(0x8083, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetEmail1Address(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x8083, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetEmail1AddressType()
{
	CString result;
	InvokeHelper(0x8082, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetEmail1AddressType(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x8082, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetEmail1DisplayName()
{
	CString result;
	InvokeHelper(0x8080, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

CString _ContactItem::GetEmail1EntryID()
{
	CString result;
	InvokeHelper(0x8085, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

CString _ContactItem::GetEmail2Address()
{
	CString result;
	InvokeHelper(0x8093, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetEmail2Address(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x8093, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetEmail2AddressType()
{
	CString result;
	InvokeHelper(0x8092, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetEmail2AddressType(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x8092, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetEmail2DisplayName()
{
	CString result;
	InvokeHelper(0x8090, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

CString _ContactItem::GetEmail2EntryID()
{
	CString result;
	InvokeHelper(0x8095, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

CString _ContactItem::GetEmail3Address()
{
	CString result;
	InvokeHelper(0x80a3, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetEmail3Address(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x80a3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetEmail3AddressType()
{
	CString result;
	InvokeHelper(0x80a2, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetEmail3AddressType(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x80a2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetEmail3DisplayName()
{
	CString result;
	InvokeHelper(0x80a0, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

CString _ContactItem::GetEmail3EntryID()
{
	CString result;
	InvokeHelper(0x80a5, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

CString _ContactItem::GetFileAs()
{
	CString result;
	InvokeHelper(0x8005, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetFileAs(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x8005, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetFirstName()
{
	CString result;
	InvokeHelper(0x3a06, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetFirstName(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a06, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetFTPSite()
{
	CString result;
	InvokeHelper(0x3a4c, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetFTPSite(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a4c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetFullName()
{
	CString result;
	InvokeHelper(0x3001, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetFullName(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3001, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetFullNameAndCompany()
{
	CString result;
	InvokeHelper(0x8019, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

long _ContactItem::GetGender()
{
	long result;
	InvokeHelper(0x3a4d, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetGender(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x3a4d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

CString _ContactItem::GetGovernmentIDNumber()
{
	CString result;
	InvokeHelper(0x3a07, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetGovernmentIDNumber(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a07, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetHobby()
{
	CString result;
	InvokeHelper(0x3a43, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetHobby(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a43, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetHome2TelephoneNumber()
{
	CString result;
	InvokeHelper(0x3a2f, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetHome2TelephoneNumber(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a2f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetHomeAddress()
{
	CString result;
	InvokeHelper(0x801a, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetHomeAddress(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x801a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetHomeAddressCity()
{
	CString result;
	InvokeHelper(0x3a59, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetHomeAddressCity(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a59, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetHomeAddressCountry()
{
	CString result;
	InvokeHelper(0x3a5a, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetHomeAddressCountry(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a5a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetHomeAddressPostalCode()
{
	CString result;
	InvokeHelper(0x3a5b, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetHomeAddressPostalCode(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a5b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetHomeAddressPostOfficeBox()
{
	CString result;
	InvokeHelper(0x3a5e, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetHomeAddressPostOfficeBox(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a5e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetHomeAddressState()
{
	CString result;
	InvokeHelper(0x3a5c, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetHomeAddressState(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a5c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetHomeAddressStreet()
{
	CString result;
	InvokeHelper(0x3a5d, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetHomeAddressStreet(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a5d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetHomeFaxNumber()
{
	CString result;
	InvokeHelper(0x3a25, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetHomeFaxNumber(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a25, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetHomeTelephoneNumber()
{
	CString result;
	InvokeHelper(0x3a09, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetHomeTelephoneNumber(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a09, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetInitials()
{
	CString result;
	InvokeHelper(0x3a0a, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetInitials(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a0a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetInternetFreeBusyAddress()
{
	CString result;
	InvokeHelper(0x80d8, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetInternetFreeBusyAddress(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x80d8, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetISDNNumber()
{
	CString result;
	InvokeHelper(0x3a2d, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetISDNNumber(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a2d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetJobTitle()
{
	CString result;
	InvokeHelper(0x3a17, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetJobTitle(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a17, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

BOOL _ContactItem::GetJournal()
{
	BOOL result;
	InvokeHelper(0x8025, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetJournal(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x8025, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

CString _ContactItem::GetLanguage()
{
	CString result;
	InvokeHelper(0x3a0c, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetLanguage(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a0c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetLastFirstAndSuffix()
{
	CString result;
	InvokeHelper(0x8036, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

CString _ContactItem::GetLastFirstNoSpace()
{
	CString result;
	InvokeHelper(0x8030, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

CString _ContactItem::GetLastFirstNoSpaceCompany()
{
	CString result;
	InvokeHelper(0x8034, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

CString _ContactItem::GetLastFirstSpaceOnly()
{
	CString result;
	InvokeHelper(0x8031, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

CString _ContactItem::GetLastFirstSpaceOnlyCompany()
{
	CString result;
	InvokeHelper(0x8035, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

CString _ContactItem::GetLastName()
{
	CString result;
	InvokeHelper(0x3a11, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetLastName(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a11, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetLastNameAndFirstName()
{
	CString result;
	InvokeHelper(0x8017, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

CString _ContactItem::GetMailingAddress()
{
	CString result;
	InvokeHelper(0x3a15, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetMailingAddress(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a15, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetMailingAddressCity()
{
	CString result;
	InvokeHelper(0x3a27, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetMailingAddressCity(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a27, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetMailingAddressCountry()
{
	CString result;
	InvokeHelper(0x3a26, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetMailingAddressCountry(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a26, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetMailingAddressPostalCode()
{
	CString result;
	InvokeHelper(0x3a2a, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetMailingAddressPostalCode(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a2a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetMailingAddressPostOfficeBox()
{
	CString result;
	InvokeHelper(0x3a2b, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetMailingAddressPostOfficeBox(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a2b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetMailingAddressState()
{
	CString result;
	InvokeHelper(0x3a28, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetMailingAddressState(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a28, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetMailingAddressStreet()
{
	CString result;
	InvokeHelper(0x3a29, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetMailingAddressStreet(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a29, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetManagerName()
{
	CString result;
	InvokeHelper(0x3a4e, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetManagerName(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a4e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetMiddleName()
{
	CString result;
	InvokeHelper(0x3a44, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetMiddleName(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a44, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetMobileTelephoneNumber()
{
	CString result;
	InvokeHelper(0x3a1c, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetMobileTelephoneNumber(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a1c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetNetMeetingAlias()
{
	CString result;
	InvokeHelper(0x805f, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetNetMeetingAlias(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x805f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetNetMeetingServer()
{
	CString result;
	InvokeHelper(0x8060, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetNetMeetingServer(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x8060, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetNickName()
{
	CString result;
	InvokeHelper(0x3a4f, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetNickName(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a4f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetOfficeLocation()
{
	CString result;
	InvokeHelper(0x3a19, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetOfficeLocation(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a19, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetOrganizationalIDNumber()
{
	CString result;
	InvokeHelper(0x3a10, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetOrganizationalIDNumber(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a10, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetOtherAddress()
{
	CString result;
	InvokeHelper(0x801c, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetOtherAddress(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x801c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetOtherAddressCity()
{
	CString result;
	InvokeHelper(0x3a5f, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetOtherAddressCity(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a5f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetOtherAddressCountry()
{
	CString result;
	InvokeHelper(0x3a60, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetOtherAddressCountry(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a60, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetOtherAddressPostalCode()
{
	CString result;
	InvokeHelper(0x3a61, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetOtherAddressPostalCode(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a61, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetOtherAddressPostOfficeBox()
{
	CString result;
	InvokeHelper(0x3a64, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetOtherAddressPostOfficeBox(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a64, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetOtherAddressState()
{
	CString result;
	InvokeHelper(0x3a62, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetOtherAddressState(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a62, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetOtherAddressStreet()
{
	CString result;
	InvokeHelper(0x3a63, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetOtherAddressStreet(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a63, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetOtherFaxNumber()
{
	CString result;
	InvokeHelper(0x3a23, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetOtherFaxNumber(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a23, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetOtherTelephoneNumber()
{
	CString result;
	InvokeHelper(0x3a1f, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetOtherTelephoneNumber(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a1f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetPagerNumber()
{
	CString result;
	InvokeHelper(0x3a21, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetPagerNumber(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a21, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetPersonalHomePage()
{
	CString result;
	InvokeHelper(0x3a50, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetPersonalHomePage(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a50, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetPrimaryTelephoneNumber()
{
	CString result;
	InvokeHelper(0x3a1a, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetPrimaryTelephoneNumber(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a1a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetProfession()
{
	CString result;
	InvokeHelper(0x3a46, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetProfession(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a46, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetRadioTelephoneNumber()
{
	CString result;
	InvokeHelper(0x3a1d, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetRadioTelephoneNumber(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a1d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetReferredBy()
{
	CString result;
	InvokeHelper(0x3a47, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetReferredBy(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a47, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

long _ContactItem::GetSelectedMailingAddress()
{
	long result;
	InvokeHelper(0x8022, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetSelectedMailingAddress(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x8022, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

CString _ContactItem::GetSpouse()
{
	CString result;
	InvokeHelper(0x3a48, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetSpouse(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a48, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetSuffix()
{
	CString result;
	InvokeHelper(0x3a05, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetSuffix(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a05, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetTelexNumber()
{
	CString result;
	InvokeHelper(0x3a2c, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetTelexNumber(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a2c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetTitle()
{
	CString result;
	InvokeHelper(0x3a45, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetTitle(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a45, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetTTYTDDTelephoneNumber()
{
	CString result;
	InvokeHelper(0x3a4b, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetTTYTDDTelephoneNumber(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3a4b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetUser1()
{
	CString result;
	InvokeHelper(0x804f, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetUser1(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x804f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetUser2()
{
	CString result;
	InvokeHelper(0x8050, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetUser2(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x8050, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetUser3()
{
	CString result;
	InvokeHelper(0x8051, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetUser3(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x8051, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetUser4()
{
	CString result;
	InvokeHelper(0x8052, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetUser4(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x8052, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetUserCertificate()
{
	CString result;
	InvokeHelper(0x8016, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetUserCertificate(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x8016, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetWebPage()
{
	CString result;
	InvokeHelper(0x802b, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetWebPage(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x802b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetYomiCompanyName()
{
	CString result;
	InvokeHelper(0x802e, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetYomiCompanyName(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x802e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetYomiFirstName()
{
	CString result;
	InvokeHelper(0x802c, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetYomiFirstName(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x802c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ContactItem::GetYomiLastName()
{
	CString result;
	InvokeHelper(0x802d, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetYomiLastName(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x802d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

LPDISPATCH _ContactItem::ForwardAsVcard()
{
	LPDISPATCH result;
	InvokeHelper(0xf8a1, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _ContactItem::GetLinks()
{
	LPDISPATCH result;
	InvokeHelper(0xf405, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _ContactItem::GetItemProperties()
{
	LPDISPATCH result;
	InvokeHelper(0xfa09, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

CString _ContactItem::GetLastFirstNoSpaceAndSuffix()
{
	CString result;
	InvokeHelper(0x8038, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

long _ContactItem::GetDownloadState()
{
	long result;
	InvokeHelper(0xfa4d, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _ContactItem::ShowCategoriesDialog()
{
	InvokeHelper(0xfa0b, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

CString _ContactItem::GetIMAddress()
{
	CString result;
	InvokeHelper(0x8062, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetIMAddress(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x8062, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

long _ContactItem::GetMarkForDownload()
{
	long result;
	InvokeHelper(0x8571, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _ContactItem::SetMarkForDownload(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x8571, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

void _ContactItem::SetEmail1DisplayName(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x8080, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

void _ContactItem::SetEmail2DisplayName(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x8090, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

void _ContactItem::SetEmail3DisplayName(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x80a0, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

BOOL _ContactItem::GetIsConflict()
{
	BOOL result;
	InvokeHelper(0xfaa4, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

BOOL _ContactItem::GetAutoResolvedWinner()
{
	BOOL result;
	InvokeHelper(0xfaba, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

LPDISPATCH _ContactItem::GetConflicts()
{
	LPDISPATCH result;
	InvokeHelper(0xfabb, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void _ContactItem::AddPicture(LPCTSTR Path)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0xfabd, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Path);
}

void _ContactItem::RemovePicture()
{
	InvokeHelper(0xfabe, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

BOOL _ContactItem::GetHasPicture()
{
	BOOL result;
	InvokeHelper(0xfabf, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}
