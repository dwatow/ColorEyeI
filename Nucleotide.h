#ifndef NUCLEOTIDE_H
#define NUCLEOTIDE_H

#include <vector>

enum PointTotal  { Pn1 = 1, Pn4 = 4, Pn5 = 5, Pn9=9, Pn13=13, Pn21=21, Pn25=25, Pn49=49, PnGamma = 256, NoPn = 999};
enum ColorType   { NoColor = 0, White, Red, Green, Blue, Dark, Nits, CrsTlk, CrsTlkW, CrsTlkD, JNDX, JND};
enum ParaOfPara  { PA_FEover = 0, PA_FElength, PA_D25RectSide, PA_NitsLv, PA_NitsDir, PA_JndGrayLv, PA_GmaBegin, PA_GmaEnd, PA_GmaAvg, PA_Max};
enum FEtype      { FT_1overN = 0, FT_Ncm };

class Nucleotide
{
//建解構子
public:
    Nucleotide(const ColorType& _C = NoColor, const PointTotal& _P = NoPn, const int& _N1 = -1, const int& _N2 = -1, const int& _N3 = -1);
    ~Nucleotide();

//該項目共幾點    
private:
    PointTotal  m_MsrPointTotal;
public:
                void SetMsrPointTotal(const PointTotal& pn);
    const PointTotal GetMsrPointTotal()    const;
    const    CString GetStrMsrPointTotal() const;

//背景顏色
private:
    ColorType m_BkColor;
public:
               void SetBackColor(const ColorType& clr);
    const ColorType GetBackColor()    const;
    const   CString GetStrBackColor() const;

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
    const BOOL equalMsrPtTotal(const Nucleotide& vCar) const;
	const BOOL equalBackColor(const Nucleotide& vCar) const;
	const BOOL equalParameter(const Nucleotide& vCar) const;

    const CString ShowMe() const;
};

inline const BOOL Nucleotide::equalMsrPtTotal(const Nucleotide& vCar) const
{
	return (GetMsrPointTotal() == vCar.GetMsrPointTotal())? TRUE : FALSE;
}

inline const BOOL Nucleotide::equalBackColor(const Nucleotide& vCar) const
{
	return (GetBackColor()  == vCar.GetBackColor() )? TRUE : FALSE;
}

inline const BOOL Nucleotide::equalParameter(const Nucleotide& vCar) const
{
	BOOL b(TRUE);
	if (vCar.m_Parameters.size() == m_Parameters.size())
	{
		for ( int i = 0; i < PA_Max; ++i)
		{
			int a, b, c;			
			a = vCar.m_Parameters[i];
			b = m_Parameters[i];
			c = i;
			if (vCar.m_Parameters[i] != m_Parameters[i])
				b = FALSE;
		}
	}
	else
		ASSERT(0);

	return b;
}


#endif