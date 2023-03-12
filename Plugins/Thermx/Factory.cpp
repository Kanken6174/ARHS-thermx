#include "ThermxController.hpp"

ThermxController* tc;   //not ideal
ThermxRenderer* tr;

extern "C" {
    std::string getManifest(){
        return "Subnode|SerialDevice|DeviceCommands";
    }

    std::string getidentifier(){
        return "Thermx";
    }

    SerialDevice* generateDevice(){
        tc = new ThermxController(tr);
        return tc;
    }

    SubNode* generateSubnode(){
        tr = new ThermxRenderer();
        return tr;
    }

    vector<DeviceCommand*> generateDeviceCommands(){
        vector<DeviceCommand*> dv;
        dv.push_back(new ThermXRefreshDataCommand(tc));
        return dv;
    }
}