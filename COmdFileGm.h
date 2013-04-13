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
             COmdFileGm(){};
	virtual ~COmdFileGm(){};
 
private:
	void txt2omd();
	void omd2txt();
};

#endif //OMDFILEGM_H
