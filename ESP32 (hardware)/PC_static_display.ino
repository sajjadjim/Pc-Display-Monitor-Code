#include <LiquidCrystal_I2C.h>
//#include <string> //It maybe be need to use, IDK
LiquidCrystal_I2C lcd(0x27,16,2); //It may not be 0x27
int cpuTemp  = 0;
int cpuUsage = 0;
int gpuTemp  = 0;
int gpuUsage = 0;
String staticData = "";

void setup() {
  Serial.begin(112500); //there may be other buad rate
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Hello World");
  delay(1000);
}

void loop() {
  if (Serial.available() > 0){
    staticData = Serial.readString();
    cpuTemp = staticData.substring(1,4).toInt();
    cpuUsage = staticData.substring(5,8).toInt();
    gpuTemp = staticData.substring(9,12).toInt();
    gpuUsage = staticData.substring(13,16).toInt();
    if (cpuTemp >= 0 && cpuUsage >= 0 && gpuTemp >= 0 && gpuUsage >= 0){
      displayStatic();
    }else {
      displayError(1);
    }
  }
  delay(1);
}

void displayError(int code){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Error TwT");
  lcd.setCursor(0,1);
  switch (code){
    case 1:{
      lcd.print("No Data");
    }
  }
}

void displayStatic(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("CPU:");
  lcd.setCursor(8-checkNumUnit(cpuTemp),0);          //0123456789012345
  lcd.print(cpuTemp);                                //CPU: 100.C 100%
  lcd.print("\xDF");
  lcd.print("C ");  
  lcd.setCursor(14-checkNumUnit(cpuUsage),0);
  lcd.print(cpuUsage);
  lcd.print("%");
  lcd.setCursor(0,1);
  lcd.print("GPU:");
  lcd.setCursor(8-checkNumUnit(gpuTemp),1);          //0123456789012345
  lcd.print(gpuTemp);                                //GPU: 100.C 100%
  lcd.print("\xDF");
  lcd.print("C ");
  lcd.setCursor(14-checkNumUnit(gpuUsage),1);
  lcd.print(gpuUsage);
  lcd.print("%");
}

int checkNumUnit(int num){
  int temp = num;
  int numUnit = 1;
  while(temp >= 10){
    temp /= 10;
    numUnit++;
  }
  return numUnit;
}
