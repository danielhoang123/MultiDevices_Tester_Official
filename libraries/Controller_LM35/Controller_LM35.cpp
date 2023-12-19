#include "Controller_LM35.h"
#include "MachTest_SP_IO.h"
#include "debugkxn.h"

Controller_LM35_Data::Controller_LM35_Data()
{
  this->nameDevice = "LM35";
  this->timeInterval = 10;
  this->valueDevice = "No device";
  // Add your code here
}

bool Controller_LM35_Data::getData()
{
  // Add your code here
  this->valueDevice = String(lm35x.getCalculated(), 2) + String(char(223)) + "C";
  // this->valueDevice = "";
  // int temp_adc_val;
  // float temp_val;
  // temp_adc_val = analogRead(lm35_pin); /* Read Temperature */
  // temp_val = (temp_adc_val * 4.88);    /* Convert adc value to equivalent voltage */
  // temp_val = (temp_val / 10);          /* LM35 gives output of 10mv/°C */

  // this->valueDevice += String(temp_val, 1) + String(char(223)) + "C";

  return true;
}

bool Controller_LM35_Data::init()
{
  deInit();
  // Add your code here
  pinMode(A0, INPUT);
  pinMode(A1, OUTPUT);
  return 1;
}

bool Controller_LM35_Data::deInit()
{
  // Add your code here
  pinMode(A1, INPUT);
  return 1;
}

Controller_LM35_Data LM35_Device;