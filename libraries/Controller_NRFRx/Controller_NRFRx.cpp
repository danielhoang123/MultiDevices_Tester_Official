#include "Controller_NRFRx.h"
#include "MachTest_SP_IO.h"
#include "debugkxn.h"

RF24 radio1(9, 10);
const byte address1[6] = "12345";
bool led_mode = 0;
boolean button_state1 = 0;
Controller_NRFRx_Data::Controller_NRFRx_Data()
{
  this->nameDevice = "NRFRx";
  this->timeInterval = 10;
  this->valueDevice = "No device";
  // Add your code here
}

bool Controller_NRFRx_Data::getData()
{
  // Add your code here
  this->valueDevice = "Start Listening";
  //********** Cách 1: Setup cơ bản, khi available thì đảo trạng thái led (this->timeInterval = 200) [KHÔNG CHẠY, chớp đèn liên tục như luôn available]**********//
  radio1.startListening();
  if (radio1.available())
  {
    char text[32] = "";
    radio1.read(&text, sizeof(text));
    radio1.read(&button_state1, sizeof(button_state1));
    led_mode = !led_mode;
    digitalWrite(A2, led_mode);
  }
  delay(10);

  // radio1.startListening();
  // if (radio1.available())
  // {
  //   this->valueDevice = "Hehe";
  //   char text[32] = "";
  //   radio1.read(&text, sizeof(text));
  //   radio1.read(&button_state1, sizeof(button_state1));
  //   if (button_state1 == HIGH)
  //   {
  //     digitalWrite(6, LOW);
  //     // Serial.println(text);
  //   }
  //   else
  //   {
  //     digitalWrite(6, HIGH);
  //     // Serial.println(text);
  //   }
  // }
  // delay(5);
  return true;
}

bool Controller_NRFRx_Data::init()
{
  deInit();
  // Add your code here
  pinMode(A2, OUTPUT);
  Serial.begin(9600);
  radio1.begin();
  if(radio1.isChipConnected()){
    Serial.println("Hehe");
  }
  else{
    Serial.println("Huhu");
  }
  radio1.openReadingPipe(0, address1);
  radio1.setPALevel(RF24_PA_MIN);
  radio1.startListening();
  
  return 1;
}

bool Controller_NRFRx_Data::deInit()
{
  // Add your code here
  return 1;
}

Controller_NRFRx_Data NRFRx_Device;