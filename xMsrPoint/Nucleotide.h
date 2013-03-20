#ifndef NUCLEOTIDE_H
#define NUCLEOTIDE_H
#include "../Enum.h"
#include <vector>

enum ParaOfPara{ PA_FEover = 0, PA_FEnum, PA_D25RectSide, PA_NitsNum, PA_NitsDir, PA_JndGrayLv, PA_GmaBegin, PA_GmaEnd, PA_GmaAvg, PA_Max};

class Nucleotide
{
//    UINT      m_MsrPointType;//處理參數的方式
//	Nucleotide(){};
public:
	Nucleotide(ColorType _C = NoColor, PointNum _P = NoPn, int _N1 = -1, int _N2 = -1, int _N3 = -1);
    ~Nucleotide();

//該項目共幾點    
private:
    PointNum  m_MsrFlowNum;  
public:
    PointNum GetMsrFlowNum() const;
    void     SetMsrFlowNum(PointNum);

    CString  GetStrPointNum() const;

//背景顏色
private:
    ColorType m_BkColor;
public:
    ColorType GetBackColor() const;
    CString   GetStrColorType() const;
    void      SetBackColor(ColorType clr);

//參數串
private:
	CString m_paraStr;
    std::vector<int> m_Parameters;
public:
    void SetPara(ParaOfPara, const int);
    int GetPara(ParaOfPara) const;
	CString GetStrPara() const;


//其它操作
    BOOL operator==(const Nucleotide& vNucl);
    void operator= (const Nucleotide& vNucl);

    CString showMe();
};

#endif