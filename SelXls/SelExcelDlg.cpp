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
    //����{���ؿ��U��.xls���
    WIN32_FIND_DATA FindFileData;  //�@�ӵ��c�A��쪺�ɮ�
    HANDLE hListFile;
    
    m_strXlsFilePath.Empty(); 
    CString strFilePathType;  //�n�䪺�ɮ�����+���|
    
    ///�]�w�Ҧb�ؿ�
    GetModuleFileName(NULL, m_strXlsFilePath.GetBuffer(MAX_PATH+1), MAX_PATH);  //�����ε{���Ҧb���ؿ�+�ɦW+���ɦW
    m_strXlsFilePath.ReleaseBuffer();
    m_strXlsFilePath = m_strXlsFilePath.Left(m_strXlsFilePath.ReverseFind('\\'));
    strFilePathType.Format("%s\\*.%s", m_strXlsFilePath, FileNameExt);         //�ثe�����ɩҦb���|\*.xls
    
    //��Ĥ@���ɮ�
    hListFile = FindFirstFile(strFilePathType.GetBuffer(0), &FindFileData);
    
    //��xls�ɮת��ʧ@
    //�]�w�U�Ԧ���檺�i����
    //���ت��
    ComboBox.ResetContent();
    ComboBox.AddString("RA Form");  //0
    ComboBox.AddString("SEC Form"); //1

    //�~�[���
    if(hListFile == INVALID_HANDLE_VALUE)
    {
        //�䤣���ɮ�
        //strFilePathType�]�Τ���F�I������ܿ��~�T���a�I
        strFilePathType.Format("���~: %d\n%s\n�䤣��.xls�ɮ�, �L�k��XExcel!!", GetLastError(), m_strXlsFilePath);
        MessageBox(strFilePathType, NULL, MB_ICONWARNING | MB_OK);
        strFilePathType.Format("");
    }
    else
    {
        //��W���Excel�U�Ԧ���檺���
        
        do ComboBox.AddString(FindFileData.cFileName);
        while(FindNextFile(hListFile, &FindFileData));
        //�`��
        //         strFilePathType.Format("���~%d", m_cbxExcelSelor.GetCount());
        //         MessageBox(strFilePathType);
    }
    ComboBox.SetCurSel(0);
    OnSelectXlsForm() ;
    //�{���즹�����A�U�����O����
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
    //��Radio��֭ܽnenable�A�֤��n
    m_rdoChooseNowFile.SetCheck(!WFCF);
    m_rdoChooseHDFile.SetCheck(WFCF);

    m_lstSelOmdFileList.EnableWindow(WFCF);
    m_btnFindFile.EnableWindow(WFCF);
    m_stcHDFileList.EnableWindow(WFCF);
}

void CSelExcelDlg::OnSelectXlsForm() 
{
    // TODO: Add your control notification handler code here
    //�U�Ԧ�����ܮɪ��ʧ@
    CString str;
    m_lstSelOmdFileList.ResetContent();
    m_cbxExcelSelor.GetLBText(m_cbxExcelSelor.GetCurSel(), str);

    if (str.Find("RA") != -1)
    {
        m_strItemOfExcel.Format("9�I�G��\n9�I���\n\nCA210-CH\nCA210-Probe\n"); 
        m_fileNumLimit = 100;
        m_ft = FORM_RA;
        m_btnOK.EnableWindow(TRUE);
    }
    else if (str.Find("F1") != -1 || str.Find("H1") != -1 || str.Find("F6") != -1 || str.Find("H6") != -1 || str.Find("OQC") != -1)
    {
        m_strItemOfExcel.Format("9�I�G��\n9�I���\n25�I�t�A\n�����I���\n5Nits\n\n�Ƕ�����\nCA210-CH\nFLICKER");
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
        m_strItemOfExcel.Format("9�I�G��\n9�I�t�A\n�����I���\n5Nits\n\n�Ƕ�����\nCA210-CH\nFLICKER\nCross Talk");
        m_fileNumLimit = 1;
        m_ft = FORM_SEC;
        m_btnOK.EnableWindow(TRUE);
    }
    else
    {
        m_strItemOfExcel.Format("(�L�k�ѧO)");
        m_fileNumLimit = 1;
        m_ft = FORM_Nothing;
        m_btnOK.EnableWindow(FALSE);
    }

    UpdateData(FALSE);
}

void CSelExcelDlg::OnFindOmdFile() 
{
    // TODO: Add your control notification handler code here
    //��omd�ɮת��ʧ@
    CString fOmdFilter("OrigMsrData Files (*.omd)|*.omd|Text File(*.txt)|*.txt|All Files (*.*)|*.* ||");//�ɮ׹L�o����
    CFileDlg aFileDialog (TRUE, NULL, NULL, \
                          (m_fileNumLimit > 1) ? OFN_ALLOWMULTISELECT | OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT \
                                               : OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, fOmdFilter);
    
    aFileDialog.SetMultiFileNameBuffer(m_fileNumLimit);
    
    int nID = aFileDialog.DoModal();
    if (nID == IDOK)
        aFileDialog.GetSelFileList(m_vOmdFilePathList);    

    if(CommDlgExtendedError() == FNERR_BUFFERTOOSMALL) 
        AfxMessageBox("Sel Excel Dialog�w�İϤ����j\n�ŤU�e���A�åB��{���]�p�v�ѨM�o���D�C", MB_OK | MB_ICONERROR); 
    else
        m_lstSelOmdFileList.ResetContent();

    //�ɮצC��˦b����W
    for (std::vector<CString>::iterator itStr = m_vOmdFilePathList.begin(); itStr != m_vOmdFilePathList.end(); ++itStr)
    {
        //��ܮɷ|�̪��A�δX��Omd�ɪ��ƶq�A������C
        if (itStr - m_vOmdFilePathList.begin() < m_fileNumLimit)
            m_lstSelOmdFileList.AddString(itStr->Right(itStr->GetLength() - itStr->ReverseFind('\\') - 1));
        else
        {
            //�W�L���i�H�˸��ƶq�A�N�R���C
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
        default:                AfxMessageBox("���|��o�@�ӿ�X�H");
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
        //�b���A���P��Doc���}������As omd
        if(!fOmd.Open(*itfPaths, fx))
            AfxMessageBox("���|�����D");
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

