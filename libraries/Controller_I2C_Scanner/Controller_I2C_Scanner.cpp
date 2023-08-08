#include "Controller_I2C_Scanner.h"
#include "MachTest_SP_IO.h"
#include "debugkxn.h"
#include "Manager_Content.h"

Controller_I2C_Scanner_Data::Controller_I2C_Scanner_Data()
{
    this->nameDevice = "I2C Scanner";
    this->timeInterval = 250;
    this->valueDevice = "No device";
    // manager_Content.my_Devices_List.add(this);
    // Add your code here
}

bool Controller_I2C_Scanner_Data::getData()
{
    // Add your code here
    int nDevices = 0;

    this->valueDevice = "";

    for (byte address = 1; address < 127; ++address)
    {

        Wire.beginTransmission(address);
        byte error = Wire.endTransmission();

        if (error == 0 && address != 39)
        {
            ++nDevices;

            this->valueDevice += "0x" + String(address, HEX) + " ";

            if (address < 16)
            {
                // Serial.print("0");
                this->valueDevice += "0";
            }
        }
        else if (error == 0 && address == 39)
        {

            this->valueDevice1 = "LCD's I2C: 0x" + String(address, HEX);
            ++nDevices;
        }
    }
    if (nDevices == 0)
    {
        // Serial.println("No I2C devices found\n");
        this->valueDevice = "No I2C address";
    }

    return true;
}

bool Controller_I2C_Scanner_Data::init()
{
    deInit();
    // Add your code here
    Wire.begin();
    return 1;
}

bool Controller_I2C_Scanner_Data::deInit()
{
    // Add your code here
    // this->valueDevice = "2 Click to Scan";
    return 1;
}

Controller_I2C_Scanner_Data I2C_Scanner_Device;