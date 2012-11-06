// TxtFile.h: interface for the CTxtFile class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TXTFILE_H__E577A7EE_A364_4A73_8E30_C42DDB851DED__INCLUDED_)
#define AFX_TXTFILE_H__E577A7EE_A364_4A73_8E30_C42DDB851DED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <vector>

typedef std::vector<CString> TxtStrData;

class CTxtFile  
{
	CStdioFile ftxt_Std;
	TxtStrData dtxt_Txt;

public:
    CTxtFile(){};
    virtual ~CTxtFile(){};
    BOOL Open(CString, CFileException&);
    BOOL Save(CString, CFileException&);

	void Close(){ ftxt_Std.Close(); };

	void iTxtData(TxtStrData& data){ dtxt_Txt = data; MemToFile(); };
	void oTxtData(TxtStrData& data){ FileToMem(); data = dtxt_Txt; };
	TxtStrData oTxtData(){ FileToMem(); return dtxt_Txt; };

private:
	void FileToMem();
	void MemToFile();
	void ErrorMsg(CFileException&);
};

#endif // !defined(AFX_TXTFILE_H__E577A7EE_A364_4A73_8E30_C42DDB851DED__INCLUDED_)
