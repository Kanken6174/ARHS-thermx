#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/semphr.h>

extern SemaphoreHandle_t serial_mutex;

extern void THREAD_SAFE_PRINTLN(String data);

enum debugLevel{
    data = 0,
    error = 1,
    warn = 2,
    info = 3,
    verbose = 4 //only use as a last resort, it makes things go real bad on the serial port
};

#define DEBUGLEVEL debugLevel::data

#define LOG_DATA(x) do { if (DEBUGLEVEL >= debugLevel::data) { THREAD_SAFE_PRINTLN(String("D")+x); } } while (0)

#define LOG_ERROR(x) do { if (DEBUGLEVEL >= debugLevel::error) { THREAD_SAFE_PRINTLN(String("E")+x); } } while (0)

#define LOG_WARN(x) do { if (DEBUGLEVEL >= debugLevel::warn) { THREAD_SAFE_PRINTLN(String("W")+x); } } while (0)

#define LOG_INFO(x) do { if (DEBUGLEVEL >= debugLevel::info) { THREAD_SAFE_PRINTLN(String("I")+x); }} while (0)

#define LOG_VERBOSE(x) do { if (DEBUGLEVEL >= debugLevel::verbose) { THREAD_SAFE_PRINTLN(String("V")+x); }} while (0)