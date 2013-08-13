#if !defined(AFX_SELEXCELDLG_H__8D74EAAE_F8BE_4BB0_8053_BFCCC8738358__INCLUDED_)
#define AFX_SELEXCELDLG_H__8D74EAAE_F8BE_4BB0_8053_BFCCC8738358__INCLUDED_

#include "XlsRA1.h"
#include "XlsOQCmass.h"
#include "XlsOQCtest.h"
#include "XlsSEC1.h"
#include "XlsGamma.h"

#include <cderr.h>   //for   definition   of   FNERR_BUFFERTOOSMALL 
#include "FileDlg.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SelExcelDlg.h : header file
//
/////////////////////////////////////////////////////////////////////////////
// CSelExcelDlg dialog

enum WhereFileComeFrom { ThisFile = 0, OtherFile};
enum FormType{ FM_Nothing = 0, FM_RA, FM_OQC_Test, FM_SEC, FM_Gamma, FM_OQCY2013_Volume};

typedef CXlsFile2* XLSPTR;

class CSelExcelDlg : public CDialog
{
// Construction
public:
	CSelExcelDlg(CWnd* pParent = NULL);   // standard constructor

public:
// Dialog Data
	//{{AFX_DATA(CSelExcelDlg)
	enum { IDD = IDD_OMD2EXCEL };
	CButton	m_tran2Xls;
	CButton	m_btnOK2Xls;
    CListBox   m_lstSelOmdFileList;
    CButton    m_stcHDFileList;
    CButton    m_rdoChooseHDFile;
    CComboBox  m_cbxExcelSelor;
    CButton    m_rdoChooseNowFile;
    CListBox   m_lstSelFileList;
    CButton    m_btnFindFile;
	CString	m_xlsDescrip;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSelExcelDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSelExcelDlg)
    virtual BOOL OnInitDialog();
    virtual void OnOK();
    afx_msg void OnSelectXlsForm();
    afx_msg void OnFindOmdFile();
    afx_msg void OnRadioNowfile();
    afx_msg void OnRadioHdfile();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	FormType   m_omdFromType;
    int        m_omdOpenLimit;
	std::vector<CString> m_omdList;//   m_vOmdFilePathList;
private:
    void initSelXlsCbx(const CString& FileNameExt);
	const CString reconstructSearchXlsPath(const CString&);
	//OnSelectXlsForm
	void setSelXlsDetail(const LPCTSTR& xlsDescrip, const int& openXlsLimit, const FormType& formTypt, const BOOL& tranXlsBtnEnble = TRUE);
	//Select Radio
	void setOmdComeFrom(WhereFileComeFrom WFCF);
	//Other Omd flie -> find Omdfile
	void findOtherOmdFile(std::vector<CString>& );
	void showOtherOmdList(std::vector<CString>& );
	//tran2Xls
	void initXlsObj(XLSPTR&);
	void out2xls(XLSPTR&);
	const CString getCurSelXlsPath() const;
	void otherOmd2xls(XLSPTR&);
	void thisOmd2xls(XLSPTR&);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SELEXCELDLG_H__8D74EAAE_F8BE_4BB0_8053_BFCCC8738358__INCLUDED_)
