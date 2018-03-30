#include "Player.h"

Player::Player(String _name, int _startCol) {
  score = 0;
  currentbreak = 0;
  pname = _name;
  startCol = _startCol;
  framesWon = 0;

}
Player::Player(int _startCol) {
  Player("player 1", _startCol);

}
Player::Player() {
  Player("player 1", 0);
}
Player::Player(String _name) {
  Player(_name, 0);
}

void Player::addScore(int _score) {
  score = score + _score;
  //    Serial.begin(9600);
  //    Serial.println("--->"+score);
}
int Player::getScore() {
  return (score);
}

String Player::getName() {
  return (pname);
};
void Player::setScore(int _score) {
  score = _score;
};

void Player::frameWon() {
  framesWon++;
};

int Player::getFrames() {
  return framesWon;
};
