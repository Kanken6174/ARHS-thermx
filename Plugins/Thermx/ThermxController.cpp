#include "ThermxController.hpp"

std::vector<std::string> split(std::string str, std::string c){
    std::vector<std::string> out;
    std::string token;
    size_t pos = 0;
    while ((pos = str.find(c)) != std::string::npos) {
        token = str.substr(0, pos);
        out.push_back(token);
        str.erase(0, pos + c.length());
    }
    return out;
}

void ThermxController::getData(){
    if(!this->enabled || serialPort == nullptr){
        _trx->enabled = false;
        return;
    }
    _trx->enabled = true;
    std::string s;
    if(!(serialPort->GetState() == mn::CppLinuxSerial::State::OPEN)){
        //std::cout << "port was closed, opening..." <<std::endl;
        serialPort->Open();
    }
    //std::cout << "port is open, sending @" << std::endl;
    serialPort->Write("@");
    //std::cout << "done" << std::endl;
    while(s.find('@') == std::string::npos){
        std::string readData;
        serialPort->Read(readData);
        s += readData;
    }
    //std::cout << "done receiving data" << std::endl;
    s = s.substr(0,s.length()-2);
    //std::cout << "trimmed data" << std::endl;
    std::vector<std::string> splitted = split(s, "|");
    //std::cout << "split data " << splitted.size() << std::endl;
    while(splitted.size() < 32*24){
        splitted.push_back("0.0");
    }
    //std::cout << "filled data " << splitted.size() << std::endl;
    float arr[24][32];
    treated.clear();
    treated.reserve(32*24);
    int i = 0;
    int j = 0;
    for(std::string str : splitted){
        arr[j][i] = std::stof(str);
        treated.push_back(arr[j][i]);
        i++;
        if(i >= 32){
            i = 0; j++;
        }
    }
    //std::cout << "data sent to array" << std::endl;
    if(_trx == NULL){
        //std::cout << "renderer was null?" << std::endl;
    }else{
    _trx->refreshData(treated);
    }
    //std::cout << "data refreshed" << std::endl;
    working = false;
}