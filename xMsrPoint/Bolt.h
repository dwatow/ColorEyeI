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
	PointNum  m_MsrFlowNum;       //�Ӷ��ئ@�X�I
	UINT      m_MsrFlowNo;        //�Ӷ��ت��ĴX�I
	COLORREF  m_5nitsBkColor;

public:
	Bolt();
	~Bolt();
	BOOL Magazine(CString LcmSize, std::vector<Cartridge>::iterator&, std::vector<Cartridge>::iterator& );  //�u�X
	void Partition(std::vector<Cartridge>& , Cartridge& );  //��u���]�ֳt�q���^

	UINT Trigger(std::vector<Cartridge>::iterator&);

	CString  GetMsrFlowName()   const;
	COLORREF GetBkColor()       const;
	CPoint   GetPointPosition() const;
	UINT     GetRadius()        const;
	BOOL     isReady()          const;
	CString  GetSetupValue()    const;
	BOOL     Set5NitsBkColor(COLORREF);
	COLORREF Get5NitsBkColor()  const;

	ColorType GetColorType() const
	{
		return m_BkColor;
	}
	void CenterRect(CDC* pDC, float FromEdge, COLORREF CntrClr);

private:
	CPoint GetCrossTalk(UINT few   , float FromEdge = 8) const;// 6/26�s�W
	CPoint GetFE5Point(UINT few, float FromEdge = 0) const;
	CPoint GetFE9Point(UINT few = 4, float FromEdge = 6) const;
	CPoint GetW49Point(UINT few)    const;
	CPoint Get5nits9Point(UINT few) const;
//	CPoint GetD9Point(UINT few)     const;
	CPoint GetD25Point(UINT few)    const;
	CPoint GetD29Point(UINT few)    const;
	CPoint GetD13Point(UINT few)    const;
	UINT CmtoPixel(const double cm) const;
};
#endif