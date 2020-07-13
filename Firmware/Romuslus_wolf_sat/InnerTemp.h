#include "Sensor.h"
#include <SparkFunTMP102.h>

class InnerTemp : Sensor
{

public:
 void FillData() override;

 InnerTemp ()
 
  private:
    TMP102 tmp102;
};
