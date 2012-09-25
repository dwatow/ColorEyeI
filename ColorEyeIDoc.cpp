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

BOOL CColorEyeIDoc::OnNewDocument()
{
    if (!CDocument::OnNewDocument())
        return FALSE;

    // TODO: add reinitialization code here
    // (SDI documents will reuse this document)
    //第一次執行時會執行這個
    SetTitle("新的Omd檔");
    m_OmdData.Empty();          //清空記憶體空間m_OmdData
    SetModifiedFlag(TRUE);

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
    SetTitle("新的Omd檔");
    m_OmdData.Empty();          //清空記憶體空間m_OmdData
    SetModifiedFlag(TRUE);

    UpdateAllViews(NULL);  //更新畫面
}

BOOL CColorEyeIDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
    if (!CDocument::OnOpenDocument(lpszPathName))
        return FALSE;    
    // TODO: Add your specialized creation code here
    //點兩下會執行這個
    BeginWaitCursor();
    OnNewDocument();
    
    COmdFile1 f_Omd;
    if(!f_Omd.Open(lpszPathName, m_ErrorFx))
        AfxMessageBox("路徑有問題");
    else 
    {
        SetPathName(lpszPathName);
        SetTitle(lpszPathName);

        m_PnlID  = f_Omd.GetPnlID();
        m_MsrDvc = f_Omd.GetMsrDvc();
        m_Prb    = f_Omd.GetPrb();
        m_CHID   = f_Omd.GetCHID();
        
        UpdateAllViews(NULL);
        SetModifiedFlag(FALSE);    
	}

    EndWaitCursor();
    return TRUE;
}

void CColorEyeIDoc::OnFileOpen() 
{
    // TODO: Add your command handler code here
//    OpenTxtFile("Text File(*.txt)|*.txt|All Files (*.*)|*.* ||");
    OpenOmdFile("OrigMsrData Files (*.omd)|*.omd|Text File(*.txt)|*.txt|All Files (*.*)|*.* ||");
}

void CColorEyeIDoc::OnFileSaveAs() 
{
    // TODO: Add your command handler code here
//    SaveTxtFile("Text File(*.txt)|*.txt|All Files (*.*)|*.* ||");
    SaveOmdFile("OrigMsrData Files (*.omd)|*.omd|Text File(*.txt)|*.txt|All Files (*.*)|*.* ||");
}

void CColorEyeIDoc::OpenTxtFile(LPCTSTR FileFilter)
{
    CFileDialog aFileDialog (TRUE, NULL, NULL, OFN_SHAREAWARE | OFN_OVERWRITEPROMPT, FileFilter);
    
    int nID = aFileDialog.DoModal();
    if (nID == IDOK)
    {
		CTxtFile f_txt;
        if(!f_txt.Open(aFileDialog.GetPathName(), m_ErrorFx))
            AfxMessageBox("檔案開啟錯誤!!");
        else
        {
            SetPathName(aFileDialog.GetPathName());
            SetTitle(aFileDialog.GetFileName());
			f_txt.oTxtData(m_TextData);
        }
        f_txt.Close();
        UpdateAllViews(NULL);
    }
}

void CColorEyeIDoc::SaveTxtFile(LPCTSTR FileFilter)
{
    CFileDialog aFileDialog (TRUE, NULL, NULL, OFN_SHAREAWARE | OFN_OVERWRITEPROMPT, FileFilter);
    
    int nID = aFileDialog.DoModal();
    if (nID == IDOK)
    {
		CTxtFile f_txt;
       if (!f_txt.Save(aFileDialog.GetPathName(), m_ErrorFx))
            AfxMessageBox("路徑有問題!!!");
        else 
        {
            SetPathName(aFileDialog.GetPathName());
            SetTitle(aFileDialog.GetFileName());
			f_txt.iTxtData(m_TextData);
        }
        f_txt.Close();
        UpdateAllViews(NULL);
    }
}

void CColorEyeIDoc::OpenOmdFile(LPCTSTR FileFilter)
{
    CFileDialog aFileDialog (TRUE, NULL, NULL, OFN_SHAREAWARE | OFN_OVERWRITEPROMPT, FileFilter);
    
    int nID = aFileDialog.DoModal();
    if (nID == IDOK)
    {
        BeginWaitCursor();

        COmdFile1 f_Omd;

        if(!f_Omd.Open(aFileDialog.GetPathName(), m_ErrorFx))
            AfxMessageBox("路徑有問題");
        else 
        {
            SetPathName(aFileDialog.GetPathName());
            SetTitle(aFileDialog.GetFileName());

            m_PnlID  = f_Omd.GetPnlID();
            m_MsrDvc = f_Omd.GetMsrDvc();
            m_Prb    = f_Omd.GetPrb();
            m_CHID   = f_Omd.GetCHID();
			f_Omd.oOmdData(m_OmdData);
                
            f_Omd.Close();
            UpdateAllViews(NULL);
        }
        EndWaitCursor();
    }
}

void CColorEyeIDoc::SaveOmdFile(LPCTSTR FileFilter)
{
    CFileDialog aFileDialog (FALSE, "omd", "*.omd", OFN_SHAREAWARE, FileFilter);
    
    int nID = aFileDialog.DoModal();
    if (nID == IDOK)
    {
		COmdFile1 f_Omd;
        if(!f_Omd.Save(aFileDialog.GetPathName(), m_ErrorFx))
            AfxMessageBox("路徑有問題!!");
        else
        {
            SetPathName(aFileDialog.GetPathName());
            SetTitle(aFileDialog.GetFileName());

            f_Omd.SetPnlID (m_PnlID);
            f_Omd.SetMsrDvc(m_MsrDvc);
            f_Omd.SetPrb   (m_Prb);
            f_Omd.SetCHID  (m_CHID);
			f_Omd.iOmdData(m_OmdData);
                
            f_Omd.Close();
            UpdateAllViews(NULL);
        }        
    }
}

void CColorEyeIDoc::OnFileSave() 
{
    // TODO: Add your command handler code here
    if (GetPathName().IsEmpty())            //若還沒有存過的檔
    {
        OnFileSaveAs();          //就另存新檔
    }
    else
    {
        SetModifiedFlag(FALSE);
        SaveOmdFile("OrigMsrData Files (*.omd)|*.omd|Text File(*.txt)|*.txt|All Files (*.*)|*.* ||");
    }
}

void CColorEyeIDoc::RestructureVector()
{
    m_OmdData.CutEqualCell(m_msrData);  //erase
    m_OmdData.AddCell(m_OmdData.End(), m_msrData.Begin(), m_msrData.End());  //insert
}

void CColorEyeIDoc::DebugByTxt()
{
    std::vector<CString> vStr;
    CString str;

    str.IsEmpty();
    vStr.clear();
    str.Format("記憶體位址\t原始順序\t區域碼\t背景色碼\t第幾點\t量測點數\tLv\tx\ty\tdu\tdv\tT\tDuv\tX\tY\tZ\n");
    vStr.push_back(str);
    for (std::vector<Cartridge>::iterator iter = m_OmdData.Begin(); iter != m_OmdData.End(); ++iter)
    {                  
        str.Format("%x\t%d\t%d\t%s\t%d\t%s\t%f\t%f\t%f\t%f\t%f\t%d\t%f\t%f\t%f\t%f\n",\
            iter, iter->GetOrigSeqc(), iter->GetArea(), 
            iter->GetStrColorType(), //背景色碼
            iter->GetMsrFlowNo(), //第幾點
            iter->GetStrPointNum(),//量測點數
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
    for (std::vector<Cartridge>::iterator iter = m_OmdData.Begin(); iter != m_OmdData.End(); ++iter)
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


