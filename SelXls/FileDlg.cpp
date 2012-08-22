// FileDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SelXls.h"
#include "FileDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFileDlg

IMPLEMENT_DYNAMIC(CFileDlg, CFileDialog)

CFileDlg::CFileDlg(BOOL bOpenFileDialog, LPCTSTR lpszDefExt, LPCTSTR lpszFileName,
		DWORD dwFlags, LPCTSTR lpszFilter, CWnd* pParentWnd) :
		CFileDialog(bOpenFileDialog, lpszDefExt, lpszFileName, dwFlags, lpszFilter, pParentWnd)
{

}


BEGIN_MESSAGE_MAP(CFileDlg, CFileDialog)
	//{{AFX_MSG_MAP(CFileDlg)
	ON_WM_CANCELMODE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

int CFileDlg::GetCurFileList(std::vector<CString>& vstrFilePath, CString FileNameExt)
{
	//抓取程式目錄下的.xls表格
	WIN32_FIND_DATA FindFileData;  //一個結構，找到的檔案
	HANDLE hListFile;
	CString strFilePath;      //檔案所在路徑
	CString strFilePathType;  //要找的檔案類型+路徑
	
	///設定所在目錄
	GetCurrentDirectory(MAX_PATH, strFilePath.GetBuffer(0));  //抓目前所在的目錄（路徑）
	strFilePathType.Format("%s\\*.%s", strFilePath, FileNameExt);         //目前執行檔所在路徑\*.xls
	hListFile = FindFirstFile(strFilePathType.GetBuffer(0), &FindFileData);
	
	if(hListFile == INVALID_HANDLE_VALUE)
	{
		//找不到檔案
		//strFilePathType也用不到了！拿來顯示錯誤訊息吧！
		strFilePathType.Format("錯誤%d", GetLastError());
		MessageBox(strFilePathType);
		strFilePathType.Format("");
	}
	else
	{
		//填上選擇Excel下拉式選單的資料
		vstrFilePath.clear();
		do
		{
			strFilePathType.Format("%s\\*.%s", strFilePath, FindFileData.cFileName);
			vstrFilePath.push_back(strFilePathType);
		}
		while(FindNextFile(hListFile, &FindFileData));
	}
	return (int)vstrFilePath.size();
    //程式到此結束，下面都是註解
}

// int CFileDlg::GetCurFileList(CComboBox& ComboBox, CString FileNameExt)
// {
// 	//抓取程式目錄下的.xls表格
// 	WIN32_FIND_DATA FindFileData;  //一個結構，找到的檔案
// 	HANDLE hListFile;
// 	
// 	CString strFilePath;      //檔案所在路徑
// 	CString strFilePathType;  //要找的檔案類型+路徑
// 	
// 	///設定所在目錄
// 	GetCurrentDirectory(MAX_PATH, strFilePath.GetBuffer(0));  //抓目前所在的目錄（路徑）
// 	strFilePathType.Format("%s\\*.%s", strFilePath, FileNameExt);         //目前執行檔所在路徑\*.xls
// 	
// 	//找第一個檔案
// 	hListFile = FindFirstFile(strFilePathType.GetBuffer(0), &FindFileData);
// 	
// 	ComboBox.AddString("null");
// 	if(hListFile == INVALID_HANDLE_VALUE)
// 	{
// 		//找不到檔案
// 		//strFilePathType也用不到了！拿來顯示錯誤訊息吧！
// 		strFilePathType.Format("錯誤%d", GetLastError());
// 		MessageBox(strFilePathType);
// 		strFilePathType.Format("");
// 	}
// 	else
// 	{
// 		//填上選擇Excel下拉式選單的資料
// 		ComboBox.ResetContent();
// 		ComboBox.AddString("RA HTOL Data Form");  //0
// 		do ComboBox.AddString(FindFileData.cFileName);
// 		while(FindNextFile(hListFile, &FindFileData));
// 	}
// 	ComboBox.SetCurSel(0);
// 	return ComboBox.GetCount();
//     //程式到此結束，下面都是註解
// }

// int CFileDlg::GetCurFileList(CListBox& ListBox, CString FileNameExt)
// {
// 	//抓取程式目錄下的.xls表格
// 	WIN32_FIND_DATA FindFileData;  //一個結構，找到的檔案
// 	HANDLE hListFile;
// 	
// 	CString strFilePath;      //檔案所在路徑
// 	CString strFilePathType;  //要找的檔案類型+路徑
// 	
// 	///設定所在目錄
// 	GetCurrentDirectory(MAX_PATH, strFilePath.GetBuffer(0));  //抓目前所在的目錄（路徑）
// 	strFilePathType.Format("%s\\*.%s", strFilePath, FileNameExt);         //目前執行檔所在路徑\*.xls
// 	
// 	//找第一個檔案
// 	hListFile = FindFirstFile(strFilePathType.GetBuffer(0), &FindFileData);
// 	
// 	ListBox.AddString("null");
// 	if(hListFile == INVALID_HANDLE_VALUE)
// 	{
// 		//找不到檔案
// 		//strFilePathType也用不到了！拿來顯示錯誤訊息吧！
// 		strFilePathType.Format("錯誤%d", GetLastError());
// 		MessageBox(strFilePathType);
// 		strFilePathType.Format("");
// 	}
// 	else
// 	{
// 		//填上選擇Excel下拉式選單的資料
// 		ListBox.ResetContent();
// 		ListBox.AddString("RA HTOL Data Form");  //0
// 		do ListBox.AddString(FindFileData.cFileName);
// 		while(FindNextFile(hListFile, &FindFileData));
// 		
// 		//總數
// 		//         strFilePathType.Format("錯誤%d", m_cbxExcelSelor.GetCount());
// 		//         MessageBox(strFilePathType);
// 	}
// 	ListBox.SetCurSel(0);
// 
// 	return ListBox.GetCount();
// }

int CFileDlg::GetSelFileList(std::vector<CString>& vstrFilePath)
{
	// 取得第一個檔案名稱的位置 若沒有的話傳回NULL
	POSITION pos = GetStartPosition();
	if (pos) vstrFilePath.clear();
	while(pos != NULL)
		vstrFilePath.push_back(GetNextPathName(pos));// 透過位置來取得檔案名稱 檔案名稱包含完整路徑
	return (int)vstrFilePath.size();
}

void CFileDlg::SetMultiFileNameBuffer(const int FileMaxBuffer)
{
	const int BufferSize = (FileMaxBuffer * (MAX_PATH + 1)) + 1;
	m_ofn.nMaxFile = BufferSize;
	m_ofn.lpstrFile = szFileNameBuffer.GetBuffer(BufferSize);
	szFileNameBuffer.ReleaseBuffer();
	m_ofn.lpstrFile[0] = NULL;
}

BOOL CFileDlg::OnInitDialog() 
{
	CFileDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
