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
    VOCSensor() : Sensor(2) 
    {
      Wire.begin();
      if(ccs.begin() == false)
      {
        Serial.print("CCS811 error. Please check wiring. Freezing...");
        while(true);
      }
    }
    void FillData() override;
};

#endif
