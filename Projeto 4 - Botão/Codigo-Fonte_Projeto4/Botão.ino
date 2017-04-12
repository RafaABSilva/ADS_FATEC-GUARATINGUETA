int botao = 7;

void setup() {
  pinMode(botao,INPUT);
  Serial.begin(9600);
}

void loop() {
  int estado = digitalRead(botao);

  if(estado == HIGH ){
  Serial.println("pressionado");
  }
  else{
    Serial.println("não pressionado");
  }

}
