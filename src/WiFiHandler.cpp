#include "WiFiHandler.h"
#include <Arduino.h>

WiFiHandler::WiFiHandler(const char* ssid, const char* password)
    : ssid(ssid), password(password) {}

void WiFiHandler::connect() {
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    Serial.print("Connecting to WiFi ..");
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print('.');
        delay(1000);
    }
    Serial.println();
    Serial.println("Connected to WiFi!");
}
