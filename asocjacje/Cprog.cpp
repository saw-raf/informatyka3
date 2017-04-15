#include "Cprog.h"
#include <iostream>


int Cprog::amount=0;

Cprog::Cprog():myState(0){
    myId=amount;
    amount++;
}

void Cprog::update(){
    myState++;
    std::cout<<"Nr obiektu: "<<myId<<" stan obiektu: "<<myState<<std::endl;
}