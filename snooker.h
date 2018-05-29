#ifndef snooker_h
#define snooker_h
#include <Arduino.h>
#include "Player.h"

class MatchSnooker
{
  public:
    MatchSnooker();
    bool process(byte);
    void getScore(int & left, int & right);
    void getFrames(int & left, int & right);
    void getBreak(int & left, int & right);

  private:
    void addScore(int pot);
    void switchPlayer();
    Player leftside;
    Player rightside;
    boolean currentPlayer;
    int currentbreak = 0;
    boolean eofRequest = false;

};

#endif
