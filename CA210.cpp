#include "stdafx.h"
#include "CA210.h"

//������ƪ���l�ơA�٬O�n��l�����O���СA�ҥH�s�u��ƥ��������A���i�H��b�@�P�������I
//���M�N�O���@�Ӧ@�P����¦���O�C

//////////////////////////////////////////////////////////////////////////
const CString Ca210::OutData()
{

#ifdef _CA210DEBUG
        DBugModeBox("TRUE of OutData()");
#endif
    try
    {
		if(isOnline())
			return m_blt.Show();
		else
			return m_blt.Show() + "\n���u��...";
    }
    catch (CException* e)
    {
        MsgFrmt(e, "�qCA-210Ū���q���ȥX���D", ImpsbStr);
    }
	ASSERT(0);
	return "";
}
//�]�wĵ�i�Хܪ��зǮ榡
