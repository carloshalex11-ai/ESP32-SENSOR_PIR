const int pirPin = 14; // OUT del PIR

void setup() {
  Serial.begin(115200);
  pinMode(pirPin, INPUT);
  Serial.println("Prueba PIR iniciada. Esperando detección...");
}

void loop() {
  int estadoPIR = digitalRead(pirPin);

  if (estadoPIR == HIGH) {
    Serial.println("Movimiento detectado!");
  } else {
    Serial.println("Sin movimiento...");
  }

  delay(500);
}
