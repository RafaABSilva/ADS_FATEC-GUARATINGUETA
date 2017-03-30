int buzzer =10;
int led =13;

void setup() {
    pinMode(buzzer,OUTPUT);
    pinMode(led, OUTPUT); 

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(buzzer,HIGH); //S on
  digitalWrite(led, HIGH);
  delay(500);

  digitalWrite(buzzer,LOW); //S off
  digitalWrite(led, LOW);
  delay(500);
  //1
  digitalWrite(buzzer,HIGH); //S on
  digitalWrite(led, HIGH);
  delay(500);

  digitalWrite(buzzer,LOW); //S off
  digitalWrite(led, LOW);
  delay(500);
  //2
  digitalWrite(buzzer,HIGH); //S on
  digitalWrite(led, HIGH);
  delay(500);

  digitalWrite(buzzer,LOW); //S off
  digitalWrite(led, LOW);
  delay(500);
  //3
  digitalWrite(buzzer, HIGH); //O on
  digitalWrite(led, HIGH);
  delay(250);
  //1
  digitalWrite(buzzer, LOW); //O off
  digitalWrite(led, LOW);
  delay(250);
  //2
  digitalWrite(buzzer, HIGH); //O on
  digitalWrite(led, HIGH);
  delay(250);
  //3
  digitalWrite(buzzer, LOW); //O off
  digitalWrite(led, LOW);
  delay(250);

  digitalWrite(buzzer, HIGH); // O on
  digitalWrite(led, HIGH);
  delay(250);

  digitalWrite(buzzer, LOW); //O off
  digitalWrite(led, LOW);
  delay(250);

  digitalWrite(buzzer,HIGH); //S on
  digitalWrite(led, HIGH);
  delay(500);

  digitalWrite(buzzer,LOW); //S off
  digitalWrite(led, LOW);
  delay(500);
  
  digitalWrite(buzzer,HIGH); //S on
  digitalWrite(led, HIGH);
  delay(500);

  digitalWrite(buzzer,LOW); //S off
  digitalWrite(led, LOW);
  delay(500);

  digitalWrite(buzzer,HIGH); //S on
  digitalWrite(led, HIGH);
  delay(500);

  digitalWrite(buzzer,LOW); //S off
  digitalWrite(led, LOW);
  delay(500);
  
  
  
  

  
}
