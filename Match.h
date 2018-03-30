#ifndef Match_h
#define Match_h

#include "Arduino.h"
#include "SlimFont.h"
#include "Player.h"
#include "tm1638.h"

class Match
{
  public:
    Match();

    void switchPlayer();
    void addScore(int);
    String show(const TM1638& _tm);
    String show(const LedControl&);
    String show(const LedControl&,const TM1638&);
    void endOfFrame(const LedControl&);
    
  private:
    void calcDigits(int tscore,int offset);

    Player leftside;
    Player rightside;
    boolean currentPlayer;
    SlimFont scoreMatrix;
    int h = -1;
    int t = -1;
    int o = -1;
    int currentbreak=0;
    boolean eofRequest=false;
};

#endif

