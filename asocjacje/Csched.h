#ifndef CSCHED_H
#define CSCHED_H

#include "Cprog.h"

class Csched {
public:
    Csched(Cprog& one, Cprog& two);
    void run(int ileRazy);
private:
    Cprog* pprog1;
    Cprog* pprog2;

};

#endif //CSCHED_H