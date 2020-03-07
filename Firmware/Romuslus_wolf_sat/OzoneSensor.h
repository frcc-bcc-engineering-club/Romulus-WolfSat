#include "Sensor.h"
#ifndef OZONESENSOR_H
#define OZONESENSOR_H

class OzoneSensor : public Sensor
{
public:
    OzoneSensor() : Sensor(/* Data Size Integer goes here */)
    {
      ;
    }
    void FillData() override;
  private:
};

#endif
