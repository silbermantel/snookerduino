#include "InputDevice.h"
byte InputDevice::getInput() {return 4;}

void InputDevice::defineMatchcodes() {
  int ircode=0;
  int rValue = 255; //do nothing
  switch (ircode)
  {
    case 44: rValue = 90; //end of break
      break;
    case 16: rValue = 91; //plus 1
      break;
    case 17: rValue = 92; //minus 1
      break;
    case 32: rValue = 95; //plus 5
      break;
    case 33: rValue = 96; //minus 5
      break;
    case 55: rValue = 99; //end of frame
      break;
    default: rValue = ircode; //passthru everything else
      break;
  }
}