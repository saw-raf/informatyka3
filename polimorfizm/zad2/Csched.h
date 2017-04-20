#ifndef CSCHED_H
#define CSCHED_H

#include "Cbase.h"

class Csched {

    Cbase* pTabObj[10];
public:
    Csched();
    void SetAdr(Cbase* prog);
    void RemAdr(Cbase* prog);
    void run(int Count);
};

#endif //CSCHED_H