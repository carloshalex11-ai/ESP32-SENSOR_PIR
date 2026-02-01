const int ledPin = 26; // LED con resistencia

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
  Serial.println("Prueba LED iniciada...");
}

void loop() {
  digitalWrite(ledPin, HIGH); // Encender LED
  Serial.println("LED encendido");
  delay(1000);

  digitalWrite(ledPin, LOW);  // Apagar LED
  Serial.println("LED apagado");
  delay(1000);
}
