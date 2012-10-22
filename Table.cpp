// Table.cpp: implementation of the CTable class.
//
//////////////////////////////////////////////////////////////////////

#include"stdafx.h"
#include "ColorEyeI.h"
#include "Table.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTable::CTable(CDC* pDC, CPoint& pt):p_DC(pDC),
m_CellSpace(2, 2), //m_CellPitch(2, 2),
m_ptCur(pt), m_ptOrig(pt), m_ptEnd(pt), m_ptNextXY(pt),
m_xCnt(1), m_yCnt(1),
//m_tdPlus(FALSE), m_trPlus(FALSE),
m_clrText(RGB(0, 0, 0)), m_clrBackGround(RGB(255, 255, 255)),
m_gBoard(1), m_fBoard(1),
m_gbColor(RGB(0,0,0)), m_fbColor(RGB(0,0,0))
{
    m_SpanTable.clear();
//     m_vCellHeight.clear();
//     m_vCellWidth.clear();

    //Create Font
    m_defFont.CreateFont(16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, FF_MODERN, "Verdana");
    m_defFont.GetLogFont(&m_lft);
    m_curFont.CreateFontIndirect(&m_lft);
    p_OldFont = p_DC->SelectObject(&m_curFont);

    //�R���r���]���ʵ{���L�k����^
    m_curFont.DeleteObject();
    m_defFont.DeleteObject();

    p_DC->SetBkMode(OPAQUE);

//     CString strTemp;
//     strTemp.Format("R:%d\nG:%d\nB:%d", GetRValue(m_gbColor), GetGValue(m_gbColor), GetBValue(m_gbColor));
//     AfxMessageBox(strTemp);
}

CTable::~CTable()
{
//      p_DC->SelectObject(&p_OldFont);
//      p_DC->SelectObject(&p_OldPen);

    //�R����
    m_GridPen.DeleteObject();
    m_FramPen.DeleteObject();

    m_SpanTable.clear();
//     m_vCellHeight.clear();
//     m_vCellWidth.clear();
}

CTable& CTable::SetTableBoard(UINT tableboard, COLORREF tbclr)
{
    m_fBoard = tableboard;
    m_fbColor = tbclr;
    return *this;
}

CTable& CTable::SetGridBoard(UINT gridboard, COLORREF gbclr)
{
    m_gBoard = gridboard;
    m_gbColor = gbclr;
    return *this;
}

CTable& CTable::SetCellSpace(UINT sp)
{
    m_CellSpace.cx = sp;
    m_CellSpace.cy = sp;

    return *this;
}

CTable& CTable::SetFont(CFont& ft)
{
    ft.GetLogFont(&m_lft);
    m_defFont.CreateFontIndirect(&m_lft);
    p_DC->SelectObject(&m_defFont);
    m_defFont.DeleteObject();

    return *this;
}

CTable& CTable::b()
{
    p_DC->SelectObject(p_OldFont);

    m_lft.lfWeight = FW_BOLD;

    m_curFont.CreateFontIndirect(&m_lft);
    p_OldFont = p_DC->SelectObject(&m_curFont);
    m_curFont.DeleteObject();

    return *this;
}

CTable& CTable::b_()
{
    p_DC->SelectObject(p_OldFont);

    m_lft.lfWeight = FW_MEDIUM;

    m_curFont.CreateFontIndirect(&m_lft);
    p_OldFont = p_DC->SelectObject(&m_curFont);
    m_curFont.DeleteObject();

    return *this;
}

CTable& CTable::i()
{
    p_DC->SelectObject(p_OldFont);
    
    m_lft.lfItalic = TRUE;
    
    m_curFont.CreateFontIndirect(&m_lft);
    p_OldFont = p_DC->SelectObject(&m_curFont);
    m_curFont.DeleteObject();
    
    return *this;
}

CTable& CTable::i_()
{
    p_DC->SelectObject(p_OldFont);
    
    m_lft.lfItalic = FALSE;
    
    m_curFont.CreateFontIndirect(&m_lft);
    p_OldFont = p_DC->SelectObject(&m_curFont);
    m_curFont.DeleteObject();
    
    return *this;
}

CTable& CTable::u()
{
    p_DC->SelectObject(p_OldFont);
    
    m_lft.lfUnderline = TRUE;
    
    m_curFont.CreateFontIndirect(&m_lft);
    p_OldFont = p_DC->SelectObject(&m_curFont);
    m_curFont.DeleteObject();
    
    return *this;
}

CTable& CTable::u_()
{
    p_DC->SelectObject(p_OldFont);
    
    m_lft.lfUnderline = FALSE;
    
    m_curFont.CreateFontIndirect(&m_lft);
    p_OldFont = p_DC->SelectObject(&m_curFont);
    m_curFont.DeleteObject();
    
    return *this;
}

CTable& CTable::s()
{
    p_DC->SelectObject(p_OldFont);
    
    m_lft.lfStrikeOut = TRUE;
    
    m_curFont.CreateFontIndirect(&m_lft);
    p_OldFont = p_DC->SelectObject(&m_curFont);
    m_curFont.DeleteObject();
    
    return *this;
}

CTable& CTable::s_()
{
    p_DC->SelectObject(p_OldFont);
    
    m_lft.lfStrikeOut = FALSE;
    
    m_curFont.CreateFontIndirect(&m_lft);
    p_OldFont = p_DC->SelectObject(&m_curFont);
    m_curFont.DeleteObject();
    
    return *this;
}

CTable& CTable::tr()//���U�@��
{
    return *this;
}


CTable& CTable::tr_()//���U�@��
{
//    CString strTemp;

    //�[�WCellspace�M��u�p��
//    if (m_xCnt != 0 && m_yCnt != 0)
        m_ptCur.y = m_ptNextXY.y;
    m_yCnt = (m_yCnt < m_yCnt_Max) ? m_yCnt + 1 : 1 ;

    //�]�wEnd�I
    m_ptEnd.x = m_ptCur.x;
    m_ptEnd.y = m_ptCur.y;

    m_ptCur.x = m_ptOrig.x;//���U�@��A�y��x�]�����^�n�^����I
    m_xCnt = 1;
    return *this;
}

CTable& CTable::td(UINT Hspan, UINT Vspan)//���k�@��
{
//    CString strTemp;
    //�����]�w�x�s��w���I

    //�`�NSpanTable�MPointTable���y�Ц첾�~�t
    //�HSpanTable���D���ܡAPointTable���y�г��n-1�~�|�k�X
    m_PointTable[(m_xCnt-1) + (m_yCnt-1) * (m_xCnt_Max-1)] = m_ptCur;
//    p_DC->SetPixel(m_ptCur, RGB(255, 0, 0));

//     strTemp.Format("%d, %d", m_xCnt, m_yCnt);
//     AfxMessageBox(strTemp);

    //defFont�McurFont���S���r���F
    //�ҥH�A���i�HGetLogFont
    m_curFont.CreateFontIndirect(&m_lft);
    p_OldFont = p_DC->SelectObject(&m_curFont);
    m_curFont.DeleteObject();
    
    //�]�w�r���C��
    m_oldclr = p_DC->SetTextColor(m_clrText);

    //�]�w����l
    if (Hspan != 1 || Vspan != 1)//�w�]�N�O1, 1
    {
//        strTemp.Format("");
        for (int ii = m_xCnt; ii < (int)(Hspan + m_xCnt); ++ii)
        for (int ij = m_yCnt; ij < (int)(Vspan + m_yCnt); ++ij)
        {
//             �YSpanTble��l�̬�1�A�N�O����X���x�s�檺�x�s��
//             �ҥH�A���ᤣ�e�ؽu
            m_SpanTable[ii + ij*m_xCnt_Max] = 1;

//             strTemp.Format("<td>\nm_xCnt=%d, Hspan=%d/%d, ii=%d\nm_yCnt=%d, Vspan=%d/%d, ij=%d\nm_SpanTable[%d]=%d"\
//                 , m_xCnt, Hspan, Hspan + m_xCnt, ii\
//                 , m_yCnt, Vspan, Vspan + m_yCnt, ij\
//                 , ii + ij*Vspan, m_SpanTable[ii + ij*Vspan]);    
//             ViewSpanTableValue(strTemp);
//            ViewSpanTableValue();
        }
        
    }

    m_ptNextXY.x = nextX(Hspan);
    m_ptNextXY.y = nextY(Vspan);
        //m_PointTable[m_xCnt].x + m_SpanTable[(m_xCnt-1)] + m_CellSpace.cx*2;
//       strTemp.Format("m_ptNextXY.y = %d, m_ptCur.y = %d\n"\
//          , m_ptNextXY.y, m_ptCur.y);
//       AfxMessageBox(strTemp);
//    AfxMessageBox("thisx");
   return *this;
}

CTable& CTable::td(COLORREF BkClr, UINT Hspan, UINT Vspan)
{
    td(Hspan, Vspan);
//    int GrayClr = 223; ���ϥΪ��ϰ��ܼ�
    DrawRect(BkClr);
    return *this;
 }

CTable& CTable::td(COLORREF bkclr)
{
    td();
    DrawRect(bkclr);

    return *this;
}

CTable& CTable::td(CFont fnt, UINT Hspan, UINT Vspan)//���k�@��
{
    fnt.GetLogFont(&m_lft);    
    return td(Hspan, Vspan);
}

CTable& CTable::td_()//���k�@��
{
    p_DC->SelectObject(p_OldFont);
    p_DC->SetTextColor(m_oldclr);
    //�]�w����l�A��l����1�A�h����l
    //��xCnt���ʡA�p�ƨ�U�@�ӭn�s��y�Ъ��O����Ŷ��C
//    CString strTemp;

//     strTemp.Format(_T("SetCellNum(%d/%d, %d/%d), VAlue=%d\n"), m_xCnt, m_xCnt_Max, m_yCnt, m_yCnt_Max, \
//         m_SpanTable[(m_xCnt%m_xCnt_Max)]);
//     ViewSpanTableValue(strTemp);
    m_ptCur.x = m_ptNextXY.x;
    do 
    {
        ++m_xCnt;

        //strTemp.Format("%d", m_SpanTable[m_xCnt + m_yCnt * m_xCnt_Max]);
//         strTemp.Format("%d/%d", m_xCnt + m_yCnt * m_xCnt_Max, m_xCnt_Max*m_yCnt_Max);
//         AfxMessageBox(strTemp);

        //�̫�@�Ӥ��nŪ��while�̪�m_SpanTable[m_xCnt + m_yCnt * m_xCnt_Max]
        //���Ы��V�����D���̪��a��A�|���C
        if (m_xCnt + m_yCnt * m_xCnt_Max == m_xCnt_Max*m_yCnt_Max)
            break;
    } while (m_SpanTable[(m_xCnt + m_yCnt * m_xCnt_Max)]);

    return *this;
}

UINT CTable::nextX(UINT SpanNum)
{
    UINT nX = m_ptCur.x;
    UINT tXCnt = m_xCnt;
    for (int i = 0; i < (int)SpanNum; ++i)
    {
        if (m_xCnt != 0 && m_yCnt != 0)
            nX = nX + m_SpanTable[(tXCnt%m_xCnt_Max)] + m_CellSpace.cx*2; //���e�סA�]�w�y��
        tXCnt = (tXCnt < m_xCnt_Max) ? tXCnt + 1 : 1 ;
    }
    return nX;
}

UINT CTable::nextY(UINT SpanNum)
{
    UINT nY = m_ptCur.y;
    UINT tYCnt = m_yCnt;

    //�ץ�Cell���ס]�ŦX�r���^
    int TextHight(m_SpanTable[(m_yCnt%m_yCnt_Max)*m_xCnt_Max]); //�����סA�]�w�y��

    //    strTemp.Format("m_yCnt m_yCnt_Max\n%d, %d = %d", m_yCnt, m_yCnt_Max, m_yCnt%m_yCnt_Max*m_xCnt_Max);
    //    AfxMessageBox(strTemp);
    
    TextHight = (TextHight < m_lft.lfHeight) ? m_lft.lfHeight : TextHight;
    m_SpanTable[(m_yCnt%m_yCnt_Max)*m_xCnt_Max] = TextHight;

    
    for (int i = 0; i < (int)SpanNum; ++i)
    {
        if (m_xCnt != 0 && m_yCnt != 0)
            nY = nY + TextHight + m_CellSpace.cy*2; //���e�סA�]�w�y��
        tYCnt = (tYCnt < m_yCnt_Max) ? tYCnt + 1 : 1 ;
    }
    return nY;
}

CTable& CTable::text(CString str, UINT nFlags)
{
    UINT X, Y;
    switch (nFlags)
    {
        case TA_CENTER:
            //�a�����r�A�w���I=(����u+�d��+��e+�d��)/2
            //�]�N�O���A�w���I=����u��k��u������
            X = (m_ptCur.x + m_ptNextXY.x)/2 + m_CellSpace.cx;
            Y = (m_ptCur.y + m_ptNextXY.y)/2 - m_lft.lfHeight + m_CellSpace.cy;
            //p_DC->TextOut ((m_ptCur.x + m_ptNextXY.x)/2 + m_CellSpace.cx, (m_ptCur.y + m_ptNextXY.y)/2 + m_CellSpace.cy, \
            //    str.GetBuffer(0), str.GetLength());
            break;
        case TA_RIGHT:
            //�a�k���r�A�w���I=����u+�d��+��l�e
            //�]�N�O���A�w���I=�k��u-�d��
            X = m_ptNextXY.x - m_CellSpace.cx;
            //p_DC->TextOut (m_ptNextXY.x - m_CellSpace.cx, m_ptNextXY.y - m_CellSpace.cy, \
            //    str.GetBuffer(0), str.GetLength());
            break;
        default:
        case TA_LEFT:
            X = m_ptCur.x + m_CellSpace.cx;
            //p_DC->TextOut (m_ptCur.x + m_CellSpace.cx, m_ptCur.y + m_CellSpace.cy, str.GetBuffer(0), str.GetLength());
            break;
    }
    
    switch (nFlags)
    {
        case TA_BOTTOM:
            //�a�k���r�A�w���I=����u+�d��+��l�e
            //�]�N�O���A�w���I=�k��u-�d��
            Y = m_ptNextXY.y - m_CellSpace.cy;
            //p_DC->TextOut (m_ptNextXY.x - m_CellSpace.cx, m_ptNextXY.y - m_CellSpace.cy, \
            //    str.GetBuffer(0), str.GetLength());
            break;
        default:
        case TA_TOP:
            Y = m_ptCur.y + m_CellSpace.cy;
            //p_DC->TextOut (m_ptCur.x + m_CellSpace.cx, m_ptCur.y + m_CellSpace.cy, str.GetBuffer(0), str.GetLength());
            break;
    }
    p_DC->SetTextAlign(nFlags);
    p_DC->TextOut (X, Y, str.GetBuffer(0), str.GetLength());
    return *this;
}

CTable& CTable::text(CString str, CFont& ft, UINT nFlags)
{
    //�D�n�]�w�r��
    p_OldFont = p_DC->SelectObject(&ft);
    ft.DeleteObject();
    text(str, nFlags);
    p_DC->SelectObject(p_OldFont);
    return *this;
}

CTable& CTable::text(CString str, CFont& ft, COLORREF clr, UINT nFlags)
{
    //�D�n�]�wcolor
    m_clrText = clr;
    m_oldclr = p_DC->SetTextColor(m_clrText);
    text(str, ft, nFlags);
    p_DC->SetTextColor(m_oldclr);
    return *this;
}

CTable& CTable::Hight(std::vector<UINT>::size_type n, UINT h) //SetHight(�ĴX��Cell, �h���^
{
    m_SpanTable[m_xCnt_Max*(n+1)] = h;
    return *this;
}

CTable& CTable::Width(std::vector<UINT>::size_type n, UINT w) //SetWidth(�ĴX��Cell, �h�e�^
{
//    ViewSpanTableValue();
    m_SpanTable[n+1] = w;
    return *this;
}

CTable& CTable::SetCellNum(UINT x, UINT y)//(11, 7)
{
    //�]�w�x�s��w���I����Ӫ�
    //��l�ȥH�C�Ӫ�檺���I����
    //�����x�sCurrPoint�N�i�H�F
    m_xCnt_Max = x;
    m_yCnt_Max = y;
    
    UINT xit;
    UINT yit;

    for (yit = 0; yit < m_yCnt_Max; ++yit) // 8
    for (xit = 0; xit < m_xCnt_Max; ++xit) // 12
        m_PointTable.push_back(m_ptOrig);

    //�]�w��歭�w��
    //���]�w�n�r�����P�e�A�~�i�H�]�w�o��
    m_xCnt_Max = x+1;
    m_yCnt_Max = y+1;
    
    UINT initValue = 0;

    for (yit = 0; yit < m_yCnt_Max; ++yit) // 8
    for (xit = 0; xit < m_xCnt_Max; ++xit) // 12
    {
        if (xit == 0 && yit == 0)
            m_SpanTable.push_back(initValue);
        else if (xit == 0)//��e
            m_SpanTable.push_back(16);
        else if (yit == 0)//�C��
            m_SpanTable.push_back(1);
        else//���e
             m_SpanTable.push_back(initValue);
    }

//     CString strTemp;
//     strTemp.Format("SetCellNum(%d, %d)", m_xCnt_Max, m_yCnt_Max);
//     ViewSpanTableValue(strTemp);

    return *this;
}

CPoint CTable::GetCellNum()
{
    CPoint pt((int)m_xCnt_Max, (int)m_yCnt_Max);
    return pt;
}

CPoint CTable::table_(std::vector<CPoint>& tbPt)
{
    //tbPt.clear();
    tbPt.clear();
    tbPt.push_back(m_ptOrig);
    for (std::vector<CPoint>::iterator it = m_PointTable.begin(); it != m_PointTable.end(); ++it)
        tbPt.push_back(*it - m_ptOrig);//�۹���楪�W������m
    tbPt.push_back(m_ptEnd);

    return table_();
}

CPoint CTable::table_()
{
//    ViewSpanTableValue("</table>");
//    ViewTableTableValue("</table>");

    //�]�w����u
    m_GridPen.CreatePen((m_gBoard == 0)?PS_NULL:PS_SOLID, m_gBoard, m_gbColor);
    p_OldPen = p_DC->SelectObject(&m_GridPen);
    
    DrawGridBoard();
    p_DC->SelectObject(p_OldPen);

    //�]�w�~�ؽu
    m_FramPen.CreatePen((m_fBoard == 0)?PS_NULL:PS_SOLID, m_fBoard, m_fbColor);
    p_OldPen = p_DC->SelectObject(&m_FramPen);
    
    DrawFrameBoard();
    p_DC->SelectObject(p_OldPen);

    //����
    m_SpanTable.clear();
    m_PointTable.clear();

    return m_ptCur;
}

void CTable::ViewSpanTableValue(const CString title)
{
    //all of table value
    CString strTemp, temp;

	LPCTSTR lpctstr;
	if (title.IsEmpty())
		lpctstr = _T("SetCellNum(%d/%d, %d/%d)"), m_xCnt, m_xCnt_Max, m_yCnt, m_yCnt_Max;
	else
		lpctstr = _T("%s"), title;

		strTemp.Format(lpctstr);

    strTemp += _T("\n");

    for (std::vector<UINT>::iterator it = m_SpanTable.begin(); it != m_SpanTable.end(); ++it)
    {
        temp.Format(_T("%6d"), *it);
        strTemp += (((it - m_SpanTable.begin())%m_xCnt_Max )+1 == m_xCnt_Max) ? temp + _T("\n") : temp + _T("");
    }

    temp.Format(_T("StartPoint(%d, %d)\nCurrentPoint(%d, %d)\nEndPoint(%d, %d)"), m_ptOrig.x, m_ptOrig.y, m_ptCur.x, m_ptCur.y, m_ptEnd.x, m_ptEnd.y);
    strTemp += temp;
    if (!strTemp.IsEmpty()) 
        AfxMessageBox(strTemp);
}

void CTable::ViewTableTableValue(const CString title)
{
    //all of table value
    CString strTemp, temp;
    
	LPCTSTR lpctstr;
	if (title.IsEmpty())
		lpctstr = _T("SetCellNum(%d/%d, %d/%d)"), m_xCnt -1, m_xCnt_Max -1, m_yCnt -1, m_yCnt_Max -1;
	else
		lpctstr = _T("%s"), title;
    strTemp.Format(lpctstr);
    strTemp += _T("\n");
    
    for (std::vector<CPoint>::iterator it = m_PointTable.begin(); it != m_PointTable.end(); ++it)
    {
        temp.Format(_T("%6d, "), it->y);
        strTemp += (((it - m_PointTable.begin())%(m_xCnt_Max -1) )+1 == (m_xCnt_Max -1)) ? temp + _T("\n") : temp + _T("");
    }
    
    temp.Format(_T("\nStartPoint(%d, %d)\nCurrentPoint(%d, %d)\nEndPoint(%d, %d)"), m_ptOrig.x, m_ptOrig.y, m_ptCur.x, m_ptCur.y, m_ptEnd.x, m_ptEnd.y);
    strTemp += temp;
    if (!strTemp.IsEmpty()) 
        AfxMessageBox(strTemp);
}

void CTable::DrawGridBoard()
{
//    CString strTemp;
    CPoint ptStart(m_ptOrig);
    CPoint ptEnd  (m_ptOrig.x, m_ptEnd.y);
    
    //�e�����u
    CRect* tRect;
    CPoint tCurrPoint(m_ptOrig);
    CSize* tCellSize;
    UINT CurrHCnt, CurrVCnt;

    for (std::vector<UINT>::iterator it = m_SpanTable.begin(); it != m_SpanTable.end(); ++it)
    {
        //�p��xy�]���j��^
        CurrHCnt = (it - m_SpanTable.begin())%m_xCnt_Max;//�����p��
        CurrVCnt = (it - m_SpanTable.begin())/m_xCnt_Max;//�����p��

        //�u���X���椺�e��
        if (CurrHCnt != 0 && CurrVCnt != 0)
        {
            /*
            �bm_SpenTable���A��U�O����e�M�C�����Ʀr
            �]����u���|���|�A�|�a�b�@�_�A�ҥH��u�|�ܲ�
            �ҥH�A�~�btCellSize = new CSize...�V�k�V�U���@��pixel

            ���Ჾ�ʩw���ItCurrPoint�ɡA�n���ץ�
            �ҥHcx�Mcy�n-1

            */
            //�]�w��l�j�p�Φ�l
            tCellSize = new CSize(\
                m_SpanTable[CurrHCnt]            + m_CellSpace.cx*2 + 1, \
                m_SpanTable[CurrVCnt*m_xCnt_Max] + m_CellSpace.cy*2 + 1);

            //�^���C�@��Cell�����I
            tCurrPoint.x = m_PointTable[ CurrHCnt -1].x;
            tCurrPoint.y = m_PointTable[(CurrVCnt -1) *(m_xCnt_Max -1)].y;

            //�e��l
            tRect = new CRect(tCurrPoint, *tCellSize);

            m_BkArea.CreateStockObject(NULL_BRUSH);
            p_OldBrush = p_DC->SelectObject(&m_BkArea);
            m_BkArea.DeleteObject();
            
            if (!*it)    p_DC->Rectangle(tRect);//�e��l
            
            p_DC->SelectObject(p_OldBrush);
            delete tRect;

//            strTemp.Format("H:%d, V:%d\n", tCellSize->cx -1, tCellSize->cy -1);
//            ViewSpanTableValue(strTemp);

            delete tCellSize;
        }
    }
}

void CTable::DrawFrameBoard()
{
    CSize shiftSize(1, 1);
    CRect tRect(m_ptOrig, m_ptEnd + shiftSize);

    m_BkArea.CreateStockObject(NULL_BRUSH);
    p_OldBrush = p_DC->SelectObject(&m_BkArea);
    m_BkArea.DeleteObject();

    p_DC->Rectangle(&tRect);

    p_DC->SelectObject(p_OldBrush);
}

void CTable::DrawRect(COLORREF bkclr)
{
    //�e��l    
    CSize shiftSize(1, 1);
    CRect* tRect = new CRect(m_ptCur, m_ptNextXY + shiftSize);
    CBrush* tbrush = new CBrush(bkclr);
    p_OldBrush = p_DC->SelectObject(tbrush);
    
    p_DC->Rectangle(tRect);//�e��l
    
    //�R����
    tbrush->DeleteObject();
    p_DC->SelectObject(p_OldBrush);    
    
    delete tbrush;
    delete tRect;
}


