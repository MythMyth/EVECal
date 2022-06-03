#include<iostream>
#include "BP/Loader.h"

int main(int argc, char** argv) {
    cout << "Started\n";
    map<string, int> ret = Loader::GetInstance()->getBP("Ishtar_0_3_6")->Calculate(10);
    for(auto it: ret) {
        cout << it.first << " " << it.second << "\n";
    }
    return 0;
}