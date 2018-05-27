#ifndef LEDnKEY_h
#define LEDnKEY_h

#include "OutputDevice.h"
// Q: the LEDnKEY has 8 buttons, so why is it not an input device?
// A: so far we have not come up with a solution to map all necessary
//    functions to 8 keys, plus these keys are realy tiny and hard to
//    use when wearing gloves


class LEDnKEY : public OutputDevice {
public:
    void stub();
};


#endif