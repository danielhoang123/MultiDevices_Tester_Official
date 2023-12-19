#include "Controller_DS18B20.h"
#include "MachTest_SP_IO.h"
// #include "debugkxn.h"

Controller_DS18B20_Data::Controller_DS18B20_Data()
{
  this->nameDevice = "DS18B20";
  this->timeInterval = 250;
  this->valueDevice = "x2Click to Start";
  // Add your code here
}

bool Controller_DS18B20_Data::getData()
{
  // Add your code here
  OneWire oneWire(ONE_WIRE_BUS);
  DallasTemperature sensor(&oneWire);
  sensor.requestTemperatures();
  this->valueDevice = String(sensor.getTempCByIndex(0)) + String(char(223)) + "C";

  return true;
}

bool Controller_DS18B20_Data::init()
{
  deInit();

  return 1;
}

bool Controller_DS18B20_Data::deInit()
{
  // Add your code here

  return 1;
}

Controller_DS18B20_Data DS18B20_Device;