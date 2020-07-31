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
#include "Interface.h"

Interface face;

bool DEBUG = false;
double testSet[] = {1.0, 1.137, 3.14159};
double* vocSensorSet;
double* ozoneSensorSet;
double* partiSet;
double* airPressSet;
double* tempSet;
double* lsSet;

DataLog logger;
TimeStamper tStamp = TimeStamper(DEBUG);
VOCSensor vocSensor = VOCSensor(DEBUG);
ParticulateSensor partiSensor = ParticulateSensor(DEBUG);
OzoneSensor o3SensorOne;
AirPressure airPressSensor;
InnerTemp innerTemp;
LifeSupport ls;

void setup() 
{
  Serial.begin(115200);// For system Diagnostics
  Serial.println("Romulus / WolfSat II\nA project by Vivia Van De Mark, DJ Richardson, Tyler Dow, and James Craft\nIf you are not debugging(" + String(DEBUG) + ") then this will be the only text on Serial.");
  Wire.begin(); 
  if(DEBUG)
    Serial.println("Setting up Romulus");
  logger = DataLog(5, DEBUG);
  tStamp = TimeStamper(DEBUG); // May be unnecessary here since it is done in the main space.
  ls.begin(innerTemp,HEATER_PIN,0,25,1,0.05,TARGET_TEMPERATURE);
  while(face.CheckButton())
  {
    face.SetReady(true);
    delay(60);
    face.SetReady(false);
    delay(60);
  }
  if (DEBUG)
    Serial.println("Starting Mission");
}

void loop() 
{
  face.SetError(checkErrors());

  //internalTMP102.begin();
  digitalWrite(LED_BUILTIN, HIGH);
  face.SetState(0);
  if (DEBUG)
    Serial.print("VOC : ");
  vocFunk();
  
  face.SetState(1);
  if (DEBUG)
    Serial.print("SPS : ");
  partiFunk();

  face.SetState(3);
  if (DEBUG)
    Serial.print("PRS : ");
  airFunk();

  face.SetState(2);
  if (DEBUG)
    Serial.print("TMP : ");
  tempFunk();

  face.SetState(4);
  ls.run();
  if (DEBUG)
    Serial.print("LIF : ");
  lifFunk();

  face.SetState(-1);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
  //Serial.println(analogRead(A14));
}



void lifFunk()
{
  ls.FillData();
  lsSet = ls.GetData();
  logger.WriteSet("LIFData.txt", lsSet, ls.GetSize(), tStamp);
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

bool checkErrors()
{
  bool toRet = false;
  if (ls.InternalTempWarning() || ls.InternalTempCrtical() || ls.LowBatteryWarning() || ls.HeaterMalfunction() || logger.GetFlag())
    toRet = true;
   else
    toRet = false;
   return  toRet;
}

