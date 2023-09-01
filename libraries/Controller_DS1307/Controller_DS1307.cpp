#include "Controller_DS1307.h"
// #include "debugkxn.h"

Controller_DS1307_Data::Controller_DS1307_Data()
{
  this->nameDevice = "RTC(DS1307, 3231..)";
  this->timeInterval = 250;
  this->valueDevice = "No device";
  this->Add_AddressList(0x68);
  // this->Add_HsCode(865);
  // Add your code here

}

Controller_DS1307_Data::~Controller_DS1307_Data()
{
  
}

bool Controller_DS1307_Data::getData()
{
  // Add your code here
  this->valueDevice = "";

  // this->now = new DateTime; 
  DateTime now = rtc1.now();

  this->valueDevice = String(now.day()) + "/" + String(now.month()) + "/" + String(now.year());
  
  this->valueDevice1 = "0" + String(now.hour(), DEC) + ":" + String(now.minute(), DEC) + ":" + String(now.second(), DEC);
 
  return true;
}

bool Controller_DS1307_Data::init()
{
  deInit();
  // Add your code here
  RTC_DS1307 rtc1;
  Wire.begin();
  rtc1.begin();
  DateTime now = rtc1.now();
  int a = int(now.hour());
  int b = int(now.minute());
  int c = int(now.second());

  if(a < 7 && b < 5){
    rtc1.adjust(DateTime(2023, 4, 23, 7, 5, 0));
  }
  else{
    return false;
  }

  return 1;
}

bool Controller_DS1307_Data::deInit()
{
  // Add your code here

  return 1;
}

Controller_DS1307_Data device_Controller_DS1307;