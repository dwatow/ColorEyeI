#include "StdAfx.h"
#include "CartridgeFinder.h"

//////////////////////////////////////////////////////////////////////////
const BOOL CartridgeFinder::Reconstr(CString& bkColor, CString& PointTotal, CString& MsrPointIndex, CString& Parameter)
{
//     CString sample;
//     multi2single(bkColor, PointTotal, MsrPointIndex, Parameter, sample);

    if (color(bkColor) & pointTotal(PointTotal) & msrIndex(MsrPointIndex) & para(Parameter))
        return TRUE;
    else
        return FALSE;
}

// void CartridgeFinder::multi2single(CString bkColorIn, CString pointTotalIn, CString msrPointIndexIn, CString parameterIn, CString& sampleOut)
// {
//     color(bkColorIn);
//     pointTotal(pointTotalIn);
//     msrIndex(msrPointIndexIn);
//     para(parameterIn);
// }

// const BOOL CartridgeFinder::m2sColor(CString bkColor)
// { return color(bkColor); }
// const BOOL CartridgeFinder::m2sPointTotal(CString pointTotalIn)
// { return pointTotal(pointTotalIn); }
// const BOOL CartridgeFinder::m2sMsrIndex(CString msrPointIndexIn)
// { return reMsrIndex(msrPointIndexIn); }
// const BOOL CartridgeFinder::m2sPara(CString parameterIn)
// { return rePara(parameterIn); }

//////////////////////////////////////////////////////////////////////////
const BOOL CartridgeFinder::Reconstr(CString& sample)
{
    CString clr = sample;
    CString pt = sample;
    CString mi = sample;
    CString pr = sample;
    if (Reconstr(clr, pt, mi, pr))
    {
        sample.Format("%s%s%s%s", clr, pt, mi, pr);
        return TRUE;
    }
    else
        return FALSE;
}

const int CartridgeFinder::color(CString& strResult)
{
    int colorName(0);
    switch(reColor(strResult))
    {
    case rCL_Se:        reColorSe(strResult);        return TRUE;
	case rCL_ShortCode: reColorShortCode(strResult); return TRUE;
    case rCL_CrossTalk: reColorCrossTalk(strResult); return TRUE;
    case rCL_Nits:      reColorNits(strResult);      return TRUE;
    default:
//        ASSERT(0);
        return FALSE;
    }
}

const reColorType CartridgeFinder::reColor(CString strResult)
{
    if ( (strResult.Find("Cross") >= 0) || (strResult.Find("cross") >= 0) )
        return rCL_CrossTalk;
    else if ( (strResult.Find("Nits") >= 0) || (strResult.Find("nits") >= 0) )
        return rCL_Nits;
    else if ( strResult.Find("��") >= 0)
        return rCL_Se;
    else if ( ((strResult.Find("��") >= 0)||
               (strResult.Find("��") >= 0)||
               (strResult.Find("��") >= 0)||
               (strResult.Find("��") >= 0)||
               (strResult.Find("��") >= 0)) && (strResult.GetLength() == 2) )
        return rCL_ShortCode;
    else
    {
        strResult.Empty();
        return rCL_NoMatch;
    }
}

void CartridgeFinder::reColorCrossTalk(CString& strResult)
{
    if ( (strResult.Find("W") >= 0) || (strResult.Find("w") >= 0))
        strResult.Format("CrossTalk�կx��");
    else if ( (strResult.Find("D") >= 0) || (strResult.Find("d") >= 0))
        strResult.Format("CrossTalk�¯x��");
    else
        strResult.Format("CrossTalk�L�x��");
}
void CartridgeFinder::reColorNits(CString& strResult)
{ strResult.Format("Nits"); }
void CartridgeFinder::reColorSe(CString& strResult)
{ strResult.Format("%s��", strResult.Left(strResult.Find("��")) ); }
void CartridgeFinder::reColorShortCode(CString& strResult)
{
    strResult += "��";
}
//////////////////////////////////////////////////////////////////////////
const BOOL CartridgeFinder::pointTotal(CString& strResult)
{
    switch(rePointTotal(strResult))
    {
    case rPT_Normal:      rePointTotalNormal(strResult);  return TRUE;
    case rPT_Gamma:       rePointTotalGamma(strResult);   return TRUE;
    case rPT_Center:      rePointTotalCenter(strResult);  return TRUE;
	case rPT_PureDigital: rePointTotalPureDig(strResult); return TRUE;
    case rPT_Word:        rePointTotalWord(strResult);    return TRUE;
    default:
        return FALSE;
    }
}

const rePtTotalType CartridgeFinder::rePointTotal(CString strResult)
{ 
    int dianIndex(0);
    if ( (strResult.Find("Gamma") >= 0) || (strResult.Find("gamma")  >= 0) )
        return rPT_Gamma;
    else if ( strResult.Find("�I") >= 0)
    {
         dianIndex = strResult.Find("�I");
//          �����I;
//          1�I;
//          12�I;
//          �T�I;
         CString centerSample = strResult.Mid(dianIndex-6, 6);
         CString oneSample = strResult.Mid(dianIndex-2, 2);
         CString wordSample = strResult.Mid(dianIndex-2, 2);

         if ( (atoi(oneSample) == 1) || (centerSample.Find("����") >= 0) )
             return rPT_Center;
         else if (atoi(wordSample) == 0)
             return rPT_Word;
         else
             return rPT_Normal;        
    }
	//���}��
	else if (isNumber(strResult))
		return rPT_PureDigital;
    else
    {
        strResult.Empty();
        return rPT_NoMatch;
    }

//     if ( atoi(strResult.Mid(strResult.Find("�I")-2, 2)) == 0 )
//         return rPT_Word;
//     else if ( ((strResult.Find("�����I") >= 0)&&(strResult.GetLength() == 6)) || 
//               ((strResult.Find("1�I")   >= 0)&&(strResult.GetLength() == 3)) )
//     {
//         strResult.Mid(strResult.Find("�I"))
//         return rPT_Center;
//     }
//     else if ( strResult.Find("�I") >= 0)
//         return rPT_Normal;
}

void CartridgeFinder::rePointTotalGamma(CString& strResult)
{ strResult.Format("Gamma"); }
void CartridgeFinder::rePointTotalCenter(CString& strResult)
{ strResult.Format("�����I"); }
void CartridgeFinder::rePointTotalNormal(CString& strResult)
{
    const int colorName(strResult.Find("�I"));
    int digitsCount(0);
        if (strResult.Left(colorName).GetLength() > 3)
        {
            //�r��b�T��Ʀr�e���O���r�A���ন�Ʀr�P�_
            if ( atoi(strResult.Mid(colorName-(3), 3)) >100)
                digitsCount = 3;
            else if ( atoi(strResult.Mid(colorName-(2), 2)) >10)
                digitsCount = 2;
            else if ( atoi(strResult.Mid(colorName-(1), 1)) > 0)
                digitsCount = 1;
        }
        else
            //�T��ƥH��
            digitsCount = strResult.Left(colorName).GetLength();
        
        strResult.Format("%3s�I", strResult.Mid(colorName-(digitsCount), digitsCount)  );
}

void CartridgeFinder::rePointTotalWord(CString& strResult)
{
    const int DianIndex(strResult.Find("�I"));
    CString Word;
    Word.Format("%s", strResult.Left(DianIndex));

         if ( (DianIndex - Word.Find("�@") == 2) && (Word.Find("�@") >= 0) ) strResult.Format("�����I");
    else if ( (DianIndex - Word.Find("�G") == 2) && (Word.Find("�G") >= 0) ) strResult.Format("2�I");
    else if ( (DianIndex - Word.Find("�T") == 2) && (Word.Find("�T") >= 0) ) strResult.Format("3�I");
    else if ( (DianIndex - Word.Find("�|") == 2) && (Word.Find("�|") >= 0) ) strResult.Format("4�I");
    else if ( (DianIndex - Word.Find("��") == 2) && (Word.Find("��") >= 0) ) strResult.Format("5�I");
    else if ( (DianIndex - Word.Find("��") == 2) && (Word.Find("��") >= 0) ) strResult.Format("6�I");
    else if ( (DianIndex - Word.Find("�C") == 2) && (Word.Find("�C") >= 0) ) strResult.Format("7�I");
    else if ( (DianIndex - Word.Find("�K") == 2) && (Word.Find("�K") >= 0) ) strResult.Format("8�I");
    else if ( (DianIndex - Word.Find("�E") == 2) && (Word.Find("�E") >= 0) ) strResult.Format("9�I");
    else if ( (DianIndex - Word.Find("�Q") == 2) && (Word.Find("�Q") >= 0) ) strResult.Format("10�I");
    else
        strResult.Format("");
}

void CartridgeFinder::rePointTotalPureDig(CString& strResult)
{
	int Digital = atoi(strResult);
	if (Digital == 1)
		strResult.Format("�����I");
	else
		strResult.Format("%3d�I", Digital);
}

//////////////////////////////////////////////////////////////////////////
const BOOL CartridgeFinder::msrIndex(CString& strResult)
{
    switch( reMsrIndex(strResult) )
    {
    case rMI_Dian:
        reMsrIndexDian(strResult);
        return TRUE;
    case rMI_Normal:
        reMsrIndexNormal(strResult);
        return TRUE;
	case rMI_PureDigital:
		reMsrIndexPureDig(strResult);
		return TRUE;
    case rMI_NoMatch:
    default:
        return FALSE;
    }
}

const reMrIndexType CartridgeFinder::reMsrIndex(CString strResult)
{
    //�զ�9�I��3�I
    const int DeeIndex(strResult.Find("��"));
    strResult = strResult.Right(strResult.GetLength() - DeeIndex); //��x�I
//    DeeLength = strResult.Right(DeeIndex+2).GetLength();

    if ( strResult.Find("��") >= 0 )
    {
        if ( (strResult.FindOneOf("��") < strResult.FindOneOf("�I")) &&
             (strResult.FindOneOf("�I") >= 0) )
            return rMI_Dian;
        else
            return rMI_Normal;
    }
	else if (isNumber(strResult))
		return rMI_PureDigital;
    else
    {
        strResult.Empty();
        return rMI_NoMatch;
    }
}

void CartridgeFinder::reMsrIndexDian(CString& strResult)
{
    strResult = strResult.Right(strResult.GetLength() - strResult.Find("��")); //��x�I
    const int deeIndex(strResult.Find("��"));
    const int dianIndex( strResult.Find("�I") );
    strResult.Format(", ��%s�I", strResult.Mid(deeIndex +2, dianIndex-deeIndex -2) );
}

void CartridgeFinder::reMsrIndexNormal(CString& strResult)
{
    int colorName( strResult.FindOneOf("��") );
    colorName += 2;

    int digitsCount(0);

    if ( atoi(strResult.Mid(colorName, 3) ) >100)
        digitsCount = 3;
    else if ( atoi(strResult.Mid(colorName, 2) ) >10)
        digitsCount = 2;
    else if ( atoi(strResult.Mid(colorName, 1) ) )
        digitsCount = 1;
    strResult.Format(", ��%s�I", strResult.Mid(colorName, digitsCount) );
}

void CartridgeFinder::reMsrIndexPureDig(CString& strResult)
{
	int Digital = atoi(strResult);
	strResult.Format(", ��%d�I", Digital);
}

//////////////////////////////////////////////////////////////////////////
const BOOL CartridgeFinder::para(CString& strResult)
{
    switch( rePara(strResult) )
    {
    case rPM_Over:      reParaOver(strResult);      return TRUE;
    case rPM_Length:    reParaLength(strResult);    return TRUE;
    case rPM_NoPara:    reParaNoPara(strResult);    return TRUE;
    case rPM_Nits:      reParaNits(strResult);      return TRUE;
    case rPM_Welt:      strResult.Format("_�K��");  return TRUE;
    case rPM_paraGamma: reParaGamma(strResult);     return TRUE;
	case rPM_PureDigital: reParaPureDig(strResult); return TRUE;
    case rMI_NoMatch:
    default:
        return FALSE;
    }
}

const reParaType CartridgeFinder::rePara(CString strResult)
{
    strResult = strResult.Right(strResult.GetLength() - strResult.Find("_"));

    if ( (strResult.GetLength() == 1) && ((strResult.Find("_") >= 0)||(strResult.Find(" ") >= 0)))
    { return rPM_NoPara; }
    else if (strResult.Find("����") >= 0)
    {
        strResult = strResult.Right(strResult.GetLength() - strResult.Find("����") -6);    

        if ( (strResult.Find("1/") >= 0) && (isNumber(strResult.Right(strResult.GetLength() - strResult.Find("1/") -2))) )
        { return rPM_Over; }
        else if (isNumber(strResult))
        { return rPM_Length; }
    }
    else if ((strResult.Find("�K��") >= 0) || ((strResult.GetLength() == 1) && (strResult.Find("0") >= 0)))
    { return rPM_Welt; }
    else if ( (strResult.Find("����") >= 0) && (strResult.Find("~") >= 0))
    { return rPM_paraGamma; }
    else if ((strResult.Find("+") >= 0) || (strResult.Find("��") >= 0) || (strResult.Find("-") >= 0) || (strResult.Find("��") >= 0) )
    { return rPM_Nits; }
	else if ( (strResult.Find("1/") >= 0) && (isNumber(strResult.Right(strResult.GetLength() - strResult.Find("1/") -2))) )
	{ return rPM_Over; }
	//���}��
    else if ( strResult.Right(strResult.GetLength() - (strResult.Find(" ")+1)).Find(" ") >= 0 )
    { return rPM_paraGamma; }
	else if (isNumber(strResult))
	{ return rPM_PureDigital; }
		//(strResult.Find(" ") >= 0) != (strResult.FindOneOf(" ") >= 0)

    strResult.Format(" ");
    return rPM_NoMatch;
}

BOOL CartridgeFinder::isNumber(const CString& strResult)
{
    if (atoi(strResult) >= 1000 && strResult.GetLength() == 4)
        return TRUE;
    else if (atoi(strResult) >= 100 && strResult.GetLength() == 3)
        return TRUE;
    else if (atoi(strResult) >= 10 && strResult.GetLength() == 2)
        return TRUE;
    else if (atoi(strResult) > 0 && strResult.GetLength() == 1)
        return TRUE;
    else if (strResult.Find("0") >= 0)
    {
//         ASSERT(0);
        return TRUE;
    }
    else
        return FALSE;
}

void CartridgeFinder::reParaOver(CString& strResult)
{
    strResult = strResult.Right(strResult.GetLength() - strResult.Find("/") -1);
    strResult.Format("_����: 1/%s", strResult.Right(strResult.GetLength() - strResult.Find("/") -1));
}

void CartridgeFinder::reParaLength(CString& strResult)
{
    strResult = strResult.Right(strResult.GetLength() - strResult.Find("����") -6);
    int FENumber(atoi(strResult));
    strResult.Format("_����: %dmm", FENumber);
}

void CartridgeFinder::reParaNits(CString& strResult)
{
    int signIndex(0);
    CString sign;
    if ( strResult.Find("+") >= 0 )
    {
        signIndex = strResult.Find("+");
        sign.Format("��");
    }
    else if ( strResult.Find("��") >= 0 )
    {
        signIndex = strResult.Find("��");
        sign.Format("��");
    }
    else if ( strResult.Find("-") >= 0 )
    {
        signIndex = strResult.Find("-");
        sign.Format("��");
    }
    else if ( strResult.Find("��") >= 0 )
    {
        signIndex = strResult.Find("��");
        sign.Format("��");
    }

    int grayLevel(0);
    if ( atoi(strResult.Mid(signIndex-3, 3)) >= 100 )
        grayLevel = atoi(strResult.Mid(signIndex-3, 3));
    else if ( atoi(strResult.Mid(signIndex-2, 2)) >= 10 )
        grayLevel = atoi(strResult.Mid(signIndex-2, 2));
    else if ( atoi(strResult.Mid(signIndex-1, 1)) > 0 )
        grayLevel = atoi(strResult.Mid(signIndex-1, 1));

    if ( signIndex && grayLevel)
        strResult.Format("_�Ƕ�: %d%s",grayLevel, sign);
    else
        strResult.Format("�~�P��Nits�Ѽ�");
}

void CartridgeFinder::reParaNoPara(CString& strResult)
{
    strResult.Format("_");
}

void CartridgeFinder::reParaGamma(CString& strResult)
{
	//0~255, ����255
	int fristIndex(0), secondIndex(0);
	CString fristSign(" ");
	CString secondSign(" ");

	if ( (strResult.Find("����") >= 0) && (strResult.Find("~") >= 0))
	{
		strResult = strResult.Right(strResult.GetLength() - strResult.Find("_"));

		fristSign = "~";
		secondSign = ", ����";
		
		fristIndex = strResult.Find(fristSign);
		secondIndex = strResult.Find(secondSign);
		
	}
	//0 255 255
	else if ( strResult.Right(strResult.GetLength() - (strResult.Find(" ")+1)).Find(" ") >= 0 )
	{
		fristSign = " ";
		secondSign = " ";

		fristIndex = strResult.Find(fristSign);
		secondIndex = strResult.Right(strResult.GetLength() - (fristIndex+fristSign.GetLength())).Find(" ") + fristIndex+fristSign.GetLength();
	}
	
	int numberBegin = atoi(strResult.Left(fristIndex));
	int numberEnd   = atoi(strResult.Mid(fristIndex+fristSign.GetLength(), secondIndex-(fristIndex+fristSign.GetLength())));
	int numberDiv   = atoi(strResult.Mid(secondIndex+secondSign.GetLength()));

	strResult.Format("_%d~%d, ����%d", numberBegin, numberEnd, numberDiv);
}

void CartridgeFinder::reParaPureDig(CString& strResult)
{
	strResult.Format("_����: %dmm", atoi(strResult));
}