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


CSelExcelDlg::CSelExcelDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSelExcelDlg::IDD, pParent),
	pMainFrm(dynamic_cast<CMainFrame*>(AfxGetMainWnd())), pDoc(dynamic_cast<CColorEyeIDoc*>(pMainFrm->GetActiveDocument()))

{
	EnableAutomation();
	ASSERT_VALID(pMainFrm);
	ASSERT_VALID(pDoc);
	
	//{{AFX_DATA_INIT(CSelExcelDlg)
	m_strItemOfExcel = _T("");
	//}}AFX_DATA_INIT
}


void CSelExcelDlg::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CDialog::OnFinalRelease();
}

void CSelExcelDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSelExcelDlg)
	DDX_Control(pDX, IDOK, m_btnOK);
	DDX_Control(pDX, IDC_STATIC_HDFILELIST, m_stcHDFileList);
	DDX_Control(pDX, IDC_RADIO_HDFILE, m_rdoChooseHDFile);
	DDX_Control(pDX, IDC_COMBO_EXCELSELER, m_cbxExcelSelor);
	DDX_Control(pDX, IDC_RADIO_NOWFILE, m_rdoChooseNowFile);
	DDX_Control(pDX, IDC_LIST_SELFILELIST, m_lstSelFileList);
	DDX_Control(pDX, IDC_BUTTON_FINDFILE, m_btnFindFile);
	DDX_Text(pDX, IDC_STATIC_ITEMLIST, m_strItemOfExcel);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSelExcelDlg, CDialog)
	//{{AFX_MSG_MAP(CSelExcelDlg)
	ON_CBN_SELCHANGE(IDC_COMBO_EXCELSELER, OnSelchangeComboExcelseler)
	ON_BN_CLICKED(IDC_BUTTON_FINDFILE, OnButtonFindfile)
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
//	HDFileCouont = 0;

	GetCurFileList(m_cbxExcelSelor, "xls");

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSelExcelDlg::GetCurFileList(CComboBox& ComboBox, CString FileNameExt)
{
	//����{���ؿ��U��.xls���
	WIN32_FIND_DATA FindFileData;  //�@�ӵ��c�A��쪺�ɮ�
	HANDLE hListFile;
	
	m_strXlsPath.Empty(); 
	CString strFilePathType;  //�n�䪺�ɮ�����+���|
	
	///�]�w�Ҧb�ؿ�
	GetModuleFileName(NULL, m_strXlsPath.GetBuffer(MAX_PATH+1), MAX_PATH);  //�����ε{���Ҧb���ؿ�+�ɦW+���ɦW
	m_strXlsPath.ReleaseBuffer();
	m_strXlsPath = m_strXlsPath.Left(m_strXlsPath.ReverseFind('\\'));
	strFilePathType.Format("%s\\*.%s", m_strXlsPath, FileNameExt);         //�ثe�����ɩҦb���|\*.xls
	
	//��Ĥ@���ɮ�
	hListFile = FindFirstFile(strFilePathType.GetBuffer(0), &FindFileData);
	
	//��xls�ɮת��ʧ@
	//�]�w�U�Ԧ���檺�i����
	//���ت��
	ComboBox.ResetContent();
	ComboBox.AddString("RA Form");  //0

	//�~�[���
	if(hListFile == INVALID_HANDLE_VALUE)
	{
		//�䤣���ɮ�
		//strFilePathType�]�Τ���F�I������ܿ��~�T���a�I
		strFilePathType.Format("���~: %d\n%s\n�䤣��.xls�ɮ�, �L�k��XExcel!!", GetLastError(), m_strXlsPath);
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
	OnSelchangeComboExcelseler() ;
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

	m_lstSelFileList.EnableWindow(WFCF);
	m_btnFindFile.EnableWindow(WFCF);
	m_stcHDFileList.EnableWindow(WFCF);
}

void CSelExcelDlg::OnSelchangeComboExcelseler() 
{
	// TODO: Add your control notification handler code here
	//�U�Ԧ�����ܮɪ��ʧ@
	CString str;
	m_lstSelFileList.ResetContent();
	m_cbxExcelSelor.GetLBText(m_cbxExcelSelor.GetCurSel(), str);

	if (str.Find("RA") != -1)
	{
		m_strItemOfExcel.Format("9�I�G��\n9�I���\n\nCA210-CH\nCA210-Probe\n"); 
		m_nBufferSize = 100;
		m_ft = FORM_RA;
		m_btnOK.EnableWindow(TRUE);
	}
	else if (str.Find("F1") != -1 || str.Find("H1") != -1 || str.Find("F6") != -1 || str.Find("H6") != -1)
	{
		m_strItemOfExcel.Format("9�I�G��\n9�I���\n25�I�t�A\n�����I���\n5Nits\n\n�Ƕ�����\nCA210-CH\nFLICKER");
		m_nBufferSize = 10;
		m_ft = FORM_OQC_LCM_SPEC;
		m_btnOK.EnableWindow(TRUE);
	}
	else if (str.Find("Gamma") != -1)
	{
		m_strItemOfExcel.Format("Gamma curve");
		m_nBufferSize = 1;
		m_ft = FORM_Gamma;
		m_btnOK.EnableWindow(TRUE);
	}
	else
	{
		m_strItemOfExcel.Format("(�L�k�ѧO)");
		m_nBufferSize = 1;
		m_ft = FORM_Nothing;
		m_btnOK.EnableWindow(FALSE);
	}

	UpdateData(FALSE);
}

void CSelExcelDlg::OnButtonFindfile() 
{
	// TODO: Add your control notification handler code here
	//��omd�ɮת��ʧ@
	CString m_strFilter("OrigMsrData Files (*.omd)|*.omd|Text File(*.txt)|*.txt|All Files (*.*)|*.* ||");//�ɮ׹L�o����
	CFileDlg aFileDialog (TRUE, NULL, NULL, (m_nBufferSize > 1) ? OFN_ALLOWMULTISELECT | OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT : OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, m_strFilter);
	
	aFileDialog.SetMultiFileNameBuffer(m_nBufferSize);
	
    int nID = aFileDialog.DoModal();
    if (nID == IDOK)
		aFileDialog.GetSelFileList(m_vFilePathList);	

	if(CommDlgExtendedError() == FNERR_BUFFERTOOSMALL) 
        AfxMessageBox("Sel Excel Dialog�w�İϤ����j\n�ŤU�e���A�åB��{���]�p�v�ѨM�o���D�C", MB_OK | MB_ICONERROR); 
	else
		m_lstSelFileList.ResetContent();//�ɮצC��˦b����W


	for (std::vector<CString>::iterator itStr = m_vFilePathList.begin(); itStr != m_vFilePathList.end(); ++itStr)
	{
		if (itStr - m_vFilePathList.begin() < m_nBufferSize)
			m_lstSelFileList.AddString(itStr->Right(itStr->GetLength() - itStr->ReverseFind('\\') - 1));
		else
		{
			m_vFilePathList.erase(itStr, m_vFilePathList.end());
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
	NewVector();
	oChooseXls();
	CDialog::OnOK();
}

void CSelExcelDlg::oChooseXls()
{
	switch(m_ft)
	{
	case FORM_SEC:      formSEC();    break;
 	case FORM_RA:       formRA();     break;    
 	case FORM_OQC_LCM_SPEC:  formOQC();    break;    
 	case FORM_Gamma:    formGamma();  break;
	 
case FORM_Nothing:
default:
	AfxMessageBox("���|��o�@�ӿ�X�H");
	}
}

void CSelExcelDlg::formGamma()
{

}

void CSelExcelDlg::formOQC()
{
	CString strXlsFilePath;
	CString strFileName;
	m_cbxExcelSelor.GetLBText(m_cbxExcelSelor.GetCurSel(), strFileName);
	strXlsFilePath.Format("%s\\%s", m_strXlsPath, strFileName);

	CXlsOQC1 xlsOQC;
	xlsOQC.Open(strXlsFilePath).SetSheetName(1,"RAReport");

	if (m_rdoChooseHDFile.GetCheck() == FromHDFile)
	{
		m_pOmdfile = new COmdFile1;
   
		for (std::vector<CString>::iterator itfPaths = m_vFilePathList.begin(); itfPaths != m_vFilePathList.end(); ++itfPaths)
		{
			//�PC3Atemp
			m_pOmdfile->SetMsrData(m_vOmdtoXls);
			m_pOmdfile->Open(*itfPaths);
			m_vOmdtoXls = m_pOmdfile->GetMsrData();

			xlsOQC.iCellNO(itfPaths - m_vFilePathList.begin()).iBarCode(m_pOmdfile->GetPnlID()).iChannel(m_pOmdfile->GetCHID()).iData(m_vOmdtoXls);
		}
	}
    else
	{
        m_pOmdfile = &(pDoc->GetOmdFile());	//strXlsFilePath = AER�ѡMoR|+AE|W
		m_vOmdtoXls = m_pOmdfile->GetMsrData();
		xlsOQC.iCellNO(0).iBarCode(m_pOmdfile->GetPnlID()).iChannel(m_pOmdfile->GetCHID()).iData(m_vOmdtoXls);
	}
	xlsOQC.SetVisible(true);
}
void CSelExcelDlg::formSEC()
{

}

void CSelExcelDlg::formRA()
{
	CXlsRA1 xlsRA;
	xlsRA.New().SetSheetName(1,"RAReport");
	xlsRA.InitForm();
	if (m_rdoChooseHDFile.GetCheck() == FromHDFile)
	{
		m_pOmdfile = new COmdFile1;
		for (std::vector<CString>::iterator itfPaths = m_vFilePathList.begin(); itfPaths != m_vFilePathList.end(); ++itfPaths)
		{
			m_pOmdfile->SetMsrData(m_vOmdtoXls);
			m_pOmdfile->Open(*itfPaths);
			m_vOmdtoXls = m_pOmdfile->GetMsrData();

			xlsRA.iCellNO(itfPaths - m_vFilePathList.begin()).iChannel(m_pOmdfile->GetCHID()).iPanelID(m_pOmdfile->GetPnlID()).iProb(m_pOmdfile->GetPrb())\
				.iData(m_vOmdtoXls);
		}
	}
	else
	{
        m_pOmdfile = &(pDoc->GetOmdFile());	//strXlsFilePath = AER�ѡMoR|+AE|W
		m_vOmdtoXls = m_pOmdfile->GetMsrData();
		
		xlsRA.iCellNO(0).iChannel(m_pOmdfile->GetCHID()).iPanelID(m_pOmdfile->GetPnlID()).iProb(m_pOmdfile->GetPrb()).iData(m_vOmdtoXls);
	}
	xlsRA.SetVisible(true);
}



