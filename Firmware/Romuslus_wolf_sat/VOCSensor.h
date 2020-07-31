#include "Sensor.h"
#include <Wire.h>
#include "SparkFunCCS811.h"
#ifndef VOCSENSOR_H
#define VOCSENSOR_H

#define CCS811_ADDR 0x5B


class VOCSensor : public Sensor
{
  CCS811 ccs = CCS811(CCS811_ADDR);
  public:
    VOCSensor(bool in_debug) : Sensor(2) 
    {
      Wire.begin();
      if((ccs.begin() == false ) && (in_debug))
      {
        Serial.print("CCS811 error. Please check wiring.");
      }
    }
    void FillData() override;
};

#endif
