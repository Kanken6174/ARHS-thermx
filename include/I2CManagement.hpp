#include <Wire.h>
#include <vector>
#include <string>

class I2CDevice{
    protected:
        int _writeAddress = 0x00;
        int _readAddress = 0xFF;
        std::string _name = "";
    public:
        int getWriteAddress(){return _writeAddress;}
        int getReadAddress(){return _readAddress;}
        std::string getname(){return _name;}
        virtual bool checkAlive(){return false;}
};

class I2CManager{
    protected:
        static std::vector<I2CDevice*> _Devices;
        static int _pinSCL;
        static int _pinSDA;
    public:
        static void Setup(int pinSDA, int pinSCL);
        static void I2CWrite(int address, int value);
        static int I2CRead(int address, int size);
        static void writeToRegister8bit(int message, int targetRegister, int i2cAddress);
        static void registerNewDevice(I2CDevice* device){_Devices.push_back(device);}
        static void scanAll();
};