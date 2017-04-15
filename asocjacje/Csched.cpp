#include "Csched.h"

Csched::Csched(Cprog& one, Cprog& two){
    pprog1=&one;
    pprog2=&two;
}

void Csched::run(int ileRazy){
    for(int i=0;i<ileRazy;i++)
    {
        pprog1->update();
        pprog2->update();
    }
}