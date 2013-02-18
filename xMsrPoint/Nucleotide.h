#ifndef NUCLEOTIDE_H
#define NUCLEOTIDE_H
#include "../Enum.h"
#include <vector>

enum ParaOfPara{ PA_FEover = 0, PA_FEnum, PA_D25RectSide, PA_NitsNum, PA_NitsDir, PA_JndGrayLv, PA_GmaBegin, PA_GmaEnd, PA_GmaAvg, PA_Max};

class Nucleotide
{
//    UINT      m_MsrPointType;//處理參數的方式

public:
	 Nucleotide(ColorType _C = NoColor, PointNum _P = NoPn, int _N1 = -1, int _N2 = -1, int _N3 = -1);
	~Nucleotide();

// private:
//     UINT m_OrigSeqc;
// public:
// 	UINT GetOrigSeqc() const;
//     void SetOrigSeqc(UINT);

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

private:
	std::vector<int> m_Parameters;
public:
	void SetPara(ParaOfPara, const int);
	int GetPara(ParaOfPara);

	BOOL operator==(const Nucleotide& vNucl);
	void operator= (const Nucleotide& vNucl);

	CString showMe();
};

inline CString Nucleotide::showMe()
{
	CString str, Para;
	//ex: 黑色25點, 6, 10...
	
	str.Format("%s%s", GetStrColorType(), GetStrPointNum());
	for ( std::vector<int>::iterator it  = m_Parameters.begin();
	                                  it != m_Parameters.end();
									++it)
	{
		Para.Format(" %d", *it);
	    str += Para;
	}
	return str + "\n";

	//type: 直接用type看
}

#endif