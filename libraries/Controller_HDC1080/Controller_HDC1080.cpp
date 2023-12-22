#include "Controller_HDC1080.h"
#include "debugkxn.h"

Controller_HDC1080_Data::Controller_HDC1080_Data()
{
  this->nameDevice = "HDC1080";
  this->timeInterval = 250;
  this->valueDevice = "No device";
  this->Add_AddressList(0x40);
  // this->Add_HsCode(1310);
  // Add your code here

}

Controller_HDC1080_Data::~Controller_HDC1080_Data()
{
  
}

bool Controller_HDC1080_Data::getData()
{
  // Add your code here
  ClosedCube_HDC1080 hdc1080;
  hdc1080.begin(0x40);
  this->valueDevice = String(hdc1080.readTemperature()) + String(char(223)) + "C";
  this->valueDevice1 = String(hdc1080.readHumidity()) +  "%";
  return true;
}

bool Controller_HDC1080_Data::init()
{
  deInit();
  // Add your code here
  
  return 1;
}

bool Controller_HDC1080_Data::deInit()
{
  // Add your code here

  return 1;
}

Controller_HDC1080_Data device_Controller_HDC1080;