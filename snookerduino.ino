#include <IRremote.h>
#include <IRremoteInt.h>
#include "LedControl.h"
#include "SlimFont.h"
#include "Player.h"
#include "snooker.h"
#include <Arduino.h>



/**************************************

     define your components

 **************************************/
#include "src/Input/InputSimulator.h"
InputSimulator controller = InputSimulator(85);
#include "src/Output/OutputSerial.h"
//OutputSerial scoreDisplay = OutputSerial("Walter Lyndrum","Joe Davis");
OutputSerial scoreDisplay = OutputSerial();
OutputSerial frameDisplay = OutputSerial();
OutputSerial breakDisplay = OutputSerial();

/**
*
*
*
*
*
*
*
*
*
**/

MatchSnooker currentMatch = MatchSnooker();

/* we always wait a bit between updates of the display */
unsigned long delaytime = 1000;


byte currentInput = 0;
void setup() {
  Serial.begin(9600);


}

void loop() {
  currentInput = controller.getInput();
  if (currentInput > 0) {

    currentMatch.process(currentInput);
    int score[]={-1,-1};
    currentMatch.getScore( score[0], score[1]);
    scoreDisplay.showScore(score);
  }

}

