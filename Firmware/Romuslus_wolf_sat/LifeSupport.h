/*
 * written by Tyler Dow
 */

#ifndef LIFESUPPORT_H
#define LIFESUPPORT_H
#include <SparkFunTMP102.h>
#include "PIDController.h"
#include "Sensor.h"

class LifeSupport : public Sensor{
  public:

  void FillData() override;


  LifeSupport();

  
  void run();
    /*
     * run will be put in the main loop to control the lifeSupport systems.
     * this function is not time senstitive and will adjust the power
     * to the heater and check the battery voltage.
     * will turn off the heater if the battery voltage goes below a certain point.
     */
   
  void begin
  (Sensor &sensor,
    int heaterPin,//The pin the heater will send the PWM signal to
    int VBatPin, // the pin the voltage divider from the battery will be hooked up to
    double P = 10,// Porpotional value to the PID loop.
    double I = 0.1,//Intergral of the PID loop.
    double D=1,// Delta portion of the PID loop.
    double target = 10// target for PID loop.
    );
  /*
   * starts the lifeSupport system to monitor
   */

    double getBatteryVoltage();
     /*
      * return the voltage of the battery based on the voltage divider
      * on the circuit. 
      */

    bool InternalTempWarning();
    /*
     * will return true if the the internal Temperature is too high.
     */
    bool InternalTempCrtical();
    /*
     * will return true if the interal temperature it is dangerously to high
     */
    bool LowBatteryWarning();
    /*
     * will return true if the battery is low;
     */
    bool HeaterMalfunction();
    /*
     * will return true if the tempature is getting to low when we
     * have been running the heater for a miniumum ammount of time.
     */

     void setHeater(bool on);
     /*
      * disable or enable the heater on the craft, disable the heater 
      * can save power if we are low.
      */


  private:
    PIDController MyPID;
      /*
       * the PID controller object that will control the temperature.
       */
    double targetCelius;
    /*
     * this target temperature in Celius to try to maintain.
     */
     double HeaterPin;
     /*
      * Heater pin we will be using
      */
     long HeaterStartTime;
     /*
      * when was the heater last turned on. Used to check if the heater
      * is having a malfunction if tempature has not hit its target.
      */
      
      /*
       * FLAGS for life support.
       * Check returning functions for more information.
       */
       bool myInternalTempWarning, myInternalTempCrtical,
            myLowBatteryWarning, myHeaterMalfunction;

       bool HeaterEnabled= true;

       Sensor* myHeatSensor;

      
    
};

#endif
