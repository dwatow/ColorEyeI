<<<<<<< HEAD
// ColorEyeIDoc.cpp : implementation of the CColorEyeIDoc class
//

#include "stdafx.h"
#include "ColorEyeI.h"
#include "ColorEyeIDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CColorEyeIDoc

IMPLEMENT_DYNCREATE(CColorEyeIDoc, CDocument)

BEGIN_MESSAGE_MAP(CColorEyeIDoc, CDocument)
	//{{AFX_MSG_MAP(CColorEyeIDoc)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_COMMAND(ID_FILE_NEW, OnFileNew)
	ON_COMMAND(ID_FILE_SAVE_AS, OnFileSaveAs)
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_UPDATE_COMMAND_UI(ID_FILE_SAVE, OnUpdateFileSave)
	ON_COMMAND(ID_MSR_ITEM, OnMsrItem)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CColorEyeIDoc, CDocument)
	//{{AFX_DISPATCH_MAP(CColorEyeIDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//      DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IColorEyeI to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {103A7CC5-072F-4C0A-9681-F1B5DF57C9E1}
static const IID IID_IColorEyeI =
{ 0x103a7cc5, 0x72f, 0x4c0a, { 0x96, 0x81, 0xf1, 0xb5, 0xdf, 0x57, 0xc9, 0xe1 } };

BEGIN_INTERFACE_MAP(CColorEyeIDoc, CDocument)
	INTERFACE_PART(CColorEyeIDoc, IID_IColorEyeI, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CColorEyeIDoc construction/destruction

CColorEyeIDoc::CColorEyeIDoc():
m_strFilter("OrigMsrData Files (*.omd)|*.omd|Text File(*.txt)|*.txt|All Files (*.*)|*.* ||")//檔案過濾條件

{
	// TODO: add one-time construction code here
// 	vChain1.clear();
// 	Cartridge X;
// 	vChain1.push_back(X);
// 	
// 	Cartridge W1  (White, Pn1 );
// 	Cartridge R1  (Red  , Pn1 );
// 	Cartridge G1  (Green, Pn1 );
// 	Cartridge B1  (Blue , Pn1 );
// 	Cartridge W9  (White, Pn9 );
// 	Cartridge W49 (White, Pn49);
// 	Cartridge nits(Nits , Pn9 );
// 	Cartridge D9  (Dark , Pn9 );
// 	Cartridge D25 (Dark , Pn25);
// 	
// 	m_SimPtnDlg.Partition(vChain1, W1);
// 	m_SimPtnDlg.Partition(vChain1, R1);
// 	m_SimPtnDlg.Partition(vChain1, G1);
// 	m_SimPtnDlg.Partition(vChain1, B1);
// 	
// 	m_SimPtnDlg.Partition(vChain1, W9);
// 	m_SimPtnDlg.Partition(vChain1, nits);
// 	m_SimPtnDlg.Partition(vChain1, D9);
// 	m_SimPtnDlg.Partition(vChain1, D25);
// 	m_SimPtnDlg.Partition(vChain1, W49);
	NewOmdData();
//	FileLoad = FALSE;

	EnableAutomation();
	AfxOleLockApp();
}

CColorEyeIDoc::~CColorEyeIDoc()
{
//	AfxMessageBox("關閉文件");
//	aFile.Close();
	AfxOleUnlockApp();
}

BOOL CColorEyeIDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CColorEyeIDoc serialization

void CColorEyeIDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CColorEyeIDoc diagnostics

#ifdef _DEBUG
void CColorEyeIDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CColorEyeIDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CColorEyeIDoc commands

void CColorEyeIDoc::OnFileNew() 
{
	// TODO: Add your command handler code here
 	CMainFrame * pWnd = static_cast<CMainFrame*>(AfxGetMainWnd());
 	ASSERT_VALID(pWnd);

	pWnd->UpdateFrameTitleForDocument("未命名原始量測資料");

	delete f_Omd;  //釋放舊的記憶體空間
	NewOmdData();  //叫新的Omd
	m_OmdFilePath.Empty();

	UpdateAllViews(NULL);  //更新畫面
}

void CColorEyeIDoc::OnFileOpen() 
{
	// TODO: Add your command handler code here
	CMainFrame * pWnd = static_cast<CMainFrame*>(AfxGetMainWnd());
	ASSERT_VALID(pWnd);

// 	CString strTemp;
// 	strTemp.Format("%x", pWnd);
// 	AfxMessageBox(strTemp);

	CFileDialog aFileDialog (TRUE, NULL, NULL, OFN_SHAREAWARE | OFN_OVERWRITEPROMPT, m_strFilter);
	
	int nID = aFileDialog.DoModal();
	if (nID == IDOK)
	{
		if(f_Omd->Open(aFileDialog.GetPathName()))
			m_OmdFilePath.Format("%s", aFileDialog.GetPathName());
		if (pWnd)
			pWnd->UpdateFrameTitleForDocument(aFileDialog.GetFileTitle());
	}

	UpdateAllViews(NULL);
}

void CColorEyeIDoc::OnFileSaveAs() 
{
	// TODO: Add your command handler code here
	CFileDialog fSaveDlg (TRUE, "omd", "*.omd", OFN_SHAREAWARE, m_strFilter);

	int nID = fSaveDlg.DoModal();
	if (nID == IDOK)
		f_Omd->Save(fSaveDlg.GetPathName()); 
}

void CColorEyeIDoc::OnFileSave() 
{
	// TODO: Add your command handler code here
	if (!m_OmdFilePath.IsEmpty())
		f_Omd->Save(m_OmdFilePath);
}

void CColorEyeIDoc::OnUpdateFileSave(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	//SetModifiedFlag()
	pCmdUI->Enable(!m_OmdFilePath.IsEmpty());
}

COmdFile1 CColorEyeIDoc::GetOmdFile()
{
	return *f_Omd;
}

BOOL CColorEyeIDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
	
	// TODO: Add your specialized creation code here
	AfxMessageBox("OnOpenDocument(LPCTSTR lpszPathName)");

	return TRUE;
}

void CColorEyeIDoc::NewOmdData()
{
	m_OmdFilePath.Empty();               //清空檔案路徑
	SetModifiedFlag();                 //文件已被更改是否要存檔

	vChain1.clear();                   //清空記憶體空間vChain1
	Cartridge X;
	vChain1.push_back(X);              //第一個就是什麼都沒有
	


	f_Omd = new COmdFile1(vChain1);    //新增Omd檔（刪掉會開不了）
}





void CColorEyeIDoc::OnMsrItem() 
{
	// TODO: Add your command handler code here
	Cartridge W1  (White, Pn1 );
	Cartridge R1  (Red  , Pn1 );
	Cartridge G1  (Green, Pn1 );
	Cartridge B1  (Blue , Pn1 );
	Cartridge W9  (White, Pn9 );
	Cartridge W49 (White, Pn49);
	Cartridge W5  (White, Pn5 );
	Cartridge nits(Nits , Pn9 );
	Cartridge D9  (Dark , Pn9 );
	Cartridge D25 (Dark , Pn25);
	//Cartridge Crstlk(crosstalk, )
	
	m_SimPtnDlg.Partition(vChain1, W1);
	m_SimPtnDlg.Partition(vChain1, R1);
	m_SimPtnDlg.Partition(vChain1, G1);
	m_SimPtnDlg.Partition(vChain1, B1);
	
	m_SimPtnDlg.Partition(vChain1, W9);
	m_SimPtnDlg.Partition(vChain1, nits);
	m_SimPtnDlg.Partition(vChain1, D9);
	m_SimPtnDlg.Partition(vChain1, D25);
	m_SimPtnDlg.Partition(vChain1, W49);
}
=======
// ColorEyeIDoc.cpp : implementation of the CColorEyeIDoc class
//

#include "stdafx.h"
#include "ColorEyeI.h"
#include "ColorEyeIDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CColorEyeIDoc

IMPLEMENT_DYNCREATE(CColorEyeIDoc, CDocument)

BEGIN_MESSAGE_MAP(CColorEyeIDoc, CDocument)
	//{{AFX_MSG_MAP(CColorEyeIDoc)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_COMMAND(ID_FILE_NEW, OnFileNew)
	ON_COMMAND(ID_FILE_SAVE_AS, OnFileSaveAs)
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_UPDATE_COMMAND_UI(ID_FILE_SAVE, OnUpdateFileSave)
	ON_COMMAND(ID_MSR_ITEM, OnMsrItem)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CColorEyeIDoc, CDocument)
	//{{AFX_DISPATCH_MAP(CColorEyeIDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//      DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IColorEyeI to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {103A7CC5-072F-4C0A-9681-F1B5DF57C9E1}
static const IID IID_IColorEyeI =
{ 0x103a7cc5, 0x72f, 0x4c0a, { 0x96, 0x81, 0xf1, 0xb5, 0xdf, 0x57, 0xc9, 0xe1 } };

BEGIN_INTERFACE_MAP(CColorEyeIDoc, CDocument)
	INTERFACE_PART(CColorEyeIDoc, IID_IColorEyeI, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CColorEyeIDoc construction/destruction

CColorEyeIDoc::CColorEyeIDoc():
m_strFilter("OrigMsrData Files (*.omd)|*.omd|Text File(*.txt)|*.txt|All Files (*.*)|*.* ||")//檔案過濾條件

{
	// TODO: add one-time construction code here
// 	vChain1.clear();
// 	Cartridge X;
// 	vChain1.push_back(X);
// 	
// 	Cartridge W1  (White, Pn1 );
// 	Cartridge R1  (Red  , Pn1 );
// 	Cartridge G1  (Green, Pn1 );
// 	Cartridge B1  (Blue , Pn1 );
// 	Cartridge W9  (White, Pn9 );
// 	Cartridge W49 (White, Pn49);
// 	Cartridge nits(Nits , Pn9 );
// 	Cartridge D9  (Dark , Pn9 );
// 	Cartridge D25 (Dark , Pn25);
// 	
// 	m_SimPtnDlg.Partition(vChain1, W1);
// 	m_SimPtnDlg.Partition(vChain1, R1);
// 	m_SimPtnDlg.Partition(vChain1, G1);
// 	m_SimPtnDlg.Partition(vChain1, B1);
// 	
// 	m_SimPtnDlg.Partition(vChain1, W9);
// 	m_SimPtnDlg.Partition(vChain1, nits);
// 	m_SimPtnDlg.Partition(vChain1, D9);
// 	m_SimPtnDlg.Partition(vChain1, D25);
// 	m_SimPtnDlg.Partition(vChain1, W49);
	NewOmdData();
//	FileLoad = FALSE;

	EnableAutomation();
	AfxOleLockApp();
}

CColorEyeIDoc::~CColorEyeIDoc()
{
//	AfxMessageBox("關閉文件");
//	aFile.Close();
	AfxOleUnlockApp();
}

BOOL CColorEyeIDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CColorEyeIDoc serialization

void CColorEyeIDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CColorEyeIDoc diagnostics

#ifdef _DEBUG
void CColorEyeIDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CColorEyeIDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CColorEyeIDoc commands

void CColorEyeIDoc::OnFileNew() 
{
	// TODO: Add your command handler code here
 	CMainFrame * pWnd = static_cast<CMainFrame*>(AfxGetMainWnd());
 	ASSERT_VALID(pWnd);

	pWnd->UpdateFrameTitleForDocument("未命名原始量測資料");

	delete f_Omd;  //釋放舊的記憶體空間
	NewOmdData();  //叫新的Omd
	m_OmdFilePath.Empty();

	UpdateAllViews(NULL);  //更新畫面
}

void CColorEyeIDoc::OnFileOpen() 
{
	// TODO: Add your command handler code here
	CMainFrame * pWnd = static_cast<CMainFrame*>(AfxGetMainWnd());
	ASSERT_VALID(pWnd);

// 	CString strTemp;
// 	strTemp.Format("%x", pWnd);
// 	AfxMessageBox(strTemp);

	CFileDialog aFileDialog (TRUE, NULL, NULL, OFN_SHAREAWARE | OFN_OVERWRITEPROMPT, m_strFilter);
	
	int nID = aFileDialog.DoModal();
	if (nID == IDOK)
	{
		if(f_Omd->Open(aFileDialog.GetPathName()))
			m_OmdFilePath.Format("%s", aFileDialog.GetPathName());
		if (pWnd)
			pWnd->UpdateFrameTitleForDocument(aFileDialog.GetFileTitle());
	}

	UpdateAllViews(NULL);
}

void CColorEyeIDoc::OnFileSaveAs() 
{
	// TODO: Add your command handler code here
	CFileDialog fSaveDlg (TRUE, "omd", "*.omd", OFN_SHAREAWARE, m_strFilter);

	int nID = fSaveDlg.DoModal();
	if (nID == IDOK)
		f_Omd->Save(fSaveDlg.GetPathName()); 
}

void CColorEyeIDoc::OnFileSave() 
{
	// TODO: Add your command handler code here
	if (!m_OmdFilePath.IsEmpty())
		f_Omd->Save(m_OmdFilePath);
}

void CColorEyeIDoc::OnUpdateFileSave(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	//SetModifiedFlag()
	pCmdUI->Enable(!m_OmdFilePath.IsEmpty());
}

COmdFile1 CColorEyeIDoc::GetOmdFile()
{
	return *f_Omd;
}

BOOL CColorEyeIDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
	
	// TODO: Add your specialized creation code here
	AfxMessageBox("OnOpenDocument(LPCTSTR lpszPathName)");

	return TRUE;
}

void CColorEyeIDoc::NewOmdData()
{
	m_OmdFilePath.Empty();               //清空檔案路徑
	SetModifiedFlag();                 //文件已被更改是否要存檔

	vChain1.clear();                   //清空記憶體空間vChain1
	Cartridge X;
	vChain1.push_back(X);              //第一個就是什麼都沒有
	


	f_Omd = new COmdFile1(vChain1);    //新增Omd檔（刪掉會開不了）
}





void CColorEyeIDoc::OnMsrItem() 
{
	// TODO: Add your command handler code here
	Cartridge W1  (White, Pn1 );
	Cartridge R1  (Red  , Pn1 );
	Cartridge G1  (Green, Pn1 );
	Cartridge B1  (Blue , Pn1 );
	Cartridge W9  (White, Pn9 );
	Cartridge W49 (White, Pn49);
	Cartridge W5  (White, Pn5 );
	Cartridge nits(Nits , Pn9 );
	Cartridge D9  (Dark , Pn9 );
	Cartridge D25 (Dark , Pn25);
	//Cartridge Crstlk(crosstalk, )
	
	m_SimPtnDlg.Partition(vChain1, W1);
	m_SimPtnDlg.Partition(vChain1, R1);
	m_SimPtnDlg.Partition(vChain1, G1);
	m_SimPtnDlg.Partition(vChain1, B1);
	
	m_SimPtnDlg.Partition(vChain1, W9);
	m_SimPtnDlg.Partition(vChain1, nits);
	m_SimPtnDlg.Partition(vChain1, D9);
	m_SimPtnDlg.Partition(vChain1, D25);
	m_SimPtnDlg.Partition(vChain1, W49);
}
>>>>>>> b5425c75ef070be7770a30afe5b503213bd2584b
