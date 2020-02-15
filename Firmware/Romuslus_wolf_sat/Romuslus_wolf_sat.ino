#include "PIDController.h"

#include <SPI.h>
#include <SD.h>
#include "DataLog.h"


int i;
void setup() 
{
    while(!SD.begin(BUILTIN_SDCARD))
    {
      Serial.println("fixing SD");
    }
    Serial.begin(115200);// For system Diagnostics
}

void loop() 
{
    if(!SD.begin(BUILTIN_SDCARD));
    {
      Serial.println("SD failed in loop...");
      setup();
      
    }
    File dataFile = SD.open("Sensor1.txt", FILE_WRITE);
    i++;
    if(!dataFile)
    {
      while(!dataFile)
      {
        Serial.println("Trying to open the file...");
        dataFile = SD.open("Sensor1.txt");
      }
    }
    else
    {
      Serial.println("Writing Data... " + (String)i);
      dataFile.println("the count is " + (String)i);
      dataFile.close(); 
    }
}
