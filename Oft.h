#ifndef OLKFILE_H
#define OLKFILE_H

#include "msoutl.h"
//#include <vector>

class olkFile
{
	_OutlApplication olApp;
	_NameSpace       olNs;

// 	_ContactItem     *polItem;  //�p���H
// 	_AppointmentItem *polAppt;  //���|
// 	_MailItem        *polMail;	//�l��

public:
	olkFile()//:polItem(0), polAppt(0), polMail(0)
	{
		COleException e;
		if(!olApp.CreateDispatch("Outlook.Application", &e)) {
			CString str;
			str.Format("CreateDispatch() failed w/error 0x%08lx", e.m_sc);
			AfxMessageBox(str, MB_SETFOREGROUND);
			return;
		}

		_NameSpace olNs(olApp.GetNamespace("MAPI"));
		COleVariant covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);
		olNs.Logon(covOptional, covOptional, covOptional, covOptional);
	};

	~olkFile()
	{
		//AfxMessageBox("All done.", MB_SETFOREGROUND);
		olNs.Logoff();
	};

	void AddContact(LPCTSTR lpszFullName, LPCTSTR Email1Addr, int YearOfBirthDay = 0, int MonthOfBirthDay = 0, int DayOfBirthday = 0, 
		LPCTSTR lpszCompanyName = NULL, LPCTSTR lpszJobTitle = NULL, LPCTSTR lpszHomeTelephone = NULL, LPCTSTR lpszHomeAddress = NULL)
	{
		_ContactItem olItem(olApp.CreateItem(2));  //�p���H

		olItem.SetFullName(lpszFullName);
		olItem.SetEmail1Address(Email1Addr);

		if (YearOfBirthDay*MonthOfBirthDay*DayOfBirthday)
		{
			COleDateTime bdDate;
			bdDate.SetDate(YearOfBirthDay, MonthOfBirthDay, DayOfBirthday);
			olItem.SetBirthday(bdDate);
		}

		if (lpszCompanyName != NULL)
			olItem.SetCompanyName(lpszCompanyName);

		if (lpszJobTitle != NULL)
			olItem.SetJobTitle(lpszJobTitle);

		if (lpszHomeTelephone != NULL)
			olItem.SetHomeTelephoneNumber(lpszHomeTelephone);

		if (lpszHomeAddress != NULL)
			olItem.SetHomeAddress(lpszHomeAddress);

		olItem.Save();
	};

	void AddMeeting(LPCTSTR lpszMeetSubject, DATE DateAndTime, LPCTSTR lpszLocation,long nReminderMinutesBeforeStart = 0 , long nFewMinutes = NULL, LPCTSTR lpszMeetingDescription = NULL)
	{
		//Note:
		//�ثe�ɶ���������
 		//COleDateTime apptDate = COleDateTime::GetCurrentTime();   
 		//olAppt.SetStart((DATE)apptDate + DATE(2.0/(24.0*60.0)));  //+�����

		_AppointmentItem olAppt(olApp.CreateItem(1));

		olAppt.SetSubject(lpszMeetSubject);
		olAppt.SetStart(DateAndTime);
		olAppt.SetLocation(lpszLocation);

		olAppt.SetDuration(nFewMinutes);  //���ʪ���(min)
		olAppt.SetBody(lpszMeetingDescription);

		if (nReminderMinutesBeforeStart != 0)
		{
			olAppt.SetReminderMinutesBeforeStart(nReminderMinutesBeforeStart);
			olAppt.SetReminderSet(TRUE);
		}
		else
			olAppt.SetReminderSet(FALSE);

		olAppt.Save();
	};

	void AddMail(LPCTSTR lpszAddr = NULL, LPCTSTR lpszTitle = NULL)
	{
		_MailItem olMail(olApp.CreateItem(0));

		olMail.SetTo(lpszAddr);
		olMail.SetSubject(lpszTitle);
// 		olMail.GetActions();
// 		olMail.Forward();
		olMail.Display(COleVariant((short)FALSE));
	};

	void SendMail(LPCTSTR lpszAddr, LPCTSTR lpszTitle, LPCTSTR lpszBody)
	{
		_MailItem olMail(olApp.CreateItem(0));
		
		olMail.SetTo(lpszAddr);
		olMail.SetBcc("dwatow@gmail.com");
		olMail.SetBcc("dwatow@hotmail.com");
		olMail.SetSubject(lpszTitle);
		olMail.SetBody(lpszBody);
 		olMail.Send();
	};

};

#endif