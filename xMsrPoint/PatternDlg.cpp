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
	//之間的順序要固定，不要修改了！
    
	if (!ConnectCa210())
        MessageBox("OnButtonMsr的CA-210連線錯誤\n這個程式即將關閉!!\n\n要關囉!");    

	CMainFrame* pMainFrm = dynamic_cast<CMainFrame*>(AfxGetMainWnd());
    ASSERT_VALID(pMainFrm);
    pMainFrm->m_pCa210->LinkMemory();
    InitialVector();
  
    CColorEyeIDoc* pDoc = dynamic_cast<CColorEyeIDoc*>(pMainFrm->GetActiveDocument());
    ASSERT_VALID(pDoc);
    
	//之後的部份要在
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
//    c_bDebugDisplay = TRUE;  //Debug 資料顯示  //替換成 #ifdef-#endif
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
    運作參數
        Goal訊息
        NextGoal訊息
        iterator的訊息
        繪圖參數
    狀態列
        操作說明
        狀態
    主要量測指示
        百分比顯示
        Goal
    量測目標指示
        數據顯示
    zero cal的字
    end的字
    */

    CPaintDC dc(this); // device context for painting
    CString temp;
    dc.SetBkMode(OPAQUE);
     dc.SetBkColor(m_BkColor);

    //Cross Talk 的背景色
    if (m_GunMchn.GetColorType() == CrsTlkW)
        m_GunMchn.CenterRect(&dc, 4.0, RGB(255, 255, 255));
    if (m_GunMchn.GetColorType() == CrsTlkD)
        m_GunMchn.CenterRect(&dc, 4.0, RGB(0, 0, 0));

//    dc.SetBkMode(TRANSPARENT);
    dc.SetTextColor(ShiftColor(m_BkColor));
    if (c_bDrawNextGold) 
        m_NextGoal.DrawCircle(dc);

#ifdef _DEBUG//     if (c_bDebugDisplay){

        //Pattern運作參數
        //Goal訊息
        temp.Format("  Goal%s",    m_Goal.GetSetupValue());
        TextOut(dc, 0, 0, temp, temp.GetLength());
        
        //NextGoal訊息
        temp.Format("nGoal%s", m_NextGoal.GetSetupValue());
        TextOut(dc, 0, 16, temp, temp.GetLength());

        //鍵盤訊息
    //     KeyMessage.Format("nChar = %d, nRepCnt = %d, nFlags = %d", key1, key2, key3);
    //     TextOut(dc, 0, 15, KeyMessage, 40);

        //iterator的訊息
        CString isEnd(m_itor == m_BeginItor? "Begin" : m_itor == m_EndItor ? "End" : "Other");
        temp.Format("迭代器資訊: itor.begin = 0x%x, itor.end = 0x%x, itor(位址 / 位置) = 0x%x / %s", m_BeginItor, m_EndItor, m_itor, isEnd);
        TextOut(dc, 0, 32, temp, temp.GetLength());

        temp.Format("PatternDlg旗標: Goal/nGoal = %d/%d, StateBar = %d;  Msr/Msring = %d/%d, 量測百分比 = %d%%, 歸零校正 = %d, 第一點 = %d, 最後一點 = %d, 自動量測模式 = %d, 連結CA-210 = %d, 5Nits中心點 = %d", \
                     c_bDrawGold, c_bDrawNextGold, c_bStateBar, c_bMsrValues, c_bMsring, m_Goal.GetPercent(), c_bZeroCal, c_bMsrBegin, c_bMsrEnd, !c_bRunMsrAI, c_bUnCntCA210, c_bFind5nits);
        TextOut(dc, 0, 48, temp, temp.GetLength());


        temp.Format("翻譯器資訊: %s", m_GunMchn.GetSetupValue());
        TextOut(dc, 0, 64, temp, temp.GetLength());

        temp.Format("這一點的資訊: %s", m_itor->GetSetupValue());
        TextOut(dc, 0, 80, temp, temp.GetLength());
#endif//    }

    //狀態列
    if (c_bStateBar)
    {
        //操作說明（左）
        temp.Format("Zero-Cal: ↑, 抓值量測: ↓, 上一點: ←, 下一點: →");
        TextOut(dc, 0, GetSystemMetrics(SM_CYSCREEN) - 15, temp, temp.GetLength());
        //狀態（右）
        temp.Format("連線狀態: %s, 目前量測: %s,  解析度: %d×%d,  Channel: %s,  LCM size: %s inch", \
            m_pCA210->GetOnline() ? "連線" : "離線" , m_GunMchn.GetMsrFlowName(), GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), m_pCA210->GetChData(), m_pCA210->GetLcmSize().Left(2));
        TextOut(dc, GetSystemMetrics(SM_CXSCREEN) - temp.GetLength()*6.7, GetSystemMetrics(SM_CYSCREEN) - 15, temp, temp.GetLength());
    }

    //主要量測指示
    if (c_bDrawGold)
        m_Goal.DrawCircle(dc);//量測目標

    if (c_bGoalPercent)
    {
    //百分比顯示
        temp.Format("%3d%% \0", m_Goal.GetPercent());
        TextOut(dc, m_Goal.GetCenter().x - 15, m_Goal.GetCenter().y - (m_Goal.GetRadius()+20) , (LPCSTR)temp, temp.GetLength());  //上
        TextOut(dc, m_Goal.GetCenter().x - 15, m_Goal.GetCenter().y + (m_Goal.GetRadius()+2 ) , (LPCSTR)temp, temp.GetLength());  //下
        TextOut(dc, m_Goal.GetCenter().x - (m_Goal.GetRadius()+40),  m_Goal.GetCenter().y -7 , (LPCSTR)temp, temp.GetLength());  //左
        TextOut(dc, m_Goal.GetCenter().x + (m_Goal.GetRadius()+2) ,  m_Goal.GetCenter().y -7 , (LPCSTR)temp, temp.GetLength());  //右
    }

    //量測目標指示
    if (c_bMsring)
        DrawMsringLabel(dc);

    if (c_bMsrValues)
        DrawMsrLabel(dc);

    dc.SetTextColor(InvrtColor(m_BkColor));

    if (c_bZeroCal)
    {
        if (!m_pCA210->isTrue())
            temp.Format("沒接 CA-210，模擬Zero Cal");
        else
            temp.Format("       正在Zero Cal...   ");
        TextOut(dc, GetSystemMetrics(SM_CXSCREEN)/2 - 75, GetSystemMetrics(SM_CYSCREEN)/2-8, temp, temp.GetLength());
    }

    if (c_bMsrEnd && c_bRunMsrAI)
    {
        temp.Format("這是最後一點！量完時，按ESC離開。");    
        if ((m_Goal.GetCenter().x == GetSystemMetrics(SM_CXSCREEN)/2) && (m_Goal.GetCenter().y == GetSystemMetrics(SM_CYSCREEN)/2))
            TextOut(dc, GetSystemMetrics(SM_CXSCREEN)/2 - 75, GetSystemMetrics(SM_CYSCREEN)/2-8-m_Goal.GetRadius()*2, temp, temp.GetLength());
        else
            TextOut(dc, GetSystemMetrics(SM_CXSCREEN)/2 - 75, GetSystemMetrics(SM_CYSCREEN)/2-8, temp, temp.GetLength());
    }

    if (c_bUnCntCA210)
    {
        if (c_bUnCntCA210)        temp.Format("未連接CA-210。");
        TextOut(dc, GetSystemMetrics(SM_CXSCREEN)/2 - 75, GetSystemMetrics(SM_CYSCREEN)/2-8, temp, temp.GetLength());
    }

    // TODO: Add your message handler code here
    // Do not call CDialog::OnPaint() for painting messages
}

void CPatternDlg::DrawMsrLabel(CDC &dc)
{
    CRect* rect1 = new CRect
        (m_Goal.GetCenter().x - (m_Goal.GetRadius()+10)     , m_Goal.GetCenter().y - (m_Goal.GetRadius()+20), \
         m_Goal.GetCenter().x - (m_Goal.GetRadius()+10) + 88, m_Goal.GetCenter().y - (m_Goal.GetRadius()+20) + 158); //設定文字區塊
    
    dc.SetTextColor(InvrtColor(m_BkColor));
    CString temp;
    temp.Format(" Lv =%3.2f\nx =%1.4f \ny =%1.4f\nT =%3d \nΔuv=%1.4f\nu' =%1.4f\nv' =%1.4f\nX = %3.2f\nY = %3.2f\nZ = %3.2f", \
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
             m_Goal.GetCenter().x + (m_Goal.GetRadius()+40) + 88, m_Goal.GetCenter().y - (m_Goal.GetRadius()+20) + 158); //設定文字區塊

    }
    else
    {
        rect2= new CRect
            (m_Goal.GetCenter().x - (m_Goal.GetRadius()+125)     , m_Goal.GetCenter().y - (m_Goal.GetRadius()+20), \
             m_Goal.GetCenter().x - (m_Goal.GetRadius()+125) + 88, m_Goal.GetCenter().y - (m_Goal.GetRadius()+20) + 158); //設定文字區塊
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
    ++m_itor;               //閃掉第一個空包彈
    m_BeginItor = m_itor;
    m_EndItor   = vCar.end();

    //++BeginItor;  
    if(!m_GunMchn.isReady())
    {
        if (!m_GunMchn.Magazine(m_pCA210->GetLcmSize(), m_EndItor))    MessageBox("Chanel選錯了\nPtnDlg->Magazine的槍機上膛出錯");            //上膛
            Trigger(m_itor);//)                                MessageBox("PtnDlg->Magazine的扳機出錯");
            NextTrigger(m_itor);//)                            MessageBox("PtnDlg->Magazine的下一搶扳機出錯");
        if (    !m_Goal.SetRadius(m_GunMchn.GetRadius()))        MessageBox("Chanel選錯了\nPtnDlg->Magazine的載入目標靶半徑出錯");     //靶大小
        if (!m_NextGoal.SetRadius(m_GunMchn.GetRadius()))        MessageBox("Chanel選錯了\nPtnDlg->Magazine的載入下一靶半徑出錯");     //次靶大小

        Invalidate();
        
        return TRUE;  //第一次量測
    }
    else
        return FALSE; //單點覆測使用
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
    ++m_itor;               //閃掉第一個空包彈
    m_BeginItor = m_itor;
    m_EndItor   = pDoc->GetVector().end();
    
    //++BeginItor;  
    if(!m_GunMchn.isReady())
    {
        if (!m_GunMchn.Magazine(m_pCA210->GetLcmSize(), m_EndItor))    MessageBox("Chanel選錯了\nPtnDlg->Magazine的槍機上膛出錯");            //上膛
        Trigger(m_itor);
        NextTrigger(m_itor);
        if (    !m_Goal.SetRadius(m_GunMchn.GetRadius()))        MessageBox("Chanel選錯了\nPtnDlg->Magazine的載入目標靶半徑出錯");     //靶大小
        if (!m_NextGoal.SetRadius(m_GunMchn.GetRadius()))        MessageBox("Chanel選錯了\nPtnDlg->Magazine的載入下一靶半徑出錯");     //次靶大小
        
        Invalidate();
        
        return TRUE;  //第一次量測
    }
    else
        return FALSE; //單點覆測使用
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
    //目前這一點是不是5nits的中心點？2=是
    c_bFind5nits = (m_GunMchn.Trigger(it) == 2)? TRUE:FALSE;

    m_BkColor = m_GunMchn.GetBkColor();              //靶背景
    m_Goal.SetCenter(m_GunMchn.GetPointPosition());  //靶位置
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
        m_NextGoal.SetColor(ShiftColor(m_BkColor));          //下一個靶顏色
        m_NextGoal.SetCenter(m_GunMchn.GetPointPosition());  //靶位置
        VbrNextGoalThread((LPVOID)&Info1);

        it--;
        m_GunMchn.Trigger(it);

        c_bMsrEnd = FALSE;
        //還可以繼續
    }
    else
    {
        c_bMsrEnd = TRUE;
        it--;
        //結束自動量測的訊號
    }
    return !c_bMsrEnd;  //還可以繼續
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
            case VK_SPACE:  EventSwCntCa210();    break;//切換連線
            case VK_UP:        EventRunZeroCal();    break;//Zero Cal
            case VK_DOWN:   EventRunMsrAi();      break;//自動量測模式
            case VK_RIGHT:  EventGoNextGoal();    break;//跳下一個點
            case VK_LEFT:   EventGoPrvsGoal();    break;//上一個點
            case VK_RETURN: EventCatchMsrValue(); break;//抓值抓抓抓!!!!
            case VK_ESCAPE://跳離Patten Dialog
                if(c_bRunMsrAI)
                    KillTimer(1);
                m_pCA210->SetOnline(FALSE);
                ShowWindow(SW_HIDE);
                pDoc->RestructureVector();  //有問題~
                break;
        }
        return TRUE;
    }
    return CDialog::PreTranslateMessage(pMsg);
}

UINT CPatternDlg::Recoil()
{
    UINT recoil = 0;

    //存目前的
    BOOL OldDrawNextGold = c_bDrawNextGold;
    BOOL OldDrawGold     = c_bDrawGold;
//    BOOL OldDebugDisplay = c_bDebugDisplay;
    BOOL OldStateBar     = c_bStateBar;
    BOOL OldMsrValues    = c_bMsrValues;
    BOOL OldMsring       = c_bMsring;

    //固定全關掉
    c_bDrawNextGold = c_bDrawGold = c_bStateBar = c_bMsrValues = c_bMsring = FALSE;

    Invalidate();
    UpdateWindow();

    Sleep(70);

    recoil = m_pCA210->Measure();//有連線、有Zero Cal

    m_itor->SetBullet(m_pCA210->GetMsrData());

    //恢復目前的
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
    //圈圈跳出動畫
    MyThreadInfo *pInfo1 = (MyThreadInfo *)LParam;
    CPatternDlg  *PtnDlg = (CPatternDlg*)(pInfo1->ptnDlg);
    Circle *pGoal = (Circle*)&(PtnDlg->m_Goal);//(pInfo1->crl);

    UINT oriR = pGoal->GetRadius(), 
         varR = 0;
    
    CPoint p1(pGoal->GetCenter());

    PtnDlg->c_bGoalPercent = FALSE;
    if (PtnDlg->c_bMsrValues) PtnDlg->c_bMsrValues = FALSE; //動畫的時候，關掉
    PtnDlg->Invalidate();
    PtnDlg->UpdateWindow();
    
    for (UINT i = 0; i < 16; ++i)
    {        
        PtnDlg->InvalidateRect(pGoal->VbrFun(i, oriR));
        PtnDlg->UpdateWindow();
        Sleep(15); //調節動畫重畫時是否看得到
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
//     //設定原始排序
//     std::vector<Cartridge>::size_type OrigPrty;
//     for (std::vector<Cartridge>::iterator itor = vCar.begin(); itor != vCar.end() ; ++itor)
//     {
//         OrigPrty = itor - vCar.begin();
//         itor->SetOrigSeqc(OrigPrty);
//     }
// }

void CPatternDlg::OnTimer(UINT nIDEvent) 
{
    //檢查連線
//    c_bUnCntCA210 = FALSE;
    /*
        兩個門檻
        1. 量測門檻值
           0  亮度0，目前0-Cal
           1  標準門檻值內：繼續量測+百分比→ 2.
           2  標準門檻值外：繼續量測-百分比
           3  未連線

        2. 百分比
           0 小於0
           1 標準範圍 →2.
           2 大於100
    */
    srand(time(NULL));
    MsrAIValue = m_pCA210->MsrAI((float)0.005);
    switch(MsrAIValue)
    {
        case 0://亮度0，目前0-Cal
            EventRunMsrAi(FALSE);
            AfxMessageBox("量測目前在0-Cal唷！\n請轉至Measure。");
            break;
        case 1://標準門檻值內：繼續量測+百分比
            SetPercentValue = m_Goal.SetPercent(m_Percent);
            switch (SetPercentValue)
            {
                case 0://空杯啦
                    //m_Percent = rand()%20+10;
                    m_Goal.SetPercent(rand()%20+10);
                    m_Percent = m_Goal.GetPercent();
                    break;
                case 1://進行中
                    m_Percent += rand()%50+rand()%50+1;
                    break;
                case 2://滿出來啦
                    c_bMsrValues = /*TRUE;*/c_bMsring = FALSE;
                    if (m_Percent > 83)
                    {
                        EventRunMsrAi(FALSE);
                        if (EventCatchMsrValue() == 1) //最複雜的步驟
                            EventRunMsrAi(TRUE);
                    }
                    break;
            }
            break;
        case 2://標準門檻值外：繼續量測-百分比
            m_Percent -= rand()%25+rand()%25+1;
            break;
        case 3://未連線
            c_bUnCntCA210 = TRUE;
            break;
    }
    Invalidate();
    UpdateWindow();

    CDialog::OnTimer(nIDEvent);
}

void CPatternDlg::EventGoPrvsGoal()
{
    //上一個點
    if (!c_bMsrBegin)
    {
        ++m_itor;
        if (m_itor != m_BeginItor)    m_itor--;
        if (m_itor != m_BeginItor)    m_itor--;
        
        Trigger(m_itor); //它會等於0，就是從最後一回返回一次        
        NextTrigger(m_itor);
        Invalidate();
        c_bMsrValues = /*TRUE;*/c_bMsring = FALSE;
    }
}

BOOL CPatternDlg::EventGoNextGoal()
{
    //下一個點
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
    //抓值抓抓抓!!!!
    //最後一點的話就停止自動
    //不然就是下一點
    if (c_bFind5nits)
        FineNits();//找背景亮度
    /*
    Recoil() 
    0 沒連線
    1 連線
    2 尚未Zero Cal//************************************
    3 檔位不在MEAS
    4 量測正常 當作1
    最後一點  5
    */    
    switch(Recoil())
    {
    case 0:        MessageBox("沒連線，無法量測");        return 0;
    case 2:        MessageBox("尚未Zero Cal");            return 2;
    case 3:        MessageBox("檔位不在MEAS");            return 3;
    default:
        m_Goal.SetPercent(100);
        if (!EventGoNextGoal())
            return 5;//是否為最後一點
    }
    m_Goal.SetPercent(0);
    m_Percent = m_Goal.GetPercent();
    Invalidate();
    return 1;
}

void CPatternDlg::EventRunMsrAi(int isRun)
{
//不要隨意更動！= =+
    c_bRunMsrAI = (isRun == 2) ? c_bRunMsrAI ? FALSE : TRUE : !isRun;

    switch(isRun)
    {
    default:
        if (!c_bRunMsrAI)
        {
    case 1://自動量測啟始點
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
    //切換連線
    m_pCA210->SetOnline(m_pCA210->GetOnline() ? FALSE : TRUE);
    Invalidate();
}

void CPatternDlg::EventRunZeroCal()
{
    c_bZeroCal = TRUE;
    Invalidate();
    UpdateWindow();
    if (!m_pCA210->CalZero())
        MessageBox("未連線");
    c_bZeroCal = FALSE;
    Invalidate();
}

void CPatternDlg::FineNits()
{
    c_bMsring = TRUE;
     int i=60;
     int j;
     float fLv = 0;

    if (m_pCA210->isTrue())  //虛擬機時，就不執行
        for(j=0;j<2;++j)
        {
            while(fLv < m_GunMchn.GetNitsSpec())//若亮度還在5以下，就...變亮
            {
                //變動背景顏色
                m_BkColor = RGB(i,i,i);
                Invalidate();
                UpdateWindow();
                //量測抓值
                m_pCA210->Measure();
                fLv = m_pCA210->GetMsrData().GetLv();//m_IProbe.GetLv();
                i+=2;
            }
            while(fLv >  m_GunMchn.GetNitsSpec())//若亮度還沒有到5以下，就減少
            {
                //變動背景顏色
                m_BkColor = RGB(i,i,i);
                Invalidate();
                UpdateWindow();
                Sleep(60);
                //量測抓值
                m_pCA210->Measure();
                fLv = m_pCA210->GetMsrData().GetLv();//m_IProbe.GetLv();
                --i;
            }
         }
    m_GunMchn.Set5NitsBkColor(m_BkColor);
    c_bMsring = c_bFind5nits = !c_bMsring;//5Nits特別流程結束
}

void CPatternDlg::InitialVector()
{
    switch(initVectorType)
    {
    case MsrForItem:
        CMsrItemDlg dlgMsrItem;        //為Pattern Dialog初始化，做準備
        dlgMsrItem.SetBolt(&m_GunMchn);
        if (dlgMsrItem.DoModal() == IDOK)        //就是MsrItemGo的按鈕
            c_bisReady = TRUE;
        break;
    }
}

BOOL CPatternDlg::isReady()
{
    return c_bisReady;
}