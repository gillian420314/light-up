#include <Wire.h>

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  while (1 < Wire.available()) { // loop through all but the last
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
  }
  int x = Wire.read();    // receive byte as an integer
  if(x == 0){
    digitalWrite(13,HIGH);
  }
  else if(x == 1){
    digitalWrite(13,LOW);
  }
  Serial.println(x);         // print the integer
}

void setup() {
  // put your setup code here, to run once:
  Wire.begin(8);
  Wire.onReceive(receiveEvent);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(100);
}
