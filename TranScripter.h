#ifndef TRANSCRIPTER_H
#define TRANSCRIPTER_H

#include "RNA.h"
#include "xMsrPoint/DNA.h"
#include "xMsrPoint/Nucleotide.h"
#include "OmdFile/TxtFile.h"
#include "ColorEyeI.h"

class TranScripter
{
#ifdef _DEBUG
	std::vector<CString> m_dTxt;
	CString m_desktopPath;
#endif // _DEBUG

	const int m_nScrmH, m_nScrmV;
	std::vector<Nucleotide>::iterator m_tranPointer;

public:
	TranScripter();
	void Trans(DNA&, RNA&);
	int Cm2pixel(const double) const;
private:
	ColorRef tranColor(UINT) const;
	CPoint   tranPoint(UINT) const;
	CString  tranDescrip(UINT) const;
	BackGroundStatus tranBkStatus(UINT few) const;

	void forCrsTlk(Cartridge2&);
	//DNA to RNA
    CPoint get5nits9Point(UINT few) const;
    CPoint getCrossTalk(UINT few) const;// 6/26新增
	
	CPoint getCenterPoint()      const;
    CPoint getFE5Point(UINT few) const;
    CPoint getFE9Point(UINT few) const;
    CPoint getW49Point(UINT few) const;
    CPoint getD25Point(UINT few) const;//side 幾公分
    CPoint getD29Point(UINT few) const;
    CPoint getD21Point(UINT few) const;
    CPoint getD13Point(UINT few) const;
	CPoint getJND()              const;

	void setSquence(Cartridge2&, std::vector<Nucleotide>::size_type, int) const;
    
	void checkPointValue(const int x, const int y = 1) const;
	void checkPointValue(const double fe, const int cm = 1) const;

};
#endif