#include "Controller_SHARP_Ngan.h"
#include "MachTest_SP_IO.h"
#include "debugkxn.h"

Controller_SHARP_Ngan_Data::Controller_SHARP_Ngan_Data()
{
  this->nameDevice = "SHARP Ngan";
  this->timeInterval = 250;
  this->valueDevice = "No device";
  // Add your code here
}

bool Controller_SHARP_Ngan_Data::getData()
{
  // Add your code here
  shortType_distance = this->shortSharpSensor->distance();
  this->valueDevice = String(shortType_distance) + "cm"; 
  return true;
}

bool Controller_SHARP_Ngan_Data::init()
{
  deInit();
  // Add your code here
  this->shortSharpSensor = new SharpIR(A3, shortType);
  return 1;
}

bool Controller_SHARP_Ngan_Data::deInit()
{
  // Add your code here
  if(this->shortSharpSensor != NULL){
    delete shortSharpSensor;
  }
  return 1;
}

Controller_SHARP_Ngan_Data SharpNgan_Device;