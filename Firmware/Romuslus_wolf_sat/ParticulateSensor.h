#ifndef PARTICULATESENSOR_H
#define PARTICULATESENSOR_H
#include "Sensor.h"

class ParticulateSensor : public Sensor
{
public:
  ParticulateSensor() : Sensor(/* I need a data size */)
  {
    ;
  }
  void FillData() override;
};


#endif
