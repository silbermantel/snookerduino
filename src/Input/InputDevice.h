#ifndef InputDevice_h
#define InputDevice_h
#include <Arduino.h>
class InputDevice
{
  public:
    String stub(int);
    virtual byte getInput();
  private:
    int foo = -1;
    void defineMatchcodes();

};

#endif