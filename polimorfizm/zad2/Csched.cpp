#include <iostream>
#include "Csched.h"


Csched::Csched(){
    for(int i=0;i<10;i++) {
        pTabObj[i] = 0;
    }
}

void Csched::SetAdr(Cbase* prog) {
    int i=0;
    bool checker=true;
    while(i<10 && checker==true){
        if(pTabObj[i]==0){
            pTabObj[i]=prog;
            checker=false;
        }
        i++;
    }
    if(i>=10 && checker==true)
        std::cout<<"Umiem obslugiwac max 10 obiektow."<<std::endl;
}

void Csched::RemAdr(Cbase *prog) {
    int i=0;
    bool checker=true;
    while(i<10 && checker==true){
        if(pTabObj[i]==prog){
            pTabObj[i]=0;
            checker=false;
        }
        i++;
    }
    if(checker==true)
        std::cout<<"RemAdrD: Nie mam takiego obiektu"<<std::endl;
}

void Csched::run(int Count) {
    for(int i=0;i<10;i++){
        if(pTabObj[i]!=0) {
            for(int j=0;j<Count;j++)
                pTabObj[i]->update();
        }
    }
}

