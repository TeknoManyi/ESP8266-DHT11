#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <DHT.h>

// DHT Sensör Ayarları
#define DHTPIN D2          // DHT11'in bağlı olduğu pin (GPIO4)
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Wi-Fi AP Ayarları
const char *ssid = "ESP8266_Sicaklik_Olcumu"; // Oluşturulacak ağ adı
const char *password = "12345678";        // Şifre (en az 8 karakter)

ESP8266WebServer server(80);

void handleRoot() {
  // Sensör verilerini oku
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Hata kontrolü
  if (isnan(h) || isnan(t)) {
    server.send(200, "text/plain", "Sensör okunamadı!");
    return;
  }

  // Basit HTML Arayüzü
  String html = "<html><head><meta charset='UTF-8'><meta http-equiv='refresh' content='5'>";
  html += "<title>ESP8266 DHT11 Panel</title>";
  html += "<style>body { font-family: Arial; text-align: center; background-color: #f4f4f4; }";
  html += "h1 { color: #333; } .data { font-size: 2rem; font-weight: bold; color: #007bff; }</style>";
  html += "</head><body>";
  html += "<h1>DHT11 Veri Paneli</h1>";
  html += "<p>Nem: <span class='data'> % " + String(h) + " </span></p>";
  html += "<p>Sıcaklık: <span class='data'>" + String(t) + " °C</span></p>";
  html += "<p>Veriler her 5 saniyede bir güncellenir.</p>";
  html += "</body></html>";

  server.send(200, "text/html", html);
}

void setup() {
  Serial.begin(115200);
  dht.begin();

  // Access Point Başlatma
  WiFi.softAP(ssid, password);
  
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP Adresi: ");
  Serial.println(myIP);

  // Web Sunucu Yönlendirmesi
  server.on("/", handleRoot);
  server.begin();
  Serial.println("HTTP sunucu baslatildi.");
}

void loop() {
  server.handleClient();
}
