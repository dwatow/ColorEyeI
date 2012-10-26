// SelExcelDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SelXls.h"
#include "SelExcelDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSelExcelDlg dialog


CSelExcelDlg::CSelExcelDlg(CWnd* pParent /*=NULL*/): 
    CDialog(CSelExcelDlg::IDD, pParent),
    m_pMainFrm(dynamic_cast<CMainFrame*>(AfxGetMainWnd())), 
    m_pDoc(dynamic_cast<CColorEyeIDoc*>(m_pMainFrm->GetActiveDocument()))

{
    EnableAutomation();
    ASSERT_VALID(m_pMainFrm);
    ASSERT_VALID(m_pDoc);
    
    //{{AFX_DATA_INIT(CSelExcelDlg)
    m_strItemOfExcel = _T("");
    //}}AFX_DATA_INIT
}



void CSelExcelDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CSelExcelDlg)
    DDX_Control(pDX, IDC_LIST_SELFILELIST, m_lstSelOmdFileList);
    DDX_Control(pDX, IDOK, m_btnOK);
    DDX_Control(pDX, IDC_STATIC_HDFILELIST, m_stcHDFileList);
    DDX_Control(pDX, IDC_RADIO_HDFILE, m_rdoChooseHDFile);
    DDX_Control(pDX, IDC_COMBO_EXCELSELER, m_cbxExcelSelor);
    DDX_Control(pDX, IDC_RADIO_NOWFILE, m_rdoChooseNowFile);
    DDX_Control(pDX, IDC_BUTTON_FINDFILE, m_btnFindFile);
    DDX_Text(pDX, IDC_STATIC_ITEMLIST, m_strItemOfExcel);
    //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSelExcelDlg, CDialog)
    //{{AFX_MSG_MAP(CSelExcelDlg)
    ON_CBN_SELCHANGE(IDC_COMBO_EXCELSELER, OnSelectXlsForm)
    ON_BN_CLICKED(IDC_BUTTON_FINDFILE, OnFindOmdFile)
    ON_BN_CLICKED(IDC_RADIO_NOWFILE, OnRadioNowfile)
    ON_BN_CLICKED(IDC_RADIO_HDFILE, OnRadioHdfile)
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CSelExcelDlg, CDialog)
    //{{AFX_DISPATCH_MAP(CSelExcelDlg)
        // NOTE - the ClassWizard will add and remove mapping macros here.
    //}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_ISelExcelDlg to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {1898EEAC-B573-4CD6-90FA-92D98663C79E}
static const IID IID_ISelExcelDlg =
{ 0x1898eeac, 0xb573, 0x4cd6, { 0x90, 0xfa, 0x92, 0xd9, 0x86, 0x63, 0xc7, 0x9e } };

BEGIN_INTERFACE_MAP(CSelExcelDlg, CDialog)
    INTERFACE_PART(CSelExcelDlg, IID_ISelExcelDlg, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSelExcelDlg message handlers

BOOL CSelExcelDlg::OnInitDialog() 
{
    CDialog::OnInitDialog();
    
    // TODO: Add extra initialization here
    SetFileComeFrom(FromNowFile);
    InitXlsFileList(m_cbxExcelSelor, "xls");

    return TRUE;  // return TRUE unless you set the focus to a control
                  // EXCEPTION: OCX Property Pages should return FALSE
}

void CSelExcelDlg::InitXlsFileList(CComboBox& ComboBox, CString FileNameExt)
{
    //抓取程式目錄下的.xls表格
    WIN32_FIND_DATA FindFileData;  //一個結構，找到的檔案
    HANDLE hListFile;
    
    m_strXlsFilePath.Empty(); 
    CString strFilePathType;  //要找的檔案類型+路徑
    
    ///設定所在目錄
    GetModuleFileName(NULL, m_strXlsFilePath.GetBuffer(MAX_PATH+1), MAX_PATH);  //抓應用程式所在的目錄+檔名+副檔名
    m_strXlsFilePath.ReleaseBuffer();
    m_strXlsFilePath = m_strXlsFilePath.Left(m_strXlsFilePath.ReverseFind('\\'));
    strFilePathType.Format("%s\\*.%s", m_strXlsFilePath, FileNameExt);         //目前執行檔所在路徑\*.xls
    
    //找第一個檔案
    hListFile = FindFirstFile(strFilePathType.GetBuffer(0), &FindFileData);
    
    //找xls檔案的動作
    //設定下拉式選單的可選表格
    //內建表格
    ComboBox.ResetContent();
    ComboBox.AddString("RA Form");  //0
    ComboBox.AddString("SEC Form"); //1

    //外加表格
    if(hListFile == INVALID_HANDLE_VALUE)
    {
        //找不到檔案
        //strFilePathType也用不到了！拿來顯示錯誤訊息吧！
        strFilePathType.Format("錯誤: %d\n%s\n找不到.xls檔案, 無法輸出Excel!!", GetLastError(), m_strXlsFilePath);
        MessageBox(strFilePathType, NULL, MB_ICONWARNING | MB_OK);
        strFilePathType.Format("");
    }
    else
    {
        //填上選擇Excel下拉式選單的資料
        
        do ComboBox.AddString(FindFileData.cFileName);
        while(FindNextFile(hListFile, &FindFileData));
        //總數
        //         strFilePathType.Format("錯誤%d", m_cbxExcelSelor.GetCount());
        //         MessageBox(strFilePathType);
    }
    ComboBox.SetCurSel(0);
    OnSelectXlsForm() ;
    //程式到此結束，下面都是註解
}

void CSelExcelDlg::OnRadioNowfile() 
{
    // TODO: Add your control notification handler code here
    SetFileComeFrom(FromNowFile);
}

void CSelExcelDlg::OnRadioHdfile() 
{
    // TODO: Add your control notification handler code here
    SetFileComeFrom(FromHDFile);
}

void CSelExcelDlg::SetFileComeFrom(enum WhereFileComeFrom WFCF)
{
    //用Radio選擇誰要enable，誰不要
    m_rdoChooseNowFile.SetCheck(!WFCF);
    m_rdoChooseHDFile.SetCheck(WFCF);

    m_lstSelOmdFileList.EnableWindow(WFCF);
    m_btnFindFile.EnableWindow(WFCF);
    m_stcHDFileList.EnableWindow(WFCF);
}

void CSelExcelDlg::OnSelectXlsForm() 
{
    // TODO: Add your control notification handler code here
    //下拉式選單選擇時的動作
    CString str;
    m_lstSelOmdFileList.ResetContent();
    m_cbxExcelSelor.GetLBText(m_cbxExcelSelor.GetCurSel(), str);

    if (str.Find("RA") != -1)
    {
        m_strItemOfExcel.Format("9點亮度\n9點色度\n\nCA210-CH\nCA210-Probe\n"); 
        m_fileNumLimit = 100;
        m_ft = FORM_RA;
        m_btnOK.EnableWindow(TRUE);
    }
    else if (str.Find("F1") != -1 || str.Find("H1") != -1 || str.Find("F6") != -1 || str.Find("H6") != -1 || str.Find("OQC") != -1)
    {
        m_strItemOfExcel.Format("9點亮度\n9點色度\n25點暗態\n中心點色度\n5Nits\n\n灰階階數\nCA210-CH\nFLICKER");
        m_fileNumLimit = 10;
        m_ft = FORM_OQC_LCM_SPEC;
        m_btnOK.EnableWindow(TRUE);
    }
    else if (str.Find("Gamma") != -1)
    {
        m_strItemOfExcel.Format("Gamma curve");
        m_fileNumLimit = 1;
        m_ft = FORM_Gamma;
        m_btnOK.EnableWindow(TRUE);
    }
    else if (str.Find("SEC") != -1)
    {
        m_strItemOfExcel.Format("9點亮度\n9點暗態\n中心點色度\n5Nits\n\n灰階階數\nCA210-CH\nFLICKER\nCross Talk");
        m_fileNumLimit = 1;
        m_ft = FORM_SEC;
        m_btnOK.EnableWindow(TRUE);
    }
    else
    {
        m_strItemOfExcel.Format("(無法識別)");
        m_fileNumLimit = 1;
        m_ft = FORM_Nothing;
        m_btnOK.EnableWindow(FALSE);
    }

    UpdateData(FALSE);
}

void CSelExcelDlg::OnFindOmdFile() 
{
    // TODO: Add your control notification handler code here
    //找omd檔案的動作
    CString fOmdFilter("OrigMsrData Files (*.omd)|*.omd|Text File(*.txt)|*.txt|All Files (*.*)|*.* ||");//檔案過濾條件
    CFileDlg aFileDialog (TRUE, NULL, NULL, \
                          (m_fileNumLimit > 1) ? OFN_ALLOWMULTISELECT | OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT \
                                               : OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, fOmdFilter);
    
    aFileDialog.SetMultiFileNameBuffer(m_fileNumLimit);
    
    int nID = aFileDialog.DoModal();
    if (nID == IDOK)
        aFileDialog.GetSelFileList(m_vOmdFilePathList);    

    if(CommDlgExtendedError() == FNERR_BUFFERTOOSMALL) 
        AfxMessageBox("Sel Excel Dialog緩衝區不夠大\n剪下畫面，並且找程式設計師解決這問題。", MB_OK | MB_ICONERROR); 
    else
        m_lstSelOmdFileList.ResetContent();

    //檔案列表裝在控制項上
    for (std::vector<CString>::iterator itStr = m_vOmdFilePathList.begin(); itStr != m_vOmdFilePathList.end(); ++itStr)
    {
        //顯示時會依表格適用幾筆Omd檔的數量，做限制。
        if (itStr - m_vOmdFilePathList.begin() < m_fileNumLimit)
            m_lstSelOmdFileList.AddString(itStr->Right(itStr->GetLength() - itStr->ReverseFind('\\') - 1));
        else
        {
            //超過表格可以裝載數量，就刪掉。
            m_vOmdFilePathList.erase(itStr, m_vOmdFilePathList.end());
            break;
        }
    }
}

void CSelExcelDlg::NewVector()
{
    m_vOmdtoXls.StdInit();
}

void CSelExcelDlg::OnOK() 
{
    BeginWaitCursor();
        CXlsFile2* pfXls = 0;
        NewVector();
        switch(m_ft)
        {
        case FORM_SEC:          pfXls = new CXlsSEC1();  pfXls->New()->SetSheetName(1,"SEC Report");                break;
        case FORM_RA:           pfXls = new CXlsRA1();   pfXls->New()->SetSheetName(1,"RA Report");                 break;    
        case FORM_OQC_LCM_SPEC: pfXls = new CXlsOQC2();  pfXls->Open(GetXlsFilePath())->SetSheetName(1,"OQC SPEC"); break;    
        case FORM_Gamma:        /*pfXls = new CXlsGamma;  */                                                        break;     
        case FORM_Nothing:
        default:                AfxMessageBox("怎麼會選這一個輸出？");
        }
        OutToExcel(pfXls);
        if (pfXls != 0)
            delete pfXls;
    EndWaitCursor();
    CDialog::OnOK();
}

CString CSelExcelDlg::GetXlsFilePath()
{
    CString strXlsFilePath;
    CString strFileName;
    m_cbxExcelSelor.GetLBText(m_cbxExcelSelor.GetCurSel(), strFileName);
    strXlsFilePath.Format("%s\\%s", m_strXlsFilePath, strFileName);
    return strXlsFilePath;
}

void CSelExcelDlg::OutToExcel(CXlsFile2* pTofXls)
{
    if (m_rdoChooseHDFile.GetCheck() == FromHDFile)
        HDfileToExcel(pTofXls);
    else
        DocfileToExcel(pTofXls);
}

void CSelExcelDlg::HDfileToExcel(CXlsFile2* pHDfXls)
{
    pHDfXls->InitForm();

    COmdFile0 fOmd;
    CFileException fx;
    BeginWaitCursor();
    for (std::vector<CString>::iterator itfPaths = m_vOmdFilePathList.begin(); itfPaths != m_vOmdFilePathList.end(); ++itfPaths)
    {
        //在此，等同於Doc的開啟舊檔As omd
        if(!fOmd.Open(*itfPaths, fx))
            AfxMessageBox("路徑有問題");
        else
        {
            fOmd.oOmdData(m_vOmdtoXls);

            pHDfXls->iCellNO (abs(itfPaths - m_vOmdFilePathList.begin()));
            pHDfXls->iChannel(fOmd.GetCHID());
            pHDfXls->iPanelID(fOmd.GetPnlID());
            pHDfXls->iProb   (fOmd.GetPrb());
            pHDfXls->iData   (m_vOmdtoXls);

            fOmd.Close();


        }
    }
    EndWaitCursor();
}

void CSelExcelDlg::DocfileToExcel(CXlsFile2* pDocfXls)
{
    pDocfXls->InitForm();
    pDocfXls->iCellNO(0)->iChannel(m_pDoc->GetCHID())->iPanelID(m_pDoc->GetPnlID())->iProb(m_pDoc->GetPrb())->iData(m_pDoc->GetOmdData());
}

