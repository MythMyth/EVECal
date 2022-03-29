#ifndef __BP__
#define __BP__
#include<iostream>
#include "Item.h"

class BP : public Item {
    public:
    BP() {
        std::cout << "BP initiated\n";
    }
};

#endif