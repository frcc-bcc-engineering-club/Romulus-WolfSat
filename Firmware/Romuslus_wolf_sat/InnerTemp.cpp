#include "InnerTemp.h"


void InnerTemp::FillData(){

  dataSet[0] = tmp.readTempC();
  

  
}

InnerTemp::InnerTemp(){
  tmp.begin();
  
  
  
}
