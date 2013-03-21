#ifndef BKNITS_H
#define BKNITS_H

#include "BkMaker.h"

class BkNits : public BkMaker
{
	//m_pCA210
	//hWnd
	void n2cPos();
	void n2cNeg();
public:
 	BkNits(const NitsDirect&);
    BkNits(const BkNits& bkN);

	void NT_SetWnd(CWnd* cWnd){ m_pdlgcWnd = cWnd; };
	void NT_SetCa(Ca210* pCa){ m_pCa210 = pCa; };

	void       NT_nits2color();
	void       NT_SetNitsDirect(NitsDirect nd);
	NitsDirect NT_GetNitsDirect() const;
};

inline BkNits::BkNits(const NitsDirect& nt)
{
	BkMaker::BkMaker();
	m_NitsDirect = nt;
}

inline BkNits::BkNits(const BkNits& bkN)
{
	BkMaker::BkMaker();
	NT_SetNitsDirect(bkN.NT_GetNitsDirect());
	_SetBkColor(bkN._GetBkColor());
}

inline void BkNits::NT_nits2color()
{
	switch(m_NitsDirect)
	{
	case ND_Pos:
		n2cPos();
		break;
	case ND_Neg:
	default:
		n2cNeg();		
	}
}

inline void BkNits::NT_SetNitsDirect(NitsDirect nd)
{ m_NitsDirect = nd;};
inline NitsDirect BkNits::NT_GetNitsDirect() const
{ return m_NitsDirect; };

// void CPatternDlg::Nits_finePos(const int& specNits)
// {
// 	int _gl= 60;//     int Graylevel = 55;
//     float fLv = 0;
//     while(fLv >  specNits)  //�Y�G���٨S����5�H�U�A�N���
//     {
//         _gl -= 2;
// 		_GetBkColor().iGray(_gl);
// 		Invalidate();
// 		UpdateWindow();
//         //�q�����
//         if (m_pCA210->Measure() == CA_ZeroCalMode)
//             AfxMessageBox("�ɦ줣�bMEAS");
//         fLv = m_pCA210->GetMsrData().oFlt(VluK_Lv);  //m_IProbe.GetLv();
//     }
// 
//     while(fLv < specNits)   //�Y�G���٦b5�H�U�A�N...�ܫG
//     {
//         ++_gl;
// 		_GetBkColor().iGray(_gl);
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
// 		_GetBkColor().iGray(_gl);
// 		Invalidate();
// 		UpdateWindow();
// //        Sleep(0);
// //        �q�����
//         if (m_pCA210->Measure() == CA_ZeroCalMode)
//             AfxMessageBox("�ɦ줣�bMEAS");
//         fLv = m_pCA210->GetMsrData().oFlt(VluK_Lv);  //m_IProbe.GetLv();
//     }
//     
//     while(fLv > specNits)   //�Y�G���٦b5�H�U�A�N...�ܫG
//     {
//         --_gl;
// 		_GetBkColor().iGray(_gl);
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
//     AfxAfxMessageBox(str)
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
// 		setBkColor(_GetBkColor());
// 		break;
// 	default:
// 		AfxMessageBox("��Nits�X���D�C");
// 	}
// 	//���槹�C��|�s�b_GetBkColor()
// }

#endif