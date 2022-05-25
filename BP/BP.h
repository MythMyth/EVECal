#ifndef __BP__
#define __BP__
#include<iostream>
#include<map>
#include "Item.h"

using namespace std;
class BP : public Item {
    public:
    double facilityReduction, ME, rigReduction;
    map<string, int> material;

    map<string, int> Calculate(int run);

};

#endif