#if !defined(AFX_SELEXCELDLG_H__ADDEE756_BDFE_4902_8E46_BCDADC42899B__INCLUDED_)
#define AFX_SELEXCELDLG_H__ADDEE756_BDFE_4902_8E46_BCDADC42899B__INCLUDED_

#include "XlsRA1.h"
#include "XlsOQC1.h"
#include "XlsSEC1.h"
#include "XlsGamma.h"

#include "FileDlg.h"
#include "cderr.h"   //for   definition   of   FNERR_BUFFERTOOSMALL 
#include "../xMsrPoint/Bolt.h"
#include "../MainFrm.h"
#include "../ColorEyeIDoc.h"
//#include <vector>
#include "../DataChain.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SelExcelDlg.h : header file
//
/////////////////////////////////////////////////////////////////////////////
// CSelExcelDlg dialog

enum WhereFileComeFrom { FromNowFile = 0, FromHDFile};
enum FormType{ FORM_Nothing = 0, FORM_RA , FORM_OQC_LCM_SPEC, FORM_SEC, FORM_Gamma};

class CSelExcelDlg : public CDialog
{
	COmdFile1* m_pOmdfile;
    FormType  m_ft;
    int       m_nBufferSize;
    CString   m_strXlsPath;  //XlsFilepath
    CDataChain m_vOmdtoXls;
	std::vector<CString>   m_vFilePathList;  //OmdFilepath

	CMainFrame* pMainFrm;
	CColorEyeIDoc* pDoc;
// Construction
public:
    CSelExcelDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
    //{{AFX_DATA(CSelExcelDlg)
    enum { IDD = IDD_OMDTOEXCEL };
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
    public:
    virtual void OnFinalRelease();
    protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    //}}AFX_VIRTUAL

// Implementation
protected:

    // Generated message map functions
    //{{AFX_MSG(CSelExcelDlg)
    virtual BOOL OnInitDialog();
    virtual void OnOK();
    afx_msg void OnSelchangeComboExcelseler();
    afx_msg void OnButtonFindfile();
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
private:
	void oChooseXls();
    void formRA();
    void formOQC();
    void formGamma();
    void formSEC();

	void NewVector();
    void GetCurFileList(CComboBox& ComboBox, CString FileNameExt);
 
	void SetFileComeFrom(enum WhereFileComeFrom WFCF);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SELEXCELDLG_H__ADDEE756_BDFE_4902_8E46_BCDADC42899B__INCLUDED_)
