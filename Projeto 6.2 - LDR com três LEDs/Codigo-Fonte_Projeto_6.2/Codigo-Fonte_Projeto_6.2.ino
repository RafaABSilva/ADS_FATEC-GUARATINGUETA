int Led1 = 8; //verde
int Led2 = 12; //amarelo
int Led3 = 13; //vermelho

void setup() {
 Serial.begin(9600);
 pinMode(Led1, OUTPUT);
 pinMode(Led2, OUTPUT);
 pinMode(Led3, OUTPUT);
}

void loop() {
int valor=analogRead(A0);
digitalWrite (Led1, LOW);
digitalWrite (Led2, LOW);
digitalWrite (Led3, LOW);
Serial.println(valor);

 if(valor>=400){
  //ambiente
  digitalWrite(Led1, HIGH);
  digitalWrite(Led2, LOW);
  digitalWrite(Led3, LOW);
  delay(1000);
 }else if(valor<=400 && valor>=200){
  //mediana
  digitalWrite(Led1, LOW);
  digitalWrite(Led2, HIGH);
  digitalWrite(Led3, LOW);
  delay(1000);
 }else if(valor<200){
  //sombra
  digitalWrite(Led3, HIGH);
  digitalWrite(Led1, LOW);
  digitalWrite(Led2, LOW);
  delay(1000);
 }
 


}

