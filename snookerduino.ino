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

/*

  this is a demo Setup

*/

#include "src/Input/InputSimulator.h"
InputSimulator controller = InputSimulator(85);
#include "src/Output/OutputSerial.h"
//OutputSerial scoreDisplay = OutputSerial("Walter Lyndrum","Joe Davis");


OutputDevice *foo[3];

/**


**/

MatchSnooker currentMatch = MatchSnooker();

/* we always wait a bit between updates of the display */
unsigned long delaytime = 1000;


byte currentInput = 0;
void setup() {
  Serial.begin(9600);
  foo[0] = &OutputSerial();
  foo[1] = &OutputSerial();
  foo[2] = &OutputSerial();
}

void loop() {
  currentInput = controller.getInput();
  if (currentInput > 0) {

    currentMatch.process(currentInput);
    int val[] = { -1, -1};
    currentMatch.getScore( val[0], val[1]);
    foo[0]->showScore(val);
    currentMatch.getFrames( val[0], val[1]);
    foo[1]->showFrames(val);
    currentMatch.getBreak( val[0], val[1]);
    foo[2]->showBreak(val);
  }

}

