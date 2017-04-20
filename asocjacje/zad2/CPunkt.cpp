#include "CPunkt.h"
#include <iostream>

CPunkt::CPunkt():X(0),Y(0){}

CPunkt::~CPunkt(){}

void CPunkt::Info() {
    std::cout<<"Numer punktu: "<<MojNumer<<"   X: "<<X<<"  Y: "<<Y<<std::endl;
}



