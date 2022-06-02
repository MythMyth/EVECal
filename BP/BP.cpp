#include "BP.h"

map<string, int> BP::Calculate(int amount, bool round = false) {
    int run = amount / output;
    if(amount %output != 0) run++;
    map<string, int> ret;
    while(run > 0) {
        int part_run = (max_run < run) ? max_run: (round ? max_run: run);
        run -= max_run;
        for(auto mat: material) {
            int count = max(part_run, (int)ceil(Item::Round((mat.second * ((100. - ME)/100.) * ((100. - rigReduction)/100.) * ((100. - facilityReduction)/100.)) * part_run)));
            ret[mat.first] += count;
        }
    }

    map<string, int> lower_mat;
    for(auto it: ret) {
        if(Loader::GetInstance()->have_bp(it->first)) {
            BP *bp = Loader::GetInstance()->getBP(it->first);
            map<string, int> lower_ret = bp->Calculate(it->second, round);
            for(auto lit: lower_ret) {
                lower_mat[lit->first] += lit->second;
            }
        }
    }

    for(auto it: lower_mat) {
        ret[it->first] += it->second;
    }

    return ret;
}

