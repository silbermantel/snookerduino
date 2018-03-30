#include "LedControl.h"
#include "SlimFont.h"
#include "Player.h"
#include "Match.h"
#include <Arduino.h>
#include <IRremote.h>
#include "RemoteControl.h"
#include "tm1638.h"

/*
  pin 2 is connected to DataIn
  pin 3 is connected to CLK
  pin 4 is connected to CS
*/

#define SIMULATION true
#define MATRIX_DIN 8
#define MATRIX_CS 6
#define MATRIX_CLK 7
#define MATRIX_NO_SEGMENTS 4
#define LED_MATRIX true

LedControl matrix1 = LedControl(MATRIX_DIN, MATRIX_CLK, MATRIX_CS, MATRIX_NO_SEGMENTS);


#define RECV_PIN 5
IRrecv irrecv(RECV_PIN);
decode_results results;
RemoteControl currentRemote = RemoteControl();

/*
  pin 2 is connected to stb
  pin 3 is connected to clk
  pin 4 is connected to dc
*/
#define LNK_STB 2
#define LNK_CLK 3
#define LNK_DC 4
#define LED_N_KEY true

TM1638 lednkey( LNK_STB, LNK_CLK, LNK_DC);

Match currentMatch = Match();

/* we always wait a bit between updates of the display */
unsigned long delaytime = 1000;

/*the Setup is shamelessly stolen from the ledcontrol tutorials*/

void setup() {
  Serial.begin(9600);
  if (LED_MATRIX) {

    int devices = matrix1.getDeviceCount();
    //we have to init all devices in a loop
    for (int address = 0; address < devices; address++) {
      /*The MAX72XX is in power-saving mode on startup*/
      matrix1.shutdown(address, false);
      /* Set the brightness to a medium values */
      matrix1.setIntensity(address, 0);
      /* and clear the display */
      matrix1.clearDisplay(address);
    }
    SlimFont scoreMatrix;
    scoreMatrix = SlimFont();
    scoreMatrix.draw(matrix1, 'i', 1, true);
    scoreMatrix.draw(matrix1, 'd', 5, true);
    scoreMatrix.draw(matrix1, '?', 10, true);
  }
  irrecv.enableIRIn();

}

void loop() {

  if (irrecv.decode(&results)) {
    Serial.print("IRRemote signal: ");
    Serial.println(results.value);
      

    if (currentRemote.getID() > 0 )
    {
      processInput(currentRemote.getCommand(results.value));

      if (LED_MATRIX)
      {
        if (LED_N_KEY)
        {
          Serial.println(currentMatch.show(matrix1, lednkey));
        } else
        {
          Serial.println(currentMatch.show(matrix1));
        }
      } else
      {
        if (LED_N_KEY)
        {
          Serial.println(currentMatch.show(lednkey));
        }
        else
        {
          Serial.println("no display device");
        }
      }

    }   else
      Serial.println(currentRemote.identify(results.value));

    irrecv.resume(); // Receive the next value

  }
  delay(100);
}


void processInput(int matchCode) {
  Serial.print("command ");
  Serial.println(matchCode);
  if (matchCode <= 9 && matchCode > 0) {
    currentMatch.addScore(matchCode);
  } //matchCode is a number
  else {
    switch (matchCode)
    {
      case 90:  currentMatch.switchPlayer();
        break;
      case 91:  currentMatch.addScore(1);
        break;
      case 92:  currentMatch.addScore(-1);
        break;
      case 95:  currentMatch.addScore(5);
        break;
      case 96:  currentMatch.addScore(-5);
        break;
      case 99:  currentMatch.endOfFrame(matrix1);
        break;
    }
  }//matchCode is not a number


}




void simulatedMatch() {

  Serial.print("starting match");
  Serial.println(currentMatch.show(matrix1));

  for (int i = 0; i <= random(2, 5); i++)
  { currentMatch.addScore(1);
    Serial.print("poted a red ball : ");
    Serial.println(currentMatch.show(matrix1));
    delay(delaytime);
    currentMatch.addScore(random(2, 7));
    Serial.print("poted a random colour : ");
    Serial.println(currentMatch.show(matrix1));
    delay(delaytime);
  }

  if (random(0, 10) > 8)
  { currentMatch.addScore(4);
    Serial.print("where is the cueball going : ");
  }
  currentMatch.switchPlayer();
  Serial.println(currentMatch.show(matrix1));
  delay(delaytime);
}



