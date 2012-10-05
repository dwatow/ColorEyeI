#if !defined(AFX_PATTERNDLG_H__20F9D625_A3E4_41B8_98B1_35DAD8586D6E__INCLUDED_)
#define AFX_PATTERNDLG_H__20F9D625_A3E4_41B8_98B1_35DAD8586D6E__INCLUDED_

#include "CircleArc.h"    // Added by ClassView
#include "CA210.h"
#include "..\MsrItems\MsrItemDlg.h"

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

    struct MyThreadInfo
    {
        CPatternDlg* ptnDlg;
    }Info1;
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
    afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	//}}AFX_MSG
    DECLARE_MESSAGE_MAP()
private:
    CaState Recoil();
    
    //手動可調
    BOOL c_bDrawGold;
    BOOL c_bDrawNextGold;
//    BOOL c_bDebugDisplay;
    BOOL c_bStateBar;

    //自動使用的參數
    BOOL c_bMsrValues;
    BOOL c_bZeroCal;
    BOOL c_bMsrBegin;
    BOOL c_bMsrEnd;
	BOOL c_bMsrEndnMsred;
    BOOL c_bMsring;
    BOOL c_bGoalPercent;
    BOOL c_bRunMsrAI;
    BOOL c_bUnCntCA210;
    BOOL c_bFind5nits;
    BOOL c_bisReady;

    UINT SetPercentValue;
    MsrAiState MsrAIValue;

    Ca210* m_pCA210;

//    std::vector<Cartridge> vDataChain;
    std::vector<Cartridge>::iterator m_itor;
    std::vector<Cartridge>::iterator m_BeginItor;
    std::vector<Cartridge>::iterator m_EndItor;

    CBrush   m_BkBrush;
    COLORREF m_BkColor;    //背景色

     CircleArc m_Goal;        //目標圈圈
//     CircleArc m_NextGoal;    //下一個目標圈圈
//    Circle    m_Goal;        //目標圈圈
    Circle    m_NextGoal;    //下一個目標圈圈

    UINT m_Percent;
    Bolt m_GunMchn;
    Bolt m_NextGunMchn;

	CString SetLCMSize();

    BOOL Trigger(std::vector<Cartridge>::iterator&);
    BOOL NextTrigger(std::vector<Cartridge>::iterator&);
    COLORREF ShiftColor(COLORREF clr, UINT shift = 55) const;
    COLORREF InvrtColor(COLORREF clr) const;
    void DrawMsrLabel(CDC &pDC);
    void DrawMsringLabel(CDC &pDC);

    void EventGoPrvsGoal();
    BOOL EventGoNextGoal();
    void EventSwCntCa210();
    void EventRunZeroCal();
    void EventRunMsrAi(BOOL isRun = 2);
    UINT EventCatchMsrValue();

    void InitDataDlgType();//Call SelMsrItem

    static UINT VbrGoalThread(LPVOID LParam);
    static UINT VbrNextGoalThread(LPVOID LParam);

public:
    void FineNits();

 //   BOOL Magazine(std::vector<Cartridge>& ); //彈匣
    BOOL Magazine(); //彈匣
//    BOOL ConnectCa210(Ca210* ca);
    BOOL ConnectCa210();
//    void Partition(std::vector<Cartridge>& , Cartridge& );  //填彈器（快速量測）

    COLORREF GetBkColor() const;
    BOOL     SetBkColor(COLORREF);

        CPoint   GetGoalPosi() const;
        BOOL     SetGoalPosi(CPoint);

        UINT     GetGoalRadius() const;
        BOOL     SetGoalRadius(UINT );

        COLORREF GetGoalBkColor() const;
        BOOL     SetGoalBkColor(COLORREF);

        COLORREF GetGoalColor() const;
        BOOL     SetGoalColor(COLORREF);

    BOOL isReady();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PATTERNDLG_H__20F9D625_A3E4_41B8_98B1_35DAD8586D6E__INCLUDED_)
