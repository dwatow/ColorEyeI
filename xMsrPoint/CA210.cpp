#include "StdAfx.h"
#include "CA210.h"

//虛擬函數的初始化，還是要初始父類別指標，所以連線函數必須移走，不可以放在共同的部份！
//不然就是做一個共同的基礎類別。

//////////////////////////////////////////////////////////////////////////
CString Ca210::OutData()
{
    CString Lv, SX, SY;
    CString T, Duv;
    CString Du, Dv;
    CString X, Y, Z;
	
    if(isOnline())
    {
#ifdef _CA210DEBUG
        DBugModeBox("TRUE of OutData()");
#endif
        try
        {
            Lv.Format("%3.2f", m_blt.GetLv());//Lv
            SX.Format("%1.4f", m_blt.GetSx());//Small x
            SY.Format("%1.4f", m_blt.GetSy());//Small y
            
            T.Format("%3d°", m_blt.GetT());//T
            Duv.Format("%1.4f", m_blt.GetDuv());//duv
            
            Du.Format("%1.4f", m_blt.GetDu());//du
            Dv.Format("%1.4f", m_blt.GetDv());//dv
            
            X.Format("%3.2f", m_blt.GetX());//X
            Y.Format("%3.2f", m_blt.GetY());//Y
            Z.Format("%3.2f", m_blt.GetZ());//Z
        }
        catch (CException* e)
        {
            MsgFrmt(e, "從CA-210讀取量測值出問題", ImpsbStr);
        }
    }    
    else
    {
        Lv.Format("離線了");//Lv
        SX.Format("離線了");//Small x
        SY.Format("離線了");//Small y
        
        T.Format("離線了");//T
        Duv.Format("離線了");//duv
        
        Du.Format("離線了");//du
        Dv.Format("離線了");//dv
        
        X.Format("離線了");//X
        Y.Format("離線了");//Y
        Z.Format("離線了");//Z
		
    } 
    return " Lv =" + Lv + "     \n" 
		+ "  x =" + SX + "     \n" 
		+ "  y =" + SY + "     \n" 
		+ "  T =" +  T + "     \n" 
		+ "Δuv=" + Duv + "     \n" 
		+ " u' =" + Du + "     \n"
		+ " v' =" + Dv + "     \n"
		+ "  X =" +  X + "     \n"
		+ "  Y =" +  Y + "     \n"
		+ "  Z =" +  Z;
}
//設定警告標示的標準格式
