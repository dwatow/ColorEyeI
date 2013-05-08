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
		CString str("Pattern Dialog初始化量測資料出問題");
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

    ColorRef tempClr(255, 0, 127); //深紅色
    m_Goal.SetArcColor(tempClr.Shift(5));

    return TRUE;  // return TRUE unless you set the focus to a control
                  // EXCEPTION: OCX Property Pages should return FALSE
}

HBRUSH CPatternDlg::OnCtlColor(CDC* , CWnd* , UINT ) 
{
    //永遠都不需要修改
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
        //Pattern運作參數
        //Goal訊息
        temp.Format("  Goal%s", m_Goal.showMe());
        TextOut(dc, 0, wordHight*lineIndex++, temp, temp.GetLength());
        
        //鍵盤訊息
//         KeyMessage.Format("nChar = %d, nRepCnt = %d, nFlags = %d", key1, key2, key3);
//         TextOut(dc, 0, wordHight*lineIndex++, KeyMessage, 40);

        //iterator的訊息
        CString IsEndstr ( m_itor == m_RNA.Begin()? "Begin" : m_itor == m_RNA.End() ? "End" : "Other" );

        temp.Format("迭代器資訊: itor.begin = 0x%x, itor.end = 0x%x, itor(位址 / 位置) = 0x%x / %s", \
			m_RNA.Begin(), m_RNA.End(), m_itor, IsEndstr);
        TextOut(dc, 0, wordHight*lineIndex++, temp, temp.GetLength());

        temp.Format("PatternDlg旗標: IsShowGoal: %d, IsShowStateBar: %d, 第一點 = %d, 最後一點 = %d, 最後一點量完 = %d, 自動量測模式 = %d, 連結CA-210 = %d", \
                     m_Goal.isVisible(), c_bStatusBar, c_bMsrBegin, c_bMsrEnd, c_bMsrEndnMsred, !c_bRunMsrAI, c_bUnCntCA210);
        TextOut(dc, 0, wordHight*lineIndex++, temp, temp.GetLength());

        temp.Format("這一點的資訊: %s", m_itor->ShowMe());
        TextOut(dc, 0, wordHight*lineIndex++, temp, temp.GetLength());
)

    //狀態列
    if (c_bStatusBar)
    {
        dc.SetTextColor(m_BkColor.Shift());
        //操作說明（左）
        temp.Format("上一點: ←, 下一點: →, 抓值+下一點: Enter, 自動量測: ↓");
        TextOut(dc, 0, GetSystemMetrics(SM_CYSCREEN) - wordHight*1, temp, temp.GetLength());
        //狀態（右）
        temp.Format("連線狀態: %s, 目前量測: %s,  解析度: %d×%d,  Channel: %s,  LCM size: %2.1f inch", \
            m_pCA210->isOnline() ? "連線" : "離線" , m_itor->GetDescrip(), GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), m_pCA210->GetChData(), m_pCA210->GetLcmSize());//LCM Size這樣抓會有問題
        TextOut(dc, GetSystemMetrics(SM_CXSCREEN) - (int)(temp.GetLength()*6.7), GetSystemMetrics(SM_CYSCREEN) - wordHight*1, temp, temp.GetLength());
    }

    //主要量測指示
    m_Goal.Draw(dc);//量測目標

    if (c_bMsrEnd && c_bRunMsrAI && c_bMsrEndnMsred)
    {
        temp.Format("按ESC離開。");    
        dc.SetTextColor(m_BkColor.Invrt());
        if ((m_Goal.GetCenter().x == GetSystemMetrics(SM_CXSCREEN)/2) && (m_Goal.GetCenter().y == GetSystemMetrics(SM_CYSCREEN)/2))
            TextOut(dc, GetSystemMetrics(SM_CXSCREEN)/2 - 75, GetSystemMetrics(SM_CYSCREEN)/2-8-m_Goal.GetRadius()*2, temp, temp.GetLength());
        else
            TextOut(dc, GetSystemMetrics(SM_CXSCREEN)/2 - 75, GetSystemMetrics(SM_CYSCREEN)/2-8, temp, temp.GetLength());
    }

    if (c_bUnCntCA210)
        temp.Format("未連接CA-210。");
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
    m_Goal.SetWnd(GetActiveWindow()); //GetActiveWindow()需等建構式完成才可以抓取
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
	checkMsrLimit();
}

void CPatternDlg::trigger()
{
    m_itor->m_pBackGorund->NT_SetWnd(GetActiveWindow());
    m_itor->m_pBackGorund->NT_SetCa(m_pCA210);

    //目前這一點是不是5nits的中心點？2=是
    setBkColor(m_itor->GetBkColor());

    m_Goal.SetData(m_itor->GetBullet());
    m_Goal.SetPrcntColor(m_BkColor.Shift());

    m_Goal.SetCenter(m_itor->GetPointPosi());  //靶位置
    m_Goal.SetPercent(0);

    m_Goal.Animation();
}

void CPatternDlg::checkMsrLimit()
{
    c_bMsrBegin     = (  m_itor   == m_RNA.Begin()) ? TRUE : FALSE;
    c_bMsrEnd       = (  m_itor+1 == m_RNA.End()  ) ? TRUE : FALSE;
    c_bMsrEndnMsred = (  c_bMsrEnd && !m_itor->GetBullet().IsEmpty() ) ? TRUE : FALSE;//若現在是最後一點，並且最後一點已經量了
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

const CaState CPatternDlg::recoil()
{
    //暫存目前的螢幕顯示/隱藏狀態
    BOOL OldDrawGold  = m_Goal.isVisible();
    BOOL OldStatusBar = c_bStatusBar;

    //固定關掉所有螢幕顯示/隱藏狀態
    c_bStatusBar = FALSE;
    m_Goal.Visible(FALSE);

    Invalidate();
    UpdateWindow();

    Sleep(70);

    const CaState camsrResult(m_pCA210->Measure());

    m_itor->SetBullet(m_pCA210->GetMsrData());
	m_Goal.SetData(m_itor->GetBullet());

    //恢復目前的螢幕顯示/隱藏狀態
    m_Goal.Visible(OldDrawGold);
    c_bStatusBar    = OldStatusBar;

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
    if (m_pCA210->isOnline())
    {
        srand(time(NULL));
        switch( m_pCA210->MsrAI( (float)0.005 ) )
        //check isRemote, isZeroCal, isRightPosition, and
        //return a status to say is MsrAiValue in spec.
        {
            case MA_InDeviation://標準門檻值內：繼續量測+百分比
				msrKernel();
                break;
            case MA_OutDeviation://標準門檻值外：繼續量測-百分比
                m_Goal.SetPercent(m_Goal.GetPercent() - rand()%25+rand()%25+1);
                 //m_Percent -= rand()%25+rand()%25+1;
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
		if ((eventCatchMsrValue() == 1) //最複雜的步驟
			|| (c_bMsrEndnMsred == FALSE))
			eventRunMsrAi(TRUE);
    }
    else
        ASSERT(0);
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
    }
	checkMsrLimit();
	m_Goal.ShowLabel(TRUE);

}

BOOL CPatternDlg::eventGoNextGoal()
{
    //下一個點
    if (!c_bMsrEnd)
    {
        //計算下一顆
        ++m_itor;
        if (m_itor == m_RNA.End()) m_itor--;
        if (m_itor == m_RNA.End()) m_itor--;

        //重新畫圈圈+動畫
        trigger();
        Invalidate();
    }
	checkMsrLimit();
	m_Goal.ShowLabel(c_bMsrEndnMsred);

    return !c_bMsrEnd;
}

UINT CPatternDlg::eventCatchMsrValue()
{
    //抓值抓抓抓!!!!
    //最後一點的話就停止自動
    //不然就是下一點
    m_Goal.ShowLabel(FALSE);
    if (m_itor->GetBkStatus() == BGS_NitsNeg || m_itor->GetBkStatus() == BGS_NitsPos)
        m_itor->m_pBackGorund->NT_colorReviseByNits(m_BkColor);
    /*
    recoil() 
    0 沒連線
    1 連線
    2 尚未Zero Cal
    3 檔位不在MEAS
    4 量測正常 當作1
    最後一點  5
    */
    switch(recoil())
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
