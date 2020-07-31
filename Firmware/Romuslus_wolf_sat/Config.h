#ifndef CONFIG_H
#define CONFIG_H

/*
 * This is where you can set values for the system functions
 * Added in by Tyler Dow
 */



 /*
  * *********************System Life Support settings******************
  */
        /*
         * ******HEATER*******
         */


  #define HEATER_PIN 2
  /*
   * The heat signal pin
   */

      
  #define TARGET_TEMPERATURE 35
  /*
   * what the the target internal temperature in celsius
   */

  #define HEATER_MALFUNCTION_TIME 900 
        /*
         * in seconds, how long we wait before we throw a system error flag up
         * to warn that the heater may be malfunctioning or not functioning.
         */
  #define HEATER_MALFUNCTION_RANGE 3
        /*
         * In celsius, when is the system in a safe range to not set the flag to heatMalfunction.
         */
  
  #define TEMPERATURE_HIGH 40
        /*
         * when is it defined the Tempature is too High in celsius
         */
  #define TEMPERATURE_CRICTICAL 60
  /*
   * When does the system set the flag for overheating in celsius
   */
         
     
      /*
       * *******Battery******
       */

 #define IGNORE_BATTERY_VOLTAGE true

  #define BATTERY_VOLTAGE_PIN A14
  /*
   * pin at which we messure the voltage from.
   */

  #define BATTERY_VOLTAGE_MULTIPLIER 3.25
  /*
   * This is the multiplier we use when detecting the voltage on the analog pin.
   */
  
  #define LOW_BATTERY_VOLTAGE 6.4 
       /*
        *When does the system say the battery is low in volts.
        *will disable heaters to preserve the abilty to record data.
        */
#endif
