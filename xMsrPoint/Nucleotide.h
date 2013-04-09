#ifndef NUCLEOTIDE_H
#define NUCLEOTIDE_H

#include <vector>

enum PointNum    {Pn1 = 1, Pn4 = 4, Pn5 = 5, Pn9=9, Pn13=13, Pn21=21, Pn25=25, Pn49=49, PnGamma = 256, NoPn = 999};
enum ColorType   {NoColor = 0, White, Red, Green, Blue, Dark, Nits, CrsTlk, CrsTlkW, CrsTlkD, JNDX, JND};
enum ParaOfPara  { PA_FEover = 0, PA_FElength, PA_D25RectSide, PA_NitsNum, PA_NitsDir, PA_JndGrayLv, PA_GmaBegin, PA_GmaEnd, PA_GmaAvg, PA_Max};

class Nucleotide
{
//建解構子
public:
    Nucleotide(const ColorType& _C = NoColor, const PointNum& _P = NoPn, const int& _N1 = -1, const int& _N2 = -1, const int& _N3 = -1);
    ~Nucleotide();

//該項目共幾點    
private:
    PointNum  m_MsrFlowNum;
public:
    const PointNum GetMsrFlowNum() const;
              void SetMsrFlowNum(const PointNum& pn);
    const  CString GetStrPointNum() const;

//背景顏色
private:
    ColorType m_BkColor;
public:
    const ColorType GetBackColor() const;
    const   CString GetStrColorType() const;
    void      SetBackColor(const ColorType& clr);

//參數串
private:
             CString m_paraStr;
    std::vector<int> m_Parameters;
public:
             void SetPara(const ParaOfPara&, const int&);
    const     int GetPara(const ParaOfPara&) const;
    const CString GetStrPara() const;

//運算子
    const BOOL operator==(const Nucleotide& vNucl) const;
          void operator= (const Nucleotide& vNucl);

    const CString showMe() const;
};

#endif