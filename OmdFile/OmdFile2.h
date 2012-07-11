// OmdFile1.h: interface for the COmdFile class.
//
//////////////////////////////////////////////////////////////////////
#include <vector>
#include "TxtFile.h"
#include "../xMsrPoint/Cartridge.h"

#if !defined(AFX_OMDFILE1_H__5E9E8D8E_4BB9_40C8_BEE3_2756DA9A7E76__INCLUDED_)
#define AFX_OMDFILE1_H__5E9E8D8E_4BB9_40C8_BEE3_2756DA9A7E76__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class COmdFile1 : public CTxtFile
{
    CString m_PnlID;
    CString m_MsrDvc;
    CString m_Prb;
    CString m_CHID;
    UINT    m_5nitsBkColor;

    std::vector<Cartridge>* p_vciData;
	std::vector<CString> m_vStrIndex;

//	UINT m_PontDataNum;

//    CString m_index;
public:
    COmdFile1(std::vector<Cartridge>&); //開新檔案，並且丟入Data
    COmdFile1();
    virtual ~COmdFile1();

    BOOL Open(CString);
    BOOL Save(CString);
	
    CString GetPnlID()  const;   void SetPnlID(CString);
    CString GetMsrDvc() const;   void SetMsrDvc(CString);
    CString GetPrb()    const;   void SetPrb(CString);
    CString GetCHID()   const;   void SetCHID(CString);

	CString GetIndex(UINT) const;    BOOL SetIndex();
	UINT    GetIdxNum() const;

private:
	void iForm();
	void oForm();
    BOOL isOldForm();
    std::vector<Cartridge>::size_type SubNum(ColorType clr, PointNum Big, UINT Little) const;
};

#endif // !defined(AFX_OMDFILE1_H__5E9E8D8E_4BB9_40C8_BEE3_2756DA9A7E76__INCLUDED_)
