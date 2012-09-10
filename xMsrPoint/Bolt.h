#ifndef BOLT_H
#define BOLT_H

#include <vector>
#include <iterator>
#include "Cartridge.h"

class Bolt 
{
    std::vector<Cartridge>::iterator m_itEnd;
    BOOL      m_isReady;
    UINT      m_nScrmH;
    UINT      m_nScrmV;
    UINT      m_Radius;
    UINT      m_LcmSize;
    ColorType m_BkColor;
    PointNum  m_MsrFlowNum;       //該項目共幾點
    UINT      m_MsrFlowNo;        //該項目的第幾點
    COLORREF  m_5nitsBkColor;

    float    m_f5FE;
    float    m_f9FE;
    float    m_f21FE;
    float    m_f21Havg;
    float    m_f21Vavg;
    float    m_f25FE;
    UINT     m_n25RectSide;
    UINT     m_nGM1;
    UINT     m_nGM2;
    float    m_fGammaSetp;
    float    m_fNits;
    float    m_fCrsTlkRectFE;

public:
    Bolt();
    ~Bolt();

    BOOL Magazine(CString LcmSize, std::vector<Cartridge>::iterator& );  //彈匣
    void Grow(std::vector<Cartridge>& , Cartridge& );  //填彈器

    UINT Trigger(std::vector<Cartridge>::iterator&);

    CString  GetMsrFlowName()   const;
    COLORREF GetBkColor()       const;
    CPoint   GetPointPosition() const;
    UINT     GetRadius()        const;
    BOOL     isReady()          const;

    float    GetNitsSpec(){ return m_fNits; }
    BOOL     Set5NitsBkColor(COLORREF);
    COLORREF Get5NitsBkColor()  const;

    ColorType GetColorType() const
    {
        return m_BkColor;
    }
    void CenterRect(CDC* pDC, float FromEdge, COLORREF CntrClr);

    Bolt* SetP5FE(float);
    Bolt* SetP9FE(float);
    Bolt* SetP21FE(float);
    Bolt* SetP21Avg(float, float);
    Bolt* SetP25FE(float);
    Bolt* SetP25RectSide(UINT);
    Bolt* SetGammaRange(UINT, UINT);
    Bolt* GammaStep(float);
    Bolt* SetNitsNum(float);
    Bolt* SetCrsTlkRectFE(float);
    
private:
    CPoint Get5nits9Point(UINT few) const;
    CPoint GetCrossTalk(UINT few) const;// 6/26新增

    CPoint GetFE5Point(UINT few)     const;
    CPoint GetFE9Point(UINT few = 4) const;
    CPoint GetW49Point(UINT few)     const;
    CPoint GetD25Point(UINT few)     const;//side 幾公分
    CPoint GetD29Point(UINT few)     const;
    CPoint GetD21Point(UINT few)     const;
    CPoint GetD13Point(UINT few)     const;

    UINT CmtoPixel(const double cm) const;


//////////////////////////////////////////////////////////////////////////
//debug function

#ifdef _DEBUG
public:
CString  GetSetupValue()    const;
#endif

};
#endif