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

    EnableAutomation();
    AfxOleLockApp();
}

CColorEyeIDoc::~CColorEyeIDoc()
{
    AfxOleUnlockApp();
}

BOOL CColorEyeIDoc::OnNewDocument()
{
    if (!CDocument::OnNewDocument())
        return FALSE;

    // TODO: add reinitialization code here
    // (SDI documents will reuse this document)
    //第一次執行時會執行這個
    NewOmdData();
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
    //開新檔案
    SetPathName(" ");        
    delete f_Omd;
    NewOmdData();          //叫新的Omd
	UpdateAllViews(NULL);  //更新畫面
}

void CColorEyeIDoc::OnFileOpen() 
{
    // TODO: Add your command handler code here
    CFileDialog aFileDialog (TRUE, NULL, NULL, OFN_SHAREAWARE | OFN_OVERWRITEPROMPT, m_strFilter);
    
    int nID = aFileDialog.DoModal();
    if (nID == IDOK)
    {
        RestructureVector();
        if(f_Omd->Open(aFileDialog.GetPathName()))
        {
            SetPathName(aFileDialog.GetPathName());
            SetTitle(aFileDialog.GetFileName());
        }
    }
    UpdateAllViews(NULL);
}

void CColorEyeIDoc::OnFileSaveAs() 
{
    // TODO: Add your command handler code here
    CFileDialog fSaveDlg (FALSE, "omd", "*.omd", OFN_SHAREAWARE, m_strFilter);  //存檔會自己加副檔名

    int nID = fSaveDlg.DoModal();
    if (nID == IDOK)
    {
		SetModifiedFlag(FALSE);
        RestructureVector();
        if (f_Omd->Save(fSaveDlg.GetPathName()))
        {
            SetPathName(fSaveDlg.GetPathName());
            SetTitle(fSaveDlg.GetFileName());
        }
    }
    DebugByTxt();
}

void CColorEyeIDoc::OnFileSave() 
{
    // TODO: Add your command handler code here
    if (vChain1.IsEmpty())            //若還沒有存過的檔
        OnFileSaveAs();          //就另存新檔
    else
	{
		SetModifiedFlag(FALSE);
        f_Omd->Save(GetPathName());
	}
}

COmdFile1& CColorEyeIDoc::GetOmdFile()
{
    return *f_Omd;
}

CDataChain& CColorEyeIDoc::GetVector()
{
    return vChain2;
}

void CColorEyeIDoc::RestructureVector()
{
	vChain1.RemoveEqualCell(vChain2);
    f_Omd->SetMsrData(vChain1);
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
    SetTitle("新的Omd檔");
    vChain1.Empty();          //清空記憶體空間vChain1
    f_Omd = new COmdFile1;    //新增Omd檔（刪掉會開不了）
	SetModifiedFlag(TRUE);
}

void CColorEyeIDoc::DebugByTxt()
{
    std::vector<CString> vStr;
    CString str;

    str.IsEmpty();
    vStr.clear();
    str.Format("記憶體位址\t原始順序\t區域碼\t背景色碼\t第幾點\t量測點數\tLv\tx\ty\tdu\tdv\tT\tDuv\tX\tY\tZ\n");
    vStr.push_back(str);
    for (std::vector<Cartridge>::iterator iter = vChain1.Begin(); iter != vChain1.End(); ++iter)
    {                  
        str.Format("%x\t%d\t%d\t%d\t%d\t%d\t%f\t%f\t%f\t%f\t%f\t%d\t%f\t%f\t%f\t%f\n",\
            iter, iter->GetOrigSeqc(), iter->GetArea(), iter->GetBackColor(), iter->GetMsrFlowNo(), iter->GetMsrFlowNum(),\
            iter->GetLv(), iter->GetSx(), iter->GetSy(), iter->GetDu(), iter->GetDv(), iter->GetT(), iter->GetDuv(), iter->GetX(), iter->GetY(), iter->GetZ());
        vStr.push_back(str);
    }


    CStdioFile file;
    CFileException fx;

    CString path;
    path.Format("%s_debug.omd", GetPathName().Left(GetPathName().GetLength()-4));

    if (!file.Open(path, CFile::modeCreate | CFile::modeWrite | CFile::typeText, &fx))
    {
        TCHAR buf[255];
        fx.GetErrorMessage(buf, 255);
        CString strPrompt(buf);
        AfxMessageBox(strPrompt);
        file.Close();
    }
    else
    {
        if (!vStr.empty())
            for (std::vector<CString>::iterator it = vStr.begin(); it != vStr.end(); ++it)
                file.WriteString(it->GetBuffer(0));            

        file.Close();
    }
}

void CColorEyeIDoc::DebugByTxt(CString path)
{
    std::vector<CString> vStr;
    CString str;
    
    str.IsEmpty();
    vStr.clear();
    str.Format("記憶體位址\t原始順序\t區域碼\t背景色碼\t第幾點\t量測點數\tLv\tx\ty\tdu\tdv\tT\tDuv\tX\tY\tZ\n");
    vStr.push_back(str);
    for (std::vector<Cartridge>::iterator iter = vChain1.Begin(); iter != vChain1.End(); ++iter)
    {                  
        str.Format("%x\t%d\t%d\t%d\t%d\t%d\t%f\t%f\t%f\t%f\t%f\t%d\t%f\t%f\t%f\t%f\n",\
            iter, iter->GetOrigSeqc(), iter->GetArea(), iter->GetBackColor(), iter->GetMsrFlowNo(), iter->GetMsrFlowNum(),\
            iter->GetLv(), iter->GetSx(), iter->GetSy(), iter->GetDu(), iter->GetDv(), iter->GetT(), iter->GetDuv(), iter->GetX(), iter->GetY(), iter->GetZ());
        vStr.push_back(str);
    }
    
    
    CStdioFile file;
    CFileException fx;
    
    if (!file.Open(path, CFile::modeCreate | CFile::modeWrite | CFile::typeText, &fx))
    {
        TCHAR buf[255];
        fx.GetErrorMessage(buf, 255);
        CString strPrompt(buf);
        AfxMessageBox(strPrompt);
        file.Close();
    }
    else
    {
        if (!vStr.empty())
            for (std::vector<CString>::iterator it = vStr.begin(); it != vStr.end(); ++it)
                file.WriteString(it->GetBuffer(0));            
            
            file.Close();
    }
}


