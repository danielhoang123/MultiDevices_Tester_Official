#include "Controller_Oled_1_3Inch.h"
#include "debugkxn.h"

Controller_Oled_1_3Inch_Data::Controller_Oled_1_3Inch_Data()
{
  this->nameDevice = "Oled";
  this->timeInterval = 1500;
  this->valueDevice = "No device";
  this->Add_AddressList(0x3C);
  // this->Add_HsCode(618);
  //  Add your code here
}

Controller_Oled_1_3Inch_Data::~Controller_Oled_1_3Inch_Data()
{
}

bool Controller_Oled_1_3Inch_Data::getData()
{
  // Add your code here
  this->valueDevice = "";
  this->valueDevice1 = "";

  count++;
  if(count > 2){
    count = 0;
  }

  if (count == 1)
  {
    U8GLIB_SH1106_128X64 u8g2(U8G_I2C_OPT_DEV_0 | U8G_I2C_OPT_NO_ACK | U8G_I2C_OPT_FAST);
    u8g2.setColorIndex(1);
    u8g2.firstPage();
    this->valueDevice += "Turn all pixel";
    this->valueDevice1 += "OLED 1.3 inch";
    do
    {
      u8g2.drawBitmapP(0, 0, 128 / 8, 64, epd_bitmap_D___n_m_i2_13);
    } while (u8g2.nextPage());

    delay(1000);

    u8g2.firstPage();

    do
    {
      u8g2.setFont(u8g_font_fub17);
      u8g2.drawStr(28, 42, "Hshop");
    } while (u8g2.nextPage());

    delay(1000);
  }

  if (count == 2)
  {
    U8GLIB_SSD1306_128X64 u8g2(U8G_I2C_OPT_DEV_0 | U8G_I2C_OPT_NO_ACK | U8G_I2C_OPT_FAST);
    this->valueDevice += "Turn all pixel";
    this->valueDevice1 += "OLED 0.96 inch";

    u8g2.setColorIndex(1);
    u8g2.firstPage();

    do
    {
      u8g2.drawBitmapP(0, 0, 128 / 8, 64, epd_bitmap_D___n_m_i2_13);
    } while (u8g2.nextPage());

    delay(1000);

    u8g2.firstPage();

    do
    {
      u8g2.setFont(u8g_font_fub17);
      u8g2.drawStr(28, 42, "Hshop");
    } while (u8g2.nextPage());

    delay(1000);
  }

  // if (count == 3)
  // {
  //   U8GLIB_SSD1306_128X32 u8g2(U8G_I2C_OPT_DEV_0 | U8G_I2C_OPT_NO_ACK | U8G_I2C_OPT_FAST);
  //   u8g2.setFont(u8g_font_tpssb);
  //   u8g2.setColorIndex(1);
  //   u8g2.firstPage();
  //   this->valueDevice += "Turn all pixel";
  //   this->valueDevice1 += "OLED 0.91 inch";
  //   do
  //   {
  //     u8g2.drawBitmapP(0, 0, 128 / 8, 64, epd_bitmap_D___n_m_i_091);
  //   } while (u8g2.nextPage());

  //   delay(250);

  //   u8g2.firstPage();
  //   do
  //   {
  //     u8g2.setFont(u8g_font_fub17);
  //     u8g2.drawStr(28, 0, "Hshop");
  //   } while (u8g2.nextPage());

  //   delay(1000);
  // }

  return true;
}

bool Controller_Oled_1_3Inch_Data::init()
{
  deInit();

  // u8g.setDefaultBackgroundColor();

  return 1;
}

bool Controller_Oled_1_3Inch_Data::deInit()
{

  return 1;
}

Controller_Oled_1_3Inch_Data device_Controller_Oled_1_3Inch;