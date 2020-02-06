
class PIDControlSystem{
/*
 * this is a PID class that can be used to create stable control systems.
 * once tuned it can be used to controled flight systems, heaters, or anything
 * that needs a responsive control setup.
*/


  public:
  
    PIDControlSystem();
    /*
      * create an empty cotroller system.
      */

   
    PIDControlSystem(int readPin, int outputPin, double Proportional, double Integral, double D);
    /*
      * create a controller system with it fully initalzied and setup the controller to be ready for use.
      * readPin is the analogPin that will 
      */

    void setProportional(double Proportional);
    /*
      * set the proportional multiplier of the PID control system. This responds to the proportional error of the 
      * current system. Error is calculated by current-target.
      */
     
    void setIntegral(double Integral);
    /*
      * set Integral multiplier. over time, adds the proportional over time to the output. 
      */

      void setDerivative(double Derivative);
      /*
        * set Derivative multiplier. This is to respond to the sudden change and counter it with 
        * rapid output change.
        */



   int run();
   /*
      *The Run function will run a single cycle of the PID and return the output from the  
      */

   private:
   int P,I,D;
   /*
      * These are the values for the PID control system
      */

   long lastRun;
   /*
      * The last run of the PID control system
      */
      
};
