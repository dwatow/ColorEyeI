// OmdFile1.h: interface for the COmdFile class.
//
//////////////////////////////////////////////////////////////////////

#ifndef OMDFILEGM_H
#define OMDFILEGM_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "COmdFileFactor.h"

class COmdFileGm : public COmdFileFactor
{

public:
             COmdFileGm(){ /*COmdFilePtr::COmdFilePtr();*/  };
	virtual ~COmdFileGm(){ /*COmdFilePtr::~COmdFilePtr();*/ };
 
private:
	void TxtToOmd();
	void OmdToTxt();
};

#endif //OMDFILEGM_H
