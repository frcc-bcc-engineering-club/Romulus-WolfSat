#include <TimeLib.h>
#include <Arduino.h>
#ifndef TIMESTAMPER_H
#define TIMESTAMPER_H


class TimeStamper
{
  public:
  TimeStamper();
  String Get_Stamp();

  private:
  static time_t getTeensy3Time();
  unsigned long processSyncMessage();
  String stringify();
  
};

#endif
