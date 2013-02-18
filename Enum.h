#ifndef ENUM_H
#define ENUM_H

#include "StdAfx.h"

enum isMsrValue  {Lv = 0, Sx, Sy, du, dv, T, duv, X, Y, Z};
enum isMsrItem   {WRGBD = 0, Nts, W49, W9, D25, W5};

enum ColorType   {NoColor = 0, White, Red, Green, Blue, Dark, Nits, CrsTlk, CrsTlkW, CrsTlkD, JNDX, JND};
enum PointNum    {Pn1 = 1, Pn4 = 4, Pn5 = 5, Pn9=9, Pn13=13, Pn21=21, Pn25=25, Pn49=49, PnGamma = 256, NoPn = 999};

//enum ParaType    {DivScrm = 0, nCm};//分數/整數/

#endif

/*
欲修改
CString Cartridge::GetStrColorType() const
CString Cartridge::GetStrPointNum() const

*/