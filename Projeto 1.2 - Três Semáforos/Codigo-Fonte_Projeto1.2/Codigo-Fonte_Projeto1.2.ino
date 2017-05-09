void setup() {
  //Definindo as Portas e os parâmetros das mesmas

  //Semaforo 0 (Rua) [SR]
  pinMode(13, OUTPUT); // Vermelho
  pinMode(12, OUTPUT); // Amarelo
  pinMode(11, OUTPUT); // Verde

  //Semaforo 1 (Avenida) [S1A]
  pinMode(10, OUTPUT); // Vermelho
  pinMode(9, OUTPUT); // Amarelo
  pinMode(8, OUTPUT); // Verde
  
  //Semaforo 2 (Avenida) [S2A]
  pinMode(7, OUTPUT); // Vermelho
  pinMode(6, OUTPUT); // Amarelo
  pinMode(5, OUTPUT); // Verde
}

void loop() {
  //Estado: [SR]:Verde | [S12A]:Vermelho
  digitalWrite(11, HIGH); // [SR] -> Liga Verde
  digitalWrite(10, HIGH); // [S1A] -> Liga Vermelho
  digitalWrite(7, HIGH); // [S2A] -> Liga Vermelho

  //Estado: [SR]:Amarelo | [S12A]:Vermelho 
  delay(5000);
  digitalWrite(11, LOW); // [SR] -> Desliga Verde 
  digitalWrite(12, HIGH); // [SR] -> Liga Amarelo

  //Estado: [SR]:Vermelho | [S12A]:Verde
  delay(2000);
  digitalWrite(12, LOW); // [SR] -> Desliga Amarelo
  digitalWrite(10, LOW); // [S1A] -> Desliga Verde
  digitalWrite(7, LOW); // [S2A] -> Desliga Verde
  digitalWrite(13, HIGH); // [SR] -> Liga Vermelho
  digitalWrite(8, HIGH); // [S1A] -> Liga Verde
  digitalWrite(5, HIGH); // [S2A] -> Liga Verde
  
  //Estado: [SR]:Vermelho | [S12A]:Amarelo
  delay(5000);
  digitalWrite(8, LOW); // [S1A] -> Desliga Verde 
  digitalWrite(5, LOW); // [S2A] -> Desliga Verde
  digitalWrite(9, HIGH); // [S1A] -> Liga Amarelo
  digitalWrite(6, HIGH); // [S2A] -> Liga Amarelo

  //Estado: Limpano para o novo Ciclo
  delay(2000);
  digitalWrite(13, LOW); // [SR] -> Desliga Vermelho
  digitalWrite(9, LOW); // [S1A] -> Desliga Amarelo
  digitalWrite(6, LOW); // [S2A] -> Desliga Amarelo
}
  
