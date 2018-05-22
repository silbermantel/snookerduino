#ifndef SlimFont_h
#define SlimFont_h

#include "Arduino.h"
#include "LedControl.h"
#define DIGIT_WIDTH 4


class SlimFont
{
  public:
    SlimFont( int );
    SlimFont( );
    void draw(const LedControl& , int , boolean );
    void draw(const LedControl& , int , int , boolean );
    void draw(const LedControl& , char , boolean );
    void draw(const LedControl& , char , int , boolean );
    void draw(const LedControl& , byte* , int  );
    void draw(const LedControl& , byte* );


    void drawEOF(const LedControl& );

  private:
    int startcol;
    boolean wobble;

};

#endif

