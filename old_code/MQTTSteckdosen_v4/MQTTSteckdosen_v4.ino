

/*
MQTT-Remot-Switches for ESP8266
Written by Matteo Reiter, 14.12.2020
© 2020 www.elektron.work
More information about this project
and the home automation project this is
part of can be found on my website:
## TBD

This code was written by Matteo Reiter
and is based on the MQTT example code 
writte by BitBastelei: www.adlerweb.info

This Sketch is open source and you are
allowed to republish and modifie it 
as long as credits are given


This Sketch does:
 * Connect to WiFi and to a MQTT Broker on the local network
 * Subscribe to a base topic and convert light controll messages 
   in the json format on this topic to
   433MHz signals for remote switches/sockets
 * send theses messages via a 433MHz Transmitter connected to pin 2
   (pin can be changed in <rctx> variable) through different
   protocols depending on the subtopic


Error Messages:
This code will inform you of an internal Error when trying to process a command
received via MQTT. It will print the error messages to serial
as well as sending an error message via MQTT.

The messages consist of an error code and an error Message.
The errror code tells the type of error, the message is 
a string that is readable to users and can tell more about
what exactly caused this error.
Here is the table of possible error codes:

1 = Invalid Topic (some part of the Topic that a command was received over is invalid)
2 = Static buffer size exceeded (Some part of the message (can be topic or payload) is to large to fit in the static buffer)
3 = Json error (something went wront during the deserializatino of the json payload)
4 = Invalid Message (this occurs when the value of the message is not what the system expects, e.g. a requires json key is messing. This error does not occur when the json is corrupted!)

 */



#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <PubSubClient.h>
#include <RCSwitch.h>
#include <ArduinoJson.h>

// At the moment, I couldn't get ssl communicatino to work, this will be added once it works reliably
// COMMENT added at 230401: The following certificates are invalid. They have never been used and have been scrambled before publishing to github and are only present to preserve the orinal shape of the code

// ca file converted to c++ array by python programm "ca2cpp_array.py"
//unsigned char root_ca[] = {0x2, 0x95, 0xa0, 0x3, 0x2, 0x1, 0x2, 0x2, 0x9b, 0x37, 0x5b, 0x4c, 0xe9, 0x37, 0x6, 0x9, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0xd, 0x1, 0x1, 0xd, 0x5, 0x0, 0x30, 0x66, 0x31, 0xe, 0x30, 0xc, 0x6, 0x3, 0x55, 0x4, 0x3, 0xc, 0x5, 0x72, 0x70, 0x69, 0x33, 0x62, 0x31, 0x16, 0x30, 0x14, 0x6, 0x3, 0x55, 0x4, 0xa, 0xc, 0xd, 0x65, 0x6c, 0x65, 0x6b, 0x74, 0x72, 0x6f, 0x6e, 0x2e, 0x77, 0x6f, 0x72, 0x6b, 0x31, 0x16, 0x30, 0x14, 0x6, 0x3, 0x55, 0x4, 0xb, 0xc, 0xd, 0x4d, 0x51, 0x54, 0x54, 0x5f, 0x53, 0x65, 0x72, 0x76, 0x69, 0x63, 0x65, 0x73, 0x31, 0x24, 0x30, 0x22, 0x6, 0x9, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0xd, 0x1, 0x9, 0x1, 0x16, 0x15, 0x73, 0x6f, 0x6d, 0x65, 0x74, 0x68, 0x69, 0x6e, 0x67, 0x40, 0x65, 0x78, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x2e, 0x6e, 0x65, 0x74, 0x30, 0x1e, 0x17, 0xd, 0x32, 0x30, 0x31, 0x31, 0x32, 0x34, 0x32, 0x31, 0x32, 0x33, 0x31, 0x30, 0x5a, 0x17, 0xd, 0x33, 0x32, 0x31, 0x31, 0x32, 0x31, 0x32, 0x31, 0x32, 0x33, 0x31, 0x30, 0x5a, 0x30, 0x66, 0x31, 0xe, 0x30, 0xc, 0x6, 0x3, 0x55, 0x4, 0x3, 0xc, 0x5, 0x72, 0x70, 0x69, 0x33, 0x62, 0x31, 0x16, 0x30, 0x14, 0x6, 0x3, 0x55, 0x4, 0xa, 0xc, 0xd, 0x65, 0x6c, 0x65, 0x6b, 0x74, 0x72, 0x6f, 0x6e, 0x2e, 0x77, 0x6f, 0x72, 0x6b, 0x31, 0x16, 0x30, 0x14, 0x6, 0x3, 0x55, 0x4, 0xb, 0xc, 0xd, 0x4d, 0x51, 0x54, 0x54, 0x5f, 0x53, 0x65, 0x72, 0x76, 0x69, 0x63, 0x65, 0x73, 0x31, 0x24, 0x30, 0x22, 0x6, 0x9, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0xd, 0x1, 0x9, 0x1, 0x16, 0x15, 0x73, 0x6f, 0x6d, 0x65, 0x74, 0x68, 0x69, 0x6e, 0x67, 0x40, 0x65, 0x78, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x2e, 0x6e, 0x65, 0x74, 0x30, 0x82, 0x1, 0x22, 0x30, 0xd, 0x6, 0x9, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0xd, 0x1, 0x1, 0x1, 0x5, 0x0, 0x3, 0x82, 0x1, 0xf, 0x0, 0x30, 0x82, 0x1, 0xa, 0x2, 0x82, 0x1, 0x1, 0x0, 0xe3, 0x48, 0x7a, 0xf2, 0xea, 0x9, 0xb, 0x99, 0x73, 0x2e, 0x9, 0xf7, 0xcf, 0x4d, 0xf, 0x8e, 0x7f, 0xe6, 0x3c, 0xbe, 0xde, 0x93, 0x34, 0x76, 0xab, 0x4b, 0xc3, 0x40, 0xd9, 0x39, 0x84, 0xe2, 0x31, 0xf8, 0x90, 0x2f, 0x40, 0x6, 0x3f, 0xcf, 0x35, 0x11, 0xfe, 0x48, 0x97, 0xd1, 0x8c, 0x60, 0x93, 0x88, 0xac, 0x3c, 0x29, 0xac, 0x4b, 0xa1, 0x3f, 0x3d, 0x87, 0x4a, 0x15, 0x6a, 0xc7, 0x7c, 0xe0, 0x6a, 0x14, 0xd0, 0xf7, 0x16, 0x7e, 0xfa, 0xd1, 0x4c, 0x6e, 0xac, 0x17, 0xba, 0xcd, 0xd4, 0xae, 0x4e, 0xc3, 0xe4, 0xfb, 0xf4, 0x84, 0x7, 0x37, 0x73, 0x58, 0xc5, 0x16, 0x45, 0x40, 0xcc, 0xad, 0x95, 0xe5, 0x69, 0x7b, 0x49, 0x6c, 0x62, 0x4f, 0x25, 0x1a, 0x6, 0xe4, 0x87, 0x67, 0x3d, 0xe5, 0xb2, 0xff, 0xe, 0xe, 0x3d, 0xa, 0xfc, 0x92, 0x7c, 0xaa, 0x7d, 0xf1, 0x3a, 0x5d, 0xc0, 0x84, 0xbc, 0xcc, 0xab, 0x71, 0x67, 0x2d, 0x75, 0xab, 0x91, 0xd5, 0x4f, 0x73, 0x84, 0xcd, 0xe6, 0x5f, 0xbb, 0x62, 0x79, 0x69, 0x6c, 0xdb, 0x79, 0x59, 0x93, 0xdb, 0x43, 0xe0, 0x60, 0x6a, 0xc3, 0x5f, 0x8b, 0x16, 0xc, 0x5c, 0x5b, 0xee, 0x45, 0xb1, 0xd7, 0xf7, 0xbc, 0x48, 0x9f, 0xcb, 0x4a, 0xed, 0x3e, 0x88, 0xd9, 0x99, 0xea, 0xc, 0xae, 0x5e, 0x20, 0xc0, 0x88, 0x93, 0x1a, 0xdb, 0xda, 0xce, 0x4a, 0xa8, 0x3f, 0x10, 0x64, 0x46, 0x2b, 0xd9, 0xad, 0xdc, 0x83, 0x94, 0x17, 0x44, 0xfe, 0x43, 0xcf, 0x55, 0x65, 0x1, 0x4b, 0x6a, 0xa, 0xdd, 0x4c, 0x54, 0xe5, 0x3e, 0x67, 0xf2, 0x64, 0xf4, 0xa0, 0x3b, 0x7a, 0x99, 0xd6, 0x66, 0xd5, 0xf8, 0xa6, 0x25, 0x1, 0xf4, 0x49, 0xef, 0xd4, 0x48, 0x95, 0xae, 0xc4, 0x5f, 0xfa, 0xef, 0x21, 0x82, 0x4d, 0xd5, 0x94, 0x4c, 0xed, 0x25, 0x1b, 0x2, 0x3, 0x1, 0x0, 0x1, 0xa3, 0x53, 0x30, 0x51, 0x30, 0x1d, 0x6, 0x3, 0x55, 0x1d, 0xe, 0x4, 0x16, 0x4, 0x14, 0x77, 0x8b, 0xa2, 0x76, 0xea, 0xf7, 0xb4, 0x20, 0x36, 0x23, 0x4d, 0xf5, 0xb9, 0xa6, 0x8c, 0x76, 0x17, 0x6c, 0x5a, 0xbf, 0x30, 0x1f, 0x6, 0x3, 0x55, 0x1d, 0x23, 0x4, 0x18, 0x30, 0x16, 0x80, 0x14, 0x77, 0x8b, 0xa2, 0x76, 0xea, 0xf7, 0xb4, 0x20, 0x36, 0x23, 0x4d, 0xf5, 0xb9, 0xa6, 0x8c, 0x76, 0x17, 0x6c, 0x5a, 0xbf, 0x30, 0xf, 0x6, 0x3, 0x55, 0x1d, 0x13, 0x1, 0x1, 0xff, 0x4, 0x5, 0x30, 0x3, 0x1, 0x1, 0xff, 0x30, 0xd, 0x6, 0x9, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0xd, 0x1, 0x1, 0xd, 0x5, 0x0, 0x3, 0x82, 0x1, 0x1, 0x0, 0x8e, 0x90, 0xbd, 0x93, 0x97, 0xb, 0xac, 0x9f, 0x71, 0x2c, 0x72, 0x1a, 0x9d, 0xce, 0xab, 0x8a, 0x41, 0xfe, 0x4f, 0xd, 0xdb, 0xaa, 0xeb, 0xa3, 0x16, 0x28, 0x65, 0x82, 0x48, 0x4e, 0x8c, 0x20, 0x4b, 0x79, 0x74, 0x70, 0x61, 0x1f, 0x92, 0xd6, 0x5d, 0x7f, 0x30, 0xa6, 0x24, 0x75, 0x49, 0xcc, 0x8b, 0xca, 0x9a, 0x71, 0x91, 0xaf, 0xf3, 0x2b, 0x90, 0x4a, 0xa4, 0xa6, 0xea, 0xff, 0x76, 0x54, 0x3f, 0xe2, 0xb6, 0x6b, 0xd3, 0x65, 0x65, 0x18, 0x6a, 0x36, 0x0, 0x3a, 0x27, 0xf6, 0xd4, 0x55, 0xed, 0xdf, 0xf3, 0xf5, 0xdd, 0xf2, 0x77, 0x9f, 0x2c, 0xc7, 0xa, 0xce, 0x57, 0xbb, 0x4c, 0x59, 0x10, 0x1b, 0x3f, 0xff, 0x2b, 0x32, 0x21, 0x95, 0xd0, 0xa2, 0xb0, 0x26, 0x99, 0xae, 0xd5, 0xf0, 0x6c, 0xce, 0xec, 0xe1, 0xaf, 0xd3, 0xee, 0x49, 0xe3, 0x18, 0x11, 0x1d, 0xcd, 0xf0, 0x4b, 0xb0, 0x15, 0xf0, 0x1, 0x25, 0x9a, 0x93, 0x76, 0x1f, 0x79, 0x31, 0xde, 0xe1, 0x3a, 0x73, 0xba, 0xf2, 0x2c, 0x69, 0xc9, 0xa3, 0x2, 0x27, 0xf9, 0xd8, 0x16, 0x81, 0xed, 0x1d, 0xfe, 0x7b, 0x6d, 0x8, 0x57, 0x7, 0x1e, 0xc3, 0x38, 0x7, 0x3f, 0xd8, 0x17, 0xd9, 0xc6, 0x75, 0xf, 0x7, 0x55, 0x51, 0xaf, 0x5f, 0xe7, 0x0, 0x3c, 0x91, 0x59, 0xbb, 0x7d, 0xcf, 0xa9, 0xf7, 0x25, 0x52, 0x64, 0x45, 0x7b, 0xd0, 0xf0, 0x26, 0x75, 0xc5, 0xe9, 0x1b, 0x89, 0x50, 0xc6, 0xbc, 0x39, 0xc1, 0x1a, 0x9c, 0x1b, 0x7a, 0x56, 0x95, 0xa8, 0x3a, 0xed, 0xb1, 0xe6, 0x0, 0x29, 0x6f, 0xdb, 0x45, 0x4d, 0x72, 0xa7, 0xc3, 0xd7, 0xe2, 0x56, 0x7b, 0x25, 0x1f, 0x17, 0xf6, 0xb9, 0x33, 0xd5, 0x96, 0xe0, 0x79, 0xd4, 0xfd, 0x97, 0xb3, 0x24, 0x76, 0xed, 0xc4, 0x7, 0x46, 0xb4, 0x83, 0x4e, 0x51, 0x82, 0xf10x30, 0x82, 0x3, 0xad, 0x14, 0x7a, 0xd, 0xe3, 0x5, 0xd, 0x98, 0x1e, 0xff, 0x17, 0x30, 0x82, 0xeb, 0x2f, 0x4b, 0xc7, 0x13, 0x30, 0xd};


/*const char* test_root_ca = \ 
"-----BEGIN CERTIFICATE-----\n" \ 
"h2c95bL/Dg49CvySfKp98TpdwIS8zKtxZy11q5HVT3OEzeZfu2J5aWzbeVmT20Pg\n" \ 
"YGrDX4sWDFxb7kWx1/e8SJ/LSu0+iNmZ6gyuXiDAiJMa29rOSqg/EGRGK9mt3IOU\n" \ 
"MIIDrTCCApWgAwIBAgIUeg3jBQ2YHv8XmzdbTOk36y9LxxMwDQYJKoZIhvcNAQEN\n" \ 
"eGFtcGxlLm5ldDAeFw0yMDExMjQyMTIzMTBaFw0zMjExMjEyMTIzMTBaMGYxDjAM\n" \ 
"BgNVBAMMBXJwaTNiMRYwFAYDVQQKDA1lbGVrdHJvbi53b3JrMRYwFAYDVQQLDA1N\n" \ 
"UVRUX1NlcnZpY2VzMSQwIgYJKoZIhvcNAQkBFhVzb21ldGhpbmdAZXhhbXBsZS5u\n" \ 
"ZXQwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQDjSHry6gkLmXMuCffP\n" \ 
"BQAwZjEOMAwGA1UEAwwFcnBpM2IxFjAUBgNVBAoMDWVsZWt0cm9uLndvcmsxFjAU\n" \ 
"BgNVBAsMDU1RVFRfU2VydmljZXMxJDAiBgkqhkiG9w0BCQEWFXNvbWV0aGluZ0Bl\n" \ 
"Ve3f8/Xd8nefLMcKzle7TFkQGz//KzIhldCisCaZrtXwbM7s4a/T7knjGBEdzfBL\n" \ 
"Ua9f5wA8kVm7fc+p9yVSZEV70PAmdcXpG4lQxrw5wRqcG3pWlag67bHmAClv20VN\n" \ 
"TQ+Of+Y8vt6TNHarS8NA2TmE4jH4kC9ABj/PNRH+SJfRjGCTiKw8KaxLoT89h0oV\n" \ 
"asd84GoU0PcWfvrRTG6sF7rN1K5Ow+T79IQHN3NYxRZFQMytleVpe0lsYk8lGgbk\n" \ 
"F0T+Q89VZQFLagrdTFTlPmfyZPSgO3qZ1mbV+KYlAfRJ79RIla7EX/rvIYJN1ZRM\n" \ 
"7SUbAgMBAAGjUzBRMB0GA1UdDgQWBBR3i6J26ve0IDYjTfW5pox2F2xavzAfBgNV\n" \ 
"HSMEGDAWgBR3i6J26ve0IDYjTfW5pox2F2xavzAPBgNVHRMBAf8EBTADAQH/MA0G\n" \ 
"sBXwASWak3YfeTHe4TpzuvIsacmjAif52BaB7R3+e20IVwcewzgHP9gX2cZ1DwdV\n" \ 
"CSqGSIb3DQEBDQUAA4IBAQCOkL2Tlwusn3EschqdzquKQf5PDduq66MWKGWCSE6M\n" \ 
"IEt5dHBhH5LWXX8wpiR1ScyLyppxka/zK5BKpKbq/3ZUP+K2a9NlZRhqNgA6J/bU\n" \ 
"cqfD1+JWeyUfF/a5M9WW4HnU/ZezJHbtxAdGtINOUYLx\n" \ 
"-----END CERTIFICATE-----\n" ;
*/
int rctx = 2;                                     // Pin for the RC-Transmitter
int rcrx = 0;                                     // Pin for the RC-Receiver (not jet implemented)
int WiFiConnected = 2;                            // Pin for an LED that blinks while WiFi is connecting

const char* cfg_wifi_ssid = "********";       // WiFi SSID
const char* cfg_wifi_pwd = "********";            // WiFi Password

const char* mqtt_server = "192.168.1.13";         // MQTT server
const unsigned int mqtt_port = 1883;              // MQTT port
const char* mqtt_user =   "****";
const char* mqtt_pass =   "****";
uint32_t conCheckInterval = 1000000;                // Each x loopcycles the connecttino to the server will be checked


// the following variables/arrays are buffers for various remote-switch/socket data protocols
// for the dip-switch remote-switch/socket protocol
char systemCode[] = "00000";                      // some char array the save the Remote-Switch/Socket system code
char unitCode[] = "00000";                        // some char array the save the Remote-Switch/Socket unit code

// for remote-switches/sockets protocol by Intertechno
char intertechno_id[3][10];
char family = 'b';
char group_char[2] = "3";
uint8_t group_int = 3;
char device_char[2] = "3";
uint8_t device_int = 2;

// for rotaty/sliding switch remote-switch/socket protocol
char switch1_char = '1';
uint8_t switch1_int = 1;
char switch2_char = '4';
uint8_t switch2_int = 4;



char remote_switch_id[10];                        // for some remote-switch/socket types I need to use strtok() to fetch the switch/socket id. Therefor i can first copy it into this array, so the original in the subtopic_list will not get destroyed
char stateBuf[5] = "off";                         // buffer to store the raw state value
char stateCode = '0';                             // come char to store the Remote-Switch/Socket state (1/0, ON/OFF)
bool messageInvalid = false;                      // message Invalid flag


// some buffers and definitions for topics and messages
#define TOPIC_BUF_L 300                                                 // lenght of the topic buffer in characters (a value of 300 means, topics are not allowed to be over 300 characters long or the programm might crash due to buffer overflow as strcpy_s is not a thing in arduino
#define MSG_BUF_L 100                                                   // lenght of the message buffer in characters (a value of 100 means, messages are not allowed to be over 100 characters long or the programm might crash due to buffer overflow as strcpy_s is not a thing in arduino
#define MAX_SUB_TOPICS 10                                               // maximum number of subtopics 
#define SUB_TOPIC_BUF_L 50                                              // lenght of the subtopic buffer in characters (a value of 50 means, subtopics are not allowed to be over 50 characters long or the programm might crash due to buffer overflow as strcpy_s is not a thing in arduino

char *base_topic = "/devices/sub0/espdev2051a/";                        // set the base topic (should end with "/")
char base_topic_cpy[100];                                               // momory pool for copy of base topic
uint8_t nr_base_subtopics;                                              // the number of subtopics the base topic has (will be calculated by the programm automatically)

char topic_buf[TOPIC_BUF_L];                                            // topic buffer
char topic_cpy[TOPIC_BUF_L];                                            // copy of topic buffer (needs to be a copy and not a pointer as the strtok() function manipulates the source string so it needs to be a copy of the original unless you don't need the original anymore afterwards
char *topicsplit;                                                       // a pointer to a section of the topic created by strtok()
char topic_delimiters[] = "/";                                           // the delimiter(s) who seperate subtopics
char subtopic_list[MAX_SUB_TOPICS][SUB_TOPIC_BUF_L];                    // buffer to store a list of all the subtopics of a message
uint8_t subtopic_counter = 0;                                           // counter to count how many subtopics the topic of a message has

char topic_out_buf[TOPIC_BUF_L];                                        // buffer for output topic

char msg_buf[MSG_BUF_L];                                                // message buffer
char msg_cpy[MSG_BUF_L];                                                // copy of the message buffer (needs to be a copy and not a pointer as the strtok() function manipulates the source string so it needs to be a copy of the original unless you don't need the original anymore afterwards

char msg_out_buf[MSG_BUF_L];                                            // buffer for output payload

StaticJsonDocument<MSG_BUF_L*2> msg_doc;                                // create a static json document for the message and allocate it double the memory of the message buffer just to be sure

// some tmp variables
char tmpchar;
char tmponechararray[2];                                                // we need to bytes to store a string with one character, because there will be an extra NULL byte for termination


// fingerprint for ssl (not jet working)
//echo | openssl s_client -connect localhost:1883 | openssl x509 -fingerprint -noout
const char* mqtt_fprint = "07 ED 59 67 2C CD 31 6C EF 27 F7 AC 38 02 07 9C 60 EC FA 0A";


// IP configuration for static IP setup, ignore or comment out if you are using DHCP
// if you are not sure what you are using, you are probably using DHCP

IPAddress ip(192,168,1,122);                       // static IP address for the ESP
IPAddress router(192,168,1,1);                    // IP address of the Wifi router
IPAddress netmask(255,255,255,0);                 // static netmask of your network


// Initialize Classes, create objects
WiFiClientSecure espClient;                       // WiFiClientSecure class, needed for communication
PubSubClient client(espClient);                   // PubSubClient class, needed for MQTT
RCSwitch mySwitch = RCSwitch();                   // RC-Swich class, needed for Remote-Switches/Sockets



void setup() {
  // Initialize Serial(UART) connection for debugging
  Serial.begin(115200);                             // Initializing UART for a baud rate of 115200, you can change it to your prefered baud rate if you want.
  Serial.println("MQTT-Remote-Switches");           // Printing a title to the Serial connection
  
  // set up wifi config
  WiFi.mode(WIFI_STA);                             // We are using the ESP as a WiFi client
  WiFi.config(ip,router,netmask);                  // This sets up static IP addresses, comment out if you are using DHCP. If you are not sure, you are probably using DHCP.
  WiFi.begin(cfg_wifi_ssid, cfg_wifi_pwd);         // Connect to WiFi using the set SSID and password
  
  // wait until wifi is connected
  while (WiFi.status() != WL_CONNECTED) {          // While the WiFi is not connected
    delay(500);                                    // Wait half a second (500ms)
    Serial.print(".");                             // Print a dot to the Serial connection
    digitalWrite(WiFiConnected, !digitalRead(WiFiConnected)); // Invert the state of I/O pin 2, which is the builtin LED on the ESP01s (not ESP01)
  }

  // now that pin 2 is no longer needed for WiFi status, we can initialize the Remote-Switches
  mySwitch.enableTransmit(rctx);
  
  // output some usefull debug information
  Serial.println();
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());                  // Print the ESP's IP address, usefull if you are usin DHCP, if you are using a static IP config, it will allways be the defined IP of the ESP
  Serial.println("MAC Address:");
  Serial.println(WiFi.macAddress());               // Print the MAC address of the ESP, usefull if you have access controll on your router and you want to allow the ESP
  
  // set the ca certificate for ssl (not jet working
  //espClient.setCACert(test_root_ca);

  // this turns of SSl. Comment out if you are using ssl (currently ssl doesn't work so I had to uncomment this line)
  espClient.setInsecure();
  
  // Configura MQTT class
  client.setServer(mqtt_server, mqtt_port);        // Set MQTT server and port
  client.setCallback(callback);                    // set the functino called when new data is available
  
  // attempting to connect to the server
  while (!client.connected()) {                                           // while not connected to MQTT server
    Serial.print("Attempting MQTT connection...");                        // print debug line
    secureConnect();                                                      // jump to secureConnect() function to try to establish a secure connection (when espClient.setInsecure() is enabled, this will not create a secure connection)
    if (client.connect(mqtt_user, mqtt_user, mqtt_pass)) {                // try to connect to the MQTT server
      Serial.println("connected");                                        // print debug line
      char subsctopic[strlen(base_topic) + 1];
      strcpy(subsctopic, base_topic);
      strcat(subsctopic, "#");
      Serial.print("subscriging to: ");
      Serial.println(subsctopic);
      client.subscribe(subsctopic);                                       // subscribe to the base topic
    }else{                                                                // if connection failed:
      Serial.print("failed, rc=");                   
      //
      Serial.print(client.state());                                       // print some debug info
      Serial.println(" try again in 5 seconds");                          //    
      delay(5000);                                                        // wait 5 seconds befor trying again.
    }
  }

  // before we go the the loop, we calculate some constant values that are needet later, so they don't have to be calculatet for every message
  
  // Number of subtopics in the basetopic
  // By isolating all the subtopics and then iterating throught them using the strtok funktin, we can count how many subtopics there are.
  char *ptr;                                                  // create a pointer
  
  // copying the base topic to the base_topic_cpy array, because the strtok() function modifies the original string
  strcpy(base_topic_cpy, base_topic);
  ptr = strtok(base_topic_cpy, topic_delimiters);             // initialize the strtok function and isolate the first subtopic
  nr_base_subtopics = 0;                                      // set the countet subtopics to zero
  while(ptr != NULL){                                         // while there are subtopics
    ptr = strtok(NULL, topic_delimiters);                     // iterate to the next subtopic
    nr_base_subtopics++;                                      // and increment the counter
  }
  Serial.print("Nr of subtopics in base topic: ");
  Serial.println(nr_base_subtopics);
}


void raiseError(int rc = 0, char *errorMsg = "NO_ERR"){
  // This function will be called when an error schould be sent out. So you can change the error messagin code here once and it apply to every error message
  Serial.print("#========== Exeception ==========#\n\rrc = ");
  Serial.print(rc);
  Serial.print(" >> ");
  Serial.println(errorMsg);
  Serial.println("#================================#");
}



void callback(char* topic, byte* payload, unsigned int length) {
  // print some log info
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.println("]");

  // load the topic from the callback pointer to the topic buffer
  int topiclen = strlen(topic);                                           // store the size of the topic
  Serial.print("Topic size: ");
  Serial.print(topiclen);
  Serial.println(" characters");
  if(topiclen > TOPIC_BUF_L){                                             // if the topic is to long for the buffer
    raiseError(2, "Topic to long for static buffer");                     // rais an error message
    return;                                                               // and break the function
  }
  strcpy(topic_buf, topic);                                               // copy the topic from the callback pointer to the topic buffer
  strcpy(topic_cpy, topic);                                               // copy the topic from the callback pointer to the second topic buffer

  Serial.print("Payload size: ");
  Serial.print(length);
  Serial.println(" characters");
  
  // load the message into a char array
  if(length > MSG_BUF_L){                                                 // if the topic is to long for the buffer
    raiseError(2, "Payload to long for static buffer");                   // rais an error message
    return;                                                               // and break the function
  }
  for (int i = 0; i < length; i++) {                                      // otherwise load the payload from a byte array into the char array msg_buf
    msg_buf[i] = (char)payload[i];
  }
  msg_buf[length] = '\0';                             // add terminator byte the the end of the char array
  strcpy(msg_cpy, msg_buf);                                               // copy the payload from the callback pointer to the second payload buffer


  Serial.println("Loading topic... ");
  // split the topic into subtopics
  subtopic_counter = 0;                                                   // reset the topic counter
  topicsplit = strtok(topic_cpy, topic_delimiters);                       // initialize the strtok funktion and isolating the first subtopic
  while(topicsplit != NULL){                                              // while there are subtopics
    strcpy(subtopic_list[subtopic_counter], topicsplit);                  // copy the current subtopic to the list of subtopics at the corresponding index (subtopic_counter)
    topicsplit = strtok(NULL, topic_delimiters);                          // isolate the next subtopic
    Serial.print("Copied subtopic: ");
    Serial.println(subtopic_list[subtopic_counter]);  
    subtopic_counter++;                                                   // increment the subtopic_counter
  }
  // print the number of subtopics found:
  Serial.print("Found ");                                                 // printing debug info about what the system found as the first subtopic after the basetopic
  Serial.print(subtopic_counter);
  Serial.print(" subtopics.\n\rChecking subtopic 1 afer base topic: ");
  Serial.println(subtopic_list[nr_base_subtopics]);
  Serial.print("Subtopic length: ");
  Serial.println(strlen(subtopic_list[nr_base_subtopics]));
  if(subtopic_counter > nr_base_subtopics){                              // Now we check if there are more topics sent than the base topic has got subtopics. If there are no additional subtopics except the base topic, we can't take a look at the rest of the subtopics in the subtopic table because there would be some random information at best or at worst information from the last command which would cause wheired behavioir
    // from here on I will call all subtopics after the base topic "command topics"
    if(strcmp(subtopic_list[nr_base_subtopics], "set") == 0){            // if the first command topic equals "set"
      Serial.println("Set remote switch");
      if(strcmp(subtopic_list[nr_base_subtopics + 1], "dip") == 0){        // if the second command topic equals "dip"
        //
        // the if the topic of the message is <base_topic>/set/dip/<third_command_topic> it means that we are in dip mode.
        // this means that the third base topic must be exactly 10 characters long and those characters must only be ones or zeros.
        if(strlen(subtopic_list[nr_base_subtopics + 2]) == 10){              // if the third command topic is 10 characters long
          //
          // this checks if the third command topic is valid, by iterating through every char and seeing if it is eighter a one or a zero
          // if the topic is invalid, the messageInvalid variable will be set to true and some errors will be printed to serial monitor
          Serial.print("Remote switch id fetched: ");
          for (int i = 0; i < 10; i++){
            Serial.print(subtopic_list[nr_base_subtopics + 2][i]);
            if (subtopic_list[nr_base_subtopics + 2][i] != '0'){
              if (subtopic_list[nr_base_subtopics + 2][i] != '1'){
                raiseError(1, "Invalid Topic!");
                Serial.print("[");
                Serial.print(i);
                Serial.print("] == ");
                Serial.print(subtopic_list[nr_base_subtopics + 2][i]);
                Serial.print(" ==> \"");
                Serial.print(subtopic_list[nr_base_subtopics + 2][i]);
                Serial.println("\" is not 0 or 1");
                messageInvalid = true;
                break;
              }
            }
          }
          Serial.println();
          
          if (messageInvalid != true){                      // if the topic is valid (the payload has not been checked jet, so this flag only indicates if the topic is valid)
            // now the topic is validated, we can go on by deserializing the payload stored in msg_buf and msg_cpy can be used
            
            DeserializationError deser_err = deserializeJson(msg_doc, msg_cpy);           // deserializin the json payload, if the payload is no json or the json is not valid, an error will be created that we can then use to return an error message
            if (deser_err){                                                               // if there was an error, it will get reported
              Serial.print("Error while deserializing the json payload!: ");  
              Serial.println(deser_err.f_str());
              raiseError(3, "Deserialization failed!");
              messageInvalid = true;
            }else{
              // Now everyting is validated, we can now transform the value of "state" in the json message  
              if(!msg_doc["state"].isNull()){                                             // otherwise we will check if the key "state" exists
                if (strlen(msg_doc["state"]) <= 5){                                         // if it exists we check if it's value is at most 5 characters  
                  strcpy(stateBuf, msg_doc["state"]);                                         // if that is the case we will copy the value to stateBuf
                  Serial.print("Fetched json \"state\": ");
                  Serial.println(stateBuf);
                  for (int i = 0; i < strlen(stateBuf); i++){                                 // and turn all letters to lower case
                    tmpchar = toupper(stateBuf[i]);
                    stateBuf[i] = tmpchar;
                  }
                  msg_doc.clear();                                                            // resetting the memory pool of the json object
                  if(strcmp(stateBuf, "OFF") == 0){                                           // if the stateBuf equals "off"
                    stateCode = '0';                                                          // set the stateCode to '0'
                  }else if(strcmp(stateBuf, "ON") == 0){                                      // if the stateBuf equals "on"
                    stateCode = '1';                                                          // set the stateCode to '1'
                  }else{
                    raiseError(4, "Invalid state value!");
                  }
                  // now we got all parameters we need to switch the remote socket.
                  // but first we need to split the third command topic into system- and unitcodes
                  for ( int i = 0; i < 5; i++){
                    systemCode[i] = subtopic_list[nr_base_subtopics + 2][i];
                  }
                  for ( int i = 0; i < 5; i++){
                    unitCode[i] = subtopic_list[nr_base_subtopics + 2][i + 5];
                  }
              
                  if (stateCode == '1'){                        // if statecode equals 1 
                    mySwitch.switchOn(systemCode, unitCode);    // the corresponding Remote-Switches/Sockets with the corresponding system- and unitcodes will be turned on
                    Serial.println("Switched on:");
                  }else if(stateCode == '0'){                   // if statecode equals 0
                    mySwitch.switchOff(systemCode, unitCode);   // the corresponding Remote-Switches/Sockets with the corresponding system- and unitcodes will be turned off
                    Serial.println("Switched off:");
                  }
                  
                  // print some more debug info
                  Serial.print("SystemCode: ");
                  Serial.print(systemCode);
                  Serial.print(", UnitCode: ");
                  Serial.println(unitCode);

                  // now that the remote switches are set, we send a response to the MQTT broker
                  // first the response topic gets assembled
                  strcpy(topic_out_buf, base_topic);
                  strcat(topic_out_buf, "state/dip/");
                  strcat(topic_out_buf, subtopic_list[nr_base_subtopics + 2]);
                  Serial.print("Response topic: ");
                  Serial.println(topic_out_buf);
                  // then the  json message has to be serialized
                  msg_doc.clear();                              // clearing the json document and resetting its memory pool
                  msg_doc["state"] = stateBuf;                  // creating a "state" key in the respons
                  serializeJson(msg_doc, msg_out_buf);          // serializing the json
                  msg_doc.clear();                              // clearing the memory pool again after usage
                  Serial.print("Response payload: ");
                  Serial.println(msg_out_buf);
                  
                  client.publish(topic_out_buf, msg_out_buf);
                  
                }else{
                  raiseError(2, "The \"state\" key contains a value to long for the buffer (len cannot be > 5");
                }
              }else{
                raiseError(4, "the \"state\" key could not be found in the json message");
              }
            }
          }
        }else{
          raiseError(1, "Invalid Topic at base topic + 3");
        }
      }else if(strcmp(subtopic_list[nr_base_subtopics + 1], "intertechno") == 0){        // if the second command topic equals "intertechno"
        //
        // the if the topic of the message is <base_topic>/set/intertechno/<third_command_topic> it means that we are in intertechno mode.
        // this means that the third base topic must be exactly 10 characters long and those characters must only be ones or zeros.
        if(strlen(subtopic_list[nr_base_subtopics + 2]) == 5){              // if the third command topic is 5 characters long
          //
          // This reads the intertechno flavour id from the third command topic into the intertechno_id array
          Serial.print("Intertechno ID fetched: ");
          strcpy(remote_switch_id, subtopic_list[nr_base_subtopics + 2]);
          Serial.println(remote_switch_id);
          Serial.print("Deserializing ID: ");
          // next we split the remote_switch_id on all "-" signs and put the seperat parts into the intertechon_id array
          char *ptr;
          uint8_t i = 0;
          ptr = strtok(remote_switch_id, "-");
          while (ptr != NULL){
            strcpy(intertechno_id[i], ptr);
            Serial.print(intertechno_id[i]);
            Serial.print(" ");
            ptr = strtok(NULL, "-");
            i++;
          }
          Serial.println();
          
          // if the id is valid the first place in the intertechno_id which represents the family, should contain a letter between a and p
          // the following segment should only be executed, if there is only one letter in the family. there can't be more or less
          if (strlen(intertechno_id[0]) == 1){
            // first we set the letter to lower case, so it doesn't matter which case it is written in
            tmpchar = tolower(intertechno_id[0][0]);
            intertechno_id[0][0] = tmpchar;
            // befor we write the value of tmpchar back into the array, we check if it only contains valid letters 
            if(strspn(intertechno_id[0], "abcdefghijklmnop")){                                              // if the family consists of a valid letter (a-p) it will be saved into the family variable (the validation works, using the strspn() function. it returns the number of legal characters before the first illegal character. The legal characters are given in the second parameter. the value can only be a one or a zero, because we have already verified that the char array we give the function consists of only one character. so if this caracter is illegal, it will return a zero as there are zero legal characters befor the first illegal character. If the character is legal, it will return a one, because there is only one character in the array, and thus the number of legal characters befor the first illegal one can only be 1.)
              family = intertechno_id[0][0];
              Serial.println("Family OK, checking group... ");
              group_int = atoi(intertechno_id[1]);                                                          // convert the group from a char array to an integer
              if (group_int > 0 && group_int < 5){                                                          // the returned integer is not allowed to be larger than 4, and not allowd to be smaller than 1. if the number is zero, eighter the user has given it a zero, which is an illegal option for the remote switches ( it can only be a 1, 2, 3 or 4) or something went wrong during the conversion from char array to integer e.g. the input is not a numeric character
                Serial.println("Group OK, checking device... ");
                device_int = atoi(intertechno_id[2]);                                                       // convert the device from a char array to an integer
                if (device_int > 0 && device_int < 5){                                                       // check if the number is between 1 and 4 (explaination as wich group)
                  Serial.println("Device OK, switching remote switches.");
                }else{
                  raiseError(4, "Message Invalid! The device can only be a number between 1 and 4!");
                  messageInvalid = true;
                }
              }else{
                raiseError(4, "Message Invalid! The group can only be a number between 1 and 4!");
                messageInvalid = true;
              }
            }else{
              raiseError(4, "Message Invalid! The Family ID can only be a letter between a and p!");
              messageInvalid = true;
            }
          }else{
            raiseError(4, "Invalid Message! Family ID can only be ONE letter!");
            messageInvalid = true;
          }

          //messageInvalid = true;// uncomment this line to stop the following segment from running for debugging
          if (messageInvalid != true){                      // if the topic is valid (the payload has not been checked jet, so this flag only indicates if the topic is valid)
            // now the topic is validated, we can go on by deserializing the payload stored in msg_buf and msg_cpy 
            
            DeserializationError deser_err = deserializeJson(msg_doc, msg_cpy);           // deserializin the json payload, if the payload is no json or the json is not valid, an error will be created that we can then use to return an error message
            if (deser_err){                                                               // if there was an error, it will get reported
              Serial.print("Error while deserializing the json payload!: ");  
              Serial.println(deser_err.f_str());
              raiseError(3, "Deserialization failed!");
              messageInvalid = true;
            }else{
              // Now everyting is validated, we can now transform the value of "state" in the json message  
              if(!msg_doc["state"].isNull()){                                             // otherwise we will check if the key "state" exists
                if (strlen(msg_doc["state"]) <= 5){                                         // if it exists we check if it's value is at most 5 characters  
                  strcpy(stateBuf, msg_doc["state"]);                                         // if that is the case we will copy the value to stateBuf
                  Serial.print("Fetched json \"state\": ");
                  Serial.println(stateBuf);
                  for (int i = 0; i < strlen(stateBuf); i++){                                 // and turn all letters to lower case
                    tmpchar = toupper(stateBuf[i]);
                    stateBuf[i] = tmpchar;
                  }
                  msg_doc.clear();                                                            // resetting the memory pool of the json object
                  if(strcmp(stateBuf, "OFF") == 0){                                           // if the stateBuf equals "off"
                    stateCode = '0';                                                          // set the stateCode to '0'
                  }else if(strcmp(stateBuf, "ON") == 0){                                      // if the stateBuf equals "on"
                    stateCode = '1';                                                          // set the stateCode to '1'
                  }else{
                    raiseError(4, "Invalid state value!");
                  }
              
                  if (stateCode == '1'){                                 // if statecode equals 1 
                    mySwitch.switchOn(family, group_int, device_int);    // the corresponding Remote-Switches/Sockets with the corresponding family-, group- and devicecode will be turned on
                    Serial.println("Switched on:");
                  }else if(stateCode == '0'){                            // if statecode equals 0
                    mySwitch.switchOff(family, group_int, device_int);   // the corresponding Remote-Switches/Sockets with the corresponding family-, group- and devicecode will be turned off
                    Serial.println("Switched off:");
                  }
                  
                  // print some more debug info
                  Serial.print("Family: ");
                  Serial.print(family);
                  Serial.print(", Group: ");
                  Serial.print(group_int);
                  Serial.print(", Device: ");
                  Serial.println(device_int);

                  // now that the remote switches are set, we send a response to the MQTT broker
                  // first the response topic gets assembled
                  strcpy(topic_out_buf, base_topic);
                  strcat(topic_out_buf, "state/intertechno/");
                  tmponechararray[0] = family;                      // as a character cannot be directly concatenated with a char array we need to put it into a temporary char arry with only one character
                  strcat(topic_out_buf, tmponechararray);           // then we can concatenate the array with the single char to the topic_out_buf array
                  strcat(topic_out_buf, "-");
                  itoa(group_int, group_char, 10);                  // as the group is an integer, it has to be converted back into a number. We could also use the original input that is already a character, but i don't want to return the raw input that the user gave. I want the programm to return the valuen that it actually worked wich, so if there is some problem with the interpretation of the userinput, we can actually see the numbers that it worked with in the return
                  strcat(topic_out_buf, group_char); 
                  strcat(topic_out_buf, "-");
                  itoa(device_int, device_char, 10);                // the device also is an integer and has to be converted back to a char
                  strcat(topic_out_buf, device_char);
                  Serial.print("Response topic: ");
                  Serial.println(topic_out_buf);
                  // then the  json message has to be serialized
                  msg_doc.clear();                              // clearing the json document and resetting its memory pool
                  msg_doc["state"] = stateBuf;                  // creating a "state" key in the respons
                  serializeJson(msg_doc, msg_out_buf);          // serializing the json
                  msg_doc.clear();                              // clearing the memory pool again after usage
                  Serial.print("Response payload: ");
                  Serial.println(msg_out_buf);
                  
                  client.publish(topic_out_buf, msg_out_buf);
                  
                }else{
                  raiseError(2, "The \"state\" key contains a value to long for the buffer (len cannot be > 5");
                }
              }else{
                raiseError(4, "the \"state\" key could not be found in the json message");
              }
            }
          }
          // after everything is done we reset all variables
          messageInvalid = false;
        }else{
          raiseError(1, "Invalid Topic at base topic + 3");
        }
      }else{
        raiseError(1, "Invalid Topic at base topic + 2");
      }
    }else if(strcmp(subtopic_list[nr_base_subtopics], "get") == 0){      // if the first command topic equals "get"
      Serial.println("Listen to remote signals");
    }else if(strcmp(subtopic_list[nr_base_subtopics], "info") == 0){     // if the first command topic equals "info"
      Serial.println("Info about Firmware");
    }else if(strcmp(subtopic_list[nr_base_subtopics], "state") == 0){     // if the first command topic equals "info"
      Serial.println("Sent state Info");
    }else{
      raiseError(1, "Invalid Topic at base topic + 1");
    }
  }
  
  // after everything is done we reset all variables
  messageInvalid = false;
}

void secureConnect() {
  if(client.connected() || espClient.connected()) return; // If the ESP is already connected to the server, everything else in this functio will be skipped

  // print some debug info
  Serial.print("Connectiong to ");
  Serial.print(mqtt_server);
  Serial.print(" ... ");
  
  if (!espClient.connect(mqtt_server, mqtt_port)) {      // trying to establish a (secure) connection to the server, if the connection fails
    Serial.println("Connection failed. Rebooting.");     // outout some debug info
    Serial.flush();                                      // flush the serial buffer
    ESP.restart();                                       // and reboot the ESP (easy way of returning to the start of the code)
  }

  // here the fingerprint of the server would be verified but this isn't currently working
  /*
  if (espClient.verify(mqtt_fprint, mqtt_server)) {
    Serial.print("Connection secure -> .");
  } else {
    Serial.println("Connection insecure! Rebooting.");
    Serial.flush();
    ESP.restart(); 
  }
  */
  espClient.stop();                                     // if everything worked we can stop the WiFiClientSecure class
  delay(100);
}





//unsigned int counter = 0;

uint32_t loopcounter = 0;

void loop() {
  // The MQTT loop function is called in order to check for new incomming packets
  client.loop();
  
  // Every <conCheckInterfal> loop cycles the connectino to the server will be checked and the esp will reboot if eighter the 
  // WiFiClientSecure connection or the PubSubClient connectinos have failed.
  if(loopcounter >= conCheckInterval){
    Serial.print("Connection check: ");
    if(!client.connected()){
      Serial.println("Connection lost! Rebooting...");
      Serial.flush();
      ESP.restart();
    }else{
      Serial.println("Connection good");
    }
    loopcounter = 0;
  }
  loopcounter++;
}
