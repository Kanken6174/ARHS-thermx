#include "I2CManagement.hpp"
#include <Arduino.h>
#include "PinDefinitions.hpp"

std::vector<I2CDevice*> I2CManager::_Devices = std::vector<I2CDevice*>();
int I2CManager::_pinSCL;
int I2CManager::_pinSDA;

void I2CManager::Setup(int pinSDA, int pinSCL){
    _pinSCL = pinSCL;
    _pinSDA = pinSDA;
    Wire.setPins(_pinSDA, _pinSCL);
    Wire.setClock(1000000);
    Wire.begin();
    Wire.setClock(1000000);
}

int I2CManager::I2CRead(int address, int size){
    return Wire.requestFrom(address, size);
}

void I2CManager::I2CWrite(int address, int value){
    Wire.beginTransmission(address);
    Wire.write(value);
    Wire.endTransmission();
}

void I2CManager::writeToRegister8bit(int message, int targetRegister, int i2cAddress){
    Wire.beginTransmission(i2cAddress); // Begins a transmission to the I2C slave
    Serial.print(Wire.write(targetRegister));              // ask to write to this register
    Serial.print(Wire.write(message));                    // set this register's value to the message value (byte)
    Wire.endTransmission(true);
}

void I2CManager::scanAll(){
  Serial.println ();
  Serial.println ("I2C scanner. Scanning ...");
  uint8_t count = 0;

  for (uint8_t i = 8; i < 120; i++)
  {
    Wire.beginTransmission (i);          // Begin I2C transmission Address (i)
    if (Wire.endTransmission () == 0)  // Receive 0 = success (ACK response) 
    {
      Serial.print ("Found address: ");
      Serial.print (i, DEC);
      Serial.print (" (0x");
      Serial.print (i, HEX);     // PCF8574 7 bit address
      Serial.println (")");
      count++;
    }
  }
  Serial.print ("Found ");      
  Serial.print (count, DEC);        // numbers of devices
  Serial.println (" device(s).");
}