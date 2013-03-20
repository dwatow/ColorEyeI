#include "stdafx.h"
#include "Nucleotide.h"


/*******************************************
 *  Define PointSet Class member function  *
 *******************************************/

Nucleotide::Nucleotide(ColorType _C, PointNum _P, int _N1, int _N2, int _N3):
m_BkColor(_C), m_MsrFlowNum(_P),
m_Parameters(PA_Max, -1)
{
	//參數填入機制
	switch (_P)
	{
	case PnGamma:
		SetPara(PA_GmaBegin, _N1);
		SetPara(PA_GmaEnd,   _N2);
		SetPara(PA_GmaAvg,   _N3);
		m_paraStr.Format("_%d~%d, 平分%d", _N1, _N2, _N3);
		break;
	//有離邊
	case Pn4:
		if (_C != CrsTlk && _C != CrsTlkD && _C != CrsTlkW)
			break;
	case Pn5:
	case Pn9:
		if (_C == Nits)
		{
			SetPara(PA_NitsNum, _N1);
			SetPara(PA_NitsDir, _N2); 
			m_paraStr.Format("_灰階: %d%s", _N1, (_N2)?"↓":"↑");
			break;
		}
		if (_C == Dark)
		{
			SetPara(PA_FEover, 0);
			m_paraStr.Format("_貼邊");
			break;
		}

	case Pn13:
	case Pn21:
	case Pn25:
		SetPara(PA_FEover, _N1);
		if (_C == Dark) SetPara(PA_D25RectSide, _N2);
		if (_N1 == 0)
			m_paraStr.Format("_貼邊");
		else
			m_paraStr.Format("_離邊: 1/%d", _N1);
		break;
	//無離邊
	//沒有特別定義，就成為空字串

	case Pn1:
		if (_C == JND || _C == JNDX)
		{
			SetPara(PA_JndGrayLv, _N1); 
			m_paraStr.Format("_灰階: %d", _N1);
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
	case CrsTlkW:Color.Format("CrossTalk白矩形"); break;
	case CrsTlkD:Color.Format("CrossTalk黑矩形"); break;
	case CrsTlk: Color.Format("CrossTalk無矩形"); break;
	case JNDX:	 Color.Format("JND十字"); break;
	case JND:    Color.Format("JND空白"); break;
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

CString Nucleotide::showMe()
{
    CString str, Para;
    //ex: 黑色25點, 6, 10...
    
    str.Format("%s%s%s", GetStrColorType(), GetStrPointNum(), GetStrPara());
    for ( std::vector<int>::iterator it  = m_Parameters.begin();
	it != m_Parameters.end();
	++it)
    {
        Para.Format(" %d", *it);
        str += Para;
    }
    return str + "\n";
	
    //type: 直接用type看
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