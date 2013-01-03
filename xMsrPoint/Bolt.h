#ifndef BOLT_H
#define BOLT_H

#include <vector>
#include <iterator>
#include "Cartridge.h"

typedef std::vector<Cartridge> xChain;
//enum PtXt {PtXtT = 0, PtXtL, PtXtR, PtXtB};
enum TrigStatus{ TS_FinalPoint = 0, TS_Normal, TS_Find_Nits, TS_JND, TS_JNDX};
enum NitsKind{ NK_POS, NK_NEG};
enum AreaKind { AA_00, AA_01, AA_02, AA_03, AA_04, AA_05, AA_06, AA_07, AA_08, AA_09};

class Bolt 
{
    xChain::iterator m_itEnd;
    int       m_nScrmH;
    int       m_nScrmV;
    int       m_Radius;
    float     m_LcmSize;
    ColorType m_BkColor;
    PointNum  m_MsrFlowNum;       //該項目共幾點
    int       m_MsrFlowNo;        //該項目的第幾點
    COLORREF  m_5nitsBkColor;
	COLORREF  m_JNDBkColor;

    float    m_f5FE;
    float    m_f9FE;
    float    m_f21FE;
    float    m_f21Havg;
    float    m_f21Vavg;
    float    m_f25FE;
    int      m_n25RectSide;
    int      m_nGM1;
    int      m_nGM2;
    float    m_fGammaSetp;
    float    m_fNits;
    float    m_fCrsTlkRectFE;
	NitsKind m_nNitsKind;

public:
    Bolt();
    ~Bolt();

    BOOL Magazine(CString LcmSize, xChain::iterator& );  //彈匣
    void Grow(xChain& , Cartridge& );  //填彈器

    TrigStatus Trigger(xChain::iterator&);

    CString  GetMsrFlowName()     const;
    COLORREF GetBkColor()         const;
    CPoint   GetPointPosition()   const;
    int      GetRadius()          const;

    float    GetNitsSpec(){ return m_fNits; }

    BOOL     Set5NitsBkColor(COLORREF);
    COLORREF Get5NitsBkColor()  const;

	void     SetJNDBkColor(COLORREF);
	COLORREF GetJDNBkColor() const;

    ColorType GetColorType() const
    {
        return m_BkColor;
    }
    void CenterRect(CDC* pDC, COLORREF CntrClr);
    void CenterCross(CDC* pDC, COLORREF CntrClr);

    Bolt* SetP5FE(float);
    Bolt* SetP9FE(float);
    Bolt* SetP21FE(float);
    Bolt* SetP21Avg(float, float);
    Bolt* SetP25FE(float);
    Bolt* SetP25RectSide(UINT);
    Bolt* SetGammaRange(UINT, UINT);
    Bolt* GammaStep(float);
    Bolt* SetNitsNum(float);
	Bolt* SetNitsKind(NitsKind);
    Bolt* SetCrsTlkRectFE(float);

	NitsKind GetNitsKind();
	float GetLcmSize() const{ return m_LcmSize; };
    
private:
	AreaKind PointToArea(CPoint p) const;
    CPoint Get5nits9Point(UINT few) const;
    CPoint GetCrossTalk(UINT few) const;// 6/26新增

    CPoint GetFE5Point(UINT few)     const;
    CPoint GetFE9Point(UINT few = 4) const;
    CPoint GetW49Point(UINT few)     const;
    CPoint GetD25Point(UINT few)     const;//side 幾公分
    CPoint GetD29Point(UINT few)     const;
    CPoint GetD21Point(UINT few)     const;
    CPoint GetD13Point(UINT few)     const;
	CPoint GetGammaPoint()           const;
	CPoint GetJND()                  const;

    UINT CmtoPixel(const double cm) const;


//////////////////////////////////////////////////////////////////////////
//debug function

#ifdef _DEBUG
public:
CString  GetSetupValue()    const;
#endif

};

inline Bolt::~Bolt(){}

#endif