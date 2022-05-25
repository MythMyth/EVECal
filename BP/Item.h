#ifndef __Item__
#define __Item__
#include<iostream>
#include<string>
#include<math.h>

class Item{

    static double Round(double n) {
        return round(n * 100) / 100.;
    }
    public: 
    Item() {
        std::cout << "Item initiated\n";
    }

    string getname() {
        return name;
    }
    protected:
    string name;
};

#endif