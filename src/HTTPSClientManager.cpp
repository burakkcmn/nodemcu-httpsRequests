#include "HTTPSClientManager.h"
#include <Arduino.h>

HTTPSClientManager::HTTPSClientManager(const uint8_t *fingerprint)
    : authType(FINGERPRINT), fingerprint(fingerprint), rootCert(nullptr), certList(nullptr)
{
    createWifiClient();
}

HTTPSClientManager::HTTPSClientManager(const char *rootCert)
    : authType(ROOT_CERT), fingerprint(nullptr), rootCert(rootCert), certStore(nullptr)
{
    certList = new X509List(rootCert);
    createWifiClient();
}

HTTPSClientManager::HTTPSClientManager(BearSSL::CertStore *certStore)
    : authType(ROOT_STORE), fingerprint(nullptr), rootCert(nullptr), certStore(certStore)
{
    createWifiClient();
}

HTTPSClientManager::HTTPSClientManager()
    : authType(NO_CERT), fingerprint(nullptr), rootCert(nullptr), certList(nullptr), certStore(nullptr)
{
    createWifiClient();
}

void HTTPSClientManager::createWifiClient()
{
    if (authType == FINGERPRINT && fingerprint != nullptr)
    {
        std::unique_ptr<BearSSL::WiFiClientSecure> bearClient(new BearSSL::WiFiClientSecure);
        bearClient->setFingerprint(fingerprint);
        client = *bearClient;
    }
    else if (authType == ROOT_CERT && rootCert != nullptr)
    {
        client.setTrustAnchors(certList);
    }
    else if (authType == NO_CERT)
    {
        std::unique_ptr<BearSSL::WiFiClientSecure> bearClient(new BearSSL::WiFiClientSecure);
        bearClient->setInsecure();
        client = *bearClient;
    }
    else if (authType == ROOT_STORE && certStore != nullptr)
    {
        client.setCertStore(certStore);
    }
}

void HTTPSClientManager::performGETRequest(const String& url) {
    HTTPClient https;
    Serial.print("[HTTPS] begin...\n");
    if (https.begin(client, url)) {
        Serial.print("[HTTPS] GET...\n");
        int httpCode = https.GET();
        if (httpCode > 0) {
            Serial.printf("[HTTPS] GET... code: %d\n", httpCode);
            if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
                String payload = https.getString();
                Serial.println(payload);
            }
        } else {
            Serial.printf("[HTTPS] GET... failed, error: %s\n", https.errorToString(httpCode).c_str());
        }
        https.end();
    } else {
        Serial.printf("[HTTPS] Unable to connect\n");
    }
}

void HTTPSClientManager::performPOSTRequest(const String& url, const String& payload) {
    HTTPClient https;
    Serial.print("[HTTPS] begin...\n");
    if (https.begin(client, url)) {
        Serial.print("[HTTPS] POST...\n");
        https.addHeader("Content-Type", "application/json");
        int httpCode = https.POST(payload);
        if (httpCode > 0) {
            Serial.printf("[HTTPS] POST... code: %d\n", httpCode);
            String response = https.getString();
            Serial.println(response);
        } else {
            Serial.printf("[HTTPS] POST... failed, error: %s\n", https.errorToString(httpCode).c_str());
        }
        https.end();
    } else {
        Serial.printf("[HTTPS] Unable to connect\n");
    }
}

void HTTPSClientManager::performPUTRequest(const String& url, const String& payload) {
    HTTPClient https;
    Serial.print("[HTTPS] begin...\n");
    if (https.begin(client, url)) {
        Serial.print("[HTTPS] PUT...\n");
        https.addHeader("Content-Type", "application/json");
        int httpCode = https.PUT(payload);
        if (httpCode > 0) {
            Serial.printf("[HTTPS] PUT... code: %d\n", httpCode);
            String response = https.getString();
            Serial.println(response);
        } else {
            Serial.printf("[HTTPS] PUT... failed, error: %s\n", https.errorToString(httpCode).c_str());
        }
        https.end();
    } else {
        Serial.printf("[HTTPS] Unable to connect\n");
    }
}

void HTTPSClientManager::performDELETERequest(const String& url) {
    HTTPClient https;
    Serial.print("[HTTPS] begin...\n");
    if (https.begin(client, url)) {
        Serial.print("[HTTPS] DELETE...\n");
        int httpCode = https.sendRequest("DELETE");
        if (httpCode > 0) {
            Serial.printf("[HTTPS] DELETE... code: %d\n", httpCode);
            String response = https.getString();
            Serial.println(response);
        } else {
            Serial.printf("[HTTPS] DELETE... failed, error: %s\n", https.errorToString(httpCode).c_str());
        }
        https.end();
    } else {
        Serial.printf("[HTTPS] Unable to connect\n");
    }
}

void HTTPSClientManager::performHEADRequest(const String& url) {
    HTTPClient https;
    Serial.print("[HTTPS] begin...\n");
    if (https.begin(client, url)) {
        Serial.print("[HTTPS] HEAD...\n");
        int httpCode = https.sendRequest("HEAD");
        if (httpCode > 0) {
            Serial.printf("[HTTPS] HEAD... code: %d\n", httpCode);
        } else {
            Serial.printf("[HTTPS] HEAD... failed, error: %s\n", https.errorToString(httpCode).c_str());
        }
        https.end();
    } else {
        Serial.printf("[HTTPS] Unable to connect\n");
    }
}

void HTTPSClientManager::performPATCHRequest(const String& url, const String& payload) {
    HTTPClient https;
    Serial.print("[HTTPS] begin...\n");
    if (https.begin(client, url)) {
        Serial.print("[HTTPS] PATCH...\n");
        https.addHeader("Content-Type", "application/json");
        int httpCode = https.sendRequest("PATCH", payload);
        if (httpCode > 0) {
            Serial.printf("[HTTPS] PATCH... code: %d\n", httpCode);
            String response = https.getString();
            Serial.println(response);
        } else {
            Serial.printf("[HTTPS] PATCH... failed, error: %s\n", https.errorToString(httpCode).c_str());
        }
        https.end();
    } else {
        Serial.printf("[HTTPS] Unable to connect\n");
    }
}

void HTTPSClientManager::performOPTIONSRequest(const String& url) {
    HTTPClient https;
    Serial.print("[HTTPS] begin...\n");
    if (https.begin(client, url)) {
        Serial.print("[HTTPS] OPTIONS...\n");
        int httpCode = https.sendRequest("OPTIONS");
        if (httpCode > 0) {
            Serial.printf("[HTTPS] OPTIONS... code: %d\n", httpCode);
            String response = https.getString();
            Serial.println(response);
        } else {
            Serial.printf("[HTTPS] OPTIONS... failed, error: %s\n", https.errorToString(httpCode).c_str());
        }
        https.end();
    } else {
        Serial.printf("[HTTPS] Unable to connect\n");
    }
}