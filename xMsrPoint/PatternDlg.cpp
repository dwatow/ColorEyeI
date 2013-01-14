// PatternDlg.cpp : implementation file
//

#include "stdafx.h"
#include <cstdlib>
#include <ctime>
#include "xMsrPoint.h"
#include "PatternDlg.h"
#include "..\EnterValueDlg.h"
#include "..\ReadBarCodeDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPatternDlg dialog


CPatternDlg::CPatternDlg(initType it, CWnd* pParent /*=NULL*/)
    : CDialog(CPatternDlg::IDD, pParent), InitDataType(it)
{
    //{{AFX_DATA_INIT(CPatternDlg)
        // NOTE: the ClassWizard will add member initialization here
    //}}AFX_DATA_INIT
    
    //���������ǭn�T�w�A���n�ק�F�I
    InitCa210();
	SetupLCMSize();
    InitDataDlgType();
}

void CPatternDlg::InitDataDlgType()
{
    CMsrItemDlg dlgMsrItem;        //��Pattern Dialog��l�ơA���ǳ�
    switch(InitDataType)
    {
    case MsrForItem:
        dlgMsrItem.SetBolt(&m_GunMchn);
        dlgMsrItem.DoModal();  //����P�_�l�u�O���O�Ū��C
		break;

// 	default:
// 		return FALSE;
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
    c_bMsrValues    = FALSE;
    c_bMsring       = FALSE;
    c_bGoalPercent  = FALSE;
    c_bRunMsrAI     = TRUE;
//    c_bZeroCal      = FALSE;
    c_bUnCntCA210   = FALSE;
    c_bFind5nits    = FALSE;

    Info1.ptnDlg = this;

    m_Goal.SetColor(ShiftColor(RGB(255, 0, 127), 5));
	

    return TRUE;  // return TRUE unless you set the focus to a control
                  // EXCEPTION: OCX Property Pages should return FALSE
}

HBRUSH CPatternDlg::OnCtlColor(CDC* , CWnd* , UINT ) 
{
    m_BkBrush.DeleteObject();
    m_BkBrush.CreateSolidBrush(m_BkColor);
    
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

    CPaintDC dc(this); // device context for painting
    CString temp;
    dc.SetBkMode(OPAQUE);
    dc.SetBkColor(m_BkColor);

    //Cross Talk ���I����
	ColorType SpecelPattern(m_GunMchn.GetColorType());
	switch(SpecelPattern)
	{
	case CrsTlkW: m_GunMchn.CenterRect(&dc, RGB(255, 255, 255));  break;
	case CrsTlkD: m_GunMchn.CenterRect(&dc, RGB(0, 0, 0));        break;
	case JNDX:    m_GunMchn.CenterCross(&dc, RGB(255, 255, 255)); break;
	}


    dc.SetTextColor(ShiftColor(m_BkColor));
    if (c_bDrawNextGold) 
        m_NextGoal.DrawCircle(dc);

#ifdef _DEBUG

        //Pattern�B�@�Ѽ�
        //Goal�T��
        temp.Format("  Goal%s",    m_Goal.GetSetupValue());
        TextOut(dc, 0, 0, temp, temp.GetLength());
        
        //NextGoal�T��
        temp.Format("nGoal%s", m_NextGoal.GetSetupValue());
        TextOut(dc, 0, 16, temp, temp.GetLength());

        //��L�T��
    //     KeyMessage.Format("nChar = %d, nRepCnt = %d, nFlags = %d", key1, key2, key3);
    //     TextOut(dc, 0, 15, KeyMessage, 40);

        //iterator���T��
        CString isEnd(m_itor == m_BeginItor? "Begin" : m_itor == m_EndItor ? "End" : "Other");
        temp.Format("���N����T: itor.begin = 0x%x, itor.end = 0x%x, itor(��} / ��m) = 0x%x / %s", m_BeginItor, m_EndItor, m_itor, isEnd);
        TextOut(dc, 0, 32, temp, temp.GetLength());

        temp.Format("PatternDlg�X��: Goal/nGoal = %d/%d, StateBar = %d;  Msr/Msring = %d/%d, �q���ʤ��� = %d%%, �Ĥ@�I = %d, �̫�@�I = %d, �۰ʶq���Ҧ� = %d, �s��CA-210 = %d, 5Nits�����I = %d", \
                     c_bDrawGold, c_bDrawNextGold, c_bStateBar, c_bMsrValues, c_bMsring, m_Goal.GetPercent(), c_bMsrBegin, c_bMsrEnd, !c_bRunMsrAI, c_bUnCntCA210, c_bFind5nits);
        TextOut(dc, 0, 48, temp, temp.GetLength());

        temp.Format("½Ķ����T: %s", m_GunMchn.GetSetupValue());
        TextOut(dc, 0, 64, temp, temp.GetLength());

        temp.Format("�o�@�I����T: %s", m_itor->GetSetupValue());
        TextOut(dc, 0, 80, temp, temp.GetLength());
#endif

    //���A�C
    if (c_bStateBar)
    {
        //�ާ@�����]���^
        temp.Format("�W�@�I: ��, �U�@�I: ��, ���+�U�@�I: Enter, �۰ʶq��: ��");
        TextOut(dc, 0, GetSystemMetrics(SM_CYSCREEN) - 15, temp, temp.GetLength());
        //���A�]�k�^
        temp.Format("�s�u���A: %s, �ثe�q��: %s,  �ѪR��: %d��%d,  Channel: %s,  LCM size: %2.1f inch", \
            m_pCA210->isOnline() ? "�s�u" : "���u" , m_GunMchn.GetMsrFlowName(), GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), m_pCA210->GetChData(), m_pCA210->GetLcmSize());//LCM Size�o�˧�|�����D
        TextOut(dc, GetSystemMetrics(SM_CXSCREEN) - (int)(temp.GetLength()*6.7), GetSystemMetrics(SM_CYSCREEN) - 15, temp, temp.GetLength());
    }

    //�D�n�q������
    if (c_bDrawGold)
        m_Goal.DrawCircle(dc);//�q���ؼ�

    if (c_bGoalPercent)
    {
    //�ʤ������
        temp.Format("%3d%% \0", m_Goal.GetPercent());
        TextOut(dc, m_Goal.GetCenter().x - 15, m_Goal.GetCenter().y - (m_Goal.GetRadius()+20) , (LPCSTR)temp, temp.GetLength());  //�W
        TextOut(dc, m_Goal.GetCenter().x - 15, m_Goal.GetCenter().y + (m_Goal.GetRadius()+2 ) , (LPCSTR)temp, temp.GetLength());  //�U
        TextOut(dc, m_Goal.GetCenter().x - (m_Goal.GetRadius()+40),  m_Goal.GetCenter().y -7 , (LPCSTR)temp, temp.GetLength());  //��
        TextOut(dc, m_Goal.GetCenter().x + (m_Goal.GetRadius()+2) ,  m_Goal.GetCenter().y -7 , (LPCSTR)temp, temp.GetLength());  //�k
    }

    //�q���ƾګ���
    if (c_bMsring)
        DrawMsringLabel(dc);

    if (c_bMsrValues)
        DrawMsrLabel(dc);

    dc.SetTextColor(InvrtColor(m_BkColor));

//     if (c_bZeroCal)
//     {
//         temp.Format("       ���bZero Cal...   ");
//         TextOut(dc, GetSystemMetrics(SM_CXSCREEN)/2 - 75, GetSystemMetrics(SM_CYSCREEN)/2-8, temp, temp.GetLength());
//     }

    if (c_bMsrEnd && c_bRunMsrAI && c_bMsrEndnMsred)
    {
        temp.Format("��ESC���}�C");    
        if ((m_Goal.GetCenter().x == GetSystemMetrics(SM_CXSCREEN)/2) && (m_Goal.GetCenter().y == GetSystemMetrics(SM_CYSCREEN)/2))
            TextOut(dc, GetSystemMetrics(SM_CXSCREEN)/2 - 75, GetSystemMetrics(SM_CYSCREEN)/2-8-m_Goal.GetRadius()*2, temp, temp.GetLength());
        else
            TextOut(dc, GetSystemMetrics(SM_CXSCREEN)/2 - 75, GetSystemMetrics(SM_CYSCREEN)/2-8, temp, temp.GetLength());
    }

    if (c_bUnCntCA210)
        temp.Format("���s��CA-210�C");
    else
        temp.Format("");
    TextOut(dc, GetSystemMetrics(SM_CXSCREEN)/2 - 75, GetSystemMetrics(SM_CYSCREEN)/2-8, temp, temp.GetLength());


    // TODO: Add your message handler code here
    // Do not call CDialog::OnPaint() for painting messages
}

void CPatternDlg::DrawMsrLabel(CDC &aDC)
{
    CRect* rect1 = new CRect
        (m_Goal.GetCenter().x - (m_Goal.GetRadius()+10)     , m_Goal.GetCenter().y - (m_Goal.GetRadius()+20), \
         m_Goal.GetCenter().x - (m_Goal.GetRadius()+10) + 88, m_Goal.GetCenter().y - (m_Goal.GetRadius()+20) + 158); //�]�w��r�϶�
    
    aDC.SetTextColor(InvrtColor(m_BkColor));
    CString temp;
    temp.Format(" Lv =%3.2f\nx =%1.4f \ny =%1.4f\nT =%3d \n�Guv=%1.4f\nu' =%1.4f\nv' =%1.4f\nX = %3.2f\nY = %3.2f\nZ = %3.2f", \
        m_itor->GetLv(), m_itor->GetSx(), m_itor->GetSy(), m_itor->GetT(), m_itor->GetDuv(), m_itor->GetDu(), m_itor->GetDv(), m_itor->GetX(), m_itor->GetY(), m_itor->GetZ());

    aDC.DrawText(temp, rect1, DT_LEFT | DT_VCENTER);

    delete rect1;
}

void CPatternDlg::DrawMsringLabel(CDC &aDC)
{    
    CRect* rect2;
    
    if (m_Goal.GetCenter().x < (LONG)((m_Goal.GetRadius()+125) + 88))
    {
        rect2= new CRect
            (m_Goal.GetCenter().x + (m_Goal.GetRadius()+40)     , m_Goal.GetCenter().y - (m_Goal.GetRadius()+20), \
             m_Goal.GetCenter().x + (m_Goal.GetRadius()+40) + 88, m_Goal.GetCenter().y - (m_Goal.GetRadius()+20) + 158); //�]�w��r�϶�

    }
    else
    {
        rect2= new CRect
            (m_Goal.GetCenter().x - (m_Goal.GetRadius()+125)     , m_Goal.GetCenter().y - (m_Goal.GetRadius()+20), \
             m_Goal.GetCenter().x - (m_Goal.GetRadius()+125) + 88, m_Goal.GetCenter().y - (m_Goal.GetRadius()+20) + 158); //�]�w��r�϶�
    }

    aDC.SetTextColor(ShiftColor(m_BkColor));
    aDC.DrawText(m_pCA210->OutData(), rect2, DT_LEFT | DT_VCENTER);

    delete rect2;
}

BOOL CPatternDlg::SetBkColor(COLORREF clr)
{
    int O = 0x000000FF & (clr >>24);
    int B = GetBValue(clr);
    int G = GetGValue(clr);
    int R = GetRValue(clr);

    if(O == 0 && R >= 0 && R <256
              && G >= 0 && G <256 
              && B >= 0 && B <256 )
    {
        m_BkColor = clr;
        return TRUE;
    }
    else
        return FALSE;    
}

COLORREF CPatternDlg::GetBkColor() const {    return m_BkColor;}

UINT CPatternDlg::GetGoalRadius() const{    return m_Goal.GetRadius( ); }
BOOL CPatternDlg::SetGoalRadius(UINT r){    return m_Goal.SetRadius(r); }

CPoint CPatternDlg::GetGoalPosi() const     {    return m_Goal.GetCenter(    ); }
BOOL   CPatternDlg::SetGoalPosi(CPoint posi){    return m_Goal.SetCenter(posi); }

COLORREF CPatternDlg::GetGoalColor() const      {    return m_Goal.GetColor(   ); }
BOOL     CPatternDlg::SetGoalColor(COLORREF clr){    return m_Goal.SetColor(clr); }

COLORREF CPatternDlg::ShiftColor(COLORREF clr, int shift) const
{
    int O = 0x000000FF & (clr >>24);
    int B = GetBValue(clr);
    int G = GetGValue(clr);
    int R = GetRValue(clr);

    if (O != 0)
        return RGB(R, G, B);
    else
    {
        R = (R < shift)?(R + shift):(R - shift);
        G = (G < shift)?(G + shift):(G - shift);
        B = (B < shift)?(B + shift):(B - shift);
        return RGB(R, G, B);
    }
}

COLORREF CPatternDlg::InvrtColor(COLORREF clr) const
{
    int O = 0x000000FF & (clr >>24);
    int B = GetBValue(clr);
    int G = GetGValue(clr);
    int R = GetRValue(clr);
    
    if (O != 0)
        return RGB(R, G, B);
    else
    {
        R = ((R < 130) && (R > 120))?(130 - R):(255 - R);
        G = ((G < 130) && (G > 120))?(130 - G):(255 - G);
        B = ((B < 130) && (B > 120))?(130 - B):(255 - B);
        return RGB(R, G, B);
    }
}

CString CPatternDlg::SetupLCMSize()
{
	CString LCMSize;
    LCMSize = m_pCA210->GetLcmSize();
    if (!atoi(LCMSize))
    {
        CEnterValueDlg dlgEnterValue("�L�k�P�OLCM Size");
        dlgEnterValue.SetValueKind("LCM Size");

        if (dlgEnterValue.DoModal() == IDOK)
		{
            LCMSize = dlgEnterValue.m_strValue;
			m_pCA210->SetLcmSize(LCMSize);
		}
    }
	return LCMSize;
}

BOOL CPatternDlg::Magazine()
{
    // TODO: Add extra validation here
    CMainFrame* pMainFrm = dynamic_cast<CMainFrame*>(AfxGetMainWnd());
    ASSERT_VALID(pMainFrm);
    
    CColorEyeIDoc* pDoc = dynamic_cast<CColorEyeIDoc*>(pMainFrm->GetActiveDocument());
    ASSERT_VALID(pDoc);
    
    pDoc->SetCHID   ( pMainFrm->m_pCa210->GetChStrNo()    );
    pDoc->SetPrb    ( pMainFrm->m_pCa210->GetProb()       );
    pDoc->SetMsrDvc ( pMainFrm->m_pCa210->GetDeviceType() );

    m_itor      = pDoc->GetMsrDataChain().Begin();
    m_BeginItor = m_itor;
    m_EndItor   = pDoc->GetMsrDataChain().End();

	//MsrItem���U�u�T�w�v�٬O�u�����v
	if (pDoc->GetMsrDataChain().IsEmpty())
		return FALSE;  //�L��u�A���ζq
	else
	{
		//SetPanel
		CReadBarCodeDialog dlgReadBarCode;
		dlgReadBarCode.DoModal();

		//++BeginItor;  
		if (!m_GunMchn.Magazine(m_EndItor))  MessageBox("Chanel����F\nPtnDlg->Magazine���j���W���X��");            //�W��
		Trigger(m_itor);
		NextTrigger(m_itor);
		if (    !m_Goal.SetRadius(m_GunMchn.GetRadius()))  MessageBox("Chanel����F\nPtnDlg->Magazine�����J�ؼйv�b�|�X��");     //�v�j�p
		if (!m_NextGoal.SetRadius(m_GunMchn.GetRadius()))  MessageBox("Chanel����F\nPtnDlg->Magazine�����J�U�@�v�b�|�X��");     //���v�j�p
    
		Invalidate();
    
	    return TRUE;  //���l�u�i�H�q��
	}
}

void CPatternDlg::InitCa210()
{
    CMainFrame* pMainFrm = dynamic_cast<CMainFrame*>(AfxGetMainWnd());
    ASSERT_VALID(pMainFrm);
    
    m_pCA210 = pMainFrm->m_pCa210;
    m_pCA210->SetOnline(TRUE);
	m_pCA210->LinkMemory();
}

BOOL CPatternDlg::Trigger(std::vector<Cartridge>::iterator& it)
{
		c_bGoalPercent = FALSE;
		//�ثe�o�@�I�O���O5nits�������I�H2=�O
		TrigStatus ts;
		ts = m_GunMchn.Trigger(it);
		switch(ts)
		{
		case TS_Find_Nits: c_bDrawGold = TRUE;  c_bFind5nits = TRUE;  c_bStateBar = TRUE; break;
		case TS_JND:       c_bDrawGold = FALSE; c_bFind5nits = FALSE; c_bStateBar = FALSE; break;
		case TS_JNDX:      c_bDrawGold = FALSE; c_bFind5nits = FALSE; c_bStateBar = TRUE; break;
		case TS_Normal:
		default:           c_bDrawGold = TRUE;  c_bFind5nits = FALSE; c_bStateBar = TRUE; 
		}
		//c_bFind5nits = (m_GunMchn.Trigger(it) == TS_Find_Nits)? TRUE : FALSE;

		SetBkColor(m_GunMchn.GetBkColor());              //�v�I��
		m_Goal.SetCenter(m_GunMchn.GetPointPosition());  //�v��m
		m_Goal.SetPercent(0);

		if ( !c_bMsrEndnMsred || it->GetMsrFlowNum() != PnGamma && it != m_BeginItor)
			VbrGoalThread((LPVOID)&Info1);
	//}

	c_bMsrBegin = (it == m_BeginItor) ? TRUE : FALSE;

    return TRUE;
}

BOOL CPatternDlg::NextTrigger(std::vector<Cartridge>::iterator& it)
{
    it++;
    if (it != m_EndItor)
    {
        m_NextGoal.SetColor(ShiftColor(m_BkColor));          //�U�@�ӹv�C��
        m_NextGoal.SetCenter(m_GunMchn.GetPointPosition());  //�v��m
		if (it->GetMsrFlowNum() != PnGamma && it != m_BeginItor)
	        VbrNextGoalThread((LPVOID)&Info1);

        it--;
        m_GunMchn.Trigger(it);

        c_bMsrEnd = FALSE;
        //�٥i�H�~��
    }
    else
    {
        it--;
        c_bMsrEnd = TRUE;
		c_bMsrEndnMsred = (it->GetBullet().isEmpty()) ? FALSE : TRUE;
        //�����۰ʶq�����T��
    }
    return !c_bMsrEnd;
}

BOOL CPatternDlg::PreTranslateMessage(MSG* pMsg) 
{
    // TODO: Add your specialized code here and/or call the base class
    CMainFrame* pMainFrm = dynamic_cast<CMainFrame*>(AfxGetMainWnd());
    ASSERT_VALID(pMainFrm);
    
    CColorEyeIDoc* pDoc = dynamic_cast<CColorEyeIDoc*>(pMainFrm->GetActiveDocument());
    ASSERT_VALID(pDoc);

    if (pMsg->message == WM_KEYDOWN)
    {
        switch(pMsg->wParam)
        {
            case VK_SPACE:  EventSwCntCa210();    break;//�ť���G�����s�u
            case VK_DOWN:   EventRunMsrAi();      break;//�U   �G�۰ʶq���Ҧ�
            case VK_RIGHT:  EventGoNextGoal();    break;//�k   �G���U�@���I
            case VK_LEFT:   EventGoPrvsGoal();    break;//��   �G�W�@���I
            case VK_RETURN: EventCatchMsrValue(); break;//Enter�G��ȧ���!!!!
            case VK_ESCAPE:                             //ESC  �G����Patten Dialog
                if(c_bRunMsrAI)
                    KillTimer(1);
                ShowWindow(SW_HIDE);
                pDoc->RestructureVector();
				pDoc->UpdateAllViews(NULL);
				int a = (int)(GetRValue(m_GunMchn.Get5NitsBkColor()));
 				pDoc->SetNitsLv(a);
                break;
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
    BOOL OldMsrValues    = c_bMsrValues;
    BOOL OldMsring       = c_bMsring;
	BOOL OldGoalPercent  = c_bGoalPercent;

    //�T�w�����Ҧ��ù����/���ê��A
    c_bDrawNextGold = c_bDrawGold = c_bStateBar = c_bMsrValues = c_bMsring = c_bGoalPercent = FALSE;

    Invalidate();
    UpdateWindow();

    Sleep(70);

    CaState camsrResult(m_pCA210->Measure());

    m_itor->SetBullet(m_pCA210->GetMsrData());

    //��_�ثe���ù����/���ê��A
    c_bDrawNextGold = OldDrawNextGold;
    c_bDrawGold     = OldDrawGold;
    c_bStateBar     = OldStateBar;
    c_bMsrValues    = OldMsrValues;
    c_bMsring       = OldMsring;
	c_bGoalPercent  = OldGoalPercent;

    Invalidate();
    UpdateWindow();

    return camsrResult;
}

UINT CPatternDlg::VbrGoalThread(LPVOID LParam)
{
    //�����X�ʵe
    MyThreadInfo *pInfo1 = (MyThreadInfo *)LParam;
    CPatternDlg  *PtnDlg = (CPatternDlg*)(pInfo1->ptnDlg);
    Circle *pGoal = (Circle*)&(PtnDlg->m_Goal);//(pInfo1->crl);

    UINT oriR = pGoal->GetRadius(), 
         varR = 0;
    
    CPoint p1(pGoal->GetCenter());

    if (PtnDlg->c_bMsrValues) PtnDlg->c_bMsrValues = FALSE; //�ʵe���ɭԡA����
    PtnDlg->Invalidate();
    PtnDlg->UpdateWindow();
    
    for (UINT i = 0; i < 16; ++i)
    {        
        PtnDlg->InvalidateRect(pGoal->VbrFun(i, oriR));
        PtnDlg->UpdateWindow();
        Sleep(15); //�ո`�ʵe���e�ɬO�_�ݱo��
    }
    //PtnDlg->c_bGoalPercent = TRUE;
    return 0;
}

UINT CPatternDlg::VbrNextGoalThread(LPVOID LParam)
{
    //�����X�ʵe
    MyThreadInfo *pInfo1 = (MyThreadInfo *)LParam;
    CPatternDlg *PtnDlg = (CPatternDlg*)(pInfo1->ptnDlg);
    Circle *pNextGoal = (Circle*)&(PtnDlg->m_NextGoal);//(pInfo1->crl);
    
    UINT oriR = pNextGoal->GetRadius(), 
         varR = 0;
    
    CPoint p1(pNextGoal->GetCenter());
    
    PtnDlg->Invalidate();
    PtnDlg->UpdateWindow();
    
    for (UINT i = 0; i < 16; ++i)
    {        
        PtnDlg->InvalidateRect(pNextGoal->VbrFun(i, oriR));
        PtnDlg->UpdateWindow();
        Sleep(15);
    }
    return 0;
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
						c_bMsrValues = /*TRUE;*/c_bMsring = FALSE;
						if (m_Percent > 83)
						{
							EventRunMsrAi(FALSE);
							if ((EventCatchMsrValue() == 1) //�̽������B�J
								|| (c_bMsrEndnMsred == FALSE))
								EventRunMsrAi(TRUE);
						}
						break;
				}
				break;
			case MA_OutDeviation://�зǪ��e�ȥ~�G�~��q��-�ʤ���
				m_Percent -= rand()%25+rand()%25+1;
				break;
			case MA_nonMsr:
				EventRunMsrAi(FALSE);
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

void CPatternDlg::EventGoPrvsGoal()
{
    //�W�@���I
    if (!c_bMsrBegin)
    {
        ++m_itor;
        if (m_itor != m_BeginItor)    m_itor--;
        if (m_itor != m_BeginItor)    m_itor--;
        
        Trigger(m_itor); //���|����0�A�N�O�q�̫�@�^��^�@��        
        NextTrigger(m_itor);
        Invalidate();
//         if (m_itor->GetBackColor() == JND || JNDX) 
// 			c_bMsrValues = FALSE;
// 		else
 			c_bMsrValues = TRUE;

		c_bMsring = FALSE;
    }
}

BOOL CPatternDlg::EventGoNextGoal()
{
    //�U�@���I
    m_Goal.SetPercent(0);
    m_Percent = m_Goal.GetPercent();

    if (!c_bMsrEnd)
    {
		//�p��U�@��
        ++m_itor;
        if (m_itor == m_EndItor) m_itor--;
        if (m_itor == m_EndItor) m_itor--;
    }

		//���s�e���+�ʵe
        Trigger(m_itor);
        NextTrigger(m_itor);
		c_bMsring = FALSE;
        c_bMsrValues = FALSE;
        Invalidate();

        return !c_bMsrEnd;
}

UINT CPatternDlg::EventCatchMsrValue()
{
    //��ȧ���!!!!
    //�̫�@�I���ܴN����۰�
    //���M�N�O�U�@�I
    if (c_bFind5nits)
        FineNits();//��I���G��
    /*
    Recoil() 
    0 �S�s�u
    1 �s�u
    2 �|��Zero Cal
    3 �ɦ줣�bMEAS
    4 �q�����` ��@1
    �̫�@�I  5
    */
// 	CaState n = Recoil();//m_pCA210->Measure();  //���նq��
// 	CString str;
// 	str.Format("%d", n);
// 	MessageBox(str);
// 	switch(n)
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
        if (!EventGoNextGoal())
			return 5;//�O�_���̫�@�I
		else
			return 1;
    }
}

void CPatternDlg::EventRunMsrAi(int isRun)
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

            c_bMsring = TRUE;
            c_bMsrValues = FALSE;

            if (isRun)    break;
        }
        else
        {
    case 0:
            KillTimer(1);

            c_bMsring = FALSE;
            c_bMsrValues = FALSE;

            m_Goal.SetPercent(0);
            m_Percent = m_Goal.GetPercent();

            if (!isRun)    break;
        }
    }
}

void CPatternDlg::EventSwCntCa210()
{
    //�����s�u
    m_pCA210->SetOnline(m_pCA210->isOnline() ? FALSE : TRUE);
    Invalidate();
}

// void CPatternDlg::EventRunZeroCal()
// {
// //    c_bZeroCal = TRUE;
//     Invalidate();
//     UpdateWindow();
//     if (m_pCA210->CalZero() == CA_Offline)
//         MessageBox("���s�u");
// //    c_bZeroCal = FALSE;
//     Invalidate();
// }

//////////////////////////////////////////////////////////////////////////
//find 5 nits

void CPatternDlg::ChangeBkColor(COLORREF color)
{
	SetBkColor(RGB(color, color, color));
	Invalidate();
    UpdateWindow();
}

void CPatternDlg::FineNitsPos(int& _gl)
{
	float fLv = 0;
	int Graylevel = 55;
	while(fLv >  m_GunMchn.GetNitsSpec())  //�Y�G���٨S����5�H�U�A�N���
	{
		_gl -= 2;
		ChangeBkColor(_gl);  //�ܦ�m_BkColor
//		Sleep(0);
		//�q�����
		if (m_pCA210->Measure() == CA_ZeroCalMode)
		    MessageBox("�ɦ줣�bMEAS");
		fLv = m_pCA210->GetMsrData().GetLv();  //m_IProbe.GetLv();
	}

	while(fLv < m_GunMchn.GetNitsSpec())   //�Y�G���٦b5�H�U�A�N...�ܫG
	{
		++_gl;
		ChangeBkColor(_gl);
		Sleep(60);
		//�q�����
		m_pCA210->Measure();
		fLv = m_pCA210->GetMsrData().GetLv();  //m_IProbe.GetLv();
    }
}

void CPatternDlg::FineNitsNeg(int& _gl)
{
	float fLv = 0;

	while(fLv <  m_GunMchn.GetNitsSpec())  //�Y�G���٨S����5�H�U�A�N���
	{
		_gl += 2;
		ChangeBkColor(_gl);
//		Sleep(0);
		//�q�����
		if (m_pCA210->Measure() == CA_ZeroCalMode)
		    MessageBox("�ɦ줣�bMEAS");
		fLv = m_pCA210->GetMsrData().GetLv();  //m_IProbe.GetLv();
	}
	
	while(fLv > m_GunMchn.GetNitsSpec())   //�Y�G���٦b5�H�U�A�N...�ܫG
	{
		--_gl;
		ChangeBkColor(_gl);
		Sleep(60);
		//�q�����
		m_pCA210->Measure();
		fLv = m_pCA210->GetMsrData().GetLv();  //m_IProbe.GetLv();
    }
}

void CPatternDlg::FineNits()
{
    c_bMsring = TRUE;
	c_bMsrValues = FALSE;
	int i;

	//�����t��k
//	int glvMax = 255, glvMin = 0;

// 	while ((glvMax - glvMin) > 2)
// 	{
// 		Graylevel = (glvMax + glvMin)/2;
// 		ChangeBkColor(Graylevel);
// 		m_pCA210->Measure();
// 		fLv = m_pCA210->GetMsrData().GetLv();
// 		
// 		if( fLv > m_GunMchn.GetNitsSpec() )
// 			glvMax = Graylevel;
// 		else// if (fLv > m_GunMchn.GetNitsSpec() )
// 			glvMin = Graylevel;
// 	}
// 
// 	CString str;
// 	str.Format("max:%d\nmin%d\ngraylv:%d", glvMax, glvMin, Graylevel);
// 	AfxMessageBox(str);

	int Graylevel(60);

	     if (m_GunMchn.GetNitsKind() == NK_POS) Graylevel = 55;
	else if (m_GunMchn.GetNitsKind() == NK_NEG) Graylevel = 60;

    for(i = 0; i < 2; ++i)
    {
 		     if (m_GunMchn.GetNitsKind() == NK_POS) FineNitsPos(Graylevel);
 		else if (m_GunMchn.GetNitsKind() == NK_NEG) FineNitsNeg(Graylevel);
		else MessageBox("��Nits�X���D�C");
	}
    m_GunMchn.Set5NitsBkColor(m_BkColor);
    c_bMsring = c_bFind5nits = !c_bMsring;  //5Nits�S�O�y�{����
}

void CPatternDlg::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialog::OnShowWindow(bShow, nStatus);
	
	// TODO: Add your message handler code here
	m_pCA210->SetOnline(bShow);	
}
