#include "StdAfx.h"
#include "CA210.h"
#include <cstdlib>
#include <ctime>


Ca210::Ca210(BOOL tr):
ImpsbStr("1. ���uPrt Scm��v��U�ثe���ù��A�ö}�p�e�a�K�W�A�t�s������\n2. Mail�����{���]�p�̡A�ԲӴy�z�ϥιL�{�ñN���ɦs������\n�o�O�|���w����X�{�����D�C�]���Ӥ��|�o�ͪ����ءC�^"),
m_isSuccess(TRUE)
{
    /*
    ��l��ca-210
    �]�w�O�_��������
    */
//    m_CA210DEBUGFlag = TRUE;
//    m_CA210DEBUGFlag = FALSE;
    m_isTrue = tr;  //TRUE���������, FALSE��������
    if (m_isTrue)
    {
#ifdef _CA210DEBUG
        DBugModeBox("TRUE of Ca210(BOOL tr)");
#endif
		int flag = 1;
		     if (!CreatCa200())   AfxMessageBox("CreatCa200() ERROR!!");
		else if (!ConnectCa210()) AfxMessageBox("ConnectCa210() ERROR!!");
		else if (!AttachCa())     AfxMessageBox("AttachCa() ERROR!!");
		else if (!AttchProbe())   AfxMessageBox("AttchProbe() ERROR!!");            
		else
			m_isZeroCal = FALSE;
    }
    else
    {
        //������
#ifdef _CA210DEBUG
        DBugModeBox("FALSE of Ca210(BOOL tr)");
#endif
        m_isZeroCal = FALSE;
//        SetOnline(FALSE);
    }
}

Ca210::~Ca210()
{
    if (m_isTrue)
    {
#ifdef _CA210DEBUG
        DBugModeBox("TRUE of ~Ca210()");
#endif
        if (GetOnline())
            SetOnline(FALSE);
        m_IMemory.DetachDispatch();
        m_IProbe.DetachDispatch();
        m_ICa.DetachDispatch();
        m_ICa200.ReleaseDispatch();
    }
}

BOOL Ca210::CreatCa200()
{
	BOOL m_isSuccess(TRUE);
	try
	{
		m_ICa200.CreateDispatch("CA200Srvr.Ca200.1");
		m_ICa200.m_bAutoRelease = TRUE;		
	}
	catch (CException* e)
	{
		MsgFrmt(e, "CreatCa200();�X���D", "1. �ˬdUSB�u�M�q��\n2. ���T�w");
		m_ICa200.ReleaseDispatch();		
		m_isSuccess = FALSE;
	}
	return m_isSuccess;
}

BOOL Ca210::ConnectCa210()
{
	BOOL m_isSuccess(TRUE);
	try
	{
		m_ICa200.AutoConnect();
	}            
	catch (CException* e)
	{
		MsgFrmt(e, "LPDISPATCH pICa = m_ICa200.ConnectCa210();�X���D", ImpsbStr);
		m_ICa200.ReleaseDispatch();
		m_isSuccess = FALSE;
	}
	
	return m_isSuccess;
}

BOOL  Ca210::AttachCa()
{
	LPDISPATCH pICa;
	BOOL m_isSuccess(TRUE);
	try
	{
		pICa = m_ICa200.GetSingleCa();
		m_ICa.AttachDispatch(pICa);
	}            
	catch (CException* e)
	{
		MsgFrmt(e, "LPDISPATCH pICa = m_ICa200.GetSingleCa();�X���D", ImpsbStr);
		pICa = 0;
		m_ICa200.ReleaseDispatch();
		m_isSuccess = FALSE;
	}

	return m_isSuccess;
}

BOOL Ca210::AttchProbe()
{
	LPDISPATCH pIProbe;
	BOOL m_isSuccess;
	try
	{
		pIProbe = m_ICa.GetSingleProbe();
		m_IProbe.AttachDispatch(pIProbe);
	}            
	catch (CException* e)
	{
		MsgFrmt(e, "LPDISPATCH pIProbe = m_ICa.GetSingleProbe();�X���D", ImpsbStr);
		pIProbe = 0;
		m_ICa.DetachDispatch();
		m_ICa200.ReleaseDispatch();
		m_isSuccess = FALSE;
	}
	
	return m_isSuccess;
}

BOOL Ca210::isReady() const
{
	return m_isSuccess;
}

BOOL Ca210::isTrue() const
{
#ifdef _CA210DEBUG
    DBugModeBox("TRUE of isTrue()");
#endif
    return m_isTrue;
}

BOOL Ca210::CalZero()
{
    /*
    �s�u ���
    caes 11   ����ZeroCal
                �ҥ~�B�z:
                  ��MessageBox
                  �A����ZeroCal
    case 10   Delay1sec ����ZeroCal���ɶ�
    default   �^��FALSE  �L�k����
    */    
    if(m_Online && m_isTrue)
    {
#ifdef _CA210DEBUG
        DBugModeBox("TRUE of CalZero()");
#endif

        int flag = 0;
         do 
         {
            try
            {
                m_ICa.CalZero();
                m_isZeroCal = TRUE;
                flag = 0;
            }
            catch (CException* e)
            {
                if (flag < 1)
                    MsgFrmt(e,"�N�M���٨S���0-Cal�N����Zero Cal", "1. �N�q�������0-Cal�ɡC\n2. ���u�T�w�v");
                else
                    MsgFrmt("1. �N�q�������0-Cal�ɡC\n2. ���u�T�w�v");
                flag++;
            }
         } while (flag);
        return TRUE;
    }
    else if(m_Online && !m_isTrue)
    {
        //������
#ifdef _CA210DEBUG
        DBugModeBox("FALSE of CalZero()");
#endif

        m_isZeroCal = TRUE;
        Sleep(1000);
        return TRUE;
    }
    else
    {
#ifdef _CA210DEBUG
        DBugModeBox("TRUE of CalZero()");
#endif
        return FALSE;
    }
}

BOOL Ca210::LinkMemory()
{
    if (m_isTrue && m_Online)
    {
#ifdef _CA210DEBUG
        DBugModeBox("TRUE of LinkMemory()");
#endif
        LPDISPATCH pMemory;

        try
        {
		    pMemory = m_ICa.GetMemory();
            m_IMemory.AttachDispatch(pMemory);
        }
        catch (CException* e)
        {
            MsgFrmt(e, "LinkMemory(pMemory);�X���D", ImpsbStr);
        }
         return TRUE;
    } 
    else
    {
#ifdef _CA210DEBUG
        DBugModeBox("FALSE of LinkMemory()");
#endif
        return FALSE;
    }
}

UINT Ca210::Measure()
{
    /*
    0 �S�s�u
    1 �s�u
    2 �|��Zero Cal
    3 �ɦ줣�bMEAS
    4 �q�����`
    */
    UINT Mode = m_Online;
    if(m_Online && m_isTrue)
    {
#ifdef _CA210DEBUG
        DBugModeBox("TRUE of Measure()");
#endif
        int flag = 0;
    
        if (m_isZeroCal)
        {
            do 
            {
                try
                {
                    m_ICa.Measure(0);
                    if (m_IProbe.GetLv() < 0.01)
                        Mode = 3;
                    else
                        Mode = 4;
                    flag = 0;
                }
                catch (CException* e)
                {
                    TCHAR buf[255];
                    e->GetErrorMessage(buf, 255);

//                     MsgFrmt(e, "�q���X���D", "���O���O�����`�ϥζq���]���O�n���ι�۱j����...�������^\n�_�h�A���n���ʶq�����T�w���q��誺�I");
//                     flag++;
                    continue;
                }
            } while (flag);
        }
        else
        {
            //MsgFrmt("�O�_Zero Cal!!!");
            Mode = 2;
        }
    }
    return Mode;
}

BOOL Ca210::SetOnline(BOOL isOnline)
{
    if (m_isTrue)
    {
#ifdef _CA210DEBUG
        DBugModeBox("TRUE of SetOnline(BOOL isOnline)");
#endif
        try
        {
            m_ICa.SetRemoteMode(isOnline);
        }
        catch (CException* e)
        {
            MsgFrmt(e, "�s�u/���u�X���D", ImpsbStr);
        }
    }
    m_Online = isOnline;
    return isOnline;
}

BOOL Ca210::GetOnline() const
{
    return m_Online;
}

CString Ca210::GetLcmSize()
{
    CString str;
    if (m_Online)
    {
         if (m_isTrue)
         {
#ifdef _CA210DEBUG
             DBugModeBox("TRUE of GetLcmSize()");
#endif
             try
             {
                 str.Format("%s", m_IMemory.GetChannelID().Left(2));
             }
             catch (CException* e)
             {
                 MsgFrmt(e, "�Ҳդؤo�j�p�]�w�X���D", ImpsbStr);
                 return "-1";
             }
             return str;
         }
         else
         {
#ifdef _CA210DEBUG
             DBugModeBox("TRUE of GetLcmSize()");
#endif
             str.Format("24");
         }
    }
    else 
        str.Format("-1");
        return str;
}

CString Ca210::GetChData()
{
    CString temp;
    if (m_Online)
    {
        try
        {
            CString str;
            str.Format("%s of GetChData()", m_Online ? "TRUE" : "FALSE");
#ifdef _CA210DEBUG
            DBugModeBox(str);
#endif
            temp.Format(m_isTrue ? "%ld - %s", m_IMemory.GetChannelNO(), m_IMemory.GetChannelID() : "XX - �����W�D");
        }
        catch (CException* e)
        {
            MsgFrmt(e, "�qCA-210��Channel����ƥX�ӥX���D", ImpsbStr);
        }
    }
    else
        temp.Format("�w���u - �L�W�D");
    return temp;
}

CString Ca210::GetChNO()
{
    str.Format("%ld", m_IMemory.GetChannelNO());
    return str;
}

CString Ca210::GetProb()
{
    return m_IProbe.GetSerialNO();
}

CString Ca210::GetDeviceType()
{
    return m_ICa.GetCAType();
}

Bullet Ca210::GetMsrData()
{
    if (m_Online)
    {
        if (m_isTrue)
        {
#ifdef _CA210DEBUG
            DBugModeBox("TRUE of GetMsrData()");
#endif

            try
            {
                m_blt.SetLv(m_IProbe.GetLv());
                m_blt.SetSx(m_IProbe.GetSx());
                m_blt.SetSy(m_IProbe.GetSy());
                
                m_blt.SetT(m_IProbe.GetT());
                m_blt.SetDuv(m_IProbe.GetDuv());
                
                m_blt.SetDu(m_IProbe.GetUd());
                m_blt.SetDv(m_IProbe.GetVd());
                
                m_blt.SetX(m_IProbe.GetX());
                m_blt.SetY(m_IProbe.GetY());
                m_blt.SetZ(m_IProbe.GetZ());
            }
            catch (CException* e)
            {
                MsgFrmt(e, "�qCA-210Ū���q���ȥX���D", ImpsbStr);
            }

        }
        else
        {
#ifdef _CA210DEBUG
            DBugModeBox("FALSE of GetMsrData()");
#endif
            srand(time(NULL));
            m_blt.SetLv((float)(rand()%100000)/100);    //%3.2f
            m_blt.SetSx((float)(rand()%10000 +1)/(float)10000);  //%1.4f
            m_blt.SetSy((float)(rand()%10000 +1)/(float)10000);  //%1.4f
            
            m_blt.SetT(rand()%1000);//%3d
            m_blt.SetDuv((float)(rand()%100000)/10000);  //%1.4f
            
            m_blt.SetDu((float)(rand()%100000)/10000);  //%1.4f
            m_blt.SetDv((float)(rand()%100000)/10000);  //%1.4f
            
            m_blt.SetX((float)(rand()%100000)/100);  //%3.2f
            m_blt.SetY((float)(rand()%100000)/100);  //%3.2f
            m_blt.SetZ((float)(rand()%100000)/100);  //%3.2f
        }
    }
    return m_blt;
}

CString Ca210::OutData()
{
    CString Lv, SX, SY;
    CString T, Duv;
    CString Du, Dv;
    CString X, Y, Z;

    if (m_Online)
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
//     else if (m_Online && !m_isTrue)
//     {
// #ifdef _CA210DEBUG
//     DBugModeBox("FALSE of OutData()");
// #endif
//         srand(time(NULL));
//         
//         Lv.Format("%3.2f", (float)(rand()%100000)/100);//Lv
//         SX.Format("%1.4f", (float)(rand()%10000 +1)/10000);//Small x
//         SY.Format("%1.4f", (float)(rand()%10000 +1)/10000);//Small y
//         
//         T.Format("%3d�X" ,         rand()%10000);//T
//         Duv.Format("%1.4f", (float)(rand()%100000)/10000);//duv
//         
//         Du.Format("%1.4f", (float)(rand()%100000)/10000);//du
//         Dv.Format("%1.4f", (float)(rand()%100000)/10000);//dv
//         
//         X.Format("%3.2f", (float)(rand()%100000)/100);//X
//         Y.Format("%3.2f", (float)(rand()%100000)/100);//Y
//         Z.Format("%3.2f", (float)(rand()%100000)/100);//Z
//     }
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
    return " Lv =" + Lv  + "     \n" 
        + "  x =" +  SX + "     \n" 
        + "  y =" +  SY + "     \n" 
        + "  T =" +  T  + "     \n" 
        + "�Guv=" + Duv + "     \n" 
        + " u' =" + Du  + "     \n"
        + " v' =" +  Dv + "     \n"
        + "  X =" +  X  + "     \n"
        + "  Y =" +  Y  + "     \n"
        + "  Z =" +  Z;
}

UINT Ca210::MsrAI(float MsrDeviation)
{
/*
  return 
  0  �G��0�A�ثe0-Cal
  1  �зǪ��e�Ȥ��G�~��q��+�ʤ���
  2  �зǪ��e�ȥ~�G�~��q��-�ʤ���
  3  ���s�u
 */
    if (m_Online)
    {
        float XFristValue = 0.0, deltaX = 0.0,
              YFristValue = 0.0, deltaY = 0.0,
              ZFristValue = 0.0, deltaZ = 0.0, deltaAll;

        if (m_isTrue)
        {
#ifdef _CA210DEBUG
            DBugModeBox("TRUE of MsrAI(float MsrDeviation)");
#endif        //�Ĥ@����ƼȦs�Ŷ�  //�ŧi�~�t�ȭp��Ŷ�

            Measure();

            if((double)m_IProbe.GetLv() == 0.0)
                return 0;//0 cal �ɦ�

            //��Ѧҭ�
                XFristValue = m_IProbe.GetX();
                YFristValue = m_IProbe.GetY();
                ZFristValue = m_IProbe.GetZ();

            Measure();

            //�~�t�������
                deltaX = ((XFristValue-m_IProbe.GetX())>=0) ? XFristValue - m_IProbe.GetX() : m_IProbe.GetX() - XFristValue;
                deltaY = ((YFristValue-m_IProbe.GetY())>=0) ? YFristValue - m_IProbe.GetY() : m_IProbe.GetY() - YFristValue;
                deltaZ = ((ZFristValue-m_IProbe.GetZ())>=0) ? ZFristValue - m_IProbe.GetZ() : m_IProbe.GetZ() - ZFristValue;
        }
        else
        {
#ifdef _CA210DEBUG
            DBugModeBox("FALSE of MsrAI(float MsrDeviation)");
#endif
            srand(time(NULL));

             //�~�t�������
                deltaX = (float)(rand()%100000)/100 - (float)(rand()%100000)/100;
                deltaY = (float)(rand()%100000)/100 - (float)(rand()%100000)/100;
                deltaZ = (float)(rand()%100000)/100 - (float)(rand()%100000)/100;
        }

        deltaAll = deltaX * deltaY * deltaZ;

        if (deltaAll < MsrDeviation )    return 1;//���e�Ȥ�
        else                             return 2;//���e�ȥ~
    }
    else
        return 3; //���s�u
}

//�]�wĵ�i�Хܪ��зǮ榡
void Ca210::MsgFrmt(CException* e, CString mean, CString steps)
{
    CString str;
    TCHAR buf[255];
    e->GetErrorMessage(buf, 255);
    
    str.Format("�V�|!!!�X�{ERROR!!!\n\n��t���~�T��:\n%s\n\n�ݤ����S���Y�A�N��N�O:\n�u%s�v\n\n�A�u�n��:\n%s", buf, mean, steps);
    AfxMessageBox(str);
}

void Ca210::MsgFrmt(CString steps)
{
    CString str;
    str.Format("�A�o�b�ܡH\n%s", steps);
    AfxMessageBox(str);
}


//////////////////////////////////////////////////////////////////////////
//debug function

#ifdef _CA210DEBUG

CString Ca210::GetSetupValue() const
{
    CString str;
    str.Format("�s�u:%d, ���:%d, ZeroCal�F�S:%d", m_Online, m_isTrue, m_isZeroCal);
    return str;
}

void Ca210::DBugModeBox(CString str) const
{
    CString strTemp;
    strTemp.Format("%s\n%s�Ҧ�, %s", str, m_isTrue?"�u��":"����", m_Online?"�s�u":"���u");
    AfxMessageBox(strTemp);
}

#endif
