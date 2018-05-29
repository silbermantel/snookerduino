#ifndef OutputTm1638_h
#define OutputTm1638_h

#include "OutputDevice.h"

class OutputTm1638 : public OutputDevice 
{
  public:
    OutputTm1638();
    virtual String showScore(int *);
    virtual String showBreak(int *);
    virtual String showFrames(int *);
    void printBoard();
    void printBoard(String left, String right);
};

#endif