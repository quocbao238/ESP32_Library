/*
 * File: BaoBonSim800.h
 * Author: Quoc Bao
 * Contact: baobondev@gmail.com
 * Copyright: 2020 Quoc Bao
 */

#ifndef _EEPROM_GEN_B_
#define _EEPROM_GEN_B_
#include "Arduino.h"
#include <SoftwareSerial.h>

/******************************** DEBUG *********************************/
/* Uncomment to enable printing out nice debug messages. */
#define SIM_DEBUG
#define DEBUG_PRINTER Serial
#ifdef SIM_DEBUG
#define DEBUG_PRINT(...) { DEBUG_PRINTER.print(__VA_ARGS__); }
#define DEBUG_PRINTLN(...) { DEBUG_PRINTER.println(__VA_ARGS__); }
#else
#define DEBUG_PRINT(...) {} /**< Debug Print Placeholder if Debug is disabled */
#define DEBUG_PRINTLN(...) {} /**< Debug Print Line Placeholder if Debug is disabled */
#endif
/******************************** DEFINE PINOUT *********************************/

#define SIM800A_RX          (2)
#define SIM800A_TX          (3)


class BaobonSim800  
{
    public:
    BaobonSim800(SoftwareSerial * serial);

    // uint32_t     b_baud;
    // uint8_t      b_rx;
    // uint8_t      b_tx;
    String       b_buffer;
    // String       b_readSerial();
    bool         b_textMode;
    char*        b_number;
    char*        b_message;
    // char*        a_number;

	// BaobonSim800(uint8_t b_rx, uint8_t b_tx);
    void begin(uint32_t b_baud);
	String readSerial();
    uint8_t signalQuality();
	bool smsMode(bool b_textMode);
    void BaobonSim800::sendSMS(char* b_number, char* b_message);
    void BaobonSim800::callUser(char* b_number);

    private:
    SoftwareSerial * sim800Aserial;
};



#endif