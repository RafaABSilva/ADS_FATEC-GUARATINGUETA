void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}
long tempo=millis();bool controle=false;
void loop() {
  // put your main code here, to run repeatedly:
  if(millis()-tempo>5000){
    if(controle==false){
    digitalWrite(13, HIGH);
    controle=true;
    }
     else{
          digitalWrite(13, LOW);
    controle=false;
     }
   
    tempo=millis();
  }
}
