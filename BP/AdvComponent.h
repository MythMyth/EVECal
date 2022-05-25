#ifndef __ADV_COMP__
#define __ADV_COMP__

#include<BP.h>

class AdvComponent : public BP {
    public:
    AdvComponent(string fname) {
        fstream fs(fname);
        string line;
        getline(fs, line);
        output = atoi(line.c_str());
        while(getline(fs, line)) {
            int pos = line.find(" x ");
            if(pos == -1) continue;
            string mat_name = line.substr(0, pos);
            string mat_num = line.substr(pos+3);
            material[mat_name] = atoi(mat_num.c_str());
        }
        int len = fname.size();
        name = fname;
        for(int i = 0; i < len; i++) {
            if(name[i] == '_') name[i] = ' ';
        }
    }
};

#endif