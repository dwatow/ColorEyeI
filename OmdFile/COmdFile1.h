// OmdFile1.h: interface for the COmdFile class.
//
//////////////////////////////////////////////////////////////////////

#ifndef OMDFILE1_H
#define OMDFILE1_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "COmdFilePtr.h"

class COmdFile1 : public COmdFilePtr
{
	BOOL m_isOld;
public:
    COmdFile1(BOOL old = FALSE);
	virtual ~COmdFile1();
	
private:
	void o2tW49();
    void o2tD13();
	void o2tD21();
	void o2tD25();
	void o2tCT();
	void o2tD9();
	void o2tW9nD1();
	void o2tWRGB1nNits();

	void t2oInfo();
	void t2oWRGBD();
	void t2oW9();
	void t2oD9();
	void t2oCT();
	void t2oD25();
	void t2oW49();
	void t2oD21();
	void t2oD13();
	void t2oNits();

	void TxtToOmd();
	void OmdToTxt();
};



inline COmdFile1::COmdFile1(BOOL isOld)
{
    m_isOld = isOld;
};

inline COmdFile1::~COmdFile1()
{}


#endif //OMDFILE1_H
