#include "Sensor.h"

Sensor::Sensor()
{
  
}

Sensor::~Sensor()
{
  
}


Sensor::Sensor(int in_dataSize)
{
  dataSize = in_dataSize;
  dataSet = new double[dataSize];
}


double* Sensor::GetData()
{
  return dataSet;
}


int Sensor::GetSize()
{
  return dataSize; 
}
