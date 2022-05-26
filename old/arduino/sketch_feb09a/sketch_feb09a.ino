unsigned long time;
unsigned long timehours1;
unsigned long timehours2;


void setup(){
  Serial.begin(9600);
}
void loop(){
  time = millis();
  timehours1 = time/3600000;
  while(timehours1 != timehours2 && timehours1 >= 1) {
    Serial.println(timehours1);
    timehours1 = timehours2;
  }
}
