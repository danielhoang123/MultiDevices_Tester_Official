#include "Controller_MPU9250.h"
#include "debugkxn.h"

Controller_MPU9250_Data::Controller_MPU9250_Data()
{
  this->nameDevice = "MPU9250";
  this->timeInterval = 250;
  this->valueDevice = "No device";
  this->Add_AddressList(0x68);
  this->Add_HsCode(195);
  // Add your code here
}

Controller_MPU9250_Data::~Controller_MPU9250_Data()
{
}

bool Controller_MPU9250_Data::getData()
{
  // Add your code here
  this->valueDevice = "";
  this->valueDevice1 = "";
  this->valueDevice2 = "";

  this->valueDevice += "Yaw: " + String(mpu.getYaw(), 2);
  this->valueDevice1 += "Pitch: " + String(mpu.getPitch(), 2);
  this->valueDevice2 += "Roll: " + String(mpu.getRoll(), 2);
  return true;
}

bool Controller_MPU9250_Data::init()
{
  deInit();
  // Add your code here
  Wire.begin();

  mpu.setup(0x68);

  return 1;
}

bool Controller_MPU9250_Data::deInit()
{
  // Add your code here

  return 1;
}

Controller_MPU9250_Data device_Controller_MPU9250;