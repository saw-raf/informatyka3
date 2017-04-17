#include "Csamochod.h"
#include "Ckolo.h"
#include <iostream>

int main() {
    Ckolo Z0(0,'L');
    Ckolo Z1(1,'L');
    Ckolo Z2(2,'L');
    Ckolo Z3(3,'L');
    Ckolo Z4(4,'Z');
    Ckolo Z5(5,'Z');
    Ckolo Z6(6,'Z');
    Ckolo Z7(7,'Z');
    Ckolo Z8(8,'U');
    Csamochod autko(&Z0,&Z1,&Z2,&Z3);
    autko.RaportOKolach();
    autko.WymienKolo(4,&Z8);
    autko.RaportOKolach();
    autko.WymienKolo(0,&Z4);
    autko.WymienKolo(1,&Z5);
    autko.WymienKolo(2,&Z6);
    autko.WymienKolo(3,&Z7);
    autko.RaportOKolach();

    return 0;
}