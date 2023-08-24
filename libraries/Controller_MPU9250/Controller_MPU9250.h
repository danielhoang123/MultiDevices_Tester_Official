#ifndef Controller_MPU9250_H__
#define Controller_MPU9250_H__
#include "Model_I2C_Device.h"

// include your Libraries here
#include "MPU9250.h"

class Controller_MPU9250_Data: public Model_I2C_Device{
  public:
  // Add your declare here
  MPU9250 mpu;
  Controller_MPU9250_Data();
  ~Controller_MPU9250_Data();
  bool getData();
  bool init();
  bool deInit();
};

extern Controller_MPU9250_Data device_Controller_MPU9250;
#endif