#include "EPROM_ESP32.h"
#include <EEPROM.h>

uint8_t addrid = 0;
EPROM_ESP32::EPROM_ESP32(){}

void EPROM_ESP32::begin() {
  EEPROM.begin(512);
  DEBUG_PRINTLN(F("Start Debug EPROM_Gen_Restore"));
}

void EPROM_ESP32::write(String id, String pw) {
  //  Clear EPROM
  for (int i = 0; i < 512; i++) {
    EEPROM.write(i, 0);
  }
  //  Write SSID
  DEBUG_PRINTLN(F("SSID"));
  for (int i = ADDRID ; i < id.length(); i++) {
    EEPROM.write(i, id[i]);
    DEBUG_PRINT(id);
  }
  //  Write PW
  DEBUG_PRINTLN(F("PASS"));
  for (int i = ADDRID ; i < pw.length(); i++) {
    EEPROM.write(ADDRPW + i, pw[i]);
    DEBUG_PRINT(pw);
  }
  EEPROM.commit();
  EEPROM.end();
  DEBUG_PRINTLN(F("Write Compile"));
}
String EPROM_ESP32::readId() {
  b_ssid = "";
  for (int i = ADDRID; i < ADDRPW; i++) {
    b_ssid += char(EEPROM.read(i));
  }
  b_ssid.trim();
  return b_ssid.c_str();
}

String EPROM_ESP32::readPw() {
  b_pass = "";
  for (int i = ADDRPW; i < ADDFN; i++) {
    b_pass += char(EEPROM.read(i));
  }
  b_pass.trim();
  return b_pass.c_str();
}
