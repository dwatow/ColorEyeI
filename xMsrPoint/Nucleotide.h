#ifndef NUCLEOTIDE_H
#define NUCLEOTIDE_H
#include "../Enum.h"
#include <vector>

enum ParaOfPara{ PA_FEover = 0, PA_FEnum, PA_D25RectSide, PA_NitsNum, PA_NitsDir, PA_JndGrayLv, PA_GmaBegin, PA_GmaEnd, PA_GmaAvg, PA_Max};

class Nucleotide
{
//    UINT      m_MsrPointType;//�B�z�Ѽƪ��覡

public:
	 Nucleotide(ColorType _C = NoColor, PointNum _P = NoPn, int _N1 = -1, int _N2 = -1, int _N3 = -1);
	~Nucleotide();

// private:
//     UINT m_OrigSeqc;
// public:
// 	UINT GetOrigSeqc() const;
//     void SetOrigSeqc(UINT);

//�Ӷ��ئ@�X�I    
private:
    PointNum  m_MsrFlowNum;  
public:
    PointNum GetMsrFlowNum() const;
    void     SetMsrFlowNum(PointNum);

	CString  GetStrPointNum() const;

//�I���C��
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
	//ex: �¦�25�I, 6, 10...
	
	str.Format("%s%s", GetStrColorType(), GetStrPointNum());
	for ( std::vector<int>::iterator it  = m_Parameters.begin();
	                                  it != m_Parameters.end();
									++it)
	{
		Para.Format(" %d", *it);
	    str += Para;
	}
	return str + "\n";

	//type: ������type��
}

#endif