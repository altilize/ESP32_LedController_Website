#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "LED Controller";
const char* password = "senyumduludong";

// Inisialisasi WebServer pada port 80
WebServer server(80);

const int ledPin = 14;
bool blinkMode = false;

void handleTurnOn() {
  digitalWrite(ledPin, HIGH);
  blinkMode = false;
  server.sendHeader("Location", "/");
  server.send(303);
}

// Fungsi untuk mematikan LED
void handleTurnOff() {
  digitalWrite(ledPin, LOW);
  blinkMode = false;
  server.sendHeader("Location", "/");
  server.send(303);
}


void handleBlink() {
  blinkMode = true;
  server.sendHeader("Location", "/"); 
  server.send(303); 
}

void handleRoot() {
  String html = "<html><head>";
  html += "<style>";
  html += "body { font-family: Arial, sans-serif; background-color: #f4f4f4; text-align: center; padding: 20px; }";
  html += "h1 { color: #333; }";
  html += "button { font-size: 24px; padding: 30px 60px; margin: 10px; cursor: pointer; border-radius: 10px; border: none; }";
  html += ".on { background-color: #4CAF50; color: white; }";
  html += ".off { background-color: #f44336; color: white; }";
  html += ".blink { background-color: #ff9800; color: white; }";
  html += "button:hover { opacity: 0.8; }";
  html += "</style>";
  html += "</head><body>";
  html += "<h1>Pencet klo mau</h1>";
  
  html += "<a href='/turnon'><button class='on'>Turn ON</button></a><br><br>";

  html += "<a href='/turnoff'><button class='off'>Turn OFF</button></a><br><br>";

  html += "<a href='/blink'><button class='blink'>Jedag Jedug</button></a><br><br>";

  html += "</body></html>";
  server.send(200, "text/html", html);
}

void setup() {
  Serial.begin(115200);

  WiFi.softAP(ssid, password);
  Serial.println("Access Point Started");
  Serial.print("IP Address: ");
  Serial.println(WiFi.softAPIP());

  pinMode(ledPin, OUTPUT);

  server.on("/", handleRoot);
  server.on("/turnon", handleTurnOn);
  server.on("/turnoff", handleTurnOff);
  server.on("/blink", handleBlink);

  server.begin();
  Serial.println("Server started");
}

void loop() {
  server.handleClient();

  if (blinkMode) {
    digitalWrite(ledPin, HIGH);
    delay(300);
    digitalWrite(ledPin, LOW); 
    delay(300);
  }
}
