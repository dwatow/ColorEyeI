#if !defined(AFX_STRLIST_H__EF983321_25FA_4CB0_83C9_F8E9FDE7B58A__INCLUDED_)
#define AFX_STRLIST_H__EF983321_25FA_4CB0_83C9_F8E9FDE7B58A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StrList.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStrList window

class CStrList : public CListBox
{
// Construction
public:
	CStrList();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStrList)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CStrList();

	// Generated message map functions
protected:
	//{{AFX_MSG(CStrList)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
private:
	void DelSelItems();
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STRLIST_H__EF983321_25FA_4CB0_83C9_F8E9FDE7B58A__INCLUDED_)
