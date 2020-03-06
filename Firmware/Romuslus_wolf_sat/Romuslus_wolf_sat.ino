#include "PIDController.h"

#include <SPI.h>
#include <SD.h>
#include "DataLog.h"
#include "TimeStamper.h"
#include "VOCSensor.h"

bool DEBUG = false;
double testSet[] = {1.0, 1.137, 3.14159};
double* vocSensorSet;
double* ozoneOneSensorSet;
double* ozoneTwoSensorSet;

DataLog logger;
TimeStamper tStamp;
VOCSensor vocSensor;


int i;
void setup() 
{
  Serial.begin(115200);// For system Diagnostics

  pinMode(LED_BUILTIN, OUTPUT);
  DEBUG = true;
  logger = DataLog(5, DEBUG);
  tStamp = TimeStamper();
}

void loop() 
{
  digitalWrite(LED_BUILTIN, HIGH);
  vocFunk();
  digitalWrite(LED_BUILTIN, LOW);
  delay(100);
}

void vocFunk()
{
  vocSensor.FillData();
  vocSensorSet = vocSensor.GetData();
  logger.WriteSet("VOCData.txt", vocSensorSet, vocSensor.GetSize(), tStamp);
}

