#include<iostream>
#include "BP/Loader.h"

int main(int argc, char** argv) {
    Debug::GetInstance()->SetDebugLevel(LOG_LEVEL_LOW);
    map<string, int> ret;
    Loader *instance = Loader::GetInstance();
    if(instance->have_bp("Ishtar_0_3_6")) Debug::GetInstance()->Log(LOG_LEVEL_LOW, "???");
    ret = instance->getBP("Ishtar_0_3_6")->Calculate(10);
    for(auto it: ret) {
        cout << it.first << " " << it.second << "\n";
    }
    return 0;
}