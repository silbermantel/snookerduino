#include "OutputSerial.h"

/*
 this is a demo implementation of an output device.
 you can always use it as a dummy devce if your short on displays.
*/


OutputSerial::OutputSerial() {
	Serial.println("initializing serial Scoreboard");
	printBoard("left", "right");
}

/* an array of 7segs realy only has one way of displaying*/
String OutputSerial::showDefault(int score[]) {
	printBoard(String(score[0]), String(score[1]));
	return "foo";
}

String OutputSerial::showScore(int score[]) {
	return showDefault(score);
}
String OutputSerial::showFrames(int score[]) {
	return showDefault(score);
}
String OutputSerial::showBreak(int score[]) {
	return showDefault(score);
}

void OutputSerial::printBoard(String left, String right) {
	byte sleft = spacing - left.length();
	byte sright = spacing - right.length();
	String thisline = "*";
	thisline = thisline + left;
	for (int i = 0; i < sleft; i++)
		thisline = thisline + " ";
	thisline = thisline + "**";
	thisline = thisline + right;
	for (int i = 0; i < sright; i++)
		thisline = thisline + " ";
	thisline = thisline + "*";


	Serial.println(thisline);
}

