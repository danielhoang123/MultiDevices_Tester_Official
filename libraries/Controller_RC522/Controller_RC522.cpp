#include "Controller_RC522.h"
#include "MachTest_SP_IO.h"
#include "debugkxn.h"

MFRC522 mfrc522(9, 10);

Controller_RC522_Data::Controller_RC522_Data()
{
  this->nameDevice = "RC522";
  this->timeInterval = 250;
  this->valueDevice = "x2Click to Start";
  // Add your code here
}

bool Controller_RC522_Data::getData()
{
  // Add your code here
  this->valueDevice = "";
  if (!mfrc522.PICC_IsNewCardPresent())
  {
    return false;
  }

  // Select one of the cards
  if (!mfrc522.PICC_ReadCardSerial())
  {
    return false;
  }
  String content = "";
  byte letter;
  this->valueDevice += "UID: ";
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    this->valueDevice += String(mfrc522.uid.uidByte[i], HEX) + " ";
  }
  return true;
}

bool Controller_RC522_Data::init()
{
  deInit();
  // Add your code here

  SPI.begin();
  mfrc522.PCD_Init();
  return 1;
}

bool Controller_RC522_Data::deInit()
{
  // Add your code here
  return 1;
}

Controller_RC522_Data RC522_Device;