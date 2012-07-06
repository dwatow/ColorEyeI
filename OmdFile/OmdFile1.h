// OmdFile1.h: interface for the COmdFile class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OMDFILE1_H__5E9E8D8E_4BB9_40C8_BEE3_2756DA9A7E76__INCLUDED_)
#define AFX_OMDFILE1_H__5E9E8D8E_4BB9_40C8_BEE3_2756DA9A7E76__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TxtFile.h"
#include "../xMsrPoint/Cartridge.h"

enum isMsrValue	{Lv = 0, Sx, Sy, du, dv, T, duv, X, Y, Z};
enum isMsrItem	{WRGBD = 0, Nts, W49, W9, D25, W5};

class COmdFile1 : public CTxtFile
{

//////////////////////////////////////////////////////////////////////////
	//輸入函式
/*	  輸入有兩種方式      *
 *	    1. 由vector串     *
 *		2. 讀取檔案進來   */
public:
	//從記憶體輸入資料
    COmdFile1(std::vector<Cartridge>&); //開新檔案，並且丟入Data
    COmdFile1();
    virtual ~COmdFile1();

    BOOL Open(CString);	//從Omd檔輸入資料
private:
	void iForm();
    BOOL isOldForm();  //判斷是不是Labview輸出的檔
//////////////////////////////////////////////////////////////////////////
//輸出
/*	  輸出有兩種方式      *
 *	    1. 輸出vector串   *
 *		2. 存成檔案進來   */
public:
	//輸出資料到記憶體
	//抓取各別資料串（依定義順序）
	//掛到某一串後面，或都生成原生串
	std::vector<Cartridge> AddMsrData(ColorType, PointNum, std::vector<Cartridge>& );
	std::vector<Cartridge> AddMsrData(ColorType clrtye, PointNum ptN);

    BOOL Save(CString);	//從Omd檔輸出資料
private:
	void oForm();
//////////////////////////////////////////////////////////////////////////
//其它資料存取函式
private:
    CString m_PnlID;
    CString m_MsrDvc;
    CString m_Prb;
    CString m_CHID;
    UINT    m_5nitsBkColor;

	std::vector<BOOL> isMsrChain;
	std::vector< std::vector<bool> > isMsrTalbe;
/*
  把每一個table裡的東西用指標指出來
  再另外去編輯

  另外，讓資料空白的儲存格做縮減的效果
  以達到動態編輯的假像！XD
 */

    std::vector<Cartridge>* p_vciData; //量測資料的記憶體空間
	std::vector<CString>    m_vStrIndex;  //量測項目的名字
public:	
    CString GetPnlID()  const;   void SetPnlID(CString);
    CString GetMsrDvc() const;   void SetMsrDvc(CString);
    CString GetPrb()    const;   void SetPrb(CString);
    CString GetCHID()   const;   void SetCHID(CString);

	//字串目錄
	CString GetIndex(UINT) const;    BOOL SetIndex();
	UINT    GetIdxNum()    const;

	//找是不是有量測值
	BOOL IsMsr(ColorType , PointNum , isMsrValue );  //	可以直接對vector做動作，找是不是有值，沒有的話回傳NULL
	BOOL IsMsr(ColorType , PointNum);                // 只管項目是不是有值
	
private:
	//對著彈鍊找
    std::vector<Cartridge>::size_type SubNum(ColorType clr, PointNum Big, UINT Little) const;
};

#endif // !defined(AFX_OMDFILE1_H__5E9E8D8E_4BB9_40C8_BEE3_2756DA9A7E76__INCLUDED_)
