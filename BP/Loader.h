#ifndef __LOADER__
#define __LOADER__

#include<mutex>
#include<dirent.h>
#include<map>
#include<string>
#include<iostream>

#include "FuelBlock.h"
#include "Reaction.h"
#include "AdvComponent.h"

using namespace std;

class Loader {
    private:
    static Loader *instance;
    static mutex m_mutex;
    map<string, Item*> all_bp;
    public:

    Loader() {
        cout << "Loader \n";
        DIR *dir;
        struct dirent *ent;
        if ((dir = opendir ("Blueprint/Reaction")) != NULL) {
            /* print all the files and directories within directory */
            while ((ent = readdir (dir)) != NULL) {
                if(ent->d_type == DT_REG) {
                    string filename(ent->d_name);
                    Reaction *reac = new Reaction(filename);
                    int len = filename.size();
                    for(int i = 0; i < len; i++) {
                        if(filename[i] == '_') filename[i] = ' ';
                    }
                    all_bp[filename] = reac;
                }
            }
            closedir (dir);
        }

        if((dir = opendir ("Blueprint/AdvancedComponent")) != NULL ) {
            while((ent = readdir (dir)) != NULL) {
                if(ent -> d_type == DT_REG) {
                    string filename(ent->d_name);
                    AdvComponent *advcomp = new AdvComponent(filename);
                    int len = filename.size();
                    for(int i = 0; i < len; i++) {
                        if(filename[i] == '_') filename[i] = ' ';
                    }
                    all_bp[filename] = advcomp;
                }
            }
        }

        all_bp["Hellium Fuel Block"] = new FuelBlock("Hellium");
        all_bp["Hydrogen Fuel Block"] = new FuelBlock("Hydrogen");
        all_bp["Nitrogen Fuel Block"] = new FuelBlock("Nitrogen");
        all_bp["Oxygen Fuel Block"] = new FuelBlock("Oxygen");

        for(auto it: all_bp) {
            cout << it.first << "\n";
        }

    }
    static Loader* GetInstance() {
        m_mutex.lock();
        if(instance == NULL) {
            instance = new Loader();
        }
        m_mutex.unlock();
    }
};

Loader* Loader::instance;
mutex Loader::m_mutex;

#endif