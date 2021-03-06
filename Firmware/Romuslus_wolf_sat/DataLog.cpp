#include "DataLog.h"


DataLog::DataLog()
{
  errorLim = -1;
  errorFlag = false;
}


DataLog::DataLog(int in_errorLim, bool in_debugging)
{
  errorLim = in_errorLim;
  errorFlag = false;
  debugging = in_debugging;
  InitializeSD();
}


void DataLog::WriteSet(char in_fileName[], double in_set[], int in_setLim, TimeStamper in_tStamp)
{
  if(!SD.begin(BUILTIN_SDCARD))
  {
    if(debugging)
      Serial.println("SD.begin returned false");
    InitializeSD();
  }
  File toWriteTo = OpenFile(in_fileName);
  if(!toWriteTo)
  {
    if(debugging)
      Serial.println("File opening failed. Data lost...");
  }
  else
  {
    WriteDoubleSet(in_set, toWriteTo, in_setLim, in_tStamp);
//    if(debugging)
//      Serial.println("Data written...");
    
  }
}


void DataLog::WriteDoubleSet(double in_set[], File in_file, int in_setLim, TimeStamper in_tStamp)
{
  String toWrite = DoubleSetToString(in_set, in_setLim, in_tStamp);
  if(debugging)
    Serial.println("Writing data: " + toWrite);
  if(in_file)
  {
    in_file.println(toWrite);
    in_file.close();
  }
  else if(debugging)
    Serial.println("WriteDoubleSet has failed...");
}


String DataLog::DoubleSetToString(double in_set[], int in_setLim, TimeStamper in_tStamp)
{
  int pos = 0;
  String toRet = in_tStamp.Get_Stamp() + ", ";
  while(pos < in_setLim)
  {
    toRet += (String) in_set[pos];
    toRet += ", ";
    pos++;
  }
  return toRet;
}

void DataLog::InitializeSD()
{
  int count = 0;
  while((!SD.begin(BUILTIN_SDCARD) && (count < errorLim)))
  {
    count++;
  }
}


File DataLog::OpenFile(char in_fileName[])
{
  File toReturn = SD.open(in_fileName, FILE_WRITE);
  if(!toReturn)
  {
    int count = 0;
    while((!toReturn) && (count < errorLim))
    {
      errorFlag = true;
      if(debugging)
      {
        Serial.print("SD.open(...) failed to return it's file target : ");
        Serial.println(in_fileName);
      }
      count++;
      toReturn = SD.open(in_fileName);
    }
    if(!toReturn)
      return;
  }
  return toReturn;
}

bool DataLog::GetFlag()
{
  return errorFlag;
}

