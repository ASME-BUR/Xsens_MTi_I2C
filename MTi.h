#ifndef MTi_h
#define MTi_h

#include "Xbus.h"
#include "Wire.h"

class MTi
{
public:
  MTi(uint8_t x, uint8_t y);
  uint8_t drdy;
  uint8_t address;
  bool detect(uint16_t timeout);
  void requestDeviceInfo();
  void configureOutputs();
  void goToConfig();
  void goToMeasurement();
  void readMessages(bool verbose = false);
  void printData();
  float *getQuat()
  {
    return xbus.quat;
  }
  float *getAcceleration()
  {
    return xbus.acc;
  }
  float *getRateOfTurn()
  {
    return xbus.rot;
  }
  float *getMag()
  {
    return xbus.mag;
  }

private:
  Xbus xbus;
  void sendMessage(uint8_t *message, uint8_t numBytes, bool verbose = false);
};

#endif
