// C library headers
#include <stdio.h>
#include <string.h>

#include <thread>
#include <vector>
#include <iostream>

#include <iterator>
#include <algorithm>

#include <CppLinuxSerial/SerialPort.hpp>

int main(){
    mn::CppLinuxSerial::SerialPort serialPort("/dev/ttyACM0", 
    mn::CppLinuxSerial::BaudRate::B_460800, 
    mn::CppLinuxSerial::NumDataBits::EIGHT, 
    mn::CppLinuxSerial::Parity::NONE, 
    mn::CppLinuxSerial::NumStopBits::ONE);
    serialPort.SetTimeout(100); // Block for up to 100ms to receive data
	serialPort.Open();

    float out_buf[24][32];
    std::string outs = std::string("");
    std::string s;

    while(true){
        serialPort.Write("@");
        while(s.find('@') == std::string::npos){
            std::cout << s.find('@') << std::endl;
            std::string readData;
            serialPort.Read(readData);
            s += readData;
            std::cout << readData << std::endl;
        }
        std::cout << "found \\n at pos: " << s.find('\n') << std::endl;
        std::cout << s << std::endl;
        s = "";
    }
    return 0;
}