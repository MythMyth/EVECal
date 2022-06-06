#ifndef __STORAGE__
#define __STORAGE__

#include <map>
#include <string>
#include "Debug/SingleTon.h"

class Storage : public SingleTon<Storage> {
public:
    void Add(string component, int amount);
    int Get(string component);
private:
    map<string, int> storedComponent;
};

#endif