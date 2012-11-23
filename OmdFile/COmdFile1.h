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
	void TxtToOmd();
	void OmdToTxt();
};

#endif //OMDFILE1_H
