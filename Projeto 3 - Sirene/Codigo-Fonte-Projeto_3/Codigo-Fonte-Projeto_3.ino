//Declaração de Variáveis
int t=10;
int f=0;
int porta=10;

void setup() {
  pinMode(porta, OUTPUT); //Definindo o tipo da porta
}

void loop() {
  for (f=150; f<1800; f++){
    tone(porta,f,t); //Definindo o Tom (Porta, Frequência, Tempo)
    delay(1);
  }
  
  for (f=1800; f>150; f--){
    tone(porta,f,t); //Definindo o Tom (Porta, Frequência, Tempo)
    delay(1);
  }
  
}
