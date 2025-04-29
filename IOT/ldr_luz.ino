#include <WiFi.h>
#include <WiFiMulti.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

const char* rede_wifi = "AAPM"; // Nome da rede Wi-Fi
const char* senha_wifi = "";    // Senha da rede (vazia nesse caso)
unsigned long zero = 0;

WiFiMulti rede;

int pinoLDR = A0;
int valorLuz = 0;
String rotaLuz = "";

void conectarWiFi() {
  rede.addAP(rede_wifi, senha_wifi);
  Serial.print("Conectando ao WiFi");

  while (rede.run() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("\nWiFi Conectado!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
  Serial.print("MAC: ");
  Serial.println(WiFi.macAddress());
}

String requisitarDados(String rota) {
  HTTPClient http;
  String url = "https://sensor_luz.onrender/lampada/" + rotaLuz;
  http.begin(url);
  
  int httpResponCode = http.GET();
  if (httpResponCode == 200) {
    String respostaJson = http.getString();
    return respostaJson;
  } else {
    Serial.print("Erro HTTP: ");
    Serial.println(httpResponCode);
    return "";
  }
}

bool processarJSON(String json, DynamicJsonDocument& resultado) {
  DeserializationError error = deserializeJson(resultado, json);
  if (error) {
    Serial.print("Erro no JSON: ");
    Serial.println(error.c_str());
    return false;
  }
  return true;
}

void setup() {
  Serial.begin(115200);
  conectarWiFi();
}

void loop() {
  valorLuz = analogRead(pinoLDR);
  
  // Define a rota com base no valor do LDR
  if (valorLuz > 500) {
    rotaLuz = "acesa";
  } else {
    rotaLuz = "apagada";
  }

  // Faz requisição a cada 5 segundos
  if (millis() - zero > 5000) {
    Serial.print("LDR: ");
    Serial.print(valorLuz);
    Serial.print(" - Estado da lâmpada: ");
    Serial.println(estadoLuz);

    String jsonRecebido = requisitarDados(estadoLuz);
    DynamicJsonDocument resultado(1024);

    zero = millis();
  }

  delay(1000);
}
