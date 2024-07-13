#include "Controller_AnalogRead.h"
#include "MachTest_SP_IO.h"
#include "debugkxn.h"

Controller_AnalogRead_Data::Controller_AnalogRead_Data()
{
    this->nameDevice = "Analog";
    this->timeInterval = 50;
    this->valueDevice = "No device";
    // Add your code here
}

bool Controller_AnalogRead_Data::getData()
{
    // Add your code here
    this->valueDevice = "";
    int sensorValue = analogRead(A3);
    // print out the value you read:
    
    this->valueDevice += String(sensorValue);

    return true;
}

bool Controller_AnalogRead_Data::init()
{
    deInit();
    // Add your code here
    pinMode(A0, OUTPUT);
    
    pinMode(A1, OUTPUT);
    analogWrite(A1, 1024);

    pinMode(A2, OUTPUT);
    
    pinMode(A3, INPUT);
    return 1;
}

bool Controller_AnalogRead_Data::deInit()
{
    // Add your code here
    pinMode(A0, INPUT);
    pinMode(A1, INPUT);
    pinMode(A2, INPUT);
    pinMode(A3, INPUT);
    return 1;
}

Controller_AnalogRead_Data Analog_Device;