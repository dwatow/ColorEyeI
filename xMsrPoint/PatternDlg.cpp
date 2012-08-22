// PatternDlg.cpp : implementation file
//

#include "stdafx.h"
#include <cstdlib>
#include <ctime>
#include "xMsrPoint.h"
#include "PatternDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPatternDlg dialog


CPatternDlg::CPatternDlg(initType it, CWnd* pParent /*=NULL*/)
    : CDialog(CPatternDlg::IDD, pParent)
{
    //{{AFX_DATA_INIT(CPatternDlg)
        // NOTE: the ClassWizard will add member initialization here
    //}}AFX_DATA_INIT
    c_bisReady = FALSE;
    initVectorType = it;

	//ConnectCa210()
	//pMainFrm->m_pCa210->LinkMemory();
	//InitialVector();
	//���������ǭn�T�w�A���n�ק�F�I
    
	if (!ConnectCa210())
        MessageBox("OnButtonMsr��CA-210�s�u���~\n�o�ӵ{���Y�N����!!\n\n�n���o!");    

	CMainFrame* pMainFrm = dynamic_cast<CMainFrame*>(AfxGetMainWnd());
    ASSERT_VALID(pMainFrm);
    pMainFrm->m_pCa210->LinkMemory();
    InitialVector();
  
    CColorEyeIDoc* pDoc = dynamic_cast<CColorEyeIDoc*>(pMainFrm->GetActiveDocument());
    ASSERT_VALID(pDoc);
    
	//���᪺�����n�b
    pDoc->GetOmdFile().SetCHID(pMainFrm->m_pCa210->GetChNO());
    pDoc->GetOmdFile().SetPrb(pMainFrm->m_pCa210->GetProb());
    pDoc->GetOmdFile().SetMsrDvc(pMainFrm->m_pCa210->GetDeviceType());
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
    ON_WM_LBUTTONDBLCLK()
    ON_WM_LBUTTONDOWN()
    ON_WM_TIMER()
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CPatternDlg message handlers

BOOL CPatternDlg::OnInitDialog() 
{
    // TODO: Add extra initialization here
    
    c_bDrawNextGold = FALSE;
    c_bDrawGold     = TRUE;
//    c_bDebugDisplay = TRUE;  //Debug ������  //������ #ifdef-#endif
    c_bStateBar     = TRUE;

    c_bMsrBegin     = FALSE;
    c_bMsrEnd       = FALSE;
    c_bMsrValues    = FALSE;
    c_bMsring       = FALSE;
    c_bGoalPercent  = FALSE;
    c_bRunMsrAI     = TRUE;
    c_bZeroCal      = FALSE;
    c_bUnCntCA210   = FALSE;
    c_bFind5nits    = FALSE;

    Info1.ptnDlg = this;

    m_Goal.SetColor(ShiftColor(RGB(255, 0, 127), 5));

    return TRUE;  // return TRUE unless you set the focus to a control
                  // EXCEPTION: OCX Property Pages should return FALSE
}

HBRUSH CPatternDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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
    if (m_GunMchn.GetColorType() == CrsTlkW)
        m_GunMchn.CenterRect(&dc, 4.0, RGB(255, 255, 255));
    if (m_GunMchn.GetColorType() == CrsTlkD)
        m_GunMchn.CenterRect(&dc, 4.0, RGB(0, 0, 0));

//    dc.SetBkMode(TRANSPARENT);
    dc.SetTextColor(ShiftColor(m_BkColor));
    if (c_bDrawNextGold) 
        m_NextGoal.DrawCircle(dc);

#ifdef _DEBUG//     if (c_bDebugDisplay){

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

        temp.Format("PatternDlg�X��: Goal/nGoal = %d/%d, StateBar = %d;  Msr/Msring = %d/%d, �q���ʤ��� = %d%%, �k�s�ե� = %d, �Ĥ@�I = %d, �̫�@�I = %d, �۰ʶq���Ҧ� = %d, �s��CA-210 = %d, 5Nits�����I = %d", \
                     c_bDrawGold, c_bDrawNextGold, c_bStateBar, c_bMsrValues, c_bMsring, m_Goal.GetPercent(), c_bZeroCal, c_bMsrBegin, c_bMsrEnd, !c_bRunMsrAI, c_bUnCntCA210, c_bFind5nits);
        TextOut(dc, 0, 48, temp, temp.GetLength());


        temp.Format("½Ķ����T: %s", m_GunMchn.GetSetupValue());
        TextOut(dc, 0, 64, temp, temp.GetLength());

        temp.Format("�o�@�I����T: %s", m_itor->GetSetupValue());
        TextOut(dc, 0, 80, temp, temp.GetLength());
#endif//    }

    //���A�C
    if (c_bStateBar)
    {
        //�ާ@�����]���^
        temp.Format("Zero-Cal: ��, ��ȶq��: ��, �W�@�I: ��, �U�@�I: ��");
        TextOut(dc, 0, GetSystemMetrics(SM_CYSCREEN) - 15, temp, temp.GetLength());
        //���A�]�k�^
        temp.Format("�s�u���A: %s, �ثe�q��: %s,  �ѪR��: %d��%d,  Channel: %s,  LCM size: %s inch", \
            m_pCA210->GetOnline() ? "�s�u" : "���u" , m_GunMchn.GetMsrFlowName(), GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), m_pCA210->GetChData(), m_pCA210->GetLcmSize().Left(2));
        TextOut(dc, GetSystemMetrics(SM_CXSCREEN) - temp.GetLength()*6.7, GetSystemMetrics(SM_CYSCREEN) - 15, temp, temp.GetLength());
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

    //�q���ؼЫ���
    if (c_bMsring)
        DrawMsringLabel(dc);

    if (c_bMsrValues)
        DrawMsrLabel(dc);

    dc.SetTextColor(InvrtColor(m_BkColor));

    if (c_bZeroCal)
    {
        if (!m_pCA210->isTrue())
            temp.Format("�S�� CA-210�A����Zero Cal");
        else
            temp.Format("       ���bZero Cal...   ");
        TextOut(dc, GetSystemMetrics(SM_CXSCREEN)/2 - 75, GetSystemMetrics(SM_CYSCREEN)/2-8, temp, temp.GetLength());
    }

    if (c_bMsrEnd && c_bRunMsrAI)
    {
        temp.Format("�o�O�̫�@�I�I�q���ɡA��ESC���}�C");    
        if ((m_Goal.GetCenter().x == GetSystemMetrics(SM_CXSCREEN)/2) && (m_Goal.GetCenter().y == GetSystemMetrics(SM_CYSCREEN)/2))
            TextOut(dc, GetSystemMetrics(SM_CXSCREEN)/2 - 75, GetSystemMetrics(SM_CYSCREEN)/2-8-m_Goal.GetRadius()*2, temp, temp.GetLength());
        else
            TextOut(dc, GetSystemMetrics(SM_CXSCREEN)/2 - 75, GetSystemMetrics(SM_CYSCREEN)/2-8, temp, temp.GetLength());
    }

    if (c_bUnCntCA210)
    {
        if (c_bUnCntCA210)        temp.Format("���s��CA-210�C");
        TextOut(dc, GetSystemMetrics(SM_CXSCREEN)/2 - 75, GetSystemMetrics(SM_CYSCREEN)/2-8, temp, temp.GetLength());
    }

    // TODO: Add your message handler code here
    // Do not call CDialog::OnPaint() for painting messages
}

void CPatternDlg::DrawMsrLabel(CDC &dc)
{
    CRect* rect1 = new CRect
        (m_Goal.GetCenter().x - (m_Goal.GetRadius()+10)     , m_Goal.GetCenter().y - (m_Goal.GetRadius()+20), \
         m_Goal.GetCenter().x - (m_Goal.GetRadius()+10) + 88, m_Goal.GetCenter().y - (m_Goal.GetRadius()+20) + 158); //�]�w��r�϶�
    
    dc.SetTextColor(InvrtColor(m_BkColor));
    CString temp;
    temp.Format(" Lv =%3.2f\nx =%1.4f \ny =%1.4f\nT =%3d \n�Guv=%1.4f\nu' =%1.4f\nv' =%1.4f\nX = %3.2f\nY = %3.2f\nZ = %3.2f", \
        m_itor->GetLv(), m_itor->GetSx(), m_itor->GetSy(), m_itor->GetT(), m_itor->GetDuv(), m_itor->GetDu(), m_itor->GetDv(), m_itor->GetX(), m_itor->GetY(), m_itor->GetZ());

    dc.DrawText(temp, rect1, DT_LEFT | DT_VCENTER);

    delete rect1;
}

void CPatternDlg::DrawMsringLabel(CDC &dc)
{    
    CRect* rect2;
    
    if (m_Goal.GetCenter().x < (m_Goal.GetRadius()+125) + 88)
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

    dc.SetTextColor(ShiftColor(m_BkColor));
    dc.DrawText(m_pCA210->OutData(), rect2, DT_LEFT | DT_VCENTER);

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

COLORREF CPatternDlg::GetGoalBkColor() const {    return m_NextGoal.GetBkColor(); }
BOOL     CPatternDlg::SetGoalBkColor(COLORREF clr)
{
    int O = 0x000000FF & (clr >>24);
    int B = GetBValue(clr);
    int G = GetGValue(clr);
    int R = GetRValue(clr);
    
    if(O == 0 && R >= 0 && R <256
              && G >= 0 && G <256 
              && B >= 0 && B <256 )
    {
        m_Goal.SetBkColor(clr);
        return TRUE;
    }
    else
        return FALSE;
}

COLORREF CPatternDlg::ShiftColor(COLORREF clr, UINT shift) const
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

//BOOL CPatternDlg::Magazine(std::vector<Cartridge>::iterator BeginItor, std::vector<Cartridge>::iterator EndItor)
BOOL CPatternDlg::Magazine(std::vector<Cartridge>& vCar)
{
    m_itor = vCar.begin();
    ++m_itor;               //�{���Ĥ@�Ӫť]�u
    m_BeginItor = m_itor;
    m_EndItor   = vCar.end();

    //++BeginItor;  
    if(!m_GunMchn.isReady())
    {
        if (!m_GunMchn.Magazine(m_pCA210->GetLcmSize(), m_EndItor))    MessageBox("Chanel����F\nPtnDlg->Magazine���j���W���X��");            //�W��
            Trigger(m_itor);//)                                MessageBox("PtnDlg->Magazine������X��");
            NextTrigger(m_itor);//)                            MessageBox("PtnDlg->Magazine���U�@�m����X��");
        if (    !m_Goal.SetRadius(m_GunMchn.GetRadius()))        MessageBox("Chanel����F\nPtnDlg->Magazine�����J�ؼйv�b�|�X��");     //�v�j�p
        if (!m_NextGoal.SetRadius(m_GunMchn.GetRadius()))        MessageBox("Chanel����F\nPtnDlg->Magazine�����J�U�@�v�b�|�X��");     //���v�j�p

        Invalidate();
        
        return TRUE;  //�Ĥ@���q��
    }
    else
        return FALSE; //���I�д��ϥ�
}

BOOL CPatternDlg::ConnectCa210(Ca210* pCa)
{
    m_pCA210 = pCa;
    if (m_pCA210 != 0)
    {
        m_pCA210->SetOnline(TRUE);
        return TRUE ;
    }
    else
        return FALSE;
}

BOOL CPatternDlg::Magazine()
{
    // TODO: Add extra validation here
    CMainFrame* pMainFrm = dynamic_cast<CMainFrame*>(AfxGetMainWnd());
    ASSERT_VALID(pMainFrm);
    
    CColorEyeIDoc* pDoc = dynamic_cast<CColorEyeIDoc*>(pMainFrm->GetActiveDocument());
    ASSERT_VALID(pDoc);
    
    m_itor = pDoc->GetVector().begin();
    ++m_itor;               //�{���Ĥ@�Ӫť]�u
    m_BeginItor = m_itor;
    m_EndItor   = pDoc->GetVector().end();
    
    //++BeginItor;  
    if(!m_GunMchn.isReady())
    {
        if (!m_GunMchn.Magazine(m_pCA210->GetLcmSize(), m_EndItor))    MessageBox("Chanel����F\nPtnDlg->Magazine���j���W���X��");            //�W��
        Trigger(m_itor);
        NextTrigger(m_itor);
        if (    !m_Goal.SetRadius(m_GunMchn.GetRadius()))        MessageBox("Chanel����F\nPtnDlg->Magazine�����J�ؼйv�b�|�X��");     //�v�j�p
        if (!m_NextGoal.SetRadius(m_GunMchn.GetRadius()))        MessageBox("Chanel����F\nPtnDlg->Magazine�����J�U�@�v�b�|�X��");     //���v�j�p
        
        Invalidate();
        
        return TRUE;  //�Ĥ@���q��
    }
    else
        return FALSE; //���I�д��ϥ�
}

BOOL CPatternDlg::ConnectCa210()
{
    CMainFrame* pMainFrm = dynamic_cast<CMainFrame*>(AfxGetMainWnd());
    ASSERT_VALID(pMainFrm);
    
    m_pCA210 = pMainFrm->m_pCa210;
    if (m_pCA210 != 0)
    {
        m_pCA210->SetOnline(TRUE);
        return TRUE ;
    }
    else
        return FALSE;
}

BOOL CPatternDlg::Trigger(std::vector<Cartridge>::iterator& it)
{
    //�ثe�o�@�I�O���O5nits�������I�H2=�O
    c_bFind5nits = (m_GunMchn.Trigger(it) == 2)? TRUE:FALSE;

    m_BkColor = m_GunMchn.GetBkColor();              //�v�I��
    m_Goal.SetCenter(m_GunMchn.GetPointPosition());  //�v��m
    m_Goal.SetPercent(0);
    VbrGoalThread((LPVOID)&Info1);

    c_bMsrBegin = (it == m_BeginItor) ?    TRUE : FALSE;

    return TRUE;
}

BOOL CPatternDlg::NextTrigger(std::vector<Cartridge>::iterator& it)
{
    it++;
    if (it != m_EndItor)
    {
        m_NextGoal.SetColor(ShiftColor(m_BkColor));          //�U�@�ӹv�C��
        m_NextGoal.SetCenter(m_GunMchn.GetPointPosition());  //�v��m
        VbrNextGoalThread((LPVOID)&Info1);

        it--;
        m_GunMchn.Trigger(it);

        c_bMsrEnd = FALSE;
        //�٥i�H�~��
    }
    else
    {
        c_bMsrEnd = TRUE;
        it--;
        //�����۰ʶq�����T��
    }
    return !c_bMsrEnd;  //�٥i�H�~��
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
            case VK_SPACE:  EventSwCntCa210();    break;//�����s�u
            case VK_UP:        EventRunZeroCal();    break;//Zero Cal
            case VK_DOWN:   EventRunMsrAi();      break;//�۰ʶq���Ҧ�
            case VK_RIGHT:  EventGoNextGoal();    break;//���U�@���I
            case VK_LEFT:   EventGoPrvsGoal();    break;//�W�@���I
            case VK_RETURN: EventCatchMsrValue(); break;//��ȧ���!!!!
            case VK_ESCAPE://����Patten Dialog
                if(c_bRunMsrAI)
                    KillTimer(1);
                m_pCA210->SetOnline(FALSE);
                ShowWindow(SW_HIDE);
                pDoc->RestructureVector();  //�����D~
                break;
        }
        return TRUE;
    }
    return CDialog::PreTranslateMessage(pMsg);
}

UINT CPatternDlg::Recoil()
{
    UINT recoil = 0;

    //�s�ثe��
    BOOL OldDrawNextGold = c_bDrawNextGold;
    BOOL OldDrawGold     = c_bDrawGold;
//    BOOL OldDebugDisplay = c_bDebugDisplay;
    BOOL OldStateBar     = c_bStateBar;
    BOOL OldMsrValues    = c_bMsrValues;
    BOOL OldMsring       = c_bMsring;

    //�T�w������
    c_bDrawNextGold = c_bDrawGold = c_bStateBar = c_bMsrValues = c_bMsring = FALSE;

    Invalidate();
    UpdateWindow();

    Sleep(70);

    recoil = m_pCA210->Measure();//���s�u�B��Zero Cal

    m_itor->SetBullet(m_pCA210->GetMsrData());

    //��_�ثe��
    c_bDrawNextGold = OldDrawNextGold;
    c_bDrawGold     = OldDrawGold;
//    c_bDebugDisplay = OldDebugDisplay;
    c_bStateBar     = OldStateBar;
    c_bMsrValues    = OldMsrValues;
    c_bMsring       = OldMsring;

    Invalidate();
    UpdateWindow();

    return recoil;
}

void CPatternDlg::Partition(std::vector<Cartridge>& vCar, Cartridge& MsrFlow)
{
    m_GunMchn.Partition(vCar, MsrFlow);
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

    PtnDlg->c_bGoalPercent = FALSE;
    if (PtnDlg->c_bMsrValues) PtnDlg->c_bMsrValues = FALSE; //�ʵe���ɭԡA����
    PtnDlg->Invalidate();
    PtnDlg->UpdateWindow();
    
    for (UINT i = 0; i < 16; ++i)
    {        
        PtnDlg->InvalidateRect(pGoal->VbrFun(i, oriR));
        PtnDlg->UpdateWindow();
        Sleep(15); //�ո`�ʵe���e�ɬO�_�ݱo��
    }
    PtnDlg->c_bGoalPercent = TRUE;
    return 0;
}

UINT CPatternDlg::VbrNextGoalThread(LPVOID LParam)
{
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

void CPatternDlg::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
    // TODO: Add your message handler code here and/or call default

    CDialog::OnLButtonDblClk(nFlags, point);
}

void CPatternDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
    // TODO: Add your message handler code here and/or call default

    CDialog::OnLButtonDown(nFlags, point);
}

// void CPatternDlg::SetOrigPriority(std::vector<Cartridge>& vCar)
// {
//     //�]�w��l�Ƨ�
//     std::vector<Cartridge>::size_type OrigPrty;
//     for (std::vector<Cartridge>::iterator itor = vCar.begin(); itor != vCar.end() ; ++itor)
//     {
//         OrigPrty = itor - vCar.begin();
//         itor->SetOrigSeqc(OrigPrty);
//     }
// }

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
    srand(time(NULL));
    MsrAIValue = m_pCA210->MsrAI((float)0.005);
    switch(MsrAIValue)
    {
        case 0://�G��0�A�ثe0-Cal
            EventRunMsrAi(FALSE);
            AfxMessageBox("�q���ثe�b0-Cal��I\n�����Measure�C");
            break;
        case 1://�зǪ��e�Ȥ��G�~��q��+�ʤ���
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
                        if (EventCatchMsrValue() == 1) //�̽������B�J
                            EventRunMsrAi(TRUE);
                    }
                    break;
            }
            break;
        case 2://�зǪ��e�ȥ~�G�~��q��-�ʤ���
            m_Percent -= rand()%25+rand()%25+1;
            break;
        case 3://���s�u
            c_bUnCntCA210 = TRUE;
            break;
    }
    Invalidate();
    UpdateWindow();

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
        c_bMsrValues = /*TRUE;*/c_bMsring = FALSE;
    }
}

BOOL CPatternDlg::EventGoNextGoal()
{
    //�U�@���I
    //m_Percent = 0;
    m_Goal.SetPercent(0);
    m_Percent = m_Goal.GetPercent();

    if (!c_bMsrEnd)
    {
        ++m_itor;
        if (m_itor == m_EndItor) m_itor--;
        if (m_itor == m_EndItor) m_itor--;
        
        Trigger(m_itor);
        NextTrigger(m_itor);
        c_bMsring = FALSE;
        c_bMsrValues = FALSE;
        Invalidate();
        return TRUE;
    }
    else
        return FALSE;
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
    2 �|��Zero Cal//************************************
    3 �ɦ줣�bMEAS
    4 �q�����` ��@1
    �̫�@�I  5
    */    
    switch(Recoil())
    {
    case 0:        MessageBox("�S�s�u�A�L�k�q��");        return 0;
    case 2:        MessageBox("�|��Zero Cal");            return 2;
    case 3:        MessageBox("�ɦ줣�bMEAS");            return 3;
    default:
        m_Goal.SetPercent(100);
        if (!EventGoNextGoal())
            return 5;//�O�_���̫�@�I
    }
    m_Goal.SetPercent(0);
    m_Percent = m_Goal.GetPercent();
    Invalidate();
    return 1;
}

void CPatternDlg::EventRunMsrAi(int isRun)
{
//���n�H�N��ʡI= =+
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
    m_pCA210->SetOnline(m_pCA210->GetOnline() ? FALSE : TRUE);
    Invalidate();
}

void CPatternDlg::EventRunZeroCal()
{
    c_bZeroCal = TRUE;
    Invalidate();
    UpdateWindow();
    if (!m_pCA210->CalZero())
        MessageBox("���s�u");
    c_bZeroCal = FALSE;
    Invalidate();
}

void CPatternDlg::FineNits()
{
    c_bMsring = TRUE;
     int i=60;
     int j;
     float fLv = 0;

    if (m_pCA210->isTrue())  //�������ɡA�N������
        for(j=0;j<2;++j)
        {
            while(fLv < m_GunMchn.GetNitsSpec())//�Y�G���٦b5�H�U�A�N...�ܫG
            {
                //�ܰʭI���C��
                m_BkColor = RGB(i,i,i);
                Invalidate();
                UpdateWindow();
                //�q�����
                m_pCA210->Measure();
                fLv = m_pCA210->GetMsrData().GetLv();//m_IProbe.GetLv();
                i+=2;
            }
            while(fLv >  m_GunMchn.GetNitsSpec())//�Y�G���٨S����5�H�U�A�N���
            {
                //�ܰʭI���C��
                m_BkColor = RGB(i,i,i);
                Invalidate();
                UpdateWindow();
                Sleep(60);
                //�q�����
                m_pCA210->Measure();
                fLv = m_pCA210->GetMsrData().GetLv();//m_IProbe.GetLv();
                --i;
            }
         }
    m_GunMchn.Set5NitsBkColor(m_BkColor);
    c_bMsring = c_bFind5nits = !c_bMsring;//5Nits�S�O�y�{����
}

void CPatternDlg::InitialVector()
{
    switch(initVectorType)
    {
    case MsrForItem:
        CMsrItemDlg dlgMsrItem;        //��Pattern Dialog��l�ơA���ǳ�
        dlgMsrItem.SetBolt(&m_GunMchn);
        if (dlgMsrItem.DoModal() == IDOK)        //�N�OMsrItemGo�����s
            c_bisReady = TRUE;
        break;
    }
}

BOOL CPatternDlg::isReady()
{
    return c_bisReady;
}