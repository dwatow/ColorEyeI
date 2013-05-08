// PatternDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ColorEyeI.h"
#include "PatternDlg.h"

#include <cstdlib>
#include <ctime>
// #include "xMsrPoint.h"
#include "EnterValueDlg.h"
#include "ReadBarCodeDialog.h"
#include "TranScripter.h"
#include "MainFrm.h"
#include "ColorEyeIDoc.h"
#include "OmdHead.h"
#include "MsrTableDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#ifdef _DEBUG
#define DebugCode( code_fragment ) { code_fragment }
#else
#define DebugCode( code_fragment )
#endif
/////////////////////////////////////////////////////////////////////////////
// CPatternDlg dialog


CPatternDlg::CPatternDlg(const initType& it, CWnd* pParent /*=NULL*/)
: CDialog(CPatternDlg::IDD, pParent), InitDataType(it)
{
	//{{AFX_DATA_INIT(CPatternDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
    initCa210();
    initDataDlgType();
	
    TranScripter Ts;
    m_Goal.SetRadius(Ts.Cm2pixel(2.25));
}

void CPatternDlg::initCa210()
{
    CMainFrame* pMainFrm = dynamic_cast<CMainFrame*>(AfxGetMainWnd());
    ASSERT_VALID(pMainFrm);
    
    m_pCA210 = pMainFrm->m_pCa210;
    m_pCA210->SetOnline(TRUE);
    m_pCA210->LinkMemory();
    initLCMSize();
}

void CPatternDlg::initDataDlgType() const
{
    CDialog *dlgData = 0;

    switch(InitDataType)
    {
    case MsrForItem:  dlgData = new CMsrItemDlg();   break;
	case MsrForTable: dlgData = new CMsrTableDlg();  break;
	default:
		CString str("Pattern Dialog��l�ƶq����ƥX���D");
		AfxMessageBox(str);
    }

	ASSERT(dlgData);
	dlgData->DoModal();
	delete dlgData;
}

void CPatternDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPatternDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPatternDlg, CDialog)
	//{{AFX_MSG_MAP(CPatternDlg)
    ON_WM_CTLCOLOR()
    ON_WM_PAINT()
    ON_WM_TIMER()
    ON_WM_SHOWWINDOW()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPatternDlg message handlers

BOOL CPatternDlg::OnInitDialog() 
{
    // TODO: Add extra initialization here
    c_bStatusBar    = TRUE;

    c_bMsrBegin     = FALSE;
    c_bMsrEnd       = FALSE;
    c_bMsrEndnMsred = FALSE;
    c_bRunMsrAI     = TRUE;
    c_bUnCntCA210   = FALSE;

    ColorRef tempClr(255, 0, 127); //�`����
    m_Goal.SetArcColor(tempClr.Shift(5));

    return TRUE;  // return TRUE unless you set the focus to a control
                  // EXCEPTION: OCX Property Pages should return FALSE
}

HBRUSH CPatternDlg::OnCtlColor(CDC* , CWnd* , UINT ) 
{
    //�û������ݭn�ק�
    m_BkBrush.DeleteObject();
    m_BkBrush.CreateSolidBrush(m_BkColor.oRGB());
    return m_BkBrush;
}

void CPatternDlg::OnPaint() 
{
    /*
    NextGoal
    �B�@�Ѽ�
        Goal�T��
        NextGoal�T��
        iterator���T��
        ø�ϰѼ�
    ���A�C
        �ާ@����
        ���A
    �D�n�q������
        �ʤ������
        Goal
    �q���ؼЫ���
        �ƾ����
    zero cal���r
    end���r
    */

    const int wordHight(18);
    CPaintDC dc(this); // device context for painting
    CString temp;
    dc.SetBkMode(OPAQUE);
    dc.SetBkColor(m_BkColor.oRGB());

    if (m_itor->m_pBackGorund != 0)
        m_itor->m_pBackGorund->Draw(dc);
    //DrawCrsTlkRect(dc);

DebugCode(
          dc.SetTextColor(m_BkColor.Shift());

        int lineIndex(0);
        //Pattern�B�@�Ѽ�
        //Goal�T��
        temp.Format("  Goal%s", m_Goal.showMe());
        TextOut(dc, 0, wordHight*lineIndex++, temp, temp.GetLength());
        
        //��L�T��
//         KeyMessage.Format("nChar = %d, nRepCnt = %d, nFlags = %d", key1, key2, key3);
//         TextOut(dc, 0, wordHight*lineIndex++, KeyMessage, 40);

        //iterator���T��
        CString IsEndstr ( m_itor == m_RNA.Begin()? "Begin" : m_itor == m_RNA.End() ? "End" : "Other" );

        temp.Format("���N����T: itor.begin = 0x%x, itor.end = 0x%x, itor(��} / ��m) = 0x%x / %s", \
			m_RNA.Begin(), m_RNA.End(), m_itor, IsEndstr);
        TextOut(dc, 0, wordHight*lineIndex++, temp, temp.GetLength());

        temp.Format("PatternDlg�X��: IsShowGoal: %d, IsShowStateBar: %d, �Ĥ@�I = %d, �̫�@�I = %d, �̫�@�I�q�� = %d, �۰ʶq���Ҧ� = %d, �s��CA-210 = %d", \
                     m_Goal.isVisible(), c_bStatusBar, c_bMsrBegin, c_bMsrEnd, c_bMsrEndnMsred, !c_bRunMsrAI, c_bUnCntCA210);
        TextOut(dc, 0, wordHight*lineIndex++, temp, temp.GetLength());

        temp.Format("�o�@�I����T: %s", m_itor->ShowMe());
        TextOut(dc, 0, wordHight*lineIndex++, temp, temp.GetLength());
)

    //���A�C
    if (c_bStatusBar)
    {
        dc.SetTextColor(m_BkColor.Shift());
        //�ާ@�����]���^
        temp.Format("�W�@�I: ��, �U�@�I: ��, ���+�U�@�I: Enter, �۰ʶq��: ��");
        TextOut(dc, 0, GetSystemMetrics(SM_CYSCREEN) - wordHight*1, temp, temp.GetLength());
        //���A�]�k�^
        temp.Format("�s�u���A: %s, �ثe�q��: %s,  �ѪR��: %d��%d,  Channel: %s,  LCM size: %2.1f inch", \
            m_pCA210->isOnline() ? "�s�u" : "���u" , m_itor->GetDescrip(), GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), m_pCA210->GetChData(), m_pCA210->GetLcmSize());//LCM Size�o�˧�|�����D
        TextOut(dc, GetSystemMetrics(SM_CXSCREEN) - (int)(temp.GetLength()*6.7), GetSystemMetrics(SM_CYSCREEN) - wordHight*1, temp, temp.GetLength());
    }

    //�D�n�q������
    m_Goal.Draw(dc);//�q���ؼ�

    if (c_bMsrEnd && c_bRunMsrAI && c_bMsrEndnMsred)
    {
        temp.Format("��ESC���}�C");    
        dc.SetTextColor(m_BkColor.Invrt());
        if ((m_Goal.GetCenter().x == GetSystemMetrics(SM_CXSCREEN)/2) && (m_Goal.GetCenter().y == GetSystemMetrics(SM_CYSCREEN)/2))
            TextOut(dc, GetSystemMetrics(SM_CXSCREEN)/2 - 75, GetSystemMetrics(SM_CYSCREEN)/2-8-m_Goal.GetRadius()*2, temp, temp.GetLength());
        else
            TextOut(dc, GetSystemMetrics(SM_CXSCREEN)/2 - 75, GetSystemMetrics(SM_CYSCREEN)/2-8, temp, temp.GetLength());
    }

    if (c_bUnCntCA210)
        temp.Format("���s��CA-210�C");
    else
        temp.Format("");

    dc.SetTextColor(m_BkColor.Invrt());
    TextOut(dc, GetSystemMetrics(SM_CXSCREEN)/2 - 75, GetSystemMetrics(SM_CYSCREEN)/2-8, temp, temp.GetLength());

    // TODO: Add your message handler code here
    // Do not call CDialog::OnPaint() for painting messages
}

void CPatternDlg::initLCMSize() const
{
    if (atoi(m_pCA210->GetLcmSize()) == 0)
    {
        CEnterValueDlg dlgEnterValue("�L�k�P�OLCM Size", "LCM Size");

        if (dlgEnterValue.DoModal() == IDOK)
            m_pCA210->SetLcmSize(dlgEnterValue.m_strValue);
    }
}

void CPatternDlg::initDocument()
{
    CMainFrame* pMainFrm = dynamic_cast<CMainFrame*>(AfxGetMainWnd());
    ASSERT_VALID(pMainFrm);
    
    CColorEyeIDoc* pDoc = dynamic_cast<CColorEyeIDoc*>(pMainFrm->GetActiveDocument());
    ASSERT_VALID(pDoc);

	pDoc->GetFileHead().iCHID  ( pMainFrm->m_pCa210->GetChStrNo()    );
	pDoc->GetFileHead().iPrb   ( pMainFrm->m_pCa210->GetProb()       );
	pDoc->GetFileHead().iMsrDvc( pMainFrm->m_pCa210->GetDeviceType() );
	pDoc->GetFileHead().iInch  ( pMainFrm->m_pCa210->GetLcmSize()    );
	

    m_RNA  = pDoc->GetMsrRNA();
    m_itor = m_RNA.Begin();

    //SetPanelID
    if (m_RNA.Size())
    {
        CReadBarCodeDialog dlgReadBarCode;
        dlgReadBarCode.DoModal();
    }
}

void CPatternDlg::LoadedCartridge()
{
    // TODO: Add extra validation here
    m_Goal.SetWnd(GetActiveWindow()); //GetActiveWindow()�ݵ��غc�������~�i�H���
    initDocument();

    //MsrItem���U�u�T�w�v�٬O�u�����v
    if (m_RNA.IsEmpty())
        ShowWindow(SW_HIDE);
    else
    {
        //++BeginItor;
        trigger();

        ShowWindow(SW_MAXIMIZE);
        SetFocus();
    }
	checkMsrLimit();
}

void CPatternDlg::trigger()
{
    m_itor->m_pBackGorund->NT_SetWnd(GetActiveWindow());
    m_itor->m_pBackGorund->NT_SetCa(m_pCA210);

    //�ثe�o�@�I�O���O5nits�������I�H2=�O
    setBkColor(m_itor->GetBkColor());

    m_Goal.SetData(m_itor->GetBullet());
    m_Goal.SetPrcntColor(m_BkColor.Shift());

    m_Goal.SetCenter(m_itor->GetPointPosi());  //�v��m
    m_Goal.SetPercent(0);

    m_Goal.Animation();
}

void CPatternDlg::checkMsrLimit()
{
    c_bMsrBegin     = (  m_itor   == m_RNA.Begin()) ? TRUE : FALSE;
    c_bMsrEnd       = (  m_itor+1 == m_RNA.End()  ) ? TRUE : FALSE;
    c_bMsrEndnMsred = (  c_bMsrEnd && !m_itor->GetBullet().IsEmpty() ) ? TRUE : FALSE;//�Y�{�b�O�̫�@�I�A�åB�̫�@�I�w�g�q�F
}

BOOL CPatternDlg::PreTranslateMessage(MSG* pMsg) 
{
    // TODO: Add your specialized code here and/or call the base class
    if (pMsg->message == WM_KEYDOWN)
    {
        switch(pMsg->wParam)
        {
            case VK_SPACE:  eventSwCntCa210();    break;//�ť���G�����s�u
            case VK_DOWN:   eventRunMsrAi();      break;//�U   �G�۰ʶq���Ҧ�
            case VK_RIGHT:  eventGoNextGoal();    break;//�k   �G���U�@���I
            case VK_LEFT:   eventGoPrvsGoal();    break;//��   �G�W�@���I
            case VK_RETURN: eventCatchMsrValue(); break;//Enter�G��ȧ���!!!!
            case VK_ESCAPE: eventExitDialog();    break;//ESC  �G����Patten Dialog
        }
        return TRUE;
    }
    return CDialog::PreTranslateMessage(pMsg);
}

const CaState CPatternDlg::recoil()
{
    //�Ȧs�ثe���ù����/���ê��A
    BOOL OldDrawGold  = m_Goal.isVisible();
    BOOL OldStatusBar = c_bStatusBar;

    //�T�w�����Ҧ��ù����/���ê��A
    c_bStatusBar = FALSE;
    m_Goal.Visible(FALSE);

    Invalidate();
    UpdateWindow();

    Sleep(70);

    const CaState camsrResult(m_pCA210->Measure());

    m_itor->SetBullet(m_pCA210->GetMsrData());
	m_Goal.SetData(m_itor->GetBullet());

    //��_�ثe���ù����/���ê��A
    m_Goal.Visible(OldDrawGold);
    c_bStatusBar    = OldStatusBar;

    Invalidate();
    UpdateWindow();

    return camsrResult;
}

void CPatternDlg::OnTimer(UINT nIDEvent) 
{
    //�ˬd�s�u
//    c_bUnCntCA210 = FALSE;
    /*
        ��Ӫ��e
        1. �q�����e��
           0  �G��0�A�ثe0-Cal
           1  �зǪ��e�Ȥ��G�~��q��+�ʤ���� 2.
           2  �зǪ��e�ȥ~�G�~��q��-�ʤ���
           3  ���s�u

        2. �ʤ���
           0 �p��0
           1 �зǽd�� ��2.
           2 �j��100
    */
    if (m_pCA210->isOnline())
    {
        srand(time(NULL));
        switch( m_pCA210->MsrAI( (float)0.005 ) )
        //check isRemote, isZeroCal, isRightPosition, and
        //return a status to say is MsrAiValue in spec.
        {
            case MA_InDeviation://�зǪ��e�Ȥ��G�~��q��+�ʤ���
				msrKernel();
                break;
            case MA_OutDeviation://�зǪ��e�ȥ~�G�~��q��-�ʤ���
                m_Goal.SetPercent(m_Goal.GetPercent() - rand()%25+rand()%25+1);
                 //m_Percent -= rand()%25+rand()%25+1;
                break;
            case MA_nonMsr:
                eventRunMsrAi(FALSE);
                AfxMessageBox("�ˬd���Y�G�n���MEAS\n�ˬd�D���GREMOTE�O�n�G\n�i�H���Q�۰ʶq���I");
                break;
        }
        Invalidate();
        UpdateWindow();
    }
    else
        c_bUnCntCA210 = TRUE;
    CDialog::OnTimer(nIDEvent);
}

void CPatternDlg::msrKernel()
{
	int percent(m_Goal.GetPercent());
	if (percent < 0)
    {
		m_Goal.SetPercent(rand()%20+10);
    }
    else if (percent >= 0 && percent <100)
    {
		percent = m_Goal.GetPercent() + rand()%50+rand()%50+1;
		m_Goal.SetPercent(( percent > 100 ) ? 100 : percent);
    }
    else if (percent >= 100)
    {
		eventRunMsrAi(FALSE);
		if ((eventCatchMsrValue() == 1) //�̽������B�J
			|| (c_bMsrEndnMsred == FALSE))
			eventRunMsrAi(TRUE);
    }
    else
        ASSERT(0);
}

void CPatternDlg::eventGoPrvsGoal()
{
    //�W�@���I
    if (!c_bMsrBegin)
    {
        ++m_itor;
        if (m_itor != m_RNA.Begin())    m_itor--;
        if (m_itor != m_RNA.Begin())    m_itor--;
        
        trigger(); //���|����0�A�N�O�q�̫�@�^��^�@��  

        Invalidate();
    }
	checkMsrLimit();
	m_Goal.ShowLabel(TRUE);

}

BOOL CPatternDlg::eventGoNextGoal()
{
    //�U�@���I
    if (!c_bMsrEnd)
    {
        //�p��U�@��
        ++m_itor;
        if (m_itor == m_RNA.End()) m_itor--;
        if (m_itor == m_RNA.End()) m_itor--;

        //���s�e���+�ʵe
        trigger();
        Invalidate();
    }
	checkMsrLimit();
	m_Goal.ShowLabel(c_bMsrEndnMsred);

    return !c_bMsrEnd;
}

UINT CPatternDlg::eventCatchMsrValue()
{
    //��ȧ���!!!!
    //�̫�@�I���ܴN����۰�
    //���M�N�O�U�@�I
    m_Goal.ShowLabel(FALSE);
    if (m_itor->GetBkStatus() == BGS_NitsNeg || m_itor->GetBkStatus() == BGS_NitsPos)
        m_itor->m_pBackGorund->NT_colorReviseByNits(m_BkColor);
    /*
    recoil() 
    0 �S�s�u
    1 �s�u
    2 �|��Zero Cal
    3 �ɦ줣�bMEAS
    4 �q�����` ��@1
    �̫�@�I  5
    */
    switch(recoil())
    {
    case CA_Offline:        
        MessageBox("�S�s�u�A�L�k�q��");  
        return 0;
    case CA_ZeroCalMode:    
        MessageBox("�ɦ줣�bMEAS");     
        return 3;
    case CA_MsrMode:
    default:
        if (!eventGoNextGoal())
            return 5;//�O�_���̫�@�I
        else
            return 1;
    }
}

void CPatternDlg::eventRunMsrAi(int isRun)
{
//���n�H�N��ʡI= =+
    //���N�����}�A�}�N������
    //���w���� TRUE FALSE
    // 2 : Switch Mode
    // 1 : Assign Run Mode
    // 0 : Assign Off Mode
    c_bRunMsrAI = (isRun == 2) ? c_bRunMsrAI ? FALSE : TRUE : !isRun;

    switch(isRun)
    {
    default:
        if (!c_bRunMsrAI)
        {
    case 1://�۰ʶq���ҩl�I
            SetTimer(1, 180, NULL);
            if (isRun)    break;
        }
        else
        {
    case 0:
            KillTimer(1);
            m_Goal.SetPercent(0);

            if (!isRun)    break;
        }
    }
}

void CPatternDlg::eventSwCntCa210()
{
    //�����s�u
    m_pCA210->SetOnline(m_pCA210->isOnline() ? FALSE : TRUE);
    Invalidate();
}

void CPatternDlg::eventExitDialog()
{
    if(c_bRunMsrAI)
        KillTimer(1);

    ShowWindow(SW_HIDE);
    
    CMainFrame* pMainFrm = dynamic_cast<CMainFrame*>(AfxGetMainWnd());
    ASSERT_VALID(pMainFrm);
    
    CColorEyeIDoc* pDoc = dynamic_cast<CColorEyeIDoc*>(pMainFrm->GetActiveDocument());
    ASSERT_VALID(pDoc);
    
	pDoc->UpdateDocRNA(m_RNA);
    pDoc->UpdateAllViews(NULL);
}

void CPatternDlg::setBkColor(const ColorRef& clr)
{
    m_BkColor = clr;
    Invalidate();
    UpdateWindow();
}

void CPatternDlg::OnShowWindow(BOOL bShow, UINT nStatus) 
{
    CDialog::OnShowWindow(bShow, nStatus);
    m_pCA210->SetOnline(bShow);    
}
