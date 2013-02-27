#ifndef VALUESLABEL_H
#define VALUESLABEL_H

//#include "Bullet.h"

enum ValueKind{VL_Lv, VL_Sx, VL_Sy, VL_T, VL_Duv, VL_Du, VL_Dv, VL_X, VL_Y, VL_Z, VL_Total};

class ValuesLabel
{
	std::vector<CString> m_Values;
public:
	ValuesLabel();
	void i(ValueKind, CString&);
	CString o(ValueKind) const;
	CString show() const;
};

inline ValuesLabel::ValuesLabel():
m_Values(VL_Total)
{}

inline void ValuesLabel::i(ValueKind _VK, CString& _S)
{
	ASSERT(_S.GetLength());
	m_Values.at(_VK) = _S;
}

inline CString ValuesLabel::o( ValueKind _VK) const
{
	return m_Values.at(_VK);
}

CString ValuesLabel::show() const
{
	
}

#endif