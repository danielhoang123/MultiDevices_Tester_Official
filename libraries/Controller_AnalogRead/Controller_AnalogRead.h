#ifndef Controller_AnalogRead_H__
#define Controller_AnalogRead_H__
#include "dataAdapter.h"

// include your Libraries here


class Controller_AnalogRead_Data: public Data_Adapter{
  public:
  // Add your declare here

  Controller_AnalogRead_Data();
  virtual ~Controller_AnalogRead_Data(){};
  bool getData();
  bool init();
  bool deInit();
};

extern Controller_AnalogRead_Data Analog_Device;
#endif