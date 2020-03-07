#ifndef PARTICULATESENSOR_H
#define PARTICULATESENSOR_H
#include "sps30.h"
#include "Sensor.h"
#include "Arduino.h"
#define SPS30_DEBUG 0

class ParticulateSensor : public Sensor
{
public:
  ParticulateSensor() : Sensor(10)
  {
    Serial.begin(115200);
    Serial.println("STARTING SPS30");
      cookie.EnableDebugging(SPS30_DEBUG);
    if((cookie.begin (SERIALPORT1) == false))
      Serial.println("SPS :: COMM DONE GOOFED");
    if ((cookie.probe() == false))
      Serial.println ("SPS :: PROBE INITILIZATION BAD");
    else 
      Serial.println ("SPS :: PROBE INITILIZATION GUD");
    if ((cookie.reset() == false))
      Serial.println ("SPS :: RESET DONE GOOFED");
    if ((cookie.clean() == true))
      Serial.println("SPS :: CLEAN GUD");
    else
      Serial.println("SPS :: NO CLEAN");
    if ((cookie.start () == true))
      Serial.println ("SPS :: BEGINNING MEASUREMENT");
    else 
      Serial.println ("SPS :: MEASUREMENT GOOF");  
  }
  void FillData() override;
  private:
  SPS30 cookie;
};


#endif
