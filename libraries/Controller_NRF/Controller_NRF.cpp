#include "Controller_nRF.h"
#include "MachTest_SP_IO.h"
#include "debugkxn.h"
#include "Btn_Process.h"

Controller_nRF_Data::Controller_nRF_Data()
{
  this->nameDevice = "NRF Tx";
  this->timeInterval = 250;
  this->valueDevice = "No device";
}

bool Controller_nRF_Data::getData()
{
  this->valueDevice = "x2Click Toggle LED";
}

bool Controller_nRF_Data::init()
{
  deInit();
  // Add your code here
  // pinMode(button_pin, INPUT);
  RF24 radio(9, 10);
  const byte address[6] = "12345";
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();

  // gửi để cho Rx nhận, nhận xong rồi phía Rx đảo trạng thái đèn khi nhận được tín hiệu
  const char text[] = "Your Button State is HIGH";
  radio.write(&text, sizeof(text));
  return 1;
}

bool Controller_nRF_Data::deInit()
{
  // Add your code here
  this->valueDevice = "x2Click to Start";
  return 1;
}

Controller_nRF_Data NRF_Device;