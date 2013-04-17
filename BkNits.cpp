#include "stdafx.h"
#include "BkNits.h"

void BkNits::n2cPos(ColorRef& Bkclr)
{
	int _gl= 60;//     int Graylevel = 55;
    int fLv = 100*100;
    while(fLv > m_Nits)  //�Y�G���٨S����5�H�U�A�N���
    {
        _gl -= 2;
		Bkclr.iGray(_gl);
		m_pdlgcWnd->Invalidate();
		m_pdlgcWnd->UpdateWindow();
        //�q�����
        if (m_pCa210->Measure() == CA_ZeroCalMode)
            AfxMessageBox("�ɦ줣�bMEAS");
        fLv = (int)((m_pCa210->GetMsrData().oFlt(VluK_Lv))*100);  //m_IProbe.GetLv();
    }
	
    while(fLv < m_Nits)   //�Y�G���٦b5�H�U�A�N...�ܫG
    {
        ++_gl;
		Bkclr.iGray(_gl);
		m_pdlgcWnd->Invalidate();
		m_pdlgcWnd->UpdateWindow();
        Sleep(60);
		//      �q�����
        m_pCa210->Measure();
        fLv = (int)((m_pCa210->GetMsrData().oFlt(VluK_Lv))*100);  //m_IProbe.GetLv();
    }
	_SetBkColor(Bkclr);
}

void BkNits::n2cNeg(ColorRef& Bkclr)
{
    int fLv = 0;
	int _gl = 55;
	
    while(fLv < m_Nits)  //�Y�G���٨S����5�H�U�A�N���
    {
        _gl += 2;
		Bkclr.iGray(_gl);
		m_pdlgcWnd->Invalidate();
		m_pdlgcWnd->UpdateWindow();
		//        Sleep(0);
		//        �q�����
        if (m_pCa210->Measure() == CA_ZeroCalMode)
            AfxMessageBox("�ɦ줣�bMEAS");
        fLv = (int)((m_pCa210->GetMsrData().oFlt(VluK_Lv))*100);  //m_IProbe.GetLv();
    }
    
    while(fLv > m_Nits)   //�Y�G���٦b5�H�U�A�N...�ܫG
    {
        --_gl;
		Bkclr.iGray(_gl);
		m_pdlgcWnd->Invalidate();
		m_pdlgcWnd->UpdateWindow();
		Sleep(60);
        //�q�����
        m_pCa210->Measure();
        fLv = (int)((m_pCa210->GetMsrData().oFlt(VluK_Lv))*100);  //m_IProbe.GetLv();
    }
	_SetBkColor(Bkclr);
}