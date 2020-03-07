#include "PIDController.h"

#include "DataLog.h"
#include "TimeStamper.h"
#include "VOCSensor.h"
#include "ParticulateSensor.h"
#include "OzoneSensor.h"

bool DEBUG = false;
double testSet[] = {1.0, 1.137, 3.14159};
double* vocSensorSet;
double* ozoneOneSensorSet;
double* ozoneTwoSensorSet;
double* partiSet;

DataLog logger;
TimeStamper tStamp;
VOCSensor vocSensor;
ParticulateSensor partiSensor;
OzoneSensor o3SensorOne;

void setup() 
{
  Serial.begin(115200);// For system Diagnostics
  Serial.println("Setting up Romulus");
  pinMode(LED_BUILTIN, OUTPUT);
  DEBUG = true;
  logger = DataLog(5, DEBUG);
  tStamp = TimeStamper();
}

void loop() 
{
  digitalWrite(LED_BUILTIN, HIGH);
  vocFunk();
  partiFunk();
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
  ozoneOneSensorSet = o3SensorOne.GetData();
  logger.WriteSet("O3OneData.txt", ozoneOneSensorSet, o3SensorOne.GetSize(), tStamp);
}

