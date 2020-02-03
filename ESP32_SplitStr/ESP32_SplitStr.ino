#include "Gen_SplitStr.h"
//  Example Data
String data = "Name1=95,Name2=123,Name3=245,Name4=Example4,";
//  Constructor
Gen_SplitStr handingData;
//  Value
String value1, value2, value3, value4;
String name1 = "Name1", name2 = "Name2", name3 = "Name3", name4 = "Name4";
String head = "=";
String last = ",";
void setup() {
  Serial.begin(115200);
  Serial.println("Start");
  value1 = handingData.splitStr(data,name1,head,last);
  value2 = handingData.splitStr(data,name2,head,last);
  value3 = handingData.splitStr(data,name3,head,last);
  value4 = handingData.splitStr(data,name4,head,last);

  //Print
  Serial.println(value1 + "--" + value2 + "--" + value3 + "--" + value4);
}

void loop() {
}
