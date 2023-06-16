#include "Controller_nRF.h"
#include "MachTest_SP_IO.h"
#include "debugkxn.h"

RF24 radio(9, 10);

Controller_nRF_Data::Controller_nRF_Data()
{
  this->nameDevice = "NRF";
  this->timeInterval = 300;
  this->valueDevice = "No device";
  // Add your code here
}

bool Controller_nRF_Data::getData()
{
  // Add your code here
  this->valueDevice = "";

  unsigned long startMillis = 0;
  unsigned long currentMillis;

  boolean button_state;
  boolean led_on = LOW;
  boolean led_off = HIGH;

  currentMillis = millis();

  this->valueDevice = "x2Click ToggleLED";
  radio.write(&led_on, sizeof(led_on));

  // if (currentMillis - startMillis >= 100)
  // {
  //   if (button_state == LOW)
  //   {
  //     this->valueDevice = "LOW";
  //     radio.write(&led_on, sizeof(led_on));
  //   }
  //   startMillis = currentMillis;
  // }
  
  return true;
}

bool Controller_nRF_Data::init()
{
  deInit();
  // Add your code here
  const byte address[6] = "00001";

  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  return 1;
}

bool Controller_nRF_Data::deInit()
{
  // Add your code here
  return 1;
}

Controller_nRF_Data NRF_Device;