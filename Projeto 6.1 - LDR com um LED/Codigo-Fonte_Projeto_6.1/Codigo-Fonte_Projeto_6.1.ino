int Led = 13;

void setup(){
  Serial.begin(9600);
  pinMode(Led, OUTPUT);
}

void loop(){
  int valor=analogRead(A0);
  digitalWrite (Led, LOW);
  Serial.println(valor);

 if(valor<400){
    digitalWrite(Led, HIGH);
    delay(1000);
 }else{
    digitalWrite(Led, LOW);
    delay(1000);
 }
}

