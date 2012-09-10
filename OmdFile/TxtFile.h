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
	CString m_filepath;
public:
	CString GetFilePathName() const{ return m_filepath; };  //for Omdfile
public:
    CTxtFile();
    virtual ~CTxtFile();
    virtual BOOL Open(CString);
    virtual BOOL Save(CString);

    BOOL LoadData(TxtStrData&);
    BOOL SaveData(TxtStrData&);

private:
	void FileToMem(CStdioFile& file, TxtStrData& dTxt);
	void MemToFile(TxtStrData& dTxt, CStdioFile& file);
	void ErrorMsg(CFileException&);
};

#endif // !defined(AFX_TXTFILE_H__E577A7EE_A364_4A73_8E30_C42DDB851DED__INCLUDED_)
