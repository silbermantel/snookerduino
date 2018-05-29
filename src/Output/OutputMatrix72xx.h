#ifndef OutputMatrix72xx_h
#define OutputMatrix72xx_h

#include "OutputDevice.h"

class OutputMatrix72xx : public OutputDevice 
{
  public:
    OutputMatrix72xx();
    virtual String showScore(int *);
    virtual String showBreak(int *);
    virtual String showFrames(int *);

  private:
    String OutputSerial::showDefault(int score[]) 
  	byte rows=1;
  	byte columns=4

};

#endif