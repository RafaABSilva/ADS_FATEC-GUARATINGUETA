void setup() {
  //Definindo as Portas e os parâmetros das mesmas
  pinMode(13, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  //Led Vermelho
  digitalWrite(13, HIGH);
  delay(5000);
  digitalWrite(13, LOW);

  //Led Amarelo
  digitalWrite(4, HIGH);
  delay(5000);
  digitalWrite(4, LOW);
  
  //Led Verde
  digitalWrite(7, HIGH);
  delay(2000);
  digitalWrite(7, LOW);
  }
