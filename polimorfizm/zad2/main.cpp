#include "Csched.h"
#include "Cprog.h"
#include "Cprog2.h"
#include <iostream>

using namespace std;

int main() {
    Cprog pr1, pr2;
    Cprog2 pr11, pr12;
    Csched planista;

    planista.SetAdr(&pr1);
    planista.SetAdr(&pr2);
    planista.SetAdr(&pr11);
    planista.SetAdr(&pr12);

    planista.run(3);

    planista.RemAdr(&pr11);

    planista.run(5);

    return 0;
}