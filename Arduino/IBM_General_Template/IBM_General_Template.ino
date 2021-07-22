#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <PubSubClient.h>

//-------- Modify these values -----------
const char* ssid = "YOUR_SSID";      // The name of your Internet BTW
const char* password = "YOUR_PASS";  // Your pass 

#define ORG "YOUR_ORGANIZATION_ID" // This information is in the previous image
#define DEVICE_ID "Test001"        //  Only for this Example 
#define DEVICE_TYPE "ESP8266"      // your device type 
#define TOKEN "YOUR_TOKEN"         // your device token

//-------- Modify these values --------

char server[] = ORG ".messaging.internetofthings.ibmcloud.com";
char TopicSub[] = "iot-2/cmd/status/fmt/json";
char TopicPub[] = "iot-2/evt/status/fmt/json"; 
// This is the topic that needs to be put in order for data to be sent and recieve in the platform, NOT MODIFY.
char authMethod[] = "use-token-auth";
char token[] = TOKEN;
char clientId[] = "d:" ORG ":" DEVICE_TYPE ":" DEVICE_ID;
unsigned int Delay = 30;    // This time is what the device will take to send data
unsigned int i=(Delay*100);

WiFiClientSecure wifiClient;
PubSubClient client(server, 8883, wifiClient); //Never modify the 8883 as it is a safe port for sending data

// Certfificate

const char* test_root_ca = \
"-----BEGIN CERTIFICATE-----\n" \
"MIIDrzCCApegAwIBAgIQCDvgVpBCRrGhdWrJWZHHSjANBgkqhkiG9w0BAQUFADBh\n" \
"MQswCQYDVQQGEwJVUzEVMBMGA1UEChMMRGlnaUNlcnQgSW5jMRkwFwYDVQQLExB3\n" \
"d3cuZGlnaWNlcnQuY29tMSAwHgYDVQQDExdEaWdpQ2VydCBHbG9iYWwgUm9vdCBD\n" \
"QTAeFw0wNjExMTAwMDAwMDBaFw0zMTExMTAwMDAwMDBaMGExCzAJBgNVBAYTAlVT\n" \
"MRUwEwYDVQQKEwxEaWdpQ2VydCBJbmMxGTAXBgNVBAsTEHd3dy5kaWdpY2VydC5j\n" \
"b20xIDAeBgNVBAMTF0RpZ2lDZXJ0IEdsb2JhbCBSb290IENBMIIBIjANBgkqhkiG\n" \
"9w0BAQEFAAOCAQ8AMIIBCgKCAQEA4jvhEXLeqKTTo1eqUKKPC3eQyaKl7hLOllsB\n" \
"CSDMAZOnTjC3U/dDxGkAV53ijSLdhwZAAIEJzs4bg7/fzTtxRuLWZscFs3YnFo97\n" \
"nh6Vfe63SKMI2tavegw5BmV/Sl0fvBf4q77uKNd0f3p4mVmFaG5cIzJLv07A6Fpt\n" \
"43C/dxC//AH2hdmoRBBYMql1GNXRor5H4idq9Joz+EkIYIvUX7Q6hL+hqkpMfT7P\n" \
"T19sdl6gSzeRntwi5m3OFBqOasv+zbMUZBfHWymeMr/y7vrTC0LUq7dBMtoM1O/4\n" \
"gdW7jVg/tRvoSSiicNoxBN33shbyTApOB6jtSj1etX+jkMOvJwIDAQABo2MwYTAO\n" \
"BgNVHQ8BAf8EBAMCAYYwDwYDVR0TAQH/BAUwAwEB/zAdBgNVHQ4EFgQUA95QNVbR\n" \
"TLtm8KPiGxvDl7I90VUwHwYDVR0jBBgwFoAUA95QNVbRTLtm8KPiGxvDl7I90VUw\n" \
"DQYJKoZIhvcNAQEFBQADggEBAMucN6pIExIK+t1EnE9SsPTfrgT1eXkIoyQY/Esr\n" \
"hMAtudXH/vTBH1jLuG2cenTnmCmrEbXjcKChzUyImZOMkXDiqw8cvpOp/2PV5Adg\n" \
"06O/nVsJ8dWO41P0jmP6P6fbtGbfYmbW0W5BjfIttep3Sp+dWOIrWcBAI+0tKIJF\n" \
"PnlUkiaY4IBIqDfv8NZ5YBberOgOzW6sRBc4L0na4UU+Krk2U886UAb3LujEV0ls\n" \
"YSEY1QSteDwsOoBrp+uvFRTp2InBuThs4pFsiv9kuXclVzDAGySj4dzp30d8tbQk\n" \
"CAUw7C29C79Fv1C5qfPrmAESrciIxpg0X40KPMbp1ZWVbd4=\n" \
"-----END CERTIFICATE-----\n";


void callback(char* topic, byte* payload, unsigned int length) 
{
  String data="";
  for (int i = 0; i < length; i++) 
  {
    data+=char(payload[i]);
  }
  Serial.println("Received Data:" + data); // In this case we print the data recive from the website.
}

void setup() {
  Serial.begin(115200); Serial.println();
  Serial.print("Connecting to "); Serial.print(ssid);
  if (strcmp (WiFi.SSID().c_str(), ssid) != 0) {
     WiFi.begin(ssid, password);
  }
  while (WiFi.status() != WL_CONNECTED) {
     delay(500);
     Serial.print(".");
  }  
  Serial.println("");
  Serial.print("WiFi connected, IP address: "); Serial.println(WiFi.localIP());
  client.setCallback(callback); // Here we "connect"the callback function to subscribe data receive
  wifiClient.setCACert(test_root_ca);
}

void loop() {
  client.loop();
   
   // Do not modify the delay of 500 ms since it depends on the correct connection.
   if (!!!client.connected()) 
   {
     Serial.print("Reconnecting client to "); Serial.println(server);
     while ( !client.connect(clientId, authMethod, token)) 
     {
        Serial.print(".");
        delay(500);
     }
     Serial.println();
     client.subscribe(TopicSub);  // This is for callback
   }

  if(i>=(Delay*100)) 
  {
    String payload ="Hello IBM"; // Data sent, you can also send a json if you want.
    Serial.print("Sending payload: "); Serial.println(payload);
      
    if (client.publish(TopicPub, (char*) payload.c_str())) 
    {
      Serial.println("Publish ok");
    } 
    else 
    {
      Serial.println("Publish failed");
    }
    i=0;
  }
  else
  {
    i++;
    delay(10);
  }
}
