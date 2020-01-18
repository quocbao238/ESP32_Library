/* 
   This Library for write ssid && write password to EEPROM Esp32
   read ssid && read password
 *  
   Support write/read ssid & password to EPROM 
*/

#include "EPROM_ESP32.h"

EPROM_ESP32 Eprom;
String b_id = "Example SSID";
String b_pass = "Example Password";
void setup() {
  Eprom.begin();
  Serial.begin(115200);
  Eprom.write(b_id, b_pass); 
  ReadEEPROM();
}
void loop() {
}

void ReadEEPROM() {
  Serial.print("ssid : "); Serial.println(Eprom.readId());
  Serial.print("pass : "); Serial.println(Eprom.readPw());
}
