#include "stdafx.h"
#include "DNA.h"
#include <algorithm>
#include "debugFile.h"

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

void DNA::DelCell(const DNA& compData)
{
    if (compData.Size())//裡面這些不要修改，影響再次量測的資料擺放
    {
        std::vector<Nucleotide>::const_iterator dnaItor = 0, compItor;
        std::vector<Nucleotide>::iterator rmBeginItor(End());

        for (compItor = compData.Begin(); compItor != compData.End(); ++compItor)
                rmBeginItor = std::remove(Begin(), rmBeginItor, *compItor);
        
        nChain.erase(rmBeginItor, End());
    }
}