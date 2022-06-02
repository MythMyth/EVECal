#include "BP.h"

class AdvMediumShip : public BP {
    public:
    AdvMediumShip(string name) {
        ifstream fs("Blueprint/Ship/" + name);
        string line;
        getline(fs, line);
        max_run = atoi(line);
        getline(fs, line);
        ME = atoi(line);
        getline(fs, line);
        TE = atoi(line);
        while(getline(fs, line)) {
            int place = line.find(" x ");
            if(place == -1) continue;
            string mat_name = line.substr(0, place);
            int amount = line.substr(place + 3);
            material[mat_name] = amount;
        }
    }

    private:
    int TE;
};