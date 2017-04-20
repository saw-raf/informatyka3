#include "Csamochod.h"
#include <iostream>

Csamochod::Csamochod(Ckolo* lPrzod, Ckolo* pPrzod, Ckolo* lTyl, Ckolo* pTyl, Ckolo* zapas){

    MojeKola[0]=new Ckolo;
    MojeKola[0]=lPrzod;
    MojeKola[1]=new Ckolo;
    MojeKola[1]=pPrzod;
    MojeKola[2]=new Ckolo;
    MojeKola[2]=lTyl;
    MojeKola[3]=new Ckolo;
    MojeKola[3]=pTyl;
    MojeKola[4]=new Ckolo;
    MojeKola[4]=zapas;

}

Csamochod::~Csamochod() {}

Ckolo* Csamochod::WymienKolo(int pozycjaKola, Ckolo* noweKolo) {
    if(pozycjaKola<5 && pozycjaKola>=0)
        MojeKola[pozycjaKola]=noweKolo;
    else
        std::cout << "Samochod ma tylko 4+1 kol" << std::endl;
    return noweKolo;// nie bylo okreslone co funkcja ma zwracac, wiec zwraca to
}

void Csamochod::RaportOKolach() {
    std::cout<<"--------------------------"<<std::endl;
    std::cout<<"Kola w aucie:"<<std::endl;
    std::cout<<"Lewy przod= ";
    MojeKola[0]->Info();
    std::cout<<"Prawy przod= ";
    MojeKola[1]->Info();
    std::cout<<"Lewy tyl= ";
    MojeKola[2]->Info();
    std::cout<<"Prawy tyl= ";
    MojeKola[3]->Info();
    std::cout<<"Zapasowe= ";
    if(MojeKola[4]!=NULL)
        MojeKola[4]->Info();
    else
        std::cout<<"brak"<<std::endl;

}