#include<iostream>
#include "BP/BP.h"
#include "BP/Item.h"
#include "BP/Loader.h"

int main(int argc, char** argv) {
    cout << "Started\n";
    Loader::GetInstance();
    return 0;
}