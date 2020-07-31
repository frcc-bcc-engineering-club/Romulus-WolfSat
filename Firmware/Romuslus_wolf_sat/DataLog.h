#ifndef DATALOG_H
#define DATALOG_H
#include "arduino.h"
#include "TimeStamper.h"
#include "Config.h"
#include <SPI.h>
#include <SD.h>

class DataLog
{
  public:
  DataLog();
  DataLog(int in_errorLim, bool in_debugging);
  void WriteSet(char in_fileName[], double in_set[], int in_setLim, TimeStamper in_tStamp);
  bool GetFlag();
  
  private:
  void WriteDoubleSet(double in_set[], File in_file, int in_setLim, TimeStamper in_tStamp);
  String DoubleSetToString(double in_set[], int in_setLim, TimeStamper in_tStamp);
  bool debugging;
  int errorLim;
  void InitializeSD();
  File OpenFile(char in_fileName[]);
  bool errorFlag;
};

#endif


