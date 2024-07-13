// #include "debugkxn.h"
#include "Manager_Content.h"
#include "Manager_I2C_Devices.h"
// #include "Manager_BatteryNBuzzer.h"
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
// #include "Controller_NRF.h"
#include "Controller_RC522.h"
#include "Controller_I2C_Scanner.h"
#include "Controller_Servo.h"
#include "Controller_AnalogRead.h"

// // Include I2C Device
// #include "Controller_MKL_I2C_Motor.h"
// #include "Controller_MKL_RTC.h"
// #include "Controller_Test_I2C_Snippet.h"
// #include "Controller_MKL_RTC_Quoc.h"
// #include "Controller_MKL_RTC_Quoc_Pointer.h"
// #include "Controller_PAJ7620U2.h"

#include "Controller_Oled_1_3Inch.h"
// #include "Controller_Oled_0_96Inch.h"
// #include "Controller_Oled_0_91Inch.h"
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

bool flag = 0;
// Khai báo biến và cấu hình bộ lọc Kalman
float Q = 0.001;  // Noise covariance process
float R = 1;      // Noise covariance measurement
float P = 1;      // Estimate error covariance
float K = 0;      // Kalman Gain
float X = 0;      // Value

// Khai báo biến cho bộ lọc trung vị
const int numReadings = 9;  // Số lượng giá trị để tính trung vị (phải là số lẻ)
int readings[numReadings];  // Mảng để lưu các giá trị đọc
int readIndex = 0;          // Chỉ số cho vị trí đọc hiện tại

void qDelay(unsigned long pa_Time) {
  unsigned long endTime = millis() + pa_Time;
  while (endTime >= millis()) {
    ;
    ;
  }
}

void buzzerBlink() {
  if (flag == 1) {

    flag = 0;
    analogWrite(A2, 1024);
    qDelay(50);
    analogWrite(A2, 0);
    qDelay(50);
    analogWrite(A2, 1024);
    qDelay(50);
    analogWrite(A2, 0);
    qDelay(50);
    analogWrite(A2, 1024);
    qDelay(50);
    analogWrite(A2, 0);
    qDelay(50);
    analogWrite(A2, 1024);
    qDelay(50);
    analogWrite(A2, 0);
    qDelay(50);

    lcd.setCursor(0, 3);
    lcd.print("   SAC PIN DI !!!   ");
  }
}

int readBatteryValue() {

  int rawData = analogRead(A1);
  if(rawData < 775){
    flag = 1;
    buzzerBlink();
    qDelay(1000);
  }
  // Áp dụng bộ lọc Kalman
  P = P + Q;
  K = P / (P + R);
  X = X + K * (rawData - X);
  P = (1 - K) * P;

  // Lưu giá trị đã lọc vào mảng readings
  readings[readIndex] = X;
  readIndex = (readIndex + 1) % numReadings;  // Di chuyển đến vị trí đọc tiếp theo

  // Tạo bản sao của mảng readings để sắp xếp
  int sortedReadings[numReadings];
  for (int i = 0; i < numReadings; i++) {
    sortedReadings[i] = readings[i];
  }

  // Sắp xếp mảng để tìm giá trị trung vị
  for (int i = 0; i < numReadings - 1; i++) {
    for (int j = i + 1; j < numReadings; j++) {
      if (sortedReadings[i] > sortedReadings[j]) {
        int temp = sortedReadings[i];
        sortedReadings[i] = sortedReadings[j];
        sortedReadings[j] = temp;
      }
    }
  }

  // Lấy giá trị trung vị
  int median = sortedReadings[numReadings / 2];

  // Chuyển đổi giá trị từ khoảng 770-1024 sang 0-100
  int filteredValue = constrain(median, 770, 1024);
  int scaledValue = map(filteredValue, 770, 1024, 0, 100);

  // // In giá trị đã lọc và đã chuyển đổi
  // Serial.print("Raw data: ");
  // Serial.print(rawData);
  // Serial.print(" | Filtered data: ");
  // Serial.print(X);
  // Serial.print(" | Median data: ");
  // Serial.print(median);
  // Serial.print(" | Scaled data: ");

  lcd.setCursor(16, 3);
  if (scaledValue >= 100) {
    lcd.print(scaledValue);
    lcd.print("%");
  }
  else if(scaledValue < 100 && scaledValue >= 10){
    lcd.print(" ");
    lcd.print(scaledValue);
    lcd.print("%");
  }
  else if(scaledValue < 10){
    lcd.print("  "); 
    lcd.print(scaledValue);
    lcd.print("%");
  }

  // Serial.println(scaledValue);

  qDelay(10);
  return scaledValue;
}
void AddManagerContent_Device() {
  // manager_Content.my_Devices_List.add(&sieuAm_Device);
  // manager_Content.my_Devices_List.add(&NRFRx_Device);

  manager_Content.my_Devices_List.add(&Manager_I2C_Device);
  manager_Content.my_Devices_List.add(&Dht_Device);
  manager_Content.my_Devices_List.add(&SR04_Device);
  manager_Content.my_Devices_List.add(&LM35_Device);
  manager_Content.my_Devices_List.add(&DS18B20_Device);
  manager_Content.my_Devices_List.add(&RC522_Device);
  manager_Content.my_Devices_List.add(&Analog_Device);
  // manager_Content.my_Devices_List.add(&NRF_Device);
  manager_Content.my_Devices_List.add(&Servo_Device);
  manager_Content.my_Devices_List.add(&I2C_Scanner_Device);
}

void Add_I2C_Device() {
  // Manager_I2C_Device.myI2C_Devices_List.add(&MKL_I2C_Motor_Device);
  // Manager_I2C_Device.myI2C_Devices_List.add(&RTC_Device);
  // Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_Test_I2C_Snippet);
  // Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_MKL_RTC_Quoc);
  // Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_MKL_RTC_Quoc_Pointer);
  // Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_PAJ7620U2);

  Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_Oled_1_3Inch);
  // Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_Oled_0_96Inch);
  // Manager_I2C_Device.myI2C_Devices_List.add(&device_Controller_Oled_0_91Inch);
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
void setup() {
  buttonInit();
  // debug("Start!");
  // Serial.begin(9600);
  View_LCD_Text_Init();
  manager_Content.begin();

  pinMode(A2, OUTPUT);

  for (int i = 0; i < numReadings; i++) {
    readings[i] = 0;
  }
  readBatteryValue();
}
void loop() {

  buttonLoop();
  manager_Content.getData();
  readBatteryValue();
  // BuzzBat_Content.Battery_LCD();
  // BuzzBat_Content.Buzzer_Timer();
  // BuzzBat_Content.Buzzer_Blinking();
  // buzzer();
}
// ---------------------------------------------------------------------------------------

// Hàm cho nút nhấn Start
void Start_do_1_Click() {
  // debugln("1 Click: Do it!");
  lcd.clear();
  manager_Content.init();
  manager_Content.timeInterval = 250;
}
void Start_do_2_Click() {
  // debugln("2 Click: Re Start!");
  lcd.clear();
  manager_Content.deInit();
  manager_Content.timeInterval = 250;
}

// Hàm cho nút nhấn Up
void Up_do_0_Click() {
  lcd.clear();
  manager_Content.deInit();
  manager_Content.Choseen_Menu++;
  manager_Content.timeInterval = 250;

  // debug("0 Click: Menu");
  // debugln(manager_Content.Choseen_Menu);
}
void Up_do_1_Click() {
  lcd.clear();
  manager_Content.deInit();
  manager_Content.Choseen_Menu++;
  manager_Content.timeInterval = 250;

  // debug("1 Click: Menu");
  // debugln(manager_Content.Choseen_Menu);
}

// Hàm cho nút nhấn Down
void Down_do_0_Click() {
  // debug("1 Click: Menu");
  // debugln(manager_Content.Choseen_Menu);
  lcd.clear();
  manager_Content.deInit();
  manager_Content.Choseen_Menu--;
  manager_Content.timeInterval = 250;
}
void Down_do_1_Click() {
  // debug("1 Click: Menu");
  // debugln(manager_Content.Choseen_Menu);
  lcd.clear();
  manager_Content.deInit();
  manager_Content.Choseen_Menu--;
  manager_Content.timeInterval = 250;
}