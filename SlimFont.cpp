#include "Arduino.h"
#include "SlimFont.h"
#include "LedControl.h"

SlimFont::SlimFont( int _startcol) {
  startcol = _startcol;
}

SlimFont::SlimFont() {
  startcol = 0;
}

void SlimFont::draw(const LedControl& lc, int number, int _startcol, boolean up ) {
  startcol = _startcol;
  draw(lc, number, up);
};

void SlimFont::draw(const LedControl& lc, int number, boolean up) {

  byte dotArray[4] = {B01111000, B00000000, B00000000, B00000000};
  if (up)
  {
    switch (number) {
      case 0:
        dotArray[3] = B01111100;
        dotArray[2] = B10000010;
        dotArray[1] = B10000010;
        dotArray[0] = B01111100;
        break;
      case 1:
        dotArray[3] = B11101110;
        dotArray[2] = B00000000;
        dotArray[1] = B00000000;
        dotArray[0] = B00000000;
        break;
      case 2:
        dotArray[3] = B01100000;
        dotArray[2] = B10010010;
        dotArray[1] = B10010010;
        dotArray[0] = B00001100;
        break;
      case 3:
        dotArray[3] = B01111100;
        dotArray[2] = B10010010;
        dotArray[1] = B10010010;
        dotArray[0] = B10000010;
        break;
      case 4:
        dotArray[3] = B00001000;
        dotArray[2] = B00111110;
        dotArray[1] = B00001000;
        dotArray[0] = B11110000;
        break;
      case 5:
        dotArray[3] = B00001100;
        dotArray[2] = B10010010;
        dotArray[1] = B10010010;
        dotArray[0] = B01100000;
        break;
      case 6:
        dotArray[3] = B00001100;
        dotArray[2] = B10010010;
        dotArray[1] = B10010010;
        dotArray[0] = B01101100;
        break;
      case 7:
        dotArray[3] = B11100000;
        dotArray[2] = B10110000;
        dotArray[1] = B10001100;
        dotArray[0] = B10000010;
        break;
      case 8:
        dotArray[3] = B01101100;
        dotArray[2] = B10010010;
        dotArray[1] = B10010010;
        dotArray[0] = B01101100;
        break;
      case 9:
        dotArray[3] = B01101100;
        dotArray[2] = B10010010;
        dotArray[1] = B10010010;
        dotArray[0] = B01100000;
        break;
      default:
        dotArray[3] = B00000000;
        dotArray[2] = B00000000;
        dotArray[1] = B00000000;
        dotArray[0] = B00000000;
        break;
    }
  }
  else
  {
    switch (number) {
      case 0:
        dotArray[3] = B00111110;
        dotArray[2] = B01000001;
        dotArray[1] = B01000001;
        dotArray[0] = B00111110;
        break;
      case 1:
        dotArray[3] = B01110111;
        dotArray[2] = B00000000;
        dotArray[1] = B00000000;
        dotArray[0] = B00000000;
        break;
      case 2:
        dotArray[3] = B00110000;
        dotArray[2] = B01001001;
        dotArray[1] = B01001001;
        dotArray[0] = B00000110;
        break;
      case 3:
        dotArray[3] = B00111110;
        dotArray[2] = B01001001;
        dotArray[1] = B01001001;
        dotArray[0] = B01000001;
        break;
      case 4:
        dotArray[3] = B00000100;
        dotArray[2] = B00011111;
        dotArray[1] = B00000100;
        dotArray[0] = B01111000;
        break;
      case 5:
        dotArray[3] = B00000110;
        dotArray[2] = B01001001;
        dotArray[1] = B01001001;
        dotArray[0] = B00110000;
        break;
      case 6:
        dotArray[3] = B00000110;
        dotArray[2] = B01001001;
        dotArray[1] = B01001001;
        dotArray[0] = B00110110;
        break;
      case 7:
        dotArray[3] = B01110000;
        dotArray[2] = B01001000;
        dotArray[1] = B01000100;
        dotArray[0] = B01000011;
        break;
      case 8:
        dotArray[3] = B00110110;
        dotArray[2] = B01001001;
        dotArray[1] = B01001001;
        dotArray[0] = B00110110;
        break;
      case 9:
        dotArray[3] = B00110110;
        dotArray[2] = B01001001;
        dotArray[1] = B01001001;
        dotArray[0] = B00110000;
        break;
      default:
        dotArray[3] = B00000000;
        dotArray[2] = B00000000;
        dotArray[1] = B00000000;
        dotArray[0] = B00000000;
        break;
    }
  }
  draw(lc, dotArray);
};


void SlimFont::draw(const LedControl& lc, char letter, int _startcol, boolean up) {
  startcol = _startcol;
  draw(lc, letter, up);
};

void SlimFont::draw(const LedControl& lc, char letter, boolean up) {

  byte dotArray[4] = {B01111000, B00000000, B00000000, B00000000};

  if (up)
  {
    switch (letter) {
      case 'd':
        dotArray[0] = B00001100;
        dotArray[1] = B00010010;
        dotArray[2] = B00010010;
        dotArray[3] = B11111110;
        break;
      case 'b':
        dotArray[0] = B11111110;
        dotArray[1] = B00010010;
        dotArray[2] = B00010010;
        dotArray[3] = B00001100;
        break;
      case 'e':
        dotArray[0] = B11111110;
        dotArray[1] = B10010010;
        dotArray[2] = B10000010;
        dotArray[3] = B00000000;
        break;
      case 'i':
        dotArray[0] = B00000000;
        dotArray[1] = B10011110;
        dotArray[2] = B00000000;
        dotArray[3] = B00000000;
        break;
      case 'o':
        dotArray[0] = B01111100;
        dotArray[1] = B10000010;
        dotArray[2] = B10000010;
        dotArray[3] = B01111100;
        break;
      case 'f':
        dotArray[0] = B11111110;
        dotArray[1] = B10010000;
        dotArray[2] = B10000000;
        dotArray[3] = B00000000;
        break;
      case '?':
        dotArray[0] = B01000000;
        dotArray[1] = B10001101;
        dotArray[2] = B10010000;
        dotArray[3] = B01100000;
        break;
      case '!':
        dotArray[0] = B00000000;
        dotArray[1] = B11111010;
        dotArray[2] = B00000000;
        dotArray[3] = B00000000;
        break;
      default:
        dotArray[3] = B00000000;
        dotArray[2] = B00000000;
        dotArray[1] = B00000000;
        dotArray[0] = B00000000;
        break;
    }
  }
  else
  {
    switch (letter) {
      case 'e':
        dotArray[3] = B11111110;
        dotArray[2] = B10010010;
        dotArray[1] = B10000010;
        dotArray[0] = B00111110;
        break;
      default:
        dotArray[3] = B00000000;
        dotArray[2] = B00000000;
        dotArray[1] = B00000000;
        dotArray[0] = B00000000;
        break;
    }
  }

  draw(lc, dotArray);
}

void SlimFont::draw(const LedControl& lc , byte* dotArray ) {
 // delay(1000);
//  int devices = lc.getDeviceCount() - 1;
  int devices=4;
  int displaycol = 0;
  int displayseg = devices;
  int curcol = 0;
  //  Serial.println(startcol);


  //Serial.println(number);
  for (int i = 0; i <= 3; i++)
  {
    curcol = startcol + i;
    displayseg = devices - (curcol / 8);
    displaycol = ((curcol % 8));

//       Serial.print("curcol: ");
//       Serial.println(displayseg);
//    lc.setColumn(displayseg, displaycol, dotArray[i])  ;
  }


};


//void SlimFont::ReversedOrderDigitExtractor (const LedControl& lc , int ) {}



