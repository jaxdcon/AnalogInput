#include <Arduino.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

String getTempratureCode(int temp) {
  String tempratureCode;
  if (temp < 10)
  {
    tempratureCode = "Cold!";
  }
  else if (temp <= 15)
  {
    tempratureCode = "Cool";
  }
  else if (temp <= 25)
  {
    tempratureCode = "Perfect";
  }
  else if (temp <= 30)
  {
    tempratureCode = "Warm";
  }
  else if (temp <= 35)
  {
    tempratureCode = "Hot";
  }
  else
  {
    tempratureCode = "Too Hot!";
  }
  return tempratureCode;
}

void loop() {
  // put your main code here, to run repeatedly:
  int iVal;
  float temp;
  
  iVal = analogRead(A0);
  temp = iVal * (50 / 1024.0);
  Serial.println("Digitized output of " + String(iVal) + " is equivalent to temprature input of " + String(temp) + " deg. C, which is " + String(getTempratureCode(temp)));

  delay(500);
}