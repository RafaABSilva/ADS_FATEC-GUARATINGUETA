void setup() {
  //Definindo as Portas e os parâmetros das mesmas
  pinMode(13, OUTPUT); // Vermelho
  pinMode(7, OUTPUT); // Amarelo
  pinMode(4, OUTPUT); // Verde
}

void loop() {
  //Led Vermelho
  digitalWrite(13, HIGH); // Liga Vermelho
  delay(5000);
  digitalWrite(13, LOW); // Desliga Vermelho
  
  //Led Amarelo
  digitalWrite(7, HIGH); // Liga Amarelo
  delay(2000);
  digitalWrite(7, LOW); // Desliga Amarelo

  //Led Verde
  digitalWrite(4, HIGH); // Liga Verde
  delay(5000);
  digitalWrite(4, LOW); // Desliga Verde
}
