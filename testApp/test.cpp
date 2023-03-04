// C library headers
#include <stdio.h>
#include <string.h>

#include <thread>
#include <vector>
#include <iostream>

#include <iterator>
#include <algorithm>

#include <CppLinuxSerial/SerialPort.hpp>

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

int main(){
    mn::CppLinuxSerial::SerialPort serialPort("/dev/ttyACM0", 
    mn::CppLinuxSerial::BaudRate::B_460800, 
    mn::CppLinuxSerial::NumDataBits::EIGHT, 
    mn::CppLinuxSerial::Parity::NONE, 
    mn::CppLinuxSerial::NumStopBits::ONE);
    serialPort.SetTimeout(150); // Block for up to 100ms to receive data
	serialPort.Open();

    float out_buf[24][32];
    std::string outs = std::string("");
    std::string s;

    while(true){
        serialPort.Write("@");
        while(s.find('@') == std::string::npos){
            std::string readData;
            serialPort.Read(readData);
            s += readData;
        }
        s = s.substr(0,s.length()-2);
        std::vector<std::string> splitted = split(s, "|");
        std::vector<float> treated;
        for(std::string str : splitted){
            treated.push_back(std::stof(str));
        }
        //system("clear");
        for(int i = 0; i < 24; i++){
            for(int j = 0; j < 32; j++){
                if(i*32+j >= treated.size()) break;
                float t = treated.at(i*32+j);
                if(t != NULL){
                        std::string c = " ";
                        if (t < 20) c = " ";
                        else if (t < 23) c = "░";
                        else if (t < 25) c = "░";
                        else if (t < 27) c = "▒";
                        else if (t < 29) c = "▒";
                        else if (t < 31) c = "▓";
                        else if (t < 33) c = "▓";
                        else if (t < 35) c = "█";
                        else if (t < 37) c = "█";
                        std::cout << c;
                }else{
                    std::cout << " ";
                }
                if(j == 31)
                    std::cout << std::endl;
            }
        }
        s = "";
    }
    return 0;
}