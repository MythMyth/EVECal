#include<BP.h>

BP::Calculate(int run) {
    map<string, int> ret;
    for(auto mat: material) {
        int count = max(run, ceil(Item::Round((mat.second * ((100. - ME)/100.) * ((100. - rigReduction)/100.) * ((100. - facilityReduction)/100.)) * run)));
        ret[mat.first] = count;
    }
    return ret;
}

