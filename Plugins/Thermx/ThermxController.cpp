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
        mn::CppLinuxSerial::SerialPort serialPort;
        std::string s;
        serialPort.Write("@");
        while(s.find('@') == std::string::npos){
            std::string readData;
            serialPort.Read(readData);
            s += readData;
        }
        s = s.substr(0,s.length()-2);
        std::vector<std::string> splitted = split(s, "|");
        float arr[24][32];
        int i = 0;
        int j = 0;
        for(std::string str : splitted){
            arr[j][i] = std::stof(str);
            i++;
            if(i >= 32){
                i = 0; j++;
            }
        }
        _trx->refreshData(arr);
}