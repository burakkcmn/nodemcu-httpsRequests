#ifndef HTTPS_CLIENT_MANAGER_H
#define HTTPS_CLIENT_MANAGER_H

#include <ESP8266HTTPClient.h>
#include <WiFiClientSecureBearSSL.h>
#include <WiFiClientSecure.h>

class HTTPSClientManager
{
public:
    enum AuthType
    {
        FINGERPRINT,
        ROOT_CERT,
        NO_CERT,
        ROOT_STORE
    };

    HTTPSClientManager(const uint8_t *fingerprint);
    HTTPSClientManager(const char *rootCert);
    HTTPSClientManager(BearSSL::CertStore *certStore);
    HTTPSClientManager();
    void performGETRequest(const String &url);
    void performPOSTRequest(const String &url, const String &payload);
    void performPUTRequest(const String &url, const String &payload);
    void performDELETERequest(const String &url);
    void performHEADRequest(const String &url);
    void performPATCHRequest(const String &url, const String &payload);
    void performOPTIONSRequest(const String &url);

private:
    AuthType authType;
    const uint8_t *fingerprint;
    const char *rootCert;
    X509List *certList;
    BearSSL::CertStore *certStore;
    WiFiClientSecure client;

    void createWifiClient();
};

#endif // HTTPS_CLIENT_MANAGER_H
