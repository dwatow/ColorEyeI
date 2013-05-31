#include "stdafx.h"
#include "xlef.h"
#include <comdef.h>

xlsFile::xlsFile(): 
VOptional((long)DISP_E_PARAMNOTFOUND,VT_ERROR), VFALSE((short)FALSE), VTRUE((short)TRUE)
{
    ZeroMemory(buf,sizeof(buf));
    ZeroMemory(buf1,sizeof(buf1));
    ZeroMemory(buf2,sizeof(buf2));
    //Step 1.�sExcel���ε{��
    if(!objApp.CreateDispatch("Excel.Application",&e))
    {
        CString str;
        str.Format("Excel CreateDispatch() failed w/err 0x%08lx", e.m_sc);
        AfxMessageBox(str, MB_SETFOREGROUND);
    }
#ifdef _DEBUG
    SetVisible(true);
#endif
};

xlsFile::~xlsFile()
{
    //objApp.SetUserControl(TRUE);  //����visualable
    range.ReleaseDispatch();
    //chartobject.ReleaseDispatch();
    //chartobjects.ReleaseDispatch();
    objSheet.ReleaseDispatch();
    objSheets.ReleaseDispatch();
    objBook.ReleaseDispatch();
    objBooks.ReleaseDispatch();
    objApp.ReleaseDispatch();
}

//Open()
xlsFile* xlsFile::New()
{
    objBooks = objApp.GetWorkbooks();
    objBook = objBooks.Add(VOptional);    //�}�s�ɮ�
    objSheets = objBook.GetWorksheets();
    return this;
}

xlsFile* xlsFile::Open(const char* path)
{
    objBooks = objApp.GetWorkbooks();
    objBook.AttachDispatch(objBooks.Add(_variant_t(path))); //�}�Ҥ@�Ӥw�s�b���ɮ�
    objBook.Activate();
    objSheets = objBook.GetWorksheets();
    return this;
}

void xlsFile::SaveAs(const char* strTableName)
{
    ZeroMemory(buf,sizeof(buf));
    sprintf(buf, "%s", strTableName);
    objBook.SaveAs(
        COleVariant(buf),
        VOptional, VOptional, 
        VOptional, VOptional, 
        VOptional, 1,
        VOptional, VFALSE,
        VOptional, VOptional, VOptional); 
    //objBook.Close (VOptional,COleVariant(buf),VOptional);
}

void xlsFile::Save()
{
    objBook.Save();
}

/*
void xlsFile::Quit(CString FileName)
{
    ZeroMemory(buf,sizeof(buf));
    sprintf(buf,"%s",FileName);
    objBook.Close(VFalse,COleVariant(buf), VOptional); //���������X�����ݰ��D
    objBooks.Close();
    objApp.Quit();
}
*/
void xlsFile::Quit()
{
    objBook.Close(VFALSE,VOptional, VOptional);
    objBooks.Close();
    objApp.Quit();
}

//SetVisible()
void xlsFile::SetVisible(bool a)
{
    objApp.SetVisible(a);    //���Excel��
    objApp.SetUserControl(a);//�ϥΪ̱����A�N���i�H�۰�����
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Sheet�ާ@

//-------------------------
////���o Sheet �Ӽ�
long xlsFile::SheetTotal()
{
    return objSheets.GetCount();//edisonx
}
//-------------------------
//��SheetIndex ���wSheetName
void xlsFile::SetSheetName(short SheetIndex, const char* SheetName)
{
    try
    {
        objSheet = objSheets.GetItem(COleVariant(SheetIndex));
        objSheet.SetName(SheetName);//�]�wsheet�W��
    }
    catch (...)
    {
        CString str;
        str.Format("�]�w��%d��Sheet���W�r��%s�X���F�I", SheetIndex, SheetName);
        AfxMessageBox(str);
    }
}
//-------------------------
//��SheetIndex ���oSheetName
CString xlsFile::GetSheetName(short SheetIndex)
{
    try
    {
        objSheet = objSheets.GetItem(COleVariant(SheetIndex));
    }
    catch (...)
    {
        CString str;
        str.Format("���o��%d��Sheet�W�r�X���F�I", SheetIndex);
        AfxMessageBox(str);
    }
    return objSheet.GetName();//edisonx
}
//-------------------------
//���Sheet
//��SheetName
xlsFile* xlsFile::SelectSheet(const char* SheetName)
{
    try
    {
        objSheet = objSheets.GetItem(_variant_t(SheetName));
        objSheet.Activate();//edisonx
    }
    catch (...)
    {
        CString str;
        str.Format("���Sheet: %s�X���F�I", SheetName);
         AfxMessageBox(str);
    }
    return this;
}
//��SheetIndex 
xlsFile* xlsFile::SelectSheet(short SheetIndex)
{
    try
    {
        objSheet = objSheets.GetItem(COleVariant(SheetIndex));
        objSheet.Activate();//edisonx
    }
    catch (...)
    {
        CString str;
        str.Format("��ܲ�%d��Sheet�X���F�I", SheetIndex);
        AfxMessageBox(str);
    }
    return this;
}
//-------------------------
//�ƻsSheetName ���w���JSheet����m�A�ë��w�sSheet�W��
void xlsFile::CopySheet(const char* SheetName)
{
    objSheet.AttachDispatch(objSheets.GetItem(_variant_t(SheetName)),true);
    objSheet.Copy(vtMissing,_variant_t(objSheet));
}
//�ƻsSheetIndex ���w���JSheet����m�A�ë��w�W��
void xlsFile::CopySheet(short SheetIndex)
{
    objSheet.AttachDispatch(objSheets.GetItem(COleVariant(SheetIndex)));
    objSheet.Copy(vtMissing,_variant_t(objSheet));
}
//-------------------------
//�R��Sheet
//��SheetName 
void xlsFile::DelSheet(const char* SheetName)
{    
    objSheet = objSheets.GetItem(_variant_t(SheetName));
    objSheet.Delete();//edisonx
}
//��SheetIndex
void xlsFile::DelSheet(short SheetIndex)
{
    objSheet = objSheets.GetItem(COleVariant(SheetIndex));
    objSheet.Delete();//edisonx
}
///////////////////////////////////////////////////////////////////////////////////////////
//Cell�ާ@
//Cell�p�ƭp��
// ���o�_�l�C
long xlsFile::GetHorztlStartCell()
{
    Range usedrange;
    usedrange.AttachDispatch(objSheet.GetUsedRange());
    return usedrange.GetColumn();
}
// ���o�_�l��
long xlsFile::GetVrticlStartCell()
{    
    Range usedrange;
    usedrange.AttachDispatch(objSheet.GetUsedRange());
    return usedrange.GetRow();
}
// ���o�`�C��
long xlsFile::GetHorztlTotalCell()
{
    Range usedrange;
    usedrange.AttachDispatch(objSheet.GetUsedRange());
    range.AttachDispatch(usedrange.GetColumns());
    return range.GetCount();
}
// ���o�`���
long xlsFile::GetVrticlTotalCell()
{
    Range usedrange;
    usedrange.AttachDispatch(objSheet.GetUsedRange());
    range.AttachDispatch(usedrange.GetRows());
    return range.GetCount();
}
//-------------------------
//Cell�榡�]�w
//-------------------------
//���l
//��@��
xlsFile* xlsFile::SelectCell(const char* x)
{
    try
    {
        range=objSheet.GetRange(COleVariant(x),COleVariant(x));
        ASSERT(range);
    }
    catch (...)
    {
        CString str;
        str.Format("����x�s��%s�X���F�I", x);
        AfxMessageBox(str);
    }
    return this;
}

xlsFile* xlsFile::SelectCell(const char* x, int y)
{
    try
    {
        ZeroMemory(buf,sizeof(buf));
        sprintf(buf,"%s%d",x,y);
        range=objSheet.GetRange(COleVariant(buf),COleVariant(buf));
        ASSERT(range);
    }
    catch (...)
    {
        CString str;
        str.Format("����x�s��%s%d�X���F�I", x, y);
        AfxMessageBox(str);
    }
    return this;
}
//�p��Z
xlsFile* xlsFile::SelectCell(char x, int y)
{
    if (x >= 'A' && x <= 'Z')
    {
        ZeroMemory(buf,sizeof(buf));
        sprintf(buf,"%c%d",x,y);
        range=objSheet.GetRange(COleVariant(buf),COleVariant(buf));
        ASSERT(range);
    }
    else
    {
        CString str;
        str.Format("����x�s��%c%d�X���F�I", x, y);
        AfxMessageBox(str);
        ASSERT(x >= 'A' && x <= 'Z');
    }
    return this;
}
//�j��Z�A�}�l��AA
xlsFile* xlsFile::SelectCell(char x1, char x2, int y)
{
    if ( (x1 >= 'A' && x1 <= 'Z') && (x2 >= 'A' && x2 <= 'Z'))
    {
        ZeroMemory(buf,sizeof(buf));
        sprintf(buf,"%c%c%d",x1,x2,y);
        range=objSheet.GetRange(COleVariant(buf),COleVariant(buf));
        ASSERT(range);
    }
    else
    {
        CString str;
        str.Format("����x�s��%c%c%d�X���F�I", x1, x2, y);
        AfxMessageBox(str);
        ASSERT(x1 >= 'A' && x1 <= 'Z');
        ASSERT(x2 >= 'A' && x2 <= 'Z');
    }
    return this;
}
//-------------------------
//���l
//��d��
xlsFile* xlsFile::SelectCell(const char* x1, const char* x2)
{
    try
    {
        range=objSheet.GetRange(COleVariant(x1),COleVariant(x2));
        ASSERT(range);
    }
    catch (...)
    {
        CString str;
        str.Format("��ܽd��A�q%s��%s�X���F�I", x1, x2);
        AfxMessageBox(str);
    }
    return this;
}

xlsFile* xlsFile::SelectCell(const char* x1, int y1, const char* x2, int y2)
{
    try
    {
        ZeroMemory(buf1,sizeof(buf1));
        ZeroMemory(buf2,sizeof(buf2));
        sprintf(buf1,"%s%d",x1,y1);
        sprintf(buf2,"%s%d",x2,y2);
        range=objSheet.GetRange(COleVariant(buf1),COleVariant(buf2));
        ASSERT(range);
    }
    catch (...)
    {
        CString str;
        str.Format("��ܽd��A�q%s%d��%s%d���a��X���F�I", x1, y1, x2, y2);
        AfxMessageBox(str);
    }
    return this;
}
//�p��Z
xlsFile* xlsFile::SelectCell(char x1, int y1, char x2, int y2)
{
    if (x1 >= 'A' && x1 <= 'Z')
    {
        ZeroMemory(buf1,sizeof(buf1));
        ZeroMemory(buf2,sizeof(buf2));
        sprintf(buf1,"%c%d",x1,y1);
        sprintf(buf2,"%c%d",x2,y2);
        range=objSheet.GetRange(COleVariant(buf1),COleVariant(buf2));
        ASSERT(range);
    }
    else
    {
        CString str;
        str.Format("��ܽd��A�q%c%d��%c%d�X���F�I", x1, y1, x2, y2);
        AfxMessageBox(str);
        ASSERT(x1 >= 'A' && x1 <= 'Z');
    }
    return this;
}
//�j��Z�A�}�l��AA
xlsFile* xlsFile::SelectCell(char xA1, char xB1, int y1, char xA2, char xB2, int y2)
{
    if ( (xA1 >= 'A' && xA2 <= 'Z') && (xB1 >= 'A' && xB2 <= 'Z') )
    {
        ZeroMemory(buf1,sizeof(buf1));
        ZeroMemory(buf2,sizeof(buf2));
        sprintf(buf1,"%c%c%d",xA1,xB1,y1);
        sprintf(buf2,"%c%c%d",xA2,xB2,y2);
        
        range=objSheet.GetRange(COleVariant(buf1),COleVariant(buf2));
        ASSERT(range);
    }
    else
    {
        CString str;
        str.Format("��ܽd��A�q%c%c%d��%c%c%d�X���F�I", xA1, xB1, y1, xA2, xB2, y2);
        AfxMessageBox(str);
        ASSERT(xA1 >= 'A' && xA2 <= 'Z');
        ASSERT(xB1 >= 'A' && xB2 <= 'Z');
    }

    return this;
}
//-------------------------
//-------------------------
//�M���x�s��
void xlsFile::ClearCell()
{
    //������@�ӽd���x�s��
    range.Clear();//edisonx
}
//�X���x�s��
xlsFile* xlsFile::SetMergeCells(short vMerge, bool isCenterAcross)
{
    //������@�ӽd���x�s��
    range.SetMergeCells(_variant_t(vMerge));
    if(isCenterAcross) SetHorztlAlgmet(HA_CENTERACROSS);
    return this;
}
//-------------------------
//-------------------------
//����覡
//�������
xlsFile* xlsFile::SetHorztlAlgmet(short position)
{
    range.SetHorizontalAlignment(COleVariant(position));
    return this;
}

//�������
xlsFile* xlsFile::SetVrticlAlgmet(short position)
{
    range.SetVerticalAlignment(COleVariant(position));
    return this;
}

//����覡����V�X�ס]+90~-90�^
xlsFile* xlsFile::SetTextAngle(short Angle)
{
    range.SetOrientation(COleVariant(Angle)); 
    return this;
}
//�]�w��r�۰ʴ���
xlsFile* xlsFile::AutoNewLine(bool NewLine)
{
    if(NewLine)        range.SetWrapText(VTRUE);
    else            range.SetWrapText(VFALSE);
    return this;
}
//-------------------------
//-------------------------
//�]�w�ؽu�B�ؽu�C��
xlsFile* xlsFile::SetCellBorder(long BoarderStyle, int BoarderWeight, long BoarderColor)
{
    range.BorderAround(_variant_t(BoarderStyle), BoarderWeight, BoarderColor,_variant_t((long)RGB(0,0,0)));
    return this;
}
//-------------------------
//-------------------------
//�]�w��e�C��
//�۰ʽվ�C��
void xlsFile::AutoFitWidth()
{
    col = range.GetEntireColumn();    //����Y�ӽd�򪺤@���
    col.AutoFit();                    //�۰ʽվ�@��ƪ���e
}
//�۰ʽվ���e
void xlsFile::AutoFitHight()
{
    row = range.GetEntireRow();        //����Y�ӽd�򪺤@���
    row.AutoFit();                    //�۰ʽվ�@��ƪ��C��
}
//�]�w�C��
xlsFile* xlsFile::SetCellHeight(float height)
{
    range.SetRowHeight(_variant_t(height));
    return this;
}
//�]�w��e
xlsFile* xlsFile::SetCellWidth(float height)
{
    range.SetColumnWidth(_variant_t(height));
    return this;
}
//-------------------------
//-------------------------
//�]�w�r��
xlsFile* xlsFile::SetFont(const char* fontType)
{
    font = range.GetFont();
    font.SetName(_variant_t(fontType));//�쥻�O����r��
    return this;
}
//����
xlsFile* xlsFile::SetFontBold(bool isBold)
{
    font = range.GetFont();
    if (isBold)        font.SetBold(VTRUE);
    else            font.SetBold(VFALSE);
    //font.SetBold(_variant_t(isBold)); //����
    return this;
}
//�R���u
xlsFile* xlsFile::SetFontStrkthrgh(bool isStrike)
{
    font = range.GetFont();
    if (isStrike)    font.SetStrikethrough(VTRUE);    //edisonx
    else            font.SetStrikethrough(VFALSE);    //edisonx
    //font.SetStrikethrough(_variant_t((short)STRIKE));
    return this;
}
//�r���j�p
xlsFile* xlsFile::SetFontSize(short fontSize)
{
    font = range.GetFont();
    font.SetSize(_variant_t(fontSize));//�r���j�ppt
    return this;
}
//�r���C��
xlsFile* xlsFile::SetFontColor(short colorIndex)
{
    font = range.GetFont();
    font.SetColorIndex(_variant_t(colorIndex)); //�r��(�w�]�¦�)
    return this;
}
//-------------------------
//-------------------------
//�]�w����
xlsFile* xlsFile::SetCellColor(short colorIndex)
{
    cell = range.GetInterior();                   //���o����d��A�]�w�x�s�檺�O�����}
    cell.SetColorIndex(_variant_t(colorIndex));   //�]�w����]�d��^
    //cell.SetColor(_variant_t(colorIndex));
    return this;
}
//����C��]�A�X�r��M����^��excel�������y�п���C��
short xlsFile::SelectColor(short x, short y)
{
//Microsoft Excel ���C��ƧǬO��
//���B��B���B��B�šB�Q�B���B�ǡ]y�^
//�Ѳ`��L�]x�^
    switch(x)
    {
    case 1:
             if(y == 1) return 1;
        else if(y == 2) return 9;
        else if(y == 3) return 3;
        else if(y == 4) return 7;
        else if(y == 5) return 38;

        else if(y == 6) return 17;
        else if(y == 7) return 38;
        break;
    case 2:
             if(y == 1) return 53;
        else if(y == 2) return 46;
        else if(y == 3) return 45;
        else if(y == 4) return 44;
        else if(y == 5) return 40;
        
        else if(y == 6) return 18;
        else if(y == 7) return 26;
        break;
    case 3:
             if(y == 1) return 52;
        else if(y == 2) return 12;
        else if(y == 3) return 43;
        else if(y == 4) return  6;
        else if(y == 5) return 36;
        
        else if(y == 6) return 19;
        else if(y == 7) return 27;
        break;
    case 4:
             if(y == 1) return 51;
        else if(y == 2) return 10;
        else if(y == 3) return 50;
        else if(y == 4) return  4;
        else if(y == 5) return 35;
        
        else if(y == 6) return 20;
        else if(y == 7) return 28;
        break;
    case 5:
             if(y == 1) return 49;
        else if(y == 2) return 14;
        else if(y == 3) return 42;
        else if(y == 4) return  8;
        else if(y == 5) return 34;
        
        else if(y == 6) return 21;
        else if(y == 7) return 29;
        break;
    case 6:
             if(y == 1) return 11;
        else if(y == 2) return  5;
        else if(y == 3) return 41;
        else if(y == 4) return 33;
        else if(y == 5) return 37;
        
        else if(y == 6) return 22;
        else if(y == 7) return 30;
        break;
    case 7:
             if(y == 1) return 55;
        else if(y == 2) return 47;
        else if(y == 3) return 13;
        else if(y == 4) return 54;
        else if(y == 5) return 39;
        
        else if(y == 6) return 23;
        else if(y == 7) return 31;
        break;
    case 8:
             if(y == 1) return 56;
        else if(y == 2) return 16;
        else if(y == 3) return 48;
        else if(y == 4) return 15;
        else if(y == 5) return  2;
        
        else if(y == 6) return 24;
        else if(y == 7) return 32;
        break;
    }
    return 2;//�w�]�զ�
}
short xlsFile::SelectColor(const char ColorChar)
{
    switch(ColorChar)
    {
    //�¦�
    case 'D':
    case 'd':
        return 1;
        break;
    //�զ�
    case 'W':
    case 'w':
        return 2;
        break;
    //����
    case 'R':
    case 'r':
        return 3;
        break;
    //���
    case 'G':
    case 'g':
        return 4;
        break;
    //�Ŧ�
    case 'B':
    case 'b':
        return 5;
        break;
    //����
    case 'Y':
    case 'y':
        return 6;
        break;    }
    return 2;//�w�]�զ�
}
///////////////////////////////////////////////////////////////////////////////////////////
//Cell�ާ@
//Cell���
//-------------------------
//-------------------------
//SetCell()
void xlsFile::SetCell(int Data)
{
    ZeroMemory(buf,sizeof(buf));
    sprintf(buf,"%d",Data);
    range.SetItem(_variant_t((long)1),_variant_t((long)1),_variant_t(buf));
}

void xlsFile::SetCell(long Data)
{
    ZeroMemory(buf,sizeof(buf));
    sprintf(buf,"%d",Data);
    range.SetItem(_variant_t((long)1),_variant_t((long)1),_variant_t(buf));
}

void xlsFile::SetCell(double Data)
{
    ZeroMemory(buf,sizeof(buf));
    sprintf(buf,"%f",Data);
    range.SetItem(_variant_t((long)1),_variant_t((long)1),_variant_t(buf));
}

void xlsFile::SetCell(const char* Data)
{
    ZeroMemory(buf,sizeof(buf));
    strcpy(buf,Data);
    //sprintf(buf,"%s",Data);
    range.SetItem(_variant_t((long)1),_variant_t((long)1),_variant_t(buf));
}

void xlsFile::SetCell(CString Data)
{
    ZeroMemory(buf,sizeof(buf));
    sprintf(buf,"%s",Data);
    range.SetItem(_variant_t((long)1),_variant_t((long)1),_variant_t(buf));
}

void xlsFile::SetCell(const char* Format, int Data)
{
    ZeroMemory(buf,sizeof(buf));
    sprintf(buf,Format,Data);
    range.SetItem(_variant_t((long)1),_variant_t((long)1),_variant_t(buf));
}

void xlsFile::SetCell(const char* Format, double Data)
{
    ZeroMemory(buf,sizeof(buf));
    sprintf(buf,Format,Data);
    range.SetItem(_variant_t((long)1),_variant_t((long)1),_variant_t(buf));
}

void xlsFile::SetCell(const char* Format, long Data)
{
    ZeroMemory(buf,sizeof(buf));
    sprintf(buf,Format,Data);
    range.SetItem(_variant_t((long)1),_variant_t((long)1),_variant_t(buf));
}
//-------------------------
//-------------------------
CString xlsFile::GetCell2CStr()
{
//     COleVariant vResult = range.GetValue2();//edisonx 
//     vResult.ChangeType(VT_BSTR);            //edisonx 
//     return vResult.bstrVal;                    //edisonx 

    //      VARIANT cellvalue;
    //      cellvalue = ;
    //cellvalue = range.GetText();
    return (char*)_bstr_t(range.GetItem(_variant_t((long)1), _variant_t((long)1)));
}
int xlsFile::GetCell2Int()
{
    COleVariant vResult = range.GetValue2();//edisonx 
    vResult.ChangeType(VT_INT);                //edisonx 
    return vResult.intVal;                    //edisonx 
}
double xlsFile::GetCell2Double()
{
    COleVariant vResult = range.GetValue2();//edisonx 
    vResult.ChangeType(VT_R8);                //edisonx 
    return vResult.dblVal;                    //edisonx 
}
///////////////////////////////////////////////////////////////////////////////////////////
//�t��k�ާ@
//�Ƨ�
void xlsFile::Sort(CString IndexCell1, long DeCrement1,
                   CString IndexCell2, long DeCrement2,
                   CString IndexCell3, long DeCrement3)
{
    VARIANT key1, key2, key3;

    V_VT(&key1) = VT_DISPATCH;
    V_DISPATCH(&key1)=objSheet.GetRange(COleVariant(IndexCell1),COleVariant(IndexCell1));

    if(IndexCell2.IsEmpty())
    {
        range.Sort( key1, DeCrement1, VOptional, VOptional, 1, VOptional, 1, 2,//�@��ﶵ
                    VOptional, _variant_t((short)TRUE),//�i�� 
                    1, 1, 1, 1, 1);//�����ﶵ//edisonx
    }
    else
    {
        V_VT(&key2) = VT_DISPATCH;
        V_DISPATCH(&key2)=objSheet.GetRange(COleVariant(IndexCell2),COleVariant(IndexCell2));
        
        if(IndexCell3.IsEmpty())
        {
            range.Sort( key1, DeCrement1, key2,    VOptional, DeCrement2, VOptional, 1, 2,
                        VOptional, _variant_t((short)TRUE),//�i�� 
                        1, 1, 1, 1, 1);//�����ﶵ//edisonx
        }
        else
        {
            V_VT(&key3) = VT_DISPATCH;
            V_DISPATCH(&key3)=objSheet.GetRange(COleVariant(IndexCell3),COleVariant(IndexCell3));
            
            range.Sort(    key1, DeCrement1, key2, VOptional, DeCrement2, key3, DeCrement3, 2,//�@��ﶵ
                        VOptional, _variant_t((short)TRUE),//�i�� 
                        1, 1, 1, 1, 1);//�����ﶵ//edisonx
        }
    }
}
///////////////////////////////////////////////////////////////////////////////////////////
//�Ϫ�ާ@
//���J�Ϫ�]�@���scode�^
/*
void xlsFile::DrawChart(CString DataRangeStart, CString DataRangeEnd, 
                       long ChartType, short PlotBy, 
                       short StartFrom, CString TitleString, 
                       UINT ChartStartX, UINT ChartStartY, UINT width, UINT height
                       ) // �e���
{    
    //�bSheet�s�W�Ϫ�
    lpDisp = objSheet.ChartObjects(VOptional);
    chartobjects.AttachDispatch(lpDisp);
    
    //�Ϫ�ŦX�x�s��d�򪺤j�p
    chartobject = chartobjects.Add( (float)range.GetLeft().dblVal,  (float)range.GetTop().dblVal, 
                                    (float)range.GetWidth().dblVal, (float)range.GetHeight().dblVal);
    //��ƨӷ��]�@���^
    xlsChart.AttachDispatch(chartobject.GetChart());
    lpDisp = objSheet.GetRange(COleVariant(DataRangeStart), COleVariant(DataRangeEnd));
    range.AttachDispatch(lpDisp);
    
    var.vt = VT_DISPATCH;
    var.pdispVal = lpDisp;

    xlsChart.ChartWizard(var,                    // const VARIANT& Source.
        COleVariant((short)11),                    // const VARIANT& fix please, Gallery: 3d Column. 1 or 11 �O�_���3D�]3D���A��, 1��A11����^
        COleVariant((short)1),                    // const VARIANT& fix please, Format, use default
        COleVariant((short)PlotBy),                // const VARIANT& PlotBy: 1.X  2.Y �Ϫ�x�b�n�ϥ� ��檺1:X-top�٬O2:Y-left
        COleVariant((short)1),                    // const VARIANT& Category Labels fix please ����b�����Ӹ�ơA�q�ĴX�Ӯ�l�}�l��]����s�ո�Ƽƶq�^
        COleVariant((short)StartFrom),            // const VARIANT& Series Labels. Start X, ����b�����Ӹ�ơA��ƦW�٭n�δX�Ӯ�l�]���W�r�^
        COleVariant((short)TRUE),                // const VARIANT& HasLegend. �O�_�n��ܸs�ո�Ƽ���
        //�H�U�i����
        _variant_t(COleVariant(TitleString)),    // const VARITNT& Title
        _variant_t(COleVariant(X_String)),        // const VARIANT& CategoryTitle
        _variant_t(COleVariant(Y_String)),        // const VARIANT& ValueTitle
        VOptional                                // const VARIANT& ExtraTitle
        );
    xlsChart.SetChartType((long)ChartType);        
}
*/


void xlsFile::newChart()
{
    //�bSheet�s�W�Ϫ�
    lpDisp = objSheet.ChartObjects(VOptional);
    chartobjects.AttachDispatch(lpDisp);    
    //�Ϫ�ŦX�x�s��d�򪺤j�p
    chartobject = chartobjects.Add(
        (float)range.GetLeft().dblVal,
        (float)range.GetTop().dblVal, 
        (float)range.GetWidth().dblVal, 
        (float)range.GetHeight().dblVal );
    //��ƨӷ��]�d��left, top�w�]�� ���Item�MGroup�^
    xlsChart.AttachDispatch(chartobject.GetChart());
}
///////////////////////////////////////////////////////////////////////////////////////////
//�Ϫ�ާ@
//�x�s�Ϫ�
//edisonx
void xlsFile::SaveChart(CString FullBmpPathName)
{
    xlsChart.Export(LPCTSTR(FullBmpPathName),VOptional,VOptional);
}
//��ܪ���ƪ��d��
xlsFile* xlsFile::SelectChartRange(const char* x1,const char* x2)
{
    newChart();

    lpDisp = objSheet.GetRange(COleVariant(x1),COleVariant(x2));
    range.AttachDispatch(lpDisp);
    
    return this;
}

xlsFile* xlsFile::SelectChartRange(const char* x1, int y1, const char* x2, int y2)
{
    newChart();    

    ZeroMemory(buf1,sizeof(buf1));
    ZeroMemory(buf2,sizeof(buf2));
    sprintf(buf1,"%s%d",x1,y1);
    sprintf(buf2,"%s%d",x2,y2);

    lpDisp = objSheet.GetRange(COleVariant(buf1),COleVariant(buf2));
    range.AttachDispatch(lpDisp);
    return this;
}
//�p��Z
xlsFile* xlsFile::SelectChartRange(char x1, int y1, char x2, int y2)
{
    newChart();

    ZeroMemory(buf1,sizeof(buf1));
    ZeroMemory(buf2,sizeof(buf2));
    //�o�{�F�o�Ӱ��D�A���O�ѰO�F�O���O�G�N�o�˼g���I
    //�Ox1, y1; x2, y2?
    sprintf(buf1,"%c%d",x1,y2);
    sprintf(buf2,"%c%d",x1,y2);

    lpDisp = objSheet.GetRange(COleVariant(buf1),COleVariant(buf2));
    range.AttachDispatch(lpDisp);
    return this;
}
//�j��Z�A�}�l��AA
xlsFile* xlsFile::SelectChartRange(char xA1, char xB1, int y1, char xA2, char xB2, int y2)
{
    newChart();
    ZeroMemory(buf1,sizeof(buf1));
    ZeroMemory(buf2,sizeof(buf2));
    sprintf(buf1,"%c%c%d",xA1,xB1,y1);
    sprintf(buf2,"%c%c%d",xA2,xB2,y2);    
    lpDisp = objSheet.GetRange(COleVariant(buf1),COleVariant(buf2));
    range.AttachDispatch(lpDisp);
    return this;
}

// �]�w���Ѽơ]�w�]�|��ܥ��骽��ϡ^
xlsFile* xlsFile::SetChart(short XaxisByToporLeft, bool isLabelVisable, CString TitleString, CString XaxisTitle, CString YaxisTitle) 
{    
    var.vt = VT_DISPATCH;
    var.pdispVal = lpDisp;

    short LabelVisable(FALSE);
    LabelVisable = (isLabelVisable) ? (short)TRUE : (short)FALSE ;
        
    xlsChart.ChartWizard(var,                    // const VARIANT& Source.
        COleVariant((short)11),                    // const VARIANT& fix please, Gallery: 3d Column. 1 or 11 �O�_���3D�]3D���A��, 1��A11����^
        COleVariant((short)1),                    // const VARIANT& fix please, Format, use default
        COleVariant(XaxisByToporLeft),            // const VARIANT& PlotBy: 1.X  2.Y �Ϫ�x�b�n�ϥ� ��檺1:X-top�٬O2:Y-left
        COleVariant((short)1),                    // const VARIANT& Category Labels fix please ����b�����Ӹ�ơA�q�ĴX�Ӯ�l�}�l��]����s�ո�Ƽƶq�^
        COleVariant((short)1),                    // const VARIANT& Series Labels. Start X, ����b�����Ӹ�ơA��ƦW�٭n�δX�Ʈ�l�]���W�r�^
        COleVariant(LabelVisable),                // const VARIANT& HasLegend. �O�_�n��ܸs�ո�Ƽ���
        //�H�U�i����
        _variant_t(COleVariant(TitleString)),    // const VARITNT& Title
        _variant_t(COleVariant(XaxisTitle)),    // const VARIANT& CategoryTitle
        _variant_t(COleVariant(YaxisTitle)),    // const VARIANT& ValueTitle
        VOptional                                // const VARIANT& ExtraTitle
        );
    return this;
}
//���J�Ϫ�
void xlsFile::InsertHistogramChart(int shapeType, bool is3D, 
                          int isVrticl_Horztl_Other, 
                          int isNone_Stack_Percent)
{
    long ChartType = 51;
    if (shapeType == 0)//Area
    {
        if(!is3D)//2D
        {
            if(isNone_Stack_Percent == 0)         ChartType = 1;//�L���|
            else if (isNone_Stack_Percent == 1) ChartType = 77;//�����|
            else if (isNone_Stack_Percent == 2) ChartType = 76;//���ʤ���
        }
        else        //3D
        {
            if(isNone_Stack_Percent == 0)          ChartType = -4098;//�L���|
            else if (isNone_Stack_Percent == 1) ChartType = 78;//�����|
            else if (isNone_Stack_Percent == 2) ChartType = 79;//�ʤ���
        }
    } 
    else if (shapeType == 1)//�����
    {
        if(isVrticl_Horztl_Other == 0)//����
        {
            if(!is3D)//2D
            {
                if(isNone_Stack_Percent == 0)        ChartType = 51;//�L���|
                else if (isNone_Stack_Percent == 1) ChartType = 52;//�����|
                else if (isNone_Stack_Percent == 2) ChartType = 53;//���ʤ���
            }
            else        //3D
            {
                if(isNone_Stack_Percent == 0)        ChartType = 54;//�L���|
                else if (isNone_Stack_Percent == 1) ChartType = 55;//�����|
                else if (isNone_Stack_Percent == 2) ChartType = 56;//�ʤ���
            }
        }
        else if(isVrticl_Horztl_Other == 1)//�
        {
            if(!is3D)//2D
            {
                if(isNone_Stack_Percent == 0)        ChartType = 57;
                else if (isNone_Stack_Percent == 1) ChartType = 58;
                else if (isNone_Stack_Percent == 2) ChartType = 59;
            }
            else        //3D
            {
                if(isNone_Stack_Percent == 0)        ChartType = 60;
                else if (isNone_Stack_Percent == 1) ChartType = 61;
                else if (isNone_Stack_Percent == 2) ChartType = 62;
            }
        }
        else                        ChartType = -4100;    //���� ��3D
    }
    else if (shapeType == 2)//CONE
    {
        if(isVrticl_Horztl_Other == 0)//����
        {
            if(isNone_Stack_Percent == 0)        ChartType = 92;//�L���|
            else if (isNone_Stack_Percent == 1) ChartType = 93;//�����|
            else if (isNone_Stack_Percent == 2) ChartType = 94;//�ʤ���
        }
        else if(isVrticl_Horztl_Other == 1)//�
        {
            if(isNone_Stack_Percent == 0)        ChartType = 95;//�L���|
            else if (isNone_Stack_Percent == 1) ChartType = 96;//�����|
            else if (isNone_Stack_Percent == 2) ChartType = 97;//�ʤ���
        }
        else                                    ChartType = 98;//���� ��3D
    }
    else if (shapeType == 3)
    {
        if(isVrticl_Horztl_Other == 0)//����
        {
            if(isNone_Stack_Percent == 0)        ChartType = 99;//�L���|
            else if (isNone_Stack_Percent == 1) ChartType = 100;//�����|
            else if (isNone_Stack_Percent == 2) ChartType = 101;//�ʤ���
        }
        else if(isVrticl_Horztl_Other == 1)//�
        {
            if(isNone_Stack_Percent == 0)        ChartType = 102;//�L���|
            else if (isNone_Stack_Percent == 1) ChartType = 103;//�����|
            else if (isNone_Stack_Percent == 2) ChartType = 104;//�ʤ���
        }
        else                    ChartType = 105;//���� ��3D
    }
    else if (shapeType == 4)
    {
        if(isVrticl_Horztl_Other == 0)//����
        {
            if(isNone_Stack_Percent == 0)        ChartType = 106;//�L���|
            else if (isNone_Stack_Percent == 1) ChartType = 107;//�����|
            else if (isNone_Stack_Percent == 2) ChartType = 108;//�ʤ���
        }
        else if(isVrticl_Horztl_Other == 1)//�
        {
            if(isNone_Stack_Percent == 0)        ChartType = 109;//�L���|
            else if (isNone_Stack_Percent == 1) ChartType = 110;//�����|
            else if (isNone_Stack_Percent == 2) ChartType = 111;//�ʤ���
        }
        else                    ChartType = 112;    //���� ��3D
    }

    xlsChart.SetChartType((long)ChartType);
}

//�w�w
void xlsFile::InsertBubleChart(bool is3D)
{
    long ChartType = 51;

        if(is3D)        ChartType = 15;
        else            ChartType = 87;

    xlsChart.SetChartType((long)ChartType);
}
//����
void xlsFile::InsertDoughnutChart(bool Explode)
{
    long ChartType = 51;
    
    if(!Explode)    ChartType = -4120;
    else            ChartType = 80;

    xlsChart.SetChartType((long)ChartType);

}
//����
void xlsFile::InsertSurfaceChart(bool is3D, bool isWire)
{
    long ChartType = 51;
    
    if (is3D)
    {
        if (!isWire)    ChartType = 83;
        else            ChartType = 84;
    } 
    else
    {
        if (!isWire)    ChartType = 85;
        else            ChartType = 86;
    }

    xlsChart.SetChartType((long)ChartType);
}
//�p�F
void xlsFile::InsertRadarChart(bool isWire, bool isDot)
{
    long ChartType = 51;
    
    if (isWire)
    {
        if (!isDot)    ChartType = -4151;
        else        ChartType = 81;
    } 
    else            ChartType = 82;

    xlsChart.SetChartType((long)ChartType);
}
//���
void xlsFile::InsertPieChart(bool Explode, int type2Dor3DorOf)
{
    long ChartType = 51;

    if(!Explode)
    {
        if (type2Dor3DorOf == 0)            ChartType = 5;
        else if (type2Dor3DorOf == 1)        ChartType = -1402;
        else if (type2Dor3DorOf == 2)        ChartType = 68;
    }
    else
    {
        if (type2Dor3DorOf == 0)            ChartType = 69;
        else if (type2Dor3DorOf == 1)        ChartType = 70;
        else if (type2Dor3DorOf == 2)        ChartType = 71;
    }
    
    xlsChart.SetChartType(ChartType);
}

void xlsFile::InsertLineChart(bool isDot, bool is3D, int isNone_Stack_Percent)
{
    long ChartType = 51;
    
    if(!is3D)//3D
    {
        if(!isDot)
        {
            if(isNone_Stack_Percent == 0)        ChartType = 4;//�L���|
            else if (isNone_Stack_Percent == 1) ChartType = 63;//�����|
            else if (isNone_Stack_Percent == 2) ChartType = 64;//���ʤ���
        }
        else
        {
            if(isNone_Stack_Percent == 0)        ChartType = 65;//�L���|
            else if (isNone_Stack_Percent == 1) ChartType = 66;//�����|
            else if (isNone_Stack_Percent == 2) ChartType = 67;//���ʤ���
        }
    }
    else                        ChartType = -4101;//3D

    xlsChart.SetChartType((long)ChartType);
}

//������
void xlsFile::InsertXYScatterChart(bool isDot, bool isLine, bool Smooth)
{
    long ChartType = 51;
    if(!isLine)            ChartType = -4169;//3D
    else
    {
        if(Smooth)
        {
            if(isDot)     ChartType = 72;
            else         ChartType = 73;
        }
        else
        {
            if(isDot)    ChartType = 74;
            else        ChartType = 75;
        }
    }
    xlsChart.SetChartType((long)ChartType);
}

//�Ѳ���
void xlsFile::InsertStockChart(int StockType)
{
    long ChartType = 51;
    
    if (StockType == 0)            ChartType = 88;
    else if (StockType == 1)    ChartType = 89;
    else if (StockType == 2)    ChartType = 90;
    else if (StockType == 3)    ChartType = 91;

    xlsChart.SetChartType((long)ChartType);
}
//--------------------------------------------
//--------------------------------------------
//���J�ϡ]�q�ɮס^
void xlsFile::InsertImage(const char* FileNamePath, float Width, float Height)
{
    shapes = objSheet.GetShapes(); 
    shapes.AddPicture(
        FileNamePath,                    //LPCTSTR Filename
        false,                            //long LinkToFile
        true,                            //long SaveWithDocument
        (float)range.GetLeft().dblVal,    //float Left
        (float)range.GetTop().dblVal,   //float Top
        Width,                            //float Width
        Height                            //float Height
        );
}

void xlsFile::InsertImage(const char* FileNamePath)
{
    shapes = objSheet.GetShapes(); 
    shapes.AddPicture(
        FileNamePath,                    //LPCTSTR Filename
        false,                            //long LinkToFile
        true,                            //long SaveWithDocument
        (float)range.GetLeft().dblVal,    //float Left
        (float)range.GetTop().dblVal,   //float Top
        (float)range.GetWidth().dblVal, //float Width
        (float)range.GetHeight().dblVal //float Height
        );
}
