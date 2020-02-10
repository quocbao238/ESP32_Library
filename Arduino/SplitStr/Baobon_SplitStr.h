#ifndef _BBON_SPLITSTRING_B_
#define _BBON_SPLITSTRING_B_

#include "Arduino.h"
//example_value = splitString(data, "example", "=", ",", 1);
// #define START_SYMBOL  "="
// #define STOP_SYMBOL   ","
// #define OFFSET         1


class Baobon_SplitStr {
  public :

    String b_start_symbol;
    String b_stop_symbol;
    unsigned char b_Offset;


    Baobon_SplitStr(String b_start_symbol,String b_stop_symbol);

    String Baobon_SplitStr::splitStr(String b_motherString, String b_Command);

    // String splitString;
    unsigned char tem_Offset;
    unsigned char lenOfCommand;
    int posOfCommand;
    int PosOfStartSymbol;

};

#endif
