// xMsrPointDlg.h : header file
//

#if !defined(AFX_XMSRPOINTDLG_H__C69B1908_A89D_43A7_A705_CDDB58D14833__INCLUDED_)
#define AFX_XMSRPOINTDLG_H__C69B1908_A89D_43A7_A705_CDDB58D14833__INCLUDED_

#include "../xMsrPoint/ca200srvr.h"    // Added by ClassView
//Bullet 彈頭
//Cartridge 子彈
//Loader填彈器
//Belt 彈鍊
#include "../xMsrPoint/Cartridge.h"
#include "../xMsrPoint/PatternDlg.h"

//#include "Bullet.h"    // Added by ClassView

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CXMsrPointDlgAutoProxy;
/////////////////////////////////////////////////////////////////////////////
// CXMsrPointDlg dialog

class CXMsrPointDlg : public CDialog
{
    //CA-SDK用的變數
	Ca210      * m_pCA210;
    CPatternDlg* p_PtnDlg;
	std::vector<Cartridge> vChain1;

	std::vector<Cartridge>::size_type SubNum(ColorType clr, PointNum Large, UINT Little) const;

    DECLARE_DYNAMIC(CXMsrPointDlg);
    friend class CXMsrPointDlgAutoProxy;

// Construction
public:
    CXMsrPointDlg(CWnd* pParent = NULL);    // standard constructor
    virtual ~CXMsrPointDlg();

// Dialog Data
    //{{AFX_DATA(CXMsrPointDlg)
	enum { IDD = IDD_XMSRPOINT_DIALOG };
	CButton	m_btnOutExcel;
	CButton	m_btnClearAll;
	CSliderCtrl	m_sldViewControl;
    CString    m_strDu;
    CString    m_strDv;
    CString    m_strDuv;
    CString    m_strLv;
    CString    m_strSx;
    CString    m_strSy;
    CString    m_strT;
    CString    m_strX;
    CString    m_strY;
    CString    m_strZ;
	CString	m_strOrig;
	CString	m_strAreaCode;
	CString	m_strBkColor;
	CString	m_strFlowNo;
	CString	m_strFlowNum;
	//}}AFX_DATA

    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CXMsrPointDlg)
    protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    //}}AFX_VIRTUAL

// Implementation
protected:
    CXMsrPointDlgAutoProxy* m_pAutoProxy;
    HICON m_hIcon;

    BOOL CanExit();

    // Generated message map functions
    //{{AFX_MSG(CXMsrPointDlg)
    virtual BOOL OnInitDialog();
    afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
    afx_msg void OnPaint();
    afx_msg HCURSOR OnQueryDragIcon();
    afx_msg void OnButtonMsr();
	afx_msg void OnReleasedcaptureSlider1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButton2();
	afx_msg void OnButton1();
	//}}AFX_MSG
    DECLARE_MESSAGE_MAP()
private:
	void DebugByExcel();

	CString itToAddress(std::vector<Cartridge>::iterator it);
	CString itToColorType(std::vector<Cartridge>::iterator it);
	CString itToPointNum(std::vector<Cartridge>::iterator it);
	CString itToPointNo(std::vector<Cartridge>::iterator it);
	CString itToSubNum(std::vector<Cartridge>::iterator it);

	CString itToAddress(Cartridge& vCar);
	CString itToColorType(Cartridge& vCar);
	CString itToPointNum(Cartridge& vCar);
	CString itToPointNo(Cartridge& vCar);
	CString itToSubNum(Cartridge& vCar);
	CString UintToStr(UINT u);

private:
	static bool AreaPriority(const Cartridge &sp1, const Cartridge &sp2);
	static bool OrigPriority(const Cartridge &sp1, const Cartridge &sp2);
	void QuackMsrSort(std::vector<Cartridge>& vCar) const;
	void OrigMsrSort(std::vector<Cartridge>& vCar) const;};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XMSRPOINTDLG_H__C69B1908_A89D_43A7_A705_CDDB58D14833__INCLUDED_)
