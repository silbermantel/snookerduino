#include "snooker.h"

MatchSnooker::MatchSnooker() {
  leftside = Player("leftside", 0);
  rightside = Player("rightside", 15);
  currentPlayer = true;
}

void MatchSnooker::switchPlayer() {
  if (currentPlayer)
    currentPlayer = false;
  else
    currentPlayer = true;

  currentbreak = 0;
  eofRequest = false;

};

void MatchSnooker::addScore(int pot) {
  if (currentPlayer)
    leftside.addScore(pot);
  else
    rightside.addScore(pot);

  eofRequest = false;
  currentbreak += pot;
};

bool MatchSnooker::process(byte matchCode) {
  bool rValue = false;
  if (matchCode <= 9 && matchCode > 0) {
    addScore(matchCode);
  } //matchCode is a number
  else {
    switch (matchCode)
    {
      case 90:
        switchPlayer();
        break;
      case 92:
        Serial.println("implement -1");
        break;
      case 96:
        Serial.println("implement -5");
        break;
      case 99:
        Serial.println("implement EOF");
        break;
    }
  }
  return rValue;
}


void MatchSnooker::getScore(int & left, int & right) {

  left = leftside.getScore();
  right = rightside.getScore();

}
void MatchSnooker::getFrames(int & left, int & right) {

  left = leftside.getFrames();
  right = rightside.getFrames();

}
void MatchSnooker::getBreak(int & left, int & right) {

  left = leftside.getBreak();
  right = rightside.getBreak();

}




