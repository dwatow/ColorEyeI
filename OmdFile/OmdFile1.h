// OmdFile1.h: interface for the COmdFile class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OMDFILE1_H__5E9E8D8E_4BB9_40C8_BEE3_2756DA9A7E76__INCLUDED_)
#define AFX_OMDFILE1_H__5E9E8D8E_4BB9_40C8_BEE3_2756DA9A7E76__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TxtFile.h"
#include "../xMsrPoint/Cartridge.h"

class COmdFile1 : public CTxtFile
{

//////////////////////////////////////////////////////////////////////////
    //��J�禡
/*      ��J����ؤ覡      *
 *        1. ��vector��     *
 *        2. Ū���ɮ׶i��   */
public:
    //�q�O�����J���
    COmdFile1(); //�}�s�ɮסA�åB��JData
//    COmdFile1();
//    virtual ~COmdFile1();

    BOOL Open(CString);    //�qOmd�ɿ�J���
private:
    void iForm();
    BOOL isOldForm();  //�P�_�O���OLabview��X����
//////////////////////////////////////////////////////////////////////////
//��X
/*      ��X����ؤ覡      *
 *        1. ��Xvector��   *
 *        2. �s���ɮ׶i��   */
public:
    //��X��ƨ�O����
    //����U�O��Ʀ�]�̩w�q���ǡ^
    //����Y�@��᭱�A�γ��ͦ���ͦ�

	//�i��n�屼�����(2)
    std::vector<Cartridge> AddMsrData(ColorType, PointNum, std::vector<Cartridge>& );
    std::vector<Cartridge> AddMsrData(ColorType clrtye, PointNum ptN);

    BOOL Save(CString);    //�qOmd�ɿ�X���
private:
    void oForm();
//////////////////////////////////////////////////////////////////////////
//�䥦��Ʀs���禡
private:
    CString m_PnlID;
    CString m_MsrDvc;
    CString m_Prb;
    CString m_CHID;
    UINT    m_5nitsBkColor;

/*
  ��C�@��table�̪��F��Ϋ��Ы��X��
  �A�t�~�h�s��

  �t�~�A����ƪťժ��x�s�氵�Y��ĪG
  �H�F��ʺA�s�誺�����IXD
 */
    std::vector<BOOL> isMsrChain;
    std::vector< std::vector<bool> > isMsrTalbe;

    std::vector<Cartridge>  m_vMsrData;    //�q����ƪ��O����Ŷ�
    std::vector<CString>    m_vStrIndex;  //�q�����ت��W�r
public:    
    CString GetPnlID()  const;   void SetPnlID(CString&);
    CString GetMsrDvc() const;   void SetMsrDvc(CString&);
    CString GetPrb()    const;   void SetPrb(CString&);
    CString GetCHID()   const;   void SetCHID(CString&);

	void SetMsrData(std::vector<Cartridge>&);  //��Vector�˨�Omd��
	std::vector<Cartridge> GetMsrData();

    //�r��ؿ�
	BOOL    SetIndex();   //return 1:���q���� 0:�S������q����
    CString GetIndex(UINT) const;    
    UINT    GetIdxNum()    const;

    //��O���O���q����
    BOOL IsMsr(ColorType , PointNum , isMsrValue );  //    �i�H������vector���ʧ@�A��O���O���ȡA�S�����ܦ^��NULL
    BOOL IsMsr(ColorType , PointNum);                // �u�޶��جO���O����
    
private:
    //��ۼu���
    std::vector<Cartridge>::size_type SubNum(ColorType clr, PointNum Big, UINT Little) const;
};

#endif // !defined(AFX_OMDFILE1_H__5E9E8D8E_4BB9_40C8_BEE3_2756DA9A7E76__INCLUDED_)
