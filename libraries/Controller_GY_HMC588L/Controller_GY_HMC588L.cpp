#include "Controller_GY_HMC588L.h"
// #include "debugkxn.h"

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
    this->valueDevice = "";
    
    MPU6050 accelgyro;
    HMC5883L mag;
    Wire.begin();

    accelgyro.setI2CMasterModeEnabled(false);
    accelgyro.setI2CBypassEnabled(true);
    accelgyro.setSleepEnabled(false);

    mag.initialize();

    
    mag.getHeading(&mx, &my, &mz);
    float heading = atan2(my, mx);

    if (heading < 0)
        heading += 2 * M_PI;

    float trueHeading = heading * 180 / M_PI;
    this->valueDevice = String(trueHeading, 2) + " from North";

    return true;
}

bool Controller_GY_HMC588L_Data::init()
{
    deInit();
    // Add your code here

    return 1;
}

bool Controller_GY_HMC588L_Data::deInit()
{
    // Add your code here

    return 1;
}

Controller_GY_HMC588L_Data device_Controller_GY_HMC588L;