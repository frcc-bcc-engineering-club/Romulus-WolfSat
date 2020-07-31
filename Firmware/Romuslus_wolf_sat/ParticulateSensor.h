#ifndef PARTICULATESENSOR_H
#define PARTICULATESENSOR_H
#include "sps30.h"
#include "Sensor.h"
#include "Arduino.h"
#define SPS30_DEBUG 0

class ParticulateSensor : public Sensor
{
public:
  ParticulateSensor(bool debug) : Sensor(10)
  {
    
    //Serial.begin(115200);
    if (debug)
      Serial.println("STARTING SPS30");
    cookie.EnableDebugging(SPS30_DEBUG);

    if((cookie.begin (SERIALPORT1) == false) && debug)
      Serial.println("SPS :: COMM DONE GOOFED");
    if ((cookie.probe() == false) && debug)
      Serial.println ("SPS :: PROBE INITILIZATION BAD");
    else if (debug)
      Serial.println ("SPS :: PROBE INITILIZATION GUD");
    if ((cookie.reset() == false) && debug)
      Serial.println ("SPS :: RESET DONE GOOFED");
    if ((cookie.clean() == true) && debug)
      Serial.println("SPS :: CLEAN GUD");
    else if (debug)
      Serial.println("SPS :: NO CLEAN");
    if ((cookie.start () == true)  && debug)
      Serial.println ("SPS :: BEGINNING MEASUREMENT");
    else  if (debug)
      Serial.println ("SPS :: MEASUREMENT GOOF");  
  }
  void FillData() override;
  private:
  SPS30 cookie;
};


#endif
