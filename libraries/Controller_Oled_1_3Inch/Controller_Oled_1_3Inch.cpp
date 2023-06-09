#include "Controller_Oled_1_3Inch.h"
#include "debugkxn.h"

Controller_Oled_1_3Inch_Data::Controller_Oled_1_3Inch_Data()
{
  this->nameDevice = "Oled_1.3Inch";
  this->timeInterval = 250;
  this->valueDevice = "No device";
  this->Add_AddressList(0x3C);
  this->Add_HsCode(618);
  // Add your code here

}

Controller_Oled_1_3Inch_Data::~Controller_Oled_1_3Inch_Data()
{
  
}

bool Controller_Oled_1_3Inch_Data::getData()
{
  // Add your code here
  this->valueDevice = "";
  
  return true;
}

bool Controller_Oled_1_3Inch_Data::init()
{
  deInit();

  U8GLIB_SH1106_128X64 u8g2(U8G_I2C_OPT_DEV_0 | U8G_I2C_OPT_NO_ACK | U8G_I2C_OPT_FAST);
  
  u8g2.setFont(u8g_font_tpssb);
  u8g2.setColorIndex(1);
  //u8g.setDefaultBackgroundColor();
  
  u8g2.firstPage();
  
  do{
   u8g2.drawBitmapP(0, 0, 128/8, 64, epd_bitmap_D___n_m_i2);
  }while(u8g2.nextPage());
  
  delay(3000);
  
  u8g2.firstPage();
  
  do{
   u8g2.drawBitmapP(0, 0, 128/8, 64, epd_bitmap_hshop_logo_new2);
  }while(u8g2.nextPage());

  return 1;
}

bool Controller_Oled_1_3Inch_Data::deInit()
{

  return 1;
}

Controller_Oled_1_3Inch_Data device_Controller_Oled_1_3Inch;