#ifndef CCOLORREF_H
#define CCOLORREF_H
#include "StdAfx.h"

class ColorRef
{
	COLORREF m_color;
public:
	ColorRef();
	ColorRef(const int&, const int&, const int&);
	ColorRef(COLORREF clr);

	COLORREF oRGB() const;
	unsigned char R() const;
	unsigned char G() const;
	unsigned char B() const;

    COLORREF  Shift(int shift = 55) const;
    COLORREF  Invrt() const;

	void iRGB(const int&, const int&, const int&);
	void operator= (const ColorRef& clr);
	BOOL operator==(const ColorRef& clr);

private:
	void checkColor(const int& r, const int& g, const int& b) const;
	BOOL midBand(const int&) const;
};

inline BOOL ColorRef::operator==(const ColorRef& clr)
{
    return ( R() == clr.R() && G() == clr.G() && B() == clr.B() )? TRUE : FALSE ;
}

inline 	void ColorRef::operator= (const ColorRef& clr)
{
    iRGB(clr.R(), clr.G(), clr.B());
}

inline BOOL ColorRef::midBand(const int& subclr) const
{
	const int BandWidth(10);
	const int Limit((256 - BandWidth)/2);
	return (subclr < 255-Limit) && (subclr > Limit);
}

inline void ColorRef::checkColor(const int& r, const int& g, const int& b) const
{
    ASSERT(r >= 0);    ASSERT(r < 256);
    ASSERT(g >= 0);    ASSERT(g < 256);
    ASSERT(b >= 0);    ASSERT(b < 256);
}

#endif  