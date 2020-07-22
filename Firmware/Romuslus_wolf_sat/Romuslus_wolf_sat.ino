
#include <SD.h>
#include "LifeSupport.h"
#include "DataLog.h"
#include "TimeStamper.h"
#include "VOCSensor.h"
#include "ParticulateSensor.h"
#include "OzoneSensor.h"
#include "AirPressure.h"
#include "InnerTemp.h"
#include <SparkFunTMP102.h>
#include <Wire.h>
#include "Config.h"

bool DEBUG = false;
double testSet[] = {1.0, 1.137, 3.14159};
double* vocSensorSet;
double* ozoneSensorSet;
double* partiSet;
double* airPressSet;
double* tempSet;

//TMP102 internalTMP102(0x48);

DataLog logger;
TimeStamper tStamp;
VOCSensor vocSensor;
ParticulateSensor partiSensor;
OzoneSensor o3SensorOne;
AirPressure airPressSensor;
InnerTemp innerTemp;



//InnerTemp it;
LifeSupport ls;

void setup() 
{
  Serial.begin(115200);// For system Diagnostics
  Wire.begin(); 
  Serial.println("Setting up Romulus");
  pinMode(LED_BUILTIN, OUTPUT);
  DEBUG = true;
  logger = DataLog(5, DEBUG);
  tStamp = TimeStamper();
  ls.begin(innerTemp,HEATER_PIN,0,25,1,0.05,TARGET_TEMPERATURE);

//  testFunction();//DELETE LATER!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

  
}

void loop() 
{

  //internalTMP102.begin();
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.print("VOC : ");
  vocFunk();
  Serial.print("SPS : ");
  partiFunk();
  Serial.print("PRS : ");
  airFunk();
  Serial.print("TMP : ");
  
  tempFunk();
  ls.run();
  
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}





void vocFunk()
{
  vocSensor.FillData();
  vocSensorSet = vocSensor.GetData();
  logger.WriteSet("VOCData.txt", vocSensorSet, vocSensor.GetSize(), tStamp);
}

void partiFunk()
{
  partiSensor.FillData();
  partiSet = partiSensor.GetData();
  logger.WriteSet("SPSData.txt", partiSet, partiSensor.GetSize(), tStamp);
}

void ozFunkOne()
{
  o3SensorOne.FillData();
  ozoneSensorSet = o3SensorOne.GetData();
  logger.WriteSet("O3OneData.txt", ozoneSensorSet, o3SensorOne.GetSize(), tStamp);
}

void airFunk()
{
  airPressSensor.FillData();
  airPressSet = airPressSensor.GetData();
  logger.WriteSet("PrsData.txt", airPressSet, airPressSensor.GetSize(), tStamp);
}

void tempFunk()
{
  innerTemp.FillData();
  tempSet = innerTemp.GetData();
  logger.WriteSet("TMPData.txt", tempSet, innerTemp.GetSize(), tStamp);
}

