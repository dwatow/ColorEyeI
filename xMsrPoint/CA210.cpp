#include "StdAfx.h"
#include "CA210.h"

//虛擬函數的初始化，還是要初始父類別指標，所以連線函數必須移走，不可以放在共同的部份！
//不然就是做一個共同的基礎類別。

//////////////////////////////////////////////////////////////////////////
CString Ca210::OutData()
{

#ifdef _CA210DEBUG
        DBugModeBox("TRUE of OutData()");
#endif
    try
    {
		if(isOnline())
			return m_blt.show();
		else
			return m_blt.show() + "\n離線中...";
    }
    catch (CException* e)
    {
        MsgFrmt(e, "從CA-210讀取量測值出問題", ImpsbStr);
    }
	ASSERT(0);
	return "";
}
//設定警告標示的標準格式
