int botao = 7, Led = 8, tipo;
bool desligado=false, ligado=true;

void setup() {
  pinMode(botao,INPUT);
  pinMode(Led,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int estado = digitalRead(botao);


if(ligado == true){  
    if(estado == HIGH){
    tipo = HIGH;
    desligado = true;
    ligado = false;
  }
}
else{
      if(estado == HIGH){
        tipo = LOW;
    desligado = false;
    ligado = true;
      }

}
    digitalWrite(Led, tipo);
}
