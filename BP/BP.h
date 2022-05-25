#ifndef __BP__
#define __BP__
#include<iostream>
#include<fstream>
#include<map>
#include "Item.h"

using namespace std;
class BP : public Item {
    public:
    double facilityReduction, ME, rigReduction;
    int output;
    BP() {
        output = 1;
    }
    map<string, int> material;

    map<string, int> Calculate(int run);

};

#endif