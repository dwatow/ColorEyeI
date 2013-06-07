#ifndef BKMAKER_H
#define BKMAKER_H

#include "CColorRef.h"
#include "CA210.h"

enum NitsDirect{ND_NoDefine = 0, ND_Pos, ND_Neg};

class BkMaker
{
//smart ptr
    int* ptr_i;
    int* cnt;
public:
    const BOOL IsPtrToNull() const;
    const int GetPtrCnt() const;
public:
    BkMaker();
    BkMaker(const BkMaker& bkN);
    ~BkMaker();
    BkMaker& operator=(const BkMaker& sp);

//背景色
private:
    ColorRef m_BkColor;
public:
    const ColorRef _GetBkColor() const;
              void _SetBkColor(const ColorRef&);

//Crosstalk的介面
protected:
    ColorRef  m_rectColor;
    CRect     m_centerRect;
public:
    virtual void CT_SetRect(const CRect& _rect, const ColorRef& clr){ };

//Nits的介面
protected:
    CWnd*  m_pdlgcWnd;
    Ca210* m_pCa210;
public:
    virtual void NT_SetWnd(CWnd* cWnd){ };
    virtual void NT_SetCa(Ca210* pCa){ };

protected:
    NitsDirect m_NitsDirect;
    int m_NitsLv;  //參數
public:
//void TranScripter::forNits(Cartridge2& crtg)
    virtual    void NT_SetNitsLv(const int&){  };
    virtual    void NT_colorReviseByNits(ColorRef&){  };

//共用介面
public:
    virtual void Draw(CPaintDC& dc);
};

inline const BOOL BkMaker::IsPtrToNull() const
{
    return (cnt == 0) ? TRUE : FALSE ;
}

inline const int BkMaker::GetPtrCnt() const
{
    return *cnt;
}


#endif
