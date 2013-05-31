#if !defined(AFX_BTM_H__B8361100_7FF1_4995_B473_465D909952CD__INCLUDED_)
#define AFX_BTM_H__B8361100_7FF1_4995_B473_465D909952CD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Btm.h : header file
//
enum tableIndex{ 
	TI_SEC_From, 
	TI_OQC_MASS_SEC, 
	TI_OQC_MASS_TPV, 
	TI_QOC_MASS_NIBO,
	TI_OQC_TEST,
	TI_RA
};

/////////////////////////////////////////////////////////////////////////////
// CBtm window

class CBtm : public CButton
{

// Construction
public:
	CBtm();
	BOOL checkKeyBtnText(const CString&);

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBtm)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBtm();

	// Generated message map functions
protected:
	//{{AFX_MSG(CBtm)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BTM_H__B8361100_7FF1_4995_B473_465D909952CD__INCLUDED_)
