#include "tm1638.h"



void TM1638::sendCommand(uint8_t value)
{
  digitalWrite(strobe, LOW);
  shiftOut(data, clock, LSBFIRST, value);
  digitalWrite(strobe, HIGH);
}



void TM1638::showNumber(int number, int digit) {
  uint8_t numbers[] = { 0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f };
  uint8_t digits[] = { 0xc0, 0xc2, 0xc4, 0xc6,  0xc8, 0xca, 0xcc, 0xce };

  digitalWrite(strobe, LOW);
  shiftOut(data, clock, LSBFIRST, digits[digit]);
  shiftOut(data, clock, LSBFIRST, numbers[number]);
  digitalWrite(strobe, HIGH);

};



TM1638::TM1638(int _strobe, int _clock, int _data) {
  strobe = _strobe;
  clock = _clock;
  data = _data;

  pinMode(strobe, OUTPUT);
  pinMode(clock, OUTPUT);
  pinMode(data, OUTPUT);

  sendCommand(0x89);  // set brightness
  reset();


};


uint8_t TM1638::readButtons(void) {
  uint8_t buttons = 0;
  digitalWrite(strobe, LOW);
  shiftOut(data, clock, LSBFIRST, 0x42);
  pinMode(data, INPUT);
  for (uint8_t i = 0; i < 4; i++)
  {
    uint8_t v = shiftIn(data, clock, LSBFIRST) << i;
    buttons |= v;
  }
  pinMode(data, OUTPUT);
  digitalWrite(strobe, HIGH);
  return buttons;
}


void TM1638::setLed(uint8_t value, uint8_t position) {
  pinMode(data, OUTPUT);
  sendCommand(0x44);
  digitalWrite(strobe, LOW);
  shiftOut(data, clock, LSBFIRST, 0xC1 + (position << 1));
  shiftOut(data, clock, LSBFIRST, value);
  digitalWrite(strobe, HIGH);
}


int TM1638::lightLEDs (uint8_t offset, uint8_t number) {
  for (int i = 0; i < number; i++)
  {
    setLed( 1 , offset + i );
  }
};


int TM1638::lightLEDs (uint8_t number) {
  lightLEDs(0, number);
};


void TM1638::resetLEDs() {
  for (int i = 0; i < 8; i++)
  {

    setLed( 0 , i );
  }


};

void TM1638::reset()
{
  sendCommand(0x40); // set auto increment mode
  digitalWrite(strobe, LOW);
  shiftOut(data, clock, LSBFIRST, 0xc0);   // set starting address to 0
  for (uint8_t i = 0; i < 16; i++)
  {
    shiftOut(data, clock, LSBFIRST, 0x00);
  }
  digitalWrite(strobe, HIGH);
}







