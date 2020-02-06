/*
 *  This is the Objects that will make sure things are happy and respond to situations to maintain
 *operation of the spacecraft. Functions including battery management and internal environmental systems and
 *recording critical information to a log system.
*/



/*
class LifeSupport{

/*
 * this class will hold all objects for life support module and initalize them.


  
};
 */



class EnvirmentalControl{
/*
 * this will control the tempature of one compartment in the spacecraft using a PID loop control system
 * this ensures that all the instruments are running at the correct operating tempature.
 */


  public:
  
    EnvirmentalControl();
    /*
      * create an empty Enviromental cotroller system.
      */

   
    EnvirmentalControl(int readPin, int outputPin, double P, double I, double D);
    /*
      * create a enviroment controller system with it fully initalzied and setup the controller to be ready for use.
      * readPin is the analogPin that will 
      */


   int run();
   /*
      *The Run function will run a single cycle of the PID and return the output from the  
      */

   private:
   

    
    

    
  
};
