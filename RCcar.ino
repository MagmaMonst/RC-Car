#include "BluetoothSerial.h"


BluetoothSerial SerialBT;


int Clock1 = 18;
int Anti1 = 19;
int Clock2 = 21;
int Anti2 = 22;


void setup() {
 Serial.begin(115200);
 SerialBT.begin("RC_Car"); 
 pinMode(18, OUTPUT);
 pinMode(19, OUTPUT);
 pinMode(21, OUTPUT);
 pinMode(22, OUTPUT);
}

void loop() {
 if (SerialBT.available()) {
   String received = SerialBT.readStringUntil('\n');

   int control = received.toInt();
   ManualControls(control);
 }

} 
//communication of esp and phone

 void front()
 {
    digitalWrite(Clock1, HIGH);
    digitalWrite(Anti1, LOW);
    digitalWrite(Clock2, HIGH);
    digitalWrite(Anti2, LOW);
 }
 //front

 void back()
 {
    digitalWrite(Clock1, LOW);
    digitalWrite(Anti1, HIGH);
    digitalWrite(Clock2, LOW);
    digitalWrite(Anti2, HIGH);
 }
 //back

 void left()
 {
    digitalWrite(Clock1, LOW);
    digitalWrite(Anti1, HIGH);
    digitalWrite(Clock2, HIGH);
    digitalWrite(Anti2, LOW);
     
 }
 //left turn

void right()
 {
    digitalWrite(Clock1, HIGH);
    digitalWrite(Anti1, LOW);
    digitalWrite(Clock2, LOW);
    digitalWrite(Anti2, HIGH);  
 }
 //right turn
 
 void stop()
 {
    digitalWrite(Clock1, LOW);
    digitalWrite(Anti1, LOW);
    digitalWrite(Clock2, LOW);
    digitalWrite(Anti2, LOW); 
 }
 //all motors off

void ManualControls(int control) {
  switch (control) {
    case 1:
      front();
      break;
    case 2:
      back();
      break;
    case 3:
      left();
      break;
    case 4:
      right();
      break;
    default:
      stop();
      break;
  }
   
 }

