#if !defined(AFX_FILEDLG_H__CD6974FB_28BB_4F52_A586_1E6812E9FD60__INCLUDED_)
#define AFX_FILEDLG_H__CD6974FB_28BB_4F52_A586_1E6812E9FD60__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FileDlg.h : header file
//
#include <vector>
/////////////////////////////////////////////////////////////////////////////
// CFileDlg dialog

class CFileDlg : public CFileDialog
{
	CString szFileNameBuffer;
	DECLARE_DYNAMIC(CFileDlg)
public:
	CFileDlg(BOOL bOpenFileDialog, // TRUE for FileOpen, FALSE for FileSaveAs
	LPCTSTR lpszDefExt = NULL,
	LPCTSTR lpszFileName = NULL,
	DWORD dwFlags = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
	LPCTSTR lpszFilter = NULL,
	CWnd* pParentWnd = NULL);

protected:
	//{{AFX_MSG(CFileDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
//  	const int GetCurFileList(std::vector<CString>& vstrFilePath, const CString& FileNameExt);
	const int GetSelFileList(std::vector<CString>& vstrFilePath);
	void SetSelMultiFileTotal(const int&);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILEDLG_H__CD6974FB_28BB_4F52_A586_1E6812E9FD60__INCLUDED_)
