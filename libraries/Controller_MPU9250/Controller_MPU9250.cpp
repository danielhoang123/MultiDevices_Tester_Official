#include "Controller_MPU9250.h"
#include "debugkxn.h"

Controller_MPU9250_Data::Controller_MPU9250_Data()
{
  this->nameDevice = "NameDevice";
  this->timeInterval = 250;
  this->valueDevice = "No device";
  this->Add_AddressList(0x68);
  this->Add_HsCode(1518);
  // Add your code here

}

Controller_MPU9250_Data::~Controller_MPU9250_Data()
{
  
}

bool Controller_MPU9250_Data::getData()
{
  // Add your code here
  this->valueDevice = "device value";
  
  return true;
}

bool Controller_MPU9250_Data::init()
{
  deInit();
  // Add your code here
  
  return 1;
}

bool Controller_MPU9250_Data::deInit()
{
  // Add your code here

  return 1;
}

Controller_MPU9250_Data device_Controller_MPU9250;