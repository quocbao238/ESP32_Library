#include "Baobon_SplitStr.h"

// //example_value = splitString(data, "example", "=", ",", 1);

Baobon_SplitStr::Baobon_SplitStr(String startSymbol,String stopSymbol){
    this->b_start_symbol = startSymbol;
    this->b_stop_symbol   = stopSymbol;  
}

String Baobon_SplitStr::splitStr(String motherString, String Command) {
  unsigned char Offset = 1;
  tem_Offset = Offset - 1;
  lenOfCommand = Command.length();
  posOfCommand = motherString.indexOf(Command);
  PosOfStartSymbol = motherString.indexOf(this->b_start_symbol, posOfCommand + lenOfCommand);
  if (posOfCommand < 0)
    return "";
  // Xu ly Dau Command
  if (posOfCommand > 0)
  {
    String tem__ = motherString.substring(posOfCommand - 1, posOfCommand);
    if ((tem__ != " ") && (tem__ != this->b_stop_symbol))
    {
      return "";
    }
  }

  // Xu ly cuoi Command
  unsigned int temPosOfLastCommand = posOfCommand + lenOfCommand;
  if (temPosOfLastCommand)
  {
    String tem__ = motherString.substring(temPosOfLastCommand, temPosOfLastCommand + 1);
    if ((tem__ != " ") && (tem__ != this->b_start_symbol))
    {
      return "";
    }
  }

  if (Offset == 0)
  {
    String tem__ = motherString.substring(posOfCommand, PosOfStartSymbol);
    if (tem__ == Command)
    {
      return tem__;
    }
    return "";
  }

  while (tem_Offset > 0)
  {
    tem_Offset--;
    PosOfStartSymbol = motherString.indexOf(this->b_start_symbol, PosOfStartSymbol + 1);
  }

  if (this->b_stop_symbol != "")
  {
    int PosOfStopSymbol = motherString.indexOf(this->b_stop_symbol, PosOfStartSymbol + 1);
    if (PosOfStopSymbol == -1)
    {
      return "";
    }
    else
      ;
    return motherString.substring(PosOfStartSymbol + 1, PosOfStopSymbol);
  }
  else
  {
    return motherString.substring(PosOfStartSymbol + 1);
  }
}
