//CONSTANTS
#define DHT22 4
#define BUZZER 2
#define TEMP_MAX 30
#define TEMP_MIN 18
#define HUMI_MAX 60
#define HUMI_MIN 30
#define TIMEOUT 900000
#define TIMEOUT_MQTT 60000

//WIFI
#define WIFISSID "SSID"//Coloque seu SSID de WiFi aqui
#define WIFIPASSWORD "PASSWORD"//Coloque seu password de WiFi aqui
//MQTT
#define SERVER "IP_ADDRESS"//IP do Servidor MQTT (broker)
#define DEVICE_ID "ID_SENSOR" //ID do dispositivo (Device id, também chamado de client name)
#define TOKEN ""//"xxxxxx" //Coloque seu TOKEN do Ubidots aqui
#define PASSWORD ""
//Porta padrão
#define PORT 1883
//Tópico aonde serão feitos os publish
#define TOPIC "smt"
