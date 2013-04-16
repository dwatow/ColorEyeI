// OmdFile1.h: interface for the COmdFile class.
//
//////////////////////////////////////////////////////////////////////

#ifndef OMDFILEPTR_H
#define OMDFILEPTR_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TxtFile.h"
#include "RNA.h"
#include <vector>
#include <iterator>
#include "OmdHead.h"

class COmdFileFactor
{
//Diff of Txt file
protected:
    OmdHead m_omdFileHead;

public:
    OmdHead& GetFileHead(){ return m_omdFileHead; };
    const OmdHead GetFileHead() const{ return m_omdFileHead; };
    void SetFileHead(const OmdHead& _H){ m_omdFileHead = _H; };

protected:
//    virtual BOOL isOldForm(TxtStrData&) = 0;
    const CString GetLine(const int& ) const;    
    const CString GetCell(const int&, const int& ) const;
    const CString GetCell(const TCHAR& , const int& ) const;   // 0< c<=24
    const CString GetCell(const PTCHAR& , const int& ) const;  //25<=c¡A±qAA¶}©lºâ

protected:
    TxtStrData m_dTxt;
//the same of Txt file;
    CTxtFile   m_fTxt;
    RNA m_dOmd;

public:
    COmdFileFactor();
    virtual ~COmdFileFactor();
    BOOL Open(LPCTSTR, CFileException&);
    BOOL Save(LPCTSTR, CFileException&);

    void Close(){ m_fTxt.Close(); };

    RNA  oOmdData()         { txt2omd(); return m_dOmd; };
    void oOmdData(RNA& data){ txt2omd(); data = m_dOmd; };
    void iOmdData(const RNA& data){ m_dOmd = data; omd2txt(); };

private:
     virtual void txt2omd() = 0;
     virtual void omd2txt() = 0;
     void ErrorMsg(CFileException& ) const;
};

#endif // OMDFILE0_H
