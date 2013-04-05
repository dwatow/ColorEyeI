#ifndef DEBUGFILE_H
#define DEBUGFILE_H

#include "OmdFile/TxtFile.h"

#ifdef _DEBUG
#define DebugCode( code_fragment ) { code_fragment }
#else
#define DebugCode( code_fragment )
#endif

class debugFile
{
    TxtStrData m_outData;

public:
	void Clear();
	void Out2File(CString path);
	void Add(CString line);
};


inline void debugFile::Clear()
{
	DebugCode(
		m_outData.clear();
	)
}

inline void debugFile::Out2File(CString path)
{
	DebugCode(
		CTxtFile fTxt;
		CFileException fx;
		fTxt.Save(path, fx);
		fTxt.iTxtData(m_outData);
		fTxt.Close();
	)
}

inline void debugFile::Add(CString line)
{
	DebugCode(
		m_outData.push_back(line);
	)
}

#endif