#ifndef TRANSCRIPTER_H
#define TRANSCRIPTER_H

#include "RNA.h"
#include "DNA.h"
#include "Nucleotide.h"
#include "TxtFile.h"
#include "ColorEyeI.h"

enum TrigStatus{ TS_FinalPoint = 0, TS_Normal, TS_Find_Nits, TS_JND, TS_JNDX};

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
	const int Cm2pixel(const double&) const;
private:
	const          ColorRef tranColor  (const UINT&) const;
	const          CPoint   tranPoint  (const UINT&) const;
	const          CString  tranDescrip(const UINT&) const;
	const BackGroundStatus tranBkStatus(const UINT&) const;

	void forCrsTlk(Cartridge2&);
	void forNits  (Cartridge2&);
	//DNA to RNA
    const CPoint get5nits9Point(const UINT& few) const;
    const CPoint getCrossTalk  (const UINT& few) const;// 6/26新增
	
	const CPoint getCenterPoint()             const;
    const CPoint getFE5Point(const UINT& few) const;
    const CPoint getFE9Point(const UINT& few) const;
    const CPoint getW49Point(const UINT& few) const;
    const CPoint getD25Point(const UINT& few) const;//side 幾公分
    const CPoint getD21Point(const UINT& few) const;
    const CPoint getD13Point(const UINT& few) const;
// 	CPoint getJND()              const;

	void setSquence(Cartridge2&, const std::vector<Nucleotide>::size_type&, const int&) const;
    
	void checkPointValue(const int& x, const int& y = 1) const;
	void checkPointValue(const double& fe, const int& cm = 1) const;
};
#endif