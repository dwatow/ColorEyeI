#ifndef DNA_H
#define DNA_H

#include "Nucleotide.h"

class DNA
{
	std::vector<Nucleotide> nChain;
public:
	void AddCell(const Nucleotide& _N);
	void AddCell(ColorType _C = NoColor, PointTotal _P = NoPn, int _N1 = -1, int _N2 = -1, int _N3 = -1);
	void AddCell(const DNA&);

    void DelCell(std::vector<Nucleotide>::size_type index);

public:
	std::vector<Nucleotide>::iterator            Begin()       { return nChain.begin(); };
	std::vector<Nucleotide>::const_iterator      Begin() const { return nChain.begin(); };

	std::vector<Nucleotide>::iterator            End  ()       { return nChain.end();   };
	std::vector<Nucleotide>::const_iterator      End  () const { return nChain.end();   };

	std::vector<Nucleotide>::size_type           Size () const { return nChain.size();  };
	void Empty(){ nChain.clear(); };
//	BOOL IsEmpty(){ nChain.empty(); };

	void operator+(const Nucleotide&  _X);
	void operator+(const DNA& _R);
};

inline void DNA::operator+(const Nucleotide&  _N)
{ AddCell(_N); };
inline void DNA::operator+(const DNA& _D)
{ AddCell(_D); };

#endif