// #include "sim800A_Program.h"
// #include "Program_Gpio.h"
// #include <SoftwareSerial.h>
// #include "sht3x_Program.h"
// #include "relay_Program.h"
// #include "sim800A_Alarm.h"

// SoftwareSerial sim800A_Serial(SIM800A_RX, SIM800A_TX); // (Rx,Tx  > Tx,Rx)

// enum{
//   STATE_ON = 0,
//   STATE_OFF,
//   STATE_IDE
// };

// String inputString;
// boolean callwhenStart = false;
// String message;
// boolean alarm_send;

// String lb_phoneNumber = NUMBERONE;

// void alarm_SMS();
// void sendMessage();
// void checkCall();
// void Call_User();


// void Sim800A_Class::setup(){
//     sim800A_Serial.begin(9600);
//     // delay(5000);
//     if(callwhenStart){
//       Call_User();
//     }
//     Serial.println("Sim800A Program Start");
// }
// void Sim800A_Class::loop(){
//   if(ui_stateProgram == STATE_ON){
//     readBuffer();
//     ul_timeRepeat = 10;
//     ui_stateProgram = STATE_OFF;
//   }else if(ui_stateProgram == STATE_OFF){
//     // alarm_SMS(); 
//     ul_timeRepeat = 10;
//     ui_stateProgram = STATE_ON;
//   }else;
// }

// /*************************************************************************************/
// void Call_User(){
//   delay(150);
//   sim800A_Serial.println("ATD" +lb_phoneNumber+";");
//   delay(150);
// }
// /*************************************************************************************/
// String splitString(String v_G_motherString, String v_G_Command, String v_G_Start_symbol, String v_G_Stop_symbol, unsigned char v_G_Offset)
// {
//   unsigned char tem_Offset = v_G_Offset - 1;
//   unsigned char lenOfCommand = v_G_Command.length();

//   int posOfCommand = v_G_motherString.indexOf(v_G_Command);
//   int PosOfStartSymbol = v_G_motherString.indexOf(v_G_Start_symbol, posOfCommand + lenOfCommand);
//   if (posOfCommand < 0)
//     return "";

//   // Xu ly Dau Command
//   //  DB_SPLIT(v_G_Command + " posOfCommand " + (String)posOfCommand);
//   if (posOfCommand > 0)
//   {
//     String tem__ = v_G_motherString.substring(posOfCommand - 1, posOfCommand);
//     //    DB_SPLIT("posOfCommand at Start " + tem__);
//     if ((tem__ != " ") && (tem__ != v_G_Stop_symbol))
//     {
//       return "";
//     }
//   }

//   // Xu ly cuoi Command
//   unsigned int temPosOfLastCommand = posOfCommand + lenOfCommand;
//   if (temPosOfLastCommand)
//   {
//     String tem__ = v_G_motherString.substring(temPosOfLastCommand, temPosOfLastCommand + 1);
//     //    DB_SPLIT("posOfCommand at Last " + tem__);
//     if ((tem__ != " ") && (tem__ != v_G_Start_symbol))
//     {
//       return "";
//     }
//   }

//   if (v_G_Offset == 0)
//   {
//     String tem__ = v_G_motherString.substring(posOfCommand, PosOfStartSymbol);
//     if (tem__ == v_G_Command)
//     {
//       return tem__;
//     }
//     return "";
//   }

//   while (tem_Offset > 0)
//   {
//     tem_Offset--;
//     PosOfStartSymbol = v_G_motherString.indexOf(v_G_Start_symbol, PosOfStartSymbol + 1);
//   }

//   if (v_G_Stop_symbol != "")
//   {
//     int PosOfStopSymbol = v_G_motherString.indexOf(v_G_Stop_symbol, PosOfStartSymbol + 1);
//     if (PosOfStopSymbol == -1)
//     {
//       return "";
//     }
//     else
//       ;
//     return v_G_motherString.substring(PosOfStartSymbol + 1, PosOfStopSymbol);
//   }
//   else
//   {
//     return v_G_motherString.substring(PosOfStartSymbol + 1);
//   }
// }


// /*************************************************************************************/
// void sendMessage(String lb_message){
//   // sim800A_Serial.println("AT+CMGF=1"); // Set the Mode as Text Mode
//   // delay(150);
//   // sim800A_Serial.println("AT+CMGS=\""+ lb_phoneNumber + "\"");
//   // delay(150);
//   // sim800A_Serial.print(lb_message);delay(150);
//   // sim800A_Serial.print(SLOGAN);delay(100);
//   // sim800A_Serial.write((byte)0x1A); delay(100);
//   // sim800A_Serial.println();
//   // delay(150);
//   Serial.println(lb_message + SLOGAN);
//   delay(150);
//   Serial.println();

// }
// /*************************************************************************************/
// void enableCall_whenStart(String data, String lb_phoneNumber){
//   if(data == "1"){
//     callwhenStart = true;
//     message = "Set call when start to ENABLE ";
//     sendMessage(message);
//   }else if(data == "0"){
//     message = "Set call when start to DISABlE ";
//     callwhenStart = false;
//     sendMessage(message);
//   }
// }
// /*************************************************************************************/
// void send_StatusTempalte(){
//    message = "T:"
//    + String(temperature) +
//    "*C - H:"
//    + String(humidity) + "%\nTB1: "
//    + statusRL1+
//    " TB2: "
//    + statusRL2  +
//    "\nTB3: "
//    + statusRL3   +
//    " TB4: " 
//    + statusRL4;
//    sendMessage(message);
// }
// /*************************************************************************************/
// void alarmsetting(String data)
// {
//   /* 
// ALARM=1,MODE=1,T=30.5,H=60.5,
//   */ 
//    alarm_temp = splitString(data,ALARM_TEMP, "=", ",",1).toFloat();
//    alarm_humi = splitString(data,ALARM_HUMI, "=", ",",1).toFloat();
//    alarm_mode = splitString(data,ALARM_MODE, "=", ",",1).toInt();
//    alarm_enable = splitString(data,SET_ALARM,"=", ",",1).toInt();
//    message = "Alarm "; 
//    alarm_enable == 1 ? message += "ON" : message += "OFF";
//    if(alarm_enable == 1){
//    alarm_mode == 1 ? message += "\nMode HIGH" : message += "\nMode LOW";
//    message += "\nT_Set: " + String(alarm_temp) + "*C - T-Real: " + String(temperature) + "*C";
//    message += "\nH_Set: " + String(alarm_humi) + "% - H-Real: " + String(humidity) + " %";
//   //  delay(10);
//    }
//    delay(100);
//    sendMessage(message);
// }

// void alarm_SMS(){
//   if(alarmRankTemp == 2){
//     message = "Warning! Temperature is High\n";
//     message += String(temperature) + "*C > " + String(alarm_temp) + " *C";
//     sendMessage(message);
//   }else
//   if(alarmRankTemp == 1 ){
//     message = "Warning! Temperature is LOW\n";
//     message += String(temperature) + "*C < " + String(alarm_temp) + " *C";
//     sendMessage(message);
//   }

//   if(alarmRankTemp == 2 ){
//     message = "Warning! Temperature is High\n";
//     message += String(temperature) + "*C > " + String(alarm_temp) + " *C";
//     sendMessage(message);
//   }else
//     if(alarmRankTemp == 1 ){
//     message = "Warning! Temperature is LOW\n";
//     message += String(temperature) + "*C < " + String(alarm_temp) + " *C";
//     sendMessage(message);
//   }

// }


// /*************************************************************************************/
// /*  ON/OFF Switch  */
// void onoffSW(int rank_rl,String active_rlData){
//   switch (rank_rl)
//   {
//   case 1 :    
//     active_rl1 = !active_rlData.toInt();
//     break;
//   case 2 :    
//     active_rl2 = !active_rlData.toInt();
//     break;
//   case 3 :    
//     active_rl3 = !active_rlData.toInt();
//     break;
//   case 4 :    
//     active_rl4 = !active_rlData.toInt();
//     break;
//   default:
//     break;
//   }
//     active_rl1 == 0 ? statusRL1 = "ON" : statusRL1 = "OFF";
//     active_rl2 == 0 ? statusRL2 = "ON" : statusRL2 = "OFF";
//     active_rl3 == 0 ? statusRL3 = "ON" : statusRL3 = "OFF";
//     active_rl4 == 0 ? statusRL4 = "ON" : statusRL4 = "OFF";
//   // send_StatusTempalte();
// }

// void onoffSWDouble(int rank1,unsigned int rank2,String active_rlData){
//  onoffSW(rank1,active_rlData);
//  onoffSW(rank2,active_rlData);
//  send_StatusTempalte();
// }
// /*************************************************************************************/

// void handingData(String _inputString){
//   // Serial.println(_inputString);
//   _inputString.toUpperCase(); //
//   if(_inputString.indexOf(READ_STATUS) > -1){
//     // Serial.println("---STATUS---");
//     send_StatusTempalte();
//   }else 
//   if(_inputString.indexOf(ENABLE_ONCALL) > -1){
//     // Serial.println("---ONCALL---");
//     enableCall_whenStart(splitString(_inputString,ENABLE_ONCALL,"=",",",1)
//     ,NUMBERONE);
//   }else 
//   if(_inputString.indexOf(SET_ALARM) > -1){
//     alarmsetting(_inputString);
//   }else 
//   if(_inputString.indexOf(SW1) > -1){
//     onoffSW(1,splitString(_inputString,"SW1","=" , "," , 1));
//     send_StatusTempalte();
//   }
//   else 
//   if(_inputString.indexOf(SW2) > -1){
//     onoffSW(2,splitString(_inputString,"SW2","=" , "," , 1));
//     send_StatusTempalte();
//   }
//   else 
//   if(_inputString.indexOf(SW3) > -1){
//     onoffSW(3,splitString(_inputString,"SW3","=" , "," , 1));
//     send_StatusTempalte();
//   }
//   else 
//   if(_inputString.indexOf(SW4) > -1){
//     onoffSW(4,splitString(_inputString,"SW4","=" , "," , 1));
//     send_StatusTempalte();
//   }
//   else 
//   if(_inputString.indexOf(SW12) > -1){
//     onoffSWDouble(1,2,splitString(_inputString,"SW1-2","=" , "," , 1));
//   }
//   else 
//   if(_inputString.indexOf(SW13) > -1){
//     onoffSWDouble(1,3,splitString(_inputString,"SW1-3","=" , "," , 1));
//   }
//   else 
//   if(_inputString.indexOf(SW14) > -1){
//     onoffSWDouble(1,4,splitString(_inputString,"SW1-4","=" , "," , 1));
//   }
//   else 
//   if(_inputString.indexOf(SW23) > -1){
//     onoffSWDouble(2,3,splitString(_inputString,"SW2-3","=" , "," , 1));
//   }else 
//   if(_inputString.indexOf(SW24) > -1){
//     onoffSWDouble(2,4,splitString(_inputString,"SW2-4","=" , "," , 1));
//   }else 
//   if(_inputString.indexOf(SW34) > -1){
//     onoffSWDouble(3,4,splitString(_inputString,"SW3-4","=" , "," , 1));
//   }
//   message = "";
// }
// /*************************************************************************************/
// void Sim800A_Class::readBuffer(){
  
//   // if (sim800A_Serial.available()) {
//   //   inputString = sim800A_Serial.readStringUntil('\n');
//   //   Serial.println(inputString);    
//   //   handingData(inputString);
//   // }

//   /* Debug */
//     if (Serial.available()) {
//     inputString = Serial.readStringUntil('\n');
//     if(inputString != ""){
//     // Serial.println(inputString);    
//     handingData(inputString);
//     inputString = "";
//     }
//   }
  
// }

// Sim800A_Class Sim800A_Program;
