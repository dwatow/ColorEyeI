#if !defined(AFX_PATTERNDLG_H__20F9D625_A3E4_41B8_98B1_35DAD8586D6E__INCLUDED_)
#define AFX_PATTERNDLG_H__20F9D625_A3E4_41B8_98B1_35DAD8586D6E__INCLUDED_

#include "CircleArc.h"    // Added by ClassView
#include "CA210.h"
#include "..\MsrItems\MsrItemDlg.h"
#include "..\CColorRef.h"

#include <cmath>
#include <vector>

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PatternDlg.h : header file
//

enum initType{  MsrForItem = 0, MsrForPoint, MsrForForm  };

/////////////////////////////////////////////////////////////////////////////
// CPatternDlg dialog
class CPatternDlg : public CDialog
{
    initType InitDataType;
//     struct MyThreadInfo
//     {
//         CPatternDlg* ptnDlg;
//     }Info1;
// Construction
public:
    CPatternDlg(initType it, CWnd* pParent = NULL);   // standard constructor

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
    RNA m_RNA;
    
    //手動可調
//     BOOL c_bDrawGold;
//    BOOL c_bDrawNextGold;
    BOOL c_bStatusBar;

    //自動使用的參數
    BOOL c_bMsrBegin;
    BOOL c_bMsrEnd;
    BOOL c_bMsrEndnMsred;
    BOOL c_bRunMsrAI;
    BOOL c_bUnCntCA210;

//     UINT SetPercentValue;
//     MsrAiState m_msrStatus;

    Ca210* m_pCA210;

    std::vector<Cartridge2>::iterator m_itor;
    std::vector<Cartridge2>::iterator m_BeginItor;
    std::vector<Cartridge2>::iterator m_EndItor;

    CBrush   m_BkBrush;
    ColorRef m_BkColor;    //背景色

    Circle m_Goal;        //目標圈圈

//     int  m_Percent;
//     Bolt m_GunMchn;
//     Bolt m_NextGunMchn;

private:
    void initLCMSize() const;
    void initCa210();
    void initDataDlgType() const;//Call SelMsrItem
    void initDocument();

    void trigger();
    void checkMsrLimit();
    void setBkColor(const ColorRef&);
    CaState recoil();
	void MsrKernel();

    void eventGoPrvsGoal();
    BOOL eventGoNextGoal();
    void eventSwCntCa210();
    void eventRunMsrAi(BOOL isRun = 2);
    UINT eventCatchMsrValue();
    void eventExitDialog();
public:
    void LoadedCartridge(); //彈匣
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PATTERNDLG_H__20F9D625_A3E4_41B8_98B1_35DAD8586D6E__INCLUDED_)
