# 🚨 ESP32 Motion Alert System

Proyecto de detección de movimiento con *ESP32, que activa un **LED* y un *buzzer* al detectar movimiento mediante un sensor *PIR, y además envía una **alerta por Telegram* usando un bot.

## 📌 Características
- Detección de movimiento con sensor PIR.
- Activación de LED y buzzer como alarma local.
- Envío de notificación a Telegram mediante un bot.
- Conexión WiFi para comunicación con la API de Telegram.
- Código escrito en Arduino IDE.

## 🛠️ Hardware necesario
- ESP32
- Sensor PIR (HC-SR501 u otro compatible)
- Buzzer activo (3 pines)
- LED + resistencia (220Ω recomendada)
- Cables y protoboard

## 🔧 Conexiones
- *PIR*  
  - VCC → 5V (o 3.3V si tu módulo lo soporta)  
  - GND → GND  
  - OUT → GPIO 14  

- *LED*  
  - Ánodo (+) → GPIO 26 (con resistencia 220Ω)  
  - Cátodo (–) → GND  

- *Buzzer activo*  
  - VCC → 3.3V o 5V  
  - GND → GND  
  - SIG → GPIO 27  

## 📜 Código principal
El proyecto usa las librerías:
- WiFi.h
- WiFiClientSecure.h
- UniversalTelegramBot.h
- ArduinoJson.h

# ESP32 + Telegram + Google Sites

Este proyecto conecta un **ESP32** con un **bot de Telegram** para enviar y recibir mensajes, y luego publica los datos en **Google Sites** usando Google Sheets como backend.

---

## 🚀 Requisitos

- **Hardware**: ESP32
- **Software**:
  - Arduino IDE (o PlatformIO)
  - Librerías: `WiFi.h`, `WiFiClientSecure.h`, `UniversalTelegramBot`
- **Servicios**:
  - Bot de Telegram (token desde @BotFather)
  - Cuenta de Google (Sheets + Sites)

---

## ⚙️ Configuración del Bot de Telegram

1. Abre Telegram y busca `@BotFather`.
2. Ejecuta `/newbot` y sigue las instrucciones.
3. Copia el **token del bot** que te entrega.

---

## 📲 Código de Ejemplo (Arduino IDE)

```cpp
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>

const char* ssid = "TU_SSID";
const char* password = "TU_PASSWORD";
const char* botToken = "TOKEN_DEL_BOT";

WiFiClientSecure client;
UniversalTelegramBot bot(botToken, client);

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  client.setInsecure(); // evita problemas con certificados
}

void loop() {
  bot.sendMessage("TU_CHAT_ID", "Hola desde ESP32!");
  delay(10000);
}

Ejemplo de integración:

```cpp
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>

const char* ssid = "TU_SSID";
const char* password = "TU_PASSWORD";

#define BOTtoken "TU_TOKEN_BOT"
#define CHAT_ID "TU_CHAT_ID"

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

const int pirPin = 14;
const int ledPin = 26;
const int buzzerPin = 27;

void setup() {
  Serial.begin(115200);
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConectado a WiFi!");
  client.setInsecure();
}

void loop() {
  int estadoPIR = digitalRead(pirPin);

  if (estadoPIR == HIGH) {
    Serial.println("Movimiento detectado!");
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);

    bot.sendMessage(CHAT_ID, "🚨 Alerta: Movimiento detectado en el ESP32!", "");
    delay(5000); // evita spam de mensajes
  } else {
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
  }

  delay(100);
}
