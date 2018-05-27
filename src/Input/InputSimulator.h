#ifndef InputSimulator_h
#define InputSimulator_h

#include "InputDevice.h"

class InputSimulator : public InputDevice {
public:
	InputSimulator(byte);
    bool pot();
    byte generateAction();
    virtual byte getInput();

private:
	byte percentage;
	byte lastaction;
	int shotdelay;
  
};


#endif