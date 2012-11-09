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

BOOL COmdFile0::Open(CString _S, CFileException& _Fx)
{ 
	GetOpenSample(_S, _Fx);
	openWhichKindOmefile();
	return  m_Omd->Open(_S, _Fx); 
};

BOOL COmdFile0::Save(CString _S, CFileException& _Fx, OmdCarData _D)
{ 
	saveWhichKindOmefile(_D);  //問題出在這！如何選用適當的呢？

	if (m_GmOmd != 0)
	{
		CString pathGm;
		CString path;
		path = _S.Left( _S.ReverseFind('.'));
		pathGm.Format("%s_gamma.omd", path);
		return m_GmOmd->Save(pathGm, _Fx) && m_Omd->Save(_S, _Fx);
	}
	else
		return m_Omd->Save(_S, _Fx); 
};

void COmdFile0::GetOpenSample(CString _path, CFileException& _fx)
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

void COmdFile0::saveWhichKindOmefile(OmdCarData _D)
{
//	KindOfOmd omdKind = OMD_AtYPE;

	for (int i = 0; i < 256; ++i)
	{
		if ((_D.At(White, PnGamma, i).GetMsrFlowNo() != 99) ||  //有量測 = .GetMsrFlowNo() != 99
			(_D.At(Red  , PnGamma, i).GetMsrFlowNo() != 99) ||
			(_D.At(Green, PnGamma, i).GetMsrFlowNo() != 99) ||
			(_D.At(Blue , PnGamma, i).GetMsrFlowNo() != 99))
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