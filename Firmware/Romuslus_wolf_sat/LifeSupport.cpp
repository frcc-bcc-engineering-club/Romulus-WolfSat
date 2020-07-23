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
      this-> MyPID = PIDController(P,I,D,3);
      this-> HeaterPin = heaterPin;
      myHeatSensor = &sensor;
      targetCelius = target;
      HeaterEnabled = true;
      
      
    }


    void LifeSupport::run(){
      myHeatSensor->FillData(); //update sensor data
      double currentTemp =  myHeatSensor->GetData()[0];// get data
      double RawPIDValue = MyPID.run(currentTemp,targetCelius); // read current temp and a
      double HeaterOutput = constrain(RawPIDValue,0,255);// contrain the value so we don't overflow the value.

      //check if heater is enabled and we are not above 
      if(HeaterEnabled && currentTemp<TEMPERATURE_HIGH){analogWrite(this-> HeaterPin,HeaterOutput);}
      else{analogWrite(this-> HeaterPin,0);}
      

       //check if our tempature is going critcally high.
      if(currentTemp>TEMPERATURE_CRICTICAL)
      {
        myInternalTempCrtical=true;
        HeaterEnabled=false;
      }


      if(getBatteryVoltage()<LOW_BATTERY_VOLTAGE&&!IGNORE_BATTERY_VOLTAGE)
        {
          HeaterEnabled=false;
          myLowBatteryWarning=true;
        }
      
    }


    double LifeSupport::getBatteryVoltage()
    {
      double voltageReading = analogRead(BATTERY_VOLTAGE_PIN)/1023.0;// get the decimal percent value of voltage
      voltageReading*= 3.3;//multiply by 3.3v as we are running on a 3.3v system
      voltageReading*=BATTERY_VOLTAGE_MULTIPLIER;// multiply by multipler to compensate for voltage divider.
      
      return voltageReading;

    }
    
    
