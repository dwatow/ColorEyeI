#include "stdafx.h"
#include "Nucleotide.h"

// #define _DEBUG
// #ifdef _DEBUG
// 
// #endif

//std::vector<Nucleotide>  == DNA
/*******************************************
 *  Define PointSet Class member function  *
 *******************************************/

Nucleotide::Nucleotide(ColorType cy, PointNum pn, int para1, int para2, int para3):
m_BkColor(cy), m_MsrFlowNum(pn),
m_Parameters(PA_Max, -1)
{

	if (pn == PnGamma)
	{
		SetPara(PA_GmaBegin, para1);
		SetPara(PA_GmaEnd,   para2);
		SetPara(PA_GmaAvg,   para3);
	}
	else
		switch(cy)
		{
		case JND:
		case JNDX:      SetPara(PA_JndGrayLv, para1); break;
		case Nits: 
			SetPara(PA_NitsNum, para1);
			SetPara(PA_NitsDir, para1); break;
		case CrsTlk:
		case CrsTlkD:
		case CrsTlkW:
		default:        SetPara(PA_FEover, para1);
		}
}

Nucleotide::~Nucleotide()
{
	m_Parameters.clear();
}

// UINT Nucleotide::GetOrigSeqc() const              { return m_OrigSeqc;    }
// void Nucleotide::SetOrigSeqc(UINT Orig)           { m_OrigSeqc = Orig;    }


ColorType Nucleotide::GetBackColor() const        { return m_BkColor;     }
void      Nucleotide::SetBackColor(ColorType clr) { m_BkColor = clr;      }

// void Nucleotide::SetArea(UINT ac)                 { m_AreaCode = ac;      }
// UINT Nucleotide::GetArea() const                  { return m_AreaCode;    } 

PointNum Nucleotide::GetMsrFlowNum() const        { return m_MsrFlowNum;  }
void Nucleotide::SetMsrFlowNum(PointNum mfNum)    { m_MsrFlowNum = mfNum; }

CString Nucleotide::GetStrPointNum() const
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

CString Nucleotide::GetStrColorType() const
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
	case CrsTlkW:
	case CrsTlkD:
	case CrsTlk: Color.Format("CrossTalk"); break;
	case JNDX:
	case JND:    Color.Format("JND"); break;
	case NoColor:
	default:     Color.Format("���w�q��m");
    }
	return Color;
}

BOOL Nucleotide::operator==(const Nucleotide& vCar)
{
	return ( (GetMsrFlowNum() == vCar.GetMsrFlowNum()) && 
		     (GetBackColor()  == vCar.GetBackColor() ) ) ? TRUE : FALSE;
};

void Nucleotide::operator= (const Nucleotide& vCar)
{
	SetMsrFlowNum(vCar.GetMsrFlowNum());
	SetBackColor(vCar.GetBackColor());
}

void Nucleotide::SetPara(ParaOfPara Parameter, int FromEdge)
{
	m_Parameters[Parameter] = FromEdge;
}

int Nucleotide::GetPara(ParaOfPara Parameter)
{
	return m_Parameters[Parameter];
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
// 	case JND:     color.Format("JND"); break;
// 	case JNDX:     color.Format("JNDX"); break;
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