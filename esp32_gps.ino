#include <WiFi.h>  // Biblioteca para conexão Wi-Fi
#include <HTTPClient.h>  // Biblioteca para fazer requisições HTTP
#include <TinyGPS++.h>  // Biblioteca para comunicação com o GPS
#include <DHT.h>  // Biblioteca para o sensor DHT11

// Configuração do Wi-Fi
const char* ssid = "CIT_Alunos";  // Nome da rede Wi-Fi
const char* password = "alunos@2024"; // Senha do Wi-Fi
const char* server = "https://kindly-translucent-crocodile.glitch.me/"; // URL do servidor

// Configuração do GPS
#define RXD2 16  // Pino RX do ESP32 conectado ao TX do GPS
#define TXD2 17  // Pino TX do ESP32 conectado ao RX do GPS
#define GPS_BAUD 9600  // Taxa de comunicação do GPS
TinyGPSPlus gps;  // Instância do objeto GPS
HardwareSerial gpsSerial(2);  // Configuração da porta serial 2 para comunicação com o GPS

// Configuração do DHT11
#define DHTPIN 4  // Pino de dados do DHT11
#define DHTTYPE DHT11  // Tipo de sensor DHT (DHT11)
DHT dht(DHTPIN, DHTTYPE);  // Instância do sensor DHT11

void setup() {
    Serial.begin(115200);  // Inicia a comunicação serial para monitoramento
    gpsSerial.begin(GPS_BAUD, SERIAL_8N1, RXD2, TXD2);  // Inicia a comunicação com o módulo GPS
    dht.begin();  // Inicia o sensor DHT11
    Serial.println("Serial 2 do GPS iniciada");

    // Conecta-se ao Wi-Fi
    WiFi.begin(ssid, password);
    Serial.print("Conectando ao Wi-Fi");

    // Aguarda a conexão com o Wi-Fi
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nWiFi Conectado!");
}

void loop() {
    unsigned long start = millis();  // Marca o tempo inicial
    bool newData = false;  // Variável para verificar se há novos dados do GPS

    // Lê os dados do GPS por 1 segundo
    while (millis() - start < 1000) {
        while (gpsSerial.available() > 0) {  // Se houver dados disponíveis na serial do GPS
            if (gps.encode(gpsSerial.read())) {  // Decodifica os dados recebidos
                newData = true;  // Marca que novos dados foram recebidos
            }
        }
    }

  // Leitura da temperatura e umidade do DHT11
  float temp = dht.readTemperature();  // Lê a temperatura em Celsius
  float humidity = dht.readHumidity();  // Lê a umidade relativa
      
  // Exibe as leituras do DHT no monitor serial
  Serial.print("Temperatura: "); 
  Serial.println(temp);  // Imprime a temperatura no monitor serial
  Serial.print("Umidade: "); 
  Serial.println(humidity);  // Imprime a umidade no monitor serial
  
    // Se houver novos dados e a localização for válida
    if (newData && gps.location.isValid()) {
        float lat = gps.location.lat();  // Obtém a latitude
        float lon = gps.location.lng();  // Obtém a longitude

        // Exibe a localização no monitor serial
        Serial.print("Latitude: "); Serial.println(lat, 6);
        Serial.print("Longitude: "); Serial.println(lon, 6);

        // Verifica se a leitura do DHT11 foi bem-sucedida
        if (isnan(temp) || isnan(humidity)) {
            Serial.println("Falha ao ler do sensor DHT!");
            return;
        }

        // Verifica se o Wi-Fi está conectado antes de enviar os dados
        if (WiFi.status() == WL_CONNECTED) {
            HTTPClient http;  // Cria um objeto HTTP
            String url = String(server) + "/update?lat=" + String(lat, 6) + "&lon=" + String(lon, 6) +
                         "&temp=" + String(temp, 2) + "&humidity=" + String(humidity, 2);  
            // Monta a URL com os parâmetros de latitude, longitude, temperatura e umidade

            http.begin(url);  // Inicia a requisição HTTP
            int httpCode = http.GET();  // Faz a requisição GET ao servidor
            http.end();  // Encerra a conexão HTTP

            // Verifica se a requisição foi bem-sucedida
            if (httpCode > 0) {
                Serial.println("Dados enviados com sucesso!");
            } else {
                Serial.println("Falha ao enviar os dados!");
            }
        } else {
            // Se o Wi-Fi estiver desconectado, tenta reconectar
            Serial.println("Wi-Fi desconectado, tentando reconectar...");
            WiFi.begin(ssid, password);
        }
    } else {
        Serial.println("Aguardando coordenadas válidas do GPS...");
    }

    delay(5000); // Aguarda 5 segundos antes de enviar novamente
}
