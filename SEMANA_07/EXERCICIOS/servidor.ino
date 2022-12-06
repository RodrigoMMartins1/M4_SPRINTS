#include <WiFi.h>
#include <WebServer.h>

/* Put your SSID & Password */
const char* ssid = "ESP32";      // Enter SSID here
const char* password = "rodrigointeli";  //Enter Password here

/* Put IP Address details */
IPAddress local_ip(192, 168, 0, 72 ); // Colocar um IP para seu ESP32
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

WebServer server(80); //Porta do servidor

int led1 = 39;
bool status;
status = LOW;



void setup() {
  Serial.begin(115200);
  pinMode(led1, OUTPUT);

  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  delay(100);

  server.on("/", start); //Função para dar um request do começo
  server.on("/win", win); // Função para dar request na vitoria

  server.begin();
  Serial.println("HTTP server started");
}
void loop() {
  server.handleClient();
  if (status) {
    digitalWrite(led1, HIGH);
  } else {
    digitalWrite(led1, LOW);
  }
}


void start() { // Inicia o jogo e a resposta do servidor
  status = LOW;
  Serial.println("O jogo começou!");
  server.send(200, "text/html"); //Envia uma resosta HTTP
}

void win() { // Se ganhar a luz acende 
  status = HIGH;
  Serial.println("O jogo acabou!");
  server.send(200, "text/html"); // Envia uma resposta HTTP
  
}


