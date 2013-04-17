#if !defined(AFX_PATTERNDLG_H__BF2314F4_1C6C_45B2_9897_554500DEADD9__INCLUDED_)
#define AFX_PATTERNDLG_H__BF2314F4_1C6C_45B2_9897_554500DEADD9__INCLUDED_

#include "CircleArc.h"    // Added by ClassView
#include "CA210.h"
#include "MsrItemDlg.h"
#include "CColorRef.h"

#include <cmath>
#include <vector>

enum initType{  MsrForItem = 0, MsrForPoint, MsrForForm  };

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PatternDlg.h : header file
//
/////////////////////////////////////////////////////////////////////////////
// CPatternDlg dialog

class CPatternDlg : public CDialog
{
// Construction
public:
    CPatternDlg(const initType& it, CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPatternDlg)
	enum { IDD = IDD_PATTERN_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPatternDlg)
	public:
    virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPatternDlg)
    virtual BOOL OnInitDialog();
    afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
    afx_msg void OnPaint();
    afx_msg void OnTimer(UINT nIDevent);
    afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	initType InitDataType;
    RNA m_RNA;
    
    //��ʥi��
    BOOL c_bStatusBar;
	
    //�۰ʨϥΪ��Ѽ�
    BOOL c_bMsrBegin;
    BOOL c_bMsrEnd;
    BOOL c_bMsrEndnMsred;
    BOOL c_bRunMsrAI;
    BOOL c_bUnCntCA210;
	
    std::vector<Cartridge2>::iterator m_itor;
    std::vector<Cartridge2>::iterator m_BeginItor;
    std::vector<Cartridge2>::iterator m_EndItor;
	
    CBrush   m_BkBrush;
    ColorRef m_BkColor;   //�I����
	
    Circle m_Goal;        //�ؼа��
    Ca210* m_pCA210;
	
private:
    void initLCMSize() const;
    void initCa210();
    void initDataDlgType() const;  //Call SelMsrItem
    void initDocument();
	
    void trigger();
    void checkMsrLimit();
    void setBkColor(const ColorRef&);
    const CaState recoil();
	void msrKernel();
	
    void eventGoPrvsGoal();
    BOOL eventGoNextGoal();
    void eventSwCntCa210();
    void eventRunMsrAi(BOOL isRun = 2);
    UINT eventCatchMsrValue();
    void eventExitDialog();
public:
    void LoadedCartridge(); //�u�X
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PATTERNDLG_H__BF2314F4_1C6C_45B2_9897_554500DEADD9__INCLUDED_)