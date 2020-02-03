
#include "BaoBonSim800.h"
#include "Program_Gpio.h"
#include "SoftwareSerial.h"

SoftwareSerial serial(2,3);
BaobonSim800 sim800A(&serial);

void setup() {
  sim800A.begin(9600);
  Serial.begin(9600);
  sim800A.callUser("84981289196");
}

void loop() {



}
