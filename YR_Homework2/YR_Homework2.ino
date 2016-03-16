/*
 Homework 2

 Created 16 March 2016
 By Yakim Rachev

 */

int ledPin8 = 8;      // LED connected to digital pin 8
int ledPin9 = 9;      // LED connected to digital pin 9
int timeDelay = 500;  // The mseconds delay

void setup() {
  pinMode(ledPin8, OUTPUT);
  pinMode(ledPin9, OUTPUT);
  
  digitalWrite(ledPin8, LOW);
  digitalWrite(ledPin9, LOW);  
}

void loop() {
  while (true){
    digitalWrite(ledPin8, HIGH);
    digitalWrite(ledPin9, LOW); 
    delay(timeDelay);
    
    digitalWrite(ledPin8, LOW);
    digitalWrite(ledPin9, HIGH);
    delay(timeDelay);
  }
}


