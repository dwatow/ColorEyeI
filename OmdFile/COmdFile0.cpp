// OmdFile1.cpp: implementation of the COmdFile0 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "COmdFile0.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////////
//輸出輸入文件格式
//oForm()  output form
//iForm()  input  form
//////////////////////////////////////////////////////////////////////////

BOOL COmdFile0::Open(LPCTSTR _S, CFileException& _Fx)
{ 
	GetOpenSample(_S, _Fx);
	openWhichKindOmefile();
	return  m_Omd->Open(_S, _Fx); 
};

//BOOL COmdFile0::Save(CString _S, CFileException& _Fx, OmdCarData _D)
BOOL COmdFile0::Save(LPCTSTR _S, CFileException& _Fx, RNA& _R)
{ 
	saveWhichKindOmefile(_R);  //如何選用適當的呢？

	CString savePathName;
	savePathName.Format("%s", _S);
	if (m_GmOmd != 0)
	{
		CString path;
		path = savePathName.Left( savePathName.ReverseFind('.'));

		CString pathGm;
		pathGm = path + "_gamma.omd";

		return m_GmOmd->Save(pathGm, _Fx) && m_Omd->Save(_S, _Fx);
	}
	else
		return m_Omd->Save(_S, _Fx);
};

void COmdFile0::GetOpenSample(LPCTSTR _path, CFileException& _fx)
{
	CTxtFile *fpTxt = new CTxtFile();

	fpTxt->Open(_path, _fx);
	fpTxt->oTxtData(m_dTxt);
	fpTxt->Close();
	delete fpTxt;
};

void COmdFile0::openWhichKindOmefile()
{
	KindOfOmd omdKind;
	if (m_dTxt.at(0).Find(':') != -1)
		omdKind = OMD_OLD;
	else if (m_dTxt.at(0).Find("Gamma") != -1)
		omdKind = OMD_GAMMA;
	else
		omdKind = OMD_AtYPE;

	switch(omdKind)
	{
		case OMD_AtYPE: m_Omd = new COmdFile1(OMD_AtYPE); break;
		case OMD_GAMMA: m_Omd = new COmdFileGm();         break;
		case OMD_OLD:
		default:        m_Omd = new COmdFile1(OMD_OLD);
	}
}

//void COmdFile0::saveWhichKindOmefile(OmdCarData _D)
void COmdFile0::saveWhichKindOmefile(RNA& _R)
{
//	KindOfOmd omdKind = OMD_AtYPE;
	CString str;
	for (int i = 0; i < 256; ++i)
	{
		str.Format("%d", i);
		if ((_R.Find("白","gamma",str,"0 255 255").GetSqncArea() != AA_00) ||  //有量測 = .GetMsrFlowNo() != 99
			(_R.Find("紅","gamma",str,"0 255 255").GetSqncArea() != AA_00) ||
			(_R.Find("綠","gamma",str,"0 255 255").GetSqncArea() != AA_00) ||
			(_R.Find("藍","gamma",str,"0 255 255").GetSqncArea() != AA_00))
		{
			//omdKind = OMD_GAMMA;
			m_GmOmd = new COmdFileGm();
			break;
		}
	}

	m_Omd = new COmdFile1(OMD_AtYPE);

// 	switch(omdKind)
// 	{
// 	case OMD_GAMMA: m_GmOmd = new COmdFileGm();  break;
// 	default:		m_Omd = new COmdFile1(OMD_AtYPE);
// 	}	
}