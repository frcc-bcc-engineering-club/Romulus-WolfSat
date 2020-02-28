#include "PIDController.h"

#include <SPI.h>
#include <SD.h>
#include "DataLog.h"
#include "TimeStamper.h"

bool DEBUG = false;
double testSet[] = {1.0, 1.137, 3.14159};

DataLog logger;
TimeStamper tStamp;


int i;
void setup() 
{
  Serial.begin(115200);// For system Diagnostics

  pinMode(LED_BUILTIN, OUTPUT);
//    while(!SD.begin(BUILTIN_SDCARD))
//    {
//      Serial.println("fixing SD");
//    } Spun out into DataLog.InitializeSD()
  DEBUG = true;
  logger = DataLog(5, DEBUG);
  tStamp = TimeStamper();
}

void loop() 
{
  digitalWrite(LED_BUILTIN, HIGH);
//  Serial.println("looping...");
  logger.WriteSet("TestData.txt", testSet, 3, tStamp);
  digitalWrite(LED_BUILTIN, LOW);
  delay(100);
}
