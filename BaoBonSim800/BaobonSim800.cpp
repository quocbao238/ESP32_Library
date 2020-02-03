/*
 * File: BaoBonSim800.h
 * Author: Quoc Bao
 * Contact: baobondev@gmail.com
 * Copyright: 2020 Quoc Bao
 */



#include "BaoBonSim800.h"
#include <SoftwareSerial.h>


BaobonSim800::BaobonSim800(SoftwareSerial * serial){
  sim800Aserial = serial;
 }

void BaobonSim800::begin(uint32_t baud)
{ 
  sim800Aserial->begin(baud);
}

String BaobonSim800::readSerial()
{
  if(sim800Aserial->available()){
    b_buffer = sim800Aserial->readStringUntil('\n');
    DEBUG_PRINTLN(b_buffer);
  }
}

uint8_t BaobonSim800::signalQuality() {
	sim800Aserial->print(F("AT+CSQ\r"));
	b_buffer = readSerial();
	if((b_buffer.indexOf("+CSQ:")) != -1) {
		return b_buffer.substring(b_buffer.indexOf("+CSQ: ")+6, b_buffer.indexOf(",")).toInt();
	} else {
		return 99;
	}
  DEBUG_PRINTLN("smsMode to " + String(b_buffer));

}

bool BaobonSim800::smsMode(bool textMode){
  
  textMode == true ? sim800Aserial->print(F("AT+CMGF=1\r")) : sim800Aserial->print(F("AT+CMGF=0\r"));
  bool result;
  b_buffer = readSerial();
  b_buffer.indexOf("OK") != -1 ? result = true : result = false;
  DEBUG_PRINTLN("smsMode to " + String(result));

}

void BaobonSim800::callUser(char* number){
  DEBUG_PRINTLN(("Call to User" + String(number)));
  this->b_number = number;
  sim800Aserial->print(F("ATD"));
  sim800Aserial->print((this->b_number));
  sim800Aserial->print(F(";"));

}

void BaobonSim800::sendSMS(char* number, char* message) {
  this->b_number = number;  this->b_message = message;
	sim800Aserial->print(F("AT+CMGS=\""));  // command to send sms
	sim800Aserial->print(this->b_number); sim800Aserial->print(F("\"\r"));
	sim800Aserial->print(message);
	sim800Aserial->print("\r");
}



// void BaobonSim800::begin() {
//   Sim800A_Serial.begin(9600);
//   DEBUG_PRINTLN(F("Start Debug BaoBonSim800A"));
// }

// void BaobonSim800::callUser(String bb_Phonenumber){
//     Sim800A_Serial.println("ATD" + bb_Phonenumber +";");
//     DEBUG_PRINTLN(F("Start Call " + bb_Phonenumber));
// }

// void BaobonSim800::readBuffer(){  
 
    
// }

