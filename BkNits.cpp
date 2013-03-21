#include "BkNits.h"

void BkNits::n2cPos()
{
	int _gl= 60;//     int Graylevel = 55;
    float fLv = 0;
    while(fLv >  m_Nits)  //�Y�G���٨S����5�H�U�A�N���
    {
        _gl -= 2;
		_GetBkColor().iGray(_gl);
		m_pdlgcWnd->Invalidate();
		m_pdlgcWnd->UpdateWindow();
        //�q�����
        if (m_pCa210->Measure() == CA_ZeroCalMode)
            AfxMessageBox("�ɦ줣�bMEAS");
        fLv = m_pCa210->GetMsrData().oFlt(VluK_Lv);  //m_IProbe.GetLv();
    }
	
    while(fLv < m_Nits)   //�Y�G���٦b5�H�U�A�N...�ܫG
    {
        ++_gl;
		_GetBkColor().iGray(_gl);
		m_pdlgcWnd->Invalidate();
		m_pdlgcWnd->UpdateWindow();
        Sleep(60);
		//      �q�����
        m_pCa210->Measure();
        fLv = m_pCa210->GetMsrData().oFlt(VluK_Lv);  //m_IProbe.GetLv();
    }
}

void BkNits::n2cNeg()
{
    float fLv = 0;
	int _gl = 55;
	
    while(fLv < m_Nits)  //�Y�G���٨S����5�H�U�A�N���
    {
        _gl += 2;
		_GetBkColor().iGray(_gl);
		m_pdlgcWnd->Invalidate();
		m_pdlgcWnd->UpdateWindow();
		//        Sleep(0);
		//        �q�����
        if (m_pCa210->Measure() == CA_ZeroCalMode)
            AfxMessageBox("�ɦ줣�bMEAS");
        fLv = m_pCa210->GetMsrData().oFlt(VluK_Lv);  //m_IProbe.GetLv();
    }
    
    while(fLv > m_Nits)   //�Y�G���٦b5�H�U�A�N...�ܫG
    {
        --_gl;
		_GetBkColor().iGray(_gl);
		m_pdlgcWnd->Invalidate();
		m_pdlgcWnd->UpdateWindow();
		Sleep(60);
        //�q�����
        m_pCa210->Measure();
        fLv = m_pCa210->GetMsrData().oFlt(VluK_Lv);  //m_IProbe.GetLv();
    }
}