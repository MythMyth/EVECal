#ifndef __FUELBLOCK__
#define __FUELBLOCK__

#include<BP.h>

class FuelBlock : public BP {
    FuelBlock(string fname) {
        output = 40;
        material["Robotics"] = 1;
        material["Enriched Uranium"] = 4;
        material["Mechanical Parts"] = 4;
        material["Coolant"] = 9;
        material["Strontium Clathrates"] = 20;
        material["Oxygen"] = 22;
        material["Heavy Water"] = 170;
        material["Liquid Ozone"] = 350;
        if(fname == "Hellium") {
            material["Helium Isotopes"] = 450;
        } else if(fname == "Hydrogen") {
            material["Hydrogen Isotopes"] = 450;
        } else if(fname == "Oxygen") {
            material["Oxygen Isotopes"] = 450;
        } else {
            material["Nitrogen Isotopes"] = 450;
        }
        ME = 10;
    }
};

#endif
