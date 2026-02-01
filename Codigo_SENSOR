#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>

// Datos de tu red WiFi
const char* ssid = "Charlee-Wifi";
const char* password = "carloshc2001";

// Token del bot de Telegram (el que te dio BotFather)
#define BOTtoken "8494932871:AAF5qKMqe-iArNr_x1RsaLZtFy3xGDaxBKA"

// Tu chat ID (el número que obtuviste con getUpdates)
#define CHAT_ID "5601713160"   // <-- reemplaza con tu chat_id real

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

// Pines
const int pirPin = 14;
const int ledPin = 26;
const int buzzerPin = 18;

void setup() {
  Serial.begin(115200);

  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  // Conexión WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConectado a WiFi!");

  // Configurar cliente seguro
  client.setInsecure(); // evita problemas con certificados SSL
}

void loop() {
  int estadoPIR = digitalRead(pirPin);

  if (estadoPIR == HIGH) {
    Serial.println("Movimiento detectado!");
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, LOW);

    // Enviar alerta por Telegram
    bot.sendMessage(CHAT_ID, "🚨 Alerta: Movimiento detectado en el ESP32!", "");
    
    delay(2000); // espera 5 segundos antes de permitir otro aviso
  } else {
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, HIGH);
  }

  delay(100);
}
