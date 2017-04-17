//
// Created by Rafał on 16.04.2017.
//

#include "CWielokat.h"
#include <iostream>

CWielokat::CWielokat(int IleWierzcholkow)
    :IleMamWierzcholkow(IleWierzcholkow){

    if(IleWierzcholkow<3 && IleWierzcholkow>100)
        std::cout<<"Musisz podac co najmniej 3 wierzcholki i maksymalnie 100. Sprobuj jeszcze raz"<<std::endl;

    else {
        for (int i = 0; i < IleWierzcholkow; i++) {
            MojeWierzcholki[i] = new CPunkt;
            MojeWierzcholki[i]->MojNumer = i;
        }
    }
}

CWielokat::~CWielokat() {
    for(int i;i<IleMamWierzcholkow;i++) {
        if (MojeWierzcholki != NULL) {
            delete MojeWierzcholki[i];
            MojeWierzcholki[i] = NULL;
        }
    }
}

void CWielokat::SetPointXY(int Numer, double X, double Y) {
    if(Numer>=IleMamWierzcholkow){
        std::cout<<"Nie znam wierzcholka o numerze: "<<Numer<<std::endl;
        std::cout<<"Podaj inny numer (UWAGA: numerowanie od zera)"<<std::endl;
    }
    else{
        MojeWierzcholki[Numer]->X=X;
        MojeWierzcholki[Numer]->Y=Y;
    }
}

void CWielokat::Opis() {
    std::cout<<"---------------------------------"<<std::endl;
    for(int i=0;i<IleMamWierzcholkow;i++)
        MojeWierzcholki[i]->Info();
    std::cout<<"---------------------------------"<<std::endl;
}

