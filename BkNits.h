#ifndef BKNITS_H
#define BKNITS_H

#include "BkMaker.h"

class BkNits : public BkMaker
{
	//m_pCA210
	//hWnd
public:
 	BkNits(const int&, const NitsType&);
    BkNits(const BkNits& bkN);

	void setWnd(CWnd* cWnd){ m_pdlgcWnd = cWnd; };
	void setCa(Ca210* pCa){ m_pCa210 = pCa; };
	void SetBkColor(const ColorRef&);
    void SetRect(const CRect& _rect, const ColorRef& clr){};
    void Draw(CPaintDC& dc){};

	ColorRef nits2color();
	ColorRef n2cPos();
	ColorRef n2cNeg();
};

inline BkNits::BkNits(const int& nits, const NitsType& nt)
{
	BkMaker::BkMaker();
	m_Nits = nits;
	m_Ntype = nt;
}

inline BkNits::BkNits(const BkNits& bkN)
{
	BkMaker::BkMaker();
	SetNitsType(NitsType bkN.m_Ntype);
	SetBkColor(bkN.m_BkColor);
}

inline ColorRef BkNits::nits2color()
{
	switch(m_Ntype)
	{
	case NT_Pos:
		return n2cPos();
		break;
	case NT_Neg:
	default:
		return n2cNeg();		
	}
}

inline ColorRef BkNits::n2cPos()
{
	ColorRef clr;
	return clr;
	int _gl= 60;//     int Graylevel = 55;
    float fLv = 0;
    while(fLv >  m_Nits)  //�Y�G���٨S����5�H�U�A�N���
    {
        _gl -= 2;
		m_BkColor.iGray(_gl);
		m_pdlgcWnd->Invalidate();
		m_pdlgcWnd->UpdateWindow();
        //�q�����
        if (m_pCa210->Measure() == CA_ZeroCalMode)
            MessageBox("�ɦ줣�bMEAS");
        fLv = m_pCa210->GetMsrData().oFlt(VluK_Lv);  //m_IProbe.GetLv();
    }

    while(fLv < m_Nits)   //�Y�G���٦b5�H�U�A�N...�ܫG
    {
        ++_gl;
		m_BkColor.iGray(_gl);
		m_pdlgcWnd->Invalidate();
		m_pdlgcWnd->UpdateWindow();
        Sleep(60);
//      �q�����
        m_pCa210->Measure();
        fLv = m_pCa210->GetMsrData().oFlt(VluK_Lv);  //m_IProbe.GetLv();
    }
}

inline ColorRef BkNits::n2cNeg()
{
    float fLv = 0;
	int _gl = 55;

    while(fLv < m_Nits)  //�Y�G���٨S����5�H�U�A�N���
    {
        _gl += 2;
		m_BkColor.iGray(_gl);
		m_pdlgcWnd->Invalidate();
		m_pdlgcWnd->UpdateWindow();
//        Sleep(0);
//        �q�����
        if (m_pCa210->Measure() == CA_ZeroCalMode)
            MessageBox("�ɦ줣�bMEAS");
        fLv = m_pCa210->GetMsrData().oFlt(VluK_Lv);  //m_IProbe.GetLv();
    }
    
    while(fLv > m_Nits)   //�Y�G���٦b5�H�U�A�N...�ܫG
    {
        --_gl;
		m_BkColor.iGray(_gl);
		m_pdlgcWnd->Invalidate();
		m_pdlgcWnd->UpdateWindow();
		Sleep(60);
        //�q�����
        m_pCa210->Measure();
        fLv = m_pCa210->GetMsrData().oFlt(VluK_Lv);  //m_IProbe.GetLv();
    }
}

// void CPatternDlg::Nits_finePos(const int& specNits)
// {
// 	int _gl= 60;//     int Graylevel = 55;
//     float fLv = 0;
//     while(fLv >  specNits)  //�Y�G���٨S����5�H�U�A�N���
//     {
//         _gl -= 2;
// 		m_BkColor.iGray(_gl);
// 		Invalidate();
// 		UpdateWindow();
//         //�q�����
//         if (m_pCA210->Measure() == CA_ZeroCalMode)
//             MessageBox("�ɦ줣�bMEAS");
//         fLv = m_pCA210->GetMsrData().oFlt(VluK_Lv);  //m_IProbe.GetLv();
//     }
// 
//     while(fLv < specNits)   //�Y�G���٦b5�H�U�A�N...�ܫG
//     {
//         ++_gl;
// 		m_BkColor.iGray(_gl);
// 		Invalidate();
// 		UpdateWindow();
//         Sleep(60);
// //      �q�����
//         m_pCA210->Measure();
//         fLv = m_pCA210->GetMsrData().oFlt(VluK_Lv);  //m_IProbe.GetLv();
//     }
// }
// 
// void CPatternDlg::Nits_fineNeg(const int& specNits)
// {
//     float fLv = 0;
// 	int _gl = 55;
// 
//     while(fLv < specNits)  //�Y�G���٨S����5�H�U�A�N���
//     {
//         _gl += 2;
// 		m_BkColor.iGray(_gl);
// 		Invalidate();
// 		UpdateWindow();
// //        Sleep(0);
// //        �q�����
//         if (m_pCA210->Measure() == CA_ZeroCalMode)
//             MessageBox("�ɦ줣�bMEAS");
//         fLv = m_pCA210->GetMsrData().oFlt(VluK_Lv);  //m_IProbe.GetLv();
//     }
//     
//     while(fLv > specNits)   //�Y�G���٦b5�H�U�A�N...�ܫG
//     {
//         --_gl;
// 		m_BkColor.iGray(_gl);
// 		Invalidate();
// 		UpdateWindow();
// 		Sleep(60);
//         //�q�����
//         m_pCA210->Measure();
//         fLv = m_pCA210->GetMsrData().oFlt(VluK_Lv);  //m_IProbe.GetLv();
//     }
// }
// 
// void CPatternDlg::Nits_fine(BackGroundStatus _BKS)
// {
// 
//     //�����t��k
//    int glvMax = 255, glvMin = 0;
// 
//     while ((glvMax - glvMin) > 2)
//     {
//         Graylevel = (glvMax + glvMin)/2;
//         setBkColor(Graylevel);
//         m_pCA210->Measure();
//         fLv = m_pCA210->GetMsrData().GetLv();
//         
//         if( fLv > m_itor->specNits )
//             glvMax = Graylevel;
//         else// if (fLv > m_itor->specNits )
//             glvMin = Graylevel;
//     }
// 
//     CString str;
//     str.Format("max:%d\nmin%d\ngraylv:%d", glvMax, glvMin, Graylevel);
//     AfxMessageBox(str)
// 	int Graylevel;
// 	switch(_BKS)
// 	{
// 	case BGS_NitsNeg:
// 		Nits_finePos();
// 		break;
// 	case BGS_NitsPos:
// 		Nits_fineNeg();
// 		break;
// 	case BGS_Normal:
// 		setBkColor(m_BkColor);
// 		break;
// 	default:
// 		MessageBox("��Nits�X���D�C");
// 	}
// 	//���槹�C��|�s�bm_BkColor
// }

#endif