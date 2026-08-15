#include <Arduino.h>
#include "ADCTouchSensor.h"

ADCTouchSensor pressure1(PA0, PA1, 50);
ADCTouchSensor pressure2(PA3, PA1, 50);

float Ref1 = 0, Ref2 = 0;
const unsigned int SAMPLES = 100; 

void setup() {
  Serial.begin(115200);           
  delay(2000); 

  analogReadResolution(12); 
  Ref1= pressure1.readRaw(300);
  Ref2 = pressure2.readRaw(300);
  
}

void loop() {
  unsigned int T1 = micros();
  float raw1 = pressure1.readRaw(SAMPLES);
  unsigned int T2 = micros();
  float raw2 = pressure2.readRaw(SAMPLES);
  unsigned int T3 = micros();
  unsigned int T_1 = T2 - T1;
  unsigned int T_2= T3 - T2;
  float value1 = raw1 - Ref1;
  float value2 = raw2 - Ref2;
  Serial.print(value1);
  Serial.print("  ");
  Serial.print(value2);
  Serial.print("  ");
  Serial.print(T_1);
  Serial.print("  ");
  Serial.println(T_2);
  delay(1000);
}