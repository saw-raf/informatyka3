#include "CWielokat.h"
#include <iostream>

int main() {
    CWielokat kwadrat(4);
    kwadrat.SetPointXY(0,1,1);
    kwadrat.SetPointXY(1,1,-1);
    kwadrat.SetPointXY(2,-1,-1);
    kwadrat.SetPointXY(3,-1,1);
    kwadrat.Opis();
    return 0;
}