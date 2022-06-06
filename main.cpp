#include<iostream>
#include "BP/Loader.h"
#include "BuildPlan.h"

int main(int argc, char** argv) {
    Debug::GetInstance()->SetDebugLevel(LOG_LEVEL_NO_LOG);
    map<string, int> ret;
    Loader *instance = Loader::GetInstance();
    BuildPlan plan;
    plan.AddItem("Ishtar_0_3_6", 10);
    vector<ItemWorkDetail> output = plan.MakePlan(true);
    for(ItemWorkDetail it: output) {
        if(it.jobRun == 0) continue;
        cout << it.name << ": Amount: " << it.amount << " Job run: " << it.jobRun << "\n";
    }
    cout << "========================\nBuy list: \n";
    for(ItemWorkDetail it: output) {
        if(it.jobRun != 0) continue;
        cout << it.name << ": Amount: " << it.amount << " Job run: " << it.jobRun << "\n";
    }
    return 0;
}