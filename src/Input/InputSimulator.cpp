#include "InputSimulator.h"

/*InputSimulator::InputSimulator() {
  bool redOn=true;
  byte actionarray=[255,255,255,255,255];
  byte actionpointer=0;
}
*/
InputSimulator::InputSimulator(byte p1){
  percentage=p1;
  lastaction=0;
  shotdelay=1000;

}


bool InputSimulator::pot() {
  if (random(0,99)<percentage)
    return true;
  else
    return false;
}

byte InputSimulator::generateAction(){
  byte rValue=0;
  if (pot()){
    if (lastaction==1){rValue=random(2,7);}
    else {rValue=1;}

  }
  else
    if (random(0,99)<=98)
        rValue=90;
        // foul... but no idea how to handle it yet
    else
        rValue=90;

  return rValue;
}

byte InputSimulator::getInput() {
  byte rValue= generateAction();

/*  Serial.print(lastaction);
  Serial.print(" : ");
  Serial.println(rValue);
*/

  lastaction=rValue;
  delay(shotdelay);
  return rValue;
}




/*
void simulatedMatch() {

  Serial.print("starting match");
  Serial.println(currentMatch.show(matrix1));

  for (int i = 0; i <= random(2, 5); i++)
  { 
    currentMatch.addScore(1);
    Serial.print("poted a red ball : ");
    Serial.println(currentMatch.show(matrix1));
    delay(delaytime);
    currentMatch.addScore(random(2, 7));
    Serial.print("poted a random colour : ");
    Serial.println(currentMatch.show(matrix1));
    delay(delaytime);
  }

  if (random(0, 10) > 8)
  { 
    currentMatch.addScore(4);
    Serial.print("where is the cueball going : ");
  }
  currentMatch.switchPlayer();
  Serial.println(currentMatch.show(matrix1));
  delay(delaytime);
}

*/