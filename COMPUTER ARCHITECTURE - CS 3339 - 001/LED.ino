//Jeremy Hester, Jason Farrell, John-Luke Speight
//This program is designed to enable and disable a single LED to determine the Mega's performance of a simple function.
//Initialize gpio
#define LED 30


void setup() {
  //Set gpio to output
  pinMode(LED, OUTPUT);
}

void loop() {

  //Number of blinks with delay time 't' in ms 
  int blinks = 10;
  int t = 500;
  //On/off Cycle
    for(int i = 0; i < blinks; i++){
      digitalWrite(LED, HIGH);
      delay(t);
      digitalWrite(LED, LOW);
      delay(t);
      ++i;
      }
      digitalWrite(LED, LOW);  
      exit(0);
      
 }
