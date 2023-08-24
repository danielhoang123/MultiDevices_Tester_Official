#include "Controller_LM35.h"
#include "MachTest_SP_IO.h"
#include "debugkxn.h"

Controller_LM35_Data::Controller_LM35_Data()
{
  this->nameDevice = "LM35";
  this->timeInterval = 250;
  this->valueDevice = "No device";
  // Add your code here
}

bool Controller_LM35_Data::getData()
{
  // Add your code here
  this->valueDevice = String(lm35x.getCalculated(), 2) + String(char(223)) + "C";

  return true;
}

bool Controller_LM35_Data::init()
{
  deInit();
  // Add your code here
  pinMode(A0, INPUT);

  return 1;
}

bool Controller_LM35_Data::deInit()
{
  // Add your code here
  return 1;
}

Controller_LM35_Data LM35_Device;