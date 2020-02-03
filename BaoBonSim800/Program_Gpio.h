#ifndef _PROGRAM_GPIO_H_H_
#define _PROGRAM_GPIO_H_H_

/*  Relay change*/
#define LED_PIN_STATUS          (13)     
#define RELAY_1_PIN             (4)       
#define RELAY_2_PIN             (5)     
#define RELAY_3_PIN             (6)     
#define RELAY_4_PIN             (7)
#define ACTIVE                  (0)


/*  SIM800A    */
#define SIM800A_RX          (2)
#define SIM800A_TX          (3)
#define SLOGAN              "\nLB-TECH SIM CONTROLLER\nLH: 0981289196"
#define NUMBERONE           "+84981289196"
/* 


----------------READ SMS----------------
1 -> Send Data Sensor
DATA?
2 -> Send Status Relay
STATUS?
3 -> Add number Phone to User
    + Number 1 -> EPROM
    + Number 2 -> EPROM
    + Number 3 -> EPROM
SETNUM=1,NUM1={SDTNUMBER1},NUMBER2={SDTNUMBER2},NUMBER3={SDTNUMBER3}
spliString -> Write to EPROM
----------------------CALL ----------------------
1 -> Call to SIM 
    + Select 1 to ON 1
    + Select 2 to ON 2
    + Select 3 to ON 3
    + Select 4 to ON 4
2 -> SIM call to User-Number1 When Turn ON Board
ONCALL = "1" to ENABLE , "0" to DISABLE

----------------------ALARM----------------------

ALARM = 1 -> ENABLE             |||     ALARM = 0 ->  DISABLE
MODE  = 1 -> HIGH               |||     MODE = 0 ->  LOW
T     = (temp) -> Select temp   |||     H = (humi) -> Select Humi;

API: ALARM={1},MODE={1},T={30.0},H={36.0},

1 -> Call User - Number 1 When
    Temp > TempSelect 
    HUmi > HumiSelect
2 -> SMS Send User - Number 1 When
    Temp > TempSelect
    HUmi > HumiSelect



**********************API KEY**********************
/*
- STATUS? -> Check Status Relay && Sensor 
- ONCALL=1, -> "1" Enable call when board ON , "0" Disable call when board ON
*/
#define READ_STATUS      "STATUS?"
#define ENABLE_ONCALL    "ONCALL"
/*
- ALARM=1,MODE=1,T=30.5,H=60.5  -> 
    + ALARM "1"-ENABLE  SMS    ||  "0"  - DISABLE || "2" ENABLE CALL
    + MODE "1"- HIGH        ||  "0" - LOW
    + T= {temperHIGH-LOW}   ||  IF(MODE = 1) -> IF  (realTemp > temperHIGH) --> CALL to USER
    + H= {humiHIGH-LOW}     ||  IF(MODE = 0) -> IF  (realHumi < humiLOW)    --> CALL to USER
*/
#define SET_ALARM           "ALARM"
#define ALARM_TEMP          "T"
#define ALARM_HUMI          "H"
#define ALARM_MODE          "MODE"
#define TIME_SEND_ALARM     (0.5)    // (15' send)
#define MESSAGE_WARNING_SEND    "\nSend \"ALARM=0,\" to Disable Alarm"


/*
- SETNUM,NUM1={SDTNUMBER1},NUMBER2={SDTNUMBER2},NUMBER3={SDTNUMBER3}
    + NUM1 : Prioritize -> Setup ALARM 
    + NUM2 : CheckdataSensor,StatusRelay,CALL TO ON/OFF RELAY
    + NUM3 : CheckdataSensor,StatusRelay,CALL TO ON/OFF RELAY
*/
#define set_NUM          "SETNUM"

#define SW1     "SW1="
#define SW2     "SW2="
#define SW3     "SW3="
#define SW4     "SW4="

#define SW12     "SW1-2="
#define SW13     "SW1-3="
#define SW14     "SW1-4="
#define SW23     "SW2-3="
#define SW24     "SW2-4="
#define SW34     "SW3-4="




/*   Sensor Change           */
#define SENSOR_DHT_PIN          (8)  
#define SENSOR_DS18B20_TWO      (9) 
#define SENSOR_SHT30_DATA       (A4)    // SDA
#define SENSOR_SHT30_CLK        (A5)    // SCL

#endif
