void setup() {
 Serial.begin(9600);  // put your setup code here, to run once:

}
long tempo=millis();

void loop() {
 if(millis()-tempo >5000){ // put your main code here, to run repeatedly:
  Serial.println("Opa, passou 5 segundos");
  tempo=millis();
 }
}
