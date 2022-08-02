#include <LiquidCrystal.h>
unsigned long time;
int seconds;
int minutes;
int hours;
int a = 1;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
lcd.begin(16, 2);

lcd.setCursor(2,0);
lcd.print(":");
lcd.setCursor(5,0);
lcd.print(":");
}

void loop() {
  
  time = millis();
  
  seconds = time/1000;
  minutes = time/60000;
  hours = time/3600000;

  if (minutes >= 1) { seconds = seconds - minutes*60 + 1 ; }
  if (hours >= 1) { minutes = minutes - hours*60 + 1 ; }
   
  lcd.setCursor(6, 0);
  if (seconds < 10) {
    lcd.print("0");
    lcd.print(seconds);
  }
  else{
  lcd.print(seconds);
  }

  lcd.setCursor(3, 0);
  if (minutes < 1 ) { lcd.print("00"); }
  if (minutes >= 1 ) {    
    if (minutes <10) {
      lcd.print("0");
      lcd.print(minutes);
    }
    else {
    lcd.print(minutes);
    }
  }

  lcd.setCursor(0,0);
  if (hours < 1) { lcd.print("00"); }
  if (hours >= 1) {
     if(hours < 10) {
      lcd.print("0");
      lcd.print(hours);
    }
    else {
    lcd.print(hours);
    }
  }

}





/*if (minutes >= 60) { minutes = minutes - 59; }
  if (minutes >= 120) { minutes = minutes - 119; }
  if (minutes >= 180) { minutes = minutes - 179; }
  if (minutes >= 240) { minutes = minutes - 239; }
  if (minutes >= 300) { minutes = minutes - 299; }
  if (minutes >= 360) { minutes = minutes - 359; }
  if (minutes >= 420) { minutes = minutes - 419; }
  if (minutes >= 480) { minutes = minutes - 479; }
  if (minutes >= 540) { minutes = minutes - 539; }
  if (minutes >= 600) { minutes = minutes - 599; }
  if (minutes >= 660) { minutes = minutes - 659; }
  if (minutes >= 720) { minutes = minutes - 719; }
  if (minutes >= 780) { minutes = minutes - 779; }
  if (minutes >= 840) { minutes = minutes - 839; }
  if (minutes >= 900) { minutes = minutes - 899; }
  if (minutes >= 960) { minutes = minutes - 959; }
  if (minutes >= 1020) { minutes = minutes - 1019; }
  if (minutes >= 1080) { minutes = minutes - 1079; }
  if (minutes >= 1140) { minutes = minutes - 1139; } 
  if (minutes >= 1200) { minutes = minutes - 1199; }*/
