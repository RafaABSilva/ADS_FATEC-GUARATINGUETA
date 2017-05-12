int PIR = 13;

void setup() {
  Serial.begin(9600);
  pinMode(PIR, INPUT);
}

void loop() {
  int acionamento = digitalRead(PIR);
  
  if(acionamento== HIGH){
    Serial.println("Ladrão!!");
  }else{
    Serial.println("Ninguém");
  }
}
