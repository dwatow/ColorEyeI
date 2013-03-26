#include "stdafx.h"
#include "Nucleotide.h"


/*******************************************
 *  Define PointSet Class member function  *
 *******************************************/

Nucleotide::Nucleotide
(const ColorType& _C, const PointNum& _P, const int& _N1, const int& _N2, const int& _N3):
m_BkColor(_C), m_MsrFlowNum(_P),
m_Parameters(PA_Max, -1)
{
    //�Ѽƶ�J����
    switch (_P)
    {
    case PnGamma:
        SetPara(PA_GmaBegin, _N1);
        SetPara(PA_GmaEnd,   _N2);
        SetPara(PA_GmaAvg,   _N3);
        m_paraStr.Format("_%d~%d, ����%d", _N1, _N2, _N3);
        break;
    //������
    case Pn4:
        if (_C != CrsTlk && _C != CrsTlkD && _C != CrsTlkW)
            break;
    case Pn5:
    case Pn9:
        if (_C == Nits)
        {
            SetPara(PA_NitsNum, _N1);
            SetPara(PA_NitsDir, _N2); 
            m_paraStr.Format("_�Ƕ�: %d%s", _N1, (_N2)?"��":"��");
            break;
        }
        if (_C == Dark)
        {
            SetPara(PA_FEover, 0);
            m_paraStr.Format("_�K��");
            break;
        }

    case Pn13:
    case Pn21:
    case Pn25:
        SetPara(PA_FEover, _N1);
        if (_C == Dark) SetPara(PA_D25RectSide, _N2);
        if (_N1 == 0)
            m_paraStr.Format("_�K��");
        else
            m_paraStr.Format("_����: 1/%d", _N1);
        break;
    //�L����
    //�S���S�O�w�q�A�N�����Ŧr��

    case Pn1:
        if (_C == JND || _C == JNDX)
        {
            SetPara(PA_JndGrayLv, _N1); 
            m_paraStr.Format("_�Ƕ�: %d", _N1);
            break;
        }
    case Pn49:
    default:
        m_paraStr.Empty();
    }
}

Nucleotide::~Nucleotide()
{
    m_Parameters.clear();
}

const ColorType Nucleotide::GetBackColor() const        { return m_BkColor;     }
void      Nucleotide::SetBackColor(const ColorType& clr) { m_BkColor = clr;      }

const PointNum Nucleotide::GetMsrFlowNum() const        { return m_MsrFlowNum;  }
void Nucleotide::SetMsrFlowNum(const PointNum& mfNum)    { m_MsrFlowNum = mfNum; }

const CString Nucleotide::GetStrPointNum() const
{
    CString Num;
    switch(m_MsrFlowNum)
    {
    case Pn1:  Num.Format("�����I");   break;
    case Pn4:  Num.Format("  4�I");   break;
    case Pn5:  Num.Format("  5�I");   break;
    case Pn9:  Num.Format("  9�I");   break;
    case Pn13: Num.Format(" 13�I");   break;
    case Pn21: Num.Format(" 21�I");   break;
    case Pn25: Num.Format(" 25�I");   break;
    case Pn49: Num.Format(" 49�I");   break;
    case PnGamma: Num.Format("Gamma");   break;
    case NoPn:
    default:   Num.Format("���w�q�I��");
    }
    return Num;
}

const CString Nucleotide::GetStrColorType() const
{
    CString Color;
    switch(m_BkColor)
    {
    case White:  Color.Format("�զ�");   break;
    case Red:    Color.Format("����");   break;
    case Green:  Color.Format("���");   break;
    case Blue:   Color.Format("�Ŧ�");   break;
    case Dark:   Color.Format("�¦�");   break;
    case Nits:   Color.Format("Nits");  break;
    case CrsTlkW:Color.Format("CrossTalk�կx��"); break;
    case CrsTlkD:Color.Format("CrossTalk�¯x��"); break;
    case CrsTlk: Color.Format("CrossTalk�L�x��"); break;
    case JNDX:     Color.Format("JND�Q�r"); break;
    case JND:    Color.Format("JND�ť�"); break;
    case NoColor:
    default:     Color.Format("���w�q��m");
    }
    return Color;
}

const CString Nucleotide::GetStrPara() const
{
    return m_paraStr;
}

const BOOL Nucleotide::operator==(const Nucleotide& vCar) const
{
    BOOL b(FALSE);
    std::vector<int>::const_iterator vCitor = vCar.m_Parameters.begin();
    if ((GetMsrFlowNum() == vCar.GetMsrFlowNum()) && (GetBackColor()  == vCar.GetBackColor() ))
        for ( std::vector<int>::const_iterator initor = m_Parameters.begin(); 
              initor != m_Parameters.end(), vCitor != vCar.m_Parameters.end(); 
              ++initor, ++vCitor)
                  if (initor == vCitor)
                      b = TRUE;
                  else
                      b = FALSE;
    return b;
};

void Nucleotide::operator= (const Nucleotide& vCar)
{
    SetMsrFlowNum(vCar.GetMsrFlowNum());
    SetBackColor(vCar.GetBackColor());
    m_Parameters.clear();
    m_Parameters = vCar.m_Parameters;
}

void Nucleotide::SetPara(const ParaOfPara& Parameter, const int& FromEdge)
{
    m_Parameters[Parameter] = FromEdge;
}

const int Nucleotide::GetPara(const ParaOfPara& Parameter) const
{
    return m_Parameters[Parameter];
}

const CString Nucleotide::showMe() const
{
    CString str, Para;
    //ex: �¦�25�I, 6, 10...
    
    str.Format("%s%s%s %d, %d, %d, %d, %d, %d\n",\
        GetStrColorType(), GetStrPointNum(), GetStrPara(),\
        m_Parameters[0], m_Parameters[1], m_Parameters[2], m_Parameters[3], m_Parameters[4], m_Parameters[5], m_Parameters[6], m_Parameters[7], m_Parameters[8], m_Parameters[0]);
    return str;
    //type: ������type��
}
//////////////////////////////////////////////////////////////////////////
//debug function

// #ifdef _DEBUG
// 
// CString Nucleotide::GetSetupValue() const
// {
//     CString str;
//     CString color;
// //    enum ColorType    { White = 1, Red, Green, Blue, Dark, Nits, CrsTlk, CrsTlkW, CrsTlkD};
// 
//     switch(m_BkColor)
//     {
//     case White: color.Format("White"); break;
//     case Red: color.Format("Red");   break;
//     case Green: color.Format("Green"); break;
//     case Blue: color.Format("Blue");  break;
//     case Dark: color.Format("Dark");  break;
//     case Nits: color.Format("Nits");  break;
//     case CrsTlk: color.Format("CrsTlk"); break;
//     case CrsTlkW: color.Format("CrsTlkW"); break;
//     case CrsTlkD: color.Format("CrsTlkD"); break;
//     case JND:     color.Format("JND"); break;
//     case JNDX:     color.Format("JNDX"); break;
//     default: color.Format("UnDefine"); break;
//     }
// 
//     str.Format("�C�ⶵ��=%s, �I��/�Ҧ�: %d/%d, �ϰ�X=%d",\
//         color, m_MsrFlowNo, m_MsrFlowNum, m_AreaCode);
// 
//     return str;
// }
// 
// CString Nucleotide::MsgBoxStr() const
// {
//     CString str;
//     str.Format("AreaCode   = %d\nBackColor  = %d\nMsrFlowNo  = %d\nMsrFlowNum = %d\n%s"\
//         , m_AreaCode, m_BkColor, m_MsrFlowNo, m_MsrFlowNum);
//     
//     return str;
// }
// 
// #endif