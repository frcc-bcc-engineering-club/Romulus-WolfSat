#include "Sensor.h"
#include <Wire.h>
#include <SparkFun_MS5803_I2C.h>

#ifndef AIRPRESSURE_H
#define AIRPRESSURE_H


class AirPressure : public Sensor
{
  MS5803 ms5803 = MS5803(ADDRESS_HIGH);
  double baseline = 0;
  double altimeter = 0;
  double Altitude(double , double);
  public:
  AirPressure() : Sensor(3)
  {
    ms5803.reset();
    ms5803.begin();
    baseline = ms5803.getPressure(ADC_4096);
    altimeter = baseline;
  }
  void FillData() override;
};

#endif
