#include "VOCSensor.h"

void VOCSensor::FillData()
{
  if(ccs.dataAvailable())
  {
    ccs.readAlgorithmResults();
    dataSet[0] = ccs.getCO2();
    dataSet[1] = ccs.getTVOC();
  }
}

