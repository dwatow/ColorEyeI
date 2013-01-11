// CaSetupDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CaSetupDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCaSetupDlg dialog


CCaSetupDlg::CCaSetupDlg(CWnd* pParent /*=NULL*/)
: CDialog(CCaSetupDlg::IDD, pParent)//, m_pMainFrm(dynamic_cast<CMainFrame*>(AfxGetMainWnd()))
{
	BeginWaitCursor();
	CMainFrame* pMainFrm = dynamic_cast<CMainFrame*>(AfxGetMainWnd());
    ASSERT_VALID(pMainFrm);
	pMainFrm->m_pCa210->SetOnline(TRUE);
	pMainFrm->m_pCa210->LinkMemory();
    m_pCA210 = pMainFrm->m_pCa210;
    //{{AFX_DATA_INIT(CCaSetupDlg)
    m_strCaType = _T("");
    m_strCaVersion = _T("");
    m_strCalMode = _T("");
    m_strCalProb = _T("");
    m_strProbSerialNo = _T("");
    m_strRefLv = _T("");
    m_strRefProb = _T("");
    m_strRefSx = _T("");
    m_strRefSy = _T("");
	m_fltRangeColor1 = 0.1f;
	m_fltRangeColor2 = 0.1f;
	m_fltRangeFlk = 0.1f;
	//}}AFX_DATA_INIT
}


void CCaSetupDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CCaSetupDlg)
	DDX_Control(pDX, IDC_COMBO_BRIG_UNIT, m_cbxBrigUnit);
	DDX_Control(pDX, IDC_COMBO_SYNC_MODE, m_cbxSynMode);
	DDX_Control(pDX, IDC_COMBO_DISPLAY_MODE, m_cbxDisMode);
	DDX_Control(pDX, IDC_COMBO_DISPLAY_DIGITS_MODE, m_cbxDisDigMode);
	DDX_Control(pDX, IDC_COMBO_DISPLAY_DEFAULT_STD, m_cbxDisCalStand);
	DDX_Control(pDX, IDC_COMBO_CHANNEL_NUMBER, m_cbxChNo);
	DDX_Control(pDX, IDC_COMBO_CHANNEL_ID, m_cbxChId);
	DDX_Control(pDX, IDC_COMBO_AVERAGING_MODE, m_cbxAvgMode);
    DDX_Text(pDX, IDC_STATIC_CA_TYPE, m_strCaType);
    DDX_Text(pDX, IDC_STATIC_CA_VERSION, m_strCaVersion);
    DDX_Text(pDX, IDC_STATIC_CAL_MODE, m_strCalMode);
    DDX_Text(pDX, IDC_STATIC_CAL_PROB, m_strCalProb);
    DDX_Text(pDX, IDC_STATIC_PROB_SNO, m_strProbSerialNo);
    DDX_Text(pDX, IDC_STATIC_REF_LV, m_strRefLv);
    DDX_Text(pDX, IDC_STATIC_REF_PROB, m_strRefProb);
    DDX_Text(pDX, IDC_STATIC_REF_X, m_strRefSx);
    DDX_Text(pDX, IDC_STATIC_REF_Y, m_strRefSy);
	DDX_Text(pDX, IDC_EDIT_DISPLAY_RANGE_COLOR1, m_fltRangeColor1);
	DDV_MinMaxFloat(pDX, m_fltRangeColor1, 0.1f, 99.f);
	DDX_Text(pDX, IDC_EDIT_DISPLAY_RANGE_COLOR2, m_fltRangeColor2);
	DDV_MinMaxFloat(pDX, m_fltRangeColor2, 0.1f, 99.f);
	DDX_Text(pDX, IDC_EDIT_DISPLAY_RANGE_FLICKER, m_fltRangeFlk);
	DDV_MinMaxFloat(pDX, m_fltRangeFlk, 0.1f, 99.f);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCaSetupDlg, CDialog)
    //{{AFX_MSG_MAP(CCaSetupDlg)
	ON_CBN_SELCHANGE(IDC_COMBO_CHANNEL_ID, OnSelchangeComboChannelId)
	ON_CBN_SELCHANGE(IDC_COMBO_CHANNEL_NUMBER, OnSelchangeComboChannelNumber)
	ON_CBN_SELCHANGE(IDC_COMBO_DISPLAY_MODE, OnSelchangeComboDisplayMode)
	ON_CBN_SELCHANGE(IDC_COMBO_SYNC_MODE, OnSelchangeComboSyncMode)
	ON_CBN_SELCHANGE(IDC_COMBO_AVERAGING_MODE, OnSelchangeComboAveragingMode)
	ON_CBN_SELCHANGE(IDC_COMBO_BRIG_UNIT, OnSelchangeComboBrigUnit)
	ON_CBN_SELCHANGE(IDC_COMBO_DISPLAY_DIGITS_MODE, OnSelchangeComboDisplayDigitsMode)
	ON_CBN_SELCHANGE(IDC_COMBO_DISPLAY_DEFAULT_STD, OnSelchangeComboDisplayDefaultStd)
	ON_WM_SHOWWINDOW()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCaSetupDlg message handlers

void CCaSetupDlg::OnOK() 
{
    // TODO: Add extra validation here
    ExitDlg();
    //CDialog::OnOK();
}

void CCaSetupDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	ExitDlg();
	//CDialog::OnOK();
}

void CCaSetupDlg::ExitDlg()
{
	ShowWindow(SW_HIDE);
}

BOOL CCaSetupDlg::OnInitDialog() 
{
    CDialog::OnInitDialog();

    // TODO: Add extra initialization here

// 	m_pCA210->SetOnline(TRUE);
// 	m_pCA210->LinkMemory();
	

	int i;
	for (i = 0; i <= 4; ++i)
		m_cbxSynMode.AddString(m_pCA210->GetSynMode((SynMode)i));
	for (i = 0; i <= 8; ++i)
		m_cbxDisMode.AddString(m_pCA210->GetDisplayMode((DisPlay)i));
	for (i = 0; i <= 1; ++i)
		m_cbxDisDigMode.AddString(m_pCA210->GetDisplayDigits((DisDigits)i));
	for (i = 0; i <= 2; ++i)
		m_cbxAvgMode.AddString(m_pCA210->GetAvgingMode((AvgMode)i));
	for (i = 0; i <= 1; ++i)
		m_cbxBrigUnit.AddString(m_pCA210->GetBrigUnit((BrigUnit)i));
	for (i = 1; i <= 1+1; ++i)
		m_cbxDisCalStand.AddString(m_pCA210->GetCalStandard((CalStand)i));

	for (long li = 0; li< 100; ++li)
	{
		m_pCA210->SetChNo(li);
		m_cbxChId.AddString((m_pCA210->GetChId().IsEmpty()) ? m_pCA210->GetChStrNo() : m_pCA210->GetChId());

		m_cbxChNo.AddString(m_pCA210->GetChStrNo());
	}

	UpdateAllSetup();

	EndWaitCursor();
	
    return TRUE;  // return TRUE unless you set the focus to a control
                  // EXCEPTION: OCX Property Pages should return FALSE
}

void CCaSetupDlg::UpdateAllSetup()
{
    m_strCaType        = m_pCA210->GetDeviceType();
    m_strCaVersion     = m_pCA210->GetCaVersion();
    m_strProbSerialNo  = m_pCA210->GetProb();
	
    m_strRefProb       = m_pCA210->GetRefProbe();
    m_strCalMode       = m_pCA210->GetCalMode();
    m_strCalProb       = m_pCA210->GetCalProbe();
	
    m_strRefLv         = m_pCA210->GetRefLv();
    m_strRefSx         = m_pCA210->GetRefSx();
    m_strRefSy         = m_pCA210->GetRefSy();

	m_fltRangeColor1   = m_pCA210->GetRangeColor1();
	m_fltRangeColor2   = m_pCA210->GetRangeColor2();
	m_fltRangeFlk      = m_pCA210->GetRangeFAM();
	UpdateData(FALSE);

	m_cbxSynMode.SetCurSel((int)m_pCA210->GetSynMode());
    m_cbxDisMode.SetCurSel(m_pCA210->GetDisplayMode());
	m_cbxDisDigMode.SetCurSel(m_pCA210->GetDisplayDigits());
	m_cbxAvgMode.SetCurSel(m_pCA210->GetAvgingMode());
	m_cbxDisCalStand.SetCurSel(m_pCA210->GetCalStandard()-1);
	m_cbxBrigUnit.SetCurSel(m_pCA210->GetBrigUnit());
	m_cbxChId.SetCurSel(m_pCA210->GetChNo());
	m_cbxChNo.SetCurSel(m_pCA210->GetChNo());
}

void CCaSetupDlg::OnSelchangeComboChannelId() 
{
	// TODO: Add your control notification handler code here
	long Ch = (long)m_cbxChId.GetCurSel();
	m_pCA210->SetChNo(Ch);
	m_pCA210->SetLcmSize("");
	UpdateAllSetup();
}

void CCaSetupDlg::OnSelchangeComboChannelNumber() 
{
	// TODO: Add your control notification handler code here
	long Ch = (long)m_cbxChNo.GetCurSel();
	m_pCA210->SetChNo(Ch);
	m_pCA210->SetLcmSize("");
	UpdateAllSetup();
}

void CCaSetupDlg::OnSelchangeComboDisplayMode() 
{
	// TODO: Add your control notification handler code here
	m_pCA210->SetDisplayMode((DisPlay)m_cbxDisMode.GetCurSel());
	UpdateAllSetup();
}

void CCaSetupDlg::OnSelchangeComboSyncMode() 
{
	// TODO: Add your control notification handler code here
	m_pCA210->SetSynMode((SynMode)m_cbxSynMode.GetCurSel());
	UpdateAllSetup();
}

void CCaSetupDlg::OnSelchangeComboAveragingMode() 
{
	// TODO: Add your control notification handler code here
	m_pCA210->SetAvgingMode((AvgMode)m_cbxAvgMode.GetCurSel());
	UpdateAllSetup();
}

void CCaSetupDlg::OnSelchangeComboBrigUnit() 
{
	// TODO: Add your control notification handler code here
	m_pCA210->SetBrigUnit((BrigUnit)m_cbxBrigUnit.GetCurSel());
	UpdateAllSetup();
}

void CCaSetupDlg::OnSelchangeComboDisplayDigitsMode() 
{
	// TODO: Add your control notification handler code here
	m_pCA210->SetDisplayDigits((DisDigits)m_cbxDisDigMode.GetCurSel());
	UpdateAllSetup();
}

void CCaSetupDlg::OnSelchangeComboDisplayDefaultStd() 
{
	// TODO: Add your control notification handler code here
	m_pCA210->SetCalStandard((CalStand)(m_cbxDisCalStand.GetCurSel()+1));
	UpdateAllSetup();
}

void CCaSetupDlg::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialog::OnShowWindow(bShow, nStatus);

	// TODO: Add your message handler code here
// 	CString str;
// 	str.Format("bShow = %d , nState = %d", bShow, nStatus);
// 	MessageBox(str);
		m_pCA210->SetOnline(bShow);	
}
