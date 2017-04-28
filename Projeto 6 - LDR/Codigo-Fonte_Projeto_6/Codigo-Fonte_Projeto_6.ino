void setup() {
  Serial.begin(9600);
}

void loop() {
  int valor=analogRead(A0);
  Serial.print("Luz: ");
  Serial.print(valor);
  Serial.print("\n");
  delay(100);
}

