
#include "Arduino.h"
#include <SoftwareSerial.h>
#include "Sigfox.hpp"

//
#define BAUDRATE_PC 9600

//
Sigfox sigfox;

//
void setup() {
  // put your setup code here, to run once:
  Serial.begin(BAUDRATE_PC);
  delay(100);

  if(sigfox.Initialize()) Serial.println("Initialize Success!");
  String msg = "0123456789AB";    // Max 12Byte
  for(int cnt = 0; cnt<5; cnt++){
    if(sigfox.SendMessage(msg)) Serial.println("SendMessage " + msg + " Success!");
  }
  if(sigfox.Finalize()) Serial.println("Finalize Success!");
}

void loop() {
  // put your main code here, to run repeatedly:

}
