# The-Ultimate-IBM-Watson-IoT-Platform-Guide
I presented the best guide for using IBM Watson IoT Platform and how to develop WEB applications with IoT devices.

<img src="https://hackster.imgix.net/uploads/attachments/612935/wpid-watch_dogs-e3-5_aVW4IYDttS.jpg?auto=compress%2Cformat&w=1280&h=960&fit=max" width="800">

Always use technology for improve the world, if you are a black hat or gray hat hacker please abstain at this point ......... or at least leave your star to make me feel less guilty XP.

# Table of contents

* [Introduction](#introduction)
* [Materials](#materials)
* [PC Setup](#pc-setup)
* [Management of the IBM Watson IoT Platform](#management-of-the-ibm-watson-iot-platform)
* [Handling of IoT devices using the IBM Watson IoT Platform (specifically ESP8266 using ArduinoIDE)](#handling-of-iot-devices-using-the-ibm-watson-iot-platform)
* [Handling of WEB pages with connectivity to IBM Watson IoT Platform](#handling-of-web-pages-with-connectivity-to-ibm-watson-iot-platform)
* [Connectivity between IoT device and WEB application](#connectivity-between-iot-device-and-web-application)
* [Connectivity between WEB application and IoT device](#connectivity-between-web-application-and-iot-device)
* [References](#references)

## Introduction:

The software world is constantly changing and evolving.

The definition of cloud computing is to offer services through the connectivity and large scale of the Internet. Cloud computing provides access to software resources at an international level, without the need for a server of your own, as it is a software application that serves various clients. Multilocation is what differentiates cloud computing from simple outsourcing and from older application service provider models. **Now, small businesses have the power to develop large-scale applications without large resources** IMPORTANT.

Cloud computing offers individuals and businesses of all sizes the capacity of a pool of computing resources with good maintenance, secure, easily accessible and on demand, such as servers, data storage and application solution (for example MQTT as it is in this case for IoT).

In a simple way, cloud computing is a technology that allows remote access to softwares, file storage and data processing through the Internet, being an alternative to running on a personal computer or server local. In the cloud model, there is no need to install applications locally on computers.

IMPORTANT NOTE: Watson does not install on his computers, he "lives" in the cloud.

## Materials:

- ESP8266 (This method can be applied to any IoT device such as ESP32, Raspberry, ETC)
(https://goo.gl/gXFGzD or https://goo.gl/byRkGx)
- Computer with Apache or WebServer.
- IBM Account (Free accounts are perfect for testing applications but have the following limitations).
  - It includes a maximum of 500 registered devices and a maximum of 200 MB of data metrics each.
  - A maximum of 500 registered devices.
  - A maximum of 500 application links.
  - A maximum of 200 MB of data exchanged, analyzed data and limit data analyzed each.

## PC Setup:

(Only if you use Apache server)

PC, MAC or Ubuntu (Linux):To be able to use the Apache service on a computer you need to install XAMPP.
https://www.apachefriends.org/es/download.html

Only for Ubuntu (Linux) I prefer to follow the following tutorial to install Apache.

https://websiteforstudents.com/installing-apache2-mariadb-on-ubuntu-16-04-17-10-18-04-with-php-7-2-support-lamp/

## Management of the IBM Watson IoT Platform:

- Register in the IBM Bluemix platform in case you do not already have an account.
(https://console.bluemix.net)

<img src="https://image.ibb.co/cYC65f/Selecci-n-003.png" width="400">

- In the search box, we put "Watson IoT Platform"

<img src="https://image.ibb.co/f3XaWL/Selecci-n-004.png" width="400">

- We select the Search option "Watson IoT Platform" in Catalog.

<img src="https://image.ibb.co/b7HaWL/Selecci-n-005.png" width="400">

- We select "Internet of Things Platform".

<img src="https://image.ibb.co/jig8kf/Selecci-n-007.png" width="400">

- Put the name that Service Name likes where it says "ExampleName" and select the corresponding region.

<img src="https://image.ibb.co/k7G8kf/Selecci-n-009.png" width="600">

- In this case select the "Lite" plan to start developing and once selected press "Create".

<img src="https://image.ibb.co/ggAzaf/Selecci-n-010.png" width="600">

-Press "Launch" to start the service.

<img src="https://image.ibb.co/epEmML/Selecci-n-011.png" width="400">

- At this time we have managed to generate our IoT service at IBM.

## Handling of IoT devices using the IBM Watson IoT Platform:
(Specifically ESP8266 using ArduinoIDE)

- To add your first "Device" we select the "+ Add Device" box.

https://image.ibb.co/mcdGo0/Selecci-n-012.png

- Fill the fields of "Device Type" with the name you like to put on your device is only a label in our case we will put "ESP8266" and as Device ID we will put "Test001" but it can be any ID, it is recommended that this ID be the registration number of the device, after that press "Next".

https://image.ibb.co/j2HgML/Selecci-n-014.png

- Insert the "Metadata" that you like and press "Next".

https://image.ibb.co/grLkgL/Selecci-n-015.png

- Leave the field of "Authentication Token" empty, but if you like you can put your own Token, I recommend leaving empty for IBM to provide you with a unique code for your device,after that press "Next".

https://image.ibb.co/huJz80/Selecci-n-016.png

- In the following box just press "Done".

- In the next window you will find all the necessary data to be able to access the cloud (SAVE ALL THESE DATA SINCE THE AUTHENTICATION TOKEN CAN NOT SEE IT AGAIN).

https://image.ibb.co/nPU9af/Selecci-n-017.png

- For the Arduino code to work we need to install the following boards and libraries.
  - Libraries.
    - PubSubClient 
  - Boards (To install the "board" use the following tutorial.).
    - https://github.com/esp8266/Arduino

- Once everything is installed, read the following code, understand the comments and try to compile the code.

```Arduino

#include <ESP8266WiFi.h>
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
char topic[] = "iot-2/evt/status/fmt/json"; // This is the topic that needs to be put in order for data to be sent to the platform, NOT MODIFY.
char authMethod[] = "use-token-auth";
char token[] = TOKEN;
char clientId[] = "d:" ORG ":" DEVICE_TYPE ":" DEVICE_ID;

WiFiClientSecure wifiClient;
PubSubClient client(server, 8883, wifiClient);

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

}

void loop() {
   
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
   }
   
  String payload ="Hello IBM"; // Data sent, you can also send a json if you want.
  
  Serial.print("Sending payload: "); Serial.println(payload);
    
  if (client.publish(topic, (char*) payload.c_str())) {
    Serial.println("Publish ok");
  } else {
    Serial.println("Publish failed");
  }

  delay(30000);
}
```
## Handling of WEB pages with connectivity to IBM Watson IoT Platform:

## Connectivity between IoT device and WEB application:

## Connectivity between WEB application and IoT device:
(Callback).






