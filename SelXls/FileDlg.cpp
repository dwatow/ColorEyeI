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
	//����{���ؿ��U��.xls���
	WIN32_FIND_DATA FindFileData;  //�@�ӵ��c�A��쪺�ɮ�
	HANDLE hListFile;
	CString strFilePath;      //�ɮשҦb���|
	CString strFilePathType;  //�n�䪺�ɮ�����+���|
	
	///�]�w�Ҧb�ؿ�
	GetCurrentDirectory(MAX_PATH, strFilePath.GetBuffer(0));  //��ثe�Ҧb���ؿ��]���|�^
	strFilePathType.Format("%s\\*.%s", strFilePath, FileNameExt);         //�ثe�����ɩҦb���|\*.xls
	hListFile = FindFirstFile(strFilePathType.GetBuffer(0), &FindFileData);
	
	if(hListFile == INVALID_HANDLE_VALUE)
	{
		//�䤣���ɮ�
		//strFilePathType�]�Τ���F�I������ܿ��~�T���a�I
		strFilePathType.Format("���~%d", GetLastError());
		MessageBox(strFilePathType);
		strFilePathType.Format("");
	}
	else
	{
		//��W���Excel�U�Ԧ���檺���
		vstrFilePath.clear();
		do
		{
			strFilePathType.Format("%s\\*.%s", strFilePath, FindFileData.cFileName);
			vstrFilePath.push_back(strFilePathType);
		}
		while(FindNextFile(hListFile, &FindFileData));
	}
	return (int)vstrFilePath.size();
    //�{���즹�����A�U�����O����
}

// int CFileDlg::GetCurFileList(CComboBox& ComboBox, CString FileNameExt)
// {
// 	//����{���ؿ��U��.xls���
// 	WIN32_FIND_DATA FindFileData;  //�@�ӵ��c�A��쪺�ɮ�
// 	HANDLE hListFile;
// 	
// 	CString strFilePath;      //�ɮשҦb���|
// 	CString strFilePathType;  //�n�䪺�ɮ�����+���|
// 	
// 	///�]�w�Ҧb�ؿ�
// 	GetCurrentDirectory(MAX_PATH, strFilePath.GetBuffer(0));  //��ثe�Ҧb���ؿ��]���|�^
// 	strFilePathType.Format("%s\\*.%s", strFilePath, FileNameExt);         //�ثe�����ɩҦb���|\*.xls
// 	
// 	//��Ĥ@���ɮ�
// 	hListFile = FindFirstFile(strFilePathType.GetBuffer(0), &FindFileData);
// 	
// 	ComboBox.AddString("null");
// 	if(hListFile == INVALID_HANDLE_VALUE)
// 	{
// 		//�䤣���ɮ�
// 		//strFilePathType�]�Τ���F�I������ܿ��~�T���a�I
// 		strFilePathType.Format("���~%d", GetLastError());
// 		MessageBox(strFilePathType);
// 		strFilePathType.Format("");
// 	}
// 	else
// 	{
// 		//��W���Excel�U�Ԧ���檺���
// 		ComboBox.ResetContent();
// 		ComboBox.AddString("RA HTOL Data Form");  //0
// 		do ComboBox.AddString(FindFileData.cFileName);
// 		while(FindNextFile(hListFile, &FindFileData));
// 	}
// 	ComboBox.SetCurSel(0);
// 	return ComboBox.GetCount();
//     //�{���즹�����A�U�����O����
// }

// int CFileDlg::GetCurFileList(CListBox& ListBox, CString FileNameExt)
// {
// 	//����{���ؿ��U��.xls���
// 	WIN32_FIND_DATA FindFileData;  //�@�ӵ��c�A��쪺�ɮ�
// 	HANDLE hListFile;
// 	
// 	CString strFilePath;      //�ɮשҦb���|
// 	CString strFilePathType;  //�n�䪺�ɮ�����+���|
// 	
// 	///�]�w�Ҧb�ؿ�
// 	GetCurrentDirectory(MAX_PATH, strFilePath.GetBuffer(0));  //��ثe�Ҧb���ؿ��]���|�^
// 	strFilePathType.Format("%s\\*.%s", strFilePath, FileNameExt);         //�ثe�����ɩҦb���|\*.xls
// 	
// 	//��Ĥ@���ɮ�
// 	hListFile = FindFirstFile(strFilePathType.GetBuffer(0), &FindFileData);
// 	
// 	ListBox.AddString("null");
// 	if(hListFile == INVALID_HANDLE_VALUE)
// 	{
// 		//�䤣���ɮ�
// 		//strFilePathType�]�Τ���F�I������ܿ��~�T���a�I
// 		strFilePathType.Format("���~%d", GetLastError());
// 		MessageBox(strFilePathType);
// 		strFilePathType.Format("");
// 	}
// 	else
// 	{
// 		//��W���Excel�U�Ԧ���檺���
// 		ListBox.ResetContent();
// 		ListBox.AddString("RA HTOL Data Form");  //0
// 		do ListBox.AddString(FindFileData.cFileName);
// 		while(FindNextFile(hListFile, &FindFileData));
// 		
// 		//�`��
// 		//         strFilePathType.Format("���~%d", m_cbxExcelSelor.GetCount());
// 		//         MessageBox(strFilePathType);
// 	}
// 	ListBox.SetCurSel(0);
// 
// 	return ListBox.GetCount();
// }

int CFileDlg::GetSelFileList(std::vector<CString>& vstrFilePath)
{
	// ���o�Ĥ@���ɮצW�٪���m �Y�S�����ܶǦ^NULL
	POSITION pos = GetStartPosition();
	if (pos) vstrFilePath.clear();
	while(pos != NULL)
		vstrFilePath.push_back(GetNextPathName(pos));// �z�L��m�Ө��o�ɮצW�� �ɮצW�٥]�t������|
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
