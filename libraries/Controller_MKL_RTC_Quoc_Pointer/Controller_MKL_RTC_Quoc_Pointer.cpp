#include "Controller_MKL_RTC_Quoc_Pointer.h"
#include "debugkxn.h"

Controller_MKL_RTC_Quoc_Pointer_Data::Controller_MKL_RTC_Quoc_Pointer_Data()
{
  this->nameDevice = "RTC_SetTime";
  this->timeInterval = 250;
  this->valueDevice = "No device";
  this->Add_AddressList(0x68);
  // this->Add_HsCode(1518);
  // Add your code here

}

Controller_MKL_RTC_Quoc_Pointer_Data::~Controller_MKL_RTC_Quoc_Pointer_Data()
{
  
}

bool Controller_MKL_RTC_Quoc_Pointer_Data::getData()
{
  // Add your code here
  

  this->valueDevice = "";

  this->valueDevice  = "Set at 07:05:00";
  this->valueDevice1 = "23/04/2023";
  this->valueDevice2 = "Run RTC_ReadTime";

  return true;
}

bool Controller_MKL_RTC_Quoc_Pointer_Data::init()
{
  deInit();
  this->rtc = new RTC_DS3231;
  this->rtc->begin();
  this->rtc->adjust(DateTime(2023, 4, 23, 7, 5, 0));

  return 1;
}

bool Controller_MKL_RTC_Quoc_Pointer_Data::deInit()
{
  // Add your code here
  if(this->rtc != NULL){
    free(this->rtc);
    this->rtc = NULL;
  }

  // if(this->wire != NULL){
  //   free(this->wire);
  //   this->wire = NULL;
  // }
  return 1;
}

Controller_MKL_RTC_Quoc_Pointer_Data device_Controller_MKL_RTC_Quoc_Pointer;