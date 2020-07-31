#include "Sensor.h"
#include "Arduino.h"

Sensor::Sensor()
{
  
}

Sensor::~Sensor()
{
  
}


Sensor::Sensor(int in_dataSize)
{
  Serial.begin(115200);
  //Serial.println("At the sensor level");
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
