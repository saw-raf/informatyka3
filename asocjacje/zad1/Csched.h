#ifndef CSCHED_H
#define CSCHED_H

#include "Cprog.h"

class Csched {
    Cprog* pprog1;
    Cprog* pprog2;

public:
    Csched(Cprog& one, Cprog& two);
    ~Csched();
    void run(int ileRazy);
};

#endif //CSCHED_H