// ColorEyeIDoc.cpp : implementation of the CColorEyeIDoc class
//

#include "stdafx.h"
#include "ColorEyeI.h"
#include "ColorEyeIDoc.h"

#include "FileDlg.h"

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

CColorEyeIDoc::CColorEyeIDoc()
{
    // TODO: add one-time construction code here

    EnableAutomation();
    AfxOleLockApp();
}

CColorEyeIDoc::~CColorEyeIDoc()
{
    AfxOleUnlockApp();
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
#endif

/////////////////////////////////////////////////////////////////////////////
// CColorEyeIDoc commands

void CColorEyeIDoc::OnFileNew() 
{
    // TODO: Add your command handler code here
    //開新檔案
    CDocument::OnNewDocument();    //開新檔後的存檔，判斷它是不是空字串，決定要不要SaveAs
    SetTitle("新的Omd檔");
    m_docFileHead.Empty();
    m_docDNA.Empty();
    m_docRNA.Empty();
    
    SetModifiedFlag(FALSE);
    UpdateAllViews(NULL);  //更新畫面
}

BOOL CColorEyeIDoc::OnNewDocument()
{
    if (!CDocument::OnNewDocument())
        return FALSE;
    
    // TODO: add reinitialization code here
    // (SDI documents will reuse this document)
    //第一次執行時會執行這個

    CColorEyeIDoc::OnFileNew();
    return TRUE;
}

BOOL CColorEyeIDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
    if (!CDocument::OnOpenDocument(lpszPathName))
        return FALSE;    
    // TODO: Add your specialized creation code here
    //點兩下會執行這個
    OnNewDocument();
//     OpenOmdFile(lpszPathName);
    SetPathName(lpszPathName);
    SetTitle(lpszPathName);
    SetModifiedFlag(FALSE);    

    UpdateAllViews(NULL);  //更新畫面
    return TRUE;
}
//////////////////////////////////////////////////////////////////////////
// Txt and Omd file process

//////////////////////////////////////////////////////////////////////////
void CColorEyeIDoc::OnFileOpen() 
{
    // TODO: Add your command handler code here
//   openTxtDlg("Text File(*.txt)|*.txt|All Files (*.*)|*.* ||");
    openOmdDlg("OrigMsrData Files (*.omd)|*.omd|Text File(*.txt)|*.txt|All Files (*.*)|*.* ||");
}

void CColorEyeIDoc::OnFileSaveAs() 
{
    // TODO: Add your command handler code here
//   saveTxtDlg("Text File(*.txt)|*.txt|All Files (*.*)|*.* ||");
    saveOmdDlg("OrigMsrData Files (*.omd)|*.omd|Text File(*.txt)|*.txt|All Files (*.*)|*.* ||");
}
//////////////////////////////////////////////////////////////////////////
void CColorEyeIDoc::openTxtDlg(LPCTSTR FileFilter)
{
    CFileDlg aFileDialog (TRUE, "txt", "*.txt", OFN_SHAREAWARE | OFN_OVERWRITEPROMPT, FileFilter);
    
    int nID = aFileDialog.DoModal();
    if (nID == IDOK)
    {
        m_docDNA.Empty();
        m_docRNA.Empty();
        m_docFileHead.Empty();
        SetModifiedFlag(FALSE);
        UpdateAllViews(NULL);

        openTxtFile(aFileDialog.GetPathName());    
        SetPathName(aFileDialog.GetPathName());
        SetTitle(aFileDialog.GetFileName());
    }
}

void CColorEyeIDoc::saveTxtDlg(LPCTSTR FileFilter)
{
    CFileDlg aFileDialog (FALSE, "txt", "*.txt", OFN_SHAREAWARE, FileFilter);
    
    int nID = aFileDialog.DoModal();
    if (nID == IDOK)
    {
        saveTxtFile(aFileDialog.GetPathName());
        SetPathName(aFileDialog.GetPathName());
        SetTitle(aFileDialog.GetFileName());
    
        SetModifiedFlag(FALSE);
    }        
}

void CColorEyeIDoc::openTxtFile(LPCTSTR FilePathName)
{
    CTxtFile f_txt;
    if(!f_txt.Open(FilePathName, m_ErrorFx))
        AfxMessageBox("檔案開啟錯誤!!");
    else
    {
        f_txt.oTxtData(m_TextData);
        f_txt.Close();
    }
}

void CColorEyeIDoc::saveTxtFile(LPCTSTR FilePathName)
{
    CTxtFile f_txt;
    if (!f_txt.Save(FilePathName, m_ErrorFx))
        AfxMessageBox("路徑有問題!!!");
    else 
    {
        f_txt.iTxtData(m_TextData);
        f_txt.Close();
    }
}
//////////////////////////////////////////////////////////////////////////
void CColorEyeIDoc::openOmdDlg(LPCTSTR FileFilter)
{
    CFileDialog aFileDialog (TRUE, NULL, NULL, OFN_SHAREAWARE | OFN_OVERWRITEPROMPT, FileFilter);
    
    int nID = aFileDialog.DoModal();
    if (nID == IDOK)
    {
        m_docDNA.Empty();
        m_docRNA.Empty();
        m_docFileHead.Empty();

        openOmdFile(aFileDialog.GetPathName());
        SetPathName(aFileDialog.GetPathName());
        SetTitle(aFileDialog.GetFileName());

        SetModifiedFlag(FALSE);
        UpdateAllViews(NULL);
   }
}

void CColorEyeIDoc::saveOmdDlg(LPCTSTR FileFilter)
{
    CFileDialog aFileDialog (FALSE, "omd", "*.omd", OFN_SHAREAWARE, FileFilter);
    
    int nID = aFileDialog.DoModal();
    if (nID == IDOK)
    {
        saveOmdFile(aFileDialog.GetPathName());
        debugByTxt(aFileDialog.GetPathName());

        SetPathName(aFileDialog.GetPathName());
        SetTitle(aFileDialog.GetFileName());
    
        SetModifiedFlag(FALSE);
    }
}

void CColorEyeIDoc::openOmdFile(LPCTSTR FilePathName)
{
    BeginWaitCursor();

    COmdFile0 ft_Omd;

    if(!ft_Omd.Open(FilePathName, m_ErrorFx))
        AfxMessageBox("路徑有問題");
    else 
    {
        m_docRNA = ft_Omd.oOmdData();
        m_docFileHead = ft_Omd.GetFileHead();

        ft_Omd.Close();
    }
    EndWaitCursor();
}

void CColorEyeIDoc::saveOmdFile(LPCTSTR FilePathName)
{
    COmdFile0 f_Omd;

    if(!f_Omd.Save(FilePathName, m_ErrorFx, m_docRNA))
        AfxMessageBox("路徑有問題!!");
    else
    {
        f_Omd.SetFileHead(m_docFileHead);
        f_Omd.iOmdData ( m_docRNA);

        f_Omd.Close();
    }
}
//////////////////////////////////////////////////////////////////////////
void CColorEyeIDoc::OnFileSave() 
{
    // TODO: Add your command handler code here
//    SetPathName()
    if (GetPathName().IsEmpty())            //若還沒有存過的檔
        OnFileSaveAs();                     //就另存新檔
    else
    {
        SetModifiedFlag(FALSE);
//        saveTxtFile(GetPathName());
         saveOmdFile(GetPathName());
    }
    SetModifiedFlag(FALSE);
}

void CColorEyeIDoc::debugByTxt(CString pathName)
{
    std::vector<CString> vStr;
    CString str;

    str.IsEmpty();
    vStr.clear();
//     str.Format("記憶體位址\t原始順序\t區域碼\t背景色碼\t第幾點\t量測點數\tLv\tx\ty\tdu\tdv\tT\tDuv\tX\tY\tZ\n");
    vStr.push_back(str);
//     for (std::vector<Cartridge2>::iterator iter = m_dOmd.Begin(); iter != m_dOmd.End(); ++iter)
    for (std::vector<Cartridge2>::iterator iter = m_docRNA.Begin(); iter != m_docRNA.End(); ++iter)
    {                  
//         str.Format("%x\t%d\t%d\t%s\t%d\t%s\t%f\t%f\t%f\t%f\t%f\t%d\t%f\t%f\t%f\t%f\n",\
//             iter, iter->GetOrigSeqc(), iter->GetArea(), 
//             iter->GetStrColorType(), //背景色碼
//             iter->GetMsrFlowNo(), //第幾點
//             iter->GetStrPointNum(),//量測點數
//             iter->GetLv(), iter->GetSx(), iter->GetSy(), iter->GetDu(), iter->GetDv(), iter->GetT(), iter->GetDuv(), iter->GetX(), iter->GetY(), iter->GetZ());
        str.Format("%s\n", iter->GetDescrip());
        vStr.push_back(str);
    }

    CStdioFile file;
    CFileException fx;

    pathName.Format("%s_debug.omd", pathName.Left(pathName.GetLength()-4));

    if (!file.Open(pathName, CFile::modeCreate | CFile::modeWrite | CFile::typeText, &fx))
    {
        TCHAR buf[255];
        fx.GetErrorMessage(buf, 255);
        CString strPrompt(buf);
        AfxMessageBox(strPrompt);
    }
    else
    {
        if (!vStr.empty())
            for (std::vector<CString>::iterator it = vStr.begin(); it != vStr.end(); ++it)
                file.WriteString(it->GetBuffer(0));            

        file.Close();
    }
}
//////////////////////////////////////////////////////////////////////////
void CColorEyeIDoc::UpdateDocRNA(const RNA& _docRNA)
{
    m_docRNA.CutEqualCell(_docRNA);
    m_docRNA.AddCell(_docRNA);
}

void CColorEyeIDoc::UpdateMsrRNA(const RNA& _msrRNA)
{ m_MsrRNA.Empty(); m_MsrRNA.AddCell(_msrRNA); }

void CColorEyeIDoc::UpdateDocDNA(const DNA& _docDNA)
{ m_docDNA.AddCell(_docDNA); }

OmdHead& CColorEyeIDoc::GetFileHead()
{ return m_docFileHead; };
const OmdHead CColorEyeIDoc::GetFileHead() const
{ return m_docFileHead; };
void CColorEyeIDoc::SetFileHead(const OmdHead& _H)
{ m_docFileHead = _H; };
