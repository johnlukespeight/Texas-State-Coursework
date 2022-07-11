//Jeremy Hester, Jason Farrell, John-Luke Speight
//This program is designed to enable and disable a single LED to determine the Mega's performance of a simple function.

#include <avr/sleep.h>
#define LED 31  // The pin the LED is connected to

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT); // Declare the LED as an output
  unsigned long timeBegin = micros();
  Serial.println(timeBegin);
  for(int i =0; i<20;i++)   //repeated 50 times
  {
  digitalWrite(LED, HIGH); // Turn the LED on
  delay(500);
  digitalWrite(LED, LOW); //Turn the LED off
  delay(500);
  }
  unsigned long timeEnd = micros();
  Serial.println(timeEnd);
}

void loop() {
  
exit(0);}
