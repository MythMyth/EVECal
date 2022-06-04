#ifndef __ADV_COMP__
#define __ADV_COMP__

#include "BP.h"

class AdvComponent : public BP {
    public:
    AdvComponent(string fname) {
        fstream fs("Blueprint/AdvancedComponent/"+fname);
        string line;
        getline(fs, line);
        output = atoi(line.c_str());
        getline(fs, line);
        max_run = atoi(line.c_str());
        Debug::GetInstance()->Log(LOG_LEVEL_LOW, "Created BP: %s, output: %d, max run: %d", fname.c_str(), output, max_run);
        while(getline(fs, line)) {
            int pos = line.find(" x ");
            if(pos == -1) continue;
            string mat_name = line.substr(0, pos);
            string mat_num = line.substr(pos+3);
            material[mat_name] = atoi(mat_num.c_str());
            Debug::GetInstance()->Log(LOG_LEVEL_LOW, "  Mat name: %s , amount: %d from line: %s", mat_name.c_str(), material[mat_name], line.c_str());
        }
        int len = fname.size();
        name = fname;
        for(int i = 0; i < len; i++) {
            if(name[i] == '_') name[i] = ' ';
        }
        ME = 10;
    }
};

#endif