void setup() {
    pinMode(13, OUTPUT); //Definindo o Tipo da Porta
    Serial.begin(9600); //Definido a Velocidade da Porta Serial
}

long tempo=millis(); //Tempo Inicial (Starter)
bool controle=false; //Definindo a variável de Controle 

void loop() {

  if(millis()-tempo>5000){
      
      if(controle==false){
          digitalWrite(13, HIGH); //Ligando o Led
          controle=true; //Mudança de valor da variável de Controle
      }else{
          digitalWrite(13, LOW); //Desligando o Led
          controle=false; //Mudança de valor da variável de Controle
      } 
      tempo=millis(); //Atualização do Tempo Inicial
  }
}
