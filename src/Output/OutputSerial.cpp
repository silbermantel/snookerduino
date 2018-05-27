#include "OutputSerial.h"

OutputSerial::OutputSerial(){
	Serial.println("initializing serial Scoreboard");
	printBoard();
}
String OutputSerial::showScore(int score[]) {
	printBoard(String(score[0]),String(score[1]));
	return "foo";}
String OutputSerial::showFrames(int score[]) {return "foo";}
String OutputSerial::showBreak(int score[]) {return "foo";}

void OutputSerial::printBoard(String left, String right) {
	byte sleft=spacing-left.length();
	byte sright=spacing-right.length();
	String thisline="*";
	thisline=thisline+left;
	for (int i=0;i<sleft;i++)
			thisline=thisline+" ";
	thisline=thisline+"**";
	thisline=thisline+right;
	for (int i=0;i<sright;i++)
			thisline=thisline+" ";
	thisline=thisline+"*";


	   Serial.println(thisline);
	}

void OutputSerial::printBoard() {
/*   Serial.println("****************************************");
   Serial.println("*     LEFT         **      RIGHT       *");
   Serial.println("****************************************");
*/
	String header="";
	
	for (int i = 0; i < spacing; i++)
			header=header+"*";
	String empty="";
	
	for (int i = 0; i < spacing; i++)
			empty=empty+" ";

	printBoard(header,header);
	printBoard("Lindrum","Davis");
	printBoard(header,header);
	printBoard(empty,empty);
	printBoard(header,header);
	printBoard(empty,empty);
	printBoard(header,header);
	printBoard(empty,empty);
	printBoard(header,header);
	
   	



}
