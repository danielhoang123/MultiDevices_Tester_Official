#ifndef Controller_NRFRx_H__
#define Controller_NRFRx_H__
#include "dataAdapter.h"

// include your Libraries here
#include <SPI.h>
#include <RF24.h>

class Controller_NRFRx_Data: public Data_Adapter{
  public:
  // Add your declare here
  Controller_NRFRx_Data();
  virtual ~Controller_NRFRx_Data(){};
  bool getData();
  bool init();
  bool deInit();
};

extern Controller_NRFRx_Data NRFRx_Device;
#endif