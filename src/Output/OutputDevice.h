#ifndef OutputDevice_h
#define OutputDevice_h
#include <Arduino.h>
class OutputDevice
{
  public:
    String stub(int);
    virtual String showScore(int *);
    virtual String showBreak(int *);
    virtual String showFrames(int *);
  private:
    int foo = -1;

};

#endif