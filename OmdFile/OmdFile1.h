// OmdFile1.h: interface for the COmdFile class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OMDFILE1_H__5E9E8D8E_4BB9_40C8_BEE3_2756DA9A7E76__INCLUDED_)
#define AFX_OMDFILE1_H__5E9E8D8E_4BB9_40C8_BEE3_2756DA9A7E76__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TxtFile.h"
//#include "../xMsrPoint/Cartridge.h"
#include "../DataChain.h"
#include <vector>
#include <iterator>
#include "../xMsrPoint/Bolt.h"

//typedef std::vector<Cartridge> OmdValueData;
typedef CDataChain OmdValueData;

class COmdFile1// : public CTxtFile
{
	//CTxtFile f_Txt;  //為了要它的路徑，才放class的全域。
	CString m_filepath;
	TxtStrData D_Txt;

	CString m_PnlID;
    CString m_MsrDvc;
    CString m_Prb;
    CString m_CHID;
	
public:
    CString GetPnlID () const { return m_PnlID;  };
    CString GetMsrDvc() const { return m_MsrDvc; };
    CString GetPrb   () const { return m_Prb;    };
    CString GetCHID  () const { return m_CHID;   };
	
	void SetPnlID  (CString& _S) { m_PnlID  =  _S; };
	void SetMsrDvc (CString& _S) { m_MsrDvc =  _S; };
    void SetPrb    (CString& _S) { m_Prb    =  _S; };
    void SetCHID   (CString& _S) { m_CHID   =  _S; };

public:
    COmdFile1();
    BOOL Open(CString path);
    BOOL Save(CString path);
    
	BOOL LoadData(OmdValueData&);
    BOOL SaveData(OmdValueData&);

// 	void iForm(OmdValueData&);
//     void oForm(OmdValueData&);

private:
	BOOL isOldForm() { return (D_Txt.at(0).Find(':') != -1) ? TRUE : FALSE; };  //判斷是不是Labview輸出的檔
	
	void TxtToOmd(TxtStrData& dTxt, OmdValueData& dOmd);
	void OmdToTxt(OmdValueData& dOmd, TxtStrData& dTxt);
	void ErrorMsg(CFileException& fx);

	CString GetLine(UINT LineNum);	
	CString GetCell(UINT Word, UINT Line);
	CString GetCell(TCHAR c, UINT n);   // 0< c<=24
	CString GetCell(PTCHAR c, UINT n);  //25<=c，從AA開始算

};

#endif // !defined(AFX_OMDFILE1_H__5E9E8D8E_4BB9_40C8_BEE3_2756DA9A7E76__INCLUDED_)
