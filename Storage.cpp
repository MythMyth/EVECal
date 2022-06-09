#include "Storage.h"

void Storage::Load() {
    ifstream fs("Storage");

}

void Storage::Add(string component, int amount) {
    storedComponent[component] += amount;
}

int Storage::Get(string component) {
    if(storedComponent.find(component) == storedComponent.end()) {
        return 0;
    }
    return storedComponent[component];
}