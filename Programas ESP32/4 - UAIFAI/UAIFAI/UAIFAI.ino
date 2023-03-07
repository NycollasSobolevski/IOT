// Config WIFI
#include <WiFi.h>
//Config DHT
#include <DHT.h>
#define DHTTYPE DHT11
#define DHTPORT 26

#define WIFI_SSID "Vivo-Internet-BF17"
#define WIFI_PASSWORD "78814222"

// Integrando o firebase
#include <FirebaseESP32.h>
#define FIREBASE_HOST "esp32-proj-a91fe-default-rtdb.firebaseio.com/"
#define FIREBASEAUTH "6v4IeegkNP2ZAjZ5lry3vL8sZqYa1jff0Yat0QNR"
FirebaseData firebaseData;
FirebaseJson json;


DHT dht(DHTPORT, DHTTYPE); // Variavel tipo DHT indicando a porta e o tipo

void setup() {
  Serial.begin(9600);
  dht.begin();

  // Configurando WIFI
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while(WiFi.status() != WL_CONNECTED){ // Enquanto nao estiver conectado printa um '.'
    Serial.print(".");
    delay(300);
  }
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());       // Pegando info IP

  //Firebase
  Firebase.begin(FIREBASE_HOST, FIREBASEAUTH);
  Firebase.reconnectWiFi(true);
  Firebase.setReadTimeout(firebaseData, 1000* 60);
  Firebase.setwriteSizeLimit(firebaseData, "tiny");
}

void loop() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();

  Serial.print("Temp: ");
  Serial.println(t);
  Serial.print("Humid: ");
  Serial.println(h);

  json.set("/temperatura", t);
  json.set("/umidade", h);
  Firebase.updateNode(firebaseData, "/Nycollas/Sensor", json);
  
  delay(500);
}
