#include <Adafruit_MLX90640.h>
#include <I2CManagement.hpp>
#include <sstream>
#include <math.h>
#include <memory>
#include <string>
#include <stdexcept>
#include <esp_task_wdt.h>

Adafruit_MLX90640 mlx;
float frame[32*24]; // buffer for full frame of temperatures

// uncomment *one* of the below
#define PRINT_TEMPERATURES
//#define PRINT_ASCIIART

template<typename ... Args>
std::string string_format( const std::string& format, Args ... args )
{
    int size_s = std::snprintf( nullptr, 0, format.c_str(), args ... ) + 1; // Extra space for '\0'
    if( size_s <= 0 ){ throw std::runtime_error( "Error during formatting." ); }
    auto size = static_cast<size_t>( size_s );
    std::unique_ptr<char[]> buf( new char[ size ] );
    std::snprintf( buf.get(), size, format.c_str(), args ... );
    return std::string( buf.get(), buf.get() + size - 1 ); // We don't want the '\0' inside
}


void setup(){
  esp_task_wdt_delete(NULL);
  Serial.begin(460800);
  Serial.setTimeout(0);
  I2CManager::Setup(6, 7);
  //I2CManager::scanAll();
  if (! mlx.begin(MLX90640_I2CADDR_DEFAULT, &Wire)) {
    while (1) delay(10);
  }
  mlx.setMode(MLX90640_CHESS); 
  mlx.setResolution(MLX90640_ADC_16BIT);
  mlx90640_resolution_t res = mlx.getResolution();
  mlx.setRefreshRate(MLX90640_16_HZ);
  mlx90640_refreshrate_t rate = mlx.getRefreshRate();
  Wire.setClock(2000000);
}

void loop(){
  char command = 0;
  while (command != '@') { // Wait for the PC to send a '1' command
    while(Serial.available() == 0){delay(1);}
    command = Serial.read();
    if(command == '$')
      Serial.println("821ce9ba-a697-487b-a402-32e29b9d599d");
  }
  Serial.flush();
  if (mlx.getFrame(frame) != 0) {
    return;
  }
  std::stringstream k;
  for (uint8_t h=0; h<24; h++) {
    for (uint8_t w=0; w<32; w++) {
      float t = frame[h*32 + w];
      k << std::to_string(t) << "|";
    }
  }
  k << "@";
  Serial.print(k.str().c_str());
}