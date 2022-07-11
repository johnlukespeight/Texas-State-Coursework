//Jeremy Hester, Jason Farrell, John-Luke Speight
//This program is designed to enable and disable a single LED to determine the Raspberry Pi 4's performance of a simple function. 
//Setting Libraries
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <wiringPi.h>

//Defining GPIO output for LED
#define RED 24


int main(void){
	//Initiate
	wiringPiSetup();
	//Declare output pin
	pinMode(RED, OUTPUT);
	//Initialize number of blinks and delay time
	int blinks = 50;
	int t =500;
	//
	for(int i = 0; i < blinks; i++)
	{
			digitalWrite(RED, HIGH);
			delay(t);
			digitalWrite(RED, LOW);
			delay(t);
			++i;
	}
	//Turn off LED
	digitalWrite(RED, LOW);
	return 0;		
}
