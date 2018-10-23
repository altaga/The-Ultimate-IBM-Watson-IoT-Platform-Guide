# The-Ultimate-IBM-Watson-IoT-Platform-Guide
Here I present you the best guide for using IBM Watson IoT Platform (not saying much because there is no other guide online for this xD) and how to develop WEB applications with IoT devices.

<img src="http://www.ilb.eus/wp-content/uploads/2018/05/WatsonIoT.jpg" width="1000">

Always use technology to improve the world, if you are a black hat or gray hat hacker please abstain at this point ......... or at least leave your star to make me feel less guilty XP.

# Table of contents

* [Introduction](#introduction)
* [Materials](#materials)
* [PC Setup](#pc-setup)
* [Management of the IBM Watson IoT Platform](#management-of-the-ibm-watson-iot-platform)
* [Handling of IoT devices using the IBM Watson IoT Platform (specifically ESP8266 using ArduinoIDE)](#handling-of-iot-devices-using-the-ibm-watson-iot-platform)
* [Handling WEB pages with connectivity to IBM Watson IoT Platform](#handling-web-pages-with-connectivity-to-ibm-watson-iot-platform)
* [Connectivity between IoT device and WEB application](#connectivity-between-iot-device-and-web-application)
* [Connectivity between WEB application and IoT device](#connectivity-between-web-application-and-iot-device)
* [Comments](#comments)
* [References](#references)

## Introduction:

The software world is constantly changing and evolving.

The definition of cloud computing is to offer services through connectivity and the large scale of the Internet. Cloud computing provides access to software resources at an international level, without the need for a server of your own, as it is a software application that serves various clients. Multilocation is what differentiates cloud computing from simple outsourcing and from older application service provider models. **Now, small businesses have the power to develop large-scale applications without large resources** IMPORTANT.

Cloud computing offers individuals and businesses of all sizes the capacity of a pool of computing resources with good maintenance, secure, easily accessible and on demand, such as servers, data storage and application solution (for example MQTT in this case for IoT).

In a simple way, cloud computing is a technology that allows remote access to software, file storage and data processing through the Internet, being an alternative to running on a personal computer or local server. In the cloud model, there is no need to install applications locally on computers.

IMPORTANT NOTE: Watson does not installs on any computer, he "lives" in the cloud.

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

- Register in the IBM Bluemix platform in case you do not have an account.
(https://console.bluemix.net)

<img src="https://image.ibb.co/cYC65f/Selecci-n-003.png" width="400">

- In the search box, we input "Watson IoT Platform"

<img src="https://image.ibb.co/f3XaWL/Selecci-n-004.png" width="400">

- We select the Search option "Watson IoT Platform" in Catalog.

<img src="https://image.ibb.co/b7HaWL/Selecci-n-005.png" width="400">

- We select "Internet of Things Platform".

<img src="https://image.ibb.co/jig8kf/Selecci-n-007.png" width="400">

- Put the name that the Service Name likes where it says "ExampleName" and select the corresponding region.

<img src="https://image.ibb.co/k7G8kf/Selecci-n-009.png" width="600">

- In this case select the "Lite" plan to start developing and once selected press "Create".

<img src="https://image.ibb.co/ggAzaf/Selecci-n-010.png" width="600">

-Press "Launch" to start the service.

<img src="https://image.ibb.co/epEmML/Selecci-n-011.png" width="400">

- At this time we have managed to generate our IoT service at IBM.

## Handling of IoT devices using the IBM Watson IoT Platform:
(Specifically ESP8266 using ArduinoIDE)

- To add your first "Device" we select the "+ Add Device" box.

<img src="https://image.ibb.co/mcdGo0/Selecci-n-012.png" width="600">

- Fill the fields of "Device Type" with the name you like to put on your device is only a label in our case we will put "ESP8266" and as Device ID we will put "Test001" but it can be any ID, it is recommended that this ID be the registration number of the device, after that press "Next".

<img src="https://image.ibb.co/j2HgML/Selecci-n-014.png" width="600">

- Insert the "Metadata" that you like and press "Next".

<img src="https://image.ibb.co/grLkgL/Selecci-n-015.png" width="600">

- Leave the field of "Authentication Token" empty, but if you like you can put your own Token, I recommend leaving empty for IBM to provide you with a unique code for your device,after that press "Next".

<img src="https://image.ibb.co/huJz80/Selecci-n-016.png" width="600">

- In the following box just press "Done".

- In the next window you will find all the necessary data to be able to access the cloud (SAVE ALL THIS DATA SINCE THE AUTHENTICATION TOKEN CAN NOT SEE IT AGAIN).

<img src="https://image.ibb.co/nPU9af/Selecci-n-017.png" width="600">

- If you scrolling down the screen you will see the "Showing Raw Data" window and here you can see the data sent by the ESP8266 (stay on this screen while you flash your device).

<img src="https://image.ibb.co/cYDMML/Selecci-n-018.png" width="600">

- For the Arduino code to work we need to install the following boards and libraries.
  - Libraries.
    - PubSubClient 
  - Boards (To install the "board" use the following tutorial.).
    - https://github.com/esp8266/Arduino

- Once everything is installed, read the following code, understand the comments and try to compile the code (Download the code inside Arduino Folder).

- If everything went well up to this point you should see how the data appears (Do not worry if you see a strange message in the form of JSON, when we connect to our website this will not matter and we will see our message "Hello IBM").

<img src="https://image.ibb.co/eLpjaf/Selecci-n-019.png" width="600">

## Handling of WEB pages with connectivity to IBM Watson IoT Platform:

- We press the "Apps" button in the left sidebar to create an API for our website.

<img src="https://image.ibb.co/eNVMo0/Selecci-n-022.png" width="500">

- Click on the "Generate API Key" button.

<img src="https://image.ibb.co/fq8D1L/Selecci-n-023.png" width="500">

- Fill in the description data and we will give you "Next".

<img src="https://image.ibb.co/nyKxT0/Selecci-n-024.png" width="500">

- We select in the menu "Backend Trusted Application" and Generate Key button.

<img src="https://image.ibb.co/j1YSvf/Selecci-n-025.png" width="500">

- The following window will appear to give access to the web page to our interface (SAVE ALL THESE DATA SINCE THE AUTHENTICATION TOKEN CAN NOT SEE IT AGAIN)

<img src="https://image.ibb.co/mCcgML/Selecci-n-026.png" width="500">

- Download the "html" folder where the basic page for mqtt connectivity with IBM comes from and follow the instructions below the image.

<img src="https://image.ibb.co/m49EQf/Selecci-n-029.png" width="600">

  - Modify the org variable for your "organization id"
  - Modify the variable apl by your "Api Key" but it is very important that you replace the "-" with ":" for example 
    "a-example-example001" -> "a:example:example001"
  - Modify userName for your "Api Key"
  - Modify password for your "Authentication Token".
  - For the example we have prepared, it is not necessary to modify the "topic" variable because the DeviceType and the DeviceID are already set.
  
- Once all this is done, open the "localhost" path in the browser once the Apache is turned on, also in the debug console you can see the message "onConnect"..

<img src="https://image.ibb.co/fdJFGL/Selecci-n-031.png" width="400">


## Connectivity between IoT device and WEB application:

- Once all the settings have been made, connect the IoT device and open the WEB page in order to start receiving messages from the device.

- If everything worked so far you should see an alert every time the device sends the value "Hello IBM", in this case every 30 seconds (Check the "Delay" variable in the Arduino Code).

<img src="https://image.ibb.co/eMZCd0/Selecci-n-030.png" width="600">

## Connectivity between WEB application and IoT device:
(Callback).

- Surprise!, if you paid a little attention, you will have noticed that the "callback" is already integrated into the Arduino code and each time the device sends a message to the web page the page returns the same message as shown in the image.

<img src="https://image.ibb.co/iAkyLf/Selecci-n-034.png" width="600">

- The section of the code of the web page that is responsible for sending data returned is this.

<img src="https://image.ibb.co/naSHwL/Selecci-n-033.png" width="600">

## Comments:

This tutorial only shows you how the IBM IoT system is connected, the development of applications through this platform is necessary to develop it through javascript and through the messages received generate actions to the system.

I recommend that if you are interested in this topic, look for the following terms to make a more landed application:

- Progressive Web App.
- HTML5
  - Javascript
  - CSS
  - Ajax

## References:

- https://console.bluemix.net/docs/services/IoT/index.html
- https://github.com/ibm-watson-iot/device-arduino
- https://developer.ibm.com/recipes/tutorials/connect-an-esp8266-with-the-arduino-sdk-to-the-ibm-iot-foundation/



