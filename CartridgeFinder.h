#ifndef CARTRIDGEFINDER_H
#define CARTRIDGEFINDER_H

enum reColorType{ rCL_NoMatch, rCL_Se, rCL_CrossTalk, rCL_Nits, rCL_ShortCode };
enum rePtTotalType{ rPT_NoMatch, rPT_Normal, rPT_Gamma, rPT_Center, rPT_Word, rPT_PureDigital };
enum reMrIndexType{ rMI_NoMatch, rMI_Normal, rMI_Dian, rMI_PureDigital };
enum reParaType{ rPM_NoMatch, rPM_NoPara, rPM_Over, rPM_Length, rPM_Nits, rPM_Welt, rPM_paraGamma, rPM_PureDigital };

class CartridgeFinder
{
public:
	const BOOL Reconstr(CString&, CString&, CString&, CString&);
	const BOOL Reconstr(CString&);
// private:
// 	void multi2single(CString, CString, CString, CString, CString&);
// 	const BOOL m2sColor(CString);
// 	const BOOL m2sPointTotal(CString);
// 	const BOOL m2sMsrIndex(CString);
// 	const BOOL m2sPara(CString);

private:
	const BOOL color(CString&);
	const reColorType reColor(CString);
	void reColorCrossTalk(CString&);
	void reColorNits(CString&);
	void reColorSe(CString&);
	void reColorShortCode(CString&);
private:
	const BOOL pointTotal(CString&);
	const rePtTotalType rePointTotal(CString);
	void rePointTotalGamma(CString&);
	void rePointTotalCenter(CString&);
	void rePointTotalWord(CString&);
	void rePointTotalNormal(CString&);
	void rePointTotalPureDig(CString&);
private:
	const BOOL msrIndex(CString&);
 	const reMrIndexType reMsrIndex(CString);
	void reMsrIndexDian(CString&);
	void reMsrIndexNormal(CString&);
	void reMsrIndexPureDig(CString&);
private:
	const BOOL para(CString&);
	const reParaType rePara(CString);
	void reParaOver(CString&);
	void reParaLength(CString&);
	void reParaNoPara(CString&);
	void reParaGamma(CString&);
	void reParaNits(CString&);
	void reParaPureDig(CString&);
private:
	BOOL isNumber(const CString& strResult);
};


#endif 