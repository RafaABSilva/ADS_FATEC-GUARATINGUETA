int botao = 7, Led = 8;

void setup() {
  pinMode(botao,INPUT);
  pinMode(Led,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int estado = digitalRead(botao);

  if(estado == HIGH ){
    digitalWrite(Led,HIGH);
  }
  else{
    digitalWrite(Led,LOW);
  }

}
