#include "CColorRef.h"

ColorRef::ColorRef():m_color(0, 0, 0)
{};


BOOL ColorRef::operator==(const ColorRef& clr)
{
    return ( R() == clr.R() && G() == clr.G() && B() == clr.B() )? TRUE : FALSE ;
}

void ColorRef::operator= (const ColorRef& clr)
{
    iRGB(clr.R(), clr.G(), clr.B());
}

BOOL ColorRef::midBand(const int& subclr) const
{
	const int BandWidth(10);
	const int Limit((256 - BandWidth)/2);
	return (subclr < 255-Limit) && (subclr > Limit);
}

void ColorRef::checkColor(const int& r, const int& g, const int& b) const
{
    ASSERT(r >= 0);    ASSERT(r < 256);
    ASSERT(g >= 0);    ASSERT(g < 256);
    ASSERT(b >= 0);    ASSERT(b < 256);
}

ColorRef::ColorRef(const int& r, const int& g, const int& b):m_color(r, g, b)
{ checkColor(R(), G(), B()); };

ColorRef::ColorRef(const COLORREF& clrR):m_color(clrR)
{ checkColor(R(), G(), B()); };

ColorRef::ColorRef(const ColorRef& clr):m_color(clr.m_color)
{ checkColor(R(), G(), B()); }

// ColorRef::~ColorRef()
// {
// 	delete m_color;
// }

COLORREF ColorRef::oRGB() const{ return m_color; };
unsigned char ColorRef::R() const{ return GetRValue(m_color); };
unsigned char ColorRef::G() const{ return GetGValue(m_color); };
unsigned char ColorRef::B() const{ return GetBValue(m_color); };
// COLORREF* ColorRef::oPtr() const{ return m_color; }

COLORREF ColorRef::Invrt() const
{
    const int r = ( midBand(R()) )?(130 - R()):(255 - R());
    const int g = ( midBand(G()) )?(130 - G()):(255 - G());
    const int b = ( midBand(B()) )?(130 - B()):(255 - B());

    return RGB(r, g, b);
}

COLORREF ColorRef::Shift(int shift) const
{
    const int r = (R() < shift)?(R() + shift):(R() - shift);
    const int g = (G() < shift)?(G() + shift):(G() - shift);
    const int b = (B() < shift)?(B() + shift):(B() - shift);
	
	return RGB(r, g, b);
}

// void ColorRef::iPtr(COLORREF* pClr)
// {
// 	m_color = pClr;
// }

void ColorRef::iRGB(const int& r, const int& g, const int& b)
{
    checkColor(r, g, b);
    m_color = RGB(r, g, b);
}

void ColorRef::iGray(const int& gray)
{
    checkColor(gray, gray, gray);
    m_color = RGB(gray, gray, gray);
}
