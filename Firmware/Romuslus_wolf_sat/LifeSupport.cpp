#include <SparkFunTMP102.h>

#include "LifeSupport.h"
#include "Config.h"
#include "PIDController.h"



void LifeSupport::begin(TMP102 &sensor, //internal sensor
  int heaterPin,//The pin the heater will send the PWM signal to
          int VBatPin, // the pin the voltage divider will be hooked up to
          double P = 10,// Porpotional value to the PID loop.
          double I = 0.1,//Intergral of the PID loop.
          double D=1,// Delta portion of the PID loop.
          double target = 10// target for PID loop.
          
          )
    {
      this-> MyPID = PIDController(P,I,D);
      this-> HeaterPin = heaterPin;

      
      
    }


    void LifeSupport::run(){

      double currentTemp =  myHeatSensor->readTempC();
      double RawPIDValue = MyPID.run(currentTemp,targetCelius); // read current temp and a
      double HeaterOutput = constrain(RawPIDValue,0,255);
      analogWrite(this-> HeaterPin,HeaterOutput);
      
    }
