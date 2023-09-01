#include "Controller_PCA9685.h"
#include "debugkxn.h"

Controller_PCA9685_Data::Controller_PCA9685_Data()
{
  this->nameDevice = "PCA9685";
  this->timeInterval = 250;
  this->valueDevice = "No device";
  this->Add_AddressList(0x40);
  //this->Add_HsCode(928);
  // Add your code here

}

Controller_PCA9685_Data::~Controller_PCA9685_Data()
{
  
}

bool Controller_PCA9685_Data::getData()
{
  // Add your code here
  this->valueDevice = "";
  Wire.beginTransmission(0x40);
  byte error = Wire.endTransmission();
  if (error == 0){
    this->valueDevice = "Found PCA9685 0x40";
  }
  else{
    this->valueDevice = "No PCA9685";
  }

  return true;
}

bool Controller_PCA9685_Data::init()
{
  deInit();
  // Add your code here
  Wire.begin();
  //Wire.beginTransmission(0x4A);
  return 1;
}

bool Controller_PCA9685_Data::deInit()
{
  // Add your code here

  return 1;
}

Controller_PCA9685_Data device_Controller_PCA9685;