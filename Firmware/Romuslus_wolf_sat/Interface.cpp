#include "Interface.h"
#include <Arduino.h>

Interface::Interface()
{
  pinMode(LED_ERROR, OUTPUT);
  pinMode(LED_READY, OUTPUT);
  pinMode(LED_MULTIR, OUTPUT);
  pinMode(LED_MULTIG, OUTPUT);
  pinMode(LED_MULTIB, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
}

bool Interface::CheckButton()
{
  if (digitalRead(BUTTON) == HIGH) 
    return true;
  else 
    return false;
}

void Interface::SetState(int ins)
{
  AllOff();
  switch(ins)
  {
    case 0:
      digitalWrite(LED_MULTIB, HIGH);
      break;
     case 1:
      digitalWrite(LED_MULTIG, HIGH);
      break;
     case 2:
      digitalWrite(LED_MULTIR, HIGH);
      break;
     case 3:
      digitalWrite(LED_MULTIB, HIGH);
      digitalWrite(LED_MULTIR, HIGH);
      break;
     case 4:
      digitalWrite(LED_MULTIR, HIGH);
      digitalWrite(LED_MULTIG, HIGH);
      digitalWrite(LED_MULTIB, HIGH);
      break;
     default:
      break;
  }
}

void Interface::AllOff()
{
  digitalWrite(LED_MULTIR, LOW);
  digitalWrite(LED_MULTIG, LOW);
  digitalWrite(LED_MULTIB, LOW);
}

void Interface::SetError(bool ins)
{
  if (ins)
    digitalWrite(LED_ERROR, HIGH);
   else
    digitalWrite(LED_ERROR, LOW);
}

void Interface::SetReady(bool ins)
{
  if (ins)
    digitalWrite(LED_READY, HIGH);
   else
    digitalWrite(LED_READY, LOW);
}

