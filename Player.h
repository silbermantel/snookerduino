#ifndef Player_h
#define Player_h

#include "Arduino.h"

class Player
{
  public:
    Player();
    Player(int);
    Player(String, int);
    Player(String);
    int getScore();
    String getName();
    void addScore(int);
    void setScore(int);
    void frameWon();
    int getFrames();
    int getBreak();

  private:
    int score;
    int currentbreak;
    String pname;
    int startCol; //to display on a matrix
    int framesWon;
    
};

#endif
