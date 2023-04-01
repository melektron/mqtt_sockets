#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <PubSubClient.h>
#include <RCSwitch.h>


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

int rctx = 2;
int rcrx = 0;

// WIFI data has been censored for publication
const char* cfg_wifi_ssid = "********";
const char* cfg_wifi_pwd = "********";

const char* mqtt_server = "192.168.1.13";
const unsigned int mqtt_port = 1883;
const char* mqtt_user =   "****";
const char* mqtt_pass =   "****";
char systemCode[] = "00000";
char unitCode[] = "00000";
char stateCode = '0';
bool messageInvalid = false;

//echo | openssl s_client -connect localhost:1883 | openssl x509 -fingerprint -noout
const char* mqtt_fprint = "07 ED 59 67 2C CD 31 6C EF 27 F7 AC 38 02 07 9C 60 EC FA 0A";


IPAddress ip(192,168,1,92); //Requested static IP address for the ESP
IPAddress router(192,168,1,1); // IP address for the Wifi router
IPAddress netmask(255,255,255,0);


//WiFiClient wifiClient;
WiFiClientSecure espClient;
PubSubClient client(espClient);

RCSwitch mySwitch = RCSwitch();

int WiFiConnected = 0;

void setup() {
  // put your setup code here, to run once:
  //delay(5000);
  espClient.setInsecure();

  Serial.begin(115200);
  pinMode(WiFiConnected, OUTPUT);
  mySwitch.enableTransmit(rctx);
  Serial.println("TestMQTT");
  // set up wifi config
  WiFi.mode(WIFI_STA);
  WiFi.config(ip,router,netmask);
  WiFi.begin(cfg_wifi_ssid, cfg_wifi_pwd);
  // wait until wifi is connected
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    digitalWrite(WiFiConnected, !digitalRead(WiFiConnected));
  }

  Serial.println("");
  digitalWrite(WiFiConnected, HIGH);
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println("MAC Address:");
  Serial.println(WiFi.macAddress());
  // set the ca certificate
  //espClient.setCACert(test_root_ca);
  
  // set MQTT server and callback function
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
  // attempting to connect to the server
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    verifyFingerprint();
    if (client.connect(mqtt_user, mqtt_user, mqtt_pass)) {
      Serial.println("connected");
      client.subscribe("/devices/sub0/espdev2048a/remote_switches/dip");
    }else{
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");

  char message[length + 1];
  for (int i = 0; i < length; i++) {
    message[i] = (char)payload[i];
  }
  message[length] = '\0';
  Serial.println(message);
  for (int i = 0; i < length; i++){
    Serial.print(message[i]);
    if (message[i] != '0'){
      if (message[i] != '1'){
        Serial.println();
        Serial.print("Message invalid: message[");
        Serial.print(i);
        Serial.print("] == ");
        Serial.print(message[i]);
        Serial.print(" ==> \"");
        Serial.print(message[i]);
        Serial.println("\" is not 0 or 1");
        messageInvalid = true;
        break;
      }
    }
  }
  if (messageInvalid != true){
    /*
    for ( int i = 0; i > 5; i++){
      systemCode[i] = message[i];
    }
    for ( int i = 5; i > 10; i++){
      unitCode[i - 5] = message[i];
    }
    */
    systemCode[0] = message[0];
    systemCode[1] = message[1];
    systemCode[2] = message[2];
    systemCode[3] = message[3];
    systemCode[4] = message[4];
    unitCode[0] = message[5];
    unitCode[1] = message[6];
    unitCode[2] = message[7];
    unitCode[3] = message[8];
    unitCode[4] = message[9];
    
    stateCode = message[10];
    if (stateCode == '1'){
      mySwitch.switchOn(systemCode, unitCode);
      Serial.println("Switched on:");
    }else if(stateCode == '0'){
      mySwitch.switchOff(systemCode, unitCode);
      Serial.println("Switched off:");
    }
    //Serial.println("Switched:");
    Serial.print("SystemCode: ");
    Serial.println(systemCode);
    Serial.print("UnitCode;   ");
    Serial.println(unitCode);
    Serial.print("StateCode:  ");
    //Serial.println(stateCode);
  }else{
    messageInvalid = false;
  }
}

void verifyFingerprint() {
  if(client.connected() || espClient.connected()) return; //Already connected
  
  Serial.print("Checking TLS @ ");
  Serial.print(mqtt_server);
  Serial.print("...");
  
  if (!espClient.connect(mqtt_server, mqtt_port)) {
    Serial.println("Connection failed. Rebooting.");
    Serial.flush();
    ESP.restart();
  }
  /*
  if (espClient.verify(mqtt_fprint, mqtt_server)) {
    Serial.print("Connection secure -> .");
  } else {
    Serial.println("Connection insecure! Rebooting.");
    Serial.flush();
    ESP.restart(); 
  }
  */
  espClient.stop();

  delay(100);
}

unsigned int counter = 0;

void loop() {
  // put your main code here, to run repeatedly:
  client.loop();
  //delay(100);
}