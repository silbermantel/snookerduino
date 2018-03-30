#ifndef TM1638_h
#define TM1638_h

#include "Arduino.h"
class TM1638
{
  public:
    TM1638(int strobe, int clock, int data);
    void showNumber(int number, int digit);
    void setLed(uint8_t value, uint8_t position);
    uint8_t readButtons(void);
    int lightLEDs (uint8_t number);
    int lightLEDs (uint8_t offset, uint8_t number);
    void resetLEDs();
    void reset();

  private:
    void sendCommand(uint8_t value);

    int strobe;
    int clock;
    int data;


    /*
      uint8_t number[] = { 0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f };
      uint8_t digit[] = { 0xc0, 0xc2, 0xc4, 0xc6,  0xc8, 0xca, 0xcc, 0xce };
      uint8_t leds[] = {  0xc1, 0xc3,  0xc5, 0xc7,  0xc9,  0xcb,  0xcd, 0xcf };
    */
};


#endif


