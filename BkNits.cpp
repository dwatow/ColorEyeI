#include "stdafx.h"
#include "BkNits.h"

void BkNits::n2cPos(ColorRef& Bkclr)
{
	int _gl= 60;//     int Graylevel = 55;
    int fLv = 100*100;
    while(fLv > m_Nits)  //若亮度還沒有到5以下，就減少
    {
        _gl -= 2;
		Bkclr.iGray(_gl);
		m_pdlgcWnd->Invalidate();
		m_pdlgcWnd->UpdateWindow();
        //量測抓值
        if (m_pCa210->Measure() == CA_ZeroCalMode)
            AfxMessageBox("檔位不在MEAS");
        fLv = (int)((m_pCa210->GetMsrData().oFlt(VluK_Lv))*100);  //m_IProbe.GetLv();
    }
	
    while(fLv < m_Nits)   //若亮度還在5以下，就...變亮
    {
        ++_gl;
		Bkclr.iGray(_gl);
		m_pdlgcWnd->Invalidate();
		m_pdlgcWnd->UpdateWindow();
        Sleep(60);
		//      量測抓值
        m_pCa210->Measure();
        fLv = (int)((m_pCa210->GetMsrData().oFlt(VluK_Lv))*100);  //m_IProbe.GetLv();
    }
	_SetBkColor(Bkclr);
}

void BkNits::n2cNeg(ColorRef& Bkclr)
{
    int fLv = 0;
	int _gl = 55;
	
    while(fLv < m_Nits)  //若亮度還沒有到5以下，就減少
    {
        _gl += 2;
		Bkclr.iGray(_gl);
		m_pdlgcWnd->Invalidate();
		m_pdlgcWnd->UpdateWindow();
		//        Sleep(0);
		//        量測抓值
        if (m_pCa210->Measure() == CA_ZeroCalMode)
            AfxMessageBox("檔位不在MEAS");
        fLv = (int)((m_pCa210->GetMsrData().oFlt(VluK_Lv))*100);  //m_IProbe.GetLv();
    }
    
    while(fLv > m_Nits)   //若亮度還在5以下，就...變亮
    {
        --_gl;
		Bkclr.iGray(_gl);
		m_pdlgcWnd->Invalidate();
		m_pdlgcWnd->UpdateWindow();
		Sleep(60);
        //量測抓值
        m_pCa210->Measure();
        fLv = (int)((m_pCa210->GetMsrData().oFlt(VluK_Lv))*100);  //m_IProbe.GetLv();
    }
	_SetBkColor(Bkclr);
}