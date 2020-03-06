#include "VOCSensor.h"

void VOCSensor::FillData()
{
  if(ccs.dataAvailable())
  {
    ccs.readAlgorithmResults();
//    Serial.print(ccs.getCO2());
//    Serial.println(" " + (String) ccs.getTVOC());
    dataSet[0] = ccs.getCO2();
    dataSet[1] = ccs.getTVOC();
  }
}

