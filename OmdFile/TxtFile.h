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
	CStdioFile f_Std;
	TxtStrData D_Txt;
public:
    CTxtFile();
    virtual ~CTxtFile();
    virtual BOOL Open(CString, CFileException&);
    virtual BOOL Save(CString, CFileException&);

	void Close(){ f_Std.Close(); };

	void iTxtData(TxtStrData& data){ D_Txt = data; MemToFile(); };
	void oTxtData(TxtStrData& data){ FileToMem(); data = D_Txt; };
	TxtStrData oTxtData(){ FileToMem(); return D_Txt; };
private:
	void FileToMem();
	void MemToFile();
	void ErrorMsg(CFileException&);
};

#endif // !defined(AFX_TXTFILE_H__E577A7EE_A364_4A73_8E30_C42DDB851DED__INCLUDED_)
