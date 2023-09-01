// #include "debugkxn.h"
#include "Manager_Content.h"
#include "Manager_I2C_Devices.h"
#include "Btn_Process.h"
#include "view_LCD_Text.h"

// #include "Controller_Sieu_Am.h"
// #include "Controller_Test_Snippet.h"
// #include <Controller/Controller_DHT.h>
// #include "Controller_NRFRx.h"

#include "Controller_DHT.h"
#include "Controller_SR04.h"
#include "Controller_LM35.h"
#include "Controller_DS18B20.h"
#include "Controller_NRF.h"
#include "Controller_RC522.h"
#include "Controller_I2C_Scanner.h"

// // Include I2C Device
// #include "Controller_MKL_I2C_Motor.h"
// #include "Controller_MKL_RTC.h"
// #include "Controller_Test_I2C_Snippet.h"
// #include "Controller_MKL_RTC_Quoc.h"
// #include "Controller_MKL_RTC_Quoc_Pointer.h"
// #include "Controller_PAJ7620U2.h"

#include "Controller_Oled_1_3Inch.h"
#include "Controller_Oled_0_96Inch.h"
#include "Controller_Oled_0_91Inch.h"
#include "Controller_SHT30.h"
#include "Controller_MPU6050.h"
#include "Controller_HMC588L.h"
#include "Controller_BMP180.h"
#include "Controller_AHT20.h"
#include "Controller_BH1750.h"
#include "Controller_MMA8452.h"
#include "Controller_ADXL345.h"
#include "Controller_L3G4200D.h"
#include "Controller_DS1307.h"
#include "Controller_LSM303DLHC.h"
#include "Controller_MS5611.h"
#include "Controller_TCS34725.h"
#include "Controller_TOF10120.h"
#include "Controller_MPU9250.h"
#include "Controller_MAX44009.h"
#include "Controller_PCA9685.h"
#include "Controller_VL53L0X.h"
#include "Controller_GY906.h"
#include "Controller_HTU21.h"
#include "Controller_HDC1080.h"
#include "Controller_PN532.h"
#include "Controller_GY_HMC588L.h"

unsigned long startMillis = 0;
unsigned long startMillis1 = 0;
unsigned long startMillis2 = 0;

// int acquiredValue, value;
// float temp_float;
int timer;

bool flag1, temp_bool;
bool temp_bool1 = 0;
bool temp_bool2 = 0;
void AddManagerContent_Device()
{
  // manager_Content.my_Devices_List.add(&sieuAm_Device);
  // manager_Content.my_Devices_List.add(&NRFRx_Device);

  manager_Content.my_Devices_List.add(&Manager_I2C_Device);
  manager_Content.my_Devices_List.add(&Dht_Device);
  manager_Content.my_Devices_List.add(&SR04_Device);
  manager_Content.my_Devices_List.add(&LM35_Device);
  manager_Content.my_Devices_List.add(&DS18B20_Device);
  manager_Content.my_Devices_List.add(&RC522_Device);
  manager_Content.my_Devices_List.add(&NRF_Device);
  manager_Content.my_Devices_List.add(&I2C_Scanner_Device);
}

void Add_I2C_Device()
{
  // Manager_I2C_Device.myI2C_Devices_List.add(&MKL_I2C_Motor_Device);
  // Manager_I2C_Device.myI2C_Devices_List.add(&RTC_Device);
  // Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_Test_I2C_Snippet);
  // Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_MKL_RTC_Quoc);
  // Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_MKL_RTC_Quoc_Pointer);
  // Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_PAJ7620U2);

  Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_Oled_1_3Inch);
  Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_Oled_0_96Inch);
  Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_Oled_0_91Inch);
  Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_SHT30);
  Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_HMC588L);
  Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_BMP180);
  Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_AHT20);
  Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_BH1750);
  Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_MMA8452);
  Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_ADXL345);
  Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_L3G4200D);
  Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_DS1307);
  Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_LSM303DLHC);
  Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_MS5611);
  Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_TCS34725);
  Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_TOF10120);
  Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_MPU9250);
  Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_MAX44009);
  Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_PCA9685);
  Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_VL53L0X);
  Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_MPU6050);
  Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_HTU21);
  Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_HDC1080);
  Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_GY906);
  Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_PN532);
  Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_GY_HMC588L);
}

// ---------------------------------------------------------------------------------------
void setup()
{
  pinMode(5, OUTPUT);
  buttonInit();
  // debug("Start!");
  View_LCD_Text_Init();
  manager_Content.begin();
  temp_bool1 = 0;
  temp_bool2 = 0;
}
void loop()
{

  int acquiredValue = analogRead(A1);
  float temp_float = acquiredValue * 0.01;
  int value = map(acquiredValue, 880, 1023, 0, 100);

  if (millis() - startMillis1 >= 100)
  {
    timer++;
    startMillis1 = millis();
  }

  if (millis() - startMillis >= 5)
  {
    startMillis = millis();

    buttonLoop();
    manager_Content.getData();

    lcd.setCursor(19, 3);
    lcd.print("%");

    if (temp_float != 0)
    {
      if (temp_float >= 10.03 && temp_float < 10.15)
      {
        lcd.setCursor(17, 3);
        lcd.print("90%");
      }
      else if (temp_float >= 9.89 && temp_float < 10.01)
      {
        lcd.setCursor(17, 3);
        lcd.print("80%");
      }

      else if (temp_float >= 9.75 && temp_float < 9.87)
      {
        lcd.setCursor(17, 3);
        lcd.print("70%");
      }
      else if (temp_float >= 9.61 && temp_float < 9.73)
      {
        lcd.setCursor(17, 3);
        lcd.print("60%");
      }
      else if (temp_float >= 9.47 && temp_float < 9.59)
      {
        lcd.setCursor(17, 3);
        lcd.print("50%");
      }
      else if (temp_float >= 9.33 && temp_float < 9.45)
      {
        lcd.setCursor(17, 3);
        lcd.print("40%");
      }
      else if (temp_float >= 9.19 && temp_float < 9.31)
      {
        lcd.setCursor(17, 3);
        lcd.print("30%");
      }
      else if (temp_float >= 9.05 && temp_float < 9.17)
      {
        lcd.setCursor(17, 3);
        lcd.print("20%");
      }
      else if (temp_float >= 8.91 && temp_float < 9.03)
      {
        lcd.setCursor(17, 3);
        lcd.print("10%");
      }
      else if (temp_float >= 10.15)
      {
        lcd.setCursor(16, 3);
        lcd.print("100%");
      }
    }
    lcd.setCursor(0, 3);
    lcd.print(120 - (timer / 10));
    lcd.print("s");
  }

  // phân biệt giữa nguồn DC và nguồn pin
  if (acquiredValue >= 1015)
  {
    flag1 = 1;
  }
  else
  {
    flag1 = 0;
  }

  if (timer >= 1200 && flag1 == 0)
  {

    if (millis() - startMillis2 >= 1000)
    {
      digitalWrite(5, LOW);
      startMillis2 = millis();
    }
    else if (millis() - startMillis2 >= 500)
    {
      digitalWrite(5, HIGH);
    }
  }
  else
  {
    digitalWrite(5, LOW);
  }

  if (timer == 210)
  {
    temp_bool1 = 1;
  }

  if (temp_bool1 == 1 && temp_bool2 == 0)
  {
    lcd.clear();
    temp_bool2 = 1;
  }
  else
  {
    ;
    ;
  }
}
// ---------------------------------------------------------------------------------------

// Hàm cho nút nhấn Start
void Start_do_1_Click()
{
  // debugln("1 Click: Do it!");
  lcd.clear();
  manager_Content.init();
  manager_Content.timeInterval = 250;
}
void Start_do_2_Click()
{
  // debugln("2 Click: Re Start!");
  lcd.clear();
  manager_Content.deInit();
  manager_Content.timeInterval = 250;
}

// Hàm cho nút nhấn Up
void Up_do_0_Click()
{
  lcd.clear();
  manager_Content.deInit();
  manager_Content.Choseen_Menu++;
  manager_Content.timeInterval = 250;

  // debug("0 Click: Menu");
  // debugln(manager_Content.Choseen_Menu);
}
void Up_do_1_Click()
{
  lcd.clear();
  manager_Content.deInit();
  manager_Content.Choseen_Menu++;
  manager_Content.timeInterval = 250;

  // debug("1 Click: Menu");
  // debugln(manager_Content.Choseen_Menu);
}

// Hàm cho nút nhấn Down
void Down_do_0_Click()
{
  // debug("1 Click: Menu");
  // debugln(manager_Content.Choseen_Menu);
  lcd.clear();
  manager_Content.deInit();
  manager_Content.Choseen_Menu--;
  manager_Content.timeInterval = 250;
}
void Down_do_1_Click()
{
  // debug("1 Click: Menu");
  // debugln(manager_Content.Choseen_Menu);
  lcd.clear();
  manager_Content.deInit();
  manager_Content.Choseen_Menu--;
  manager_Content.timeInterval = 250;
}