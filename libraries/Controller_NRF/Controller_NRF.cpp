#include "Controller_nRF.h"
#include "MachTest_SP_IO.h"
#include "debugkxn.h"

RF24 radio(9, 10);
const byte address[6] = "12345";
int button_pin = 4;
const uint8_t led_on = 1;
const uint8_t led_off = 0;

Controller_nRF_Data::Controller_nRF_Data()
{
  this->nameDevice = "NRF";
  this->timeInterval = 10;
  this->valueDevice = "No device";
  // Add your code here
}

bool Controller_nRF_Data::getData()
{
  //********** Cách 1: Sử dụng Millis để thực hiện liên tục (this->timeInterval = 50) [KHÔNG CHẠY]**********//
  // unsigned long startMillis;
  // unsigned long currentMillis;
  // currentMillis = millis();
  // if (currentMillis - startMillis >= 200)
  // {
  //   bool button_state = digitalRead(4);
  //   if (button_state == HIGH)
  //   {
  //     this->valueDevice = "Hehe";
  //     radio.write(&led_on, sizeof(led_on));
  //   }
  //   else if (button_state == LOW)
  //   {
  //     this->valueDevice = "Hoho";
  //     radio.write(&led_off, sizeof(led_off));
  //   }
  //   else{
  //     return 0;
  //   }
  //   startMillis = currentMillis;
  // }
  //********** Cách 2: Cứ bấm vào là truyền 1 byte qua, (this->timeInterval = 10) (Có thể nhấp nháy đèn tx của con nhận)**********//
  // radio.stopListening(); //thêm đoạn này là do tham khảo trên mạng, có lẽ phải khởi tại cho con hiện tại là phát thì mới có thể truyền được
  // this->valueDevice = "x2Click";
  // radio.write(&led_on, sizeof(led_on));
  // delay(5);
  //********** Cách 3: Code mẫu trên internet (this->timeInterval = 10)(truyền thành công chuỗi "Your button State is HIGH")**********//
  radio.stopListening();
  bool button_state = digitalRead(4);
  if (button_state == HIGH)
  {
    const char text[] = "Your Button State is HIGH";
    radio.write(&text, sizeof(text));
  }
  else
  {
    const char text[] = "Your Button State is LOW";
    radio.write(&text, sizeof(text));
  }
  radio.write(&button_state, sizeof(button_state));
  // delay(5);
}

bool Controller_nRF_Data::init()
{
  deInit();
  // Add your code here
  pinMode(button_pin, INPUT);
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