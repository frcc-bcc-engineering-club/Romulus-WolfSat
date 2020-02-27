#include "PIDController.h"

#include <SPI.h>
#include <SD.h>
#include "DataLog.h"

bool DEBUG = false;
double testSet[] = {1.0, 1.137, 3.14159};

DataLog logger;


int i;
void setup() 
{
//    while(!SD.begin(BUILTIN_SDCARD))
//    {
//      Serial.println("fixing SD");
//    } Spun out into DataLog.InitializeSD()
    DEBUG = true;
    logger = DataLog(5, DEBUG);
    Serial.begin(115200);// For system Diagnostics
}

void loop() 
{
  Serial.println("looping...");
  logger.WriteSet("TestData.txt", testSet, 3);
}
