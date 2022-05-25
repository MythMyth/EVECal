#ifndef __REACTION__
#define __REACTION__
#include <BP.h>

class Reaction : public BP {
    public:

    Reaction(string fname) {
        ifstream fs(fname);
        string line;
        if(fname.substr(0, 3) == "CM_") {
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