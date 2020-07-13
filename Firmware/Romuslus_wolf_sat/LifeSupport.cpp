#include <SparkFunTMP102.h>

#include "LifeSupport.h"
#include "Config.h"
#include "PIDController.h"



void LifeSupport::begin(Sensor &sensor, //internal sensor
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
      myHeatSensor = &sensor;
      targetCelius = target;
      
      
    }


    void LifeSupport::run(){
      myHeatSensor->FillData(); //update sensor data
      double currentTemp =  myHeatSensor->GetData()[0];// get data
      double RawPIDValue = MyPID.run(currentTemp,targetCelius); // read current temp and a
      double HeaterOutput = constrain(RawPIDValue,0,255);// contrain the value so we don't overflow the value.
      analogWrite(this-> HeaterPin,HeaterOutput);
      
    }
