#ifndef __Item__
#define __Item__
#include<iostream>
#include<string>
#include<math.h>
using namespace std;
class Item{
    public: 
    Item() {
    }

    string getname() {
        return name;
    }
    protected:
    string name;
    static double Round(double n) {
        return round(n * 100) / 100.;
    }
};

#endif