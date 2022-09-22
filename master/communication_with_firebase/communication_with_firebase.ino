//libraries for connecting to wifi and using http communcation protocal
#include <WiFi.h>
#include <FirebaseESP32.h>

//firebase prerequisites
#define firebaseHost "https://testing-58bc5-default-rtdb.firebaseio.com/"
#define firebaseAuth "oSNvh6eGbWV4QbITgtoZghe0eCRxDefpbGvuRWe3"

//wifi passwords
//const char* ssid = "TP-Link_D1F6";
//const char* password = "77373816" ;
const char* ssid = "dekut";
const char* password = "dekut@ict2020?" ;
//const char* ssid = "Martin Router King";
//const char* password = "Budaboss2" ;

#define txd2 17
#define rxd2 16
char *base, *shoulder, *elbow, *wristpitch, *wristroll;

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

void setup()
{
  Serial.begin(115200);
  Serial2.begin(115200, SERIAL_8N1, rxd2, txd2);
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
void loop()
{
  if (Serial2.available()) {
    jsonStr = Serial2.readString();
    Serial.println(jsonStr);
    
    char allAnglesArrays[25];
     jsonStr.toCharArray(allAnglesArrays,25);
    
    //splitt into sections
    const char *delimiter =",";
    
    //detokenize the angles
    base = strtok(allAnglesArrays,delimiter);
    shoulder = strtok(NULL,delimiter);
    elbow = strtok(NULL,delimiter);
    wristpitch = strtok(NULL,delimiter);
    wristroll= strtok(NULL,delimiter);
    json.set(motor1path, base);
    json.set(motor2path, shoulder);
    json.set(motor3path, elbow);
    json.set(motor4path, wristpitch);
    json.set(motor5path, wristroll);
    
    Firebase.updateNode(firebaseData,"/Sensor",json);
  }
}
