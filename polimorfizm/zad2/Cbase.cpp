#include "Cbase.h"
#include <iostream>

int Cbase::amount=0;

Cbase::Cbase():myState(0){
    myId=amount;
    amount++;
}

void Cbase::update(){
    myState++;
    std::cout<<"Nr obiektu: "<<myId<<" stan obiektu: "<<myState<<std::endl;
}