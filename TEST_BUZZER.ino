const int buzzerPin = 27; // SIG del buzzer activo

void setup() {
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(115200);
  Serial.println("Prueba buzzer iniciada...");
}

void loop() {
  digitalWrite(buzzerPin, HIGH); // Suena
  Serial.println("Buzzer encendido");
  delay(1000);

  digitalWrite(buzzerPin, LOW);  // Silencio
  Serial.println("Buzzer apagado");
  delay(1000);
}
