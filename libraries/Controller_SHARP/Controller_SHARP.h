#ifndef Controller_SHARP_H__
#define Controller_SHARP_H__
#include "dataAdapter.h"

// include your Libraries here


class Controller_SHARP_Data: public Data_Adapter{
  public:
  // Add your declare here

  Controller_SHARP_Data();
  virtual ~Controller_SHARP_Data(){};
  bool getData();
  bool init();
  bool deInit();
};

extern Controller_SHARP_Data SHARP_Device;
#endif