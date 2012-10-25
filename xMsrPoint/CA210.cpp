#include "StdAfx.h"
#include "CA210.h"

//������ƪ���l�ơA�٬O�n��l�����O���СA�ҥH�s�u��ƥ��������A���i�H��b�@�P�������I
//���M�N�O���@�Ӧ@�P����¦���O�C

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
            
            T.Format("%3d�X", m_blt.GetT());//T
            Duv.Format("%1.4f", m_blt.GetDuv());//duv
            
            Du.Format("%1.4f", m_blt.GetDu());//du
            Dv.Format("%1.4f", m_blt.GetDv());//dv
            
            X.Format("%3.2f", m_blt.GetX());//X
            Y.Format("%3.2f", m_blt.GetY());//Y
            Z.Format("%3.2f", m_blt.GetZ());//Z
        }
        catch (CException* e)
        {
            MsgFrmt(e, "�qCA-210Ū���q���ȥX���D", ImpsbStr);
        }
    }    
    else
    {
        Lv.Format("���u�F");//Lv
        SX.Format("���u�F");//Small x
        SY.Format("���u�F");//Small y
        
        T.Format("���u�F");//T
        Duv.Format("���u�F");//duv
        
        Du.Format("���u�F");//du
        Dv.Format("���u�F");//dv
        
        X.Format("���u�F");//X
        Y.Format("���u�F");//Y
        Z.Format("���u�F");//Z
		
    } 
    return " Lv =" + Lv + "     \n" 
		+ "  x =" + SX + "     \n" 
		+ "  y =" + SY + "     \n" 
		+ "  T =" +  T + "     \n" 
		+ "�Guv=" + Duv + "     \n" 
		+ " u' =" + Du + "     \n"
		+ " v' =" + Dv + "     \n"
		+ "  X =" +  X + "     \n"
		+ "  Y =" +  Y + "     \n"
		+ "  Z =" +  Z;
}
//�]�wĵ�i�Хܪ��зǮ榡
