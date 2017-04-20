#include "CInstrument.h"
#include "CGitara.h"
#include "CTrabka.h"
#include <iostream>

int main() {
    CInstrument *WskaznikNaInstrument;
    CInstrument JakisInstrument;
    CTrabka Trabka;
    CGitara Gitara;

    WskaznikNaInstrument = &JakisInstrument;
    WskaznikNaInstrument->Graj();
    WskaznikNaInstrument = &Trabka;
    WskaznikNaInstrument->Graj();

    WskaznikNaInstrument = &Gitara;
    WskaznikNaInstrument->Graj();


    std::cout<<"Suma rozmiarow: "<<sizeof(JakisInstrument)+sizeof(Trabka)+sizeof(Gitara)<<std::endl;

    return 0;
}