#ifndef NUCLEOTIDE_H
#define NUCLEOTIDE_H
#include "../Enum.h"
#include <vector>

enum ParaOfPara{ PA_FEover = 0, PA_FEnum, PA_D25RectSide, PA_NitsNum, PA_NitsDir, PA_JndGrayLv, PA_GmaBegin, PA_GmaEnd, PA_GmaAvg, PA_Max};

class Nucleotide
{
//    UINT      m_MsrPointType;//矪瞶把计よΑ

public:
	Nucleotide(ColorType _C = NoColor, PointNum _P = NoPn, int _N1 = -1, int _N2 = -1, int _N3 = -1);
    ~Nucleotide();

//赣兜ヘ碭翴    
private:
    PointNum  m_MsrFlowNum;  
public:
    PointNum GetMsrFlowNum() const;
    void     SetMsrFlowNum(PointNum);

    CString  GetStrPointNum() const;

//璉春肅︹
private:
    ColorType m_BkColor;
public:
    ColorType GetBackColor() const;
    CString   GetStrColorType() const;
    void      SetBackColor(ColorType clr);

//把计﹃
private:
	CString m_paraStr;
    std::vector<int> m_Parameters;
public:
    void SetPara(ParaOfPara, const int);
    int GetPara(ParaOfPara) const;
	CString GetStrPara() const;


//ㄤウ巨
    BOOL operator==(const Nucleotide& vNucl);
    void operator= (const Nucleotide& vNucl);

    CString showMe();
};

#endif