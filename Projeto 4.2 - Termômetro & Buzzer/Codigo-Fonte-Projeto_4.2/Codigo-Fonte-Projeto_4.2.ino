#include "DHT.h"
#define DHTPIN 2 
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);

float h = dht.readHumidity();
float t = dht.readTemperature();
int buzzer = 13;
int controle;

void setup() {
  Serial.begin(9600);
  Serial.println("DHT Test!");
  dht.begin();
  pinMode(buzzer, OUTPUT);
}

void loop() {
  h = dht.readHumidity();
  t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Falha ao ler o Sensor DHT!");
    return;
  }

  if(t >= 30){
      digitalWrite(buzzer,HIGH);
      Serial.print("Humidity: ");
      Serial.print(h);
      Serial.print(" %\t");
      Serial.print("Temperature: ");
      Serial.print(t);
      Serial.print(" *C \n");
      
  }else if(t <= 20){
      digitalWrite(buzzer,HIGH);  
      delay(250);
      digitalWrite(buzzer,LOW);
      delay(250);
      Serial.print("Humidity: ");
      Serial.print(h);
      Serial.print(" %\t");
      Serial.print("Temperature: ");
      Serial.print(t);
      Serial.print(" *C \n");
  }  
}
