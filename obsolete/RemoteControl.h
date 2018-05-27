#ifndef RemoteControl_h
#define RemoteControl_h

#include "Arduino.h"

class RemoteControl
{
  public:
    String identify(int);
    int getCommand(int);
    int getID();
  private:
    int ID = -1;
    int decode1(int);
    int decode2(int);
    int decode1787(int);
    int decode4032(int);

};

#endif
