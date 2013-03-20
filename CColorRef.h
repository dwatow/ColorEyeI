#ifndef CCOLORREF_H
#define CCOLORREF_H
#include "StdAfx.h"

class ColorRef
{
// 	COLORREF* m_pColor;
	COLORREF  m_color;
public:
	ColorRef();
	ColorRef(const int&, const int&, const int&);
	ColorRef(const COLORREF& clr);
	ColorRef(const ColorRef& clr);
// 	~ColorRef();

// 	COLORREF* oPtr() const;
// 	void iPtr(COLORREF*);

	COLORREF  oRGB() const;
	unsigned char R() const;
	unsigned char G() const;
	unsigned char B() const;

    COLORREF  Shift(int shift = 55) const;
    COLORREF  Invrt() const;

	void iRGB(const int&, const int&, const int&);
	void iGray(const int&);
	void operator= (const ColorRef& clr);
	BOOL operator==(const ColorRef& clr);

private:
	void checkColor(const int& r, const int& g, const int& b) const;
	BOOL midBand(const int&) const;
};


#endif  