//libraries for connecting to wifi and using http communcation protocal
#include <WiFi.h>
#include <FirebaseESP32.h>

//uart pins connected to mega
#define txd1 17
#define rxd1 16


//firebase prerequisites
//#define firebaseHost "https://fir-20fd7-default-rtdb.firebaseio.com/"
//#define firebaseAuth "jzT1xgPDY9La8wNbminplWB9FPHrzTHEXdm1gWBM"
#define firebaseHost "https://pegasus-3b383-default-rtdb.firebaseio.com/"
#define firebaseAuth "Y8oJuEhRiWsvRhikncnlBBQjOUMHWUzCNtPcFOV5"

//wifi passwords
//const char* ssid = "TP-Link_D1F6";
//const char* password = "77373816" ;
//const char* ssid = "dekut";
//const char* password = "dekut@ict2020?" ;
const char* ssid = "Martin Router King";
const char* password = "Budaboss2" ;

//Define FirebaseESP32 data object
FirebaseData firebaseData;
//used to create json data
FirebaseJson json;
String jsonStr;

//child nodes to be updated
String motor1path = "/motor1";
String motor2path = "/motor2";
String motor3path = "/motor3";
String motor4path = "/motor4";
String motor5path = "/motor5";
String motor6path = "/motor6";

float motor1 = 30.3;
float motor2 = 40.4;
float motor3 = 50.5;
float motor4 = 60.6;
float motor5 = 70.7;
float motor6 = 80.8;

void setup() {
  Serial.begin(115200);
  Serial2.begin(115200, SERIAL_8N1, rxd1, txd1);
  // put your setup code here, to run once:
  WiFi.disconnect();  //disconnects wifi to previous network
  WiFi.begin(ssid, password);
  WiFi.mode(WIFI_STA); //sets the wifi module to station mode
  Serial.println("Connecting to wifi");
  //buffer, waiting for wifi to connect
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("\n Connected to a wifi network");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

    Firebase.begin(firebaseHost, firebaseAuth);
  Firebase.reconnectWiFi(true);
 
  //Set database read timeout to 1 minute (max 15 minutes)
  Firebase.setReadTimeout(firebaseData, 1000 * 60);
  //tiny, small, medium, large and unlimited.
  //Size and its write timeout e.g. tiny (1s), small (10s), medium (30s) and large (60s).
  Firebase.setwriteSizeLimit(firebaseData, "tiny");

  Serial.println("------------------------------------");
  Serial.println("Connected...");
}

void loop() {
  // put your main code here, to run repeatedly:
  json.set(motor1path, motor1);
  json.set(motor2path, motor2);
  json.set(motor3path, motor3);
  json.set(motor4path, motor4);
  json.set(motor5path, motor5);
  json.set(motor6path, motor6);
  Firebase.updateNode(firebaseData,"/Sensor",json);
  

}
