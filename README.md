# Disclaimer

This is a PlatformIO "port" of an old of an old ESP8266 Arduino project that I did several years ago.
This code is by no means clean or memory safe and there are no guarantees of it working as expected. The only reason this old project is published in this state is so I can preserve it and fix bugs that arise over time as I need this in daily production. It has been working mostly reliably but use it at your own risk. 

Note to myself:
The folder "old_code" contains all the old code and versions that came about before I used git to store the project. These are just here for historical purposes and are not to be used. 

# MQTT Sockets

This project allows an ESP8266 connected to an MQTT server through WiFi and take commands from a SmartHome system like HomeAssistant. It then parses these commands and switches 433 MHz Remote controlled sockets on or off using a 433 MHz transmitter connected to the ESP. Multiple Remote-Socket protocols are supported.

## Setup

To use the project, you need to specify WIFI secrets, fingerprints and other configuration in the ```include/secrets.h``` file. Example content:

```c
#define MQTT_FINGERPRINT "07 ED 59 67 2C CD 31 6C EF 27 F7 AC 38 02 07 9C 60 EC FA 0A"
#define WIFI_SSID "MyHomeWifi"
#define WIFI_PSK "MyWiFiPassword"
#define MQTT_BASE_TOPIC "/devices/sub0/espdev2051a/"

```