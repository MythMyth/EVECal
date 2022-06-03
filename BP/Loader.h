#ifndef __LOADER__
#define __LOADER__

#include<mutex>
#include<dirent.h>
#include<map>
#include<string>
#include<iostream>
#include "BP.h"
#include "FuelBlock.h"
#include "Reaction.h"
#include "AdvComponent.h"
#include "AdvMediumShip.h"

using namespace std;

class Loader {
    private:
    static Loader *instance;
    static mutex m_mutex;
    map<string, BP*> all_bp;
    public:
    Loader();

    bool have_bp(string bp) ;
    BP* getBP(string bp) ;
    static Loader* GetInstance();
};

#endif