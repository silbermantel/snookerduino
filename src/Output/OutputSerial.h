#ifndef OutputSerial_h
#define OutputSerial_h

#include "OutputDevice.h"

class OutputSerial : public OutputDevice 
{
  public:
    OutputSerial();
    virtual String showScore(int *);
    virtual String showBreak(int *);
    virtual String showFrames(int *);
    void printBoard();
    void printBoard(String left, String right);
 
  private:
    String OutputSerial::showDefault(int score[]) ;
 /* 	byte leftscore=0;
  	byte rightscore=0;
  	byte leftframes=0;
  	byte rightframes=0;
  	byte leftbreak=0;
  	byte rightbreak=0;*/
 	const byte spacing=18;
  
};

#endif