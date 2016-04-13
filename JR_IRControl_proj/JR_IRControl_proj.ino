#include <IRLib.h>

int pot = A0; // Potentiometer input
int ledTemp = 7; // Red LED
int ledLight = 8; // Green LED
int btnGo = 2;
int potVal = 0;
int irTimeout = 2000;
int buttonState = 0;

IRrecv irReceiver(11);
IRsendNECx irEmitter;
IRdecode irDecoder;

void setup() {
  Serial.begin(9600);
  irReceiver.enableIRIn();
  pinMode(btnGo, INPUT);
  pinMode(ledTemp, OUTPUT);
  pinMode(ledLight, OUTPUT);

}

void loop() {
    
  if (irReceiver.GetResults(&irDecoder)){
    irDecoder.decode();
    Serial.print("got signal " + (String) irDecoder.value + " - ");
    Serial.println(irDecoder.value, DEC);
    irReceiver.resume();
  }

  int tmpPot = analogRead(pot);
  if ((potVal > tmpPot + 15) || (potVal < tmpPot - 15)){
    potVal = tmpPot;  
    if(potVal > 500){
      digitalWrite(ledLight, LOW);
      digitalWrite(ledTemp, HIGH);
    }else{
      digitalWrite(ledTemp, LOW);
      digitalWrite(ledLight, HIGH);
    }  
  }
  
  buttonState = digitalRead(btnGo);
  delay(250);
  
  if (buttonState == HIGH){
    boolean isAnswered = false;
    Serial.println("Pot val - " + (String) potVal);
    Serial.println("Sending voltage info to the remote unit");
    irEmitter.send(potVal); // Updates the other unit for voltage changes
    
    Serial.println("You just send signal ");
    unsigned long currentMillis = millis(); // get the time when the request has been sent
    
    while(millis() - currentMillis < irTimeout){
      if (irReceiver.GetResults(&irDecoder)){
        irDecoder.decode();
        irReceiver.resume();
        irReceiver.enableIRIn();
        Serial.print("got from remote " + (String) irDecoder.value + " - ");
        Serial.println(irDecoder.value, DEC);
        isAnswered = true;
        break;
      }
    }
    
    irReceiver.resume();
    irReceiver.enableIRIn();
    
    if(!isAnswered){
      Serial.println("No response from the remote unit");
    }
  }

}
