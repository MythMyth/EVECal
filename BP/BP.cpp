#include "BP.h"
#include "Loader.h"

BP::BP() {
    output = 1;
    max_run = 1;
    facilityReduction = 0;
    rigReduction = 0;
    ME = 0;
}

map<string, int> BP::Calculate(int amount, bool round) {
    int run = amount / output;
    if(amount %output != 0) run++;
    Debug::GetInstance()->Log(LOG_LEVEL_MED, "Run %s with amount %d and job run %d", this->name.c_str(), amount, run);
    Debug::GetInstance()->Log(LOG_LEVEL_MED, "BP output: %d , BP max run %d", output, max_run);
    map<string, int> ret;
    while(run > 0) {
        int part_run = (max_run < run) ? max_run: (round ? max_run: run);
        run -= max_run;
        for(auto mat: material) {
            int count = max(part_run, (int)ceil(Item::Round((mat.second * ((100. - ME)/100.) * ((100. - rigReduction)/100.) * ((100. - facilityReduction)/100.)) * part_run)));
            ret[mat.first] += count;
            Debug::GetInstance()->Log(LOG_LEVEL_MED, "Mat: %s amount: %d", mat.first.c_str(), count);
        }
    }

    return ret;
}

