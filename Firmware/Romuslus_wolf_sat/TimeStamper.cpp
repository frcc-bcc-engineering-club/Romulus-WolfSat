#include"TimeStamper.h"

TimeStamper::TimeStamper(bool in_debug)
{
  debug = in_debug;
  setSyncProvider(getTeensy3Time);
  //  while(!Serial);
  //  delay(100);
  if ((timeStatus() != timeSet) && debug)
    Serial.println("RTC could not sync!");
  else if (debug)
    Serial.println("RTC has set the system time." + String(debug) + " " + String(in_debug));
}

String TimeStamper::Get_Stamp()
{
  if (Serial.available())
  {
    time_t activeTime = processSyncMessage();
    if (activeTime != 0)
    {
      Teensy3Clock.set(activeTime);
      setTime(activeTime);
    }
  }
  return stringify();

}

String TimeStamper::stringify()
{
  String h = (String)hour();
  String m = (String)minute();
  String s = (String)second();
  
  String toRet = h + ':' + m + ':' + s;
//  Serial.println("tStamp = " + toRet);
  return toRet;
}


static time_t TimeStamper::getTeensy3Time()
{
  return Teensy3Clock.get();
}

unsigned long TimeStamper::processSyncMessage()
{
  unsigned long pctime = 0L;
  const unsigned long DEFAULT_TIME = 1357041600; // Jan 1 2013

  if (Serial.find("T")) {
    pctime = Serial.parseInt();
//    return pctime;
    if ( pctime < DEFAULT_TIME) { // check the value is a valid time (greater than Jan 1 2013)
      pctime = 0L; // return 0 to indicate that the time is not valid
    }
  }
  return pctime;
}


