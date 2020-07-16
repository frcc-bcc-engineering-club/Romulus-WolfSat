#include "Sensor.h"
#include <SparkFunTMP102.h>

class InnerTemp : public Sensor
{

public:
 void FillData() override;
 void setAlarm(double temp);
 /*
  * set the alarm for when the tmp102 will trigger an interupt line so life support can
  * dealwith it. Probably will force disable the heater.
  */
 InnerTemp ();
 
  private:
    TMP102 tmp;
};
