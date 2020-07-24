#include "PIDController.h"
#include "arduino.h"



PIDController::PIDController(){

P=10;//setting poroptional
I=0.1;//setting intergral
D=1;//setting derivitive

}

PIDController::PIDController(double Proportional, double Integral, double Deveritive,double IntLimit = 5){
P=Proportional;
I=Integral;
D=Deveritive;
intergralLimit=IntLimit;
}


void PIDController::setProportional(double Proportional){
  P=Proportional;
}

void PIDController::setIntegral(double Integral){
  I = Integral;
}

void PIDController::setDerivative(double Derivative){
D=Derivative;
  
}
void PIDController::setIntergralLimit(int limit){
  intergralLimit = limit;
}




double PIDController::run(double current, double target){

  
  double porpational = target - current;
  
  double derivative;

  if(abs(porpational)>intergralLimit){
    intergral=0;
  }
  else{
    intergral+=porpational*millis()/1000;
  }

    intergral=constrain(intergral,-25,25);

  derivative = (porpational-lastP)*(lastRun-millis())/1000.0;

  lastP=porpational;
  
  lastRun=millis();

  Serial.println("PID:: P: "+String(porpational)+" :I "+String(intergral*I)+" D: "+ String(derivative*D) +" OUT:" +String((porpational*P + intergral*I + derivative*D)));
  lastRun = (porpational*P + intergral*I + derivative*D);
  
  return lastRun;
  
}


double PIDController::getLastRun(){
    return lastRun;
   }
