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
//     while(fLv >  specNits)  //若亮度還沒有到5以下，就減少
//     {
//         _gl -= 2;
// 		_GetBkColor().iGray(_gl);
// 		Invalidate();
// 		UpdateWindow();
//         //量測抓值
//         if (m_pCA210->Measure() == CA_ZeroCalMode)
//             AfxMessageBox("檔位不在MEAS");
//         fLv = m_pCA210->GetMsrData().oFlt(VluK_Lv);  //m_IProbe.GetLv();
//     }
// 
//     while(fLv < specNits)   //若亮度還在5以下，就...變亮
//     {
//         ++_gl;
// 		_GetBkColor().iGray(_gl);
// 		Invalidate();
// 		UpdateWindow();
//         Sleep(60);
// //      量測抓值
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
//     while(fLv < specNits)  //若亮度還沒有到5以下，就減少
//     {
//         _gl += 2;
// 		_GetBkColor().iGray(_gl);
// 		Invalidate();
// 		UpdateWindow();
// //        Sleep(0);
// //        量測抓值
//         if (m_pCA210->Measure() == CA_ZeroCalMode)
//             AfxMessageBox("檔位不在MEAS");
//         fLv = m_pCA210->GetMsrData().oFlt(VluK_Lv);  //m_IProbe.GetLv();
//     }
//     
//     while(fLv > specNits)   //若亮度還在5以下，就...變亮
//     {
//         --_gl;
// 		_GetBkColor().iGray(_gl);
// 		Invalidate();
// 		UpdateWindow();
// 		Sleep(60);
//         //量測抓值
//         m_pCA210->Measure();
//         fLv = m_pCA210->GetMsrData().oFlt(VluK_Lv);  //m_IProbe.GetLv();
//     }
// }
// 
// void CPatternDlg::Nits_fine(BackGroundStatus _BKS)
// {
// 
//     //夾擊演算法
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
// 		AfxMessageBox("找Nits出問題。");
// 	}
// 	//執行完顏色會存在_GetBkColor()
// }

#endif