#include <IRLib.h>

int ledTemp = 7; //Red LED
int ledLight = 6; //Green LED
long potVal = 0;

IRsendNECx irEmitter; // Default port for UNO ~3
IRrecv irReceiver(11);
IRdecode irDecoder; // Used to decode IR signals

void setup()
{
  Serial.begin(9600);
  irReceiver.enableIRIn();
  pinMode(ledTemp, OUTPUT);
  pinMode(ledLight, OUTPUT);
}

void loop() {
  if (irReceiver.GetResults(&irDecoder)) {
    irDecoder.decode();
    potVal = (long) irDecoder.value;
    Serial.println("I got signal from remote - " + (String) potVal);
    Serial.print("got signal " + (String) irDecoder.value + " - ");
    Serial.println(irDecoder.value, DEC);
    irReceiver.resume();
    
    if(potVal > 500){
      digitalWrite(ledLight, LOW);
      digitalWrite(ledTemp, HIGH);
    }else{
      digitalWrite(ledTemp, LOW);
      digitalWrite(ledLight, HIGH);
    }
  }
 
  irEmitter.send(potVal);
  irReceiver.enableIRIn();
  delay(150);
}

