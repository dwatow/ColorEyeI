// PatternDlg.cpp : implementation file
//

#include "stdafx.h"
#include <cstdlib>
#include <ctime>
#include "xMsrPoint.h"
#include "PatternDlg.h"
#include "..\EnterValueDlg.h"
#include "..\ReadBarCodeDialog.h"
#include "..\MainFrm.h"
#include "..\ColorEyeIDoc.h"
#include "..\TranScripter.h"

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


CPatternDlg::CPatternDlg(initType it, CWnd* pParent /*=NULL*/)
: CDialog(CPatternDlg::IDD, pParent), InitDataType(it)
// m_centerRect(0, 0, 0, 0), m_bColor(0, 0, 0),
{
    //{{AFX_DATA_INIT(CPatternDlg)
        // NOTE: the ClassWizard will add member initialization here
    //}}AFX_DATA_INIT
    
    //���������ǭn�T�w�A���n�ק�F�I
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
    setupLCMSize();
}

void CPatternDlg::initDataDlgType()
{
    CDialog *DataDlg = new CMsrItemDlg();
    CMsrItemDlg dlgMsrItem;        //��Pattern Dialog��l�ơA���ǳ�
    switch(InitDataType)
    {
    case MsrForItem:
        dlgMsrItem.DoModal();  //����P�_�l�u�O���O�Ū��C
        break;
    }
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
    
    c_bDrawNextGold = FALSE;
    c_bDrawGold     = TRUE;
    c_bStateBar     = TRUE;

    c_bMsrBegin     = FALSE;
    c_bMsrEnd       = FALSE;
    c_bMsrEndnMsred = FALSE;
    c_bGoalPercent  = FALSE;
    c_bRunMsrAI     = TRUE;
    c_bUnCntCA210   = FALSE;
    c_bFind5nits    = FALSE;

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

//     if (c_bDrawNextGold) 
//         m_NextGoal.DrawCircle(dc);
DebugCode(
		  dc.SetTextColor(m_BkColor.Shift());

		int lineNum(0);
        //Pattern�B�@�Ѽ�
        //Goal�T��
        temp.Format("  Goal%s", m_Goal.showMe());
        TextOut(dc, 0, wordHight*lineNum++, temp, temp.GetLength());
        
        //NextGoal�T��
//         temp.Format("nGoal%s", m_NextGoal.showMe());
//         TextOut(dc, 0, wordHight*lineNum++, temp, temp.GetLength());

        //��L�T��
    //     KeyMessage.Format("nChar = %d, nRepCnt = %d, nFlags = %d", key1, key2, key3);
    //     TextOut(dc, 0, wordHight*lineNum++, KeyMessage, 40);

        //iterator���T��
        CString isEnd(m_itor == m_RNA.Begin()? "Begin" : m_itor == m_RNA.End() ? "End" : "Other");
        temp.Format("���N����T: itor.begin = 0x%x, itor.end = 0x%x, itor(��} / ��m) = 0x%x / %s", m_RNA.Begin(), m_RNA.End(), m_itor, isEnd);
        TextOut(dc, 0, wordHight*lineNum++, temp, temp.GetLength());

        temp.Format("PatternDlg�X��: Goal/nGoal = %d/%d, StateBar = %d; �q���ʤ��� = %d%%, �Ĥ@�I = %d, �̫�@�I = %d, �۰ʶq���Ҧ� = %d, �s��CA-210 = %d, 5Nits�����I = %d", \
                     c_bDrawGold, c_bDrawNextGold, c_bStateBar, m_Goal.GetPercent(), c_bMsrBegin, c_bMsrEnd, !c_bRunMsrAI, c_bUnCntCA210, c_bFind5nits);
        TextOut(dc, 0, wordHight*lineNum++, temp, temp.GetLength());

//         temp.Format("½Ķ����T: %s", m_GunMchn.GetSetupValue());
//         TextOut(dc, 0, 64, temp, temp.GetLength());

        temp.Format("�o�@�I����T: %s", m_itor->showMe());
        TextOut(dc, 0, wordHight*lineNum++, temp, temp.GetLength());
)

    //���A�C
    if (c_bStateBar)
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
    if (c_bDrawGold)
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

void CPatternDlg::setupLCMSize()
{
    if (!atoi(m_pCA210->GetLcmSize()))
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
    
    pDoc->SetCHID   ( pMainFrm->m_pCa210->GetChStrNo()    );
    pDoc->SetPrb    ( pMainFrm->m_pCa210->GetProb()       );
    pDoc->SetMsrDvc ( pMainFrm->m_pCa210->GetDeviceType() );


    m_RNA = pDoc->GetDocRNA();
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
    m_Goal.setWnd(GetActiveWindow()); //GetActiveWindow()�ݵ��غc�������~�i�H���
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
}

void CPatternDlg::trigger()
{
    c_bGoalPercent = FALSE;
	m_itor->m_pBackGorund->NT_SetWnd(GetActiveWindow());
	m_itor->m_pBackGorund->NT_SetCa(m_pCA210);

    //�ثe�o�@�I�O���O5nits�������I�H2=�O
//     TrigStatus ts(TS_Normal);
//     ts = m_GunMchn.Trigger(it);
//     switch(ts)
//     {
//     case TS_Find_Nits: c_bDrawGold = TRUE;  c_bFind5nits = TRUE;  c_bStateBar = TRUE; break;
//     case TS_JND:       c_bDrawGold = FALSE; c_bFind5nits = FALSE; c_bStateBar = FALSE; break;
//     case TS_JNDX:      c_bDrawGold = FALSE; c_bFind5nits = FALSE; c_bStateBar = TRUE; break;
//     case TS_Normal:
//     default:           c_bDrawGold = TRUE;  c_bFind5nits = FALSE; c_bStateBar = TRUE; 
//     }
    //c_bFind5nits = (m_GunMchn.trigger(it) == TS_Find_Nits)? TRUE : FALSE;

//	Nits_fine(m_itor->GetBkStatus());
	setBkColor(m_itor->GetBkColor());

	m_Goal.SetupLabel(m_itor->GetBullet());
 	m_Goal.SetStrColor(m_BkColor.Shift());

    m_Goal.SetCenter(m_itor->GetPointPosi());  //�v��m
    m_Goal.SetPercent(0);

    //if ( /*!c_bMsrEndnMsred || it->GetMsrFlowNum() != PnGamma && */m_itor != m_RNA.Begin())
    m_Goal.Animation();

	checkMsrLimit();
}

void CPatternDlg::checkMsrLimit()
{
    c_bMsrBegin     = (  m_itor   == m_RNA.Begin()) ? TRUE : FALSE;
    c_bMsrEnd       = (  m_itor+1 == m_RNA.End()  ) ? TRUE : FALSE;
    c_bMsrEndnMsred = (  c_bMsrEnd && (m_itor->GetBullet().isEmpty()) ) ? FALSE : TRUE;
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

CaState CPatternDlg::Recoil()
{
    //�Ȧs�ثe���ù����/���ê��A
    BOOL OldDrawNextGold = c_bDrawNextGold;
    BOOL OldDrawGold     = c_bDrawGold;
    BOOL OldStateBar     = c_bStateBar;
    BOOL OldGoalPercent  = c_bGoalPercent;

    //�T�w�����Ҧ��ù����/���ê��A
    c_bDrawNextGold = c_bDrawGold = c_bStateBar = c_bGoalPercent = FALSE;

    Invalidate();
    UpdateWindow();

    Sleep(70);

    CaState camsrResult(m_pCA210->Measure());

    m_itor->SetBullet(m_pCA210->GetMsrData());

    //��_�ثe���ù����/���ê��A
    c_bDrawNextGold = OldDrawNextGold;
    c_bDrawGold     = OldDrawGold;
    c_bStateBar     = OldStateBar;
    c_bGoalPercent  = OldGoalPercent;

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
    c_bGoalPercent = TRUE;
    if (m_pCA210->isOnline())
    {
        srand(time(NULL));
        MsrAIValue = m_pCA210->MsrAI((float)0.005);
        switch(MsrAIValue)
        {
            case MA_InDeviation://�зǪ��e�Ȥ��G�~��q��+�ʤ���
                SetPercentValue = m_Goal.SetPercent(m_Percent);
                switch (SetPercentValue)
                {
                    case 0://�ŪM��
                        //m_Percent = rand()%20+10;
                        m_Goal.SetPercent(rand()%20+10);
                        m_Percent = m_Goal.GetPercent();
                        break;
                    case 1://�i�椤
                        m_Percent += rand()%50+rand()%50+1;
                        break;
                    case 2://���X�Ӱ�
                        //c_bMsrValues = /*TRUE;*/c_bMsring = FALSE;
                        if (m_Percent > 83)
                        {
                            eventRunMsrAi(FALSE);
                            if ((eventCatchMsrValue() == 1) //�̽������B�J
                                || (c_bMsrEndnMsred == FALSE))
                                eventRunMsrAi(TRUE);
                        }
                        break;
                }
                break;
            case MA_OutDeviation://�зǪ��e�ȥ~�G�~��q��-�ʤ���
                m_Percent -= rand()%25+rand()%25+1;
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
    {
        c_bUnCntCA210 = TRUE;
    }

    CDialog::OnTimer(nIDEvent);
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
		m_Goal.ShowLabel(TRUE);

        Invalidate();
//         if (m_itor->GetBackColor() == JND || JNDX) 
//             c_bMsrValues = FALSE;
//         else
//             c_bMsrValues = TRUE;
    }
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
	m_Goal.ShowLabel(FALSE);
    Invalidate();
    }

    return !c_bMsrEnd;
}

UINT CPatternDlg::eventCatchMsrValue()
{
    //��ȧ���!!!!
    //�̫�@�I���ܴN����۰�
    //���M�N�O�U�@�I
//     if (c_bFind5nits)
//         fineNits();//��I���G��
	if (m_itor->GetBkStatus() == BGS_NitsNeg || m_itor->GetBkStatus() == BGS_NitsPos)
		m_itor->m_pBackGorund->NT_colorReviseByNits(m_BkColor);
    /*
    Recoil() 
    0 �S�s�u
    1 �s�u
    2 �|��Zero Cal
    3 �ɦ줣�bMEAS
    4 �q�����` ��@1
    �̫�@�I  5
    */

    switch(Recoil())
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
            m_Percent = m_Goal.GetPercent();

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
    
    pDoc->RestructureVector();
    pDoc->UpdateAllViews(NULL);
//     int a = (int)(GetRValue(m_GunMchn.Get5NitsBkColor()));
//    pDoc->SetNitsLv(a);
}

//////////////////////////////////////////////////////////////////////////
//find 5 nits

void CPatternDlg::setBkColor(ColorRef clr)
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

//////////////////////////////////////////////////////////////////////////
// void CPatternDlg::setCrsTlkRect(CRect& _rect, ColorRef& clr)
// {
// 	//�bDNA��RNA�ɨϥ�
// 	// 	m_centerRect.top    = 10;
// 	// 	m_centerRect.bottom = 200;
// 	// 	m_centerRect.left   = 10;
// 	// 	m_centerRect.right  = 200;
// 	// 	m_centerRectBrush.CreateSolidBrush(RGB(0, 0, 255));
// 	m_centerRect = _rect;
// 	m_bColor = clr;
// }
// 
// void CPatternDlg::DrawCrsTlkRect(CPaintDC& dc)
// {
// 	//�bCPatternDlg�ϥ�
// 	// Cross Talk ���I����
// 	CBrush _brush(m_bColor.oRGB());
//     dc.FillRect(m_centerRect, &_brush);
// }

