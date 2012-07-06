// TxtFile.h: interface for the CTxtFile class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TXTFILE_H__E577A7EE_A364_4A73_8E30_C42DDB851DED__INCLUDED_)
#define AFX_TXTFILE_H__E577A7EE_A364_4A73_8E30_C42DDB851DED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <vector>

class CTxtFile  
{
	UINT m_LineNum;
	std::vector<CString> vStr;
protected:
	CString GetCell(TCHAR, UINT);	//介面程式段
	CString GetCell(PTCHAR, UINT);	//介面程式段
public:
	CTxtFile();
	virtual ~CTxtFile();
	virtual BOOL Open(CString);
	virtual BOOL Save(CString);
	CString GetLine(UINT Num);		//取得第幾行（從1開始）
	std::vector<CString>::size_type SetLine(CString& );
	void Clear();
	UINT GetLineNum();
private:
	BOOL LoadData(CStdioFile &infile);
	BOOL SaveData(CStdioFile &infile);
	CString GetCell(UINT, UINT);	//取得第幾個字
};

#endif // !defined(AFX_TXTFILE_H__E577A7EE_A364_4A73_8E30_C42DDB851DED__INCLUDED_)
