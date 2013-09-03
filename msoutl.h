// Machine generated IDispatch wrapper class(es) created with ClassWizard
/////////////////////////////////////////////////////////////////////////////
// _Application wrapper class

class _OutlApplication : public COleDispatchDriver
{
public:
	_OutlApplication() {}		// Calls COleDispatchDriver default constructor
	_OutlApplication(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	_OutlApplication(const _OutlApplication& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPDISPATCH GetApplication();
	long GetClass();
	LPDISPATCH GetSession();
	LPDISPATCH GetParent();
	LPDISPATCH GetAssistant();
	CString GetName();
	CString GetVersion();
	LPDISPATCH ActiveExplorer();
	LPDISPATCH ActiveInspector();
	LPDISPATCH CreateItem(long ItemType);
	LPDISPATCH CreateItemFromTemplate(LPCTSTR TemplatePath, const VARIANT& InFolder);
	LPDISPATCH CreateObject(LPCTSTR ObjectName);
	LPDISPATCH GetNamespace(LPCTSTR Type);
	void Quit();
	LPDISPATCH GetCOMAddIns();
	LPDISPATCH GetExplorers();
	LPDISPATCH GetInspectors();
	LPDISPATCH GetLanguageSettings();
	CString GetProductCode();
	LPDISPATCH GetAnswerWizard();
	LPDISPATCH ActiveWindow();
	LPDISPATCH CopyFile(LPCTSTR FilePath, LPCTSTR DestFolderPath);
	LPDISPATCH AdvancedSearch(LPCTSTR Scope, const VARIANT& Filter, const VARIANT& SearchSubFolders, const VARIANT& Tag);
	BOOL IsSearchSynchronous(LPCTSTR LookInFolders);
	LPDISPATCH GetReminders();
};
/////////////////////////////////////////////////////////////////////////////
// _NameSpace wrapper class

class _NameSpace : public COleDispatchDriver
{
public:
	_NameSpace() {}		// Calls COleDispatchDriver default constructor
	_NameSpace(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	_NameSpace(const _NameSpace& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPDISPATCH GetApplication();
	long GetClass();
	LPDISPATCH GetSession();
	LPDISPATCH GetParent();
	LPDISPATCH GetCurrentUser();
	LPDISPATCH GetFolders();
	CString GetType();
	LPDISPATCH GetAddressLists();
	LPDISPATCH CreateRecipient(LPCTSTR RecipientName);
	LPDISPATCH GetDefaultFolder(long FolderType);
	LPDISPATCH GetFolderFromID(LPCTSTR EntryIDFolder, const VARIANT& EntryIDStore);
	LPDISPATCH GetItemFromID(LPCTSTR EntryIDItem, const VARIANT& EntryIDStore);
	LPDISPATCH GetRecipientFromID(LPCTSTR EntryID);
	LPDISPATCH GetSharedDefaultFolder(LPDISPATCH Recipient, long FolderType);
	void Logoff();
	void Logon(const VARIANT& Profile, const VARIANT& Password, const VARIANT& ShowDialog, const VARIANT& NewSession);
	LPDISPATCH PickFolder();
	LPDISPATCH GetSyncObjects();
	void AddStore(const VARIANT& Store);
	void RemoveStore(LPDISPATCH Folder);
	BOOL GetOffline();
	void Dial(const VARIANT& ContactItem);
	long GetExchangeConnectionMode();
	void AddStoreEx(const VARIANT& Store, long Type);
};
/////////////////////////////////////////////////////////////////////////////
// _AppointmentItem wrapper class

class _AppointmentItem : public COleDispatchDriver
{
public:
	_AppointmentItem() {}		// Calls COleDispatchDriver default constructor
	_AppointmentItem(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	_AppointmentItem(const _AppointmentItem& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPDISPATCH GetApplication();
	long GetClass();
	LPDISPATCH GetSession();
	LPDISPATCH GetParent();
	LPDISPATCH GetActions();
	LPDISPATCH GetAttachments();
	CString GetBillingInformation();
	void SetBillingInformation(LPCTSTR lpszNewValue);
	CString GetBody();
	void SetBody(LPCTSTR lpszNewValue);
	CString GetCategories();
	void SetCategories(LPCTSTR lpszNewValue);
	CString GetCompanies();
	void SetCompanies(LPCTSTR lpszNewValue);
	CString GetConversationIndex();
	CString GetConversationTopic();
	DATE GetCreationTime();
	CString GetEntryID();
	LPDISPATCH GetFormDescription();
	LPDISPATCH GetGetInspector();
	long GetImportance();
	void SetImportance(long nNewValue);
	DATE GetLastModificationTime();
	CString GetMessageClass();
	void SetMessageClass(LPCTSTR lpszNewValue);
	CString GetMileage();
	void SetMileage(LPCTSTR lpszNewValue);
	BOOL GetNoAging();
	void SetNoAging(BOOL bNewValue);
	long GetOutlookInternalVersion();
	CString GetOutlookVersion();
	BOOL GetSaved();
	long GetSensitivity();
	void SetSensitivity(long nNewValue);
	long GetSize();
	CString GetSubject();
	void SetSubject(LPCTSTR lpszNewValue);
	BOOL GetUnRead();
	void SetUnRead(BOOL bNewValue);
	LPDISPATCH GetUserProperties();
	void Close(long SaveMode);
	LPDISPATCH Copy();
	void Delete();
	void Display(const VARIANT& Modal);
	LPDISPATCH Move(LPDISPATCH DestFldr);
	void PrintOut();
	void Save();
	void SaveAs(LPCTSTR Path, const VARIANT& Type);
	BOOL GetAllDayEvent();
	void SetAllDayEvent(BOOL bNewValue);
	long GetBusyStatus();
	void SetBusyStatus(long nNewValue);
	long GetDuration();
	void SetDuration(long nNewValue);
	DATE GetEnd();
	void SetEnd(DATE newValue);
	BOOL GetIsOnlineMeeting();
	void SetIsOnlineMeeting(BOOL bNewValue);
	BOOL GetIsRecurring();
	CString GetLocation();
	void SetLocation(LPCTSTR lpszNewValue);
	long GetMeetingStatus();
	void SetMeetingStatus(long nNewValue);
	BOOL GetNetMeetingAutoStart();
	void SetNetMeetingAutoStart(BOOL bNewValue);
	CString GetNetMeetingOrganizerAlias();
	void SetNetMeetingOrganizerAlias(LPCTSTR lpszNewValue);
	CString GetNetMeetingServer();
	void SetNetMeetingServer(LPCTSTR lpszNewValue);
	long GetNetMeetingType();
	void SetNetMeetingType(long nNewValue);
	CString GetOptionalAttendees();
	void SetOptionalAttendees(LPCTSTR lpszNewValue);
	CString GetOrganizer();
	LPDISPATCH GetRecipients();
	long GetRecurrenceState();
	long GetReminderMinutesBeforeStart();
	void SetReminderMinutesBeforeStart(long nNewValue);
	BOOL GetReminderOverrideDefault();
	void SetReminderOverrideDefault(BOOL bNewValue);
	BOOL GetReminderPlaySound();
	void SetReminderPlaySound(BOOL bNewValue);
	BOOL GetReminderSet();
	void SetReminderSet(BOOL bNewValue);
	CString GetReminderSoundFile();
	void SetReminderSoundFile(LPCTSTR lpszNewValue);
	DATE GetReplyTime();
	void SetReplyTime(DATE newValue);
	CString GetRequiredAttendees();
	void SetRequiredAttendees(LPCTSTR lpszNewValue);
	CString GetResources();
	void SetResources(LPCTSTR lpszNewValue);
	BOOL GetResponseRequested();
	void SetResponseRequested(BOOL bNewValue);
	long GetResponseStatus();
	DATE GetStart();
	void SetStart(DATE newValue);
	void ClearRecurrencePattern();
	LPDISPATCH ForwardAsVcal();
	LPDISPATCH GetRecurrencePattern();
	LPDISPATCH Respond(long Response, const VARIANT& fNoUI, const VARIANT& fAdditionalTextDialog);
	void Send();
	CString GetNetMeetingDocPathName();
	void SetNetMeetingDocPathName(LPCTSTR lpszNewValue);
	CString GetNetShowURL();
	void SetNetShowURL(LPCTSTR lpszNewValue);
	LPDISPATCH GetLinks();
	BOOL GetConferenceServerAllowExternal();
	void SetConferenceServerAllowExternal(BOOL bNewValue);
	CString GetConferenceServerPassword();
	void SetConferenceServerPassword(LPCTSTR lpszNewValue);
	LPDISPATCH GetItemProperties();
	long GetDownloadState();
	void ShowCategoriesDialog();
	long GetInternetCodepage();
	void SetInternetCodepage(long nNewValue);
	long GetMarkForDownload();
	void SetMarkForDownload(long nNewValue);
	BOOL GetIsConflict();
	CString GetMeetingWorkspaceURL();
	BOOL GetAutoResolvedWinner();
	LPDISPATCH GetConflicts();
};
/////////////////////////////////////////////////////////////////////////////
// _MailItem wrapper class

class _MailItem : public COleDispatchDriver
{
public:
	_MailItem() {}		// Calls COleDispatchDriver default constructor
	_MailItem(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	_MailItem(const _MailItem& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPDISPATCH GetApplication();
	long GetClass();
	LPDISPATCH GetSession();
	LPDISPATCH GetParent();
	LPDISPATCH GetActions();
	LPDISPATCH GetAttachments();
	CString GetBillingInformation();
	void SetBillingInformation(LPCTSTR lpszNewValue);
	CString GetBody();
	void SetBody(LPCTSTR lpszNewValue);
	CString GetCategories();
	void SetCategories(LPCTSTR lpszNewValue);
	CString GetCompanies();
	void SetCompanies(LPCTSTR lpszNewValue);
	CString GetConversationIndex();
	CString GetConversationTopic();
	DATE GetCreationTime();
	CString GetEntryID();
	LPDISPATCH GetFormDescription();
	LPDISPATCH GetGetInspector();
	long GetImportance();
	void SetImportance(long nNewValue);
	DATE GetLastModificationTime();
	CString GetMessageClass();
	void SetMessageClass(LPCTSTR lpszNewValue);
	CString GetMileage();
	void SetMileage(LPCTSTR lpszNewValue);
	BOOL GetNoAging();
	void SetNoAging(BOOL bNewValue);
	long GetOutlookInternalVersion();
	CString GetOutlookVersion();
	BOOL GetSaved();
	long GetSensitivity();
	void SetSensitivity(long nNewValue);
	long GetSize();
	CString GetSubject();
	void SetSubject(LPCTSTR lpszNewValue);
	BOOL GetUnRead();
	void SetUnRead(BOOL bNewValue);
	LPDISPATCH GetUserProperties();
	void Close(long SaveMode);
	LPDISPATCH Copy();
	void Delete();
	void Display(const VARIANT& Modal);
	LPDISPATCH Move(LPDISPATCH DestFldr);
	void PrintOut();
	void Save();
	void SaveAs(LPCTSTR Path, const VARIANT& Type);
	BOOL GetAlternateRecipientAllowed();
	void SetAlternateRecipientAllowed(BOOL bNewValue);
	BOOL GetAutoForwarded();
	void SetAutoForwarded(BOOL bNewValue);
	CString GetBcc();
	void SetBcc(LPCTSTR lpszNewValue);
	CString GetCc();
	void SetCc(LPCTSTR lpszNewValue);
	DATE GetDeferredDeliveryTime();
	void SetDeferredDeliveryTime(DATE newValue);
	BOOL GetDeleteAfterSubmit();
	void SetDeleteAfterSubmit(BOOL bNewValue);
	DATE GetExpiryTime();
	void SetExpiryTime(DATE newValue);
	DATE GetFlagDueBy();
	void SetFlagDueBy(DATE newValue);
	CString GetFlagRequest();
	void SetFlagRequest(LPCTSTR lpszNewValue);
	long GetFlagStatus();
	void SetFlagStatus(long nNewValue);
	CString GetHTMLBody();
	void SetHTMLBody(LPCTSTR lpszNewValue);
	BOOL GetOriginatorDeliveryReportRequested();
	void SetOriginatorDeliveryReportRequested(BOOL bNewValue);
	BOOL GetReadReceiptRequested();
	void SetReadReceiptRequested(BOOL bNewValue);
	CString GetReceivedByEntryID();
	CString GetReceivedByName();
	CString GetReceivedOnBehalfOfEntryID();
	CString GetReceivedOnBehalfOfName();
	DATE GetReceivedTime();
	BOOL GetRecipientReassignmentProhibited();
	void SetRecipientReassignmentProhibited(BOOL bNewValue);
	LPDISPATCH GetRecipients();
	BOOL GetReminderOverrideDefault();
	void SetReminderOverrideDefault(BOOL bNewValue);
	BOOL GetReminderPlaySound();
	void SetReminderPlaySound(BOOL bNewValue);
	BOOL GetReminderSet();
	void SetReminderSet(BOOL bNewValue);
	CString GetReminderSoundFile();
	void SetReminderSoundFile(LPCTSTR lpszNewValue);
	DATE GetReminderTime();
	void SetReminderTime(DATE newValue);
	long GetRemoteStatus();
	void SetRemoteStatus(long nNewValue);
	CString GetReplyRecipientNames();
	LPDISPATCH GetReplyRecipients();
	LPDISPATCH GetSaveSentMessageFolder();
	void SetRefSaveSentMessageFolder(LPDISPATCH newValue);
	CString GetSenderName();
	BOOL GetSent();
	DATE GetSentOn();
	CString GetSentOnBehalfOfName();
	void SetSentOnBehalfOfName(LPCTSTR lpszNewValue);
	BOOL GetSubmitted();
	CString GetTo();
	void SetTo(LPCTSTR lpszNewValue);
	CString GetVotingOptions();
	void SetVotingOptions(LPCTSTR lpszNewValue);
	CString GetVotingResponse();
	void SetVotingResponse(LPCTSTR lpszNewValue);
	void ClearConversationIndex();
	LPDISPATCH Forward();
	LPDISPATCH Reply();
	LPDISPATCH ReplyAll();
	void Send();
	LPDISPATCH GetLinks();
	LPDISPATCH GetItemProperties();
	long GetBodyFormat();
	void SetBodyFormat(long nNewValue);
	long GetDownloadState();
	void ShowCategoriesDialog();
	long GetInternetCodepage();
	void SetInternetCodepage(long nNewValue);
	long GetMarkForDownload();
	void SetMarkForDownload(long nNewValue);
	BOOL GetIsConflict();
	long GetFlagIcon();
	void SetFlagIcon(long nNewValue);
	BOOL GetAutoResolvedWinner();
	LPDISPATCH GetConflicts();
	CString GetSenderEmailAddress();
	CString GetSenderEmailType();
	long GetPermission();
	void SetPermission(long nNewValue);
	long GetPermissionService();
	void SetPermissionService(long nNewValue);
};
/////////////////////////////////////////////////////////////////////////////
// _ContactItem wrapper class

class _ContactItem : public COleDispatchDriver
{
public:
	_ContactItem() {}		// Calls COleDispatchDriver default constructor
	_ContactItem(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	_ContactItem(const _ContactItem& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPDISPATCH GetApplication();
	long GetClass();
	LPDISPATCH GetSession();
	LPDISPATCH GetParent();
	LPDISPATCH GetActions();
	LPDISPATCH GetAttachments();
	CString GetBillingInformation();
	void SetBillingInformation(LPCTSTR lpszNewValue);
	CString GetBody();
	void SetBody(LPCTSTR lpszNewValue);
	CString GetCategories();
	void SetCategories(LPCTSTR lpszNewValue);
	CString GetCompanies();
	void SetCompanies(LPCTSTR lpszNewValue);
	CString GetConversationIndex();
	CString GetConversationTopic();
	DATE GetCreationTime();
	CString GetEntryID();
	LPDISPATCH GetFormDescription();
	LPDISPATCH GetGetInspector();
	long GetImportance();
	void SetImportance(long nNewValue);
	DATE GetLastModificationTime();
	CString GetMessageClass();
	void SetMessageClass(LPCTSTR lpszNewValue);
	CString GetMileage();
	void SetMileage(LPCTSTR lpszNewValue);
	BOOL GetNoAging();
	void SetNoAging(BOOL bNewValue);
	long GetOutlookInternalVersion();
	CString GetOutlookVersion();
	BOOL GetSaved();
	long GetSensitivity();
	void SetSensitivity(long nNewValue);
	long GetSize();
	CString GetSubject();
	void SetSubject(LPCTSTR lpszNewValue);
	BOOL GetUnRead();
	void SetUnRead(BOOL bNewValue);
	LPDISPATCH GetUserProperties();
	void Close(long SaveMode);
	LPDISPATCH Copy();
	void Delete();
	void Display(const VARIANT& Modal);
	LPDISPATCH Move(LPDISPATCH DestFldr);
	void PrintOut();
	void Save();
	void SaveAs(LPCTSTR Path, const VARIANT& Type);
	CString GetAccount();
	void SetAccount(LPCTSTR lpszNewValue);
	DATE GetAnniversary();
	void SetAnniversary(DATE newValue);
	CString GetAssistantName();
	void SetAssistantName(LPCTSTR lpszNewValue);
	CString GetAssistantTelephoneNumber();
	void SetAssistantTelephoneNumber(LPCTSTR lpszNewValue);
	DATE GetBirthday();
	void SetBirthday(DATE newValue);
	CString GetBusiness2TelephoneNumber();
	void SetBusiness2TelephoneNumber(LPCTSTR lpszNewValue);
	CString GetBusinessAddress();
	void SetBusinessAddress(LPCTSTR lpszNewValue);
	CString GetBusinessAddressCity();
	void SetBusinessAddressCity(LPCTSTR lpszNewValue);
	CString GetBusinessAddressCountry();
	void SetBusinessAddressCountry(LPCTSTR lpszNewValue);
	CString GetBusinessAddressPostalCode();
	void SetBusinessAddressPostalCode(LPCTSTR lpszNewValue);
	CString GetBusinessAddressPostOfficeBox();
	void SetBusinessAddressPostOfficeBox(LPCTSTR lpszNewValue);
	CString GetBusinessAddressState();
	void SetBusinessAddressState(LPCTSTR lpszNewValue);
	CString GetBusinessAddressStreet();
	void SetBusinessAddressStreet(LPCTSTR lpszNewValue);
	CString GetBusinessFaxNumber();
	void SetBusinessFaxNumber(LPCTSTR lpszNewValue);
	CString GetBusinessHomePage();
	void SetBusinessHomePage(LPCTSTR lpszNewValue);
	CString GetBusinessTelephoneNumber();
	void SetBusinessTelephoneNumber(LPCTSTR lpszNewValue);
	CString GetCallbackTelephoneNumber();
	void SetCallbackTelephoneNumber(LPCTSTR lpszNewValue);
	CString GetCarTelephoneNumber();
	void SetCarTelephoneNumber(LPCTSTR lpszNewValue);
	CString GetChildren();
	void SetChildren(LPCTSTR lpszNewValue);
	CString GetCompanyAndFullName();
	CString GetCompanyLastFirstNoSpace();
	CString GetCompanyLastFirstSpaceOnly();
	CString GetCompanyMainTelephoneNumber();
	void SetCompanyMainTelephoneNumber(LPCTSTR lpszNewValue);
	CString GetCompanyName();
	void SetCompanyName(LPCTSTR lpszNewValue);
	CString GetComputerNetworkName();
	void SetComputerNetworkName(LPCTSTR lpszNewValue);
	CString GetCustomerID();
	void SetCustomerID(LPCTSTR lpszNewValue);
	CString GetDepartment();
	void SetDepartment(LPCTSTR lpszNewValue);
	CString GetEmail1Address();
	void SetEmail1Address(LPCTSTR lpszNewValue);
	CString GetEmail1AddressType();
	void SetEmail1AddressType(LPCTSTR lpszNewValue);
	CString GetEmail1DisplayName();
	CString GetEmail1EntryID();
	CString GetEmail2Address();
	void SetEmail2Address(LPCTSTR lpszNewValue);
	CString GetEmail2AddressType();
	void SetEmail2AddressType(LPCTSTR lpszNewValue);
	CString GetEmail2DisplayName();
	CString GetEmail2EntryID();
	CString GetEmail3Address();
	void SetEmail3Address(LPCTSTR lpszNewValue);
	CString GetEmail3AddressType();
	void SetEmail3AddressType(LPCTSTR lpszNewValue);
	CString GetEmail3DisplayName();
	CString GetEmail3EntryID();
	CString GetFileAs();
	void SetFileAs(LPCTSTR lpszNewValue);
	CString GetFirstName();
	void SetFirstName(LPCTSTR lpszNewValue);
	CString GetFTPSite();
	void SetFTPSite(LPCTSTR lpszNewValue);
	CString GetFullName();
	void SetFullName(LPCTSTR lpszNewValue);
	CString GetFullNameAndCompany();
	long GetGender();
	void SetGender(long nNewValue);
	CString GetGovernmentIDNumber();
	void SetGovernmentIDNumber(LPCTSTR lpszNewValue);
	CString GetHobby();
	void SetHobby(LPCTSTR lpszNewValue);
	CString GetHome2TelephoneNumber();
	void SetHome2TelephoneNumber(LPCTSTR lpszNewValue);
	CString GetHomeAddress();
	void SetHomeAddress(LPCTSTR lpszNewValue);
	CString GetHomeAddressCity();
	void SetHomeAddressCity(LPCTSTR lpszNewValue);
	CString GetHomeAddressCountry();
	void SetHomeAddressCountry(LPCTSTR lpszNewValue);
	CString GetHomeAddressPostalCode();
	void SetHomeAddressPostalCode(LPCTSTR lpszNewValue);
	CString GetHomeAddressPostOfficeBox();
	void SetHomeAddressPostOfficeBox(LPCTSTR lpszNewValue);
	CString GetHomeAddressState();
	void SetHomeAddressState(LPCTSTR lpszNewValue);
	CString GetHomeAddressStreet();
	void SetHomeAddressStreet(LPCTSTR lpszNewValue);
	CString GetHomeFaxNumber();
	void SetHomeFaxNumber(LPCTSTR lpszNewValue);
	CString GetHomeTelephoneNumber();
	void SetHomeTelephoneNumber(LPCTSTR lpszNewValue);
	CString GetInitials();
	void SetInitials(LPCTSTR lpszNewValue);
	CString GetInternetFreeBusyAddress();
	void SetInternetFreeBusyAddress(LPCTSTR lpszNewValue);
	CString GetISDNNumber();
	void SetISDNNumber(LPCTSTR lpszNewValue);
	CString GetJobTitle();
	void SetJobTitle(LPCTSTR lpszNewValue);
	BOOL GetJournal();
	void SetJournal(BOOL bNewValue);
	CString GetLanguage();
	void SetLanguage(LPCTSTR lpszNewValue);
	CString GetLastFirstAndSuffix();
	CString GetLastFirstNoSpace();
	CString GetLastFirstNoSpaceCompany();
	CString GetLastFirstSpaceOnly();
	CString GetLastFirstSpaceOnlyCompany();
	CString GetLastName();
	void SetLastName(LPCTSTR lpszNewValue);
	CString GetLastNameAndFirstName();
	CString GetMailingAddress();
	void SetMailingAddress(LPCTSTR lpszNewValue);
	CString GetMailingAddressCity();
	void SetMailingAddressCity(LPCTSTR lpszNewValue);
	CString GetMailingAddressCountry();
	void SetMailingAddressCountry(LPCTSTR lpszNewValue);
	CString GetMailingAddressPostalCode();
	void SetMailingAddressPostalCode(LPCTSTR lpszNewValue);
	CString GetMailingAddressPostOfficeBox();
	void SetMailingAddressPostOfficeBox(LPCTSTR lpszNewValue);
	CString GetMailingAddressState();
	void SetMailingAddressState(LPCTSTR lpszNewValue);
	CString GetMailingAddressStreet();
	void SetMailingAddressStreet(LPCTSTR lpszNewValue);
	CString GetManagerName();
	void SetManagerName(LPCTSTR lpszNewValue);
	CString GetMiddleName();
	void SetMiddleName(LPCTSTR lpszNewValue);
	CString GetMobileTelephoneNumber();
	void SetMobileTelephoneNumber(LPCTSTR lpszNewValue);
	CString GetNetMeetingAlias();
	void SetNetMeetingAlias(LPCTSTR lpszNewValue);
	CString GetNetMeetingServer();
	void SetNetMeetingServer(LPCTSTR lpszNewValue);
	CString GetNickName();
	void SetNickName(LPCTSTR lpszNewValue);
	CString GetOfficeLocation();
	void SetOfficeLocation(LPCTSTR lpszNewValue);
	CString GetOrganizationalIDNumber();
	void SetOrganizationalIDNumber(LPCTSTR lpszNewValue);
	CString GetOtherAddress();
	void SetOtherAddress(LPCTSTR lpszNewValue);
	CString GetOtherAddressCity();
	void SetOtherAddressCity(LPCTSTR lpszNewValue);
	CString GetOtherAddressCountry();
	void SetOtherAddressCountry(LPCTSTR lpszNewValue);
	CString GetOtherAddressPostalCode();
	void SetOtherAddressPostalCode(LPCTSTR lpszNewValue);
	CString GetOtherAddressPostOfficeBox();
	void SetOtherAddressPostOfficeBox(LPCTSTR lpszNewValue);
	CString GetOtherAddressState();
	void SetOtherAddressState(LPCTSTR lpszNewValue);
	CString GetOtherAddressStreet();
	void SetOtherAddressStreet(LPCTSTR lpszNewValue);
	CString GetOtherFaxNumber();
	void SetOtherFaxNumber(LPCTSTR lpszNewValue);
	CString GetOtherTelephoneNumber();
	void SetOtherTelephoneNumber(LPCTSTR lpszNewValue);
	CString GetPagerNumber();
	void SetPagerNumber(LPCTSTR lpszNewValue);
	CString GetPersonalHomePage();
	void SetPersonalHomePage(LPCTSTR lpszNewValue);
	CString GetPrimaryTelephoneNumber();
	void SetPrimaryTelephoneNumber(LPCTSTR lpszNewValue);
	CString GetProfession();
	void SetProfession(LPCTSTR lpszNewValue);
	CString GetRadioTelephoneNumber();
	void SetRadioTelephoneNumber(LPCTSTR lpszNewValue);
	CString GetReferredBy();
	void SetReferredBy(LPCTSTR lpszNewValue);
	long GetSelectedMailingAddress();
	void SetSelectedMailingAddress(long nNewValue);
	CString GetSpouse();
	void SetSpouse(LPCTSTR lpszNewValue);
	CString GetSuffix();
	void SetSuffix(LPCTSTR lpszNewValue);
	CString GetTelexNumber();
	void SetTelexNumber(LPCTSTR lpszNewValue);
	CString GetTitle();
	void SetTitle(LPCTSTR lpszNewValue);
	CString GetTTYTDDTelephoneNumber();
	void SetTTYTDDTelephoneNumber(LPCTSTR lpszNewValue);
	CString GetUser1();
	void SetUser1(LPCTSTR lpszNewValue);
	CString GetUser2();
	void SetUser2(LPCTSTR lpszNewValue);
	CString GetUser3();
	void SetUser3(LPCTSTR lpszNewValue);
	CString GetUser4();
	void SetUser4(LPCTSTR lpszNewValue);
	CString GetUserCertificate();
	void SetUserCertificate(LPCTSTR lpszNewValue);
	CString GetWebPage();
	void SetWebPage(LPCTSTR lpszNewValue);
	CString GetYomiCompanyName();
	void SetYomiCompanyName(LPCTSTR lpszNewValue);
	CString GetYomiFirstName();
	void SetYomiFirstName(LPCTSTR lpszNewValue);
	CString GetYomiLastName();
	void SetYomiLastName(LPCTSTR lpszNewValue);
	LPDISPATCH ForwardAsVcard();
	LPDISPATCH GetLinks();
	LPDISPATCH GetItemProperties();
	CString GetLastFirstNoSpaceAndSuffix();
	long GetDownloadState();
	void ShowCategoriesDialog();
	CString GetIMAddress();
	void SetIMAddress(LPCTSTR lpszNewValue);
	long GetMarkForDownload();
	void SetMarkForDownload(long nNewValue);
	void SetEmail1DisplayName(LPCTSTR lpszNewValue);
	void SetEmail2DisplayName(LPCTSTR lpszNewValue);
	void SetEmail3DisplayName(LPCTSTR lpszNewValue);
	BOOL GetIsConflict();
	BOOL GetAutoResolvedWinner();
	LPDISPATCH GetConflicts();
	void AddPicture(LPCTSTR Path);
	void RemovePicture();
	BOOL GetHasPicture();
};
