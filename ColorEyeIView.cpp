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

	CFont afont;
    afont.CreateFont(TextHight, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, FF_MODERN, "Century Gothic");
    pDC->SelectObject(&afont);

    CSize szAroundSpace(2, 2);  //視窗的留白
    CPoint ptOrig(0, 0);        //視窗的原點（左上角）
    CPoint ptFix (0, 0);


    ptOrig = ptOrig + szAroundSpace;
    ptFix.x = ptFix.x + szAroundSpace.cx;
    ptFix.y = ptFix.y + szAroundSpace.cy;

    //表格的部份
    //設計一個table class用類似HTML的語法來管理表格
    //視窗左半邊，導覽區
    ptFix = GetDeviceScrollPosition();
    CPoint ptTemp = ptFix;

	int line(0);//18*7
// 	pDC->TextOut(ptTemp.x, ptTemp.y, "Panel ID");            pDC->TextOut(ptTemp.x+(TextHight*9), ptTemp.y, pDoc->GetPnlID()  );    line++;	ptTemp.y =  TextHight*(line);	
// 	pDC->TextOut(ptTemp.x, ptTemp.y, "Measurement device");  pDC->TextOut(ptTemp.x+(TextHight*9), ptTemp.y, pDoc->GetMsrDvc() );    line++;	ptTemp.y =  TextHight*(line);	
// 	pDC->TextOut(ptTemp.x, ptTemp.y, "Probe");               pDC->TextOut(ptTemp.x+(TextHight*9), ptTemp.y, pDoc->GetPrb()    );    line++;	ptTemp.y =  TextHight*(line);	
// 	pDC->TextOut(ptTemp.x, ptTemp.y, "Channel");             pDC->TextOut(ptTemp.x+(TextHight*9), ptTemp.y, pDoc->GetCHID()   );    line++;	ptTemp.y =  TextHight*(line);	
// 	pDC->TextOut(ptTemp.x, ptTemp.y, "Inch");                pDC->TextOut(ptTemp.x+(TextHight*9), ptTemp.y, pDoc->GetInch()   );    line++;	ptTemp.y =  TextHight*(line);	

	pDC->TextOut(ptTemp.x, ptTemp.y, "Panel ID");            pDC->TextOut(ptTemp.x+(TextHight*9), ptTemp.y, pDoc->GetFileHead().oPnlID()  );    line++;	ptTemp.y =  TextHight*(line);	
	pDC->TextOut(ptTemp.x, ptTemp.y, "Measurement device");  pDC->TextOut(ptTemp.x+(TextHight*9), ptTemp.y, pDoc->GetFileHead().oMsrDvc() );    line++;	ptTemp.y =  TextHight*(line);	
	pDC->TextOut(ptTemp.x, ptTemp.y, "Probe");               pDC->TextOut(ptTemp.x+(TextHight*9), ptTemp.y, pDoc->GetFileHead().oPrb()    );    line++;	ptTemp.y =  TextHight*(line);	
	pDC->TextOut(ptTemp.x, ptTemp.y, "Channel");             pDC->TextOut(ptTemp.x+(TextHight*9), ptTemp.y, pDoc->GetFileHead().oCHID()   );    line++;	ptTemp.y =  TextHight*(line);	
	pDC->TextOut(ptTemp.x, ptTemp.y, "Inch");                pDC->TextOut(ptTemp.x+(TextHight*9), ptTemp.y, pDoc->GetFileHead().oInch()   );    line++;	ptTemp.y =  TextHight*(line);	

    //自訂字型

    CString str;

    int maxXview(0), 
        maxYview(0);

    DNA showDNA(pDoc->GetDocDNA());
	if (!showDNA.Size())
	{
        str.Format("（空的DNA）");
        pDC->TextOut(ptTemp.x, ptTemp.y, str.GetBuffer(0));
	}
	else
	{
		for ( std::vector<Nucleotide>::iterator indexItor = showDNA.Begin(); indexItor != showDNA.End(); ++indexItor)
		{
			str.Format("%s", indexItor->ShowMe());
			pDC->TextOut(ptTemp.x, ptTemp.y, str.GetBuffer(0));

			//set position point
			line++;
			ptTemp.y = TextHight*(line);

			//set max X veiw
			if (maxXview < str.GetLength()*5.5)
				maxXview = (int)((float)str.GetLength()*5.5); //介於5~6之間

			//set max Y view
			maxYview = ptTemp.y;
		}
	}



    //視窗右半邊（主要資料檢視區）
    int maxX_LeftView(maxXview);
    ptTemp.x = 291;
    ptTemp.y = ptOrig.y;
    line = 0;
    RNA showRNA(pDoc->GetDocRNA());
	if (showRNA.IsEmpty())
	{
		str.Format("（空的RNA）");
		pDC->TextOut(ptTemp.x, ptTemp.y, str.GetBuffer(0));
	}
	else
	{
		for ( std::vector<Cartridge2>::iterator dataItor = showRNA.Begin(); dataItor != showRNA.End(); ++dataItor)
		{
			str.Format("%s %s", dataItor->GetDescrip(), dataItor->GetBullet().ShowDataReport());
			pDC->TextOut(ptTemp.x, ptTemp.y, str.GetBuffer(0));
			maxYview = ptTemp.y;
			if (maxXview < str.GetLength()*5.5)
				maxXview = (int)((float)str.GetLength()*5.5); //介於5~6之間

			ptTemp.y =  TextHight*(line);
			line++;
		}
	}
    maxXview += maxX_LeftView;

   
    pDC->RestoreDC( nDC );

    //設定高度
    CSize sizeTotal;
    // TODO: calculate the total size of this view
    sizeTotal.cx = maxXview;
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
#endif

/////////////////////////////////////////////////////////////////////////////
// CColorEyeIView message handlers

void CColorEyeIView::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
    // TODO: Add your message handler code here and/or call default
//    keepSc();
    CScrollView::OnVScroll(nSBCode, nPos, pScrollBar);
}

BOOL CColorEyeIView::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) 
{
    // TODO: Add your message handler code here and/or call default
//    keepSc();
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
