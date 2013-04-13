#if !defined(AFX_SELEXCELDLG_H__ADDEE756_BDFE_4902_8E46_BCDADC42899B__INCLUDED_)
#define AFX_SELEXCELDLG_H__ADDEE756_BDFE_4902_8E46_BCDADC42899B__INCLUDED_

#include "XlsRA1.h"
#include "XlsOQC1.h"
#include "XlsOQC2.h"
#include "XlsSEC1.h"
#include "XlsGamma.h"

#include "../MainFrm.h"
#include "../ColorEyeIDoc.h"
#include "cderr.h"   //for   definition   of   FNERR_BUFFERTOOSMALL 
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

class CSelExcelDlg : public CDialog
{
    FormType   m_ft;
    int        m_fileNumLimit;
    CString    m_strXlsFilePath;  //XlsFilepath

    RNA m_omd2xls;
    std::vector<CString> m_omdFilesList;//   m_vOmdFilePathList;

    CMainFrame*    m_pMainFrm;
    CColorEyeIDoc* m_pDoc;

// Construction
public:
    CSelExcelDlg(CWnd* pParent = NULL);   // standard constructor

private:
	const CString getCurSelXlsPath() const;
	void out2xls(CXlsFile2* );
//     void NewVector();
    void initSelXlsCbx(CString FileNameExt);
	void otherOmd2xls(CXlsFile2* pfXls);
	void thisOmd2xls(CXlsFile2* fXls);
	
    void setFileComeFrom(enum WhereFileComeFrom WFCF);

	void findOtherOmdFile(std::vector<CString>& );
	void showFileList(std::vector<CString>& );
public:
// Dialog Data
    //{{AFX_DATA(CSelExcelDlg)
    enum { IDD = IDD_OMDTOEXCEL };
    CListBox   m_lstSelOmdFileList;
    CButton    m_btnOK;
    CButton    m_stcHDFileList;
    CButton    m_rdoChooseHDFile;
    CComboBox  m_cbxExcelSelor;
    CButton    m_rdoChooseNowFile;
    CListBox   m_lstSelFileList;
    CButton    m_btnFindFile;
    CString    m_strItemOfExcel;
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
    // Generated OLE dispatch map functions
    //{{AFX_DISPATCH(CSelExcelDlg)
        // NOTE - the ClassWizard will add and remove member functions here.
    //}}AFX_DISPATCH
    DECLARE_DISPATCH_MAP()
    DECLARE_INTERFACE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SELEXCELDLG_H__ADDEE756_BDFE_4902_8E46_BCDADC42899B__INCLUDED_)
