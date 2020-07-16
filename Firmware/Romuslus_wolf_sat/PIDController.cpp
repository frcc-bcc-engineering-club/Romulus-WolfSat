#include "PIDController.h"
#include "arduino.h"



PIDController::PIDController(){

P=10;//setting poroptional
I=0.1;//setting intergral
D=1;//setting derivitive

}

PIDController::PIDController(double Proportional, double Integral, double Deveritive){
P=Proportional;
I=Integral;
D=Deveritive;
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
  double intergral;
  double derivative;

  if(abs(porpational)>intergralLimit){
    intergral=0;
  }
  else{
    intergral+=porpational;
  }

  derivative = (porpational-lastP)*(lastRun-millis());

  lastP=porpational;
  
  lastRun=millis();

  return porpational*P + intergral*I + derivative*D;
  
}
