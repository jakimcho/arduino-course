/*
 Homework 1

 Created 16 March 2016
 By Yakim Rachev

 */

int ledPin8 = 8;      // LED connected to digital pin 8
int ledPin9 = 9;      // LED connected to digital pin 9
int timeDelay = 250;  // The mseconds delay

void setup() {
  pinMode(ledPin8, OUTPUT);
  pinMode(ledPin9, OUTPUT);
  
  digitalWrite(ledPin8, LOW);
  digitalWrite(ledPin9, LOW);  
}

void loop() {
  int i = 0;    // keep track of the ledPin8 blinks
  while (true){
    digitalWrite(ledPin8, HIGH);
    delay(timeDelay);
    digitalWrite(ledPin8, LOW);
    delay(timeDelay);
    i++;
    
    if (i == 2){
       digitalWrite(ledPin9, HIGH);
    }
    
    if (i == 4){
       digitalWrite(ledPin9, LOW);
       i = 0;
    }  
  }
}


