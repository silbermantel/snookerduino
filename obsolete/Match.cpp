#include "Arduino.h"
#include "SlimFont.h"
#include "Match.h"
#include "Player.h"


Match::Match() {
  leftside = Player("leftside", 0);
  rightside = Player("rightside", 15);
  scoreMatrix = SlimFont();
  currentPlayer = &leftside;
};

void Match::switchPlayer() {
  if (currentPlayer)
    currentPlayer = false;
  else
    currentPlayer = true;

  currentbreak = 0;
  eofRequest = false;

};


void Match::addScore(int pot) {
  if (currentPlayer)
    leftside.addScore(pot);
  else
    rightside.addScore(pot);

  eofRequest = false;
  currentbreak += pot;
};

void Match::calcDigits(int tscore, int offset) {
  h = -1;
  t = -1;
  o = -1;
  if (tscore > 100)
  {
    h = tscore / 100;
    tscore -= 100;
    t = tscore / 10;
    o = tscore % 10;
  } else {
    if (tscore == 100)
    {
      h = 1;
      t = 0;
      o = 0;
    } else {
      if (tscore > 9)
      {
        t = tscore / 10;
        o = tscore % 10;
      }
      else
        o = tscore;
    }

  }



};


String Match::show(const LedControl& _matrix) {
  int devices = _matrix.getDeviceCount();
  for (int address = 0; address < devices; address++) {
    _matrix.clearDisplay(address);
  }

  boolean up = currentPlayer;

  int offset = 10;
  int tscore = leftside.getScore();
  // scoreMatrix.draw(_matrix, 0, 10, up);
  Serial.print("processing leftside score :");
  Serial.println(tscore);
  while (tscore > 0)
  {
    int digit = tscore % 10;
    tscore /= 10;
    scoreMatrix.draw(_matrix, digit, offset, up);
    offset -= 5;
  }

  /*
    calcDigits(leftside.getScore(), 0);
    scoreMatrix.draw(_matrix, h, 0, up);
    scoreMatrix.draw(_matrix, t, 5, up);
    scoreMatrix.draw(_matrix, o, 10, up);
  */

  up = !currentPlayer;

  offset = 28;
  tscore = rightside.getScore();
  //  scoreMatrix.draw(_matrix, 0, 28, up);
  Serial.print("processing rightside score :");
  Serial.println(tscore);
  while (tscore > 0)
  {
    int digit = tscore % 10;
    tscore /= 10;
    scoreMatrix.draw(_matrix, digit, offset, up);
    offset -= 5;
  }

  /*
    calcDigits(rightside.getScore(), 18);
    scoreMatrix.draw(_matrix, h, 18, up);
    scoreMatrix.draw(_matrix, t, 23, up);
    scoreMatrix.draw(_matrix, o, 28, up);
  */

  return (leftside.getName() + " " + leftside.getScore() + " - " + rightside.getScore() + " " + rightside.getName());
};


String Match::show(const LedControl& _matrix, const TM1638& _tm) {

  int devices = _matrix.getDeviceCount();
  for (int address = 0; address < devices; address++) {
    _matrix.clearDisplay(address);
  }

  boolean up = currentPlayer;

  int offset = 10;
  int tscore = leftside.getScore();
  //  scoreMatrix.draw(_matrix, 0, 10, up);
  Serial.print("processing leftside score :");
  Serial.println(tscore);
  if (tscore == 0)
    scoreMatrix.draw(_matrix, 0, offset, up);
  else
    while (tscore > 0)
    {
      int digit = tscore % 10;
      tscore /= 10;
      scoreMatrix.draw(_matrix, digit, offset, up);
      offset -= 5;
    }

  up = !currentPlayer;

  offset = 28;
  tscore = rightside.getScore();
  //  scoreMatrix.draw(_matrix, 0, 28, up);
  Serial.print("processing rightside score :");
  Serial.println(tscore);
  if (tscore == 0)
    scoreMatrix.draw(_matrix, 0, offset, up);
  else
    while (tscore > 0)
    {
      int digit = tscore % 10;
      tscore /= 10;
      scoreMatrix.draw(_matrix, digit, offset, up);
      offset -= 5;
    }

  if (currentPlayer)  //draw separator
  {
    _matrix.setLed(2, 4, 7, true);
    _matrix.setLed(2, 2, 7, true);
  }
  else
  {
    _matrix.setLed(1, 4, 1, true);
    _matrix.setLed(1, 2, 1, true);
  }

  _tm.reset();
  tscore = currentbreak;
  if (currentPlayer)
    offset = 3;
  else
    offset = 7;
  if (tscore == 0)
    _tm.showNumber( 0,  offset);
  else
    while (tscore > 0)
    {
      int digit = tscore % 10;
      tscore /= 10;

      _tm.showNumber( digit,  offset);
      offset -= 1;
    }

  _tm.resetLEDs();
  _tm.lightLEDs(leftside.getFrames());
  _tm.lightLEDs(4, rightside.getFrames());


  return (leftside.getName() + " " + leftside.getScore() + " - " + rightside.getScore() + " " + rightside.getName() + " break: " + currentbreak);
};

String Match::show(const TM1638& _tm) {
  boolean up = currentPlayer;

  int offset = 3;
  int tscore = leftside.getScore();
  while (tscore > 0)
  {
    int digit = tscore % 10;
    tscore /= 10;

    _tm.showNumber( digit,  offset);
    offset -= 1;
  }

  up = !currentPlayer;

  offset = 7;
  tscore = rightside.getScore();
  while (tscore > 0)
  {
    int digit = tscore % 10;
    tscore /= 10;

    _tm.showNumber( digit,  offset);
    offset -= 1;
  }



  return (leftside.getName() + " " + leftside.getScore() + " - " + rightside.getScore() + " " + rightside.getName() + " break: " + currentbreak);
};


void Match::endOfFrame(const LedControl& _matrix) {
  int devices = _matrix.getDeviceCount();
  for (int address = 0; address < devices; address++) {
    _matrix.clearDisplay(address);
  }
  Serial.println("EOF received");

  scoreMatrix.draw(_matrix, 'e', 0, true);
  scoreMatrix.draw(_matrix, 'o', 5, true);
  scoreMatrix.draw(_matrix, 'f', 10, true);
  delay(1000);
  if (eofRequest)
  {
    switchPlayer();
    if (leftside.getScore() > rightside.getScore())
      leftside.frameWon();
    else
      rightside.frameWon();

    leftside.setScore(0);
    rightside.setScore(0);
    currentbreak = 0;
    scoreMatrix.draw(_matrix, '!', 20, true);

    delay(500);


  }
  else
  {
    Serial.println("no prior requests");
    eofRequest = true;
    scoreMatrix.draw(_matrix, '?', 18, true);
    delay(1000);

  }

};


