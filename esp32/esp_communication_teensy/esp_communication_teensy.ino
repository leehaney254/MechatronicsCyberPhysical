#define txd2 17
#define rxd2 16

void setup()
{
  Serial.begin(115200);
  Serial2.begin(115200, SERIAL_8N1, rxd2, txd2);
}
void loop()
{
  if (Serial2.available()) {
    Serial.println(Serial2.readString());
  }
}
