#include "stdafx.h"
#include "Nucleotide.h"


/*******************************************
 *  Define PointSet Class member function  *
 *******************************************/

Nucleotide::Nucleotide
(const ColorType& _C, const PointTotal& _P, const int& _N1, const int& _N2, const int& _N3):
m_BkColor(_C), m_MsrPointTotal(_P),
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
        if (_C == Nits)  //Nits
        {
            SetPara(PA_NitsLv, _N1);
            SetPara(PA_NitsDir, _N2); 
            m_paraStr.Format("_�Ƕ�: %d%s", _N1, (_N2)?"��":"��");
            break;
        }
        if (_C == Dark)  //�¦�9�I
        {
            SetPara(PA_FEover, _N1);
            m_paraStr.Format("_�K��");
            break;
        }
		if (_C == White)  //�զ�9�I
		{
			if ( (_N2 == FT_1overN) || (_N1 == 0) )
			{
				SetPara(PA_FEover, _N1);
				if (_N1 == 0)
					m_paraStr.Format("_�K��");
				else
					m_paraStr.Format("_����: 1/%d", _N1);
			}
			else if (_N2 == FT_Ncm)
			{
				SetPara(PA_FElength, _N1);
				m_paraStr.Format("_����: %dcm", _N1);
			}

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
        m_paraStr.Format("_");
    }
}

Nucleotide::~Nucleotide()
{
    m_Parameters.clear();
}

const ColorType Nucleotide::GetBackColor() const        { return m_BkColor;     }
void      Nucleotide::SetBackColor(const ColorType& clr) { m_BkColor = clr;      }

const PointTotal Nucleotide::GetMsrPointTotal() const        { return m_MsrPointTotal;  }
void Nucleotide::SetMsrPointTotal(const PointTotal& msrPtTotal)    { m_MsrPointTotal = msrPtTotal; }
const CString Nucleotide::GetStrMsrPointTotal() const
{
    CString total;
    switch(m_MsrPointTotal)
    {
    case Pn1:     total.Format("�����I");   break;
    case Pn4:     total.Format("  4�I");   break;
    case Pn5:     total.Format("  5�I");   break;
    case Pn9:     total.Format("  9�I");   break;
    case Pn13:    total.Format(" 13�I");   break;
    case Pn21:    total.Format(" 21�I");   break;
    case Pn25:    total.Format(" 25�I");   break;
    case Pn49:    total.Format(" 49�I");   break;
    case PnGamma: total.Format("Gamma");   break;
    case NoPn:
    default:      total.Format("���w�q�I��");
    }
    return total;
}

const CString Nucleotide::GetStrBackColor() const
{
    CString bkColor;
    switch(m_BkColor)
    {
    case White:  bkColor.Format("�զ�");   break;
    case Red:    bkColor.Format("����");   break;
    case Green:  bkColor.Format("���");   break;
    case Blue:   bkColor.Format("�Ŧ�");   break;
    case Dark:   bkColor.Format("�¦�");   break;
    case Nits:   bkColor.Format("Nits");  break;
    case CrsTlkW:bkColor.Format("CrossTalk�կx��"); break;
    case CrsTlkD:bkColor.Format("CrossTalk�¯x��"); break;
    case CrsTlk: bkColor.Format("CrossTalk�L�x��"); break;
//     case JNDX:     bkColor.Format("JND�Q�r"); break;
//     case JND:    bkColor.Format("JND�ť�"); break;
    case NoColor:
    default:     bkColor.Format("���w�q��m");
    }
    return bkColor;
}

const CString Nucleotide::GetStrPara() const
{
    return m_paraStr;
}

const BOOL Nucleotide::operator==(const Nucleotide& vCar) const
{
    BOOL b(FALSE);
    std::vector<int>::const_iterator vCitor = vCar.m_Parameters.begin();
    if ((GetMsrPointTotal() == vCar.GetMsrPointTotal()) && (GetBackColor()  == vCar.GetBackColor() ))
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
    SetMsrPointTotal(vCar.GetMsrPointTotal());
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

const CString Nucleotide::ShowMe() const
{
    CString str, Para;
    //ex: �¦�25�I, 6, 10...
    
    str.Format("%s%s%s %d, %d, %d, %d, %d, %d\n",\
        GetStrBackColor(), GetStrMsrPointTotal(), GetStrPara(),\
        m_Parameters[0], m_Parameters[1], m_Parameters[2], m_Parameters[3], m_Parameters[4], m_Parameters[5], m_Parameters[6], m_Parameters[7], m_Parameters[8], m_Parameters[0]);
    return str;
    //type: ������type��
}
