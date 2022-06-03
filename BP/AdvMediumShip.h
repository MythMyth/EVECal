#ifndef __ADVSHIP__
#define __ADVSHIP__
#include "BP.h"

class AdvMediumShip : public BP {
    public:
    AdvMediumShip(string name) {
        ifstream fs("Blueprint/Ship/" + name);
        string line;
        getline(fs, line);
        max_run = atoi(line.c_str());
        getline(fs, line);
        ME = atoi(line.c_str());
        getline(fs, line);
        TE = atoi(line.c_str());
        while(getline(fs, line)) {
            int place = line.find(" x ");
            if(place == -1) continue;
            string mat_name = line.substr(0, place);
            int amount = atoi(line.substr(place + 3).c_str());
            material[mat_name] = amount;
        }
    }

    private:
    int TE;
};

#endif