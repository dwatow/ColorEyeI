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
{
    //{{AFX_DATA_INIT(CPatternDlg)
        // NOTE: the ClassWizard will add member initialization here
    //}}AFX_DATA_INIT
    
    //之間的順序要固定，不要修改了！
//    m_Goal.setWnd();
//     CString str;
//     str.Format("%x\n", GetSafeOwner()->m_hWnd);
//     AfxMessageBox(str);

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
    CMsrItemDlg dlgMsrItem;        //為Pattern Dialog初始化，做準備
    switch(InitDataType)
    {
    case MsrForItem:
        dlgMsrItem.DoModal();  //之後判斷子彈是不是空的。
//        LoadedCartridge(dlgMsrItem.MsrItem());
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
    c_bMsrValues    = FALSE;
    c_bMsring       = FALSE;
    c_bGoalPercent  = FALSE;
    c_bRunMsrAI     = TRUE;
    c_bUnCntCA210   = FALSE;
    c_bFind5nits    = FALSE;

//    Info1.ptnDlg = this;

    ColorRef tempClr(255, 0, 127); //深紅色
    m_Goal.SetColor(tempClr.Shift(5));

    return TRUE;  // return TRUE unless you set the focus to a control
                  // EXCEPTION: OCX Property Pages should return FALSE
}

HBRUSH CPatternDlg::OnCtlColor(CDC* , CWnd* , UINT ) 
{
    m_BkBrush.DeleteObject();
    m_BkBrush.CreateSolidBrush(m_BkColor.oRGB());
    
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
    dc.SetBkColor(m_BkColor.oRGB());

    //Cross Talk 的背景色
//     ColorType SpecelPattern(m_GunMchn.GetColorType());
//     switch(SpecelPattern)
//     {
//     case CrsTlkW: m_GunMchn.CenterRect(&dc, RGB(255, 255, 255));  break;
//     case CrsTlkD: m_GunMchn.CenterRect(&dc, RGB(0, 0, 0));        break;
//     case JNDX:    m_GunMchn.CenterCross(&dc, RGB(255, 255, 255)); break;
//     }


//     if (c_bDrawNextGold) 
//         m_NextGoal.DrawCircle(dc);

DebugCode(
          dc.SetTextColor(m_BkColor.Shift());

        //Pattern運作參數
        //Goal訊息
        temp.Format("  Goal%s", m_Goal.showMe());
        TextOut(dc, 0, 0, temp, temp.GetLength());
        
        //NextGoal訊息
//         temp.Format("nGoal%s", m_NextGoal.showMe());
//         TextOut(dc, 0, 16, temp, temp.GetLength());

        //鍵盤訊息
    //     KeyMessage.Format("nChar = %d, nRepCnt = %d, nFlags = %d", key1, key2, key3);
    //     TextOut(dc, 0, 15, KeyMessage, 40);

        //iterator的訊息
        CString isEnd(m_itor == m_RNA.Begin()? "Begin" : m_itor == m_RNA.End() ? "End" : "Other");
        temp.Format("迭代器資訊: itor.begin = 0x%x, itor.end = 0x%x, itor(位址 / 位置) = 0x%x / %s", m_RNA.Begin(), m_RNA.End(), m_itor, isEnd);
        TextOut(dc, 0, 32, temp, temp.GetLength());

        temp.Format("PatternDlg旗標: Goal/nGoal = %d/%d, StateBar = %d;  Msr/Msring = %d/%d, 量測百分比 = %d%%, 第一點 = %d, 最後一點 = %d, 自動量測模式 = %d, 連結CA-210 = %d, 5Nits中心點 = %d", \
                     c_bDrawGold, c_bDrawNextGold, c_bStateBar, c_bMsrValues, c_bMsring, m_Goal.GetPercent(), c_bMsrBegin, c_bMsrEnd, !c_bRunMsrAI, c_bUnCntCA210, c_bFind5nits);
        TextOut(dc, 0, 48, temp, temp.GetLength());

//         temp.Format("翻譯器資訊: %s", m_GunMchn.GetSetupValue());
//         TextOut(dc, 0, 64, temp, temp.GetLength());

        temp.Format("這一點的資訊: %s", m_itor->showMe());
        TextOut(dc, 0, 80, temp, temp.GetLength());
)

    //狀態列
    if (c_bStateBar)
    {
        //操作說明（左）
        temp.Format("上一點: ←, 下一點: →, 抓值+下一點: Enter, 自動量測: ↓");
        TextOut(dc, 0, GetSystemMetrics(SM_CYSCREEN) - 15, temp, temp.GetLength());
        //狀態（右）
        temp.Format("連線狀態: %s, 目前量測: %s,  解析度: %d×%d,  Channel: %s,  LCM size: %2.1f inch", \
            m_pCA210->isOnline() ? "連線" : "離線" , m_itor->GetDescrip(), GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), m_pCA210->GetChData(), m_pCA210->GetLcmSize());//LCM Size這樣抓會有問題
        TextOut(dc, GetSystemMetrics(SM_CXSCREEN) - (int)(temp.GetLength()*6.7), GetSystemMetrics(SM_CYSCREEN) - 15, temp, temp.GetLength());
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

    //量測數據指示
    if (c_bMsring)
        drawMsringLabel(dc);

    if (c_bMsrValues)
        drawMsrLabel(dc);

    dc.SetTextColor(m_BkColor.Invrt());

    if (c_bMsrEnd && c_bRunMsrAI && c_bMsrEndnMsred)
    {
        temp.Format("按ESC離開。");    
        if ((m_Goal.GetCenter().x == GetSystemMetrics(SM_CXSCREEN)/2) && (m_Goal.GetCenter().y == GetSystemMetrics(SM_CYSCREEN)/2))
            TextOut(dc, GetSystemMetrics(SM_CXSCREEN)/2 - 75, GetSystemMetrics(SM_CYSCREEN)/2-8-m_Goal.GetRadius()*2, temp, temp.GetLength());
        else
            TextOut(dc, GetSystemMetrics(SM_CXSCREEN)/2 - 75, GetSystemMetrics(SM_CYSCREEN)/2-8, temp, temp.GetLength());
    }

    if (c_bUnCntCA210)
        temp.Format("未連接CA-210。");
    else
        temp.Format("");
    TextOut(dc, GetSystemMetrics(SM_CXSCREEN)/2 - 75, GetSystemMetrics(SM_CYSCREEN)/2-8, temp, temp.GetLength());

    // TODO: Add your message handler code here
    // Do not call CDialog::OnPaint() for painting messages
}

void CPatternDlg::drawMsrLabel(CDC &aDC)
{
    const int r = m_Goal.GetRadius();
    const CSize Area(88, 158);
    CPoint shift(-10-r, -20-r);

    CRect rect1(m_Goal.GetCenter() + shift, Area);
    aDC.SetTextColor(m_BkColor.Invrt());
    
    //已量過的數據
    aDC.DrawText(m_itor->GetBullet().show(), rect1, DT_LEFT | DT_VCENTER);

}

void CPatternDlg::drawMsringLabel(CDC &aDC)
{    
    const int r = m_Goal.GetRadius();
    const CSize Area(88, 158);
    CPoint shift(0, -20-r);
    shift.x = (m_Goal.GetCenter().x < (LONG)((m_Goal.GetRadius()+125) + 88))? 40-r : -125-r;

    CRect rect2(m_Goal.GetCenter() + shift, Area);
    aDC.SetTextColor(m_BkColor.Shift());

    //正在量的數據
    aDC.DrawText(m_pCA210->OutData(), rect2, DT_LEFT | DT_VCENTER);
}

void CPatternDlg::setBkColor(ColorRef clr)
{
    m_BkColor = clr;
}



void CPatternDlg::setupLCMSize()
{
    if (!atoi(m_pCA210->GetLcmSize()))
    {
        CEnterValueDlg dlgEnterValue("無法判別LCM Size", "LCM Size");

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

    //SetPanelID
    CReadBarCodeDialog dlgReadBarCode;
    dlgReadBarCode.DoModal();

    m_RNA = pDoc->GetDocRNA();
    m_itor = m_RNA.Begin();
}

void CPatternDlg::LoadedCartridge()
{
    // TODO: Add extra validation here
    m_Goal.setWnd(GetActiveWindow()); //GetActiveWindow()需等建構式完成才可以抓取
    initDocument();

    //MsrItem按下「確定」還是「取消」
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
    //目前這一點是不是5nits的中心點？2=是
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

    setBkColor(m_itor->GetBkColor());          //靶背景
    m_Goal.SetCenter(m_itor->GetPointPosi());  //靶位置
    m_Goal.SetPercent(0);

    //if ( /*!c_bMsrEndnMsred || it->GetMsrFlowNum() != PnGamma && */m_itor != m_RNA.Begin())
    m_Goal.Animation();
    
	checkMsrLimit();
}

void CPatternDlg::checkMsrLimit()
{
    c_bMsrBegin = (m_itor == m_RNA.Begin()) ? TRUE : FALSE;
    c_bMsrEnd   = (m_itor+1 == m_RNA.End() ) ? TRUE : FALSE;
    c_bMsrEndnMsred = ( (m_itor+1 == m_RNA.End()) && (m_itor->GetBullet().isEmpty()) ) ? FALSE : TRUE;
}

BOOL CPatternDlg::PreTranslateMessage(MSG* pMsg) 
{
    // TODO: Add your specialized code here and/or call the base class
    if (pMsg->message == WM_KEYDOWN)
    {
        switch(pMsg->wParam)
        {
            case VK_SPACE:  eventSwCntCa210();    break;//空白鍵：切換連線
            case VK_DOWN:   eventRunMsrAi();      break;//下   ：自動量測模式
            case VK_RIGHT:  eventGoNextGoal();    break;//右   ：跳下一個點
            case VK_LEFT:   eventGoPrvsGoal();    break;//左   ：上一個點
            case VK_RETURN: eventCatchMsrValue(); break;//Enter：抓值抓抓抓!!!!
            case VK_ESCAPE: eventExitDialog();    break;//ESC  ：跳離Patten Dialog
                
        }
        return TRUE;
    }
    return CDialog::PreTranslateMessage(pMsg);
}

CaState CPatternDlg::Recoil()
{
    //暫存目前的螢幕顯示/隱藏狀態
    BOOL OldDrawNextGold = c_bDrawNextGold;
    BOOL OldDrawGold     = c_bDrawGold;
    BOOL OldStateBar     = c_bStateBar;
    BOOL OldMsrValues    = c_bMsrValues;
    BOOL OldMsring       = c_bMsring;
    BOOL OldGoalPercent  = c_bGoalPercent;

    //固定關掉所有螢幕顯示/隱藏狀態
    c_bDrawNextGold = c_bDrawGold = c_bStateBar = c_bMsrValues = c_bMsring = c_bGoalPercent = FALSE;

    Invalidate();
    UpdateWindow();

    Sleep(70);

    CaState camsrResult(m_pCA210->Measure());

    m_itor->SetBullet(m_pCA210->GetMsrData());

    //恢復目前的螢幕顯示/隱藏狀態
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
    c_bGoalPercent = TRUE;
    if (m_pCA210->isOnline())
    {
        srand(time(NULL));
        MsrAIValue = m_pCA210->MsrAI((float)0.005);
        switch(MsrAIValue)
        {
            case MA_InDeviation://標準門檻值內：繼續量測+百分比
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
                            eventRunMsrAi(FALSE);
                            if ((eventCatchMsrValue() == 1) //最複雜的步驟
                                || (c_bMsrEndnMsred == FALSE))
                                eventRunMsrAi(TRUE);
                        }
                        break;
                }
                break;
            case MA_OutDeviation://標準門檻值外：繼續量測-百分比
                m_Percent -= rand()%25+rand()%25+1;
                break;
            case MA_nonMsr:
                eventRunMsrAi(FALSE);
                AfxMessageBox("檢查探頭：要轉到MEAS\n檢查主機：REMOTE燈要亮\n可以順利自動量測！");
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
    //上一個點
    if (!c_bMsrBegin)
    {
        ++m_itor;
        if (m_itor != m_RNA.Begin())    m_itor--;
        if (m_itor != m_RNA.Begin())    m_itor--;
        
        trigger(); //它會等於0，就是從最後一回返回一次        
        Invalidate();
//         if (m_itor->GetBackColor() == JND || JNDX) 
//             c_bMsrValues = FALSE;
//         else
             c_bMsrValues = TRUE;

        c_bMsring = FALSE;
    }
}

BOOL CPatternDlg::eventGoNextGoal()
{
    //下一個點
    //m_Goal.SetPercent(0);
    //m_Percent = m_Goal.GetPercent();

    if (!c_bMsrEnd)
    {
        //計算下一顆
        ++m_itor;
        if (m_itor == m_RNA.End()) m_itor--;
        if (m_itor == m_RNA.End()) m_itor--;
    }

    //重新畫圈圈+動畫
    trigger();
    c_bMsring = FALSE;
    c_bMsrValues = FALSE;
    Invalidate();

    return !c_bMsrEnd;
}

UINT CPatternDlg::eventCatchMsrValue()
{
    //抓值抓抓抓!!!!
    //最後一點的話就停止自動
    //不然就是下一點
    if (c_bFind5nits)
        fineNits();//找背景亮度
    /*
    Recoil() 
    0 沒連線
    1 連線
    2 尚未Zero Cal
    3 檔位不在MEAS
    4 量測正常 當作1
    最後一點  5
    */

    switch(Recoil())
    {
    case CA_Offline:        
        MessageBox("沒連線，無法量測");  
        return 0;
    case CA_ZeroCalMode:    
        MessageBox("檔位不在MEAS");     
        return 3;
    case CA_MsrMode:
    default:
        if (!eventGoNextGoal())
            return 5;//是否為最後一點
        else
            return 1;
    }
}

void CPatternDlg::eventRunMsrAi(int isRun)
{
//不要隨意更動！= =+
    //關就給它開，開就給它關
    //指定控制 TRUE FALSE
    // 2 : Switch Mode
    // 1 : Assign Run Mode
    // 0 : Assign Off Mode
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

void CPatternDlg::eventSwCntCa210()
{
    //切換連線
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

void CPatternDlg::changeBkColor(ColorRef color)
{
    setBkColor(color);
    Invalidate();
    UpdateWindow();
}

void CPatternDlg::fineNitsPos(int& _gl)
{
    float fLv = 0;
    int Graylevel = 55;
    while(fLv >  m_GunMchn.GetNitsSpec())  //若亮度還沒有到5以下，就減少
    {
        _gl -= 2;
        changeBkColor(_gl);  //變成m_BkColor
//        Sleep(0);
        //量測抓值
        if (m_pCA210->Measure() == CA_ZeroCalMode)
            MessageBox("檔位不在MEAS");
        fLv = m_pCA210->GetMsrData().oFlt(VluK_Lv);  //m_IProbe.GetLv();
    }

    while(fLv < m_GunMchn.GetNitsSpec())   //若亮度還在5以下，就...變亮
    {
        ++_gl;
        changeBkColor(_gl);
        Sleep(60);
        //量測抓值
        m_pCA210->Measure();
        fLv = m_pCA210->GetMsrData().oFlt(VluK_Lv);  //m_IProbe.GetLv();
    }
}

void CPatternDlg::fineNitsNeg(int& _gl)
{
    float fLv = 0;

    while(fLv <  m_GunMchn.GetNitsSpec())  //若亮度還沒有到5以下，就減少
    {
        _gl += 2;
        changeBkColor(_gl);
//        Sleep(0);
        //量測抓值
        if (m_pCA210->Measure() == CA_ZeroCalMode)
            MessageBox("檔位不在MEAS");
        fLv = m_pCA210->GetMsrData().oFlt(VluK_Lv);  //m_IProbe.GetLv();
    }
    
    while(fLv > m_GunMchn.GetNitsSpec())   //若亮度還在5以下，就...變亮
    {
        --_gl;
        changeBkColor(_gl);
        Sleep(60);
        //量測抓值
        m_pCA210->Measure();
        fLv = m_pCA210->GetMsrData().oFlt(VluK_Lv);  //m_IProbe.GetLv();
    }
}

void CPatternDlg::fineNits()
{
    c_bMsring = TRUE;
    c_bMsrValues = FALSE;
    int i;

    //夾擊演算法
//    int glvMax = 255, glvMin = 0;

//     while ((glvMax - glvMin) > 2)
//     {
//         Graylevel = (glvMax + glvMin)/2;
//         changeBkColor(Graylevel);
//         m_pCA210->Measure();
//         fLv = m_pCA210->GetMsrData().GetLv();
//         
//         if( fLv > m_GunMchn.GetNitsSpec() )
//             glvMax = Graylevel;
//         else// if (fLv > m_GunMchn.GetNitsSpec() )
//             glvMin = Graylevel;
//     }
// 
//     CString str;
//     str.Format("max:%d\nmin%d\ngraylv:%d", glvMax, glvMin, Graylevel);
//     AfxMessageBox(str);

    int Graylevel(60);

         if (m_GunMchn.GetNitsKind() == NK_POS) Graylevel = 55;
    else if (m_GunMchn.GetNitsKind() == NK_NEG) Graylevel = 60;

    for(i = 0; i < 2; ++i)
    {
              if (m_GunMchn.GetNitsKind() == NK_POS) fineNitsPos(Graylevel);
         else if (m_GunMchn.GetNitsKind() == NK_NEG) fineNitsNeg(Graylevel);
        else MessageBox("找Nits出問題。");
    }
    m_GunMchn.Set5NitsBkColor(m_BkColor.oRGB());
    c_bMsring = c_bFind5nits = !c_bMsring;  //5Nits特別流程結束
}

void CPatternDlg::OnShowWindow(BOOL bShow, UINT nStatus) 
{
    CDialog::OnShowWindow(bShow, nStatus);
    
    m_pCA210->SetOnline(bShow);    
}