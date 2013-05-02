#include "stdafx.h"
#include "DNA.h"

void DNA::AddCell(const Nucleotide& _N) 
{
    nChain.push_back(_N);
};

void DNA::AddCell(ColorType _C, PointTotal _P, int _N1, int _N2, int _N3)
{
	Nucleotide _N(_C, _P, _N1, _N2, _N3);
	nChain.push_back(_N);
}

void DNA::DelCell(std::vector<Nucleotide>::size_type index)
{
	nChain.erase(&nChain.at(index));
}

void DNA::AddCell(const DNA& _D)
{
	nChain.insert(End(), _D.Begin(), _D.End());
}
