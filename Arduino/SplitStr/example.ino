#include "Baobon_SplitStr.h"
// //  Example Data
String data = "Name1=95,Name2=123,Name3=245,Name4=Example4,";
// //  Constructor
Baobon_SplitStr handingData("=",",");
// //  Value
String value1, value2, value3, value4;
String name1 = "Name1", name2 = "Name2", name3 = "Name3", name4 = "Name4";

void setup() {
  Serial.begin(115200);
  Serial.println("Start");
  value1 = handingData.splitStr(data,name1);
  value2 = handingData.splitStr(data,name2);
  value3 = handingData.splitStr(data,name3);
  value4 = handingData.splitStr(data,name4);
}

void loop() {
}
