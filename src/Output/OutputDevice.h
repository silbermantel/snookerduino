#ifndef OutputDevice_h
#define OutputDevice_h
#include <Arduino.h>
class OutputDevice
{
  public:
    String stub(int);
    virtual String showScore(int *) = 0;
    virtual String showBreak(int *) = 0;
    virtual String showFrames(int *) = 0;
  private:
    virtual String showDefault(int *) = 0;

};

#endif