#include "Loader.h"

Loader::Loader() {
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

    all_bp["Cerberus_0_3_6"] = new AdvMediumShip("Cerberus_0_3_6");
    all_bp["Ishtar_0_3_6"] = new AdvMediumShip("Ishtar_0_3_6");

}

bool Loader::have_bp(string bp) {
    return all_bp.find(bp) != all_bp.end();
}

BP* Loader::getBP(string bp) {
    return all_bp[bp];
}

Loader* Loader::GetInstance() {
    m_mutex.lock();
    if(instance == NULL) {
        instance = new Loader();
    }
    m_mutex.unlock();
}

Loader* Loader::instance;
mutex Loader::m_mutex;