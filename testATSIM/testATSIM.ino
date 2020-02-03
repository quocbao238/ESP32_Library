
#include <SoftwareSerial.h>
 
SoftwareSerial SIM800(2, 3); // RX, TX

void setup() {

    Serial.begin(9600);
    SIM800.begin(9600);
     while (!Serial) {
  }
   while (!SIM800) {
  }

}

void loop() {
  if (SIM800.available()) {
    String command = SIM800.readStringUntil('\n');
    Serial.println(command);
  }

  if (Serial.available()) {
    String command = Serial.readStringUntil('\n');
    SIM800.println(command);
  }
  
}
