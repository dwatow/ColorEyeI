// SelExcelDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ColorEyeI.h"
#include "SelExcelDlg.h"
#include "MainFrm.h"
#include "ColorEyeIDoc.h"
#include "ColorEyeI.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSelExcelDlg dialog


CSelExcelDlg::CSelExcelDlg(CWnd* pParent /*=NULL*/)
    : CDialog(CSelExcelDlg::IDD, pParent)
{
    EnableAutomation();
    //{{AFX_DATA_INIT(CSelExcelDlg)
    m_xlsDescrip = _T("");
    //}}AFX_DATA_INIT
}



void CSelExcelDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CSelExcelDlg)
    DDX_Control(pDX, IDOK, m_tran2Xls);
    DDX_Control(pDX, IDC_LIST_SELFILELIST, m_lstSelOmdFileList);
    DDX_Control(pDX, IDC_STATIC_HDFILELIST, m_stcHDFileList);
    DDX_Control(pDX, IDC_RADIO_HDFILE, m_rdoChooseHDFile);
    DDX_Control(pDX, IDC_COMBO_EXCELSELER, m_cbxExcelSelor);
    DDX_Control(pDX, IDC_RADIO_NOWFILE, m_rdoChooseNowFile);
    DDX_Control(pDX, IDC_BUTTON_FINDFILE, m_btnFindFile);
    DDX_Text(pDX, IDC_STATIC_XLSDESCRIP, m_xlsDescrip);
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

// BEGIN_DISPATCH_MAP(CSelExcelDlg, CDialog)
// //{{AFX_DISPATCH_MAP(CSelExcelDlg)
// // NOTE - the ClassWizard will add and remove mapping macros here.
// //}}AFX_DISPATCH_MAP
// END_DISPATCH_MAP()
// 
// // Note: we add support for IID_ISelExcelDlg to support typesafe binding
// //  from VBA.  This IID must match the GUID that is attached to the 
// //  dispinterface in the .ODL file.
// 
// // {1898EEAC-B573-4CD6-90FA-92D98663C79E}
// static const IID IID_ISelExcelDlg =
// { 0x1898eeac, 0xb573, 0x4cd6, { 0x90, 0xfa, 0x92, 0xd9, 0x86, 0x63, 0xc7, 0x9e } };
// 
// BEGIN_INTERFACE_MAP(CSelExcelDlg, CDialog)
// INTERFACE_PART(CSelExcelDlg, IID_ISelExcelDlg, Dispatch)
// END_INTERFACE_MAP()
/////////////////////////////////////////////////////////////////////////////
// CSelExcelDlg message handlers

BOOL CSelExcelDlg::OnInitDialog() 
{
    CDialog::OnInitDialog();
    
    // TODO: Add extra initialization here
    setOmdComeFrom(ThisFile);
    initSelXlsCbx("xls");

    return TRUE;  // return TRUE unless you set the focus to a control
                  // EXCEPTION: OCX Property Pages should return FALSE
}

const CString CSelExcelDlg::reconstructSearchXlsPath(const CString& XlsNameExt)
{
	CColorEyeIApp* pApp = dynamic_cast<CColorEyeIApp*>(AfxGetApp());
	ASSERT_VALID(pApp);

    //����{���ؿ��U��.xls���
	return pApp->GetPath() + "\\" + XlsNameExt;  //�ثe�����ɩҦb���|/*.xls
}

void CSelExcelDlg::initSelXlsCbx(const CString& XlsNameExt)
{
    //��Ĥ@���ɮ�
	WIN32_FIND_DATA FindFileData;  //�@�ӵ��c�A��쪺�ɮ�
    HANDLE hListFile;

    hListFile = FindFirstFile(reconstructSearchXlsPath(XlsNameExt), &FindFileData);

    //��xls�ɮת��ʧ@
    //�]�w�U�Ԧ���檺�i����
    //���ت��
    m_cbxExcelSelor.ResetContent();
    m_cbxExcelSelor.AddString("RA Form");  //0
    m_cbxExcelSelor.AddString("SEC Form"); //1

    //�~�[���
    if(hListFile != INVALID_HANDLE_VALUE)
    {
        //��W���Excel�U�Ԧ���檺���
        do m_cbxExcelSelor.AddString(FindFileData.cFileName);
        while(FindNextFile(hListFile, &FindFileData));
    }
    m_cbxExcelSelor.SetCurSel(0);
    OnSelectXlsForm();
}

void CSelExcelDlg::OnRadioNowfile() 
{
    // TODO: Add your control notification handler code here
    setOmdComeFrom(ThisFile);
}

void CSelExcelDlg::OnRadioHdfile() 
{
    // TODO: Add your control notification handler code here
    setOmdComeFrom(OtherFile);
}

void CSelExcelDlg::setOmdComeFrom(enum WhereFileComeFrom WFCF)
{
    //��Radio��֭ܽnenable�A�֤��n
    m_rdoChooseNowFile.SetCheck(!WFCF);
    m_rdoChooseHDFile.SetCheck(WFCF);

    m_lstSelOmdFileList.EnableWindow(WFCF);
    m_btnFindFile.EnableWindow(WFCF);
    m_stcHDFileList.EnableWindow(WFCF);
}

void CSelExcelDlg::setSelXlsDetail(const LPCTSTR& _S, const int& _I, const FormType& _F, const BOOL& _B)
{
    m_xlsDescrip.Format(_S); 
    m_openOmdLimit = _I;
    m_ft = _F;
    m_tran2Xls.EnableWindow(_B);
}

void CSelExcelDlg::OnSelectXlsForm() 
{
    // TODO: Add your control notification handler code here
    //�U�Ԧ�����ܮɪ��ʧ@
    CString str;
    m_lstSelOmdFileList.ResetContent();
    m_cbxExcelSelor.GetLBText(m_cbxExcelSelor.GetCurSel(), str);

         if (str.Find("RA") != -1)     setSelXlsDetail("9�I�G��\n9�I���\n\nCA210-CH\nCA210-Probe\n", 100, FM_RA); 
    else if (str.Find("OQC") != -1)       setSelXlsDetail("2013�~�ղ����\n9�I�G��סB�����I�G��סB5Nits\n25�I�t�A\n21�I�t�A\nCrossTalk\nCrossTalk\nColor Gamu\n\n�Ƕ�����\nCA210-CH\nFlicker", 10, FM_OQC_Test); 
    else if (str.Find("Y2013") != -1)  setSelXlsDetail("2013�~�q�����\n9�I�G��\n25�I�t�A\n�����I�G���\n5Nits\n21�I�t�A\nCrossTalk\nCrossTalk\nColor Gamu\n\n�Ƕ�����\nCA210-CH\nFlicker", 10, FM_OQCY2013_Volume); 
    else if (str.Find("Gamma") != -1)  setSelXlsDetail("Gamma curve", 5, FM_Gamma); 
    else if (str.Find("SEC") != -1)       setSelXlsDetail("9�I�G��\n9�I�t�A\n�����I���\n5Nits\n\n�Ƕ�����\nCA210-CH\nFLICKER\nCross Talk", 1, FM_SEC); 
    else                               setSelXlsDetail("(�L�k�ѧO)", 1, FM_Nothing, FALSE); 

    UpdateData(FALSE);
}

void CSelExcelDlg::findOtherOmdFile(std::vector<CString>& fileList)
{
    CString fOmdFilter("OrigMsrData Files (*.omd)|*.omd|Text File(*.txt)|*.txt|All Files (*.*)|*.* ||");//�ɮ׹L�o����
    CFileDlg aFileDialog (TRUE, NULL, NULL, \
        ( m_openOmdLimit > 1 ) ? OFN_ALLOWMULTISELECT | OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT \
        : OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, fOmdFilter);
    
    aFileDialog.SetSelMultiFileTotal(m_openOmdLimit);  //�]�w�i�H��X���ɮסC
    
    if (aFileDialog.DoModal() == IDOK)
        aFileDialog.GetSelFileList(fileList);
    
    if(CommDlgExtendedError() == FNERR_BUFFERTOOSMALL) 
        AfxMessageBox("Sel Excel Dialog�w�İϤ����j\n�ŤU�e���A�åB��{���]�p�v�ѨM�o���D�C", MB_OK | MB_ICONERROR); 
    else
        m_lstSelOmdFileList.ResetContent();
}

void CSelExcelDlg::showOtherOmdList(std::vector<CString>& fileList)
{
    for (std::vector<CString>::iterator itStr = fileList.begin(); itStr != fileList.end(); ++itStr)
    {
        //��ܮɷ|�̪��A�δX��Omd�ɪ��ƶq�A������C
        if (itStr - fileList.begin() < m_openOmdLimit)
            m_lstSelOmdFileList.AddString(itStr->Right(itStr->GetLength() - itStr->ReverseFind('\\') - 1));
        else
        {
            fileList.erase(itStr, fileList.end());  //�W�L���i�H�˸��ƶq�A�N�R���C
            break;
        }
    }
}
void CSelExcelDlg::OnFindOmdFile()
{
    // TODO: Add your control notification handler code here
    findOtherOmdFile(m_omdFilesList);  //��omd�ɮת��ʧ@
    showOtherOmdList(m_omdFilesList);  //�ɮצC��˦b����W
}

void CSelExcelDlg::OnOK()
{
    BeginWaitCursor();
        CXlsFile2* pfXls = 0;
        initXlsObj(pfXls);

        if (pfXls != 0)
            delete pfXls;

    EndWaitCursor();
    CDialog::OnOK();
}

void CSelExcelDlg::initXlsObj(CXlsFile2* pfXls)
{
    switch(m_ft)
    {
    case FM_SEC:             pfXls = new CXlsSEC1 (); pfXls->New()->SetSheetName(1,"SEC Report");                   break;
    case FM_RA:              pfXls = new CXlsRA1  (); pfXls->New()->SetSheetName(1,"RA Report");                    break;    
    case FM_OQC_Test:        pfXls = new CXlsOQC2 (); pfXls->Open(getCurSelXlsPath())->SetSheetName(1, "OQC SPEC");   break;
    case FM_OQCY2013_Volume: pfXls = new CXlsOQC1 (); pfXls->Open(getCurSelXlsPath())->SetSheetName(1, "����");        break;
    case FM_Gamma:           pfXls = new CXlsGamma(); pfXls->Open(getCurSelXlsPath())->SetSheetName(1, "Color Data"); break;
    case FM_Nothing:
    default:                AfxMessageBox("���|��o�@�ӿ�X�H");
    }
}

const CString CSelExcelDlg::getCurSelXlsPath() const
{
	CColorEyeIApp* pApp = dynamic_cast<CColorEyeIApp*>(AfxGetApp());
	ASSERT_VALID(pApp);

    CString xlsSelNamePath;
    m_cbxExcelSelor.GetLBText(m_cbxExcelSelor.GetCurSel(), xlsSelNamePath);   //ComboBox -> file name
    return pApp->GetPath() + "\\" + xlsSelNamePath;
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
        //�b���A���P��Doc���}������As omd
        if(!fOmd.Open(*itfPaths, fx))
            AfxMessageBox("���|�����D");
        else
        {
            pHDfXls->iCellNO (abs(itfPaths - m_omdFilesList.begin()));
            pHDfXls->iChannel(fOmd.GetCHID());
            pHDfXls->iPanelID(fOmd.GetPnlID());
            pHDfXls->iProb   (fOmd.GetPrb());
            pHDfXls->iNitsLv (fOmd.GetNitsLv());
            pHDfXls->iData   (fOmd.oOmdData());

            fOmd.Close();
        }
    }
    EndWaitCursor();
}

void CSelExcelDlg::thisOmd2xls(CXlsFile2* pDocfXls)
{
    CMainFrame*    m_pMainFrm = dynamic_cast<CMainFrame*>(AfxGetMainWnd());
    CColorEyeIDoc* m_pDoc     = dynamic_cast<CColorEyeIDoc*>(m_pMainFrm->GetActiveDocument());

    ASSERT_VALID(m_pMainFrm);
    ASSERT_VALID(m_pDoc);

    pDocfXls->InitForm();
    pDocfXls->iCellNO (0)
            ->iChannel(m_pDoc->GetFileHead().oCHID())
            ->iPanelID(m_pDoc->GetFileHead().oPnlID())
            ->iProb   (m_pDoc->GetFileHead().oPrb())
            ->iNitsLv (m_pDoc->GetFileHead().oNitsLv())
			->iData   (m_pDoc->GetDocRNA());
}
