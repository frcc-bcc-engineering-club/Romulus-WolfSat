#include "ParticulateSensor.h"

void ParticulateSensor::FillData()
{
  struct sps_values loc;
  cookie.GetValues (&loc);
  dataSet[0] = loc.MassPM1;
  dataSet [1] = loc.MassPM2;
  dataSet [2] = loc.MassPM4;
  dataSet [3] = loc.MassPM10;
  dataSet [4] = loc.NumPM0;
  dataSet [5] = loc.NumPM1;
  dataSet [6] = loc.NumPM2;
  dataSet [7] = loc.NumPM4;
  dataSet [8] = loc.NumPM10;
  dataSet [9] = loc.PartSize;
}
