#ifndef TRANSCRIPTER_H
#define TRANSCRIPTER_H

#include "RNA.h"
#include "xMsrPoint/DNA.h"
#include "xMsrPoint/Nucleotide.h"
#include "xMsrPoint/Cartridge2.h"

class TranScripter
{
	UINT m_nScrmH, m_nScrmV;
	std::vector<Nucleotide>::iterator m_tranPointer;

public:
	TranScripter();
	void Trans(DNA&, RNA&);
private:
	COLORREF tranColor(UINT) const;
	CPoint   tranPoint(UINT) const;
	CString  tranDescrip(UINT) const;
	//DNA to RNA
    CPoint get5nits9Point(UINT few) const;
    CPoint getCrossTalk(UINT few) const;// 6/26新增
	
    CPoint getFE5Point(UINT few)     const;
    CPoint getFE9Point(UINT few = 4) const;
    CPoint getW49Point(UINT few)     const;
    CPoint getD25Point(UINT few)     const;//side 幾公分
    CPoint getD29Point(UINT few)     const;
    CPoint getD21Point(UINT few)     const;
    CPoint getD13Point(UINT few)     const;
	CPoint getGammaPoint()           const;
	CPoint getJND()                  const;

	UINT cm2pixel(const double) const;

	void setSquence(Cartridge2&, std::vector<Nucleotide>::size_type) const;
    

	//RNA processor
//private:

};
#endif