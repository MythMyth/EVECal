#ifndef __BP__
#define __BP__
#include<iostream>
#include<fstream>
#include<map>
#include "Item.h"
#include "Loader.h"

class BP : public Item {
    public:
    double facilityReduction, ME, rigReduction;
    int output, max_run;
    BP() {
        output = 1;
    }
    map<string, int> material;

    map<string, int> Calculate(int run);

};

#endif