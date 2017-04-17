#include "Ckolo.h"
#include <iostream>

Ckolo::Ckolo(int nr, char t) {
    nrSeryjny=nr;
    typ=t;
}

Ckolo::Ckolo(){}

Ckolo::~Ckolo() {}

void Ckolo::Info() {
    std::cout<<"Kolo nr: "<<nrSeryjny<<" typ: "<<typ<<std::endl;
}