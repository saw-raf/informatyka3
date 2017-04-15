#include <iostream>
#include "Csched.h"
#include "Cprog.h"
using namespace std;

int main() {
    Cprog One,Two;
    Csched Droznik(One,Two);
    Droznik.run(3);
    return 0;
}