#ifndef _EEPROM_ESP32_B_
#define _EEPROM_ESP32_B_
#include "Arduino.h"

//#define EPROM_DEBUG
#define DEBUG_PRINTER Serial /**< Define where debug output will be printed. */
/* Setup debug printing macros. */
#ifdef EPROM_DEBUG
#define DEBUG_PRINT(...) { DEBUG_PRINTER.print(__VA_ARGS__); }
#define DEBUG_PRINTLN(...) { DEBUG_PRINTER.println(__VA_ARGS__); }
#else
#define DEBUG_PRINT(...) {} /**< Debug Print Placeholder if Debug is disabled */
#define DEBUG_PRINTLN(...) {} /**< Debug Print Line Placeholder if Debug is disabled */
#endif
/*
   PIN  && VALUE
   EEPROM
*/
#define ADDRID  0
#define ADDRPW  30
#define ADDFN   60

extern "C" {
  typedef void (*Warning_Function)();
}
class EPROM_ESP32 {
  public:
    Warning_Function pF_Warning;
    //  Contructor
    EPROM_ESP32();
   //  Gen_EPROM(uint8_t b_outPin , uint8_t b_outLed, uint8_t b_restore = 1);
    //  Funtion
    void begin();
    void write(String b_id, String b_pass);
   //  void waitRestore(String w_ssid,String w_pass);
    String readId();
    String readPw();
    //  Value
    String b_ssid, b_pass;
};

#endif
