
#ifndef SHIFTREG_H
#define SHIFTREG_H

class PIDController{
/*
 * this is a PID class that can be used to create stable control systems.
 * once tuned it can be used to controled flight systems, heaters, or anything
 * that needs a responsive control setup.
*/


  public:
  
    PIDController();
    /*
      * create an empty cotroller system.
      */

   
    PIDController(double Proportional, double Integral, double Deveritive,double IntLimit = 5, bool in_debug = false);
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
    void setIntergralLimit(int limit);



   double run(double current, double target);
   /*
      *The Run function will run a single cycle of the PID and return the output from the  
      */
   double getLastRun();
   /*
    * return what output of last run was
    */

   private:
   int P,I,D, intergralLimit, lastP, intergral;
   /*
      * These are the values for the PID control system
      */
  
    
    double lastOutput  = 0;
    /*
     * The last output of the PID loop
     */
   long lastRun;
   /*
      * The last run of the PID control system
      */

    bool debug;

      
};

#endif
