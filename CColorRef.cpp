#include "CColorRef.h"

ColorRef::ColorRef():m_color(0, 0, 0)
{};

ColorRef::ColorRef(const int& r, const int& g, const int& b):m_color(r, g, b)
{ checkColor(R(), G(), B()); };

ColorRef::ColorRef(const COLORREF& clr):m_color(clr)
{ checkColor(R(), G(), B()); };

ColorRef::ColorRef(const ColorRef& clr):m_color(clr.m_color)
{ checkColor(R(), G(), B()); }


COLORREF ColorRef::oRGB() const{ return m_color; };
unsigned char ColorRef::R() const{ return GetRValue(m_color); };
unsigned char ColorRef::G() const{ return GetGValue(m_color); };
unsigned char ColorRef::B() const{ return GetBValue(m_color); };

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
