#include <Ultrasonic.h>

#define TRIGGER_PIN  12
#define ECHO_PIN     11

int buzzer = 13;
int frequencia = 0; 
int tempo=10;

Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);

void setup(){
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
}

void loop(){
  float cmMsec;
  long microsec = ultrasonic.timing();

  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  Serial.print("MS: ");
  Serial.print(microsec);
  Serial.print(", CM: ");
  Serial.print(cmMsec);
  Serial.print("\n");

  if(cmMsec<=15){
      frequencia=180;
      delay(150);
      tone(buzzer,frequencia,cmMsec);
  }else if (cmMsec<=30){
      frequencia=2500;
      delay(250);
      tone(buzzer,frequencia,cmMsec);
  }
}
  
