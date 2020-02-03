#include <GSMSim.h>

#define RX 2
#define TX 3
//#define RESET 2
#define BAUD 9600


GSMSim gsm(RX, TX);
/*
 * Also you can this types:
 * GSMSim gsm(RX, TX);
 * GSMSim gsm(RX, TX, RESET);
 * GSMSim gsm(RX, TX, RESET, LED_PIN, LED_FLAG);
 */

void setup() {

  Serial.begin(9600);
  gsm.start(9600);
  char* phone_no = "+84981289196";
  Serial.println("Calling the number " + String(phone_no));
  // CALL 
  gsm.call(phone_no);
  // Cancel call
  delay(1000);
  gsm.callHangoff();
  Serial.println("Cancel call");
  // Set gsm to Text Mode
  gsm.smsTextMode(true);
  char* message = "Hi my friend. How are you?";
  gsm.smsSend(phone_no, message);

  

  
}

void loop() {
  // put your main code here, to run repeatedly:
}
