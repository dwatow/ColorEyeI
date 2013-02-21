#include "stdafx.h"
#include "Nucleotide.h"


/*******************************************
 *  Define PointSet Class member function  *
 *******************************************/

Nucleotide::Nucleotide(ColorType cy, PointNum pn, int para1, int para2, int para3):
m_BkColor(cy), m_MsrFlowNum(pn),
m_Parameters(PA_Max, -1)
{
	//參數填入機制
	switch (pn)
	{
	case PnGamma:
		SetPara(PA_GmaBegin, para1);
		SetPara(PA_GmaEnd,   para2);
		SetPara(PA_GmaAvg,   para3);
		m_paraStr.Format("_%d~%d, 平分%d", para1, para2, para3);
		break;
	//有離邊
	case Pn4:
		if (cy != Nits)
			break;	
	case Pn5:
	case Pn9:
		if (cy == Nits)
		{
			SetPara(PA_NitsNum, para1);
			SetPara(PA_NitsDir, para2); 
			m_paraStr.Format("_灰階: %d%s", para1, (para2)?"↑":"↓");
			break;
		}

	case Pn13:
	case Pn25:
		SetPara(PA_FEover, para1);
		if (para1 == 0)
			m_paraStr.Format("_貼邊");
		else
			m_paraStr.Format("_離邊: 1/%d", para1);
		break;
	//無離邊
	//沒有特別定義，就成為空字串

	case Pn1:
		if (cy == JND || cy == JNDX)
		{
			SetPara(PA_JndGrayLv, para1); 
			m_paraStr.Format("_灰階: %d", para1);
			break;
		}
	case Pn21:
	case Pn49:
	default:
		m_paraStr.Empty();

	}
}

Nucleotide::~Nucleotide()
{
	m_Parameters.clear();
}

ColorType Nucleotide::GetBackColor() const        { return m_BkColor;     }
void      Nucleotide::SetBackColor(ColorType clr) { m_BkColor = clr;      }

PointNum Nucleotide::GetMsrFlowNum() const        { return m_MsrFlowNum;  }
void Nucleotide::SetMsrFlowNum(PointNum mfNum)    { m_MsrFlowNum = mfNum; }

CString Nucleotide::GetStrPointNum() const
{
    CString Num;
	switch(m_MsrFlowNum)
	{
	case Pn1:  Num.Format("中心點");   break;
	case Pn4:  Num.Format("  4點");   break;
	case Pn5:  Num.Format("  5點");   break;
	case Pn9:  Num.Format("  9點");   break;
	case Pn13: Num.Format(" 13點");   break;
	case Pn21: Num.Format(" 21點");   break;
	case Pn25: Num.Format(" 25點");   break;
	case Pn49: Num.Format(" 49點");   break;
	case PnGamma: Num.Format("Gamma");   break;
	case NoPn:
	default:   Num.Format("未定義點位");
    }
	return Num;
}

CString Nucleotide::GetStrColorType() const
{
    CString Color;
	switch(m_BkColor)
	{
	case White:  Color.Format("白色");   break;
	case Red:    Color.Format("紅色");   break;
	case Green:  Color.Format("綠色");   break;
	case Blue:   Color.Format("藍色");   break;
	case Dark:   Color.Format("黑色");   break;
	case Nits:   Color.Format("Nits");  break;
	case CrsTlkW:
	case CrsTlkD:
	case CrsTlk: Color.Format("CrossTalk"); break;
	case JNDX:
	case JND:    Color.Format("JND"); break;
	case NoColor:
	default:     Color.Format("未定義色彩");
    }
	return Color;
}

CString Nucleotide::GetStrPara() const
{
	return m_paraStr;
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

int Nucleotide::GetPara(ParaOfPara Parameter) const
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
//     str.Format("顏色項目=%s, 點位/所有: %d/%d, 區域碼=%d",\
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