#include <LiquidCrystal.h>
unsigned long time;
int seconds;
int seconds1;
int minutes;
int hours;
int a = 0;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
lcd.begin(16, 2);
}

void loop() {
  
  time = millis();
  seconds = time/1000;
  minutes = seconds/60;
  hours = minutes/60;

  if (seconds != 0 && seconds % 60 == 0 ) {
    a++;
  }
  seconds1 = seconds - 60*a;

  lcd.setCursor(6, 0);
  if (seconds1 < 10) {
    lcd.print("0");
    lcd.print(seconds1);
  }
  else{
  lcd.print(seconds1);
  }

  if (minutes >= 1 ) {
    lcd.setCursor(3, 0);
    if (minutes <10) {
      lcd.print("0");
      lcd.print(minutes);
    }
    else {
    lcd.print(minutes);
    }
  }
  if (hours >= 1) {
    lcd.setCursor(0,0);
    if(hours < 10) {
      lcd.print("0");
      lcd.print(hours);
    }
    else {
    lcd.print(hours);
    }
  }

}
