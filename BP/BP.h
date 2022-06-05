#ifndef __BP__
#define __BP__

#include<iostream>
#include<fstream>
#include<map>
#include "Item.h"

class Loader;
class BP : public Item {
    public:
    double facilityReduction, rigReduction;
    int output, max_run, ME;
    map<string, int> material;
    map<string, int> Calculate(int amount, int &true_run, bool round = false);

    BP();

};

#endif