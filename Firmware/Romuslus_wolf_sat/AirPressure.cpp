#include "AirPressure.h"

void AirPressure::FillData()
{
  dataSet[0] = ms5803.getPressure(ADC_4096);
  dataSet[1] = ms5803.getTemperature(CELSIUS, ADC_4096);
  dataSet[2] = ms5803.getTemperature(FAHRENHEIT, ADC_4096);
  altimeter = Altitude(dataSet[0], baseline);
}

double AirPressure::Altitude(double pressure, double base)
{
  return (44330.0 * (1 - pow(pressure / base, 1 / 5.255)));
}

