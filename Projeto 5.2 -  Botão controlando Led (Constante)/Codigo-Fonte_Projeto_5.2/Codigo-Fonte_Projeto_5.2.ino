int botao = 7, Led = 8;
bool ligado=true;

void setup() {
  pinMode(botao,INPUT);
  pinMode(Led,OUTPUT);
}

void loop() {
  int estado = digitalRead(botao);

if(estado==HIGH)
  if(ligado==true){
    digitalWrite(Led,HIGH);
    ligado=false;
    delay(200);

  }else{
    digitalWrite(Led,LOW);
    ligado=true;
    delay(200); 
  }
}

