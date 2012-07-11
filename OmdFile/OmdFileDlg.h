// OmdFileDlg.h : header file
//

#if !defined(AFX_OMDFILEDLG_H__4C8E02B8_7198_48DF_9178_86201F177621__INCLUDED_)
#define AFX_OMDFILEDLG_H__4C8E02B8_7198_48DF_9178_86201F177621__INCLUDED_
#include <vector>
#include "../xMsrPoint/Cartridge.h"
#include "../xMsrPoint/Bolt.h"
#include "OmdFile1.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// COmdFileDlg dialog

class COmdFileDlg : public CDialog
{
	Bolt SimPtnDlg;
	std::vector<Cartridge> vChain1;
	CString m_PnlID;
    CString m_MsrDvc;
    CString m_Prb;
    CString m_CHID;
//	TCHAR *pbuf;
	COmdFile1* f_Omd;//tempfile;
//	CTxtFile* f_txt;

// Construction
public:
	COmdFileDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(COmdFileDlg)
	enum { IDD = IDD_OMDFILE_DIALOG };
	CComboBox	m_cmbCartridgeChoose;
	CString	m_str;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COmdFileDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(COmdFileDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnStaticTerminal();
	afx_msg void OnSelchangeCombo1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void SetOrigPriority(std::vector<Cartridge>& vCar);
//	CString GetLine(UINT Num);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OMDFILEDLG_H__4C8E02B8_7198_48DF_9178_86201F177621__INCLUDED_)
