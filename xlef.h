/*******************************************************************
 *                                                                 *
 * ��class��kx�]�p�A�õo�G�쪩                                        *
 * �G���h��Edison.Shih.���Ѩ禡�A�ɨ��쪩������                         *
 *                                                                 *
 * ��Edison.Shih.���Ѫ��禡�ɨ��A�|��edisonx���O��                     *
 *                                                                 *
 * Class�� Visual C++ 6 �}�o                                        *
 * �A�Ω�Microsoft Excel 2003 �� Microsoft Excel 2003 SP3 ���յL�~   *
 * ���ե��x Microsoft Windows XP SP3                                *
 *                           2011/7/11                             *
 *******************************************************************/
#ifndef XLSFILE_H
#define XLSFILE_H

#include "excel.h"
#include <vector>

enum Boarder_Style
{
    BS_NONE    = 0,      //�L�ؽu
    BS_SOLIDLINE,        //�@��u
    BS_BIGDASH,          //�p���j��u- - - - - -���ʲ�
    BS_SMALLDASH,        //�j���j��u- - - - - -�L�ʲ�
    BS_DOTDASH,          //��u-.-.-.-.-.-.
    BS_DASHDOTDOT,       //��u.-..-..-..-..-.
    BS_DOUBLSOLID = 9,   //���u============�]�����ʲӧ��ܡ^
    BS_SLASHDASH  = 13   //���u-/-/-/-/-/-/�]�����ʲӧ��ܡ^
};
enum Boarder_Weight    //�]�ʲӡ^
{
    BA_HAITLINE = 1,     //��@��p�]�ҥH�ε�u��ܡ^
    BA_THIN,             //�@��
    BA_MEDIUM,           //��
    BA_THICK             //�p
};
enum Horizontal_Alignment
{
    HA_GENERAL = 1,
    HA_LEFT,           //edisonx
    HA_CENTER,
    HA_RIGHT,          //edisonx
    HA_FILL,           //���Ʀܶ�    //edisonx
    HA_JUSTIFYPARA,    //�q�����ơ]���d����A���۰��_��^
    HA_CENTERACROSS,   //����m���]���X���x�s��^
    HA_JUSTIFY,        //��������]�Y�ơ^
};

enum Vertical_Alignment
{
    VA_TOP = 1,        //edisonx
    VA_CENTER,         //edisonx
    VA_BOTTOM,         //edisonx
    VA_JUSTIFYPARA,    //�q�����ơ]���d����A���۰��_��^
    VA_JUSTIFY         //�������
};

enum Histogram_Chart_Type
{
    CT_AREA = 0,       //�ϰ�
    CT_COLUMN,         //��W
    CT_CONE,           //���@
    CT_CYLINDER,       //��W
    CT_PYRAMID         //���r��
};

enum Stock_Type
{
    ST_HLC = 0,    //�̰�-�̧C-���L
    ST_OHLC,       //�}�L-�̰�-�̧C-���L
    ST_VHLC,       //����q-�̰�-�̧C-���L
    ST_VOHLC       //����q-�}�L-�̰�-�̧C-���L
};
///////////////////////////////////
//Boarder
//Set Boarder Style
// #define BS_NONE      0  //�L�ؽu
// #define BS_SOLIDLINE     1  //�@��u
// #define BS_BIGDASH       2  //�p���j��u- - - - - -���ʲ�
// #define BS_SMALLDASH     3  //�j���j��u- - - - - -�L�ʲ�
// #define BS_DOTDASH       4  //��u-.-.-.-.-.-.
// #define BS_DASHDOTDOT    5  //��u.-..-..-..-..-.
// //6, 7, 8 = 1
// #define BS_DOUBLSOLID    9  //���u============�]�����ʲӧ��ܡ^
// //10, 11, 12 = 1
// #define BS_SLASHDASH    13  //���u-/-/-/-/-/-/�]�����ʲӧ��ܡ^

//Set Boarder Weight�]�ʲӡ^
// #define BA_HAITLINE    1  //��@��p�]�ҥH�ε�u��ܡ^
// #define BA_THIN    2  //�@��
// #define BA_MEDIUM      3  //��
// #define BA_THICK       4  //�p
//Set Boarder Color
//0-56

///////////////////////////////////
//Alignment
//Set Horizontal Alignment
// #define HA_GENERAL        1//�q�ή榡
// #define HA_LEFT        2        //edisonx
// #define HA_CENTER        3
// #define HA_RIGHT        4        //edisonx
// #define HA_FILL        5//���Ʀܶ�    //edisonx
// #define HA_JUSTIFYPARA     6//�q�����ơ]���d����A���۰��_��^
// #define HA_CENTERACROSS    7//����m���]���X���x�s��^
// #define HA_JUSTIFY        8//��������]�Y�ơ^
//Set Vertical Alignment    
// #define VA_TOP        1        //edisonx
// #define VA_CENTER        2        //edisonx
// #define VA_BOTTOM        3        //edisonx
// #define VA_JUSTIFYPARA    4//�q�����ơ]���d����A���۰��_��^
// #define VA_JUSTIFY        5//�������

///////////////////////////////////
//Histogram Chart Type
// #define CT_AREA    0    //�ϰ�
// #define CT_COLUMN    1    //��W
// #define CT_CONE    2    //���@
// #define CT_CYLINDER    3    //��W
// #define CT_PYRAMID    4    //���r��
//Stock Type
// #define ST_HLC    0    //�̰�-�̧C-���L
// #define ST_OHLC    1    //�}�L-�̰�-�̧C-���L
// #define ST_VHLC    2    //����q-�̰�-�̧C-���L
// #define ST_VOHLC    3    //����q-�}�L-�̰�-�̧C-���L

class xlsFile
{
protected:
    COleVariant VOptional, VTRUE, VFALSE;  
    //VOptional((long)DISP_E_PARAMNOTFOUND,VT_ERROR)
    //VFalse((short)FALSE)
    //VTrue((short)TRUE)
    _Application objApp;
    Workbooks objBooks;
    _Workbook objBook;
    Sheets objSheets;
    _Worksheet objSheet,objSheetT;
    Range range,col,row;//,oCell;//,range2,range3;
    Interior cell;
    Font font;
    COleException e;

    LPDISPATCH lpDisp;
    ChartObjects chartobjects;
    ChartObject chartobject;
    _Chart xlsChart;
    VARIANT var;
    
    Shapes shapes;

    char buf[200];  //�Ȧs���r��
    char buf1[200];
    char buf2[200];
      
public:
//	virtual	void InitForm() = 0; //�e�X��檺title
// 	virtual xlsFile* iData(std::vector<Cartridge>&, std::vector<Cartridge>::size_type) = 0;
// 	virtual std::vector<Cartridge> oData() = 0;

public:
    xlsFile();
    ~xlsFile();
    //xlsFile* //�}�F�ɮפ���i�H�~����Sheet�M�R�W
    xlsFile* New();
    xlsFile* Open();
    xlsFile* Open(const char*);
    void SaveAs(const char*);
    void Save();
    //void Quit(CString FileName);
    void Quit();
    void SetVisible(bool);//�]�w�������ݱo���A�çⱱ���v�浹�ϥΪ�
    //----------------------------------------------------
    //Sheet�ާ@
    long SheetTotal();            //���o Sheet �Ӽ�
    void SetSheetName(short, const char*);    //��SheetNumber    ���wSheetName
    CString GetSheetName(short);          //��SheetNumber    ���oSheetName
    
    xlsFile* SelectSheet(const char*);    //��SheetName      ���Sheet
    xlsFile* SelectSheet(short);          //��SheetNumber    ���Sheet
    void CopySheet(const char*);          //�ƻsSheetName    ���w���JSheet����m�A�ë��w�sSheet�W��
    void CopySheet(short);            //�ƻsSheetNumber  ���w���JSheet����m�A�ë��w�W��
    void DelSheet(const char*);           //��SheetName      �R��Sheet
    void DelSheet(short);             //��SheetNumber    �R��Sheet
    //-----------------------------------------------------
    //
    long GetHorztlStartCell(); // �_�l��
    long GetVrticlStartCell(); // �_�l�C
    long GetHorztlTotalCell(); // �`���
    long GetVrticlTotalCell(); // �`�C��
    //-----------------------------------------------------
    //xlsFile* ��F��l����i�H�~��U�uŪ�v�u�g�v���������
    //��@��
    xlsFile* SelectCell(const char* );
    xlsFile* SelectCell(const char* , int );
    xlsFile* SelectCell(char,int);
    xlsFile* SelectCell(char,char,int);
    //��@�ӽd��
    xlsFile* SelectCell(const char* , const char* );
    xlsFile* SelectCell(const char* , int ,const char* , int );
    xlsFile* SelectCell(char,int,char,int);
    xlsFile* SelectCell(char,char,int,char,char,int);
    //--------------------------------------------
    void ClearCell();                //�M���x�s��
    xlsFile* SetMergeCells(short vMerge = TRUE, 
            bool isCenterAcross = true);     //�X���x�s��]�q�`�|�t����m���^
    //--------------------------------------------
    //���
    xlsFile* SetHorztlAlgmet(short);    //�������
    xlsFile* SetVrticlAlgmet(short);    //�������
    xlsFile* SetTextAngle(short Angle); //��V-��r����
    xlsFile* AutoNewLine(bool NewLine); //�۰ʴ���
    //---------------------------------------------
    //��u
    xlsFile* SetCellBorder(long BoarderStyle = 1, 
    int BoarderWeight = 2, long BoarderColor = 1);  //�]�w�ؽu�ʲөM�C��
    //---------------------------------------
    //�x�s��j�p
    void AutoFitHight();        //�۰ʽվ�C��
    void AutoFitWidth();        //�۰ʽվ���e
    xlsFile* SetCellHeight(float);    //�]�w�C��
    xlsFile* SetCellWidth(float);    //�]�w��e
    //---------------------------------------------
    //�r
    xlsFile* SetFont(const char* fontType = "�s�ө���");    //�]�w�r���]�w�]�s�ө���^
    xlsFile* SetFontBold(bool isBold = true);           //����
    xlsFile* SetFontStrkthrgh(bool isBold = true);      //�R���u
    xlsFile* SetFontSize(short fontSize = 12);          //�]�w�r��j�p�]�w�]12pt�^
    xlsFile* SetFontColor(short colorIndex = 1);        //�r���C��]�w�]�¦�^
    //---------------------------------------------
    xlsFile* SetCellColor(short);//�]�w����
    //---------------------------------------------
    //�]17-32���ê��]�����i�ӡ^
    //Microsoft Excel ���C��ƧǬO��
    //���B��B���B��B�šB�Q�B���B�ǡ]y�^�A�Ѳ`��L�]x�^
    //���L����RGB�èS���W�ߪ��s�b�o�Ӫ��
    short SelectColor(short x = 8, short y = 7);  //��excel�������y�п���C��
    short SelectColor(const char ColorChar = 'W');    //�ֳt���]��D�B��W�B��R�B��G�B��B�B��Y�^
    //---------------------------------------------
    //�]�w��ƶi�x�s��]�s���r��^
    //�@�목
    void SetCell(int);
    void SetCell(double);
    void SetCell(long);    
    void SetCell(const char* );    
    void SetCell(CString );    
    //�ۭq�ӳ��榡��
    void SetCell(const char*, int);
    void SetCell(const char*, double);
    void SetCell(const char*, long);
    //--------------------------------------------
    //����
    int GetCell2Int();
    CString GetCell2CStr();
    double GetCell2Double();
    //--------------------------------------------
    //�Ƨǡ]�̦C�Ƨǡ^//edisonx
    void Sort(CString IndexCell1, long DeCrement1,
          CString IndexCell2 = "", long DeCrement2 = 1,
          CString IndexCell3 = "", long DeCrement3 = 1);
    //--------------------------------------------
    //�ҥ�edisonx���Ѩ�Ƹ��

	//�x�s�Ϫ�Ϥ�.bmp�].jpg��i�H�^
    void SaveChart(CString FullBmpPathName);
    //�Ϫ�]�T��������Ʀb�C���إ߳��n�ϥΡ^
	//�ϥΫe������ܶK�WChart���x�s��d��
    
	//��ܸ�ƽd��
	xlsFile* SelectChartRange(const char* , const char* );    
    xlsFile* SelectChartRange(const char* , int ,const char* , int );
    xlsFile* SelectChartRange(char,int,char,int);    
    xlsFile* SelectChartRange(char,char,int,char,char,int);
	//�]�wChart�Ѽ�
    xlsFile* SetChart(short XaxisByToporLeft = 2, bool isLabelVisable = 1, 
    CString = "" , CString = "" , CString = "" );
    //�ϰ�B����B��W�B��W�B���@�B���r��
    void InsertHistogramChart(int shapeType = CT_COLUMN, bool is3D = 0, 
              int isVrticlorHorztlorOther = 0, 
              int isNone_Stack_Percent = 0);
    //�䥦�]�S��Ϫ�^   
    void InsertBubleChart(bool is3D = 0);                         //�w�w��
    void InsertDoughnutChart(bool Explode = 0);                       //������
    void InsertSurfaceChart(bool is3D = 0, bool isWire = 0);                  //������
    void InsertRadarChart(bool isWire = 0, bool isDot = 1);                   //�p�F��
    void InsertPieChart(bool Explode = 0, int type2Dor3DorOf = 0);            //����
    void InsertLineChart(bool isDot = 1, bool is3D = 0, int isNone_Stack_Percent = 0);    //��u��
    void InsertXYScatterChart(bool isDot, bool isLine, bool Smooth);              //������
    void InsertStockChart(int);                               //�Ѳ���
    //--------------------------------------------
    void InsertImage(const char* , float , float );  //���J�Ϥ�
    void InsertImage(const char* );          //���J�Ϥ��]������d��A���ɥ����u�^
protected:
   void xlsFile::newChart();  //�bSheet�s�W�Ϫ�
    //�������B��
// private:
//     void operator+(const xlsFile&);
//     void operator-(const xlsFile&);
//     void operator*(const xlsFile&);
//     void operator/(const xlsFile&);
//     void operator%(const xlsFile&);
//     void operator=(const xlsFile&);
//     
//     bool operator<(const xlsFile&);
//     bool operator>(const xlsFile&);
//     bool operator>=(const xlsFile&);
//     bool operator<=(const xlsFile&);
//     bool operator==(const xlsFile&);
//     bool operator!=(const xlsFile&);
// 
//     
//     bool operator&&(const xlsFile&);
//     bool operator&(const xlsFile&);
//     bool operator||(const xlsFile&);
//     bool operator|(const xlsFile&);
//     
//     bool operator>>(const xlsFile&);
//     bool operator<<(const xlsFile&);
};
/*

  range.SetFormula(COleVariant("=RAND()*100000"));    //�M����
  range.setSetValue(COleVariant("Last Name"));    //��J��
  range.SetNumberFormat(COleVariant("$0.00"));    //�Ʀr�榡

  //����
  Shapes shapes = objSheet.GetShapes(); 
  range = objSheet.GetRange(COleVariant("J7"),COleVariant("R21")); 
  
    //range.AttachDispatch(pRange);
    shapes.AddPicture(
    "c:\\CHILIN.bmp",        //LPCTSTR Filename
    false,                //long LinkToFile
    true,                //long SaveWithDocument
    (float)range.GetLeft().dblVal,    //float Left
    (float)range.GetTop().dblVal,   //float Top
    (float)range.GetWidth().dblVal, //float Width
    (float)range.GetHeight().dblVal //float Height
    );
    range.Sort(
    key1,    //  key1
    DeCrement1,    // long Order1, [ 1(ascending order) or 2(descending order) ]
    key2,    // key2, 
    VOptional,    // type, [xlSortLabels, xlSortValues]
    DeCrement2,    // long Order2, [ 1(�ɾ�) or 2( ��) ]
    key3,    // key3
    DeCrement3,    // long Order3, [ 1(�ɾ�) or 2( ��) ]
    2,        // Header, [0,1 : ���t title 2 : title �]����d��^�@�_��
    //�i��
    VOptional,            // OrderCustom [�q1�}�l�A�۩w�q�ƧǶ��ǦC�������޸��A�ٲ��ϥα`�W]
    _variant_t((short)TRUE),    // MatchCase [TRUE���j�p�g��]
    1,                // Orientation : [�ƧǤ�V, 1:���C, 2:����)
    1,                // SortMethod : [1:���r�ź~�y��������, 2:���r�ŵ��e��]
    //�����ﶵ
    1, // DataOption1 �i�� 0 �P 1
    1, // DataOption2 �i�� 0 �P 1
    1  // DataOption3 �i�� 0 �P 1
    );
*/
#endif