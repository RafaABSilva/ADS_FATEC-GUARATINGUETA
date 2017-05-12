int Sensor  = 13;

void setup() {
  Serial.begin(9600);
  pinMode(Sensor, INPUT);
}

void loop() {
  int acionamento = digitalRead(Sensor);

  if(acionamento == LOW){
    Serial.println("Obstáculo");
  }else{
    Serial.println("Passagem Livre");
  }
}
