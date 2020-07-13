#include "InnerTemp.h"


void InnerTemp::FillData(){

  dataSet[0] = tmp.readTempC();
  

  
}

InnerTemp::InnerTemp():Sensor(1){
  tmp.begin();
  tmp.setConversionRate(3);// sensor updates at 8 hz
  tmp.setExtendedMode(0);// system should not go over 128C  
  
}

void InnerTemp::setAlarm(double temp)
{

tmp.setHighTempC(temp);//trigger interupt from TMP102 so we can shutdown heaters.
tmp.setLowTempC(temp-10);//reset if we go below this temp
  
}
