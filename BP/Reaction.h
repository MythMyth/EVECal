#ifndef __REACTION__
#define __REACTION__
#include "BP.h"

class Reaction : public BP {
    public:

    Reaction(string fname) {
        Debug::GetInstance()->Log(LOG_LEVEL_LOW, "Create BP: %s", fname.c_str());
        ifstream fs(fname);
        string line;
        string indicator;
        getline(fs, indicator);
        indicator = indicator.substr(0, 2);
        max_run = 1000;
        if(indicator == "CM") {
            getline(fs, line);
            output = atoi(line.c_str());
            getline(fs, line);
            material[line] = 5; //Fuel block
            while(getline(fs, line)) {
                material[line] = 100; //Material
            }
        } else {
            output = 200;
            getline(fs, line);
            material[line] = 5; //Fuel block
            getline(fs, line);
            material[line] = 100; //First moon goo
            getline(fs, line);
            material[line] = 100; //Second moon goo
        }
        name = fname.substr(3);
        int len = name.size();
        for(int i = 0; i < len; i++) {
            if(name[i] == '_') {
                name[i] = ' ';
            }
        }
    }
};

#endif