#ifndef CCOLORREF_H
#define CCOLORREF_H

class ColorRef
{
    COLORREF  m_color;
public:
    ColorRef();
    ColorRef(const int&, const int&, const int&);
    ColorRef(const COLORREF& clr);
    ColorRef(const ColorRef& clr);
//彩色
                   void iRGB(const int&, const int&, const int&);
    const      COLORREF oRGB() const;
    const unsigned char R() const;
    const unsigned char G() const;
    const unsigned char B() const;
//變色
    const      COLORREF Shift(int shift = 55) const;
    const      COLORREF Invrt() const;
//灰階
                   void iGray(const int&);
//運算子
public:            void operator= (const ColorRef& clr);
    const          BOOL operator==(const ColorRef& clr) const;

private:           void checkColor(const int& r, const int& g, const int& b) const;
             const BOOL checkInv(const int&) const;
};


#endif  