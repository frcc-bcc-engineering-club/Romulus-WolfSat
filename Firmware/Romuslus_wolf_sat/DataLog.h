#include "arduino.h"
#include <SPI.h>
#include <SD.h>

class DataLog
{
  public:
  DataLog();
  DataLog(int in_errorLim, bool in_debugging);
  void WriteSet(char in_fileName[], double in_set[], int in_setLim);
  private:
  void WriteDoubleSet(double in_set[], File in_file, int in_setLim);
  String DoubleSetToString(double in_set[], int in_setLim);
  bool debugging;
  int errorLim;
  void InitializeSD();
  File OpenFile(char in_fileName[]);
};




