#include<iostream>
#include "BP/Loader.h"

int main(int argc, char** argv) {
    Debug::GetInstance()->SetDebugLevel(LOG_LEVEL_NO_LOG);
    map<string, int> ret;
    Loader *instance = Loader::GetInstance();
    ret = instance->getBP("Ishtar_0_3_6")->Calculate(10);
    for(auto it: ret) {
        cout << it.first << " " << it.second << "\n";
    }
    return 0;
}