#include "Controller_SHARP.h"
#include "MachTest_SP_IO.h"
#include "debugkxn.h"

Controller_SHARP_Data::Controller_SHARP_Data()
{
  this->nameDevice = "SHARP";
  this->timeInterval = 250;
  this->valueDevice = "No device";
  // Add your code here
}

bool Controller_SHARP_Data::getData()
{
  // Add your code here
  
  return true;
}

bool Controller_SHARP_Data::init()
{
  deInit();
  // Add your code here
  
  return 1;
}

bool Controller_SHARP_Data::deInit()
{
  // Add your code here
  return 1;
}

Controller_SHARP_Data SHARP_Device;