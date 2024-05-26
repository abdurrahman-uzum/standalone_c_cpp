#include "PinLayouts.h"
#include "arduino/avr/pgmspace.h"
#include "HX711_ADC.h"


#define baudRate 115200
#define interval 10
#define tempCons 10       // 10mV/deg
#define alfa 0.999

// Load Cell Calibration Values
#define calValue_1 43.0
#define calValue_2 43.0
#define calValue_3 43.0
#define calValue_4 43.0

// Timer
unsigned long previousMillis = 0;

double intTempRaw = 0.0, intTemp = 0.0;

// Load Cell Parameters
HX711_ADC LoadCell_1(lc1DoutPin, lc1SckPin);
HX711_ADC LoadCell_2(lc2DoutPin, lc2SckPin);
HX711_ADC LoadCell_3(lc3DoutPin, lc3SckPin);
HX711_ADC LoadCell_4(lc4DoutPin, lc4SckPin);

double w1 = 0.0, w2 = 0.0, w3 = 0.0, w4 = 0.0, totalW = 0.0;
long stabilisingTime = 2000;
int loadCellStabilisingCount = 0;        // first 500 count, load cell values will be 0 because of prevent to exeed max load limit
bool isloadCellStabilisingCount = true;  // if true, then count (it is not required to continue counting if loadCellStabilisingCount exeed its limit)
byte loadcell_1_rdy = 0, loadcell_2_rdy = 0, loadcell_3_rdy = 0, loadcell_4_rdy = 0;

bool errorDetected = false;
double errorThreshold = 10.0;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(internalTempSensPin, INPUT);

  digitalWrite(ledPin, LOW);
  digitalWrite(internalTempSensPin, LOW);

  // Load Cell Init
  LoadCell_1.begin();
  LoadCell_2.begin();
  LoadCell_3.begin();
  LoadCell_4.begin();

  while ((loadcell_1_rdy + loadcell_2_rdy + loadcell_3_rdy + loadcell_4_rdy) < 2.5)
  {
    if (!loadcell_1_rdy) loadcell_1_rdy = LoadCell_1.startMultiple(stabilisingTime);
    if (!loadcell_2_rdy) loadcell_2_rdy = LoadCell_2.startMultiple(stabilisingTime);
    if (!loadcell_3_rdy) loadcell_3_rdy = LoadCell_3.startMultiple(stabilisingTime);
    if (!loadcell_4_rdy) loadcell_4_rdy = LoadCell_4.startMultiple(stabilisingTime);
  }

  // Load Cell Calibration
  LoadCell_1.setCalFactor(calValue_1);
  LoadCell_2.setCalFactor(calValue_2);
  LoadCell_3.setCalFactor(calValue_3);
  LoadCell_4.setCalFactor(calValue_4);

  Serial.begin(baudRate);
}

void loop()
{
  getInternalTemp();
  getWeights();

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval)
  {
    previousMillis = currentMillis;

    serialWrite();
    ledBlink();
  }

  if (Serial.available())
  {
    char temp = Serial.read();
    if (temp == '0')
    {
       LoadCell_1.tare();
       LoadCell_2.tare();
       LoadCell_3.tare();
       LoadCell_4.tare();
    }
  }
}

void getInternalTemp()
{
  intTempRaw = ((analogRead(internalTempSensPin) * 3300.0 / 1023.0) - 500) / tempCons;
  intTemp = intTemp * alfa + intTempRaw * (1.0 - alfa);
}

void ledBlink()
{
  if (digitalRead(ledPin)) digitalWrite(ledPin, LOW);
  else digitalWrite(ledPin, HIGH);
}

void getWeights()
{
  LoadCell_1.update();
  LoadCell_2.update();
  LoadCell_3.update();
  LoadCell_4.update();

  w1 = LoadCell_1.getData() / 1000.0; // kg
  // if (w1 < 0.05) w1 = 0.0;
  if (w1 >= 49.9) w1 = 49.9;
  w2 = LoadCell_2.getData() / 1000.0; // kg
  // if (w2 < 0.05) w2 = 0.0;
  if (w2 >= 49.9) w2 = 49.9;
  w3 = LoadCell_3.getData() / 1000.0; // kg
  // if (w3 < 0.05) w3 = 0.0;
  if (w3 >= 49.9) w3 = 49.9;
  w4 = LoadCell_4.getData() / 1000.0; // kg
  // if (w4 < 0.05) w4 = 0.0;
  if (w4 >= 49.9) w4 = 49.9;

  // only count first 250 count in order to wait load cell calibration, after 250 count, stop counting
  if (isloadCellStabilisingCount) loadCellStabilisingCount++;
  if (loadCellStabilisingCount <= 250)
  {
    w1 = 0.0;
    w2 = 0.0;
    w3 = 0.0;
    w4 = 0.0;
  }
  else isloadCellStabilisingCount = false;

  if (w1 > errorThreshold) errorDetected = true;
  else if (w2 > errorThreshold) errorDetected = true;
  else if (w3 > errorThreshold) errorDetected = true;
  else if (w4 > errorThreshold) errorDetected = true;

  totalW = w1 + w2 + w3 + w4;
  if (totalW > 4 * errorThreshold) errorDetected = true;
}

void serialWrite()
{

  if (abs(w1 + w2 + w3 + w4) <= .5)
  {
    w1 = w2 = w3 = w4 = 0;
  }
  
  Serial.print(w4, 3);
  Serial.print(" ");
  Serial.print(w2, 3);
  Serial.print(" ");
  Serial.print(w1, 3);
  Serial.print(" ");
  Serial.println(w3, 3);
  
  
  /*
  Serial.print("Int Temp, [C]: ");
  Serial.print(intTemp);
  Serial.print(" Load Cell1, [kg]: ");
  if (w1 < 10.0) Serial.print("0");
  Serial.print(w1);
  Serial.print(" Load Cell2, [kg]: ");
  if (w2 < 10.0) Serial.print("0");
  Serial.print(w2);
  Serial.print(" Load Cell3, [kg]: ");
  if (w3 < 10.0) Serial.print("0");
  Serial.print(w3);
  Serial.print(" Load Cell4, [kg]: ");
  if (w4 < 10.0) Serial.print("0");
  Serial.print(w4);
  Serial.print(" Total Weight, [kg]: ");
  if (totalW < 10.0) Serial.print("00");
  else if (totalW >= 10.0 && totalW < 100.0) Serial.print("0");
  Serial.print(totalW);
  Serial.print(" ERROR STATUS: ");
  Serial.println(errorDetected);
  */

}
