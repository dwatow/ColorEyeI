// SelExcelDlg.cpp : implementation file
//

#include "StdAfx.h"
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
    setFileComeFrom(ThisFile);
    initSelXlsCbx("xls");

    return TRUE;  // return TRUE unless you set the focus to a control
                  // EXCEPTION: OCX Property Pages should return FALSE
}

void CSelExcelDlg::initSelXlsCbx(CString FileNameExt)
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
    m_cbxExcelSelor.ResetContent();
    m_cbxExcelSelor.AddString("RA Form");  //0
    m_cbxExcelSelor.AddString("SEC Form"); //1

    //外加表格
    if(hListFile == INVALID_HANDLE_VALUE)
    {
        //找不到檔案
        //strFilePathType也用不到了！拿來顯示錯誤訊息吧！
//         strFilePathType.Format("錯誤: %d\n%s\n找不到.xls檔案, 無法輸出Excel!!", GetLastError(), m_strXlsFilePath);
//         MessageBox(strFilePathType, NULL, MB_ICONWARNING | MB_OK);
        strFilePathType.Format("");
    }
    else
    {
        //填上選擇Excel下拉式選單的資料
        
        do m_cbxExcelSelor.AddString(FindFileData.cFileName);
        while(FindNextFile(hListFile, &FindFileData));
        //總數
        //         strFilePathType.Format("錯誤%d", m_cbxExcelSelor.GetCount());
        //         MessageBox(strFilePathType);
    }
    m_cbxExcelSelor.SetCurSel(0);
    OnSelectXlsForm() ;
    //程式到此結束，下面都是註解
}

void CSelExcelDlg::OnRadioNowfile() 
{
    // TODO: Add your control notification handler code here
    setFileComeFrom(ThisFile);
}

void CSelExcelDlg::OnRadioHdfile() 
{
    // TODO: Add your control notification handler code here
    setFileComeFrom(OtherFile);
}

void CSelExcelDlg::setFileComeFrom(enum WhereFileComeFrom WFCF)
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
        m_ft = FM_RA;
        m_btnOK.EnableWindow(TRUE);
    }
    else if (str.Find("OQC") != -1)
    {
        m_strItemOfExcel.Format("2013年試產表格\n9點亮色度、中心點亮色度、5Nits\n25點暗態\n21點暗態\nCrossTalk\nCrossTalk\nColor Gamu\n\n灰階階數\nCA210-CH\nFlicker");
        m_fileNumLimit = 10;
        m_ft = FM_OQC_Test;  //試產
        m_btnOK.EnableWindow(TRUE);
    }
    else if (str.Find("Y2013") != -1)
    {
        m_strItemOfExcel.Format("2013年量產表格\n9點亮度\n25點暗態\n中心點亮色度\n5Nits\n21點暗態\nCrossTalk\nCrossTalk\nColor Gamu\n\n灰階階數\nCA210-CH\nFlicker");
        m_fileNumLimit = 10;
        m_ft = FM_OQCY2013_Volume;  //量產
        m_btnOK.EnableWindow(TRUE);
    }
    else if (str.Find("Gamma") != -1)
    {
        m_strItemOfExcel.Format("Gamma curve");
        m_fileNumLimit = 5;
        m_ft = FM_Gamma;
        m_btnOK.EnableWindow(TRUE);
    }
    else if (str.Find("SEC") != -1)
    {
        m_strItemOfExcel.Format("9點亮度\n9點暗態\n中心點色度\n5Nits\n\n灰階階數\nCA210-CH\nFLICKER\nCross Talk");
        m_fileNumLimit = 1;
        m_ft = FM_SEC;
        m_btnOK.EnableWindow(TRUE);
    }
    else
    {
        m_strItemOfExcel.Format("(無法識別)");
        m_fileNumLimit = 1;
        m_ft = FM_Nothing;
        m_btnOK.EnableWindow(FALSE);
    }

    UpdateData(FALSE);
}

void CSelExcelDlg::findOtherOmdFile(std::vector<CString>& fileList)
{
    CString fOmdFilter("OrigMsrData Files (*.omd)|*.omd|Text File(*.txt)|*.txt|All Files (*.*)|*.* ||");//檔案過濾條件
    CFileDlg aFileDialog (TRUE, NULL, NULL, \
		( m_fileNumLimit > 1 ) ? OFN_ALLOWMULTISELECT | OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT \
		: OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, fOmdFilter);

    aFileDialog.SetSelMultiFileTotal(m_fileNumLimit);  //設定可以選幾個檔案。

    if (aFileDialog.DoModal() == IDOK)
        aFileDialog.GetSelFileList(fileList);

    if(CommDlgExtendedError() == FNERR_BUFFERTOOSMALL) 
        AfxMessageBox("Sel Excel Dialog緩衝區不夠大\n剪下畫面，並且找程式設計師解決這問題。", MB_OK | MB_ICONERROR); 
    else
        m_lstSelOmdFileList.ResetContent();
}

void CSelExcelDlg::showFileList(std::vector<CString>& fileList)
{
    for (std::vector<CString>::iterator itStr = fileList.begin(); itStr != fileList.end(); ++itStr)
    {
        //顯示時會依表格適用幾筆Omd檔的數量，做限制。
        if (itStr - fileList.begin() < m_fileNumLimit)
            m_lstSelOmdFileList.AddString(itStr->Right(itStr->GetLength() - itStr->ReverseFind('\\') - 1));
        else
        {
            fileList.erase(itStr, fileList.end());  //超過表格可以裝載數量，就刪掉。
            break;
        }
    }
}
void CSelExcelDlg::OnFindOmdFile()
{
    // TODO: Add your control notification handler code here
	findOtherOmdFile(m_omdFilesList);  //找omd檔案的動作
	showFileList    (m_omdFilesList);  //檔案列表裝在控制項上
}

// void CSelExcelDlg::NewVector()
// {
// //    m_omd2xls.StdInit();
// }

void CSelExcelDlg::OnOK()
{
    BeginWaitCursor();
        CXlsFile2* pfXls = 0;
//         NewVector();
        switch(m_ft)
        {
        case FM_SEC:             pfXls = new CXlsSEC1 (); pfXls->New()->SetSheetName(1,"SEC Report");                   break;
        case FM_RA:              pfXls = new CXlsRA1  (); pfXls->New()->SetSheetName(1,"RA Report");                    break;    
        case FM_OQC_Test:        pfXls = new CXlsOQC2 (); pfXls->Open(getCurSelXlsPath())->SetSheetName(1, "OQC SPEC");   break;
		case FM_OQCY2013_Volume: pfXls = new CXlsOQC1 (); pfXls->Open(getCurSelXlsPath())->SetSheetName(1, "光學");        break;
        case FM_Gamma:           pfXls = new CXlsGamma(); pfXls->Open(getCurSelXlsPath())->SetSheetName(1, "Color Data"); break;
        case FM_Nothing:
        default:                AfxMessageBox("怎麼會選這一個輸出？");
        }
        out2xls(pfXls);

        if (pfXls != 0)
            delete pfXls;

    EndWaitCursor();
    CDialog::OnOK();
}

const CString CSelExcelDlg::getCurSelXlsPath() const
{
    CString strXlsFilePath;
    CString strFileName;

    m_cbxExcelSelor.GetLBText(m_cbxExcelSelor.GetCurSel(), strFileName);   //ComboBox -> file name
    strXlsFilePath.Format("%s\\%s", m_strXlsFilePath, strFileName);        //path + file name
    return strXlsFilePath;
}

void CSelExcelDlg::out2xls(CXlsFile2* pTofXls)
{
    if ( m_rdoChooseHDFile.GetCheck() == OtherFile )
        otherOmd2xls(pTofXls);
    else
        thisOmd2xls(pTofXls);
}

void CSelExcelDlg::otherOmd2xls(CXlsFile2* pHDfXls)
{
    pHDfXls->InitForm();

    COmdFile0 fOmd;
    CFileException fx;
    BeginWaitCursor();
    for (std::vector<CString>::iterator itfPaths = m_omdFilesList.begin(); itfPaths != m_omdFilesList.end(); ++itfPaths)
    {
        //在此，等同於Doc的開啟舊檔As omd
        if(!fOmd.Open(*itfPaths, fx))
            AfxMessageBox("路徑有問題");
        else
        {
            fOmd.oOmdData(m_omd2xls);

            pHDfXls->iCellNO (abs(itfPaths - m_omdFilesList.begin()));
            pHDfXls->iChannel(fOmd.GetCHID());
            pHDfXls->iPanelID(fOmd.GetPnlID());
            pHDfXls->iProb   (fOmd.GetPrb());
			pHDfXls->iNitsLv (fOmd.GetNitsLv());
            pHDfXls->iData   (m_omd2xls);

            fOmd.Close();
        }
    }
    EndWaitCursor();
}

void CSelExcelDlg::thisOmd2xls(CXlsFile2* pDocfXls)
{
    pDocfXls->InitForm();
    pDocfXls
		->iCellNO(0)
		->iChannel(m_pDoc->GetFileHead().oCHID())
		->iPanelID(m_pDoc->GetFileHead().oPnlID())
		->iProb   (m_pDoc->GetFileHead().oPrb())
		->iNitsLv (m_pDoc->GetFileHead().oNitsLv());//->iData(m_pDoc->GetOmdData());
}

