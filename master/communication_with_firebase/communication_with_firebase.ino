//libraries for connecting to wifi and using http communcation protocal
#include <WiFi.h>
#include <FirebaseESP32.h>

//uart pins connected to mega
#define txd1 17
#define rxd1 16


//firebase prerequisites
#define firebaseHost "https://fir-20fd7-default-rtdb.firebaseio.com/"
#define firebaseAuth "jzT1xgPDY9La8wNbminplWB9FPHrzTHEXdm1gWBM"

//wifi passwords
const char* ssid = "TP-Link_D1F6";
const char* password = "77373816" ;
//const char* ssid = "dekut";
//const char* password = "dekut@ict2020?" ;
//const char* ssid = "Martin Router King";
//const char* password = "Budaboss2" ;

//Define FirebaseESP32 data object
FirebaseData firebaseData;
FirebaseJson json;
String jsonStr;
String path = "/sensor";

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
  String sdata = "\"motor1\":20, \"motor2\":30,\"motor3\":40,";
  json.set("/data", sdata);
  Firebase.updateNode(firebaseData,"/Sensor",json);
  

}
