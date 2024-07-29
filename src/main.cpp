#include <Arduino.h>
#include "WiFiHandler.h"
#include "HTTPSClientManager.h"
#include <LittleFS.h>
// #include "security.h"


// Replace with your network credentials
const char *ssid = "IAS-BKOCAMAN 2626";
const char *password = "45E4g1#8";

// HTTPSClientManager httpsClientFinger(fingerprint); // Use fingerprint

// HTTPSClientManager httpsClient(IRG_Root_X1); // Use root certificate

HTTPSClientManager httpsClientNoCert;                // No certificate (insecure)

//BearSSL::CertStore certStore;
//HTTPSClientManager httpsClientRootStore(&certStore); // Use root store

WiFiHandler wiFiHandler(ssid, password);

void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println();
  Serial.println();

  wiFiHandler.connect();

  // Initialize LittleFS and cert store
  /*LittleFS.begin();
  int numCerts = certStore.initCertStore(LittleFS, PSTR("/certs.idx"), PSTR("/certs.ar"));
  Serial.printf("Number of CA certs read: %d\n", numCerts);
  if (numCerts == 0)
  {
    Serial.printf("No certs found. Did you run certs-from-mozilla.py and upload the LittleFS directory before running?\n");
  }*/
}

void loop()
{
    //httpsClientFingerprint.performGETRequest("https://www.howsmyssl.com/a/check");
    //httpsClientRootCert.performPOSTRequest("https://jsonplaceholder.typicode.com/posts", "{\"title\":\"foo\",\"body\":\"bar\",\"userId\":1}");
    httpsClientNoCert.performPUTRequest("https://jsonplaceholder.typicode.com/posts/1", "{\"id\":1,\"title\":\"foo\",\"body\":\"bar\",\"userId\":1}");
    //httpsClientRootStore.performDELETERequest("https://jsonplaceholder.typicode.com/posts/1");
    //httpsClientRootStore.performHEADRequest("https://www.howsmyssl.com/a/check");
    //httpsClientRootStore.performPATCHRequest("https://jsonplaceholder.typicode.com/posts/1", "{\"title\":\"foo\"}");
    //httpsClientRootStore.performOPTIONSRequest("https://jsonplaceholder.typicode.com/posts");


  Serial.println();
  Serial.println("Waiting 2min before the next round...");
  delay(5000);
}
