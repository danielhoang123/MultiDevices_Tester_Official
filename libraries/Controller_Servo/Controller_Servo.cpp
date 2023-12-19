#include "Controller_Servo.h"
#include "MachTest_SP_IO.h"

Servo Servo1;
int servoPin = 5;

Controller_Servo_Data::Controller_Servo_Data()
{
    this->nameDevice = "Servo";
    this->timeInterval = 1500;
    this->valueDevice = "No device";
    // Add your code here
}

bool Controller_Servo_Data::getData()
{
    this->valueDevice = "";

    temp++;
    
    /*C1*/

    if (temp == 1)
    {

        this->valueDevice = "0" + String(char(223));
        Servo1.write(0);
    }
    else if (temp == 2)
    {

        this->valueDevice = "90" + String(char(223));
        Servo1.write(90);
    }
    else if (temp == 3)
    {

        this->valueDevice = "180" + String(char(223));
        Servo1.write(180);
    }
    else if (temp > 3)
    {
        temp = 0;
    }
    else
    {
        return;
    }

    return true;
}

bool Controller_Servo_Data::init()
{
    deInit();
    // Add your code here
    Servo1.attach(servoPin);
    return 1;
}

bool Controller_Servo_Data::deInit()
{
    // Add your code here
    return 1;
}

Controller_Servo_Data Servo_Device;