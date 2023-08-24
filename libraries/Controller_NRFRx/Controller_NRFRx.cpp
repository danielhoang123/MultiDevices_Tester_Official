#include "Controller_NRFRx.h"
#include "MachTest_SP_IO.h"
#include "debugkxn.h"

RF24 radio1(9, 10);
const byte address1[6] = "12345";
bool led_mode = 0;
boolean button_state1 = 0;

Controller_NRFRx_Data::Controller_NRFRx_Data()
{
  this->nameDevice = "NRF Rx";
  this->timeInterval = 100;
  this->valueDevice = "No device";
  // Add your code here
}

bool Controller_NRFRx_Data::getData()
{
  // Add your code here
  radio.startListening();
  if (radio.available())
  {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    ledState = !ledState;
    digitalWrite(8, ledState);
  }
  delay(5);
  return true;
}

bool Controller_NRFRx_Data::init()
{
  deInit();
  // Add your code here
  pinMode(A2, OUTPUT);

  radio1.begin();
  radio1.openReadingPipe(0, address1);
  radio1.setPALevel(RF24_PA_MIN);
  radio1.startListening();

  return 1;
}

bool Controller_NRFRx_Data::deInit()
{
  // Add your code here
  this->valueDevice = "No Device";
  return 1;
}

Controller_NRFRx_Data NRFRx_Device;