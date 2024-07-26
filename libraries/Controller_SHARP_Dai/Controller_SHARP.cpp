#include "Controller_SHARP.h"
#include "MachTest_SP_IO.h"
#include "debugkxn.h"

Controller_SHARP_Data::Controller_SHARP_Data()
{
  this->nameDevice = "SHARP Dai";
  this->timeInterval = 250;
  this->valueDevice = "No device";
  // Add your code here
}

bool Controller_SHARP_Data::getData()
{
  // Add your code here
  longType_distance = this->longSharpSensor->distance();
  this->valueDevice = String(longType_distance) + "cm";
  return true;
}

bool Controller_SHARP_Data::init()
{
  deInit();
  // Add your code here
  this->longSharpSensor = new SharpIR(A3, longType_model);
  return 1;
}

bool Controller_SHARP_Data::deInit()
{
  // Add your code here
  if(this->longSharpSensor != NULL){
    delete longSharpSensor;
  }

}

Controller_SHARP_Data SHARP_Device;