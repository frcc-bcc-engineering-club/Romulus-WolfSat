#include "PIDController.h"
#include "arduino.h"



PIDControlSystem::PIDControlSystem(){

P=10;//setting poroptional
I=0.1;//setting intergral
D=1;//setting derivitive

}

PIDControlSystem::PIDControlSystem(double Proportional, double Integral, double Deveritive){
P=Proportional;
I=Integral;
D=Deveritive;
}


void PIDControlSystem::setProportional(double Proportional){
  P=Proportional;
}

void PIDControlSystem::setIntegral(double Integral){
  I = Integral;
}

void PIDControlSystem::setDerivative(double Derivative){
D=Derivative;
  
}
void PIDControlSystem::setIntergralLimit(int limit){
  intergralLimit = limit;
}




double PIDControlSystem::run(double current, double target){

  
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
