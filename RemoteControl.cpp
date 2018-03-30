#include "RemoteControl.h"
String RemoteControl::identify(int ircode) {
  Serial.print("Init signal: ");
  Serial.println(ircode);
  String rValue = "unknown";
  //code received in IRrecvDumpV2 when pressing power button
  //http://files.remotecentral.com/download/157/rm139e-manual.zip.html
  switch (ircode)
  {
    case 12:  ID = 1;
      rValue = "philipsTV";
      break;
    case 18615:  ID = 2;
      rValue = "easyZapper";
      break;
    case 2080:  ID = 1787;
      rValue = "easyZapperMedion";
      break;

    case 0:  ID = 65535;
      rValue = "dummy";
      break;

    case 4032:  ID = 4032;
      rValue = "benq";
      break;

  }
  return (rValue);
};


int RemoteControl::getCommand(int ircode) {
  int rValue = 255;
  switch (ID)
  {
    case 1:  rValue = decode1(ircode);
      break;
    case 2:  rValue = decode2(ircode);
      break;
    case 1787:  rValue = decode1787(ircode);
      break;
    case 4032:  rValue = decode4032(ircode);
      break;
  }

  //
  Serial.print("received: ");
  Serial.print(ircode);
  Serial.print(" from Remote ");
  Serial.print(ID);
  Serial.print(" returning: ");
  Serial.println(rValue);
  return (rValue);
};



int RemoteControl::getID() {

  return (ID);
};


int  RemoteControl::decode1(int ircode) {
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

  return (rValue);
};

int  RemoteControl::decode2(int ircode) {
  int rValue = 255; //do nothing
  switch (ircode)
  {
    case 8415: rValue = 1;
      break;
    case -24481: rValue = 2;
      break;
    case 24735: rValue = 3;
      break;
    case 4335: rValue = 4;
      break;
    case -28561: rValue = 5;
      break;
    case 20655: rValue = 6;
      break;
    case 12495: rValue = 7;
      break;
    case -20401: rValue = 8;
      break;
    case 28815: rValue = 9;
      break;
    case 50135295: rValue = 0;
      break;


    case -15301: rValue = 90; //end of break
      break;
    case 18615: rValue = 90; //end of break
      break;
    case 22695: rValue = 91; //plus 1
      break;
    case -12241: rValue = 92; //minus 1
      break;
    case -10201: rValue = 95; //plus 5
      break;
    case 2295: rValue = 96; //minus 5
      break;
    case 10455: rValue = 99; //end of frame
      break;
    default: rValue = ircode; //passthru everything else
      break;
  }

  return (rValue);
};
int  RemoteControl::decode1787(int ircode) {
  int rValue = 255; //do nothing
  switch (ircode)
  {
    case 2064: rValue = 0;
      break;
    case 2065: rValue = 1;
      break;
    case 2066: rValue = 2;
      break;
    case 2067: rValue = 3;
      break;
    case 2068: rValue = 4;
      break;
    case 2069: rValue = 5;
      break;
    case 2070: rValue = 6;
      break;
    case 2071: rValue = 7;
      break;
    case 2072: rValue = 8;
      break;
    case 2073: rValue = 9;
      break;
    case 16: rValue = 0;
      break;
    case 17: rValue = 1;
      break;
    case 18: rValue = 2;
      break;
    case 19: rValue = 3;
      break;
    case 20: rValue = 4;
      break;
    case 21: rValue = 5;
      break;
    case 22: rValue = 6;
      break;
    case 23: rValue = 7;
      break;
    case 24: rValue = 8;
      break;
    case 25: rValue = 9;
      break;


    case 2080: rValue = 90; //end of break
      break;
    case 32: rValue = 90; //end of break
      break;
    case 2084: rValue = 91; //plus 1
      break;
    case 36: rValue = 91; //plus 1
      break;
    case 2085: rValue = 92; //minus 1
      break;
    case 37: rValue = 92; //minus 1
      break;
    case 2076: rValue = 95; //plus 5
      break;
    case 28: rValue = 95; //plus 5
      break;
    case 2075: rValue = 96; //minus 5
      break;
    case 27: rValue = 96; //minus 5
      break;
    case 2090: rValue = 99; //end of frame
      break;
    case 42: rValue = 99; //end of frame
      break;
    default: rValue = ircode; //passthru everything else
      break;
  }

  return (rValue);
};



int  RemoteControl::decode4032(int ircode) {
  int rValue = 255; //do nothing
  switch (ircode)
  {
    case 4052: rValue = 0;
      break;
    case 4064: rValue = 1;
      break;
    case 4048: rValue = 2;
      break;
    case 4080: rValue = 3;
      break;
    case 4040: rValue = 4;
      break;
    case 4072: rValue = 5;
      break;
    case 4056: rValue = 6;
      break;
    case 4088: rValue = 7;
      break;
    case 4036: rValue = 8;
      break;
    case 4068: rValue = 9;
      break;


    case 4032: rValue = 90; //end of break
      break;
    case 4050: rValue = 99; //end of frame
      break;
    default: rValue = ircode; //passthru everything else
      break;
  }

  return (rValue);
};

