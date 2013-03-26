// ColorEyeIView.cpp : implementation of the CColorEyeIView class
//

#include "stdafx.h"
#include "ColorEyeI.h"

#include "ColorEyeIDoc.h"
#include "ColorEyeIView.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CColorEyeIView

IMPLEMENT_DYNCREATE(CColorEyeIView, CScrollView)

BEGIN_MESSAGE_MAP(CColorEyeIView, CScrollView)
    //{{AFX_MSG_MAP(CColorEyeIView)
    ON_WM_VSCROLL()
    ON_WM_MOUSEWHEEL()
    ON_WM_LBUTTONUP()
    ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CColorEyeIView construction/destruction

CColorEyeIView::CColorEyeIView(){}
CColorEyeIView::~CColorEyeIView(){}

BOOL CColorEyeIView::PreCreateWindow(CREATESTRUCT& cs)
{
    // TODO: Modify the Window class or styles here by modifying
    //  the CREATESTRUCT cs

    return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CColorEyeIView drawing

void CColorEyeIView::OnDraw(CDC* pDC)
{
    CColorEyeIDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    // TODO: add draw code for native data here

    int nDC = pDC->SaveDC();
    const UINT TextHight(16);

    CSize szAroundSpace(2, 2);  //�������d��
    CPoint ptOrig(0, 0);        //���������I�]���W���^
    CPoint ptFix (0, 0);


    ptOrig = ptOrig + szAroundSpace;
    ptFix.x = ptFix.x + szAroundSpace.cx;
    ptFix.y = ptFix.y + szAroundSpace.cy;

    //��檺����
    //�]�p�@��table class������HTML���y�k�Ӻ޲z���
    //�������b��A������
    ptFix = GetDeviceScrollPosition();
    CPoint ptTemp = ptFix;

//     CTable tbInfo(pDC, ptTemp);
//     ptTemp = tbInfo.SetCellNum(2, 4).SetTableBoard(0).SetGridBoard(0)/*.SetFont(afont)*/.SetCellSpace(1)
//      .Width(0, TextHight*10).Width(1, TextHight*12).Hight(0, TextHight).Hight(1, TextHight).Hight(2, TextHight)
//              .tr().td().b().text("Panel ID").b_().td_()          .td().text(pDoc->GetPnlID()).td_().tr_()
//              .tr().td().b().text("Measurement device").b_().td_().td().text(pDoc->GetMsrDvc()).td_().tr_()
//              .tr().td().b().text("Probe").b_().td_()             .td().text(pDoc->GetPrb()).td_().tr_()
//              .tr().td().b().text("Channel").b_().td_()           .td().text(pDoc->GetCHID()).td_().tr_()
//         .table_();

    //�ۭq�r��
    CFont afont;
    afont.CreateFont(TextHight, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, FF_MODERN, "Century Gothic");
    pDC->SelectObject(&afont);

    int line(0);
    CString str;

    int maxXview(0), 
        maxYview(0);

    DNA showIndex(pDoc->GetDocDNA());

    for ( std::vector<Nucleotide>::iterator indexItor = showIndex.Begin(); indexItor != showIndex.End(); ++indexItor)
    {
        str.Format("%s", indexItor->showMe());
        ptTemp.y =  TextHight*(line);
        pDC->TextOut(ptTemp.x, ptTemp.y, str.GetBuffer(0));
        line++;
        maxYview = ptTemp.y;
        if (maxXview < str.GetLength()*5.5)
            maxXview = (int)((float)str.GetLength()*5.5); //����5~6����
    }

//  str.Format("%d, %d", maxXview, maxYview);
//  if (showIndex.Size())
//      AfxMessageBox(str);
    //�����k�b��]�D�n����˵��ϡ^
    int maxX_LeftView(maxXview);
    ptTemp.x = maxX_LeftView;
//  ptTemp.x = 0;
    ptTemp.y = ptOrig.y;
    line = 0;
    RNA showData(pDoc->GetDocRNA());
    for ( std::vector<Cartridge2>::iterator dataItor = showData.Begin(); dataItor != showData.End(); ++dataItor)
    {
        str.Format("%s %s", dataItor->GetDescrip(), dataItor->GetBullet().show());
        ptTemp.y =  TextHight*(line);
        pDC->TextOut(ptTemp.x, ptTemp.y, str.GetBuffer(0));
        line++;
        maxYview = ptTemp.y;
        if (maxXview < str.GetLength()*5.5)
            maxXview = (int)((float)str.GetLength()*5.5); //����5~6����
    }
    maxXview += maxX_LeftView;

//  str.Format("%d, %d", maxXview, maxYview);
//  AfxMessageBox(str);
    
    pDC->RestoreDC( nDC );

    //�]�w����
    CSize sizeTotal;
    // TODO: calculate the total size of this view
    sizeTotal.cx = maxXview;
//     sizeTotal.cy = (ptTemp.y > 291) ? ptTemp.y : 291; //291�O���䪺
    sizeTotal.cy = maxYview;
    SetScrollSizes(MM_TEXT, sizeTotal);
}

void CColorEyeIView::OnInitialUpdate()
{
    CScrollView::OnInitialUpdate();
    CSize sizeTotal;
    // TODO: calculate the total size of this view
    sizeTotal.cx = GetDeviceScrollPosition().x;
    sizeTotal.cy = GetDeviceScrollPosition().y;
    SetScrollSizes(MM_TEXT, sizeTotal);

}

/////////////////////////////////////////////////////////////////////////////
// CColorEyeIView diagnostics

#ifdef _DEBUG
void CColorEyeIView::AssertValid() const
{
    CScrollView::AssertValid();
}

void CColorEyeIView::Dump(CDumpContext& dc) const
{
    CScrollView::Dump(dc);
}

CColorEyeIDoc* CColorEyeIView::GetDocument() // non-debug version is inline
{
    ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CColorEyeIDoc)));
    return (CColorEyeIDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CColorEyeIView message handlers

void CColorEyeIView::KeepSc()
{
    CRect* pRcClient = new CRect;
//    GetClientRect(&rcClient);
    pRcClient->top    = 2;
    pRcClient->left   = 2;
    pRcClient->right  = 340;
    pRcClient->bottom = 285;
    InvalidateRect(pRcClient);
    delete pRcClient;
}

void CColorEyeIView::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
    // TODO: Add your message handler code here and/or call default
//    KeepSc();
    CScrollView::OnVScroll(nSBCode, nPos, pScrollBar);
}

BOOL CColorEyeIView::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) 
{
    // TODO: Add your message handler code here and/or call default
//    KeepSc();
    return CScrollView::OnMouseWheel(nFlags, zDelta, pt);
}

BOOL CColorEyeIView::PreTranslateMessage(MSG* pMsg) 
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
// 		case VK_SPACE:   break;
// 		case VK_UP:      break;
// 		case VK_DOWN:    break;
// 		case VK_RIGHT:   break;
// 		case VK_LEFT:    break;
// 		case VK_RETURN:  break;
// 		case VK_ESCAPE:  break;
		case VK_F5:     pDoc->UpdateAllViews(NULL); break;
        }
        return TRUE;
    }
	return CScrollView::PreTranslateMessage(pMsg);
}
