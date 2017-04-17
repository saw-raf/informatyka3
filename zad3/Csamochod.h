#ifndef ZAD3_CSAMOCHOD_H
#define ZAD3_CSAMOCHOD_H

#include <cstdlib>
#include "Ckolo.h"

class Csamochod {
    Ckolo* MojeKola[5];
public:
    Csamochod(Ckolo* lPrzod, Ckolo* pPrzod, Ckolo* lTyl, Ckolo* pTyl, Ckolo* zapas=NULL);
    ~Csamochod();

    Ckolo* WymienKolo(int pozycjaKola, Ckolo* noweKolo);
    void RaportOKolach();
};


#endif //ZAD3_CSAMOCHOD_H
