ESP8266 ile DHT11 Hava Durumu Paneli

Bu projede ESP8266 (NodeMCU) kullanarak bir Wi-Fi ağ noktası oluşturdum. DHT11 sensöründen aldığım sıcaklık ve nem verilerini, herhangi bir internete ihtiyaç duymadan, doğrudan cihazın oluşturduğu web sayfası üzerinden takip edebiliyorum.
# 🛠️ Nasıl Çalışır?

    ESP8266 güç aldığında "ESP8266_Hava_Durumu" adında bir Wi-Fi ağı açar.

    Telefon veya bilgisayardan bu ağa bağlanılır (Şifre: 12345678).

    Tarayıcıya 192.168.4.1 yazıldığında sensör verileri ekranda görünür.

    Sayfa her 5 saniyede bir kendini otomatik yeniler.

# 📌 Bağlantılar

    VCC: 3.3V

    GND: GND

    DATA: D2 (GPIO 4)

# 🔧 Gerekli Kütüphaneler

    DHT sensor library (Adafruit)

    Adafruit Unified Sensor

<img width="568" height="302" alt="resim" src="https://github.com/user-attachments/assets/c52d8153-7771-41b0-9d66-98a05833c039" />

![ESP8266-DHT11](https://github.com/user-attachments/assets/9c53f6c9-5f24-4db5-8720-4e70d4bccb79)

