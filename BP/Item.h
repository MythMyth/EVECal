#ifndef __Item__
#define __Item__
#include<iostream>
#include<string>
#include<math.h>
#include "../Debug/Debug.h"

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
        double ret = round(n * 100) / 100.;
        Debug::GetInstance()->Log(LOG_LEVEL_LOW, "return: %f", ret);
        return ret;
    }
};

#endif