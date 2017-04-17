#ifndef ZAD2_CWIELOKAT_H
#define ZAD2_CWIELOKAT_H

#include "CPunkt.h"

class CWielokat {

    CPunkt* MojeWierzcholki[100];
    int IleMamWierzcholkow;

public:
    CWielokat(int IleWierzcholkow=3);
    ~CWielokat();

    void SetPointXY(int Numer,double X,double Y);
    void Opis();
};


#endif //ZAD2_CWIELOKAT_H
