#include "Controller_GY_HMC588L.h"
// #include "debugkxn.h"

MPU6050 accelgyro;
QMC5883LCompass compass;

Controller_GY_HMC588L_Data::Controller_GY_HMC588L_Data()
{
    this->nameDevice = "HMC588L from GY86(7)";
    this->timeInterval = 250;
    this->valueDevice = "No device";
    this->Add_AddressList(0x68);
    // this->Add_HsCode(194);
    // Add your code here
}

Controller_GY_HMC588L_Data::~Controller_GY_HMC588L_Data()
{
}

bool Controller_GY_HMC588L_Data::getData()
{
    // Add your code here
    this->valueDevice = "RAW Value:";
    this->valueDevice1 = "";
    this->valueDevice2 = "";

    compass.read();

    int x = compass.getX();
    int y = compass.getY();
    int z = compass.getZ();

    this->valueDevice1 += "x: " + String(x) + " ; " + "y: " + String(y);
    this->valueDevice2 += "z: " + String(z);
    // int a;

    // // Read compass values
    // compass.read();

    // // Return Azimuth reading
    // a = compass.getAzimuth();

    // Serial.print("A: ");
    // Serial.print(a);
    // Serial.println();
    // this->valueDevice1 += String(a);
    return true;
}

bool Controller_GY_HMC588L_Data::init()
{
    deInit();
    // Add your code here

    Wire.begin();
    accelgyro.setI2CMasterModeEnabled(false);
    accelgyro.setI2CBypassEnabled(true);
    accelgyro.setSleepEnabled(false);

    compass.init();

    return 1;
}

bool Controller_GY_HMC588L_Data::deInit()
{
    // Add your code here

    return 1;
}

Controller_GY_HMC588L_Data device_Controller_GY_HMC588L;