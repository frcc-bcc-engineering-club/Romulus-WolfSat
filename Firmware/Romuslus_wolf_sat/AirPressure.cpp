#include "AirPressure.h"
const double BASEALTITUDE = 1586.18; // 1518.21 Tinkermill. 1641.35 for Limon. 1586.18 for Deer Trail

void AirPressure::FillData()
{
  dataSet[0] = ms5803.getPressure(ADC_4096);
  dataSet[1] = Relative(dataSet[0]);
  dataSet[2] = altimeter + BASEALTITUDE;
  dataSet[3] = ms5803.getTemperature(CELSIUS, ADC_4096);
  dataSet[4] = ms5803.getTemperature(FAHRENHEIT, ADC_4096);
  altimeter = Altitude(dataSet[0], baseline);
}

double AirPressure::Altitude(double pressure, double base)
{
  return (44330.0 * (1 - pow(pressure / base, 1 / 5.255)));
}

double AirPressure::Relative(double absPressure)
{
  return(absPressure/pow(1-(BASEALTITUDE/44330.0),5.255));
}

