int t=10;
int f=0;
int P=10;
void setup() {
  pinMode(P, OUTPUT);

}

void loop() {
  for (f=150; f<1800; f++){
    tone(P,f,t);
    delay(1);
  }
  
  for (f=1800; f>150; f--){
    tone(P,f,t);
    delay(1);
  }
}
