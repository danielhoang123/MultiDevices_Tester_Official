#ifndef Controller_LM35_H__
#define Controller_LM35_H__
#include "dataAdapter.h"

// include your Libraries here
#include "quoc_LM35_Kalman.h"
// #define lm35_pin A0
class Controller_LM35_Data: public Data_Adapter{
  public:
  // Add your declare here
  quoc_lm35 lm35x;

  Controller_LM35_Data();
  virtual ~Controller_LM35_Data(){};
  bool getData();
  bool init();
  bool deInit();
};

extern Controller_LM35_Data LM35_Device;
#endif